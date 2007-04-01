// 2007-02-04  Edward Smith-Rowland <3dw4rd@verizon.net>
//
// Copyright (C) 2007 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

//  cyl_bessel_i


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
testcase_cyl_bessel_i<double> data001[] = {
  { 1.0000000000000000, 0.0000000000000000, 0.0000000000000000 },
  { 27.239871823604439, 0.0000000000000000, 5.0000000000000000 },
  { 2815.7166284662558, 0.0000000000000000, 10.000000000000000 },
  { 339649.37329791381, 0.0000000000000000, 15.000000000000000 },
  { 43558282.559553474, 0.0000000000000000, 20.000000000000000 },
  { 5774560606.4663124, 0.0000000000000000, 25.000000000000000 },
  { 781672297823.97925, 0.0000000000000000, 30.000000000000000 },
  { 107338818494514.42, 0.0000000000000000, 35.000000000000000 },
  { 14894774793419918., 0.0000000000000000, 40.000000000000000 },
  { 2.0834140751773158e+18, 0.0000000000000000, 45.000000000000000 },
  { 2.9325537838493463e+20, 0.0000000000000000, 50.000000000000000 },
  { 4.1487895607332160e+22, 0.0000000000000000, 55.000000000000000 },
  { 5.8940770556098216e+24, 0.0000000000000000, 60.000000000000000 },
  { 8.4030398456255610e+26, 0.0000000000000000, 65.000000000000000 },
  { 1.2015889579125422e+29, 0.0000000000000000, 70.000000000000000 },
  { 1.7226390780357971e+31, 0.0000000000000000, 75.000000000000000 },
  { 2.4751784043341670e+33, 0.0000000000000000, 80.000000000000000 },
  { 3.5634776304081418e+35, 0.0000000000000000, 85.000000000000000 },
  { 5.1392383455086475e+37, 0.0000000000000000, 90.000000000000000 },
  { 7.4233258618752096e+39, 0.0000000000000000, 95.000000000000000 },
  { 1.0737517071310986e+42, 0.0000000000000000, 100.00000000000000 },
};

// Test function for nu=0.0000000000000000.
template <typename Tp>
void test001()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data001)
                         / sizeof(testcase_cyl_bessel_i<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_i(Tp(data001[i].nu), Tp(data001[i].x));
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
  VERIFY(max_abs_frac < Tp(2.5000000000000015e-12));
}

// Test data for nu=0.33333333333333331.
testcase_cyl_bessel_i<double> data002[] = {
  { 0.0000000000000000, 0.33333333333333331, 0.0000000000000000 },
  { 26.897553069268362, 0.33333333333333331, 5.0000000000000000 },
  { 2799.2396097056790, 0.33333333333333331, 10.000000000000000 },
  { 338348.63146593655, 0.33333333333333331, 15.000000000000000 },
  { 43434263.927938439, 0.33333333333333331, 20.000000000000000 },
  { 5761474759.6213636, 0.33333333333333331, 25.000000000000000 },
  { 780201111830.30225, 0.33333333333333331, 30.000000000000000 },
  { 107166066959051.92, 0.33333333333333331, 35.000000000000000 },
  { 14873836574083760., 0.33333333333333331, 40.000000000000000 },
  { 2.0808143020217085e+18, 0.33333333333333331, 45.000000000000000 },
  { 2.9292639365644229e+20, 0.33333333333333331, 50.000000000000000 },
  { 4.1445621624120489e+22, 0.33333333333333331, 55.000000000000000 },
  { 5.8885758374365916e+24, 0.33333333333333331, 60.000000000000000 },
  { 8.3958047021083955e+26, 0.33333333333333331, 65.000000000000000 },
  { 1.2006287819446431e+29, 0.33333333333333331, 70.000000000000000 },
  { 1.7213548977150022e+31, 0.33333333333333331, 75.000000000000000 },
  { 2.4734492458444449e+33, 0.33333333333333331, 80.000000000000000 },
  { 3.5611354547857122e+35, 0.33333333333333331, 85.000000000000000 },
  { 5.1360491295551829e+37, 0.33333333333333331, 90.000000000000000 },
  { 7.4189629097600431e+39, 0.33333333333333331, 95.000000000000000 },
  { 1.0731523308358370e+42, 0.33333333333333331, 100.00000000000000 },
};

