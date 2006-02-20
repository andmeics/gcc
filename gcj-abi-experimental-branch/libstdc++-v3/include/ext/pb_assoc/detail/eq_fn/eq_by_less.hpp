// -*- C++ -*-

// Copyright (C) 2005 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

// Copyright (C) 2004 Ami Tavory and Vladimir Dreizin, IBM-HRL.

// Permission to use, copy, modify, sell, and distribute this software
// is hereby granted without fee, provided that the above copyright
// notice appears in all copies, and that both that copyright notice and
// this permission notice appear in supporting documentation. None of
// the above authors, nor IBM Haifa Research Laboratories, make any
// representation about the suitability of this software for any
// purpose. It is provided "as is" without express or implied warranty.

/**
 * @file eq_by_less.hpp
 * Contains an equivalence function.
 */

#ifndef EQ_BY_LESS_HPP
#define EQ_BY_LESS_HPP

#include <utility>
#include <functional>
#include <vector>
#include <assert.h>
#include <ext/pb_assoc/detail/types_traits.hpp>

namespace pb_assoc
{

  namespace detail
  {

#include <functional>

    template<typename Key, class Cmp_Fn>
    struct eq_by_less : public std::binary_function<const Key& , const Key& , bool>,
			protected Cmp_Fn
    {
      bool
      operator()(const Key& r_lhs, const Key& r_rhs) const
      {
	return (!(Cmp_Fn::operator()(r_lhs, r_rhs)&& 
		  !(Cmp_Fn::operator()(r_rhs, r_lhs))));
      }
    };

  } // namespace detail

} // namespace pb_assoc

#endif // #ifndef EQ_BY_LESS_HPP
