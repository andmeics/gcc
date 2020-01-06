// { dg-do run { target c++11 } }
// { dg-options "-D__STDCPP_WANT_MATH_SPEC_FUNCS__" }
//
// Copyright (C) 2016-2020 Free Software Foundation, Inc.
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

//  legendre
//  Compare against values generated by the GNU Scientific Library.
//  The GSL can be found on the web: http://www.gnu.org/software/gsl/
#include <limits>
#include <cmath>
#if defined(__TEST_DEBUG)
#  include <iostream>
#  define VERIFY(A) \
  if (!(A)) \
    { \
      std::cout << "line " << __LINE__ \
	<< "  max_abs_frac = " << max_abs_frac \
	<< std::endl; \
    }
#else
#  include <testsuite_hooks.h>
#endif
#include <specfun_testcase.h>

// Test data for l=0.
// max(|f - f_GSL|): 0.0000000000000000 at index 0
// max(|f - f_GSL| / |f_GSL|): 0.0000000000000000
// mean(f - f_GSL): 0.0000000000000000
// variance(f - f_GSL): 0.0000000000000000
// stddev(f - f_GSL): 0.0000000000000000
const testcase_legendre<double>
data001[21] =
{
  { 1.0000000000000000, 0, -1.0000000000000000, 0.0 },
  { 1.0000000000000000, 0, -0.90000000000000002, 0.0 },
  { 1.0000000000000000, 0, -0.80000000000000004, 0.0 },
  { 1.0000000000000000, 0, -0.69999999999999996, 0.0 },
  { 1.0000000000000000, 0, -0.59999999999999998, 0.0 },
  { 1.0000000000000000, 0, -0.50000000000000000, 0.0 },
  { 1.0000000000000000, 0, -0.39999999999999991, 0.0 },
  { 1.0000000000000000, 0, -0.29999999999999993, 0.0 },
  { 1.0000000000000000, 0, -0.19999999999999996, 0.0 },
  { 1.0000000000000000, 0, -0.099999999999999978, 0.0 },
  { 1.0000000000000000, 0, 0.0000000000000000, 0.0 },
  { 1.0000000000000000, 0, 0.10000000000000009, 0.0 },
  { 1.0000000000000000, 0, 0.20000000000000018, 0.0 },
  { 1.0000000000000000, 0, 0.30000000000000004, 0.0 },
  { 1.0000000000000000, 0, 0.40000000000000013, 0.0 },
  { 1.0000000000000000, 0, 0.50000000000000000, 0.0 },
  { 1.0000000000000000, 0, 0.60000000000000009, 0.0 },
  { 1.0000000000000000, 0, 0.70000000000000018, 0.0 },
  { 1.0000000000000000, 0, 0.80000000000000004, 0.0 },
  { 1.0000000000000000, 0, 0.90000000000000013, 0.0 },
  { 1.0000000000000000, 0, 1.0000000000000000, 0.0 },
};
const double toler001 = 2.5000000000000020e-13;

