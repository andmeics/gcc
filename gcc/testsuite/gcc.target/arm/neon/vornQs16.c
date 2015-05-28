/* Test the `vornQs16' ARM Neon intrinsic.  */
/* This file was autogenerated by neon-testgen.  */

/* { dg-do assemble } */
/* { dg-require-effective-target arm_neon_ok } */
/* { dg-options "-save-temps -O2" } */
/* { dg-add-options arm_neon } */

#include "arm_neon.h"

int16x8_t out_int16x8_t;
int16x8_t arg0_int16x8_t;
int16x8_t arg1_int16x8_t;
void test_vornQs16 (void)
{

  out_int16x8_t = vornq_s16 (arg0_int16x8_t, arg1_int16x8_t);
}

/* { dg-final { scan-assembler "vorn\[ 	\]+\[qQ\]\[0-9\]+, \[qQ\]\[0-9\]+, \[qQ\]\[0-9\]+!?\(\[ 	\]+@\[a-zA-Z0-9 \]+\)?\n" } } */
/* { dg-final { cleanup-saved-temps } } */
