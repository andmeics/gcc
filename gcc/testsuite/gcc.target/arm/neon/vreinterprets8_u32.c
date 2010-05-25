/* Test the `vreinterprets8_u32' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0" } */
/* { dg-add-options arm_neon } */

#include "arm_neon.h"

void test_vreinterprets8_u32 (void)
{
  int8x8_t out_int8x8_t;
  uint32x2_t arg0_uint32x2_t;

  out_int8x8_t = vreinterpret_s8_u32 (arg0_uint32x2_t);
}

/* { dg-final { cleanup-saved-temps } } */
