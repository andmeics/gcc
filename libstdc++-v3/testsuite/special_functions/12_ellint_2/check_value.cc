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

//  ellint_2
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


// Test data for k=-0.90000000000000002.
// max(|f - f_GSL|): 8.8817841970012523e-16 at index 8
// max(|f - f_GSL| / |f_GSL|): 8.1185321054386169e-16
// mean(f - f_GSL): -1.2767564783189299e-16
// variance(f - f_GSL): 1.2360190398645194e-32
// stddev(f - f_GSL): 1.1117639317159552e-16
const testcase_ellint_2<double>
data001[10] =
{
  { 0.0000000000000000, -0.90000000000000002, 0.0000000000000000, 0.0 },
  { 0.17381690606167960, -0.90000000000000002, 0.17453292519943295, 0.0 },
  { 0.34337919186972055, -0.90000000000000002, 0.34906585039886590, 0.0 },
  { 0.50464268659856326, -0.90000000000000002, 0.52359877559829882, 0.0 },
  { 0.65400003842368570, -0.90000000000000002, 0.69813170079773179, 0.0 },
  { 0.78854928419904646, -0.90000000000000002, 0.87266462599716477, 0.0 },
  { 0.90645698626315396, -0.90000000000000002, 1.0471975511965976, 0.0 },
  { 1.0075154899135932, -0.90000000000000002, 1.2217304763960306, 0.0 },
  { 1.0940135583194075, -0.90000000000000002, 1.3962634015954636, 0.0 },
  { 1.1716970527816140, -0.90000000000000002, 1.5707963267948966, 0.0 },
};
const double toler001 = 2.5000000000000020e-13;

// Test data for k=-0.80000000000000004.
// max(|f - f_GSL|): 1.3322676295501878e-15 at index 9
// max(|f - f_GSL| / |f_GSL|): 1.0438106231598255e-15
// mean(f - f_GSL): 1.5543122344752191e-16
// variance(f - f_GSL): 1.7098073169489370e-31
// stddev(f - f_GSL): 4.1349816407681146e-16
const testcase_ellint_2<double>
data002[10] =
{
  { 0.0000000000000000, -0.80000000000000004, 0.0000000000000000, 0.0 },
  { 0.17396762274534805, -0.80000000000000004, 0.17453292519943295, 0.0 },
  { 0.34458685226969316, -0.80000000000000004, 0.34906585039886590, 0.0 },
  { 0.50872923654502433, -0.80000000000000004, 0.52359877559829882, 0.0 },
  { 0.66372016539176215, -0.80000000000000004, 0.69813170079773179, 0.0 },
  { 0.80760344410167406, -0.80000000000000004, 0.87266462599716477, 0.0 },
  { 0.93945480372495049, -0.80000000000000004, 1.0471975511965976, 0.0 },
  { 1.0597473310395038, -0.80000000000000004, 1.2217304763960306, 0.0 },
  { 1.1706981862452368, -0.80000000000000004, 1.3962634015954636, 0.0 },
  { 1.2763499431699064, -0.80000000000000004, 1.5707963267948966, 0.0 },
};
const double toler002 = 2.5000000000000020e-13;

// Test data for k=-0.69999999999999996.
// max(|f - f_GSL|): 4.4408920985006262e-16 at index 9
// max(|f - f_GSL| / |f_GSL|): 4.0435005012914979e-16
// mean(f - f_GSL): -7.2164496600635178e-17
// variance(f - f_GSL): 1.7077529916749237e-32
// stddev(f - f_GSL): 1.3068102355257720e-16
const testcase_ellint_2<double>
data003[10] =
{
  { 0.0000000000000000, -0.69999999999999996, 0.0000000000000000, 0.0 },
  { 0.17410041242702542, -0.69999999999999996, 0.17453292519943295, 0.0 },
  { 0.34564605085764760, -0.69999999999999996, 0.34906585039886590, 0.0 },
  { 0.51228495693314646, -0.69999999999999996, 0.52359877559829882, 0.0 },
  { 0.67207654098799530, -0.69999999999999996, 0.69813170079773179, 0.0 },
  { 0.82370932631556515, -0.69999999999999996, 0.87266462599716477, 0.0 },
  { 0.96672313309452795, -0.69999999999999996, 1.0471975511965976, 0.0 },
  { 1.1017090644949505, -0.69999999999999996, 1.2217304763960306, 0.0 },
  { 1.2304180097292921, -0.69999999999999996, 1.3962634015954636, 0.0 },
  { 1.3556611355719554, -0.69999999999999996, 1.5707963267948966, 0.0 },
};
const double toler003 = 2.5000000000000020e-13;

