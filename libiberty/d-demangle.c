/* Demangler for the D programming language
   Copyright 2014, 2015 Free Software Foundation, Inc.
   Written by Iain Buclaw (ibuclaw@gdcproject.org)

This file is part of the libiberty library.
Libiberty is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

In addition to the permissions in the GNU Library General Public
License, the Free Software Foundation gives you unlimited permission
to link the compiled version of this file into combinations with other
programs, and to distribute those combinations without any restriction
coming from the use of this file.  (The Library Public License
restrictions do apply in other respects; for example, they cover
modification of the file, and distribution when not linked into a
combined executable.)

Libiberty is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with libiberty; see the file COPYING.LIB.
If not, see <http://www.gnu.org/licenses/>.  */

/* This file exports one function; dlang_demangle.

   This file imports strtol and strtod for decoding mangled literals.  */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "safe-ctype.h"

#include <sys/types.h>
#include <string.h>
#include <stdio.h>

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#else
extern long strtol (const char *nptr, char **endptr, int base);
extern double strtod (const char *nptr, char **endptr);
#endif

#include <demangle.h>
#include "libiberty.h"

/* A mini string-handling package */

typedef struct string		/* Beware: these aren't required to be */
{				/*  '\0' terminated.  */
  char *b;			/* pointer to start of string */
  char *p;			/* pointer after last character */
  char *e;			/* pointer after end of allocated space */
} string;

static void
string_need (string *s, int n)
{
  int tem;

  if (s->b == NULL)
    {
      if (n < 32)
	{
	  n = 32;
	}
      s->p = s->b = XNEWVEC (char, n);
      s->e = s->b + n;
    }
  else if (s->e - s->p < n)
    {
      tem = s->p - s->b;
      n += tem;
      n *= 2;
      s->b = XRESIZEVEC (char, s->b, n);
      s->p = s->b + tem;
      s->e = s->b + n;
    }
}

static void
string_delete (string *s)
{
  if (s->b != NULL)
    {
      XDELETEVEC (s->b);
      s->b = s->e = s->p = NULL;
    }
}

static void
string_init (string *s)
{
  s->b = s->p = s->e = NULL;
}

static int
string_length (string *s)
{
  if (s->p == s->b)
    {
      return 0;
    }
  return s->p - s->b;
}

static void
string_setlength (string *s, int n)
{
  if (n - string_length (s) < 0)
    {
      s->p = s->b + n;
    }
}

static void
string_append (string *p, const char *s)
{
  int n = strlen (s);
  string_need (p, n);
  memcpy (p->p, s, n);
  p->p += n;
}

static void
string_appendn (string *p, const char *s, int n)
{
  if (n != 0)
    {
      string_need (p, n);
      memcpy (p->p, s, n);
      p->p += n;
    }
}

static void
string_prependn (string *p, const char *s, int n)
{
  char *q;

  if (n != 0)
    {
      string_need (p, n);
      for (q = p->p - 1; q >= p->b; q--)
	{
	  q[n] = q[0];
	}
      memcpy (p->b, s, n);
      p->p += n;
    }
}

static void
string_prepend (string *p, const char *s)
{
  if (s != NULL && *s != '\0')
    {
      string_prependn (p, s, strlen (s));
    }
}

/* What kinds of symbol we could be parsing.  */
enum dlang_symbol_kinds
{
  /* Top-level symbol, needs it's type checked.  */
  dlang_top_level,
  /* Function symbol, needs it's type checked.   */
  dlang_function,
  /* Strongly typed name, such as for classes, structs and enums.  */
  dlang_type_name,
  /* Template identifier.  */
  dlang_template_ident,
  /* Template symbol parameter.  */
  dlang_template_param
};

/* Prototypes for forward referenced functions */
static const char *dlang_function_args (string *, const char *);

static const char *dlang_type (string *, const char *);

static const char *dlang_value (string *, const char *, const char *, char);

static const char *dlang_parse_symbol (string *, const char *,
				       enum dlang_symbol_kinds);

static const char *dlang_parse_tuple (string *, const char *);

static const char *dlang_parse_template (string *, const char *, long);


/* Demangle the calling convention from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_call_convention (string *decl, const char *mangled)
{
  if (mangled == NULL || *mangled == '\0')
    return NULL;

  switch (*mangled)
    {
    case 'F': /* (D) */
      mangled++;
      break;
    case 'U': /* (C) */
      mangled++;
      string_append (decl, "extern(C) ");
      break;
    case 'W': /* (Windows) */
      mangled++;
      string_append (decl, "extern(Windows) ");
      break;
    case 'V': /* (Pascal) */
      mangled++;
      string_append (decl, "extern(Pascal) ");
      break;
    case 'R': /* (C++) */
      mangled++;
      string_append (decl, "extern(C++) ");
      break;
    default:
      return NULL;
    }

  return mangled;
}

