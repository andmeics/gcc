#define N 1000

struct str {
  int a;
  int b;
  int c;
  int d;
};

void init_str (struct str *);
void g (struct str *);

int main (void)
{
  struct str a;
  
  init_str (&a);

  g (&a);

  return (a.a + a.b + a.c + a.d); 
}

void init_str (struct str * str_p)
{
  int i;
  
  str_p->a = 11;
  str_p->b = 12;
  str_p->c = 13;
  str_p->d = 14;
 
}

void g (struct str * str_p)
{
  int i;
  
  for (i=0; i < N; i++)
    {
      str_p->a = str_p->a + str_p->b;
      str_p->b = str_p->c + str_p->c;
      str_p->c = str_p->c + str_p->d;
      str_p->d = str_p->d + str_p->a;
    }  
}