// Test data for k=-0.59999999999999998.
// max(|f - f_GSL|): 4.4408920985006262e-16 at index 8
// max(|f - f_GSL| / |f_GSL|): 3.4747085911018057e-16
// mean(f - f_GSL): -1.9428902930940238e-17
// variance(f - f_GSL): 4.6602749271592373e-35
// stddev(f - f_GSL): 6.8266206333435850e-18
const testcase_ellint_2<double>
data004[10] =
{
  { 0.0000000000000000, -0.59999999999999998, 0.0000000000000000, 0.0 },
  { 0.17421534919599127, -0.59999999999999998, 0.17453292519943295, 0.0 },
  { 0.34655927787174101, -0.59999999999999998, 0.34906585039886590, 0.0 },
  { 0.51533034538432143, -0.59999999999999998, 0.52359877559829882, 0.0 },
  { 0.67916550597453018, -0.59999999999999998, 0.69813170079773179, 0.0 },
  { 0.83720218180349870, -0.59999999999999998, 0.87266462599716477, 0.0 },
  { 0.98922159354937755, -0.59999999999999998, 1.0471975511965976, 0.0 },
  { 1.1357478470419362, -0.59999999999999998, 1.2217304763960306, 0.0 },
  { 1.2780617372844065, -0.59999999999999998, 1.3962634015954636, 0.0 },
  { 1.4180833944487241, -0.59999999999999998, 1.5707963267948966, 0.0 },
};
const double toler004 = 2.5000000000000020e-13;

// Test data for k=-0.50000000000000000.
// max(|f - f_GSL|): 8.8817841970012523e-16 at index 7
// max(|f - f_GSL| / |f_GSL|): 7.6357985642402232e-16
// mean(f - f_GSL): -1.1934897514720432e-16
// variance(f - f_GSL): 1.4388836606733082e-32
// stddev(f - f_GSL): 1.1995347684303728e-16
const testcase_ellint_2<double>
data005[10] =
{
  { 0.0000000000000000, -0.50000000000000000, 0.0000000000000000, 0.0 },
  { 0.17431249677315910, -0.50000000000000000, 0.17453292519943295, 0.0 },
  { 0.34732862537770803, -0.50000000000000000, 0.34906585039886590, 0.0 },
  { 0.51788193485993794, -0.50000000000000000, 0.52359877559829882, 0.0 },
  { 0.68506022954164536, -0.50000000000000000, 0.69813170079773179, 0.0 },
  { 0.84831662803347196, -0.50000000000000000, 0.87266462599716477, 0.0 },
  { 1.0075555551444717, -0.50000000000000000, 1.0471975511965976, 0.0 },
  { 1.1631768599287307, -0.50000000000000000, 1.2217304763960306, 0.0 },
  { 1.3160584048772552, -0.50000000000000000, 1.3962634015954636, 0.0 },
  { 1.4674622093394274, -0.50000000000000000, 1.5707963267948966, 0.0 },
};
const double toler005 = 2.5000000000000020e-13;