/* Extract the type modifiers from MANGLED and append them to DECL.
   Returns the remaining signature on success or NULL on failure.  */
static const char *
dlang_type_modifiers (string *decl, const char *mangled)
{
  if (mangled == NULL || *mangled == '\0')
    return NULL;

  switch (*mangled)
    {
    case 'x': /* const */
      mangled++;
      string_append (decl, " const");
      return mangled;
    case 'y': /* immutable */
      mangled++;
      string_append (decl, " immutable");
      return mangled;
    case 'O': /* shared */
      mangled++;
      string_append (decl, " shared");
      return dlang_type_modifiers (decl, mangled);
    case 'N':
      mangled++;
      if (*mangled == 'g') /* wild */
	{
	  mangled++;
	  string_append (decl, " inout");
	  return dlang_type_modifiers (decl, mangled);
	}
      else
	return NULL;

    default:
      return mangled;
    }
}

/* Demangle the D function attributes from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_attributes (string *decl, const char *mangled)
{
  if (mangled == NULL || *mangled == '\0')
    return NULL;

  while (*mangled == 'N')
    {
      mangled++;
      switch (*mangled)
	{
	case 'a': /* pure */
	  mangled++;
	  string_append (decl, "pure ");
	  continue;
	case 'b': /* nothrow */
	  mangled++;
	  string_append (decl, "nothrow ");
	  continue;
	case 'c': /* ref */
	  mangled++;
	  string_append (decl, "ref ");
	  continue;
	case 'd': /* @property */
	  mangled++;
	  string_append (decl, "@property ");
	  continue;
	case 'e': /* @trusted */
	  mangled++;
	  string_append (decl, "@trusted ");
	  continue;
	case 'f': /* @safe */
	  mangled++;
	  string_append (decl, "@safe ");
	  continue;
	case 'g':
	case 'h':
	case 'k':
	  /* inout parameter is represented as 'Ng'.
	     vector parameter is represented as 'Nh'.
	     return paramenter is represented as 'Nk'.
	     If we see this, then we know we're really in the
	     parameter list.  Rewind and break.  */
	  mangled--;
	  break;
	case 'i': /* @nogc */
	  mangled++;
	  string_append (decl, "@nogc ");
	  continue;
	case 'j': /* return */
	  mangled++;
	  string_append (decl, "return ");
	  continue;

	default: /* unknown attribute */
	  return NULL;
	}
      break;
    }

  return mangled;
}

/* Demangle the function type from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_function_type (string *decl, const char *mangled)
{
  string attr, args, type;
  size_t szattr, szargs, sztype;

  if (mangled == NULL || *mangled == '\0')
    return NULL;

  /* The order of the mangled string is:
	CallConvention FuncAttrs Arguments ArgClose Type

     The demangled string is re-ordered as:
	CallConvention Type Arguments FuncAttrs
   */
  string_init (&attr);
  string_init (&args);
  string_init (&type);

  /* Function call convention.  */
  mangled = dlang_call_convention (decl, mangled);

  /* Function attributes.  */
  mangled = dlang_attributes (&attr, mangled);
  szattr = string_length (&attr);

  /* Function arguments.  */
  mangled = dlang_function_args (&args, mangled);
  szargs = string_length (&args);

  /* Function return type.  */
  mangled = dlang_type (&type, mangled);
  sztype = string_length (&type);

  /* Append to decl in order. */
  string_appendn (decl, type.b, sztype);
  string_append (decl, "(");
  string_appendn (decl, args.b, szargs);
  string_append (decl, ") ");
  string_appendn (decl, attr.b, szattr);

  string_delete (&attr);
  string_delete (&args);
  string_delete (&type);
  return mangled;
}

/* Demangle the argument list from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_function_args (string *decl, const char *mangled)
{
  size_t n = 0;

  while (mangled && *mangled != '\0')
    {
      switch (*mangled)
	{
	case 'X': /* (variadic T t...) style.  */
	  mangled++;
	  string_append (decl, "...");
	  return mangled;
	case 'Y': /* (variadic T t, ...) style.  */
	  mangled++;
	  string_append (decl, ", ...");
	  return mangled;
	case 'Z': /* Normal function.  */
	  mangled++;
	  return mangled;
	}

      if (n++)
	string_append (decl, ", ");

      if (*mangled == 'M') /* scope(T) */
	{
	  mangled++;
	  string_append (decl, "scope ");
	}

      if (mangled[0] == 'N' && mangled[1] == 'k') /* return(T) */
	{
	  mangled += 2;
	  string_append (decl, "return ");
	}

      switch (*mangled)
	{
	case 'J': /* out(T) */
	  mangled++;
	  string_append (decl, "out ");
	  break;
	case 'K': /* ref(T) */
	  mangled++;
	  string_append (decl, "ref ");
	  break;
	case 'L': /* lazy(T) */
	  mangled++;
	  string_append (decl, "lazy ");
	  break;
	}
      mangled = dlang_type (decl, mangled);
    }

  return mangled;
}

