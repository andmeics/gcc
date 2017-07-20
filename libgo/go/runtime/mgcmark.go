// Copyright 2009 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// Garbage collector: marking and scanning

package runtime

import (
	"runtime/internal/atomic"
	"runtime/internal/sys"
	"unsafe"
)

const (
	fixedRootFinalizers = iota
	fixedRootFreeGStacks
	fixedRootCount

	// rootBlockBytes is the number of bytes to scan per data or
	// BSS root.
	rootBlockBytes = 256 << 10

	// rootBlockSpans is the number of spans to scan per span
	// root.
	rootBlockSpans = 8 * 1024 // 64MB worth of spans

	// maxObletBytes is the maximum bytes of an object to scan at
	// once. Larger objects will be split up into "oblets" of at
	// most this size. Since we can scan 1–2 MB/ms, 128 KB bounds
	// scan preemption at ~100 µs.
	//
	// This must be > _MaxSmallSize so that the object base is the
	// span base.
	maxObletBytes = 128 << 10

	// idleCheckThreshold specifies how many units of work to do
	// between run queue checks in an idle worker. Assuming a scan
	// rate of 1 MB/ms, this is ~100 µs. Lower values have higher
	// overhead in the scan loop (the scheduler check may perform
	// a syscall, so its overhead is nontrivial). Higher values
	// make the system less responsive to incoming work.
	idleCheckThreshold = 100000
)

// gcMarkRootPrepare queues root scanning jobs (stacks, globals, and
// some miscellany) and initializes scanning-related state.
//
// The caller must have call gcCopySpans().
//
// The world must be stopped.
//
//go:nowritebarrier
func gcMarkRootPrepare() {
	if gcphase == _GCmarktermination {
		work.nFlushCacheRoots = int(gomaxprocs)
	} else {
		work.nFlushCacheRoots = 0
	}

	work.nDataRoots = 0

	// Only scan globals once per cycle; preferably concurrently.
	if !work.markrootDone {
		roots := gcRoots
		for roots != nil {
			work.nDataRoots++
			roots = roots.next
		}
	}

	if !work.markrootDone {
		// On the first markroot, we need to scan span roots.
		// In concurrent GC, this happens during concurrent
		// mark and we depend on addfinalizer to ensure the
		// above invariants for objects that get finalizers
		// after concurrent mark. In STW GC, this will happen
		// during mark termination.
		//
		// We're only interested in scanning the in-use spans,
		// which will all be swept at this point. More spans
		// may be added to this list during concurrent GC, but
		// we only care about spans that were allocated before
		// this mark phase.
		work.nSpanRoots = mheap_.sweepSpans[mheap_.sweepgen/2%2].numBlocks()

		// On the first markroot, we need to scan all Gs. Gs
		// may be created after this point, but it's okay that
		// we ignore them because they begin life without any
		// roots, so there's nothing to scan, and any roots
		// they create during the concurrent phase will be
		// scanned during mark termination. During mark
		// termination, allglen isn't changing, so we'll scan
		// all Gs.
		work.nStackRoots = int(atomic.Loaduintptr(&allglen))
		work.nRescanRoots = 0
	} else {
		// We've already scanned span roots and kept the scan
		// up-to-date during concurrent mark.
		work.nSpanRoots = 0

		// On the second pass of markroot, we're just scanning
		// dirty stacks. It's safe to access rescan since the
		// world is stopped.
		work.nStackRoots = 0
		work.nRescanRoots = len(work.rescan.list)
	}

	work.markrootNext = 0
	work.markrootJobs = uint32(fixedRootCount + work.nFlushCacheRoots + work.nDataRoots + work.nSpanRoots + work.nStackRoots + work.nRescanRoots)
}

// gcMarkRootCheck checks that all roots have been scanned. It is
// purely for debugging.
func gcMarkRootCheck() {
	if work.markrootNext < work.markrootJobs {
		print(work.markrootNext, " of ", work.markrootJobs, " markroot jobs done\n")
		throw("left over markroot jobs")
	}

	lock(&allglock)
	// Check that stacks have been scanned.
	var gp *g
	if gcphase == _GCmarktermination && debug.gcrescanstacks > 0 {
		for i := 0; i < len(allgs); i++ {
			gp = allgs[i]
			if !(gp.gcscandone && gp.gcscanvalid) && readgstatus(gp) != _Gdead {
				goto fail
			}
		}
	} else {
		for i := 0; i < work.nStackRoots; i++ {
			gp = allgs[i]
			if !gp.gcscandone {
				goto fail
			}
		}
	}
	unlock(&allglock)
	return

fail:
	println("gp", gp, "goid", gp.goid,
		"status", readgstatus(gp),
		"gcscandone", gp.gcscandone,
		"gcscanvalid", gp.gcscanvalid)
	unlock(&allglock) // Avoid self-deadlock with traceback.
	throw("scan missed a g")
}

// ptrmask for an allocation containing a single pointer.
var oneptrmask = [...]uint8{1}