// Test data for k=-0.39999999999999991.
// max(|f - f_GSL|): 4.4408920985006262e-16 at index 9
// max(|f - f_GSL| / |f_GSL|): 3.2188943299675670e-16
// mean(f - f_GSL): 4.1633363423443370e-17
// variance(f - f_GSL): 1.9996383743576116e-32
// stddev(f - f_GSL): 1.4140857026211713e-16
const testcase_ellint_2<double>
data006[10] =
{
  { 0.0000000000000000, -0.39999999999999991, 0.0000000000000000, 0.0 },
  { 0.17439190872481267, -0.39999999999999991, 0.17453292519943295, 0.0 },
  { 0.34795581767099210, -0.39999999999999991, 0.34906585039886590, 0.0 },
  { 0.51995290683804463, -0.39999999999999991, 0.52359877559829882, 0.0 },
  { 0.68981638464431538, -0.39999999999999991, 0.69813170079773179, 0.0 },
  { 0.85722088859936041, -0.39999999999999991, 0.87266462599716477, 0.0 },
  { 1.0221301327876993, -0.39999999999999991, 1.0471975511965976, 0.0 },
  { 1.1848138019818375, -0.39999999999999991, 1.2217304763960306, 0.0 },
  { 1.3458259266501535, -0.39999999999999991, 1.3962634015954636, 0.0 },
  { 1.5059416123600404, -0.39999999999999991, 1.5707963267948966, 0.0 },
};
const double toler006 = 2.5000000000000020e-13;

// Test data for k=-0.29999999999999993.
// max(|f - f_GSL|): 4.4408920985006262e-16 at index 9
// max(|f - f_GSL| / |f_GSL|): 6.3860540218057383e-16
// mean(f - f_GSL): -2.2204460492503132e-17
// variance(f - f_GSL): 2.6843183580437205e-32
// stddev(f - f_GSL): 1.6383889520024605e-16
const testcase_ellint_2<double>
data007[10] =
{
  { 0.0000000000000000, -0.29999999999999993, 0.0000000000000000, 0.0 },
  { 0.17445362864048913, -0.29999999999999993, 0.17453292519943295, 0.0 },
  { 0.34844223535713464, -0.29999999999999993, 0.34906585039886590, 0.0 },
  { 0.52155353877411770, -0.29999999999999993, 0.52359877559829882, 0.0 },
  { 0.69347584418369879, -0.29999999999999993, 0.69813170079773179, 0.0 },
  { 0.86403609928237668, -0.29999999999999993, 0.87266462599716477, 0.0 },
  { 1.0332234514065408, -0.29999999999999993, 1.0471975511965976, 0.0 },
  { 1.2011943182068927, -0.29999999999999993, 1.2217304763960306, 0.0 },
  { 1.3682566113689627, -0.29999999999999993, 1.3962634015954636, 0.0 },
  { 1.5348334649232491, -0.29999999999999993, 1.5707963267948966, 0.0 },
};
const double toler007 = 2.5000000000000020e-13;

// Test data for k=-0.19999999999999996.
// max(|f - f_GSL|): 1.1102230246251565e-15 at index 8
// max(|f - f_GSL| / |f_GSL|): 8.0222718664258199e-16
// mean(f - f_GSL): -7.2164496600635178e-17
// variance(f - f_GSL): 6.7294369948179385e-32
// stddev(f - f_GSL): 2.5941158406705623e-16
const testcase_ellint_2<double>
data008[10] =
{
  { 0.0000000000000000, -0.19999999999999996, 0.0000000000000000, 0.0 },
  { 0.17449769027652812, -0.19999999999999996, 0.17453292519943295, 0.0 },
  { 0.34878893400762095, -0.19999999999999996, 0.34906585039886590, 0.0 },
  { 0.52269152856057410, -0.19999999999999996, 0.52359877559829882, 0.0 },
  { 0.69606913360157563, -0.19999999999999996, 0.69813170079773179, 0.0 },
  { 0.86884782374863356, -0.19999999999999996, 0.87266462599716477, 0.0 },
  { 1.0410255369689567, -0.19999999999999996, 1.0471975511965976, 0.0 },
  { 1.2126730391631362, -0.19999999999999996, 1.2217304763960306, 0.0 },
  { 1.3839259540325159, -0.19999999999999996, 1.3962634015954636, 0.0 },
  { 1.5549685462425291, -0.19999999999999996, 1.5707963267948966, 0.0 },
};
const double toler008 = 2.5000000000000020e-13;

