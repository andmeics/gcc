
#ifndef fma_3
#define fma_3

TYPE __attribute__((sseregparm))
test_noneg_add_noneg_add (TYPE a, TYPE b, TYPE c)
{
  return ((a * b) + c) * b + a;
}

TYPE __attribute__((sseregparm))
test_noneg_add_noneg_sub (TYPE a, TYPE b, TYPE c)
{
  return ((a * b) + c) * b - a;
}

TYPE __attribute__((sseregparm))
test_noneg_add_neg_add (TYPE a, TYPE b, TYPE c)
{
  return -((a * b) + c) * b + a;
}

TYPE __attribute__((sseregparm))
test_noneg_add_neg_sub (TYPE a, TYPE b, TYPE c)
{
  return -((a * b) + c) * b - a;
}

TYPE __attribute__((sseregparm))
test_noneg_sub_noneg_add (TYPE a, TYPE b, TYPE c)
{
  return ((a * b) - c) * b + a;
}

TYPE __attribute__((sseregparm))
test_noneg_sub_noneg_sub (TYPE a, TYPE b, TYPE c)
{
  return ((a * b) - c) * b - a;
}

TYPE __attribute__((sseregparm))
test_noneg_sub_neg_add (TYPE a, TYPE b, TYPE c)
{
  return -((a * b) - c) * b + a;
}

TYPE __attribute__((sseregparm))
test_noneg_sub_neg_sub (TYPE a, TYPE b, TYPE c)
{
  return -((a * b) - c) * b - a;
}

TYPE __attribute__((sseregparm))
test_neg_add_noneg_add (TYPE a, TYPE b, TYPE c)
{
  return (-(a * b) + c) * b + a;
}

TYPE __attribute__((sseregparm))
test_neg_add_noneg_sub (TYPE a, TYPE b, TYPE c)
{
  return (-(a * b) + c) * b - a;
}

TYPE __attribute__((sseregparm))
test_neg_add_neg_add (TYPE a, TYPE b, TYPE c)
{
  return -(-(a * b) + c) * b + a;
}

TYPE __attribute__((sseregparm))
test_neg_add_neg_sub (TYPE a, TYPE b, TYPE c)
{
  return -(-(a * b) + c) * b - a;
}

TYPE __attribute__((sseregparm))
test_neg_sub_noneg_add (TYPE a, TYPE b, TYPE c)
{
  return (-(a * b) - c) * b + a;
}

TYPE __attribute__((sseregparm))
test_neg_sub_noneg_sub (TYPE a, TYPE b, TYPE c)
{
  return (-(a * b) - c) * b - a;
}

TYPE __attribute__((sseregparm))
test_neg_sub_neg_add (TYPE a, TYPE b, TYPE c)
{
  return -(-(a * b) - c) * b + a;
}

TYPE __attribute__((sseregparm))
test_neg_sub_neg_sub (TYPE a, TYPE b, TYPE c)
{
  return -(-(a * b) - c) * b - a;
}

#endif