// markroot scans the i'th root.
//
// Preemption must be disabled (because this uses a gcWork).
//
// nowritebarrier is only advisory here.
//
//go:nowritebarrier
func markroot(gcw *gcWork, i uint32) {
	// TODO(austin): This is a bit ridiculous. Compute and store
	// the bases in gcMarkRootPrepare instead of the counts.
	baseFlushCache := uint32(fixedRootCount)
	baseData := baseFlushCache + uint32(work.nFlushCacheRoots)
	baseSpans := baseData + uint32(work.nDataRoots)
	baseStacks := baseSpans + uint32(work.nSpanRoots)
	baseRescan := baseStacks + uint32(work.nStackRoots)
	end := baseRescan + uint32(work.nRescanRoots)

	// Note: if you add a case here, please also update heapdump.go:dumproots.
	switch {
	case baseFlushCache <= i && i < baseData:
		flushmcache(int(i - baseFlushCache))

	case baseData <= i && i < baseSpans:
		roots := gcRoots
		c := baseData
		for roots != nil {
			if i == c {
				markrootBlock(roots, gcw)
				break
			}
			roots = roots.next
			c++
		}

	case i == fixedRootFinalizers:
		for fb := allfin; fb != nil; fb = fb.alllink {
			cnt := uintptr(atomic.Load(&fb.cnt))
			scanblock(uintptr(unsafe.Pointer(&fb.fin[0])), cnt*unsafe.Sizeof(fb.fin[0]), &finptrmask[0], gcw)
		}

	case i == fixedRootFreeGStacks:
		// FIXME: We don't do this for gccgo.

	case baseSpans <= i && i < baseStacks:
		// mark MSpan.specials
		markrootSpans(gcw, int(i-baseSpans))

	default:
		// the rest is scanning goroutine stacks
		var gp *g
		if baseStacks <= i && i < baseRescan {
			gp = allgs[i-baseStacks]
		} else if baseRescan <= i && i < end {
			gp = work.rescan.list[i-baseRescan].ptr()
			if gp.gcRescan != int32(i-baseRescan) {
				// Looking for issue #17099.
				println("runtime: gp", gp, "found at rescan index", i-baseRescan, "but should be at", gp.gcRescan)
				throw("bad g rescan index")
			}
		} else {
			throw("markroot: bad index")
		}

		// remember when we've first observed the G blocked
		// needed only to output in traceback
		status := readgstatus(gp) // We are not in a scan state
		if (status == _Gwaiting || status == _Gsyscall) && gp.waitsince == 0 {
			gp.waitsince = work.tstart
		}

		// scang must be done on the system stack in case
		// we're trying to scan our own stack.
		systemstack(func() {
			// If this is a self-scan, put the user G in
			// _Gwaiting to prevent self-deadlock. It may
			// already be in _Gwaiting if this is a mark
			// worker or we're in mark termination.
			userG := getg().m.curg
			selfScan := gp == userG && readgstatus(userG) == _Grunning
			if selfScan {
				casgstatus(userG, _Grunning, _Gwaiting)
				userG.waitreason = "garbage collection scan"
			}

			// TODO: scang blocks until gp's stack has
			// been scanned, which may take a while for
			// running goroutines. Consider doing this in
			// two phases where the first is non-blocking:
			// we scan the stacks we can and ask running
			// goroutines to scan themselves; and the
			// second blocks.
			scang(gp, gcw)

			if selfScan {
				casgstatus(userG, _Gwaiting, _Grunning)
			}
		})
	}
}

// markrootBlock scans one element of the list of GC roots.
//
//go:nowritebarrier
func markrootBlock(roots *gcRootList, gcw *gcWork) {
	for i := 0; i < roots.count; i++ {
		r := &roots.roots[i]
		scanblock(uintptr(r.decl), r.ptrdata, r.gcdata, gcw)
	}
}

// markrootSpans marks roots for one shard of work.spans.
//
//go:nowritebarrier
func markrootSpans(gcw *gcWork, shard int) {
	// Objects with finalizers have two GC-related invariants:
	//
	// 1) Everything reachable from the object must be marked.
	// This ensures that when we pass the object to its finalizer,
	// everything the finalizer can reach will be retained.
	//
	// 2) Finalizer specials (which are not in the garbage
	// collected heap) are roots. In practice, this means the fn
	// field must be scanned.
	//
	// TODO(austin): There are several ideas for making this more
	// efficient in issue #11485.

	if work.markrootDone {
		throw("markrootSpans during second markroot")
	}

	sg := mheap_.sweepgen
	spans := mheap_.sweepSpans[mheap_.sweepgen/2%2].block(shard)
	// Note that work.spans may not include spans that were
	// allocated between entering the scan phase and now. This is
	// okay because any objects with finalizers in those spans
	// must have been allocated and given finalizers after we
	// entered the scan phase, so addfinalizer will have ensured
	// the above invariants for them.
	for _, s := range spans {
		if s.state != mSpanInUse {
			continue
		}
		if !useCheckmark && s.sweepgen != sg {
			// sweepgen was updated (+2) during non-checkmark GC pass
			print("sweep ", s.sweepgen, " ", sg, "\n")
			throw("gc: unswept span")
		}

		// Speculatively check if there are any specials
		// without acquiring the span lock. This may race with
		// adding the first special to a span, but in that
		// case addfinalizer will observe that the GC is
		// active (which is globally synchronized) and ensure
		// the above invariants. We may also ensure the
		// invariants, but it's okay to scan an object twice.
		if s.specials == nil {
			continue
		}

		// Lock the specials to prevent a special from being
		// removed from the list while we're traversing it.
		lock(&s.speciallock)

		for sp := s.specials; sp != nil; sp = sp.next {
			if sp.kind != _KindSpecialFinalizer {
				continue
			}
			// don't mark finalized object, but scan it so we
			// retain everything it points to.
			spf := (*specialfinalizer)(unsafe.Pointer(sp))
			// A finalizer can be set for an inner byte of an object, find object beginning.
			p := s.base() + uintptr(spf.special.offset)/s.elemsize*s.elemsize

			// Mark everything that can be reached from
			// the object (but *not* the object itself or
			// we'll never collect it).
			scanobject(p, gcw)

			// The special itself is a root.
			scanblock(uintptr(unsafe.Pointer(&spf.fn)), sys.PtrSize, &oneptrmask[0], gcw)
		}

		unlock(&s.speciallock)
	}
}

