// The template and inlines for the -*- C++ -*- numeric_limits classes.

// Copyright (C) 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
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

// Note: this is not a conforming implementation.
// Written by Gabriel Dos Reis <gdr@codesourcery.com>

//
// ISO 14882:1998
// 18.2.1
//

/** @file limits
 *  This is a Standard C++ Library header.  You should @c #include this header
 *  in your programs, rather than any of the "st[dl]_*.h" implementation files.
 */

#ifndef _CPP_NUMERIC_LIMITS
#define _CPP_NUMERIC_LIMITS 1

#pragma GCC system_header

#include <bits/cpu_limits.h>
#include <bits/c++config.h>

//
// The numeric_limits<> traits document implementation-defined aspects
// of fundamental arithmetic data types (integers and floating points).
// From Standard C++ point of view, there are 13 such types:
//   * integers
//         bool						        (1)
//         char, signed char, unsigned char			(3)
//         short, unsigned short				(2)
//         int, unsigned					(2)
//         long, unsigned long					(2)
//
//   * floating points
//         float						(1)
//         double						(1)
//         long double						(1)
//
// GNU C++ undertstands (where supported by the host C-library) 
//   * integer
//         long long, unsigned long long			(2)
//
// which brings us to 15 fundamental arithmetic data types in GNU C++.
//
// 
// Since a numeric_limits<> is a bit tricky to get right, we rely on
// an interface composed of macros which should be defined in config/os
// or config/cpu when they differ from the generic (read arbitrary)
// definitions given here.
//

#ifdef __CHAR_UNSIGNED__
#  define __glibcpp_plain_char_is_signed false
#else
#  define __glibcpp_plain_char_is_signed true
#endif

#ifndef __WCHAR_UNSIGNED__
#  define __glibcpp_wchar_t_is_signed false
#else
#  define __glibcpp_wchar_t_is_signed true
#endif

// These values can be overridden in the target configuration file.
// The default values are appropriate for many 32-bit targets.

// GCC only intrinsicly supports modulo integral types.  The only remaining
// integral exceptional values is division by zero.  Only targets that do not
// signal division by zero in some "hard to ignore" way should use false.
#ifndef __glibcpp_integral_traps
# define __glibcpp_integral_traps true
#endif

// You should not need to define any macros below this point, unless
// you have a machine with non-standard bit-widths.

// These values are the minimums and maximums for standard data types
// of common widths.

#define __glibcpp_s8_max 127
#define __glibcpp_s8_min (-__glibcpp_s8_max - 1)
#define __glibcpp_s8_digits 7
#define __glibcpp_s8_digits10 2
#define __glibcpp_u8_min 0U
#define __glibcpp_u8_max (__glibcpp_s8_max * 2 + 1)
#define __glibcpp_u8_digits 8
#define __glibcpp_u8_digits10 2
#define __glibcpp_s16_max 32767
#define __glibcpp_s16_min (-__glibcpp_s16_max - 1)
#define __glibcpp_s16_digits 15
#define __glibcpp_s16_digits10 4
#define __glibcpp_u16_min 0U
#define __glibcpp_u16_max (__glibcpp_s16_max * 2 + 1)
#define __glibcpp_u16_digits 16
#define __glibcpp_u16_digits10 4
#define __glibcpp_s32_max 2147483647L
#define __glibcpp_s32_min (-__glibcpp_s32_max - 1)
#define __glibcpp_s32_digits 31
#define __glibcpp_s32_digits10 9
#define __glibcpp_u32_min 0UL
#define __glibcpp_u32_max (__glibcpp_s32_max * 2U + 1)
#define __glibcpp_u32_digits 32
#define __glibcpp_u32_digits10 9
#define __glibcpp_s64_max 9223372036854775807LL
#define __glibcpp_s64_min (-__glibcpp_s64_max - 1)
#define __glibcpp_s64_digits 63
#define __glibcpp_s64_digits10 18
#define __glibcpp_u64_min 0ULL
#define __glibcpp_u64_max (__glibcpp_s64_max * 2ULL + 1)
#define __glibcpp_u64_digits 64
#define __glibcpp_u64_digits10 19

// bool-specific hooks:
//     __glibcpp_bool_digits

#ifndef __glibcpp_bool_digits
#  define __glibcpp_bool_digits 1
#endif

// char.

#if __CHAR_BIT__ == 8
#  define __glibcpp_signed_char_min __glibcpp_s8_min
#  define __glibcpp_signed_char_max __glibcpp_s8_max
#  define __glibcpp_signed_char_digits __glibcpp_s8_digits
#  define __glibcpp_signed_char_digits10 __glibcpp_s8_digits10
#  define __glibcpp_unsigned_char_min __glibcpp_u8_min
#  define __glibcpp_unsigned_char_max __glibcpp_u8_max
#  define __glibcpp_unsigned_char_digits __glibcpp_u8_digits
#  define __glibcpp_unsigned_char_digits10 __glibcpp_u8_digits10
#elif __CHAR_BIT__ == 16
#  define __glibcpp_signed_char_min __glibcpp_s16_min
#  define __glibcpp_signed_char_max __glibcpp_s16_max
#  define __glibcpp_signed_char_digits __glibcpp_s16_digits
#  define __glibcpp_signed_char_digits10 __glibcpp_s16_digits10
#  define __glibcpp_unsigned_char_min __glibcpp_u16_min
#  define __glibcpp_unsigned_char_max __glibcpp_u16_max
#  define __glibcpp_unsigned_char_digits __glibcpp_u16_digits
#  define __glibcpp_unsigned_char_digits10 __glibcpp_u16_digits10
#elif __CHAR_BIT__ == 32
#  define __glibcpp_signed_char_min (signed char)__glibcpp_s32_min
#  define __glibcpp_signed_char_max (signed char)__glibcpp_s32_max
#  define __glibcpp_signed_char_digits __glibcpp_s32_digits
#  define __glibcpp_signed_char_digits10 __glibcpp_s32_digits10
#  define __glibcpp_unsigned_char_min (unsigned char)__glibcpp_u32_min
#  define __glibcpp_unsigned_char_max (unsigned char)__glibcpp_u32_max
#  define __glibcpp_unsigned_char_digits __glibcpp_u32_digits
#  define __glibcpp_unsigned_char_digits10 __glibcpp_u32_digits10
#elif __CHAR_BIT__ == 64
#  define __glibcpp_signed_char_min (signed char)__glibcpp_s64_min
#  define __glibcpp_signed_char_max (signed char)__glibcpp_s64_max
#  define __glibcpp_signed_char_digits __glibcpp_s64_digits
#  define __glibcpp_signed_char_digits10 __glibcpp_s64_digits10
#  define __glibcpp_unsigned_char_min (unsigned char)__glibcpp_u64_min
#  define __glibcpp_unsigned_char_max (unsigned char)__glibcpp_u64_max
#  define __glibcpp_unsigned_char_digits __glibcpp_u64_digits
#  define __glibcpp_unsigned_char_digits10 __glibcpp_u64_digits10
#else
// You must define these macros in the configuration file.
#endif

