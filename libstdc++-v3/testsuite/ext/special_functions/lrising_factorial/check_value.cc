// { dg-do run { target c++11 } }
// { dg-options "-D__STDCPP_WANT_MATH_SPEC_FUNCS__" }
//
// Copyright (C) 2016-2017 Free Software Foundation, Inc.
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

//  lpochhammer
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


// Test data for a=0.25000000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data001[7] =
{
  { -1.3862943611198906, 0.25000000000000000, 1.0000000000000000, 0.0 },
  { -1.1631508098056809, 0.25000000000000000, 2.0000000000000000, 0.0 },
  { 2.2733533856886194, 0.25000000000000000, 5.0000000000000000, 0.0 },
  { 12.080001146777969, 0.25000000000000000, 10.000000000000000, 0.0 },
  { 38.796088073219273, 0.25000000000000000, 20.000000000000000, 0.0 },
  { 144.25384907163405, 0.25000000000000000, 50.000000000000000, 0.0 },
  { 358.99653711306615, 0.25000000000000000, 100.00000000000000, 0.0 },
};
const double toler001 = 2.5000000000000020e-13;

// Test data for a=0.50000000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data002[7] =
{
  { -0.69314718055994529, 0.50000000000000000, 1.0000000000000000, 0.0 },
  { -0.28768207245178090, 0.50000000000000000, 2.0000000000000000, 0.0 },
  { 3.3854490246940161, 0.50000000000000000, 5.0000000000000000, 0.0 },
  { 13.368260276479063, 0.50000000000000000, 10.000000000000000, 0.0 },
  { 40.259136031606097, 0.50000000000000000, 20.000000000000000, 0.0 },
  { 145.94689054779593, 0.50000000000000000, 50.000000000000000, 0.0 },
  { 360.86317552485292, 0.50000000000000000, 100.00000000000000, 0.0 },
};
const double toler002 = 2.5000000000000020e-13;

// Test data for a=0.75000000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data003[7] =
{
  { -0.28768207245178090, 0.75000000000000000, 1.0000000000000000, 0.0 },
  { 0.27193371548364176, 0.75000000000000000, 2.0000000000000000, 0.0 },
  { 4.1634350851909909, 0.75000000000000000, 5.0000000000000000, 0.0 },
  { 14.316191273629222, 0.75000000000000000, 10.000000000000000, 0.0 },
  { 41.378734830523598, 0.75000000000000000, 20.000000000000000, 0.0 },
  { 147.29460839722435, 0.75000000000000000, 50.000000000000000, 0.0 },
  { 362.38386534180256, 0.75000000000000000, 100.00000000000000, 0.0 },
};
const double toler003 = 2.5000000000000020e-13;

// Test data for a=1.0000000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data004[7] =
{
  { 0.0000000000000000, 1.0000000000000000, 1.0000000000000000, 0.0 },
  { 0.69314718055994529, 1.0000000000000000, 2.0000000000000000, 0.0 },
  { 4.7874917427820458, 1.0000000000000000, 5.0000000000000000, 0.0 },
  { 15.104412573075516, 1.0000000000000000, 10.000000000000000, 0.0 },
  { 42.335616460753485, 1.0000000000000000, 20.000000000000000, 0.0 },
  { 148.47776695177302, 1.0000000000000000, 50.000000000000000, 0.0 },
  { 363.73937555556347, 1.0000000000000000, 100.00000000000000, 0.0 },
};
const double toler004 = 2.5000000000000020e-13;

// Test data for a=1.2500000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data005[7] =
{
  { 0.22314355131420976, 1.2500000000000000, 1.0000000000000000, 0.0 },
  { 1.0340737675305385, 1.2500000000000000, 2.0000000000000000, 0.0 },
  { 5.3178758234120425, 1.2500000000000000, 5.0000000000000000, 0.0 },
  { 15.793573213482277, 1.2500000000000000, 10.000000000000000, 0.0 },
  { 43.190537227891710, 1.2500000000000000, 20.000000000000000, 0.0 },
  { 149.55715397969311, 1.2500000000000000, 50.000000000000000, 0.0 },
  { 364.99049854037276, 1.2500000000000000, 100.00000000000000, 0.0 },
};
const double toler005 = 2.5000000000000020e-13;

// Test data for a=1.5000000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data006[7] =
{
  { 0.40546510810816438, 1.5000000000000000, 1.0000000000000000, 0.0 },
  { 1.3217558399823195, 1.5000000000000000, 2.0000000000000000, 0.0 },
  { 5.7833442974923868, 1.5000000000000000, 5.0000000000000000, 0.0 },
  { 16.412782714202486, 1.5000000000000000, 10.000000000000000, 0.0 },
  { 43.972708098310406, 1.5000000000000000, 20.000000000000000, 0.0 },
  { 150.56201106463718, 1.5000000000000000, 50.000000000000000, 0.0 },
  { 366.16648043291201, 1.5000000000000000, 100.00000000000000, 0.0 },
};
const double toler006 = 2.5000000000000020e-13;

