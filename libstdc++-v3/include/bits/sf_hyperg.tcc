// Special functions -*- C++ -*-

// Copyright (C) 2006-2017 Free Software Foundation, Inc.
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
// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file bits/sf_hyperg.tcc
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{cmath}
 */

//
// ISO C++ 14882 TR29124: Mathematical Special Functions
//

// Written by Edward Smith-Rowland.
//
// References:
// (1) Handbook of Mathematical Functions,
//     ed. Milton Abramowitz and Irene A. Stegun,
//     Dover Publications,
//     Section 6, pp. 555-566
// (2) The Gnu Scientific Library, http://www.gnu.org/software/gsl

#ifndef _GLIBCXX_BITS_SF_HYPERG_TCC
#define _GLIBCXX_BITS_SF_HYPERG_TCC 1

#pragma GCC system_header

#include <ext/math_const.h>

namespace std _GLIBCXX_VISIBILITY(default)
{
// Implementation-space details.
namespace __detail
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  /**
   * @brief This routine returns the confluent hypergeometric limit function
   * 	    by series expansion.
   *
   * @f[
   *   {}_0F_1(-;c;x) = \Gamma(c)
   * 		\sum_{n=0}^{\infty} \frac{1}{\Gamma(c+n)} \frac{x^n}{n!}
   * @f]
   *
   * If a and b are integers and a < 0 and either b > 0 or b < a
   * then the series is a polynomial with a finite number of
   * terms.
   *
   * @param  __c  The "denominator" parameter.
   * @param  __x  The argument of the confluent hypergeometric limit function.
   * @return  The confluent hypergeometric limit function.
   */
  template<typename _Tp>
    _Tp
    __conf_hyperg_lim_series(_Tp __c, _Tp __x)
    {
      const auto __eps = __gnu_cxx::__epsilon(__x);

      auto __term = _Tp{1};
      auto __Fac = _Tp{1};
      const unsigned int __max_iter = 100000;
      unsigned int __i;
      for (__i = 0; __i < __max_iter; ++__i)
	{
	  __term *= __x / ((__c + _Tp(__i)) * _Tp(1 + __i));
	  __Fac += __term;
	  if (std::abs(__term) < __eps)
	    break;
	}
      if (__i == __max_iter)
	std::__throw_runtime_error(__N("__conf_hyperg_lim_series: "
				       "series failed to converge"));

      return __Fac;
    }


  /**
   * @brief  Return the confluent hypergeometric limit function
   *	     @f$ {}_0F_1(-;c;x) @f$.
   *
   * @param  __c  The @a denominator parameter.
   * @param  __x  The argument of the confluent hypergeometric limit function.
   * @return  The confluent limit hypergeometric function.
   */
  template<typename _Tp>
    _Tp
    __conf_hyperg_lim(_Tp __c, _Tp __x)
    {
      const _Tp __c_nint = std::nearbyint(__c);
      if (__isnan(__c) || __isnan(__x))
	return __gnu_cxx::__quiet_NaN(__x);
      else if (__c_nint == __c && __c_nint <= 0)
	return __gnu_cxx::__infinity(__x);
      //else if (__x < _Tp{0})
	//return __conf_hyperg_lim_luke(__c, __x);
      else
	return __conf_hyperg_lim_series(__c, __x);
    }


  /**
   * @brief This routine returns the confluent hypergeometric function
   * 	    by series expansion.
   *
   * @f[
   *   {}_1F_1(a;c;x) = \frac{\Gamma(c)}{\Gamma(a)}
   * 			\sum_{n=0}^{\infty}
   * 			\frac{\Gamma(a+n)}{\Gamma(c+n)}
   * 			\frac{x^n}{n!}
   * @f]
   *
   * @param  __a  The "numerator" parameter.
   * @param  __c  The "denominator" parameter.
   * @param  __x  The argument of the confluent hypergeometric function.
   * @return  The confluent hypergeometric function.
   */
  template<typename _Tp>
    _Tp
    __conf_hyperg_series(_Tp __a, _Tp __c, _Tp __x)
    {
      const auto __eps = __gnu_cxx::__epsilon(__x);

      _Tp __term = _Tp{1};
      _Tp __Fac = _Tp{1};
      const unsigned int __max_iter = 100000;
      unsigned int __i;
      for (__i = 0; __i < __max_iter; ++__i)
	{
	  __term *= (__a + _Tp(__i)) * __x
		  / ((__c + _Tp(__i)) * _Tp(1 + __i));
	  __Fac += __term;
	  if (std::abs(__term) < __eps)
	    break;
	}
      if (__i == __max_iter)
	std::__throw_runtime_error(__N("__conf_hyperg_series: "
				       "series failed to converge"));

      return __Fac;
    }


