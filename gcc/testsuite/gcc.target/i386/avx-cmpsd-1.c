/* { dg-do run } */
/* { dg-require-effective-target avx } */
/* { dg-options "-O2 -mavx -std=c99" } */

#define CHECK_H "avx-check.h"
#define TEST avx_test

#include "sse2-cmpsd-1.c"
