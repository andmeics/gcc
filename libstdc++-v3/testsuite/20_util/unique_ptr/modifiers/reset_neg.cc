// { dg-do compile }
// { dg-options "-std=gnu++0x" }

// Copyright (C) 2008, 2009 Free Software Foundation
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

#include <memory>

struct A
{
};

struct B : A
{
  virtual ~B() { }
};

void test01()
{
  std::unique_ptr<B[]> up;
  up.reset(new A[3]);
}

// { dg-error "used here" "" { target *-*-* } 36 } 
// { dg-error "deleted function" "" { target *-*-* } 355 }
