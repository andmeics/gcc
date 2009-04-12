// Copyright (C) 2003, 2009 Free Software Foundation, Inc.
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

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// 27.8.1.4 Overridden virtual functions

#include <fstream>
#include <testsuite_hooks.h>

void test01()
{
  using namespace std;

  bool test __attribute__((unused)) = true;
  const char* name = "tmp_sync_1";

  filebuf fb;

  fb.open(name, ios_base::in | ios_base::out | ios_base::trunc);
  fb.sputn("abc", 3);

  fb.pubseekoff(0, ios_base::beg);
  fb.sputc('1');

  // Sync can't be used to switch from write mode to read mode.
  fb.pubsync();

  filebuf::int_type c = fb.sbumpc();
  VERIFY( c == filebuf::traits_type::eof() );

  fb.close();
}

int main()
{
  test01();
  return 0;
}
