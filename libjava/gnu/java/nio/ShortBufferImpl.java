/* ShortBufferImpl.java -- 
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

package gnu.java.nio;

import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.DoubleBuffer;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;
import java.nio.LongBuffer;
import java.nio.ShortBuffer;

public final class ShortBufferImpl extends ShortBuffer
{
  private int array_offset;
  private boolean ro;

  public ShortBufferImpl(int cap, int off, int lim)
  {
    this.backing_buffer = new short[cap];
    this.cap = cap ;
    this.position(off);
    this.limit(lim);
  }

  public ShortBufferImpl(short[] array, int off, int lim)
  {
    this.backing_buffer = array;
    this.cap = array.length;
    this.position(off);
    this.limit(lim);
  }

  public ShortBufferImpl(ShortBufferImpl copy)
  {
    backing_buffer = copy.backing_buffer;
    ro = copy.ro;
    position(copy.position());
    limit(copy.limit());
  }

  void inc_pos(int a)
  {
    position(position() + a);
  }

//   private static native short[] nio_cast(byte[]copy);
//   private static native short[] nio_cast(char[]copy);
//   private static native short[] nio_cast(short[]copy);
//   private static native short[] nio_cast(long[]copy);
//   private static native short[] nio_cast(int[]copy);
//   private static native short[] nio_cast(float[]copy);
//   private static native short[] nio_cast(double[]copy);

  private static short[] nio_cast(byte[]copy) { return null; };
  private static short[] nio_cast(char[]copy) { return null; };
  private static short[] nio_cast(short[]copy) { return null; };
  private static short[] nio_cast(long[]copy) { return null; };
  private static short[] nio_cast(int[]copy) { return null; };
  private static short[] nio_cast(float[]copy) { return null; };
  private static short[] nio_cast(double[]copy) { return null; };

  ShortBufferImpl(byte[] copy) { this.backing_buffer = copy != null ? nio_cast(copy) : null; }
//   private static native byte nio_get_Byte(ShortBufferImpl b, int index, int limit);
//   private static native void nio_put_Byte(ShortBufferImpl b, int index, int limit, byte value);
  private static byte nio_get_Byte(ShortBufferImpl b, int index, int limit) { return 0; };
  private static void nio_put_Byte(ShortBufferImpl b, int index, int limit, byte value) { };
  public java.nio. ByteBuffer asByteBuffer() { gnu.java.nio. ByteBufferImpl res = new gnu.java.nio. ByteBufferImpl(backing_buffer); res.limit((limit()*1)/2); return res; }

  ShortBufferImpl(char[] copy) { this.backing_buffer = copy != null ? nio_cast(copy) : null; }
//   private static native char nio_get_Char(ShortBufferImpl b, int index, int limit);
//   private static native void nio_put_Char(ShortBufferImpl b, int index, int limit, char value);
  private static char nio_get_Char(ShortBufferImpl b, int index, int limit) { return ' '; };
  private static void nio_put_Char(ShortBufferImpl b, int index, int limit, char value) { };
  public java.nio. CharBuffer asCharBuffer() { gnu.java.nio. CharBufferImpl res = new gnu.java.nio. CharBufferImpl(backing_buffer); res.limit((limit()*2)/2); return res; }

  ShortBufferImpl(short[] copy) { this.backing_buffer = copy != null ? nio_cast(copy) : null; }
//   private static native short nio_get_Short(ShortBufferImpl b, int index, int limit);
//   private static native void nio_put_Short(ShortBufferImpl b, int index, int limit, short value);
  private static short nio_get_Short(ShortBufferImpl b, int index, int limit) { return 0; };
  private static void nio_put_Short(ShortBufferImpl b, int index, int limit, short value) { };
  public java.nio. ShortBuffer asShortBuffer() { gnu.java.nio. ShortBufferImpl res = new gnu.java.nio. ShortBufferImpl(backing_buffer); res.limit((limit()*2)/2); return res; }

  ShortBufferImpl(int[] copy) { this.backing_buffer = copy != null ? nio_cast(copy) : null; }
//   private static native int nio_get_Int(ShortBufferImpl b, int index, int limit);
//   private static native void nio_put_Int(ShortBufferImpl b, int index, int limit, int value);
  private static int nio_get_Int(ShortBufferImpl b, int index, int limit) { return 0; };
  private static void nio_put_Int(ShortBufferImpl b, int index, int limit, int value) { };
  public java.nio. IntBuffer asIntBuffer() { gnu.java.nio. IntBufferImpl res = new gnu.java.nio. IntBufferImpl(backing_buffer); res.limit((limit()*4)/2); return res; }

  ShortBufferImpl(long[] copy) { this.backing_buffer = copy != null ? nio_cast(copy) : null; }
//   private static native long nio_get_Long(ShortBufferImpl b, int index, int limit);
//   private static native void nio_put_Long(ShortBufferImpl b, int index, int limit, long value);
  private static long nio_get_Long(ShortBufferImpl b, int index, int limit) { return 0; };
  private static void nio_put_Long(ShortBufferImpl b, int index, int limit, long value) { };
  public java.nio. LongBuffer asLongBuffer() { gnu.java.nio. LongBufferImpl res = new gnu.java.nio. LongBufferImpl(backing_buffer); res.limit((limit()*8)/2); return res; }

  ShortBufferImpl(float[] copy) { this.backing_buffer = copy != null ? nio_cast(copy) : null; }
//   private static native float nio_get_Float(ShortBufferImpl b, int index, int limit);
//   private static native void nio_put_Float(ShortBufferImpl b, int index, int limit, float value);
  private static float nio_get_Float(ShortBufferImpl b, int index, int limit) { return 0.0f; };
  private static void nio_put_Float(ShortBufferImpl b, int index, int limit, float value) { };
  public java.nio. FloatBuffer asFloatBuffer() { gnu.java.nio. FloatBufferImpl res = new gnu.java.nio. FloatBufferImpl(backing_buffer); res.limit((limit()*4)/2); return res; }

  ShortBufferImpl(double[] copy) { this.backing_buffer = copy != null ? nio_cast(copy) : null; }
//   private static native double nio_get_Double(ShortBufferImpl b, int index, int limit);
//   private static native void nio_put_Double(ShortBufferImpl b, int index, int limit, double value);
  private static double nio_get_Double(ShortBufferImpl b, int index, int limit) { return 0.0d; };
  private static void nio_put_Double(ShortBufferImpl b, int index, int limit, double value) { };
  public java.nio. DoubleBuffer asDoubleBuffer() { gnu.java.nio. DoubleBufferImpl res = new gnu.java.nio. DoubleBufferImpl(backing_buffer); res.limit((limit()*8)/2); return res; }

  public boolean isReadOnly()
  {
    return ro;
  }

  public ShortBuffer slice()
  {
    ShortBufferImpl a = new ShortBufferImpl(this);
    a.array_offset = position();
    return a;
  }

  public ShortBuffer duplicate()
  {
    return new ShortBufferImpl(this);
  }

  public ShortBuffer asReadOnlyBuffer()
  {
    ShortBufferImpl a = new ShortBufferImpl(this);
    a.ro = true;
    return a;
  }

  public ShortBuffer compact()
  {
    return this;
  }

  public boolean isDirect()
  {
    return backing_buffer != null;
  }

  final public short get()
  {
    short e = backing_buffer[position()];
    position(position()+1);
    return e;
  }

  final public ShortBuffer put(short b)
  {
    backing_buffer[position()] = b;
    position(position()+1);
    return this;
  }

  final public short get(int index)
  {
    return backing_buffer[index];
  }

  final public ShortBuffer put(int index, short b)
  {
    backing_buffer[index] = b;
    return this;
  }

  final public char getChar() { char a = nio_get_Char(this, position(), limit()); inc_pos(2); return a; } final public java.nio. ShortBuffer putChar(char value) { nio_put_Char(this, position(), limit(), value); inc_pos(2); return this; } final public char getChar(int index) { char a = nio_get_Char(this, index, limit()); return a; } final public java.nio. ShortBuffer putChar(int index, char value) { nio_put_Char(this, index, limit(), value); return this; };
  final public short getShort() { return get(); } final public java.nio. ShortBuffer putShort(short value) { return put(value); } final public short getShort(int index) { return get(index); } final public java.nio. ShortBuffer putShort(int index, short value) { return put(index, value); };
  final public int getInt() { int a = nio_get_Int(this, position(), limit()); inc_pos(4); return a; } final public java.nio. ShortBuffer putInt(int value) { nio_put_Int(this, position(), limit(), value); inc_pos(4); return this; } final public int getInt(int index) { int a = nio_get_Int(this, index, limit()); return a; } final public java.nio. ShortBuffer putInt(int index, int value) { nio_put_Int(this, index, limit(), value); return this; };
  final public long getLong() { long a = nio_get_Long(this, position(), limit()); inc_pos(8); return a; } final public java.nio. ShortBuffer putLong(long value) { nio_put_Long(this, position(), limit(), value); inc_pos(8); return this; } final public long getLong(int index) { long a = nio_get_Long(this, index, limit()); return a; } final public java.nio. ShortBuffer putLong(int index, long value) { nio_put_Long(this, index, limit(), value); return this; };
  final public float getFloat() { float a = nio_get_Float(this, position(), limit()); inc_pos(4); return a; } final public java.nio. ShortBuffer putFloat(float value) { nio_put_Float(this, position(), limit(), value); inc_pos(4); return this; } final public float getFloat(int index) { float a = nio_get_Float(this, index, limit()); return a; } final public java.nio. ShortBuffer putFloat(int index, float value) { nio_put_Float(this, index, limit(), value); return this; };
  final public double getDouble() { double a = nio_get_Double(this, position(), limit()); inc_pos(8); return a; } final public java.nio. ShortBuffer putDouble(double value) { nio_put_Double(this, position(), limit(), value); inc_pos(8); return this; } final public double getDouble(int index) { double a = nio_get_Double(this, index, limit()); return a; } final public java.nio. ShortBuffer putDouble(int index, double value) { nio_put_Double(this, index, limit(), value); return this; };
}
