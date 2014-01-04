// { dg-do compile }
// { dg-options "-std=gnu++11" }
// { dg-require-cstdint "" }
// { dg-require-gthreads "" }

// Copyright (C) 2012-2014 Free Software Foundation, Inc.
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
#include <memory>
#include <functional>

template<typename, typename...P>
void make_shared(P&&...)
{}

struct C {};

void f(C){}

// PR libstdc++/53872
int main()
{
  std::thread t(std::bind(&::f, C()));
}