/* Demangle the type from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_type (string *decl, const char *mangled)
{
  if (mangled == NULL || *mangled == '\0')
    return NULL;

  switch (*mangled)
    {
    case 'O': /* shared(T) */
      mangled++;
      string_append (decl, "shared(");
      mangled = dlang_type (decl, mangled);
      string_append (decl, ")");
      return mangled;
    case 'x': /* const(T) */
      mangled++;
      string_append (decl, "const(");
      mangled = dlang_type (decl, mangled);
      string_append (decl, ")");
      return mangled;
    case 'y': /* immutable(T) */
      mangled++;
      string_append (decl, "immutable(");
      mangled = dlang_type (decl, mangled);
      string_append (decl, ")");
      return mangled;
    case 'N':
      mangled++;
      if (*mangled == 'g') /* wild(T) */
	{
	  mangled++;
	  string_append (decl, "inout(");
	  mangled = dlang_type (decl, mangled);
	  string_append (decl, ")");
	  return mangled;
	}
      else if (*mangled == 'h') /* vector(T) */
	{
	  mangled++;
	  string_append (decl, "__vector(");
	  mangled = dlang_type (decl, mangled);
	  string_append (decl, ")");
	  return mangled;
	}
      else
	return NULL;
    case 'A': /* dynamic array (T[]) */
      mangled++;
      mangled = dlang_type (decl, mangled);
      string_append (decl, "[]");
      return mangled;
    case 'G': /* static array (T[N]) */
    {
      const char *numptr;
      size_t num = 0;
      mangled++;

      numptr = mangled;
      while (ISDIGIT (*mangled))
	{
	  num++;
	  mangled++;
	}
      mangled = dlang_type (decl, mangled);
      string_append (decl, "[");
      string_appendn (decl, numptr, num);
      string_append (decl, "]");
      return mangled;
    }
    case 'H': /* associative array (T[T]) */
    {
      string type;
      size_t sztype;
      mangled++;

      string_init (&type);
      mangled = dlang_type (&type, mangled);
      sztype = string_length (&type);

      mangled = dlang_type (decl, mangled);
      string_append (decl, "[");
      string_appendn (decl, type.b, sztype);
      string_append (decl, "]");

      string_delete (&type);
      return mangled;
    }
    case 'P': /* pointer (T*) */
      mangled++;
      mangled = dlang_type (decl, mangled);
      string_append (decl, "*");
      return mangled;
    case 'I': /* ident T */
    case 'C': /* class T */
    case 'S': /* struct T */
    case 'E': /* enum T */
    case 'T': /* typedef T */
      mangled++;
      return dlang_parse_symbol (decl, mangled, dlang_type_name);
    case 'D': /* delegate T */
    {
      string mods;
      size_t szmods;
      mangled++;

      string_init (&mods);
      mangled = dlang_type_modifiers (&mods, mangled);
      szmods = string_length (&mods);

      mangled = dlang_function_type (decl, mangled);
      string_append (decl, "delegate");
      string_appendn (decl, mods.b, szmods);

      string_delete (&mods);
      return mangled;
    }
    case 'B': /* tuple T */
      mangled++;
      return dlang_parse_tuple (decl, mangled);

    /* Function types */
    case 'F': case 'U': case 'W':
    case 'V': case 'R':
      mangled = dlang_function_type (decl, mangled);
      string_append (decl, "function");
      return mangled;

    /* Basic types */
    case 'n':
      mangled++;
      string_append (decl, "none");
      return mangled;
    case 'v':
      mangled++;
      string_append (decl, "void");
      return mangled;
    case 'g':
      mangled++;
      string_append (decl, "byte");
      return mangled;
    case 'h':
      mangled++;
      string_append (decl, "ubyte");
      return mangled;
    case 's':
      mangled++;
      string_append (decl, "short");
      return mangled;
    case 't':
      mangled++;
      string_append (decl, "ushort");
      return mangled;
    case 'i':
      mangled++;
      string_append (decl, "int");
      return mangled;
    case 'k':
      mangled++;
      string_append (decl, "uint");
      return mangled;
    case 'l':
      mangled++;
      string_append (decl, "long");
      return mangled;
    case 'm':
      mangled++;
      string_append (decl, "ulong");
      return mangled;
    case 'f':
      mangled++;
      string_append (decl, "float");
      return mangled;
    case 'd':
      mangled++;
      string_append (decl, "double");
      return mangled;
    case 'e':
      mangled++;
      string_append (decl, "real");
      return mangled;

    /* Imaginary and Complex types */
    case 'o':
      mangled++;
      string_append (decl, "ifloat");
      return mangled;
    case 'p':
      mangled++;
      string_append (decl, "idouble");
      return mangled;
    case 'j':
      mangled++;
      string_append (decl, "ireal");
      return mangled;
    case 'q':
      mangled++;
      string_append (decl, "cfloat");
      return mangled;
    case 'r':
      mangled++;
      string_append (decl, "cdouble");
      return mangled;
    case 'c':
      mangled++;
      string_append (decl, "creal");
      return mangled;

    /* Other types */
    case 'b':
      mangled++;
      string_append (decl, "bool");
      return mangled;
    case 'a':
      mangled++;
      string_append (decl, "char");
      return mangled;
    case 'u':
      mangled++;
      string_append (decl, "wchar");
      return mangled;
    case 'w':
      mangled++;
      string_append (decl, "dchar");
      return mangled;
    case 'z':
      mangled++;
      switch (*mangled)
	{
	case 'i':
	  mangled++;
	  string_append (decl, "cent");
	  return mangled;
	case 'k':
	  mangled++;
	  string_append (decl, "ucent");
	  return mangled;
	}
      return NULL;

    default: /* unhandled */
      return NULL;
    }
}

