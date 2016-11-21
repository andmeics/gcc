// { dg-do run { target c++11 } }
// { dg-options "-D__STDCPP_WANT_MATH_SPEC_FUNCS__" }
//
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

//  cyl_bessel_k
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


// Test data for nu=0.0000000000000000.
// max(|f - f_GSL|): 2.2204460492503131e-16
// max(|f - f_GSL| / |f_GSL|): 1.7863051312335036e-16
const testcase_cyl_bessel_k<double>
data001[20] =
{
  { 1.5415067512483025, 0.0000000000000000, 0.25000000000000000 },
  { 0.92441907122766565, 0.0000000000000000, 0.50000000000000000 },
  { 0.61058242211646430, 0.0000000000000000, 0.75000000000000000 },
  { 0.42102443824070829, 0.0000000000000000, 1.0000000000000000 },
  { 0.29760308908410588, 0.0000000000000000, 1.2500000000000000 },
  { 0.21380556264752565, 0.0000000000000000, 1.5000000000000000 },
  { 0.15537981238660362, 0.0000000000000000, 1.7500000000000000 },
  { 0.11389387274953360, 0.0000000000000000, 2.0000000000000000 },
  { 0.084043111974658191, 0.0000000000000000, 2.2500000000000000 },
  { 0.062347553200366168, 0.0000000000000000, 2.5000000000000000 },
  { 0.046454901308760774, 0.0000000000000000, 2.7500000000000000 },
  { 0.034739504386279256, 0.0000000000000000, 3.0000000000000000 },
  { 0.026058755255154966, 0.0000000000000000, 3.2500000000000000 },
  { 0.019598897170368501, 0.0000000000000000, 3.5000000000000000 },
  { 0.014774250877128706, 0.0000000000000000, 3.7500000000000000 },
  { 0.011159676085853026, 0.0000000000000000, 4.0000000000000000 },
  { 0.0084443877245429649, 0.0000000000000000, 4.2500000000000000 },
  { 0.0063998572432339747, 0.0000000000000000, 4.5000000000000000 },
  { 0.0048572045578879524, 0.0000000000000000, 4.7500000000000000 },
  { 0.0036910983340425947, 0.0000000000000000, 5.0000000000000000 },
};
const double toler001 = 2.5000000000000020e-13;

// Test data for nu=0.33333333333333331.
// max(|f - f_GSL|): 1.3322676295501878e-15
// max(|f - f_GSL| / |f_GSL|): 4.3522010494015439e-15
const testcase_cyl_bessel_k<double>
data002[20] =
{
  { 1.7144912564234518, 0.33333333333333331, 0.25000000000000000 },
  { 0.98903107424672421, 0.33333333333333331, 0.50000000000000000 },
  { 0.64216899667282989, 0.33333333333333331, 0.75000000000000000 },
  { 0.43843063344153432, 0.33333333333333331, 1.0000000000000000 },
  { 0.30788192414945043, 0.33333333333333331, 1.2500000000000000 },
  { 0.22015769026776688, 0.33333333333333331, 1.5000000000000000 },
  { 0.15943413057311245, 0.33333333333333331, 1.7500000000000000 },
  { 0.11654496129616534, 0.33333333333333331, 2.0000000000000000 },
  { 0.085809609306439674, 0.33333333333333331, 2.2500000000000000 },
  { 0.063542537454733386, 0.33333333333333331, 2.5000000000000000 },
  { 0.047273354184795509, 0.33333333333333331, 2.7500000000000000 },
  { 0.035305904902162587, 0.33333333333333331, 3.0000000000000000 },
  { 0.026454186892773169, 0.33333333333333331, 3.2500000000000000 },
  { 0.019877061407943805, 0.33333333333333331, 3.5000000000000000 },
  { 0.014971213514760214, 0.33333333333333331, 3.7500000000000000 },
  { 0.011299947573672165, 0.33333333333333331, 4.0000000000000000 },
  { 0.0085447959546110473, 0.33333333333333331, 4.2500000000000000 },
  { 0.0064720581217078237, 0.33333333333333331, 4.5000000000000000 },
  { 0.0049093342803275264, 0.33333333333333331, 4.7500000000000000 },
  { 0.0037288750960535887, 0.33333333333333331, 5.0000000000000000 },
};
const double toler002 = 2.5000000000000020e-13;