#if __glibcpp_plain_char_is_signed
#  define __glibcpp_char_min (char)__glibcpp_signed_char_min
#  define __glibcpp_char_max (char)__glibcpp_signed_char_max
#  define __glibcpp_char_digits __glibcpp_signed_char_digits
#  define __glibcpp_char_digits10 __glibcpp_signed_char_digits
#else
#  define __glibcpp_char_min (char)__glibcpp_unsigned_char_min
#  define __glibcpp_char_max (char)__glibcpp_unsigned_char_max
#  define __glibcpp_char_digits __glibcpp_unsigned_char_digits
#  define __glibcpp_char_digits10 __glibcpp_unsigned_char_digits
#endif

// short

#if __SHRT_BIT__ == 8
#  define __glibcpp_signed_short_min __glibcpp_s8_min
#  define __glibcpp_signed_short_max __glibcpp_s8_max
#  define __glibcpp_signed_short_digits __glibcpp_s8_digits
#  define __glibcpp_signed_short_digits10 __glibcpp_s8_digits10
#  define __glibcpp_unsigned_short_min __glibcpp_u8_min
#  define __glibcpp_unsigned_short_max __glibcpp_u8_max
#  define __glibcpp_unsigned_short_digits __glibcpp_u8_digits
#  define __glibcpp_unsigned_short_digits10 __glibcpp_u8_digits10
#elif __SHRT_BIT__ == 16
#  define __glibcpp_signed_short_min __glibcpp_s16_min
#  define __glibcpp_signed_short_max __glibcpp_s16_max
#  define __glibcpp_signed_short_digits __glibcpp_s16_digits
#  define __glibcpp_signed_short_digits10 __glibcpp_s16_digits10
#  define __glibcpp_unsigned_short_min __glibcpp_u16_min
#  define __glibcpp_unsigned_short_max __glibcpp_u16_max
#  define __glibcpp_unsigned_short_digits __glibcpp_u16_digits
#  define __glibcpp_unsigned_short_digits10 __glibcpp_u16_digits10
#elif __SHRT_BIT__ == 32
#  define __glibcpp_signed_short_min (short)__glibcpp_s32_min
#  define __glibcpp_signed_short_max (short)__glibcpp_s32_max
#  define __glibcpp_signed_short_digits __glibcpp_s32_digits
#  define __glibcpp_signed_short_digits10 __glibcpp_s32_digits10
#  define __glibcpp_unsigned_short_min (unsigned short)__glibcpp_u32_min
#  define __glibcpp_unsigned_short_max (unsigned short)__glibcpp_u32_max
#  define __glibcpp_unsigned_short_digits __glibcpp_u32_digits
#  define __glibcpp_unsigned_short_digits10 __glibcpp_u32_digits10
#elif __SHRT_BIT__ == 64
#  define __glibcpp_signed_short_min (short)__glibcpp_s64_min
#  define __glibcpp_signed_short_max (short)__glibcpp_s64_max
#  define __glibcpp_signed_short_digits __glibcpp_s64_digits
#  define __glibcpp_signed_short_digits10 __glibcpp_s64_digits10
#  define __glibcpp_unsigned_short_min (unsigned short)__glibcpp_u64_min
#  define __glibcpp_unsigned_short_max (unsigned short)__glibcpp_u64_max
#  define __glibcpp_unsigned_short_digits __glibcpp_u64_digits
#  define __glibcpp_unsigned_short_digits10 __glibcpp_u64_digits10
#else
// You must define these macros in the configuration file.
#endif

// int

