/* {{{ Copyright */

/* Mudflap: narrow-pointer bounds-checking by tree rewriting.
   Copyright (C) 2002 Free Software Foundation, Inc.
   Contributed by Frank Ch. Eigler <fche@redhat.com>
   and Graydon Hoare <graydon@redhat.com>

This file is part of GCC.

XXX: libgcc license?
*/

/* }}} */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <execinfo.h>
#include <assert.h>

#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <signal.h>

#include "mf-runtime.h"

#ifndef max
#define max(a,b) ((a) > (b) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) ((a) < (b) ? (a) : (b))
#endif

#ifdef _MUDFLAP
#error "Do not compile this file with -fmudflap!"
#endif

/* ------------------------------------------------------------------------ */
/* {{{ Utility macros */

#define MINPTR ((uintptr_t) 0)
#define MAXPTR (~ (uintptr_t) 0)

/* Clamp the addition/subtraction of uintptr_t's to [MINPTR,MAXPTR] */
#define CLAMPSUB(ptr,offset) ((ptr) >= (offset) ? (ptr)-(offset) : MINPTR)
#define CLAMPADD(ptr,offset) ((ptr) <= MAXPTR-(offset) ? (ptr)+(offset) : MAXPTR)
#define CLAMPSZ(ptr,size) ((ptr) <= MAXPTR-(size)+1 ? (ptr)+(size)-1 : MAXPTR)

/* }}} */
/* ------------------------------------------------------------------------ */
/* {{{ Required globals.  */

#ifndef LOOKUP_CACHE_MASK_DFL
#define LOOKUP_CACHE_MASK_DFL 1023
#endif
#ifndef LOOKUP_CACHE_SIZE_MAX
#define LOOKUP_CACHE_SIZE_MAX 4096 /* Allows max CACHE_MASK 0x0FFF */
#endif
#ifndef LOOKUP_CACHE_SHIFT_DFL
#define LOOKUP_CACHE_SHIFT_DFL 2
#endif

struct __mf_cache __mf_lookup_cache [LOOKUP_CACHE_SIZE_MAX];
uintptr_t __mf_lc_mask = LOOKUP_CACHE_MASK_DFL;
unsigned char __mf_lc_shift = LOOKUP_CACHE_SHIFT_DFL;
#define LOOKUP_CACHE_SIZE (__mf_lc_mask + 1)

/* }}} */
/* ------------------------------------------------------------------------ */
/* {{{ Configuration engine */

struct __mf_options __mf_opts;

mf_state __mf_state = inactive;

#define BEGIN_RECURSION_PROTECT           \
  mf_state old_state;                     \
  if (UNLIKELY (__mf_state == reentrant)) \
    return;                               \
  old_state = __mf_state;                 \
  __mf_state = reentrant;

#define END_RECURSION_PROTECT             \
  __mf_state = old_state;



static void
__mf_set_default_options ()
{
  __mf_opts.trace_mf_calls = 0;
  __mf_opts.collect_stats = 0;
  __mf_opts.internal_checking = 0;
  __mf_opts.print_leaks = 0;
  __mf_opts.verbose_violations = 0;
  __mf_opts.optimize_object_tree = 0;
  __mf_opts.multi_threaded = 0;
  __mf_opts.stack_bound = 0;
  __mf_opts.free_queue_length = 0;
  __mf_opts.persistent_count = 0;
  __mf_opts.crumple_zone = 32;
  __mf_opts.backtrace = 4;
  __mf_opts.mudflap_mode = mode_check;
  __mf_opts.violation_mode = viol_nop;
  __mf_opts.heur_proc_map = 1;
}

static struct option
{
  char *name;
  char *description;
  enum
    {
      set_option,
      read_integer_option,
    } type;
  int value;
  int *target;
} 
options [] =
  {
    {"mode-nop", 
     "mudflaps do nothing", 
     set_option, (int)mode_nop, (int *)&__mf_opts.mudflap_mode},    
    {"mode-populate", 
     "mudflaps populate object tree", 
     set_option, (int)mode_populate, (int *)&__mf_opts.mudflap_mode},    
    {"mode-check", 
     "mudflaps check for memory violations",
     set_option, (int)mode_check, (int *)&__mf_opts.mudflap_mode},
    {"mode-violate", 
     "mudflaps always cause violations (diagnostic)",
     set_option, (int)mode_violate, (int *)&__mf_opts.mudflap_mode},
    
    {"viol-nop", 
     "violations do not change program execution",
     set_option, (int)viol_nop, (int *)&__mf_opts.violation_mode},
    {"viol-abort", 
     "violations cause a call to abort()",
     set_option, (int)viol_abort, (int *)&__mf_opts.violation_mode},
    {"viol-segv", 
     "violations are promoted to SIGSEGV signals",
     set_option, (int)viol_segv, (int *)&__mf_opts.violation_mode},
    {"viol-gdb", 
     "violations fork a gdb process attached to current program",
     set_option, (int)viol_gdb, (int *)&__mf_opts.violation_mode},

    {"trace-calls", 
     "trace calls to mudflap runtime library",
     set_option, 1, &__mf_opts.trace_mf_calls},
    {"collect-stats", 
     "collect statistics on mudflap's operation",
     set_option, 1, &__mf_opts.collect_stats},
    {"internal-checking", 
     "perform more expensive internal checking",
     set_option, 1, &__mf_opts.internal_checking},
    {"print-leaks", 
     "print any memory leaks at program shutdown",
     set_option, 1, &__mf_opts.print_leaks},
    {"verbose-violations", 
     "print verbose messages when memory violations occur",
     set_option, 1, &__mf_opts.verbose_violations},
    {"optimize-object-tree", 
     "periodically optimize memory object tracking tree",
     set_option, 1, &__mf_opts.optimize_object_tree},
    /* XXX: this should be sensitive to gcc --enable-threading= setting */
    {"multi-threaded", 
     "support multiple threads",
     set_option, 1, &__mf_opts.multi_threaded},
    {"heur-proc-map", 
     "support /proc/self/map heuristics",
     set_option, 1, &__mf_opts.heur_proc_map},
    {"stack-bound",
     "enable a simple upper stack bound heuristic",
     set_option, 1, &__mf_opts.stack_bound},
     
    {"free-queue-length", 
     "queue N deferred free() calls before performing them",
     read_integer_option, 0, &__mf_opts.free_queue_length},
    {"persistent-count", 
     "keep a history of N unregistered regions",
     read_integer_option, 0, &__mf_opts.persistent_count},
    {"crumple-zone", 
     "surround allocations with crumple zones of N bytes",
     read_integer_option, 0, &__mf_opts.crumple_zone},
    {"lc-mask", 
     "set lookup cache size mask to N (2**M - 1)",
     read_integer_option, 0, &__mf_lc_mask},
    {"lc-shift", 
     "set lookup cache pointer shift",
     read_integer_option, 0, &__mf_lc_shift},
    {"backtrace", 
     "keep an N-level stack trace of each call context",
     read_integer_option, 0, &__mf_opts.backtrace},

    {0, 0, set_option, 0, NULL}
  };

