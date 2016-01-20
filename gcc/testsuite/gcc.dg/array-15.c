/* PR c/69262 */
/* { dg-do compile } */
/* { dg-options "-std=c11 -pedantic-errors" } */

struct S
{
  int a[1][][2]; /* { dg-error "array type has incomplete element type" } */
  /* { dg-message "declaration of .a. as multidimensional array must have bounds" "" { target *-*-* } 7 } */
};

struct R
{
  int i;
  int a[][]; /* { dg-error "array type has incomplete element type" } */
  /* { dg-message "declaration of .a. as multidimensional array must have bounds" "" { target *-*-* } 14 } */
};

typedef int T[];
typedef int U[][]; /* { dg-error "array type has incomplete element type" } */
/* { dg-message "declaration of .U. as multidimensional array must have bounds" "" { target *-*-* } 19 } */

int x[][]; /* { dg-error "array type has incomplete element type" } */
/* { dg-message "declaration of .x. as multidimensional array must have bounds" "" { target *-*-* } 22 } */

struct N;

void
fn1 (int z[][]) /* { dg-error "array type has incomplete element type" } */
/* { dg-message "declaration of .z. as multidimensional array must have bounds" "" { target *-*-* } 28 } */
{
  int a[1][][2]; /* { dg-error "array type has incomplete element type" } */
  /* { dg-message "declaration of .a. as multidimensional array must have bounds" "" { target *-*-* } 31 } */
  /* OK */
  int b[3][2][1];
  int c[1][2][3][]; /* { dg-error "array type has incomplete element type" } */
  /* { dg-message "declaration of .c. as multidimensional array must have bounds" "" { target *-*-* } 35 } */
  T d[1]; /* { dg-error "array type has incomplete element type" } */
  /* { dg-message "declaration of .d. as multidimensional array must have bounds" "" { target *-*-* } 37 } */
  T e[]; /* { dg-error "array type has incomplete element type" } */
  /* { dg-message "declaration of .e. as multidimensional array must have bounds" "" { target *-*-* } 39 } */

  /* This array has incomplete element type, but is not multidimensional.  */
  struct N f[1]; /* { dg-error "array type has incomplete element type" } */
  /* { dg-bogus "declaration of .f. as multidimensional array must have bounds" "" { target *-*-* } 43 } */
}

void fn2 (int [][]); /* { dg-error "array type has incomplete element type" } */
/* { dg-message "declaration of multidimensional array must have bounds" "" { target *-*-* } 47 } */
/* OK */
void fn3 (int [][*]);
void fn4 (T []); /* { dg-error "array type has incomplete element type" } */
/* { dg-message "declaration of multidimensional array must have bounds" "" { target *-*-* } 51 } */
