/* { dg-do compile } */ 
/* { dg-options "-O1 -fscalar-evolutions -fdump-tree-scev-details -fall-data-deps -fdump-tree-ddall" } */

void foo (int);

int main ()
{
  int c[100][200];
  int a;
  int x;
  
  for (a = 1; a < 50; a++)
    {
      x = a;
      c[x-7][1] = c[x+2][3] + c[x-1][2];
      c[x][2] = c[x+2][3];
    }
  foo (c[12][13]);
}

/* { dg-final { diff-tree-dumps "ddall" } } */
