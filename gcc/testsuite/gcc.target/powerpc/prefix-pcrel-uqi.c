/* { dg-do compile } */
/* { dg-require-effective-target powerpc_pcrel } */
/* { dg-options "-O2 -mdejagnu-cpu=future" } */

/* Tests for prefixed instructions testing whether pc-relative prefixed
   instructions are generated for the unsigned char type.  */

#define TYPE unsigned char

#include "prefix-pcrel.h"

/* { dg-final { scan-assembler-times {[@]pcrel}  4 } } */
/* { dg-final { scan-assembler-times {\mplbz\M}  2 } } */
/* { dg-final { scan-assembler-times {\mpstb\M}  2 } } */
