/* PR tree-optimization/49039 */
/* { dg-do compile } */
/* { dg-options "-O2 -fdump-tree-evrp" } */

extern void bar (void);

void
foo (unsigned int x, unsigned int y)
{
  unsigned int minv, maxv;
  if (x >= 3 && x <= 6)
    return;
  if (y >= 5 && y <= 8)
    return;
  minv = x < y ? x : y;
  maxv = x > y ? x : y;
  if (minv == 5)
    bar ();
  if (minv == 6)
    bar ();
  if (maxv == 5)
    bar ();
  if (maxv == 6)
    bar ();
}

/* { dg-final { scan-tree-dump-not "== 5" "evrp" } } */
/* { dg-final { scan-tree-dump-not "== 6" "evrp" } } */
