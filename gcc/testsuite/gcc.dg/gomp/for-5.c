/* { dg-do compile } */
/* { dg-options "-fopenmp -O1 -fdump-tree-ompexp" } */

extern void bar(int);

void foo (int n)
{
  int i;

  #pragma omp for schedule(guided)
  for (i = 0; i < n; ++i)
    bar(i);
}

/* { dg-final { scan-tree-dump-times "GOMP_loop_guided_start" 1 "ompexp" } } */
/* { dg-final { scan-tree-dump-times "GOMP_loop_guided_next" 1 "ompexp" } } */
/* { dg-final { cleanup-tree-dump "ompexp" } } */
