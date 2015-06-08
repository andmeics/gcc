/* { dg-do compile { target x86_64-*-linux* } } */
/* { dg-options "-fno-pic -fno-plt" } */

void foo();

int main()
{
  foo();
  return 0;
}

/* { dg-final { scan-assembler "call\[ \t\]\\*.*foo.*@GOTPCREL\\(%rip\\)" } } */ 
