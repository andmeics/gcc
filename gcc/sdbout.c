/* Output sdb-format symbol table information from GNU compiler.
   Copyright (C) 1988, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,
   2000, 2001, 2002 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  */

/*  mike@tredysvr.Tredydev.Unisys.COM says:
I modified the struct.c example and have a nm of a .o resulting from the
AT&T C compiler.  From the example below I would conclude the following:

1. All .defs from structures are emitted as scanned.  The example below
   clearly shows the symbol table entries for BoxRec2 are after the first
   function.

2. All functions and their locals (including statics) are emitted as scanned.

3. All nested unnamed union and structure .defs must be emitted before
   the structure in which they are nested.  The AT&T assembler is a
   one pass beast as far as symbolics are concerned.

4. All structure .defs are emitted before the typedefs that refer to them.

5. All top level static and external variable definitions are moved to the
   end of file with all top level statics occurring first before externs.

6. All undefined references are at the end of the file.
*/

#include "config.h"

#ifdef SDB_DEBUGGING_INFO

#include "system.h"
#include "tree.h"
#include "rtl.h"
#include "regs.h"
#include "flags.h"
#include "insn-config.h"
#include "reload.h"
#include "output.h"
#include "toplev.h"
#include "ggc.h"
#include "tm_p.h"
#include "gsyms.h"
#include "debug.h"
#include "langhooks.h"

/* 1 if PARM is passed to this function in memory.  */

#define PARM_PASSED_IN_MEMORY(PARM) \
 (GET_CODE (DECL_INCOMING_RTL (PARM)) == MEM)

/* A C expression for the integer offset value of an automatic variable
   (C_AUTO) having address X (an RTX).  */
#ifndef DEBUGGER_AUTO_OFFSET
#define DEBUGGER_AUTO_OFFSET(X) \
  (GET_CODE (X) == PLUS ? INTVAL (XEXP (X, 1)) : 0)
#endif

/* A C expression for the integer offset value of an argument (C_ARG)
   having address X (an RTX).  The nominal offset is OFFSET.  */
#ifndef DEBUGGER_ARG_OFFSET
#define DEBUGGER_ARG_OFFSET(OFFSET, X) (OFFSET)
#endif

/* Line number of beginning of current function, minus one.
   Negative means not in a function or not using sdb.  */

int sdb_begin_function_line = -1;

/* Counter to generate unique "names" for nameless struct members.  */

static int unnamed_struct_number = 0;

extern FILE *asm_out_file;

extern tree current_function_decl;

#include "sdbout.h"

static void sdbout_init			PARAMS ((const char *));
static void sdbout_finish		PARAMS ((const char *));
static void sdbout_start_source_file	PARAMS ((unsigned int, const char *));
static void sdbout_end_source_file	PARAMS ((unsigned int));
static void sdbout_begin_block		PARAMS ((unsigned int, unsigned int));
static void sdbout_end_block		PARAMS ((unsigned int, unsigned int));
static void sdbout_source_line		PARAMS ((unsigned int, const char *));
static void sdbout_end_epilogue		PARAMS ((void));
static void sdbout_global_decl		PARAMS ((tree));
#ifndef MIPS_DEBUGGING_INFO
static void sdbout_begin_prologue	PARAMS ((unsigned int, const char *));
#endif
static void sdbout_end_prologue		PARAMS ((unsigned int));
static void sdbout_begin_function	PARAMS ((tree));
static void sdbout_end_function		PARAMS ((unsigned int));
static void sdbout_toplevel_data	PARAMS ((tree));
static void sdbout_label		PARAMS ((rtx));
static char *gen_fake_label		PARAMS ((void));
static int plain_type			PARAMS ((tree));
static int template_name_p		PARAMS ((tree));
static void sdbout_record_type_name	PARAMS ((tree));
static int plain_type_1			PARAMS ((tree, int));
static void sdbout_block		PARAMS ((tree));
static void sdbout_syms			PARAMS ((tree));
#ifdef SDB_ALLOW_FORWARD_REFERENCES
static void sdbout_queue_anonymous_type	PARAMS ((tree));
static void sdbout_dequeue_anonymous_types PARAMS ((void));
#endif
static void sdbout_type			PARAMS ((tree));
static void sdbout_field_types		PARAMS ((tree));
static void sdbout_one_type		PARAMS ((tree));
static void sdbout_parms		PARAMS ((tree));
static void sdbout_reg_parms		PARAMS ((tree));
static void sdbout_global_decl		PARAMS ((tree));

/* Random macros describing parts of SDB data.  */

/* Put something here if lines get too long */
#define CONTIN

/* Default value of delimiter is ";".  */
#ifndef SDB_DELIM
#define SDB_DELIM	";"
#endif

/* Maximum number of dimensions the assembler will allow.  */
#ifndef SDB_MAX_DIM
#define SDB_MAX_DIM 4
#endif

#ifndef PUT_SDB_SCL
#define PUT_SDB_SCL(a) fprintf(asm_out_file, "\t.scl\t%d%s", (a), SDB_DELIM)
#endif

#ifndef PUT_SDB_INT_VAL
#define PUT_SDB_INT_VAL(a) \
 do {									\
   fputs ("\t.val\t", asm_out_file);		       			\
   fprintf (asm_out_file, HOST_WIDE_INT_PRINT_DEC, (HOST_WIDE_INT) (a)); \
   fprintf (asm_out_file, "%s", SDB_DELIM);				\
 } while (0)

#endif

#ifndef PUT_SDB_VAL
#define PUT_SDB_VAL(a)				\
( fputs ("\t.val\t", asm_out_file),		\
  output_addr_const (asm_out_file, (a)),	\
  fprintf (asm_out_file, SDB_DELIM))
#endif

#ifndef PUT_SDB_DEF
#define PUT_SDB_DEF(a)				\
do { fprintf (asm_out_file, "\t.def\t");	\
     assemble_name (asm_out_file, a); 	\
     fprintf (asm_out_file, SDB_DELIM); } while (0)
#endif

#ifndef PUT_SDB_PLAIN_DEF
#define PUT_SDB_PLAIN_DEF(a) fprintf(asm_out_file,"\t.def\t.%s%s",a, SDB_DELIM)
#endif

#ifndef PUT_SDB_ENDEF
#define PUT_SDB_ENDEF fputs("\t.endef\n", asm_out_file)
#endif

#ifndef PUT_SDB_TYPE
#define PUT_SDB_TYPE(a) fprintf(asm_out_file, "\t.type\t0%o%s", a, SDB_DELIM)
#endif

#ifndef PUT_SDB_SIZE
#define PUT_SDB_SIZE(a) \
 do {									\
   fputs ("\t.size\t", asm_out_file);					\
   fprintf (asm_out_file, HOST_WIDE_INT_PRINT_DEC, (HOST_WIDE_INT) (a)); \
   fprintf (asm_out_file, "%s", SDB_DELIM);				\
 } while(0)
#endif

#ifndef PUT_SDB_START_DIM
#define PUT_SDB_START_DIM fprintf(asm_out_file, "\t.dim\t")
#endif

#ifndef PUT_SDB_NEXT_DIM
#define PUT_SDB_NEXT_DIM(a) fprintf(asm_out_file, "%d,", a)
#endif

#ifndef PUT_SDB_LAST_DIM
#define PUT_SDB_LAST_DIM(a) fprintf(asm_out_file, "%d%s", a, SDB_DELIM)
#endif

#ifndef PUT_SDB_TAG
#define PUT_SDB_TAG(a)				\
do { fprintf (asm_out_file, "\t.tag\t");	\
     assemble_name (asm_out_file, a);	\
     fprintf (asm_out_file, SDB_DELIM); } while (0)
#endif

#ifndef PUT_SDB_BLOCK_START
#define PUT_SDB_BLOCK_START(LINE)		\
  fprintf (asm_out_file,			\
	   "\t.def\t.bb%s\t.val\t.%s\t.scl\t100%s\t.line\t%d%s\t.endef\n", \
	   SDB_DELIM, SDB_DELIM, SDB_DELIM, (LINE), SDB_DELIM)
