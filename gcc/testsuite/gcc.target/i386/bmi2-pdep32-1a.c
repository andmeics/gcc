/* { dg-do compile } */
/* { dg-options "-mbmi2 -O2 -dp" } */

#include "bmi2-pdep32-1.c"

/* { dg-final { scan-assembler "bmi2_pdep_si3" } } */