  /**
   * @brief  Return the hypergeometric function @f$ {}_1F_1(a;c;x) @f$
   *	     by an iterative procedure described in
   *	     Luke, Algorithms for the Computation of Mathematical Functions.
   *
   * Like the case of the 2F1 rational approximations, these are
   * probably guaranteed to converge for x < 0, barring gross
   * numerical instability in the pre-asymptotic regime.
   */
  template<typename _Tp>
    _Tp
    __conf_hyperg_luke(_Tp __a, _Tp __c, _Tp __xin)
    {
      const _Tp __big = __gnu_cxx::__root_max(_Tp{6});
      const int __nmax = 20000;
      const _Tp __eps = __gnu_cxx::__epsilon(__xin);
      const _Tp __x  = -__xin;
      const _Tp __x3 = __x * __x * __x;
      const _Tp __t0 = __a / __c;
      const _Tp __t1 = (__a + _Tp{1}) / (_Tp{2} * __c);
      const _Tp __t2 = (__a + _Tp{2}) / (_Tp{2} * (__c + _Tp{1}));
      _Tp __F = _Tp{1};
      _Tp __prec;

      _Tp __Bnm3 = _Tp{1};
      _Tp __Bnm2 = _Tp{1} + __t1 * __x;
      _Tp __Bnm1 = _Tp{1} + __t2 * __x * (_Tp{1} + __t1 / _Tp{3} * __x);

      _Tp __Anm3 = _Tp{1};
      _Tp __Anm2 = __Bnm2 - __t0 * __x;
      _Tp __Anm1 = __Bnm1 - __t0 * (_Tp{1} + __t2 * __x) * __x
		 + __t0 * __t1 * (__c / (__c + _Tp{1})) * __x * __x;

      int __n = 3;
      while(true)
	{
	  _Tp __npam1 = _Tp(__n - 1) + __a;
	  _Tp __npcm1 = _Tp(__n - 1) + __c;
	  _Tp __npam2 = _Tp(__n - 2) + __a;
	  _Tp __npcm2 = _Tp(__n - 2) + __c;
	  _Tp __tnm1  = _Tp(2 * __n - 1);
	  _Tp __tnm3  = _Tp(2 * __n - 3);
	  _Tp __tnm5  = _Tp(2 * __n - 5);
	  _Tp __F1 =  (_Tp(__n - 2) - __a) / (_Tp{2} * __tnm3 * __npcm1);
	  _Tp __F2 =  (_Tp(__n) + __a) * __npam1
		   / (_Tp{4} * __tnm1 * __tnm3 * __npcm2 * __npcm1);
	  _Tp __F3 = -__npam2 * __npam1 * (_Tp(__n - 2) - __a)
		   / (_Tp{8} * __tnm3 * __tnm3 * __tnm5
		   * (_Tp(__n - 3) + __c) * __npcm2 * __npcm1);
	  _Tp __E  = -__npam1 * (_Tp(__n - 1) - __c)
		   / (_Tp{2} * __tnm3 * __npcm2 * __npcm1);

	  _Tp __An = (_Tp{1} + __F1 * __x) * __Anm1
		   + (__E + __F2 * __x) * __x * __Anm2 + __F3 * __x3 * __Anm3;
	  _Tp __Bn = (_Tp{1} + __F1 * __x) * __Bnm1
		   + (__E + __F2 * __x) * __x * __Bnm2 + __F3 * __x3 * __Bnm3;
	  _Tp __r = __An / __Bn;

	  __prec = std::abs((__F - __r) / __F);
	  __F = __r;

	  if (__prec < __eps || __n > __nmax)
	    break;

	  if (std::abs(__An) > __big || std::abs(__Bn) > __big)
	    {
	      __An   /= __big;
	      __Bn   /= __big;
	      __Anm1 /= __big;
	      __Bnm1 /= __big;
	      __Anm2 /= __big;
	      __Bnm2 /= __big;
	      __Anm3 /= __big;
	      __Bnm3 /= __big;
	    }
	  else if (std::abs(__An) < _Tp{1} / __big
		|| std::abs(__Bn) < _Tp{1} / __big)
	    {
	      __An   *= __big;
	      __Bn   *= __big;
	      __Anm1 *= __big;
	      __Bnm1 *= __big;
	      __Anm2 *= __big;
	      __Bnm2 *= __big;
	      __Anm3 *= __big;
	      __Bnm3 *= __big;
	    }

	  ++__n;
	  __Bnm3 = __Bnm2;
	  __Bnm2 = __Bnm1;
	  __Bnm1 = __Bn;
	  __Anm3 = __Anm2;
	  __Anm2 = __Anm1;
	  __Anm1 = __An;
	}

      if (__n >= __nmax)
	std::__throw_runtime_error(__N("__conf_hyperg_luke: "
				       "iteration failed to converge"));

      return __F;
    }


