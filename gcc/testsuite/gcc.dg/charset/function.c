/* { dg-do compile }
   { dg-require-iconv "IBM-1047" }
   { dg-final { scan-assembler-not "\"foobar\"" } } */

const char *str;

void foobar (void)
{
  str = __FUNCTION__;
}
