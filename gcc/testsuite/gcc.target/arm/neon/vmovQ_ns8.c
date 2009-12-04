/* Test the `vmovQ_ns8' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O0 -mfpu=neon -mfloat-abi=softfp" } */

#include "arm_neon.h"

void test_vmovQ_ns8 (void)
{
  int8x16_t out_int8x16_t;
  int8_t arg0_int8_t;

  out_int8x16_t = vmovq_n_s8 (arg0_int8_t);
}

/* { dg-final { scan-assembler "vdup\.8\[ 	\]+\[qQ\]\[0-9\]+, (\[rR\]\[0-9\]+|\[dD\]\[0-9\]+\\\[\[0-9\]+\\\])!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