static void
__mf_usage ()
{
  struct option *opt;

  fprintf (stderr, 
	   "This is a GCC \"mudflap\" memory-checked binary.\n"
	   "Mudflap is Copyright (C) 2002 Free Software Foundation, Inc.\n"
	   "\n"
	   "The mudflap code can be controlled by an environment variable:\n"
	   "\n"
	   "$ export MUDFLAP_OPTIONS='<options>'\n"
	   "$ <mudflapped_program>\n"
	   "\n"
	   "where <options> is a space-separated list of \n"
	   "any of the following options.  Use `-no-OPTION' to disable options.\n"
	   "\n");

  for (opt = options; opt->name; opt++)
    {
      int default_p = (opt->value == * opt->target);

      switch (opt->type)
	{
	  char buf[128];
	case set_option:
	  fprintf (stderr, "-%-23.23s %s", opt->name, opt->description);
	  if (default_p)
	    fprintf (stderr, " [default]\n", opt->value);
	  else
	    fprintf (stderr, "\n");
	  break;
	case read_integer_option:
	  strncpy (buf, opt->name, 128);
	  strncpy (buf + strnlen (opt->name, 128), "=N", 2);
	  fprintf (stderr, "-%-23.23s %s", buf, opt->description);
	  fprintf (stderr, " [%d]\n", * opt->target);
	  break;	  
	default: abort();
	}
    }

  fprintf (stderr, "\n");
}


static int 
__mf_process_opts (char *optstr)
{
  struct option *opts = 0;
  char *nxt = 0;
  long tmp = 0;

  while (*optstr)
    {
      switch (*optstr) {
      case ' ':
      case '\t':
      case '\n':
	optstr++;
	break;

      case '-':
	if (*optstr+1)
	  {	    
	    int negate = 0;
	    optstr++;

	    if (*optstr == '?' || strcmp (optstr, "help") == 0)
	      {
		__mf_usage ();
		exit (0);
	      }
	    
	    if (strncmp (optstr, "no-", 3) == 0)
	      {
		negate = 1;
		optstr = & optstr[3];
	      }
	    
	    for (opts = options; opts->name; opts++)
	      {
		if (strncmp (optstr, opts->name, 
			     strlen (opts->name)) == 0)
		  {
		    optstr += strlen (opts->name);
		    assert (opts->target);
		    switch (opts->type) 
		      {
		      case set_option:
			if (negate)
			  *(opts->target) = 0;
			else
			  *(opts->target) = opts->value;
			break;
		      case read_integer_option:
			if (! negate && (*optstr == '=' && *(optstr+1)))
			  {
			    optstr++;
			    tmp = strtol (optstr, &nxt, 10);
			    if ((optstr != nxt) && (tmp != LONG_MAX))
			      {
				optstr = nxt;				
				*(opts->target) = (int)tmp;
			      }
			  }
			else if (negate)
			  * opts->target = 0;
			break;
		      }
		  }
	      }
	  }
	break;
	
      default:
	fprintf (stderr, 
		 "warning: unrecognized string '%s' in mudflap options\n",
		 optstr);
	return 0;
	break;
      }
    }

  /* Special post-processing: bound __mf_lc_mask for security. */
  __mf_lc_mask &= (LOOKUP_CACHE_SIZE_MAX - 1);

  return 1;
}

#define CTOR  __attribute__ ((constructor))
#define DTOR  __attribute__ ((destructor))


extern void __mf_init () CTOR;
void __mf_init ()
{
  char *ov = 0;

  __mf_state = starting;

  __mf_set_default_options ();

  ov = getenv ("MUDFLAP_OPTIONS");
  if (ov)
    {
      if (__mf_process_opts (ov) == 0)
	{
	  fprintf (stderr, 
		   "mudflap error: unknown options in "
		   "environment variable MUDFLAP_OPTIONS\n");
	  __mf_usage ();
	  exit (1);
	}
    }

  __mf_init_heuristics ();
  __mf_state = active;

  TRACE_OUT;
}


extern void __mf_fini () DTOR;
void __mf_fini ()
{
  TRACE_IN;
  __mf_report ();
  TRACE_OUT;
}

/* }}} */
/* ------------------------------------------------------------------------ */
/* {{{ stats-related globals.  */

static unsigned long __mf_count_check;
static unsigned long __mf_lookup_cache_reusecount [LOOKUP_CACHE_SIZE_MAX];
static unsigned long __mf_treerot_left, __mf_treerot_right;
static unsigned long __mf_count_register;
static unsigned long __mf_total_register_size [__MF_TYPE_GUESS+1];
static unsigned long __mf_count_unregister;
static unsigned long __mf_total_unregister_size;
static unsigned long __mf_count_violation [__MF_VIOL_UNREGISTER+1];

