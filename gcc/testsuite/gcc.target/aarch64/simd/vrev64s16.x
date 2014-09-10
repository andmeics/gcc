extern void abort (void);

int16x4_t
test_vrev64s16 (int16x4_t _arg)
{
  return vrev64_s16 (_arg);
}

int
main (int argc, char **argv)
{
  int i;
  int16x4_t inorder = {1, 2, 3, 4};
  int16x4_t reversed = test_vrev64s16 (inorder);
  int16x4_t expected = {4, 3, 2, 1};

  for (i = 0; i < 4; i++)
    if (reversed[i] != expected[i])
      abort ();
  return 0;
}

