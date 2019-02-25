// Copyright (C) 2019 Free Software Foundation, Inc.
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

// { dg-do compile { target c++11 } }

#include <type_traits>

// Test for SFINAE-friendly underlying_type

template<typename T, typename = typename std::underlying_type<T>::type>
  constexpr bool is_enum(int) { return true; }

template<typename T>
  constexpr bool is_enum(...) { return false; }

void
test01()
{
  enum E { };
  static_assert( is_enum<E>(0), "");

  static_assert( !is_enum<void>(0), "");
  static_assert( !is_enum<int>(0), "");
  static_assert( !is_enum<long>(0), "");
  static_assert( !is_enum<int*>(0), "");
  static_assert( !is_enum<int[]>(0), "");
  static_assert( !is_enum<const int*>(0), "");
  static_assert( !is_enum<const int&>(0), "");
  static_assert( !is_enum<int()>(0), "");
  static_assert( !is_enum<int(&)()>(0), "");
  static_assert( !is_enum<int(*)()>(0), "");
  struct S { };
  static_assert( !is_enum<S>(0), "");
  static_assert( !is_enum<S&>(0), "");
  static_assert( !is_enum<S*>(0), "");
  static_assert( !is_enum<int S::*>(0), "");
  static_assert( !is_enum<int (S::*)()>(0), "");
}