/* }}} */
/* ------------------------------------------------------------------------ */
/* {{{ MODE_CHECK-related globals.  */

typedef struct __mf_object
{
  uintptr_t low, high;
  int type;
  const char *name;
  unsigned check_count; /* Number of times __mf_check was called.  */

  uintptr_t alloc_pc;
  struct timeval alloc_time;
  char **alloc_backtrace;
  size_t alloc_backtrace_size;

  int deallocated_p;
  uintptr_t dealloc_pc;
  struct timeval dealloc_time;
  char **dealloc_backtrace;
  size_t dealloc_backtrace_size;
} __mf_object_t;


typedef struct __mf_object_tree
{
  __mf_object_t data;
  struct __mf_object_tree *left;
  struct __mf_object_tree *right;
} __mf_object_tree_t;

/* Live objects: binary tree on __mf_object_t.low */
__mf_object_tree_t *__mf_object_root;
/* Dead objects: circular arrays */
unsigned __mf_object_dead_head[__MF_TYPE_GUESS+1]; /* next empty spot */
__mf_object_tree_t *__mf_object_cemetary[__MF_TYPE_GUESS+1][__MF_PERSIST_MAX];

static __mf_object_tree_t *__mf_find_object (uintptr_t low, uintptr_t high);
static unsigned __mf_find_objects (uintptr_t ptr_low, uintptr_t ptr_high, 
				   __mf_object_tree_t **objs, unsigned max_objs);
static unsigned __mf_find_dead_objects (uintptr_t ptr_low, uintptr_t ptr_high, 
					__mf_object_tree_t **objs, unsigned max_objs);
static void __mf_link_object (__mf_object_tree_t *obj);
static void __mf_unlink_object (__mf_object_tree_t *obj);
static void __mf_describe_object (__mf_object_t *obj);

/* }}} */
/* ------------------------------------------------------------------------ */
/* {{{ __mf_check */

void __mf_check (uintptr_t ptr, uintptr_t sz, const char *location)
{
  unsigned entry_idx = __MF_CACHE_INDEX (ptr);
  struct __mf_cache *entry = & __mf_lookup_cache [entry_idx];
  int violation_p = 0;
  uintptr_t ptr_high = CLAMPSZ (ptr, sz);

  struct __mf_cache old_entry = *entry;

  BEGIN_RECURSION_PROTECT;
  
  switch (__mf_opts.mudflap_mode)
    {
    case mode_nop:
      break;

    case mode_populate:
      entry->low = ptr;
      entry->high = ptr_high;
      break;

    case mode_check:
      {
	__mf_object_tree_t *node = __mf_find_object (ptr, ptr_high);
	__mf_object_t *obj = (node != NULL ? (& node->data) : NULL);
	
	if (LIKELY (obj && ptr >= obj->low && ptr_high <= obj->high))
	  {
	    entry->low = obj->low;
	    entry->high = obj->high;
	    obj->check_count ++;  /* XXX: what about overflow?  */
	  }
	else
	  {
	    if (! __mf_heuristic_check (ptr, ptr_high))
	      {	      
		/* XXX:  */
		violation_p = 1;
	      }
	  }
      }    
      break;

    case mode_violate:
      violation_p = 1;
      break;
    }

  if (__mf_opts.collect_stats)
    {
      __mf_count_check ++;
      
      if (LIKELY (old_entry.low != entry->low || old_entry.high != entry->high))
	/* && (old_entry.low != 0) && (old_entry.high != 0)) */
	__mf_lookup_cache_reusecount [entry_idx] ++;    
    }
  
  TRACE ("mf: check p=%p s=%lu viol=%d location=%s\n", (void *)ptr, sz, 
	 violation_p, location);
  END_RECURSION_PROTECT;
  
  if (UNLIKELY (violation_p))
    __mf_violation (ptr, sz,
		    (uintptr_t) __builtin_return_address (0), location,
		    __MF_VIOL_CHECK);
}

/* }}} */
/* {{{ __mf_register */

static __mf_object_tree_t *
__mf_insert_new_object (uintptr_t low, uintptr_t high, int type, 
			const char *name, uintptr_t pc)
{
  extern void * __real_calloc (size_t c, size_t);

  __mf_object_tree_t *new_obj;
  new_obj = __real_calloc (1, sizeof(__mf_object_tree_t));
  new_obj->data.low = low;
  new_obj->data.high = high;
  new_obj->data.type = type;
  new_obj->data.name = name;
  new_obj->data.alloc_pc = pc;
  gettimeofday (& new_obj->data.alloc_time, NULL);
  
  if (__mf_opts.backtrace > 0)
    new_obj->data.alloc_backtrace_size = 
      __mf_backtrace (& new_obj->data.alloc_backtrace,
		      (void *) pc, 2);
  
  __mf_link_object (new_obj);
  return new_obj;
}


static void 
__mf_remove_old_object (__mf_object_tree_t *old_obj)
{
  __mf_unlink_object (old_obj);
  
  /* Remove any low/high pointers for this object from the lookup cache.  */
  if (LIKELY (old_obj->data.check_count)) /* Can it possibly exist in the cache?  */
    {
      uintptr_t low = old_obj->data.low;
      uintptr_t high = old_obj->data.high;
      unsigned idx_low = __MF_CACHE_INDEX (low);
      unsigned idx_high = __MF_CACHE_INDEX (high);
      unsigned i;
      for (i = idx_low; i <= idx_high; i++)
	{
	  struct __mf_cache *entry = & __mf_lookup_cache [i];
	  if (entry->low == low && entry->high == high)
	    {
	      entry->low = entry->high = (uintptr_t) 0;
	    }
	}
    }
}