// Test function for nu=0.33333333333333331.
template <typename Tp>
void test002()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data002)
                         / sizeof(testcase_cyl_bessel_i<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_i(Tp(data002[i].nu), Tp(data002[i].x));
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
  VERIFY(max_abs_frac < Tp(1.0000000000000008e-12));
}

// Test data for nu=0.50000000000000000.
testcase_cyl_bessel_i<double> data003[] = {
  { 0.0000000000000000, 0.50000000000000000, 0.0000000000000000 },
  { 26.477547497559065, 0.50000000000000000, 5.0000000000000000 },
  { 2778.7846038745711, 0.50000000000000000, 10.000000000000000 },
  { 336729.88718706399, 0.50000000000000000, 15.000000000000000 },
  { 43279746.272428922, 0.50000000000000000, 20.000000000000000 },
  { 5745159748.3464680, 0.50000000000000000, 25.000000000000000 },
  { 778366068840.44580, 0.50000000000000000, 30.000000000000000 },
  { 106950522408567.66, 0.50000000000000000, 35.000000000000000 },
  { 14847705549021962., 0.50000000000000000, 40.000000000000000 },
  { 2.0775691824625661e+18, 0.50000000000000000, 45.000000000000000 },
  { 2.9251568529912988e+20, 0.50000000000000000, 50.000000000000000 },
  { 4.1392840094781220e+22, 0.50000000000000000, 55.000000000000000 },
  { 5.8817065760751945e+24, 0.50000000000000000, 60.000000000000000 },
  { 8.3867695787277231e+26, 0.50000000000000000, 65.000000000000000 },
  { 1.1994296461653203e+29, 0.50000000000000000, 70.000000000000000 },
  { 1.7197510246063332e+31, 0.50000000000000000, 75.000000000000000 },
  { 2.4712895036230794e+33, 0.50000000000000000, 80.000000000000000 },
  { 3.5582099086757769e+35, 0.50000000000000000, 85.000000000000000 },
  { 5.1320654031231090e+37, 0.50000000000000000, 90.000000000000000 },
  { 7.4135128383495227e+39, 0.50000000000000000, 95.000000000000000 },
  { 1.0724035825423179e+42, 0.50000000000000000, 100.00000000000000 },
};

// Test function for nu=0.50000000000000000.
template <typename Tp>
void test003()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data003)
                         / sizeof(testcase_cyl_bessel_i<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_i(Tp(data003[i].nu), Tp(data003[i].x));
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
  VERIFY(max_abs_frac < Tp(1.0000000000000008e-12));
}

// Test data for nu=0.66666666666666663.
testcase_cyl_bessel_i<double> data004[] = {
  { 0.0000000000000000, 0.66666666666666663, 0.0000000000000000 },
  { 25.902310583215122, 0.66666666666666663, 5.0000000000000000 },
  { 2750.4090423459315, 0.66666666666666663, 10.000000000000000 },
  { 334476.98138574383, 0.66666666666666663, 15.000000000000000 },
  { 43064361.686912313, 0.66666666666666663, 20.000000000000000 },
  { 5722397441.9603882, 0.66666666666666663, 25.000000000000000 },
  { 775804343498.02661, 0.66666666666666663, 30.000000000000000 },
  { 106649495512800.89, 0.66666666666666663, 35.000000000000000 },
  { 14811199896983756., 0.66666666666666663, 40.000000000000000 },
  { 2.0730345814356961e+18, 0.66666666666666663, 45.000000000000000 },
  { 2.9194166755257467e+20, 0.66666666666666663, 50.000000000000000 },
  { 4.1319059569935366e+22, 0.66666666666666663, 55.000000000000000 },
  { 5.8721031476386222e+24, 0.66666666666666663, 60.000000000000000 },
  { 8.3741368248217830e+26, 0.66666666666666663, 65.000000000000000 },
  { 1.1977528777008688e+29, 0.66666666666666663, 70.000000000000000 },
  { 1.7175081240014333e+31, 0.66666666666666663, 75.000000000000000 },
  { 2.4682690458513916e+33, 0.66666666666666663, 80.000000000000000 },
  { 3.5541181975850724e+35, 0.66666666666666663, 85.000000000000000 },
  { 5.1264933963228864e+37, 0.66666666666666663, 90.000000000000000 },
  { 7.4058894880134064e+39, 0.66666666666666663, 95.000000000000000 },
  { 1.0713562154788124e+42, 0.66666666666666663, 100.00000000000000 },
};

