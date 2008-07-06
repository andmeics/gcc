// { dg-options "-std=gnu++0x" }
// { dg-do compile }

// Copyright (C) 2008 Free Software Foundation
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

// You should have received a copy of the GNU General Public License
// along with this library; see the file COPYING.  If not, write to
// the Free Software Foundation, 51 Franklin Street, Fifth Floor,
// Boston, MA 02110-1301, USA.

#include <ratio>

#ifdef _GLIBCXX_USE_C99_STDINT_TR1

void
test01()
{
  std::ratio<INTMAX_MAX, INTMAX_MAX> r1;
  std::ratio<-INTMAX_MAX, INTMAX_MAX> r2;
}

void
test02()
{
  std::ratio<INTMAX_MIN, 1> r1;
}

void
test03()
{
  std::ratio<1, INTMAX_MIN> r1;
}

void
test04()
{
  std::ratio<1,0> r1;
}

// { dg-error "instantiated from here" "" { target *-*-* } 36 }
// { dg-error "instantiated from here" "" { target *-*-* } 42 }
// { dg-error "instantiated from here" "" { target *-*-* } 48 }
// { dg-error "denominator cannot be zero" "" { target *-*-* } 150 }
// { dg-error "out of range" "" { target *-*-* } 151 }
// { dg-excess-errors "In instantiation of" }

#endif //_GLIBCXX_USE_C99_STDINT_TR1
