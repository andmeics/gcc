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

//  ellnome

//  Compare against values generated by Equator V4.1.
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
const testcase_ellnome<double>
data001[101] =
{
  {0.00000000000000e+00, 0.00000000000000e+00, 0.0},
  {6.25031252050933e-06, 1.00000000000000e-02, 0.0},
  {2.50050013128876e-05, 2.00000000000000e-02, 0.0},
  {5.62753274601336e-05, 3.00000000000000e-02, 0.0},
  {1.00080084099325e-04, 4.00000000000000e-02, 0.0},
  {1.56445633527016e-04, 5.00000000000000e-02, 0.0},
  {2.25405959362125e-04, 6.00000000000000e-02, 0.0},
  {3.07002733983498e-04, 7.00000000000000e-02, 0.0},
  {4.01285401524022e-04, 8.00000000000000e-02, 0.0},
  {5.08311276769908e-04, 9.00000000000000e-02, 0.0},
  {6.28145660383016e-04, 1.00000000000000e-01, 0.0},
  {7.60861970936401e-04, 1.10000000000000e-01, 0.0},
  {9.06541894329195e-04, 1.20000000000000e-01, 0.0},
  {1.06527555122704e-03, 1.30000000000000e-01, 0.0},
  {1.23716168325927e-03, 1.40000000000000e-01, 0.0},
  {1.42230785879466e-03, 1.50000000000000e-01, 0.0},
  {1.62083069921429e-03, 1.60000000000000e-01, 0.0},
  {1.83285612670420e-03, 1.70000000000000e-01, 0.0},
  {2.05851963470279e-03, 1.80000000000000e-01, 0.0},
  {2.29796658225894e-03, 1.90000000000000e-01, 0.0},
  {2.55135251368867e-03, 2.00000000000000e-01, 0.0},
  {2.81884350506122e-03, 2.10000000000000e-01, 0.0},
  {3.10061653920168e-03, 2.20000000000000e-01, 0.0},
  {3.39685991106767e-03, 2.30000000000000e-01, 0.0},
  {3.70777366554573e-03, 2.40000000000000e-01, 0.0},
  {4.03357006991752e-03, 2.50000000000000e-01, 0.0},
  {4.37447412347288e-03, 2.60000000000000e-01, 0.0},
  {4.73072410699764e-03, 2.70000000000000e-01, 0.0},
  {5.10257217513694e-03, 2.80000000000000e-01, 0.0},
  {5.49028499494539e-03, 2.90000000000000e-01, 0.0},
  {5.89414443426904e-03, 3.00000000000000e-01, 0.0},
  {6.31444830398655e-03, 3.10000000000000e-01, 0.0},
  {6.75151115855157e-03, 3.20000000000000e-01, 0.0},
  {7.20566515975274e-03, 3.30000000000000e-01, 0.0},
  {7.67726100912401e-03, 3.40000000000000e-01, 0.0},
  {8.16666895503199e-03, 3.50000000000000e-01, 0.0},
  {8.67427988111769e-03, 3.60000000000000e-01, 0.0},
  {9.20050648351377e-03, 3.70000000000000e-01, 0.0},
  {9.74578454508908e-03, 3.80000000000000e-01, 0.0},
  {1.03105743159102e-02, 3.90000000000000e-01, 0.0},
  {1.08953620101726e-02, 4.00000000000000e-01, 0.0},
  {1.15006614310552e-02, 4.10000000000000e-01, 0.0},
  {1.21270157363179e-02, 4.20000000000000e-01, 0.0},
  {1.27749993590111e-02, 4.30000000000000e-01, 0.0},
  {1.34452200994400e-02, 4.40000000000000e-01, 0.0},
  {1.41383214065439e-02, 4.50000000000000e-01, 0.0},
  {1.48549848691661e-02, 4.60000000000000e-01, 0.0},
  {1.55959329403522e-02, 4.70000000000000e-01, 0.0},
  {1.63619319208646e-02, 4.80000000000000e-01, 0.0},
  {1.71537952316370e-02, 4.90000000000000e-01, 0.0},
  {1.79723870089672e-02, 5.00000000000000e-01, 0.0},
  {1.88186260609847e-02, 5.10000000000000e-01, 0.0},
  {1.96934902294317e-02, 5.20000000000000e-01, 0.0},
  {2.05980212072246e-02, 5.30000000000000e-01, 0.0},
  {2.15333298697754e-02, 5.40000000000000e-01, 0.0},
  {2.25006021868827e-02, 5.50000000000000e-01, 0.0},
  {2.35011057923909e-02, 5.60000000000000e-01, 0.0},
  {2.45361973011128e-02, 5.70000000000000e-01, 0.0},
  {2.56073304770739e-02, 5.80000000000000e-01, 0.0},
  {2.67160653745022e-02, 5.90000000000000e-01, 0.0},
  {2.78640785937288e-02, 6.00000000000000e-01, 0.0},
  {2.90531748190690e-02, 6.10000000000000e-01, 0.0},
  {3.02852998357781e-02, 6.20000000000000e-01, 0.0},
  {3.15625552595314e-02, 6.30000000000000e-01, 0.0},
  {3.28872152561226e-02, 6.40000000000000e-01, 0.0},
  {3.42617455831721e-02, 6.50000000000000e-01, 0.0},
  {3.56888253521474e-02, 6.60000000000000e-01, 0.0},
  {3.71713719912133e-02, 6.70000000000000e-01, 0.0},
  {3.87125699916553e-02, 6.80000000000000e-01, 0.0},
  {4.03159041485195e-02, 6.90000000000000e-01, 0.0},
  {4.19851981671834e-02, 7.00000000000000e-01, 0.0},
  {4.37246597118200e-02, 7.10000000000000e-01, 0.0},
  {4.55389332326563e-02, 7.20000000000000e-01, 0.0},
  {4.74331622448942e-02, 7.30000000000000e-01, 0.0},
  {4.94130631683910e-02, 7.40000000000000e-01, 0.0},
  {5.14850134086884e-02, 7.50000000000000e-01, 0.0},
  {5.36561571159104e-02, 7.60000000000000e-01, 0.0},
  {5.59345330682945e-02, 7.70000000000000e-01, 0.0},
  {5.83292304923470e-02, 7.80000000000000e-01, 0.0},
  {6.08505804987984e-02, 7.90000000000000e-01, 0.0},
  {6.35103934007458e-02, 8.00000000000000e-01, 0.0},
  {6.63222558163278e-02, 8.10000000000000e-01, 0.0},
  {6.93019066477622e-02, 8.20000000000000e-01, 0.0},
  {7.24677185620000e-02, 8.30000000000000e-01, 0.0},
  {7.58413227405007e-02, 8.40000000000000e-01, 0.0},
  {7.94484314899747e-02, 8.50000000000000e-01, 0.0},
  {8.33199393021230e-02, 8.60000000000000e-01, 0.0},
  {8.74934241695202e-02, 8.70000000000000e-01, 0.0},
  {9.20152382557009e-02, 8.80000000000000e-01, 0.0},
  {9.69434905817386e-02, 8.90000000000000e-01, 0.0},
  {1.02352423513544e-01, 9.00000000000000e-01, 0.0},
  {1.08339049838803e-01, 9.10000000000000e-01, 0.0},
  {1.15033622306760e-01, 9.20000000000000e-01, 0.0},
  {1.22616957879768e-01, 9.30000000000000e-01, 0.0},
  {1.31350861076012e-01, 9.40000000000000e-01, 0.0},
  {1.41635776642689e-01, 9.50000000000000e-01, 0.0},
  {1.54131700155765e-01, 9.60000000000000e-01, 0.0},
  {1.70050727445056e-01, 9.70000000000000e-01, 0.0},
  {1.92039857764661e-01, 9.80000000000000e-01, 0.0},
  {2.28190210130364e-01, 9.90000000000000e-01, 0.0},
  {1.00000000000000e+00, 1.00000000000000e+00, 0.0},
};
const double toler001 = 2.5000000000000020e-13;

template<typename Tp, unsigned int Num>
  void
  test(const testcase_ellnome<Tp> (&data)[Num], Tp toler)
  {
    bool test __attribute__((unused)) = true;
    const Tp eps = std::numeric_limits<Tp>::epsilon();
    Tp max_abs_diff = -Tp(1);
    Tp max_abs_frac = -Tp(1);
    unsigned int num_datum = Num;
    for (unsigned int i = 0; i < num_datum; ++i)
      {
	const Tp f = __gnu_cxx::ellnome(data[i].k);
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
  return 0;
}
