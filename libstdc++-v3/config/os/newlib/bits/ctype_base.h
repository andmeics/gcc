// Locale support -*- C++ -*-

// Copyright (C) 2000 Free Software Foundation, Inc.
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
// ISO C++ 14882: 22.1  Locales
//
  
// Information as gleaned from /usr/include/ctype.h, for solaris2.5.1

// Support for Solaris 2.5.1
  
  struct ctype_base
  {
    typedef char 		mask;
    // Non-standard typedefs.
    typedef const int* 		__to_type;

    enum
    {
      space = 010,				// Whitespace
      print = 020 | 01 | 02 | 04 | 0200,	// Printing
      cntrl = 040,				// Control character
      upper = 01,				// UPPERCASE
      lower = 02,				// lowercase
      alpha = 01 | 02,				// Alphabetic
      digit = 04,				// Numeric
      punct = 020,				// Punctuation
      xdigit = 0200,				// Hexadecimal numeric
      alnum = 01 | 02 | 04,			// Alphanumeric
      graph = 020 | 01 | 02 | 04 		// Graphical
    };
  };