/* Extract the identifier from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_identifier (string *decl, const char *mangled,
		  enum dlang_symbol_kinds kind)
{
  char *endptr;
  long len;

  if (mangled == NULL || *mangled == '\0')
    return NULL;

  len = strtol (mangled, &endptr, 10);

  if (endptr == NULL || len <= 0)
    return NULL;

  /* In template parameter symbols, the first character of the mangled
     name can be a digit.  This causes ambiguity issues because the
     digits of the two numbers are adjacent.  */
  if (kind == dlang_template_param)
    {
      long psize = len;
      char *pend;
      int saved = string_length (decl);

      /* Work backwards until a match is found.  */
      for (pend = endptr; endptr != NULL; pend--)
	{
	  mangled = pend;

	  /* Reached the beginning of the pointer to the name length,
	     try parsing the entire symbol.  */
	  if (psize == 0)
	    {
	      psize = len;
	      pend = endptr;
	      endptr = NULL;
	    }

	  /* Check whether template parameter is a function with a valid
	     return type or an untyped identifier.  */
	  if (ISDIGIT (*mangled))
	    mangled = dlang_parse_symbol (decl, mangled, dlang_template_ident);
	  else if (strncmp (mangled, "_D", 2) == 0)
	    {
	      mangled += 2;
	      mangled = dlang_parse_symbol (decl, mangled, dlang_function);
	    }

	  /* Check for name length mismatch.  */
	  if (mangled && (mangled - pend) == psize)
	    return mangled;

	  psize /= 10;
	  string_setlength (decl, saved);
	}

      /* No match on any combinations.  */
      return NULL;
    }
  else
    {
      if (strlen (endptr) < (size_t) len)
	return NULL;

      mangled = endptr;

      /* May be a template instance.  */
      if (len >= 5 && strncmp (mangled, "__T", 3) == 0)
	{
	  /* Template symbol.  */
	  if (ISDIGIT (mangled[3]) && mangled[3] != '0')
	    return dlang_parse_template (decl, mangled, len);

	  return NULL;
	}

      switch (len)
	{
	case 6:
	  if (strncmp (mangled, "__ctor", len) == 0)
	    {
	      /* Constructor symbol for a class/struct.  */
	      string_append (decl, "this");
	      mangled += len;
	      return mangled;
	    }
	  else if (strncmp (mangled, "__dtor", len) == 0)
	    {
	      /* Destructor symbol for a class/struct.  */
	      string_append (decl, "~this");
	      mangled += len;
	      return mangled;
	    }
	  else if (strncmp (mangled, "__initZ", len+1) == 0)
	    {
	      /* The static initialiser for a given symbol.  */
	      string_append (decl, "init$");
	      mangled += len;
	      return mangled;
	    }
	  else if (strncmp (mangled, "__vtblZ", len+1) == 0)
	    {
	      /* The vtable symbol for a given class.  */
	      string_prepend (decl, "vtable for ");
	      string_setlength (decl, string_length (decl) - 1);
	      mangled += len;
	      return mangled;
	    }
	  break;

	case 7:
	  if (strncmp (mangled, "__ClassZ", len+1) == 0)
	    {
	      /* The classinfo symbol for a given class.  */
	      string_prepend (decl, "ClassInfo for ");
	      string_setlength (decl, string_length (decl) - 1);
	      mangled += len;
	      return mangled;
	    }
	  break;

	case 10:
	  if (strncmp (mangled, "__postblitMFZ", len+3) == 0)
	    {
	      /* Postblit symbol for a struct.  */
	      string_append (decl, "this(this)");
	      mangled += len + 3;
	      return mangled;
	    }
	  break;

	case 11:
	  if (strncmp (mangled, "__InterfaceZ", len+1) == 0)
	    {
	      /* The interface symbol for a given class.  */
	      string_prepend (decl, "Interface for ");
	      string_setlength (decl, string_length (decl) - 1);
	      mangled += len;
	      return mangled;
	    }
	  break;

	case 12:
	  if (strncmp (mangled, "__ModuleInfoZ", len+1) == 0)
	    {
	      /* The ModuleInfo symbol for a given module.  */
	      string_prepend (decl, "ModuleInfo for ");
	      string_setlength (decl, string_length (decl) - 1);
	      mangled += len;
	      return mangled;
	    }
	  break;
	}

      string_appendn (decl, mangled, len);
      mangled += len;
    }

  return mangled;
}