// Test data for nu=0.50000000000000000.
// max(|f - f_GSL|): 1.3322676295501878e-15
// max(|f - f_GSL| / |f_GSL|): 1.5172850443872369e-15
const testcase_cyl_bessel_k<double>
data003[20] =
{
  { 1.9521640631515476, 0.50000000000000000, 0.25000000000000000 },
  { 1.0750476034999195, 0.50000000000000000, 0.50000000000000000 },
  { 0.68361006034952421, 0.50000000000000000, 0.75000000000000000 },
  { 0.46106850444789454, 0.50000000000000000, 1.0000000000000000 },
  { 0.32117137397144746, 0.50000000000000000, 1.2500000000000000 },
  { 0.22833505222826550, 0.50000000000000000, 1.5000000000000000 },
  { 0.16463628997380864, 0.50000000000000000, 1.7500000000000000 },
  { 0.11993777196806145, 0.50000000000000000, 2.0000000000000000 },
  { 0.088065558803650454, 0.50000000000000000, 2.2500000000000000 },
  { 0.065065943154009986, 0.50000000000000000, 2.5000000000000000 },
  { 0.048315198301417825, 0.50000000000000000, 2.7500000000000000 },
  { 0.036025985131764589, 0.50000000000000000, 3.0000000000000000 },
  { 0.026956356532443351, 0.50000000000000000, 3.2500000000000000 },
  { 0.020229969578139294, 0.50000000000000000, 3.5000000000000000 },
  { 0.015220888252975564, 0.50000000000000000, 3.7500000000000000 },
  { 0.011477624576608052, 0.50000000000000000, 4.0000000000000000 },
  { 0.0086718932956978342, 0.50000000000000000, 4.2500000000000000 },
  { 0.0065633945646345407, 0.50000000000000000, 4.5000000000000000 },
  { 0.0049752435421262292, 0.50000000000000000, 4.7500000000000000 },
  { 0.0037766133746428825, 0.50000000000000000, 5.0000000000000000 },
};
const double toler003 = 2.5000000000000020e-13;

// Test data for nu=0.66666666666666663.
// max(|f - f_GSL|): 4.4408920985006262e-16
// max(|f - f_GSL| / |f_GSL|): 8.1483075013172610e-16
const testcase_cyl_bessel_k<double>
data004[20] =
{
  { 2.3289060745544101, 0.66666666666666663, 0.25000000000000000 },
  { 1.2059304647203353, 0.66666666666666663, 0.50000000000000000 },
  { 0.74547232976647215, 0.66666666666666663, 0.75000000000000000 },
  { 0.49447506210420827, 0.66666666666666663, 1.0000000000000000 },
  { 0.34062994813514252, 0.66666666666666663, 1.2500000000000000 },
  { 0.24024045240315581, 0.66666666666666663, 1.5000000000000000 },
  { 0.17217716908452310, 0.66666666666666663, 1.7500000000000000 },
  { 0.12483892748812841, 0.66666666666666663, 2.0000000000000000 },
  { 0.091315296079621050, 0.66666666666666663, 2.2500000000000000 },
  { 0.067255322171623361, 0.66666666666666663, 2.5000000000000000 },
  { 0.049809546542402224, 0.66666666666666663, 2.7500000000000000 },
  { 0.037057074495188531, 0.66666666666666663, 3.0000000000000000 },
  { 0.027674365504886729, 0.66666666666666663, 3.2500000000000000 },
  { 0.020733915836010912, 0.66666666666666663, 3.5000000000000000 },
  { 0.015577015510251332, 0.66666666666666663, 3.7500000000000000 },
  { 0.011730801456525336, 0.66666666666666663, 4.0000000000000000 },
  { 0.0088528343204658851, 0.66666666666666663, 4.2500000000000000 },
  { 0.0066933190915775560, 0.66666666666666663, 4.5000000000000000 },
  { 0.0050689292106255480, 0.66666666666666663, 4.7500000000000000 },
  { 0.0038444246344968226, 0.66666666666666663, 5.0000000000000000 },
};
const double toler004 = 2.5000000000000020e-13;

// Test data for nu=1.0000000000000000.
// max(|f - f_GSL|): 5.5511151231257827e-17
// max(|f - f_GSL| / |f_GSL|): 2.7422040631145076e-16
const testcase_cyl_bessel_k<double>
data005[20] =
{
  { 3.7470259744407115, 1.0000000000000000, 0.25000000000000000 },
  { 1.6564411200033007, 1.0000000000000000, 0.50000000000000000 },
  { 0.94958046696214016, 1.0000000000000000, 0.75000000000000000 },
  { 0.60190723019723458, 1.0000000000000000, 1.0000000000000000 },
  { 0.40212407978419540, 1.0000000000000000, 1.2500000000000000 },
  { 0.27738780045684375, 1.0000000000000000, 1.5000000000000000 },
  { 0.19547745347439310, 1.0000000000000000, 1.7500000000000000 },
  { 0.13986588181652262, 1.0000000000000000, 2.0000000000000000 },
  { 0.10121630256832535, 1.0000000000000000, 2.2500000000000000 },
  { 0.073890816347747038, 1.0000000000000000, 2.5000000000000000 },
  { 0.054318522758919859, 1.0000000000000000, 2.7500000000000000 },
  { 0.040156431128194198, 1.0000000000000000, 3.0000000000000000 },
  { 0.029825529796040143, 1.0000000000000000, 3.2500000000000000 },
  { 0.022239392925923845, 1.0000000000000000, 3.5000000000000000 },
  { 0.016638191754688912, 1.0000000000000000, 3.7500000000000000 },
  { 0.012483498887268435, 1.0000000000000000, 4.0000000000000000 },
  { 0.0093896806560432589, 1.0000000000000000, 4.2500000000000000 },
  { 0.0070780949089680901, 1.0000000000000000, 4.5000000000000000 },
  { 0.0053459218178228390, 1.0000000000000000, 4.7500000000000000 },
  { 0.0040446134454521655, 1.0000000000000000, 5.0000000000000000 },
};
const double toler005 = 2.5000000000000020e-13;

