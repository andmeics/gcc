/* { dg-require-effective-target vect_int } */

#include <stdarg.h>
#include "tree-vect.h"

#define N 16 

typedef struct {
   unsigned char a;
   unsigned char b;
   unsigned char c;
   unsigned char d;
   unsigned char e;
   unsigned char f;
   unsigned char g;
   unsigned char h;
} viterbi_struct;

int
main1 (viterbi_struct *arr)
{
  int i;
  viterbi_struct *ptr = arr;
  viterbi_struct res[N];
  unsigned char x;

  for (i = 0; i < N; i++)
    {
      res[i].c = ptr->b + ptr->c;
      x = ptr->c + ptr->f;
      res[i].a = x + ptr->b;
      res[i].d = ptr->b + ptr->c;
      res[i].b = ptr->c;
      res[i].f = ptr->f + ptr->e;
      res[i].e = ptr->b + ptr->e; 
      res[i].h = ptr->c;   
      res[i].g = ptr->b + ptr->c;
      ptr++; 
    } 
   
  /* check results:  */
  for (i = 0; i < N; i++)
    { 
      if (res[i].c != arr[i].b + arr[i].c
          || res[i].a != arr[i].c + arr[i].f + arr[i].b
          || res[i].d != arr[i].b + arr[i].c
          || res[i].b != arr[i].c
          || res[i].f != arr[i].f + arr[i].e
          || res[i].e != arr[i].b + arr[i].e
          || res[i].h != arr[i].c
          || res[i].g != arr[i].b + arr[i].c)
          abort();
   }
}


int main (void)
{
  int i;
  viterbi_struct arr[N];
  
  check_vect ();

  for (i = 0; i < N; i++)
    { 
      arr[i].a = i;
      arr[i].b = i * 2;
      arr[i].c = 17;
      arr[i].d = i+34;
      arr[i].e = i * 3 + 5;
      arr[i].f = i * 5;
      arr[i].g = i - 3;
      arr[i].h = 56;
      if (arr[i].a == 178)
         abort(); 
    } 

  main1 (arr);

  return 0;
}

/* { dg-final { scan-tree-dump-times "vectorized 1 loops" 1 "vect" { target powerpc*-*-* } } } */
/* { dg-final { cleanup-tree-dump "vect" } } */