// Test data for a=1.7500000000000000.
// max(|f - f_Boost|): 8.8817841970012523e-16 at index 2
// max(|f - f_Boost| / |f_Boost|): 1.4324725944115532e-16
// mean(f - f_Boost): -1.2688263138573217e-16
// variance(f - f_Boost): 3.1304004175436975e-33
// stddev(f - f_Boost): 5.5949981390021016e-17
const testcase_lpochhammer<double>
data007[7] =
{
  { 0.55961578793542266, 1.7500000000000000, 1.0000000000000000, 0.0 },
  { 1.5712166996139025, 1.7500000000000000, 2.0000000000000000, 0.0 },
  { 6.2003170124520315, 1.7500000000000000, 5.0000000000000000, 0.0 },
  { 16.978779100654677, 1.7500000000000000, 10.000000000000000, 0.0 },
  { 44.698963149652087, 1.7500000000000000, 20.000000000000000, 0.0 },
  { 151.50920208759803, 1.7500000000000000, 50.000000000000000, 0.0 },
  { 367.28418961508112, 1.7500000000000000, 100.00000000000000, 0.0 },
};
const double toler007 = 2.5000000000000020e-13;

// Test data for a=2.0000000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data008[7] =
{
  { 0.69314718055994529, 2.0000000000000000, 1.0000000000000000, 0.0 },
  { 1.7917594692280550, 2.0000000000000000, 2.0000000000000000, 0.0 },
  { 6.5792512120101012, 2.0000000000000000, 5.0000000000000000, 0.0 },
  { 17.502307845873887, 2.0000000000000000, 10.000000000000000, 0.0 },
  { 45.380138898476908, 2.0000000000000000, 20.000000000000000, 0.0 },
  { 152.40959258449735, 2.0000000000000000, 50.000000000000000, 0.0 },
  { 368.35449607240474, 2.0000000000000000, 100.00000000000000, 0.0 },
};
const double toler008 = 2.5000000000000020e-13;

// Test data for a=2.2500000000000000.
// max(|f - f_Boost|): 2.2204460492503131e-16 at index 1
// max(|f - f_Boost| / |f_Boost|): 1.1160346564877836e-16
// mean(f - f_Boost): 3.1720657846433042e-17
// variance(f - f_Boost): 1.9565002609648109e-34
// stddev(f - f_Boost): 1.3987495347505254e-17
const testcase_lpochhammer<double>
data009[7] =
{
  { 0.81093021621632877, 2.2500000000000000, 1.0000000000000000, 0.0 },
  { 1.9895852125579747, 2.2500000000000000, 2.0000000000000000, 0.0 },
  { 6.9273137358461430, 2.2500000000000000, 5.0000000000000000, 0.0 },
  { 17.990797790818498, 2.2500000000000000, 10.000000000000000, 0.0 },
  { 46.023750571947929, 2.2500000000000000, 20.000000000000000, 0.0 },
  { 153.27072604639741, 2.2500000000000000, 50.000000000000000, 0.0 },
  { 369.38494769504518, 2.2500000000000000, 100.00000000000000, 0.0 },
};
const double toler009 = 2.5000000000000020e-13;

// Test data for a=2.5000000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data010[7] =
{
  { 0.91629073187415511, 2.5000000000000000, 1.0000000000000000, 0.0 },
  { 2.1690537003695232, 2.5000000000000000, 2.0000000000000000, 0.0 },
  { 7.2496813662858139, 2.5000000000000000, 5.0000000000000000, 0.0 },
  { 18.449664641463528, 2.5000000000000000, 10.000000000000000, 0.0 },
  { 46.635295925335861, 2.5000000000000000, 20.000000000000000, 0.0 },
  { 154.09812776419872, 2.5000000000000000, 50.000000000000000, 0.0 },
  { 370.38107412328566, 2.5000000000000000, 100.00000000000000, 0.0 },
};
const double toler010 = 2.5000000000000020e-13;

// Test data for a=2.7500000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data011[7] =
{
  { 1.0116009116784799, 2.7500000000000000, 1.0000000000000000, 0.0 },
  { 2.3333567516607996, 2.7500000000000000, 2.0000000000000000, 0.0 },
  { 7.5502437294010472, 2.7500000000000000, 5.0000000000000000, 0.0 },
  { 18.883016553309421, 2.7500000000000000, 10.000000000000000, 0.0 },
  { 47.218961119251361, 2.7500000000000000, 20.000000000000000, 0.0 },
  { 154.89601073180808, 2.7500000000000000, 50.000000000000000, 0.0 },
  { 371.34709265146842, 2.7500000000000000, 100.00000000000000, 0.0 },
};
const double toler011 = 2.5000000000000020e-13;

