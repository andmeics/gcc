/* { dg-do compile { target { ! { nvptx*-*-* visium-*-* } } } } */
/* { dg-options "-O2 -fpatchable-function-entry=65536,1" } */
/* { dg-additional-options "-fno-pie" { target sparc*-*-* } } */
/* { dg-error "invalid arguments for '-fpatchable-function-entry'" "" { target *-*-* } 0 } */

void
foo (void)
{
}
