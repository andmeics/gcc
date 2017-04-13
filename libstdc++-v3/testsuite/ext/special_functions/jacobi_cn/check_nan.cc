// { dg-require-c-std "" }
// { dg-add-options ieee }
// { dg-options "-D__STDCPP_WANT_MATH_SPEC_FUNCS__" }

// Copyright (C) 2016 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// jacobi_cn

#include <cmath>
#include <testsuite_hooks.h>

void
test01()
{
  float kf = std::numeric_limits<float>::quiet_NaN();
  double kd = std::numeric_limits<double>::quiet_NaN();
  long double kl = std::numeric_limits<long double>::quiet_NaN();

  float uf = 0.5F;
  double ud = 0.5;
  long double ul = 0.5L;

  float a = __gnu_cxx::jacobi_cn(kf, uf);
  float b = __gnu_cxx::jacobi_cnf(kf, uf);
  double c = __gnu_cxx::jacobi_cn(kd, ud);
  long double d = __gnu_cxx::jacobi_cn(kl, ul);
  long double e = __gnu_cxx::jacobi_cnl(kl, ul);

  bool test [[gnu::unused]] = true;
  VERIFY(std::isnan(a));
  VERIFY(std::isnan(b));
  VERIFY(std::isnan(c));
  VERIFY(std::isnan(d));
  VERIFY(std::isnan(e));

  return;
}

void
test02()
{
  float kf = 1.5F;
  double kd = 1.5;
  long double kl = 1.5L;

  float uf = std::numeric_limits<float>::quiet_NaN();
  double ud = std::numeric_limits<double>::quiet_NaN();
  long double ul = std::numeric_limits<long double>::quiet_NaN();

  float a = __gnu_cxx::jacobi_cn(kf, uf);
  float b = __gnu_cxx::jacobi_cnf(kf, uf);
  double c = __gnu_cxx::jacobi_cn(kd, ud);
  long double d = __gnu_cxx::jacobi_cn(kl, ul);
  long double e = __gnu_cxx::jacobi_cnl(kl, ul);

  bool test [[gnu::unused]] = true;
  VERIFY(std::isnan(a));
  VERIFY(std::isnan(b));
  VERIFY(std::isnan(c));
  VERIFY(std::isnan(d));
  VERIFY(std::isnan(e));

  return;
}

int
main()
{
  test01();
  test02();
  return 0;
}

