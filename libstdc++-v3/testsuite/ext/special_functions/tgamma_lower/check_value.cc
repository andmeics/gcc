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

//  tgamma_lower
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


// Test data for a=0.50000000000000000.
// max(|f - f_Boost|): 8.8817841970012523e-16 at index 4
// max(|f - f_Boost| / |f_Boost|): 5.2498811028723779e-16
// mean(f - f_Boost): 4.4408920985006262e-16
// variance(f - f_Boost): 0.0000000000000000
// stddev(f - f_Boost): 2.4865981221422578e-257
const testcase_tgamma_lower<double>
data001[11] =
{
  { 0.0000000000000000, 0.50000000000000000, 0.0000000000000000, 0.0 },
  { 1.2100356193111088, 0.50000000000000000, 0.50000000000000000, 0.0 },
  { 1.4936482656248540, 0.50000000000000000, 1.0000000000000000, 0.0 },
  { 1.6248713377014197, 0.50000000000000000, 1.5000000000000000, 0.0 },
  { 1.6918067329451982, 0.50000000000000000, 2.0000000000000000, 0.0 },
  { 1.7275268983055081, 0.50000000000000000, 2.5000000000000000, 0.0 },
  { 1.7470973415820525, 0.50000000000000000, 3.0000000000000000, 0.0 },
  { 1.7580066299159907, 0.50000000000000000, 3.5000000000000000, 0.0 },
  { 1.7641627815248433, 0.50000000000000000, 4.0000000000000000, 0.0 },
  { 1.7676685869765310, 0.50000000000000000, 4.5000000000000000, 0.0 },
  { 1.7696792476451033, 0.50000000000000000, 5.0000000000000000, 0.0 },
};
const double toler001 = 2.5000000000000020e-13;

// Test data for a=1.0000000000000000.
// max(|f - f_Boost|): 1.0658141036401503e-14 at index 4
// max(|f - f_Boost| / |f_Boost|): 1.2326328147512544e-14
// mean(f - f_Boost): 6.7824533868009566e-15
// variance(f - f_Boost): 1.6523050232992830e-30
// stddev(f - f_Boost): 1.2854201738339425e-15
const testcase_tgamma_lower<double>
data002[11] =
{
  { 0.0000000000000000, 1.0000000000000000, 0.0000000000000000, 0.0 },
  { 0.39346934028736658, 1.0000000000000000, 0.50000000000000000, 0.0 },
  { 0.63212055882855767, 1.0000000000000000, 1.0000000000000000, 0.0 },
  { 0.77686983985157021, 1.0000000000000000, 1.5000000000000000, 0.0 },
  { 0.86466471676338730, 1.0000000000000000, 2.0000000000000000, 0.0 },
  { 0.91791500137610116, 1.0000000000000000, 2.5000000000000000, 0.0 },
  { 0.95021293163213605, 1.0000000000000000, 3.0000000000000000, 0.0 },
  { 0.96980261657768152, 1.0000000000000000, 3.5000000000000000, 0.0 },
  { 0.98168436111126578, 1.0000000000000000, 4.0000000000000000, 0.0 },
  { 0.98889100346175773, 1.0000000000000000, 4.5000000000000000, 0.0 },
  { 0.99326205300091452, 1.0000000000000000, 5.0000000000000000, 0.0 },
};
const double toler002 = 1.0000000000000008e-12;

// Test data for a=1.5000000000000000.
// max(|f - f_Boost|): 4.4408920985006262e-16 at index 8
// max(|f - f_Boost| / |f_Boost|): 5.2526956118340025e-16
// mean(f - f_Boost): 1.8419609272190098e-16
// variance(f - f_Boost): 2.4378771405134429e-33
// stddev(f - f_Boost): 4.9374863448048569e-17
const testcase_tgamma_lower<double>
data003[11] =
{
  { 0.0000000000000000, 1.5000000000000000, 0.0000000000000000, 0.0 },
  { 0.17613586717520105, 1.5000000000000000, 0.50000000000000000, 0.0 },
  { 0.37894469164098471, 1.5000000000000000, 1.0000000000000000, 0.0 },
  { 0.53915814955613639, 1.5000000000000000, 1.5000000000000000, 0.0 },
  { 0.65451037345177732, 1.5000000000000000, 2.0000000000000000, 0.0 },
  { 0.73397567046110035, 1.5000000000000000, 2.5000000000000000, 0.0 },
  { 0.78731493881798065, 1.5000000000000000, 3.0000000000000000, 0.0 },
  { 0.82250918358631386, 1.5000000000000000, 3.5000000000000000, 0.0 },
  { 0.84545011298495332, 1.5000000000000000, 4.0000000000000000, 0.0 },
  { 0.86026855313515838, 1.5000000000000000, 4.5000000000000000, 0.0 },
  { 0.86977311630380583, 1.5000000000000000, 5.0000000000000000, 0.0 },
};
const double toler003 = 2.5000000000000020e-13;