void
__mf_register (uintptr_t ptr, uintptr_t sz, int type, const char *name)
{

  if (UNLIKELY (!(__mf_state == active || __mf_state == starting))) return;

  TRACE("mf: reg p=%p s=%lu t=%d n='%s'\n", (void *)ptr, sz, 
	type, name ? name : "");

  switch (__mf_opts.mudflap_mode)
    {
    case mode_nop:
      break;
      
    case mode_violate:
      __mf_violation (ptr, sz, (uintptr_t) 
		      __builtin_return_address (0), NULL,
		      __MF_VIOL_REGISTER);
      break;

    case mode_populate:
      /* Clear the cache.  */
      memset (__mf_lookup_cache, 0, sizeof(__mf_lookup_cache));
      break;

    case mode_check:
      {
	__mf_object_tree_t *ovr_obj[1];
	__mf_object_tree_t *new_obj;
	unsigned num_overlapping_objs;
	uintptr_t low = ptr;
	uintptr_t high = CLAMPSZ (ptr, sz);
	uintptr_t pc = (uintptr_t) __builtin_return_address (0);
	
	BEGIN_RECURSION_PROTECT;
	
	/* Treat unknown size indication as 1.  */
	if (UNLIKELY (sz == 0)) sz = 1;
	
	num_overlapping_objs = __mf_find_objects (low, high, ovr_obj, 1);
	if (UNLIKELY (num_overlapping_objs > 0))
	  {
	    /* Normally, this would be a violation.  However, accept a
	       single duplicate registration for static objects, since these
	       may come from distinct compilation units.  */
	    if (type == __MF_TYPE_STATIC &&
		num_overlapping_objs == 1 &&
		ovr_obj[0]->data.type == __MF_TYPE_STATIC &&
		ovr_obj[0]->data.low == low &&
		ovr_obj[0]->data.high == high)
	      {
		/* do nothing */
		TRACE ("mf: duplicate static reg %p\n", (void *)low);
		END_RECURSION_PROTECT;
		return;
	      }
	    else if (type == __MF_TYPE_GUESS)
	      {
		/* do nothing, someone has beat us here. */
		TRACE ("mf: existing guessed reg %p\n", (void *)low);
		END_RECURSION_PROTECT;
		return;
	      }
	    else
	      {
		int i;
		int all_guesses = 1;
		for (i = 0; i < num_overlapping_objs; ++i)
		  {
		    if (ovr_obj[i]->data.type == __MF_TYPE_GUESS)
		      {
			/* We're going to split our existing guess
			   into 2 and put this new region in the
			   middle. */
			
			uintptr_t guess1_low, guess1_high;
			uintptr_t guess2_low, guess2_high;
			uintptr_t guess_pc;
			const char *guess_name;
			extern void  __real_free (void *);
		
			guess_pc = ovr_obj[i]->data.alloc_pc;
			guess_name = ovr_obj[i]->data.name;

			guess1_low = ovr_obj[i]->data.low;
			guess1_high = CLAMPSUB (low, (1 + __mf_opts.crumple_zone));

			guess2_low = CLAMPADD (high, (1 + __mf_opts.crumple_zone));
			guess2_high = ovr_obj[i]->data.high;

			TRACE("mf: splitting guess region %p-%p\n", 
			      guess1_low, guess2_high);
		    
			/* NB: split regions may disappear if low > high. */

			__mf_remove_old_object (ovr_obj[i]);
			__real_free (ovr_obj[i]->data.alloc_backtrace);
			__real_free (ovr_obj[i]);
			ovr_obj[i] = NULL;

			/* XXX: preserve other information: stats? backtraces */

			if (guess1_low <= guess1_high)
			  {
			    __mf_insert_new_object (guess1_low, guess1_high, 
						    __MF_TYPE_GUESS, 
						    guess_name, guess_pc);
			  }

			if (guess2_low <= guess2_high)
			  {
			    __mf_insert_new_object (guess2_low, guess2_high, 
						    __MF_TYPE_GUESS, 
						    guess_name, guess_pc);
			  }
		      }
		    else
		      {
			/* Two or more *real* mappings here. */
			TRACE("mf: reg violation %p\n", (void *)low);
			__mf_violation 
			  (ptr, sz, 
			   (uintptr_t) __builtin_return_address (0), NULL,
			   __MF_VIOL_REGISTER);
		      }
		  }
	      }
	  }

	__mf_insert_new_object (low, high, type, name, pc);
	
	/* We could conceivably call __mf_check() here to prime the cache,
	   but then the check_count field is not reliable.  */
	
	END_RECURSION_PROTECT;
	break;
      }

    } /* end switch (__mf_opts.mudflap_mode) */

  if (__mf_opts.collect_stats)
    {
      __mf_count_register ++;
      __mf_total_register_size [(type < 0) ? 0 :
				(type > __MF_TYPE_GUESS) ? 0 : 
				type] += sz;
    }
}

/* }}} */
/* {{{ __mf_unregister */

