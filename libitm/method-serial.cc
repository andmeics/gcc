/* Copyright (C) 2008, 2009, 2011 Free Software Foundation, Inc.
   Contributed by Richard Henderson <rth@redhat.com>.

   This file is part of the GNU Transactional Memory Library (libitm).

   Libitm is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   Libitm is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#include "libitm_i.h"

// Avoid a dependency on libstdc++ for the pure virtuals in abi_dispatch.
extern "C" void HIDDEN
__cxa_pure_virtual ()
{
  abort ();
}

using namespace GTM;

namespace {

// This group consists of the serial, serialirr, and serialirr_onwrite
// methods, which all need no global state (except what is already provided
// by the serial mode implementation).
struct serial_mg : public method_group
{
  virtual void init() { }
  virtual void fini() { }
};

static serial_mg o_serial_mg;


class serialirr_dispatch : public abi_dispatch
{
 public:
  serialirr_dispatch() : abi_dispatch(false, true, true, false, &o_serial_mg)
  { }

 protected:
  serialirr_dispatch(bool ro, bool wt, bool uninstrumented,
      bool closed_nesting, method_group* mg) :
    abi_dispatch(ro, wt, uninstrumented, closed_nesting, mg) { }

  // Transactional loads and stores simply access memory directly.
  // These methods are static to avoid indirect calls, and will be used by the
  // virtual ABI dispatch methods or by static direct-access methods created
  // below.
  template <typename V> static V load(const V* addr, ls_modifier mod)
  {
    return *addr;
  }
  template <typename V> static void store(V* addr, const V value,
      ls_modifier mod)
  {
    *addr = value;
  }

 public:
  static void memtransfer_static(void *dst, const void* src, size_t size,
      bool may_overlap, ls_modifier dst_mod, ls_modifier src_mod)
  {
    if (!may_overlap)
      ::memcpy(dst, src, size);
    else
      ::memmove(dst, src, size);
  }

  static void memset_static(void *dst, int c, size_t size, ls_modifier mod)
  {
    ::memset(dst, c, size);
  }

  CREATE_DISPATCH_METHODS(virtual, )
  CREATE_DISPATCH_METHODS_MEM()

  virtual gtm_restart_reason begin_or_restart() { return NO_RESTART; }
  virtual bool trycommit(gtm_word& priv_time) { return true; }
  virtual void rollback(gtm_transaction_cp *cp) { abort(); }

  virtual abi_dispatch* closed_nesting_alternative()
  {
    // For nested transactions with an instrumented code path, we can do
    // undo logging.
    return GTM::dispatch_serial();
  }
};

class serial_dispatch : public abi_dispatch
{
protected:
  static void log(const void *addr, size_t len)
  {
    // TODO Ensure that this gets inlined: Use internal log interface and LTO.
    GTM_LB(addr, len);
  }

  template <typename V> static V load(const V* addr, ls_modifier mod)
  {
    return *addr;
  }
  template <typename V> static void store(V* addr, const V value,
      ls_modifier mod)
  {
    if (mod != WaW)
      log(addr, sizeof(V));
    *addr = value;
  }

public:
  static void memtransfer_static(void *dst, const void* src, size_t size,
      bool may_overlap, ls_modifier dst_mod, ls_modifier src_mod)
  {
    if (dst_mod != WaW && dst_mod != NONTXNAL)
      log(dst, size);
    if (!may_overlap)
      ::memcpy(dst, src, size);
    else
      ::memmove(dst, src, size);
  }

  static void memset_static(void *dst, int c, size_t size, ls_modifier mod)
  {
    if (mod != WaW)
      log(dst, size);
    ::memset(dst, c, size);
  }

  virtual gtm_restart_reason begin_or_restart() { return NO_RESTART; }
  virtual bool trycommit(gtm_word& priv_time) { return true; }
  // Local undo will handle this.
  // trydropreference() need not be changed either.
  virtual void rollback(gtm_transaction_cp *cp) { }

  CREATE_DISPATCH_METHODS(virtual, )
  CREATE_DISPATCH_METHODS_MEM()

  serial_dispatch() : abi_dispatch(false, true, false, true, &o_serial_mg) { }
};


// Like serialirr_dispatch but does not requests serial-irrevocable mode until
// the first write in the transaction. Can be useful for read-mostly workloads
// and testing, but is likely too simple to be of general purpose.
class serialirr_onwrite_dispatch : public serialirr_dispatch
{
 public:
  serialirr_onwrite_dispatch() :
    serialirr_dispatch(false, true, false, false, &o_serial_mg) { }

 protected:
  static void pre_write()
  {
    gtm_thread *tx = gtm_thr();
    if (!(tx->state & (gtm_thread::STATE_SERIAL
	| gtm_thread::STATE_IRREVOCABLE)))
      tx->serialirr_mode();
  }

  // Transactional loads access memory directly.
  // Transactional stores switch to serial mode first.
  template <typename V> static void store(V* addr, const V value,
      ls_modifier mod)
  {
    pre_write();
    serialirr_dispatch::store(addr, value, mod);
  }

 public:
  static void memtransfer_static(void *dst, const void* src, size_t size,
      bool may_overlap, ls_modifier dst_mod, ls_modifier src_mod)
  {
    pre_write();
    serialirr_dispatch::memtransfer_static(dst, src, size, may_overlap,
	dst_mod, src_mod);
  }

  static void memset_static(void *dst, int c, size_t size, ls_modifier mod)
  {
    pre_write();
    serialirr_dispatch::memset_static(dst, c, size, mod);
  }

  CREATE_DISPATCH_METHODS(virtual, )
  CREATE_DISPATCH_METHODS_MEM()

  virtual void rollback(gtm_transaction_cp *cp)
  {
    gtm_thread *tx = gtm_thr();
    if (tx->state & gtm_thread::STATE_IRREVOCABLE)
      abort();
  }
};

} // anon namespace

static const serialirr_dispatch o_serialirr_dispatch;
static const serial_dispatch o_serial_dispatch;
static const serialirr_onwrite_dispatch o_serialirr_onwrite_dispatch;

abi_dispatch *
GTM::dispatch_serialirr ()
{
  return const_cast<serialirr_dispatch *>(&o_serialirr_dispatch);
}

abi_dispatch *
GTM::dispatch_serial ()
{
  return const_cast<serial_dispatch *>(&o_serial_dispatch);
}

abi_dispatch *
GTM::dispatch_serialirr_onwrite ()
{
  return
      const_cast<serialirr_onwrite_dispatch *>(&o_serialirr_onwrite_dispatch);
}

// Put the transaction into serial-irrevocable mode.

void
GTM::gtm_thread::serialirr_mode ()
{
  struct abi_dispatch *disp = abi_disp ();
  bool need_restart = true;

  if (this->state & STATE_SERIAL)
    {
      if (this->state & STATE_IRREVOCABLE)
	return;

      // Try to commit the dispatch-specific part of the transaction, as we
      // would do for an outermost commit.
      // We're already serial, so we don't need to ensure privatization safety
      // for other transactions here.
      gtm_word priv_time = 0;
      bool ok = disp->trycommit (priv_time);
      // Given that we're already serial, the trycommit better work.
      assert (ok);
      need_restart = false;
    }
  else if (serial_lock.write_upgrade (this))
    {
      this->state |= STATE_SERIAL;
      // Try to commit the dispatch-specific part of the transaction, as we
      // would do for an outermost commit.
      // We have successfully upgraded to serial mode, so we don't need to
      // ensure privatization safety for other transactions here.
      gtm_word priv_time = 0;
      if (disp->trycommit (priv_time))
	need_restart = false;
    }

  if (need_restart)
    restart (RESTART_SERIAL_IRR);
  else
    {
      this->state |= (STATE_SERIAL | STATE_IRREVOCABLE);
      set_abi_disp (dispatch_serialirr ());
    }
}

void ITM_REGPARM
_ITM_changeTransactionMode (_ITM_transactionState state)
{
  assert (state == modeSerialIrrevocable);
  gtm_thr()->serialirr_mode ();
}
