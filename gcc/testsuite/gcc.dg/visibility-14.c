/* Test that called external functions are marked. */
/* { dg-do compile } */
/* { dg-require-visibility "" } */
/* { dg-final { scan-hidden "foo" } } */

extern void foo(void) __attribute__ ((visibility ("hidden")));
int f () {
 foo();
}
