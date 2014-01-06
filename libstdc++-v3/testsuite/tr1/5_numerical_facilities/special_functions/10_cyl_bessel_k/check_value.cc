// 2007-02-04  Edward Smith-Rowland <3dw4rd@verizon.net>
//
// Copyright (C) 2007-2014 Free Software Foundation, Inc.
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

//  cyl_bessel_k


//  Compare against values generated by the GNU Scientific Library.
//  The GSL can be found on the web: http://www.gnu.org/software/gsl/

#include <tr1/cmath>
#if defined(__TEST_DEBUG)
#include <iostream>
#define VERIFY(A) \
if (!(A)) \
  { \
    std::cout << "line " << __LINE__ \
      << "  max_abs_frac = " << max_abs_frac \
      << std::endl; \
  }
#else
#include <testsuite_hooks.h>
#endif
#include "../testcase.h"


// Test data for nu=0.0000000000000000.
testcase_cyl_bessel_k<double> data001[] = {
  { 0.0036910983340425947, 0.0000000000000000, 5.0000000000000000 },
  { 1.7780062316167650e-05, 0.0000000000000000, 10.000000000000000 },
  { 9.8195364823964333e-08, 0.0000000000000000, 15.000000000000000 },
  { 5.7412378153365238e-10, 0.0000000000000000, 20.000000000000000 },
  { 3.4641615622131151e-12, 0.0000000000000000, 25.000000000000000 },
  { 2.1324774964630566e-14, 0.0000000000000000, 30.000000000000000 },
  { 1.3310351491429464e-16, 0.0000000000000000, 35.000000000000000 },
  { 8.3928611000995700e-19, 0.0000000000000000, 40.000000000000000 },
  { 5.3334561226187255e-21, 0.0000000000000000, 45.000000000000000 },
  { 3.4101677497894956e-23, 0.0000000000000000, 50.000000000000000 },
  { 2.1913102183534147e-25, 0.0000000000000000, 55.000000000000000 },
  { 1.4138978405591074e-27, 0.0000000000000000, 60.000000000000000 },
  { 9.1544673210030045e-30, 0.0000000000000000, 65.000000000000000 },
  { 5.9446613372925013e-32, 0.0000000000000000, 70.000000000000000 },
  { 3.8701170455869113e-34, 0.0000000000000000, 75.000000000000000 },
  { 2.5251198425054723e-36, 0.0000000000000000, 80.000000000000000 },
  { 1.6507623579783908e-38, 0.0000000000000000, 85.000000000000000 },
  { 1.0810242556984256e-40, 0.0000000000000000, 90.000000000000000 },
  { 7.0901249699001278e-43, 0.0000000000000000, 95.000000000000000 },
  { 4.6566282291759032e-45, 0.0000000000000000, 100.00000000000000 },
};

// Test function for nu=0.0000000000000000.
template <typename Tp>
void test001()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data001)
                         / sizeof(testcase_cyl_bessel_k<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_k(Tp(data001[i].nu), Tp(data001[i].x));
      const Tp f0 = data001[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000020e-13));
}

// Test data for nu=0.33333333333333331.
testcase_cyl_bessel_k<double> data002[] = {
  { 0.0037288750960535887, 0.33333333333333331, 5.0000000000000000 },
  { 1.7874608271055339e-05, 0.33333333333333331, 10.000000000000000 },
  { 9.8548341568798317e-08, 0.33333333333333331, 15.000000000000000 },
  { 5.7568278247790865e-10, 0.33333333333333331, 20.000000000000000 },
  { 3.4717201424907059e-12, 0.33333333333333331, 25.000000000000000 },
  { 2.1363664736611189e-14, 0.33333333333333331, 30.000000000000000 },
  { 1.3331202314165813e-16, 0.33333333333333331, 35.000000000000000 },
  { 8.4043837769480934e-19, 0.33333333333333331, 40.000000000000000 },
  { 5.3399731261024948e-21, 0.33333333333333331, 45.000000000000000 },
  { 3.4139217813583632e-23, 0.33333333333333331, 50.000000000000000 },
  { 2.1935050179185627e-25, 0.33333333333333331, 55.000000000000000 },
  { 1.4151968805623662e-27, 0.33333333333333331, 60.000000000000000 },
  { 9.1622357217019043e-30, 0.33333333333333331, 65.000000000000000 },
  { 5.9493479703461315e-32, 0.33333333333333331, 70.000000000000000 },
  { 3.8729660011055947e-34, 0.33333333333333331, 75.000000000000000 },
  { 2.5268631828013877e-36, 0.33333333333333331, 80.000000000000000 },
  { 1.6518353676138867e-38, 0.33333333333333331, 85.000000000000000 },
  { 1.0816880942511496e-40, 0.33333333333333331, 90.000000000000000 },
  { 7.0942508599231512e-43, 0.33333333333333331, 95.000000000000000 },
  { 4.6592031570213454e-45, 0.33333333333333331, 100.00000000000000 },
};

