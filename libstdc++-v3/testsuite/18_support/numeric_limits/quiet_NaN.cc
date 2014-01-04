// { dg-add-options ieee }

// 1999-08-23 bkoz

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

// 18.2.1.1 template class numeric_limits

#include <limits>
#include <limits.h>
#include <float.h>
#include <cwchar>
#include <testsuite_hooks.h>

template<typename T>
void
test_qnan()
{
  bool test;

  if (std::numeric_limits<T>::has_quiet_NaN)
    {
      T nan = std::numeric_limits<T>::quiet_NaN();
      test = (nan != nan);
    }
  else
    test = true;

  VERIFY (test);
}

int main()
{
  test_qnan<float>();
  test_qnan<double>();
  test_qnan<long double>();

  return 0;
}
