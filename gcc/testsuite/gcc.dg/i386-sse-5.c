/* { dg-do compile { target i?86-*-* } } */
/* { dg-forbid-option "-m64" } */
/* { dg-options "-Winline -O2 -march=i386" } */
typedef float v2df __attribute__ ((mode(V2DF)));
v2df p;
q(v2df t)
{			 /* { dg-warning "SSE" "" } */
	p=t;
}
