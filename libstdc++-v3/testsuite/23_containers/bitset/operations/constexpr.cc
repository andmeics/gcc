// { dg-do compile }
// { dg-options "-std=gnu++0x" }

// Copyright (C) 2011 Free Software Foundation, Inc.
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

#include <bitset>

int main()
{
  // bitset base type
  typedef std::_Base_bitset<6> bitset_base;
  constexpr bitset_base base = bitset_base();

  constexpr auto r1 = base._M_getword(2);
  // constexpr auto r2 = base._M_getdata(); // error, pointer to this
  auto r2 = base._M_getdata(); 
  constexpr auto r3 = base._M_hiword();

  // bitset operators
  typedef std::bitset<6> bitset_type;
  constexpr bitset_type a = bitset_type();
  constexpr auto v = a[0];

  return 0;
}
