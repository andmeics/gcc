/* { dg-do compile } */
/* { dg-options "-O2 -mavx -mfpmath=sse" } */
/* { dg-final { scan-assembler "vmaxsd" } } */
/* { dg-final { scan-assembler "vminsd" } } */
double x;
q()
{
  x=x<5?5:x;
}

double x;
q1()
{
  x=x>5?5:x;
}