// gcAssistAlloc performs GC work to make gp's assist debt positive.
// gp must be the calling user gorountine.
//
// This must be called with preemption enabled.
func gcAssistAlloc(gp *g) {
	// Don't assist in non-preemptible contexts. These are
	// generally fragile and won't allow the assist to block.
	if getg() == gp.m.g0 {
		return
	}
	if mp := getg().m; mp.locks > 0 || mp.preemptoff != "" {
		return
	}

retry:
	// Compute the amount of scan work we need to do to make the
	// balance positive. When the required amount of work is low,
	// we over-assist to build up credit for future allocations
	// and amortize the cost of assisting.
	debtBytes := -gp.gcAssistBytes
	scanWork := int64(gcController.assistWorkPerByte * float64(debtBytes))
	if scanWork < gcOverAssistWork {
		scanWork = gcOverAssistWork
		debtBytes = int64(gcController.assistBytesPerWork * float64(scanWork))
	}

	// Steal as much credit as we can from the background GC's
	// scan credit. This is racy and may drop the background
	// credit below 0 if two mutators steal at the same time. This
	// will just cause steals to fail until credit is accumulated
	// again, so in the long run it doesn't really matter, but we
	// do have to handle the negative credit case.
	bgScanCredit := atomic.Loadint64(&gcController.bgScanCredit)
	stolen := int64(0)
	if bgScanCredit > 0 {
		if bgScanCredit < scanWork {
			stolen = bgScanCredit
			gp.gcAssistBytes += 1 + int64(gcController.assistBytesPerWork*float64(stolen))
		} else {
			stolen = scanWork
			gp.gcAssistBytes += debtBytes
		}
		atomic.Xaddint64(&gcController.bgScanCredit, -stolen)

		scanWork -= stolen

		if scanWork == 0 {
			// We were able to steal all of the credit we
			// needed.
			return
		}
	}

	// Perform assist work
	systemstack(func() {
		gcAssistAlloc1(gp, scanWork)
		// The user stack may have moved, so this can't touch
		// anything on it until it returns from systemstack.
	})

	completed := gp.param != nil
	gp.param = nil
	if completed {
		gcMarkDone()
	}

	if gp.gcAssistBytes < 0 {
		// We were unable steal enough credit or perform
		// enough work to pay off the assist debt. We need to
		// do one of these before letting the mutator allocate
		// more to prevent over-allocation.
		//
		// If this is because we were preempted, reschedule
		// and try some more.
		if gp.preempt {
			Gosched()
			goto retry
		}

		// Add this G to an assist queue and park. When the GC
		// has more background credit, it will satisfy queued
		// assists before flushing to the global credit pool.
		//
		// Note that this does *not* get woken up when more
		// work is added to the work list. The theory is that
		// there wasn't enough work to do anyway, so we might
		// as well let background marking take care of the
		// work that is available.
		if !gcParkAssist() {
			goto retry
		}

		// At this point either background GC has satisfied
		// this G's assist debt, or the GC cycle is over.
	}
}

// gcAssistAlloc1 is the part of gcAssistAlloc that runs on the system
// stack. This is a separate function to make it easier to see that
// we're not capturing anything from the user stack, since the user
// stack may move while we're in this function.
//
// gcAssistAlloc1 indicates whether this assist completed the mark
// phase by setting gp.param to non-nil. This can't be communicated on
// the stack since it may move.
//
//go:systemstack
func gcAssistAlloc1(gp *g, scanWork int64) {
	// Clear the flag indicating that this assist completed the
	// mark phase.
	gp.param = nil

	if atomic.Load(&gcBlackenEnabled) == 0 {
		// The gcBlackenEnabled check in malloc races with the
		// store that clears it but an atomic check in every malloc
		// would be a performance hit.
		// Instead we recheck it here on the non-preemptable system
		// stack to determine if we should preform an assist.

		// GC is done, so ignore any remaining debt.
		gp.gcAssistBytes = 0
		return
	}
	// Track time spent in this assist. Since we're on the
	// system stack, this is non-preemptible, so we can
	// just measure start and end time.
	startTime := nanotime()

	decnwait := atomic.Xadd(&work.nwait, -1)
	if decnwait == work.nproc {
		println("runtime: work.nwait =", decnwait, "work.nproc=", work.nproc)
		throw("nwait > work.nprocs")
	}

	// gcDrainN requires the caller to be preemptible.
	casgstatus(gp, _Grunning, _Gwaiting)
	gp.waitreason = "GC assist marking"

	// drain own cached work first in the hopes that it
	// will be more cache friendly.
	gcw := &getg().m.p.ptr().gcw
	workDone := gcDrainN(gcw, scanWork)
	// If we are near the end of the mark phase
	// dispose of the gcw.
	if gcBlackenPromptly {
		gcw.dispose()
	}

	casgstatus(gp, _Gwaiting, _Grunning)

	// Record that we did this much scan work.
	//
	// Back out the number of bytes of assist credit that
	// this scan work counts for. The "1+" is a poor man's
	// round-up, to ensure this adds credit even if
	// assistBytesPerWork is very low.
	gp.gcAssistBytes += 1 + int64(gcController.assistBytesPerWork*float64(workDone))

	// If this is the last worker and we ran out of work,
	// signal a completion point.
	incnwait := atomic.Xadd(&work.nwait, +1)
	if incnwait > work.nproc {
		println("runtime: work.nwait=", incnwait,
			"work.nproc=", work.nproc,
			"gcBlackenPromptly=", gcBlackenPromptly)
		throw("work.nwait > work.nproc")
	}

	if incnwait == work.nproc && !gcMarkWorkAvailable(nil) {
		// This has reached a background completion point. Set
		// gp.param to a non-nil value to indicate this. It
		// doesn't matter what we set it to (it just has to be
		// a valid pointer).
		gp.param = unsafe.Pointer(gp)
	}
	duration := nanotime() - startTime
	_p_ := gp.m.p.ptr()
	_p_.gcAssistTime += duration
	if _p_.gcAssistTime > gcAssistTimeSlack {
		atomic.Xaddint64(&gcController.assistTime, _p_.gcAssistTime)
		_p_.gcAssistTime = 0
	}
}

