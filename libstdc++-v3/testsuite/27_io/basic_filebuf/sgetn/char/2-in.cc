// 2001-05-21 Benjamin Kosnik  <bkoz@redhat.com>

// Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
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

// 27.8.1.4 Overridden virtual functions

#include <fstream>
#include <testsuite_hooks.h>
#include <testsuite_io.h>

// @require@ %-*.tst %-*.txt
// @diff@ %-*.tst %*.txt

const char name_01[] = "sgetn.txt"; // file with data in it

// Test overloaded virtual functions.
void test05() 
{
  using namespace std;
  using namespace __gnu_test;
  typedef filebuf::int_type 	int_type;
  typedef filebuf::traits_type 	traits_type;

  bool test __attribute__((unused)) = true;

  streamsize 			strmsz_1, strmsz_2;
  char carray1[13] = "";
  char carray2[8192] = "";
  int_type 			c1, c4;
  
  // streamsize sgetn(char_type *s, streamsize n)
  // streamsize xsgetn(char_type *s, streamsize n)
  // assign up to n chars to s from input sequence, indexing in_cur as
  // approp and returning the number of chars assigned

  // in 
  {
    constraint_filebuf fb_01; 
    fb_01.pubsetbuf(0, 0);
    fb_01.open(name_01, ios_base::in);
    VERIFY( fb_01.unbuffered() );
    strmsz_1 = fb_01.in_avail();
    strmsz_2 = fb_01.sgetn(carray1, 10);
    VERIFY( strmsz_2 == 10 );
    strmsz_2 = fb_01.in_avail(); 
    VERIFY( strmsz_1 > strmsz_2 );
    c1 = fb_01.sgetc();
    VERIFY( c1 == 'b' );  
    strmsz_1 = fb_01.in_avail(); // 8181 or 8250 depending on buffer
    strmsz_2 = fb_01.sgetn(carray2, 8181 + 5);
    VERIFY( 8181 == strmsz_2 - 5 ); 
    c4 = fb_01.sgetc(); // buffer should have underflowed from above.
    VERIFY( c4 == 'h' );
    strmsz_1 = fb_01.in_avail();
    VERIFY( strmsz_1 > 0 );
    strmsz_2 = fb_01.sgetn(carray2, 65 + 5);
    VERIFY( 65 == strmsz_2 ); // at the end of the actual file 
    VERIFY( fb_01.unbuffered() );
  }
}

int main() 
{
  test05();
  return 0;
}