// Test data for l=1.
// max(|f - f_GSL|): 0.0000000000000000 at index 0
// max(|f - f_GSL| / |f_GSL|): 0.0000000000000000
// mean(f - f_GSL): 0.0000000000000000
// variance(f - f_GSL): 0.0000000000000000
// stddev(f - f_GSL): 0.0000000000000000
const testcase_legendre<double>
data002[21] =
{
  { -1.0000000000000000, 1, -1.0000000000000000, 0.0 },
  { -0.90000000000000002, 1, -0.90000000000000002, 0.0 },
  { -0.80000000000000004, 1, -0.80000000000000004, 0.0 },
  { -0.69999999999999996, 1, -0.69999999999999996, 0.0 },
  { -0.59999999999999998, 1, -0.59999999999999998, 0.0 },
  { -0.50000000000000000, 1, -0.50000000000000000, 0.0 },
  { -0.39999999999999991, 1, -0.39999999999999991, 0.0 },
  { -0.29999999999999993, 1, -0.29999999999999993, 0.0 },
  { -0.19999999999999996, 1, -0.19999999999999996, 0.0 },
  { -0.099999999999999978, 1, -0.099999999999999978, 0.0 },
  { 0.0000000000000000, 1, 0.0000000000000000, 0.0 },
  { 0.10000000000000009, 1, 0.10000000000000009, 0.0 },
  { 0.20000000000000018, 1, 0.20000000000000018, 0.0 },
  { 0.30000000000000004, 1, 0.30000000000000004, 0.0 },
  { 0.40000000000000013, 1, 0.40000000000000013, 0.0 },
  { 0.50000000000000000, 1, 0.50000000000000000, 0.0 },
  { 0.60000000000000009, 1, 0.60000000000000009, 0.0 },
  { 0.70000000000000018, 1, 0.70000000000000018, 0.0 },
  { 0.80000000000000004, 1, 0.80000000000000004, 0.0 },
  { 0.90000000000000013, 1, 0.90000000000000013, 0.0 },
  { 1.0000000000000000, 1, 1.0000000000000000, 0.0 },
};
const double toler002 = 2.5000000000000020e-13;

// Test data for l=2.
// max(|f - f_GSL|): 1.1102230246251565e-16 at index 17
// max(|f - f_GSL| / |f_GSL|): 1.3877787807814482e-15
// mean(f - f_GSL): 1.8503717077085941e-17
// variance(f - f_GSL): 1.7975346147614202e-35
// stddev(f - f_GSL): 4.2397342071896678e-18
const testcase_legendre<double>
data003[21] =
{
  { 1.0000000000000000, 2, -1.0000000000000000, 0.0 },
  { 0.71500000000000008, 2, -0.90000000000000002, 0.0 },
  { 0.46000000000000019, 2, -0.80000000000000004, 0.0 },
  { 0.23499999999999988, 2, -0.69999999999999996, 0.0 },
  { 0.039999999999999925, 2, -0.59999999999999998, 0.0 },
  { -0.12500000000000000, 2, -0.50000000000000000, 0.0 },
  { -0.26000000000000012, 2, -0.39999999999999991, 0.0 },
  { -0.36500000000000005, 2, -0.29999999999999993, 0.0 },
  { -0.44000000000000006, 2, -0.19999999999999996, 0.0 },
  { -0.48499999999999999, 2, -0.099999999999999978, 0.0 },
  { -0.50000000000000000, 2, 0.0000000000000000, 0.0 },
  { -0.48499999999999999, 2, 0.10000000000000009, 0.0 },
  { -0.43999999999999989, 2, 0.20000000000000018, 0.0 },
  { -0.36499999999999999, 2, 0.30000000000000004, 0.0 },
  { -0.25999999999999984, 2, 0.40000000000000013, 0.0 },
  { -0.12500000000000000, 2, 0.50000000000000000, 0.0 },
  { 0.040000000000000147, 2, 0.60000000000000009, 0.0 },
  { 0.23500000000000032, 2, 0.70000000000000018, 0.0 },
  { 0.46000000000000019, 2, 0.80000000000000004, 0.0 },
  { 0.71500000000000030, 2, 0.90000000000000013, 0.0 },
  { 1.0000000000000000, 2, 1.0000000000000000, 0.0 },
};
const double toler003 = 2.5000000000000020e-13;