// Test function for nu=0.33333333333333331.
template <typename Tp>
void test002()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data002)
                         / sizeof(testcase_cyl_bessel_k<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_k(Tp(data002[i].nu), Tp(data002[i].x));
      const Tp f0 = data002[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000020e-13));
}

// Test data for nu=0.50000000000000000.
testcase_cyl_bessel_k<double> data003[] = {
  { 0.0037766133746428825, 0.50000000000000000, 5.0000000000000000 },
  { 1.7993478093705181e-05, 0.50000000000000000, 10.000000000000000 },
  { 9.8991312032877236e-08, 0.50000000000000000, 15.000000000000000 },
  { 5.7763739747074450e-10, 0.50000000000000000, 20.000000000000000 },
  { 3.4811912768406949e-12, 0.50000000000000000, 25.000000000000000 },
  { 2.1412375659560111e-14, 0.50000000000000000, 30.000000000000000 },
  { 1.3357311366035824e-16, 0.50000000000000000, 35.000000000000000 },
  { 8.4188091949489049e-19, 0.50000000000000000, 40.000000000000000 },
  { 5.3481305002517408e-21, 0.50000000000000000, 45.000000000000000 },
  { 3.4186200954570754e-23, 0.50000000000000000, 50.000000000000000 },
  { 2.1962515908772453e-25, 0.50000000000000000, 55.000000000000000 },
  { 1.4168223500353693e-27, 0.50000000000000000, 60.000000000000000 },
  { 9.1719554473256892e-30, 0.50000000000000000, 65.000000000000000 },
  { 5.9552114337788932e-32, 0.50000000000000000, 70.000000000000000 },
  { 3.8765301321409432e-34, 0.50000000000000000, 75.000000000000000 },
  { 2.5290440439442910e-36, 0.50000000000000000, 80.000000000000000 },
  { 1.6531776067605980e-38, 0.50000000000000000, 85.000000000000000 },
  { 1.0825184636529955e-40, 0.50000000000000000, 90.000000000000000 },
  { 7.0994115873258822e-43, 0.50000000000000000, 95.000000000000000 },
  { 4.6624238126346715e-45, 0.50000000000000000, 100.00000000000000 },
};

// Test function for nu=0.50000000000000000.
template <typename Tp>
void test003()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data003)
                         / sizeof(testcase_cyl_bessel_k<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_k(Tp(data003[i].nu), Tp(data003[i].x));
      const Tp f0 = data003[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000020e-13));
}

// Test data for nu=0.66666666666666663.
testcase_cyl_bessel_k<double> data004[] = {
  { 0.0038444246344968226, 0.66666666666666663, 5.0000000000000000 },
  { 1.8161187569530204e-05, 0.66666666666666663, 10.000000000000000 },
  { 9.9614751542305571e-08, 0.66666666666666663, 15.000000000000000 },
  { 5.8038484271925811e-10, 0.66666666666666663, 20.000000000000000 },
  { 3.4944937498488603e-12, 0.66666666666666663, 25.000000000000000 },
  { 2.1480755645577720e-14, 0.66666666666666663, 30.000000000000000 },
  { 1.3393949190152161e-16, 0.66666666666666663, 35.000000000000000 },
  { 8.4390460553642992e-19, 0.66666666666666663, 40.000000000000000 },
  { 5.3595716143622089e-21, 0.66666666666666663, 45.000000000000000 },
  { 3.4252085301433749e-23, 0.66666666666666663, 50.000000000000000 },
  { 2.2001025377982308e-25, 0.66666666666666663, 55.000000000000000 },
  { 1.4191011274172078e-27, 0.66666666666666663, 60.000000000000000 },
  { 9.1855803020269763e-30, 0.66666666666666663, 65.000000000000000 },
  { 5.9634299472578764e-32, 0.66666666666666663, 70.000000000000000 },
  { 3.8815254026478500e-34, 0.66666666666666663, 75.000000000000000 },
  { 2.5321003991943851e-36, 0.66666666666666663, 80.000000000000000 },
  { 1.6550585670593067e-38, 0.66666666666666663, 85.000000000000000 },
  { 1.0836820479428609e-40, 0.66666666666666663, 90.000000000000000 },
  { 7.1066428916285356e-43, 0.66666666666666663, 95.000000000000000 },
  { 4.6669364587280465e-45, 0.66666666666666663, 100.00000000000000 },
};