#endif

#ifndef PUT_SDB_BLOCK_END
#define PUT_SDB_BLOCK_END(LINE)			\
  fprintf (asm_out_file,			\
	   "\t.def\t.eb%s\t.val\t.%s\t.scl\t100%s\t.line\t%d%s\t.endef\n",  \
	   SDB_DELIM, SDB_DELIM, SDB_DELIM, (LINE), SDB_DELIM)
#endif

#ifndef PUT_SDB_FUNCTION_START
#define PUT_SDB_FUNCTION_START(LINE)		\
  fprintf (asm_out_file,			\
	   "\t.def\t.bf%s\t.val\t.%s\t.scl\t101%s\t.line\t%d%s\t.endef\n", \
	   SDB_DELIM, SDB_DELIM, SDB_DELIM, (LINE), SDB_DELIM)
#endif

#ifndef PUT_SDB_FUNCTION_END
#define PUT_SDB_FUNCTION_END(LINE)		\
  fprintf (asm_out_file,			\
	   "\t.def\t.ef%s\t.val\t.%s\t.scl\t101%s\t.line\t%d%s\t.endef\n", \
	   SDB_DELIM, SDB_DELIM, SDB_DELIM, (LINE), SDB_DELIM)
#endif

#ifndef SDB_GENERATE_FAKE
#define SDB_GENERATE_FAKE(BUFFER, NUMBER) \
  sprintf ((BUFFER), ".%dfake", (NUMBER));
#endif

/* Return the sdb tag identifier string for TYPE
   if TYPE has already been defined; otherwise return a null pointer.  */

#define KNOWN_TYPE_TAG(type)  TYPE_SYMTAB_POINTER (type)

/* Set the sdb tag identifier string for TYPE to NAME.  */

#define SET_KNOWN_TYPE_TAG(TYPE, NAME) \
  TYPE_SYMTAB_POINTER (TYPE) = (NAME)

/* Return the name (a string) of the struct, union or enum tag
   described by the TREE_LIST node LINK.  This is 0 for an anonymous one.  */

#define TAG_NAME(link) \
  (((link) && TREE_PURPOSE ((link)) \
    && IDENTIFIER_POINTER (TREE_PURPOSE ((link)))) \
   ? IDENTIFIER_POINTER (TREE_PURPOSE ((link))) : (char *) 0)

/* Ensure we don't output a negative line number.  */
#define MAKE_LINE_SAFE(line)  \
  if ((int) line <= sdb_begin_function_line) \
    line = sdb_begin_function_line + 1

/* Perform linker optimization of merging header file definitions together
   for targets with MIPS_DEBUGGING_INFO defined.  This won't work without a
   post 960826 version of GAS.  Nothing breaks with earlier versions of GAS,
   the optimization just won't be done.  The native assembler already has the
   necessary support.  */

#ifdef MIPS_DEBUGGING_INFO

#ifndef PUT_SDB_SRC_FILE
#define PUT_SDB_SRC_FILE(FILENAME) \
output_file_directive (asm_out_file, (FILENAME))
#endif

/* ECOFF linkers have an optimization that does the same kind of thing as
   N_BINCL/E_INCL in stabs: eliminate duplicate debug information in the
   executable.  To achieve this, GCC must output a .file for each file
   name change.  */

/* This is a stack of input files.  */

struct sdb_file
{
  struct sdb_file *next;
  const char *name;
};

/* This is the top of the stack.  */

static struct sdb_file *current_file;

#endif /* MIPS_DEBUGGING_INFO */

/* The debug hooks structure.  */
const struct gcc_debug_hooks sdb_debug_hooks =
{
  sdbout_init,			/* init */
  sdbout_finish,		/* finish */
  debug_nothing_int_charstar,	/* define */
  debug_nothing_int_charstar,	/* undef */
  sdbout_start_source_file,	/* start_source_file */
  sdbout_end_source_file,	/* end_source_file */
  sdbout_begin_block,		/* begin_block */
  sdbout_end_block,		/* end_block */
  debug_true_tree,		/* ignore_block */
  sdbout_source_line,		/* source_line */
#ifdef MIPS_DEBUGGING_INFO
  /* Defer on MIPS systems so that parameter descriptions follow
     function entry.  */
  debug_nothing_int_charstar,	/* begin_prologue */
  sdbout_end_prologue,		/* end_prologue */
#else
  sdbout_begin_prologue,	/* begin_prologue */
  debug_nothing_int,		/* end_prologue */
#endif
  sdbout_end_epilogue,		/* end_epilogue */
  sdbout_begin_function,	/* begin_function */
  sdbout_end_function,		/* end_function */
  debug_nothing_tree,		/* function_decl */
  sdbout_global_decl,		/* global_decl */
  debug_nothing_tree,		/* deferred_inline_function */
  debug_nothing_tree,		/* outlining_inline_function */
  sdbout_label
};

#if 0

/* return the tag identifier for type
 */

char *
tag_of_ru_type (type,link)
     tree type,link;
{
  if (TYPE_SYMTAB_ADDRESS (type))
    return TYPE_SYMTAB_ADDRESS (type);
  if (link && TREE_PURPOSE (link)
      && IDENTIFIER_POINTER (TREE_PURPOSE (link)))
    TYPE_SYMTAB_ADDRESS (type) = IDENTIFIER_POINTER (TREE_PURPOSE (link));
  else
    return (char *) TYPE_SYMTAB_ADDRESS (type);
}
#endif

/* Return a unique string to name an anonymous type.  */

static char *
gen_fake_label ()
{
  char label[10];
  char *labelstr;
  SDB_GENERATE_FAKE (label, unnamed_struct_number);
  unnamed_struct_number++;
  labelstr = (char *) permalloc (strlen (label) + 1);
  strcpy (labelstr, label);
  return labelstr;
}

/* Return the number which describes TYPE for SDB.
   For pointers, etc., this function is recursive.
   Each record, union or enumeral type must already have had a
   tag number output.  */

/* The number is given by d6d5d4d3d2d1bbbb
   where bbbb is 4 bit basic type, and di indicate  one of notype,ptr,fn,array.
   Thus, char *foo () has bbbb=T_CHAR
			  d1=D_FCN
			  d2=D_PTR
 N_BTMASK=     017       1111     basic type field.
 N_TSHIFT=       2                derived type shift
 N_BTSHFT=       4                Basic type shift */

/* Produce the number that describes a pointer, function or array type.
   PREV is the number describing the target, value or element type.
   DT_type describes how to transform that type.  */
#define PUSH_DERIVED_LEVEL(DT_type,PREV)		\
  ((((PREV) & ~(int) N_BTMASK) << (int) N_TSHIFT)		\
   | ((int) DT_type << (int) N_BTSHFT)			\
   | ((PREV) & (int) N_BTMASK))

/* Number of elements used in sdb_dims.  */
static int sdb_n_dims = 0;

/* Table of array dimensions of current type.  */
static int sdb_dims[SDB_MAX_DIM];

/* Size of outermost array currently being processed.  */
static int sdb_type_size = -1;

static int
plain_type (type)
     tree type;
{
  int val = plain_type_1 (type, 0);

  /* If we have already saved up some array dimensions, print them now.  */
  if (sdb_n_dims > 0)
    {
      int i;
      PUT_SDB_START_DIM;
      for (i = sdb_n_dims - 1; i > 0; i--)
	PUT_SDB_NEXT_DIM (sdb_dims[i]);
      PUT_SDB_LAST_DIM (sdb_dims[0]);
      sdb_n_dims = 0;

      sdb_type_size = int_size_in_bytes (type);
      /* Don't kill sdb if type is not laid out or has variable size.  */
      if (sdb_type_size < 0)
	sdb_type_size = 0;
    }
  /* If we have computed the size of an array containing this type,
     print it now.  */
  if (sdb_type_size >= 0)
    {
      PUT_SDB_SIZE (sdb_type_size);
      sdb_type_size = -1;
    }
  return val;
}