// Test function for nu=0.66666666666666663.
template <typename Tp>
void test004()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data004)
                         / sizeof(testcase_cyl_bessel_i<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_i(Tp(data004[i].nu), Tp(data004[i].x));
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
  VERIFY(max_abs_frac < Tp(5.0000000000000039e-13));
}

// Test data for nu=1.0000000000000000.
testcase_cyl_bessel_i<double> data005[] = {
  { 0.0000000000000000, 1.0000000000000000, 0.0000000000000000 },
  { 24.335642142450524, 1.0000000000000000, 5.0000000000000000 },
  { 2670.9883037012560, 1.0000000000000000, 10.000000000000000 },
  { 328124.92197020649, 1.0000000000000000, 15.000000000000000 },
  { 42454973.385127775, 1.0000000000000000, 20.000000000000000 },
  { 5657865129.8787022, 1.0000000000000000, 25.000000000000000 },
  { 768532038938.95667, 1.0000000000000000, 30.000000000000000 },
  { 105794126051896.17, 1.0000000000000000, 35.000000000000000 },
  { 14707396163259354., 1.0000000000000000, 40.000000000000000 },
  { 2.0601334620815775e+18, 1.0000000000000000, 45.000000000000000 },
  { 2.9030785901035635e+20, 1.0000000000000000, 50.000000000000000 },
  { 4.1108986452992812e+22, 1.0000000000000000, 55.000000000000000 },
  { 5.8447515883904527e+24, 1.0000000000000000, 60.000000000000000 },
  { 8.3381485471501302e+26, 1.0000000000000000, 65.000000000000000 },
  { 1.1929750788892366e+29, 1.0000000000000000, 70.000000000000000 },
  { 1.7111160152965384e+31, 1.0000000000000000, 75.000000000000000 },
  { 2.4596595795675343e+33, 1.0000000000000000, 80.000000000000000 },
  { 3.5424536064404024e+35, 1.0000000000000000, 85.000000000000000 },
  { 5.1106068152566129e+37, 1.0000000000000000, 90.000000000000000 },
  { 7.3841518091360157e+39, 1.0000000000000000, 95.000000000000000 },
  { 1.0683693903381569e+42, 1.0000000000000000, 100.00000000000000 },
};

// Test function for nu=1.0000000000000000.
template <typename Tp>
void test005()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data005)
                         / sizeof(testcase_cyl_bessel_i<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_i(Tp(data005[i].nu), Tp(data005[i].x));
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
  VERIFY(max_abs_frac < Tp(5.0000000000000039e-13));
}

