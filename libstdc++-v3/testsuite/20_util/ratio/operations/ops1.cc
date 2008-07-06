// { dg-options "-std=gnu++0x" }

// 2008-07-03 Chris Fairles <chris.fairles@gmail.com>

// Copyright (C) 2008 Free Software Foundation
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this library; see the file COPYING.  If not, write to
// the Free Software Foundation, 51 Franklin Street, Fifth Floor,
// Boston, MA 02110-1301, USA.

#include <ratio>
#include <testsuite_hooks.h>

#ifdef _GLIBCXX_USE_C99_STDINT_TR1

void
test01()
{
  bool test __attribute__((unused)) = true;

  std::ratio_add<std::ratio<3,8>, std::ratio<5,12>>::type r;

  VERIFY( r.num == 19);
  VERIFY( r.den == 24);
}

void
test02()
{  
  bool test __attribute__((unused)) = true;
  std::ratio_subtract<std::ratio<3,8>, std::ratio<5,12>>::type r;

  VERIFY( r.num == -1);
  VERIFY( r.den == 24);
}

void
test03()
{
  bool test __attribute__((unused)) = true;
  std::ratio_multiply<std::ratio<3,8>, std::ratio<5,12>>::type r;

  VERIFY( r.num == 5);
  VERIFY( r.den == 32);
}

void
test04()
{
  bool test __attribute__((unused)) = true;
  std::ratio_divide<std::ratio<3,8>, std::ratio<5,12>>::type r;

  VERIFY( r.num == 9);
  VERIFY( r.den == 10);
}

#endif //_GLIBCXX_USE_C99_STDINT_TR1

int main()
{
#ifdef _GLIBCXX_USE_C99_STDINT_TR1
  test01();
  test02();
  test03();
  test04();
#endif //_GLIBCXX_USE_C99_STDINT_TR1
  return 0;
}
