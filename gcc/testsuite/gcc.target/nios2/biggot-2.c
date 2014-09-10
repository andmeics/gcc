/* Check that a program that requires large-GOT support builds and
   executes without error.  This program defines a very large number
   of leaf functions; compiled with -fPIC, they all require GOT
   entries, which will overflow the range addressible by 16-bit -fpic
   offsets by about a factor of 2.  */

/* { dg-options "-fPIC" } */
/* { dg-do run { target nios2-*-linux-gnu } } */

extern void abort (void);

static int n = 0;

void
doit (int m)
{
  if (m != n)
    abort ();
  n++;
}

#define X(N) \
  void f_##N (void) { doit (0x##N); }

#define F(N) f_##N ();

#define A(N) \
  X(N##0) X(N##1) X(N##2) X(N##3) X(N##4) X(N##5) X(N##6) X(N##7) \
  X(N##8) X(N##9) X(N##a) X(N##b) X(N##c) X(N##d) X(N##e) X(N##f) \
  void f_##N (void) { \
    F(N##0) F(N##1) F(N##2) F(N##3) F(N##4) F(N##5) F(N##6) F(N##7) \
    F(N##8) F(N##9) F(N##a) F(N##b) F(N##c) F(N##d) F(N##e) F(N##f) \
    }

#define B(N) \
  A(N##0) A(N##1) A(N##2) A(N##3) A(N##4) A(N##5) A(N##6) A(N##7) \
  A(N##8) A(N##9) A(N##a) A(N##b) A(N##c) A(N##d) A(N##e) A(N##f) \
  void f_##N (void) { \
    F(N##0) F(N##1) F(N##2) F(N##3) F(N##4) F(N##5) F(N##6) F(N##7) \
    F(N##8) F(N##9) F(N##a) F(N##b) F(N##c) F(N##d) F(N##e) F(N##f) \
    }

#define C(N) \
  B(N##0) B(N##1) B(N##2) B(N##3) B(N##4) B(N##5) B(N##6) B(N##7) \
  B(N##8) B(N##9) B(N##a) B(N##b) B(N##c) B(N##d) B(N##e) B(N##f) \
  void f_##N (void) { \
    F(N##0) F(N##1) F(N##2) F(N##3) F(N##4) F(N##5) F(N##6) F(N##7) \
    F(N##8) F(N##9) F(N##a) F(N##b) F(N##c) F(N##d) F(N##e) F(N##f) \
    }

#define D(N) \
  C(N##0) C(N##1) C(N##2) C(N##3) C(N##4) C(N##5) C(N##6) C(N##7) \
  void f_##N (void) { \
    F(N##0) F(N##1) F(N##2) F(N##3) F(N##4) F(N##5) F(N##6) F(N##7) \
    }

/* This defines 16x16x16x8 leaf functions, requiring something over
   128K of GOT space overall.  */
D(0)

int
main (void)
{
  f_0 ();
  if (n != 16*16*16*8)
    abort ();
  return 0;
}