// gcWakeAllAssists wakes all currently blocked assists. This is used
// at the end of a GC cycle. gcBlackenEnabled must be false to prevent
// new assists from going to sleep after this point.
func gcWakeAllAssists() {
	lock(&work.assistQueue.lock)
	injectglist(work.assistQueue.head.ptr())
	work.assistQueue.head.set(nil)
	work.assistQueue.tail.set(nil)
	unlock(&work.assistQueue.lock)
}

// gcParkAssist puts the current goroutine on the assist queue and parks.
//
// gcParkAssist returns whether the assist is now satisfied. If it
// returns false, the caller must retry the assist.
//
//go:nowritebarrier
func gcParkAssist() bool {
	lock(&work.assistQueue.lock)
	// If the GC cycle finished while we were getting the lock,
	// exit the assist. The cycle can't finish while we hold the
	// lock.
	if atomic.Load(&gcBlackenEnabled) == 0 {
		unlock(&work.assistQueue.lock)
		return true
	}

	gp := getg()
	oldHead, oldTail := work.assistQueue.head, work.assistQueue.tail
	if oldHead == 0 {
		work.assistQueue.head.set(gp)
	} else {
		oldTail.ptr().schedlink.set(gp)
	}
	work.assistQueue.tail.set(gp)
	gp.schedlink.set(nil)

	// Recheck for background credit now that this G is in
	// the queue, but can still back out. This avoids a
	// race in case background marking has flushed more
	// credit since we checked above.
	if atomic.Loadint64(&gcController.bgScanCredit) > 0 {
		work.assistQueue.head = oldHead
		work.assistQueue.tail = oldTail
		if oldTail != 0 {
			oldTail.ptr().schedlink.set(nil)
		}
		unlock(&work.assistQueue.lock)
		return false
	}
	// Park.
	goparkunlock(&work.assistQueue.lock, "GC assist wait", traceEvGoBlockGC, 2)
	return true
}

// gcFlushBgCredit flushes scanWork units of background scan work
// credit. This first satisfies blocked assists on the
// work.assistQueue and then flushes any remaining credit to
// gcController.bgScanCredit.
//
// Write barriers are disallowed because this is used by gcDrain after
// it has ensured that all work is drained and this must preserve that
// condition.
//
//go:nowritebarrierrec
func gcFlushBgCredit(scanWork int64) {
	if work.assistQueue.head == 0 {
		// Fast path; there are no blocked assists. There's a
		// small window here where an assist may add itself to
		// the blocked queue and park. If that happens, we'll
		// just get it on the next flush.
		atomic.Xaddint64(&gcController.bgScanCredit, scanWork)
		return
	}

	scanBytes := int64(float64(scanWork) * gcController.assistBytesPerWork)

	lock(&work.assistQueue.lock)
	gp := work.assistQueue.head.ptr()
	for gp != nil && scanBytes > 0 {
		// Note that gp.gcAssistBytes is negative because gp
		// is in debt. Think carefully about the signs below.
		if scanBytes+gp.gcAssistBytes >= 0 {
			// Satisfy this entire assist debt.
			scanBytes += gp.gcAssistBytes
			gp.gcAssistBytes = 0
			xgp := gp
			gp = gp.schedlink.ptr()
			// It's important that we *not* put xgp in
			// runnext. Otherwise, it's possible for user
			// code to exploit the GC worker's high
			// scheduler priority to get itself always run
			// before other goroutines and always in the
			// fresh quantum started by GC.
			ready(xgp, 0, false)
		} else {
			// Partially satisfy this assist.
			gp.gcAssistBytes += scanBytes
			scanBytes = 0
			// As a heuristic, we move this assist to the
			// back of the queue so that large assists
			// can't clog up the assist queue and
			// substantially delay small assists.
			xgp := gp
			gp = gp.schedlink.ptr()
			if gp == nil {
				// gp is the only assist in the queue.
				gp = xgp
			} else {
				xgp.schedlink = 0
				work.assistQueue.tail.ptr().schedlink.set(xgp)
				work.assistQueue.tail.set(xgp)
			}
			break
		}
	}
	work.assistQueue.head.set(gp)
	if gp == nil {
		work.assistQueue.tail.set(nil)
	}

	if scanBytes > 0 {
		// Convert from scan bytes back to work.
		scanWork = int64(float64(scanBytes) * gcController.assistWorkPerByte)
		atomic.Xaddint64(&gcController.bgScanCredit, scanWork)
	}
	unlock(&work.assistQueue.lock)
}

// We use a C function to find the stack.
func doscanstack(*g, *gcWork)

