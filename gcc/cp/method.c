/* Handle the hair of processing (but not expanding) inline functions.
   Also manage function and variable name overloading.
   Copyright (C) 1987, 89, 92-97, 1998 Free Software Foundation, Inc.
   Contributed by Michael Tiemann (tiemann@cygnus.com)

This file is part of GNU CC.
   
GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */


#ifndef __GNUC__
#define __inline
#endif

#ifndef PARM_CAN_BE_ARRAY_TYPE
#define PARM_CAN_BE_ARRAY_TYPE 1
#endif

/* Handle method declarations.  */
#include "config.h"
#include "system.h"
#include "tree.h"
#include "cp-tree.h"
#include "obstack.h"
#include "rtl.h"
#include "expr.h"
#include "output.h"
#include "hard-reg-set.h"
#include "flags.h"
#include "toplev.h"

/* TREE_LIST of the current inline functions that need to be
   processed.  */
struct pending_inline *pending_inlines;

int static_labelno;

#define obstack_chunk_alloc xmalloc
#define obstack_chunk_free free

/* Obstack where we build text strings for overloading, etc.  */
static struct obstack scratch_obstack;
static char *scratch_firstobj;

static void icat PROTO((HOST_WIDE_INT));
static void dicat PROTO((HOST_WIDE_INT, HOST_WIDE_INT));
static void flush_repeats PROTO((tree));
static void build_overload_identifier PROTO((tree));
static void build_overload_nested_name PROTO((tree));
static void build_overload_int PROTO((tree, int));
static void build_overload_identifier PROTO((tree));
static void build_qualified_name PROTO((tree));
static void build_overload_value PROTO((tree, tree, int));
static void issue_nrepeats PROTO((tree));
static char *build_mangled_name PROTO((tree,int,int));
static void process_modifiers PROTO((tree));
static void process_overload_item PROTO((tree,int));
static void do_build_assign_ref PROTO((tree));
static void do_build_copy_constructor PROTO((tree));
static tree largest_union_member PROTO((tree));
static tree build_decl_overload_real PROTO((tree, tree, tree, tree,
					    tree, int)); 
static void build_template_template_parm_names PROTO((tree));
static void build_template_parm_names PROTO((tree, tree));
static void build_underscore_int PROTO((int));
static void start_squangling PROTO((void));
static void end_squangling PROTO((void));
static int check_ktype PROTO((tree, int));
static int issue_ktype PROTO((tree));
static void build_overload_scope_ref PROTO((tree));
static void build_mangled_template_parm_index PROTO((char *, tree));
static int check_btype PROTO((tree));

# define OB_INIT() (scratch_firstobj ? (obstack_free (&scratch_obstack, scratch_firstobj), 0) : 0)
# define OB_PUTC(C) (obstack_1grow (&scratch_obstack, (C)))
# define OB_PUTC2(C1,C2)	\
  (obstack_1grow (&scratch_obstack, (C1)), obstack_1grow (&scratch_obstack, (C2)))
# define OB_PUTS(S) (obstack_grow (&scratch_obstack, (S), sizeof (S) - 1))
# define OB_PUTID(ID)  \
  (obstack_grow (&scratch_obstack, IDENTIFIER_POINTER (ID),	\
		 IDENTIFIER_LENGTH (ID)))
# define OB_PUTCP(S) (obstack_grow (&scratch_obstack, (S), strlen (S)))
# define OB_FINISH() (obstack_1grow (&scratch_obstack, '\0'))
# define OB_LAST() (obstack_next_free (&scratch_obstack)[-1])

void
init_method ()
{
  gcc_obstack_init (&scratch_obstack);
  scratch_firstobj = (char *)obstack_alloc (&scratch_obstack, 0);
}

/* This must be large enough to hold any printed integer or floating-point
   value.  */
static char digit_buffer[128];

/* Move inline function definitions out of structure so that they
   can be processed normally.  CNAME is the name of the class
   we are working from, METHOD_LIST is the list of method lists
   of the structure.  We delete friend methods here, after
   saving away their inline function definitions (if any).  */

void
do_inline_function_hair (type, friend_list)
     tree type, friend_list;
{
  tree method = TYPE_METHODS (type);

  if (method && TREE_CODE (method) == TREE_VEC)
    {
      if (TREE_VEC_ELT (method, 1))
	method = TREE_VEC_ELT (method, 1);
      else if (TREE_VEC_ELT (method, 0))
	method = TREE_VEC_ELT (method, 0);
      else
	method = TREE_VEC_ELT (method, 2);
    }

  while (method)
    {
      /* Do inline member functions.  */
      struct pending_inline *info = DECL_PENDING_INLINE_INFO (method);
      if (info)
	{
	  tree args;

	  my_friendly_assert (info->fndecl == method, 238);
	  args = DECL_ARGUMENTS (method);
	  while (args)
	    {
	      DECL_CONTEXT (args) = method;
	      args = TREE_CHAIN (args);
	    }
	}
      method = TREE_CHAIN (method);
    }
  while (friend_list)
    {
      tree fndecl = TREE_VALUE (friend_list);
      struct pending_inline *info = DECL_PENDING_INLINE_INFO (fndecl);
      if (info)
	{
	  tree args;

	  my_friendly_assert (info->fndecl == fndecl, 239);
	  args = DECL_ARGUMENTS (fndecl);
	  while (args)
	    {
	      DECL_CONTEXT (args) = fndecl;
	      args = TREE_CHAIN (args);
	    }
	}

      friend_list = TREE_CHAIN (friend_list);
    }
}

/* Here is where overload code starts.  */

/* type tables for K and B type compression */
static tree *btypelist = NULL;
static tree *ktypelist = NULL;
static tree lasttype = NULL;
static int maxbsize = 0;
static int maxksize = 0;

/* number of each type seen */
static int maxbtype = 0;
static int maxktype = 0;

/* Number of occurrences of last b type seen.  */
static int nrepeats = 0;

/* Array of types seen so far in top-level call to `build_mangled_name'.
   Allocated and deallocated by caller.  */
static tree *typevec = NULL;
static int  typevec_size;

/* Number of types interned by `build_mangled_name' so far.  */
static int maxtype = 0;

/* Number of occurrences of last type seen.  */
static int Nrepeats = 0;

/* Nonzero if we should not try folding parameter types.  */
static int nofold;

/* This appears to be set to true if an underscore is required to be
   comcatenated before another number can be outputed. */
static int numeric_output_need_bar;

static __inline void
start_squangling ()
{
  if (flag_do_squangling)
    {
      lasttype = NULL;
      nofold = 0;
      nrepeats = 0;
      maxbtype = 0;
      maxktype = 0;
      maxbsize = 50;
      maxksize = 50;
      btypelist = (tree *)xmalloc (sizeof (tree) * maxbsize);
      ktypelist = (tree *)xmalloc (sizeof (tree) * maxksize);
    }
}

static __inline void
end_squangling ()
{
  if (flag_do_squangling)
    {
      lasttype = NULL;
      if (ktypelist)
        free (ktypelist);
      if (btypelist)
        free (btypelist);
      maxbsize = 0;
      maxksize = 0;
      maxbtype = 0;
      maxktype = 0;
      ktypelist = NULL;
      btypelist = NULL;
    }
}

/* Code to concatenate an asciified integer to a string.  */

static __inline void
icat (i)
     HOST_WIDE_INT i;
{
  unsigned HOST_WIDE_INT ui;

  /* Handle this case first, to go really quickly.  For many common values,
     the result of ui/10 below is 1.  */
  if (i == 1)
    {
      OB_PUTC ('1');
      return;
    }

  if (i >= 0)
    ui = i;
  else
    {
      OB_PUTC ('m');
      ui = -i;
    }

  if (ui >= 10)
    icat (ui / 10);

  OB_PUTC ('0' + (ui % 10));
}

static void
dicat (lo, hi)
     HOST_WIDE_INT lo, hi;
{
  unsigned HOST_WIDE_INT ulo, uhi, qlo, qhi;

  if (hi >= 0)
    {
      uhi = hi;
      ulo = lo;
    }
  else
    {
      uhi = (lo == 0 ? -hi : -hi-1);
      ulo = -lo;
    }
  if (uhi == 0
      && ulo < ((unsigned HOST_WIDE_INT)1 << (HOST_BITS_PER_WIDE_INT - 1)))
    {
      icat (ulo);
      return;
    }
  /* Divide 2^HOST_WIDE_INT*uhi+ulo by 10. */
  qhi = uhi / 10;
  uhi = uhi % 10;
  qlo = uhi * (((unsigned HOST_WIDE_INT)1 << (HOST_BITS_PER_WIDE_INT - 1)) / 5);
  qlo += ulo / 10;
  ulo = ulo % 10;
  ulo += uhi * (((unsigned HOST_WIDE_INT)1 << (HOST_BITS_PER_WIDE_INT - 1)) % 5)
	 * 2;
  qlo += ulo / 10;
  ulo = ulo % 10;
  /* Quotient is 2^HOST_WIDE_INT*qhi+qlo, remainder is ulo. */
  dicat (qlo, qhi);
  OB_PUTC ('0' + ulo);
}

