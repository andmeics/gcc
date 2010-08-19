// { dg-require-namedlocale "" }

// 2001-08-27 Benjamin Kosnik  <bkoz@redhat.com>

// Copyright (C) 2001, 2002, 2003, 2004, 2005, 2009, 2010
// Free Software Foundation
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

// 22.2.6.2.1 money_put members

#include <locale>
#include <sstream>
#include <testsuite_hooks.h>

// test double version
void test03()
{
  using namespace std;
  typedef ostreambuf_iterator<char> iterator_type;

  bool test __attribute__((unused)) = true;

  // basic construction
  locale loc_c = locale::classic();
  locale loc_de = locale("de_DE@euro");
  VERIFY( loc_c != loc_de );

  // sanity check the data is correct.
  const string empty;

  // total EPA budget FY 2002
  const long double  digits1 = 720000000000.0;
  
  // cache the money_put facet
  ostringstream oss;
  oss.imbue(loc_de);
  const money_put<char>& mon_put = use_facet<money_put<char> >(oss.getloc()); 

  mon_put.put(oss.rdbuf(), true, oss, ' ', digits1);
  string result1 = oss.str();
  VERIFY( result1 == "7.200.000.000,00 ");

  oss.str(empty);
  mon_put.put(oss.rdbuf(), false, oss, ' ', digits1);
  string result2 = oss.str();
  VERIFY( result2 == "7.200.000.000,00 ");

  // intl and non-intl versions should be the same.
  VERIFY( result1 == result2 );

  // now try with showbase, to get currency symbol in format
  oss.setf(ios_base::showbase);

  oss.str(empty);
  mon_put.put(oss.rdbuf(), true, oss, ' ', digits1);
  string result3 = oss.str();
  VERIFY( result3 == "7.200.000.000,00 EUR ");

  oss.str(empty);
  mon_put.put(oss.rdbuf(), false, oss, ' ', digits1);
  string result4 = oss.str();
  VERIFY( result4 == "7.200.000.000,00 \244");

  // intl and non-intl versions should be different.
  VERIFY( result3 != result4 );
  VERIFY( result3 != result1 );
  VERIFY( result4 != result2 );
}

int main()
{
  test03();
  return 0;
}