// Test data for a=2.0000000000000000.
// max(|f - f_Boost|): 1.0769163338864018e-14 at index 6
// max(|f - f_Boost| / |f_Boost|): 1.3447137568829578e-14
// mean(f - f_Boost): 4.8294701571194310e-15
// variance(f - f_Boost): 3.7370744640889924e-30
// stddev(f - f_Boost): 1.9331514333049525e-15
const testcase_tgamma_lower<double>
data004[11] =
{
  { 0.0000000000000000, 2.0000000000000000, 0.0000000000000000, 0.0 },
  { 0.090204010431049864, 2.0000000000000000, 0.50000000000000000, 0.0 },
  { 0.26424111765711533, 2.0000000000000000, 1.0000000000000000, 0.0 },
  { 0.44217459962892541, 2.0000000000000000, 1.5000000000000000, 0.0 },
  { 0.59399415029016189, 2.0000000000000000, 2.0000000000000000, 0.0 },
  { 0.71270250481635422, 2.0000000000000000, 2.5000000000000000, 0.0 },
  { 0.80085172652854419, 2.0000000000000000, 3.0000000000000000, 0.0 },
  { 0.86411177459956678, 2.0000000000000000, 3.5000000000000000, 0.0 },
  { 0.90842180555632912, 2.0000000000000000, 4.0000000000000000, 0.0 },
  { 0.93890051903966731, 2.0000000000000000, 4.5000000000000000, 0.0 },
  { 0.95957231800548715, 2.0000000000000000, 5.0000000000000000, 0.0 },
};
const double toler004 = 1.0000000000000008e-12;

// Test data for a=2.5000000000000000.
// max(|f - f_Boost|): 6.6613381477509392e-16 at index 6
// max(|f - f_Boost| / |f_Boost|): 7.2227540650239113e-16
// mean(f - f_Boost): 1.2742332441720546e-16
// variance(f - f_Boost): 3.1922989166380029e-32
// stddev(f - f_Boost): 1.7867005671454864e-16
const testcase_tgamma_lower<double>
data005[11] =
{
  { 0.0000000000000000, 2.5000000000000000, 0.0000000000000000, 0.0 },
  { 0.049762829522624882, 2.5000000000000000, 0.50000000000000000, 0.0 },
  { 0.20053759629003473, 2.5000000000000000, 1.0000000000000000, 0.0 },
  { 0.39882094539234464, 2.5000000000000000, 1.5000000000000000, 0.0 },
  { 0.59897957413602232, 2.5000000000000000, 2.0000000000000000, 0.0 },
  { 0.77649405896251644, 2.5000000000000000, 2.5000000000000000, 0.0 },
  { 0.92227121230783404, 2.5000000000000000, 3.0000000000000000, 0.0 },
  { 1.0360343155785856, 2.5000000000000000, 3.5000000000000000, 0.0 },
  { 1.1216500583675566, 2.5000000000000000, 4.0000000000000000, 0.0 },
  { 1.1843569981137558, 2.5000000000000000, 4.5000000000000000, 0.0 },
  { 1.2293271368619796, 2.5000000000000000, 5.0000000000000000, 0.0 },
};
const double toler005 = 2.5000000000000020e-13;

