// -*- C++ -*-

// Copyright (C) 2005, 2006 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the terms
// of the GNU General Public License as published by the Free Software
// Foundation; either version 2, or (at your option) any later
// version.

// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this library; see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330, Boston,
// MA 02111-1307, USA.

// As a special exception, you may use this file as part of a free
// software library without restriction.  Specifically, if other files
// instantiate templates or use macros or inline functions from this
// file, or you compile this file and link it with other files to
// produce an executable, this file does not by itself cause the
// resulting executable to be covered by the GNU General Public
// License.  This exception does not however invalidate any other
// reasons why the executable file might be covered by the GNU General
// Public License.

// Copyright (C) 2004 Ami Tavory and Vladimir Dreizin, IBM-HRL.

// Permission to use, copy, modify, sell, and distribute this software
// is hereby granted without fee, provided that the above copyright
// notice appears in all copies, and that both that copyright notice
// and this permission notice appear in supporting documentation. None
// of the above authors, nor IBM Haifa Research Laboratories, make any
// representation about the suitability of this software for any
// purpose. It is provided "as is" without express or implied
// warranty.

/**
 * @file types_traits.hpp
 * Contains a traits class of types used by containers.
 */

#ifndef PB_DS_TYPES_TRAITS_HPP
#define PB_DS_TYPES_TRAITS_HPP

#include <ext/pb_ds/detail/basic_types.hpp>
#include <ext/pb_ds/detail/type_utils.hpp>
#include <utility>

namespace pb_ds
{
  namespace detail
  {

    template<typename Key,
	     typename Mapped,
	     class Allocator,
	     bool Store_Extra>
    struct vt_base_selector
    {
      typedef value_type_base< Key, Mapped, Allocator, Store_Extra> type;
    };

    template<typename Key,
	     typename Mapped,
	     class Allocator,
	     bool Store_Extra>
    struct types_traits : public vt_base_selector<
      Key,
      Mapped,
      Allocator,
      Store_Extra>::type
    {

      typedef typename Allocator::template rebind< Key>::other key_allocator;

      typedef typename key_allocator::value_type key_type;

      typedef typename key_allocator::pointer key_pointer;

      typedef typename key_allocator::const_pointer const_key_pointer;

      typedef typename key_allocator::reference key_reference;

      typedef typename key_allocator::const_reference const_key_reference;

      typedef typename Allocator::size_type size_type;

      typedef false_type store_extra_false_type;

      typedef true_type store_extra_true_type;

      integral_constant<int,Store_Extra> m_store_extra_indicator;

      typedef false_type no_throw_copies_false_type;

      typedef true_type no_throw_copies_true_type;

      typename no_throw_copies<Key, Mapped>::indicator
      m_no_throw_copies_indicator;

      // Extra value (used when the extra value is stored with each value).
      typedef typename comp_hash_< size_type>::comp_hash comp_hash;
    };

  } // namespace detail
} // namespace pb_ds

#endif // #ifndef PB_DS_TYPES_TRAITS_HPP