/* Extract the integer value from MANGLED and append it to DECL,
   where TYPE is the type it should be represented as.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_parse_integer (string *decl, const char *mangled, char type)
{
  if (type == 'a' || type == 'u' || type == 'w')
    {
      /* Parse character value.  */
      char value[10];
      int pos = 10;
      int width = 0;
      char *endptr;
      long val = strtol (mangled, &endptr, 10);

      if (endptr == NULL || val < 0)
	return NULL;

      string_append (decl, "'");

      if (type == 'a' && val >= 0x20 && val < 0x7F)
	{
	  /* Represent as a character literal.  */
	  char c = (char) val;
	  string_appendn (decl, &c, 1);
	}
      else
	{
	  /* Represent as a hexadecimal value.  */
	  switch (type)
	    {
	    case 'a': /* char */
	      string_append (decl, "\\x");
	      width = 2;
	      break;
	    case 'u': /* wchar */
	      string_append (decl, "\\u");
	      width = 4;
	      break;
	    case 'w': /* dchar */
	      string_append (decl, "\\U");
	      width = 8;
	      break;
	    }

	  while (val > 0)
	    {
	      int digit = val % 16;

	      if (digit < 10)
		value[--pos] = (char)(digit + '0');
	      else
		value[--pos] = (char)((digit - 10) + 'a');

	      val /= 16;
	      width--;
	    }

	  for (; width > 0; width--)
	    value[--pos] = '0';

	  string_appendn (decl, &(value[pos]), 10 - pos);
	}
      string_append (decl, "'");
      mangled = endptr;
    }
  else if (type == 'b')
    {
      /* Parse boolean value.  */
      char *endptr;
      long val = strtol (mangled, &endptr, 10);

      if (endptr == NULL || val < 0)
	return NULL;

      string_append (decl, val ? "true" : "false");
      mangled = endptr;
    }
  else
    {
      /* Parse integer value.  */
      const char *numptr = mangled;
      size_t num = 0;

      while (ISDIGIT (*mangled))
	{
	  num++;
	  mangled++;
	}
      string_appendn (decl, numptr, num);

      /* Append suffix.  */
      switch (type)
	{
	case 'h': /* ubyte */
	case 't': /* ushort */
	case 'k': /* uint */
	  string_append (decl, "u");
	  break;
	case 'l': /* long */
	  string_append (decl, "L");
	  break;
	case 'm': /* ulong */
	  string_append (decl, "uL");
	  break;
	}
    }

  return mangled;
}