// Test data for k=-0.099999999999999978.
// max(|f - f_GSL|): 8.8817841970012523e-16 at index 8
// max(|f - f_GSL| / |f_GSL|): 6.3751190970696029e-16
// mean(f - f_GSL): -1.3877787807814457e-16
// variance(f - f_GSL): 8.5596886417210486e-34
// stddev(f - f_GSL): 2.9256945571472510e-17
const testcase_ellint_2<double>
data009[10] =
{
  { 0.0000000000000000, -0.099999999999999978, 0.0000000000000000, 0.0 },
  { 0.17452411766649939, -0.099999999999999978, 0.17453292519943295, 0.0 },
  { 0.34899665805442404, -0.099999999999999978, 0.34906585039886590, 0.0 },
  { 0.52337222400508776, -0.099999999999999978, 0.52359877559829882, 0.0 },
  { 0.69761705217284864, -0.099999999999999978, 0.69813170079773179, 0.0 },
  { 0.87171309273007491, -0.099999999999999978, 0.87266462599716477, 0.0 },
  { 1.0456602197056326, -0.099999999999999978, 1.0471975511965976, 0.0 },
  { 1.2194762899272031, -0.099999999999999978, 1.2217304763960306, 0.0 },
  { 1.3931950229892751, -0.099999999999999978, 1.3962634015954636, 0.0 },
  { 1.5668619420216685, -0.099999999999999978, 1.5707963267948966, 0.0 },
};
const double toler009 = 2.5000000000000020e-13;

// Test data for k=0.0000000000000000.
// max(|f - f_GSL|): 4.4408920985006262e-16 at index 8
// max(|f - f_GSL| / |f_GSL|): 3.1805546814635157e-16
// mean(f - f_GSL): -3.3306690738754695e-17
// variance(f - f_GSL): 1.3695501826753678e-34
// stddev(f - f_GSL): 1.1702778228589003e-17
const testcase_ellint_2<double>
data010[10] =
{
  { 0.0000000000000000, 0.0000000000000000, 0.0000000000000000, 0.0 },
  { 0.17453292519943292, 0.0000000000000000, 0.17453292519943295, 0.0 },
  { 0.34906585039886584, 0.0000000000000000, 0.34906585039886590, 0.0 },
  { 0.52359877559829870, 0.0000000000000000, 0.52359877559829882, 0.0 },
  { 0.69813170079773168, 0.0000000000000000, 0.69813170079773179, 0.0 },
  { 0.87266462599716477, 0.0000000000000000, 0.87266462599716477, 0.0 },
  { 1.0471975511965974, 0.0000000000000000, 1.0471975511965976, 0.0 },
  { 1.2217304763960308, 0.0000000000000000, 1.2217304763960306, 0.0 },
  { 1.3962634015954640, 0.0000000000000000, 1.3962634015954636, 0.0 },
  { 1.5707963267948966, 0.0000000000000000, 1.5707963267948966, 0.0 },
};
const double toler010 = 2.5000000000000020e-13;

// Test data for k=0.10000000000000009.
// max(|f - f_GSL|): 8.8817841970012523e-16 at index 8
// max(|f - f_GSL| / |f_GSL|): 6.3751190970696029e-16
// mean(f - f_GSL): -1.3877787807814457e-16
// variance(f - f_GSL): 8.5596886417210486e-34
// stddev(f - f_GSL): 2.9256945571472510e-17
const testcase_ellint_2<double>
data011[10] =
{
  { 0.0000000000000000, 0.10000000000000009, 0.0000000000000000, 0.0 },
  { 0.17452411766649939, 0.10000000000000009, 0.17453292519943295, 0.0 },
  { 0.34899665805442404, 0.10000000000000009, 0.34906585039886590, 0.0 },
  { 0.52337222400508776, 0.10000000000000009, 0.52359877559829882, 0.0 },
  { 0.69761705217284864, 0.10000000000000009, 0.69813170079773179, 0.0 },
  { 0.87171309273007491, 0.10000000000000009, 0.87266462599716477, 0.0 },
  { 1.0456602197056326, 0.10000000000000009, 1.0471975511965976, 0.0 },
  { 1.2194762899272031, 0.10000000000000009, 1.2217304763960306, 0.0 },
  { 1.3931950229892751, 0.10000000000000009, 1.3962634015954636, 0.0 },
  { 1.5668619420216685, 0.10000000000000009, 1.5707963267948966, 0.0 },
};
const double toler011 = 2.5000000000000020e-13;

