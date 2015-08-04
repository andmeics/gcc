/* { dg-do compile } */
/* { dg-options "-std=gnu89 -Os -fprofile-arcs -fsanitize=kernel-address" } */

char *a;
int d;

static int
fn1 (int b, int c)
{
  while (a)
    if (*a)
      return -126;
  if (b)
    return -12;
  if (c == -12)
    return c;
}

void
fn2 (int b, int c)
{
  for (;;)
    {
      d = fn1 (b, c);
      switch (d)
        {
        case -126:
          continue;
        default:
          return;
        }
    }
}
