// <experimental/bits/erase_if.h> -*- C++ -*-

// Copyright (C) 2015-2017 Free Software Foundation, Inc.
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

/** @file experimental/bits/erase_if.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly.
 */

#ifndef _GLIBCXX_EXPERIMENTAL_ERASE_IF_H
#define _GLIBCXX_EXPERIMENTAL_ERASE_IF_H 1

#pragma GCC system_header

#if __cplusplus >= 201402L
#include <experimental/bits/lfts_config.h>

namespace std
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

namespace experimental
{
inline namespace fundamentals_v2
{
  namespace __detail
  {
    template<typename _Container, typename _Predicate>
      void
      __erase_nodes_if(_Container& __cont, _Predicate __pred)
      {
	for (auto __iter = __cont.begin(), __last = __cont.end();
	     __iter != __last;)
	{
	  if (__pred(*__iter))
	    __iter = __cont.erase(__iter);
	  else
	    ++__iter;
	}
      }
  } // namespace __detail
} // inline namespace fundamentals_v2
} // namespace experimental

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std

#endif // C++14

#endif // _GLIBCXX_EXPERIMENTAL_ERASE_IF_H
