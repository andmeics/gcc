/* ParseException.java -- An error occurred while parsing.
   Copyright (C) 1998, 1999, 2001 Free Software Foundation, Inc.

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


package java.text;

/* Written using "Java Class Libraries", 2nd edition, plus online
 * API docs for JDK 1.2 beta from http://www.javasoft.com.
 * Status:  Believed complete and correct.
 */

/**
  * This exception is thrown when an unexpected error occurs during parsing.
  *
  * @version 0.0
  *
  * @author Aaron M. Renn (arenn@urbanophile.com)
  * @author Per Bothner <bothner@cygnus.com>
  * @date October 25, 1998.
  */
public class ParseException extends Exception
{

/*
 * Instance Variables
 */

/**
  * This is the position where the error was encountered.
  */
private int errorOffset;

/*************************************************************************/

/*
 * Constructors
 */

/**
  * This method initializes a new instance of <code>ParseException</code>
  * with a detailed error message and a error position.
  *
  * @param msg The descriptive message describing the error.
  * @param offset The position where the error was encountered.
  */
public
ParseException(String s, int offset)
{
  super(s);
  
  errorOffset = offset;
}

/*************************************************************************/

/**
  * This method returns the position where the error occurred.
  * 
  * @return The position where the error occurred.
  */
public int
getErrorOffset()
{
  return(errorOffset);
}

} // class ParseException

