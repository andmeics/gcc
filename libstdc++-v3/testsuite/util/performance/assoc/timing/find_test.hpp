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
 * @file find_test.hpp
 * Contains a generic find test.
 */

#ifndef PB_DS_FIND_TEST_HPP
#define PB_DS_FIND_TEST_HPP

#include <performance/time/timing_test_base.hpp>
#include <performance/io/xml_formatter.hpp>
#include <common_type/assoc/string_form.hpp>
#include <iterator>

namespace pb_ds
{

  namespace test
  {

    namespace detail
    {

      template<typename It, class Cntnr, bool LOR>
      class find_find_functor
      {
      public:
        find_find_functor(Cntnr& r_container,  It fnd_it_b,  It fnd_it_e) : m_r_container(r_container),
									    m_fnd_it_b(fnd_it_b),
									    m_fnd_it_e(fnd_it_e)
	{ }

	void
        operator()(std::size_t resolution)
	{
	  for (std::size_t i = 0; i < resolution; ++i)
	    {
	      It fnd_it = m_fnd_it_b;

	      while (fnd_it != m_fnd_it_e)
                ++m_r_container.find((fnd_it++)->first)->second;
	    }
	}

      private:
	Cntnr& m_r_container;

	const It m_fnd_it_b;
	const It m_fnd_it_e;
      };

      template<typename It, class Cntnr>
      class find_find_functor<
	It,
	Cntnr,
	true>
      {
      public:
        find_find_functor(Cntnr& r_container,  It fnd_it_b,  It fnd_it_e) : m_r_container(r_container),
									    m_fnd_it_b(fnd_it_b),
									    m_fnd_it_e(fnd_it_e)
	{ }

	void
        operator()(std::size_t resolution)
	{
	  It fnd_it = m_fnd_it_b;

	  while (fnd_it != m_fnd_it_e)
	    {
	      for (std::size_t i = 0; i < resolution; ++i)
                ++m_r_container.find(fnd_it->first)->second;

	      ++fnd_it;
	    }
	}

      private:
	Cntnr& m_r_container;

	const It m_fnd_it_b;
	const It m_fnd_it_e;
      };

    } // namespace detail

#define PB_DS_CLASS_T_DEC			\
    template<typename It, bool LOR>

#define PB_DS_CLASS_C_DEC				\
    find_test<						\
						It,	\
						LOR>

    template<typename It, bool LOR = false>
    class find_test : private pb_ds::test::detail::timing_test_base
    {
    public:
      find_test(It ins_b, It fnd_it_b, size_t ins_vn, size_t ins_vs, size_t ins_vm, size_t fnd_vn, size_t fnd_vs, size_t fnd_vm);

      template<typename Cntnr>
      void
      operator()(pb_ds::detail::type_to_type<Cntnr>);

    private:
      find_test(const find_test& );

    private:
      const It m_ins_b;

      const It m_fnd_it_b;

      const size_t m_ins_vn;
      const size_t m_ins_vs;
      const size_t m_ins_vm;

      const size_t m_fnd_vn;
      const size_t m_fnd_vs;
      const size_t m_fnd_vm;
    };

    PB_DS_CLASS_T_DEC
    PB_DS_CLASS_C_DEC::
    find_test(It ins_b, It fnd_it_b, size_t ins_vn, size_t ins_vs, size_t ins_vm, size_t fnd_vn, size_t fnd_vs, size_t fnd_vm) :
      m_ins_b(ins_b),
      m_fnd_it_b(fnd_it_b),
      m_ins_vn(ins_vn),
      m_ins_vs(ins_vs),
      m_ins_vm(ins_vm),
      m_fnd_vn(fnd_vn),
      m_fnd_vs(fnd_vs),
      m_fnd_vm(fnd_vm)
    { }

    PB_DS_CLASS_T_DEC
    template<typename Cntnr>
    void
    PB_DS_CLASS_C_DEC::
    operator()(pb_ds::detail::type_to_type<Cntnr>)
    {
      xml_result_set_performance_formatter res_set_fmt(
						       string_form<Cntnr>::name(),
						       string_form<Cntnr>::desc());

      for (size_t size_i = 0; m_ins_vn + size_i*  m_ins_vs < m_ins_vm; ++size_i)
	{
	  const size_t v = m_ins_vn + size_i*  m_ins_vs;
	  const size_t fnd_size = m_fnd_vn + size_i*  m_fnd_vs;

	  It ins_it_b = m_ins_b;
	  It ins_it_e = m_ins_b;
	  std::advance(ins_it_e, v);

	  Cntnr test_container(ins_it_b, ins_it_e);

	  It fnd_it_b = m_fnd_it_b;
	  It fnd_it_e = m_fnd_it_b;
	  std::advance(fnd_it_e, fnd_size);

	  pb_ds::test::detail::find_find_functor<It, Cntnr, LOR>
            fn(test_container, fnd_it_b, fnd_it_e);

	  const double res =
            pb_ds::test::detail::timing_test_base::operator()(fn);

	  res_set_fmt.add_res(v, res / fnd_size);
	}
    }

#undef PB_DS_CLASS_T_DEC

#undef PB_DS_CLASS_C_DEC

  } // namespace test

} // namespace pb_ds

#endif // #ifndef PB_DS_FIND_TEST_HPP

