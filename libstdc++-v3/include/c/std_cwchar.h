// -*- C++ -*- forwarding header.

// Copyright (C) 2000, 2002 Free Software Foundation, Inc.
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

//
// ISO C++ 14882: 21.4
//

#ifndef _CPP_CWCHAR
#define _CPP_CWCHAR 1

#pragma GCC system_header

#include <bits/c++config.h>
#include <cstddef>
#include <ctime>

#if _GLIBCPP_HAVE_WCHAR_H
#include_next <wchar.h>
#endif

// Get rid of those macros defined in <wchar.h> in lieu of real functions.
#undef btowc
#undef fgetwc
#undef fgetws
#undef fputwc
#undef fputws
#undef fwide
#undef fwprintf
#undef fwscanf
#undef getwc
#undef getwchar
#undef mbrlen
#undef mbrtowc
#undef mbsinit
#undef mbsrtowcs
#undef putwc
#undef putwchar
#undef swprintf
#undef swscanf
#undef ungetwc
#undef vfwprintf
#undef vswprintf
#undef vwprintf
#undef wcrtomb
#undef wcscat
#undef wcschr
#undef wcscmp
#undef wcscoll
#undef wcscpy
#undef wcscspn
#undef wcsftime
#undef wcslen
#undef wcsncat
#undef wcsncmp
#undef wcsncpy
#undef wcspbrk
#undef wcsrchr
#undef wcsrtombs
#undef wcsspn
#undef wcsstr
#undef wcstod
#undef wcstok
#undef wcstol
#undef wcstoul
#undef wcsxfrm
#undef wctob
#undef wmemchr
#undef wmemcmp
#undef wmemcpy
#undef wmemmove
#undef wmemset
#undef wprintf
#undef wscanf



// Need to do a bit of trickery here with mbstate_t as char_traits
// assumes it is in wchar.h, regardless of wchar_t specializations.
#ifndef _GLIBCPP_HAVE_MBSTATE_T
namespace std
{
  extern "C" 
  {
    typedef struct 
    {
      int __fill[6];
    } mbstate_t;
  }
}  
#endif

#endif 