// Test data for nu=2.0000000000000000.
// max(|f - f_GSL|): 3.5527136788005009e-15
// max(|f - f_GSL| / |f_GSL|): 1.9937716861613039e-16
const testcase_cyl_bessel_k<double>
data006[20] =
{
  { 31.517714546773998, 2.0000000000000000, 0.25000000000000000 },
  { 7.5501835512408695, 2.0000000000000000, 0.50000000000000000 },
  { 3.1427970006821715, 2.0000000000000000, 0.75000000000000000 },
  { 1.6248388986351774, 2.0000000000000000, 1.0000000000000000 },
  { 0.94100161673881855, 2.0000000000000000, 1.2500000000000000 },
  { 0.58365596325665070, 2.0000000000000000, 1.5000000000000000 },
  { 0.37878261635733856, 2.0000000000000000, 1.7500000000000000 },
  { 0.25375975456605621, 2.0000000000000000, 2.0000000000000000 },
  { 0.17401315870205850, 2.0000000000000000, 2.2500000000000000 },
  { 0.12146020627856381, 2.0000000000000000, 2.5000000000000000 },
  { 0.085959281497066137, 2.0000000000000000, 2.7500000000000000 },
  { 0.061510458471742059, 2.0000000000000000, 3.0000000000000000 },
  { 0.044412927437333515, 2.0000000000000000, 3.2500000000000000 },
  { 0.032307121699467839, 2.0000000000000000, 3.5000000000000000 },
  { 0.023647953146296127, 2.0000000000000000, 3.7500000000000000 },
  { 0.017401425529487244, 2.0000000000000000, 4.0000000000000000 },
  { 0.012863060974445674, 2.0000000000000000, 4.2500000000000000 },
  { 0.0095456772027753475, 2.0000000000000000, 4.5000000000000000 },
  { 0.0071081190074975690, 2.0000000000000000, 4.7500000000000000 },
  { 0.0053089437122234608, 2.0000000000000000, 5.0000000000000000 },
};
const double toler006 = 2.5000000000000020e-13;

// Test data for nu=5.0000000000000000.
// max(|f - f_GSL|): 5.8207660913467407e-11
// max(|f - f_GSL| / |f_GSL|): 2.4867363835720159e-16
const testcase_cyl_bessel_k<double>
data007[20] =
{
  { 391683.98962334893, 5.0000000000000000, 0.25000000000000000 },
  { 12097.979476096394, 5.0000000000000000, 0.50000000000000000 },
  { 1562.5870339691098, 5.0000000000000000, 0.75000000000000000 },
  { 360.96058960124066, 5.0000000000000000, 1.0000000000000000 },
  { 114.29321426334016, 5.0000000000000000, 1.2500000000000000 },
  { 44.067781159301056, 5.0000000000000000, 1.5000000000000000 },
  { 19.426568687730292, 5.0000000000000000, 1.7500000000000000 },
  { 9.4310491005964820, 5.0000000000000000, 2.0000000000000000 },
  { 4.9221270549918685, 5.0000000000000000, 2.2500000000000000 },
  { 2.7168842907865423, 5.0000000000000000, 2.5000000000000000 },
  { 1.5677685890536335, 5.0000000000000000, 2.7500000000000000 },
  { 0.93777360238680818, 5.0000000000000000, 3.0000000000000000 },
  { 0.57775534736785106, 5.0000000000000000, 3.2500000000000000 },
  { 0.36482440208451983, 5.0000000000000000, 3.5000000000000000 },
  { 0.23520290620082257, 5.0000000000000000, 3.7500000000000000 },
  { 0.15434254872599723, 5.0000000000000000, 4.0000000000000000 },
  { 0.10283347176876455, 5.0000000000000000, 4.2500000000000000 },
  { 0.069423643150881773, 5.0000000000000000, 4.5000000000000000 },
  { 0.047410616917942211, 5.0000000000000000, 4.7500000000000000 },
  { 0.032706273712031865, 5.0000000000000000, 5.0000000000000000 },
};
const double toler007 = 2.5000000000000020e-13;

