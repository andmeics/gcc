/* Basile's static analysis (should have a better name) basilys.c
   Copyright (C) 2008 Free Software Foundation, Inc.
   Contributed by Basile Starynkevitch <basile@starynkevitch.net>
   Indented with GNU indent 

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.   If not see
<http://www.gnu.org/licenses/>.   
  */

/* for debugging -fbasilys-debug is useful */


#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "obstack.h"
#include "tm.h"
#include "tree.h"
#include "filenames.h"
#include "tree-pass.h"
#include "tree-dump.h"
#include "basic-block.h"
#include "timevar.h"
#include "errors.h"
#include "ggc.h"
#include "cgraph.h"
#include "diagnostic.h"
#include "flags.h"
#include "toplev.h"
#include "options.h"
#include "params.h"
#include "real.h"
#include "prefix.h"
#include "md5.h"

#include "cppdefault.h"

#include "compiler-probe.h"


#if HAVE_PARMAPOLY
#include <ppl_c.h>
#else
#error required parma polyedral library PPL
#endif /*HAVE_PARMAPOLY */

#if HAVE_LIBTOOLDYNL
#include <ltdl.h>
#else
#error required libtool dynamic loader library LTDL
#endif /*HAVE_LIBTOOLDYNL */

#include "basilys.h"


#define MINOR_SIZE_KILOWORD PARAM_VALUE(PARAM_BASILYS_MINOR_ZONE)
#define FULL_FREQ PARAM_VALUE(PARAM_BASILYS_FULL_FREQ)

#ifndef MELT_PRIVATE_INCLUDE_DIR
#error MELT_PRIVATE_INCLUDE_DIR is not defined thru compile flags
#endif

#ifndef MELT_SOURCE_DIR
#error MELT_SOURCE_DIR is not defined thru compile flags
#endif

#ifndef MELT_GENERATED_DIR
#error MELT_GENERATED_DIR is not defined thru compile flags
#endif

#ifndef MELT_DYNLIB_DIR
#error MELT_DYNLIB_DIR is not defined thru compile flags
#endif

#ifndef MELT_COMPILE_SCRIPT
#error MELT_COMPILE_SCRIPT  is not defined thru compile flags
#endif

/* *INDENT-OFF* */
static const char melt_private_include_dir[] = MELT_PRIVATE_INCLUDE_DIR;
static const char melt_source_dir[] = MELT_SOURCE_DIR;
static const char melt_generated_dir[] = MELT_GENERATED_DIR;
static const char melt_dynlib_dir[] = MELT_DYNLIB_DIR;
static const char melt_compile_script[] = MELT_COMPILE_SCRIPT;

basilys_ptr_t basilys_globarr[BGLOB__LASTGLOB];
void* basilys_startalz=NULL;
void* basilys_endalz;
char* basilys_curalz;
void** basilys_storalz;

struct callframe_basilys_st* basilys_topframe; 
struct basilyslocalsptr_st* basilys_localtab; 
struct basilysspecial_st* basilys_newspeclist;
struct basilysspecial_st* basilys_oldspeclist;
unsigned long basilys_kilowords_sincefull;
/* number of full & any basilys garbage collections */
unsigned long basilys_nb_full_garbcoll;
unsigned long basilys_nb_garbcoll;
void* basilys_touched_cache[BASILYS_TOUCHED_CACHE_SIZE];
bool basilys_prohibit_garbcoll;

long basilys_dbgcounter;

void (*basilys_extra_scanrout_p)(void);

int basilys_last_global_ix = BGLOB__LASTGLOB;

/* our copying garbage collector needs a vector of basilys_ptr_t to
   scan and an hashtable of basilys_ptr_t which are local variables
   copied into GGC heap;  */
static GTY(()) VEC(basilys_ptr_t,gc) *bscanvec;


struct basilocalsptr_st GTY(()) {
  unsigned char lenix;			/* length is prime, this is the index of length */
  int nbent;
  basilys_ptr_t  GTY((length("basilys_primtab[%h.lenix]"))) ptrtab[FLEXIBLE_DIM];
};

static GTY(()) struct basilocalsptr_st* blocaltab; 




/* *INDENT-ON* */

/* to code case ALL_OBMAG_SPECIAL_CASES: */
#define ALL_OBMAG_SPECIAL_CASES	       	\
         OBMAG_SPEC_FILE:			\
    case OBMAG_SPEC_MPFR:			\
    case OBMAG_SPECPPL_COEFFICIENT:   		\
    case OBMAG_SPECPPL_LINEAR_EXPRESSION:	\
    case OBMAG_SPECPPL_CONSTRAINT:		\
    case OBMAG_SPECPPL_CONSTRAINT_SYSTEM:	\
    case OBMAG_SPECPPL_GENERATOR:		\
    case OBMAG_SPECPPL_GENERATOR_SYSTEM

/* Obstack used for reading names */
static struct obstack bname_obstack;


/* random data for generating hashcodes */
static struct drand48_data randata;

long
basilys_lrand (void)
{
  long lh = 0;
  lrand48_r (&randata, &lh);
  return lh;
}


static inline void
delete_special (struct basilysspecial_st *sp)
{
  switch (sp->discr->object_magic)
    {
    case OBMAG_SPEC_FILE:
      if (sp->val.sp_file)
	{
	  fclose (sp->val.sp_file);
	  sp->val.sp_file = NULL;
	};
      break;
    case OBMAG_SPEC_MPFR:
      if (sp->val.sp_mpfr)
	{
	  mpfr_clear (sp->val.sp_mpfr);
	  free (sp->val.sp_mpfr);
	  sp->val.sp_mpfr = NULL;
	};
      break;
    case OBMAG_SPECPPL_COEFFICIENT:
      if (sp->val.sp_coefficient)
	ppl_delete_Coefficient (sp->val.sp_coefficient);
      sp->val.sp_coefficient = NULL;
      break;
    case OBMAG_SPECPPL_LINEAR_EXPRESSION:
      if (sp->val.sp_linear_expression)
	ppl_delete_Linear_Expression (sp->val.sp_linear_expression);
      sp->val.sp_linear_expression = NULL;
      break;
    case OBMAG_SPECPPL_CONSTRAINT:
      if (sp->val.sp_constraint)
	ppl_delete_Constraint (sp->val.sp_constraint);
      sp->val.sp_constraint = NULL;
      break;
    case OBMAG_SPECPPL_CONSTRAINT_SYSTEM:
      if (sp->val.sp_constraint_system)
	ppl_delete_Constraint_System (sp->val.sp_constraint_system);
      sp->val.sp_constraint_system = NULL;
      break;
    case OBMAG_SPECPPL_GENERATOR:
      if (sp->val.sp_generator)
	ppl_delete_Generator (sp->val.sp_generator);
      sp->val.sp_generator = NULL;
      break;
    case OBMAG_SPECPPL_GENERATOR_SYSTEM:
      if (sp->val.sp_generator_system)
	ppl_delete_Generator_System (sp->val.sp_generator_system);
      sp->val.sp_generator_system = NULL;
      break;
    default:
      break;
    }
}

#define FORWARDED_DISCR (basilysobject_ptr_t)1
static basilys_ptr_t forwarded_copy (basilys_ptr_t);

#ifdef ENABLE_CHECKING
/* only for debugging, to be set from the debugger */
static void *bstrangelocal;
static long nbaddlocalptr;

static FILE *debughack_file;
void *basilys_checkedp_ptr1;
void *basilys_checkedp_ptr2;

#endif


static inline void *
forwarded (void *ptr)
{
  basilys_ptr_t p = ptr;
  if (p && basilys_is_young (p))
    {
      if (p->u_discr == FORWARDED_DISCR)
	p = ((struct basilysforward_st *) p)->forward;
      else
	p = forwarded_copy (p);
    }
  return p;
}

#if ENABLE_CHECKING
#define FORWARDED(P) do {if (P) {				\
      if (debughack_file)					\
	fprintf(debughack_file,"%s:%d forwarded %p\n", 	\
		basename(__FILE__), __LINE__, (void*)(P));	\
      (P) = forwarded((P));} }  while(0)
#else
#define FORWARDED(P) do {if (P) { 		       		\
      (P) = forwarded((P));} }  while(0)
#endif
static void scanning (basilys_ptr_t);


static void
add_localptr (basilys_ptr_t p)
{
  HOST_WIDE_INT ix;
  int h, k;
  long primsiz = basilys_primtab[blocaltab->lenix];
  if (!p)
    return;
#ifdef ENABLE_CHECKING
  nbaddlocalptr++;
  if (p == bstrangelocal)
    {
      debugeprintf ("adding #%ld bstrangelocal %p", nbaddlocalptr,
		    (void *) p);
    }
#endif
  gcc_assert ((void *) p != (void *) FORWARDED_DISCR);
  gcc_assert (primsiz > 0);
  ix = (HOST_WIDE_INT) p;
  ix ^= ((HOST_WIDE_INT) p) >> 11;
  ix &= 0x3fffffff;
  h = (int) ix % primsiz;
  for (k = h; k < primsiz; k++)
    {
      if (!blocaltab->ptrtab[k])
	{
	  blocaltab->ptrtab[k] = p;
	  blocaltab->nbent++;
	  return;
	}
      else if (blocaltab->ptrtab[k] == p)
	return;
    }
  for (k = 0; k < h; k++)
    {
      if (!blocaltab->ptrtab[k])
	{
	  blocaltab->ptrtab[k] = p;
	  blocaltab->nbent++;
	  return;
	}
      else if (blocaltab->ptrtab[k] == p)
	return;
    }
  /* the only way to reach this point is that blocaltab is
     full; this should never happen, since it was allocated bigger
     than the number of locals! */
  gcc_unreachable ();
}


#if ENABLE_CHECKING
/***
 * check our call frames
 ***/
static inline void
check_pointer_at (const char msg[], long count, basilys_ptr_t * pptr,
		  const char *filenam, int lineno)
{
  basilys_ptr_t ptr = *pptr;
  if (!ptr)
    return;
  if (!ptr->u_discr)
    fatal_error
      ("<%s#%ld> corrupted pointer %p (at %p) without discr at %s:%d", msg,
       count, (void *) ptr, (void *) pptr, basename (filenam), lineno);
  switch (ptr->u_discr->object_magic)
    {
    case OBMAG_OBJECT:
    case OBMAG_DECAY:
    case OBMAG_BOX:
    case OBMAG_MULTIPLE:
    case OBMAG_CLOSURE:
    case OBMAG_ROUTINE:
    case OBMAG_LIST:
    case OBMAG_PAIR:
    case OBMAG_TRIPLE:
    case OBMAG_INT:
    case OBMAG_MIXINT:
    case OBMAG_REAL:
    case OBMAG_STRING:
    case OBMAG_STRBUF:
    case OBMAG_TREE:
    case OBMAG_BASICBLOCK:
    case OBMAG_EDGE:
    case OBMAG_MAPOBJECTS:
    case OBMAG_MAPTREES:
    case OBMAG_MAPSTRINGS:
    case OBMAG_MAPBASICBLOCKS:
    case OBMAG_MAPEDGES:
    case ALL_OBMAG_SPECIAL_CASES:
      break;
    default:
      fatal_error ("<%s#%ld> bad pointer %p (at %p) bad magic %d at %s:%d",
		   msg, count, (void *) ptr, (void *) pptr,
		   (int) ptr->u_discr->object_magic, basename (filenam),
		   lineno);
    }
}

static long nbcheckcallframes;
static long thresholdcheckcallframes;


void
basilys_check_call_frames_at (int noyoungflag, const char *msg,
			      const char *filenam, int lineno)
{
  struct callframe_basilys_st *cfram = NULL;
  int nbfram = 0, nbvar = 0;
  nbcheckcallframes++;
  if (!msg)
    msg = "/";
  if (thresholdcheckcallframes > 0
      && nbcheckcallframes > thresholdcheckcallframes)
    {
      debugeprintf
	("start check_call_frames#%ld {%s} from %s:%d",
	 nbcheckcallframes, msg, basename (filenam), lineno);
    }
  for (cfram = basilys_topframe; cfram != NULL; cfram = cfram->prev)
    {
      int varix = 0;
      nbfram++;
      if (cfram->clos)
	{
	  if (noyoungflag && basilys_is_young (cfram->clos))
	    fatal_error
	      ("bad frame <%s#%ld> unexpected young closure %p in frame %p at %s:%d",
	       msg, nbcheckcallframes,
	       (void *) cfram->clos, (void *) cfram, basename (filenam),
	       lineno);

	  check_pointer_at (msg, nbcheckcallframes,
			    (basilys_ptr_t *) (void *) &cfram->clos, filenam,
			    lineno);
	  if (cfram->clos->discr->object_magic != OBMAG_CLOSURE)
	    fatal_error
	      ("bad frame <%s#%ld> invalid closure %p in frame %p at %s:%d",
	       msg, nbcheckcallframes,
	       (void *) cfram->clos, (void *) cfram, basename (filenam),
	       lineno);
	}
      for (varix = ((int) cfram->nbvar) - 1; varix >= 0; varix--)
	{
	  nbvar++;
	  if (noyoungflag && cfram->varptr[varix] != NULL
	      && basilys_is_young (cfram->varptr[varix]))
	    fatal_error
	      ("bad frame <%s#%ld> unexpected young pointer %p in frame %p at %s:%d",
	       msg, nbcheckcallframes, (void *) cfram->varptr[varix],
	       (void *) cfram, basename (filenam), lineno);

	  check_pointer_at (msg, nbcheckcallframes, &cfram->varptr[varix],
			    filenam, lineno);
	}
    }
  if (thresholdcheckcallframes > 0
      && nbcheckcallframes > thresholdcheckcallframes)
    debugeprintf ("end check_call_frames#%ld {%s} %d frames/%d vars %s:%d",
		  nbcheckcallframes, msg, nbfram, nbvar, basename (filenam),
		  lineno);
  if (debughack_file)
    {
      fprintf (debughack_file,
	       "check_call_frames#%ld {%s} %d frames/%d vars %s:%d\n",
	       nbcheckcallframes, msg, nbfram, nbvar, basename (filenam),
	       lineno);
      fflush (debughack_file);
    }
}

void
basilys_caught_assign_at (void *ptr, const char *fil, int lin)
{
  if (debughack_file)
    {
      fprintf (debughack_file, "caught assign %p at %s:%d\n", ptr,
	       basename (fil), lin);
      fflush (debughack_file);
    }
  debugeprintf ("caught assign %p at %s:%d", ptr, basename (fil), lin);
}

static long nbcbreak;

void
basilys_cbreak_at (const char *msg, const char *fil, int lin)
{
  nbcbreak++;
  if (debughack_file)
    {
      fprintf (debughack_file, "CBREAK#%ld AT %s:%d - %s\n", nbcbreak,
	       basename (fil), lin, msg);
      fflush (debughack_file);
    };
  debugeprintf_raw ("%s:%d: CBREAK#%ld %s\n", basename (fil), lin, nbcbreak,
		    msg);
}

#endif

/***
 * our copying garbage collector 
 ***/
void
basilys_garbcoll (size_t wanted, bool needfull)
{
  long primix = 0;
  int locdepth = 0;
  int nbloc = 0;
  int nbglob = 0;
  int locsiz = 0;
  int ix = 0;
  struct callframe_basilys_st *cfram = NULL;
  basilys_ptr_t *storp = NULL;
  struct basilysspecial_st *specp = NULL;
  struct basilysspecial_st **prevspecptr = NULL;
  struct basilysspecial_st *nextspecp = NULL;
  if (basilys_prohibit_garbcoll)
    fatal_error ("basilys garbage collection prohibited");
  basilys_nb_garbcoll++;
  basilys_check_call_frames (BASILYS_ANYWHERE, "before garbage collection");
  gcc_assert ((char *) basilys_startalz < (char *) basilys_endalz);
  gcc_assert ((char *) basilys_curalz >= (char *) basilys_startalz
	      && (char *) basilys_curalz < (char *) basilys_storalz);
  gcc_assert ((char *) basilys_storalz < (char *) basilys_endalz);
  bscanvec = VEC_alloc (basilys_ptr_t, gc, 1024 + 32 * MINOR_SIZE_KILOWORD);
  wanted += wanted / 4 + MINOR_SIZE_KILOWORD * 1000;
  wanted |= 0x3fff;
  wanted++;
  if (wanted < MINOR_SIZE_KILOWORD * sizeof (void *) * 1024)
    wanted = MINOR_SIZE_KILOWORD * sizeof (void *) * 1024;
  /* compute number of locals and depth of call stack */
  nbglob = BGLOB__LASTGLOB;
  for (cfram = basilys_topframe; cfram != NULL; cfram = cfram->prev)
    {
      locdepth++;
      /* we should never have more than a few thousand locals in a
         call frame, so we check this */
      gcc_assert (cfram->nbvar < (int) BASILYS_MAXNBLOCALVAR);
      nbloc += cfram->nbvar;
    }
  locsiz = 200 + (5 * (locdepth + nbloc + nbglob + 100)) / 4;
  locsiz |= 0xff;
  for (primix = 5;
       basilys_primtab[primix] > 0
       && basilys_primtab[primix] <= locsiz; primix++);
  locsiz = basilys_primtab[primix];
  gcc_assert (locsiz > 10);
  blocaltab =
    ggc_alloc_cleared (sizeof (struct basilocalsptr_st) +
		       locsiz * sizeof (void *));
  blocaltab->lenix = primix;
  for (ix = 0; ix < BGLOB__LASTGLOB; ix++)
    FORWARDED (basilys_globarr[ix]);
  if (basilys_extra_scanrout_p)
    (*basilys_extra_scanrout_p) ();
  for (cfram = basilys_topframe; cfram != NULL; cfram = cfram->prev)
    {
      int varix;
      if (cfram->clos)
	{
	  FORWARDED (cfram->clos);
	  add_localptr ((basilys_ptr_t) (cfram->clos));
	}
      for (varix = ((int) cfram->nbvar) - 1; varix >= 0; varix--)
	{
	  if (!cfram->varptr[varix])
	    continue;
	  FORWARDED (cfram->varptr[varix]);
	  add_localptr (cfram->varptr[varix]);
	}
    };
  /* scan the store list */
  for (storp = (basilys_ptr_t *) basilys_storalz;
       (char *) storp < (char *) basilys_endalz; storp++)
    {
      if (*storp)
	scanning (*storp);
    }
  memset (basilys_touched_cache, 0, sizeof (basilys_touched_cache));
  /* sort of Chesney loop */
  while (!VEC_empty (basilys_ptr_t, bscanvec))
    {
      basilys_ptr_t p = VEC_pop (basilys_ptr_t, bscanvec);
      if (!p)
	continue;
#if ENABLE_CHECKING
      if (debughack_file)
	fprintf (debughack_file, "chesney scan %p\n", (void *) p);
#endif
      scanning (p);
    }
  /* delete every unmarked special on the new list and clear it */
  for (specp = basilys_newspeclist; specp; specp = specp->nextspec)
    {
      gcc_assert (basilys_is_young (specp));
      if (specp->mark)
	continue;
      delete_special (specp);
    }
  basilys_newspeclist = NULL;
  /* free the previous young zone and allocate a new one */
#if ENABLE_CHECKING
  if (debughack_file)
    {
      fprintf (debughack_file,
	       "%s:%d free previous young %p - %p GC#%ld\n",
	       basename (__FILE__), __LINE__, basilys_startalz,
	       basilys_endalz, basilys_nb_garbcoll);
      fflush (debughack_file);
    }
  memset (basilys_startalz, 0,
	  (char *) basilys_endalz - (char *) basilys_startalz);
#endif
  free (basilys_startalz);
  basilys_startalz = basilys_endalz = basilys_curalz = NULL;
  basilys_storalz = NULL;
  basilys_kilowords_sincefull += wanted / (1024 * sizeof (void *));
  if (basilys_kilowords_sincefull >
      (unsigned long) MINOR_SIZE_KILOWORD * FULL_FREQ)
    needfull = TRUE;
  basilys_startalz = basilys_curalz =
    xcalloc (sizeof (void *), wanted / sizeof (void *));
  basilys_endalz = (char *) basilys_curalz + wanted;
  basilys_storalz = ((void **) basilys_endalz) - 2;
  if (needfull)
    {
      bool wasforced = ggc_force_collect;
      basilys_nb_full_garbcoll++;
      debugeprintf ("basilys_garbcoll #%ld fullgarbcoll #%ld",
		    basilys_nb_garbcoll, basilys_nb_full_garbcoll);
      /* clear marks on the old spec list */
      for (specp = basilys_oldspeclist; specp; specp = specp->nextspec)
	specp->mark = 0;
      /* force major collection */
      ggc_force_collect = true;
      ggc_collect ();
      ggc_force_collect = wasforced;
      /* delete the unmarked spec */
      prevspecptr = &basilys_oldspeclist;
      for (specp = basilys_oldspeclist; specp; specp = nextspecp)
	{
	  nextspecp = specp->nextspec;
	  if (specp->mark)
	    {
	      prevspecptr = &specp->nextspec;
	      continue;
	    }
	  delete_special (specp);
	  memset (specp, 0, sizeof (*specp));
	  ggc_free (specp);
	  *prevspecptr = nextspecp;
	}
      basilys_kilowords_sincefull = 0;
    }
  ggc_free (blocaltab);
  blocaltab = NULL;
  ggc_free (bscanvec);
  bscanvec = NULL;
  basilys_check_call_frames (BASILYS_NOYOUNG, "after garbage collection");
}