// Test data for l=5.
// max(|f - f_GSL|): 2.0122792321330962e-16 at index 19
// max(|f - f_GSL| / |f_GSL|): 4.8911475274405560e-15
// mean(f - f_GSL): -2.3129646346357427e-18
// variance(f - f_GSL): 2.8086478355647191e-37
// stddev(f - f_GSL): 5.2996677589870847e-19
const testcase_legendre<double>
data004[21] =
{
  { -1.0000000000000000, 5, -1.0000000000000000, 0.0 },
  { 0.041141250000000087, 5, -0.90000000000000002, 0.0 },
  { 0.39951999999999993, 5, -0.80000000000000004, 0.0 },
  { 0.36519874999999991, 5, -0.69999999999999996, 0.0 },
  { 0.15263999999999994, 5, -0.59999999999999998, 0.0 },
  { -0.089843750000000000, 5, -0.50000000000000000, 0.0 },
  { -0.27064000000000010, 5, -0.39999999999999991, 0.0 },
  { -0.34538624999999995, 5, -0.29999999999999993, 0.0 },
  { -0.30751999999999996, 5, -0.19999999999999996, 0.0 },
  { -0.17882874999999995, 5, -0.099999999999999978, 0.0 },
  { 0.0000000000000000, 5, 0.0000000000000000, 0.0 },
  { 0.17882875000000015, 5, 0.10000000000000009, 0.0 },
  { 0.30752000000000013, 5, 0.20000000000000018, 0.0 },
  { 0.34538625000000001, 5, 0.30000000000000004, 0.0 },
  { 0.27063999999999988, 5, 0.40000000000000013, 0.0 },
  { 0.089843750000000000, 5, 0.50000000000000000, 0.0 },
  { -0.15264000000000016, 5, 0.60000000000000009, 0.0 },
  { -0.36519875000000024, 5, 0.70000000000000018, 0.0 },
  { -0.39951999999999993, 5, 0.80000000000000004, 0.0 },
  { -0.041141249999999151, 5, 0.90000000000000013, 0.0 },
  { 1.0000000000000000, 5, 1.0000000000000000, 0.0 },
};
const double toler004 = 2.5000000000000020e-13;

// Test data for l=10.
// max(|f - f_GSL|): 3.8857805861880479e-16 at index 19
// max(|f - f_GSL| / |f_GSL|): 1.4766655123690915e-15
// mean(f - f_GSL): -2.5112187461759493e-17
// variance(f - f_GSL): 3.3107652853513909e-35
// stddev(f - f_GSL): 5.7539249954716919e-18
const testcase_legendre<double>
data005[21] =
{
  { 1.0000000000000000, 10, -1.0000000000000000, 0.0 },
  { -0.26314561785585960, 10, -0.90000000000000002, 0.0 },
  { 0.30052979560000004, 10, -0.80000000000000004, 0.0 },
  { 0.085805795531640333, 10, -0.69999999999999996, 0.0 },
  { -0.24366274560000001, 10, -0.59999999999999998, 0.0 },
  { -0.18822860717773438, 10, -0.50000000000000000, 0.0 },
  { 0.096839064400000258, 10, -0.39999999999999991, 0.0 },
  { 0.25147634951601561, 10, -0.29999999999999993, 0.0 },
  { 0.12907202559999983, 10, -0.19999999999999996, 0.0 },
  { -0.12212499738710943, 10, -0.099999999999999978, 0.0 },
  { -0.24609375000000000, 10, 0.0000000000000000, 0.0 },
  { -0.12212499738710922, 10, 0.10000000000000009, 0.0 },
  { 0.12907202560000042, 10, 0.20000000000000018, 0.0 },
  { 0.25147634951601561, 10, 0.30000000000000004, 0.0 },
  { 0.096839064399999633, 10, 0.40000000000000013, 0.0 },
  { -0.18822860717773438, 10, 0.50000000000000000, 0.0 },
  { -0.24366274559999984, 10, 0.60000000000000009, 0.0 },
  { 0.085805795531641277, 10, 0.70000000000000018, 0.0 },
  { 0.30052979560000004, 10, 0.80000000000000004, 0.0 },
  { -0.26314561785586010, 10, 0.90000000000000013, 0.0 },
  { 1.0000000000000000, 10, 1.0000000000000000, 0.0 },
};
const double toler005 = 2.5000000000000020e-13;

