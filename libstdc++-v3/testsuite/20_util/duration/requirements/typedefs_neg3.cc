// { dg-do compile }
// { dg-options "-std=gnu++0x" }
// { dg-require-cstdint "" }
// 2008-07-31 Chris Fairles <chris.fairles@gmail.com>

// Copyright (C) 2008, 2009 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#include <ratio>
#include <chrono>

void test01()
{
  // Check if period is positive
  typedef int rep_type;
  typedef std::ratio<-1> period_type;
  typedef std::chrono::duration<rep_type, period_type> test_type;
  test_type d;
}

// { dg-error "period must be positive" "" { target *-*-* } 210 }
// { dg-error "instantiated from here" "" { target *-*-* } 42 }
// { dg-excess-errors "In instantiation of" }