static int
template_name_p (name)
     tree name;
{
  const char *ptr = IDENTIFIER_POINTER (name);
  while (*ptr && *ptr != '<')
    ptr++;

  return *ptr != '\0';
}

static void
sdbout_record_type_name (type)
     tree type;
{
  const char *name = 0;
  int no_name;

  if (KNOWN_TYPE_TAG (type))
    return;

  if (TYPE_NAME (type) != 0)
    {
      tree t = 0;

      /* Find the IDENTIFIER_NODE for the type name.  */
      if (TREE_CODE (TYPE_NAME (type)) == IDENTIFIER_NODE)
	t = TYPE_NAME (type);
      else if (TREE_CODE (TYPE_NAME (type)) == TYPE_DECL)
	{
	  t = DECL_NAME (TYPE_NAME (type));
	  /* The DECL_NAME for templates includes "<>", which breaks
	     most assemblers.  Use its assembler name instead, which
	     has been mangled into being safe.  */
	  if (t && template_name_p (t))
	    t = DECL_ASSEMBLER_NAME (TYPE_NAME (type));
	}

      /* Now get the name as a string, or invent one.  */
      if (t != NULL_TREE)
	name = IDENTIFIER_POINTER (t);
    }

  no_name = (name == 0 || *name == 0);
  if (no_name)
    name = gen_fake_label ();

  SET_KNOWN_TYPE_TAG (type, name);
#ifdef SDB_ALLOW_FORWARD_REFERENCES
  if (no_name)
    sdbout_queue_anonymous_type (type);
#endif
}

/* Return the .type value for type TYPE.

   LEVEL indicates how many levels deep we have recursed into the type.
   The SDB debug format can only represent 6 derived levels of types.
   After that, we must output inaccurate debug info.  We deliberately
   stop before the 7th level, so that ADA recursive types will not give an
   infinite loop.  */

static int
plain_type_1 (type, level)
     tree type;
     int level;
{
  if (type == 0)
    type = void_type_node;
  else if (type == error_mark_node)
    type = integer_type_node;
  else
    type = TYPE_MAIN_VARIANT (type);

  switch (TREE_CODE (type))
    {
    case VOID_TYPE:
      return T_VOID;
    case BOOLEAN_TYPE:
    case INTEGER_TYPE:
      {
	int size = int_size_in_bytes (type) * BITS_PER_UNIT;

	/* Carefully distinguish all the standard types of C,
	   without messing up if the language is not C.
	   Note that we check only for the names that contain spaces;
	   other names might occur by coincidence in other languages.  */
	if (TYPE_NAME (type) != 0
	    && TREE_CODE (TYPE_NAME (type)) == TYPE_DECL
	    && DECL_NAME (TYPE_NAME (type)) != 0
	    && TREE_CODE (DECL_NAME (TYPE_NAME (type))) == IDENTIFIER_NODE)
	  {
	    const char *const name
	      = IDENTIFIER_POINTER (DECL_NAME (TYPE_NAME (type)));

	    if (!strcmp (name, "char"))
	      return T_CHAR;
	    if (!strcmp (name, "unsigned char"))
	      return T_UCHAR;
	    if (!strcmp (name, "signed char"))
	      return T_CHAR;
	    if (!strcmp (name, "int"))
	      return T_INT;
	    if (!strcmp (name, "unsigned int"))
	      return T_UINT;
	    if (!strcmp (name, "short int"))
	      return T_SHORT;
	    if (!strcmp (name, "short unsigned int"))
	      return T_USHORT;
	    if (!strcmp (name, "long int"))
	      return T_LONG;
	    if (!strcmp (name, "long unsigned int"))
	      return T_ULONG;
	  }

	if (size == INT_TYPE_SIZE)
	  return (TREE_UNSIGNED (type) ? T_UINT : T_INT);
	if (size == CHAR_TYPE_SIZE)
	  return (TREE_UNSIGNED (type) ? T_UCHAR : T_CHAR);
	if (size == SHORT_TYPE_SIZE)
	  return (TREE_UNSIGNED (type) ? T_USHORT : T_SHORT);
	if (size == LONG_TYPE_SIZE)
	  return (TREE_UNSIGNED (type) ? T_ULONG : T_LONG);
	if (size == LONG_LONG_TYPE_SIZE)	/* better than nothing */
	  return (TREE_UNSIGNED (type) ? T_ULONG : T_LONG);
	return 0;
      }

    case REAL_TYPE:
      {
	int precision = TYPE_PRECISION (type);
	if (precision == FLOAT_TYPE_SIZE)
	  return T_FLOAT;
	if (precision == DOUBLE_TYPE_SIZE)
	  return T_DOUBLE;
#ifdef EXTENDED_SDB_BASIC_TYPES
	if (precision == LONG_DOUBLE_TYPE_SIZE)
	  return T_LNGDBL;
#else
	if (precision == LONG_DOUBLE_TYPE_SIZE)
	  return T_DOUBLE;	/* better than nothing */
#endif
	return 0;
      }

    case ARRAY_TYPE:
      {
	int m;
	if (level >= 6)
	  return T_VOID;
	else
	  m = plain_type_1 (TREE_TYPE (type), level+1);
	if (sdb_n_dims < SDB_MAX_DIM)
	  sdb_dims[sdb_n_dims++]
	    = (TYPE_DOMAIN (type)
	       && TYPE_MIN_VALUE (TYPE_DOMAIN (type)) != 0
	       && TYPE_MAX_VALUE (TYPE_DOMAIN (type)) != 0
	       && host_integerp (TYPE_MAX_VALUE (TYPE_DOMAIN (type)), 0)
	       && host_integerp (TYPE_MIN_VALUE (TYPE_DOMAIN (type)), 0)
	       ? (tree_low_cst (TYPE_MAX_VALUE (TYPE_DOMAIN (type)), 0)
		  - tree_low_cst (TYPE_MIN_VALUE (TYPE_DOMAIN (type)), 0) + 1)
	       : 0);

	return PUSH_DERIVED_LEVEL (DT_ARY, m);
      }

    case RECORD_TYPE:
    case UNION_TYPE:
    case QUAL_UNION_TYPE:
    case ENUMERAL_TYPE:
      {
	char *tag;
#ifdef SDB_ALLOW_FORWARD_REFERENCES
	sdbout_record_type_name (type);
#endif
#ifndef SDB_ALLOW_UNKNOWN_REFERENCES
	if ((TREE_ASM_WRITTEN (type) && KNOWN_TYPE_TAG (type) != 0)
#ifdef SDB_ALLOW_FORWARD_REFERENCES
	    || TYPE_MODE (type) != VOIDmode
#endif
	    )
#endif
	  {
	    /* Output the referenced structure tag name
	       only if the .def has already been finished.
	       At least on 386, the Unix assembler
	       cannot handle forward references to tags.  */
	    /* But the 88100, it requires them, sigh...  */
	    /* And the MIPS requires unknown refs as well...  */
	    tag = KNOWN_TYPE_TAG (type);
	    PUT_SDB_TAG (tag);
	    /* These 3 lines used to follow the close brace.
	       However, a size of 0 without a tag implies a tag of 0,
	       so if we don't know a tag, we can't mention the size.  */
	    sdb_type_size = int_size_in_bytes (type);
	    if (sdb_type_size < 0)
	      sdb_type_size = 0;
	  }
	return ((TREE_CODE (type) == RECORD_TYPE) ? T_STRUCT
		: (TREE_CODE (type) == UNION_TYPE) ? T_UNION
		: (TREE_CODE (type) == QUAL_UNION_TYPE) ? T_UNION
		: T_ENUM);
      }
    case POINTER_TYPE:
    case REFERENCE_TYPE:
      {
	int m;
	if (level >= 6)
	  return T_VOID;
	else
	  m = plain_type_1 (TREE_TYPE (type), level+1);
	return PUSH_DERIVED_LEVEL (DT_PTR, m);
      }
    case FUNCTION_TYPE:
    case METHOD_TYPE:
      {
	int m;
	if (level >= 6)
	  return T_VOID;
	else
	  m = plain_type_1 (TREE_TYPE (type), level+1);
	return PUSH_DERIVED_LEVEL (DT_FCN, m);
      }
    default:
      return 0;
    }
}

