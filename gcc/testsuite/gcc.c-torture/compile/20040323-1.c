/* PR 14694 */
/* { dg-require-alias "" } */

extern unsigned int _rtld_local __attribute__ ((alias ("_rtld_global")));

unsigned int
_dl_start (void *arg)
{
  unsigned int elf_machine_rel () { return _rtld_local; }
  return elf_machine_rel ();
}