static basilys_ptr_t
forwarded_copy (basilys_ptr_t p)
{
  basilys_ptr_t n = 0;
  int mag = 0;
  gcc_assert (basilys_is_young (p));
  gcc_assert (p->u_discr && p->u_discr != FORWARDED_DISCR);
  if (p->u_discr->obj_class == FORWARDED_DISCR)
    mag =
      ((basilysobject_ptr_t)
       (((struct basilysforward_st *) p->u_discr)->forward))->object_magic;
  else
    mag = p->u_discr->object_magic;
  switch (mag)
    {
    case OBMAG_OBJECT:
      {
	struct basilysobject_st *src = (void *) p;
	struct basilysobject_st *dst =
	  ggc_alloc_cleared (offsetof (struct basilysobject_st,
				       obj__tabfields));
	unsigned oblen = src->obj_len;
	int ix;
	*dst = *src;
	if (oblen > 0)
	  {
	    dst->obj_vartab = ggc_alloc_cleared (sizeof (void *) * oblen);
	    for (ix = (int) oblen - 1; ix >= 0; ix--)
	      dst->obj_vartab[ix] = src->obj_vartab[ix];
	  }
	else
	  dst->obj_vartab = NULL;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_DECAY:
      {
	struct basilysdecay_st *src = (void *) p;
	struct basilysdecay_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysdecay_st));
	*dst = *src;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_BOX:
      {
	struct basilysbox_st *src = (void *) p;
	struct basilysbox_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysbox_st));
	*dst = *src;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_MULTIPLE:
      {
	struct basilysmultiple_st *src = (void *) p;
	unsigned nbv = src->nbval;
	int ix;
	struct basilysmultiple_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysmultiple_st) +
			     nbv * sizeof (void *));
	*dst = *src;
	for (ix = (int) nbv; ix >= 0; ix--)
	  dst->tabval[ix] = src->tabval[ix];
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_CLOSURE:
      {
	struct basilysclosure_st *src = (void *) p;
	unsigned nbv = src->nbval;
	int ix;
	struct basilysclosure_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysclosure_st) +
			     nbv * sizeof (void *));
	*dst = *src;
	for (ix = (int) nbv; ix >= 0; ix--)
	  dst->tabval[ix] = src->tabval[ix];
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_ROUTINE:
      {
	struct basilysroutine_st *src = (void *) p;
	unsigned nbv = src->nbval;
	int ix;
	struct basilysroutine_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysroutine_st) +
			     nbv * sizeof (void *));
	*dst = *src;
	for (ix = (int) nbv; ix >= 0; ix--)
	  dst->tabval[ix] = src->tabval[ix];
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_LIST:
      {
	struct basilyslist_st *src = (void *) p;
	struct basilyslist_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilyslist_st));
	*dst = *src;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_PAIR:
      {
	struct basilyspair_st *src = (void *) p;
	struct basilyspair_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilyspair_st));
	*dst = *src;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_TRIPLE:
      {
	struct basilystriple_st *src = (void *) p;
	struct basilystriple_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilystriple_st));
	*dst = *src;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_INT:
      {
	struct basilysint_st *src = (void *) p;
	struct basilysint_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysint_st));
	*dst = *src;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_MIXINT:
      {
	struct basilysmixint_st *src = (void *) p;
	struct basilysmixint_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysmixint_st));
	*dst = *src;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_REAL:
      {
	struct basilysreal_st *src = (void *) p;
	struct basilysreal_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysreal_st));
	*dst = *src;
	n = (basilys_ptr_t) dst;
	break;
      }
    case ALL_OBMAG_SPECIAL_CASES:
      {
	struct basilysspecial_st *src = (void *) p;
	struct basilysspecial_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysspecial_st));
	*dst = *src;
	/* add the new copy to the old (major) special list */
	dst->nextspec = basilys_oldspeclist;
	basilys_oldspeclist = dst;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_STRING:
      {
	struct basilysstring_st *src = (void *) p;
	int srclen = strlen (src->val);
	struct basilysstring_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysstring_st) + srclen + 1);
	*dst = *src;
	memcpy (dst->val, src->val, srclen);
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_STRBUF:
      {
	struct basilysstrbuf_st *src = (void *) p;
	unsigned blen = basilys_primtab[src->buflenix];
	struct basilysstrbuf_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysstrbuf_st));
	*dst = *src;
	if (blen > 0)
	  {
	    dst->bufzn = ggc_alloc_cleared (1 + blen);
	    memcpy (dst->bufzn, src->bufzn, blen);
	  }
	else
	  dst->bufzn = NULL;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_TREE:
      {
	struct basilystree_st *src = (void *) p;
	struct basilystree_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilystree_st));
	*dst = *src;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_BASICBLOCK:
      {
	struct basilysbasicblock_st *src = (void *) p;
	struct basilysbasicblock_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysbasicblock_st));
	*dst = *src;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_EDGE:
      {
	struct basilysedge_st *src = (void *) p;
	struct basilysedge_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysedge_st));
	*dst = *src;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_MAPOBJECTS:
      {
	struct basilysmapobjects_st *src = (void *) p;
	int siz = basilys_primtab[src->lenix];
	struct basilysmapobjects_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysmapobjects_st));
	*dst = *src;
	if (siz > 0 && src->entab)
	  {
	    dst->entab = ggc_alloc_cleared (siz * sizeof (dst->entab[0]));
	    memcpy (dst->entab, src->entab, siz * sizeof (dst->entab[0]));
	  }
	else
	  dst->entab = NULL;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_MAPTREES:
      {
	struct basilysmaptrees_st *src = (void *) p;
	int siz = basilys_primtab[src->lenix];
	struct basilysmaptrees_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysmaptrees_st));
	*dst = *src;
	if (siz > 0 && src->entab)
	  {
	    dst->entab = ggc_alloc_cleared (siz * sizeof (dst->entab[0]));
	    memcpy (dst->entab, src->entab, siz * sizeof (dst->entab[0]));
	  }
	else
	  dst->entab = NULL;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_MAPSTRINGS:
      {
	struct basilysmapstrings_st *src = (void *) p;
	int siz = basilys_primtab[src->lenix];
	struct basilysmapstrings_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysmapstrings_st));
	*dst = *src;
	if (siz > 0 && src->entab)
	  {
	    dst->entab = ggc_alloc_cleared (siz * sizeof (dst->entab[0]));
	    memcpy (dst->entab, src->entab, siz * sizeof (dst->entab[0]));
	  }
	else
	  dst->entab = NULL;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_MAPBASICBLOCKS:
      {
	struct basilysmapbasicblocks_st *src = (void *) p;
	int siz = basilys_primtab[src->lenix];
	struct basilysmapbasicblocks_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysmapbasicblocks_st));
	*dst = *src;
	if (siz > 0 && src->entab)
	  {
	    dst->entab = ggc_alloc_cleared (siz * sizeof (dst->entab[0]));
	    memcpy (dst->entab, src->entab, siz * sizeof (dst->entab[0]));
	  }
	else
	  dst->entab = NULL;
	n = (basilys_ptr_t) dst;
	break;
      }
    case OBMAG_MAPEDGES:
      {
	struct basilysmapedges_st *src = (void *) p;
	int siz = basilys_primtab[src->lenix];
	struct basilysmapedges_st *dst =
	  ggc_alloc_cleared (sizeof (struct basilysmapedges_st));
	*dst = *src;
	if (siz > 0 && src->entab)
	  {
	    dst->entab = ggc_alloc_cleared (siz * sizeof (dst->entab[0]));
	    memcpy (dst->entab, src->entab, siz * sizeof (dst->entab[0]));
	  }
	else
	  dst->entab = NULL;
	n = (basilys_ptr_t) dst;
	break;
      }
    default:
      debugeprintf ("forward invalid p=%p discr=%p magic=%d",
		    (void *) p, (void *) p->u_discr, mag);
      gcc_unreachable ();
    }
  if (n)
    {
      p->u_forward.discr = FORWARDED_DISCR;
      p->u_forward.forward = n;
#ifdef ENABLE_CHECKING
      if (debughack_file)
	{
	  fprintf (debughack_file, "forwarded pushing %p to scan\n",
		   (void *) n);
	}
#endif
      VEC_safe_push (basilys_ptr_t, gc, bscanvec, n);
    }
  return n;
  /* end of forwarded_copy */
}



/* the scanning routine is mostly chesney like; however some types,
   including objects, strbuf, stringmaps, objectmaps, all the other
   *maps, contain a pointer to a non value; this pointer should be
   carefully updated if it was young */
static void
scanning (basilys_ptr_t p)
{
  if (!p)
    return;
  gcc_assert (p != (void *) 1);
#if ENABLE_CHECKING
  if (debughack_file)
    {
      fprintf (debughack_file, "scanning %p\n", (void *) p);
    }
#endif
  gcc_assert (p->u_discr && p->u_discr != (basilysobject_ptr_t) 1);
  FORWARDED (p->u_discr);
  gcc_assert (!basilys_is_young (p));
  switch (p->u_discr->object_magic)
    {
    case OBMAG_OBJECT:
      {
	int ix;
	struct basilysobject_st *src = (void *) p;
	if (basilys_is_young (src->obj_vartab))
	  {
	    basilys_ptr_t *newtab =
	      ggc_alloc_cleared (sizeof (void *) * src->obj_len);
	    int ix;
	    for (ix = (int) src->obj_len - 1; ix >= 0; ix--)
	      newtab[ix] = src->obj_vartab[ix];
	    src->obj_vartab = newtab;
	  }
	for (ix = (int) (src->obj_len) - 1; ix >= 0; ix--)
	  FORWARDED (src->obj_vartab[ix]);
	break;
      }
    case OBMAG_DECAY:
      {
	struct basilysdecay_st *src = (void *) p;
	FORWARDED (src->val);
	break;
      }
    case OBMAG_BOX:
      {
	struct basilysbox_st *src = (void *) p;
	FORWARDED (src->val);
	break;
      }
    case OBMAG_MULTIPLE:
      {
	struct basilysmultiple_st *src = (void *) p;
	unsigned nbval = src->nbval;
	int ix;
	for (ix = (int) nbval - 1; ix >= 0; ix--)
	  FORWARDED (src->tabval[ix]);
	break;
      }
    case OBMAG_CLOSURE:
      {
	struct basilysclosure_st *src = (void *) p;
	unsigned nbval = src->nbval;
	int ix;
	FORWARDED (src->rout);
	for (ix = (int) nbval - 1; ix >= 0; ix--)
	  FORWARDED (src->tabval[ix]);
	break;
      }
    case OBMAG_ROUTINE:
      {
	struct basilysroutine_st *src = (void *) p;
	unsigned nbval = src->nbval;
	int ix;
	for (ix = (int) nbval - 1; ix >= 0; ix--)
	  FORWARDED (src->tabval[ix]);
	break;
      }
    case OBMAG_LIST:
      {
	struct basilyslist_st *src = (void *) p;
	FORWARDED (src->first);
	FORWARDED (src->last);
	break;
      }
    case OBMAG_PAIR:
      {
	struct basilyspair_st *src = (void *) p;
	FORWARDED (src->hd);
	FORWARDED (src->tl);
	break;
      }
    case OBMAG_TRIPLE:
      {
	struct basilystriple_st *src = (void *) p;
	FORWARDED (src->hd);
	FORWARDED (src->mi);
	FORWARDED (src->tl);
	break;
      }
    case ALL_OBMAG_SPECIAL_CASES:
      {
	struct basilysspecial_st *src = (void *) p;
	src->mark = 1;
	break;
      }
    case OBMAG_MAPOBJECTS:
      {
	struct basilysmapobjects_st *src = (void *) p;
	int siz, ix;
	if (!src->entab)
	  break;
	siz = basilys_primtab[src->lenix];
	gcc_assert (siz > 0);
	if (basilys_is_young (src->entab))
	  {
	    struct entryobjectsbasilys_st *newtab =
	      ggc_alloc_cleared (siz *
				 sizeof (struct entryobjectsbasilys_st));
	    memcpy (newtab, src->entab,
		    siz * sizeof (struct entryobjectsbasilys_st));
	    src->entab = newtab;
	  }
	for (ix = 0; ix < siz; ix++)
	  {
	    basilysobject_ptr_t at = src->entab[ix].e_at;
	    if (!at || at == (void *) 1)
	      {
		src->entab[ix].e_va = NULL;
		continue;
	      }
	    FORWARDED (at);
	    src->entab[ix].e_at = at;
	    FORWARDED (src->entab[ix].e_va);
	  }
	break;
      }
    case OBMAG_MAPTREES:
      {
	struct basilysmaptrees_st *src = (void *) p;
	int ix, siz;
	if (!src->entab)
	  break;
	siz = basilys_primtab[src->lenix];
	gcc_assert (siz > 0);
	if (basilys_is_young (src->entab))
	  {
	    struct entrytreesbasilys_st *newtab =
	      ggc_alloc_cleared (siz * sizeof (struct entrytreesbasilys_st));
	    memcpy (newtab, src->entab,
		    siz * sizeof (struct entrytreesbasilys_st));
	    src->entab = newtab;
	  }
	for (ix = 0; ix < siz; ix++)
	  {
	    tree at = src->entab[ix].e_at;
	    if (!at || at == (void *) 1)
	      {
		src->entab[ix].e_va = NULL;
		continue;
	      }
	    FORWARDED (src->entab[ix].e_va);
	  }
	break;
      }
    case OBMAG_MAPSTRINGS:
      {
	struct basilysmapstrings_st *src = (void *) p;
	int ix, siz;
	if (!src->entab)
	  break;
	siz = basilys_primtab[src->lenix];
	gcc_assert (siz > 0);
	if (basilys_is_young (src->entab))
	  {
	    struct entrystringsbasilys_st *newtab
	      =
	      ggc_alloc_cleared (siz *
				 sizeof (struct entrystringsbasilys_st));
	    memcpy (newtab, src->entab,
		    siz * sizeof (struct entrystringsbasilys_st));
	    src->entab = newtab;
	  }
	for (ix = 0; ix < siz; ix++)
	  {
	    char *at = src->entab[ix].e_at;
	    if (!at || at == (void *) 1)
	      {
		src->entab[ix].e_va = NULL;
		continue;
	      }
	    if (basilys_is_young (at))
	      src->entab[ix].e_at = (char *) ggc_strdup (at);
	    FORWARDED (src->entab[ix].e_va);
	  }
	break;
      }
    case OBMAG_MAPBASICBLOCKS:
      {
	struct basilysmapbasicblocks_st *src = (void *) p;
	int ix, siz;
	if (!src->entab)
	  break;
	siz = basilys_primtab[src->lenix];
	gcc_assert (siz > 0);
	if (basilys_is_young (src->entab))
	  {
	    struct entrybasicblocksbasilys_st *newtab
	      =
	      ggc_alloc_cleared (siz *
				 sizeof (struct entrybasicblocksbasilys_st));
	    memcpy (newtab, src->entab,
		    siz * sizeof (struct entrybasicblocksbasilys_st));
	    src->entab = newtab;
	  }
	for (ix = 0; ix < siz; ix++)
	  {
	    basic_block at = src->entab[ix].e_at;
	    if (!at || at == (void *) 1)
	      {
		src->entab[ix].e_va = NULL;
		continue;
	      }
	    FORWARDED (src->entab[ix].e_va);
	  }
	break;
      }
    case OBMAG_MAPEDGES:
      {
	struct basilysmapedges_st *src = (void *) p;
	int siz, ix;
	if (!src->entab)
	  break;
	siz = basilys_primtab[src->lenix];
	gcc_assert (siz > 0);
	if (basilys_is_young (src->entab))
	  {
	    struct entryedgesbasilys_st *newtab
	      =
	      ggc_alloc_cleared (siz * sizeof (struct entryedgesbasilys_st));
	    memcpy (newtab, src->entab,
		    siz * sizeof (struct entryedgesbasilys_st));
	    src->entab = newtab;
	  }
	for (ix = 0; ix < siz; ix++)
	  {
	    edge at = src->entab[ix].e_at;
	    if (!at || at == (void *) 1)
	      {
		src->entab[ix].e_va = NULL;
		continue;
	      }
	    FORWARDED (src->entab[ix].e_va);
	  }
	break;
      }
    case OBMAG_MIXINT:
      {
	struct basilysmixint_st *src = (void *) p;
	FORWARDED (src->ptrval);
	break;
      }
    case OBMAG_STRBUF:
      {
	struct basilysstrbuf_st *src = (void *) p;
	char *oldbufzn = src->bufzn;
	if (basilys_is_young (oldbufzn))
	  {
	    int bsiz = basilys_primtab[src->buflenix];
	    if (bsiz > 0)
	      {
		char *newbufzn = ggc_alloc_cleared (bsiz + 1);
		memcpy (newbufzn, oldbufzn, bsiz);
		src->bufzn = newbufzn;
		memset (oldbufzn, 0, bsiz);
	      }
	    else
	      src->bufzn = NULL;
	  }
	break;
      }
    case OBMAG_INT:
    case OBMAG_REAL:
    case OBMAG_STRING:
    case OBMAG_TREE:
    case OBMAG_BASICBLOCK:
    case OBMAG_EDGE:
      break;
    default:
      gcc_unreachable ();
    }
}






/** array of about 190 primes gotten by shell command 
    primes 3 2000000000 | awk '($1>p+p/8){print $1, ","; p=$1}'  **/
const long basilys_primtab[256] = {
  0,				/* the first entry indexed #0 is 0 to never be used */
  3, 5, 7, 11, 13, 17, 23, 29, 37, 43, 53, 61, 71, 83, 97, 113,
  131, 149, 173, 197, 223, 251, 283, 331, 373, 421, 479, 541,
  613, 691, 787, 887, 1009, 1151, 1297, 1471, 1657, 1867, 2111,
  2377, 2677, 3019, 3407, 3833, 4327, 4871, 5483, 6173, 6947,
  7817, 8803, 9907, 11149, 12547, 14143, 15913, 17903, 20143,
  22669, 25523, 28723, 32321, 36373, 40927, 46049, 51817,
  58309, 65599, 73819, 83047, 93463, 105167, 118343, 133153,
  149803, 168533, 189613, 213319, 239999, 270001, 303767,
  341743, 384469, 432539, 486617, 547453, 615887, 692893,
  779507, 876947, 986567, 1109891, 1248631, 1404721, 1580339,
  1777891, 2000143, 2250163, 2531443, 2847893, 3203909,
  3604417, 4054987, 4561877, 5132117, 5773679, 6495389,
  7307323, 8220743, 9248339, 10404403, 11704963, 13168091,
  14814103, 16665881, 18749123, 21092779, 23729411, 26695609,
  30032573, 33786659, 38010019, 42761287, 48106453, 54119761,
  60884741, 68495347, 77057297, 86689469, 97525661, 109716379,
  123430961, 138859837, 156217333, 175744531, 197712607,
  222426683, 250230023, 281508827, 316697431, 356284619,
  400820209, 450922753, 507288107, 570699121, 642036517,
  722291083, 812577517, 914149741,
#if HOST_BITS_PER_LONG >= 64
  1028418463, 1156970821, 1301592203,
  1464291239, 1647327679, 1853243677, 2084899139, 2345511541,
  2638700497, 2968538081, 3339605383, 3757056091, 4226688133,
  4755024167, 5349402193, 6018077509, 6770337239, 7616629399,
  8568708139, 9639796667, 10844771263, 12200367671,
  13725413633, 15441090347, 17371226651, 19542629983,
  21985458749, 24733641113, 27825346259, 31303514549,
  35216453869, 39618510629, 44570824481, 50142177559,
#endif
  0, 0
};

/* index of entry to get or add an attribute in an mapobject (or -1 on error) */
static inline int
unsafe_index_mapobject (struct entryobjectsbasilys_st *tab,
			basilysobject_ptr_t attr, int siz)
{
  int da = 0, ix = 0, frix = -1;
  unsigned h = 0;
  if (!tab)
    return -1;
  da = attr->obj_class->object_magic;
  if (da == OBMAG_OBJECT)
    h = ((struct basilysobject_st *) attr)->obj_hash;
  else
    return -1;
  h = h % siz;
  for (ix = h; ix < siz; ix++)
    {
      basilysobject_ptr_t curat = tab[ix].e_at;
      if (curat == attr)
	return ix;
      else if (curat == (void *) HTAB_DELETED_ENTRY)
	{
	  if (frix < 0)
	    frix = ix;
	}
      else if (!curat)
	{
	  if (frix < 0)
	    frix = ix;
	  return frix;
	}
    }
  for (ix = 0; ix < (int) h; ix++)
    {
      basilysobject_ptr_t curat = tab[ix].e_at;
      if (curat == attr)
	return ix;
      else if (curat == (void *) HTAB_DELETED_ENTRY)
	{
	  if (frix < 0)
	    frix = ix;
	}
      else if (!curat)
	{
	  if (frix < 0)
	    frix = ix;
	  return frix;
	}
    }
  return -1;			/* entirely full, should not happen */
}


basilys_ptr_t
basilysgc_new_int (basilysobject_ptr_t discr_p, long num)
{
  BASILYS_ENTERFRAME (2, NULL);
#define newint curfram__.varptr[0]
#define discrv  curfram__.varptr[1]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define int_newint ((struct basilysint_st*)(newint))
  newint = NULL;
  discrv = (void *) discr_p;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_INT)
    goto end;
  newint = basilysgc_allocate (sizeof (struct basilysint_st), 0);
  int_newint->discr = object_discrv;
  int_newint->val = num;
end:
  BASILYS_EXITFRAME ();
  return newint;
#undef newint
#undef discrv
#undef int_newint
#undef object_discrv
}


basilys_ptr_t
basilysgc_new_mixint (basilysobject_ptr_t discr_p,
		      basilys_ptr_t val_p, long num)
{
  BASILYS_ENTERFRAME (3, NULL);
#define newmix  curfram__.varptr[0]
#define discrv  curfram__.varptr[1]
#define valv    curfram__.varptr[2]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define mix_newmix ((struct basilysmixint_st*)(newmix))
  newmix = NULL;
  discrv = (void *) discr_p;
  valv = val_p;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_MIXINT)
    goto end;
  newmix = basilysgc_allocate (sizeof (struct basilysmixint_st), 0);
  mix_newmix->discr = object_discrv;
  mix_newmix->intval = num;
  mix_newmix->ptrval = valv;
end:
  BASILYS_EXITFRAME ();
  return newmix;
#undef newmix
#undef valv
#undef discrv
#undef mix_newmix
#undef object_discrv
}


/* allocate a new routine object of given DISCR and of length LEN,
   with a DESCR-iptive string a a PROC-edure */
basilysroutine_ptr_t
basilysgc_new_routine (basilysobject_ptr_t discr_p,
		       unsigned len, const char *descr,
		       basilysroutfun_t * proc)
{
  union
  {
    long fad[1 + sizeof (basilysroutfun_t *) / sizeof (long)];
    basilysroutfun_t *fproc;
  } un;
  BASILYS_ENTERFRAME (2, NULL);
#define newroutv curfram__.varptr[0]
#define discrv  curfram__.varptr[1]
#define obj_discrv ((basilysobject_ptr_t)(discrv))
#define rou_newroutv ((basilysroutine_ptr_t)(newroutv))
  newroutv = NULL;
  discrv = discr_p;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT
      || obj_discrv->object_magic != OBMAG_ROUTINE || !descr || !descr[0]
      || !proc || len > BASILYS_MAXLEN)
    goto end;
  newroutv =
    basilysgc_allocate (sizeof (struct basilysroutine_st),
			len * sizeof (void *));
  rou_newroutv->discr = discrv;
  rou_newroutv->nbval = len;
  memset (&un, 0, sizeof (un));
  un.fproc = proc;
  memcpy (rou_newroutv->routaddr, un.fad, sizeof (rou_newroutv->routaddr));
  strncpy (rou_newroutv->routdescr, descr, BASILYS_ROUTDESCR_LEN - 1);
  rou_newroutv->routdescr[BASILYS_ROUTDESCR_LEN - 1] = (char) 0;
end:
  BASILYS_EXITFRAME ();
  return newroutv;
#undef newroutv
#undef discrv
#undef obj_discrv
#undef rou_newroutv
}

basilysclosure_ptr_t
basilysgc_new_closure (basilysobject_ptr_t discr_p,
		       basilysroutine_ptr_t rout_p, unsigned len)
{
  BASILYS_ENTERFRAME (3, NULL);
#define newclosv  curfram__.varptr[0]
#define discrv    curfram__.varptr[1]
#define routv     curfram__.varptr[2]
#define clo_newclosv ((basilysclosure_ptr_t)(newclosv))
#define obj_discrv   ((basilysobject_ptr_t)(discrv))
#define rou_routv    ((basilysroutine_ptr_t)(routv))
  discrv = discr_p;
  routv = rout_p;
  newclosv = NULL;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT
      || obj_discrv->object_magic != OBMAG_CLOSURE
      || basilys_magic_discr (routv) != OBMAG_ROUTINE || len > BASILYS_MAXLEN)
    goto end;
  newclosv =
    basilysgc_allocate (sizeof (struct basilysclosure_st),
			sizeof (void *) * len);
  clo_newclosv->discr = discrv;
  clo_newclosv->rout = routv;
  clo_newclosv->nbval = len;
end:
  BASILYS_EXITFRAME ();
  return newclosv;
#undef newclosv
#undef discrv
#undef routv
#undef clo_newclosv
#undef obj_discrv
#undef rou_routv
}



struct basilysstrbuf_st *
basilysgc_new_strbuf (basilysobject_ptr_t discr_p, const char *str)
{
  int slen = 0, blen = 0, ix = 0;
  BASILYS_ENTERFRAME (2, NULL);
#define newbufv  curfram__.varptr[0]
#define discrv   curfram__.varptr[1]
#define buf_newbufv ((struct basilysstrbuf_st*)(newbufv))
  discrv = discr_p;
  newbufv = NULL;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (((basilysobject_ptr_t) (discrv))->object_magic != OBMAG_STRBUF)
    goto end;
  if (str)
    slen = strlen (str);
  gcc_assert (slen < BASILYS_MAXLEN);
  slen += slen / 5 + 40;
  for (ix = 2; (blen = basilys_primtab[ix]) != 0 && blen < slen; ix++);
  gcc_assert (blen != 0);
  newbufv =
    basilysgc_allocate (offsetof
			(struct basilysstrbuf_st, buf_space), blen + 1);
  buf_newbufv->discr = discrv;
  buf_newbufv->bufzn = buf_newbufv->buf_space;
  buf_newbufv->buflenix = ix;
  buf_newbufv->bufstart = 0;
  if (str)
    {
      strcpy (buf_newbufv->bufzn, str);
      buf_newbufv->bufend = strlen (str);
    }
  else
    buf_newbufv->bufend = 0;
end:
  BASILYS_EXITFRAME ();
  return newbufv;
#undef newbufv
#undef discrv
#undef buf_newbufv
}