// Test data for a=3.0000000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data012[7] =
{
  { 1.0986122886681096, 3.0000000000000000, 1.0000000000000000, 0.0 },
  { 2.4849066497880004, 3.0000000000000000, 2.0000000000000000, 0.0 },
  { 7.8320141805054693, 3.0000000000000000, 5.0000000000000000, 0.0 },
  { 19.294067315101941, 3.0000000000000000, 10.000000000000000, 0.0 },
  { 47.778034171275280, 3.0000000000000000, 20.000000000000000, 0.0 },
  { 155.66768912251885, 3.0000000000000000, 50.000000000000000, 0.0 },
  { 372.28632170512907, 3.0000000000000000, 100.00000000000000, 0.0 },
};
const double toler012 = 2.5000000000000020e-13;

// Test data for a=3.2500000000000000.
// max(|f - f_Boost|): 4.4408920985006262e-16 at index 1
// max(|f - f_Boost| / |f_Boost|): 1.6913985793391602e-16
// mean(f - f_Boost): 6.3441315692866085e-17
// variance(f - f_Boost): 7.8260010438592437e-34
// stddev(f - f_Boost): 2.7974990695010508e-17
const testcase_lpochhammer<double>
data013[7] =
{
  { 1.1786549963416462, 3.2500000000000000, 1.0000000000000000, 0.0 },
  { 2.6255739792779713, 3.2500000000000000, 2.0000000000000000, 0.0 },
  { 8.0973849884963975, 3.2500000000000000, 5.0000000000000000, 0.0 },
  { 19.685393511592903, 3.2500000000000000, 10.000000000000000, 0.0 },
  { 48.315162364343848, 3.2500000000000000, 20.000000000000000, 0.0 },
  { 156.41583572102601, 3.2500000000000000, 50.000000000000000, 0.0 },
  { 373.20143827375176, 3.2500000000000000, 100.00000000000000, 0.0 },
};
const double toler013 = 2.5000000000000020e-13;

// Test data for a=3.5000000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data014[7] =
{
  { 1.2527629684953681, 3.5000000000000000, 1.0000000000000000, 0.0 },
  { 2.7568403652716422, 3.5000000000000000, 2.0000000000000000, 0.0 },
  { 8.3482936549539239, 3.5000000000000000, 5.0000000000000000, 0.0 },
  { 20.059102553897628, 3.5000000000000000, 10.000000000000000, 0.0 },
  { 48.832520502672075, 3.5000000000000000, 20.000000000000000, 0.0 },
  { 157.14265020192212, 3.5000000000000000, 50.000000000000000, 0.0 },
  { 374.09464618998999, 3.5000000000000000, 100.00000000000000, 0.0 },
};
const double toler014 = 2.5000000000000020e-13;

// Test data for a=3.7500000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data015[7] =
{
  { 1.3217558399823195, 3.7500000000000000, 1.0000000000000000, 0.0 },
  { 2.8799004580288692, 3.7500000000000000, 2.0000000000000000, 0.0 },
  { 8.5863356610878228, 3.7500000000000000, 5.0000000000000000, 0.0 },
  { 20.416946913235375, 3.7500000000000000, 10.000000000000000, 0.0 },
  { 49.331925352969840, 3.7500000000000000, 20.000000000000000, 0.0 },
  { 157.84997359248578, 3.7500000000000000, 50.000000000000000, 0.0 },
  { 374.96779059316628, 3.7500000000000000, 100.00000000000000, 0.0 },
};
const double toler015 = 2.5000000000000020e-13;

// Test data for a=4.0000000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data016[7] =
{
  { 1.3862943611198906, 4.0000000000000000, 1.0000000000000000, 0.0 },
  { 2.9957322735539909, 4.0000000000000000, 2.0000000000000000, 0.0 },
  { 8.8128434335171946, 4.0000000000000000, 5.0000000000000000, 0.0 },
  { 20.760404383895366, 4.0000000000000000, 10.000000000000000, 0.0 },
  { 49.814916098536315, 4.0000000000000000, 20.000000000000000, 0.0 },
  { 158.53936874740285, 4.0000000000000000, 50.000000000000000, 0.0 },
  { 375.82243840469062, 4.0000000000000000, 100.00000000000000, 0.0 },
};
const double toler016 = 2.5000000000000020e-13;

