/* Generate the machine mode enumeration and associated tables.
   Copyright (C) 2003, 2004, 2005, 2006, 2007
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "bconfig.h"
#include "system.h"
#include "errors.h"
#include "hashtab.h"

#define DEBUG if (0) printf

/* FIXME: The intention is that across targets, modes are considered
   equivalent if they have the same bitsize, mode_class and (where applicable)
   precision.  Thus, QImode and a target with 32 bit units should be
   equivalent to SImode on a target with 8 bit units.
   However, at the moment we don't support mixing targets with different
   BITS_PER_UNIT.  */
/* FIXME: We need to change the handling of RESET_FLOAT_FORMAT so that
   it doesn't change the original mode for other targets.  */

/* enum mode_class is normally defined by machmode.h but we can't
   include that header here.  */
#include "mode-classes.def"

#define DEF_MODE_CLASS(M) M
enum mode_class { MODE_CLASSES, MAX_MODE_CLASS };
#undef DEF_MODE_CLASS

/* Text names of mode classes, for output.  */
#define DEF_MODE_CLASS(M) #M
static const char *const mode_class_names[MAX_MODE_CLASS] =
{
  MODE_CLASSES
};
#undef DEF_MODE_CLASS
#undef MODE_CLASSES

#ifdef EXTRA_MODES_FILE
# define HAVE_EXTRA_MODES 1
#else
# define HAVE_EXTRA_MODES 0
# define EXTRA_MODES_FILE ""
#endif

/* Data structure for building up what we know about a mode.
   They're clustered by mode class.  */
struct mode_data
{
  struct mode_data *next;	/* next this class - arbitrary order */

  const char *name;		/* printable mode name -- SI, not SImode */
  const char *target;		/* the target this mode is specific to.  */
  enum mode_class cl;		/* this mode class */
  unsigned int precision;	/* size in bits, equiv to TYPE_PRECISION */
  unsigned int bytesize;	/* storage size in addressable units */
  unsigned int ncomponents;	/* number of subunits */
  unsigned int alignment;	/* mode alignment */
  const char *format;		/* floating point format - float modes only */

  struct mode_data *component;	/* mode of components */
  struct mode_data *wider;	/* next wider mode */
  struct mode_data *wider_2x;	/* 2x wider mode */

  struct mode_data *contained;  /* Pointer to list of modes that have
				   this mode as a component.  */
  struct mode_data *next_cont;  /* Next mode in that list.  */

  const char *file;		/* file and line of definition, */
  unsigned int line;		/* for error reporting */
  unsigned int counter;		/* Rank ordering of modes */
  unsigned int ibit;		/* the number of integral bits */
  unsigned int fbit;		/* the number of fractional bits */
};

static struct mode_data *modes[MAX_MODE_CLASS];
static unsigned int n_modes[MAX_MODE_CLASS];
static struct mode_data *void_mode;

static const struct mode_data blank_mode = {
  0, "<unknown>", (const char *) 0, MAX_MODE_CLASS,
  -1U, -1U, -1U, -1U,
  0, 0, 0, 0, 0, 0,
  "<unknown>", 0, 0, 0, 0
};

static htab_t modes_by_name;

/* Data structure for recording target-specified runtime adjustments
   to a particular mode.  We support varying the byte size, the
   alignment, and the floating point format.  */
struct mode_adjust
{
  struct mode_adjust *next;
  struct mode_data *mode;
  const char *adjustment;
  const char *target;

  const char *file;
  unsigned int line;
};

static struct mode_adjust *adj_bytesize;
static struct mode_adjust *adj_alignment;
static struct mode_adjust *adj_format;
static struct mode_adjust *adj_ibit;
static struct mode_adjust *adj_fbit;

/* Mode class operations.  */
static enum mode_class
complex_class (enum mode_class c)
{
  switch (c)
    {
    case MODE_INT: return MODE_COMPLEX_INT;
    case MODE_FLOAT: return MODE_COMPLEX_FLOAT;
    default:
      error ("no complex class for class %s", mode_class_names[c]);
      return MODE_RANDOM;
    }
}

static enum mode_class
vector_class (enum mode_class cl)
{
  switch (cl)
    {
    case MODE_INT: return MODE_VECTOR_INT;
    case MODE_FLOAT: return MODE_VECTOR_FLOAT;
    case MODE_FRACT: return MODE_VECTOR_FRACT;
    case MODE_UFRACT: return MODE_VECTOR_UFRACT;
    case MODE_ACCUM: return MODE_VECTOR_ACCUM;
    case MODE_UACCUM: return MODE_VECTOR_UACCUM;
    default:
      error ("no vector class for class %s", mode_class_names[cl]);
      return MODE_RANDOM;
    }
}

static const char *target = (const char *) 0;

/* Utility routines.  */
static inline struct mode_data *
find_mode (const char *name)
{
  struct mode_data key;

  key.name = name;
  key.target = target;
  return (struct mode_data *) htab_find (modes_by_name, &key);
}

static struct mode_data *
new_mode (enum mode_class cl, const char *name,
	  const char *file, unsigned int line)
{
  struct mode_data *m;
  static unsigned int count = 0;

  m = find_mode (name);
  if (m)
    {
      error ("%s:%d: duplicate definition of mode \"%s\"",
	     trim_filename (file), line, name);
      error ("%s:%d: previous definition here", m->file, m->line);
      return m;
    }

  m = XNEW (struct mode_data);
  memcpy (m, &blank_mode, sizeof (struct mode_data));
  m->cl = cl;
  m->name = name;
  m->target = target;
  if (file)
    m->file = trim_filename (file);
  m->line = line;
  m->counter = count++;

  m->next = modes[cl];
  modes[cl] = m;
  n_modes[cl]++;

  *htab_find_slot (modes_by_name, m, INSERT) = m;

  return m;
}

static hashval_t
hash_mode (const void *p)
{
  const struct mode_data *m = (const struct mode_data *)p;
  return htab_hash_string (m->name);
}