void
basilysgc_add_strbuf_raw (struct basilysstrbuf_st *strbuf_p, const char *str)
{
#ifdef ENABLE_CHECKING
  static long addcount;
#endif
  int slen = 0, blen = 0;
  BASILYS_ENTERFRAME (2, NULL);
#define strbufv  curfram__.varptr[0]
#define buf_strbufv  ((struct basilysstrbuf_st*)(strbufv))
  strbufv = strbuf_p;
  if (!str)
    goto end;
  if (basilys_magic_discr (strbufv) != OBMAG_STRBUF)
    goto end;
  gcc_assert (!basilys_is_young ((void *) (char *) str));
  slen = strlen (str);
  blen = basilys_primtab[buf_strbufv->buflenix];
  gcc_assert (blen > 0);
#ifdef ENABLE_CHECKING
  addcount++;
#endif
  gcc_assert (buf_strbufv->bufstart <= buf_strbufv->bufend
	      && buf_strbufv->bufend < (unsigned) blen);
  if ((int) buf_strbufv->bufend + slen + 2 < blen)
    {				/* simple case, just copy at end */
      strcpy (buf_strbufv->bufzn + buf_strbufv->bufend, str);
      buf_strbufv->bufend += slen;
      buf_strbufv->bufzn[buf_strbufv->bufend] = 0;
    }
  else
    if ((int) buf_strbufv->bufstart > (int) 0
	&& (int) buf_strbufv->bufend -
	(int) buf_strbufv->bufstart + (int) slen + 2 < (int) blen)
    {				/* should move the buffer to fit */
      int siz = buf_strbufv->bufend - buf_strbufv->bufstart;
      gcc_assert (siz > 0);
      memmove (buf_strbufv->bufzn,
	       buf_strbufv->bufzn + buf_strbufv->bufstart, siz);
      buf_strbufv->bufstart = 0;
      strcpy (buf_strbufv->bufzn + siz, str);
      buf_strbufv->bufend = siz + slen;
      buf_strbufv->bufzn[buf_strbufv->bufend] = 0;
    }
  else
    {				/* should grow the buffer to fit */
      int siz = buf_strbufv->bufend - buf_strbufv->bufstart;
      int newsiz = (siz + slen + 50 + siz / 8) | 0x1f;
      int newix = 0, newblen = 0;
      char *newb = NULL;
      int oldblen = basilys_primtab[buf_strbufv->buflenix];
      for (newix = buf_strbufv->buflenix + 1;
	   (newblen = basilys_primtab[newix]) != 0
	   && newblen < newsiz; newix++);
      gcc_assert (newblen >= newsiz);
      gcc_assert (siz >= 0);
      if (newblen > BASILYS_MAXLEN)
	fatal_error ("strbuf overflow to %d bytes", newblen);
      /* the newly grown buffer is allocated in young memory if the
         previous was young, or in old memory if it was already old */
      if (basilys_is_young (buf_strbufv->bufzn))
	{
	  newb = basilysgc_allocate (newblen + 1, 0);
	  memcpy (newb, buf_strbufv->bufzn + buf_strbufv->bufstart, siz);
	  strcpy (newb + siz, str);
	  memset (buf_strbufv->bufzn, 0, oldblen);
	  buf_strbufv->bufzn = newb;
	}
      else
	{
	  newb = ggc_alloc_cleared (newblen + 1);
	  memcpy (newb, buf_strbufv->bufzn + buf_strbufv->bufstart, siz);
	  strcpy (newb + siz, str);
	  memset (buf_strbufv->bufzn, 0, oldblen);
	  ggc_free (buf_strbufv->bufzn);
	  buf_strbufv->bufzn = newb;
	}
      buf_strbufv->buflenix = newix;
      buf_strbufv->bufstart = 0;
      buf_strbufv->bufend = siz + slen;
      buf_strbufv->bufzn[buf_strbufv->bufend] = 0;
      /* touch the buffer so that it will be scanned if not young */
      basilysgc_touch (strbufv);
    }
end:
  BASILYS_EXITFRAME ();
#undef strbufv
#undef buf_strbufv
}

void
basilysgc_add_strbuf (struct basilysstrbuf_st *strbuf_p, const char *str)
{
  char sbuf[80];
  char *cstr = NULL;
  int slen = 0;
  if (str)
    slen = strlen (str);
  if (slen <= 0)
    return;
  if (slen < (int) sizeof (sbuf) - 1)
    {
      memset (sbuf, 0, sizeof (sbuf));
      strcpy (sbuf, str);
      basilysgc_add_strbuf_raw (strbuf_p, sbuf);
    }
  else
    {
      cstr = xstrdup (str);
      basilysgc_add_strbuf_raw (strbuf_p, cstr);
      free (cstr);
    }
}

void
basilysgc_add_strbuf_cstr (struct basilysstrbuf_st *strbuf_p, const char *str)
{
  int slen = str ? strlen (str) : 0;
  const char *ps = NULL;
  char *pd = NULL;
  char *cstr = NULL;
  if (!str || !str[0])
    return;
  cstr = xcalloc (slen + 5, 4);
  pd = cstr;
  for (ps = str; *ps; ps++)
    {
      switch (*ps)
	{
#define ADDS(S) strcpy(pd, S); pd+=sizeof(S)-1; break
	case '\n':
	  ADDS ("\\n");
	case '\r':
	  ADDS ("\\r");
	case '\t':
	  ADDS ("\\t");
	case '\v':
	  ADDS ("\\v");
	case '\f':
	  ADDS ("\\f");
	case '\'':
	  ADDS ("\\\'");
	case '\"':
	  ADDS ("\\\"");
	case '\\':
	  ADDS ("\\\\");
#undef ADDS
	default:
	  if (ISPRINT (*ps))
	    *(pd++) = *ps;
	  else
	    {
	      sprintf (pd, "\\%03o", (*ps) & 0xff);
	      pd += 4;
	    }
	}
    };
  basilysgc_add_strbuf_raw (strbuf_p, cstr);
  free (cstr);
}


void
basilysgc_add_strbuf_ccomment (struct basilysstrbuf_st
			       *strbuf_p, const char *str)
{
  int slen = str ? strlen (str) : 0;
  const char *ps = NULL;
  char *pd = NULL;
  char *cstr = NULL;
  if (!str || !str[0])
    return;
  cstr = xcalloc (slen + 4, 4);
  pd = cstr;
  for (ps = str; *ps; ps++)
    {
      if (ps[0] == '/' && ps[1] == '*')
	{
	  pd[0] = '/';
	  pd[1] = '+';
	  pd += 2;
	  ps++;
	}
      else if (ps[0] == '*' && ps[1] == '/')
	{
	  pd[0] = '+';
	  pd[1] = '/';
	  pd += 2;
	  ps++;
	}
      else
	*(pd++) = *ps;
    };
  basilysgc_add_strbuf_raw (strbuf_p, cstr);
  free (cstr);
}

void
basilysgc_add_strbuf_cident (struct basilysstrbuf_st
			     *strbuf_p, const char *str)
{
  int slen = str ? strlen (str) : 0;
  char *dupstr = 0;
  char *pc = 0;
  char tinybuf[80];
  if (!str || !str[0])
    return;
  if (slen < (int) sizeof (tinybuf) - 2)
    {
      memset (tinybuf, 0, sizeof (tinybuf));
      if (str)
	strcpy (tinybuf, str);
      dupstr = tinybuf;
    }
  else
    {
      dupstr = xcalloc (slen + 2, 1);
      if (str)
	strcpy (dupstr, str);
    };
  for (pc = dupstr; *pc; pc++)
    if (!ISALNUM (*pc))
      *pc = '_';
  basilysgc_add_strbuf_raw (strbuf_p, dupstr);
  if (dupstr && dupstr != tinybuf)
    free (dupstr);
}

void
basilysgc_add_strbuf_cidentprefix (struct basilysstrbuf_st
				   *strbuf_p, const char *str, int preflen)
{
  char *dupstr = 0;
  char *pc = 0;
  char tinybuf[80];
  if (str)
    {
      int lenst = strlen (str);
      if (lenst < preflen)
	preflen = lenst;
    }
  else
    return;
  if (preflen >= (int) sizeof (tinybuf) - 1)
    preflen = sizeof (tinybuf) - 2;
  if (preflen <= 0)
    return;
  memset (tinybuf, 0, sizeof (tinybuf));
  if (str)
    strncpy (tinybuf, str, preflen);
  dupstr = tinybuf;
  for (pc = dupstr; *pc; pc++)
    if (!ISALNUM (*pc))
      *pc = '_';
  basilysgc_add_strbuf_raw (strbuf_p, dupstr);
}


void
basilysgc_add_strbuf_hex (struct basilysstrbuf_st *strbuf_p, unsigned long l)
{
  if (l == 0UL)
    basilysgc_add_strbuf_raw (strbuf_p, "0");
  else
    {
      int ix = 0, j = 0;
      char revbuf[80], thebuf[80];
      memset (revbuf, 0, sizeof (revbuf));
      memset (thebuf, 0, sizeof (thebuf));
      while (ix < (int) sizeof (revbuf) - 1 && l != 0UL)
	{
	  unsigned h = l & 15;
	  l >>= 4;
	  revbuf[ix++] = "0123456789abcdef"[h];
	}
      ix--;
      for (j = 0; j < (int) sizeof (thebuf) - 1 && ix >= 0; j++, ix--)
	thebuf[j] = revbuf[ix];
      basilysgc_add_strbuf_raw (strbuf_p, thebuf);
    }
}


void
basilysgc_add_strbuf_dec (struct basilysstrbuf_st *strbuf_p, long l)
{
  if (l == 0UL)
    basilysgc_add_strbuf_raw (strbuf_p, "0");
  else
    {
      int ix = 0, j = 0, neg = 0;
      char revbuf[96], thebuf[96];
      memset (revbuf, 0, sizeof (revbuf));
      memset (thebuf, 0, sizeof (thebuf));
      if (l < 0)
	{
	  l = -l;
	  neg = 1;
	};
      while (ix < (int) sizeof (revbuf) - 1 && l != 0UL)
	{
	  unsigned h = l % 10;
	  l = l / 10;
	  revbuf[ix++] = "0123456789"[h];
	}
      ix--;
      if (neg)
	{
	  thebuf[0] = '-';
	  j = 1;
	};
      for (; j < (int) sizeof (thebuf) - 1 && ix >= 0; j++, ix--)
	thebuf[j] = revbuf[ix];
      basilysgc_add_strbuf_raw (strbuf_p, thebuf);
    }
}


void
basilysgc_strbuf_printf (struct basilysstrbuf_st *strbuf_p,
			 const char *fmt, ...)
{
  char *cstr = NULL;
  va_list ap;
  int l = 0;
  static char tinybuf[80];
  memset (tinybuf, 0, sizeof (tinybuf));
  va_start (ap, fmt);
  l = vsnprintf (tinybuf, sizeof (tinybuf) - 1, fmt, ap);
  va_end (ap);
  if (l < (int) sizeof (tinybuf) - 3)
    {
      basilysgc_add_strbuf_raw (strbuf_p, tinybuf);
      return;
    }
  va_start (ap, fmt);
  vasprintf (&cstr, fmt, ap);
  va_end (ap);
  basilysgc_add_strbuf_raw (strbuf_p, cstr);
  free (cstr);
}


/* add safely into STRBUF either a space or an indented newline if the current line is bigger than the threshold */
void
basilysgc_strbuf_add_indent (struct basilysstrbuf_st
			     *strbuf_p, int depth, int linethresh)
{
  int llln = 0;			/* last line length */
  if (!strbuf_p || basilys_magic_discr ((void *) strbuf_p) != OBMAG_STRBUF)
    return;
  if (linethresh > 0 && linethresh < 40)
    linethresh = 40;
  /* compute the last line length llln */
  {
    char *bs = 0, *be = 0, *nl = 0;
    bs = strbuf_p->bufzn + strbuf_p->bufstart;
    be = strbuf_p->bufzn + strbuf_p->bufend;
    for (nl = be - 1; nl > bs && *nl && *nl != '\n'; nl--);
    llln = be - nl;
    gcc_assert (llln >= 0);
  }
  if (linethresh > 0 && llln < linethresh)
    basilysgc_add_strbuf_raw (strbuf_p, " ");
  else
    {
      int nbsp = depth;
      static const char spaces32[] = "                                ";
      basilysgc_add_strbuf_raw (strbuf_p, "\n");
      if (nbsp < 0)
	nbsp = 0;
      if (nbsp > 0 && nbsp % 32 != 0)
	basilysgc_add_strbuf_raw (strbuf_p, spaces32 + (32 - nbsp % 32));
    }
}




/***************/

basilysobject_ptr_t
basilysgc_new_raw_object (basilysobject_ptr_t klass_p, unsigned len)
{
  unsigned h = 0;
  BASILYS_ENTERFRAME (2, NULL);
#define newobjv   curfram__.varptr[0]
#define klassv    curfram__.varptr[1]
#define obj_newobjv  ((basilysobject_ptr_t)(newobjv))
#define obj_klassv   ((basilysobject_ptr_t)(klassv))
  newobjv = NULL;
  klassv = klass_p;
  if (basilys_magic_discr (klassv) != OBMAG_OBJECT
      || obj_klassv->object_magic != OBMAG_OBJECT || len >= SHRT_MAX)
    goto end;
  newobjv =
    basilysgc_allocate (offsetof
			(struct basilysobject_st,
			 obj__tabfields), len * sizeof (void *));
  obj_newobjv->obj_class = klassv;
  do
    {
      h = basilys_lrand () & BASILYS_MAXHASH;
    }
  while (h == 0);
  obj_newobjv->obj_hash = h;
  obj_newobjv->obj_len = len;
  if (len > 0)
    obj_newobjv->obj_vartab = obj_newobjv->obj__tabfields;
end:
  BASILYS_EXITFRAME ();
  return newobjv;
#undef newobjv
#undef klassv
#undef obj_newobjv
#undef obj_klassv
}


/* allocate a new multiple of given DISCR & length LEN */
basilys_ptr_t
basilysgc_new_multiple (basilysobject_ptr_t discr_p, unsigned len)
{
  BASILYS_ENTERFRAME (2, NULL);
#define newmul curfram__.varptr[0]
#define discrv  curfram__.varptr[1]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define mult_newmul ((struct basilysmultiple_st*)(newmul))
  discrv = (void *) discr_p;
  newmul = NULL;
  gcc_assert (len < BASILYS_MAXLEN);
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_MULTIPLE)
    goto end;
  newmul =
    basilysgc_allocate (sizeof (struct basilysmultiple_st),
			sizeof (void *) * len);
  mult_newmul->discr = object_discrv;
  mult_newmul->nbval = len;
end:
  BASILYS_EXITFRAME ();
  return newmul;
#undef newmul
#undef discr
#undef mult_newmul
#undef object_discrv
}


void
basilysgc_multiple_put_nth (basilysmultiple_ptr_t mul_p,
			    int n, basilys_ptr_t val_p)
{
  int ln = 0;
  BASILYS_ENTERFRAME (3, NULL);
#define mulv    curfram__.varptr[0]
#define mult_mulv ((struct basilysmultiple_st*)(mulv))
#define discrv  curfram__.varptr[1]
#define valv    curfram__.varptr[2]
  mulv = mul_p;
  valv = val_p;
  if (!basilys_magic_discr (mulv) == OBMAG_MULTIPLE)
    goto end;
  ln = mult_mulv->nbval;
  if (n < 0)
    n += ln;
  if (n >= 0 && n < ln)
    {
      mult_mulv->tabval[n] = valv;
      basilysgc_touch_dest (mulv, valv);
    }
end:
  BASILYS_EXITFRAME ();
#undef mulv
#undef mult_mulv
#undef discrv
#undef valv
}

/* allocate a new box of given DISCR & content VAL */
basilys_ptr_t
basilysgc_new_box (basilysobject_ptr_t discr_p, basilys_ptr_t val_p)
{
  BASILYS_ENTERFRAME (3, NULL);
#define boxv curfram__.varptr[0]
#define discrv  curfram__.varptr[1]
#define valv   curfram__.varptr[2]
#define object_discrv ((basilysobject_ptr_t)(discrv))
  discrv = (void *) discr_p;
  valv = (void *) val_p;
  boxv = NULL;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_BOX)
    goto end;
  boxv = basilysgc_allocate (sizeof (struct basilysbox_st), 0);
  ((struct basilysbox_st *) (boxv))->discr = discrv;
  ((struct basilysbox_st *) (boxv))->val = valv;
end:
  BASILYS_EXITFRAME ();
  return boxv;
#undef boxv
#undef discr
#undef valv
#undef object_discrv
}

/* put inside a box */
void
basilysgc_box_put (basilys_ptr_t box_p, basilys_ptr_t val_p)
{
  BASILYS_ENTERFRAME (2, NULL);
#define boxv curfram__.varptr[0]
#define valv   curfram__.varptr[1]
  boxv = box_p;
  valv = val_p;
  if (basilys_magic_discr (boxv) != OBMAG_BOX)
    goto end;
  ((basilysbox_ptr_t) boxv)->val = valv;
  basilysgc_touch_dest (boxv, valv);
end:
  BASILYS_EXITFRAME ();
#undef boxv
#undef valv
}


/* allocate a multiple of arity 1 */
basilys_ptr_t
basilysgc_new_mult1 (basilysobject_ptr_t discr_p, basilys_ptr_t v0_p)
{
  BASILYS_ENTERFRAME (3, NULL);
#define newmul curfram__.varptr[0]
#define discrv  curfram__.varptr[1]
#define v0   curfram__.varptr[2]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define mult_newmul ((struct basilysmultiple_st*)(newmul))
  discrv = (void *) discr_p;
  v0 = v0_p;
  newmul = NULL;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_MULTIPLE)
    goto end;
  newmul =
    basilysgc_allocate (sizeof (struct basilysmultiple_st),
			sizeof (void *) * 1);
  mult_newmul->discr = object_discrv;
  mult_newmul->nbval = 1;
  mult_newmul->tabval[0] = v0;
end:
  BASILYS_EXITFRAME ();
  return newmul;
#undef newmul
#undef discr
#undef v0
#undef mult_newmul
#undef object_discrv
}

basilys_ptr_t
basilysgc_new_mult2 (basilysobject_ptr_t discr_p,
		     basilys_ptr_t v0_p, basilys_ptr_t v1_p)
{
  BASILYS_ENTERFRAME (4, NULL);
#define newmul curfram__.varptr[0]
#define discrv  curfram__.varptr[1]
#define v0   curfram__.varptr[2]
#define v1   curfram__.varptr[3]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define mult_newmul ((struct basilysmultiple_st*)(newmul))
  discrv = (void *) discr_p;
  v0 = v0_p;
  v1 = v1_p;
  newmul = NULL;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_MULTIPLE)
    goto end;
  newmul =
    basilysgc_allocate (sizeof (struct basilysmultiple_st),
			sizeof (void *) * 2);
  mult_newmul->discr = object_discrv;
  mult_newmul->nbval = 2;
  mult_newmul->tabval[0] = v0;
  mult_newmul->tabval[1] = v1;
end:
  BASILYS_EXITFRAME ();
  return newmul;
#undef newmul
#undef discr
#undef v0
#undef v1
#undef mult_newmul
#undef object_discrv
}

basilys_ptr_t
basilysgc_new_mult3 (basilysobject_ptr_t discr_p,
		     basilys_ptr_t v0_p, basilys_ptr_t v1_p,
		     basilys_ptr_t v2_p)
{
  BASILYS_ENTERFRAME (5, NULL);
#define newmul curfram__.varptr[0]
#define discrv  curfram__.varptr[1]
#define v0   curfram__.varptr[2]
#define v1   curfram__.varptr[3]
#define v2   curfram__.varptr[4]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define mult_newmul ((struct basilysmultiple_st*)(newmul))
  discrv = (void *) discr_p;
  v0 = v0_p;
  v1 = v1_p;
  v2 = v2_p;
  newmul = NULL;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_MULTIPLE)
    goto end;
  newmul =
    basilysgc_allocate (sizeof (struct basilysmultiple_st),
			sizeof (void *) * 3);
  mult_newmul->discr = object_discrv;
  mult_newmul->nbval = 3;
  mult_newmul->tabval[0] = v0;
  mult_newmul->tabval[1] = v1;
  mult_newmul->tabval[2] = v2;
end:
  BASILYS_EXITFRAME ();
  return newmul;
#undef newmul
#undef discrv
#undef v0
#undef v1
#undef v2
#undef mult_newmul
#undef object_discrv
}

basilys_ptr_t
basilysgc_new_mult4 (basilysobject_ptr_t discr_p,
		     basilys_ptr_t v0_p, basilys_ptr_t v1_p,
		     basilys_ptr_t v2_p, basilys_ptr_t v3_p)
{
  BASILYS_ENTERFRAME (6, NULL);
#define newmul curfram__.varptr[0]
#define discrv  curfram__.varptr[1]
#define v0   curfram__.varptr[2]
#define v1   curfram__.varptr[3]
#define v2   curfram__.varptr[4]
#define v3   curfram__.varptr[5]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define mult_newmul ((struct basilysmultiple_st*)(newmul))
  discrv = (void *) discr_p;
  v0 = v0_p;
  v1 = v1_p;
  v2 = v2_p;
  v3 = v3_p;
  newmul = NULL;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_MULTIPLE)
    goto end;
  newmul =
    basilysgc_allocate (sizeof (struct basilysmultiple_st),
			sizeof (void *) * 4);
  mult_newmul->discr = object_discrv;
  mult_newmul->nbval = 4;
  mult_newmul->tabval[0] = v0;
  mult_newmul->tabval[1] = v1;
  mult_newmul->tabval[2] = v2;
  mult_newmul->tabval[3] = v3;
end:
  BASILYS_EXITFRAME ();
  return newmul;
#undef newmul
#undef discrv
#undef v0
#undef v1
#undef v2
#undef v3
#undef mult_newmul
#undef object_discrv
}

basilys_ptr_t
basilysgc_new_mult5 (basilysobject_ptr_t discr_p,
		     basilys_ptr_t v0_p, basilys_ptr_t v1_p,
		     basilys_ptr_t v2_p, basilys_ptr_t v3_p,
		     basilys_ptr_t v4_p)
{
  BASILYS_ENTERFRAME (7, NULL);
#define newmul curfram__.varptr[0]
#define discrv  curfram__.varptr[1]
#define v0   curfram__.varptr[2]
#define v1   curfram__.varptr[3]
#define v2   curfram__.varptr[4]
#define v3   curfram__.varptr[5]
#define v4   curfram__.varptr[6]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define mult_newmul ((struct basilysmultiple_st*)(newmul))
  discrv = (void *) discr_p;
  v0 = v0_p;
  v1 = v1_p;
  v2 = v2_p;
  v3 = v3_p;
  v4 = v4_p;
  newmul = NULL;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_MULTIPLE)
    goto end;
  newmul =
    basilysgc_allocate (sizeof (struct basilysmultiple_st),
			sizeof (void *) * 5);
  mult_newmul->discr = object_discrv;
  mult_newmul->nbval = 5;
  mult_newmul->tabval[0] = v0;
  mult_newmul->tabval[1] = v1;
  mult_newmul->tabval[2] = v2;
  mult_newmul->tabval[3] = v3;
  mult_newmul->tabval[4] = v4;
end:
  BASILYS_EXITFRAME ();
  return newmul;
#undef newmul
#undef discrv
#undef v0
#undef v1
#undef v2
#undef v3
#undef v4
#undef mult_newmul
#undef object_discrv
}


basilys_ptr_t
basilysgc_new_list (basilysobject_ptr_t discr_p)
{
  BASILYS_ENTERFRAME (2, NULL);
#define discrv curfram__.varptr[0]
#define newlist curfram__.varptr[1]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define list_newlist ((struct basilyslist_st*)(newlist))
  discrv = (void *) discr_p;
  newlist = NULL;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_LIST)
    goto end;
  newlist = basilysgc_allocate (sizeof (struct basilyslist_st), 0);
  list_newlist->discr = object_discrv;
  list_newlist->first = NULL;
  list_newlist->last = NULL;
end:
  BASILYS_EXITFRAME ();
  return newlist;
#undef newlist
#undef discrv
#undef list_newlist
#undef object_discrv
}

/* allocate a pair of given head and tail */
basilys_ptr_t
basilysgc_new_pair (basilysobject_ptr_t discr_p, void *head_p, void *tail_p)
{
  BASILYS_ENTERFRAME (4, NULL);
#define pairv   curfram__.varptr[0]
#define discrv  curfram__.varptr[1]
#define headv   curfram__.varptr[2]
#define tailv   curfram__.varptr[3]
  discrv = discr_p;
  headv = head_p;
  tailv = tail_p;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT
      || ((basilysobject_ptr_t) (discrv))->object_magic != OBMAG_PAIR)
    goto end;
  if (basilys_magic_discr (tailv) != OBMAG_PAIR)
    tailv = NULL;
  pairv = basilysgc_allocate (sizeof (struct basilyspair_st), 0);
  ((struct basilyspair_st *) (pairv))->discr = discrv;
  ((struct basilyspair_st *) (pairv))->hd = headv;
  ((struct basilyspair_st *) (pairv))->tl = tailv;
end:
  BASILYS_EXITFRAME ();
  return pairv;
#undef pairv
#undef headv
#undef tailv
#undef discrv
}

/* change the head of a pair */
void
basilysgc_pair_set_head (basilys_ptr_t pair_p, void *head_p)
{
  BASILYS_ENTERFRAME (2, NULL);
#define pairv   curfram__.varptr[0]
#define headv   curfram__.varptr[1]
  pairv = pair_p;
  headv = head_p;
  if (basilys_magic_discr (pairv) != OBMAG_PAIR)
    goto end;
  ((struct basilyspair_st *) pairv)->hd = headv;
  basilysgc_touch_dest (pairv, headv);
end:
  BASILYS_EXITFRAME ();
#undef pairv
#undef headv
}