static __inline void
flush_repeats (type)
     tree type;
{
  int tindex = 0;

  while (typevec[tindex] != type)
    tindex++;

  if (Nrepeats > 1)
    {
      OB_PUTC ('N');
      icat (Nrepeats);
      if (Nrepeats > 9)
	OB_PUTC ('_');
    }
  else
    OB_PUTC ('T');
  Nrepeats = 0;
  icat (tindex);
  if (tindex > 9)
    OB_PUTC ('_');
}


/* issue squangling type repeating */
static void
issue_nrepeats (lasttype)
     tree lasttype;
{
  if (nrepeats == 1)
    {
      switch (TREE_CODE (lasttype))
        {
          case INTEGER_TYPE:
          case REAL_TYPE:
          case VOID_TYPE:
          case BOOLEAN_TYPE:
            process_overload_item (lasttype, FALSE);
            nrepeats = 0;
            return;

          default:
            break;
        }
    }
  OB_PUTC ('n');
  icat (nrepeats);
  if (nrepeats > 9)
    OB_PUTC ('_');
  nrepeats = 0;
}


/* Check to see if a tree node has been entered into the Kcode typelist    */
/* if not, add it. Return -1 if it isn't found, otherwise return the index */
static int
check_ktype (node, add)
     tree node;
     int add;
{
  int x;
  tree localnode = node;

  if (ktypelist == NULL)
    return -1;

  if (TREE_CODE (node) == TYPE_DECL)
    localnode = TREE_TYPE (node);

  for (x=0; x < maxktype; x++)
    {
      if (localnode == ktypelist[x])
        return x ;
    }
  /* Didn't find it, so add it here */
  if (add)
    {
      if (maxksize <= maxktype)
        {
          maxksize = maxksize* 3 / 2;
          ktypelist = (tree *)xrealloc (ktypelist, sizeof (tree) * maxksize);
        }
      ktypelist[maxktype++] = localnode;
    }
  return -1;
}


static __inline int
issue_ktype (decl)
     tree decl;
{
  int kindex;
  kindex = check_ktype (decl, FALSE);
  if (kindex != -1)
    {
      OB_PUTC ('K');
      icat (kindex);
      if (kindex > 9)
        OB_PUTC ('_');
      return TRUE;
    }
  return FALSE;
}

static void
build_overload_nested_name (decl)
     tree decl;
{

  tree context;

  if (ktypelist && issue_ktype (decl))
      return;

  if (decl == global_namespace)
    return;

  context = CP_DECL_CONTEXT (decl);

  /* try to issue a K type, and if we can't continue the normal path */
  if (!(ktypelist && issue_ktype (context)))
  {
    /* For a template type parameter, we want to output an 'Xn'
       rather than 'T' or some such. */
    if (TREE_CODE (context) == TEMPLATE_TYPE_PARM
        || TREE_CODE (context) == TEMPLATE_TEMPLATE_PARM)
      build_mangled_name (context, 0, 0);
    else
    {
      if (TREE_CODE_CLASS (TREE_CODE (context)) == 't')
        context = TYPE_NAME (context);
      build_overload_nested_name (context);
    }
  }

  if (TREE_CODE (decl) == FUNCTION_DECL)
    {
      tree name = DECL_ASSEMBLER_NAME (decl);
      char *label;

      ASM_FORMAT_PRIVATE_NAME (label, IDENTIFIER_POINTER (name), static_labelno);
      static_labelno++;

      if (numeric_output_need_bar)
	OB_PUTC ('_');
      icat (strlen (label));
      OB_PUTCP (label);
      numeric_output_need_bar = 1;
    }
  else if (TREE_CODE (decl) == NAMESPACE_DECL)
    build_overload_identifier (DECL_NAME (decl));
  else				/* TYPE_DECL */
    build_overload_identifier (decl);
}

static void
build_underscore_int (i)
     int i;
{
  if (i > 9)
    OB_PUTC ('_');
  icat (i);
  if (i > 9)
    OB_PUTC ('_');
}

static void
build_overload_scope_ref (value)
     tree value;
{
  OB_PUTC2 ('Q', '2');
  numeric_output_need_bar = 0;
  build_mangled_name (TREE_OPERAND (value, 0), 0, 0);
  build_overload_identifier (TREE_OPERAND (value, 1));
}

/* Encoding for an INTEGER_CST value.  */

static void
build_overload_int (value, in_template)
     tree value;
     int in_template;
{
  if (in_template && TREE_CODE (value) != INTEGER_CST)
    {
      if (TREE_CODE (value) == SCOPE_REF)
	{
	  build_overload_scope_ref (value);
	  return;
	}

      OB_PUTC ('E');
      numeric_output_need_bar = 0;

      if (IS_EXPR_CODE_CLASS (TREE_CODE_CLASS (TREE_CODE (value))))
	{
	  int i;
	  int operands = tree_code_length[(int) TREE_CODE (value)];
	  tree id;
	  char* name;

	  id = ansi_opname [(int) TREE_CODE (value)];
	  my_friendly_assert (id != NULL_TREE, 0);
	  name = IDENTIFIER_POINTER (id);
	  if (name[0] != '_' || name[1] != '_')
	    /* On some erroneous inputs, we can get here with VALUE a
	       LOOKUP_EXPR.  In that case, the NAME will be the
	       identifier for "<invalid operator>".  We must survive
	       this routine in order to issue a sensible error
	       message, so we fall through to the case below.  */
	    goto bad_value;

	  for (i = 0; i < operands; ++i)
	    {
	      tree operand;
	      enum tree_code tc;

	      /* We just outputted either the `E' or the name of the
		 operator.  */
	      numeric_output_need_bar = 0;

	      if (i != 0)
		/* Skip the leading underscores.  */
		OB_PUTCP (name + 2);

	      operand = TREE_OPERAND (value, i);
	      tc = TREE_CODE (operand);

	      if (TREE_CODE_CLASS (tc) == 't')
		/* We can get here with sizeof, e.g.:
		     
		   template <class T> void f(A<sizeof(T)>);  */
		process_overload_item (operand, 0);
	      else if (IS_EXPR_CODE_CLASS (TREE_CODE_CLASS (tc)))
		build_overload_int (operand, in_template);
	      else
		build_overload_value (TREE_TYPE (operand),
				      operand,
				      in_template);
	    }
	}
      else
	{
	  /* We don't ever want this output, but it's
	     inconvenient not to be able to build the string.
	     This should cause assembler errors we'll notice.  */
	    
	  static int n;
	bad_value:
	  sprintf (digit_buffer, " *%d", n++);
	  OB_PUTCP (digit_buffer);
	}

      OB_PUTC ('W');
      numeric_output_need_bar = 0;
      return;
    }

  my_friendly_assert (TREE_CODE (value) == INTEGER_CST, 243);
  if (TYPE_PRECISION (TREE_TYPE (value)) == 2 * HOST_BITS_PER_WIDE_INT)
    {
      if (TREE_INT_CST_HIGH (value)
	  != (TREE_INT_CST_LOW (value) >> (HOST_BITS_PER_WIDE_INT - 1)))
	{
	  /* need to print a DImode value in decimal */
	  dicat (TREE_INT_CST_LOW (value), TREE_INT_CST_HIGH (value));
	  numeric_output_need_bar = 1;
	  return;
	}
      /* else fall through to print in smaller mode */
    }
  /* Wordsize or smaller */
  icat (TREE_INT_CST_LOW (value));
  numeric_output_need_bar = 1;
}


/* Output S followed by a representation of the TEMPLATE_PARM_INDEX
   supplied in INDEX.  */

static void 
build_mangled_template_parm_index (s, index)
     char* s;
     tree index;
{
  OB_PUTCP (s);
  build_underscore_int (TEMPLATE_PARM_IDX (index));
  /* We use the LEVEL, not the ORIG_LEVEL, because the mangling is a
     representation of the function from the point of view of its
     type.  */
  build_underscore_int (TEMPLATE_PARM_LEVEL (index));
}