// Test data for k=0.20000000000000018.
// max(|f - f_GSL|): 1.1102230246251565e-15 at index 8
// max(|f - f_GSL| / |f_GSL|): 8.0222718664258199e-16
// mean(f - f_GSL): -7.2164496600635178e-17
// variance(f - f_GSL): 6.7294369948179385e-32
// stddev(f - f_GSL): 2.5941158406705623e-16
const testcase_ellint_2<double>
data012[10] =
{
  { 0.0000000000000000, 0.20000000000000018, 0.0000000000000000, 0.0 },
  { 0.17449769027652812, 0.20000000000000018, 0.17453292519943295, 0.0 },
  { 0.34878893400762095, 0.20000000000000018, 0.34906585039886590, 0.0 },
  { 0.52269152856057410, 0.20000000000000018, 0.52359877559829882, 0.0 },
  { 0.69606913360157563, 0.20000000000000018, 0.69813170079773179, 0.0 },
  { 0.86884782374863356, 0.20000000000000018, 0.87266462599716477, 0.0 },
  { 1.0410255369689567, 0.20000000000000018, 1.0471975511965976, 0.0 },
  { 1.2126730391631362, 0.20000000000000018, 1.2217304763960306, 0.0 },
  { 1.3839259540325159, 0.20000000000000018, 1.3962634015954636, 0.0 },
  { 1.5549685462425289, 0.20000000000000018, 1.5707963267948966, 0.0 },
};
const double toler012 = 2.5000000000000020e-13;

// Test data for k=0.30000000000000004.
// max(|f - f_GSL|): 4.4408920985006262e-16 at index 9
// max(|f - f_GSL| / |f_GSL|): 6.3860540218057383e-16
// mean(f - f_GSL): -2.2204460492503132e-17
// variance(f - f_GSL): 2.6843183580437205e-32
// stddev(f - f_GSL): 1.6383889520024605e-16
const testcase_ellint_2<double>
data013[10] =
{
  { 0.0000000000000000, 0.30000000000000004, 0.0000000000000000, 0.0 },
  { 0.17445362864048913, 0.30000000000000004, 0.17453292519943295, 0.0 },
  { 0.34844223535713464, 0.30000000000000004, 0.34906585039886590, 0.0 },
  { 0.52155353877411770, 0.30000000000000004, 0.52359877559829882, 0.0 },
  { 0.69347584418369879, 0.30000000000000004, 0.69813170079773179, 0.0 },
  { 0.86403609928237668, 0.30000000000000004, 0.87266462599716477, 0.0 },
  { 1.0332234514065408, 0.30000000000000004, 1.0471975511965976, 0.0 },
  { 1.2011943182068927, 0.30000000000000004, 1.2217304763960306, 0.0 },
  { 1.3682566113689627, 0.30000000000000004, 1.3962634015954636, 0.0 },
  { 1.5348334649232491, 0.30000000000000004, 1.5707963267948966, 0.0 },
};
const double toler013 = 2.5000000000000020e-13;

// Test data for k=0.40000000000000013.
// max(|f - f_GSL|): 1.7763568394002505e-15 at index 9
// max(|f - f_GSL| / |f_GSL|): 1.1795655454506157e-15
// mean(f - f_GSL): 1.7486012637846215e-16
// variance(f - f_GSL): 3.1664095331106078e-31
// stddev(f - f_GSL): 5.6270858649132121e-16
const testcase_ellint_2<double>
data014[10] =
{
  { 0.0000000000000000, 0.40000000000000013, 0.0000000000000000, 0.0 },
  { 0.17439190872481267, 0.40000000000000013, 0.17453292519943295, 0.0 },
  { 0.34795581767099210, 0.40000000000000013, 0.34906585039886590, 0.0 },
  { 0.51995290683804463, 0.40000000000000013, 0.52359877559829882, 0.0 },
  { 0.68981638464431527, 0.40000000000000013, 0.69813170079773179, 0.0 },
  { 0.85722088859936041, 0.40000000000000013, 0.87266462599716477, 0.0 },
  { 1.0221301327876993, 0.40000000000000013, 1.0471975511965976, 0.0 },
  { 1.1848138019818375, 0.40000000000000013, 1.2217304763960306, 0.0 },
  { 1.3458259266501533, 0.40000000000000013, 1.3962634015954636, 0.0 },
  { 1.5059416123600402, 0.40000000000000013, 1.5707963267948966, 0.0 },
};
const double toler014 = 2.5000000000000020e-13;