// Test data for l=20.
// max(|f - f_GSL|): 3.6082248300317588e-16 at index 19
// max(|f - f_GSL| / |f_GSL|): 2.4166281401316513e-15
// mean(f - f_GSL): 0.0000000000000000
// variance(f - f_GSL): 4.9424644697959907e-65
// stddev(f - f_GSL): 7.0302663319365015e-33
const testcase_legendre<double>
data006[21] =
{
  { 1.0000000000000000, 20, -1.0000000000000000, 0.0 },
  { -0.14930823530984835, 20, -0.90000000000000002, 0.0 },
  { 0.22420460541741347, 20, -0.80000000000000004, 0.0 },
  { -0.20457394463834172, 20, -0.69999999999999996, 0.0 },
  { 0.15916752910098109, 20, -0.59999999999999998, 0.0 },
  { -0.048358381067373557, 20, -0.50000000000000000, 0.0 },
  { -0.10159261558628112, 20, -0.39999999999999991, 0.0 },
  { 0.18028715947998047, 20, -0.29999999999999993, 0.0 },
  { -0.098042194344594796, 20, -0.19999999999999996, 0.0 },
  { -0.082077130944527663, 20, -0.099999999999999978, 0.0 },
  { 0.17619705200195312, 20, 0.0000000000000000, 0.0 },
  { -0.082077130944528023, 20, 0.10000000000000009, 0.0 },
  { -0.098042194344594089, 20, 0.20000000000000018, 0.0 },
  { 0.18028715947998042, 20, 0.30000000000000004, 0.0 },
  { -0.10159261558628192, 20, 0.40000000000000013, 0.0 },
  { -0.048358381067373557, 20, 0.50000000000000000, 0.0 },
  { 0.15916752910098075, 20, 0.60000000000000009, 0.0 },
  { -0.20457394463834136, 20, 0.70000000000000018, 0.0 },
  { 0.22420460541741347, 20, 0.80000000000000004, 0.0 },
  { -0.14930823530984758, 20, 0.90000000000000013, 0.0 },
  { 1.0000000000000000, 20, 1.0000000000000000, 0.0 },
};
const double toler006 = 2.5000000000000020e-13;

// Test data for l=50.
// max(|f - f_GSL|): 1.6653345369377348e-16 at index 2
// max(|f - f_GSL| / |f_GSL|): 1.6665460706897444e-15
// mean(f - f_GSL): -8.0953762212251003e-18
// variance(f - f_GSL): 3.4405935985667807e-36
// stddev(f - f_GSL): 1.8548837156454796e-18
const testcase_legendre<double>
data007[21] =
{
  { 1.0000000000000000, 50, -1.0000000000000000, 0.0 },
  { -0.17003765994383671, 50, -0.90000000000000002, 0.0 },
  { 0.13879737345093113, 50, -0.80000000000000004, 0.0 },
  { -0.014572731645892852, 50, -0.69999999999999996, 0.0 },
  { -0.058860798844002096, 50, -0.59999999999999998, 0.0 },
  { -0.031059099239609811, 50, -0.50000000000000000, 0.0 },
  { 0.041569033381824674, 50, -0.39999999999999991, 0.0 },
  { 0.10911051574714790, 50, -0.29999999999999993, 0.0 },
  { 0.083432272204197494, 50, -0.19999999999999996, 0.0 },
  { -0.038205812661313600, 50, -0.099999999999999978, 0.0 },
  { -0.11227517265921705, 50, 0.0000000000000000, 0.0 },
  { -0.038205812661314155, 50, 0.10000000000000009, 0.0 },
  { 0.083432272204196564, 50, 0.20000000000000018, 0.0 },
  { 0.10911051574714797, 50, 0.30000000000000004, 0.0 },
  { 0.041569033381826007, 50, 0.40000000000000013, 0.0 },
  { -0.031059099239609811, 50, 0.50000000000000000, 0.0 },
  { -0.058860798844001430, 50, 0.60000000000000009, 0.0 },
  { -0.014572731645890737, 50, 0.70000000000000018, 0.0 },
  { 0.13879737345093113, 50, 0.80000000000000004, 0.0 },
  { -0.17003765994383679, 50, 0.90000000000000013, 0.0 },
  { 1.0000000000000000, 50, 1.0000000000000000, 0.0 },
};
const double toler007 = 2.5000000000000020e-13;

