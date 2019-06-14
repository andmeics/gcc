/* { dg-do compile { target { powerpc64*-*-* && lp64 } } } */
/* { dg-require-effective-target powerpc_p9vector_ok } */
/* { dg-options "-mdejagnu-cpu=power9 -O2" } */

/* PR target/81348: Compiler died in doing short->float conversion due to using
   the wrong register in a define_split.  Originially it failed with -Og.
   Changes due to PR 90822 meant that -Og does not generate the lxsihzx and
   vextsh2d instructions, but -O2 does.  */

int a;
short b;
float ***c;

void d(void)
{
        int e = 3;

        if (a)
                e = b;

        ***c = e;
}

/* { dg-final { scan-assembler {\mlxsihzx\M}  } } */
/* { dg-final { scan-assembler {\mvextsh2d\M} } } */