// Test data for k=0.50000000000000000.
// max(|f - f_GSL|): 8.8817841970012523e-16 at index 7
// max(|f - f_GSL| / |f_GSL|): 7.6357985642402232e-16
// mean(f - f_GSL): -1.1934897514720432e-16
// variance(f - f_GSL): 1.4388836606733082e-32
// stddev(f - f_GSL): 1.1995347684303728e-16
const testcase_ellint_2<double>
data015[10] =
{
  { 0.0000000000000000, 0.50000000000000000, 0.0000000000000000, 0.0 },
  { 0.17431249677315910, 0.50000000000000000, 0.17453292519943295, 0.0 },
  { 0.34732862537770803, 0.50000000000000000, 0.34906585039886590, 0.0 },
  { 0.51788193485993794, 0.50000000000000000, 0.52359877559829882, 0.0 },
  { 0.68506022954164536, 0.50000000000000000, 0.69813170079773179, 0.0 },
  { 0.84831662803347196, 0.50000000000000000, 0.87266462599716477, 0.0 },
  { 1.0075555551444717, 0.50000000000000000, 1.0471975511965976, 0.0 },
  { 1.1631768599287307, 0.50000000000000000, 1.2217304763960306, 0.0 },
  { 1.3160584048772552, 0.50000000000000000, 1.3962634015954636, 0.0 },
  { 1.4674622093394274, 0.50000000000000000, 1.5707963267948966, 0.0 },
};
const double toler015 = 2.5000000000000020e-13;

// Test data for k=0.60000000000000009.
// max(|f - f_GSL|): 2.2204460492503131e-16 at index 5
// max(|f - f_GSL| / |f_GSL|): 2.6522220050442704e-16
// mean(f - f_GSL): -8.3266726846886737e-18
// variance(f - f_GSL): 5.6389326618626776e-33
// stddev(f - f_GSL): 7.5092826966779442e-17
const testcase_ellint_2<double>
data016[10] =
{
  { 0.0000000000000000, 0.60000000000000009, 0.0000000000000000, 0.0 },
  { 0.17421534919599127, 0.60000000000000009, 0.17453292519943295, 0.0 },
  { 0.34655927787174101, 0.60000000000000009, 0.34906585039886590, 0.0 },
  { 0.51533034538432143, 0.60000000000000009, 0.52359877559829882, 0.0 },
  { 0.67916550597453018, 0.60000000000000009, 0.69813170079773179, 0.0 },
  { 0.83720218180349870, 0.60000000000000009, 0.87266462599716477, 0.0 },
  { 0.98922159354937744, 0.60000000000000009, 1.0471975511965976, 0.0 },
  { 1.1357478470419362, 0.60000000000000009, 1.2217304763960306, 0.0 },
  { 1.2780617372844063, 0.60000000000000009, 1.3962634015954636, 0.0 },
  { 1.4180833944487241, 0.60000000000000009, 1.5707963267948966, 0.0 },
};
const double toler016 = 2.5000000000000020e-13;

// Test data for k=0.70000000000000018.
// max(|f - f_GSL|): 4.4408920985006262e-16 at index 8
// max(|f - f_GSL| / |f_GSL|): 4.0435005012914984e-16
// mean(f - f_GSL): -4.9960036108132046e-17
// variance(f - f_GSL): 9.1341388572321050e-33
// stddev(f - f_GSL): 9.5572688866810198e-17
const testcase_ellint_2<double>
data017[10] =
{
  { 0.0000000000000000, 0.70000000000000018, 0.0000000000000000, 0.0 },
  { 0.17410041242702540, 0.70000000000000018, 0.17453292519943295, 0.0 },
  { 0.34564605085764760, 0.70000000000000018, 0.34906585039886590, 0.0 },
  { 0.51228495693314646, 0.70000000000000018, 0.52359877559829882, 0.0 },
  { 0.67207654098799519, 0.70000000000000018, 0.69813170079773179, 0.0 },
  { 0.82370932631556504, 0.70000000000000018, 0.87266462599716477, 0.0 },
  { 0.96672313309452784, 0.70000000000000018, 1.0471975511965976, 0.0 },
  { 1.1017090644949503, 0.70000000000000018, 1.2217304763960306, 0.0 },
  { 1.2304180097292925, 0.70000000000000018, 1.3962634015954636, 0.0 },
  { 1.3556611355719554, 0.70000000000000018, 1.5707963267948966, 0.0 },
};
const double toler017 = 2.5000000000000020e-13;

