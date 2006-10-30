/* Test the `vget_lowp16' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vget_lowp16 (void)
{
  poly16x4_t out_poly16x4_t;
  poly16x8_t arg0_poly16x8_t;

  out_poly16x4_t = vget_low_p16 (arg0_poly16x8_t);
}

/* { dg-final { scan-assembler "vmov\[ 	\]+\[dD\]\[0-9\]+, \[dD\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