static void
build_overload_value (type, value, in_template)
     tree type, value;
     int in_template;
{
  while (TREE_CODE (value) == NON_LVALUE_EXPR
	 || TREE_CODE (value) == NOP_EXPR)
    value = TREE_OPERAND (value, 0);

  if (TREE_CODE (type) == PARM_DECL)
    type = TREE_TYPE (type);

  my_friendly_assert (TREE_CODE_CLASS (TREE_CODE (type)) == 't', 0);

  if (numeric_output_need_bar)
    {
      OB_PUTC ('_');
      numeric_output_need_bar = 0;
    }

  if (TREE_CODE (value) == TEMPLATE_PARM_INDEX)
    {
      build_mangled_template_parm_index ("Y", value);
      return;
    }

  if (TREE_CODE (type) == POINTER_TYPE
      && TREE_CODE (TREE_TYPE (type)) == OFFSET_TYPE)
    {
      /* Handle a pointer to data member as a template instantiation
	 parameter, boy, what fun!  */
      type = integer_type_node;
      if (TREE_CODE (value) != INTEGER_CST)
	{
	  sorry ("unknown pointer to member constant");
	  return;
	}
    }

  if (TYPE_PTRMEMFUNC_P (type))
    type = TYPE_PTRMEMFUNC_FN_TYPE (type);

  switch (TREE_CODE (type))
    {
    case INTEGER_TYPE:
    case ENUMERAL_TYPE:
    case BOOLEAN_TYPE:
      {
	build_overload_int (value, in_template);
	return;
      }
    case REAL_TYPE:
      {
	REAL_VALUE_TYPE val;
	char *bufp = digit_buffer;

	pedwarn ("ANSI C++ forbids floating-point template arguments");

	my_friendly_assert (TREE_CODE (value) == REAL_CST, 244);
	val = TREE_REAL_CST (value);
	if (REAL_VALUE_ISNAN (val))
	  {
	    sprintf (bufp, "NaN");
	  }
	else
	  {
	    if (REAL_VALUE_NEGATIVE (val))
	      {
		val = REAL_VALUE_NEGATE (val);
		*bufp++ = 'm';
	      }
	    if (REAL_VALUE_ISINF (val))
	      {
		sprintf (bufp, "Infinity");
	      }
	    else
	      {
		REAL_VALUE_TO_DECIMAL (val, "%.20e", bufp);
		bufp = (char *) index (bufp, 'e');
		if (!bufp)
		  strcat (digit_buffer, "e0");
		else
		  {
		    char *p;
		    bufp++;
		    if (*bufp == '-')
		      {
			*bufp++ = 'm';
		      }
		    p = bufp;
		    if (*p == '+')
		      p++;
		    while (*p == '0')
		      p++;
		    if (*p == 0)
		      {
			*bufp++ = '0';
			*bufp = 0;
		      }
		    else if (p != bufp)
		      {
			while (*p)
			  *bufp++ = *p++;
			*bufp = 0;
		      }
		  }
#ifdef NO_DOT_IN_LABEL
		bufp = (char *) index (bufp, '.');
		if (bufp)
		  *bufp = '_';
#endif
	      }
	  }
	OB_PUTCP (digit_buffer);
	numeric_output_need_bar = 1;
	return;
      }
    case POINTER_TYPE:
      if (TREE_CODE (TREE_TYPE (type)) == METHOD_TYPE
	  && TREE_CODE (value) != ADDR_EXPR)
	{
	  if (TREE_CODE (value) == CONSTRUCTOR)
	    {
	      /* This is dangerous code, crack built up pointer to members.  */
	      tree args = CONSTRUCTOR_ELTS (value);
	      tree a1 = TREE_VALUE (args);
	      tree a2 = TREE_VALUE (TREE_CHAIN (args));
	      tree a3 = CONSTRUCTOR_ELTS (TREE_VALUE (TREE_CHAIN (TREE_CHAIN (args))));
	      a3 = TREE_VALUE (a3);
	      STRIP_NOPS (a3);
	      if (TREE_CODE (a1) == INTEGER_CST
		  && TREE_CODE (a2) == INTEGER_CST)
		{
		  build_overload_int (a1, in_template);
		  OB_PUTC ('_');
		  build_overload_int (a2, in_template);
		  OB_PUTC ('_');
		  if (TREE_CODE (a3) == ADDR_EXPR)
		    {
		      a3 = TREE_OPERAND (a3, 0);
		      if (TREE_CODE (a3) == FUNCTION_DECL)
			{
			  numeric_output_need_bar = 0;
			  build_overload_identifier (DECL_ASSEMBLER_NAME (a3));
			  return;
			}
		    }
		  else if (TREE_CODE (a3) == INTEGER_CST)
		    {
		      OB_PUTC ('i');
		      build_overload_int (a3, in_template);
		      return;
		    }
		}
	    }
	  sorry ("template instantiation with pointer to method that is too complex");
	  return;
	}
      if (TREE_CODE (value) == INTEGER_CST)
	{
	  build_overload_int (value, in_template);
	  return;
	}
      else if (TREE_CODE (value) == TEMPLATE_PARM_INDEX)
	{
	  build_mangled_template_parm_index ("", value);
	  numeric_output_need_bar = 1;
	  return;
	}

      value = TREE_OPERAND (value, 0);
      if (TREE_CODE (value) == VAR_DECL)
	{
	  my_friendly_assert (DECL_NAME (value) != 0, 245);
	  build_overload_identifier (DECL_ASSEMBLER_NAME (value));
	  return;
	}
      else if (TREE_CODE (value) == FUNCTION_DECL)
	{
	  my_friendly_assert (DECL_NAME (value) != 0, 246);
	  build_overload_identifier (DECL_ASSEMBLER_NAME (value));
	  return;
	}
      else if (TREE_CODE (value) == SCOPE_REF)
	build_overload_scope_ref (value);
      else
	my_friendly_abort (71);
      break; /* not really needed */

    default:
      sorry ("conversion of %s as template parameter",
	     tree_code_name [(int) TREE_CODE (type)]);
      my_friendly_abort (72);
    }
}


/* Add encodings for the declaration of template template parameters.
   PARMLIST must be a TREE_VEC */

static void
build_template_template_parm_names (parmlist)
     tree parmlist;
{
  int i, nparms;

  my_friendly_assert (TREE_CODE (parmlist) == TREE_VEC, 246.5);
  nparms = TREE_VEC_LENGTH (parmlist);
  icat (nparms);
  for (i = 0; i < nparms; i++)
    {
      tree parm = TREE_VALUE (TREE_VEC_ELT (parmlist, i));
      if (TREE_CODE (parm) == TYPE_DECL)
	{
	  /* This parameter is a type.  */
	  OB_PUTC ('Z');
	}
      else if (TREE_CODE (parm) == TEMPLATE_DECL)
	{
	  /* This parameter is a template. */
	  OB_PUTC ('z');
	  build_template_template_parm_names (DECL_INNERMOST_TEMPLATE_PARMS (parm));
	}
      else
	{
	  /* It's a PARM_DECL.  */
	  build_mangled_name (TREE_TYPE (parm), 0, 0);
	}
    }
}


/* Add encodings for the vector of template parameters in PARMLIST,
   given the vector of arguments to be substituted in ARGLIST.  */

static void
build_template_parm_names (parmlist, arglist)
     tree parmlist;
     tree arglist;
{
  int i, nparms;
  
  nparms = TREE_VEC_LENGTH (parmlist);
  icat (nparms);
  for (i = 0; i < nparms; i++)
    {
      tree parm = TREE_VALUE (TREE_VEC_ELT (parmlist, i));
      tree arg = TREE_VEC_ELT (arglist, i);
      if (TREE_CODE (parm) == TYPE_DECL)
	{
	  /* This parameter is a type.  */
	  OB_PUTC ('Z');
	  build_mangled_name (arg, 0, 0);
	}
      else if (TREE_CODE (parm) == TEMPLATE_DECL)
	{
	  /* This parameter is a template. */
	  if (TREE_CODE (arg) == TEMPLATE_TEMPLATE_PARM)
	    /* Output parameter declaration, argument index and level */
	    build_mangled_name (arg, 0, 0);
	  else
	    {
	      /* A TEMPLATE_DECL node, output the parameter declaration 
		 and template name */

	      OB_PUTC ('z');
	      build_template_template_parm_names (DECL_INNERMOST_TEMPLATE_PARMS (parm));
	      icat (IDENTIFIER_LENGTH (DECL_NAME (arg)));
	      OB_PUTID (DECL_NAME (arg));
	    }
	}
      else
	{
	  parm = tsubst (parm, arglist, NULL_TREE);
	  /* It's a PARM_DECL.  */
	  build_mangled_name (TREE_TYPE (parm), 0, 0);
	  build_overload_value (parm, arg, uses_template_parms (arglist));
	}
    }
 }


static void
build_overload_identifier (name)
     tree name;
{
  if (TREE_CODE (name) == TYPE_DECL
      && IS_AGGR_TYPE (TREE_TYPE (name))
      && CLASSTYPE_TEMPLATE_INFO (TREE_TYPE (name))
      && (PRIMARY_TEMPLATE_P (CLASSTYPE_TI_TEMPLATE (TREE_TYPE (name)))
	  || (TREE_CODE (DECL_CONTEXT (CLASSTYPE_TI_TEMPLATE 
				       (TREE_TYPE (name))))
	      == FUNCTION_DECL)))
    {
      tree template, parmlist, arglist, tname;
      template = CLASSTYPE_TEMPLATE_INFO (TREE_TYPE (name));
      arglist = innermost_args (TREE_VALUE (template), 0);
      template = TREE_PURPOSE (template);
      tname = DECL_NAME (template);
      parmlist = DECL_INNERMOST_TEMPLATE_PARMS (template);
      OB_PUTC ('t');
      icat (IDENTIFIER_LENGTH (tname));
      OB_PUTID (tname);
      build_template_parm_names (parmlist, arglist);
    }
  else
    {
      if (TREE_CODE (name) == TYPE_DECL)
	name = DECL_NAME (name);
      if (numeric_output_need_bar)
	{
	  OB_PUTC ('_');
	  numeric_output_need_bar = 0;
	}
      icat (IDENTIFIER_LENGTH (name));
      OB_PUTID (name);
    }
}