  /**
   * @brief  Return the confluent hypergeometric function
   * 	     @f$ {}_1F_1(a;c;x) = M(a,c,x) @f$.
   *
   * @param  __a  The @a numerator parameter.
   * @param  __c  The @a denominator parameter.
   * @param  __x  The argument of the confluent hypergeometric function.
   * @return  The confluent hypergeometric function.
   */
  template<typename _Tp>
    _Tp
    __conf_hyperg(_Tp __a, _Tp __c, _Tp __x)
    {
      const _Tp __c_nint = std::nearbyint(__c);
      if (__isnan(__a) || __isnan(__c) || __isnan(__x))
	return __gnu_cxx::__quiet_NaN(__x);
      else if (__c_nint == __c && __c_nint <= 0)
	return __gnu_cxx::__infinity(__x);
      else if (__a == _Tp{0})
	return _Tp{1};
      else if (__c == __a)
	return std::exp(__x);
      else if (__x < _Tp{0})
	return __conf_hyperg_luke(__a, __c, __x);
      else
	return __conf_hyperg_series(__a, __c, __x);
    }


  /**
   * @brief  Return the Tricomi confluent hypergeometric function
   * @f[
   *   U(a,c,x) = \frac{\Gamma(1-c)}{\Gamma(a-c+1)} {}_1F_1(a;c;x)
   *       + \frac{\Gamma(c-1)}{\Gamma(a)} x^{1-c} {}_1F_1(a-c+1;2-c;x)
   * @f]
   * @param  __a  The @a numerator parameter.
   * @param  __c  The @a denominator parameter.
   * @param  __x  The argument of the confluent hypergeometric function.
   * @return  The Tricomi confluent hypergeometric function.
   */
  template<typename _Tp>
    _Tp
    __tricomi_u_naive(_Tp __a, _Tp __c, _Tp __x)
    {
      auto __U1 = _Tp{};
      auto __b = __a - __c + _Tp{1};
      auto __ib = __gnu_cxx::__fp_is_integer(__b);
      if (!__ib || (__ib && __ib() > 0))
	__U1 = std::tgamma(_Tp{1} - __c)
	       * __conf_hyperg(__a, __c, __x)
	       / std::tgamma(__b);

      auto __U2 = _Tp{};
      auto __ia = __gnu_cxx::__fp_is_integer(__a);
      if (!__ia || (__ia && __ia() > 0))
	__U2 = std::tgamma(__c - _Tp{1})
	       * std::pow(__x, _Tp{1} - __c)
	       * __conf_hyperg(__b, _Tp{2} - __c, __x)
	       / std::tgamma(__a);

      return __U1 + __U2;
    }

  /**
   * @brief  Return the Tricomi confluent hypergeometric function
   * @f[
   *   U(a,c,x) = \frac{\Gamma(1-c)}{\Gamma(a-c+1)} {}_1F_1(a;c;x)
   *       + \frac{\Gamma(c-1)}{\Gamma(a)} x^{1-c} {}_1F_1(a-c+1;2-c;x)
   * @f]
   * @param  __a  The @a numerator parameter.
   * @param  __c  The @a denominator parameter.
   * @param  __x  The argument of the confluent hypergeometric function.
   * @return  The Tricomi confluent hypergeometric function.
   */
  template<typename _Tp>
    _Tp
    __tricomi_u(_Tp __a, _Tp __c, _Tp __x)
    {
      return __tricomi_u_naive(__a, __c, __x);
    }


