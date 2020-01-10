// Core algorithmic facilities -*- C++ -*-

// Copyright (C) 2019 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file bits/ranges_algo.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{algorithm}
 */

#ifndef _RANGES_ALGO_H
#define _RANGES_ALGO_H 1

#if __cplusplus > 201703L

#include <compare>
#include <iterator>
// #include <bits/range_concepts.h>
#include <ranges>
#include <bits/invoke.h>
#include <bits/cpp_type_traits.h> // __is_byte

#if __cpp_lib_concepts
namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION
namespace ranges
{
  template<input_iterator _Iter, sentinel_for<_Iter> _Sent,
	   typename _Proj = identity,
	   indirect_unary_predicate<projected<_Iter, _Proj>> _Pred>
    constexpr bool
    all_of(_Iter __first, _Sent __last, _Pred __pred, _Proj __proj = {})
    {
      for (; __first != __last; ++__first)
	if (!std::__invoke(__pred, std::__invoke(__proj, *__first)))
	  return false;
      return true;
    }

  template<input_range _Range, typename _Proj = identity,
	   indirect_unary_predicate<projected<iterator_t<_Range>, _Proj>> _Pred>
    constexpr bool
    all_of(_Range&& __r, _Pred __pred, _Proj __proj = {})
    {
      return ranges::all_of(ranges::begin(__r), ranges::end(__r),
			    std::move(__pred), std::move(__proj));
    }

  template<input_iterator _Iter, sentinel_for<_Iter> _Sent,
	   typename _Proj = identity,
	   indirect_unary_predicate<projected<_Iter, _Proj>> _Pred>
    constexpr bool
    any_of(_Iter __first, _Sent __last, _Pred __pred, _Proj __proj = {})
    {
      for (; __first != __last; ++__first)
	if (std::__invoke(__pred, std::__invoke(__proj, *__first)))
	  return true;
      return false;
    }

  template<input_range _Range, typename _Proj = identity,
	   indirect_unary_predicate<projected<iterator_t<_Range>, _Proj>> _Pred>
    constexpr bool
    any_of(_Range&& __r, _Pred __pred, _Proj __proj = {})
    {
      return ranges::any_of(ranges::begin(__r), ranges::end(__r),
			    std::move(__pred), std::move(__proj));
    }

  template<input_iterator _Iter, sentinel_for<_Iter> _Sent,
	   typename _Proj = identity,
	   indirect_unary_predicate<projected<_Iter, _Proj>> _Pred>
    constexpr bool
    none_of(_Iter __first, _Sent __last, _Pred __pred, _Proj __proj = {})
    {
      for (; __first != __last; ++__first)
	if (std::__invoke(__pred, std::__invoke(__proj, *__first)))
	  return false;
      return true;
    }

  template<input_range _Range, typename _Proj = identity,
	   indirect_unary_predicate<projected<iterator_t<_Range>, _Proj>> _Pred>
    constexpr bool
    none_of(_Range&& __r, _Pred __pred, _Proj __proj = {})
    {
      return ranges::none_of(ranges::begin(__r), ranges::end(__r),
			    std::move(__pred), std::move(__proj));
    }

  template<typename _Iter, typename _F>
    struct for_each_result
    {
      [[no_unique_address]] _Iter in;
      [[no_unique_address]] _F fun;

      template<typename _Iter2, typename _F2>
	requires convertible_to<const _Iter&, _Iter2>
	  && convertible_to<const _F&, _F2>
	operator for_each_result<_Iter2, _F2>() const &
	{
	  return {in, fun};
	}

      template<typename _Iter2, typename _F2>
	requires convertible_to<_Iter, _Iter2> && convertible_to<_F, _F2>
	operator for_each_result<_Iter2, _F2>() &&
	{
	  return {std::move(in), std::move(fun)};
	}
    };

  template<input_iterator _Iter, sentinel_for<_Iter> _Sent,
	   typename _Proj = identity,
	   indirectly_unary_invocable<projected<_Iter, _Proj>> _Fun>
    constexpr for_each_result<_Iter, _Fun>
    for_each(_Iter __first, _Sent __last, _Fun __f, _Proj __proj = {})
    {
      for (; __first != __last; ++__first)
	std::__invoke(__f, std::__invoke(__proj, *__first));
      return { __last, std::move(__f) };
    }

  template<input_range _Range, typename _Proj = identity,
	   indirectly_unary_invocable<projected<iterator_t<_Range>, _Proj>>
	     _Fun>
    constexpr for_each_result<safe_iterator_t<_Range>, _Fun>
    for_each(_Range&& __r, _Fun __f, _Proj __proj = {})
    {
      return ranges::for_each(ranges::begin(__r), ranges::end(__r),
			      std::move(__f), std::move(__proj));
    }

  template<input_iterator _Iter, sentinel_for<_Iter> _Sent, typename _Tp,
	   typename _Proj = identity>
    requires indirect_binary_predicate<ranges::equal_to,
				       projected<_Iter, _Proj>, const _Tp*>
    constexpr _Iter
    find(_Iter __first, _Sent __last, const _Tp& __value, _Proj __proj = {})
    {
      while (__first != __last
	  && !(std::__invoke(__proj, *__first) == __value))
	++__first;
      return __first;
    }

  template<input_range _Range, typename _Tp, typename _Proj = identity>
    requires indirect_binary_predicate<ranges::equal_to,
				       projected<iterator_t<_Range>, _Proj>,
				       const _Tp*>
    constexpr safe_iterator_t<_Range>
    find(_Range&& __r, const _Tp& __value, _Proj __proj = {})
    {
      return ranges::find(ranges::begin(__r), ranges::end(__r), __value,
			  std::move(__proj));
    }

  template<input_iterator _Iter, sentinel_for<_Iter> _Sent,
	   typename _Proj = identity,
	   indirect_unary_predicate<projected<_Iter, _Proj>> _Pred>
    constexpr _Iter
    find_if(_Iter __first, _Sent __last, _Pred __pred, _Proj __proj = {})
    {
      while (__first != __last
	  && !(bool)std::__invoke(__pred, std::__invoke(__proj, *__first)))
	++__first;
      return __first;
    }

  template<input_range _Range, typename _Proj = identity,
	   indirect_unary_predicate<projected<iterator_t<_Range>, _Proj>>
	     _Pred>
    constexpr safe_iterator_t<_Range>
    find_if(_Range&& __r, _Pred __pred, _Proj __proj = {})
    {
      return ranges::find_if(ranges::begin(__r), ranges::end(__r),
			     std::move(__pred), std::move(__proj));
    }

  template<input_iterator _Iter, sentinel_for<_Iter> _Sent,
	   typename _Proj = identity,
	   indirect_unary_predicate<projected<_Iter, _Proj>> _Pred>
    constexpr _Iter
    find_if_not(_Iter __first, _Sent __last, _Pred __pred, _Proj __proj = {})
    {
      while (__first != __last
	  && (bool)std::__invoke(__pred, std::__invoke(__proj, *__first)))
	++__first;
      return __first;
    }

  template<input_range _Range, typename _Proj = identity,
	   indirect_unary_predicate<projected<iterator_t<_Range>, _Proj>>
	     _Pred>
    constexpr safe_iterator_t<_Range>
    find_if_not(_Range&& __r, _Pred __pred, _Proj __proj = {})
    {
      return ranges::find_if_not(ranges::begin(__r), ranges::end(__r),
				 std::move(__pred), std::move(__proj));
    }

} // namespace ranges
_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std
#endif // concepts
#endif // C++20
#endif // _RANGES_ALGO_H