// Test data for a=4.2500000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data017[7] =
{
  { 1.4469189829363254, 4.2500000000000000, 1.0000000000000000, 0.0 },
  { 3.1051470595398580, 4.2500000000000000, 2.0000000000000000, 0.0 },
  { 9.0289431925013410, 4.2500000000000000, 5.0000000000000000, 0.0 },
  { 21.090736067683487, 4.2500000000000000, 10.000000000000000, 0.0 },
  { 50.282812500035568, 4.2500000000000000, 20.000000000000000, 0.0 },
  { 159.21217852927390, 4.2500000000000000, 50.000000000000000, 0.0 },
  { 376.65993650925122, 4.2500000000000000, 100.00000000000000, 0.0 },
};
const double toler017 = 2.5000000000000020e-13;

// Test data for a=4.5000000000000000.
// max(|f - f_Boost|): 4.4408920985006262e-16 at index 1
// max(|f - f_Boost| / |f_Boost|): 1.3839618619659635e-16
// mean(f - f_Boost): 6.3441315692866085e-17
// variance(f - f_Boost): 7.8260010438592437e-34
// stddev(f - f_Boost): 2.7974990695010508e-17
const testcase_lpochhammer<double>
data018[7] =
{
  { 1.5040773967762742, 4.5000000000000000, 1.0000000000000000, 0.0 },
  { 3.2088254890146990, 4.5000000000000000, 2.0000000000000000, 0.0 },
  { 9.2355968499548258, 4.5000000000000000, 5.0000000000000000, 0.0 },
  { 21.409029270846641, 4.5000000000000000, 10.000000000000000, 0.0 },
  { 50.736757955326823, 4.5000000000000000, 20.000000000000000, 0.0 },
  { 159.86956888732874, 4.5000000000000000, 50.000000000000000, 0.0 },
  { 377.48145483420006, 4.5000000000000000, 100.00000000000000, 0.0 },
};
const double toler018 = 2.5000000000000020e-13;

// Test data for a=4.7500000000000000.
// max(|f - f_Boost|): 0.0000000000000000 at index 0
// max(|f - f_Boost| / |f_Boost|): 0.0000000000000000
// mean(f - f_Boost): 0.0000000000000000
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 0.0000000000000000
const testcase_lpochhammer<double>
data019[7] =
{
  { 1.5581446180465499, 4.7500000000000000, 1.0000000000000000, 0.0 },
  { 3.3073444728558088, 4.7500000000000000, 2.0000000000000000, 0.0 },
  { 9.4336335214750253, 4.7500000000000000, 5.0000000000000000, 0.0 },
  { 21.716229897365636, 4.7500000000000000, 10.000000000000000, 0.0 },
  { 51.177752043468168, 4.7500000000000000, 20.000000000000000, 0.0 },
  { 160.51256141951123, 4.7500000000000000, 50.000000000000000, 0.0 },
  { 378.28801891229477, 4.7500000000000000, 100.00000000000000, 0.0 },
};
const double toler019 = 2.5000000000000020e-13;

// Test data for a=5.0000000000000000.
// max(|f - f_Boost|): 2.8421709430404007e-14 at index 5
// max(|f - f_Boost| / |f_Boost|): 1.7637673061156899e-16
// mean(f - f_Boost): -4.0602442043434294e-15
// variance(f - f_Boost): 3.2055300275647462e-30
// stddev(f - f_Boost): 1.7903994044806725e-15
const testcase_lpochhammer<double>
data020[7] =
{
  { 1.6094379124341003, 5.0000000000000000, 1.0000000000000000, 0.0 },
  { 3.4011973816621555, 5.0000000000000000, 2.0000000000000000, 0.0 },
  { 9.6237736497335238, 5.0000000000000000, 5.0000000000000000, 0.0 },
  { 22.013167352390735, 5.0000000000000000, 10.000000000000000, 0.0 },
  { 51.606675567764377, 5.0000000000000000, 20.000000000000000, 0.0 },
  { 161.14205843284725, 5.0000000000000000, 50.000000000000000, 0.0 },
  { 379.08053494271206, 5.0000000000000000, 100.00000000000000, 0.0 },
};
const double toler020 = 2.5000000000000020e-13;

template<typename Ret, unsigned int Num>
  void
  test(const testcase_lpochhammer<Ret> (&data)[Num], Ret toler)
  {
    bool test __attribute__((unused)) = true;
    const Ret eps = std::numeric_limits<Ret>::epsilon();
    Ret max_abs_diff = -Ret(1);
    Ret max_abs_frac = -Ret(1);
    unsigned int num_datum = Num;
    for (unsigned int i = 0; i < num_datum; ++i)
      {
	const Ret f = __gnu_cxx::lpochhammer(data[i].a, data[i].x);
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
  test(data009, toler009);
  test(data010, toler010);
  test(data011, toler011);
  test(data012, toler012);
  test(data013, toler013);
  test(data014, toler014);
  test(data015, toler015);
  test(data016, toler016);
  test(data017, toler017);
  test(data018, toler018);
  test(data019, toler019);
  test(data020, toler020);
  return 0;
}
