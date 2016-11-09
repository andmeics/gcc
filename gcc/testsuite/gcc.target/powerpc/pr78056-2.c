/* { dg-do compile { target { powerpc*-*-* } } } */
/* { dg-skip-if "do not override -mcpu" { powerpc*-*-* } { "-mcpu=*" } { "-mcpu=power8" } } */
/* { dg-skip-if "" { powerpc_p9vector_ok } } */
/* { dg-skip-if "" { powerpc*-*-aix* } } */
/* { dg-options "-mcpu=power8" } */

/* This test should succeed on both 32- and 64-bit configurations.  */
#include <altivec.h>

/* Though the command line specifies power8 target, this function is
   to support power9. Expect an error message here because this target
   does not support power9.  */
__attribute__((target("cpu=power9"))) /* { dg-warning "lacks power9 support" } */
int get_random ()
{
  return __builtin_darn_32 (); /* { dg-warning "implicit declaration" } */
}

