// 2003-02-26 Benjamin Kosnik <bkoz@redhat.com>

// Copyright (C) 2003 Free Software Foundation, Inc.
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
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// IA 64 C++ ABI - 5.1 External Names (a.k.a. Mangling)

#include <testsuite_hooks.h>

// Specific examples mentioned in the IA64 C++ ABI text
// http://www.codesourcery.com/cxx-abi/abi.html#mangling
int main()
{
  using namespace __gnu_test;

  // encoding of N::f::X::g() 
  // (third local mangled entity used as a class-qualifier) 
  // cplus-dem FAIL
  // icc CORE
  verify_demangle("_ZNZN1N1fEiE1X1gE", "error code = -2: invalid mangled name");
  return 0;
}
