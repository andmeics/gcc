// Copyright (C) 2004 Free Software Foundation, Inc.
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

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#include <cstdio>
#include <fstream>
#include <string>
#include <testsuite_performance.h>

// libstdc++/15002
int main() 
{
  using namespace std;
  using namespace __gnu_test;

  time_counter time;
  resource_counter resource;

  const char filename[] = "tmp_getline.txt";
  const unsigned lines = 1000000;
  const unsigned line_length = 200;

  char* line = new char[line_length + 2];
  
  // Construct data.
  {
    memset(line, 'x', line_length);
    line[line_length] = '\n';
    line[line_length + 1] = '\0';
    
    ofstream out(filename);
    for (unsigned i = 0; i < lines; ++i)
      out << line;
  }

  // C
  {
    // Fill the cache.
    FILE *file = fopen(filename, "r");
    while (fgets(line, line_length + 2, file));
    fclose(file);

    file = fopen(filename, "r");
    start_counters(time, resource);
    while (fgets(line, line_length + 2, file));
    stop_counters(time, resource);
    fclose(file);
    report_performance(__FILE__, "C (fgets)", time, resource);
    clear_counters(time, resource);
  }

  // getline(basic_istream<_CharT, _Traits>& __in,
  //         basic_string<_CharT, _Traits, _Alloc>& __str, _CharT __delim)
  {
    ifstream file(filename);
    string string_line;

    start_counters(time, resource);
    while (getline(file, string_line));
    stop_counters(time, resource);
    report_performance(__FILE__, "C++ (string)", time, resource);
    clear_counters(time, resource);
  }

  // getline(char_type* __s, streamsize __n, char_type __delim)
  {
    ifstream file(filename);
    
    start_counters(time, resource);
    while (file.getline(line, line_length + 2));
    stop_counters(time, resource);
    report_performance(__FILE__, "C++ (char array)", time, resource);
    clear_counters(time, resource);
  }

  delete[] line;
  unlink(filename);
  return 0;
}
