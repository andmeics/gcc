/* Check that eliminable compare-instructions are eliminated. */
/* { dg-do compile } */
/* { dg-options "-O2" } */
/* { dg-final { scan-assembler-not "\tcmp|\ttest" } } */

#define op |
#include "pr93372-16.c"