// Test data for nu=2.0000000000000000.
testcase_cyl_bessel_i<double> data006[] = {
  { 0.0000000000000000, 2.0000000000000000, 0.0000000000000000 },
  { 17.505614966624233, 2.0000000000000000, 5.0000000000000000 },
  { 2281.5189677260046, 2.0000000000000000, 10.000000000000000 },
  { 295899.38370188634, 2.0000000000000000, 15.000000000000000 },
  { 39312785.221040756, 2.0000000000000000, 20.000000000000000 },
  { 5321931396.0760136, 2.0000000000000000, 25.000000000000000 },
  { 730436828561.38013, 2.0000000000000000, 30.000000000000000 },
  { 101293439862977.19, 2.0000000000000000, 35.000000000000000 },
  { 14159404985256920., 2.0000000000000000, 40.000000000000000 },
  { 1.9918525879736883e+18, 2.0000000000000000, 45.000000000000000 },
  { 2.8164306402451938e+20, 2.0000000000000000, 50.000000000000000 },
  { 3.9993023372677515e+22, 2.0000000000000000, 55.000000000000000 },
  { 5.6992520026634433e+24, 2.0000000000000000, 60.000000000000000 },
  { 8.1464814287900378e+26, 2.0000000000000000, 65.000000000000000 },
  { 1.1675039556585663e+29, 2.0000000000000000, 70.000000000000000 },
  { 1.6770093176278926e+31, 2.0000000000000000, 75.000000000000000 },
  { 2.4136869148449879e+33, 2.0000000000000000, 80.000000000000000 },
  { 3.4801257808448186e+35, 2.0000000000000000, 85.000000000000000 },
  { 5.0256693051696307e+37, 2.0000000000000000, 90.000000000000000 },
  { 7.2678700343145842e+39, 2.0000000000000000, 95.000000000000000 },
  { 1.0523843193243042e+42, 2.0000000000000000, 100.00000000000000 },
};

// Test function for nu=2.0000000000000000.
template <typename Tp>
void test006()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data006)
                         / sizeof(testcase_cyl_bessel_i<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_i(Tp(data006[i].nu), Tp(data006[i].x));
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
  VERIFY(max_abs_frac < Tp(5.0000000000000039e-13));
}

// Test data for nu=5.0000000000000000.
testcase_cyl_bessel_i<double> data007[] = {
  { 0.0000000000000000, 5.0000000000000000, 0.0000000000000000 },
  { 2.1579745473225476, 5.0000000000000000, 5.0000000000000000 },
  { 777.18828640326012, 5.0000000000000000, 10.000000000000000 },
  { 144572.01120063406, 5.0000000000000000, 15.000000000000000 },
  { 23018392.213413671, 5.0000000000000000, 20.000000000000000 },
  { 3472466208.7419176, 5.0000000000000000, 25.000000000000000 },
  { 512151465476.93494, 5.0000000000000000, 30.000000000000000 },
  { 74756743552251.531, 5.0000000000000000, 35.000000000000000 },
  { 10858318337624276., 5.0000000000000000, 40.000000000000000 },
  { 1.5736087399245906e+18, 5.0000000000000000, 45.000000000000000 },
  { 2.2785483079112829e+20, 5.0000000000000000, 50.000000000000000 },
  { 3.2989391052963687e+22, 5.0000000000000000, 55.000000000000000 },
  { 4.7777652072561742e+24, 5.0000000000000000, 60.000000000000000 },
  { 6.9232165147172671e+26, 5.0000000000000000, 65.000000000000000 },
  { 1.0038643002095153e+29, 5.0000000000000000, 70.000000000000000 },
  { 1.4566328222327068e+31, 5.0000000000000000, 75.000000000000000 },
  { 2.1151488565944838e+33, 5.0000000000000000, 80.000000000000000 },
  { 3.0735883450768236e+35, 5.0000000000000000, 85.000000000000000 },
  { 4.4694790189230327e+37, 5.0000000000000000, 90.000000000000000 },
  { 6.5037505570430971e+39, 5.0000000000000000, 95.000000000000000 },
  { 9.4700938730355882e+41, 5.0000000000000000, 100.00000000000000 },
};