/* Given DECL, either a class TYPE, TYPE_DECL or FUNCTION_DECL, produce
   the mangling for it.  Used by build_mangled_name and build_static_name.  */

static void
build_qualified_name (decl)
     tree decl;
{
  tree context;
  int i = 1;

  if (TREE_CODE_CLASS (TREE_CODE (decl)) == 't')
    decl = TYPE_NAME (decl);

  /* If DECL_ASSEMBLER_NAME has been set properly, use it.  */
  if (TREE_CODE (decl) == TYPE_DECL
      && DECL_ASSEMBLER_NAME (decl) != DECL_NAME (decl) && !flag_do_squangling)
    {
      tree id = DECL_ASSEMBLER_NAME (decl);
      OB_PUTID (id);
      if (ISDIGIT (IDENTIFIER_POINTER (id) [IDENTIFIER_LENGTH (id) - 1]))
	numeric_output_need_bar = 1;
      return;
    }

  context = decl;
  /* if we can't find a Ktype, do it the hard way */
  if (check_ktype (context, FALSE) == -1)
    {
      /* count type and namespace scopes */
      while (DECL_CONTEXT (context) && DECL_CONTEXT (context) != global_namespace)
	{
	  i += 1;
	  context = DECL_CONTEXT (context);
	  if (check_ktype (context, FALSE) != -1)  /* found it! */
	    break;
	  if (TREE_CODE_CLASS (TREE_CODE (context)) == 't')
	    context = TYPE_NAME (context);
	}
    }

  if (i > 1)
    {
      OB_PUTC ('Q');
      build_underscore_int (i);
      numeric_output_need_bar = 0;
    }
  build_overload_nested_name (decl);
}

/* Given a list of parameters in PARMTYPES, create an unambiguous
   overload string. Should distinguish any type that C (or C++) can
   distinguish. I.e., pointers to functions are treated correctly.

   Caller must deal with whether a final `e' goes on the end or not.

   Any default conversions must take place before this function
   is called.

   BEGIN and END control initialization and finalization of the
   obstack where we build the string.  */

char *
build_overload_name (parmtypes, begin, end)
     tree parmtypes;
     int begin, end;
{
  char *ret;
  start_squangling ();
  ret = build_mangled_name (parmtypes, begin, end);
  end_squangling ();
  return ret ;
}

static char *
build_mangled_name (parmtypes, begin, end)
     tree parmtypes;
     int begin, end;
{
  tree parmtype;

  if (begin) 
    OB_INIT ();
  numeric_output_need_bar = 0;

  if (TREE_CODE (parmtypes) != TREE_LIST)  /* just one item */
    {
      if (TYPE_PTRMEMFUNC_P (parmtypes))
        parmtypes = TYPE_PTRMEMFUNC_FN_TYPE (parmtypes);
      parmtypes = CANONICAL_TYPE_VARIANT (parmtypes);
      process_modifiers (parmtypes);
      process_overload_item (parmtypes, FALSE);
    }
  else  {
    for ( ; parmtypes!=NULL; parmtypes = TREE_CHAIN (parmtypes))
      {
        parmtype = CANONICAL_TYPE_VARIANT (TREE_VALUE (parmtypes));
        if (flag_do_squangling)       /* squangling style repeats */
          {
            if (parmtype == lasttype) 
              {
                nrepeats++;
                continue;
              }
            else 
              if (nrepeats != 0) 
                {
                  issue_nrepeats (lasttype);
                }
            lasttype = parmtype;
          }
        else 
          if (!nofold && typevec)
            {
              /* Every argument gets counted.  */
	      my_friendly_assert (maxtype < typevec_size, 387);
              typevec[maxtype++] = parmtype;

              if (TREE_USED (parmtype) && parmtype == typevec[maxtype-2]
		  && ! TYPE_FOR_JAVA (parmtype))
                {
                  Nrepeats++;
                  continue;
                }

              if (Nrepeats)
                flush_repeats (typevec[maxtype-2]);

              if (TREE_USED (parmtype))
                {
#if 0
                  /* We can turn this on at some point when we want
                     improved symbol mangling.  */
                  Nrepeats++;
#else
                  /* This is bug compatible with 2.7.x  */
                  flush_repeats (parmtype);
#endif
                  continue;
                }

              /* Only cache types which take more than one character.  */
              if ((parmtype != TYPE_MAIN_VARIANT (parmtype)
		   || (TREE_CODE (parmtype) != INTEGER_TYPE
		       && TREE_CODE (parmtype) != REAL_TYPE))
		  && ! TYPE_FOR_JAVA (parmtype))
                TREE_USED (parmtype) = 1;
            }
        if (TYPE_PTRMEMFUNC_P (parmtype))
          parmtype = TYPE_PTRMEMFUNC_FN_TYPE (parmtype);
        process_modifiers (parmtype);
        if (TREE_CODE(parmtype)==VOID_TYPE) 
	  {
#if 0
	      extern tree void_list_node;

	      /* See if anybody is wasting memory.  */
	      my_friendly_assert (parmtypes == void_list_node, 247);
#endif
	      /* This is the end of a parameter list.  */
	      if (end) 
                OB_FINISH ();
	      return (char *)obstack_base (&scratch_obstack);
	  }
        process_overload_item (parmtype, TRUE);
      }
      if (flag_do_squangling && nrepeats != 0)
        issue_nrepeats (lasttype);
      else 
        if (Nrepeats && typevec)
          flush_repeats (typevec[maxtype-1]);

      /* To get here, parms must end with `...'.  */
      OB_PUTC ('e');
  }
  if (end) 
    OB_FINISH ();
  return (char *)obstack_base (&scratch_obstack);
}

/* handles emitting modifiers such as Constant, read-only, and volatile */
void 
process_modifiers (parmtype) 
     tree parmtype;
{


  if (TREE_READONLY (parmtype))
    OB_PUTC ('C');
  if (TREE_CODE (parmtype) == INTEGER_TYPE
      && (TYPE_MAIN_VARIANT (parmtype)
	  == unsigned_type (TYPE_MAIN_VARIANT (parmtype)))
      && ! TYPE_FOR_JAVA (parmtype))
    {
      OB_PUTC ('U');
    }
  if (TYPE_VOLATILE (parmtype))
    OB_PUTC ('V');
}

/* Check to see if a tree node has been entered into the Bcode typelist 
   if not, add it. Otherwise emit the code and return TRUE */
static int 
check_btype (node) 
     tree node;
{
  int x;

  if (btypelist == NULL)
    return 0;

  switch (TREE_CODE (node)) 
    {
    case INTEGER_TYPE:
    case REAL_TYPE:
    case VOID_TYPE:
    case BOOLEAN_TYPE:
      return 0;         /* don't compress single char basic types */

    default:
      break;
    }

  node = TYPE_MAIN_VARIANT (node);
  for (x = 0; x < maxbtype; x++) 
    {
      if (node == btypelist[x]) 
        {
          OB_PUTC ('B');
          icat (x);
          if (x > 9)
            OB_PUTC ('_');
          return 1 ;
        }
    }
  /* didn't find it, so add it here */
  if (maxbsize <= maxbtype) 
    {
      maxbsize = maxbsize * 3 / 2;
      btypelist = (tree *)xrealloc (btypelist, sizeof (tree) * maxbsize); 
    }
  btypelist[maxbtype++] = node;
  return 0;
}