/* Extract the floating-point value from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_parse_real (string *decl, const char *mangled)
{
  char buffer[64];
  int len = 0;
  double value;
  char *endptr;

  /* Handle NAN and +-INF.  */
  if (strncmp (mangled, "NAN", 3) == 0)
    {
      string_append (decl, "NaN");
      mangled += 3;
      return mangled;
    }
  else if (strncmp (mangled, "INF", 3) == 0)
    {
      string_append (decl, "Inf");
      mangled += 3;
      return mangled;
    }
  else if (strncmp (mangled, "NINF", 4) == 0)
    {
      string_append (decl, "-Inf");
      mangled += 4;
      return mangled;
    }

  /* Hexadecimal prefix and leading bit.  */
  if (*mangled == 'N')
    {
      buffer[len++] = '-';
      mangled++;
    }

  if (!ISXDIGIT (*mangled))
    return NULL;

  buffer[len++] = '0';
  buffer[len++] = 'x';
  buffer[len++] = *mangled;
  buffer[len++] = '.';
  mangled++;

  /* Significand.  */
  while (ISXDIGIT (*mangled))
    {
      buffer[len++] = *mangled;
      mangled++;
    }

  /* Exponent.  */
  if (*mangled != 'P')
    return NULL;

  buffer[len++] = 'p';
  mangled++;

  if (*mangled == 'N')
    {
      buffer[len++] = '-';
      mangled++;
    }

  while (ISDIGIT (*mangled))
    {
      buffer[len++] = *mangled;
      mangled++;
    }

  /* Convert buffer from hexadecimal to floating-point.  */
  buffer[len] = '\0';
  value = strtod (buffer, &endptr);

  if (endptr == NULL || endptr != (buffer + len))
    return NULL;

  len = snprintf (buffer, sizeof(buffer), "%#g", value);
  string_appendn (decl, buffer, len);
  return mangled;
}

/* Convert VAL from an ascii hexdigit to value.  */
static char
ascii2hex (char val)
{
  if (val >= 'a' && val <= 'f')
    return (val - 'a' + 10);

  if (val >= 'A' && val <= 'F')
    return (val - 'A' + 10);

  if (val >= '0' && val <= '9')
    return (val - '0');

  return 0;
}

/* Extract the string value from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_parse_string (string *decl, const char *mangled)
{
  char type = *mangled;
  char *endptr;
  long len;

  mangled++;
  len = strtol (mangled, &endptr, 10);

  if (endptr == NULL || len < 0)
    return NULL;

  mangled = endptr;
  if (*mangled != '_')
    return NULL;

  mangled++;
  string_append (decl, "\"");
  while (len--)
    {
      if (ISXDIGIT (mangled[0]) && ISXDIGIT (mangled[1]))
	{
	  char a = ascii2hex (mangled[0]);
	  char b = ascii2hex (mangled[1]);
	  char val = (a << 4) | b;

	  /* Sanitize white and non-printable characters.  */
	  switch (val)
	    {
	    case ' ':
	      string_append (decl, " ");
	      break;
	    case '\t':
	      string_append (decl, "\\t");
	      break;
	    case '\n':
	      string_append (decl, "\\n");
	      break;
	    case '\r':
	      string_append (decl, "\\r");
	      break;
	    case '\f':
	      string_append (decl, "\\f");
	      break;
	    case '\v':
	      string_append (decl, "\\v");
	      break;

	    default:
	      if (ISPRINT (val))
		string_appendn (decl, &val, 1);
	      else
		{
		  string_append (decl, "\\x");
		  string_appendn (decl, mangled, 2);
		}
	    }
	}
      else
	return NULL;

      mangled += 2;
    }
  string_append (decl, "\"");

  if (type != 'a')
    string_appendn (decl, &type, 1);

  return mangled;
}

