/* { dg-do compile } */ 
/* { dg-options "-O1 -fscalar-evolutions -fdump-tree-scev-stats" } */

int 
foo (int *c)
{
  int i = 0;
  int j = 10;
  
  while (1)
    {
      /* This case exercises the number of iterations detector for 
	 {0, +, 1}_1 == {10, +, -1}_1
      */
      if (i == j)
	break;
      
      i++;
      j--;
    }
  
  return j;
}

/* FIXME. */