#if __INT_BIT__ == 8
#  define __glibcpp_signed_int_min __glibcpp_s8_min
#  define __glibcpp_signed_int_max __glibcpp_s8_max
#  define __glibcpp_signed_int_digits __glibcpp_s8_digits
#  define __glibcpp_signed_int_digits10 __glibcpp_s8_digits10
#  define __glibcpp_unsigned_int_min __glibcpp_u8_min
#  define __glibcpp_unsigned_int_max __glibcpp_u8_max
#  define __glibcpp_unsigned_int_digits __glibcpp_u8_digits
#  define __glibcpp_unsigned_int_digits10 __glibcpp_u8_digits10
#elif __INT_BIT__ == 16
#  define __glibcpp_signed_int_min __glibcpp_s16_min
#  define __glibcpp_signed_int_max __glibcpp_s16_max
#  define __glibcpp_signed_int_digits __glibcpp_s16_digits
#  define __glibcpp_signed_int_digits10 __glibcpp_s16_digits10
#  define __glibcpp_unsigned_int_min __glibcpp_u16_min
#  define __glibcpp_unsigned_int_max __glibcpp_u16_max
#  define __glibcpp_unsigned_int_digits __glibcpp_u16_digits
#  define __glibcpp_unsigned_int_digits10 __glibcpp_u16_digits10
#elif __INT_BIT__ == 32
#  define __glibcpp_signed_int_min (int)__glibcpp_s32_min
#  define __glibcpp_signed_int_max (int)__glibcpp_s32_max
#  define __glibcpp_signed_int_digits __glibcpp_s32_digits
#  define __glibcpp_signed_int_digits10 __glibcpp_s32_digits10
#  define __glibcpp_unsigned_int_min (unsigned)__glibcpp_u32_min
#  define __glibcpp_unsigned_int_max (unsigned)__glibcpp_u32_max
#  define __glibcpp_unsigned_int_digits __glibcpp_u32_digits
#  define __glibcpp_unsigned_int_digits10 __glibcpp_u32_digits10
#elif __INT_BIT__ == 64
#  define __glibcpp_signed_int_min (int)__glibcpp_s64_min
#  define __glibcpp_signed_int_max (int)__glibcpp_s64_max
#  define __glibcpp_signed_int_digits __glibcpp_s64_digits
#  define __glibcpp_signed_int_digits10 __glibcpp_s64_digits10
#  define __glibcpp_unsigned_int_min (unsigned)__glibcpp_u64_min
#  define __glibcpp_unsigned_int_max (unsigned)__glibcpp_u64_max
#  define __glibcpp_unsigned_int_digits __glibcpp_u64_digits
#  define __glibcpp_unsigned_int_digits10 __glibcpp_u64_digits10
#else
// You must define these macros in the configuration file.
#endif

// long

#if __LONG_BIT__ == 8
#  define __glibcpp_signed_long_min __glibcpp_s8_min
#  define __glibcpp_signed_long_max __glibcpp_s8_max
#  define __glibcpp_signed_long_digits __glibcpp_s8_digits
#  define __glibcpp_signed_long_digits10 __glibcpp_s8_digits10
#  define __glibcpp_unsigned_long_min __glibcpp_u8_min
#  define __glibcpp_unsigned_long_max __glibcpp_u8_max
#  define __glibcpp_unsigned_long_digits __glibcpp_u8_digits
#  define __glibcpp_unsigned_long_digits10 __glibcpp_u8_digits10
#elif __LONG_BIT__ == 16
#  define __glibcpp_signed_long_min __glibcpp_s16_min
#  define __glibcpp_signed_long_max __glibcpp_s16_max
#  define __glibcpp_signed_long_digits __glibcpp_s16_digits
#  define __glibcpp_signed_long_digits10 __glibcpp_s16_digits10
#  define __glibcpp_unsigned_long_min __glibcpp_u16_min
#  define __glibcpp_unsigned_long_max __glibcpp_u16_max
#  define __glibcpp_unsigned_long_digits __glibcpp_u16_digits
#  define __glibcpp_unsigned_long_digits10 __glibcpp_u16_digits10
#elif __LONG_BIT__ == 32
#  define __glibcpp_signed_long_min __glibcpp_s32_min
#  define __glibcpp_signed_long_max __glibcpp_s32_max
#  define __glibcpp_signed_long_digits __glibcpp_s32_digits
#  define __glibcpp_signed_long_digits10 __glibcpp_s32_digits10
#  define __glibcpp_unsigned_long_min __glibcpp_u32_min
#  define __glibcpp_unsigned_long_max __glibcpp_u32_max
#  define __glibcpp_unsigned_long_digits __glibcpp_u32_digits
#  define __glibcpp_unsigned_long_digits10 __glibcpp_u32_digits10
#elif __LONG_BIT__ == 64
#  define __glibcpp_signed_long_min (long)__glibcpp_s64_min
#  define __glibcpp_signed_long_max (long)__glibcpp_s64_max
#  define __glibcpp_signed_long_digits __glibcpp_s64_digits
#  define __glibcpp_signed_long_digits10 __glibcpp_s64_digits10
#  define __glibcpp_unsigned_long_min (unsigned long)__glibcpp_u64_min
#  define __glibcpp_unsigned_long_max (unsigned long)__glibcpp_u64_max
#  define __glibcpp_unsigned_long_digits __glibcpp_u64_digits
#  define __glibcpp_unsigned_long_digits10 __glibcpp_u64_digits10
#else
// You must define these macros in the configuration file.
#endif

// long long

