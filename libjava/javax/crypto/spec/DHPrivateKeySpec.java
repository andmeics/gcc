/* DHPrivateKeySpec.java -- Wrapper for Diffie-Hellman private keys.
   Copyright (C) 2004  Free Software Foundation, Inc.

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


package javax.crypto.spec;

import java.math.BigInteger;
import java.security.spec.KeySpec;

/**
 * A wrapper for Diffie-Hellman private key data.
 *
 * @author Casey Marshall (csm@gnu.org)
 * @since 1.4
 * @see DHPublicKeySpec
 */
public class DHPrivateKeySpec implements KeySpec
{

  // Variables.
  // ------------------------------------------------------------------------

  /** The base generator. */
  private BigInteger g;

  /** The prime modulus. */
  private BigInteger p;

  /** The private exponent. */
  private BigInteger x;

  // Constructors.
  // ------------------------------------------------------------------------

  /**
   * Create a new Diffie-Hellman private key spec.
   *
   * @param x The private exponent.
   * @param p The prime modulus.
   * @param g The base generator.
   */
  public DHPrivateKeySpec(BigInteger x, BigInteger p, BigInteger g)
  {
    this.x = x;
    this.p = p;
    this.g = g;
  }

  // Instance methods.
  // ------------------------------------------------------------------------

  /**
   * Get the base generator.
   *
   * @return The base generator.
   */
  public BigInteger getG()
  {
    return g;
  }

  /**
   * Get the prime modulus.
   *
   * @return The prime modulus.
   */
  public BigInteger getP()
  {
    return p;
  }

  /**
   * Get the private exponent.
   *
   * @return The private exponent.
   */
  public BigInteger getX()
  {
    return x;
  }
}
