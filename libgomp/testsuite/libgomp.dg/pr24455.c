/* { dg-do run } */
/* { dg-additional-sources pr24455-1.c } */

extern void abort (void);

extern int i;
#pragma omp threadprivate(i)

int main()
{
  i = 0;

#pragma omp parallel default(none) num_threads(10)
    {
      i++;
#pragma omp barrier
      if (i != 1)
	abort ();
    }

    return 0;
}