  /**
   * @brief Return the hypergeometric function @f$ {}_2F_1(a,b;c;x) @f$
   * by series expansion.
   *
   * The hypergeometric function is defined by
   * @f[
   *   {}_2F_1(a,b;c;x) = \frac{\Gamma(c)}{\Gamma(a)\Gamma(b)}
   * 			\sum_{n=0}^{\infty}
   * 			\frac{\Gamma(a+n)\Gamma(b+n)}{\Gamma(c+n)}
   * 			\frac{x^n}{n!}
   * @f]
   *
   * This works and it's pretty fast.
   *
   * @param  __a  The first @a numerator parameter.
   * @param  __b  The second @a numerator parameter.
   * @param  __c  The @a denominator parameter.
   * @param  __x  The argument of the confluent hypergeometric function.
   * @return  The confluent hypergeometric function.
   */
  template<typename _Tp>
    _Tp
    __hyperg_series(_Tp __a, _Tp __b, _Tp __c, _Tp __x)
    {
      const auto __eps = __gnu_cxx::__epsilon(__x);

      auto __term = _Tp{1};
      auto __Fabc = _Tp{1};
      const unsigned int __max_iter = 100000;
      unsigned int __i;
      for (__i = 0u; __i < __max_iter; ++__i)
	{
	  __term *= (__a + _Tp(__i)) * (__b + _Tp(__i)) * __x
		  / ((__c + _Tp(__i)) * _Tp(1 + __i));
	  __Fabc += __term;
	  if (std::abs(__term) < __eps)
	    break;
	}
      if (__i == __max_iter)
	std::__throw_runtime_error(__N("Series failed to converge "
				       "in __hyperg_series."));

      return __Fabc;
    }


  /**
   * @brief  Return the hypergeometric function @f$ {}_2F_1(a,b;c;x) @f$
   * 	     by an iterative procedure described in
   * 	     Luke, Algorithms for the Computation of Mathematical Functions.
   */
  template<typename _Tp>
    _Tp
    __hyperg_luke(_Tp __a, _Tp __b, _Tp __c, _Tp __xin)
    {
      const auto __big = __gnu_cxx::__root_max(_Tp{6});
      const int __nmax = 20000;
      const auto __eps = __gnu_cxx::__epsilon(__xin);
      const auto __x  = -__xin;
      const auto __x3 = __x * __x * __x;
      const auto __t0 = __a * __b / __c;
      const auto __t1 = (__a + _Tp{1}) * (__b + _Tp{1}) / (_Tp{2} * __c);
      const auto __t2 = (__a + _Tp{2}) * (__b + _Tp{2})
		     / (_Tp{2} * (__c + _Tp{1}));

      auto __F = _Tp{1};

      auto __Bnm3 = _Tp{1};
      auto __Bnm2 = _Tp{1} + __t1 * __x;
      auto __Bnm1 = _Tp{1} + __t2 * __x * (_Tp{1} + __t1 / _Tp{3} * __x);

      auto __Anm3 = _Tp{1};
      auto __Anm2 = __Bnm2 - __t0 * __x;
      auto __Anm1 = __Bnm1 - __t0 * (_Tp{1} + __t2 * __x) * __x
		  + __t0 * __t1 * (__c / (__c + _Tp{1})) * __x * __x;

      int __n = 3;
      while (true)
	{
	  const auto __npam1 = _Tp(__n - 1) + __a;
	  const auto __npbm1 = _Tp(__n - 1) + __b;
	  const auto __npcm1 = _Tp(__n - 1) + __c;
	  const auto __npam2 = _Tp(__n - 2) + __a;
	  const auto __npbm2 = _Tp(__n - 2) + __b;
	  const auto __npcm2 = _Tp(__n - 2) + __c;
	  const auto __tnm1  = _Tp(2 * __n - 1);
	  const auto __tnm3  = _Tp(2 * __n - 3);
	  const auto __tnm5  = _Tp(2 * __n - 5);
	  const auto __n2 = __n * __n;
	  const auto __F1 = (_Tp{3} * __n2 + (__a + __b - _Tp{6}) * __n
			  + _Tp{2} - __a * __b - _Tp{2} * (__a + __b))
			  / (_Tp{2} * __tnm3 * __npcm1);
	  const auto __F2 = -(_Tp{3} * __n2 - (__a + __b + _Tp{6}) * __n
			  + _Tp{2} - __a * __b) * __npam1 * __npbm1
			  / (_Tp{4} * __tnm1 * __tnm3 * __npcm2 * __npcm1);
	  const auto __F3 = (__npam2 * __npam1 * __npbm2 * __npbm1
			  * (_Tp(__n - 2) - __a) * (_Tp(__n - 2) - __b))
			  / (_Tp{8} * __tnm3 * __tnm3 * __tnm5
			  * (_Tp(__n - 3) + __c) * __npcm2 * __npcm1);
	  const auto __E  = -__npam1 * __npbm1 * (_Tp(__n - 1) - __c)
			  / (_Tp{2} * __tnm3 * __npcm2 * __npcm1);

	  auto __An = (_Tp{1} + __F1 * __x) * __Anm1
		    + (__E + __F2 * __x) * __x * __Anm2 + __F3 * __x3 * __Anm3;
	  auto __Bn = (_Tp{1} + __F1 * __x) * __Bnm1
		    + (__E + __F2 * __x) * __x * __Bnm2 + __F3 * __x3 * __Bnm3;
	  const auto __r = __An / __Bn;

	  const auto __prec = std::abs((__F - __r) / __F);
	  __F = __r;

	  if (__prec < __eps || __n > __nmax)
	    break;

	  if (std::abs(__An) > __big || std::abs(__Bn) > __big)
	    {
	      __An   /= __big;
	      __Bn   /= __big;
	      __Anm1 /= __big;
	      __Bnm1 /= __big;
	      __Anm2 /= __big;
	      __Bnm2 /= __big;
	      __Anm3 /= __big;
	      __Bnm3 /= __big;
	    }
	  else if (std::abs(__An) < _Tp{1} / __big
		|| std::abs(__Bn) < _Tp{1} / __big)
	    {
	      __An   *= __big;
	      __Bn   *= __big;
	      __Anm1 *= __big;
	      __Bnm1 *= __big;
	      __Anm2 *= __big;
	      __Bnm2 *= __big;
	      __Anm3 *= __big;
	      __Bnm3 *= __big;
	    }

	  ++__n;
	  __Bnm3 = __Bnm2;
	  __Bnm2 = __Bnm1;
	  __Bnm1 = __Bn;
	  __Anm3 = __Anm2;
	  __Anm2 = __Anm1;
	  __Anm1 = __An;
	}

      if (__n >= __nmax)
	std::__throw_runtime_error(__N("__hyperg_luke: "
				       "iteration failed to converge"));

      return __F;
    }


