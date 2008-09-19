/* { dg-do compile } */
/* Currently ICEs for IA64, HPPA, MIPS, CRIS, Xtensa and PowerPC; see PR33642.  */
/* { dg-xfail-if "PR33642" { hppa*-*-* mips*-*-* powerpc*-*-linux* cris-*-* crisv32-*-* ia64-*-* xtensa*-*-* } { "*" } { "" } } */
/* Currently ICEs for (x86 && ilp32 && pic).  */
/* { dg-xfail-if "PR33642/36240" { { i?86-*-* x86_64-*-* } && { ilp32 && { ! nonpic } } } { "*" } { "" } } */
/* { dg-prune-output ".*internal compiler error.*" }
/* { dg-options "-frtl-abstract-sequences" } */

int a, b, e;
unsigned char *c;
void foo()
{
  int d = 13;
  b = -1;   
  switch (e) {
    case 1:
      b++; c[b] = (unsigned char)d;
      break;
    case 2:
      b++; c[b] = (unsigned char)d;
      b++; c[b] = (unsigned char)d;
      break;
    case 3:
      b++; c[b] = (unsigned char)d;
      b++; c[b] = (unsigned char)d;
      b++; c[b] = (unsigned char)d;
      break;
    default:
      a = 1;
      b++; c[b] = (unsigned char)d;
      b++; c[b] = (unsigned char)d;
      b++; c[b] = (unsigned char)d;
      b++; c[b] = (unsigned char)d;
  }
}