// Test data for nu=10.000000000000000.
// max(|f - f_GSL|): 6.1035156250000000e-05
// max(|f - f_GSL| / |f_GSL|): 7.7998476565326393e-16
const testcase_cyl_bessel_k<double>
data008[20] =
{
  { 194481817927839.88, 10.000000000000000, 0.25000000000000000 },
  { 188937569319.90030, 10.000000000000000, 0.50000000000000000 },
  { 3248187687.8018155, 10.000000000000000, 0.75000000000000000 },
  { 180713289.90102941, 10.000000000000000, 1.0000000000000000 },
  { 19104425.945252180, 10.000000000000000, 1.2500000000000000 },
  { 3027483.5236822353, 10.000000000000000, 1.5000000000000000 },
  { 633724.71555087867, 10.000000000000000, 1.7500000000000000 },
  { 162482.40397955943, 10.000000000000000, 2.0000000000000000 },
  { 48602.446087749791, 10.000000000000000, 2.2500000000000000 },
  { 16406.916416341937, 10.000000000000000, 2.5000000000000000 },
  { 6104.1720745909606, 10.000000000000000, 2.7500000000000000 },
  { 2459.6204220569480, 10.000000000000000, 3.0000000000000000 },
  { 1059.2358443703381, 10.000000000000000, 3.2500000000000000 },
  { 482.53582096664758, 10.000000000000000, 3.5000000000000000 },
  { 230.64249314993776, 10.000000000000000, 3.7500000000000000 },
  { 114.91408364049620, 10.000000000000000, 4.0000000000000000 },
  { 59.361613632706479, 10.000000000000000, 4.2500000000000000 },
  { 31.652958759229868, 10.000000000000000, 4.5000000000000000 },
  { 17.357723966417399, 10.000000000000000, 4.7500000000000000 },
  { 9.7585628291778121, 10.000000000000000, 5.0000000000000000 },
};
const double toler008 = 2.5000000000000020e-13;

// Test data for nu=20.000000000000000.
// max(|f - f_GSL|): 2.7670116110564327e+19
// max(|f - f_GSL| / |f_GSL|): 1.2737005853777639e-15
const testcase_cyl_bessel_k<double>
data009[20] =
{
  { 7.0065983661641184e+34, 20.000000000000000, 0.25000000000000000 },
  { 6.6655498744171593e+28, 20.000000000000000, 0.50000000000000000 },
  { 1.9962989615380379e+25, 20.000000000000000, 0.75000000000000000 },
  { 6.2943693604245335e+22, 20.000000000000000, 1.0000000000000000 },
  { 7.2034511920074182e+20, 20.000000000000000, 1.2500000000000000 },
  { 1.8620549984645546e+19, 20.000000000000000, 1.5000000000000000 },
  { 8.4415605303952486e+17, 20.000000000000000, 1.7500000000000000 },
  { 57708568527002520., 20.000000000000000, 2.0000000000000000 },
  { 5396824209986879.0, 20.000000000000000, 2.2500000000000000 },
  { 645996884063683.62, 20.000000000000000, 2.5000000000000000 },
  { 94387401970996.328, 20.000000000000000, 2.7500000000000000 },
  { 16254643952204.371, 20.000000000000000, 3.0000000000000000 },
  { 3212694836166.4053, 20.000000000000000, 3.2500000000000000 },
  { 713857897923.74072, 20.000000000000000, 3.5000000000000000 },
  { 175423421958.35925, 20.000000000000000, 3.7500000000000000 },
  { 47050078926.298080, 20.000000000000000, 4.0000000000000000 },
  { 13625066095.067503, 20.000000000000000, 4.2500000000000000 },
  { 4222179870.6810656, 20.000000000000000, 4.5000000000000000 },
  { 1389634112.7516634, 20.000000000000000, 4.7500000000000000 },
  { 482700052.06214869, 20.000000000000000, 5.0000000000000000 },
};
const double toler009 = 2.5000000000000020e-13;

