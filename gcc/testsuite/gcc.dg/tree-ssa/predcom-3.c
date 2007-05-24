/* { dg-do compile } */
/* { dg-options "-O2 -fpredictive-commoning -fdump-tree-pcom-details" } */

int a[1000], b[1000];

void test(void)
{
  int i;

  for (i = 1; i < 999; i++)
    b[i] = (a[i + 1] + a[i] + a[i - 1]) / 3;
}

/* Verify that we used 3 temporary variables for the loop.  */
/* { dg-final { scan-tree-dump-times "Unrolling 3 times." 1 "pcom"} } */
/* { dg-final { cleanup-tree-dump "pcom" } } */