// Test data for l=100.
// max(|f - f_GSL|): 3.4694469519536142e-16 at index 2
// max(|f - f_GSL| / |f_GSL|): 6.8214063779431592e-15
// mean(f - f_GSL): -4.1385545784018113e-17
// variance(f - f_GSL): 8.9920078491655612e-35
// stddev(f - f_GSL): 9.4826198116161765e-18
const testcase_legendre<double>
data008[21] =
{
  { 1.0000000000000000, 100, -1.0000000000000000, 0.0 },
  { 0.10226582055871893, 100, -0.90000000000000002, 0.0 },
  { 0.050861167913584228, 100, -0.80000000000000004, 0.0 },
  { -0.077132507199778641, 100, -0.69999999999999996, 0.0 },
  { -0.023747023905133141, 100, -0.59999999999999998, 0.0 },
  { -0.060518025961861198, 100, -0.50000000000000000, 0.0 },
  { -0.072258202125685025, 100, -0.39999999999999991, 0.0 },
  { 0.057127392202801046, 100, -0.29999999999999993, 0.0 },
  { 0.014681835355659706, 100, -0.19999999999999996, 0.0 },
  { -0.063895098434750205, 100, -0.099999999999999978, 0.0 },
  { 0.079589237387178727, 100, 0.0000000000000000, 0.0 },
  { -0.063895098434749761, 100, 0.10000000000000009, 0.0 },
  { 0.014681835355657875, 100, 0.20000000000000018, 0.0 },
  { 0.057127392202801566, 100, 0.30000000000000004, 0.0 },
  { -0.072258202125684082, 100, 0.40000000000000013, 0.0 },
  { -0.060518025961861198, 100, 0.50000000000000000, 0.0 },
  { -0.023747023905134217, 100, 0.60000000000000009, 0.0 },
  { -0.077132507199780501, 100, 0.70000000000000018, 0.0 },
  { 0.050861167913584228, 100, 0.80000000000000004, 0.0 },
  { 0.10226582055872063, 100, 0.90000000000000013, 0.0 },
  { 1.0000000000000000, 100, 1.0000000000000000, 0.0 },
};
const double toler008 = 5.0000000000000039e-13;

template<typename Ret, unsigned int Num>
  void
  test(const testcase_legendre<Ret> (&data)[Num], Ret toler)
  {
    bool test __attribute__((unused)) = true;
    const Ret eps = std::numeric_limits<Ret>::epsilon();
    Ret max_abs_diff = -Ret(1);
    Ret max_abs_frac = -Ret(1);
    unsigned int num_datum = Num;
    for (unsigned int i = 0; i < num_datum; ++i)
      {
	const Ret f = std::legendre(data[i].l, data[i].x);
	const Ret f0 = data[i].f0;
	const Ret diff = f - f0;
	if (std::abs(diff) > max_abs_diff)
	  max_abs_diff = std::abs(diff);
	if (std::abs(f0) > Ret(10) * eps
	 && std::abs(f) > Ret(10) * eps)
	  {
	    const Ret frac = diff / f0;
	    if (std::abs(frac) > max_abs_frac)
	      max_abs_frac = std::abs(frac);
	  }
      }
    VERIFY(max_abs_frac < toler);
  }

int
main()
{
  test(data001, toler001);
  test(data002, toler002);
  test(data003, toler003);
  test(data004, toler004);
  test(data005, toler005);
  test(data006, toler006);
  test(data007, toler007);
  test(data008, toler008);
  return 0;
}
