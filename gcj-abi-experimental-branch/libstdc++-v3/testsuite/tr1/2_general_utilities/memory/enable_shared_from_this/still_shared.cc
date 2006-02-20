// Copyright (C) 2005 Free Software Foundation
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

// 2.2.5 Template class enable_shared_from_this [tr.util.smartptr.enab]

#include <tr1/memory>
#include <testsuite_hooks.h>

struct X : public std::tr1::enable_shared_from_this<X>
{
};

int
test01()
{
  bool test __attribute__((unused)) = true;

  std::tr1::shared_ptr<X> p(new X);

  *p = X();  // assigning to shared object doesn't stop it being shared

  try
  {
    std::tr1::shared_ptr<X> p2 = p->shared_from_this();
  }
  catch (const std::tr1::bad_weak_ptr&)
  {
    test = false;
  }
  VERIFY( test );

  return 0;
}

int 
main()
{
  test01();
  return 0;
}