#if __LONG_LONG_BIT__ == 8
#  define __glibcpp_signed_long_long_min __glibcpp_s8_min
#  define __glibcpp_signed_long_long_max __glibcpp_s8_max
#  define __glibcpp_signed_long_long_digits __glibcpp_s8_digits
#  define __glibcpp_signed_long_long_digits10 __glibcpp_s8_digits10
#  define __glibcpp_unsigned_long_long_min __glibcpp_u8_min
#  define __glibcpp_unsigned_long_long_max __glibcpp_u8_max
#  define __glibcpp_unsigned_long_long_digits __glibcpp_u8_digits
#  define __glibcpp_unsigned_long_long_digits10 __glibcpp_u8_digits10
#elif __LONG_LONG_BIT__ == 16
#  define __glibcpp_signed_long_long_min __glibcpp_s16_min
#  define __glibcpp_signed_long_long_max __glibcpp_s16_max
#  define __glibcpp_signed_long_long_digits __glibcpp_s16_digits
#  define __glibcpp_signed_long_long_digits10 __glibcpp_s16_digits10
#  define __glibcpp_unsigned_long_long_min __glibcpp_u16_min
#  define __glibcpp_unsigned_long_long_max __glibcpp_u16_max
#  define __glibcpp_unsigned_long_long_digits __glibcpp_u16_digits
#  define __glibcpp_unsigned_long_long_digits10 __glibcpp_u16_digits10
#elif __LONG_LONG_BIT__ == 32
#  define __glibcpp_signed_long_long_min __glibcpp_s32_min
#  define __glibcpp_signed_long_long_max __glibcpp_s32_max
#  define __glibcpp_signed_long_long_digits __glibcpp_s32_digits
#  define __glibcpp_signed_long_long_digits10 __glibcpp_s32_digits10
#  define __glibcpp_unsigned_long_long_min __glibcpp_u32_min
#  define __glibcpp_unsigned_long_long_max __glibcpp_u32_max
#  define __glibcpp_unsigned_long_long_digits __glibcpp_u32_digits
#  define __glibcpp_unsigned_long_long_digits10 __glibcpp_u32_digits10
#elif __LONG_LONG_BIT__ == 64
#  define __glibcpp_signed_long_long_min __glibcpp_s64_min
#  define __glibcpp_signed_long_long_max __glibcpp_s64_max
#  define __glibcpp_signed_long_long_digits __glibcpp_s64_digits
#  define __glibcpp_signed_long_long_digits10 __glibcpp_s64_digits10
#  define __glibcpp_unsigned_long_long_min __glibcpp_u64_min
#  define __glibcpp_unsigned_long_long_max __glibcpp_u64_max
#  define __glibcpp_unsigned_long_long_digits __glibcpp_u64_digits
#  define __glibcpp_unsigned_long_long_digits10 __glibcpp_u64_digits10
#else
// You must define these macros in the configuration file.
#endif

// wchar_t

#if __glibcpp_wchar_t_is_signed
#  if __WCHAR_BIT__ == 8
#    define __glibcpp_wchar_t_min __glibcpp_s8_min
#    define __glibcpp_wchar_t_max __glibcpp_s8_max
#    define __glibcpp_wchar_t_digits __glibcpp_s8_digits
#    define __glibcpp_wchar_t_digits10 __glibcpp_s8_digits10
#  elif __WCHAR_BIT__ == 16
#    define __glibcpp_wchar_t_min __glibcpp_s16_min
#    define __glibcpp_wchar_t_max __glibcpp_s16_max
#    define __glibcpp_wchar_t_digits __glibcpp_s16_digits
#    define __glibcpp_wchar_t_digits10 __glibcpp_s16_digits10
#  elif __WCHAR_BIT__ == 32
#    define __glibcpp_wchar_t_min (wchar_t)__glibcpp_s32_min
#    define __glibcpp_wchar_t_max (wchar_t)__glibcpp_s32_max
#    define __glibcpp_wchar_t_digits __glibcpp_s32_digits
#    define __glibcpp_wchar_t_digits10 __glibcpp_s32_digits10
#  elif __WCHAR_BIT__ == 64
#    define __glibcpp_wchar_t_min (wchar_t)__glibcpp_s64_min
#    define __glibcpp_wchar_t_max (wchar_t)__glibcpp_s64_max
#    define __glibcpp_wchar_t_digits __glibcpp_s64_digits
#    define __glibcpp_wchar_t_digits10 __glibcpp_s64_digits10
#  else
// You must define these macros in the configuration file.
#  endif
#else
#  if __WCHAR_BIT__ == 8
#    define __glibcpp_wchar_t_min __glibcpp_u8_min
#    define __glibcpp_wchar_t_max __glibcpp_u8_max
#    define __glibcpp_wchar_t_digits __glibcpp_u8_digits
#    define __glibcpp_wchar_t_digits10 __glibcpp_u8_digits10
#  elif __WCHAR_BIT__ == 16
#    define __glibcpp_wchar_t_min __glibcpp_u16_min
#    define __glibcpp_wchar_t_max __glibcpp_u16_max
#    define __glibcpp_wchar_t_digits __glibcpp_u16_digits
#    define __glibcpp_wchar_t_digits10 __glibcpp_u16_digits10
#  elif __WCHAR_BIT__ == 32
#    define __glibcpp_wchar_t_min (wchar_t)__glibcpp_u32_min
#    define __glibcpp_wchar_t_max (wchar_t)__glibcpp_u32_max
#    define __glibcpp_wchar_t_digits __glibcpp_u32_digits
#    define __glibcpp_wchar_t_digits10 __glibcpp_u32_digits10
#  elif __WCHAR_BIT__ == 64
#    define __glibcpp_wchar_t_min (wchar_t)__glibcpp_u64_min
#    define __glibcpp_wchar_t_max (wchar_t)__glibcpp_u64_max
#    define __glibcpp_wchar_t_digits __glibcpp_u64_digits
#    define __glibcpp_wchar_t_digits10 __glibcpp_u64_digits10
#  else
// You must define these macros in the configuration file.
#  endif
#endif

// float
//

// Default values.  Should be overriden in configuration files if necessary.

#ifndef __glibcpp_float_has_denorm_loss
#  define __glibcpp_float_has_denorm_loss false
#endif

#ifndef __glibcpp_float_is_modulo
#  define __glibcpp_float_is_modulo false
#endif

#ifndef __glibcpp_float_traps
#  define __glibcpp_float_traps false
#endif

#ifndef __glibcpp_float_tinyness_before
#  define __glibcpp_float_tinyness_before false
#endif

// double

// Default values.  Should be overriden in configuration files if necessary.

#ifndef __glibcpp_double_has_denorm_loss
#  define __glibcpp_double_has_denorm_loss false
#endif

#ifndef __glibcpp_double_is_modulo
#  define __glibcpp_double_is_modulo false
#endif

#ifndef __glibcpp_double_traps
#  define __glibcpp_double_traps false
#endif

#ifndef __glibcpp_double_tinyness_before
#  define __glibcpp_double_tinyness_before false
#endif

// long double

// Default values.  Should be overriden in configuration files if necessary.

