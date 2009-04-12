// { dg-options "-std=gnu++0x" }

// Copyright (C) 2005, 2006, 2007, 2009 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.


#include <deque>
#include <testsuite_hooks.h>
#include <testsuite_rvalref.h>

using namespace __gnu_test;

// According to n1771, there should be two resizes, with and without
// parameter. We only have one at present, whose second parameter defaults
// to a default-constructed object.
void
test01()
{
  bool test __attribute__((unused)) = true;

  std::deque<copycounter> a;
  copycounter::copycount = 0;
  a.resize(10);
  a.resize(98);
  a.resize(99);
  a.resize(100);
#ifndef _GLIBCXX_DEBUG
  VERIFY( copycounter::copycount == 100 );
#else
  VERIFY( copycounter::copycount == 100 + 4 );
#endif
  a.resize(99);
  a.resize(0);
#ifndef _GLIBCXX_DEBUG
  VERIFY( copycounter::copycount == 100 );
#else
  VERIFY( copycounter::copycount == 100 + 6 );
#endif
  a.resize(100);
#ifndef _GLIBCXX_DEBUG
  VERIFY( copycounter::copycount == 200 );
#else
  VERIFY( copycounter::copycount == 200 + 7 );
#endif
  a.clear();
#ifndef _GLIBCXX_DEBUG
  VERIFY( copycounter::copycount == 200 );
#else
  VERIFY( copycounter::copycount == 200 + 7 );
#endif
}


int main()
{
  test01();
  return 0;
}
