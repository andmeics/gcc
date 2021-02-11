// Copyright (C) 2020 Free Software Foundation, Inc.
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

// { dg-options "-std=gnu++17" }
// { dg-do compile { target c++17 } }

#include <numeric>
#include <limits.h>

void
test01()
{
  // PR libstdc++/92978
  static_assert( std::gcd(-120, 10U) == 10 );
  static_assert( std::gcd(120U, -10) == 10 );
}

void
test02()
{
  // |INT_MIN| should not be undefined, as long as it fits in the result type.
  static_assert( std::gcd(INT_MIN, 0LL) == 1LL+INT_MAX );
  static_assert( std::gcd(0LL, INT_MIN) == 1LL+INT_MAX );
  static_assert( std::gcd(INT_MIN, 0LL + INT_MIN) == 1LL + INT_MAX );
  static_assert( std::gcd(INT_MIN, 1LL + INT_MAX) == 1LL + INT_MAX );
  static_assert( std::gcd(SHRT_MIN, 1U + SHRT_MAX) == 1U + SHRT_MAX );
}