// Test data for nu=50.000000000000000.
// max(|f - f_GSL|): 3.9111090745622133e+92
// max(|f - f_GSL| / |f_GSL|): 3.7220730535457535e-15
const testcase_cyl_bessel_k<double>
data010[20] =
{
  { 4.3394604622138714e+107, 50.000000000000000, 0.25000000000000000 },
  { 3.8505298918269003e+92, 50.000000000000000, 0.50000000000000000 },
  { 6.0292756894842793e+83, 50.000000000000000, 0.75000000000000000 },
  { 3.4068968541616991e+77, 50.000000000000000, 1.0000000000000000 },
  { 4.8485527365039051e+72, 50.000000000000000, 1.2500000000000000 },
  { 5.3091717574907920e+68, 50.000000000000000, 1.5000000000000000 },
  { 2.3762245257445824e+65, 50.000000000000000, 1.7500000000000000 },
  { 2.9799817396049268e+62, 50.000000000000000, 2.0000000000000000 },
  { 8.2079431233488581e+59, 50.000000000000000, 2.2500000000000000 },
  { 4.2046528212987503e+57, 50.000000000000000, 2.5000000000000000 },
  { 3.5578676911884825e+55, 50.000000000000000, 2.7500000000000000 },
  { 4.5559542293221535e+53, 50.000000000000000, 3.0000000000000000 },
  { 8.2606735967628997e+51, 50.000000000000000, 3.2500000000000000 },
  { 2.0139406747903812e+50, 50.000000000000000, 3.5000000000000000 },
  { 6.3368727837484600e+48, 50.000000000000000, 3.7500000000000000 },
  { 2.4897317389325753e+47, 50.000000000000000, 4.0000000000000000 },
  { 1.1888958173039699e+46, 50.000000000000000, 4.2500000000000000 },
  { 6.7472593648148542e+44, 50.000000000000000, 4.5000000000000000 },
  { 4.4664266585930700e+43, 50.000000000000000, 4.7500000000000000 },
  { 3.3943222434301628e+42, 50.000000000000000, 5.0000000000000000 },
};
const double toler010 = 2.5000000000000020e-13;

// Test data for nu=100.00000000000000.
// max(|f - f_GSL|): 8.5970689361151757e+232
// max(|f - f_GSL| / |f_GSL|): 9.0457919481999128e-14
const testcase_cyl_bessel_k<double>
data011[20] =
{
  { 9.5039428115809898e+245, 100.00000000000000, 0.25000000000000000 },
  { 7.4937399313533112e+215, 100.00000000000000, 0.50000000000000000 },
  { 1.8417471020730701e+198, 100.00000000000000, 0.75000000000000000 },
  { 5.9003331836386410e+185, 100.00000000000000, 1.0000000000000000 },
  { 1.2002130935576950e+176, 100.00000000000000, 1.2500000000000000 },
  { 1.4467044226487075e+168, 100.00000000000000, 1.5000000000000000 },
  { 2.9161498411497642e+161, 100.00000000000000, 1.7500000000000000 },
  { 4.6194159776013925e+155, 100.00000000000000, 2.0000000000000000 },
  { 3.5332121583541727e+150, 100.00000000000000, 2.2500000000000000 },
  { 9.3566097231039940e+145, 100.00000000000000, 2.5000000000000000 },
  { 6.7672283615134532e+141, 100.00000000000000, 2.7500000000000000 },
  { 1.1219630864949494e+138, 100.00000000000000, 3.0000000000000000 },
  { 3.7329723699990903e+134, 100.00000000000000, 3.2500000000000000 },
  { 2.2476893883855163e+131, 100.00000000000000, 3.5000000000000000 },
  { 2.2564559319883196e+128, 100.00000000000000, 3.7500000000000000 },
  { 3.5353340499626455e+125, 100.00000000000000, 4.0000000000000000 },
  { 8.1898439213010234e+122, 100.00000000000000, 4.2500000000000000 },
  { 2.6823744110726800e+120, 100.00000000000000, 4.5000000000000000 },
  { 1.1963963615212274e+118, 100.00000000000000, 4.7500000000000000 },
  { 7.0398601930616815e+115, 100.00000000000000, 5.0000000000000000 },
};
const double toler011 = 5.0000000000000029e-12;
//  cyl_bessel_k