// scanstack scans gp's stack, greying all pointers found on the stack.
//
// During mark phase, it also installs stack barriers while traversing
// gp's stack. During mark termination, it stops scanning when it
// reaches an unhit stack barrier.
//
// scanstack is marked go:systemstack because it must not be preempted
// while using a workbuf.
//
//go:nowritebarrier
//go:systemstack
func scanstack(gp *g, gcw *gcWork) {
	if gp.gcscanvalid {
		return
	}

	if readgstatus(gp)&_Gscan == 0 {
		print("runtime:scanstack: gp=", gp, ", goid=", gp.goid, ", gp->atomicstatus=", hex(readgstatus(gp)), "\n")
		throw("scanstack - bad status")
	}

	switch readgstatus(gp) &^ _Gscan {
	default:
		print("runtime: gp=", gp, ", goid=", gp.goid, ", gp->atomicstatus=", readgstatus(gp), "\n")
		throw("mark - bad status")
	case _Gdead:
		return
	case _Grunning:
		// ok for gccgo, though not for gc.
	case _Grunnable, _Gsyscall, _Gwaiting:
		// ok
	}

	mp := gp.m
	if mp != nil && mp.helpgc != 0 {
		throw("can't scan gchelper stack")
	}

	// Scan the stack.
	doscanstack(gp, gcw)

	// Conservatively scan the saved register values.
	scanstackblock(uintptr(unsafe.Pointer(&gp.gcregs)), unsafe.Sizeof(gp.gcregs), gcw)
	scanstackblock(uintptr(unsafe.Pointer(&gp.context)), unsafe.Sizeof(gp.context), gcw)

	if gcphase == _GCmark {
		// gp may have added itself to the rescan list between
		// when GC started and now. It's clean now, so remove
		// it. This isn't safe during mark termination because
		// mark termination is consuming this list, but it's
		// also not necessary.
		dequeueRescan(gp)
	}
	gp.gcscanvalid = true
}

// queueRescan adds gp to the stack rescan list and clears
// gp.gcscanvalid. The caller must own gp and ensure that gp isn't
// already on the rescan list.
func queueRescan(gp *g) {
	if debug.gcrescanstacks == 0 {
		// Clear gcscanvalid to keep assertions happy.
		//
		// TODO: Remove gcscanvalid entirely when we remove
		// stack rescanning.
		gp.gcscanvalid = false
		return
	}

	if gcphase == _GCoff {
		gp.gcscanvalid = false
		return
	}
	if gp.gcRescan != -1 {
		throw("g already on rescan list")
	}

	lock(&work.rescan.lock)
	gp.gcscanvalid = false

	// Recheck gcphase under the lock in case there was a phase change.
	if gcphase == _GCoff {
		unlock(&work.rescan.lock)
		return
	}
	if len(work.rescan.list) == cap(work.rescan.list) {
		throw("rescan list overflow")
	}
	n := len(work.rescan.list)
	gp.gcRescan = int32(n)
	work.rescan.list = work.rescan.list[:n+1]
	work.rescan.list[n].set(gp)
	unlock(&work.rescan.lock)
}

// dequeueRescan removes gp from the stack rescan list, if gp is on
// the rescan list. The caller must own gp.
func dequeueRescan(gp *g) {
	if debug.gcrescanstacks == 0 {
		return
	}

	if gp.gcRescan == -1 {
		return
	}
	if gcphase == _GCoff {
		gp.gcRescan = -1
		return
	}

	lock(&work.rescan.lock)
	if work.rescan.list[gp.gcRescan].ptr() != gp {
		throw("bad dequeueRescan")
	}
	// Careful: gp may itself be the last G on the list.
	last := work.rescan.list[len(work.rescan.list)-1]
	work.rescan.list[gp.gcRescan] = last
	last.ptr().gcRescan = gp.gcRescan
	gp.gcRescan = -1
	work.rescan.list = work.rescan.list[:len(work.rescan.list)-1]
	unlock(&work.rescan.lock)
}

type gcDrainFlags int

const (
	gcDrainUntilPreempt gcDrainFlags = 1 << iota
	gcDrainNoBlock
	gcDrainFlushBgCredit
	gcDrainIdle

	// gcDrainBlock means neither gcDrainUntilPreempt or
	// gcDrainNoBlock. It is the default, but callers should use
	// the constant for documentation purposes.
	gcDrainBlock gcDrainFlags = 0
)

// gcDrain scans roots and objects in work buffers, blackening grey
// objects until all roots and work buffers have been drained.
//
// If flags&gcDrainUntilPreempt != 0, gcDrain returns when g.preempt
// is set. This implies gcDrainNoBlock.
//
// If flags&gcDrainIdle != 0, gcDrain returns when there is other work
// to do. This implies gcDrainNoBlock.
//
// If flags&gcDrainNoBlock != 0, gcDrain returns as soon as it is
// unable to get more work. Otherwise, it will block until all
// blocking calls are blocked in gcDrain.
//
// If flags&gcDrainFlushBgCredit != 0, gcDrain flushes scan work
// credit to gcController.bgScanCredit every gcCreditSlack units of
// scan work.
//
//go:nowritebarrier
func gcDrain(gcw *gcWork, flags gcDrainFlags) {
	if !writeBarrier.needed {
		throw("gcDrain phase incorrect")
	}

	gp := getg().m.curg
	preemptible := flags&gcDrainUntilPreempt != 0
	blocking := flags&(gcDrainUntilPreempt|gcDrainIdle|gcDrainNoBlock) == 0
	flushBgCredit := flags&gcDrainFlushBgCredit != 0
	idle := flags&gcDrainIdle != 0

	initScanWork := gcw.scanWork
	// idleCheck is the scan work at which to perform the next
	// idle check with the scheduler.
	idleCheck := initScanWork + idleCheckThreshold

	// Drain root marking jobs.
	if work.markrootNext < work.markrootJobs {
		for !(preemptible && gp.preempt) {
			job := atomic.Xadd(&work.markrootNext, +1) - 1
			if job >= work.markrootJobs {
				break
			}
			markroot(gcw, job)
			if idle && pollWork() {
				goto done
			}
		}
	}

	// Drain heap marking jobs.
	for !(preemptible && gp.preempt) {
		// Try to keep work available on the global queue. We used to
		// check if there were waiting workers, but it's better to
		// just keep work available than to make workers wait. In the
		// worst case, we'll do O(log(_WorkbufSize)) unnecessary
		// balances.
		if work.full == 0 {
			gcw.balance()
		}

		var b uintptr
		if blocking {
			b = gcw.get()
		} else {
			b = gcw.tryGetFast()
			if b == 0 {
				b = gcw.tryGet()
			}
		}
		if b == 0 {
			// work barrier reached or tryGet failed.
			break
		}
		scanobject(b, gcw)

		// Flush background scan work credit to the global
		// account if we've accumulated enough locally so
		// mutator assists can draw on it.
		if gcw.scanWork >= gcCreditSlack {
			atomic.Xaddint64(&gcController.scanWork, gcw.scanWork)
			if flushBgCredit {
				gcFlushBgCredit(gcw.scanWork - initScanWork)
				initScanWork = 0
			}
			idleCheck -= gcw.scanWork
			gcw.scanWork = 0

			if idle && idleCheck <= 0 {
				idleCheck += idleCheckThreshold
				if pollWork() {
					break
				}
			}
		}
	}

	// In blocking mode, write barriers are not allowed after this
	// point because we must preserve the condition that the work
	// buffers are empty.

done:
	// Flush remaining scan work credit.
	if gcw.scanWork > 0 {
		atomic.Xaddint64(&gcController.scanWork, gcw.scanWork)
		if flushBgCredit {
			gcFlushBgCredit(gcw.scanWork - initScanWork)
		}
		gcw.scanWork = 0
	}
}