/* Output the symbols defined in block number DO_BLOCK.

   This function works by walking the tree structure of blocks,
   counting blocks until it finds the desired block.  */

static int do_block = 0;

static void
sdbout_block (block)
     tree block;
{
  while (block)
    {
      /* Ignore blocks never expanded or otherwise marked as real.  */
      if (TREE_USED (block))
	{
	  /* When we reach the specified block, output its symbols.  */
	  if (BLOCK_NUMBER (block) == do_block)
	    sdbout_syms (BLOCK_VARS (block));

	  /* If we are past the specified block, stop the scan.  */
	  if (BLOCK_NUMBER (block) > do_block)
	    return;

	  /* Scan the blocks within this block.  */
	  sdbout_block (BLOCK_SUBBLOCKS (block));
	}

      block = BLOCK_CHAIN (block);
    }
}

/* Call sdbout_symbol on each decl in the chain SYMS.  */

static void
sdbout_syms (syms)
     tree syms;
{
  while (syms)
    {
      if (TREE_CODE (syms) != LABEL_DECL)
	sdbout_symbol (syms, 1);
      syms = TREE_CHAIN (syms);
    }
}

/* Output SDB information for a symbol described by DECL.
   LOCAL is nonzero if the symbol is not file-scope.  */

void
sdbout_symbol (decl, local)
     tree decl;
     int local;
{
  tree type = TREE_TYPE (decl);
  tree context = NULL_TREE;
  rtx value;
  int regno = -1;
  const char *name;

  sdbout_one_type (type);

#if 0 /* This loses when functions are marked to be ignored,
	 which happens in the C++ front end.  */
  if (DECL_IGNORED_P (decl))
    return;
#endif

  switch (TREE_CODE (decl))
    {
    case CONST_DECL:
      /* Enum values are defined by defining the enum type.  */
      return;

    case FUNCTION_DECL:
      /* Don't mention a nested function under its parent.  */
      context = decl_function_context (decl);
      if (context == current_function_decl)
	return;
      /* Check DECL_INITIAL to distinguish declarations from definitions.
	 Don't output debug info here for declarations; they will have
	 a DECL_INITIAL value of 0.  */
      if (! DECL_INITIAL (decl))
	return;
      if (GET_CODE (DECL_RTL (decl)) != MEM
	  || GET_CODE (XEXP (DECL_RTL (decl), 0)) != SYMBOL_REF)
	return;
      PUT_SDB_DEF (IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (decl)));
      PUT_SDB_VAL (XEXP (DECL_RTL (decl), 0));
      PUT_SDB_SCL (TREE_PUBLIC (decl) ? C_EXT : C_STAT);
      break;

    case TYPE_DECL:
      /* Done with tagged types.  */
      if (DECL_NAME (decl) == 0)
	return;
      if (DECL_IGNORED_P (decl))
	return;

      /* Output typedef name.  */
      if (template_name_p (DECL_NAME (decl)))
	PUT_SDB_DEF (IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (decl)));
      else
	PUT_SDB_DEF (IDENTIFIER_POINTER (DECL_NAME (decl)));
      PUT_SDB_SCL (C_TPDEF);
      break;

    case PARM_DECL:
      /* Parm decls go in their own separate chains
	 and are output by sdbout_reg_parms and sdbout_parms.  */
      abort ();

    case VAR_DECL:
      /* Don't mention a variable that is external.
	 Let the file that defines it describe it.  */
      if (DECL_EXTERNAL (decl))
	return;

      /* Ignore __FUNCTION__, etc.  */
      if (DECL_IGNORED_P (decl))
	return;

      /* If there was an error in the declaration, don't dump core
	 if there is no RTL associated with the variable doesn't
	 exist.  */
      if (!DECL_RTL_SET_P (decl))
	return;

      SET_DECL_RTL (decl, 
		    eliminate_regs (DECL_RTL (decl), 0, NULL_RTX));
#ifdef LEAF_REG_REMAP
      if (current_function_uses_only_leaf_regs)
	leaf_renumber_regs_insn (DECL_RTL (decl));
#endif
      value = DECL_RTL (decl);

      /* Don't mention a variable at all
	 if it was completely optimized into nothingness.

	 If DECL was from an inline function, then its rtl
	 is not identically the rtl that was used in this
	 particular compilation.  */
      if (GET_CODE (value) == REG)
	{
	  regno = REGNO (value);
	  if (regno >= FIRST_PSEUDO_REGISTER)
	    return;
	}
      else if (GET_CODE (value) == SUBREG)
	{
	  while (GET_CODE (value) == SUBREG)
	    value = SUBREG_REG (value);
	  if (GET_CODE (value) == REG)
	    {
	      if (REGNO (value) >= FIRST_PSEUDO_REGISTER)
		return;
	    }
	  regno = REGNO (alter_subreg (&value));
	  SET_DECL_RTL (decl, value);
	}
      /* Don't output anything if an auto variable
	 gets RTL that is static.
	 GAS version 2.2 can't handle such output.  */
      else if (GET_CODE (value) == MEM && CONSTANT_P (XEXP (value, 0))
	       && ! TREE_STATIC (decl))
	return;

      /* Emit any structure, union, or enum type that has not been output.
	 This occurs for tag-less structs (et al) used to declare variables
	 within functions.  */
      if (TREE_CODE (type) == ENUMERAL_TYPE
	  || TREE_CODE (type) == RECORD_TYPE
	  || TREE_CODE (type) == UNION_TYPE
	  || TREE_CODE (type) == QUAL_UNION_TYPE)
	{
	  if (COMPLETE_TYPE_P (type)		/* not a forward reference */
	      && KNOWN_TYPE_TAG (type) == 0)	/* not yet declared */
	    sdbout_one_type (type);
	}

      /* Defer SDB information for top-level initialized variables! */
      if (! local
	  && GET_CODE (value) == MEM
	  && DECL_INITIAL (decl))
	return;

      /* C++ in 2.3 makes nameless symbols.  That will be fixed later.
	 For now, avoid crashing.  */
      if (DECL_NAME (decl) == NULL_TREE)
	return;

      /* Record the name for, starting a symtab entry.  */
      if (local)
	name = IDENTIFIER_POINTER (DECL_NAME (decl));
      else
	name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (decl));

      if (GET_CODE (value) == MEM
	  && GET_CODE (XEXP (value, 0)) == SYMBOL_REF)
	{
	  PUT_SDB_DEF (name);
	  if (TREE_PUBLIC (decl))
	    {
	      PUT_SDB_VAL (XEXP (value, 0));
              PUT_SDB_SCL (C_EXT);
	    }
	  else
	    {
	      PUT_SDB_VAL (XEXP (value, 0));
              PUT_SDB_SCL (C_STAT);
	    }
	}
      else if (regno >= 0)
	{
	  PUT_SDB_DEF (name);
	  PUT_SDB_INT_VAL (DBX_REGISTER_NUMBER (regno));
	  PUT_SDB_SCL (C_REG);
	}
      else if (GET_CODE (value) == MEM
	       && (GET_CODE (XEXP (value, 0)) == MEM
		   || (GET_CODE (XEXP (value, 0)) == REG
		       && REGNO (XEXP (value, 0)) != HARD_FRAME_POINTER_REGNUM
		       && REGNO (XEXP (value, 0)) != STACK_POINTER_REGNUM)))
	/* If the value is indirect by memory or by a register
	   that isn't the frame pointer
	   then it means the object is variable-sized and address through
	   that register or stack slot.  COFF has no way to represent this
	   so all we can do is output the variable as a pointer.  */
	{
	  PUT_SDB_DEF (name);
	  if (GET_CODE (XEXP (value, 0)) == REG)
	    {
	      PUT_SDB_INT_VAL (DBX_REGISTER_NUMBER (REGNO (XEXP (value, 0))));
	      PUT_SDB_SCL (C_REG);
	    }
	  else
	    {
	      /* DECL_RTL looks like (MEM (MEM (PLUS (REG...)
		 (CONST_INT...)))).
		 We want the value of that CONST_INT.  */
	      /* Encore compiler hates a newline in a macro arg, it seems.  */
	      PUT_SDB_INT_VAL (DEBUGGER_AUTO_OFFSET
			       (XEXP (XEXP (value, 0), 0)));
	      PUT_SDB_SCL (C_AUTO);
	    }

	  /* Effectively do build_pointer_type, but don't cache this type,
	     since it might be temporary whereas the type it points to
	     might have been saved for inlining.  */
	  /* Don't use REFERENCE_TYPE because dbx can't handle that.  */
	  type = make_node (POINTER_TYPE);
	  TREE_TYPE (type) = TREE_TYPE (decl);
	}
      else if (GET_CODE (value) == MEM
	       && ((GET_CODE (XEXP (value, 0)) == PLUS
		    && GET_CODE (XEXP (XEXP (value, 0), 0)) == REG
		    && GET_CODE (XEXP (XEXP (value, 0), 1)) == CONST_INT)
		   /* This is for variables which are at offset zero from
		      the frame pointer.  This happens on the Alpha.
		      Non-frame pointer registers are excluded above.  */
		   || (GET_CODE (XEXP (value, 0)) == REG)))
	{
	  /* DECL_RTL looks like (MEM (PLUS (REG...) (CONST_INT...)))
	     or (MEM (REG...)).  We want the value of that CONST_INT
	     or zero.  */
	  PUT_SDB_DEF (name);
	  PUT_SDB_INT_VAL (DEBUGGER_AUTO_OFFSET (XEXP (value, 0)));
	  PUT_SDB_SCL (C_AUTO);
	}
      else if (GET_CODE (value) == MEM && GET_CODE (XEXP (value, 0)) == CONST)
	{
	  /* Handle an obscure case which can arise when optimizing and
	     when there are few available registers.  (This is *always*
	     the case for i386/i486 targets).  The DECL_RTL looks like
	     (MEM (CONST ...)) even though this variable is a local `auto'
	     or a local `register' variable.  In effect, what has happened
	     is that the reload pass has seen that all assignments and
	     references for one such a local variable can be replaced by
	     equivalent assignments and references to some static storage
	     variable, thereby avoiding the need for a register.  In such
	     cases we're forced to lie to debuggers and tell them that
	     this variable was itself `static'.  */
	  PUT_SDB_DEF (name);
	  PUT_SDB_VAL (XEXP (XEXP (value, 0), 0));
	  PUT_SDB_SCL (C_STAT);
	}
      else
	{
	  /* It is something we don't know how to represent for SDB.  */
	  return;
	}
      break;

    default:
      break;
    }
  PUT_SDB_TYPE (plain_type (type));
  PUT_SDB_ENDEF;
}

