/* Test the `vmlsls8' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vmlsls8 (void)
{
  int16x8_t out_int16x8_t;
  int16x8_t arg0_int16x8_t;
  int8x8_t arg1_int8x8_t;
  int8x8_t arg2_int8x8_t;

  out_int16x8_t = vmlsl_s8 (arg0_int16x8_t, arg1_int8x8_t, arg2_int8x8_t);
}

/* { dg-final { scan-assembler "vmlsl\.s8\[ 	\]+\[qQ\]\[0-9\]+, \[dD\]\[0-9\]+, \[dD\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