/* handle emitting the correct code for various node types */
static void 
process_overload_item (parmtype, extra_Gcode) 
  tree parmtype;
  int extra_Gcode;
{

  /* These tree types are considered modifiers for B code squangling , */
  /* and therefore should not get entries in the Btypelist             */
  /* they are, however, repeatable types                               */

  switch (TREE_CODE (parmtype))
    {
    case REFERENCE_TYPE:
      OB_PUTC ('R');
      goto more;

    case ARRAY_TYPE:
#if PARM_CAN_BE_ARRAY_TYPE
      {
        tree length;

        OB_PUTC ('A');
        if (TYPE_DOMAIN (parmtype) == NULL_TREE)
          error("pointer/reference to array of unknown bound in parm type");
        else
          {
            length = array_type_nelts (parmtype);
            if (TREE_CODE (length) == INTEGER_CST)
              icat (TREE_INT_CST_LOW (length) + 1);
          }
        OB_PUTC ('_');
        goto more;
      }
#else
      OB_PUTC ('P');
      goto more;
#endif

    case POINTER_TYPE:
      OB_PUTC ('P');
    more:
      build_mangled_name (TREE_TYPE (parmtype), 0, 0);
      return;
      break;

    default:
      break;
    }
  
  /* check if type is already in the typelist. If not, add it now */

  if (flag_do_squangling && btypelist != NULL) {
    if (check_btype (parmtype))    /* emits the code if it finds it */
      return;
  }

  switch (TREE_CODE (parmtype))
    {
    case OFFSET_TYPE:
      OB_PUTC ('O');
      build_mangled_name (TYPE_OFFSET_BASETYPE (parmtype), 0, 0);
      OB_PUTC ('_');
      build_mangled_name (TREE_TYPE (parmtype), 0, 0);
      break;

    case FUNCTION_TYPE:
    case METHOD_TYPE:
      {
        tree firstarg = TYPE_ARG_TYPES (parmtype);
        /* Otherwise have to implement reentrant typevecs,
           unmark and remark types, etc.  */
        int old_nofold = nofold;
        if (!flag_do_squangling) {
          nofold = 1;
          if (Nrepeats)
            flush_repeats (typevec[maxtype-1]);
        }
        else 
          if (nrepeats != 0)
            issue_nrepeats (lasttype);

        /* @@ It may be possible to pass a function type in
           which is not preceded by a 'P'.  */
        if (TREE_CODE (parmtype) == FUNCTION_TYPE)
          {
            OB_PUTC ('F');
            if (firstarg == NULL_TREE)
              OB_PUTC ('e');
            else if (firstarg == void_list_node)
              OB_PUTC ('v');
            else
              build_mangled_name (firstarg, 0, 0);
          }
        else
          {
            int constp = TYPE_READONLY (TREE_TYPE (TREE_VALUE (firstarg)));
            int volatilep = TYPE_VOLATILE (TREE_TYPE (TREE_VALUE (firstarg)));
            OB_PUTC ('M');
            firstarg = TREE_CHAIN (firstarg);

            build_mangled_name (TYPE_METHOD_BASETYPE (parmtype), 0, 0);
            if (constp)
              OB_PUTC ('C');
            if (volatilep)
              OB_PUTC ('V');

            /* For cfront 2.0 compatibility.  */
            OB_PUTC ('F');

            if (firstarg == NULL_TREE)
              OB_PUTC ('e');
            else if (firstarg == void_list_node)
              OB_PUTC ('v');
            else
              build_mangled_name (firstarg, 0, 0);
          }

        /* Separate args from return type.  */
        OB_PUTC ('_');
        build_mangled_name (TREE_TYPE (parmtype), 0, 0);
        nofold = old_nofold;
        break;
      }

    case INTEGER_TYPE:
      parmtype = TYPE_MAIN_VARIANT (parmtype);
      if (parmtype == integer_type_node
          || parmtype == unsigned_type_node
	  || parmtype == java_int_type_node)
        OB_PUTC ('i');
      else if (parmtype == long_integer_type_node
               || parmtype == long_unsigned_type_node)
        OB_PUTC ('l');
      else if (parmtype == short_integer_type_node
               || parmtype == short_unsigned_type_node
	       || parmtype == java_short_type_node)
        OB_PUTC ('s');
      else if (parmtype == signed_char_type_node)
        {
          OB_PUTC ('S');
          OB_PUTC ('c');
        }
      else if (parmtype == char_type_node
               || parmtype == unsigned_char_type_node
	       || parmtype == java_byte_type_node)
        OB_PUTC ('c');
      else if (parmtype == wchar_type_node
	       || parmtype == java_char_type_node)
        OB_PUTC ('w');
      else if (parmtype == long_long_integer_type_node
	       || parmtype == long_long_unsigned_type_node
	       || parmtype == java_long_type_node)
        OB_PUTC ('x');
#if 0
      /* it would seem there is no way to enter these in source code,
         yet.  (mrs) */
      else if (parmtype == long_long_long_integer_type_node
          || parmtype == long_long_long_unsigned_type_node)
        OB_PUTC ('q');
#endif
      else if (parmtype == java_boolean_type_node)
	OB_PUTC ('b');
      else
        my_friendly_abort (73);
      break;

    case BOOLEAN_TYPE:
      OB_PUTC ('b');
      break;

    case REAL_TYPE:
      parmtype = TYPE_MAIN_VARIANT (parmtype);
      if (parmtype == long_double_type_node)
        OB_PUTC ('r');
      else if (parmtype == double_type_node
	       || parmtype == java_double_type_node)
        OB_PUTC ('d');
      else if (parmtype == float_type_node
	       || parmtype == java_float_type_node)
        OB_PUTC ('f');
      else my_friendly_abort (74);
      break;

    case COMPLEX_TYPE:
      OB_PUTC ('J');
      build_mangled_name (TREE_TYPE (parmtype), 0, 0);
      break;

    case VOID_TYPE:
      OB_PUTC ('v');
      break;

    case ERROR_MARK:	/* not right, but nothing is anyway */
      break;

      /* have to do these */
    case UNION_TYPE:
    case RECORD_TYPE:
      {   
        if (extra_Gcode)
          OB_PUTC ('G');       /* make it look incompatible with AT&T */
        /* drop through into next case */
      }
    case ENUMERAL_TYPE:
      {
        tree name = TYPE_NAME (parmtype);

        if (TREE_CODE (name) == IDENTIFIER_NODE)
          {
            build_overload_identifier (TYPE_NAME (parmtype));
            break;
          }
        my_friendly_assert (TREE_CODE (name) == TYPE_DECL, 248);

        build_qualified_name (name);
        break;
      }

    case UNKNOWN_TYPE:
      /* This will take some work.  */
      OB_PUTC ('?');
      break;

    case TEMPLATE_TEMPLATE_PARM:
      /* Find and output the original template parameter 
         declaration. */
      if (CLASSTYPE_TEMPLATE_INFO (parmtype))
        {
	  build_mangled_template_parm_index ("tzX",
					     TEMPLATE_TYPE_PARM_INDEX 
					     (parmtype));
          build_template_parm_names
            (DECL_INNERMOST_TEMPLATE_PARMS (CLASSTYPE_TI_TEMPLATE (parmtype)),
	     CLASSTYPE_TI_ARGS (parmtype));
        }
      else
        {
	  build_mangled_template_parm_index ("ZzX",
					     TEMPLATE_TYPE_PARM_INDEX 
					     (parmtype));
          build_template_template_parm_names
            (DECL_INNERMOST_TEMPLATE_PARMS (TYPE_STUB_DECL (parmtype)));
        }
      break;

    case TEMPLATE_TYPE_PARM:
      build_mangled_template_parm_index ("X", 
					 TEMPLATE_TYPE_PARM_INDEX
					 (parmtype));
      break;
        
    case TYPENAME_TYPE:
      /* When mangling the type of a function template whose
         declaration looks like:

         template <class T> void foo(typename T::U)
         
         we have to mangle these.  */
      build_qualified_name (parmtype);
      break;

    default:
      my_friendly_abort (75);
    }

}

/* Produce the mangling for a variable named NAME in CONTEXT, which can
   be either a class TYPE or a FUNCTION_DECL.  */

tree
build_static_name (context, name)
     tree context, name;
{
  OB_INIT ();
  numeric_output_need_bar = 0;
  start_squangling ();
#ifdef JOINER
  OB_PUTC ('_');
  build_qualified_name (context);
  OB_PUTC (JOINER);
#else
  OB_PUTS ("__static_");
  build_qualified_name (context);
  OB_PUTC ('_');
#endif
  OB_PUTID (name);
  OB_FINISH ();
  end_squangling ();

  return get_identifier ((char *)obstack_base (&scratch_obstack));
}