void
basilysgc_append_list (basilys_ptr_t list_p, basilys_ptr_t valu_p)
{
  BASILYS_ENTERFRAME (4, NULL);
#define list curfram__.varptr[0]
#define valu curfram__.varptr[1]
#define pairv curfram__.varptr[2]
#define lastv curfram__.varptr[3]
#define pai_pairv ((struct basilyspair_st*)(pairv))
#define list_list ((struct basilyslist_st*)(list))
  list = list_p;
  valu = valu_p;
  if (basilys_magic_discr (list) != OBMAG_LIST || !BASILYSGOB (DISCR_PAIR))
    goto end;
  pairv = basilysgc_allocate (sizeof (struct basilyspair_st), 0);
  pai_pairv->discr = BASILYSGOB (DISCR_PAIR);
  pai_pairv->hd = valu;
  pai_pairv->tl = NULL;
  gcc_assert (basilys_magic_discr (pairv) == OBMAG_PAIR);
  lastv = list_list->last;
  if (basilys_magic_discr ((basilys_ptr_t) lastv) == OBMAG_PAIR)
    {
      gcc_assert (((struct basilyspair_st *) lastv)->tl == NULL);
      ((struct basilyspair_st *) lastv)->tl = pairv;
      basilysgc_touch_dest (lastv, pairv);
    }
  else
    list_list->first = pairv;
  list_list->last = pairv;
  basilysgc_touch_dest (list, pairv);
end:
  BASILYS_EXITFRAME ();
#undef list
#undef valu
#undef list_list
#undef pairv
#undef pai_pairv
#undef lastv
}

void
basilysgc_prepend_list (basilys_ptr_t list_p, basilys_ptr_t valu_p)
{
  BASILYS_ENTERFRAME (4, NULL);
#define list curfram__.varptr[0]
#define valu curfram__.varptr[1]
#define pairv curfram__.varptr[2]
#define firstv curfram__.varptr[3]
#define pai_pairv ((struct basilyspair_st*)(pairv))
#define list_list ((struct basilyslist_st*)(list))
  list = list_p;
  valu = valu_p;
  if (basilys_magic_discr (list) != OBMAG_LIST || !BASILYSGOB (DISCR_PAIR))
    goto end;
  pairv = basilysgc_allocate (sizeof (struct basilyspair_st), 0);
  pai_pairv->discr = BASILYSGOB (DISCR_PAIR);
  pai_pairv->hd = valu;
  pai_pairv->tl = NULL;
  gcc_assert (basilys_magic_discr (pairv) == OBMAG_PAIR);
  firstv = (basilys_ptr_t) (list_list->first);
  if (basilys_magic_discr (firstv) == OBMAG_PAIR)
    {
      pai_pairv->tl = firstv;
      basilysgc_touch_dest (pairv, firstv);
    }
  else
    list_list->last = pairv;
  list_list->first = pairv;
  basilysgc_touch_dest (list, pairv);
end:
  BASILYS_EXITFRAME ();
#undef list
#undef valu
#undef list_list
#undef pairv
#undef pai_pairv
}


basilys_ptr_t
basilysgc_popfirst_list (basilys_ptr_t list_p)
{
  BASILYS_ENTERFRAME (3, NULL);
#define list curfram__.varptr[0]
#define valu curfram__.varptr[1]
#define pairv curfram__.varptr[2]
#define pai_pairv ((struct basilyspair_st*)(pairv))
#define list_list ((struct basilyslist_st*)(list))
  list = list_p;
  if (basilys_magic_discr (list) != OBMAG_LIST)
    goto end;
  pairv = list_list->first;
  if (basilys_magic_discr ((basilys_ptr_t) pairv) != OBMAG_PAIR)
    goto end;
  if (list_list->last == pairv)
    {
      valu = pai_pairv->hd;
      list_list->first = NULL;
      list_list->last = NULL;
    }
  else
    {
      valu = pai_pairv->hd;
      list_list->first = pai_pairv->tl;
    }
  basilysgc_touch (list);
end:
  BASILYS_EXITFRAME ();
  return valu;
#undef list
#undef value
#undef list_list
#undef pairv
#undef pai_pairv
}				/* enf of popfirst */


/* return the length of a list or -1 iff non list */
int
basilys_list_length (basilys_ptr_t list_p)
{
  struct basilyspair_st *pair = NULL;
  int ln = 0;
  if (basilys_magic_discr (list_p) != OBMAG_LIST)
    return -1;
  for (pair = ((struct basilyslist_st *) list_p)->first;
       basilys_magic_discr ((basilys_ptr_t) pair) ==
       OBMAG_PAIR; pair = (struct basilyspair_st *) (pair->tl))
    ln++;
  return ln;
}


/* allocate a new empty mapobjects */
basilys_ptr_t
basilysgc_new_mapobjects (basilysobject_ptr_t discr_p, unsigned len)
{
  int maplen = 0;
  int lenix = 0, primlen = 0;
  BASILYS_ENTERFRAME (2, NULL);
#define discrv curfram__.varptr[0]
#define newmapv curfram__.varptr[1]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define mapobject_newmapv ((struct basilysmapobjects_st*)(newmapv))
  discrv = discr_p;
  if (!discrv || object_discrv->obj_class->object_magic != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_MAPOBJECTS)
    goto end;
  if (len > 0)
    {
      gcc_assert (len < (unsigned) BASILYS_MAXLEN);
      for (lenix = 1;
	   (primlen = (int) basilys_primtab[lenix]) != 0
	   && primlen <= (int) len; lenix++);
      maplen = primlen;
    };
  newmapv =
    basilysgc_allocate (offsetof
			(struct basilysmapobjects_st, map_space),
			maplen * sizeof (struct entryobjectsbasilys_st));
  mapobject_newmapv->discr = object_discrv;
  if (len > 0)
    {
      mapobject_newmapv->entab = mapobject_newmapv->map_space;
      mapobject_newmapv->lenix = lenix;
    };
end:
  BASILYS_EXITFRAME ();
  return newmapv;
#undef discrv
#undef newmapv
#undef object_discrv
#undef mapobject_newmapv
}

/* get from a mapobject */
basilys_ptr_t
basilys_get_mapobjects (basilysmapobjects_ptr_t mapobject_p,
			basilysobject_ptr_t attrobject_p)
{
  long ix, len;
  basilys_ptr_t val = NULL;
  if (!mapobject_p || !attrobject_p
      || mapobject_p->discr->object_magic != OBMAG_MAPOBJECTS
      || !mapobject_p->entab
      || attrobject_p->obj_class->object_magic != OBMAG_OBJECT)
    return NULL;
  len = basilys_primtab[mapobject_p->lenix];
  if (len <= 0)
    return NULL;
  ix = unsafe_index_mapobject (mapobject_p->entab, attrobject_p, len);
  if (ix < 0)
    return NULL;
  if (mapobject_p->entab[ix].e_at == attrobject_p)
    val = mapobject_p->entab[ix].e_va;
  return val;
}

void
basilysgc_put_mapobjects (basilysmapobjects_ptr_t
			  mapobject_p,
			  basilysobject_ptr_t attrobject_p,
			  basilys_ptr_t valu_p)
{
  long ix = 0, len = 0, cnt = 0;
  BASILYS_ENTERFRAME (4, NULL);
#define discrv curfram__.varptr[0]
#define mapobjectv curfram__.varptr[1]
#define attrobjectv curfram__.varptr[2]
#define valuv curfram__.varptr[3]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define object_attrobjectv ((basilysobject_ptr_t)(attrobjectv))
#define map_mapobjectv ((basilysmapobjects_ptr_t)(mapobjectv))
  mapobjectv = mapobject_p;
  attrobjectv = attrobject_p;
  valuv = valu_p;
  if (!mapobjectv || !attrobjectv || !valuv)
    goto end;
  discrv = map_mapobjectv->discr;
  if (!discrv || object_discrv->object_magic != OBMAG_MAPOBJECTS)
    goto end;
  discrv = object_attrobjectv->obj_class;
  if (!discrv || object_discrv->object_magic != OBMAG_OBJECT)
    goto end;
  if (!map_mapobjectv->entab)
    {
      len = basilys_primtab[1];	/* i.e. 3 */
      if (basilys_is_young (mapobjectv))
	map_mapobjectv->entab =
	  basilysgc_allocate (len *
			      sizeof (struct entryobjectsbasilys_st), 0);
      else
	map_mapobjectv->entab =
	  ggc_alloc_cleared (len * sizeof (struct entryobjectsbasilys_st));
      map_mapobjectv->lenix = 1;
      basilysgc_touch (map_mapobjectv);
    }
  else
    if ((len = basilys_primtab[map_mapobjectv->lenix]) <=
	(5 * (cnt = map_mapobjectv->count)) / 4 + 1
	|| (len <= 5 && cnt + 1 >= len))
    {
      int ix, newcnt = 0;
      int newlen = basilys_primtab[map_mapobjectv->lenix + 1];
      struct entryobjectsbasilys_st *newtab = NULL;
      struct entryobjectsbasilys_st *oldtab = NULL;
      if (basilys_is_young (map_mapobjectv->entab))
	newtab =
	  basilysgc_allocate (newlen *
			      sizeof (struct entryobjectsbasilys_st), 0);
      else
	newtab =
	  ggc_alloc_cleared (newlen * sizeof (struct entryobjectsbasilys_st));
      oldtab = map_mapobjectv->entab;
      for (ix = 0; ix < len; ix++)
	{
	  basilysobject_ptr_t curat = oldtab[ix].e_at;
	  int newix;
	  if (!curat || curat == (void *) HTAB_DELETED_ENTRY)
	    continue;
	  newix = unsafe_index_mapobject (newtab, curat, newlen);
	  gcc_assert (newix >= 0);
	  newtab[newix] = oldtab[ix];
	  newcnt++;
	}
      if (!basilys_is_young (oldtab))
	/* free oldtab since it is in old ggc space */
	ggc_free (oldtab);
      map_mapobjectv->entab = newtab;
      map_mapobjectv->count = newcnt;
      map_mapobjectv->lenix++;
      basilysgc_touch (map_mapobjectv);
      len = newlen;
    }
  ix =
    unsafe_index_mapobject (map_mapobjectv->entab, object_attrobjectv, len);
  gcc_assert (ix >= 0);
  if (map_mapobjectv->entab[ix].e_at != attrobjectv)
    {
      map_mapobjectv->entab[ix].e_at = attrobjectv;
      map_mapobjectv->count++;
    }
  map_mapobjectv->entab[ix].e_va = valuv;
  basilysgc_touch_dest (map_mapobjectv, attrobjectv);
  basilysgc_touch_dest (map_mapobjectv, valuv);
end:
  BASILYS_EXITFRAME ();
#undef discrv
#undef mapobjectv
#undef attrobjectv
#undef valuv
#undef object_discrv
#undef object_attrobjectv
#undef map_mapobjectv
}


basilys_ptr_t
basilysgc_remove_mapobjects (basilysmapobjects_ptr_t
			     mapobject_p, basilysobject_ptr_t attrobject_p)
{
  long ix = 0, len = 0, cnt = 0;
  BASILYS_ENTERFRAME (4, NULL);
#define discrv curfram__.varptr[0]
#define mapobjectv curfram__.varptr[1]
#define attrobjectv curfram__.varptr[2]
#define valuv curfram__.varptr[3]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define object_attrobjectv ((basilysobject_ptr_t)(attrobjectv))
#define map_mapobjectv ((basilysmapobjects_ptr_t)(mapobjectv))
  mapobjectv = mapobject_p;
  attrobjectv = attrobject_p;
  valuv = NULL;
  if (!mapobjectv || !attrobjectv)
    goto end;
  discrv = map_mapobjectv->discr;
  if (!discrv || object_discrv->object_magic != OBMAG_MAPOBJECTS)
    goto end;
  discrv = object_attrobjectv->obj_class;
  if (!discrv || object_discrv->object_magic != OBMAG_OBJECT)
    goto end;
  if (!map_mapobjectv->entab)
    goto end;
  len = basilys_primtab[map_mapobjectv->lenix];
  if (len <= 0)
    goto end;
  ix = unsafe_index_mapobject (map_mapobjectv->entab, attrobject_p, len);
  if (ix < 0 || map_mapobjectv->entab[ix].e_at != attrobjectv)
    goto end;
  map_mapobjectv->entab[ix].e_at = (void *) HTAB_DELETED_ENTRY;
  valuv = map_mapobjectv->entab[ix].e_va;
  map_mapobjectv->entab[ix].e_va = NULL;
  map_mapobjectv->count--;
  cnt = map_mapobjectv->count;
  if (len >= 7 && cnt < len / 2 - 2)
    {
      int newcnt = 0, newlen = 0, newlenix;
      struct entryobjectsbasilys_st *oldtab = NULL, *newtab = NULL;
      for (newlenix = map_mapobjectv->lenix;
	   (newlen = basilys_primtab[newlenix]) > 2 * cnt + 3; newlenix--);
      if (newlen >= len)
	goto end;
      if (basilys_is_young (map_mapobjectv->entab))
	newtab =
	  basilysgc_allocate (newlen *
			      sizeof (struct entryobjectsbasilys_st), 0);
      else
	newtab =
	  ggc_alloc_cleared (newlen * sizeof (struct entryobjectsbasilys_st));
      oldtab = map_mapobjectv->entab;
      for (ix = 0; ix < len; ix++)
	{
	  basilysobject_ptr_t curat = oldtab[ix].e_at;
	  int newix;
	  if (!curat || curat == (void *) HTAB_DELETED_ENTRY)
	    continue;
	  newix = unsafe_index_mapobject (newtab, curat, newlen);
	  gcc_assert (newix >= 0);
	  newtab[newix] = oldtab[ix];
	  newcnt++;
	}
      if (!basilys_is_young (oldtab))
	/* free oldtab since it is in old ggc space */
	ggc_free (oldtab);
      map_mapobjectv->entab = newtab;
      map_mapobjectv->count = newcnt;
      map_mapobjectv->lenix = newlenix;
    }
  basilysgc_touch (map_mapobjectv);
end:
  BASILYS_EXITFRAME ();
  return valuv;
#undef discrv
#undef mapobjectv
#undef attrobjectv
#undef valuv
#undef object_discrv
#undef object_attrobjectv
#undef map_mapobjectv
}



/* index of entry to get or add an attribute in an mapstring (or -1 on error) */
static inline int
unsafe_index_mapstring (struct entrystringsbasilys_st *tab,
			const char *attr, int siz)
{
  int ix = 0, frix = -1;
  unsigned h = 0;
  if (!tab || !attr || siz <= 0)
    return -1;
  h = (unsigned) htab_hash_string (attr) & BASILYS_MAXHASH;
  h = h % siz;
  for (ix = h; ix < siz; ix++)
    {
      const char *curat = tab[ix].e_at;
      if (curat == (void *) HTAB_DELETED_ENTRY)
	{
	  if (frix < 0)
	    frix = ix;
	}
      else if (!curat)
	{
	  if (frix < 0)
	    frix = ix;
	  return frix;
	}
      else if (!strcmp (curat, attr))
	return ix;
    }
  for (ix = 0; ix < (int) h; ix++)
    {
      const char *curat = tab[ix].e_at;
      if (curat == (void *) HTAB_DELETED_ENTRY)
	{
	  if (frix < 0)
	    frix = ix;
	}
      else if (!curat)
	{
	  if (frix < 0)
	    frix = ix;
	  return frix;
	}
      else if (!strcmp (curat, attr))
	return ix;
    }
  return -1;			/* entirely full, should not happen */
}

/* allocate a new empty mapstrings */
basilys_ptr_t
basilysgc_new_mapstrings (basilysobject_ptr_t discr_p, unsigned len)
{
  BASILYS_ENTERFRAME (2, NULL);
#define discrv curfram__.varptr[0]
#define newmapv curfram__.varptr[1]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define mapstring_newmapv ((struct basilysmapstrings_st*)(newmapv))
  discrv = discr_p;
  if (!discrv || object_discrv->obj_class->object_magic != OBMAG_OBJECT)
    goto end;
  if (object_discrv->object_magic != OBMAG_MAPSTRINGS)
    goto end;
  newmapv = basilysgc_allocate (sizeof (struct basilysmapstrings_st), 0);
  mapstring_newmapv->discr = object_discrv;
  if (len > 0)
    {
      int lenix, primlen;
      gcc_assert (len < (unsigned) BASILYS_MAXLEN);
      for (lenix = 1;
	   (primlen = (int) basilys_primtab[lenix]) != 0
	   && primlen <= (int) len; lenix++);
      /* the newmapv is always young */
      mapstring_newmapv->entab =
	basilysgc_allocate (primlen *
			    sizeof (struct entrystringsbasilys_st), 0);
      mapstring_newmapv->lenix = lenix;
      basilysgc_touch_dest (newmapv, mapstring_newmapv->entab);
    }
end:
  BASILYS_EXITFRAME ();
  return newmapv;
#undef discrv
#undef newmapv
#undef object_discrv
#undef mapstring_newmapv
}


void
basilysgc_put_mapstrings (struct basilysmapstrings_st
			  *mapstring_p, const char *attr,
			  basilys_ptr_t valu_p)
{
  long ix = 0, len = 0, cnt = 0, atlen = 0;
  char *attrdup = 0;
  char tinybuf[130];
  BASILYS_ENTERFRAME (3, NULL);
#define discrv curfram__.varptr[0]
#define mapstringv curfram__.varptr[1]
#define valuv curfram__.varptr[2]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define map_mapstringv ((struct basilysmapstrings_st*)(mapstringv))
  mapstringv = mapstring_p;
  valuv = valu_p;
  if (!mapstringv || !attr || !attr[0] || !valuv)
    goto end;
  discrv = map_mapstringv->discr;
  if (!discrv || object_discrv->object_magic != OBMAG_MAPSTRINGS)
    goto end;
  atlen = strlen (attr);
  if (atlen < (int) sizeof (tinybuf) - 1)
    {
      memset (tinybuf, 0, sizeof (tinybuf));
      attrdup = strcpy (tinybuf, attr);
    }
  else
    attrdup = strcpy (xcalloc (atlen + 1, 1), attr);
  if (!map_mapstringv->entab)
    {
      len = basilys_primtab[1];	/* i.e. 3 */
      if (basilys_is_young (mapstringv))
	map_mapstringv->entab =
	  basilysgc_allocate (len *
			      sizeof (struct entrystringsbasilys_st), 0);
      else
	map_mapstringv->entab =
	  ggc_alloc_cleared (len * sizeof (struct entrystringsbasilys_st));
      map_mapstringv->lenix = 1;
      basilysgc_touch (map_mapstringv);
    }
  else
    if ((len = basilys_primtab[map_mapstringv->lenix]) <=
	(5 * (cnt = map_mapstringv->count)) / 4 + 1
	|| (len <= 5 && cnt + 1 >= len))
    {
      int ix, newcnt = 0;
      int newlen = basilys_primtab[map_mapstringv->lenix + 1];
      struct entrystringsbasilys_st *oldtab = NULL;
      struct entrystringsbasilys_st *newtab = NULL;
      if (basilys_is_young (mapstringv))
	newtab =
	  basilysgc_allocate (newlen *
			      sizeof (struct entrystringsbasilys_st), 0);
      else
	newtab =
	  ggc_alloc_cleared (newlen * sizeof (struct entrystringsbasilys_st));
      oldtab = map_mapstringv->entab;
      for (ix = 0; ix < len; ix++)
	{
	  char *curat = oldtab[ix].e_at;
	  int newix;
	  if (!curat || curat == (void *) HTAB_DELETED_ENTRY)
	    continue;
	  newix = unsafe_index_mapstring (newtab, curat, newlen);
	  gcc_assert (newix >= 0);
	  newtab[newix] = oldtab[ix];
	  newcnt++;
	}
      if (!basilys_is_young (oldtab))
	/* free oldtab since it is in old ggc space */
	ggc_free (oldtab);
      map_mapstringv->entab = newtab;
      map_mapstringv->count = newcnt;
      map_mapstringv->lenix++;
      basilysgc_touch (map_mapstringv);
      len = newlen;
    }
  ix = unsafe_index_mapstring (map_mapstringv->entab, attrdup, len);
  gcc_assert (ix >= 0);
  if (!map_mapstringv->entab[ix].e_at
      || map_mapstringv->entab[ix].e_at == HTAB_DELETED_ENTRY)
    {
      char *newat = basilysgc_allocate (atlen + 1, 0);
      strcpy (newat, attrdup);
      map_mapstringv->entab[ix].e_at = newat;
      map_mapstringv->count++;
    }
  map_mapstringv->entab[ix].e_va = valuv;
  basilysgc_touch_dest (map_mapstringv, valuv);
end:
  if (attrdup && attrdup != tinybuf)
    free (attrdup);
  BASILYS_EXITFRAME ();
#undef discrv
#undef mapstringv
#undef attrobjectv
#undef valuv
#undef object_discrv
#undef object_attrobjectv
#undef map_mapstringv
}

basilys_ptr_t
basilys_get_mapstrings (struct basilysmapstrings_st
			*mapstring_p, const char *attr)
{
  long ix = 0, len = 0;
  char *oldat = NULL;
  if (!mapstring_p || !attr)
    return NULL;
  if (mapstring_p->discr->object_magic != OBMAG_MAPSTRINGS)
    return NULL;
  if (!mapstring_p->entab)
    return NULL;
  len = basilys_primtab[mapstring_p->lenix];
  if (len <= 0)
    return NULL;
  ix = unsafe_index_mapstring (mapstring_p->entab, attr, len);
  if (ix < 0 || !(oldat = mapstring_p->entab[ix].e_at)
      || oldat == HTAB_DELETED_ENTRY)
    return NULL;
  return mapstring_p->entab[ix].e_va;
}

basilys_ptr_t
basilysgc_remove_mapstrings (struct basilysmapstrings_st *
			     mapstring_p, const char *attr)
{
  long ix = 0, len = 0, cnt = 0, atlen = 0;
  const char *oldat = NULL;
  char *attrdup = 0;
  char tinybuf[130];
  BASILYS_ENTERFRAME (3, NULL);
#define discrv curfram__.varptr[0]
#define mapstringv curfram__.varptr[1]
#define valuv curfram__.varptr[2]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define map_mapstringv ((struct basilysmapstrings_st*)(mapstringv))
  mapstringv = mapstring_p;
  valuv = NULL;
  if (!mapstringv || !attr || !valuv || !attr[0])
    goto end;
  atlen = strlen (attr);
  discrv = map_mapstringv->discr;
  if (!discrv || object_discrv->object_magic != OBMAG_MAPSTRINGS)
    goto end;
  if (!map_mapstringv->entab)
    goto end;
  len = basilys_primtab[map_mapstringv->lenix];
  if (len <= 0)
    goto end;
  if (atlen < (int) sizeof (tinybuf) - 1)
    {
      memset (tinybuf, 0, sizeof (tinybuf));
      attrdup = strcpy (tinybuf, attr);
    }
  else
    attrdup = strcpy (xcalloc (atlen + 1, 1), attr);
  ix = unsafe_index_mapstring (map_mapstringv->entab, attrdup, len);
  if (ix < 0 || !(oldat = map_mapstringv->entab[ix].e_at)
      || oldat == HTAB_DELETED_ENTRY)
    goto end;
  if (!basilys_is_young ((void *) (char *) oldat))
    ggc_free ((void *) oldat);
  map_mapstringv->entab[ix].e_at = (void *) HTAB_DELETED_ENTRY;
  valuv = map_mapstringv->entab[ix].e_va;
  map_mapstringv->entab[ix].e_va = NULL;
  map_mapstringv->count--;
  cnt = map_mapstringv->count;
  if (len > 7 && 2 * cnt + 2 < len)
    {
      int newcnt = 0, newlen = 0, newlenix;
      struct entrystringsbasilys_st *oldtab = NULL, *newtab = NULL;
      for (newlenix = map_mapstringv->lenix;
	   (newlen = basilys_primtab[newlenix]) > 2 * cnt + 3; newlenix--);
      if (newlen >= len)
	goto end;
      if (basilys_is_young (mapstringv))
	newtab =
	  basilysgc_allocate (newlen *
			      sizeof (struct entrystringsbasilys_st), 0);
      else
	newtab =
	  ggc_alloc_cleared (newlen * sizeof (struct entrystringsbasilys_st));
      oldtab = map_mapstringv->entab;
      for (ix = 0; ix < len; ix++)
	{
	  char *curat = oldtab[ix].e_at;
	  int newix;
	  if (!curat || curat == (void *) HTAB_DELETED_ENTRY)
	    continue;
	  newix = unsafe_index_mapstring (newtab, curat, newlen);
	  gcc_assert (newix >= 0);
	  newtab[newix] = oldtab[ix];
	  newcnt++;
	}
      if (!basilys_is_young (oldtab))
	/* free oldtab since it is in ol<d ggc space */
	ggc_free (oldtab);
      map_mapstringv->entab = newtab;
      map_mapstringv->count = newcnt;
    }
  basilysgc_touch (map_mapstringv);
end:
  if (attrdup && attrdup != tinybuf)
    free (attrdup);
  BASILYS_EXITFRAME ();
  return valuv;
#undef discrv
#undef mapstringv
#undef valuv
#undef object_discrv
#undef map_mapstringv
}



