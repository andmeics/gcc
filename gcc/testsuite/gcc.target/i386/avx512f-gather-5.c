/* { dg-do compile } */
/* { dg-options "-O3 -mavx512f -mtune=knl" } */

#include "avx512f-gather-4.c"

/* { dg-final { scan-assembler-times "gather\[^\n\]*zmm\[0-9\]+\{%k\[1-7\]\}(?:\n|\[ \\t\]+#)" 2 } } */
/* { dg-final { scan-assembler-not "gather\[^\n\]*ymm\[^\n\]*ymm" } } */
/* { dg-final { scan-assembler-not "gather\[^\n\]*xmm\[^\n\]*ymm" } } */
/* { dg-final { scan-assembler-not "gather\[^\n\]*ymm\[^\n\]*xmm" } } */
/* { dg-final { scan-assembler-not "gather\[^\n\]*xmm\[^\n\]*xmm" } } */