static tree 
build_decl_overload_real (dname, parms, ret_type, tparms, targs,
			  for_method) 
     tree dname;
     tree parms;
     tree ret_type;
     tree tparms;
     tree targs;
     int for_method;
{
  char *name = IDENTIFIER_POINTER (dname);

  /* member operators new and delete look like methods at this point.  */
  if (! for_method && parms != NULL_TREE && TREE_CODE (parms) == TREE_LIST
      && TREE_CHAIN (parms) == void_list_node)
    {
      if (dname == ansi_opname[(int) DELETE_EXPR])
	return get_identifier ("__builtin_delete");
      else if (dname == ansi_opname[(int) VEC_DELETE_EXPR])
	return get_identifier ("__builtin_vec_delete");
      if (dname == ansi_opname[(int) NEW_EXPR])
	return get_identifier ("__builtin_new");
      else if (dname == ansi_opname[(int) VEC_NEW_EXPR])
	return get_identifier ("__builtin_vec_new");
    }

  start_squangling ();
  OB_INIT ();
  if (for_method != 2)
    OB_PUTCP (name);
  /* Otherwise, we can divine that this is a constructor,
     and figure out its name without any extra encoding.  */

  OB_PUTC2 ('_', '_');
  if (for_method)
    {
#if 0
      /* We can get away without doing this.  */
      OB_PUTC ('M');
#endif
      if (tparms != NULL_TREE)
	OB_PUTC ('H');
      {
	tree this_type = TREE_VALUE (parms);

	if (TREE_CODE (this_type) == RECORD_TYPE)  /* a signature pointer */
	  parms = temp_tree_cons (NULL_TREE, SIGNATURE_TYPE (this_type),
				  TREE_CHAIN (parms));
	else
	  parms = temp_tree_cons (NULL_TREE, TREE_TYPE (this_type),
				  TREE_CHAIN (parms));
      }
    }
  else if (tparms)
    OB_PUTC ('H');
  /* XXX this works only if we call this in the same namespace
     as the declaration. Unfortunately, we don't have the _DECL,
     only its name */
  else if (current_namespace == global_namespace)
    OB_PUTC ('F');

  if (tparms)
    {
      build_template_parm_names (tparms, targs);
      OB_PUTC ('_');
    }

  /* qualify with namespace */
  if (!for_method && current_namespace != global_namespace)
    build_qualified_name (current_namespace);

  if (parms == NULL_TREE)
    OB_PUTC ('e');
  else if (parms == void_list_node)
    OB_PUTC ('v');
  else
    {
      if (!flag_do_squangling)    /* Allocate typevec array. */
        {
          maxtype = 0;
          Nrepeats = 0;
	  typevec_size = list_length (parms);
	  if (!for_method && current_namespace != global_namespace)
	    /* the namespace of a global function needs one slot */
	    typevec_size++;
          typevec = (tree *)alloca (typevec_size * sizeof (tree));
        }
      nofold = 0;
      if (for_method)
	{
	  build_mangled_name (TREE_VALUE (parms), 0, 0);

          if (!flag_do_squangling) {
	    my_friendly_assert (maxtype < typevec_size, 387);
            typevec[maxtype++] = TREE_VALUE (parms);
            TREE_USED (TREE_VALUE (parms)) = 1;
          }

	  if (TREE_CHAIN (parms))
	    build_mangled_name (TREE_CHAIN (parms), 0, 0);
	  else
	    OB_PUTC ('e');
	}
      else
	{
	  /* the namespace qualifier for a global function 
	     will count as type */
	  if (current_namespace != global_namespace
	      && !flag_do_squangling)
	    {
	      my_friendly_assert (maxtype < typevec_size, 387);
	      typevec[maxtype++] = current_namespace;
	    }
	  build_mangled_name (parms, 0, 0);
	}

      if (!flag_do_squangling)     /* Deallocate typevec array */
        {
          tree t = parms;
          typevec = NULL;
          while (t)
            {
              tree temp = TREE_VALUE (t);
              TREE_USED (temp) = 0;
              /* clear out the type variant in case we used it */
              temp = CANONICAL_TYPE_VARIANT (temp);
              TREE_USED (temp) = 0;
              t = TREE_CHAIN (t);
            }
        }
    }

  if (ret_type != NULL_TREE && for_method != 2)
    {
      /* Add the return type. */
      OB_PUTC ('_');
      build_mangled_name (ret_type, 0, 0);
    }

  OB_FINISH ();
  end_squangling ();
  {
    tree n = get_identifier (obstack_base (&scratch_obstack));
    if (IDENTIFIER_OPNAME_P (dname))
      IDENTIFIER_OPNAME_P (n) = 1;
    return n;
  }
}

/* Change the name of a function definition so that it may be
   overloaded. NAME is the name of the function to overload,
   PARMS is the parameter list (which determines what name the
   final function obtains).

   FOR_METHOD is 1 if this overload is being performed
   for a method, rather than a function type.  It is 2 if
   this overload is being performed for a constructor.  */

tree
build_decl_overload (dname, parms, for_method)
     tree dname;
     tree parms;
     int for_method;
{
  return build_decl_overload_real (dname, parms, NULL_TREE, NULL_TREE,
				   NULL_TREE, for_method); 
}


/* Like build_decl_overload, but for template functions. */

tree
build_template_decl_overload (dname, parms, ret_type, tparms, targs,
			      for_method) 
     tree dname;
     tree parms;
     tree ret_type;
     tree tparms;
     tree targs;
     int for_method;
{
  return build_decl_overload_real (dname, parms, ret_type, tparms, targs,
				   for_method); 
}


/* Build an overload name for the type expression TYPE.  */

tree
build_typename_overload (type)
     tree type;
{
  tree id;

  OB_INIT ();
  OB_PUTID (ansi_opname[(int) TYPE_EXPR]);
  nofold = 1;
  start_squangling ();
  build_mangled_name (type, 0, 1);
  id = get_identifier (obstack_base (&scratch_obstack));
  IDENTIFIER_OPNAME_P (id) = 1;
#if 0
  IDENTIFIER_GLOBAL_VALUE (id) = TYPE_MAIN_DECL (type);
#endif
  TREE_TYPE (id) = type;
  end_squangling ();
  return id;
}

tree
build_overload_with_type (name, type)
     tree name, type;
{
  OB_INIT ();
  OB_PUTID (name);
  nofold = 1;

  start_squangling ();
  build_mangled_name (type, 0, 1);
  end_squangling ();
  return get_identifier (obstack_base (&scratch_obstack));
}

tree
get_id_2 (name, name2)
     char *name;
     tree name2;
{
  OB_INIT ();
  OB_PUTCP (name);
  OB_PUTID (name2);
  OB_FINISH ();
  return get_identifier (obstack_base (&scratch_obstack));
}

/* Returns a DECL_ASSEMBLER_NAME for the destructor of type TYPE.  */

tree
build_destructor_name (type)
     tree type;
{
  return build_overload_with_type (get_identifier (DESTRUCTOR_DECL_PREFIX),
				   type);
}

/* Given a tree_code CODE, and some arguments (at least one),
   attempt to use an overloaded operator on the arguments.

   For unary operators, only the first argument need be checked.
   For binary operators, both arguments may need to be checked.

   Member functions can convert class references to class pointers,
   for one-level deep indirection.  More than that is not supported.
   Operators [](), ()(), and ->() must be member functions.

   We call function call building calls with LOOKUP_COMPLAIN if they
   are our only hope.  This is true when we see a vanilla operator
   applied to something of aggregate type.  If this fails, we are free
   to return `error_mark_node', because we will have reported the
   error.

   Operators NEW and DELETE overload in funny ways: operator new takes
   a single `size' parameter, and operator delete takes a pointer to the
   storage being deleted.  When overloading these operators, success is
   assumed.  If there is a failure, report an error message and return
   `error_mark_node'.  */

/* NOSTRICT */
tree
build_opfncall (code, flags, xarg1, xarg2, arg3)
     enum tree_code code;
     int flags;
     tree xarg1, xarg2, arg3;
{
  return build_new_op (code, flags, xarg1, xarg2, arg3);
}

/* This function takes an identifier, ID, and attempts to figure out what
   it means. There are a number of possible scenarios, presented in increasing
   order of hair:

   1) not in a class's scope
   2) in class's scope, member name of the class's method
   3) in class's scope, but not a member name of the class
   4) in class's scope, member name of a class's variable

   NAME is $1 from the bison rule. It is an IDENTIFIER_NODE.
   VALUE is $$ from the bison rule. It is the value returned by lookup_name ($1)

   As a last ditch, try to look up the name as a label and return that
   address.

   Values which are declared as being of REFERENCE_TYPE are
   automatically dereferenced here (as a hack to make the
   compiler faster).  */