void
__mf_unregister (uintptr_t ptr, uintptr_t sz)
{

  extern void  __real_free (void *);

  BEGIN_RECURSION_PROTECT;

  switch (__mf_opts.mudflap_mode)
    { 
    case mode_nop:
      break;

    case mode_violate:
      __mf_violation (ptr, sz,
		      (uintptr_t) __builtin_return_address (0), NULL,
		      __MF_VIOL_UNREGISTER);
      break;

    case mode_populate:
      /* Clear the cache.  */
      memset (__mf_lookup_cache, 0, sizeof(__mf_lookup_cache));
      break;

    case mode_check:
      {
	static unsigned recursion = 0;
	__mf_object_tree_t *old_obj = NULL;
	__mf_object_tree_t *del_obj = NULL;  /* Object to actually delete. */
	__mf_object_tree_t *objs[1] = {NULL};
	unsigned num_overlapping_objs;
		
	/* Treat unknown size indication as 1.  */
	if (sz == 0) sz = 1;
	
	num_overlapping_objs = __mf_find_objects (ptr, CLAMPSZ (ptr, sz), objs, 1);

	{
	  /* do not unregister guessed regions */
	  int i;
	  for (i = 0; i < num_overlapping_objs; ++i)
	    {
	      if (objs[i]->data.type == __MF_TYPE_GUESS)
		{
		  TRACE("mf: ignored guess unreg %p\n", objs[i]->data.low); 		  
		  END_RECURSION_PROTECT;
		  return;
		}
	    }	    
	}

	if (UNLIKELY (num_overlapping_objs != 1))
	  {
	    /* XXX: also: should match ptr == old_obj->low ? */
	    TRACE("mf: unreg viol %p\n", (void *)ptr);
	    END_RECURSION_PROTECT;
	    __mf_violation (ptr, sz,
			    (uintptr_t) __builtin_return_address (0), NULL,
			    __MF_VIOL_UNREGISTER);
	    return;
	  }
	
	old_obj = objs[0];

	TRACE("mf: removing %p-%p\n", old_obj->data.low, old_obj->data.high); 

	__mf_remove_old_object (old_obj);
	
	if (__mf_opts.persistent_count > 0)
	  {
	    old_obj->data.deallocated_p = 1;
	    old_obj->left = old_obj->right = NULL;
	    old_obj->data.dealloc_pc = (uintptr_t) __builtin_return_address (0);
	    gettimeofday (& old_obj->data.dealloc_time, NULL);
	    
	    if (__mf_opts.backtrace > 0)
	      old_obj->data.dealloc_backtrace_size = 
		__mf_backtrace (& old_obj->data.dealloc_backtrace,
				NULL, 2);

	    
	    /* Put this object into the cemetary.  This may require this plot to
	       be recycled, and the previous resident to be designated del_obj.  */
	    
	    assert (old_obj->data.type >= __MF_TYPE_UNKNOWN && 
		    old_obj->data.type <= __MF_TYPE_GUESS);
	    {
	      unsigned row = old_obj->data.type;
	      unsigned plot = __mf_object_dead_head [row];
	      
	      del_obj = __mf_object_cemetary [row][plot];
	      __mf_object_cemetary [row][plot] = old_obj;
	      
	      plot ++;
	      if (plot == __mf_opts.persistent_count) plot = 0;
	      __mf_object_dead_head [row] = plot;
	    }
	    
	  } else {
	    del_obj = old_obj;
	  }
	
	if (__mf_opts.print_leaks)
	  {
	    if (old_obj->data.check_count == 0 &&
		old_obj->data.type == __MF_TYPE_HEAP)
	      {
		fprintf (stderr, 
			 "*******\n"
			 "mudflap warning: unaccessed registered object:\n");
		__mf_describe_object (& old_obj->data);
	      }
	  }
	
	if (del_obj != NULL) /* May or may not equal old_obj.  */
	  {
	    if (__mf_opts.backtrace > 0)
	      {
		__real_free (del_obj->data.alloc_backtrace);
		if (__mf_opts.persistent_count > 0)
		  __real_free (del_obj->data.dealloc_backtrace);
	      }
	    __real_free (del_obj);
	  }
	
	break;
      }
    } /* end switch (__mf_opts.mudflap_mode) */


  if (__mf_opts.collect_stats)
    {
      __mf_count_unregister ++;
      __mf_total_unregister_size += sz;
    }

  TRACE("mf: unr p=%p s=%lu\n", (void *)ptr, sz);
  END_RECURSION_PROTECT;
}

/* }}} */
/* ------------------------------------------------------------------------ */
/* {{{ __mf_validate_live_object_tree, _object_cemetary */

static void
__mf_validate_live_object_tree (__mf_object_tree_t *obj)
{
  assert (obj != NULL);

  if (__mf_opts.persistent_count > 0)
    assert (! obj->data.deallocated_p);

  if (obj->left)
    {
      assert (obj->left->data.high < obj->data.low);
      __mf_validate_live_object_tree (obj->left);
    }
  if (obj->right)
    {
      assert (obj->right->data.low > obj->data.high);
      __mf_validate_live_object_tree (obj->right);
    }
}

static void
__mf_validate_object_cemetary ()
{
  unsigned cls;
  unsigned i;

  for (cls = __MF_TYPE_UNKNOWN; cls <= __MF_TYPE_GUESS; cls++)
    {
      assert (__mf_object_dead_head [cls] >= 0 &&
	      __mf_object_dead_head [cls] < __mf_opts.persistent_count);
      for (i = 0; i < __mf_opts.persistent_count; i++)
	{
	  __mf_object_tree_t *obj = __mf_object_cemetary [cls][i];
	  if (obj != NULL)
	    {
	      assert (obj->data.deallocated_p);
	      assert (obj->left == NULL);
	      assert (obj->right == NULL);
	    }
	}
    }
}

static void 
__mf_validate_objects ()
{
  if (__mf_object_root)
    __mf_validate_live_object_tree (__mf_object_root);

  if (__mf_opts.persistent_count > 0)
    __mf_validate_object_cemetary ();
}

/* }}} */
/* {{{ __mf_find_object[s] */

/* Find overlapping live objecs between [low,high].  Return up to
   max_objs of their pointers in objs[].  Return total count of
   overlaps (may exceed max_objs). */

/* XXX: track traversal statistics, like average depth, balance.  */

