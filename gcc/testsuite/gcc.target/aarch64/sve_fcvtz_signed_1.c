/* { dg-do assemble } */
/* { dg-options "-O3 -march=armv8-a+sve --save-temps" } */

void vfcvtz_32 (signed int *dst, float *src1, int size)
{
  for (int i = 0; i < size; i++)
    dst[i] = (signed int) src1[i];
}

void vfcvtz_64 (signed long *dst, double *src1, int size)
{
  for (int i = 0; i < size; i++)
    dst[i] = (signed long) src1[i];
}

/* { dg-final { scan-assembler-times {\tfcvtzs\tz[0-9]+\.s, p[0-7]/m, z[0-9]+\.s\n} 1 } } */
/* { dg-final { scan-assembler-times {\tfcvtzs\tz[0-9]+\.d, p[0-7]/m, z[0-9]+\.d\n} 1 } } */
