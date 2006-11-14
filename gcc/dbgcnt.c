#include "config.h"
#include "system.h"
#include "coretypes.h"

#include "dbgcnt.h"

struct string2counter_map {
  const char *name;
  enum debug_counter counter;
};

#define COUNTER(a) { #a , a }

static struct string2counter_map map[debug_counter_number_of_counters] =
{
COUNTER (new_dce),
COUNTER (tail_call)
};

static int count[debug_counter_number_of_counters];
static int limit[debug_counter_number_of_counters];

bool
dbg_cnt (enum debug_counter index)
{
  count[index]++;
  return limit[index] == 0 || (count[index] < limit[index]);
}

static void
dbg_cnt_set_limit_by_index (enum debug_counter index, int value)
{
  limit[index] = value;

  fprintf (stderr, "dbg_cnt '%s' set to %d\n", map[index].name, value);
}

static void
dbg_cnt_set_limit_by_name (const char *name, int len, int value)
{
  int i;
  for (i = debug_counter_number_of_counters - 1; i >= 0; i--)
    if (!strncmp (map[i].name, name, len))
      break;

  if (i < 0)
    return;

  dbg_cnt_set_limit_by_index (i, value);
}

void
dbg_cnt_process_opt (const char *arg)
{
   char *colon = strchr (arg, ':');
   char *comma;
   
   if (colon == NULL)
     return;

   dbg_cnt_set_limit_by_name (arg, colon - arg, atoi (colon + 1));

   comma = strchr (colon + 1, ',');
   while (comma)
     {
       colon = strchr (comma + 1, ':');
       if (colon == NULL || !(colon[1] >= '0' && colon[1] <= '9'))
         return;
       dbg_cnt_set_limit_by_name (comma + 1, colon - (comma + 1), atoi (colon + 1));
       comma = strchr (colon + 1, ',');
     }
}