#ifndef __glibcpp_long_double_has_denorm_loss
#  define __glibcpp_long_double_has_denorm_loss false
#endif

#ifndef __glibcpp_long_double_is_modulo
#  define __glibcpp_long_double_is_modulo false
#endif

#ifndef __glibcpp_long_double_traps
#  define __glibcpp_long_double_traps false
#endif

#ifndef __glibcpp_long_double_tinyness_before
#  define __glibcpp_long_double_tinyness_before false
#endif


namespace std
{
  // This is better handled by the compiler, but we do it here for the
  // time being.  (We're just second-guessing something the compiler
  // knows about better than we do.) -- Gaby
  typedef unsigned char __glibcpp_byte;
#define __glibcpp_word_bits 32
#if __CHAR_BIT__ == __glibcpp_word_bits
#  define __glibcpp_word unsigned char
#elif __SHRT_BIT__ == __glibcpp_word_bits
#  define __glibcpp_word unsigned short  
#elif __INT_BIT__ == __glibcpp_word_bits
#  define __glibcpp_word unsigned int
#elif __LONG_BIT__ == __glibcpp_word_bits
#  define __glibcpp_word unsigned long
#endif  

  // Define storage types for the single, double and extended floating
  // point data types.  Maybe we could avoid the conditional #defines by
  // using the aligned_storage<> extension.  -- Gaby
  typedef const
#if __FLOAT_BIT__ % __glibcpp_word_bits == 0
    __glibcpp_word __float_storage[sizeof (float) / sizeof (__glibcpp_word)]
#else
    __glibcpp_byte __float_storage[sizeof (float)]
#endif  
    __attribute__((__aligned__(__alignof__(float))));

  typedef const
#if __DOUBLE_BIT__ % __glibcpp_word_bits == 0
    __glibcpp_word __double_storage[sizeof (double) / sizeof (__glibcpp_word)]
#else
    __glibcpp_byte __double_storage[sizeof (double)]
#endif  
    __attribute__((__aligned__(__alignof__(double))));

  typedef const
#if __LONG_DOUBLE_BIT__ % __glibcpp_word_bits == 0
    __glibcpp_word __long_double_storage[sizeof (long double) / sizeof (__glibcpp_word)]
#else
    __glibcpp_byte __long_double_storage[sizeof (long double)]
#endif  
    __attribute__((__aligned__(__alignof__(long double))));

  enum float_round_style 
  {
    round_indeterminate       = -1,
    round_toward_zero         = 0,
    round_to_nearest          = 1,
    round_toward_infinity     = 2,
    round_toward_neg_infinity = 3
  };

  enum float_denorm_style 
  {
    denorm_indeterminate = -1,
    denorm_absent        = 0,
    denorm_present       = 1
  };

  //
  // The primary class traits
  //
  struct __numeric_limits_base
  {
    static const bool is_specialized = false;

    static const int digits = 0;
    static const int digits10 = 0;
    static const bool is_signed = false;
    static const bool is_integer = false;
    static const bool is_exact = false;
    static const int radix = 0;

    static const int min_exponent = 0;
    static const int min_exponent10 = 0;
    static const int max_exponent = 0;
    static const int max_exponent10 = 0;
    
    static const bool has_infinity = false;
    static const bool has_quiet_NaN = false;
    static const bool has_signaling_NaN = false;
    static const float_denorm_style has_denorm = denorm_absent;
    static const bool has_denorm_loss = false;

    static const bool is_iec559 = false;
    static const bool is_bounded = false;
    static const bool is_modulo = false;

    static const bool traps = false;
    static const bool tinyness_before = false;
    static const float_round_style round_style = round_toward_zero;
  };

  template<typename _Tp> 
    struct numeric_limits : public __numeric_limits_base 
    {
      static _Tp min() throw() { return static_cast<_Tp>(0); }
      static _Tp max() throw() { return static_cast<_Tp>(0); }
      static _Tp epsilon() throw() { return static_cast<_Tp>(0); }
      static _Tp round_error() throw() { return static_cast<_Tp>(0); }
      static _Tp infinity() throw()  { return static_cast<_Tp>(0); }
      static _Tp quiet_NaN() throw() { return static_cast<_Tp>(0); }
      static _Tp signaling_NaN() throw() { return static_cast<_Tp>(0); }
      static _Tp denorm_min() throw() { return static_cast<_Tp>(0); }
    };

  // Now there follow 15 explicit specializations.  Yes, 15.  Make sure
  // you get the count right.  
  template<>
    struct numeric_limits<bool>
    {
      static const bool is_specialized = true;

      static bool min() throw()
      { return false; }

      static bool max() throw()
      { return true; }

