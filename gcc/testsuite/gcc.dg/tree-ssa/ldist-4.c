/* { dg-do compile } */ 
/* { dg-options "-O2 -ftree-loop-distribution -fdump-tree-ldist-all" } */

int loop1 (int k)
{
  unsigned int i;
  unsigned int j;
  int a[100], b[100][100];

  a[0] = k;
  for (i = 1; i < 100; i ++)
    {
      for (j = 0; j < 100; j++)
	{
	  a[j] = k * i;
	  b[i][j] = a[j-1] + k;
	}
    }

  return b[100-1][0];
}

/* { dg-final { scan-tree-dump-times "distributed: split to 2 loops" 1 "ldist" } } */
/* { dg-final { cleanup-tree-dump "ldist" } } */