static unsigned
__mf_find_objects_rec (uintptr_t low, uintptr_t high, __mf_object_tree_t **nodep,
		       __mf_object_tree_t **objs, unsigned max_objs)
{
  unsigned count;
  __mf_object_tree_t *node = *nodep;

  assert (low <= high);
  assert (max_objs == 0 || objs != NULL);

  if (UNLIKELY (node == NULL)) return 0;

  /* Traverse down left subtree. */
  count = 0;
  if (low < node->data.low)
    count += __mf_find_objects_rec (low, high, & node->left, objs, max_objs);

  /* Track the used slots of objs[].  */
  if (count < max_objs)
    {
      objs += count;
      max_objs -= count;
    }
  else
    {
      max_objs = 0;
    }

  /* Check for overlap with this node.  */
  if (high >= node->data.low && low <= node->data.high)
    {
      count ++;
      if (max_objs > 0)  /* Any room left?  */
	{
	  objs[0] = node;
	  objs ++;
	  max_objs --;
	}
    }

  /* Traverse down right subtree.  */
  if (high > node->data.high)
    count += __mf_find_objects_rec (low, high, & node->right, objs, max_objs);
  /* There is no need to manipulate objs/max_objs any further.  */


  /* Rotate a child node up if its access count is higher. */
  /* XXX: Should there be a minimum check_count delta that triggers this?  */
  /* XXX: Should age (scale down) system-wide check_counts periodically.  */
  if (UNLIKELY ((node->left && node->left->data.check_count > node->data.check_count) &&
		((!node->right || (node->right && 
				   node->left->data.check_count > 
				   node->right->data.check_count)))))
    {
      __mf_object_tree_t *l = node->left;
      __mf_object_tree_t *l_r = l->right;

      *nodep = l;
      l->right = node;
      node->left = l_r;
      __mf_treerot_left ++;
    }
  else if (UNLIKELY ((node->right && node->right->data.check_count > node->data.check_count) &&
		     ((!node->left || (node->left && 
				       node->right->data.check_count > 
				       node->left->data.check_count)))))
    {
      __mf_object_tree_t *r = node->right;
      __mf_object_tree_t *r_l = r->left;

      *nodep = r;
      r->left = node;
      node->right = r_l;
      __mf_treerot_right ++;
    }


  return count;
}


__mf_object_tree_t *
__mf_find_object (uintptr_t low, uintptr_t high)
{
  __mf_object_tree_t* objects[1]; /* Find at most one.  */
  unsigned count;

  if (UNLIKELY(__mf_opts.internal_checking))
    __mf_validate_objects ();

  count = __mf_find_objects_rec (low, high, & __mf_object_root, objects, 1);
  if (count == 1)
    return objects[0];
  else
    return NULL;
}


unsigned
__mf_find_objects (uintptr_t ptr_low, uintptr_t ptr_high,
		   __mf_object_tree_t **objs, unsigned max_objs)
{
  if (UNLIKELY(__mf_opts.internal_checking))
    __mf_validate_objects ();

  return __mf_find_objects_rec (ptr_low, ptr_high, & __mf_object_root, objs, max_objs);
}

/* }}} */
/* {{{ __mf_link_object */

static void
__mf_link_object2 (__mf_object_tree_t *ptr, __mf_object_tree_t **link)
{
  __mf_object_tree_t *node = *link;

  assert (ptr != NULL);
  if (UNLIKELY(node == NULL))
    {
      *link = ptr;
      return;
    }

  if (ptr->data.high < node->data.low)
    return __mf_link_object2 (ptr, & node->left);
  else if (ptr->data.low > node->data.high)
    return __mf_link_object2 (ptr, & node->right);
  else
    abort (); /* XXX: duplicate object */
}


void
__mf_link_object (__mf_object_tree_t *ptr)
{
  if (UNLIKELY(__mf_opts.internal_checking))
    __mf_validate_objects ();

  return __mf_link_object2 (ptr, & __mf_object_root);
}

/* }}} */
/* {{{ __mf_unlink_object */

static void
__mf_unlink_object2 (__mf_object_tree_t *ptr, __mf_object_tree_t **link)
{
  __mf_object_tree_t *node = *link;
  
  assert (ptr != NULL);
  if (UNLIKELY(node == ptr))
    {
      static unsigned promote_left_p = 0;
      promote_left_p = 1 - promote_left_p;

      /* Alternate promoting the left & right subtrees. */
      if (promote_left_p)
	{
	  *link = ptr->left;
	  if (ptr->right != NULL)
	    __mf_link_object2 (ptr->right, link);
	}
      else
	{
	  *link = ptr->right;
	  if (ptr->left != NULL)
	    __mf_link_object2 (ptr->left, link);
	}

      return;
    }

  if (ptr->data.high < node->data.low)
    return __mf_unlink_object2 (ptr, & node->left);
  else if (ptr->data.low > node->data.high)
    return __mf_unlink_object2 (ptr, & node->right);
  else
    abort (); /* XXX: missing object; should fail more gracefully. */
}

static void
__mf_unlink_object (__mf_object_tree_t *node)
{
  __mf_unlink_object2 (node, & __mf_object_root);
}

/* }}} */
/* {{{ __mf_find_dead_objects */

/* Find overlapping dead objecs between [low,high].  Return up to
   max_objs of their pointers in objs[].  Return total count of
   overlaps (may exceed max_objs).  */

static unsigned
__mf_find_dead_objects (uintptr_t low, uintptr_t high,
			__mf_object_tree_t **objs, unsigned max_objs)
{
  if (__mf_opts.persistent_count > 0)
    {
      unsigned count = 0;
      unsigned recollection = 0;
      unsigned row = 0;
      
      assert (low <= high);
      assert (max_objs == 0 || objs != NULL);
      
      /* Widen the search from the most recent plots in each row, looking
	 backward in time.  */
      recollection = 0;
      while (recollection < __mf_opts.persistent_count)
	{
	  count = 0;
	  
	  for (row = __MF_TYPE_UNKNOWN; row <= __MF_TYPE_GUESS; row ++)
	    {
	      unsigned plot;
	      unsigned i;
	      
	      plot = __mf_object_dead_head [row];
	      for (i = 0; i <= recollection; i ++)
		{
		  __mf_object_tree_t *obj;
		  
		  /* Look backward through row: it's a circular buffer.  */
		  if (plot > 0) plot --;
		  else plot = __mf_opts.persistent_count - 1;
		  
		  obj = __mf_object_cemetary [row][plot];
		  if (obj && obj->data.low <= high && obj->data.high >= low)
		    {
		      /* Found an overlapping dead object!  */
		      if (count < max_objs)
			objs [count] = obj;
		      count ++;
		    }
		}
	    }
	  
	  if (count)
	    break;
	  
	  /* Look farther back in time.  */
	  recollection = (recollection * 2) + 1;
	}
      
      return count;
    } else {
      return 0;
    }
}

