// { dg-options "-std=gnu++17" }

// Copyright (C) 2016-2018 Free Software Foundation, Inc.
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

// [string.modifiers]

#include <string>
#include <testsuite_hooks.h>

void
test03()
{
  std::wstring_view str1(L"foo");
  std::wstring str2;
  str2.assign(str1);
  VERIFY (str2 == str1);
  std::wstring str4;
  str4.assign(str1, 1, 2);
  VERIFY (str4 == L"oo");
}

// PR libstdc++/77264
void
test04()
{
  std::wstring str(L"a");

  wchar_t c = L'b';
  str.assign(&c, 1);
  VERIFY (str[0] == c);

  wchar_t arr[] = L"c";
  str.assign(arr, 1);
  VERIFY (str[0] == arr[0]);

  const wchar_t carr[] = L"d";
  str.assign(carr, 1);
  VERIFY (str[0] == carr[0]);

  struct S {
    operator wchar_t*() { return &c; }
    operator std::wstring_view() { return L"!"; }
    wchar_t c = L'e';
  };

  str.assign(S{}, 1);
  VERIFY (str[0] == S{}.c);
}

int main()
{ 
  test03();
  test04();
  return 0;
}
