// { dg-do compile { target c++14 } }

// Copyright (C) 2014-2017 Free Software Foundation, Inc.
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

#include <chrono>

void
test01()
{
  using namespace std::literals::chrono_literals;

  // std::numeric_limits<int64_t>::max() == 9223372036854775807;
  auto h = 9223372036854775808h;
  // { dg-error "cannot be represented" "" { target *-*-* } 880 }
}
// { dg-prune-output "in constexpr expansion" } // needed for -O0