// Test data for nu=0.0000000000000000.
// max(|f - f_GSL|): 4.3368086899420177e-19
// max(|f - f_GSL| / |f_GSL|): 1.8009631353873430e-16
const testcase_cyl_bessel_k<double>
data012[20] =
{
  { 0.0036910983340425947, 0.0000000000000000, 5.0000000000000000 },
  { 1.7780062316167650e-05, 0.0000000000000000, 10.000000000000000 },
  { 9.8195364823964333e-08, 0.0000000000000000, 15.000000000000000 },
  { 5.7412378153365238e-10, 0.0000000000000000, 20.000000000000000 },
  { 3.4641615622131151e-12, 0.0000000000000000, 25.000000000000000 },
  { 2.1324774964630566e-14, 0.0000000000000000, 30.000000000000000 },
  { 1.3310351491429464e-16, 0.0000000000000000, 35.000000000000000 },
  { 8.3928611000995700e-19, 0.0000000000000000, 40.000000000000000 },
  { 5.3334561226187247e-21, 0.0000000000000000, 45.000000000000000 },
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
const double toler012 = 2.5000000000000020e-13;

// Test data for nu=0.33333333333333331.
// max(|f - f_GSL|): 1.0339757656912846e-25
// max(|f - f_GSL| / |f_GSL|): 1.7960859646361972e-16
const testcase_cyl_bessel_k<double>
data013[20] =
{
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
  { 1.0816880942511494e-40, 0.33333333333333331, 90.000000000000000 },
  { 7.0942508599231512e-43, 0.33333333333333331, 95.000000000000000 },
  { 4.6592031570213454e-45, 0.33333333333333331, 100.00000000000000 },
};
const double toler013 = 2.5000000000000020e-13;

// Test data for nu=0.50000000000000000.
// max(|f - f_GSL|): 1.5046327690525280e-36
// max(|f - f_GSL| / |f_GSL|): 0.0000000000000000
const testcase_cyl_bessel_k<double>
data014[20] =
{
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
const double toler014 = 2.5000000000000020e-13;

// Test data for nu=0.66666666666666663.
// max(|f - f_GSL|): 4.3368086899420177e-19
// max(|f - f_GSL| / |f_GSL|): 3.5630695000470094e-16
const testcase_cyl_bessel_k<double>
data015[20] =
{
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
  { 1.0836820479428605e-40, 0.66666666666666663, 90.000000000000000 },
  { 7.1066428916285356e-43, 0.66666666666666663, 95.000000000000000 },
  { 4.6669364587280465e-45, 0.66666666666666663, 100.00000000000000 },
};
const double toler015 = 2.5000000000000020e-13;

// Test data for nu=1.0000000000000000.
// max(|f - f_GSL|): 1.0339757656912846e-25
// max(|f - f_GSL| / |f_GSL|): 2.9112857291682056e-16
const testcase_cyl_bessel_k<double>
data016[20] =
{
  { 0.0040446134454521655, 1.0000000000000000, 5.0000000000000000 },
  { 1.8648773453825582e-05, 1.0000000000000000, 10.000000000000000 },
  { 1.0141729369762091e-07, 1.0000000000000000, 15.000000000000000 },
  { 5.8830579695570384e-10, 1.0000000000000000, 20.000000000000000 },
  { 3.5327780731999345e-12, 1.0000000000000000, 25.000000000000000 },
  { 2.1677320018915498e-14, 1.0000000000000000, 30.000000000000000 },
  { 1.3499178340011053e-16, 1.0000000000000000, 35.000000000000000 },
  { 8.4971319548610435e-19, 1.0000000000000000, 40.000000000000000 },
  { 5.3923945937225035e-21, 1.0000000000000000, 45.000000000000000 },
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
const double toler016 = 2.5000000000000020e-13;

// Test data for nu=2.0000000000000000.
// max(|f - f_GSL|): 8.6736173798840355e-19
// max(|f - f_GSL| / |f_GSL|): 1.6337745981208381e-16
const testcase_cyl_bessel_k<double>
data017[20] =
{
  { 0.0053089437122234608, 2.0000000000000000, 5.0000000000000000 },
  { 2.1509817006932767e-05, 2.0000000000000000, 10.000000000000000 },
  { 1.1171767065031378e-07, 2.0000000000000000, 15.000000000000000 },
  { 6.3295436122922281e-10, 2.0000000000000000, 20.000000000000000 },
  { 3.7467838080691102e-12, 2.0000000000000000, 25.000000000000000 },
  { 2.2769929632558265e-14, 2.0000000000000000, 30.000000000000000 },
  { 1.4081733110858665e-16, 2.0000000000000000, 35.000000000000000 },
  { 8.8177176978426223e-19, 2.0000000000000000, 40.000000000000000 },
  { 5.5731181045619470e-21, 2.0000000000000000, 45.000000000000000 },
  { 3.5479318388581979e-23, 2.0000000000000000, 50.000000000000000 },
  { 2.2717153918665688e-25, 2.0000000000000000, 55.000000000000000 },
  { 1.4614189081096777e-27, 2.0000000000000000, 60.000000000000000 },
  { 9.4383017680150234e-30, 2.0000000000000000, 65.000000000000000 },
  { 6.1157177279757537e-32, 2.0000000000000000, 70.000000000000000 },
  { 3.9740059241667034e-34, 2.0000000000000000, 75.000000000000000 },
  { 2.5886411706935015e-36, 2.0000000000000000, 80.000000000000000 },
  { 1.6898316402103142e-38, 2.0000000000000000, 85.000000000000000 },
  { 1.1051801100484218e-40, 2.0000000000000000, 90.000000000000000 },
  { 7.2401743221736176e-43, 2.0000000000000000, 95.000000000000000 },
  { 4.7502253038886413e-45, 2.0000000000000000, 100.00000000000000 },
};
const double toler017 = 2.5000000000000020e-13;

// Test data for nu=5.0000000000000000.
// max(|f - f_GSL|): 6.9388939039072284e-18
// max(|f - f_GSL| / |f_GSL|): 2.3552470349020973e-16
const testcase_cyl_bessel_k<double>
data018[20] =
{
  { 0.032706273712031865, 5.0000000000000000, 5.0000000000000000 },
  { 5.7541849985312288e-05, 5.0000000000000000, 10.000000000000000 },
  { 2.1878261369258224e-07, 5.0000000000000000, 15.000000000000000 },
  { 1.0538660139974233e-09, 5.0000000000000000, 20.000000000000000 },
  { 5.6485921365284157e-12, 5.0000000000000000, 25.000000000000000 },
  { 3.2103335105890266e-14, 5.0000000000000000, 30.000000000000000 },
  { 1.8919208406439644e-16, 5.0000000000000000, 35.000000000000000 },
  { 1.1423814375953188e-18, 5.0000000000000000, 40.000000000000000 },
  { 7.0181216822204101e-21, 5.0000000000000000, 45.000000000000000 },
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
const double toler018 = 2.5000000000000020e-13;

// Test data for nu=10.000000000000000.
// max(|f - f_GSL|): 5.3290705182007514e-15
// max(|f - f_GSL| / |f_GSL|): 5.4609173619982130e-16
const testcase_cyl_bessel_k<double>
data019[20] =
{
  { 9.7585628291778121, 10.000000000000000, 5.0000000000000000 },
  { 0.0016142553003906700, 10.000000000000000, 10.000000000000000 },
  { 2.2605303776606435e-06, 10.000000000000000, 15.000000000000000 },
  { 6.3162145283215804e-09, 10.000000000000000, 20.000000000000000 },
  { 2.4076769602801233e-11, 10.000000000000000, 25.000000000000000 },
  { 1.0842816942222975e-13, 10.000000000000000, 30.000000000000000 },
  { 5.3976770429777191e-16, 10.000000000000000, 35.000000000000000 },
  { 2.8680293113671932e-18, 10.000000000000000, 40.000000000000000 },
  { 1.5939871900169600e-20, 10.000000000000000, 45.000000000000000 },
  { 9.1509882099879962e-23, 10.000000000000000, 50.000000000000000 },
  { 5.3823846249592858e-25, 10.000000000000000, 55.000000000000000 },
  { 3.2253408700563144e-27, 10.000000000000000, 60.000000000000000 },
  { 1.9613367530075138e-29, 10.000000000000000, 65.000000000000000 },
  { 1.2068471495933484e-31, 10.000000000000000, 70.000000000000000 },
  { 7.4979152649449644e-34, 10.000000000000000, 75.000000000000000 },
  { 4.6957285830490538e-36, 10.000000000000000, 80.000000000000000 },
  { 2.9606323347034079e-38, 10.000000000000000, 85.000000000000000 },
  { 1.8773542561131613e-40, 10.000000000000000, 90.000000000000000 },
  { 1.1962899527846350e-42, 10.000000000000000, 95.000000000000000 },
  { 7.6554279773881018e-45, 10.000000000000000, 100.00000000000000 },
};
const double toler019 = 2.5000000000000020e-13;

// Test data for nu=20.000000000000000.
// max(|f - f_GSL|): 4.1723251342773438e-07
// max(|f - f_GSL| / |f_GSL|): 1.2224656515794909e-15
const testcase_cyl_bessel_k<double>
data020[20] =
{
  { 482700052.06214869, 20.000000000000000, 5.0000000000000000 },
  { 178.74427820770546, 20.000000000000000, 10.000000000000000 },
  { 0.012141257729731143, 20.000000000000000, 15.000000000000000 },
  { 5.5431116361258155e-06, 20.000000000000000, 20.000000000000000 },
  { 6.3744029330352113e-09, 20.000000000000000, 25.000000000000000 },
  { 1.2304516475442478e-11, 20.000000000000000, 30.000000000000000 },
  { 3.2673136479809018e-14, 20.000000000000000, 35.000000000000000 },
  { 1.0703023799997383e-16, 20.000000000000000, 40.000000000000000 },
  { 4.0549953175660457e-19, 20.000000000000000, 45.000000000000000 },
  { 1.7061483797220349e-21, 20.000000000000000, 50.000000000000000 },
  { 7.7617008115659413e-24, 20.000000000000000, 55.000000000000000 },
  { 3.7482954006874720e-26, 20.000000000000000, 60.000000000000000 },
  { 1.8966880763956576e-28, 20.000000000000000, 65.000000000000000 },
  { 9.9615763479998864e-31, 20.000000000000000, 70.000000000000000 },
  { 5.3921623063091066e-33, 20.000000000000000, 75.000000000000000 },
  { 2.9920407657642272e-35, 20.000000000000000, 80.000000000000000 },
  { 1.6948662723618255e-37, 20.000000000000000, 85.000000000000000 },
  { 9.7689149642963042e-40, 20.000000000000000, 90.000000000000000 },
  { 5.7143603019220823e-42, 20.000000000000000, 95.000000000000000 },
  { 3.3852054148901700e-44, 20.000000000000000, 100.00000000000000 },
};
const double toler020 = 2.5000000000000020e-13;

// Test data for nu=50.000000000000000.
// max(|f - f_GSL|): 8.6655802749976619e+27
// max(|f - f_GSL| / |f_GSL|): 2.6684549464729312e-15
const testcase_cyl_bessel_k<double>
data021[20] =
{
  { 3.3943222434301628e+42, 50.000000000000000, 5.0000000000000000 },
  { 2.0613737753892557e+27, 50.000000000000000, 10.000000000000000 },
  { 1.7267736974519188e+18, 50.000000000000000, 15.000000000000000 },
  { 411711209122.01788, 50.000000000000000, 20.000000000000000 },
  { 1972478.7419813874, 50.000000000000000, 25.000000000000000 },
  { 58.770686258007267, 50.000000000000000, 30.000000000000000 },
  { 0.0058659391182535178, 50.000000000000000, 35.000000000000000 },
  { 1.3634854128794101e-06, 50.000000000000000, 40.000000000000000 },
  { 5.8652396362160819e-10, 50.000000000000000, 45.000000000000000 },
  { 4.0060134766400893e-13, 50.000000000000000, 50.000000000000000 },
  { 3.9062324485711016e-16, 50.000000000000000, 55.000000000000000 },
  { 5.0389298085176510e-19, 50.000000000000000, 60.000000000000000 },
  { 8.1305344250110424e-22, 50.000000000000000, 65.000000000000000 },
  { 1.5732816234948991e-24, 50.000000000000000, 70.000000000000000 },
  { 3.5349854993874412e-27, 50.000000000000000, 75.000000000000000 },
  { 8.9940101003189485e-30, 50.000000000000000, 80.000000000000000 },
  { 2.5403205503080723e-32, 50.000000000000000, 85.000000000000000 },
  { 7.8397596486715721e-35, 50.000000000000000, 90.000000000000000 },
  { 2.6098900651329542e-37, 50.000000000000000, 95.000000000000000 },
  { 9.2745226536133258e-40, 50.000000000000000, 100.00000000000000 },
};
const double toler021 = 2.5000000000000020e-13;

// Test data for nu=100.00000000000000.
// max(|f - f_GSL|): 3.4996011596528191e+101
// max(|f - f_GSL| / |f_GSL|): 4.9711230957426436e-15
const testcase_cyl_bessel_k<double>
data022[20] =
{
  { 7.0398601930616815e+115, 100.00000000000000, 5.0000000000000000 },
  { 4.5966740842695238e+85, 100.00000000000000, 10.000000000000000 },
  { 8.2565552242653946e+67, 100.00000000000000, 15.000000000000000 },
  { 1.7081356456876041e+55, 100.00000000000000, 20.000000000000000 },
  { 1.9858028128780610e+45, 100.00000000000000, 25.000000000000000 },
  { 1.2131584253026677e+37, 100.00000000000000, 30.000000000000000 },
  { 1.1016916354696688e+30, 100.00000000000000, 35.000000000000000 },
  { 7.0074023297775712e+23, 100.00000000000000, 40.000000000000000 },
  { 1.9236643958470894e+18, 100.00000000000000, 45.000000000000000 },
  { 16394035276269.250, 100.00000000000000, 50.000000000000000 },
  { 343254952.89495474, 100.00000000000000, 55.000000000000000 },
  { 14870.012754946298, 100.00000000000000, 60.000000000000000 },
  { 1.1708099078572216, 100.00000000000000, 65.000000000000000 },
  { 0.00015161193930722313, 100.00000000000000, 70.000000000000000 },
  { 2.9850234381623443e-08, 100.00000000000000, 75.000000000000000 },
  { 8.3928710724649129e-12, 100.00000000000000, 80.000000000000000 },
  { 3.2033435630927732e-15, 100.00000000000000, 85.000000000000000 },
  { 1.5922281431788096e-18, 100.00000000000000, 90.000000000000000 },
  { 9.9589454577674131e-22, 100.00000000000000, 95.000000000000000 },
  { 7.6171296304940840e-25, 100.00000000000000, 100.00000000000000 },
};
const double toler022 = 2.5000000000000020e-13;

template<typename Tp, unsigned int Num>
  void
  test(const testcase_cyl_bessel_k<Tp> (&data)[Num], Tp toler)
  {
    const Tp eps = std::numeric_limits<Tp>::epsilon();
    Tp max_abs_diff = -Tp(1);
    Tp max_abs_frac = -Tp(1);
    unsigned int num_datum = Num;
    for (unsigned int i = 0; i < num_datum; ++i)
      {
	const Tp f = std::cyl_bessel_k(data[i].nu, data[i].x);
	const Tp f0 = data[i].f0;
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
  test(data021, toler021);
  test(data022, toler022);
  return 0;
}