static int
eq_mode (const void *p, const void *q)
{
  const struct mode_data *a = (const struct mode_data *)p;
  const struct mode_data *b = (const struct mode_data *)q;

  return (!strcmp (a->name, b->name)
	  && ((a->target ? a->target : target)
	      == (b->target ? b->target : target)));
}

#define for_all_modes(C, M)			\
  for (C = 0; C < MAX_MODE_CLASS; C++)		\
    for (M = modes[C]; M; M = M->next)

static void ATTRIBUTE_UNUSED
new_adjust (const char *name,
	    struct mode_adjust **category, const char *catname,
	    const char *adjustment,
	    enum mode_class required_class_from,
	    enum mode_class required_class_to,
	    const char *file, unsigned int line)
{
  struct mode_data *mode = find_mode (name);
  struct mode_adjust *a;

  file = trim_filename (file);

  if (!mode)
    {
      error ("%s:%d: no mode \"%s\"", file, line, name);
      return;
    }

  if (required_class_from != MODE_RANDOM
      && (mode->cl < required_class_from || mode->cl > required_class_to))
    {
      error ("%s:%d: mode \"%s\" is not among class {%s, %s}",
	     file, line, name, mode_class_names[required_class_from] + 5,
	     mode_class_names[required_class_to] + 5);
      return;
    }

  for (a = *category; a; a = a->next)
    if (a->mode == mode)
      {
	error ("%s:%d: mode \"%s\" already has a %s adjustment",
	       file, line, name, catname);
	error ("%s:%d: previous adjustment here", a->file, a->line);
	return;
      }

  a = XNEW (struct mode_adjust);
  a->mode = mode;
  a->target = target;
  a->adjustment = adjustment;
  a->file = file;
  a->line = line;

  a->next = *category;
  *category = a;
}

/* Diagnose failure to meet expectations in a partially filled out
   mode structure.  */
enum requirement { SET, UNSET, OPTIONAL };

#define validate_field_(mname, fname, req, val, unset, file, line) do {	\
  switch (req)								\
    {									\
    case SET:								\
      if (val == unset)							\
	error ("%s:%d: (%s) field %s must be set",			\
	       file, line, mname, fname);				\
      break;								\
    case UNSET:								\
      if (val != unset)							\
	error ("%s:%d: (%s) field %s must not be set",			\
	       file, line, mname, fname);				\
    case OPTIONAL:							\
      break;								\
    }									\
} while (0)