/* Output SDB information for a top-level initialized variable
   that has been delayed.  */

static void
sdbout_toplevel_data (decl)
     tree decl;
{
  tree type = TREE_TYPE (decl);

  if (DECL_IGNORED_P (decl))
    return;

  if (! (TREE_CODE (decl) == VAR_DECL
	 && GET_CODE (DECL_RTL (decl)) == MEM
	 && DECL_INITIAL (decl)))
    abort ();

  PUT_SDB_DEF (IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (decl)));
  PUT_SDB_VAL (XEXP (DECL_RTL (decl), 0));
  if (TREE_PUBLIC (decl))
    {
      PUT_SDB_SCL (C_EXT);
    }
  else
    {
      PUT_SDB_SCL (C_STAT);
    }
  PUT_SDB_TYPE (plain_type (type));
  PUT_SDB_ENDEF;
}

#ifdef SDB_ALLOW_FORWARD_REFERENCES

/* Machinery to record and output anonymous types.  */

static tree anonymous_types;

static void
sdbout_queue_anonymous_type (type)
     tree type;
{
  anonymous_types = tree_cons (NULL_TREE, type, anonymous_types);
}

static void
sdbout_dequeue_anonymous_types ()
{
  tree types, link;

  while (anonymous_types)
    {
      types = nreverse (anonymous_types);
      anonymous_types = NULL_TREE;

      for (link = types; link; link = TREE_CHAIN (link))
	{
	  tree type = TREE_VALUE (link);

	  if (type && ! TREE_ASM_WRITTEN (type))
	    sdbout_one_type (type);
	}
    }
}

#endif

/* Given a chain of ..._TYPE nodes, all of which have names,
   output definitions of those names, as typedefs.  */

void
sdbout_types (types)
     tree types;
{
  tree link;

  for (link = types; link; link = TREE_CHAIN (link))
    sdbout_one_type (link);

#ifdef SDB_ALLOW_FORWARD_REFERENCES
  sdbout_dequeue_anonymous_types ();
#endif
}

static void
sdbout_type (type)
     tree type;
{
  if (type == error_mark_node)
    type = integer_type_node;
  PUT_SDB_TYPE (plain_type (type));
}

/* Output types of the fields of type TYPE, if they are structs.

   Formerly did not chase through pointer types, since that could be circular.
   They must come before TYPE, since forward refs are not allowed.
   Now james@bigtex.cactus.org says to try them.  */

static void
sdbout_field_types (type)
     tree type;
{
  tree tail;

  for (tail = TYPE_FIELDS (type); tail; tail = TREE_CHAIN (tail))
    /* This condition should match the one for emitting the actual
       members below.  */
    if (TREE_CODE (tail) == FIELD_DECL
	&& DECL_NAME (tail)
	&& DECL_SIZE (tail)
	&& host_integerp (DECL_SIZE (tail), 1)
	&& host_integerp (bit_position (tail), 0))
      {
	if (POINTER_TYPE_P (TREE_TYPE (tail)))
	  sdbout_one_type (TREE_TYPE (TREE_TYPE (tail)));
	else
	  sdbout_one_type (TREE_TYPE (tail));
      }
}

/* Use this to put out the top level defined record and union types
   for later reference.  If this is a struct with a name, then put that
   name out.  Other unnamed structs will have .xxfake labels generated so
   that they may be referred to later.
   The label will be stored in the KNOWN_TYPE_TAG slot of a type.
   It may NOT be called recursively.  */

