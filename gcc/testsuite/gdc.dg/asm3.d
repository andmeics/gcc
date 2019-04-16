// { dg-do compile }
// { dg-options "-Wall -Wdeprecated -Werror" }
module asm3;

void test1() nothrow    // { dg-error "nothrow function 'asm3.test1' may throw" }
{
    asm { }             // { dg-error "asm statement is assumed to throw - mark it with 'nothrow' if it does not" }
}

void test2() pure
{
    asm { }             // { dg-error "asm statement is assumed to be impure - mark it with 'pure' if it is not" }
}

void test3() @nogc
{
    asm { }             // { dg-error "asm statement is assumed to use the GC - mark it with '@nogc' if it does not" }
}

void test4() @safe
{
    asm { }             // { dg-error "asm statement is assumed to be @system - mark it with '@trusted' if it is not" }
}

