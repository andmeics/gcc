/* AbstractSelector.java -- 
   Copyright (C) 2002 Free Software Foundation, Inc.

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
Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
02111-1307 USA.

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


package java.nio.channels.spi;

import java.io.IOException;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.util.Set;

public abstract class AbstractSelector extends Selector
{
  boolean closed = false;
  SelectorProvider provider;

  /**
   * Initializes the slector.
   */
  protected AbstractSelector (SelectorProvider provider)
  {
    this.provider = provider;
  }
 
  /**
   * Marks the beginning of an I/O operation that might block indefinitely.
   */
  protected final void begin ()
  {
  }

  /**
   * Closes the channel.
   * 
   * @exception IOException If an error occurs
   */
  public final void close () throws IOException
  {
    if (closed)
      return;
    
    closed = true;
    implCloseSelector ();
  }

  /**
   * Tells whether this channel is open or not.
   */
  public final boolean isOpen ()
  {
    return ! closed;
  }

  protected final void deregister (AbstractSelectionKey key)
  {
    cancelledKeys ().remove (key);
  }
    
  protected final void end()
  {
  }
    
  public final SelectorProvider provider ()
  {
    return provider;
  }

  protected final Set cancelledKeys()
  {
    return null;
  }

  /**
   * Closes the channel.
   */
  protected abstract void implCloseSelector () throws IOException;

  protected abstract SelectionKey register (AbstractSelectableChannel ch,
                                            int ops, Object att);   
}
