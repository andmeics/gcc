// 2003-04-26 Petur Runolfsson  <peturr02@ru.is>

// Copyright (C) 2003 Free Software Foundation
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

// 27.3 Standard iostream objects

// ios_base::Init::~Init() calls cout.flush(), which may call
// cout.setstate(badbit), which may throw an exception. Check that
// the exception doesn't escape from the destructor.

#include <iostream>
#include <streambuf>
#include <testsuite_hooks.h>

class Badbuf : public std::streambuf
{
protected:
  virtual int sync()
  { return -1; }
};

void test06()
{
  bool test = true;

  try
    {
      // No-op in current code.
      std::ios_base::Init init;
      std::cout.rdbuf(new Badbuf);
      std::cout.exceptions(std::ios_base::badbit);
    }
  catch(...)
    {
      test = false;
    }
  VERIFY( test );
}

int main()
{
  test06();
  return 0;
}
