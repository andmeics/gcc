/* NameClassPair.java --
   Copyright (C) 2001, 2005, 2006  Free Software Foundation, Inc.

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


package javax.naming;

import java.io.Serializable;

/**
 * @author Tom Tromey (tromey@redhat.com)
 * @date May 16, 2001
 */
public class NameClassPair implements Serializable
{
  private static final long serialVersionUID = 5620776610160863339L;

  public NameClassPair (String name, String className)
  {
    this (name, className, true);
  }

  public NameClassPair (String name, String className, boolean isRelative)
  {
    this.name = name;
    this.className = className;
    this.isRel = isRelative;
  }

  public String getClassName ()
  {
    return className;
  }

  public String getName ()
  {
    return name;
  }

  public boolean isRelative ()
  {
    return isRel;
  }

  public void setClassName (String name)
  {
    this.className = name;
  }

  public void setName (String name)
  {
    this.name = name;
  }

  public void setRelative (boolean r)
  {
    this.isRel = r;
  }

  public String toString ()
  {
    // Specified by class documentation.
    return name + ":" + className;
  }

  // These field names are fixed by the serialization spec.
  private String name;
  private String className;
  private boolean isRel;
}
