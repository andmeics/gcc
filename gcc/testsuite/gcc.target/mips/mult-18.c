/* { dg-options "-O -mgp32 (-mips16)" } */
/* { dg-final { scan-assembler "\tmultu?\t" } } */
/* { dg-final { scan-assembler "\tmflo\t" } } */
/* { dg-final { scan-assembler-not "\tmfhi\t" } } */

typedef int SI __attribute__((mode(SI)));

MIPS16 SI
f (SI x, SI y)
{
  return x * y;
}