  /**
   * @brief  Return the hypergeometric function @f$ {}_2F_1(a,b;c;x) @f$
   * by the reflection formulae in Abramowitz & Stegun formula
   * 15.3.6 for d = c - a - b not integral and formula 15.3.11 for
   * d = c - a - b integral.  This assumes a, b, c != negative
   * integer.
   *
   * The hypergeometric function is defined by
   * @f[
   *   {}_2F_1(a,b;c;x) = \frac{\Gamma(c)}{\Gamma(a)\Gamma(b)}
   *    		\sum_{n=0}^{\infty}
   *    		\frac{\Gamma(a+n)\Gamma(b+n)}{\Gamma(c+n)}
   *    		\frac{x^n}{n!}
   * @f]
   *
   * The reflection formula for nonintegral @f$ d = c - a - b @f$ is:
   * @f[
   *   {}_2F_1(a,b;c;x) = \frac{\Gamma(c)\Gamma(d)}{\Gamma(c-a)\Gamma(c-b)}
   *    		      {}_2F_1(a,b;1-d;1-x)
   *    	      + \frac{\Gamma(c)\Gamma(-d)}{\Gamma(a)\Gamma(b)}
   *    		      {}_2F_1(c-a,c-b;1+d;1-x)
   * @f]
   *
   * The reflection formula for integral @f$ m = c - a - b @f$ is:
   * @f[
   *   {}_2F_1(a,b;a+b+m;x)
   *        = \frac{\Gamma(m)\Gamma(a+b+m)}{\Gamma(a+m)\Gamma(b+m)}
   *          \sum_{k=0}^{m-1} \frac{(m+a)_k(m+b)_k}{k!(1-m)_k} (1 - x)^k
   *    		 + (-1)^m 
   * @f]
   */
  template<typename _Tp>
    _Tp
    __hyperg_reflect(_Tp __a, _Tp __b, _Tp __c, _Tp __x)
    {
      const auto _S_log_max = __gnu_cxx::__log_max(__x);
      const auto __d = __c - __a - __b;
      const int __intd  = std::floor(__d + _Tp{0.5L});
      const auto __eps = __gnu_cxx::__epsilon(__x);
      const auto __toler = _Tp{1000} * __eps;
      const bool __d_integer = (std::abs(__d - __intd) < __toler);

      if (__d_integer)
	{
	  const auto __ln_omx = std::log1p(-__x);
	  const auto __ad = std::abs(__d);
	  _Tp __F1, __F2;

	  _Tp __d1, __d2;
	  if (__d >= _Tp{0})
	    {
	      __d1 = __d;
	      __d2 = _Tp{0};
	    }
	  else
	    {
	      __d1 = _Tp{0};
	      __d2 = __d;
	    }

	  const _Tp __lng_c = __log_gamma(__c);

	  // Evaluate F1.
	  if (__ad < __eps)
	    {
	      // d = c - a - b = 0.
	      __F1 = _Tp{0};
	    }
	  else
	    {

	      bool __ok_d1 = true;
	      _Tp __lng_ad, __lng_ad1, __lng_bd1;
	      __try
		{
		  __lng_ad = __log_gamma(__ad);
		  __lng_ad1 = __log_gamma(__a + __d1);
		  __lng_bd1 = __log_gamma(__b + __d1);
		}
	      __catch(...)
		{
		  __ok_d1 = false;
		}

	      if (__ok_d1)
		{
		  /* Gamma functions in the denominator are ok.
		   * Proceed with evaluation.
		   */
		  auto __sum1 = _Tp{1};
		  auto __term = _Tp{1};
		  auto __ln_pre1 = __lng_ad + __lng_c + __d2 * __ln_omx
				 - __lng_ad1 - __lng_bd1;

		  /* Do F1 sum.
		   */
		  for (int __i = 1; __i < __ad; ++__i)
		    {
		      const int __j = __i - 1;
		      __term *= (__a + __d2 + __j) * (__b + __d2 + __j)
			      / (_Tp{1} + __d2 + __j) / __i * (_Tp{1} - __x);
		      __sum1 += __term;
		    }

		  if (__ln_pre1 > _S_log_max)
		    std::__throw_runtime_error(__N("__hyperg_reflect: "
						   "overflow of gamma functions"));
		  else
		    __F1 = std::exp(__ln_pre1) * __sum1;
		}
	      else
		{
		  // Gamma functions in the denominator were not ok.
		  // So the F1 term is zero.
		  __F1 = _Tp{0};
		}
	    } // end F1 evaluation

	  // Evaluate F2.
	  bool __ok_d2 = true;
	  _Tp __lng_ad2, __lng_bd2;
	  __try
	    {
	      __lng_ad2 = __log_gamma(__a + __d2);
	      __lng_bd2 = __log_gamma(__b + __d2);
	    }
	  __catch(...)
	    {
	      __ok_d2 = false;
	    }

	  if (__ok_d2)
	    {
	      // Gamma functions in the denominator are ok.
	      // Proceed with evaluation.
	      const int __maxiter = 2000;
	      const auto __psi_1 = -__gnu_cxx::__const_gamma_e(__x);
	      const auto __psi_1pd = __psi(_Tp{1} + __ad);
	      const auto __psi_apd1 = __psi(__a + __d1);
	      const auto __psi_bpd1 = __psi(__b + __d1);

	      auto __psi_term = __psi_1 + __psi_1pd - __psi_apd1
			      - __psi_bpd1 - __ln_omx;
	      auto __fact = _Tp{1};
	      auto __sum2 = __psi_term;
	      auto __ln_pre2 = __lng_c + __d1 * __ln_omx
			     - __lng_ad2 - __lng_bd2;

	      // Do F2 sum.
	      int __j;
	      for (__j = 1; __j < __maxiter; ++__j)
		{
		  // Values for psi functions use recurrence;
		  // Abramowitz & Stegun 6.3.5
		  const auto __term1 = _Tp{1} / _Tp{__j}
				     + _Tp{1} / (__ad + __j);
		  const auto __term2 = _Tp{1} / (__a + __d1 + _Tp{__j - 1})
				     + _Tp{1} / (__b + __d1 + _Tp{__j - 1});
		  __psi_term += __term1 - __term2;
		  __fact *= (__a + __d1 + _Tp(__j - 1))
			  * (__b + __d1 + _Tp(__j - 1))
			  / ((__ad + __j) * __j) * (_Tp{1} - __x);
		  const auto __delta = __fact * __psi_term;
		  __sum2 += __delta;
		  if (std::abs(__delta) < __eps * std::abs(__sum2))
		    break;
		}
	      if (__j == __maxiter)
		std::__throw_runtime_error(__N("__hyperg_reflect: "
					       "sum F2 failed to converge"));

	      if (__sum2 == _Tp{0})
		__F2 = _Tp{0};
	      else
		__F2 = std::exp(__ln_pre2) * __sum2;
	    }
	  else
	    {
	      // Gamma functions in the denominator not ok.
	      // So the F2 term is zero.
	      __F2 = _Tp{0};
	    } // end F2 evaluation

	  const auto __sgn_2 = (__intd % 2 == 1 ? -_Tp{1} : _Tp{1});
	  const auto __F = __F1 + __sgn_2 * __F2;

	  return __F;
	}
      else // d = c - a - b not an integer.
	{
	  // These gamma functions appear in the denominator, so we
	  // catch their harmless domain errors and set the terms to zero.
	  bool __ok1 = true;
	  auto __sgn_g1ca = _Tp{0}, __ln_g1ca = _Tp{0};
	  auto __sgn_g1cb = _Tp{0}, __ln_g1cb = _Tp{0};
	  __try
	    {
	      __sgn_g1ca = __log_gamma_sign(__c - __a);
	      __ln_g1ca = __log_gamma(__c - __a);
	      __sgn_g1cb = __log_gamma_sign(__c - __b);
	      __ln_g1cb = __log_gamma(__c - __b);
	    }
	  __catch(...)
	    {
	      __ok1 = false;
	    }

	  bool __ok2 = true;
	  auto __sgn_g2a = _Tp{0}, __ln_g2a = _Tp{0};
	  auto __sgn_g2b = _Tp{0}, __ln_g2b = _Tp{0};
	  __try
	    {
	      __sgn_g2a = __log_gamma_sign(__a);
	      __ln_g2a = __log_gamma(__a);
	      __sgn_g2b = __log_gamma_sign(__b);
	      __ln_g2b = __log_gamma(__b);
	    }
	  __catch(...)
	    {
	      __ok2 = false;
	    }

	  const auto __sgn_gc = __log_gamma_sign(__c);
	  const auto __ln_gc = __log_gamma(__c);
	  const auto __sgn_gd = __log_gamma_sign(__d);
	  const auto __ln_gd = __log_gamma(__d);
	  const auto __sgn_gmd = __log_gamma_sign(-__d);
	  const auto __ln_gmd = __log_gamma(-__d);

	  const auto __sgn1 = __sgn_gc * __sgn_gd  * __sgn_g1ca * __sgn_g1cb;
	  const auto __sgn2 = __sgn_gc * __sgn_gmd * __sgn_g2a  * __sgn_g2b;

	  _Tp __pre1, __pre2;
	  if (__ok1 && __ok2)
	    {
	      auto __ln_pre1 = __ln_gc + __ln_gd  - __ln_g1ca - __ln_g1cb;
	      auto __ln_pre2 = __ln_gc + __ln_gmd - __ln_g2a  - __ln_g2b
			    + __d * std::log(_Tp{1} - __x);
	      if (__ln_pre1 < _S_log_max && __ln_pre2 < _S_log_max)
		{
		  __pre1 = __sgn1 * std::exp(__ln_pre1);
		  __pre2 = __sgn2 * std::exp(__ln_pre2);
		}
	      else
		std::__throw_runtime_error(__N("__hyperg_reflect: "
					       "overflow of gamma functions"));
	    }
	  else if (__ok1 && !__ok2)
	    {
	      auto __ln_pre1 = __ln_gc + __ln_gd - __ln_g1ca - __ln_g1cb;
	      if (__ln_pre1 < _S_log_max)
		{
		  __pre1 = __sgn1 * std::exp(__ln_pre1);
		  __pre2 = _Tp{0};
		}
	      else
		std::__throw_runtime_error(__N("__hyperg_reflect: "
					       "overflow of gamma functions"));
	    }
	  else if (!__ok1 && __ok2)
	    {
	      auto __ln_pre2 = __ln_gc + __ln_gmd - __ln_g2a - __ln_g2b
			     + __d * std::log(_Tp{1} - __x);
	      if (__ln_pre2 < _S_log_max)
		{
		  __pre1 = _Tp{0};
		  __pre2 = __sgn2 * std::exp(__ln_pre2);
		}
	      else
		std::__throw_runtime_error(__N("__hyperg_reflect: "
					       "overflow of gamma functions"));
	    }
	  else
	    std::__throw_runtime_error(__N("__hyperg_reflect: "
					   "underflow of gamma functions"));

	  const auto __F1 = __hyperg_series(__a, __b, _Tp{1} - __d,
					    _Tp{1} - __x);
	  const auto __F2 = __hyperg_series(__c - __a, __c - __b, _Tp{1} + __d,
					    _Tp{1} - __x);

	  const auto __F = __pre1 * __F1 + __pre2 * __F2;

	  return __F;
	}
    }