/* }}} */
/* {{{ __mf_describe_object */

static void
__mf_describe_object (__mf_object_t *obj)
{
  /* if (UNLIKELY (__mf_state != active)) return; */

  fprintf (stderr,
	   "mudflap object %08lx: name=`%s'\n"
	   "bounds=[%08lx,%08lx] size=%lu area=%s access-count=%u\n"
	   "alloc time=%lu.%06lu pc=%08lx\n",
	   obj, (obj->name ? obj->name : ""), 
	   obj->low, obj->high, (obj->high - obj->low + 1),
	   (obj->type == __MF_TYPE_HEAP ? "heap" :
	    obj->type == __MF_TYPE_STACK ? "stack" :
	    obj->type == __MF_TYPE_STATIC ? "static" :
	    obj->type == __MF_TYPE_GUESS ? "guess" :
	    "unknown"),
	   obj->check_count,
	   obj->alloc_time.tv_sec, obj->alloc_time.tv_usec, obj->alloc_pc);

  if (__mf_opts.backtrace > 0)
  {
    int i;
    for (i=0; i<obj->alloc_backtrace_size; i++)
      fprintf (stderr, "      %s\n", obj->alloc_backtrace[i]);
  }

  if (__mf_opts.persistent_count > 0)
    {
      if (obj->deallocated_p)
	{
	  fprintf (stderr, "dealloc time=%lu.%06lu pc=%08lx\n",
		   obj->dealloc_time.tv_sec, obj->dealloc_time.tv_usec, obj->dealloc_pc);

	  if (__mf_opts.backtrace > 0)
	  {
	    int i;
	    for (i=0; i<obj->dealloc_backtrace_size; i++)
	      fprintf (stderr, "      %s\n", obj->dealloc_backtrace[i]);
	  }
	}
    }
}

static unsigned
__mf_report_leaks (__mf_object_tree_t *node)
{
  static unsigned count = 0;  /* Shared amongst recursive calls.  */
  /* XXX: when to reset?  */

  if (node == NULL) return count;

  /* Inorder traversal. */
  __mf_report_leaks (node->left);
  if (node->data.type == __MF_TYPE_HEAP)
    {
      count ++;
      fprintf (stderr, "Leaked object %u:\n", count);
      __mf_describe_object (& node->data);
    }
  __mf_report_leaks (node->right);

  return count;
}

/* }}} */
/* ------------------------------------------------------------------------ */
/* {{{ __mf_report */

void
__mf_report ()
{
  /* if (UNLIKELY (__mf_state == active)) return; */

  if (__mf_opts.collect_stats)
    {
      fprintf (stderr,
	       "*******\n"
	       "mudflap stats:\n"
	       "calls to __mf_check: %lu rot: %lu/%lu\n"
	       "         __mf_register: %lu [%luB, %luB, %luB, %luB]\n"
	       "         __mf_unregister: %lu [%luB]\n"
	       "         __mf_violation: [%lu, %lu, %lu, %lu]\n",
	       __mf_count_check, __mf_treerot_left, __mf_treerot_right,
	       __mf_count_register,
	       __mf_total_register_size[0], __mf_total_register_size[1],
	       __mf_total_register_size[2], __mf_total_register_size[3],
	       __mf_count_unregister, __mf_total_unregister_size,
	       __mf_count_violation[0], __mf_count_violation[1],
	       __mf_count_violation[2], __mf_count_violation[3]);

      /* Lookup cache stats.  */
      {
	unsigned i;
	unsigned max_reuse = 0;
	unsigned num_used = 0;
	unsigned num_unused = 0;

	for (i = 0; i < LOOKUP_CACHE_SIZE; i++)
	  {
	    if (__mf_lookup_cache_reusecount[i])
	      num_used ++;
	    else
	      num_unused ++;
	    if (max_reuse < __mf_lookup_cache_reusecount[i])
	      max_reuse = __mf_lookup_cache_reusecount[i];
	  }
	fprintf (stderr, "lookup cache slots used: %u  unused: %u  peak-reuse: %u\n",
		 num_used, num_unused, max_reuse);
      }

      {
	unsigned live_count;
	live_count = __mf_find_objects ((uintptr_t) 0, ~ (uintptr_t) 0, NULL, 0);
	fprintf (stderr, "number of live objects: %u\n", live_count);
      }

      if (__mf_opts.persistent_count > 0)
	{
	  unsigned dead_count = 0;
	  unsigned row, plot;
	  for (row = __MF_TYPE_UNKNOWN; row <= __MF_TYPE_GUESS; row ++)
	    for (plot = 0 ; plot < __mf_opts.persistent_count; plot ++)
	      if (__mf_object_cemetary [row][plot] != 0)
		dead_count ++;
	  fprintf (stderr, "          persistent dead objects: %u\n", dead_count);
	}
    }
  if (__mf_opts.print_leaks && (__mf_opts.mudflap_mode == mode_check))
    {
      unsigned l = __mf_report_leaks (__mf_object_root);
      fprintf (stderr, "number of leaked objects: %u\n", l);
    }
}

/* }}} */
/* {{{ __mf_backtrace */