tree
hack_identifier (value, name)
     tree value, name;
{
  tree type;

  if (value == error_mark_node)
    {
      if (current_class_name)
	{
	  tree fields = lookup_fnfields (TYPE_BINFO (current_class_type), name, 1);
	  if (fields == error_mark_node)
	    return error_mark_node;
	  if (fields)
	    {
	      tree fndecl;

	      fndecl = TREE_VALUE (fields);
	      my_friendly_assert (TREE_CODE (fndecl) == FUNCTION_DECL, 251);
	      /* I could not trigger this code. MvL */
	      my_friendly_abort (980325);
#ifdef DEAD
	      if (DECL_CHAIN (fndecl) == NULL_TREE)
		{
		  warning ("methods cannot be converted to function pointers");
		  return fndecl;
		}
	      else
		{
		  error ("ambiguous request for method pointer `%s'",
			 IDENTIFIER_POINTER (name));
		  return error_mark_node;
		}
#endif
	    }
	}
      if (flag_labels_ok && IDENTIFIER_LABEL_VALUE (name))
	{
	  return IDENTIFIER_LABEL_VALUE (name);
	}
      return error_mark_node;
    }

  type = TREE_TYPE (value);
  if (TREE_CODE (value) == FIELD_DECL)
    {
      if (current_class_ptr == NULL_TREE)
	{
	  error ("request for member `%s' in static member function",
		 IDENTIFIER_POINTER (DECL_NAME (value)));
	  return error_mark_node;
	}
      TREE_USED (current_class_ptr) = 1;

      /* Mark so that if we are in a constructor, and then find that
	 this field was initialized by a base initializer,
	 we can emit an error message.  */
      TREE_USED (value) = 1;
      value = build_component_ref (current_class_ref, name, NULL_TREE, 1);
    }
  else if (really_overloaded_fn (value))
    {
#if 0
      tree t = get_first_fn (value);
      for (; t; t = DECL_CHAIN (t))
	{
	  if (TREE_CODE (t) == TEMPLATE_DECL)
	    continue;

	  assemble_external (t);
	  TREE_USED (t) = 1;
	}
#endif
    }
  else if (TREE_CODE (value) == OVERLOAD)
    /* not really overloaded function */
    mark_used (OVL_FUNCTION (value));
  else if (TREE_CODE (value) == TREE_LIST)
    {
      /* Ambiguous reference to base members, possibly other cases?.  */
      tree t = value;
      while (t && TREE_CODE (t) == TREE_LIST)
	{
	  mark_used (TREE_VALUE (t));
	  t = TREE_CHAIN (t);
	}
    }
  else if (TREE_CODE (value) == NAMESPACE_DECL)
    {
      cp_error ("use of namespace `%D' as expression", value);
      return error_mark_node;
    }
  else if (DECL_CLASS_TEMPLATE_P (value))
    {
      cp_error ("use of class template `%T' as expression", value);
      return error_mark_node;
    }
  else
    mark_used (value);

  if (TREE_CODE (value) == VAR_DECL || TREE_CODE (value) == PARM_DECL)
    {
      tree context = decl_function_context (value);
      if (context != NULL_TREE && context != current_function_decl
	  && ! TREE_STATIC (value))
	{
	  cp_error ("use of %s from containing function",
		      (TREE_CODE (value) == VAR_DECL
		       ? "`auto' variable" : "parameter"));
	  cp_error_at ("  `%#D' declared here", value);
	  value = error_mark_node;
	}
    }

  if (TREE_CODE_CLASS (TREE_CODE (value)) == 'd' && DECL_NONLOCAL (value))
    {
      if (DECL_LANG_SPECIFIC (value)
	  && DECL_CLASS_CONTEXT (value) != current_class_type)
	{
	  tree path, access;
	  register tree context
	    = (TREE_CODE (value) == FUNCTION_DECL && DECL_VIRTUAL_P (value))
	      ? DECL_CLASS_CONTEXT (value)
	      : DECL_CONTEXT (value);

	  get_base_distance (context, current_class_type, 0, &path);
	  if (path)
	    {
	      access = compute_access (path, value);
	      if (access != access_public_node)
		{
		  if (TREE_CODE (value) == VAR_DECL)
		    error ("static member `%s' is %s",
			   IDENTIFIER_POINTER (name),
			   TREE_PRIVATE (value) ? "private"
						: "from a private base class");
		  else
		    error ("enum `%s' is from private base class",
			   IDENTIFIER_POINTER (name));
		  return error_mark_node;
		}
	    }
	}
    }
  else if (TREE_CODE (value) == TREE_LIST && TREE_NONLOCAL_FLAG (value))
    {
      if (type == 0)
	{
	  error ("request for member `%s' is ambiguous in multiple inheritance lattice",
		 IDENTIFIER_POINTER (name));
	  return error_mark_node;
	}

      return value;
    }

  if (TREE_CODE (type) == REFERENCE_TYPE && ! processing_template_decl)
    value = convert_from_reference (value);
  return value;
}


tree
make_thunk (function, delta)
     tree function;
     int delta;
{
  tree thunk_id;
  tree thunk;
  tree func_decl;

  if (TREE_CODE (function) != ADDR_EXPR)
    abort ();
  func_decl = TREE_OPERAND (function, 0);
  if (TREE_CODE (func_decl) != FUNCTION_DECL)
    abort ();

  OB_INIT ();
  OB_PUTS ("__thunk_");
  if (delta > 0)
    {
      OB_PUTC ('n');
      icat (delta);
    }
  else
    icat (-delta);
  OB_PUTC ('_');
  OB_PUTID (DECL_ASSEMBLER_NAME (func_decl));
  OB_FINISH ();
  thunk_id = get_identifier (obstack_base (&scratch_obstack));

  thunk = IDENTIFIER_GLOBAL_VALUE (thunk_id);
  if (thunk && TREE_CODE (thunk) != THUNK_DECL)
    {
      cp_error ("implementation-reserved name `%D' used", thunk_id);
      thunk = NULL_TREE;
      SET_IDENTIFIER_GLOBAL_VALUE (thunk_id, thunk);
    }
  if (thunk == NULL_TREE)
    {
      thunk = build_decl (FUNCTION_DECL, thunk_id, TREE_TYPE (func_decl));
      TREE_READONLY (thunk) = TREE_READONLY (func_decl);
      TREE_THIS_VOLATILE (thunk) = TREE_THIS_VOLATILE (func_decl);
      comdat_linkage (thunk);
      TREE_SET_CODE (thunk, THUNK_DECL);
      DECL_INITIAL (thunk) = function;
      THUNK_DELTA (thunk) = delta;
      DECL_EXTERNAL (thunk) = 1;
      DECL_ARTIFICIAL (thunk) = 1;
      /* So that finish_file can write out any thunks that need to be: */
      pushdecl_top_level (thunk);
    }
  return thunk;
}

/* Emit the definition of a C++ multiple inheritance vtable thunk.  */

void
emit_thunk (thunk_fndecl)
     tree thunk_fndecl;
{
  tree function = TREE_OPERAND (DECL_INITIAL (thunk_fndecl), 0);
  int delta = THUNK_DELTA (thunk_fndecl);

  if (TREE_ASM_WRITTEN (thunk_fndecl))
    return;

  TREE_ASM_WRITTEN (thunk_fndecl) = 1;

  TREE_ADDRESSABLE (function) = 1;
  mark_used (function);

  if (current_function_decl)
    abort ();

  TREE_SET_CODE (thunk_fndecl, FUNCTION_DECL);

  {
#ifdef ASM_OUTPUT_MI_THUNK
    char *fnname;
    current_function_decl = thunk_fndecl;
    /* Make sure we build up its RTL before we go onto the
       temporary obstack.  */
    make_function_rtl (thunk_fndecl);
    temporary_allocation ();
    DECL_RESULT (thunk_fndecl)
      = build_decl (RESULT_DECL, 0, integer_type_node);
    fnname = XSTR (XEXP (DECL_RTL (thunk_fndecl), 0), 0);
    init_function_start (thunk_fndecl, input_filename, lineno);
    current_function_is_thunk = 1;
    assemble_start_function (thunk_fndecl, fnname);
    ASM_OUTPUT_MI_THUNK (asm_out_file, thunk_fndecl, delta, function);
    assemble_end_function (thunk_fndecl, fnname);
    permanent_allocation (1);
    current_function_decl = 0;
#else /* ASM_OUTPUT_MI_THUNK */
  /* If we don't have the necessary macro for efficient thunks, generate a
     thunk function that just makes a call to the real function.
     Unfortunately, this doesn't work for varargs.  */

    tree a, t;

    if (varargs_function_p (function))
      cp_error ("generic thunk code fails for method `%#D' which uses `...'",
		function);

    /* Set up clone argument trees for the thunk.  */
    t = NULL_TREE;
    for (a = DECL_ARGUMENTS (function); a; a = TREE_CHAIN (a))
      {
	tree x = copy_node (a);
	TREE_CHAIN (x) = t;
	DECL_CONTEXT (x) = thunk_fndecl;
	t = x;
      }
    a = nreverse (t);
    DECL_ARGUMENTS (thunk_fndecl) = a;
    DECL_RESULT (thunk_fndecl) = NULL_TREE;
    DECL_LANG_SPECIFIC (thunk_fndecl) = DECL_LANG_SPECIFIC (function);
    copy_lang_decl (thunk_fndecl);
    DECL_INTERFACE_KNOWN (thunk_fndecl) = 1;
    DECL_NOT_REALLY_EXTERN (thunk_fndecl) = 1;

    start_function (NULL_TREE, thunk_fndecl, NULL_TREE, 1);
    store_parm_decls ();
    current_function_is_thunk = 1;

    /* Build up the call to the real function.  */
    t = build_int_2 (delta, -1 * (delta < 0));
    TREE_TYPE (t) = signed_type (sizetype);
    t = fold (build (PLUS_EXPR, TREE_TYPE (a), a, t));
    t = expr_tree_cons (NULL_TREE, t, NULL_TREE);
    for (a = TREE_CHAIN (a); a; a = TREE_CHAIN (a))
      t = expr_tree_cons (NULL_TREE, a, t);
    t = nreverse (t);
    t = build_call (function, TREE_TYPE (TREE_TYPE (function)), t);
    c_expand_return (t);

    finish_function (lineno, 0, 0);

    /* Don't let the backend defer this function.  */
    if (DECL_DEFER_OUTPUT (thunk_fndecl))
      {
	output_inline_function (thunk_fndecl);
	permanent_allocation (1);
      }
#endif /* ASM_OUTPUT_MI_THUNK */
  }

  TREE_SET_CODE (thunk_fndecl, THUNK_DECL);
}

/* Code for synthesizing methods which have default semantics defined.  */

/* For the anonymous union in TYPE, return the member that is at least as
   large as the rest of the members, so we can copy it.  */

static tree
largest_union_member (type)
     tree type;
{
  tree f, type_size = TYPE_SIZE (type);

  for (f = TYPE_FIELDS (type); f; f = TREE_CHAIN (f))
    if (simple_cst_equal (DECL_SIZE (f), type_size) == 1)
      return f;

  /* We should always find one.  */
  my_friendly_abort (323);
  return NULL_TREE;
}