/* index of entry to get or add an attribute in an mappointer (or -1 on error) */
struct entrypointerbasilys_st
{
  const void *e_at;
  basilys_ptr_t e_va;
};
static inline int
unsafe_index_mappointer (struct entrypointerbasilys_st *tab,
			 const void *attr, int siz)
{
  int ix = 0, frix = -1;
  unsigned h = 0;
  if (!tab || !attr || siz <= 0)
    return -1;
  h = ((unsigned) (((long) (attr)) >> 3)) & BASILYS_MAXHASH;
  h = h % siz;
  for (ix = h; ix < siz; ix++)
    {
      const void *curat = tab[ix].e_at;
      if (curat == (void *) HTAB_DELETED_ENTRY)
	{
	  if (frix < 0)
	    frix = ix;
	}
      else if (!curat)
	{
	  if (frix < 0)
	    frix = ix;
	  return frix;
	}
      else if (curat == attr)
	return ix;
    }
  for (ix = 0; ix < (int) h; ix++)
    {
      const void *curat = tab[ix].e_at;
      if (curat == (void *) HTAB_DELETED_ENTRY)
	{
	  if (frix < 0)
	    frix = ix;
	}
      else if (!curat)
	{
	  if (frix < 0)
	    frix = ix;
	  return frix;
	}
      else if (curat == attr)
	return ix;
    }
  return -1;			/* entirely full, should not happen */
}


/* this should be the same as basilysmaptrees_st, basilysmapedges_st,
   basilysmapbasicblocks_st, .... */
struct basilysmappointers_st
{
  basilysobject_ptr_t discr;
  unsigned count;
  unsigned char lenix;
  struct entrypointerbasilys_st *entab;
  /* the following field is usually the value of entab (for
     objects in the young zone), to allocate the object and its fields
     at once */
  struct entrypointerbasilys_st map_space[FLEXIBLE_DIM];
};
/* allocate a new empty mappointers without checks */
void *
basilysgc_raw_new_mappointers (basilysobject_ptr_t discr_p, unsigned len)
{
  int lenix = 0, primlen = 0;
  BASILYS_ENTERFRAME (2, NULL);
#define discrv curfram__.varptr[0]
#define newmapv curfram__.varptr[1]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define map_newmapv ((struct basilysmappointers_st*)(newmapv))
  discrv = discr_p;
  if (len > 0)
    {
      gcc_assert (len < (unsigned) BASILYS_MAXLEN);
      for (lenix = 1;
	   (primlen = (int) basilys_primtab[lenix]) != 0
	   && primlen <= (int) len; lenix++);
    };
  gcc_assert (sizeof (struct entrypointerbasilys_st) ==
	      sizeof (struct entrytreesbasilys_st));
  gcc_assert (sizeof (struct entrypointerbasilys_st) ==
	      sizeof (struct entryedgesbasilys_st));
  gcc_assert (sizeof (struct entrypointerbasilys_st) ==
	      sizeof (struct entrybasicblocksbasilys_st));
  newmapv =
    basilysgc_allocate (offsetof
			(struct basilysmappointers_st,
			 map_space),
			primlen * sizeof (struct entrypointerbasilys_st));
  map_newmapv->discr = object_discrv;
  map_newmapv->count = 0;
  map_newmapv->lenix = lenix;
  if (len > 0)
    map_newmapv->entab = map_newmapv->map_space;
  else
    map_newmapv->entab = NULL;
  BASILYS_EXITFRAME ();
  return newmapv;
#undef discrv
#undef newmapv
#undef object_discrv
#undef map_newmapv
}


void
basilysgc_raw_put_mappointers (void *mappointer_p,
			       const void *attr, basilys_ptr_t valu_p)
{
  long ix = 0, len = 0, cnt = 0;
  BASILYS_ENTERFRAME (2, NULL);
#define mappointerv curfram__.varptr[0]
#define valuv curfram__.varptr[1]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define map_mappointerv ((struct basilysmappointers_st*)(mappointerv))
  mappointerv = mappointer_p;
  valuv = valu_p;
  if (!map_mappointerv->entab)
    {
      len = basilys_primtab[1];	/* i.e. 3 */
      if (basilys_is_young (mappointerv))
	map_mappointerv->entab =
	  basilysgc_allocate (len *
			      sizeof (struct entrypointerbasilys_st), 0);
      else
	map_mappointerv->entab =
	  ggc_alloc_cleared (len * sizeof (struct entrypointerbasilys_st));
      map_mappointerv->lenix = 1;
      basilysgc_touch (map_mappointerv);
    }
  else
    if ((len = basilys_primtab[map_mappointerv->lenix]) <=
	(5 * (cnt = map_mappointerv->count)) / 4 + 1
	|| (len <= 5 && cnt + 1 >= len))
    {
      int ix, newcnt = 0;
      int newlen = basilys_primtab[map_mappointerv->lenix + 1];
      struct entrypointerbasilys_st *oldtab = NULL;
      struct entrypointerbasilys_st *newtab = NULL;
      if (basilys_is_young (mappointerv))
	newtab =
	  basilysgc_allocate (newlen *
			      sizeof (struct entrypointerbasilys_st), 0);
      else
	newtab =
	  ggc_alloc_cleared (newlen * sizeof (struct entrypointerbasilys_st));
      oldtab = map_mappointerv->entab;
      for (ix = 0; ix < len; ix++)
	{
	  const void *curat = oldtab[ix].e_at;
	  int newix;
	  if (!curat || curat == (void *) HTAB_DELETED_ENTRY)
	    continue;
	  newix = unsafe_index_mappointer (newtab, curat, newlen);
	  gcc_assert (newix >= 0);
	  newtab[newix] = oldtab[ix];
	  newcnt++;
	}
      if (!basilys_is_young (oldtab))
	/* free oldtab since it is in old ggc space */
	ggc_free (oldtab);
      map_mappointerv->entab = newtab;
      map_mappointerv->count = newcnt;
      map_mappointerv->lenix++;
      basilysgc_touch (map_mappointerv);
      len = newlen;
    }
  ix = unsafe_index_mappointer (map_mappointerv->entab, attr, len);
  gcc_assert (ix >= 0);
  if (!map_mappointerv->entab[ix].e_at
      || map_mappointerv->entab[ix].e_at == HTAB_DELETED_ENTRY)
    {
      map_mappointerv->entab[ix].e_at = attr;
      map_mappointerv->count++;
    }
  map_mappointerv->entab[ix].e_va = valuv;
  basilysgc_touch_dest (map_mappointerv, valuv);
  BASILYS_EXITFRAME ();
#undef discrv
#undef mappointerv
#undef valuv
#undef object_discrv
#undef map_mappointerv
}

basilys_ptr_t
basilys_raw_get_mappointers (void *map, const void *attr)
{
  long ix = 0, len = 0;
  const void *oldat = NULL;
  struct basilysmappointers_st *mappointer_p = map;
  if (!mappointer_p->entab)
    return NULL;
  len = basilys_primtab[mappointer_p->lenix];
  if (len <= 0)
    return NULL;
  ix = unsafe_index_mappointer (mappointer_p->entab, attr, len);
  if (ix < 0 || !(oldat = mappointer_p->entab[ix].e_at)
      || oldat == HTAB_DELETED_ENTRY)
    return NULL;
  return mappointer_p->entab[ix].e_va;
}

basilys_ptr_t
basilysgc_raw_remove_mappointers (void *mappointer_p, const void *attr)
{
  long ix = 0, len = 0, cnt = 0;
  const char *oldat = NULL;
  BASILYS_ENTERFRAME (3, NULL);
#define discrv curfram__.varptr[0]
#define mappointerv curfram__.varptr[1]
#define valuv curfram__.varptr[2]
#define object_discrv ((basilysobject_ptr_t)(discrv))
#define map_mappointerv ((struct basilysmappointers_st*)(mappointerv))
  mappointerv = mappointer_p;
  valuv = NULL;
  if (!map_mappointerv->entab)
    goto end;
  len = basilys_primtab[map_mappointerv->lenix];
  if (len <= 0)
    goto end;
  ix = unsafe_index_mappointer (map_mappointerv->entab, attr, len);
  if (ix < 0 || !(oldat = map_mappointerv->entab[ix].e_at)
      || oldat == HTAB_DELETED_ENTRY)
    goto end;
  map_mappointerv->entab[ix].e_at = (void *) HTAB_DELETED_ENTRY;
  valuv = map_mappointerv->entab[ix].e_va;
  map_mappointerv->entab[ix].e_va = NULL;
  map_mappointerv->count--;
  cnt = map_mappointerv->count;
  if (len > 7 && 2 * cnt + 2 < len)
    {
      int newcnt = 0, newlen = 0, newlenix;
      struct entrypointerbasilys_st *oldtab = NULL, *newtab = NULL;
      for (newlenix = map_mappointerv->lenix;
	   (newlen = basilys_primtab[newlenix]) > 2 * cnt + 3; newlenix--);
      if (newlen >= len)
	goto end;
      if (basilys_is_young (mappointerv))
	newtab =
	  basilysgc_allocate (newlen *
			      sizeof (struct entrypointerbasilys_st), 0);
      else
	newtab =
	  ggc_alloc_cleared (newlen * sizeof (struct entrypointerbasilys_st));
      oldtab = map_mappointerv->entab;
      for (ix = 0; ix < len; ix++)
	{
	  const void *curat = oldtab[ix].e_at;
	  int newix;
	  if (!curat || curat == (void *) HTAB_DELETED_ENTRY)
	    continue;
	  newix = unsafe_index_mappointer (newtab, curat, newlen);
	  gcc_assert (newix >= 0);
	  newtab[newix] = oldtab[ix];
	  newcnt++;
	}
      if (!basilys_is_young (oldtab))
	/* free oldtab since it is in old ggc space */
	ggc_free (oldtab);
      map_mappointerv->entab = newtab;
      map_mappointerv->count = newcnt;
    }
  basilysgc_touch (map_mappointerv);
end:
  BASILYS_EXITFRAME ();
  return valuv;
#undef discrv
#undef mappointerv
#undef valuv
#undef object_discrv
#undef map_mappointerv
}


/***************** objvlisp test of strict subclassing */
bool
basilys_is_subclass_of (basilysobject_ptr_t subclass_p,
			basilysobject_ptr_t superclass_p)
{
  struct basilysmultiple_st *subanc = NULL;
  struct basilysmultiple_st *superanc = NULL;
  unsigned subdepth = 0, superdepth = 0;
  if (basilys_magic_discr ((basilys_ptr_t) subclass_p) !=
      OBMAG_OBJECT || subclass_p->object_magic != OBMAG_OBJECT
      || basilys_magic_discr ((basilys_ptr_t) superclass_p) !=
      OBMAG_OBJECT || superclass_p->object_magic != OBMAG_OBJECT)
    {
      gcc_unreachable ();
      return FALSE;
    }
  if (subclass_p->obj_len < FCLASS__LAST
      || !subclass_p->obj_vartab
      || superclass_p->obj_len < FCLASS__LAST || !superclass_p->obj_vartab)
    {
      gcc_unreachable ();
      return FALSE;
    }
  if (superclass_p == BASILYSGOB (CLASS_ROOT))
    return TRUE;
  subanc =
    (struct basilysmultiple_st *) subclass_p->obj_vartab[FCLASS_ANCESTORS];
  superanc =
    (struct basilysmultiple_st *) superclass_p->obj_vartab[FCLASS_ANCESTORS];
  if (basilys_magic_discr ((basilys_ptr_t) subanc) !=
      OBMAG_MULTIPLE || subanc->discr != BASILYSGOB (DISCR_SEQCLASS))
    {
      gcc_unreachable ();
      return FALSE;
    }
  if (basilys_magic_discr ((basilys_ptr_t) superanc) !=
      OBMAG_MULTIPLE || superanc->discr != BASILYSGOB (DISCR_SEQCLASS))
    {
      gcc_unreachable ();
      return FALSE;
    }
  subdepth = subanc->nbval;
  superdepth = superanc->nbval;
  if (subdepth <= superdepth)
    return FALSE;
  if ((basilys_ptr_t) subanc->tabval[superdepth] ==
      (basilys_ptr_t) superclass_p)
    return TRUE;
  return FALSE;
}


basilys_ptr_t
basilysgc_new_string (basilysobject_ptr_t discr_p, const char *str)
{
  int slen = 0;
  BASILYS_ENTERFRAME (2, NULL);
#define discrv     curfram__.varptr[0]
#define strv       curfram__.varptr[1]
#define obj_discrv  ((struct basilysobject_st*)(discrv))
#define str_strv  ((struct basilysstring_st*)(strv))
  strv = 0;
  if (!str)
    goto end;
  slen = strlen (str);
  discrv = discr_p;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (obj_discrv->object_magic != OBMAG_STRING)
    goto end;
  strv = basilysgc_allocate (sizeof (struct basilysstring_st), slen + 1);
  str_strv->discr = obj_discrv;
  strcpy (str_strv->val, str);
end:
  BASILYS_EXITFRAME ();
  return strv;
#undef discrv
#undef strv
#undef obj_discrv
#undef str_strv
}

basilys_ptr_t
basilysgc_new_stringdup (basilysobject_ptr_t discr_p, const char *str)
{
  int slen = 0;
  char tinybuf[80];
  char *strcop = 0;
  BASILYS_ENTERFRAME (2, NULL);
#define discrv     curfram__.varptr[0]
#define strv       curfram__.varptr[1]
#define obj_discrv  ((struct basilysobject_st*)(discrv))
#define str_strv  ((struct basilysstring_st*)(strv))
  strv = 0;
  if (!str)
    goto end;
  discrv = discr_p;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (obj_discrv->object_magic != OBMAG_STRING)
    goto end;
  slen = strlen (str);
  if (slen < (int) sizeof (tinybuf) - 1)
    {
      memset (tinybuf, 0, sizeof (tinybuf));
      strcop = strcpy (tinybuf, str);
    }
  else
    strcop = strcpy (xcalloc (1, slen + 1), str);
  strv = basilysgc_allocate (sizeof (struct basilysstring_st), slen + 1);
  str_strv->discr = obj_discrv;
  strcpy (str_strv->val, strcop);
end:
  if (strcop && strcop != tinybuf)
    free (strcop);
  memset (tinybuf, 0, sizeof (tinybuf));
  BASILYS_EXITFRAME ();
  return strv;
#undef discrv
#undef strv
#undef obj_discrv
#undef str_strv
}

basilys_ptr_t
basilysgc_new_string_nakedbasename (basilysobject_ptr_t
				    discr_p, const char *str)
{
  int slen = 0;
  char tinybuf[120];
  char *strcop = 0;
  char *basestr = 0;
  char *dot = 0;
  BASILYS_ENTERFRAME (2, NULL);
#define discrv     curfram__.varptr[0]
#define strv       curfram__.varptr[1]
#define obj_discrv  ((struct basilysobject_st*)(discrv))
#define str_strv  ((struct basilysstring_st*)(strv))
  strv = 0;
  if (!str)
    goto end;
  discrv = discr_p;
  if (basilys_magic_discr (discrv) != OBMAG_OBJECT)
    goto end;
  if (obj_discrv->object_magic != OBMAG_STRING)
    goto end;
  slen = strlen (str);
  if (slen < (int) sizeof (tinybuf) - 1)
    {
      memset (tinybuf, 0, sizeof (tinybuf));
      strcop = strcpy (tinybuf, str);
    }
  else
    strcop = strcpy (xcalloc (1, slen + 1), str);
  basestr = (char *) lbasename (strcop);
  dot = strchr (basestr, '.');
  if (dot)
    *dot = 0;
  strv =
    basilysgc_allocate (sizeof (struct basilysstring_st),
			strlen (basestr) + 1);
  str_strv->discr = obj_discrv;
  strcpy (str_strv->val, basestr);
end:
  if (strcop && strcop != tinybuf)
    free (strcop);
  memset (tinybuf, 0, sizeof (tinybuf));
  BASILYS_EXITFRAME ();
  return strv;
#undef discrv
#undef strv
#undef obj_discrv
#undef str_strv
}


#if 0 && NOT_NEEDED
static const char *
copynamestring (const char *string)
{
  size_t len = strlen (string) + 1;
  char *s = (char *) obstack_alloc (&bname_obstack, len);
  strcpy (s, string);
  return s;
}
#endif


#if ENABLE_CHECKING
static long applcount_basilys;
static int appldepth_basilys;
#define MAXDEPTH_APPLY_BASILYS 2000
#endif
/*************** closure application ********************/
basilys_ptr_t
basilysgc_apply (basilysclosure_ptr_t clos_p,
		 basilys_ptr_t arg1_p,
		 const char *xargdescr_,
		 union basilysparam_un *xargtab_,
		 const char *xresdescr_, union basilysparam_un *xrestab_)
{
  basilys_ptr_t res = NULL;
  union
  {
    long funad[1 + sizeof (basilysroutfun_t *) / sizeof (long)];
    basilysroutfun_t *pfun;
  }
  ufun;
#if ENABLE_CHECKING
  applcount_basilys++;
  appldepth_basilys++;
  if (appldepth_basilys > MAXDEPTH_APPLY_BASILYS)
    fatal_error ("too deep (%d) basilys application", appldepth_basilys);
#endif
  memset (&ufun, 0, sizeof (ufun));
  if (basilys_magic_discr ((void *) clos_p) != OBMAG_CLOSURE)
    return NULL;
  if (basilys_magic_discr ((void *) clos_p->rout) !=
      OBMAG_ROUTINE || !clos_p->rout->routaddr)
    return NULL;
  memcpy (&ufun.funad, clos_p->rout->routaddr,
	  sizeof (clos_p->rout->routaddr));
  gcc_assert (ufun.pfun);
  /* only make sense on AMD64/Linux */
  gcc_assert (((unsigned long) ufun.pfun) > 4096UL
	      && ((unsigned long) ufun.pfun) < 0xffffffffff600000UL);
  res =
    (*ufun.pfun) (clos_p, arg1_p, xargdescr_, xargtab_, xresdescr_, xrestab_);
#if ENABLE_CHECKING
  appldepth_basilys--;
#endif
  return res;
}



/************** method sending ***************/
basilys_ptr_t
basilysgc_send (basilys_ptr_t recv_p,
		basilys_ptr_t sel_p,
		const char *xargdescr_,
		union basilysparam_un * xargtab_,
		const char *xresdescr_, union basilysparam_un * xrestab_)
{
#ifdef ENABLE_CHECKING
  static long sendcount;
  long sendnum = ++sendcount;
#endif
  BASILYS_ENTERFRAME (9, NULL);
#define recv    curfram__.varptr[0]
#define selv    curfram__.varptr[1]
#define argv    curfram__.varptr[2]
#define closv   curfram__.varptr[3]
#define discrv  curfram__.varptr[4]
#define mapv    curfram__.varptr[5]
#define superv  curfram__.varptr[6]
#define resv    curfram__.varptr[7]
#define ancv    curfram__.varptr[8]
#define obj_discrv ((basilysobject_ptr_t)(discrv))
#define obj_selv ((basilysobject_ptr_t)(selv))
#define clo_closv ((basilysclosure_ptr_t)(closv))
#define mul_ancv  ((struct basilysmultiple_st*)(ancv))
  recv = recv_p;
  selv = sel_p;
  if (!recv)
    goto end;
#ifdef ENABLE_CHECKING
  (void) sendnum;		/* to use it */
#endif
  if (basilys_magic_discr (selv) != OBMAG_OBJECT)
    goto end;
  if (!basilys_is_instance_of (selv, BASILYSG (CLASS_SELECTOR)))
    goto end;
#if 0 && ENABLE_CHECKING
  debugeprintf ("send #%ld recv %p", sendnum, (void *) recv);
  debugeprintf ("send #%ld selv %p <%s>", sendnum,
		(void *) obj_selv,
		basilys_string_str (obj_selv->obj_vartab[FNAMED_NAME]));
#endif
  discrv =
    recv ? ((basilys_ptr_t) recv)->u_discr : BASILYSGOB (DISCR_NULLRECV);
  while (discrv)
    {
      gcc_assert (basilys_magic_discr (discrv) == OBMAG_OBJECT);
      gcc_assert (obj_discrv->obj_len >= FDISCR__LAST);
#if 0 && ENABLE_CHECKING
      debugeprintf ("send #%ld discrv %p <%s>",
		    sendnum, discrv,
		    basilys_string_str (obj_discrv->obj_vartab[FNAMED_NAME]));
#endif
      mapv = obj_discrv->obj_vartab[FDISCR_METHODICT];
      if (basilys_magic_discr (mapv) == OBMAG_MAPOBJECTS)
	{
	  closv = basilys_get_mapobjects (mapv, selv);
	}
      else
	{
	  closv = obj_discrv->obj_vartab[FDISCR_SENDCLOSURE];
	  if (basilys_magic_discr (closv) == OBMAG_CLOSURE)
	    {
	      union basilysparam_un pararg[1];
	      pararg[0].bp_aptr = (basilys_ptr_t *) & selv;
	      resv = basilysgc_apply (closv, recv, BPARSTR_PTR, pararg,
				      "", NULL);
	      closv = resv;
	    }
	}
      if (basilys_magic_discr (closv) == OBMAG_CLOSURE)
	{
#if 0 && ENABLE_CHECKING
	  debugeprintf ("send #%ld applying closv %p", sendnum, closv);
#endif
	  resv =
	    basilysgc_apply (closv, recv, xargdescr_, xargtab_,
			     xresdescr_, xrestab_);
	  goto end;
	}
      discrv = obj_discrv->obj_vartab[FDISCR_SUPER];
    }				/* end while discrv */
  resv = NULL;
end:
#if 0 && ENABLE_CHECKING
  debugeprintf ("endsend #%ld recv %p resv %p selv %p <%s>",
		sendnum, recv, resv, (void *) obj_selv,
		basilys_string_str (obj_selv->obj_vartab[FNAMED_NAME]));
#endif
  BASILYS_EXITFRAME ();
  return resv;
#undef recv
#undef selv
#undef closv
#undef discrv
#undef argv
#undef mapv
#undef superv
#undef resv
#undef ancv
#undef obj_discrv
#undef obj_selv
#undef clo_closv
}

/* our temporary directory */
static char *tempdir_basilys;

/* returns malloc-ed path inside a temporary directory, with a given basename  */
char *
basilys_tempdir_path (const char *basnam)
{
  int loopcnt = 0;
  char *res = 0;
  char *cdir = 0;
  extern char *choose_tmpdir (void);	/* from libiberty/choose-temp.c */
  gcc_assert (basnam && (ISALNUM (basnam[0]) || basnam[0] == '_'));
  if (basilys_tempdir_string && basilys_tempdir_string[0])
    return concat (basilys_tempdir_string, "/", basnam, NULL);
  if (!tempdir_basilys)
    {
      char tbuf[80];
      /* usually this loop runs only once */
      for (loopcnt = 0; loopcnt < 1000; loopcnt++)
	{
	  int n = basilys_lrand () & 0xfffffff;
	  memset (tbuf, 0, sizeof (tbuf));
	  if (cdir)
	    {
	      free (cdir);
	      cdir = NULL;
	    };
	  snprintf (tbuf, sizeof (tbuf) - 1, "Melt%d-%d", (int) getpid (), n);
	  cdir = concat (choose_tmpdir (), "/", tbuf, NULL);
	  if (!mkdir (cdir, 0600))
	    {
	      tempdir_basilys = cdir;
	      break;
	    }
	}
      if (!tempdir_basilys)
	fatal_error ("failed to create temporary directory for MELT in %s",
		     choose_tmpdir ());
    };
  return concat (tempdir_basilys, "/", basnam, NULL);
}





/* the srcfile is a generated .c file or otherwise a dynamic library,
   the dlfile has no suffix, because the suffix is expected to be
   added by the basilys-gcc script */