// gcDrainN blackens grey objects until it has performed roughly
// scanWork units of scan work or the G is preempted. This is
// best-effort, so it may perform less work if it fails to get a work
// buffer. Otherwise, it will perform at least n units of work, but
// may perform more because scanning is always done in whole object
// increments. It returns the amount of scan work performed.
//
// The caller goroutine must be in a preemptible state (e.g.,
// _Gwaiting) to prevent deadlocks during stack scanning. As a
// consequence, this must be called on the system stack.
//
//go:nowritebarrier
//go:systemstack
func gcDrainN(gcw *gcWork, scanWork int64) int64 {
	if !writeBarrier.needed {
		throw("gcDrainN phase incorrect")
	}

	// There may already be scan work on the gcw, which we don't
	// want to claim was done by this call.
	workFlushed := -gcw.scanWork

	gp := getg().m.curg
	for !gp.preempt && workFlushed+gcw.scanWork < scanWork {
		// See gcDrain comment.
		if work.full == 0 {
			gcw.balance()
		}

		// This might be a good place to add prefetch code...
		// if(wbuf.nobj > 4) {
		//         PREFETCH(wbuf->obj[wbuf.nobj - 3];
		//  }
		//
		b := gcw.tryGetFast()
		if b == 0 {
			b = gcw.tryGet()
		}

		if b == 0 {
			// Try to do a root job.
			//
			// TODO: Assists should get credit for this
			// work.
			if work.markrootNext < work.markrootJobs {
				job := atomic.Xadd(&work.markrootNext, +1) - 1
				if job < work.markrootJobs {
					markroot(gcw, job)
					continue
				}
			}
			// No heap or root jobs.
			break
		}
		scanobject(b, gcw)

		// Flush background scan work credit.
		if gcw.scanWork >= gcCreditSlack {
			atomic.Xaddint64(&gcController.scanWork, gcw.scanWork)
			workFlushed += gcw.scanWork
			gcw.scanWork = 0
		}
	}

	// Unlike gcDrain, there's no need to flush remaining work
	// here because this never flushes to bgScanCredit and
	// gcw.dispose will flush any remaining work to scanWork.

	return workFlushed + gcw.scanWork
}

// scanblock scans b as scanobject would, but using an explicit
// pointer bitmap instead of the heap bitmap.
//
// This is used to scan non-heap roots, so it does not update
// gcw.bytesMarked or gcw.scanWork.
//
//go:nowritebarrier
func scanblock(b0, n0 uintptr, ptrmask *uint8, gcw *gcWork) {
	// Use local copies of original parameters, so that a stack trace
	// due to one of the throws below shows the original block
	// base and extent.
	b := b0
	n := n0

	arena_start := mheap_.arena_start
	arena_used := mheap_.arena_used

	for i := uintptr(0); i < n; {
		// Find bits for the next word.
		bits := uint32(*addb(ptrmask, i/(sys.PtrSize*8)))
		if bits == 0 {
			i += sys.PtrSize * 8
			continue
		}
		for j := 0; j < 8 && i < n; j++ {
			if bits&1 != 0 {
				// Same work as in scanobject; see comments there.
				obj := *(*uintptr)(unsafe.Pointer(b + i))
				if obj != 0 && arena_start <= obj && obj < arena_used {
					if obj, hbits, span, objIndex := heapBitsForObject(obj, b, i, false); obj != 0 {
						greyobject(obj, b, i, hbits, span, gcw, objIndex, false)
					}
				}
			}
			bits >>= 1
			i += sys.PtrSize
		}
	}
}