static void
sdbout_one_type (type)
     tree type;
{
  if (current_function_decl != NULL_TREE
      && DECL_SECTION_NAME (current_function_decl) != NULL_TREE)
    ; /* Don't change section amid function.  */
  else
    text_section ();

  switch (TREE_CODE (type))
    {
    case RECORD_TYPE:
    case UNION_TYPE:
    case QUAL_UNION_TYPE:
    case ENUMERAL_TYPE:
      type = TYPE_MAIN_VARIANT (type);
      /* Don't output a type twice.  */
      if (TREE_ASM_WRITTEN (type))
	/* James said test TREE_ASM_BEING_WRITTEN here.  */
	return;

      /* Output nothing if type is not yet defined.  */
      if (!COMPLETE_TYPE_P (type))
	return;

      TREE_ASM_WRITTEN (type) = 1;
#if 1
      /* This is reputed to cause trouble with the following case,
	 but perhaps checking TYPE_SIZE above will fix it.  */

      /* Here is a test case:

	struct foo {
	  struct badstr *bbb;
	} forwardref;

	typedef struct intermediate {
	  int aaaa;
	} intermediate_ref;

	typedef struct badstr {
	  int ccccc;
	} badtype;   */

#if 0
      TREE_ASM_BEING_WRITTEN (type) = 1;
#endif
      /* This change, which ought to make better output,
	 used to make the COFF assembler unhappy.
	 Changes involving KNOWN_TYPE_TAG may fix the problem.  */
      /* Before really doing anything, output types we want to refer to.  */
      /* Note that in version 1 the following two lines
	 are not used if forward references are in use.  */
      if (TREE_CODE (type) != ENUMERAL_TYPE)
	sdbout_field_types (type);
#if 0
      TREE_ASM_WRITTEN (type) = 1;
#endif
#endif

      /* Output a structure type.  */
      {
	int size = int_size_in_bytes (type);
	int member_scl = 0;
	tree tem;
	int i, n_baseclasses = 0;

	/* Record the type tag, but not in its permanent place just yet.  */
	sdbout_record_type_name (type);

	PUT_SDB_DEF (KNOWN_TYPE_TAG (type));

	switch (TREE_CODE (type))
	  {
	  case UNION_TYPE:
	  case QUAL_UNION_TYPE:
	    PUT_SDB_SCL (C_UNTAG);
	    PUT_SDB_TYPE (T_UNION);
	    member_scl = C_MOU;
	    break;

	  case RECORD_TYPE:
	    PUT_SDB_SCL (C_STRTAG);
	    PUT_SDB_TYPE (T_STRUCT);
	    member_scl = C_MOS;
	    break;

	  case ENUMERAL_TYPE:
	    PUT_SDB_SCL (C_ENTAG);
	    PUT_SDB_TYPE (T_ENUM);
	    member_scl = C_MOE;
	    break;

	  default:
	    break;
	  }

	PUT_SDB_SIZE (size);
	PUT_SDB_ENDEF;

	/* Print out the base class information with fields
	   named after the types they hold.  */
	/* This is only relevant to aggregate types.  TYPE_BINFO is used
	   for other purposes in an ENUMERAL_TYPE, so we must exclude that
	   case.  */
	if (TREE_CODE (type) != ENUMERAL_TYPE)
	  {
	    if (TYPE_BINFO (type)
		&& TYPE_BINFO_BASETYPES (type))
	      n_baseclasses = TREE_VEC_LENGTH (TYPE_BINFO_BASETYPES (type));
	    for (i = 0; i < n_baseclasses; i++)
	      {
		tree child = TREE_VEC_ELT (BINFO_BASETYPES (TYPE_BINFO (type)),
					   i);
		tree child_type = BINFO_TYPE (child);
		tree child_type_name;
		if (TYPE_NAME (child_type) == 0)
		  continue;
		if (TREE_CODE (TYPE_NAME (child_type)) == IDENTIFIER_NODE)
		  child_type_name = TYPE_NAME (child_type);
		else if (TREE_CODE (TYPE_NAME (child_type)) == TYPE_DECL)
		  {
		    child_type_name = DECL_NAME (TYPE_NAME (child_type));
		    if (child_type_name && template_name_p (child_type_name))
		      child_type_name
			= DECL_ASSEMBLER_NAME (TYPE_NAME (child_type));
		  }
		else
		  continue;

		CONTIN;
		PUT_SDB_DEF (IDENTIFIER_POINTER (child_type_name));
		PUT_SDB_INT_VAL (tree_low_cst (BINFO_OFFSET (child), 0));
		PUT_SDB_SCL (member_scl);
		sdbout_type (BINFO_TYPE (child));
		PUT_SDB_ENDEF;
	      }
	  }

	/* output the individual fields */

	if (TREE_CODE (type) == ENUMERAL_TYPE)
	  {
	    for (tem = TYPE_FIELDS (type); tem; tem = TREE_CHAIN (tem))
	      if (host_integerp (TREE_VALUE (tem), 0))
		{
		  PUT_SDB_DEF (IDENTIFIER_POINTER (TREE_PURPOSE (tem)));
		  PUT_SDB_INT_VAL (tree_low_cst (TREE_VALUE (tem), 0));
		  PUT_SDB_SCL (C_MOE);
		  PUT_SDB_TYPE (T_MOE);
		  PUT_SDB_ENDEF;
		}
	  }
	else			/* record or union type */
	  for (tem = TYPE_FIELDS (type); tem; tem = TREE_CHAIN (tem))
	    /* Output the name, type, position (in bits), size (in bits)
	       of each field.  */

	    /* Omit here the nameless fields that are used to skip bits.
	       Also omit fields with variable size or position.
	       Also omit non FIELD_DECL nodes that GNU C++ may put here.  */
	    if (TREE_CODE (tem) == FIELD_DECL
		&& DECL_NAME (tem)
		&& DECL_SIZE (tem)
		&& host_integerp (DECL_SIZE (tem), 1)
		&& host_integerp (bit_position (tem), 0))
	      {
		const char *name;

		CONTIN;
		name = IDENTIFIER_POINTER (DECL_NAME (tem));
		PUT_SDB_DEF (name);
		if (DECL_BIT_FIELD_TYPE (tem))
		  {
		    PUT_SDB_INT_VAL (int_bit_position (tem));
		    PUT_SDB_SCL (C_FIELD);
		    sdbout_type (DECL_BIT_FIELD_TYPE (tem));
		    PUT_SDB_SIZE (tree_low_cst (DECL_SIZE (tem), 1));
		  }
		else
		  {
		    PUT_SDB_INT_VAL (int_bit_position (tem) / BITS_PER_UNIT);
		    PUT_SDB_SCL (member_scl);
		    sdbout_type (TREE_TYPE (tem));
		  }
		PUT_SDB_ENDEF;
	      }
	/* output end of a structure,union, or enumeral definition */

	PUT_SDB_PLAIN_DEF ("eos");
	PUT_SDB_INT_VAL (size);
	PUT_SDB_SCL (C_EOS);
	PUT_SDB_TAG (KNOWN_TYPE_TAG (type));
	PUT_SDB_SIZE (size);
	PUT_SDB_ENDEF;
	break;

      default:
	break;
      }
    }
}

/* The following two functions output definitions of function parameters.
   Each parameter gets a definition locating it in the parameter list.
   Each parameter that is a register variable gets a second definition
   locating it in the register.

   Printing or argument lists in gdb uses the definitions that
   locate in the parameter list.  But reference to the variable in
   expressions uses preferentially the definition as a register.  */

/* Output definitions, referring to storage in the parmlist,
   of all the parms in PARMS, which is a chain of PARM_DECL nodes.  */

