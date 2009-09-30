/* { dg-do run } */
/* { dg-options "-O2 -fdump-tree-eipa_sra-details"  } */

struct bovid
{
  float red;
  int green;
  void *blue;
};

extern int printf (const char *, ...);
extern void abort (void);

static int
__attribute__((noinline))
ox (struct bovid cow)
{
  if (cow.green != 6)
    abort ();

  printf ("green: %f\nblue: %p\nblue again: %p\n", cow.green,
	  cow.blue, cow.blue);
  return 0;
}

int
main (int argc, char *argv[])
{
  struct bovid cow;

  cow.red = 7.4;
  cow.green = 6;
  cow.blue = &cow;

  ox (cow);
  return 0;
}

/* { dg-final { scan-tree-dump "About to replace expr cow.green with ISRA" "eipa_sra"  } } */
/* { dg-final { scan-tree-dump "About to replace expr cow.blue with ISRA" "eipa_sra"  } } */
/* { dg-final { cleanup-tree-dump "eipa_sra" } } */
