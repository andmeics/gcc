// Copyright 2011 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// +build freebsd linux

#include "runtime.h"

// This implementation depends on OS-specific implementations of
//
//	runtime_futexsleep(uint32 *addr, uint32 val, int64 ns)
//		Atomically,
//			if(*addr == val) sleep
//		Might be woken up spuriously; that's allowed.
//		Don't sleep longer than ns; ns < 0 means forever.
//
//	runtime_futexwakeup(uint32 *addr, uint32 cnt)
//		If any procs are sleeping on addr, wake up at most cnt.

enum
{
	MUTEX_UNLOCKED = 0,
	MUTEX_LOCKED = 1,
	MUTEX_SLEEPING = 2,

	ACTIVE_SPIN = 4,
	ACTIVE_SPIN_CNT = 30,
	PASSIVE_SPIN = 1,
};

// Possible lock states are MUTEX_UNLOCKED, MUTEX_LOCKED and MUTEX_SLEEPING.
// MUTEX_SLEEPING means that there is presumably at least one sleeping thread.
// Note that there can be spinning threads during all states - they do not
// affect mutex's state.
void
runtime_lock(Lock *l)
{
	uint32 i, v, wait, spin;

	if(runtime_m()->locks++ < 0)
		runtime_throw("runtime_lock: lock count");

	// Speculative grab for lock.
	v = runtime_xchg(&l->key, MUTEX_LOCKED);
	if(v == MUTEX_UNLOCKED)
		return;

	// wait is either MUTEX_LOCKED or MUTEX_SLEEPING
	// depending on whether there is a thread sleeping
	// on this mutex.  If we ever change l->key from
	// MUTEX_SLEEPING to some other value, we must be
	// careful to change it back to MUTEX_SLEEPING before
	// returning, to ensure that the sleeping thread gets
	// its wakeup call.
	wait = v;

	// On uniprocessor's, no point spinning.
	// On multiprocessors, spin for ACTIVE_SPIN attempts.
	spin = 0;
	if(runtime_ncpu > 1)
		spin = ACTIVE_SPIN;

	for(;;) {
		// Try for lock, spinning.
		for(i = 0; i < spin; i++) {
			while(l->key == MUTEX_UNLOCKED)
				if(runtime_cas(&l->key, MUTEX_UNLOCKED, wait))
					return;
			runtime_procyield(ACTIVE_SPIN_CNT);
		}

		// Try for lock, rescheduling.
		for(i=0; i < PASSIVE_SPIN; i++) {
			while(l->key == MUTEX_UNLOCKED)
				if(runtime_cas(&l->key, MUTEX_UNLOCKED, wait))
					return;
			runtime_osyield();
		}

		// Sleep.
		v = runtime_xchg(&l->key, MUTEX_SLEEPING);
		if(v == MUTEX_UNLOCKED)
			return;
		wait = MUTEX_SLEEPING;
		runtime_futexsleep(&l->key, MUTEX_SLEEPING, -1);
	}
}

void
runtime_unlock(Lock *l)
{
	uint32 v;

	if(--runtime_m()->locks < 0)
		runtime_throw("runtime_unlock: lock count");

	v = runtime_xchg(&l->key, MUTEX_UNLOCKED);
	if(v == MUTEX_UNLOCKED)
		runtime_throw("unlock of unlocked lock");
	if(v == MUTEX_SLEEPING)
		runtime_futexwakeup(&l->key, 1);
}

// One-time notifications.
void
runtime_noteclear(Note *n)
{
	n->key = 0;
}

void
runtime_notewakeup(Note *n)
{
	if(runtime_xchg(&n->key, 1))
		runtime_throw("notewakeup - double wakeup");
	runtime_futexwakeup(&n->key, 1);
}

void
runtime_notesleep(Note *n)
{
	if(runtime_m()->profilehz > 0)
		runtime_setprof(false);
	while(runtime_atomicload(&n->key) == 0)
		runtime_futexsleep(&n->key, 0, -1);
	if(runtime_m()->profilehz > 0)
		runtime_setprof(true);
}

void
runtime_notetsleep(Note *n, int64 ns)
{
	int64 deadline, now;

	if(ns < 0) {
		runtime_notesleep(n);
		return;
	}

	if(runtime_atomicload(&n->key) != 0)
		return;

	if(runtime_m()->profilehz > 0)
		runtime_setprof(false);
	deadline = runtime_nanotime() + ns;
	for(;;) {
		runtime_futexsleep(&n->key, 0, ns);
		if(runtime_atomicload(&n->key) != 0)
			break;
		now = runtime_nanotime();
		if(now >= deadline)
			break;
		ns = deadline - now;
	}
	if(runtime_m()->profilehz > 0)
		runtime_setprof(true);
}