static void
compile_to_dyl (const char *srcfile, const char *dlfile)
{
  struct pex_obj *pex = 0;
  int err = 0;
  int cstatus = 0;
  const char *errmsg = 0;
  /* possible improvement  : avoid recompiling
     when not necessary; using timestamps a la make is not enough,
     since the C source files are generated.  

     The melt-cc-script takes two arguments: the C source file path to
     compile as a basilys plugin, and the naked dynamic library file to be
     generated. Standard path are in Makefile.in $(melt_compile_script)

     The melt-cc-script should be generated in the building process.
     In addition of compiling the C source file, it should put into the
     generated dynamic library the following two constant strings;
     const char basilys_compiled_timestamp[];
     const char basilys_md5[];

     the basilys_compiled_timestamp should contain a human readable
     timestamp the basilys_md5 should contain the hexadecimal md5 digest,
     followed by the source file name (i.e. the single line output by the
     command: md5sum $Csourcefile; where $Csourcefile is replaced by the
     source file path)

   */
  const char *ourmeltcompilescript = NULL;
  struct pex_time ptime;
  char *argv[4];
  memset (&ptime, 0, sizeof (ptime));
  /* compute the ourmeltcompilscript */
  ourmeltcompilescript = getenv ("MELT_GCC_COMPILE_SCRIPT");
  if (!ourmeltcompilescript)
    ourmeltcompilescript = basilys_compile_script_string;
  if (!ourmeltcompilescript)
    ourmeltcompilescript = melt_compile_script;
  debugeprintf ("compile_to_dyl melt ourmeltcompilescript=%s",
		ourmeltcompilescript);
  debugeprintf ("compile_to_dyl srcfile %s dlfile %s", srcfile, dlfile);
  fflush (stdout);
  fflush (stderr);
  pex = pex_init (PEX_RECORD_TIMES, ourmeltcompilescript, NULL);
  argv[0] = (char *) ourmeltcompilescript;
  argv[1] = (char *) srcfile;
  argv[2] = (char *) dlfile;
  argv[3] = (char *) 0;
  errmsg =
    pex_run (pex, PEX_LAST | PEX_SEARCH, ourmeltcompilescript, argv,
	     NULL, NULL, &err);
  if (errmsg)
    fatal_error
      ("failed to basilys compile to dyl: %s %s %s : %s",
       ourmeltcompilescript, srcfile, dlfile, errmsg);
  if (!pex_get_status (pex, 1, &cstatus))
    fatal_error
      ("failed to get status of basilys dynamic compilation to dyl:  %s %s %s - %m",
       ourmeltcompilescript, srcfile, dlfile);
  if (!pex_get_times (pex, 1, &ptime))
    fatal_error
      ("failed to get time of basilys dynamic compilation to dyl:  %s %s %s - %m",
       ourmeltcompilescript, srcfile, dlfile);
  pex_free (pex);
  debugeprintf ("compile_to_dyl done srcfile %s dlfile %s", srcfile, dlfile);
}



/* load a dynamic library using the filepath DYPATH; if MD5SRC  is given,
   check that the basilys_md5 inside is indeed MD5SRC, otherwise
   return NULL */
static lt_dlhandle
load_checked_dylib (const char *dypath, char *md5src)
{
  lt_dlhandle dlh = NULL;
  char *dynmd5 = NULL;
  int i = 0, c = 0;
  char hbuf[4];
  dlh = lt_dlopenext (dypath);
  if (!dlh)
    return NULL;
  /* we always check that a basilys_md5 exists within the dynamically
     loaded stuff; otherwise it was not generated from MELT/basilys */
  dynmd5 = (char *) lt_dlsym (dlh, "basilys_md5");
  if (!dynmd5)
    goto bad;
  if (md5src)
    {
      for (i = 0; i < 16; i++)
	{
	  if (ISXDIGIT (dynmd5[2 * i]) && ISXDIGIT (dynmd5[2 * i + 1]))
	    {
	      hbuf[0] = dynmd5[2 * i];
	      hbuf[1] = dynmd5[2 * i + 1];
	      hbuf[2] = (char) 0;
	      c = (int) strtol (hbuf, (char **) 0, 16);
	      if (c != (int) (md5src[i] & 0xff))
		goto bad;
	    }
	  else
	    goto bad;
	}
    }
  return dlh;
bad:
  lt_dlclose (dlh);
  return NULL;
}


/* compile (as a dynamically loadable module) some (usually generated)
   C code (or a dynamically loaded stuff) and dynamically load it; the
   C code should contain a function named start_module_basilys; that
   function is called with the given modata and returns the module */
basilys_ptr_t
basilysgc_compile_dyn (basilys_ptr_t modata_p,  const char *modfile)
{
  char *srcpath = NULL;
  FILE *srcfi = NULL;
  lt_dlhandle dlh = 0;
  lt_ptr dlsy = 0;
  int modfilelen = 0;
  int isasrc = 0;
  typedef basilys_ptr_t startroutine_t (basilys_ptr_t);
  startroutine_t *starout = 0;
  int srcpathlen = 0;
  char md5srctab[16];
  char *md5src = NULL;
  char *plainstuffpath = NULL;
  char *tmpath = NULL;
  BASILYS_ENTERFRAME (3, NULL);
#define modulv curfram__.varptr[0]
#define mdatav curfram__.varptr[1]
  mdatav = modata_p;
  modfilelen = strlen (modfile);
  /* is the module file is a *.c file - otherwise it is supposed to be
     a dynamically loadable stuff ie *.so shared object or *.la
     libtool or *.sl or *.dylib etc..  */
  isasrc = modfilelen > 2 && modfile[modfilelen - 2] == '.'
    && modfile[modfilelen - 1] == 'c';
  debugeprintf ("basilysgc_compile modfile=%s - %s", modfile,
		isasrc ? "C source" : "dynloadable");
  if (isasrc)
    {
      /* absolute paths are taken as such */
      if (IS_ABSOLUTE_PATH (modfile))
	{
	  srcpath = xstrdup (modfile);
	  goto foundsrcpath;
	}
      /* relative path to some existing file are taken as such */
      else if (!access (modfile, R_OK))
	{
	  srcpath = xstrdup (modfile);
	  goto foundsrcpath;
	}
      /* check for modfile in our tempdir */
      tmpath = basilys_tempdir_path (modfile);
      if (!access (tmpath, R_OK))
	{
	  srcpath = tmpath;
	  goto foundsrcpath;
	}
      free (tmpath);
      tmpath = NULL;
      if (basilys_gensrcdir_string && basilys_gensrcdir_string[0])
	{
	  /* check for modfile in the gensrcdir */
	  tmpath = concat (basilys_gensrcdir_string, "/", modfile, NULL);
	  if (!access (tmpath, R_OK))
	    {
	      srcpath = tmpath;
	      goto foundsrcpath;
	    }
	  free (tmpath);
	  tmpath = NULL;
	}
      /* check for modfile in melt_source_dir */
      tmpath = concat (melt_source_dir, "/", modfile, NULL);
      if (!access (tmpath, R_OK))
	{
	  srcpath = tmpath;
	  goto foundsrcpath;
	}
      free (tmpath);
      tmpath = NULL;
    foundsrcpath:
      srcpathlen = srcpath ? strlen (srcpath) : 0;
      plainstuffpath = NULL;
      srcfi = fopen (srcpath, "r");
      if (!srcfi)
	fatal_error ("cannot open generated source file %s for MELT : %m",
		     srcpath);
      memset (md5srctab, 0, sizeof (md5srctab));
      if (md5_stream (srcfi, &md5srctab))
	fatal_error
	  ("failed to compute md5sum of generated source file %s for MELT",
	   srcpath);
      md5src = md5srctab;
      fclose (srcfi);
      srcfi = NULL;
      gcc_assert (modfilelen > 2 && modfile[modfilelen - 2] == '.'
		  && modfile[modfilelen - 1] == 'c');
      plainstuffpath = xstrdup (modfile);
      plainstuffpath[modfilelen - 2] = (char) 0;
    }
  else
    {				/* modfile is not a generated C srcfile */
      plainstuffpath = xstrdup (modfile);
    }
  /**
     we have to scan several dynlib directories to find the module;
     when we find a module, we dynamically load it to check that it
     has the right md5 sum (i.e. that its basilys_md5 is correct); if
     no dynlib is found, we have to compile the generated C source.
  **/
  /* check the plain stuff path directly */
  dlh = load_checked_dylib (plainstuffpath, md5src);
  if (dlh)
    goto dylibfound;
  /* absolute paths should be found */
  if (IS_ABSOLUTE_PATH (plainstuffpath))
    fatal_error ("failed to load melt dynlib %s (%s)", plainstuffpath,
		 lt_dlerror ());
  /* if a dynlib directory is given, check it */
  if (basilys_dynlibdir_string && basilys_dynlibdir_string[0])
    {
      tmpath = concat (basilys_dynlibdir_string, "/", plainstuffpath, NULL);
      dlh = load_checked_dylib (tmpath, md5src);
      if (dlh)
	{
	  free (plainstuffpath);
	  plainstuffpath = tmpath;
	  goto dylibfound;
	};
      free (tmpath);
    }
  /* check in the builtin melt dynamic lib directory */
  tmpath = concat (melt_dynlib_dir, "/", plainstuffpath, NULL);
  dlh = load_checked_dylib (tmpath, md5src);
  if (dlh)
    {
      free (plainstuffpath);
      plainstuffpath = tmpath;
      goto dylibfound;
    };
  free (tmpath);
  /* check in the temporary directory */
  tmpath = basilys_tempdir_path (plainstuffpath);
  dlh = tmpath ? load_checked_dylib (tmpath, md5src) : NULL;
  if (dlh)
    {
      free (plainstuffpath);
      plainstuffpath = tmpath;
      goto dylibfound;
    };
  free (tmpath);
  /* if we really have the source, we can afford to check in the current directory */
  if (md5src)
    {
      tmpath = concat ("./", plainstuffpath, NULL);
      dlh = load_checked_dylib (tmpath, md5src);
      if (dlh)
	{
	  free (plainstuffpath);
	  plainstuffpath = tmpath;
	  goto dylibfound;
	};
      free (tmpath);
    }
  /* if we have the srcpath but did'nt found the stuff, try to compile it using the temporary directory */
  if (srcpath && !strchr (plainstuffpath, '/'))
    {
      tmpath = basilys_tempdir_path (plainstuffpath);
      compile_to_dyl (srcpath, tmpath);
      debugeprintf ("basilysgc_compile srcpath=%s compiled to tmpath=%s",
		    srcpath, tmpath);
      dlh = load_checked_dylib (tmpath, md5src);
      if (dlh)
	{
	  free (plainstuffpath);
	  plainstuffpath = tmpath;
	  goto dylibfound;
	};
    }
  /* catch all situation, failed to find the dynamic stuff */
  fatal_error ("failed to find dynamic stuff for basilys generated %s (%s)",
	       modfile, lt_dlerror ());
 dylibfound:
  dlsy = lt_dlsym (dlh, "start_module_basilys");
  if (!dlsy)
    fatal_error
      ("basilysgc_compile failed to lt_dlsym start_module_basilys in modfile=%s plainstuff=%s - %s",
       modfile, plainstuffpath, lt_dlerror ());
  starout = (startroutine_t *) dlsy;
  debugeprintvalue ("mdatav before calling start_module_basilys", mdatav);
  debugeprintf
    ("basilysgc_compile before calling start_module_basilys @%p",
     (void *) dlsy);
  modulv = (*starout) (mdatav);
  debugeprintvalue ("modulv after calling start_module_basilys", modulv);
  /* we never free  plainstuffpath and we never release the shared library! */
  BASILYS_EXITFRAME ();
  return modulv;
#undef mdatav
#undef modulv
}

/*************** initial load machinery *******************/