// Test data for k=0.80000000000000004.
// max(|f - f_GSL|): 1.3322676295501878e-15 at index 9
// max(|f - f_GSL| / |f_GSL|): 1.0438106231598255e-15
// mean(f - f_GSL): 1.5543122344752191e-16
// variance(f - f_GSL): 1.7098073169489370e-31
// stddev(f - f_GSL): 4.1349816407681146e-16
const testcase_ellint_2<double>
data018[10] =
{
  { 0.0000000000000000, 0.80000000000000004, 0.0000000000000000, 0.0 },
  { 0.17396762274534805, 0.80000000000000004, 0.17453292519943295, 0.0 },
  { 0.34458685226969316, 0.80000000000000004, 0.34906585039886590, 0.0 },
  { 0.50872923654502433, 0.80000000000000004, 0.52359877559829882, 0.0 },
  { 0.66372016539176215, 0.80000000000000004, 0.69813170079773179, 0.0 },
  { 0.80760344410167406, 0.80000000000000004, 0.87266462599716477, 0.0 },
  { 0.93945480372495049, 0.80000000000000004, 1.0471975511965976, 0.0 },
  { 1.0597473310395038, 0.80000000000000004, 1.2217304763960306, 0.0 },
  { 1.1706981862452368, 0.80000000000000004, 1.3962634015954636, 0.0 },
  { 1.2763499431699064, 0.80000000000000004, 1.5707963267948966, 0.0 },
};
const double toler018 = 2.5000000000000020e-13;

// Test data for k=0.90000000000000013.
// max(|f - f_GSL|): 1.1102230246251565e-15 at index 8
// max(|f - f_GSL| / |f_GSL|): 1.0148165131798269e-15
// mean(f - f_GSL): -1.7208456881689927e-16
// variance(f - f_GSL): 9.1341388572321050e-33
// stddev(f - f_GSL): 9.5572688866810198e-17
const testcase_ellint_2<double>
data019[10] =
{
  { 0.0000000000000000, 0.90000000000000013, 0.0000000000000000, 0.0 },
  { 0.17381690606167960, 0.90000000000000013, 0.17453292519943295, 0.0 },
  { 0.34337919186972055, 0.90000000000000013, 0.34906585039886590, 0.0 },
  { 0.50464268659856337, 0.90000000000000013, 0.52359877559829882, 0.0 },
  { 0.65400003842368593, 0.90000000000000013, 0.69813170079773179, 0.0 },
  { 0.78854928419904657, 0.90000000000000013, 0.87266462599716477, 0.0 },
  { 0.90645698626315396, 0.90000000000000013, 1.0471975511965976, 0.0 },
  { 1.0075154899135930, 0.90000000000000013, 1.2217304763960306, 0.0 },
  { 1.0940135583194077, 0.90000000000000013, 1.3962634015954636, 0.0 },
  { 1.1716970527816144, 0.90000000000000013, 1.5707963267948966, 0.0 },
};
const double toler019 = 2.5000000000000020e-13;

template<typename Ret, unsigned int Num>
  void
  test(const testcase_ellint_2<Ret> (&data)[Num], Ret toler)
  {
    const Ret eps = std::numeric_limits<Ret>::epsilon();
    Ret max_abs_diff = -Ret(1);
    Ret max_abs_frac = -Ret(1);
    unsigned int num_datum = Num;
    for (unsigned int i = 0; i < num_datum; ++i)
      {
	const Ret f = std::ellint_2(data[i].k, data[i].phi);
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
  return 0;
}
