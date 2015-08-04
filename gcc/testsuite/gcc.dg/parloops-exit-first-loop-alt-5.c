/* { dg-do compile } */
/* { dg-require-effective-target pthread } */
/* { dg-options "-O2 -ftree-parallelize-loops=2 -fdump-tree-parloops-details" } */

/* Variable bound, vector addition, unsigned loop counter, unsigned bound.  */

void
f (unsigned int n, unsigned int *__restrict__ a, unsigned int *__restrict__ b,
   unsigned int *__restrict__ c)
{
  unsigned int i;

  for (i = 0; i < n; ++i)
    c[i] = a[i] + b[i];
}

/* { dg-final { scan-tree-dump-times "alternative exit-first loop transform succeeded" 1 "parloops" } } */
