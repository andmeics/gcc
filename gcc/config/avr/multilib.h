/*
   Auto-generated C header
   Generated by    : ./gcc/config/avr/genmultilib.awk
   Generated from  : ./gcc/config/avr/avr-mcus.def
   Used by         : ./gcc/gcc.c via tm.h
   Purpose         : Override multilib_raw[] from multilib.h
*/
/*
   Copyright (C) 2011 Free Software Foundation, Inc.
  
   This file is part of GCC.
  
   GCC is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 3, or (at your option) any later
   version.
  
   GCC is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
   for more details.
  
   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.
*/
#if defined NULL && !defined AVR_MULTILIB_H
#define AVR_MULTILIB_H
static const char* const avr_multilib_raw[] = {
  "tiny-stack mmcu=at90s2313;",
  "tiny-stack mmcu=at90s2323;",
  "tiny-stack mmcu=at90s2333;",
  "tiny-stack mmcu=at90s2343;",
  "tiny-stack mmcu=attiny22;",
  "tiny-stack mmcu=attiny26;",
  "tiny-stack mmcu=at90s4433;",
  "avr25/tiny-stack mmcu=attiny13;",
  "avr25/tiny-stack mmcu=attiny13a;",
  "avr25/tiny-stack mmcu=attiny2313;",
  "avr25/tiny-stack mmcu=attiny2313a;",
  "avr25/tiny-stack mmcu=attiny24;",
  "avr25/tiny-stack mmcu=attiny24a;",
  "avr25/tiny-stack mmcu=attiny25;",
  "avr25/tiny-stack mmcu=attiny261;",
  "avr25/tiny-stack mmcu=attiny261a;",

  ". !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7 !mtiny-stack !mmcu=at90s2313 !mmcu=at90s2323 !mmcu=at90s2333 !mmcu=at90s2343 !mmcu=attiny22 !mmcu=attiny26 !mmcu=at90s4433 !mmcu=attiny13 !mmcu=attiny13a !mmcu=attiny2313 !mmcu=attiny2313a !mmcu=attiny24 !mmcu=attiny24a !mmcu=attiny25 !mmcu=attiny261 !mmcu=attiny261a;",
  "avr2 mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7 !mtiny-stack;",
  "avr25 !mmcu=avr2 mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7 !mtiny-stack;",
  "avr3 !mmcu=avr2 !mmcu=avr25 mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7;",
  "avr31 !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7;",
  "avr35 !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7;",
  "avr4 !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7;",
  "avr5 !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7;",
  "avr51 !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7;",
  "avr6 !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7;",
  "avrxmega2 !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7;",
  "avrxmega4 !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7;",
  "avrxmega5 !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7;",
  "avrxmega6 !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 mmcu=avrxmega6 !mmcu=avrxmega7;",
  "avrxmega7 !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 mmcu=avrxmega7;",
  "tiny-stack !mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7 mtiny-stack;",
  "avr2/tiny-stack mmcu=avr2 !mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7 mtiny-stack;",
  "avr25/tiny-stack !mmcu=avr2 mmcu=avr25 !mmcu=avr3 !mmcu=avr31 !mmcu=avr35 !mmcu=avr4 !mmcu=avr5 !mmcu=avr51 !mmcu=avr6 !mmcu=avrxmega2 !mmcu=avrxmega4 !mmcu=avrxmega5 !mmcu=avrxmega6 !mmcu=avrxmega7 mtiny-stack;",

  NULL
};
#undef  multilib_raw
#define multilib_raw avr_multilib_raw
#endif /* AVR_MULTILIB_H */