static void
sdbout_parms (parms)
     tree parms;
{
  for (; parms; parms = TREE_CHAIN (parms))
    if (DECL_NAME (parms))
      {
	int current_sym_value = 0;
	const char *name = IDENTIFIER_POINTER (DECL_NAME (parms));

	if (name == 0 || *name == 0)
	  name = gen_fake_label ();

	/* Perform any necessary register eliminations on the parameter's rtl,
	   so that the debugging output will be accurate.  */
	DECL_INCOMING_RTL (parms)
	  = eliminate_regs (DECL_INCOMING_RTL (parms), 0, NULL_RTX);
	SET_DECL_RTL (parms,
		      eliminate_regs (DECL_RTL (parms), 0, NULL_RTX));

	if (PARM_PASSED_IN_MEMORY (parms))
	  {
	    rtx addr = XEXP (DECL_INCOMING_RTL (parms), 0);
	    tree type;

	    /* ??? Here we assume that the parm address is indexed
	       off the frame pointer or arg pointer.
	       If that is not true, we produce meaningless results,
	       but do not crash.  */
	    if (GET_CODE (addr) == PLUS
		&& GET_CODE (XEXP (addr, 1)) == CONST_INT)
	      current_sym_value = INTVAL (XEXP (addr, 1));
	    else
	      current_sym_value = 0;

	    if (GET_CODE (DECL_RTL (parms)) == REG
		&& REGNO (DECL_RTL (parms)) < FIRST_PSEUDO_REGISTER)
	      type = DECL_ARG_TYPE (parms);
	    else
	      {
		int original_sym_value = current_sym_value;

		/* This is the case where the parm is passed as an int or
		   double and it is converted to a char, short or float
		   and stored back in the parmlist.  In this case, describe
		   the parm with the variable's declared type, and adjust
		   the address if the least significant bytes (which we are
		   using) are not the first ones.  */
		if (BYTES_BIG_ENDIAN
		    && TREE_TYPE (parms) != DECL_ARG_TYPE (parms))
		  current_sym_value +=
		    (GET_MODE_SIZE (TYPE_MODE (DECL_ARG_TYPE (parms)))
		     - GET_MODE_SIZE (GET_MODE (DECL_RTL (parms))));

		if (GET_CODE (DECL_RTL (parms)) == MEM
		    && GET_CODE (XEXP (DECL_RTL (parms), 0)) == PLUS
		    && (GET_CODE (XEXP (XEXP (DECL_RTL (parms), 0), 1))
			== CONST_INT)
		    && (INTVAL (XEXP (XEXP (DECL_RTL (parms), 0), 1))
			== current_sym_value))
		  type = TREE_TYPE (parms);
		else
		  {
		    current_sym_value = original_sym_value;
		    type = DECL_ARG_TYPE (parms);
		  }
	      }

	    PUT_SDB_DEF (name);
	    PUT_SDB_INT_VAL (DEBUGGER_ARG_OFFSET (current_sym_value, addr));
	    PUT_SDB_SCL (C_ARG);
	    PUT_SDB_TYPE (plain_type (type));
	    PUT_SDB_ENDEF;
	  }
	else if (GET_CODE (DECL_RTL (parms)) == REG)
	  {
	    rtx best_rtl;
	    /* Parm passed in registers and lives in registers or nowhere.  */

	    /* If parm lives in a register, use that register;
	       pretend the parm was passed there.  It would be more consistent
	       to describe the register where the parm was passed,
	       but in practice that register usually holds something else.  */
	    if (REGNO (DECL_RTL (parms)) < FIRST_PSEUDO_REGISTER)
	      best_rtl = DECL_RTL (parms);
	    /* If the parm lives nowhere,
	       use the register where it was passed.  */
	    else
	      best_rtl = DECL_INCOMING_RTL (parms);

	    PUT_SDB_DEF (name);
	    PUT_SDB_INT_VAL (DBX_REGISTER_NUMBER (REGNO (best_rtl)));
	    PUT_SDB_SCL (C_REGPARM);
	    PUT_SDB_TYPE (plain_type (TREE_TYPE (parms)));
	    PUT_SDB_ENDEF;
	  }
	else if (GET_CODE (DECL_RTL (parms)) == MEM
		 && XEXP (DECL_RTL (parms), 0) != const0_rtx)
	  {
	    /* Parm was passed in registers but lives on the stack.  */

	    /* DECL_RTL looks like (MEM (PLUS (REG...) (CONST_INT...))),
	       in which case we want the value of that CONST_INT,
	       or (MEM (REG ...)) or (MEM (MEM ...)),
	       in which case we use a value of zero.  */
	    if (GET_CODE (XEXP (DECL_RTL (parms), 0)) == REG
		|| GET_CODE (XEXP (DECL_RTL (parms), 0)) == MEM)
	      current_sym_value = 0;
	    else
	      current_sym_value = INTVAL (XEXP (XEXP (DECL_RTL (parms), 0), 1));

	    /* Again, this assumes the offset is based on the arg pointer.  */
	    PUT_SDB_DEF (name);
	    PUT_SDB_INT_VAL (DEBUGGER_ARG_OFFSET (current_sym_value,
						  XEXP (DECL_RTL (parms), 0)));
	    PUT_SDB_SCL (C_ARG);
	    PUT_SDB_TYPE (plain_type (TREE_TYPE (parms)));
	    PUT_SDB_ENDEF;
	  }
      }
}

/* Output definitions for the places where parms live during the function,
   when different from where they were passed, when the parms were passed
   in memory.

   It is not useful to do this for parms passed in registers
   that live during the function in different registers, because it is
   impossible to look in the passed register for the passed value,
   so we use the within-the-function register to begin with.

   PARMS is a chain of PARM_DECL nodes.  */

static void
sdbout_reg_parms (parms)
     tree parms;
{
  for (; parms; parms = TREE_CHAIN (parms))
    if (DECL_NAME (parms))
      {
	const char *name = IDENTIFIER_POINTER (DECL_NAME (parms));

	/* Report parms that live in registers during the function
	   but were passed in memory.  */
	if (GET_CODE (DECL_RTL (parms)) == REG
	    && REGNO (DECL_RTL (parms)) < FIRST_PSEUDO_REGISTER
	    && PARM_PASSED_IN_MEMORY (parms))
	  {
	    if (name == 0 || *name == 0)
	      name = gen_fake_label ();
	    PUT_SDB_DEF (name);
	    PUT_SDB_INT_VAL (DBX_REGISTER_NUMBER (REGNO (DECL_RTL (parms))));
	    PUT_SDB_SCL (C_REG);
	    PUT_SDB_TYPE (plain_type (TREE_TYPE (parms)));
	    PUT_SDB_ENDEF;
	  }
	/* Report parms that live in memory but not where they were passed.  */
	else if (GET_CODE (DECL_RTL (parms)) == MEM
		 && GET_CODE (XEXP (DECL_RTL (parms), 0)) == PLUS
		 && GET_CODE (XEXP (XEXP (DECL_RTL (parms), 0), 1)) == CONST_INT
		 && PARM_PASSED_IN_MEMORY (parms)
		 && ! rtx_equal_p (DECL_RTL (parms), DECL_INCOMING_RTL (parms)))
	  {
#if 0 /* ??? It is not clear yet what should replace this.  */
	    int offset = DECL_OFFSET (parms) / BITS_PER_UNIT;
	    /* A parm declared char is really passed as an int,
	       so it occupies the least significant bytes.
	       On a big-endian machine those are not the low-numbered ones.  */
	    if (BYTES_BIG_ENDIAN
		&& offset != -1
		&& TREE_TYPE (parms) != DECL_ARG_TYPE (parms))
	      offset += (GET_MODE_SIZE (TYPE_MODE (DECL_ARG_TYPE (parms)))
			 - GET_MODE_SIZE (GET_MODE (DECL_RTL (parms))));
	    if (INTVAL (XEXP (XEXP (DECL_RTL (parms), 0), 1)) != offset) {...}
#endif
	      {
		if (name == 0 || *name == 0)
		  name = gen_fake_label ();
		PUT_SDB_DEF (name);
		PUT_SDB_INT_VAL (DEBUGGER_AUTO_OFFSET
				 (XEXP (DECL_RTL (parms), 0)));
		PUT_SDB_SCL (C_AUTO);
		PUT_SDB_TYPE (plain_type (TREE_TYPE (parms)));
		PUT_SDB_ENDEF;
	      }
	  }
      }
}

/* Output debug information for a global DECL.  Called from toplev.c
   after compilation proper has finished.  */

static void
sdbout_global_decl (decl)
     tree decl;
{
  if (TREE_CODE (decl) == VAR_DECL
      && !DECL_EXTERNAL (decl)
      && DECL_RTL_SET_P (decl))
    {
      /* The COFF linker can move initialized global vars to the end.
	 And that can screw up the symbol ordering.  Defer those for
	 sdbout_finish ().  */
      if (!DECL_INITIAL (decl) || !TREE_PUBLIC (decl))
	sdbout_symbol (decl, 0);

      /* Output COFF information for non-global file-scope initialized
	 variables.  */
      if (DECL_INITIAL (decl) && GET_CODE (DECL_RTL (decl)) == MEM)
	sdbout_toplevel_data (decl);
    }
}

/* Output initialized global vars at the end, in the order of
   definition.  See comment in sdbout_global_decl.  */