// Test function for nu=0.66666666666666663.
template <typename Tp>
void test004()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data004)
                         / sizeof(testcase_cyl_bessel_k<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_k(Tp(data004[i].nu), Tp(data004[i].x));
      const Tp f0 = data004[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000020e-13));
}

// Test data for nu=1.0000000000000000.
testcase_cyl_bessel_k<double> data005[] = {
  { 0.0040446134454521655, 1.0000000000000000, 5.0000000000000000 },
  { 1.8648773453825582e-05, 1.0000000000000000, 10.000000000000000 },
  { 1.0141729369762091e-07, 1.0000000000000000, 15.000000000000000 },
  { 5.8830579695570384e-10, 1.0000000000000000, 20.000000000000000 },
  { 3.5327780731999345e-12, 1.0000000000000000, 25.000000000000000 },
  { 2.1677320018915498e-14, 1.0000000000000000, 30.000000000000000 },
  { 1.3499178340011053e-16, 1.0000000000000000, 35.000000000000000 },
  { 8.4971319548610435e-19, 1.0000000000000000, 40.000000000000000 },
  { 5.3923945937225050e-21, 1.0000000000000000, 45.000000000000000 },
  { 3.4441022267175555e-23, 1.0000000000000000, 50.000000000000000 },
  { 2.2111422716117463e-25, 1.0000000000000000, 55.000000000000000 },
  { 1.4256320265171041e-27, 1.0000000000000000, 60.000000000000000 },
  { 9.2246195278906156e-30, 1.0000000000000000, 65.000000000000000 },
  { 5.9869736739138550e-32, 1.0000000000000000, 70.000000000000000 },
  { 3.8958329467421912e-34, 1.0000000000000000, 75.000000000000000 },
  { 2.5408531275211708e-36, 1.0000000000000000, 80.000000000000000 },
  { 1.6604444948567571e-38, 1.0000000000000000, 85.000000000000000 },
  { 1.0870134457498335e-40, 1.0000000000000000, 90.000000000000000 },
  { 7.1273442329907240e-43, 1.0000000000000000, 95.000000000000000 },
  { 4.6798537356369101e-45, 1.0000000000000000, 100.00000000000000 },
};

// Test function for nu=1.0000000000000000.
template <typename Tp>
void test005()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data005)
                         / sizeof(testcase_cyl_bessel_k<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_k(Tp(data005[i].nu), Tp(data005[i].x));
      const Tp f0 = data005[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000020e-13));
}

