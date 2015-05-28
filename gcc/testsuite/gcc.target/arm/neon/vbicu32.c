/* Test the `vbicu32' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O2" } */
/* { dg-add-options arm_neon } */

#include "arm_neon.h"

uint32x2_t out_uint32x2_t;
uint32x2_t arg0_uint32x2_t;
uint32x2_t arg1_uint32x2_t;
void test_vbicu32 (void)
{

  out_uint32x2_t = vbic_u32 (arg0_uint32x2_t, arg1_uint32x2_t);
}

/* { dg-final { scan-assembler "vbic\[ 	\]+\[dD\]\[0-9\]+, \[dD\]\[0-9\]+, \[dD\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