struct reading_st
{
  FILE *rfil;
  const char *rpath;
  char *rcurlin;		/* current line mallocated buffer */
  int rlineno;			/* current line number */
  int rcol;			/* current column */
  basilys_ptr_t *rpfilnam;	/* pointer to location of file name string */
  basilys_ptr_t *rpgenv;	/* pointer to location of environment */
};
/* Obstack used for reading strings */
static struct obstack bstring_obstack;
#define rdback() (rd->rcol--)
#define rdnext() (rd->rcol++)
#define rdcurc() rd->rcurlin[rd->rcol]
#define rdfollowc(Rk) rd->rcurlin[rd->rcol + (Rk)]
#define rdeof() (feof(rd->rfil) && rd->rcurlin[rd->rcol]==0)
#define READ_ERROR(Fmt,...)					\
  fatal_error("%s:%d:%d: read error <%s:%d> - " Fmt,		\
	      rd->rpath, rd->rlineno,	rd->rcol,		\
	      basename(__FILE__),__LINE__, ##__VA_ARGS__)
/* readval returns the read value and sets *PGOT to true if something
   was read */
static basilys_ptr_t readval (struct reading_st *rd, bool * pgot);
static int
skipspace_getc (struct reading_st *rd)
{
  int c = 0;
  int incomm = 0;
readagain:
  if (rdeof ())
    return EOF;
  if (!rd->rcurlin)
    goto readline;
  c = rdcurc ();
  if (c == '\n' || c == 0)
  readline:
    {
      /* we expect most lines to fit into linbuf, so we don't handle
         efficiently long lines */
      static char linbuf[400];
      char *mlin = 0;		/* partial mallocated line buffer when
				   not fitting into linbuf */
      char *eol = 0;
      if (rd->rcurlin)
	free ((void *) rd->rcurlin);
      rd->rcurlin = NULL;
      /* we really want getline here .... */
      for (;;)
	{
	  memset (linbuf, 0, sizeof (linbuf));
	  eol = NULL;
	  if (!fgets (linbuf, sizeof (linbuf), rd->rfil))
	    {
	      /* reached eof, so either give mlin or duplicate an empty
	         line */
	      if (mlin)
		rd->rcurlin = mlin;
	      else
		rd->rcurlin = xstrdup ("");
	      break;
	    }
	  else
	    eol = strchr (linbuf, '\n');
	  if (eol)
	    {
	      if (rd->rcurlin)
		free ((void *) rd->rcurlin);
	      if (!mlin)
		rd->rcurlin = xstrdup (linbuf);
	      else
		{
		  rd->rcurlin = concat (mlin, linbuf, NULL);
		  free (mlin);
		}
	      break;
	    }
	  else
	    {
	      /* read partly a long line without reaching the end of line */
	      if (mlin)
		{
		  char *newmlin = concat (mlin, linbuf, NULL);
		  free (mlin);
		  mlin = newmlin;
		}
	      else
		mlin = xstrdup (linbuf);
	    }
	};
      rd->rlineno++;
      rd->rcol = 0;
      goto readagain;
    }
  else if (c == ';')
    goto readline;
  else if (c == '#' && rdfollowc (1) == '|')
    {
      incomm = 1;
      rdnext ();
      c = rdcurc ();
      goto readagain;
    }
  else if (incomm && c == '|' && rdfollowc (1) == '#')
    {
      incomm = 0;
      rdnext ();
      rdnext ();
      c = rdcurc ();
      goto readagain;
    }
  else if (ISSPACE (c) || incomm)
    {
      rdnext ();
      c = rdcurc ();
      goto readagain;
    }
  else
    return c;
}


#define EXTRANAMECHARS "_+-*/<>=!?:%~&@$"
/* read a simple name on the bname_obstack */
static char *
readsimplename (struct reading_st *rd)
{
  int c = 0;
  while (!rdeof () && (c = rdcurc ()) > 0 &&
	 (ISALNUM (c) || strchr (EXTRANAMECHARS, c) != NULL))
    {
      obstack_1grow (&bname_obstack, (char) c);
      rdnext ();
    }
  obstack_1grow (&bname_obstack, (char) 0);
  return XOBFINISH (&bname_obstack, char *);
}


/* read an integer, like +123, which may also be +%numbername or +|fieldname */
static long
readsimplelong (struct reading_st *rd)
{
  int c = 0;
  long r = 0;
  char *endp = 0;
  char *nam = 0;
  bool neg = FALSE;
  /* we do not need any GC locals ie BASILYS_ENTERFRAME because no
     garbage collection occurs here */
  c = rdcurc ();
  if (((c == '+' || c == '-') && ISDIGIT (rdfollowc (1))) || ISDIGIT (c))
    {
      /* R5RS and R6RS require decimal notation -since the binary and
         hex numbers are hash-prefixed but for convenience we accept
         them thru strtol */
      r = strtol (&rdcurc (), &endp, 0);
      if (r == 0 && endp <= &rdcurc ())
	READ_ERROR ("failed to read number %.20s", &rdcurc ());
      rd->rcol += endp - &rdcurc ();
      return r;
    }
  else if ((c == '+' || c == '-') && rdfollowc (1) == '%')
    {
      neg = (c == '-');
      rdnext ();
      rdnext ();
      nam = readsimplename (rd);
      r = -1;
      /* the +%magicname notation is seldom used, we don't care to do
         many needless strcmp-s in that case, to be able to define the
         below simple macro */
      if (!nam)
	READ_ERROR
	  ("magic number name expected after +%% or -%% for magic %s", nam);
#define NUMNAM(N) else if (!strcmp(nam,#N)) r = (N)
      NUMNAM (OBMAG_OBJECT);
      NUMNAM (OBMAG_MULTIPLE);
      NUMNAM (OBMAG_BOX);
      NUMNAM (OBMAG_CLOSURE);
      NUMNAM (OBMAG_ROUTINE);
      NUMNAM (OBMAG_LIST);
      NUMNAM (OBMAG_PAIR);
      NUMNAM (OBMAG_TRIPLE);
      NUMNAM (OBMAG_INT);
      NUMNAM (OBMAG_MIXINT);
      NUMNAM (OBMAG_REAL);
      NUMNAM (OBMAG_STRING);
      NUMNAM (OBMAG_STRBUF);
      NUMNAM (OBMAG_TREE);
      NUMNAM (OBMAG_BASICBLOCK);
      NUMNAM (OBMAG_EDGE);
      NUMNAM (OBMAG_MAPOBJECTS);
      NUMNAM (OBMAG_MAPSTRINGS);
      NUMNAM (OBMAG_MAPTREES);
      NUMNAM (OBMAG_MAPBASICBLOCKS);
      NUMNAM (OBMAG_MAPEDGES);
      NUMNAM (OBMAG_DECAY);
      NUMNAM (OBMAG_SPEC_FILE);
      NUMNAM (OBMAG_SPEC_MPFR);
      NUMNAM (OBMAG_SPECPPL_COEFFICIENT);
      NUMNAM (OBMAG_SPECPPL_LINEAR_EXPRESSION);
      NUMNAM (OBMAG_SPECPPL_CONSTRAINT);
      NUMNAM (OBMAG_SPECPPL_CONSTRAINT_SYSTEM);
      NUMNAM (OBMAG_SPECPPL_GENERATOR);
      NUMNAM (OBMAG_SPECPPL_GENERATOR_SYSTEM);
      NUMNAM (FPROPED_PROP);
      NUMNAM (FPROPED__LAST);
      NUMNAM (FNAMED_NAME);
      NUMNAM (FNAMED__LAST);
      NUMNAM (FDISCR_METHODICT);
      NUMNAM (FDISCR_SENDCLOSURE);
      NUMNAM (FDISCR__LAST);
      NUMNAM (FCLASS_ANCESTORS);
      NUMNAM (FCLASS_FIELDS);
      NUMNAM (FCLASS_OBJNUMDESCR);
      NUMNAM (FCLASS_DATA);
      NUMNAM (FCLASS__LAST);
      NUMNAM (FSEXPR_LOCATION);
      NUMNAM (FSEXPR_CONTENTS);
      NUMNAM (FSEXPR__LAST);
      /***
      not @NumNam (FFIELD_OWNCLASS);
      not @NumNam (FFIELD_TYPINFO);
      not @NumNam (FFIELD__LAST);
      not @NumNam (FRENV_MACRODICT);
      not @NumNam (FRENV_NAMEBIND);
      not @NumNam (FRENV_PARENTENV);
      not @NumNam (FRENV__LAST);
      not @NumNam (FSYMB_DATA);
      not @NumNam (FSYMB__LAST);
      not @NumNam (FQUARK_SIGN);
      not @NumNam (FQUARK_DATA);
      not @NumNam (FQUARK__LAST);
      not @NumNam (BPAR_PTR);
      not @NumNam (BPAR_RESTPTR);
      not @NumNam (BPAR_TREE);
      not @NumNam (BPAR_LONG);
      not @NumNam (BPAR_EDGE);
      not @NumNam (BPAR_BB);
      ***/
#undef NUMNAM
      if (r < 0)
	READ_ERROR ("bad magic number name %s", nam);
      obstack_free (&bname_obstack, nam);
      return neg ? -r : r;
    }
  else
    READ_ERROR ("invalid number %.20s", &rdcurc ());
  return 0;
}


static basilys_ptr_t
readseqlist (struct reading_st *rd, int endc)
{
  int c = 0;
  int nbcomp = 0;
  bool got = FALSE;
  BASILYS_ENTERFRAME (2, NULL);
#define seqv curfram__.varptr[0]
#define compv curfram__.varptr[1]
  seqv = basilysgc_new_list (BASILYSGOB (DISCR_LIST));
readagain:
  compv = NULL;
  c = skipspace_getc (rd);
  if (c == endc)
    {
      rdnext ();
      goto end;
    }
  got = FALSE;
  compv = readval (rd, &got);
  if (!compv && !got)
    READ_ERROR ("unexpected stuff in seq %.20s", &rdcurc ());
  basilysgc_append_list (seqv, compv);
  nbcomp++;
  goto readagain;
end:
  BASILYS_EXITFRAME ();
  return seqv;
#undef compv
#undef seqv
}




static basilys_ptr_t
makesexpr (struct reading_st *rd, int lineno, basilys_ptr_t contents_p)
{
  BASILYS_ENTERFRAME (4, NULL);
#define sexprv  curfram__.varptr[0]
#define contsv   curfram__.varptr[1]
#define locmixv curfram__.varptr[2]
  contsv = contents_p;
  gcc_assert (basilys_magic_discr (contsv) == OBMAG_LIST);
  locmixv = basilysgc_new_mixint (BASILYSGOB (DISCR_MIXEDINT),
				  *rd->rpfilnam, (long) lineno);
  sexprv = basilysgc_new_raw_object (BASILYSGOB (CLASS_SEXPR), FSEXPR__LAST);
  ((basilysobject_ptr_t) (sexprv))->obj_vartab[FSEXPR_LOCATION] = locmixv;
  ((basilysobject_ptr_t) (sexprv))->obj_vartab[FSEXPR_CONTENTS] = contsv;
  basilysgc_touch (sexprv);
  BASILYS_EXITFRAME ();
  return sexprv;
#undef sexprv
#undef contsv
#undef locmixv
}


basilys_ptr_t
basilysgc_named_symbol (const char *nam, int create)
{
  int namlen = 0, ix = 0;
  char *namdup = 0;
  char tinybuf[130];
  BASILYS_ENTERFRAME (4, NULL);
#define symbv    curfram__.varptr[0]
#define dictv    curfram__.varptr[1]
#define closv    curfram__.varptr[2]
#define nstrv    curfram__.varptr[3]
  symbv = NULL;
  dictv = NULL;
  closv = NULL;
  if (!nam)
    goto end;
  namlen = strlen (nam);
  memset (tinybuf, 0, sizeof (tinybuf));
  if (namlen < (int) sizeof (tinybuf) - 2)
    namdup = strcpy (tinybuf, nam);
  else
    namdup = strcpy (xcalloc (namlen + 1, 1), nam);
  gcc_assert (basilys_magic_discr (BASILYSG (CLASS_TOKENIZER))
	      == OBMAG_OBJECT);
  gcc_assert (basilys_magic_discr (BASILYSG (TOKENIZER)) == OBMAG_OBJECT);
  for (ix = 0; ix < namlen; ix++)
    if (ISALPHA (namdup[ix]))
      namdup[ix] = TOUPPER (namdup[ix]);
  if (basilys_is_instance_of
      (BASILYSG (TOKENIZER), BASILYSG (CLASS_TOKENIZER))
      && BASILYSGOB (TOKENIZER)->obj_len >= FTOK__LAST)
    {
      dictv = BASILYSGOB (TOKENIZER)->obj_vartab[FTOK_SYMBDICT];
      if (basilys_magic_discr (dictv) == OBMAG_MAPSTRINGS)
	symbv = basilys_get_mapstrings (dictv, namdup);
      if (symbv || !create)
	goto end;
      closv = BASILYSGOB (TOKENIZER)->obj_vartab[FTOK_ADDSYMB];
      if (basilys_magic_discr (closv) == OBMAG_CLOSURE)
	{
	  union basilysparam_un pararg[1];
	  memset (&pararg, 0, sizeof (pararg));
	  nstrv = basilysgc_new_string (BASILYSGOB (DISCR_STRING), namdup);
	  pararg[0].bp_aptr = (basilys_ptr_t *) & nstrv;
	  symbv =
	    basilysgc_apply (closv, BASILYSG (TOKENIZER), BPARSTR_PTR,
			     pararg, "", NULL);
	  goto end;
	}
    }
end:;
  if (namdup && namdup != tinybuf)
    free (namdup);
  BASILYS_EXITFRAME ();
  return symbv;
#undef symbv
#undef dictv
#undef closv
#undef nstrv
}

basilys_ptr_t
basilysgc_intern_symbol (basilys_ptr_t symb_p)
{
  BASILYS_ENTERFRAME (5, NULL);
#define symbv    curfram__.varptr[0]
#define dictv    curfram__.varptr[1]
#define closv    curfram__.varptr[2]
#define nstrv    curfram__.varptr[3]
#define resv     curfram__.varptr[4]
#define obj_symbv    ((basilysobject_ptr_t)(symbv))
  symbv = symb_p;
  if (basilys_magic_discr (symbv) != OBMAG_OBJECT
      || obj_symbv->obj_len < FSYMB__LAST
      || !basilys_is_instance_of (symbv, BASILYSG (CLASS_SYMBOL)))
    goto fail;
  nstrv = obj_symbv->obj_vartab[FNAMED_NAME];
  if (basilys_magic_discr (nstrv) != OBMAG_STRING)
    goto fail;
  if (basilys_magic_discr (BASILYSG (TOKENIZER)) !=
      OBMAG_OBJECT
      || BASILYSGOB (TOKENIZER)->obj_len < FTOK__LAST
      || !basilys_is_instance_of (BASILYSG (TOKENIZER),
				  BASILYSG (CLASS_TOKENIZER)))
    goto fail;
  closv = BASILYSGOB (TOKENIZER)->obj_vartab[FTOK_INTERNSYMB];
  if (basilys_magic_discr (closv) != OBMAG_CLOSURE)
    goto fail;
  else
    {
      union basilysparam_un pararg[1];
      memset (&pararg, 0, sizeof (pararg));
      pararg[0].bp_aptr = (basilys_ptr_t *) & symbv;
      resv =
	basilysgc_apply (closv, BASILYSG (TOKENIZER), BPARSTR_PTR,
			 pararg, "", NULL);
      goto end;
    }
fail:
  resv = NULL;
end:;
  BASILYS_EXITFRAME ();
  return resv;
#undef symbv
#undef dictv
#undef closv
#undef nstrv
#undef resv
#undef obj_symbv
}


basilys_ptr_t
basilysgc_intern_keyword (basilys_ptr_t keyw_p)
{
  BASILYS_ENTERFRAME (5, NULL);
#define keywv    curfram__.varptr[0]
#define dictv    curfram__.varptr[1]
#define closv    curfram__.varptr[2]
#define nstrv    curfram__.varptr[3]
#define resv     curfram__.varptr[4]
#define obj_keywv    ((basilysobject_ptr_t)(keywv))
  keywv = keyw_p;
  if (basilys_magic_discr (keywv) != OBMAG_OBJECT
      || obj_keywv->obj_len < FSYMB__LAST
      || !basilys_is_instance_of (keywv, BASILYSG (CLASS_KEYWORD)))
    goto fail;
  nstrv = obj_keywv->obj_vartab[FNAMED_NAME];
  if (basilys_magic_discr (nstrv) != OBMAG_STRING)
    goto fail;
  if (basilys_magic_discr (BASILYSG (TOKENIZER)) !=
      OBMAG_OBJECT
      || BASILYSGOB (TOKENIZER)->obj_len < FTOK__LAST
      || !basilys_is_instance_of (BASILYSG (TOKENIZER),
				  BASILYSG (CLASS_TOKENIZER)))
    goto fail;
  closv = BASILYSGOB (TOKENIZER)->obj_vartab[FTOK_INTERNKEYW];
  if (basilys_magic_discr (closv) != OBMAG_CLOSURE)
    goto fail;
  else
    {
      union basilysparam_un pararg[1];
      memset (&pararg, 0, sizeof (pararg));
      pararg[0].bp_aptr = (basilys_ptr_t *) & keywv;
      resv =
	basilysgc_apply (closv, BASILYSG (TOKENIZER), BPARSTR_PTR,
			 pararg, "", NULL);
      goto end;
    }
fail:
  resv = NULL;
end:;
  BASILYS_EXITFRAME ();
  return resv;
#undef symbv
#undef dictv
#undef closv
#undef nstrv
#undef resv
#undef obj_symbv
}






basilys_ptr_t
basilysgc_named_keyword (const char *nam, int create)
{
  int namlen = 0, ix = 0;
  char *namdup = 0;
  char tinybuf[130];
  BASILYS_ENTERFRAME (4, NULL);
#define keywv    curfram__.varptr[0]
#define dictv    curfram__.varptr[1]
#define closv    curfram__.varptr[2]
#define nstrv    curfram__.varptr[3]
  keywv = NULL;
  dictv = NULL;
  closv = NULL;
  if (!nam)
    goto end;
  if (nam[0] == ':')
    nam++;
  namlen = strlen (nam);
  memset (tinybuf, 0, sizeof (tinybuf));
  if (namlen < (int) sizeof (tinybuf) - 2)
    namdup = strcpy (tinybuf, nam);
  else
    namdup = strcpy (xcalloc (namlen + 1, 1), nam);
  for (ix = 0; ix < namlen; ix++)
    if (ISALPHA (namdup[ix]))
      namdup[ix] = TOUPPER (namdup[ix]);
  gcc_assert (basilys_magic_discr (BASILYSG (CLASS_TOKENIZER))
	      == OBMAG_OBJECT);
  gcc_assert (basilys_magic_discr (BASILYSG (TOKENIZER)) == OBMAG_OBJECT);
  if (basilys_is_instance_of
      (BASILYSG (TOKENIZER), BASILYSG (CLASS_TOKENIZER))
      && BASILYSGOB (TOKENIZER)->obj_len >= FTOK__LAST)
    {
      dictv = BASILYSGOB (TOKENIZER)->obj_vartab[FTOK_KEYWDICT];
      if (basilys_magic_discr (dictv) == OBMAG_MAPSTRINGS)
	keywv = basilys_get_mapstrings (dictv, namdup);
      if (keywv || !create)
	goto end;
      closv = BASILYSGOB (TOKENIZER)->obj_vartab[FTOK_ADDKEYW];
      if (basilys_magic_discr (closv) == OBMAG_CLOSURE)
	{
	  union basilysparam_un pararg[1];
	  memset (&pararg, 0, sizeof (pararg));
	  nstrv = basilysgc_new_string (BASILYSGOB (DISCR_STRING), namdup);
	  pararg[0].bp_aptr = (basilys_ptr_t *) & nstrv;
	  keywv =
	    basilysgc_apply (closv, BASILYSG (TOKENIZER), BPARSTR_PTR,
			     pararg, "", NULL);
	  goto end;
	}
    }
end:;
  if (namdup && namdup != tinybuf)
    free (namdup);
  BASILYS_EXITFRAME ();
  return keywv;
#undef keywv
#undef dictv
#undef closv
#undef nstrv
}



static basilys_ptr_t
readsexpr (struct reading_st *rd, int endc)
{
  int c = 0, lineno = rd->rlineno;
  BASILYS_ENTERFRAME (3, NULL);
#define sexprv  curfram__.varptr[0]
#define contv   curfram__.varptr[1]
#define locmixv curfram__.varptr[2]
  if (!endc || rdeof ())
    READ_ERROR ("eof in s-expr (lin%d)", lineno);
  c = skipspace_getc (rd);
  contv = readseqlist (rd, endc);
  sexprv = makesexpr (rd, lineno, contv);
  BASILYS_EXITFRAME ();
  return sexprv;
#undef sexprv
#undef contv
#undef locmixv
}


static basilys_ptr_t
readassoc (struct reading_st *rd)
{
  int sz = 0, c = 0, ln = 0, pos = 0;
  BASILYS_ENTERFRAME (3, NULL);
#define mapv  curfram__.varptr[0]
#define attrv curfram__.varptr[1]
#define valv   curfram__.varptr[2]
  /* maybe read the size */
  if (rdcurc () == '/')
    {
      sscanf (&rdcurc (), "/%d%n", &sz, &pos);
      if (pos > 0)
	rd->rcol += pos;
    };
  if (sz > BASILYS_MAXLEN)
    sz = BASILYS_MAXLEN;
  else if (sz < 0)
    sz = 2;
  mapv = basilysgc_new_mapobjects (BASILYSGOB (DISCR_MAPOBJECTS), sz);
  c = skipspace_getc (rd);
  while (c != '}' && !rdeof ())
    {
      bool gotat = FALSE, gotva = FALSE;
      ln = rd->rlineno;
      attrv = readval (rd, &gotat);
      if (!gotat || !attrv || basilys_magic_discr (attrv) != OBMAG_OBJECT)
	READ_ERROR ("bad attribute in mapoobject line %d", ln);
      c = skipspace_getc (rd);
      if (c != '=')
	READ_ERROR ("expected equal = after attribute but got %c",
		    ISPRINT (c) ? c : ' ');
      rdnext ();
      ln = rd->rlineno;
      valv = readval (rd, &gotva);
      if (!valv)
	READ_ERROR ("null or missing value in mapobject line %d", ln);
      c = skipspace_getc (rd);
      if (c == '.')
	c = skipspace_getc (rd);
    }
  if (c == '}')
    rdnext ();
  BASILYS_EXITFRAME ();
  return mapv;
#undef mapv
#undef attrv
#undef valv
}



static basilys_ptr_t
readstring (struct reading_st *rd)
{
  int c = 0;
  int nbesc = 0;
  char *cstr = 0, *endc = 0;
  BASILYS_ENTERFRAME (1, NULL);
#define strv   curfram__.varptr[0]
#define str_strv  ((struct basilysstring_st*)(strv))
  while ((c = rdcurc ()) != '"' && !rdeof ())
    {
      if (c != '\\')
	{
	  obstack_1grow (&bstring_obstack, (char) c);
	  rdnext ();
	}
      else
	{
	  rdnext ();
	  c = rdcurc ();
	  nbesc++;
	  switch (c)
	    {
	    case 'a':
	      c = '\a';
	      rdnext ();
	      break;
	    case 'b':
	      c = '\b';
	      rdnext ();
	      break;
	    case 't':
	      c = '\t';
	      rdnext ();
	      break;
	    case 'n':
	      c = '\n';
	      rdnext ();
	      break;
	    case 'v':
	      c = '\v';
	      rdnext ();
	      break;
	    case 'f':
	      c = '\f';
	      rdnext ();
	      break;
	    case 'r':
	      c = '\r';
	      rdnext ();
	      break;
	    case '"':
	      c = '\"';
	      rdnext ();
	      break;
	    case '\n':
	    case '\r':
	      rdnext ();
	      continue;
	    case ' ':
	      c = ' ';
	      rdnext ();
	      break;
	    case 'x':
	      rdnext ();
	      c = (char) strtol (&rdcurc (), &endc, 16);
	      if (c == 0 && endc <= &rdcurc ())
		READ_ERROR ("illegal hex \\x escape in string %.20s",
			    &rdcurc ());
	      if (*endc == ';')
		endc++;
	      rd->rcol += endc - &rdcurc ();
	      break;
	    default:
	      READ_ERROR ("illegal escape sequence %.3s in string",
			  &rdcurc () - 1);
	    }
	  obstack_1grow (&bstring_obstack, (char) c);
	}
    }
  if (c == '"')
    rdnext ();
  else
    READ_ERROR ("unterminated string %.20s", &rdcurc ());
  obstack_1grow (&bstring_obstack, (char) 0);
  cstr = XOBFINISH (&bstring_obstack, char *);
  strv = basilysgc_new_string (BASILYSGOB (DISCR_STRING), cstr);
  if (nbesc > 0)
    debugeprintf ("read at line %d escaped string '%s'", rd->rlineno, cstr);
  obstack_free (&bstring_obstack, cstr);
  BASILYS_EXITFRAME ();
  return strv;
#undef strv
#undef str_strv
}


static basilys_ptr_t
readhashescape (struct reading_st *rd)
{
  int c = 0;
  BASILYS_ENTERFRAME (4, NULL);
#define readv  curfram__.varptr[0]
#define compv  curfram__.varptr[1]
#define listv  curfram__.varptr[2]
#define pairv  curfram__.varptr[3]
  readv = NULL;
  c = rdcurc ();
  if (!c || rdeof ())
    READ_ERROR ("eof in hashescape %.20s", &rdcurc ());
  if (c == '\\')
    {
      rdnext ();
      if (ISALPHA (rdcurc ()) && rdcurc () != 'x' && ISALPHA (rdfollowc (1)))
	{
	  char *nam = readsimplename (rd);
	  c = 0;
	  if (!strcmp (nam, "nul"))
	    c = 0;
	  else if (!strcmp (nam, "alarm"))
	    c = '\a';
	  else if (!strcmp (nam, "backspace"))
	    c = '\b';
	  else if (!strcmp (nam, "tab"))
	    c = '\t';
	  else if (!strcmp (nam, "linefeed"))
	    c = '\n';
	  else if (!strcmp (nam, "vtab"))
	    c = '\v';
	  else if (!strcmp (nam, "page"))
	    c = '\f';
	  else if (!strcmp (nam, "return"))
	    c = '\r';
	  else if (!strcmp (nam, "space"))
	    c = ' ';
	  /* won't work on non ASCII or ISO or Unicode host, but we don't care */
	  else if (!strcmp (nam, "delete"))
	    c = 0xff;
	  else if (!strcmp (nam, "esc"))
	    c = 0x1b;
	  else
	    READ_ERROR ("invalid char escape %s", nam);
	  obstack_free (&bname_obstack, nam);
	char_escape:
	  readv = basilysgc_new_int (BASILYSGOB (DISCR_CHARINTEGER), c);
	}
      else if (rdcurc () == 'x' && ISXDIGIT (rdfollowc (1)))
	{
	  char *endc = 0;
	  rdnext ();
	  c = strtol (&rdcurc (), &endc, 16);
	  if (c == 0 && endc <= &rdcurc ())
	    READ_ERROR ("illigal hex #\\x escape in char %.20s", &rdcurc ());
	  rd->rcol += endc - &rdcurc ();
	  goto char_escape;
	}
      else if (ISPRINT (rdcurc ()))
	{
	  c = rdcurc ();
	  rdnext ();
	  goto char_escape;
	}
      else
	READ_ERROR ("unrecognized char escape #\\%s", &rdcurc ());
    }
  else if (c == '(')
    {
      int ln = 0, ix = 0;
      listv = readseqlist (rd, ')');
      ln = basilys_list_length (listv);
      gcc_assert (ln >= 0);
      readv = basilysgc_new_multiple (BASILYSGOB (DISCR_MULTIPLE), ln);
      for ((ix = 0), (pairv =
		      ((struct basilyslist_st *) (listv))->first);
	   ix < ln && basilys_magic_discr (pairv) == OBMAG_PAIR;
	   pairv = ((struct basilyspair_st *) (pairv))->tl)
	((struct basilysmultiple_st *) (readv))->
	  tabval[ix++] = ((struct basilyspair_st *) (pairv))->hd;
      basilysgc_touch (readv);
    }
  else if (c == '[')
    {
      /* a basilys extension #[ .... ] for lists */
      readv = readseqlist (rd, ']');
    }
  else if ((c == 'b' || c == 'B') && ISDIGIT (rdfollowc (1)))
    {
      /* binary number */
      char *endc = 0;
      long n = 0;
      rdnext ();
      n = strtol (&rdcurc (), &endc, 2);
      if (n == 0 && endc <= &rdcurc ())
	READ_ERROR ("bad binary number %s", endc);
      readv = basilysgc_new_int (BASILYSGOB (DISCR_INTEGER), n);
    }
  else if ((c == 'o' || c == 'O') && ISDIGIT (rdfollowc (1)))
    {
      /* octal number */
      char *endc = 0;
      long n = 0;
      rdnext ();
      n = strtol (&rdcurc (), &endc, 8);
      if (n == 0 && endc <= &rdcurc ())
	READ_ERROR ("bad octal number %s", endc);
      readv = basilysgc_new_int (BASILYSGOB (DISCR_INTEGER), n);
    }
  else if ((c == 'd' || c == 'D') && ISDIGIT (rdfollowc (1)))
    {
      /* decimal number */
      char *endc = 0;
      long n = 0;
      rdnext ();
      n = strtol (&rdcurc (), &endc, 10);
      if (n == 0 && endc <= &rdcurc ())
	READ_ERROR ("bad decimal number %s", endc);
      readv = basilysgc_new_int (BASILYSGOB (DISCR_INTEGER), n);
    }
  else if ((c == 'x' || c == 'x') && ISDIGIT (rdfollowc (1)))
    {
      /* hex number */
      char *endc = 0;
      long n = 0;
      rdnext ();
      n = strtol (&rdcurc (), &endc, 16);
      if (n == 0 && endc <= &rdcurc ())
	READ_ERROR ("bad octal number %s", endc);
      readv = basilysgc_new_int (BASILYSGOB (DISCR_INTEGER), n);
    }
  else if (c == '+' && ISALPHA (rdfollowc (1)))
    {
      bool gotcomp = FALSE;
      char *nam = 0;
      nam = readsimplename (rd);
      compv = readval (rd, &gotcomp);
      if (!strcmp (nam, "BASILYS"))
	readv = compv;
      else
	readv = readval (rd, &gotcomp);
    }
  else
    READ_ERROR ("invalid escape %.20s", &rdcurc ());
  BASILYS_EXITFRAME ();
  return readv;
#undef readv
#undef listv
#undef compv
#undef pairv
}



static basilys_ptr_t
readval (struct reading_st *rd, bool * pgot)
{
  int c = 0;
  char *nam = 0;
  BASILYS_ENTERFRAME (4, NULL);
#define readv   curfram__.varptr[0]
#define compv   curfram__.varptr[1]
#define seqv    curfram__.varptr[2]
#define altv    curfram__.varptr[3]
  readv = NULL;
  c = skipspace_getc (rd);
  /*   debugeprintf ("start readval line %d col %d char %c", rd->rlineno, rd->rcol,
     ISPRINT (c) ? c : ' '); */
  if (ISDIGIT (c)
      || ((c == '-' || c == '+')
	  && (ISDIGIT (rdfollowc (1)) || rdfollowc (1) == '%'
	      || rdfollowc (1) == '|')))
    {
      long num = 0;
      num = readsimplelong (rd);
      readv =
	basilysgc_new_int ((basilysobject_ptr_t) BASILYSGOB (DISCR_INTEGER),
			   num);
      *pgot = TRUE;
      goto end;
    }				/* end if ISDIGIT or '-' or '+' */
  else if (c == '"')
    {
      rdnext ();
      readv = readstring (rd);
      *pgot = TRUE;
      goto end;
    }				/* end if '"' */
  else if (c == '(')
    {
      rdnext ();
      if (rdcurc () == ')')
	{
	  rdnext ();
	  readv = NULL;
	  *pgot = TRUE;
	  goto end;
	}
      readv = readsexpr (rd, ')');
      *pgot = TRUE;
      goto end;
    }				/* end if '(' */
  else if (c == '[')
    {
      rdnext ();
      readv = readsexpr (rd, ']');
      *pgot = TRUE;
      goto end;
    }				/* end if '(' */
  else if (c == '{')
    {
      rdnext ();
      readv = readassoc (rd);
      *pgot = TRUE;
      goto end;
    }
  else if (c == '#')
    {
      rdnext ();
      c = rdcurc ();
      readv = readhashescape (rd);
      *pgot = TRUE;
      goto end;
    }
  else if (c == '\'')
    {
      int lineno = rd->rlineno;
      bool got = false;
      rdnext ();
      compv = readval (rd, &got);
      if (!got)
	READ_ERROR ("expecting value after quote %.20s", &rdcurc ());
      seqv = basilysgc_new_list (BASILYSGOB (DISCR_LIST));
      altv = basilysgc_named_symbol ("quote", BASILYS_CREATE);
      basilysgc_append_list (seqv, altv);
      basilysgc_append_list (seqv, compv);
      readv = makesexpr (rd, lineno, seqv);
      *pgot = TRUE;
      goto end;
    }
  else if (c == '`')
    {
      int lineno = rd->rlineno;
      bool got = false;
      rdnext ();
      compv = readval (rd, &got);
      if (!got)
	READ_ERROR ("expecting value after backquote %.20s", &rdcurc ());
      seqv = basilysgc_new_list (BASILYSGOB (DISCR_LIST));
      altv = basilysgc_named_symbol ("backquote", BASILYS_CREATE);
      basilysgc_append_list (seqv, altv);
      basilysgc_append_list (seqv, compv);
      readv = makesexpr (rd, lineno, seqv);
      *pgot = TRUE;
      goto end;
    }
  else if (c == ',')
    {
      int lineno = rd->rlineno;
      bool got = false;
      rdnext ();
      compv = readval (rd, &got);
      if (!got)
	READ_ERROR ("expecting value after comma %.20s", &rdcurc ());
      seqv = basilysgc_new_list (BASILYSGOB (DISCR_LIST));
      altv = basilysgc_named_symbol ("comma", BASILYS_CREATE);
      basilysgc_append_list (seqv, altv);
      basilysgc_append_list (seqv, compv);
      readv = makesexpr (rd, lineno, seqv);
      *pgot = TRUE;
      goto end;
    }
  else if (c == ':')
    {
      nam = readsimplename (rd);
      readv = basilysgc_named_keyword (nam, BASILYS_CREATE);
      if (!readv)
	READ_ERROR ("unknown named keyword %s", nam);
      *pgot = TRUE;
      goto end;
    }
  else if (ISALPHA (c) || strchr (EXTRANAMECHARS, c) != NULL)
    {
      nam = readsimplename (rd);
      readv = basilysgc_named_symbol (nam, BASILYS_CREATE);
      *pgot = TRUE;
      goto end;
    }
  else
    {
      if (c >= 0)
	rdback ();
      readv = NULL;
    }
end:
  BASILYS_EXITFRAME ();
  if (nam)
    {
      *nam = 0;
      obstack_free (&bname_obstack, nam);
    };
  return readv;
#undef readv
#undef compv
#undef seqv
#undef altv
}



basilys_ptr_t
basilysgc_read_file (const char *filnam)
{
  struct reading_st rds;
  FILE *fil = 0;
  char *filpath = 0, *filnamdup = 0;
  int filnamlen = 0;
  char tinybuf[140];
  struct reading_st *rd = 0;
  BASILYS_ENTERFRAME (4, NULL);
#define genv      curfram__.varptr[0]
#define valv      curfram__.varptr[1]
#define filnamv   curfram__.varptr[2]
#define seqv      curfram__.varptr[3]
  memset (&rds, 0, sizeof (rds));
  memset (tinybuf, 0, sizeof (tinybuf));
  if (!filnam)
    goto end;
  debugeprintf ("basilysgc_read_file filnam %s", filnam);
  filnamlen = strlen (filnam);
  if (filnamlen < (int) sizeof (tinybuf) - 1)
    filnamdup = strcpy (tinybuf, filnam);
  else
    filnamdup = strcpy (xcalloc (filnamlen + 1, 1), filnam);
  fil = fopen (filnamdup, "rt");
  if (!fil)
    {
      filpath = update_path (filnamdup, "GCC");
      fil = fopen (filpath, "rt");
    }
  if (!fil)
    fatal_error ("cannot open basilys file %s - %m", filnamdup);
  /*  debugeprintf ("starting loading file %s", filnamdup); */
  rds.rfil = fil;
  rds.rpath = filnamdup;
  rds.rlineno = 0;
  rd = &rds;
  filnamv = basilysgc_new_string (BASILYSGOB (DISCR_STRING), filnamdup);
  rds.rpfilnam = (basilys_ptr_t *) & filnamv;
  rds.rpgenv = (basilys_ptr_t *) & genv;
  seqv = basilysgc_new_list (BASILYSGOB (DISCR_LIST));
  while (!rdeof ())
    {
      bool got = FALSE;
      skipspace_getc (rd);
      if (rdeof ())
	break;
      valv = readval (rd, &got);
      if (!got)
	READ_ERROR ("no value read %.20s", &rdcurc ());
      basilysgc_append_list (seqv, valv);
    };
  rd = 0;
end:
  BASILYS_EXITFRAME ();
  if (filpath)
    free (filpath);
  if (filnamdup && filnamdup != tinybuf)
    free (filnamdup);
  return seqv;
#undef vecshv
#undef genv
#undef filnamv
#undef seqv
}


static void
do_initial_command (void)
{
  BASILYS_ENTERFRAME (4, NULL);
#define dictv     curfram__.varptr[0]
#define closv     curfram__.varptr[1]
#define cstrv     curfram__.varptr[2]
  debugeprintf ("do_initial_command command_string %s",
		basilys_command_string);
  if (basilys_magic_discr
      ((BASILYSG (INITIAL_COMMAND_DISPATCHER))) != OBMAG_OBJECT
      || BASILYSGOB (INITIAL_COMMAND_DISPATCHER)->obj_len <
      FCMDIS__LAST
      || !BASILYSGOB (INITIAL_COMMAND_DISPATCHER)->obj_vartab
      || !basilys_command_string || !basilys_command_string[0])
    goto end;
  dictv = BASILYSGOB (INITIAL_COMMAND_DISPATCHER)->obj_vartab[FCMDIS_FUNDICT];
  debugeprintf ("do_initial_command dictv=%p", dictv);
  if (basilys_magic_discr (dictv) != OBMAG_MAPSTRINGS)
    goto end;
  closv = basilys_get_mapstrings (dictv, basilys_command_string);
  debugeprintf ("do_initial_command closv=%p", closv);
  if (basilys_magic_discr (closv) != OBMAG_CLOSURE)
    goto end;
  debugeprintf ("do_initial_command argument_string %s",
		basilys_argument_string);
  {
    union basilysparam_un pararg[1];
    memset (pararg, 0, sizeof (pararg));
    cstrv =
      basilysgc_new_string (BASILYSGOB (DISCR_STRING),
			    basilys_argument_string);
    pararg[0].bp_aptr = (basilys_ptr_t *) & cstrv;
    debugeprintf ("do_initial_command before apply closv %p", closv);
    (void) basilysgc_apply (closv,
			    BASILYSG
			    (INITIAL_COMMAND_DISPATCHER),
			    BPARSTR_PTR, pararg, "", NULL);
    debugeprintf ("do_initial_command after apply closv %p", closv);
  }
end:;
  debugeprintf ("do_initial_command end %s", basilys_argument_string);
  BASILYS_EXITFRAME ();
#undef dictv
#undef closv
#undef cstrv
}



/****
 * Initialize basilys. Called from toplevel.c before pass management.
 ****/
void
basilys_initialize (void)
{
  static int inited;
  long seed;
  const char *pc;
  const char *randomseed = 0;
  if (inited)
    return;
  seed = 0;
  randomseed = get_random_seed (false);
  gcc_assert (randomseed != (char *) 0);
  gcc_assert (BASILYS_ALIGN == sizeof (void *)
	      || BASILYS_ALIGN == 2 * sizeof (void *)
	      || BASILYS_ALIGN == 4 * sizeof (void *));
  inited = 1;
  ggc_collect ();
  obstack_init (&bstring_obstack);
  obstack_init (&bname_obstack);
  for (pc = randomseed; *pc; pc++)
    seed ^= (seed << 6) + (*pc);
  srand48_r ((long) seed, &randata);
  gcc_assert (!basilys_curalz);
  {
    size_t wantedwords = MINOR_SIZE_KILOWORD * 4096;
    if (wantedwords < (1 << 20))
      wantedwords = (1 << 20);
    gcc_assert (basilys_startalz == NULL && basilys_endalz == NULL);
    gcc_assert (wantedwords * sizeof (void *) >
		300 * BGLOB__LASTGLOB * sizeof (struct basilysobject_st));
    basilys_curalz = basilys_startalz =
      xcalloc (sizeof (void *), wantedwords);
    basilys_endalz = (char *) basilys_curalz + wantedwords * sizeof (void *);
    basilys_storalz = ((void **) basilys_endalz) - 2;
    basilys_newspeclist = NULL;
    basilys_oldspeclist = NULL;
  }
  debugeprintf ("basilys_initialize cpp_PREFIX=%s", cpp_PREFIX);
  debugeprintf ("basilys_initialize cpp_EXEC_PREFIX=%s", cpp_EXEC_PREFIX);
  debugeprintf ("basilys_initialize gcc_exec_prefix=%s", gcc_exec_prefix);
  debugeprintf ("basilys_initialize melt_private_include_dir=%s",
		melt_private_include_dir);
  debugeprintf ("basilys_initialize melt_source_dir=%s", melt_source_dir);
  debugeprintf ("basilys_initialize melt_generated_dir=%s",
		melt_generated_dir);
  debugeprintf ("basilys_initialize melt_dynlib_dir=%s", melt_dynlib_dir);
  if (!basilys_init_string)
    fatal_error ("no initial basilys file specified thru -fbasilys-init");
  debugeprintf
    ("basilys_initialize before compile_dyn init_string=%s",
     basilys_init_string);
  basilysgc_compile_dyn ((basilys_ptr_t) 0, basilys_init_string);
  debugeprintf
    ("basilys_initialize before initial_command command_string=%s",
     basilys_command_string);
  if (basilys_magic_discr
      ((BASILYSG (INITIAL_COMMAND_DISPATCHER))) == OBMAG_OBJECT
      && BASILYSGOB (INITIAL_COMMAND_DISPATCHER)->obj_len >=
      FCMDIS__LAST && basilys_command_string)
    {
      gcc_assert (dump_file == (FILE *) 0);
      if (flag_basilys_debug)
	{
	  fflush (stderr);
	  dump_file = stderr;
	  fflush (stderr);
	}
      do_initial_command ();
      exit_after_options = 1;
      debugeprintf
	("basilys_initialize after do_initial_command (will exit after options) command_string %s",
	 basilys_command_string);
      if (dump_file)
	{
	  debugeprintf ("basilys_initialize dump_file cleared was %p",
			(void *) dump_file);
	  fflush (dump_file);
	  dump_file = 0;
	}
    }
  debugeprintf ("basilys_initialize ended with %ld GarbColl, %ld fullGc",
		basilys_nb_garbcoll, basilys_nb_full_garbcoll);
}



/****
 * finalize basilys. Called from toplevel.c after all is done
 ****/
void
basilys_finalize (void)
{
  debugeprintf ("basilys_finalize with %ld GarbColl, %ld fullGc",
		basilys_nb_garbcoll, basilys_nb_full_garbcoll);
#warning we should clear our temporary directory here
}




static void
discr_out (struct debugprint_basilys_st *dp, basilysobject_ptr_t odiscr)
{
  int dmag = basilys_magic_discr ((void *) odiscr);
  struct basilysstring_st *str = NULL;
  if (dmag != OBMAG_OBJECT)
    {
      fprintf (dp->dfil, "?discr@%p?", (void *) odiscr);
      return;
    }
  if (odiscr->obj_len >= FNAMED__LAST && odiscr->obj_vartab)
    {
      str = (void *) odiscr->obj_vartab[FNAMED_NAME];
      if (basilys_magic_discr ((void *) str) != OBMAG_STRING)
	str = NULL;
    }
  if (!str)
    {
      fprintf (dp->dfil, "?odiscr/%d?", odiscr->obj_hash);
      return;
    }
  fprintf (dp->dfil, "#%s", str->val);
}


static void
nl_debug_out (struct debugprint_basilys_st *dp, int depth)
{
  int i;
  putc ('\n', dp->dfil);
  for (i = 0; i < depth; i++)
    putc (' ', dp->dfil);
}

static void
skip_debug_out (struct debugprint_basilys_st *dp, int depth)
{
  if (dp->dcount % 4 == 0)
    nl_debug_out (dp, depth);
  else
    putc (' ', dp->dfil);
}


static bool
is_named_obj (basilysobject_ptr_t ob)
{
  struct basilysstring_st *str = 0;
  if (basilys_magic_discr ((void *) ob) != OBMAG_OBJECT)
    return FALSE;
  if (ob->obj_len < FNAMED__LAST || !ob->obj_vartab)
    return FALSE;
  str = (void *) ob->obj_vartab[FNAMED_NAME];
  if (basilys_magic_discr ((void *) str) != OBMAG_STRING)
    return FALSE;
  if (basilys_is_instance_of ((basilys_ptr_t) ob, BASILYSG (CLASS_NAMED)))
    return TRUE;
  return FALSE;
}

static void
debug_outstr (struct debugprint_basilys_st *dp, const char *str)
{
  int nbclin = 0;
  const char *pc;
  for (pc = str; *pc; pc++)
    {
      nbclin++;
      if (nbclin > 60 && strlen (pc) > 5)
	{
	  if (ISSPACE (*pc) || ISPUNCT (*pc) || nbclin > 72)
	    {
	      fputs ("\\\n", dp->dfil);
	      nbclin = 0;
	    }
	}
      switch (*pc)
	{
	case '\n':
	  fputs ("\\n", dp->dfil);
	  break;
	case '\r':
	  fputs ("\\r", dp->dfil);
	  break;
	case '\t':
	  fputs ("\\t", dp->dfil);
	  break;
	case '\v':
	  fputs ("\\v", dp->dfil);
	  break;
	case '\f':
	  fputs ("\\f", dp->dfil);
	  break;
	case '\"':
	  fputs ("\\q", dp->dfil);
	  break;
	case '\'':
	  fputs ("\\a", dp->dfil);
	  break;
	default:
	  if (ISPRINT (*pc))
	    putc (*pc, dp->dfil);
	  else
	    fprintf (dp->dfil, "\\x%02x", (*pc) & 0xff);
	  break;
	}
    }
}


void
basilys_debug_out (struct debugprint_basilys_st *dp,
		   basilys_ptr_t ptr, int depth)
{
  int mag = basilys_magic_discr (ptr);
  int ix;
  if (!dp->dfil)
    return;
  dp->dcount++;
  switch (mag)
    {
    case 0:
      {
	if (ptr)
	  fprintf (dp->dfil, "??@%p??", (void *) ptr);
	else
	  fputs ("@@", dp->dfil);
	break;
      }
    case OBMAG_OBJECT:
      {
	struct basilysobject_st *p = (void *) ptr;
	bool named = is_named_obj (p);
	fputs ("%", dp->dfil);
	discr_out (dp, p->obj_class);
	fprintf (dp->dfil, "/L%dH%d", p->obj_len, p->obj_hash);
	if (p->obj_num)
	  fprintf (dp->dfil, "N%d", p->obj_num);
	if (named)
	  fprintf (dp->dfil, "<#%s>",
		   ((struct basilysstring_st *) (p->
						 obj_vartab
						 [FNAMED_NAME]))->val);
	if ((!named || depth == 0) && depth < dp->dmaxdepth)
	  {
	    fputs ("[", dp->dfil);
	    if (p->obj_vartab)
	      for (ix = 0; ix < p->obj_len; ix++)
		{
		  if (ix > 0)
		    skip_debug_out (dp, depth);
		  basilys_debug_out (dp, p->obj_vartab[ix], depth + 1);
		}
	    fputs ("]", dp->dfil);
	  }
	else if (!named)
	  fputs ("..", dp->dfil);
	break;
      }
    case OBMAG_MULTIPLE:
      {
	struct basilysmultiple_st *p = (void *) ptr;
	fputs ("*", dp->dfil);
	discr_out (dp, p->discr);
	if (depth < dp->dmaxdepth)
	  {
	    fputs ("(", dp->dfil);
	    for (ix = 0; ix < (int) p->nbval; ix++)
	      {
		if (ix > 0)
		  skip_debug_out (dp, depth);
		basilys_debug_out (dp, p->tabval[ix], depth + 1);
	      }
	    fputs (")", dp->dfil);
	  }
	else
	  fputs ("..", dp->dfil);
	break;
      }
    case OBMAG_STRING:
      {
	struct basilysstring_st *p = (void *) ptr;
	fputs ("!", dp->dfil);
	discr_out (dp, p->discr);
	if (depth < dp->dmaxdepth)
	  {
	    fputs ("\"", dp->dfil);
	    debug_outstr (dp, p->val);
	    fputs ("\"", dp->dfil);
	  }
	else
	  fputs ("..", dp->dfil);
	break;
      }
    case OBMAG_INT:
      {
	struct basilysint_st *p = (void *) ptr;
	fputs ("!", dp->dfil);
	discr_out (dp, p->discr);
	fprintf (dp->dfil, "#%ld", p->val);
	break;
      }
    case OBMAG_MIXINT:
      {
	struct basilysmixint_st *p = (void *) ptr;
	fputs ("!", dp->dfil);
	discr_out (dp, p->discr);
	fprintf (dp->dfil, "[#%ld&", p->intval);
	basilys_debug_out (dp, p->ptrval, depth + 1);
	fputs ("]", dp->dfil);
	break;
      }
    case OBMAG_LIST:
      {
	struct basilyslist_st *p = (void *) ptr;
	fputs ("!", dp->dfil);
	discr_out (dp, p->discr);
	if (depth < dp->dmaxdepth)
	  {
	    int ln = basilys_list_length ((void *) p);
	    struct basilyspair_st *pr;
	    if (ln > 2)
	      fprintf (dp->dfil, "[/%d ", ln);
	    else
	      fputs ("[", dp->dfil);
	    for (pr = p->first;
		 pr && basilys_magic_discr ((void *) pr) == OBMAG_PAIR;
		 pr = pr->tl)
	      {
		basilys_debug_out (dp, pr->hd, depth + 1);
		if (pr->tl)
		  skip_debug_out (dp, depth);
	      }
	    fputs ("]", dp->dfil);
	  }
	else
	  fputs ("..", dp->dfil);
	break;
      }
    case OBMAG_MAPSTRINGS:
      {
	struct basilysmapstrings_st *p = (void *) ptr;
	fputs ("|", dp->dfil);
	discr_out (dp, p->discr);
	if (depth < dp->dmaxdepth)
	  {
	    int ln = basilys_primtab[p->lenix];
	    fprintf (dp->dfil, "{~%d/", p->count);
	    if (p->entab)
	      for (ix = 0; ix < ln; ix++)
		{
		  const char *ats = p->entab[ix].e_at;
		  if (!ats || ats == HTAB_DELETED_ENTRY)
		    continue;
		  nl_debug_out (dp, depth);
		  fputs ("'", dp->dfil);
		  debug_outstr (dp, ats);
		  fputs ("' = ", dp->dfil);
		  basilys_debug_out (dp, p->entab[ix].e_va, depth + 1);
		  fputs (";", dp->dfil);
		}
	    fputs (" ~}", dp->dfil);
	  }
	else
	  fputs ("..", dp->dfil);
	break;
      }
    case OBMAG_MAPOBJECTS:
      {
	struct basilysmapobjects_st *p = (void *) ptr;
	fputs ("|", dp->dfil);
	discr_out (dp, p->discr);
	if (depth < dp->dmaxdepth)
	  {
	    int ln = basilys_primtab[p->lenix];
	    fprintf (dp->dfil, "{%d/", p->count);
	    if (p->entab)
	      for (ix = 0; ix < ln; ix++)
		{
		  basilysobject_ptr_t atp = p->entab[ix].e_at;
		  if (!atp || atp == HTAB_DELETED_ENTRY)
		    continue;
		  nl_debug_out (dp, depth);
		  basilys_debug_out (dp, (void *) atp, dp->dmaxdepth);
		  fputs ("' = ", dp->dfil);
		  basilys_debug_out (dp, p->entab[ix].e_va, depth + 1);
		  fputs (";", dp->dfil);
		}
	    fputs (" }", dp->dfil);
	  }
	else
	  fputs ("..", dp->dfil);
	break;
      }
    case OBMAG_CLOSURE:
      {
	struct basilysclosure_st *p = (void *) ptr;
	fputs ("!.", dp->dfil);
	discr_out (dp, p->discr);
	if (depth < dp->dmaxdepth)
	  {
	    fprintf (dp->dfil, "[. rout=");
	    basilys_debug_out (dp, (void *) p->rout, depth + 1);
	    skip_debug_out (dp, depth);
	    fprintf (dp->dfil, " /%d: ", p->nbval);
	    for (ix = 0; ix < (int) p->nbval; ix++)
	      {
		if (ix > 0)
		  skip_debug_out (dp, depth);
		basilys_debug_out (dp, p->tabval[ix], depth + 1);
	      }
	    fputs (".]", dp->dfil);
	  }
	else
	  fputs ("..", dp->dfil);
	break;
      }
    case OBMAG_ROUTINE:
      {
	struct basilysroutine_st *p = (void *) ptr;
	fputs ("!:", dp->dfil);
	discr_out (dp, p->discr);
	if (depth < dp->dmaxdepth)
	  {
	    fprintf (dp->dfil, ".%s[:/%d ", p->routdescr, p->nbval);
	    for (ix = 0; ix < (int) p->nbval; ix++)
	      {
		if (ix > 0)
		  skip_debug_out (dp, depth);
		basilys_debug_out (dp, p->tabval[ix], depth + 1);
	      }
	    fputs (":]", dp->dfil);
	  }
	else
	  fputs ("..", dp->dfil);
	break;
      }
    case OBMAG_STRBUF:
      {
	struct basilysstrbuf_st *p = (void *) ptr;
	fputs ("!`", dp->dfil);
	discr_out (dp, p->discr);
	if (depth < dp->dmaxdepth)
	  {
	    fprintf (dp->dfil, "[`buflen=%ld ", basilys_primtab[p->buflenix]);
	    gcc_assert (p->bufstart <= p->bufend
			&& p->bufend < basilys_primtab[p->buflenix]);
	    fprintf (dp->dfil, "bufstart=%u bufend=%u buf='",
		     p->bufstart, p->bufend);
	    if (p->bufzn)
	      debug_outstr (dp, p->bufzn + p->bufstart);
	    fputs ("' `]", dp->dfil);
	  }
	else
	  fputs ("..", dp->dfil);
	break;
      }
    case OBMAG_PAIR:
      {
	struct basilyspair_st *p = (void *) ptr;
	fputs ("[pair:", dp->dfil);
	discr_out (dp, p->discr);
	if (depth < dp->dmaxdepth)
	  {
	    fputs ("hd:", dp->dfil);
	    basilys_debug_out (dp, p->hd, depth + 1);
	    fputs ("; ti:", dp->dfil);
	    basilys_debug_out (dp, (basilys_ptr_t) p->tl, depth + 1);
	  }
	else
	  fputs ("..", dp->dfil);
	fputs ("]", dp->dfil);
	break;
      }
    case OBMAG_TRIPLE:
    case OBMAG_TREE:
    case OBMAG_BASICBLOCK:
    case OBMAG_EDGE:
    case OBMAG_MAPTREES:
    case OBMAG_MAPBASICBLOCKS:
    case OBMAG_MAPEDGES:
    case OBMAG_DECAY:
      fatal_error ("debug_out unimplemented magic %d", mag);
    default:
      gcc_unreachable ();
    }
}



/* just dump the cgraph node to understand what is it about */
static void
dump_cgraph_basilys (int passcount)
{
  struct cgraph_node *cgr_fun = 0;
  tree tr_body = 0;
  dbgprintf ("start dump_cgraph_basilys passcount=%d", passcount);
  for (cgr_fun = cgraph_nodes; cgr_fun; cgr_fun = cgr_fun->next)
    {
      dbgprintf ("current cgraph cgr_fun %p ", (void *) cgr_fun);
      if (dump_file)
	dump_cgraph_node (dump_file, cgr_fun);
      tr_body = DECL_SAVED_TREE (cgr_fun->decl);
      dbgprintf ("current cgraph tr_body %p ", (void *) tr_body);
      if (dump_file)
	print_generic_stmt (dump_file, tr_body,
			    TDF_LINENO | TDF_BLOCKS | TDF_DETAILS | TDF_IPA);
    }
}

void
basilys_dbgeprint (void *p)
{
  struct debugprint_basilys_st dps = {
    0, 4, 0
  };
  dps.dfil = stderr;
  basilys_debug_out (&dps, p, 0);
  putc ('\n', stderr);
  fflush (stderr);
}

void
basilys_dbgbacktrace (int depth)
{
  int curdepth = 1, totdepth = 0;
  struct callframe_basilys_st *fr = 0;
  fprintf (stderr, "    <{\n");
  for (fr = basilys_topframe; fr != NULL && curdepth < depth;
       (fr = fr->prev), (curdepth++))
    {
      fprintf (stderr, "frame#%d closure: ", curdepth);
      basilys_dbgeprint (fr->clos);
    }
  for (totdepth = curdepth; fr != NULL; fr = fr->prev);
  fprintf (stderr, "}> backtraced %d frames of %d\n", curdepth, totdepth);
  fflush (stderr);
}


void
basilys_dbgshortbacktrace (const char *msg, int maxdepth)
{
  int curdepth = 1;
  struct callframe_basilys_st *fr = 0;
  if (maxdepth < 2)
    maxdepth = 2;
  fprintf (stderr, "\nSHORT BACKTRACE %s;", msg ? msg : "/");
  for (fr = basilys_topframe; fr != NULL && curdepth < maxdepth;
       (fr = fr->prev), (curdepth++))
    {
      if ((curdepth - 1) % 3 == 0)
	putc ('\n', stderr);
      fprintf (stderr, "#%d:", curdepth);
      if (basilys_magic_discr ((void *) fr->clos) == OBMAG_CLOSURE)
	{
	  basilysroutine_ptr_t curout = fr->clos->rout;
	  if (basilys_magic_discr ((void *) curout) == OBMAG_ROUTINE)
	    fprintf (stderr, "<%s> ", curout->routdescr);
	  else
	    fputs ("?norout? ", stderr);
	}
      else
	fprintf (stderr, "_ ");
    };
  if (fr)
    fprintf (stderr, "...&%d", maxdepth - curdepth);
  else
    fputs (".", stderr);
  putc ('\n', stderr);
  putc ('\n', stderr);
  fflush (stderr);
}

/***********************************************************
 * generate C code for a basilys unit name 
 ***********************************************************/
void
basilys_output_cfile_decl_impl (basilys_ptr_t unitnam,
				basilys_ptr_t declbuf, basilys_ptr_t implbuf)
{
  int unamlen = 0;
  char *dotcnam = NULL;
  char *dotcpercentnam = NULL;
  FILE *cfil = NULL;
  gcc_assert (basilys_magic_discr (unitnam) == OBMAG_STRING);
  gcc_assert (basilys_magic_discr (declbuf) == OBMAG_STRBUF);
  gcc_assert (basilys_magic_discr (implbuf) == OBMAG_STRBUF);
  /** FIXME : should implement some policy about the location of the
      generated C file; currently using the pwd */
  unamlen = strlen (basilys_string_str (unitnam));
  dotcnam = xcalloc (unamlen + 3, 1);
  dotcpercentnam = xcalloc (unamlen + 4, 1);
  strcpy (dotcnam, basilys_string_str (unitnam));
  strcpy (dotcpercentnam, basilys_string_str (unitnam));
  strcat (dotcnam, ".c");
  strcat (dotcpercentnam, ".c%");
  (void) rename (dotcnam, dotcpercentnam);
  cfil = fopen (dotcnam, "w");
  if (!cfil)
    fatal_error ("failed to open basilys generated file %s - %m", dotcnam);
  fprintf (cfil,
	   "/* GCC BASILYS GENERATED FILE %s - DO NOT EDIT */\n", dotcnam);
  fprintf (cfil, "#include \"run-basilys.h\"\n");
  fprintf (cfil, "\n/**** %s declarations ****/\n",
	   basilys_string_str (unitnam));
  basilys_putstrbuf (cfil, declbuf);
  putc ('\n', cfil);
  fflush (cfil);
  fprintf (cfil, "\n/**** %s implementations ****/\n",
	   basilys_string_str (unitnam));
  basilys_putstrbuf (cfil, implbuf);
  putc ('\n', cfil);
  fflush (cfil);
  fprintf (cfil, "\n/**** end of %s ****/\n", basilys_string_str (unitnam));
  fclose (cfil);
  free (dotcnam);
  free (dotcpercentnam);
}

/* this function decides if Basile's analysis is done. Currently we
   check for -fbasilys flag; but we should also check for
   -fwhole-program flag */
static bool
gate_basilys (void)
{
#if HAVE_PARMAPOLY && HAVE_LIBTOOLDYNL
  /*@@@ we need to check the whole program flag @@@ */
  if (!flag_basilys)
    return 0;
  if (!flag_whole_program && flag_basilys)
    {
      static int warnedonce;
      if (!warnedonce)
	{
	  warnedonce = 1;
	  warning (OPT_Wall, "-fbasilys flag passed without -fwhole-program");
	};
    }
  return flag_basilys;
#else /* no HAVE_PARMAPOLY or no HAVE_LIBTOOLDYNL */
#warning  no HAVE_PARMAPOLY or no HAVE_LIBTOOLDYNL
  if (flag_basilys)
    fatal_error ("-fbasilys flag specified, \
but GCC configured without Parma Polyhedra Library or LibTool Dynamic Loader");
  return 0;
#endif
}

void
basilys_assert_failed (const char *msg, const char *filnam,
		       int lineno, const char *fun)
{
  static char msgbuf[500];
  if (basilys_dbgcounter > 0)
    snprintf (msgbuf, sizeof (msgbuf) - 1,
	      "%s:%d: BASILYS ASSERT #!%ld: %s {%s}", basename (filnam),
	      lineno, basilys_dbgcounter, fun, msg);
  else
    snprintf (msgbuf, sizeof (msgbuf) - 1, "%s:%d: BASILYS ASSERT: %s {%s}",
	      basename (filnam), lineno, fun, msg);
  basilys_dbgshortbacktrace (msgbuf, 100);
  fatal_error ("%s:%d: BASILYS ASSERT FAILED <%s> : %s\n",
	       basename (filnam), lineno, fun, msg);
}


/* this function does the bulk of the work; return additional TODOs to
   the pass machinery */
static unsigned int
execute_basilys (void)
{
  static int passcount;
  passcount++;
  fprintf (stderr, "\nbasilys.c:%d: start pass %d\n", __LINE__, passcount);
  dbgprintf ("start of execute_basilys pass %d", passcount);
  dump_cgraph_basilys (passcount);
  dbgprintf ("end of execute_basilys pass %d\n", passcount);
  fprintf (stderr, "basilys.c:%d: end pass %d\n\n", __LINE__, passcount);
  return 0;
}

struct tree_opt_pass pass_basilys = {
  "basilys",			/* name */
  gate_basilys,			/* gate */
  execute_basilys,		/* execute */
  NULL,				/* sub */
  NULL,				/* next */
  0,				/* static_pass_number */
  TV_BASILE_ANALYSIS,		/* tv_id */
  PROP_cfg | PROP_ssa,		/* properties_required */
  0,				/* properties_provided */
  0,				/* properties_destroyed */
  0,				/* todo_flags_start */
  0,				/* todo_flags_finish */
  0				/* letter */
};

#include "gt-basilys.h"
/* eof basilys.c */
