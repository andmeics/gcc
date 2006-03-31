/* DGCImpl.java --
   Copyright (c) 1996, 1997, 1998, 1999, 2002, 2005
   Free Software Foundation, Inc.

This file is part of GNU Classpath.

GNU Classpath is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Classpath is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Classpath; see the file COPYING.  If not, write to the
Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301 USA.

Linking this library statically or dynamically with other modules is
making a combined work based on this library.  Thus, the terms and
conditions of the GNU General Public License cover the whole
combination.

As a special exception, the copyright holders of this library give you
permission to link this library with independent modules to produce an
executable, regardless of the license terms of these independent
modules, and to copy and distribute the resulting executable under
terms of your choice, provided that you also meet, for each linked
independent module, the terms and conditions of the license of that
module.  An independent module is a module which is not derived from
or based on this library.  If you modify this library, you may extend
this exception to your version of the library, but you are not
obligated to do so.  If you do not wish to do so, delete this
exception statement from your version. */

package gnu.java.rmi.dgc;

import gnu.java.rmi.server.UnicastServerRef;

import java.rmi.RemoteException;
import java.rmi.dgc.DGC;
import java.rmi.dgc.Lease;
import java.rmi.dgc.VMID;
import java.rmi.server.ObjID;
import java.rmi.server.RMISocketFactory;
import java.util.Hashtable;

/**
 * The DGC implementation is used for the server side during the distributed
 * garbage collection. This interface contains the two methods: dirty and clean.
 * A dirty call is made when a remote reference is unmarshaled in a client. A
 * corresponding clean call is made by client it no longer uses that remote
 * reference. A reference to a remote object is also automatically released
 * after so called lease period that starts after the dirty call is received. It
 * is the client's responsibility to renew the leases, by making additional
 * dirty calls before such leases expire.
 */
public class DGCImpl
    extends UnicastServerRef
    implements DGC
{
  /*
   * The DGCImpl extends UnicastServerRef and not UnicastRemoteObject, because
   * UnicastRemoteObject must exportObject automatically.
   */
  
  /**
   * This defauld lease value is used if the lease value, passed to the
   * {@link #dirty} is equal to zero.
   */
  static final long LEASE_VALUE = 600000L;

  // leaseCache caches a LeaseRecord associated with a vmid
  Hashtable leaseCache = new Hashtable();

  public DGCImpl() throws RemoteException
  {
    super(new ObjID(ObjID.DGC_ID), 0, RMISocketFactory.getSocketFactory());
  }

  /**
   * Mark the given objects referecnes as used on the client side.
   * 
   * @param ids the ids of the used objects.
   * @param sequenceNum the number of the call (used to detect and discard late
   *          calls).
   * @param lease the requested lease
   * @return the granted lease
   */
  public Lease dirty(ObjID[] ids, long sequenceNum, Lease lease)
      throws RemoteException
  {
    VMID vmid = lease.getVMID();
    if (vmid == null)
      vmid = new VMID();

    long leaseValue = lease.getValue();
    if (leaseValue <= 0)
      leaseValue = LEASE_VALUE;

    lease = new Lease(vmid, leaseValue);
    LeaseRecord lr = (LeaseRecord) leaseCache.get(vmid);
    if (lr != null)
      lr.reset(leaseValue);
    else
      {
        lr = new LeaseRecord(vmid, leaseValue, ids);
        leaseCache.put(vmid, lr);
      }
    
    return (lease);
  }

  /**
   * Mark the given objects as no longer used on the client side.
   * 
   * @param ids the ids of the objects that are no longer used.
   * @param sequenceNum the number of the call (used to detect and discard late
   *          calls)
   * @param vmid the VMID of the client.
   * @param strong make the "strong" clean call.
   */
  public void clean(ObjID[] ids, long sequenceNum, VMID vmid, boolean strong)
      throws RemoteException
  {
    // Not implemented
    // TODO implement
  }

  /**
   * LeaseRecord associates a vmid to expireTime.
   */
  static class LeaseRecord
  {
    /**
     * The lease id.
     */
    final VMID vmid;

    /**
     * The lease expiration time.
     */ 
    long expireTime;
    
    /**
     * The array of ObjeID's that must be protected from being garbage
     * collected.
     */
    final ObjID [] objects;

    /**
     * Create the new lease record.
     * 
     * @param vmid lease id.
     * @param leaseValue lease value
     */
    LeaseRecord(VMID vmid, long leaseValue, ObjID [] an_objects)
    {
      this.vmid = vmid;
      reset(leaseValue);
      objects = an_objects;
    }

    /**
     * Prolong the expiration time till current time + passed value
     * 
     * @param leaseValue the value after that (since the current moment)
     * the lease should expire in the future.
     */
    void reset(long leaseValue)
    {
      long l = System.currentTimeMillis();
      expireTime = l + leaseValue;
    }
    
    /**
     * Check if the lease has been expired.
     * 
     * @return true if the lease has been expired, false if it is still valid.
     */
    boolean isExpired()
    {
      long l = System.currentTimeMillis();
      if (l > expireTime)
        return true;
      return false;
    }

  } // End of LeaseRecord

} // End of DGCImpl