/* Generate code for default X(X&) constructor.  */

static void
do_build_copy_constructor (fndecl)
     tree fndecl;
{
  tree parm = TREE_CHAIN (DECL_ARGUMENTS (fndecl));
  tree t;

  clear_last_expr ();
  push_momentary ();

  if (TYPE_USES_VIRTUAL_BASECLASSES (current_class_type))
    parm = TREE_CHAIN (parm);
  parm = convert_from_reference (parm);

  if (TYPE_HAS_TRIVIAL_INIT_REF (current_class_type)
      && is_empty_class (current_class_type))
    /* Don't copy the padding byte; it might not have been allocated
       if *this is a base subobject.  */;
  else if (TYPE_HAS_TRIVIAL_INIT_REF (current_class_type))
    {
      t = build (INIT_EXPR, void_type_node, current_class_ref, parm);
      TREE_SIDE_EFFECTS (t) = 1;
      cplus_expand_expr_stmt (t);
    }
  else
    {
      tree fields = TYPE_FIELDS (current_class_type);
      int n_bases = CLASSTYPE_N_BASECLASSES (current_class_type);
      tree binfos = TYPE_BINFO_BASETYPES (current_class_type);
      int i;

      for (t = CLASSTYPE_VBASECLASSES (current_class_type); t;
	   t = TREE_CHAIN (t))
	{
	  tree basetype = BINFO_TYPE (t);
	  tree p = convert_to_reference
	    (build_reference_type (basetype), parm,
	     CONV_IMPLICIT|CONV_CONST, LOOKUP_COMPLAIN, NULL_TREE);
	  p = convert_from_reference (p);

	  if (p == error_mark_node)
	    cp_error ("in default copy constructor");
	  else 
	    current_base_init_list = tree_cons (basetype,
						p, current_base_init_list);
	}
	
      for (i = 0; i < n_bases; ++i)
	{
	  tree p, basetype = TREE_VEC_ELT (binfos, i);
	  if (TREE_VIA_VIRTUAL (basetype))
	    continue; 

	  basetype = BINFO_TYPE (basetype);
	  p = convert_to_reference
	    (build_reference_type (basetype), parm,
	     CONV_IMPLICIT|CONV_CONST, LOOKUP_COMPLAIN, NULL_TREE);

	  if (p == error_mark_node) 
	    cp_error ("in default copy constructor");
	  else 
	    {
	      p = convert_from_reference (p);
	      current_base_init_list = tree_cons (basetype,
						  p, current_base_init_list);
	    }
	}
      for (; fields; fields = TREE_CHAIN (fields))
	{
	  tree init, t;
	  tree field = fields;

	  if (TREE_CODE (field) != FIELD_DECL)
	    continue;

	  init = parm;
	  if (DECL_NAME (field))
	    {
	      if (VFIELD_NAME_P (DECL_NAME (field)))
		continue;
	      if (VBASE_NAME_P (DECL_NAME (field)))
		continue;

	      /* True for duplicate members.  */
	      if (IDENTIFIER_CLASS_VALUE (DECL_NAME (field)) != field)
		continue;
	    }
	  else if ((t = TREE_TYPE (field)) != NULL_TREE
		   && ANON_UNION_TYPE_P (t)
		   && TYPE_FIELDS (t) != NULL_TREE)
	    {
	      do
		{
		  init = build (COMPONENT_REF, t, init, field);
		  field = largest_union_member (t);
		}
	      while ((t = TREE_TYPE (field)) != NULL_TREE
		     && ANON_UNION_TYPE_P (t)
		     && TYPE_FIELDS (t) != NULL_TREE);
	    }
	  else
	    continue;

	  init = build (COMPONENT_REF, TREE_TYPE (field), init, field);
	  init = build_tree_list (NULL_TREE, init);

	  current_member_init_list
	    = tree_cons (DECL_NAME (field), init, current_member_init_list);
	}
      current_member_init_list = nreverse (current_member_init_list);
      current_base_init_list = nreverse (current_base_init_list);
      setup_vtbl_ptr ();
    }

  pop_momentary ();
}

static void
do_build_assign_ref (fndecl)
     tree fndecl;
{
  tree parm = TREE_CHAIN (DECL_ARGUMENTS (fndecl));

  clear_last_expr ();
  push_momentary ();

  parm = convert_from_reference (parm);

  if (TYPE_HAS_TRIVIAL_ASSIGN_REF (current_class_type)
      && is_empty_class (current_class_type))
    /* Don't copy the padding byte; it might not have been allocated
       if *this is a base subobject.  */;
  else if (TYPE_HAS_TRIVIAL_ASSIGN_REF (current_class_type))
    {
      tree t = build (MODIFY_EXPR, void_type_node, current_class_ref, parm);
      TREE_SIDE_EFFECTS (t) = 1;
      cplus_expand_expr_stmt (t);
    }
  else
    {
      tree fields = TYPE_FIELDS (current_class_type);
      int n_bases = CLASSTYPE_N_BASECLASSES (current_class_type);
      tree binfos = TYPE_BINFO_BASETYPES (current_class_type);
      int i;

      for (i = 0; i < n_bases; ++i)
	{
	  tree basetype = BINFO_TYPE (TREE_VEC_ELT (binfos, i));
	  tree p = convert_to_reference
	    (build_reference_type (basetype), parm,
	     CONV_IMPLICIT|CONV_CONST, LOOKUP_COMPLAIN, NULL_TREE);
	  p = convert_from_reference (p);
	  p = build_member_call (basetype, ansi_opname [MODIFY_EXPR],
				 build_expr_list (NULL_TREE, p));
	  expand_expr_stmt (p);
	}
      for (; fields; fields = TREE_CHAIN (fields))
	{
	  tree comp, init, t;
	  tree field = fields;

	  if (TREE_CODE (field) != FIELD_DECL)
	    continue;

	  if (TREE_READONLY (field))
	    {
	      if (DECL_NAME (field))
		cp_error ("non-static const member `%#D', can't use default assignment operator", field);
	      else
		cp_error ("non-static const member in type `%T', can't use default assignment operator", current_class_type);
	      continue;
	    }
	  else if (TREE_CODE (TREE_TYPE (field)) == REFERENCE_TYPE)
	    {
	      if (DECL_NAME (field))
		cp_error ("non-static reference member `%#D', can't use default assignment operator", field);
	      else
		cp_error ("non-static reference member in type `%T', can't use default assignment operator", current_class_type);
	      continue;
	    }

	  comp = current_class_ref;
	  init = parm;

	  if (DECL_NAME (field))
	    {
	      if (VFIELD_NAME_P (DECL_NAME (field)))
		continue;
	      if (VBASE_NAME_P (DECL_NAME (field)))
		continue;

	      /* True for duplicate members.  */
	      if (IDENTIFIER_CLASS_VALUE (DECL_NAME (field)) != field)
		continue;
	    }
	  else if ((t = TREE_TYPE (field)) != NULL_TREE
		   && ANON_UNION_TYPE_P (t)
		   && TYPE_FIELDS (t) != NULL_TREE)
	    {
	      do
		{
		  comp = build (COMPONENT_REF, t, comp, field);
		  init = build (COMPONENT_REF, t, init, field);
		  field = largest_union_member (t);
		}
	      while ((t = TREE_TYPE (field)) != NULL_TREE
		     && ANON_UNION_TYPE_P (t)
		     && TYPE_FIELDS (t) != NULL_TREE);
	    }
	  else
	    continue;

	  comp = build (COMPONENT_REF, TREE_TYPE (field), comp, field);
	  init = build (COMPONENT_REF, TREE_TYPE (field), init, field);

	  expand_expr_stmt (build_modify_expr (comp, NOP_EXPR, init));
	}
    }
  c_expand_return (current_class_ref);
  pop_momentary ();
}

void
synthesize_method (fndecl)
     tree fndecl;
{
  int nested = (current_function_decl != NULL_TREE);
  tree context = hack_decl_function_context (fndecl);

  if (at_eof)
    import_export_decl (fndecl);

  if (! context)
    push_to_top_level ();
  else if (nested)
    push_cp_function_context (context);

  interface_unknown = 1;
  start_function (NULL_TREE, fndecl, NULL_TREE, 1);
  store_parm_decls ();

  if (DECL_NAME (fndecl) == ansi_opname[MODIFY_EXPR])
    do_build_assign_ref (fndecl);
  else if (DESTRUCTOR_NAME_P (DECL_ASSEMBLER_NAME (fndecl)))
    ;
  else
    {
      tree arg_chain = FUNCTION_ARG_CHAIN (fndecl);
      if (DECL_CONSTRUCTOR_FOR_VBASE_P (fndecl))
	arg_chain = TREE_CHAIN (arg_chain);
      if (arg_chain != void_list_node)
	do_build_copy_constructor (fndecl);
      else if (TYPE_NEEDS_CONSTRUCTING (current_class_type))
	setup_vtbl_ptr ();
    }

  finish_function (lineno, 0, nested);

  extract_interface_info ();
  if (! context)
    pop_from_top_level ();
  else if (nested)
    pop_cp_function_context (context);
}