/* Extract the static array value from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_parse_arrayliteral (string *decl, const char *mangled)
{
  char *endptr;
  long elements = strtol (mangled, &endptr, 10);

  if (endptr == NULL || elements < 0)
    return NULL;

  mangled = endptr;
  string_append (decl, "[");
  while (elements--)
    {
      mangled = dlang_value (decl, mangled, NULL, '\0');
      if (elements != 0)
	string_append (decl, ", ");
    }

  string_append (decl, "]");
  return mangled;
}

/* Extract the associative array value from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_parse_assocarray (string *decl, const char *mangled)
{
  char *endptr;
  long elements = strtol (mangled, &endptr, 10);

  if (endptr == NULL || elements < 0)
    return NULL;

  mangled = endptr;
  string_append (decl, "[");
  while (elements--)
    {
      mangled = dlang_value (decl, mangled, NULL, '\0');
      string_append (decl, ":");
      mangled = dlang_value (decl, mangled, NULL, '\0');

      if (elements != 0)
	string_append (decl, ", ");
    }

  string_append (decl, "]");
  return mangled;
}

/* Extract the struct literal value for NAME from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_parse_structlit (string *decl, const char *mangled, const char *name)
{
  char *endptr;
  long args = strtol (mangled, &endptr, 10);

  if (endptr == NULL || args < 0)
    return NULL;

  mangled = endptr;
  if (name != NULL)
    string_append (decl, name);

  string_append (decl, "(");
  while (args--)
    {
      mangled = dlang_value (decl, mangled, NULL, '\0');
      if (args != 0)
	string_append (decl, ", ");
    }

  string_append (decl, ")");
  return mangled;
}

/* Extract the value from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_value (string *decl, const char *mangled, const char *name, char type)
{
  if (mangled == NULL || *mangled == '\0')
    return NULL;

  switch (*mangled)
    {
      /* Null value.  */
    case 'n':
      mangled++;
      string_append (decl, "null");
      break;

      /* Integral values.  */
    case 'N':
      mangled++;
      string_append (decl, "-");
      mangled = dlang_parse_integer (decl, mangled, type);
      break;

    case 'i':
      mangled++;
      if (*mangled < '0' || *mangled > '9')
	return NULL;
      /* Fall through */
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      mangled = dlang_parse_integer (decl, mangled, type);
      break;

      /* Real value.  */
    case 'e':
      mangled++;
      mangled = dlang_parse_real (decl, mangled);
      break;

      /* Complex value.  */
    case 'c':
      mangled++;
      mangled = dlang_parse_real (decl, mangled);
      string_append (decl, "+");
      if (mangled == NULL || *mangled != 'c')
	return NULL;
      mangled++;
      mangled = dlang_parse_real (decl, mangled);
      string_append (decl, "i");
      break;

      /* String values.  */
    case 'a': /* UTF8 */
    case 'w': /* UTF16 */
    case 'd': /* UTF32 */
      mangled = dlang_parse_string (decl, mangled);
      break;

      /* Array values.  */
    case 'A':
      mangled++;
      if (type == 'H')
	mangled = dlang_parse_assocarray (decl, mangled);
      else
	mangled = dlang_parse_arrayliteral (decl, mangled);
      break;

      /* Struct values.  */
    case 'S':
      mangled++;
      mangled = dlang_parse_structlit (decl, mangled, name);
      break;

    default:
      return NULL;
    }

  return mangled;
}

/* Extract the type modifiers from MANGLED and return the string
   length that it consumes in MANGLED on success or 0 on failure.  */
static int
dlang_type_modifier_p (const char *mangled)
{
  int i;

  switch (*mangled)
    {
    case 'x': case 'y':
      return 1;

    case 'O':
      mangled++;
      i = dlang_type_modifier_p (mangled);
      return i + 1;

    case 'N':
      mangled++;
      if (*mangled == 'g')
	{
	  mangled++;
	  i = dlang_type_modifier_p (mangled);
	  return i + 2;
	}
    }

  return 0;
}

/* Extract the function calling convention from MANGLED and
   return 1 on success or 0 on failure.  */
static int
dlang_call_convention_p (const char *mangled)
{
  /* Prefix for functions needing 'this' */
  if (*mangled == 'M')
    {
      mangled++;
      /* Also skip over any type modifiers.  */
      mangled += dlang_type_modifier_p (mangled);
    }

  switch (*mangled)
    {
    case 'F': case 'U': case 'V':
    case 'W': case 'R':
      return 1;

    default:
      return 0;
    }
}

/* Extract and demangle the symbol in MANGLED and append it to DECL.
   Returns the remaining signature on success or NULL on failure.  */
static const char *
dlang_parse_symbol (string *decl, const char *mangled,
		    enum dlang_symbol_kinds kind)
{
  int saved;
  size_t n = 0;
  do
    {
      if (n++)
	string_append (decl, ".");

      mangled = dlang_identifier (decl, mangled, kind);

      if (mangled && dlang_call_convention_p (mangled))
	{
	  string mods;
	  const char *start = NULL;
	  int checkpoint = 0;

	  /* Skip over 'this' parameter.  */
	  if (*mangled == 'M')
	    mangled++;

	  /* We have reached here because we expect an extern(Pascal) function.
	     However this is so rare, that it is more likely a template value
	     parameter.  Since this can't be assumed, first attempt parsing
	     the symbol as a function, and then back out on failure.  */
	  if (*mangled == 'V')
	    {
	      start = mangled;
	      checkpoint = string_length (decl);
	    }

	  /* Save the type modifiers for appending at the end.  */
	  string_init (&mods);
	  mangled = dlang_type_modifiers (&mods, mangled);

	  /* Skip over calling convention and attributes in qualified name.  */
	  saved = string_length (decl);
	  mangled = dlang_call_convention (decl, mangled);
	  mangled = dlang_attributes (decl, mangled);
	  string_setlength (decl, saved);

	  string_append (decl, "(");
	  mangled = dlang_function_args (decl, mangled);
	  string_append (decl, ")");

	  /* Add any const/immutable/shared modifier. */
	  string_appendn (decl, mods.b, string_length (&mods));
	  string_delete (&mods);

	  if (mangled == NULL && checkpoint != 0)
	    {
	      mangled = start;
	      string_setlength (decl, checkpoint);
	    }
	}
    }
  while (mangled && ISDIGIT (*mangled));

