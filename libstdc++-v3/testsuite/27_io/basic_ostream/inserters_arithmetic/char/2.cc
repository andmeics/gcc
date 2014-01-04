// { dg-require-namedlocale "de_DE" }

// 1999-11-15 Kevin Ediger  <kediger@licor.com>
// test the floating point inserters (facet num_put)

// Copyright (C) 1999-2014 Free Software Foundation, Inc.
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

#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <limits>
#include <testsuite_hooks.h>

void
test02()
{
  using namespace std;
  bool test __attribute__((unused)) = true;

  // Make sure we can output a long float in fixed format
  // without seg-faulting (libstdc++/4402)
  double val2 = 3.5e230;

  ostringstream os2;
  os2.precision(3);
  os2.setf(ios::fixed);

  // Check it can be done in a locale with grouping on.
  locale loc2 = locale("de_DE");
  os2.imbue(loc2);
  os2 << fixed << setprecision(3) << val2 << endl;
  os2 << endl;
  os2 << fixed << setprecision(1) << val2 << endl;
}

int 
main()
{
  test02();
  return 0;
}
