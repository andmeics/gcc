/* PR target/7042.  In cris.md the return pattern and its condition
   had a bug uncovered by the combination of saved registers and
   filled delay slot, where the delay-slot insn set the
   return-value register.  Derived from ghostscript-6.52 (GPL)
   by hp@axis.com.  */

typedef struct font_hints_s {
  int axes_swapped;
  int x_inverted, y_inverted;
} font_hints;
typedef struct gs_fixed_point_s {
  long x, y;
} gs_fixed_point;

int
line_hints(const font_hints *fh, const gs_fixed_point *p0,
	   const gs_fixed_point *p1)
{
  long dx = p1->x - p0->x;
  long dy = p1->y - p0->y;
  long adx, ady;
  int xi = fh->x_inverted, yi = fh->y_inverted;
  int hints;
  if (xi)
    dx = -dx;
  if (yi)
    dy = -dy;
  if (fh->axes_swapped) {
    long t = dx;
    int ti = xi;
    dx = dy, xi = yi;
    dy = t, yi = ti;
  }
  adx = dx < 0 ? -dx : dx;
  ady = dy < 0 ? -dy : dy;
  if (dy != 0 && (adx <= ady >> 4)) {
    hints = dy > 0 ? 2 : 1;
    if (xi)
      hints ^= 3;
  } else if (dx != 0 && (ady <= adx >> 4)) {
    hints = dx < 0 ? 8 : 4;
    if (yi)
      hints ^= 12;
  } else
    hints = 0;
  return hints;
}
int main ()
{
  static font_hints fh[] = {{0, 1, 0}, {0, 0, 1}, {0, 0, 0}};
  static gs_fixed_point gsf[]
    = {{0x30000, 0x13958}, {0x30000, 0x18189},
       {0x13958, 0x30000}, {0x18189, 0x30000}};
  if (line_hints (fh, gsf, gsf + 1) != 1
      || line_hints (fh + 1, gsf + 2, gsf + 3) != 8
      || line_hints (fh + 2, gsf + 2, gsf + 3) != 4)
    abort ();
  exit (0);
}