// Test data for a=3.0000000000000000.
// max(|f - f_Boost|): 2.1316282072803006e-14 at index 8
// max(|f - f_Boost| / |f_Boost|): 1.3988958232907167e-14
// mean(f - f_Boost): 5.7148099384043216e-15
// variance(f - f_Boost): 2.6774652603646051e-29
// stddev(f - f_Boost): 5.1744229246985649e-15
const testcase_tgamma_lower<double>
data006[11] =
{
  { 0.0000000000000000, 3.0000000000000000, 0.0000000000000000, 0.0 },
  { 0.028775355933941375, 3.0000000000000000, 0.50000000000000000, 0.0 },
  { 0.16060279414278839, 3.0000000000000000, 1.0000000000000000, 0.0 },
  { 0.38230633892388372, 3.0000000000000000, 1.5000000000000000, 0.0 },
  { 0.64664716763387309, 3.0000000000000000, 2.0000000000000000, 0.0 },
  { 0.91237376823334093, 3.0000000000000000, 2.5000000000000000, 0.0 },
  { 1.1536198377463129, 3.0000000000000000, 3.0000000000000000, 0.0 },
  { 1.3583056022757318, 3.0000000000000000, 3.5000000000000000, 0.0 },
  { 1.5237933888929114, 3.0000000000000000, 4.0000000000000000, 0.0 },
  { 1.6528438581799278, 3.0000000000000000, 4.5000000000000000, 0.0 },
  { 1.7506959610338377, 3.0000000000000000, 5.0000000000000000, 0.0 },
};
const double toler006 = 1.0000000000000008e-12;

// Test data for a=3.5000000000000000.
// max(|f - f_Boost|): 1.3322676295501878e-15 at index 8
// max(|f - f_Boost| / |f_Boost|): 6.0065500111950081e-16
// mean(f - f_Boost): 4.5418214643756407e-17
// variance(f - f_Boost): 1.7483241866066530e-32
// stddev(f - f_Boost): 1.3222421058968939e-16
const testcase_tgamma_lower<double>
data007[11] =
{
  { 0.0000000000000000, 3.5000000000000000, 0.0000000000000000, 0.0 },
  { 0.017186588186473853, 3.5000000000000000, 0.50000000000000000, 0.0 },
  { 0.13346454955364451, 3.5000000000000000, 1.0000000000000000, 0.0 },
  { 0.38217794506807151, 3.5000000000000000, 1.5000000000000000, 0.0 },
  { 0.73187696325676832, 3.5000000000000000, 2.0000000000000000, 0.0 },
  { 1.1300615305834556, 3.5000000000000000, 2.5000000000000000, 0.0 },
  { 1.5295744430121743, 3.5000000000000000, 3.0000000000000000, 0.0 },
  { 1.8980326796433657, 3.5000000000000000, 3.5000000000000000, 0.0 },
  { 2.2180247014793975, 3.5000000000000000, 4.0000000000000000, 0.0 },
  { 2.4836862531339721, 3.5000000000000000, 4.5000000000000000, 0.0 },
  { 2.6966551541863035, 3.5000000000000000, 5.0000000000000000, 0.0 },
};
const double toler007 = 2.5000000000000020e-13;

// Test data for a=4.0000000000000000.
// max(|f - f_Boost|): 6.3948846218409017e-14 at index 10
// max(|f - f_Boost| / |f_Boost|): 1.4501383461314364e-14
// mean(f - f_Boost): 5.9447396500383383e-15
// variance(f - f_Boost): 3.7009240166743927e-28
// stddev(f - f_Boost): 1.9237785778707467e-14
const testcase_tgamma_lower<double>
data008[11] =
{
  { 0.0000000000000000, 4.0000000000000000, 0.0000000000000000, 0.0 },
  { 0.010509735337744942, 4.0000000000000000, 0.50000000000000000, 0.0 },
  { 0.11392894125692285, 4.0000000000000000, 1.0000000000000000, 0.0 },
  { 0.39385472627070056, 4.0000000000000000, 1.5000000000000000, 0.0 },
  { 0.85725923700871776, 4.0000000000000000, 2.0000000000000000, 0.0 },
  { 1.4545432012016042, 4.0000000000000000, 2.5000000000000000, 0.0 },
  { 2.1166086673066125, 4.0000000000000000, 3.0000000000000000, 0.0 },
  { 2.7802039925952897, 4.0000000000000000, 3.5000000000000000, 0.0 },
  { 3.3991792777997465, 4.0000000000000000, 4.0000000000000000, 0.0 },
  { 3.9462242649924537, 4.0000000000000000, 4.5000000000000000, 0.0 },
  { 4.4098445082158300, 4.0000000000000000, 5.0000000000000000, 0.0 },
};
const double toler008 = 1.0000000000000008e-12;