// Test function for nu=5.0000000000000000.
template <typename Tp>
void test007()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data007)
                         / sizeof(testcase_cyl_bessel_i<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_i(Tp(data007[i].nu), Tp(data007[i].x));
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
testcase_cyl_bessel_i<double> data008[] = {
  { 0.0000000000000000, 10.000000000000000, 0.0000000000000000 },
  { 0.0045800444191760525, 10.000000000000000, 5.0000000000000000 },
  { 21.891706163723381, 10.000000000000000, 10.000000000000000 },
  { 12267.475049806462, 10.000000000000000, 15.000000000000000 },
  { 3540200.2090195213, 10.000000000000000, 20.000000000000000 },
  { 771298871.17072666, 10.000000000000000, 25.000000000000000 },
  { 145831809975.96713, 10.000000000000000, 30.000000000000000 },
  { 25449470018534.785, 10.000000000000000, 35.000000000000000 },
  { 4228469210516757.5, 10.000000000000000, 40.000000000000000 },
  { 6.8049404557505152e+17, 10.000000000000000, 45.000000000000000 },
  { 1.0715971594776370e+20, 10.000000000000000, 50.000000000000000 },
  { 1.6618215752886714e+22, 10.000000000000000, 55.000000000000000 },
  { 2.5486246072566784e+24, 10.000000000000000, 60.000000000000000 },
  { 3.8764628702155481e+26, 10.000000000000000, 65.000000000000000 },
  { 5.8592538145409686e+28, 10.000000000000000, 70.000000000000000 },
  { 8.8135370711317444e+30, 10.000000000000000, 75.000000000000000 },
  { 1.3207418268325279e+33, 10.000000000000000, 80.000000000000000 },
  { 1.9732791360862186e+35, 10.000000000000000, 85.000000000000000 },
  { 2.9411893748384672e+37, 10.000000000000000, 90.000000000000000 },
  { 4.3754494922439990e+39, 10.000000000000000, 95.000000000000000 },
  { 6.4989755247201446e+41, 10.000000000000000, 100.00000000000000 },
};

// Test function for nu=10.000000000000000.
template <typename Tp>
void test008()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data008)
                         / sizeof(testcase_cyl_bessel_i<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_i(Tp(data008[i].nu), Tp(data008[i].x));
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
testcase_cyl_bessel_i<double> data009[] = {
  { 0.0000000000000000, 20.000000000000000, 0.0000000000000000 },
  { 5.0242393579718066e-11, 20.000000000000000, 5.0000000000000000 },
  { 0.00012507997356449481, 20.000000000000000, 10.000000000000000 },
  { 1.6470152535015834, 20.000000000000000, 15.000000000000000 },
  { 3188.7503288536154, 20.000000000000000, 20.000000000000000 },
  { 2449840.5422952301, 20.000000000000000, 25.000000000000000 },
  { 1126985104.4483771, 20.000000000000000, 30.000000000000000 },
  { 379617876611.88586, 20.000000000000000, 35.000000000000000 },
  { 104459633129479.89, 20.000000000000000, 40.000000000000000 },
  { 25039579987216504., 20.000000000000000, 45.000000000000000 },
  { 5.4420084027529964e+18, 20.000000000000000, 50.000000000000000 },
  { 1.1007498584335492e+21, 20.000000000000000, 55.000000000000000 },
  { 2.1091734863057236e+23, 20.000000000000000, 60.000000000000000 },
  { 3.8763618091286899e+25, 20.000000000000000, 65.000000000000000 },
  { 6.8946130527930859e+27, 20.000000000000000, 70.000000000000000 },
  { 1.1946319948836447e+30, 20.000000000000000, 75.000000000000000 },
  { 2.0265314377577580e+32, 20.000000000000000, 80.000000000000000 },
  { 3.3784665214179971e+34, 20.000000000000000, 85.000000000000000 },
  { 5.5516089411796670e+36, 20.000000000000000, 90.000000000000000 },
  { 9.0129310795305151e+38, 20.000000000000000, 95.000000000000000 },
  { 1.4483461256427176e+41, 20.000000000000000, 100.00000000000000 },
};

// Test function for nu=20.000000000000000.
template <typename Tp>
void test009()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data009)
                         / sizeof(testcase_cyl_bessel_i<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_i(Tp(data009[i].nu), Tp(data009[i].x));
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
testcase_cyl_bessel_i<double> data010[] = {
  { 0.0000000000000000, 50.000000000000000, 0.0000000000000000 },
  { 2.9314696468108517e-45, 50.000000000000000, 5.0000000000000000 },
  { 4.7568945607268442e-30, 50.000000000000000, 10.000000000000000 },
  { 5.5468372730667069e-21, 50.000000000000000, 15.000000000000000 },
  { 2.2551205757604056e-14, 50.000000000000000, 20.000000000000000 },
  { 4.5344251866130282e-09, 50.000000000000000, 25.000000000000000 },
  { 0.00014590106916468937, 50.000000000000000, 30.000000000000000 },
  { 1.3965549457254878, 50.000000000000000, 35.000000000000000 },
  { 5726.8656631289878, 50.000000000000000, 40.000000000000000 },
  { 12672593.113027776, 50.000000000000000, 45.000000000000000 },
  { 17650802430.016705, 50.000000000000000, 50.000000000000000 },
  { 17220231607789.926, 50.000000000000000, 55.000000000000000 },
  { 12704607933652172., 50.000000000000000, 60.000000000000000 },
  { 7.4989491942193766e+18, 50.000000000000000, 65.000000000000000 },
  { 3.6944034898904901e+21, 50.000000000000000, 70.000000000000000 },
  { 1.5691634774370194e+24, 50.000000000000000, 75.000000000000000 },
  { 5.8927749458163587e+26, 50.000000000000000, 80.000000000000000 },
  { 1.9958849054749339e+29, 50.000000000000000, 85.000000000000000 },
  { 6.1946050361781518e+31, 50.000000000000000, 90.000000000000000 },
  { 1.7845429728697110e+34, 50.000000000000000, 95.000000000000000 },
  { 4.8219580855940813e+36, 50.000000000000000, 100.00000000000000 },
};

// Test function for nu=50.000000000000000.
template <typename Tp>
void test010()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data010)
                         / sizeof(testcase_cyl_bessel_i<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_i(Tp(data010[i].nu), Tp(data010[i].x));
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
  VERIFY(max_abs_frac < Tp(5.0000000000000029e-12));
}

