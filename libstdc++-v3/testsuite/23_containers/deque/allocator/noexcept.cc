// Copyright (C) 2014 Free Software Foundation, Inc.
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

// { dg-do compile }
// { dg-options "-std=gnu++11" }

#include <deque>
#include <testsuite_allocator.h>

struct T { int i; };

namespace __gnu_test
{
  template<typename U>
    inline void
    swap(propagating_allocator<U, true>& l, propagating_allocator<U, true>& r)
    noexcept(false)
    { }
}

using __gnu_test::propagating_allocator;

void test01()
{
  typedef std::allocator<T> alloc_type;
  typedef std::deque<T, alloc_type> test_type;
  test_type v1;
  test_type v2;
  // this is a GNU extension for std::allocator
  // static_assert( noexcept( v1 = std::move(v2) ), "Move assign cannot throw" );
  static_assert( noexcept( v1.swap(v2) ), "Swap cannot throw" );
}

void test02()
{
  typedef propagating_allocator<T, false> alloc_type;
  typedef std::deque<T, alloc_type> test_type;
  test_type v1(alloc_type(1));
  test_type v2(alloc_type(2));
  static_assert( !noexcept( v1 = std::move(v2) ), "Move assign can throw" );
  static_assert( noexcept( v1.swap(v2) ), "Swap cannot throw" );
}

void test03()
{
  typedef propagating_allocator<T, true> alloc_type;
  typedef std::deque<T, alloc_type> test_type;
  test_type v1(alloc_type(1));
  test_type v2(alloc_type(2));
  // static_assert( noexcept( v1 = std::move(v2) ), "Move assign cannot throw" );
  // noexcept spec of deque::swap depends on swap overload at top of this file
  static_assert( !noexcept( v1.swap(v2) ), "Swap can throw" );
}
