/* { dg-do compile } */
/* { dg-require-effective-target powerpc_prefixed_addr_ok } */
/* { dg-options "-O2 -mdejagnu-cpu=future" } */

/* Tests for prefixed instructions testing whether we can generate a prefixed
   load/store instruction that has a 34-bit offset.  */

#define TYPE double

#include "prefix-large.h"

/* { dg-final { scan-assembler-times {\mplfd\M}  2 } } */
/* { dg-final { scan-assembler-times {\mpstfd\M} 2 } } */