      static const int digits = __glibcpp_bool_digits;
      static const int digits10 = 0;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static bool epsilon() throw()
      { return false; }
      static bool round_error() throw()
      { return false; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static bool infinity() throw()
      { return false; }
      static bool quiet_NaN() throw()
      { return false; }
      static bool signaling_NaN() throw()
      { return false; }
      static bool denorm_min() throw()
      { return false; }

      static const bool is_iec559 = false;
      static const bool is_bounded = true;
      static const bool is_modulo = false;

      // It is not clear what it means for a boolean type to trap.
      // This is a DR on the LWG issue list.  Here, I use integer
      // promotion semantics.
      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_bool_digits  
  
  template<>
    struct numeric_limits<char>
    {
      static const bool is_specialized = true;

      static char min() throw()
      { return __glibcpp_char_min; }
      static char max() throw()
      { return __glibcpp_char_max; }

      static const int digits = __glibcpp_char_digits;
      static const int digits10 = __glibcpp_char_digits10;
      static const bool is_signed = __glibcpp_plain_char_is_signed;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static char epsilon() throw()
      { return 0; }
      static char round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static char infinity() throw()
      { return char(); }
      static char quiet_NaN() throw()
      { return char(); }
      static char signaling_NaN() throw()
      { return char(); }
      static char denorm_min() throw()
      { return static_cast<char>(0); }

      static const bool is_iec559 = false;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_char_min
#undef __glibcpp_char_max  
#undef __glibcpp_char_digits
#undef __glibcpp_char_digits10
#undef __glibcpp_char_is_signed



  template<>
    struct numeric_limits<signed char>
    {
      static const bool is_specialized = true;

      static signed char min() throw()
      { return __glibcpp_signed_char_min; }
      static signed char max() throw()
      { return __glibcpp_signed_char_max; }

      static const int digits = __glibcpp_signed_char_digits;
      static const int digits10 = __glibcpp_signed_char_digits10;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static signed char epsilon() throw()
      { return 0; }
      static signed char round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static signed char infinity() throw()
      { return static_cast<signed char>(0); }
      static signed char quiet_NaN() throw()
      { return static_cast<signed char>(0); }
      static signed char signaling_NaN() throw()
      { return static_cast<signed char>(0); }
      static signed char denorm_min() throw()
      { return static_cast<signed char>(0); }

      static const bool is_iec559 = false;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_signed_char_min
#undef __glibcpp_signed_char_max
#undef __glibcpp_signed_char_digits
#undef __glibcpp_signed_char_digits10

  template<>
    struct numeric_limits<unsigned char>
    {
      static const bool is_specialized = true;

      static unsigned char min() throw()
      { return 0; }
      static unsigned char max() throw()
      { return __glibcpp_unsigned_char_max; }

      static const int digits = __glibcpp_unsigned_char_digits;
      static const int digits10 = __glibcpp_unsigned_char_digits10;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static unsigned char epsilon() throw()
      { return 0; }
      static unsigned char round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static unsigned char infinity() throw()
      { return static_cast<unsigned char>(0); }
      static unsigned char quiet_NaN() throw()
      { return static_cast<unsigned char>(0); }
      static unsigned char signaling_NaN() throw()
      { return static_cast<unsigned char>(0); }
      static unsigned char denorm_min() throw()
      { return static_cast<unsigned char>(0); }

      static const bool is_iec559 = false;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_unsigned_char_max
#undef __glibcpp_unsigned_char_digits
#undef __glibcpp_unsigned_char_digits10

  template<>
    struct numeric_limits<wchar_t>
    {
      static const bool is_specialized = true;

      static wchar_t min() throw()
      { return __glibcpp_wchar_t_min; }
      static wchar_t max() throw()
      { return __glibcpp_wchar_t_max; }

      static const int digits = __glibcpp_wchar_t_digits;
      static const int digits10 = __glibcpp_wchar_t_digits10;
      static const bool is_signed = __glibcpp_wchar_t_is_signed;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static wchar_t epsilon() throw()
      { return 0; }
      static wchar_t round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static wchar_t infinity() throw()
      { return wchar_t(); }
      static wchar_t quiet_NaN() throw()
      { return wchar_t(); }
      static wchar_t signaling_NaN() throw()
      { return wchar_t(); }
      static wchar_t denorm_min() throw()
      { return wchar_t(); }

      static const bool is_iec559 = false;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_wchar_t_min
#undef __glibcpp_wchar_t_max
#undef __glibcpp_wchar_t_digits
#undef __glibcpp_wchar_t_digits10  
#undef __glibcpp_wchar_t_is_signed
  
  template<>
    struct numeric_limits<short>
    {
      static const bool is_specialized = true;

      static short min() throw()
      { return __glibcpp_signed_short_min; }
      static short max() throw()
      { return __glibcpp_signed_short_max; }

      static const int digits = __glibcpp_signed_short_digits;
      static const int digits10 = __glibcpp_signed_short_digits10;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static short epsilon() throw()
      { return 0; }
      static short round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static short infinity() throw()
      { return short(); }
      static short quiet_NaN() throw()
      { return short(); }
      static short signaling_NaN() throw()
      { return short(); }
      static short denorm_min() throw()
      { return short(); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_signed_short_min
#undef __glibcpp_signed_short_max
#undef __glibcpp_signed_short_digits
#undef __glibcpp_signed_short_digits10
  
  template<>
    struct numeric_limits<unsigned short>
    {
      static const bool is_specialized = true;

      static unsigned short min() throw()
      { return 0; }
      static unsigned short max() throw()
      { return __glibcpp_unsigned_short_max; }

      static const int digits = __glibcpp_unsigned_short_digits;
      static const int digits10 = __glibcpp_unsigned_short_digits10;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static unsigned short epsilon() throw()
      { return 0; }
      static unsigned short round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static unsigned short infinity() throw()
      { return static_cast<unsigned short>(0); }
      static unsigned short quiet_NaN() throw()
      { return static_cast<unsigned short>(0); }
      static unsigned short signaling_NaN() throw()
      { return static_cast<unsigned short>(0); }
      static unsigned short denorm_min() throw()
      { return static_cast<unsigned short>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_unsigned_short_max
#undef __glibcpp_unsigned_short_digits
#undef __glibcpp_unsigned_short_digits10
  
  template<>
    struct numeric_limits<int>
    {
      static const bool is_specialized = true;

      static int min() throw()
      { return __glibcpp_signed_int_min; }
      static int max() throw()
      { return __glibcpp_signed_int_max; }

      static const int digits = __glibcpp_signed_int_digits;
      static const int digits10 = __glibcpp_signed_int_digits10;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static int epsilon() throw()
      { return 0; }
      static int round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static int infinity() throw()
      { return static_cast<int>(0); }
      static int quiet_NaN() throw()
      { return static_cast<int>(0); }
      static int signaling_NaN() throw()
      { return static_cast<int>(0); }
      static int denorm_min() throw()
      { return static_cast<int>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_signed_int_min
#undef __glibcpp_signed_int_max
#undef __glibcpp_signed_int_digits
#undef __glibcpp_signed_int_digits10
  
  template<>
    struct numeric_limits<unsigned int>
    {
      static const bool is_specialized = true;

      static unsigned int min() throw()
      { return 0; }
          static unsigned int max() throw()
      { return __glibcpp_unsigned_int_max; }

      static const int digits = __glibcpp_unsigned_int_digits;
      static const int digits10 = __glibcpp_unsigned_int_digits10;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static unsigned int epsilon() throw()
      { return 0; }
      static unsigned int round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static unsigned int infinity() throw()
      { return static_cast<unsigned int>(0); }
      static unsigned int quiet_NaN() throw()
      { return static_cast<unsigned int>(0); }
      static unsigned int signaling_NaN() throw()
      { return static_cast<unsigned int>(0); }
      static unsigned int denorm_min() throw()
      { return static_cast<unsigned int>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_unsigned_int_max
#undef __glibcpp_unsigned_int_digits
#undef __glibcpp_unsigned_int_digits10

  template<>
    struct numeric_limits<long>
    {
      static const bool is_specialized = true;

      static long min() throw()
      { return __glibcpp_signed_long_min; }
      static long max() throw()
      { return __glibcpp_signed_long_max; }

      static const int digits = __glibcpp_signed_long_digits;
      static const int digits10 = __glibcpp_signed_long_digits10;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static long epsilon() throw()
      { return 0; }
      static long round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static long infinity() throw()
      { return static_cast<long>(0); }
      static long quiet_NaN() throw()
      { return static_cast<long>(0); }
      static long signaling_NaN() throw()
      { return static_cast<long>(0); }
      static long denorm_min() throw()
      { return static_cast<long>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_signed_long_min
#undef __glibcpp_signed_long_max
#undef __glibcpp_signed_long_digits
#undef __glibcpp_signed_long_digits10
  
  template<>
    struct numeric_limits<unsigned long>
    {
      static const bool is_specialized = true;

      static unsigned long min() throw()
      { return 0; }
      static unsigned long max() throw()
      { return __glibcpp_unsigned_long_max; }

      static const int digits = __glibcpp_unsigned_long_digits;
      static const int digits10 = __glibcpp_unsigned_long_digits10;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static unsigned long epsilon() throw()
      { return 0; }
      static unsigned long round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static unsigned long infinity() throw()
      { return static_cast<unsigned long>(0); }
      static unsigned long quiet_NaN() throw()
      { return static_cast<unsigned long>(0); }
      static unsigned long signaling_NaN() throw()
      { return static_cast<unsigned long>(0); }
      static unsigned long denorm_min() throw()
      { return static_cast<unsigned long>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_unsigned_long_max
#undef __glibcpp_unsigned_long_digits
#undef __glibcpp_unsigned_long_digits10

  template<>
    struct numeric_limits<long long>
    {
      static const bool is_specialized = true;
      
      static long long min() throw()
      { return __glibcpp_signed_long_long_min; }
      static long long max() throw()
      { return __glibcpp_signed_long_long_max; }
      
      static const int digits = __glibcpp_signed_long_long_digits;
      static const int digits10 = __glibcpp_signed_long_long_digits10;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static long long epsilon() throw()
      { return 0; }
      static long long round_error() throw()
      { return 0; }
      
      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;
      
      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;
      
      static long long infinity() throw()
      { return static_cast<long long>(0); }
      static long long quiet_NaN() throw()
      { return static_cast<long long>(0); }
      static long long signaling_NaN() throw()
      { return static_cast<long long>(0); }
      static long long denorm_min() throw()
      { return static_cast<long long>(0); }
      
      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_signed_long_long_min
#undef __glibcpp_signed_long_long_max
#undef __glibcpp_signed_long_long_digits
#undef __glibcpp_signed_long_long_digits10
  
  template<>
    struct numeric_limits<unsigned long long>
    {
      static const bool is_specialized = true;

      static unsigned long long min() throw()
      { return 0; }
      static unsigned long long max() throw()
      { return __glibcpp_unsigned_long_long_max; }

      static const int digits = __glibcpp_unsigned_long_long_digits;
      static const int digits10 = __glibcpp_unsigned_long_long_digits10;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static unsigned long long epsilon() throw()
      { return 0; }
      static unsigned long long round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static unsigned long long infinity() throw()
      { return static_cast<unsigned long long>(0); }
      static unsigned long long quiet_NaN() throw()
      { return static_cast<unsigned long long>(0); }
      static unsigned long long signaling_NaN() throw()
      { return static_cast<unsigned long long>(0); }
      static unsigned long long denorm_min() throw()
      { return static_cast<unsigned long long>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = __glibcpp_integral_traps;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

#undef __glibcpp_unsigned_long_long_max
#undef __glibcpp_unsigned_long_long_digits
#undef __glibcpp_unsigned_long_long_digits10

  template<>
    struct numeric_limits<float>
    {
      static const bool is_specialized = true;

      static float min() throw()
      { return __FLT_MIN__; }
      static float max() throw()
      { return __FLT_MAX__; }

      static const int digits = __FLT_MANT_DIG__;
      static const int digits10 = __FLT_DIG__;
      static const bool is_signed = true;
      static const bool is_integer = false;
      static const bool is_exact = false;
      static const int radix = __FLT_RADIX__;
      static float epsilon() throw()
      { return __FLT_EPSILON__; }
      static float round_error() throw()
      { return 0.5F; }

      static const int min_exponent = __FLT_MIN_EXP__;
      static const int min_exponent10 = __FLT_MIN_10_EXP__;
      static const int max_exponent = __FLT_MAX_EXP__;
      static const int max_exponent10 = __FLT_MAX_10_EXP__;

      static const bool has_infinity
	= __builtin_huge_valf () / 2 == __builtin_huge_valf ();
      static const bool has_quiet_NaN
	= __builtin_nanf ("") != __builtin_nanf ("");
      static const bool has_signaling_NaN = has_quiet_NaN;
      static const float_denorm_style has_denorm
	= __FLT_DENORM_MIN__ ? denorm_present : denorm_absent;
      static const bool has_denorm_loss = __glibcpp_float_has_denorm_loss;

      static float infinity() throw()
      { return __builtin_huge_valf (); }
      static float quiet_NaN() throw()
      { return __builtin_nanf (""); }
      static float signaling_NaN() throw()
      { return __builtin_nansf (""); }
      static float denorm_min() throw()
      { return __FLT_DENORM_MIN__; }

      static const bool is_iec559 = has_infinity && has_quiet_NaN;
      static const bool is_bounded = true;
      static const bool is_modulo = __glibcpp_float_is_modulo;

      static const bool traps = __glibcpp_float_traps;
      static const bool tinyness_before = __glibcpp_float_tinyness_before;
      static const float_round_style round_style = round_to_nearest;
    };

#undef __glibcpp_float_has_denorm_loss
#undef __glibcpp_float_is_modulo
#undef __glibcpp_float_traps
#undef __glibcpp_float_tinyness_before

  template<>
    struct numeric_limits<double>
    {
      static const bool is_specialized = true;

      static double min() throw()
      { return __DBL_MIN__; }
      static double max() throw()
      { return __DBL_MAX__; }

      static const int digits = __DBL_MANT_DIG__;
      static const int digits10 = __DBL_DIG__;
      static const bool is_signed = true;
      static const bool is_integer = false;
      static const bool is_exact = false;
      static const int radix = __FLT_RADIX__;
      static double epsilon() throw()
      { return __DBL_EPSILON__; }
      static double round_error() throw()
      { return 0.5; }

      static const int min_exponent = __DBL_MIN_EXP__;
      static const int min_exponent10 = __DBL_MIN_10_EXP__;
      static const int max_exponent = __DBL_MAX_EXP__;
      static const int max_exponent10 = __DBL_MAX_10_EXP__;

      static const bool has_infinity
	= __builtin_huge_val () / 2 == __builtin_huge_val ();
      static const bool has_quiet_NaN
	= __builtin_nan ("") != __builtin_nan ("");
      static const bool has_signaling_NaN = has_quiet_NaN;
      static const float_denorm_style has_denorm
	= __DBL_DENORM_MIN__ ? denorm_present : denorm_absent;
      static const bool has_denorm_loss = __glibcpp_double_has_denorm_loss;

      static double infinity() throw()
      { return __builtin_huge_val(); }
      static double quiet_NaN() throw()
      { return __builtin_nan (""); }
      static double signaling_NaN() throw()
      { return __builtin_nans (""); }
      static double denorm_min() throw()
      { return __DBL_DENORM_MIN__; }

      static const bool is_iec559 = has_infinity && has_quiet_NaN;
      static const bool is_bounded = true;
      static const bool is_modulo = __glibcpp_double_is_modulo;

      static const bool traps = __glibcpp_double_traps;
      static const bool tinyness_before = __glibcpp_double_tinyness_before;
      static const float_round_style round_style = round_to_nearest;
    };

#undef __glibcpp_double_has_denorm_loss
#undef __glibcpp_double_is_modulo
#undef __glibcpp_double_traps
#undef __glibcpp_double_tinyness_before
  
  
  template<>
    struct numeric_limits<long double>
    {
      static const bool is_specialized = true;

      static long double min() throw()
      { return __LDBL_MIN__; }
      static long double max() throw()
      { return __LDBL_MAX__; }

      static const int digits = __LDBL_MANT_DIG__;
      static const int digits10 = __LDBL_DIG__;
      static const bool is_signed = true;
      static const bool is_integer = false;
      static const bool is_exact = false;
      static const int radix = __FLT_RADIX__;
      static long double epsilon() throw()
      { return __LDBL_EPSILON__; }
      static long double round_error() throw()
      { return 0.5L; }

      static const int min_exponent = __LDBL_MIN_EXP__;
      static const int min_exponent10 = __LDBL_MIN_10_EXP__;
      static const int max_exponent = __LDBL_MAX_EXP__;
      static const int max_exponent10 = __LDBL_MAX_10_EXP__;

      static const bool has_infinity
	= __builtin_huge_vall () / 2 == __builtin_huge_vall ();
      static const bool has_quiet_NaN
	= __builtin_nanl ("") != __builtin_nanl ("");
      static const bool has_signaling_NaN = has_quiet_NaN;
      static const float_denorm_style has_denorm
	= __LDBL_DENORM_MIN__ ? denorm_present : denorm_absent;
      static const bool has_denorm_loss
	= __glibcpp_long_double_has_denorm_loss;

      static long double infinity() throw()
      { return __builtin_huge_vall (); } 
      static long double quiet_NaN() throw()
      { return __builtin_nanl (""); }
      static long double signaling_NaN() throw()
      { return __builtin_nansl (""); }
      static long double denorm_min() throw()
      { return __LDBL_DENORM_MIN__; }

      static const bool is_iec559 = has_infinity && has_quiet_NaN;
      static const bool is_bounded = true;
      static const bool is_modulo = __glibcpp_long_double_is_modulo;

      static const bool traps = __glibcpp_long_double_traps; 
      static const bool tinyness_before = __glibcpp_long_double_tinyness_before;
      static const float_round_style round_style = round_to_nearest;
    };

#undef __glibcpp_long_double_has_denorm_loss
#undef __glibcpp_long_double_is_modulo
#undef __glibcpp_long_double_traps
#undef __glibcpp_long_double_tinyness_before

} // namespace std

#endif // _CPP_NUMERIC_LIMITS