// Test data for nu=2.0000000000000000.
testcase_cyl_bessel_k<double> data006[] = {
  { 0.0053089437122234608, 2.0000000000000000, 5.0000000000000000 },
  { 2.1509817006932767e-05, 2.0000000000000000, 10.000000000000000 },
  { 1.1171767065031378e-07, 2.0000000000000000, 15.000000000000000 },
  { 6.3295436122922281e-10, 2.0000000000000000, 20.000000000000000 },
  { 3.7467838080691102e-12, 2.0000000000000000, 25.000000000000000 },
  { 2.2769929632558265e-14, 2.0000000000000000, 30.000000000000000 },
  { 1.4081733110858665e-16, 2.0000000000000000, 35.000000000000000 },
  { 8.8177176978426223e-19, 2.0000000000000000, 40.000000000000000 },
  { 5.5731181045619477e-21, 2.0000000000000000, 45.000000000000000 },
  { 3.5479318388581979e-23, 2.0000000000000000, 50.000000000000000 },
  { 2.2717153918665688e-25, 2.0000000000000000, 55.000000000000000 },
  { 1.4614189081096777e-27, 2.0000000000000000, 60.000000000000000 },
  { 9.4383017680150234e-30, 2.0000000000000000, 65.000000000000000 },
  { 6.1157177279757537e-32, 2.0000000000000000, 70.000000000000000 },
  { 3.9740059241667034e-34, 2.0000000000000000, 75.000000000000000 },
  { 2.5886411706935015e-36, 2.0000000000000000, 80.000000000000000 },
  { 1.6898316402103145e-38, 2.0000000000000000, 85.000000000000000 },
  { 1.1051801100484218e-40, 2.0000000000000000, 90.000000000000000 },
  { 7.2401743221736176e-43, 2.0000000000000000, 95.000000000000000 },
  { 4.7502253038886413e-45, 2.0000000000000000, 100.00000000000000 },
};

// Test function for nu=2.0000000000000000.
template <typename Tp>
void test006()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data006)
                         / sizeof(testcase_cyl_bessel_k<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_k(Tp(data006[i].nu), Tp(data006[i].x));
      const Tp f0 = data006[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000020e-13));
}

// Test data for nu=5.0000000000000000.
testcase_cyl_bessel_k<double> data007[] = {
  { 0.032706273712031865, 5.0000000000000000, 5.0000000000000000 },
  { 5.7541849985312275e-05, 5.0000000000000000, 10.000000000000000 },
  { 2.1878261369258224e-07, 5.0000000000000000, 15.000000000000000 },
  { 1.0538660139974233e-09, 5.0000000000000000, 20.000000000000000 },
  { 5.6485921365284157e-12, 5.0000000000000000, 25.000000000000000 },
  { 3.2103335105890266e-14, 5.0000000000000000, 30.000000000000000 },
  { 1.8919208406439644e-16, 5.0000000000000000, 35.000000000000000 },
  { 1.1423814375953188e-18, 5.0000000000000000, 40.000000000000000 },
  { 7.0181216822204116e-21, 5.0000000000000000, 45.000000000000000 },
  { 4.3671822541009859e-23, 5.0000000000000000, 50.000000000000000 },
  { 2.7444967640357869e-25, 5.0000000000000000, 55.000000000000000 },
  { 1.7382232741886986e-27, 5.0000000000000000, 60.000000000000000 },
  { 1.1078474298959669e-29, 5.0000000000000000, 65.000000000000000 },
  { 7.0974537081794416e-32, 5.0000000000000000, 70.000000000000000 },
  { 4.5667269500061064e-34, 5.0000000000000000, 75.000000000000000 },
  { 2.9491764420206150e-36, 5.0000000000000000, 80.000000000000000 },
  { 1.9105685973117463e-38, 5.0000000000000000, 85.000000000000000 },
  { 1.2411034311592645e-40, 5.0000000000000000, 90.000000000000000 },
  { 8.0814211331379146e-43, 5.0000000000000000, 95.000000000000000 },
  { 5.2732561132929509e-45, 5.0000000000000000, 100.00000000000000 },
};

// Test function for nu=5.0000000000000000.
template <typename Tp>
void test007()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data007)
                         / sizeof(testcase_cyl_bessel_k<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_k(Tp(data007[i].nu), Tp(data007[i].x));
      const Tp f0 = data007[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000020e-13));
}

