/* Test __atomic routines for existence and proper execution on 1 byte
   values with each valid memory model.  */
/* { dg-do run } */
/* { dg-require-effective-target sync_char_short } */

/* Test the execution of the __atomic_exchange_n builtin for a char.  */

extern void abort(void);

char v, count, ret;

int
main ()
{
  v = 0;
  count = 0;

  if (__atomic_exchange_n (&v, count + 1, __ATOMIC_RELAXED) != count)
    abort ();
  count++;

  if (__atomic_exchange_n (&v, count + 1, __ATOMIC_ACQUIRE) != count)
    abort ();
  count++;

  if (__atomic_exchange_n (&v, count + 1, __ATOMIC_RELEASE) != count)
    abort ();
  count++;

  if (__atomic_exchange_n (&v, count + 1, __ATOMIC_ACQ_REL) != count)
    abort ();
  count++;

  if (__atomic_exchange_n (&v, count + 1, __ATOMIC_SEQ_CST) != count)
    abort ();
  count++;

  /* Now test the generic version.  */

  count++;

  __atomic_exchange (&v, &count, &ret, __ATOMIC_RELAXED);
  if (ret != count - 1 || v != count)
    abort ();
  count++;

  __atomic_exchange (&v, &count, &ret, __ATOMIC_ACQUIRE);
  if (ret != count - 1 || v != count)
    abort ();
  count++;

  __atomic_exchange (&v, &count, &ret, __ATOMIC_RELEASE);
  if (ret != count - 1 || v != count)
    abort ();
  count++;

  __atomic_exchange (&v, &count, &ret, __ATOMIC_ACQ_REL);
  if (ret != count - 1 || v != count)
    abort ();
  count++;

  __atomic_exchange (&v, &count, &ret, __ATOMIC_SEQ_CST);
  if (ret != count - 1 || v != count)
    abort ();
  count++;

  return 0;
}