size_t
__mf_backtrace (char ***symbols, void *guess_pc, unsigned guess_omit_levels)
{
  void ** pc_array;
  unsigned pc_array_size = __mf_opts.backtrace + guess_omit_levels;
  unsigned remaining_size;
  unsigned omitted_size = 0;
  unsigned i;

  pc_array = alloca (pc_array_size * sizeof (void *));
  pc_array_size = backtrace (pc_array, pc_array_size);

  /* We want to trim the first few levels of the stack traceback,
     since they contain libmudflap wrappers and junk.  If pc_array[]
     ends up containing a non-NULL guess_pc, then trim everything
     before that.  Otherwise, omit the first guess_omit_levels
     entries. */
  
  if (guess_pc != NULL)
    for (i=0; i<pc_array_size; i++)
      if (pc_array [i] == guess_pc)
	omitted_size = i;

  if (omitted_size == 0) /* No match? */
    if (pc_array_size > guess_omit_levels)
      omitted_size = guess_omit_levels;

  remaining_size = pc_array_size - omitted_size;

  *symbols = backtrace_symbols (pc_array + omitted_size, remaining_size);
  return remaining_size;
}

/* }}} */
/* ------------------------------------------------------------------------ */
/* {{{ __mf_violation */

void
__mf_violation (uintptr_t ptr, uintptr_t sz, uintptr_t pc, 
		const char *location, int type)
{
  char buf [128];
  static unsigned violation_number;
  extern void  __real_free (void *);

  BEGIN_RECURSION_PROTECT;

  TRACE("mf: violation pc=%p location=%s type=%d ptr=%p size=%lu\n", pc, 
	(location != NULL ? location : ""), type, ptr, sz);

  if (__mf_opts.collect_stats)
    __mf_count_violation [(type < 0) ? 0 :
			  (type > __MF_VIOL_UNREGISTER) ? 0 :
			  type] ++;

  /* Print out a basic warning message.  */
  if (__mf_opts.verbose_violations)
  {
    unsigned dead_p;
    unsigned num_helpful = 0;
    struct timeval now;
    gettimeofday (& now, NULL);

    violation_number ++;
    fprintf (stderr,
	     "*******\n"
	     "mudflap violation %u: time=%lu.%06lu ptr=%08lx size=%lu pc=%08lx%s%s%s type=%s\n", 
	     violation_number,
	     now.tv_sec, now.tv_usec, ptr, sz, pc,
	     (location != NULL ? " location=`" : ""),
	     (location != NULL ? location : ""),
	     (location != NULL ? "'" : ""),
	     ((type == __MF_VIOL_CHECK) ? "check" :
	      (type == __MF_VIOL_REGISTER) ? "register" :
	      (type == __MF_VIOL_UNREGISTER) ? "unregister" :
	      "unknown"));

    if (__mf_opts.backtrace > 0)
      {
	char ** symbols;
	unsigned i, num;
	
	num = __mf_backtrace (& symbols, (void *) pc, 2);
	/* Note: backtrace_symbols calls malloc().  But since we're in
	   __mf_violation and presumably __mf_check, it'll detect
	   recursion, and not put the new string into the database.  */
	
	for (i=0; i<num; i++)
	  fprintf (stderr, "      %s\n", symbols[i]);
	
	/* Calling free() here would trigger a violation.  */
	__real_free (symbols);
      }
    
    
    /* Look for nearby objects.  For this, we start with s_low/s_high
       pointing to the given area, looking for overlapping objects.
       If none show up, widen the search area and keep looking. */
    
    if (sz == 0) sz = 1;
    
    for (dead_p = 0; dead_p <= 1; dead_p ++) /* for dead_p in 0 1 */
      {
	enum {max_objs = 3}; /* magic */
	__mf_object_tree_t *objs[max_objs];
	unsigned num_objs = 0;
	uintptr_t s_low, s_high;
	unsigned tries = 0;
	unsigned i;
	
	s_low = ptr;
	s_high = CLAMPSZ (ptr, sz);

	while (tries < 4) /* magic */
	  {
	    if (dead_p)
	      num_objs = __mf_find_dead_objects (s_low, s_high, objs, max_objs);
	    else
	      num_objs = __mf_find_objects (s_low, s_high, objs, max_objs);

	    if (num_objs) /* good enough */
	      break;

	    tries ++;
	    s_low = CLAMPSUB (s_low, (sz * tries));
	    s_high = CLAMPADD (s_high, (sz * tries));
	  }

	for (i = 0; i < num_objs; i++)
	  {
	    __mf_object_t *obj = & objs[i]->data;
	    uintptr_t low = ptr;
	    uintptr_t high = CLAMPSZ (ptr, sz);
	    unsigned before = (high < obj->low) ? obj->low - high : 0;
	    unsigned after = (low > obj->high) ? low - obj->high : 0;
	    unsigned into = (high >= obj->low && low <= obj->high) ? low - obj->low : 0;

	    fprintf (stderr, "Nearby object %u: ptr is %uB %s\n",
		     i + 1,
		     (before ? before :
		      after ? after :
		      into),
		     (before ? "before" :
		      after ? "after" :
		      "into"));
	    __mf_describe_object (obj);
	  }
	num_helpful += num_objs;
      }

    fprintf (stderr, "number of nearby objects: %u\n", num_helpful);
  }

  /* How to finally handle this violation?  */
  switch (__mf_opts.violation_mode)
    {
    case viol_nop:
      break;
    case viol_segv:
      kill (getpid(), SIGSEGV);
      break;
    case viol_abort:
      abort ();
      break;
    case viol_gdb:
      snprintf (buf, 128, "gdb --pid=%d", getpid ());
      system (buf);
      /* XXX: should probably fork() && sleep(GDB_WAIT_PARAMETER)
      instead, and let the forked child execlp() gdb.  That way, this
      subject process can be resumed under the supervision of gdb.
      This can't happen now, since system() only returns when gdb
      dies.  In that case, we need to beware of starting a second
      concurrent gdb child upon the next violation.  (But if the first
      gdb dies, then starting a new one is appropriate.)  */
      break;
    }
  
  END_RECURSION_PROTECT;
}

/* }}} */
/* ------------------------------------------------------------------------ */