// scanobject scans the object starting at b, adding pointers to gcw.
// b must point to the beginning of a heap object or an oblet.
// scanobject consults the GC bitmap for the pointer mask and the
// spans for the size of the object.
//
//go:nowritebarrier
func scanobject(b uintptr, gcw *gcWork) {
	// Note that arena_used may change concurrently during
	// scanobject and hence scanobject may encounter a pointer to
	// a newly allocated heap object that is *not* in
	// [start,used). It will not mark this object; however, we
	// know that it was just installed by a mutator, which means
	// that mutator will execute a write barrier and take care of
	// marking it. This is even more pronounced on relaxed memory
	// architectures since we access arena_used without barriers
	// or synchronization, but the same logic applies.
	arena_start := mheap_.arena_start
	arena_used := mheap_.arena_used

	// Find the bits for b and the size of the object at b.
	//
	// b is either the beginning of an object, in which case this
	// is the size of the object to scan, or it points to an
	// oblet, in which case we compute the size to scan below.
	hbits := heapBitsForAddr(b)
	s := spanOfUnchecked(b)
	n := s.elemsize
	if n == 0 {
		throw("scanobject n == 0")
	}

	if n > maxObletBytes {
		// Large object. Break into oblets for better
		// parallelism and lower latency.
		if b == s.base() {
			// It's possible this is a noscan object (not
			// from greyobject, but from other code
			// paths), in which case we must *not* enqueue
			// oblets since their bitmaps will be
			// uninitialized.
			if !hbits.hasPointers(n) {
				// Bypass the whole scan.
				gcw.bytesMarked += uint64(n)
				return
			}

			// Enqueue the other oblets to scan later.
			// Some oblets may be in b's scalar tail, but
			// these will be marked as "no more pointers",
			// so we'll drop out immediately when we go to
			// scan those.
			for oblet := b + maxObletBytes; oblet < s.base()+s.elemsize; oblet += maxObletBytes {
				if !gcw.putFast(oblet) {
					gcw.put(oblet)
				}
			}
		}

		// Compute the size of the oblet. Since this object
		// must be a large object, s.base() is the beginning
		// of the object.
		n = s.base() + s.elemsize - b
		if n > maxObletBytes {
			n = maxObletBytes
		}
	}

	var i uintptr
	for i = 0; i < n; i += sys.PtrSize {
		// Find bits for this word.
		if i != 0 {
			// Avoid needless hbits.next() on last iteration.
			hbits = hbits.next()
		}
		// Load bits once. See CL 22712 and issue 16973 for discussion.
		bits := hbits.bits()
		// During checkmarking, 1-word objects store the checkmark
		// in the type bit for the one word. The only one-word objects
		// are pointers, or else they'd be merged with other non-pointer
		// data into larger allocations.
		if i != 1*sys.PtrSize && bits&bitScan == 0 {
			break // no more pointers in this object
		}
		if bits&bitPointer == 0 {
			continue // not a pointer
		}

		// Work here is duplicated in scanblock and above.
		// If you make changes here, make changes there too.
		obj := *(*uintptr)(unsafe.Pointer(b + i))

		// At this point we have extracted the next potential pointer.
		// Check if it points into heap and not back at the current object.
		if obj != 0 && arena_start <= obj && obj < arena_used && obj-b >= n {
			// Mark the object.
			if obj, hbits, span, objIndex := heapBitsForObject(obj, b, i, false); obj != 0 {
				greyobject(obj, b, i, hbits, span, gcw, objIndex, false)
			}
		}
	}
	gcw.bytesMarked += uint64(n)
	gcw.scanWork += int64(i)
}

//go:linkname scanstackblock runtime.scanstackblock

// scanstackblock is called by the stack scanning code in C to
// actually find and mark pointers in the stack block. This is like
// scanblock, but we scan the stack conservatively, so there is no
// bitmask of pointers.
func scanstackblock(b, n uintptr, gcw *gcWork) {
	arena_start := mheap_.arena_start
	arena_used := mheap_.arena_used

	for i := uintptr(0); i < n; i += sys.PtrSize {
		// Same work as in scanobject; see comments there.
		obj := *(*uintptr)(unsafe.Pointer(b + i))
		if obj != 0 && arena_start <= obj && obj < arena_used {
			if obj, hbits, span, objIndex := heapBitsForObject(obj, b, i, true); obj != 0 {
				greyobject(obj, b, i, hbits, span, gcw, objIndex, true)
			}
		}
	}
}

// Shade the object if it isn't already.
// The object is not nil and known to be in the heap.
// Preemption must be disabled.
//go:nowritebarrier
func shade(b uintptr) {
	// shade can be called to shade a pointer found on the stack,
	// so pass forStack as true to heapBitsForObject and greyobject.
	if obj, hbits, span, objIndex := heapBitsForObject(b, 0, 0, true); obj != 0 {
		gcw := &getg().m.p.ptr().gcw
		greyobject(obj, 0, 0, hbits, span, gcw, objIndex, true)
		if gcphase == _GCmarktermination || gcBlackenPromptly {
			// Ps aren't allowed to cache work during mark
			// termination.
			gcw.dispose()
		}
	}
}

// obj is the start of an object with mark mbits.
// If it isn't already marked, mark it and enqueue into gcw.
// base and off are for debugging only and could be removed.
//go:nowritebarrierrec
func greyobject(obj, base, off uintptr, hbits heapBits, span *mspan, gcw *gcWork, objIndex uintptr, forStack bool) {
	// obj should be start of allocation, and so must be at least pointer-aligned.
	if obj&(sys.PtrSize-1) != 0 {
		throw("greyobject: obj not pointer-aligned")
	}
	mbits := span.markBitsForIndex(objIndex)

	if useCheckmark {
		if !mbits.isMarked() {
			// Stack scanning is conservative, so we can
			// see a reference to an object not previously
			// found. Assume the object was correctly not
			// marked and ignore the pointer.
			if forStack {
				return
			}
			printlock()
			print("runtime:greyobject: checkmarks finds unexpected unmarked object obj=", hex(obj), "\n")
			print("runtime: found obj at *(", hex(base), "+", hex(off), ")\n")

			// Dump the source (base) object
			gcDumpObject("base", base, off)

			// Dump the object
			gcDumpObject("obj", obj, ^uintptr(0))

			throw("checkmark found unmarked object")
		}
		if hbits.isCheckmarked(span.elemsize) {
			return
		}
		hbits.setCheckmarked(span.elemsize)
		if !hbits.isCheckmarked(span.elemsize) {
			throw("setCheckmarked and isCheckmarked disagree")
		}
	} else {
		// Stack scanning is conservative, so we can see a
		// pointer to a free object. Assume the object was
		// correctly freed and we must ignore the pointer.
		if forStack && span.isFree(objIndex) {
			return
		}

		if debug.gccheckmark > 0 && span.isFree(objIndex) {
			print("runtime: marking free object ", hex(obj), " found at *(", hex(base), "+", hex(off), ")\n")
			gcDumpObject("base", base, off)
			gcDumpObject("obj", obj, ^uintptr(0))
			throw("marking free object")
		}

		// If marked we have nothing to do.
		if mbits.isMarked() {
			return
		}
		// mbits.setMarked() // Avoid extra call overhead with manual inlining.
		atomic.Or8(mbits.bytep, mbits.mask)
		// If this is a noscan object, fast-track it to black
		// instead of greying it.
		if !hbits.hasPointers(span.elemsize) {
			gcw.bytesMarked += uint64(span.elemsize)
			return
		}
	}

	// Queue the obj for scanning. The PREFETCH(obj) logic has been removed but
	// seems like a nice optimization that can be added back in.
	// There needs to be time between the PREFETCH and the use.
	// Previously we put the obj in an 8 element buffer that is drained at a rate
	// to give the PREFETCH time to do its work.
	// Use of PREFETCHNTA might be more appropriate than PREFETCH
	if !gcw.putFast(obj) {
		gcw.put(obj)
	}
}