// Test data for nu=10.000000000000000.
testcase_cyl_bessel_k<double> data008[] = {
  { 9.7585628291778121, 10.000000000000000, 5.0000000000000000 },
  { 0.0016142553003906700, 10.000000000000000, 10.000000000000000 },
  { 2.2605303776606440e-06, 10.000000000000000, 15.000000000000000 },
  { 6.3162145283215787e-09, 10.000000000000000, 20.000000000000000 },
  { 2.4076769602801230e-11, 10.000000000000000, 25.000000000000000 },
  { 1.0842816942222975e-13, 10.000000000000000, 30.000000000000000 },
  { 5.3976770429777191e-16, 10.000000000000000, 35.000000000000000 },
  { 2.8680293113671932e-18, 10.000000000000000, 40.000000000000000 },
  { 1.5939871900169603e-20, 10.000000000000000, 45.000000000000000 },
  { 9.1509882099879962e-23, 10.000000000000000, 50.000000000000000 },
  { 5.3823846249592858e-25, 10.000000000000000, 55.000000000000000 },
  { 3.2253408700563144e-27, 10.000000000000000, 60.000000000000000 },
  { 1.9613367530075138e-29, 10.000000000000000, 65.000000000000000 },
  { 1.2068471495933484e-31, 10.000000000000000, 70.000000000000000 },
  { 7.4979152649449644e-34, 10.000000000000000, 75.000000000000000 },
  { 4.6957285830490538e-36, 10.000000000000000, 80.000000000000000 },
  { 2.9606323347034084e-38, 10.000000000000000, 85.000000000000000 },
  { 1.8773542561131613e-40, 10.000000000000000, 90.000000000000000 },
  { 1.1962899527846350e-42, 10.000000000000000, 95.000000000000000 },
  { 7.6554279773881018e-45, 10.000000000000000, 100.00000000000000 },
};

// Test function for nu=10.000000000000000.
template <typename Tp>
void test008()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data008)
                         / sizeof(testcase_cyl_bessel_k<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_k(Tp(data008[i].nu), Tp(data008[i].x));
      const Tp f0 = data008[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000020e-13));
}

// Test data for nu=20.000000000000000.
testcase_cyl_bessel_k<double> data009[] = {
  { 482700052.06214869, 20.000000000000000, 5.0000000000000000 },
  { 178.74427820770549, 20.000000000000000, 10.000000000000000 },
  { 0.012141257729731146, 20.000000000000000, 15.000000000000000 },
  { 5.5431116361258155e-06, 20.000000000000000, 20.000000000000000 },
  { 6.3744029330352105e-09, 20.000000000000000, 25.000000000000000 },
  { 1.2304516475442478e-11, 20.000000000000000, 30.000000000000000 },
  { 3.2673136479809012e-14, 20.000000000000000, 35.000000000000000 },
  { 1.0703023799997383e-16, 20.000000000000000, 40.000000000000000 },
  { 4.0549953175660486e-19, 20.000000000000000, 45.000000000000000 },
  { 1.7061483797220352e-21, 20.000000000000000, 50.000000000000000 },
  { 7.7617008115659413e-24, 20.000000000000000, 55.000000000000000 },
  { 3.7482954006874725e-26, 20.000000000000000, 60.000000000000000 },
  { 1.8966880763956578e-28, 20.000000000000000, 65.000000000000000 },
  { 9.9615763479998882e-31, 20.000000000000000, 70.000000000000000 },
  { 5.3921623063091066e-33, 20.000000000000000, 75.000000000000000 },
  { 2.9920407657642272e-35, 20.000000000000000, 80.000000000000000 },
  { 1.6948662723618263e-37, 20.000000000000000, 85.000000000000000 },
  { 9.7689149642963025e-40, 20.000000000000000, 90.000000000000000 },
  { 5.7143603019220823e-42, 20.000000000000000, 95.000000000000000 },
  { 3.3852054148901700e-44, 20.000000000000000, 100.00000000000000 },
};

// Test function for nu=20.000000000000000.
template <typename Tp>
void test009()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data009)
                         / sizeof(testcase_cyl_bessel_k<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_k(Tp(data009[i].nu), Tp(data009[i].x));
      const Tp f0 = data009[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000020e-13));
}

