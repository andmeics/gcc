// { dg-do run { target *-*-linux* *-*-gnu* *-*-solaris* powerpc-ibm-aix* } }
// { dg-options " -std=gnu++0x -pthread" { target *-*-linux* *-*-gnu* powerpc-ibm-aix* } }
// { dg-options " -std=gnu++0x -pthreads" { target *-*-solaris* } }
// { dg-require-cstdint "" }
// { dg-require-gthreads "" }

// Copyright (C) 2009-2014 Free Software Foundation, Inc.
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

#include <thread>
#include <thread/all.h>

int main()
{
  typedef std::thread test_type;
  __gnu_test::compare_type_to_native_type<test_type>();
  return 0;
}
