// PERMUTE_ARGS:
/*
TEST_OUTPUT:
---
fail_compilation/fail19912d.d(8): Error: enum `fail19912d.object` conflicts with import `fail19912d.object` at fail_compilation/fail19912d.d
---
*/
enum object { }
void fun(string) { }