// Test data for a=4.5000000000000000.
// max(|f - f_Boost|): 6.2172489379008766e-15 at index 10
// max(|f - f_Boost| / |f_Boost|): 9.2169047953130274e-16
// mean(f - f_Boost): -3.5687992964868312e-16
// variance(f - f_Boost): 3.7778317404171079e-30
// stddev(f - f_Boost): 1.9436645133399713e-15
const testcase_tgamma_lower<double>
data009[11] =
{
  { 0.0000000000000000, 4.5000000000000000, 0.0000000000000000, 0.0 },
  { 0.0065428158426143086, 4.5000000000000000, 0.50000000000000000, 0.0 },
  { 0.099246482266313482, 4.5000000000000000, 1.0000000000000000, 0.0 },
  { 0.41531118011906520, 4.5000000000000000, 1.5000000000000000, 0.0 },
  { 1.0304254272321143, 4.5000000000000000, 2.0000000000000000, 0.0 },
  { 1.9272813149850065, 4.5000000000000000, 2.5000000000000000, 0.0 },
  { 3.0251997872703771, 4.5000000000000000, 3.0000000000000000, 0.0 },
  { 4.2209284961909361, 4.5000000000000000, 3.5000000000000000, 0.0 },
  { 5.4186846774199164, 4.5000000000000000, 4.0000000000000000, 0.0 },
  { 6.5454737962920220, 4.5000000000000000, 4.5000000000000000, 0.0 },
  { 7.5549795998088349, 4.5000000000000000, 5.0000000000000000, 0.0 },
};
const double toler009 = 2.5000000000000020e-13;

// Test data for a=5.0000000000000000.
// max(|f - f_Boost|): 1.4210854715202004e-14 at index 9
// max(|f - f_Boost| / |f_Boost|): 1.2654914989069235e-15
// mean(f - f_Boost): 9.8784616850170186e-16
// variance(f - f_Boost): 4.3893780069413889e-30
// stddev(f - f_Boost): 2.0950842481727052e-15
const testcase_tgamma_lower<double>
data010[11] =
{
  { 0.0000000000000000, 5.0000000000000000, 0.0000000000000000, 0.0 },
  { 0.0041307751189401786, 5.0000000000000000, 0.50000000000000000, 0.0 },
  { 0.087836323856249093, 5.0000000000000000, 1.0000000000000000, 0.0 },
  { 0.44582246933137620, 5.0000000000000000, 1.5000000000000000, 0.0 },
  { 1.2636724162490678, 5.0000000000000000, 2.0000000000000000, 0.0 },
  { 2.6117275460603704, 5.0000000000000000, 2.5000000000000000, 0.0 },
  { 4.4336821314294701, 5.0000000000000000, 3.0000000000000000, 0.0 },
  { 6.5893211205694895, 5.0000000000000000, 3.5000000000000000, 0.0 },
  { 8.9079135556830362, 5.0000000000000000, 4.0000000000000000, 0.0 },
  { 11.229514167006828, 5.0000000000000000, 4.5000000000000000, 0.0 },
  { 13.428161158434902, 5.0000000000000000, 5.0000000000000000, 0.0 },
};
const double toler010 = 2.5000000000000020e-13;

template<typename Ret, unsigned int Num>
  void
  test(const testcase_tgamma_lower<Ret> (&data)[Num], Ret toler)
  {
    bool test __attribute__((unused)) = true;
    const Ret eps = std::numeric_limits<Ret>::epsilon();
    Ret max_abs_diff = -Ret(1);
    Ret max_abs_frac = -Ret(1);
    unsigned int num_datum = Num;
    for (unsigned int i = 0; i < num_datum; ++i)
      {
	const Ret f = __gnu_cxx::tgamma_lower(data[i].a, data[i].x);
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
  return 0;
}