  /* Only top-level symbols or function template parameters have
     a type that needs checking.  */
  if (kind == dlang_top_level || kind == dlang_function)
    {
      /* Artificial symbols end with 'Z' and have no type.  */
      if (mangled && *mangled == 'Z')
	mangled++;
      else
	{
	  saved = string_length (decl);
	  mangled = dlang_type (decl, mangled);
	  string_setlength (decl, saved);
	}

      /* Check that the entire symbol was successfully demangled.  */
      if (kind == dlang_top_level)
	{
	  if (mangled == NULL || *mangled != '\0')
	    return NULL;
	}
    }

  return mangled;
}

/* Demangle the tuple from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_parse_tuple (string *decl, const char *mangled)
{
  char *endptr;
  long elements = strtol (mangled, &endptr, 10);

  if (endptr == NULL || elements < 0)
    return NULL;

  mangled = endptr;
  string_append (decl, "Tuple!(");

  while (elements--)
    {
      mangled = dlang_type (decl, mangled);
      if (elements != 0)
	string_append (decl, ", ");
    }

  string_append (decl, ")");
  return mangled;
}

/* Demangle the argument list from MANGLED and append it to DECL.
   Return the remaining string on success or NULL on failure.  */
static const char *
dlang_template_args (string *decl, const char *mangled)
{
  size_t n = 0;

  while (mangled && *mangled != '\0')
    {
      switch (*mangled)
	{
	case 'Z': /* End of parameter list.  */
	  mangled++;
	  return mangled;
	}

      if (n++)
	string_append (decl, ", ");

      /* Skip over specialised template prefix.  */
      if (*mangled == 'H')
	mangled++;

      switch (*mangled)
	{
	case 'S': /* Symbol parameter.  */
	  mangled++;
	  mangled = dlang_parse_symbol (decl, mangled, dlang_template_param);
	  break;
	case 'T': /* Type parameter.  */
	  mangled++;
	  mangled = dlang_type (decl, mangled);
	  break;
	case 'V': /* Value parameter.  */
	{
	  string name;
	  char type;

	  /* Peek at the type.  */
	  mangled++;
	  type = *mangled;

	  /* In the few instances where the type is actually desired in
	     the output, it should precede the value from dlang_value.  */
	  string_init (&name);
	  mangled = dlang_type (&name, mangled);
	  string_need (&name, 1);
	  *(name.p) = '\0';

	  mangled = dlang_value (decl, mangled, name.b, type);
	  string_delete (&name);
	  break;
	}

	default:
	  return NULL;
	}
    }

  return mangled;
}

/* Extract and demangle the template symbol in MANGLED, expected to
   be made up of LEN characters, and append it to DECL.
   Returns the remaining signature on success or NULL on failure.  */
static const char *
dlang_parse_template (string *decl, const char *mangled, long len)
{
  const char *start = mangled;

  /* Template instance names have the types and values of its parameters
     encoded into it.

	TemplateInstanceName:
	    Number __T LName TemplateArgs Z
		   ^
     The start pointer should be at the above location, and LEN should be
     the value of the decoded number.
   */
  if (strncmp (mangled, "__T", 3) != 0)
    return NULL;

  mangled += 3;

  /* Template identifier.  */
  mangled = dlang_identifier (decl, mangled, dlang_template_ident);

  /* Template arguments.  */
  string_append (decl, "!(");
  mangled = dlang_template_args (decl, mangled);
  string_append (decl, ")");

  /* Check for template name length mismatch.  */
  if (mangled && (mangled - start) != len)
    return NULL;

  return mangled;
}

/* Extract and demangle the symbol in MANGLED.  Returns the demangled
   signature on success or NULL on failure.  */

char *
dlang_demangle (const char *mangled, int option ATTRIBUTE_UNUSED)
{
  string decl;
  char *demangled = NULL;

  if (mangled == NULL || *mangled == '\0')
    return NULL;

  if (strncmp (mangled, "_D", 2) != 0)
    return NULL;

  string_init (&decl);

  if (strcmp (mangled, "_Dmain") == 0)
    {
      string_append (&decl, "D main");
    }
  else
    {
      mangled += 2;

      if (dlang_parse_symbol (&decl, mangled, dlang_top_level) == NULL)
	string_delete (&decl);
    }

  if (string_length (&decl) > 0)
    {
      string_need (&decl, 1);
      *(decl.p) = '\0';
      demangled = decl.b;
    }

  return demangled;
}