#define validate_field(M, F) \
  validate_field_(M->name, #F, r_##F, M->F, blank_mode.F, M->file, M->line)

static void
validate_mode (struct mode_data *m,
	       enum requirement r_precision,
	       enum requirement r_bytesize,
	       enum requirement r_component,
	       enum requirement r_ncomponents,
	       enum requirement r_format)
{
  validate_field (m, precision);
  validate_field (m, bytesize);
  validate_field (m, component);
  validate_field (m, ncomponents);
  validate_field (m, format);
}
#undef validate_field
#undef validate_field_

/* Given a partially-filled-out mode structure, figure out what we can
   and fill the rest of it in; die if it isn't enough.  */
static void
complete_mode (struct mode_data *m)
{
  unsigned int alignment;

  if (!m->name)
    {
      error ("%s:%d: mode with no name", m->file, m->line);
      return;
    }
  if (m->cl == MAX_MODE_CLASS)
    {
      error ("%s:%d: %smode has no mode class", m->file, m->line, m->name);
      return;
    }

  switch (m->cl)
    {
    case MODE_RANDOM:
      /* Nothing more need be said.  */
      if (!strcmp (m->name, "VOID"))
	void_mode = m;

      validate_mode (m, UNSET, UNSET, UNSET, UNSET, UNSET);

      m->precision = 0;
      m->bytesize = 0;
      m->ncomponents = 0;
      m->component = 0;
      break;

    case MODE_CC:
      /* Again, nothing more need be said.  For historical reasons,
	 the size of a CC mode is four units.  */
      validate_mode (m, UNSET, UNSET, UNSET, UNSET, UNSET);

      m->bytesize = 4;
      m->ncomponents = 1;
      m->component = 0;
      break;

    case MODE_INT:
    case MODE_FLOAT:
    case MODE_DECIMAL_FLOAT:
    case MODE_FRACT:
    case MODE_UFRACT:
    case MODE_ACCUM:
    case MODE_UACCUM:
      /* A scalar mode must have a byte size, may have a bit size,
	 and must not have components.   A float mode must have a
         format.  */
      validate_mode (m, OPTIONAL, SET, UNSET, UNSET,
		     (m->cl == MODE_FLOAT || m->cl == MODE_DECIMAL_FLOAT)
		     ? SET : UNSET);

      m->ncomponents = 1;
      m->component = 0;
      break;

    case MODE_PARTIAL_INT:
      /* A partial integer mode uses ->component to say what the
	 corresponding full-size integer mode is, and may also
	 specify a bit size.  */
      validate_mode (m, OPTIONAL, UNSET, SET, UNSET, UNSET);

      m->bytesize = m->component->bytesize;

      m->ncomponents = 1;
      m->component = 0;  /* ??? preserve this */
      break;

    case MODE_COMPLEX_INT:
    case MODE_COMPLEX_FLOAT:
      /* Complex modes should have a component indicated, but no more.  */
      validate_mode (m, UNSET, UNSET, SET, UNSET, UNSET);
      m->ncomponents = 2;
      if (m->component->precision != (unsigned int)-1)
	m->precision = 2 * m->component->precision;
      m->bytesize = 2 * m->component->bytesize;
      break;

    case MODE_VECTOR_INT:
    case MODE_VECTOR_FLOAT:
    case MODE_VECTOR_FRACT:
    case MODE_VECTOR_UFRACT:
    case MODE_VECTOR_ACCUM:
    case MODE_VECTOR_UACCUM:
      /* Vector modes should have a component and a number of components.  */
      validate_mode (m, UNSET, UNSET, SET, SET, UNSET);
      if (m->component->precision != (unsigned int)-1)
	m->precision = m->ncomponents * m->component->precision;
      m->bytesize = m->ncomponents * m->component->bytesize;
      break;

    default:
      gcc_unreachable ();
    }

  /* If not already specified, the mode alignment defaults to the largest
     power of two that divides the size of the object.  Complex types are
     not more aligned than their contents.  */
  if (m->cl == MODE_COMPLEX_INT || m->cl == MODE_COMPLEX_FLOAT)
    alignment = m->component->bytesize;
  else
    alignment = m->bytesize;

  m->alignment = alignment & (~alignment + 1);

  /* If this mode has components, make the component mode point back
     to this mode, for the sake of adjustments.  */
  if (m->component)
    {
      m->next_cont = m->component->contained;
      m->component->contained = m;
    }
}

static void
complete_all_modes (void)
{
  struct mode_data *m;
  int cl;

  for_all_modes (cl, m)
    complete_mode (m);
}

/* Remove the duplicate mode OLD.  All referenecs to it should be replaced
   with NEW.  */
static void
drop_mode (struct mode_data *old, struct mode_data *new_m)
{
  struct mode_data *m, *last;

  DEBUG ("dropping %s %s\n", m->name, m->target);
  if (old->contained)
    {
      for (m = old->contained; m; last = m, m = m->next_cont)
	m->component = new_m;
      last->next_cont = new_m->contained;
      new_m->contained = old->contained;
    }
}

static void
fixup_target_modes (void)
{
  struct mode_data *m, *m_prev, *m2, *m2_prev, *m3, *m3_prev;
  int cl;

  /* Find target-specific modes that describe the same data.  When a mode
     is found that matches a mode earlier in the list, move all earlier modes
     from the same target in the same mode class in front of the earlier mode;
     of the equivalent modes, keep only the one that is for the output
     target.  */
  for (cl = 0; cl < MAX_MODE_CLASS; cl++)
    {
      if (cl == MODE_RANDOM || cl == MODE_CC)
	continue;
      for (m_prev = 0, m = modes[cl]; m; m_prev = m, m = m->next)
	{
	  for (m2_prev = 0, m2 = modes[cl]; m2 != m;
	       m2_prev = m2, m2 = m2->next)
	    if (m->precision == m2->precision
		&& m->bytesize == m2->bytesize
		&& m->ncomponents == m2->ncomponents
		&& m->format == m2->format
		&& m->ibit == m2->ibit
		&& m->fbit == m2->fbit)
	      {
		gcc_assert (m->target && m2->target);
		gcc_assert (m->target != m2->target);
		/* Find all modes between m2 and m which are for the same
		   target as m and insert them in front of m2.  */
		for (m3_prev = m2; m3 = m3_prev->next, m3 != m; )
		  {
		    if (m3->target != m->target)
		      {
			m3_prev = m3;
			continue;
		      }
		    m3_prev->next = m3->next;
		    if (m2_prev)
		      m2_prev->next = m3;
		    else
		      modes[cl] = m3;
		    m2_prev = m3;
		    m3->next = m2;
		    if (m3 == m_prev)
		      {
			m_prev = m3_prev;
			break;
		      }
		  }
		/* Remove m from the list.  */
		gcc_assert (m_prev && m_prev->next == m);
		gcc_assert (m->next != m);
		gcc_assert (m_prev != m);
		m_prev->next = m->next;
		/* If m is for the output target, retain it in place of m2.  */
		if (!strcmp (m->target, output_target))
		  {
		    if (m2_prev)
		      m2_prev->next = m;
		    else
		      modes[cl] = m;
		    if (m_prev == m2)
		      m_prev = m;
		    m->next = m2->next;
		    drop_mode (m2, m);
		  }
		else
		  drop_mode (m, m2);
		m = m_prev;
		break;
	      }
	  gcc_assert (m2 == m || m == m_prev);
	}
    }

  /* Reset the target field for modes that are for the output target.
     Henceforth, all modes with the target field set are not modes for
     the output target.  */
  for_all_modes (cl, m)
    if (m->target && !strcmp (m->target, output_target))
      m->target = (const char *)0;
    /* Mangle name of modes for other targets.  */
    else if (m->target)
      {
	size_t t_len = strlen (m->target);
	size_t n_len = strlen (m->name);
	char *new_name
	  = XNEWVEC (char, t_len + 1 + n_len + 1);

	strcpy (new_name, m->target);
	new_name[t_len] = '_';
	strcat (new_name + t_len + 1, m->name);
	m->name = new_name;
      }
}

/* For each mode in class CLASS, construct a corresponding complex mode.  */
#define COMPLEX_MODES(C) make_complex_modes(MODE_##C, __FILE__, __LINE__)
static void
make_complex_modes (enum mode_class cl,
		    const char *file, unsigned int line)
{
  struct mode_data *m;
  struct mode_data *c;
  char buf[8];
  enum mode_class cclass = complex_class (cl);
  const char *save_target;

  if (cclass == MODE_RANDOM)
    return;

  for (m = modes[cl]; m; m = m->next)
    {
      /* Skip BImode.  FIXME: BImode probably shouldn't be MODE_INT.  */
      if (m->precision == 1)
	continue;
      if (m->target && target && m->target != target)
	continue;

      if (strlen (m->name) >= sizeof buf)
	{
	  error ("%s:%d:mode name \"%s\" is too long",
		 m->file, m->line, m->name);
	  continue;
	}

      /* Float complex modes are named SCmode, etc.
	 Int complex modes are named CSImode, etc.
         This inconsistency should be eliminated.  */
      if (cl == MODE_FLOAT)
	{
	  char *p, *q = 0;
	  strncpy (buf, m->name, sizeof buf);
	  p = strchr (buf, 'F');
	  if (p == 0)
	    q = strchr (buf, 'D');
	  if (p == 0 && q == 0)
	    {
	      error ("%s:%d: float mode \"%s\" has no 'F' or 'D'",
		     m->file, m->line, m->name);
	      continue;
	    }

	  if (p != 0)
	    *p = 'C';
	  else
	    snprintf (buf, sizeof buf, "C%s", m->name);
	}
      else
	snprintf (buf, sizeof buf, "C%s", m->name);

      save_target = target;
      target = m->target;
      c = new_mode (cclass, xstrdup (buf), file, line);
      target = save_target;
      c->component = m;
    }
}

/* For all modes in class CL, construct vector modes of width
   WIDTH, having as many components as necessary.  */
#define VECTOR_MODES(C, W) make_vector_modes(MODE_##C, W, __FILE__, __LINE__)
static void ATTRIBUTE_UNUSED
make_vector_modes (enum mode_class cl, unsigned int width,
		   const char *file, unsigned int line)
{
  struct mode_data *m;
  struct mode_data *v;
  char buf[8];
  unsigned int ncomponents;
  enum mode_class vclass = vector_class (cl);

  if (vclass == MODE_RANDOM)
    return;

  for (m = modes[cl]; m; m = m->next)
    {
      /* Do not construct vector modes with only one element, or
	 vector modes where the element size doesn't divide the full
	 size evenly.  */
      ncomponents = width / m->bytesize;
      if (ncomponents < 2)
	continue;
      if (width % m->bytesize)
	continue;
      if (m->target && target && m->target != target)
	continue;

      /* Skip QFmode and BImode.  FIXME: this special case should
	 not be necessary.  */
      if (cl == MODE_FLOAT && m->bytesize == 1)
	continue;
      if (cl == MODE_INT && m->precision == 1)
	continue;

      if ((size_t)snprintf (buf, sizeof buf, "V%u%s", ncomponents, m->name)
	  >= sizeof buf)
	{
	  error ("%s:%d: mode name \"%s\" is too long",
		 m->file, m->line, m->name);
	  continue;
	}

      v = new_mode (vclass, xstrdup (buf), file, line);
      v->component = m;
      v->ncomponents = ncomponents;
    }
}

/* Input.  */

#define _SPECIAL_MODE(C, N) make_special_mode(MODE_##C, #N, __FILE__, __LINE__)
#define RANDOM_MODE(N) _SPECIAL_MODE (RANDOM, N)
#define CC_MODE(N) _SPECIAL_MODE (CC, N)

static void
make_special_mode (enum mode_class cl, const char *name,
		   const char *file, unsigned int line)
{
  new_mode (cl, name, file, line);
}

#define INT_MODE(N, Y) FRACTIONAL_INT_MODE (N, -1U, Y)
#define FRACTIONAL_INT_MODE(N, B, Y) \
  make_int_mode (#N, B, Y, __FILE__, __LINE__)

static void
make_int_mode (const char *name,
	       unsigned int precision, unsigned int bytesize,
	       const char *file, unsigned int line)
{
  struct mode_data *m = new_mode (MODE_INT, name, file, line);
  m->bytesize = bytesize;
  m->precision = precision;
}

#define FRACT_MODE(N, Y, F) \
	make_fixed_point_mode (MODE_FRACT, #N, Y, 0, F, __FILE__, __LINE__)

#define UFRACT_MODE(N, Y, F) \
	make_fixed_point_mode (MODE_UFRACT, #N, Y, 0, F, __FILE__, __LINE__)

#define ACCUM_MODE(N, Y, I, F) \
	make_fixed_point_mode (MODE_ACCUM, #N, Y, I, F, __FILE__, __LINE__)

#define UACCUM_MODE(N, Y, I, F) \
	make_fixed_point_mode (MODE_UACCUM, #N, Y, I, F, __FILE__, __LINE__)

/* Create a fixed-point mode by setting CL, NAME, BYTESIZE, IBIT, FBIT,
   FILE, and LINE.  */

static void
make_fixed_point_mode (enum mode_class cl,
		       const char *name,
		       unsigned int bytesize,
		       unsigned int ibit,
		       unsigned int fbit,
		       const char *file, unsigned int line)
{
  struct mode_data *m = new_mode (cl, name, file, line);
  m->bytesize = bytesize;
  m->ibit = ibit;
  m->fbit = fbit;
}

#define FLOAT_MODE(N, Y, F)             FRACTIONAL_FLOAT_MODE (N, -1U, Y, F)
#define FRACTIONAL_FLOAT_MODE(N, B, Y, F) \
  make_float_mode (#N, B, Y, #F, __FILE__, __LINE__)

static void
make_float_mode (const char *name,
		 unsigned int precision, unsigned int bytesize,
		 const char *format,
		 const char *file, unsigned int line)
{
  struct mode_data *m = new_mode (MODE_FLOAT, name, file, line);
  m->bytesize = bytesize;
  m->precision = precision;
  m->format = format;
}

#define DECIMAL_FLOAT_MODE(N, Y, F)	\
	FRACTIONAL_DECIMAL_FLOAT_MODE (N, -1U, Y, F)
#define FRACTIONAL_DECIMAL_FLOAT_MODE(N, B, Y, F)	\
  make_decimal_float_mode (#N, B, Y, #F, __FILE__, __LINE__)

static void
make_decimal_float_mode (const char *name,
			 unsigned int precision, unsigned int bytesize,
			 const char *format,
			 const char *file, unsigned int line)
{
  struct mode_data *m = new_mode (MODE_DECIMAL_FLOAT, name, file, line);
  m->bytesize = bytesize;
  m->precision = precision;
  m->format = format;
}

#define RESET_FLOAT_FORMAT(N, F) \
  reset_float_format (#N, #F, __FILE__, __LINE__)
static void ATTRIBUTE_UNUSED
reset_float_format (const char *name, const char *format,
		    const char *file, unsigned int line)
{
  struct mode_data *m = find_mode (name);
  if (!m)
    {
      error ("%s:%d: no mode \"%s\"", file, line, name);
      return;
    }
  if (m->cl != MODE_FLOAT && m->cl != MODE_DECIMAL_FLOAT)
    {
      error ("%s:%d: mode \"%s\" is not a FLOAT class", file, line, name);
      return;
    }
  m->format = format;
}

/* Partial integer modes are specified by relation to a full integer mode.
   For now, we do not attempt to narrow down their bit sizes.  */
#define PARTIAL_INT_MODE(M) \
  make_partial_integer_mode (#M, "P" #M, -1U, __FILE__, __LINE__)
static void ATTRIBUTE_UNUSED
make_partial_integer_mode (const char *base, const char *name,
			   unsigned int precision,
			   const char *file, unsigned int line)
{
  struct mode_data *m;
  struct mode_data *component = find_mode (base);
  if (!component)
    {
      error ("%s:%d: no base mode \"%s\" for \"%s\"", file, line, base, name);
      return;
    }
  if (component->cl != MODE_INT)
    {
      error ("%s:%d: mode \"%s\" is not class INT", file, line, name);
      return;
    }

  m = new_mode (MODE_PARTIAL_INT, name, file, line);
  m->precision = precision;
  m->component = component;
}

/* A single vector mode can be specified by naming its component
   mode and the number of components.  */
#define VECTOR_MODE(C, M, N) \
  make_vector_mode (MODE_##C, #M, N, __FILE__, __LINE__);
static void ATTRIBUTE_UNUSED
make_vector_mode (enum mode_class bclass,
		  const char *base,
		  unsigned int ncomponents,
		  const char *file, unsigned int line)
{
  struct mode_data *v;
  enum mode_class vclass = vector_class (bclass);
  struct mode_data *component = find_mode (base);
  char namebuf[8];

  if (vclass == MODE_RANDOM)
    return;
  if (component == 0)
    {
      error ("%s:%d: no mode \"%s\"", file, line, base);
      return;
    }
  if (component->cl != bclass
      && (component->cl != MODE_PARTIAL_INT
	  || bclass != MODE_INT))
    {
      error ("%s:%d: mode \"%s\" is not class %s",
	     file, line, base, mode_class_names[bclass] + 5);
      return;
    }

  if ((size_t)snprintf (namebuf, sizeof namebuf, "V%u%s",
			ncomponents, base) >= sizeof namebuf)
    {
      error ("%s:%d: mode name \"%s\" is too long",
	     file, line, base);
      return;
    }

  v = new_mode (vclass, xstrdup (namebuf), file, line);
  v->ncomponents = ncomponents;
  v->component = component;
}

/* Adjustability.  */
#define _ADD_ADJUST(A, M, X, C1, C2) \
  new_adjust (#M, &adj_##A, #A, #X, MODE_##C1, MODE_##C2, __FILE__, __LINE__)

#define ADJUST_BYTESIZE(M, X)  _ADD_ADJUST(bytesize, M, X, RANDOM, RANDOM)
#define ADJUST_ALIGNMENT(M, X) _ADD_ADJUST(alignment, M, X, RANDOM, RANDOM)
#define ADJUST_FLOAT_FORMAT(M, X)    _ADD_ADJUST(format, M, X, FLOAT, FLOAT)
#define ADJUST_IBIT(M, X)  _ADD_ADJUST(ibit, M, X, ACCUM, UACCUM)
#define ADJUST_FBIT(M, X)  _ADD_ADJUST(fbit, M, X, FRACT, UACCUM)

static void
create_modes (void)
{
#include "machmode.def"
}

/* Processing.  */

/* Sort a list of modes into the order needed for the WIDER field:
   major sort by precision, minor sort by component precision.

   For instance:
     QI < HI < SI < DI < TI
     V4QI < V2HI < V8QI < V4HI < V2SI.

   If the precision is not set, sort by the bytesize.  A mode with
   precision set gets sorted before a mode without precision set, if
   they have the same bytesize; this is the right thing because
   the precision must always be smaller than the bytesize * BITS_PER_UNIT.
   We don't have to do anything special to get this done -- an unset
   precision shows up as (unsigned int)-1, i.e. UINT_MAX.  */
static int
cmp_modes (const void *a, const void *b)
{
  const struct mode_data *const m = *(const struct mode_data *const*)a;
  const struct mode_data *const n = *(const struct mode_data *const*)b;

  if (m->bytesize > n->bytesize)
    return 1;
  else if (m->bytesize < n->bytesize)
    return -1;

  if (m->precision > n->precision)
    return 1;
  else if (m->precision < n->precision)
    return -1;

  if (!m->component && !n->component)
    {
      if (m->counter < n->counter)
	return -1;
      else
	return 1;
    }

  if (m->component->bytesize > n->component->bytesize)
    return 1;
  else if (m->component->bytesize < n->component->bytesize)
    return -1;

  if (m->component->precision > n->component->precision)
    return 1;
  else if (m->component->precision < n->component->precision)
    return -1;

  if (m->counter < n->counter)
    return -1;
  else
    return 1;
}

static void
calc_wider_mode (void)
{
  int c;
  struct mode_data *m, *last;
  struct mode_data **sortbuf;
  unsigned int max_n_modes = 0;
  unsigned int i, j;

  for (c = 0; c < MAX_MODE_CLASS; c++)
    max_n_modes = MAX (max_n_modes, n_modes[c]);

  /* Allocate max_n_modes + 1 entries to leave room for the extra null
     pointer assigned after the qsort call below.  */
  sortbuf = (struct mode_data **) alloca ((max_n_modes + 1) * sizeof (struct mode_data *));

  for (c = 0; c < MAX_MODE_CLASS; c++)
    {
      /* "wider" is not meaningful for MODE_RANDOM and MODE_CC.
	 However, we want these in textual order, and we have
	 precisely the reverse.  */
      if (c == MODE_RANDOM || c == MODE_CC)
	{
	  struct mode_data *prev, *next;

	  for (prev = 0, m = modes[c]; m; m = next)
	    {
	      m->wider = void_mode;
	      m->wider_2x = void_mode;

	      /* this is nreverse */
	      next = m->next;
	      m->next = prev;
	      prev = m;
	    }
	  modes[c] = prev;
	}
      else
	{
	  if (!modes[c])
	    continue;

	  for (i = 0, m = modes[c]; m; i++, m = m->next)
	    sortbuf[i] = m;

	  qsort (sortbuf, i, sizeof (struct mode_data *), cmp_modes);

	  sortbuf[i] = 0;
	  last = 0;
	  for (j = 0; j < i; j++)
	    {
	      sortbuf[j]->wider = void_mode;
	      if (!sortbuf[j]->target)
		{
		  if (last)
		    last->wider = sortbuf[j];
		  last = sortbuf[j];
		}
	      sortbuf[j]->next = sortbuf[j + 1];
	    }

	  modes[c] = sortbuf[0];
	}
    }
}

/* Output routines.  */

#define tagged_printf(FMT, ARG, TAG) do {		\
  int count_ = printf ("  " FMT ",", ARG);		\
  printf ("%*s/* %s */\n", 27 - count_, "", TAG);	\
} while (0)

#define print_decl(TYPE, NAME, ASIZE) \
  puts ("\nconst " TYPE " " NAME "[" ASIZE "] =\n{");

#define print_maybe_const_decl(TYPE, NAME, ASIZE, CATEGORY)	\
  printf ("\n%s" TYPE " " NAME "[" ASIZE "] = \n{\n",		\
	  (adj_##CATEGORY \
	   ? "" \
	   : "extern const " TYPE " " NAME "[" ASIZE "];\nconst "));

#define print_closer() puts ("};")

static void
emit_insn_modes_h (void)
{
  int c;
  struct mode_data *m, *first, *last;

  printf ("/* Generated automatically from machmode.def%s%s\n",
	   HAVE_EXTRA_MODES ? " and " : "",
	   EXTRA_MODES_FILE);

  puts ("\
   by genmodes.  */\n\
\n\
#ifndef GCC_INSN_MODES_H\n\
#define GCC_INSN_MODES_H\n\
\n\
enum machine_mode\n{");

  for (c = 0; c < MAX_MODE_CLASS; c++)
    for (m = modes[c]; m; m = m->next)
      {
	int count_ = printf ("  %smode,", m->name);
	printf ("%*s/* %s:%d */\n", 27 - count_, "",
		 trim_filename (m->file), m->line);
      }

  puts ("  MAX_MACHINE_MODE,\n");

  for (c = 0; c < MAX_MODE_CLASS; c++)
    {
      first = modes[c];
      last = 0;
      for (m = first; m && !m->target; last = m, m = m->next)
	;

      /* Don't use BImode for MIN_MODE_INT, since otherwise the middle
	 end will try to use it for bitfields in structures and the
	 like, which we do not want.  Only the target md file should
	 generate BImode widgets.  */
      while (first && (first->precision == 1 || first->target))
	first = first->next;

      if (first && last)
	printf ("  MIN_%s = %smode,\n  MAX_%s = %smode,\n\n",
		 mode_class_names[c], first->name,
		 mode_class_names[c], last->name);
      else
	printf ("  MIN_%s = %smode,\n  MAX_%s = %smode,\n\n",
		 mode_class_names[c], void_mode->name,
		 mode_class_names[c], void_mode->name);
    }

  puts ("\
  NUM_MACHINE_MODES = MAX_MACHINE_MODE\n\
};\n");

  /* I can't think of a better idea, can you?  */
  printf ("#define CONST_MODE_SIZE%s\n", adj_bytesize ? "" : " const");
  printf ("#define CONST_MODE_BASE_ALIGN%s\n", adj_alignment ? "" : " const");
#if 0 /* disabled for backward compatibility, temporary */
  printf ("#define CONST_REAL_FORMAT_FOR_MODE%s\n", adj_format ? "" :" const");
#endif
  printf ("#define CONST_MODE_IBIT%s\n", adj_ibit ? "" : " const");
  printf ("#define CONST_MODE_FBIT%s\n", adj_fbit ? "" : " const");
  puts ("\
\n\
#endif /* insn-modes.h */");
}

static void
emit_insn_modes_c_header (void)
{
  printf ("/* Generated automatically from machmode.def%s%s\n",
	   HAVE_EXTRA_MODES ? " and " : "",
	   EXTRA_MODES_FILE);

  puts ("\
   by genmodes.  */\n\
\n\
#include \"config.h\"\n\
#include \"system.h\"\n\
#include \"coretypes.h\"\n\
#include \"tm.h\"\n\
#include \"machmode.h\"\n\
#include \"real.h\"\n\
#include \"multi-target.h\"\n\
\n\
START_TARGET_SPECIFIC");
}

static void
emit_min_insn_modes_c_header (void)
{
  printf ("/* Generated automatically from machmode.def%s%s\n",
	   HAVE_EXTRA_MODES ? " and " : "",
	   EXTRA_MODES_FILE);

  puts ("\
   by genmodes.  */\n\
\n\
#include \"bconfig.h\"\n\
#include \"system.h\"\n\
#include \"machmode.h\"\n\
#include \"multi-target.h\"\n\
\n\
START_TARGET_SPECIFIC");
}

static void
emit_mode_name (void)
{
  int c;
  struct mode_data *m;

  print_decl ("char *const", "mode_name", "NUM_MACHINE_MODES");

  for_all_modes (c, m)
    printf ("  \"%s\",\n", m->name);

  print_closer ();
}

static void
emit_mode_class (void)
{
  int c;
  struct mode_data *m;

  print_decl ("unsigned char", "mode_class", "NUM_MACHINE_MODES");

  for_all_modes (c, m)
    tagged_printf ("%s", mode_class_names[m->cl], m->name);

  print_closer ();
}

static void
emit_mode_precision (void)
{
  int c;
  struct mode_data *m;

  print_decl ("unsigned short", "mode_precision", "NUM_MACHINE_MODES");

  for_all_modes (c, m)
    if (m->precision != (unsigned int)-1)
      tagged_printf ("%u", m->precision, m->name);
    else
      tagged_printf ("%u*BITS_PER_UNIT", m->bytesize, m->name);

  print_closer ();
}

static void
emit_mode_size (void)
{
  int c;
  struct mode_data *m;

  print_maybe_const_decl ("unsigned char", "mode_size",
			  "NUM_MACHINE_MODES", bytesize);

  for_all_modes (c, m)
    tagged_printf ("%u", m->bytesize, m->name);

  print_closer ();
}

static void
emit_mode_nunits (void)
{
  int c;
  struct mode_data *m;

  print_decl ("unsigned char", "mode_nunits", "NUM_MACHINE_MODES");

  for_all_modes (c, m)
    tagged_printf ("%u", m->ncomponents, m->name);

  print_closer ();
}

static void
emit_mode_wider (void)
{
  int c;
  struct mode_data *m;

  print_decl ("unsigned char", "mode_wider", "NUM_MACHINE_MODES");

  for_all_modes (c, m)
    tagged_printf ("%smode",
		   m->wider ? m->wider->name : void_mode->name,
		   m->name);

  print_closer ();
  print_decl ("unsigned char", "mode_2xwider", "NUM_MACHINE_MODES");

  for_all_modes (c, m)
    {
      struct mode_data * m2;

      for (m2 = m;
	   m2 && m2 != void_mode;
	   m2 = m2->wider)
	{
	  if (m2->target)
	    continue;
	  if (m2->bytesize < 2 * m->bytesize)
	    continue;
	  if (m->precision != (unsigned int) -1)
	    {
	      if (m2->precision != 2 * m->precision)
		continue;
	    }
	  else
	    {
	      if (m2->precision != (unsigned int) -1)
		continue;
	    }

	  break;
	}
      if (m->target || m2 == void_mode)
	m2 = 0;
      tagged_printf ("%smode",
		     m2 ? m2->name : void_mode->name,
		     m->name);
    }

  print_closer ();
}

static void
emit_mode_mask (void)
{
  int c;
  struct mode_data *m;

  print_decl ("unsigned HOST_WIDE_INT", "mode_mask_array",
	      "NUM_MACHINE_MODES");
  puts ("\
#define MODE_MASK(m)                          \\\n\
  ((m) >= HOST_BITS_PER_WIDE_INT)             \\\n\
   ? ~(unsigned HOST_WIDE_INT) 0              \\\n\
   : ((unsigned HOST_WIDE_INT) 1 << (m)) - 1\n");

  for_all_modes (c, m)
    if (m->precision != (unsigned int)-1)
      tagged_printf ("MODE_MASK (%u)", m->precision, m->name);
    else
      tagged_printf ("MODE_MASK (%u*BITS_PER_UNIT)", m->bytesize, m->name);

  puts ("#undef MODE_MASK");
  print_closer ();
}

static void
emit_mode_inner (void)
{
  int c;
  struct mode_data *m;

  print_decl ("unsigned char", "mode_inner", "NUM_MACHINE_MODES");

  for_all_modes (c, m)
    tagged_printf ("%smode",
		   m->component ? m->component->name : void_mode->name,
		   m->name);

  print_closer ();
}

static void
emit_mode_base_align (void)
{
  int c;
  struct mode_data *m;

  print_maybe_const_decl ("unsigned char",
			  "mode_base_align", "NUM_MACHINE_MODES",
			  alignment);

  for_all_modes (c, m)
    tagged_printf ("%u", m->alignment, m->name);

  print_closer ();
}

static void
emit_class_narrowest_mode (void)
{
  int c;

  print_decl ("unsigned char", "class_narrowest_mode", "MAX_MODE_CLASS");

  for (c = 0; c < MAX_MODE_CLASS; c++)
    /* Bleah, all this to get the comment right for MIN_MODE_INT.  */
    tagged_printf ("MIN_%s", mode_class_names[c],
		   modes[c]
		   ? (modes[c]->precision != 1
		      ? modes[c]->name
		      : (modes[c]->next
			 ? modes[c]->next->name
			 : void_mode->name))
		   : void_mode->name);

  print_closer ();
}

static void
emit_real_format_for_mode (void)
{
  struct mode_data *m;

  /* The entities pointed to by this table are constant, whether
     or not the table itself is constant.

     For backward compatibility this table is always writable
     (several targets modify it in OVERRIDE_OPTIONS).   FIXME:
     convert all said targets to use ADJUST_FORMAT instead.  */
#if 0
  print_maybe_const_decl ("const struct real_format *%s",
			  "real_format_for_mode",
			  "MAX_MODE_FLOAT - MIN_MODE_FLOAT + 1",
			  format);
#else
  print_decl ("struct real_format *\n", "real_format_for_mode",
	      "MAX_MODE_FLOAT - MIN_MODE_FLOAT + 1 "
	      "+ MAX_MODE_DECIMAL_FLOAT - MIN_MODE_DECIMAL_FLOAT + 1");
#endif

  /* The beginning of the table is entries for float modes.  */
  for (m = modes[MODE_FLOAT]; m; m = m->next)
    if (m->target)
      ; /* Skip.  */
    else if (!strcmp (m->format, "0"))
      tagged_printf ("%s", m->format, m->name);
    else
      tagged_printf ("&%s", m->format, m->name);

  /* The end of the table is entries for decimal float modes.  */
  for (m = modes[MODE_DECIMAL_FLOAT]; m; m = m->next)
    if (m->target)
      ; /* Skip.  */
    else if (!strcmp (m->format, "0"))
      tagged_printf ("%s", m->format, m->name);
    else
      tagged_printf ("&%s", m->format, m->name);

  print_closer ();
}

static void
emit_mode_adjustments (void)
{
  struct mode_adjust *a;
  struct mode_data *m;

  puts ("\
\nvoid\
\ninit_adjust_machine_modes (void)\
\n{\
\n  size_t s ATTRIBUTE_UNUSED;");

  /* Size adjustments must be propagated to all containing modes.
     A size adjustment forces us to recalculate the alignment too.  */
  for (a = adj_bytesize; a; a = a->next)
    {
      if (a->target && strcmp (a->target, output_target) != 0)
	continue;
      printf ("\n  /* %s:%d */\n  s = %s;\n",
	      a->file, a->line, a->adjustment);
      printf ("  mode_size[%smode] = s;\n", a->mode->name);
      printf ("  mode_base_align[%smode] = s & (~s + 1);\n",
	      a->mode->name);

      for (m = a->mode->contained; m; m = m->next_cont)
	{
	  switch (m->cl)
	    {
	    case MODE_COMPLEX_INT:
	    case MODE_COMPLEX_FLOAT:
	      printf ("  mode_size[%smode] = 2*s;\n", m->name);
	      printf ("  mode_base_align[%smode] = s & (~s + 1);\n",
		      m->name);
	      break;

	    case MODE_VECTOR_INT:
	    case MODE_VECTOR_FLOAT:
	    case MODE_VECTOR_FRACT:
	    case MODE_VECTOR_UFRACT:
	    case MODE_VECTOR_ACCUM:
	    case MODE_VECTOR_UACCUM:
	      printf ("  mode_size[%smode] = %d*s;\n",
		      m->name, m->ncomponents);
	      printf ("  mode_base_align[%smode] = (%d*s) & (~(%d*s)+1);\n",
		      m->name, m->ncomponents, m->ncomponents);
	      break;

	    default:
	      internal_error (
	      "mode %s is neither vector nor complex but contains %s",
	      m->name, a->mode->name);
	      /* NOTREACHED */
	    }
	}
    }

  /* Alignment adjustments propagate too.
     ??? This may not be the right thing for vector modes.  */
  for (a = adj_alignment; a; a = a->next)
    {
      if (a->target && strcmp (a->target, output_target) != 0)
	continue;
      printf ("\n  /* %s:%d */\n  s = %s;\n",
	      a->file, a->line, a->adjustment);
      printf ("  mode_base_align[%smode] = s;\n", a->mode->name);

      for (m = a->mode->contained; m; m = m->next_cont)
	{
	  switch (m->cl)
	    {
	    case MODE_COMPLEX_INT:
	    case MODE_COMPLEX_FLOAT:
	      printf ("  mode_base_align[%smode] = s;\n", m->name);
	      break;

	    case MODE_VECTOR_INT:
	    case MODE_VECTOR_FLOAT:
	    case MODE_VECTOR_FRACT:
	    case MODE_VECTOR_UFRACT:
	    case MODE_VECTOR_ACCUM:
	    case MODE_VECTOR_UACCUM:
	      printf ("  mode_base_align[%smode] = %d*s;\n",
		      m->name, m->ncomponents);
	      break;

	    default:
	      internal_error (
	      "mode %s is neither vector nor complex but contains %s",
	      m->name, a->mode->name);
	      /* NOTREACHED */
	    }
	}
    }

  /* Ibit adjustments don't have to propagate.  */
  for (a = adj_ibit; a; a = a->next)
    {
      if (a->target && strcmp (a->target, output_target) != 0)
	continue;
      printf ("\n  /* %s:%d */\n  s = %s;\n",
	      a->file, a->line, a->adjustment);
      printf ("  mode_ibit[%smode] = s;\n", a->mode->name);
    }

  /* Fbit adjustments don't have to propagate.  */
  for (a = adj_fbit; a; a = a->next)
    {
      if (a->target && strcmp (a->target, output_target) != 0)
	continue;
      printf ("\n  /* %s:%d */\n  s = %s;\n",
	      a->file, a->line, a->adjustment);
      printf ("  mode_fbit[%smode] = s;\n", a->mode->name);
    }

  /* Real mode formats don't have to propagate anywhere.  */
  for (a = adj_format; a; a = a->next)
    {
      if (a->target && strcmp (a->target, output_target) != 0)
	continue;
      printf ("\n  /* %s:%d */\n  REAL_MODE_FORMAT (%smode) = %s;\n",
	      a->file, a->line, a->mode->name, a->adjustment);
    }

  puts ("}");
}

/* Emit ibit for all modes.  */

static void
emit_mode_ibit (void)
{
  int c;
  struct mode_data *m;

  print_maybe_const_decl ("unsigned char",
			  "mode_ibit", "NUM_MACHINE_MODES",
			  ibit);

  for_all_modes (c, m)
    tagged_printf ("%u", m->ibit, m->name);

  print_closer ();
}

/* Emit fbit for all modes.  */

static void
emit_mode_fbit (void)
{
  int c;
  struct mode_data *m;

  print_maybe_const_decl ("unsigned char",
			  "mode_fbit", "NUM_MACHINE_MODES",
			  fbit);

  for_all_modes (c, m)
    tagged_printf ("%u", m->fbit, m->name);

  print_closer ();
}


static void
emit_insn_modes_c (void)
{
  emit_insn_modes_c_header ();
  emit_mode_name ();
  emit_mode_class ();
  emit_mode_precision ();
  emit_mode_size ();
  emit_mode_nunits ();
  emit_mode_wider ();
  emit_mode_mask ();
  emit_mode_inner ();
  emit_mode_base_align ();
  emit_class_narrowest_mode ();
  emit_real_format_for_mode ();
  emit_mode_adjustments ();
  emit_mode_ibit ();
  emit_mode_fbit ();
  puts ("END_TARGET_SPECIFIC");
}

static void
emit_min_insn_modes_c (void)
{
  emit_min_insn_modes_c_header ();
  emit_mode_name ();
  emit_mode_class ();
  emit_mode_wider ();
  emit_class_narrowest_mode ();
  puts ("END_TARGET_SPECIFIC");
}

/* Master control.  */
int
main (int argc, char **argv)
{
  bool gen_header = false, gen_min = false;
  progname = argv[0];

  if (argc == 1)
    ;
  else if (argc == 2 && !strcmp (argv[1], "-h"))
    gen_header = true;
  else if (argc == 2 && !strcmp (argv[1], "-m"))
    gen_min = true;
  else
    {
      error ("usage: %s [-h|-m] > file", progname);
      return FATAL_EXIT_CODE;
    }

  modes_by_name = htab_create_alloc (64, hash_mode, eq_mode, 0, xcalloc, free);

  create_modes ();
  complete_all_modes ();

  if (have_error)
    return FATAL_EXIT_CODE;

  fixup_target_modes ();

  calc_wider_mode ();

  if (gen_header)
    emit_insn_modes_h ();
  else if (gen_min)
    emit_min_insn_modes_c ();
  else
    emit_insn_modes_c ();

  if (fflush (stdout) || fclose (stdout))
    return FATAL_EXIT_CODE;
  return SUCCESS_EXIT_CODE;
}
