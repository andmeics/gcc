/* Check that 128-bit struct's are represented as TImode values.  */
/* { dg-do compile { target int128 } } */
/* { dg-skip-if "different ABI" { x86_64-*-mingw* } } */
/* { dg-options "-O2 -fdump-rtl-expand" } */

struct shared_ptr_struct
{
  unsigned long long phase:48;
  unsigned short thread:16;
  union
    {
      void *addr;
      unsigned long long pad;
    };
};
typedef struct shared_ptr_struct sptr_t;

sptr_t sptr_1, sptr_2;

void
copy_sptr (void)
{
  sptr_1 = sptr_2;
}

/* { dg-final { scan-rtl-dump "\\\(set \\\(reg:TI \[0-9\]*" "expand" } } */
/* { dg-final { scan-rtl-dump "\\\(set \\\(mem/c:TI" "expand" } } */