// Test data for nu=100.00000000000000.
testcase_cyl_bessel_i<double> data011[] = {
  { 0.0000000000000000, 100.00000000000000, 0.0000000000000000 },
  { 7.0935514885313123e-119, 100.00000000000000, 5.0000000000000000 },
  { 1.0823442017492018e-88, 100.00000000000000, 10.000000000000000 },
  { 5.9887888536468904e-71, 100.00000000000000, 15.000000000000000 },
  { 2.8703193216428771e-58, 100.00000000000000, 20.000000000000000 },
  { 2.4426896913122370e-48, 100.00000000000000, 25.000000000000000 },
  { 3.9476420053334271e-40, 100.00000000000000, 30.000000000000000 },
  { 4.2836596180818801e-33, 100.00000000000000, 35.000000000000000 },
  { 6.6249380222596129e-27, 100.00000000000000, 40.000000000000000 },
  { 2.3702587262788881e-21, 100.00000000000000, 45.000000000000000 },
  { 2.7278879470966907e-16, 100.00000000000000, 50.000000000000000 },
  { 1.2763258878228088e-11, 100.00000000000000, 55.000000000000000 },
  { 2.8832770906491951e-07, 100.00000000000000, 60.000000000000000 },
  { 0.0035805902717061240, 100.00000000000000, 65.000000000000000 },
  { 27.017219102595398, 100.00000000000000, 70.000000000000000 },
  { 134001.44891209516, 100.00000000000000, 75.000000000000000 },
  { 465194832.85061038, 100.00000000000000, 80.000000000000000 },
  { 1189280653119.4819, 100.00000000000000, 85.000000000000000 },
  { 2334119331258731.0, 100.00000000000000, 90.000000000000000 },
  { 3.6399223078502380e+18, 100.00000000000000, 95.000000000000000 },
  { 4.6415349416161989e+21, 100.00000000000000, 100.00000000000000 },
};

// Test function for nu=100.00000000000000.
template <typename Tp>
void test011()
{
  const Tp eps = std::numeric_limits<Tp>::epsilon();
  Tp max_abs_diff = -Tp(1);
  Tp max_abs_frac = -Tp(1);
  unsigned int num_datum = sizeof(data011)
                         / sizeof(testcase_cyl_bessel_i<double>);
  for (unsigned int i = 0; i < num_datum; ++i)
    {
      const Tp f = std::tr1::cyl_bessel_i(Tp(data011[i].nu), Tp(data011[i].x));
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
  VERIFY(max_abs_frac < Tp(2.5000000000000014e-11));
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