static void
sdbout_finish (main_filename)
     const char *main_filename ATTRIBUTE_UNUSED;
{
  tree decl = (*lang_hooks.decls.getdecls) ();
  unsigned int len = list_length (decl);
  tree *vec = (tree *) xmalloc (sizeof (tree) * len);
  unsigned int i;

  /* Process the decls in reverse order--earliest first.  Put them
     into VEC from back to front, then take out from front.  */

  for (i = 0; i < len; i++, decl = TREE_CHAIN (decl))
    vec[len - i - 1] = decl;

  for (i = 0; i < len; i++)
    {
      decl = vec[i];
      if (TREE_CODE (decl) == VAR_DECL
	  && ! DECL_EXTERNAL (decl)
	  && DECL_INITIAL (decl)
	  && TREE_PUBLIC (decl)
	  && DECL_RTL_SET_P (decl))
	sdbout_symbol (decl, 0);
    }

  free (vec);
}

/* Describe the beginning of an internal block within a function.
   Also output descriptions of variables defined in this block.

   N is the number of the block, by order of beginning, counting from 1,
   and not counting the outermost (function top-level) block.
   The blocks match the BLOCKs in DECL_INITIAL (current_function_decl),
   if the count starts at 0 for the outermost one.  */

static void
sdbout_begin_block (line, n)
     unsigned int line;
     unsigned int n;
{
  tree decl = current_function_decl;
  MAKE_LINE_SAFE (line);

  /* The SCO compiler does not emit a separate block for the function level
     scope, so we avoid it here also.  However, mips ECOFF compilers do emit
     a separate block, so we retain it when MIPS_DEBUGGING_INFO is defined.  */
#ifndef MIPS_DEBUGGING_INFO
  if (n != 1)
#endif
    PUT_SDB_BLOCK_START (line - sdb_begin_function_line);

  if (n == 1)
    {
      /* Include the outermost BLOCK's variables in block 1.  */
      do_block = BLOCK_NUMBER (DECL_INITIAL (decl));
      sdbout_block (DECL_INITIAL (decl));
    }
  /* If -g1, suppress all the internal symbols of functions
     except for arguments.  */
  if (debug_info_level != DINFO_LEVEL_TERSE)
    {
      do_block = n;
      sdbout_block (DECL_INITIAL (decl));
    }

#ifdef SDB_ALLOW_FORWARD_REFERENCES
  sdbout_dequeue_anonymous_types ();
#endif
}

/* Describe the end line-number of an internal block within a function.  */

static void
sdbout_end_block (line, n)
     unsigned int line;
     unsigned int n ATTRIBUTE_UNUSED;
{
  MAKE_LINE_SAFE (line);

  /* The SCO compiler does not emit a separate block for the function level
     scope, so we avoid it here also.  However, mips ECOFF compilers do emit
     a separate block, so we retain it when MIPS_DEBUGGING_INFO is defined.  */
#ifndef MIPS_DEBUGGING_INFO
  if (n != 1)
#endif
  PUT_SDB_BLOCK_END (line - sdb_begin_function_line);
}

static void
sdbout_source_line (line, filename)
     unsigned int line;
     const char *filename ATTRIBUTE_UNUSED;
{
  /* COFF relative line numbers must be positive.  */
  if ((int) line > sdb_begin_function_line)
    {
#ifdef ASM_OUTPUT_SOURCE_LINE
      ASM_OUTPUT_SOURCE_LINE (asm_out_file, line);
#else
      fprintf (asm_out_file, "\t.ln\t%d\n",
	       ((sdb_begin_function_line > -1)
		? line - sdb_begin_function_line : 1));
#endif
    }
}

/* Output sdb info for the current function name.
   Called from assemble_start_function.  */

static void
sdbout_begin_function (decl)
     tree decl ATTRIBUTE_UNUSED;
{
  sdbout_symbol (current_function_decl, 0);
}

/* Called at beginning of function body (before or after prologue,
   depending on MIPS_DEBUGGING_INFO).  Record the function's starting
   line number, so we can output relative line numbers for the other
   lines.  Describe beginning of outermost block.  Also describe the
   parameter list.  */

#ifndef MIPS_DEBUGGING_INFO
static void
sdbout_begin_prologue (line, file)
     unsigned int line;
     const char *file ATTRIBUTE_UNUSED;
{
  sdbout_end_prologue (line);
}
#endif

static void
sdbout_end_prologue (line)
     unsigned int line;
{
  sdb_begin_function_line = line - 1;
  PUT_SDB_FUNCTION_START (line);
  sdbout_parms (DECL_ARGUMENTS (current_function_decl));
  sdbout_reg_parms (DECL_ARGUMENTS (current_function_decl));
}

/* Called at end of function (before epilogue).
   Describe end of outermost block.  */

static void
sdbout_end_function (line)
     unsigned int line;
{
#ifdef SDB_ALLOW_FORWARD_REFERENCES
  sdbout_dequeue_anonymous_types ();
#endif

  MAKE_LINE_SAFE (line);
  PUT_SDB_FUNCTION_END (line - sdb_begin_function_line);

  /* Indicate we are between functions, for line-number output.  */
  sdb_begin_function_line = -1;
}

/* Output sdb info for the absolute end of a function.
   Called after the epilogue is output.  */

static void
sdbout_end_epilogue ()
{
  const char *const name ATTRIBUTE_UNUSED
    = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (current_function_decl));

#ifdef PUT_SDB_EPILOGUE_END
  PUT_SDB_EPILOGUE_END (name);
#else
  fprintf (asm_out_file, "\t.def\t");
  assemble_name (asm_out_file, name);
  fprintf (asm_out_file, "%s\t.val\t.%s\t.scl\t-1%s\t.endef\n",
	   SDB_DELIM, SDB_DELIM, SDB_DELIM);
#endif
}

/* Output sdb info for the given label.  Called only if LABEL_NAME (insn)
   is present.  */

static void
sdbout_label (insn)
     rtx insn;
{
  PUT_SDB_DEF (LABEL_NAME (insn));
  PUT_SDB_VAL (insn);
  PUT_SDB_SCL (C_LABEL);
  PUT_SDB_TYPE (T_NULL);
  PUT_SDB_ENDEF;
}

/* Change to reading from a new source file.  */

static void
sdbout_start_source_file (line, filename)
     unsigned int line ATTRIBUTE_UNUSED;
     const char *filename ATTRIBUTE_UNUSED;
{
#ifdef MIPS_DEBUGGING_INFO
  struct sdb_file *n = (struct sdb_file *) xmalloc (sizeof *n);

  n->next = current_file;
  n->name = filename;
  current_file = n;
  PUT_SDB_SRC_FILE (filename);
#endif
}

/* Revert to reading a previous source file.  */

static void
sdbout_end_source_file (line)
     unsigned int line ATTRIBUTE_UNUSED;
{
#ifdef MIPS_DEBUGGING_INFO
  struct sdb_file *next;

  next = current_file->next;
  free (current_file);
  current_file = next;
  PUT_SDB_SRC_FILE (current_file->name);
#endif
}

/* Set up for SDB output at the start of compilation.  */

static void
sdbout_init (input_file_name)
     const char *input_file_name ATTRIBUTE_UNUSED;
{
#ifdef MIPS_DEBUGGING_INFO
  current_file = (struct sdb_file *) xmalloc (sizeof *current_file);
  current_file->next = NULL;
  current_file->name = input_file_name;
#endif

#ifdef RMS_QUICK_HACK_1
  tree t;
  for (t = (*lang_hooks.decls.getdecls) (); t; t = TREE_CHAIN (t))
    if (DECL_NAME (t) && IDENTIFIER_POINTER (DECL_NAME (t)) != 0
	&& !strcmp (IDENTIFIER_POINTER (DECL_NAME (t)), "__vtbl_ptr_type"))
      sdbout_symbol (t, 0);
#endif  

#ifdef SDB_ALLOW_FORWARD_REFERENCES
  ggc_add_tree_root (&anonymous_types, 1);
#endif
}

#endif /* SDB_DEBUGGING_INFO */