// gcDumpObject dumps the contents of obj for debugging and marks the
// field at byte offset off in obj.
func gcDumpObject(label string, obj, off uintptr) {
	if obj < mheap_.arena_start || obj >= mheap_.arena_used {
		print(label, "=", hex(obj), " is not in the Go heap\n")
		return
	}
	k := obj >> _PageShift
	x := k
	x -= mheap_.arena_start >> _PageShift
	s := mheap_.spans[x]
	print(label, "=", hex(obj), " k=", hex(k))
	if s == nil {
		print(" s=nil\n")
		return
	}
	print(" s.base()=", hex(s.base()), " s.limit=", hex(s.limit), " s.sizeclass=", s.sizeclass, " s.elemsize=", s.elemsize, " s.state=")
	if 0 <= s.state && int(s.state) < len(mSpanStateNames) {
		print(mSpanStateNames[s.state], "\n")
	} else {
		print("unknown(", s.state, ")\n")
	}

	skipped := false
	size := s.elemsize
	if s.state == _MSpanStack && size == 0 {
		// We're printing something from a stack frame. We
		// don't know how big it is, so just show up to an
		// including off.
		size = off + sys.PtrSize
	}
	for i := uintptr(0); i < size; i += sys.PtrSize {
		// For big objects, just print the beginning (because
		// that usually hints at the object's type) and the
		// fields around off.
		if !(i < 128*sys.PtrSize || off-16*sys.PtrSize < i && i < off+16*sys.PtrSize) {
			skipped = true
			continue
		}
		if skipped {
			print(" ...\n")
			skipped = false
		}
		print(" *(", label, "+", i, ") = ", hex(*(*uintptr)(unsafe.Pointer(obj + i))))
		if i == off {
			print(" <==")
		}
		print("\n")
	}
	if skipped {
		print(" ...\n")
	}
}

// gcmarknewobject marks a newly allocated object black. obj must
// not contain any non-nil pointers.
//
// This is nosplit so it can manipulate a gcWork without preemption.
//
//go:nowritebarrier
//go:nosplit
func gcmarknewobject(obj, size, scanSize uintptr) {
	if useCheckmark && !gcBlackenPromptly { // The world should be stopped so this should not happen.
		throw("gcmarknewobject called while doing checkmark")
	}
	markBitsForAddr(obj).setMarked()
	gcw := &getg().m.p.ptr().gcw
	gcw.bytesMarked += uint64(size)
	gcw.scanWork += int64(scanSize)
	if gcBlackenPromptly {
		// There shouldn't be anything in the work queue, but
		// we still need to flush stats.
		gcw.dispose()
	}
}

// gcMarkTinyAllocs greys all active tiny alloc blocks.
//
// The world must be stopped.
func gcMarkTinyAllocs() {
	for _, p := range &allp {
		if p == nil || p.status == _Pdead {
			break
		}
		c := p.mcache
		if c == nil || c.tiny == 0 {
			continue
		}
		_, hbits, span, objIndex := heapBitsForObject(c.tiny, 0, 0, false)
		gcw := &p.gcw
		greyobject(c.tiny, 0, 0, hbits, span, gcw, objIndex, false)
		if gcBlackenPromptly {
			gcw.dispose()
		}
	}
}

// Checkmarking

// To help debug the concurrent GC we remark with the world
// stopped ensuring that any object encountered has their normal
// mark bit set. To do this we use an orthogonal bit
// pattern to indicate the object is marked. The following pattern
// uses the upper two bits in the object's boundary nibble.
// 01: scalar  not marked
// 10: pointer not marked
// 11: pointer     marked
// 00: scalar      marked
// Xoring with 01 will flip the pattern from marked to unmarked and vica versa.
// The higher bit is 1 for pointers and 0 for scalars, whether the object
// is marked or not.
// The first nibble no longer holds the typeDead pattern indicating that the
// there are no more pointers in the object. This information is held
// in the second nibble.

// If useCheckmark is true, marking of an object uses the
// checkmark bits (encoding above) instead of the standard
// mark bits.
var useCheckmark = false

//go:nowritebarrier
func initCheckmarks() {
	useCheckmark = true
	for _, s := range mheap_.allspans {
		if s.state == _MSpanInUse {
			heapBitsForSpan(s.base()).initCheckmarkSpan(s.layout())
		}
	}
}

func clearCheckmarks() {
	useCheckmark = false
	for _, s := range mheap_.allspans {
		if s.state == _MSpanInUse {
			heapBitsForSpan(s.base()).clearCheckmarkSpan(s.layout())
		}
	}
}