  /**
   * @brief Return the hypergeometric function @f$ {}_2F_1(a,b;c;x) @f$.
   *
   * The hypergeometric function is defined by
   * @f[
   *   {}_2F_1(a,b;c;x) = \frac{\Gamma(c)}{\Gamma(a)\Gamma(b)}
   * 			\sum_{n=0}^{\infty}
   * 			\frac{\Gamma(a+n)\Gamma(b+n)}{\Gamma(c+n)}
   * 			\frac{x^n}{n!}
   * @f]
   *
   * @param  __a  The first @a numerator parameter.
   * @param  __b  The second @a numerator parameter.
   * @param  __c  The @a denominator parameter.
   * @param  __x  The argument of the confluent hypergeometric function.
   * @return  The confluent hypergeometric function.
   */
  template<typename _Tp>
    _Tp
    __hyperg(_Tp __a, _Tp __b, _Tp __c, _Tp __x)
    {
      const auto _S_log_max = __gnu_cxx::__log_max(__x);
      const _Tp __a_nint = std::nearbyint(__a);
      const _Tp __b_nint = std::nearbyint(__b);
      const _Tp __c_nint = std::nearbyint(__c);
      const _Tp __toler = _Tp{1000} * __gnu_cxx::__epsilon(__x);
      const bool __c_neg_integer
		  = (__c < _Tp{0} && std::abs(__c - __c_nint) < __toler );
      if (std::abs(__x - _Tp{1}) < __toler && __c - __b - __a > _Tp{0}
       && __c != _Tp{0} && !__c_neg_integer)
	{
	  const auto __log_gamc = __log_gamma(__c);
	  const auto __sign_gamc = __log_gamma_sign(__c);
	  const auto __log_gamcab = __log_gamma(__c - __a - __b);
	  const auto __log_gamca = __log_gamma(__c - __a);
	  const auto __sign_gamca = __log_gamma_sign(__c - __a);
	  const auto __log_gamcb = __log_gamma(__c - __b);
	  const auto __sign_gamcb = __log_gamma_sign(__c - __b);
	  const auto __log_pre = __log_gamc + __log_gamcab
			       - __log_gamca - __log_gamcb;
	  const auto __sign = __sign_gamc * __sign_gamca * __sign_gamcb;
	  if (__sign == _Tp{0})
	    return __gnu_cxx::__quiet_NaN(__x);
	  if (__log_pre < _S_log_max)
	    return __sign * std::exp(__log_pre);
	  else
	    std::__throw_domain_error(__N("__hyperg: "
					  "overflow of gamma functions"));
	}
      else if (std::abs(__x) >= _Tp{1})
	std::__throw_domain_error(__N("__hyperg: "
				      "argument outside unit circle"));
      else if (__isnan(__a) || __isnan(__b)
	    || __isnan(__c) || __isnan(__x))
	return __gnu_cxx::__quiet_NaN(__x);
      else if (__c_nint == __c && __c_nint <= _Tp{0})
	return __gnu_cxx::__infinity(__x);
      else if (std::abs(__c - __b) < __toler || std::abs(__c - __a) < __toler)
	return std::pow(_Tp{1} - __x, __c - __a - __b);
      else if (__a >= _Tp{0} && __b >= _Tp{0} && __c >= _Tp{0}
	    && __x >= _Tp{0} && __x < _Tp{0.995L})
	return __hyperg_series(__a, __b, __c, __x);
      else if (std::abs(__a) < _Tp{10} && std::abs(__b) < _Tp{10})
	{
	  // For integer a and b the hypergeometric function is a
	  // finite polynomial.
	  if (__a < _Tp{0}  &&  std::abs(__a - __a_nint) < __toler)
	    return __hyperg_series(__a_nint, __b, __c, __x);
	  else if (__b < _Tp{0}  &&  std::abs(__b - __b_nint) < __toler)
	    return __hyperg_series(__a, __b_nint, __c, __x);
	  else if (__x < -_Tp{0.25L})
	    return __hyperg_luke(__a, __b, __c, __x);
	  else if (__x < _Tp{0.5L})
	    return __hyperg_series(__a, __b, __c, __x);
	  else if (std::abs(__c) > _Tp{10})
	    return __hyperg_series(__a, __b, __c, __x);
	  else
	    return __hyperg_reflect(__a, __b, __c, __x);
	}
      else
	return __hyperg_luke(__a, __b, __c, __x);
    }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace __detail
} // namespace std

#endif // _GLIBCXX_BITS_SF_HYPERG_TCC