// Test data for nu=50.000000000000000.
testcase_cyl_bessel_k<double> data010[] = {
  { 3.3943222434301628e+42, 50.000000000000000, 5.0000000000000000 },
  { 2.0613737753892579e+27, 50.000000000000000, 10.000000000000000 },
  { 1.7267736974519191e+18, 50.000000000000000, 15.000000000000000 },
  { 411711209122.01794, 50.000000000000000, 20.000000000000000 },
  { 1972478.7419813862, 50.000000000000000, 25.000000000000000 },
  { 58.770686258007267, 50.000000000000000, 30.000000000000000 },
  { 0.0058659391182535195, 50.000000000000000, 35.000000000000000 },
  { 1.3634854128794103e-06, 50.000000000000000, 40.000000000000000 },
  { 5.8652396362160840e-10, 50.000000000000000, 45.000000000000000 },
  { 4.0060134766400903e-13, 50.000000000000000, 50.000000000000000 },
  { 3.9062324485711016e-16, 50.000000000000000, 55.000000000000000 },
  { 5.0389298085176520e-19, 50.000000000000000, 60.000000000000000 },
  { 8.1305344250110396e-22, 50.000000000000000, 65.000000000000000 },
  { 1.5732816234949002e-24, 50.000000000000000, 70.000000000000000 },
  { 3.5349854993874397e-27, 50.000000000000000, 75.000000000000000 },
  { 8.9940101003189485e-30, 50.000000000000000, 80.000000000000000 },
  { 2.5403205503080723e-32, 50.000000000000000, 85.000000000000000 },
  { 7.8397596486715711e-35, 50.000000000000000, 90.000000000000000 },
  { 2.6098900651329550e-37, 50.000000000000000, 95.000000000000000 },
  { 9.2745226536133274e-40, 50.000000000000000, 100.00000000000000 },
};

// Test function for nu=50.000000000000000.
template <typename Tp>
void test010()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data010)
                         / sizeof(testcase_cyl_bessel_k<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_k(Tp(data010[i].nu), Tp(data010[i].x));
      const Tp f0 = data010[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(2.5000000000000020e-13));
}

// Test data for nu=100.00000000000000.
testcase_cyl_bessel_k<double> data011[] = {
  { 7.0398601930616797e+115, 100.00000000000000, 5.0000000000000000 },
  { 4.5966740842695286e+85, 100.00000000000000, 10.000000000000000 },
  { 8.2565552242653898e+67, 100.00000000000000, 15.000000000000000 },
  { 1.7081356456876038e+55, 100.00000000000000, 20.000000000000000 },
  { 1.9858028128780595e+45, 100.00000000000000, 25.000000000000000 },
  { 1.2131584253026677e+37, 100.00000000000000, 30.000000000000000 },
  { 1.1016916354696684e+30, 100.00000000000000, 35.000000000000000 },
  { 7.0074023297775712e+23, 100.00000000000000, 40.000000000000000 },
  { 1.9236643958470909e+18, 100.00000000000000, 45.000000000000000 },
  { 16394035276269.254, 100.00000000000000, 50.000000000000000 },
  { 343254952.89495456, 100.00000000000000, 55.000000000000000 },
  { 14870.012754946305, 100.00000000000000, 60.000000000000000 },
  { 1.1708099078572209, 100.00000000000000, 65.000000000000000 },
  { 0.00015161193930722305, 100.00000000000000, 70.000000000000000 },
  { 2.9850234381623436e-08, 100.00000000000000, 75.000000000000000 },
  { 8.3928710724649065e-12, 100.00000000000000, 80.000000000000000 },
  { 3.2033435630927728e-15, 100.00000000000000, 85.000000000000000 },
  { 1.5922281431788077e-18, 100.00000000000000, 90.000000000000000 },
  { 9.9589454577674300e-22, 100.00000000000000, 95.000000000000000 },
  { 7.6171296304940858e-25, 100.00000000000000, 100.00000000000000 },
};

// Test function for nu=100.00000000000000.
template <typename Tp>
void test011()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data011)
                         / sizeof(testcase_cyl_bessel_k<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_k(Tp(data011[i].nu), Tp(data011[i].x));
      const Tp f0 = data011[i].f0;
      const Tp diff = f - f0;
      if (std::abs(diff) > max_abs_diff)
        max_abs_diff = std::abs(diff);
      if (std::abs(f0) > Tp(10) * eps
       && std::abs(f) > Tp(10) * eps)
        {
          const Tp frac = diff / f0;
          if (std::abs(frac) > max_abs_frac)
            max_abs_frac = std::abs(frac);
        }
    }
  VERIFY(max_abs_frac < Tp(5.0000000000000039e-13));
}

int main(int, char**)
{
  test001<double>();
  test002<double>();
  test003<double>();
  test004<double>();
  test005<double>();
  test006<double>();
  test007<double>();
  test008<double>();
  test009<double>();
  test010<double>();
  test011<double>();
  return 0;
}
