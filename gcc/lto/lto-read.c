/* Read the gimple representation of a function and it's local
   variables from the memory mapped representation of a a .o file.

   Copyright 2006 Free Software Foundation, Inc.
   Contributed by Kenneth Zadeck <zadeck@naturalbridge.com>

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to
the Free Software Foundation, 51 Franklin Street, Fifth Floor,
Boston, MA 02110-1301, USA.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "toplev.h"
#include "tree.h"
#include "expr.h"
#include "flags.h"
#include "params.h"
#include "input.h"
#include "varray.h"
#include "hashtab.h"
#include "langhooks.h"
#include "basic-block.h"
#include "tree-iterator.h"
#include "tree-pass.h"
#include "tree-flow.h"
#include "cgraph.h"
#include "function.h"
#include "ggc.h"
#include "diagnostic.h"
#include "except.h"
#include "debug.h"
#include "vec.h"
#include "timevar.h"
#include "dwarf2asm.h"
#include "dwarf2out.h"
#include "output.h"
#include "lto-tags.h"
#include "lto.h"
#include <ctype.h>

static enum tree_code tag_to_expr[LTO_last_tag];

/* The number of flags that are defined for each tree code.  */
static int num_flags_for_code[NUM_TREE_CODES];

struct fun_in
{
  tree *field_decls;        /* The field decls.  */
  tree *fn_decls;           /* The function decls.  */
  tree *var_decls;          /* The global or static var_decls.  */
  tree *types;              /* All of the types.  */
  tree *local_decls;        /* The local var_decls and the parm_decls.  */
  tree *labels;             /* All of the labels.  */
  const char * strings;     /* The string table.  */
  unsigned int strings_len; /* The length of the string table.  */
  /* Number of named labels.  Used to find the index of unnamed labels
     since they share space with the named labels.  */
  unsigned int num_named_labels;  
};


struct input_block 
{
  const char *data;
  unsigned int p;
  unsigned int len;
};


#ifdef LTO_STREAM_DEBUGGING
static struct lto_debug_context lto_debug_context;
static void debug_out_fun (struct lto_debug_context *, char);
static void dump_debug_stream (struct input_block *, char, char);
#endif

static tree
input_expr_operand (struct input_block *, struct fun_in *, unsigned int);


/* Return the next character of input from IB.  Abort if you
   overrun.  */

static unsigned char 
input_1_unsigned (struct input_block *ib)
{
  gcc_assert (ib->p < ib->len);
  return (ib->data[ib->p++]);
}


/* Read an ULEB128 Number of IB.  */

static unsigned HOST_WIDE_INT 
input_uleb128 (struct input_block *ib)
{
  unsigned HOST_WIDE_INT result = 0;
  int shift = 0;
  unsigned int byte;

  while (true)
    {
      byte = input_1_unsigned (ib);
      result |= (byte & 0x7f) << shift;
      shift += 7;
      if ((byte & 0x80) == 0)
	{
	  LTO_DEBUG_WIDE ("U", result)
	  return result;
	}
    }
}


/* Read an SLEB128 Number of IB.  */

static HOST_WIDE_INT 
input_sleb128 (struct input_block *ib)
{
  HOST_WIDE_INT result = 0;
  int shift = 0;
  unsigned HOST_WIDE_INT byte;

  while (true)
    {
      byte = input_1_unsigned (ib);
      result |= (byte & 0x7f) << shift;
      shift += 7;
      if ((byte & 0x80) == 0)
	{
	  if ((shift < HOST_BITS_PER_INT) && (byte & 0x40))
	    result |= - (1 << shift);

	  LTO_DEBUG_WIDE ("S", result)
	  return result;
	}
    }
}


/* Read the string at LOC from the string table in FUN_IN.  */

static const char * 
input_string_internal (struct fun_in *fun_in, unsigned int loc, 
		       unsigned int *rlen)
{
  struct input_block str_tab 
    = {fun_in->strings, loc, fun_in->strings_len};
  unsigned int len = input_uleb128 (&str_tab);
  const char * result;

  *rlen = len;
  gcc_assert (str_tab.p + len <= fun_in->strings_len);

  result = (const char *)(fun_in->strings + str_tab.p);
  LTO_DEBUG_STRING (result, len)
  return result;
}


/* Read a STRING_CST at LOC from the string table in FUN_IN.  */

static tree
input_string (struct fun_in *fun_in, unsigned int loc)
{
  unsigned int len;
  const char * ptr = input_string_internal (fun_in, loc, &len);
  return build_string (len, ptr);
}


/* Input a real constant of TYPE at LOC.  */

static tree
input_real (struct fun_in *fun_in, unsigned int loc, tree type)
{
  unsigned int len;
  const char * str = input_string_internal (fun_in, loc, &len); 
  REAL_VALUE_TYPE value;

  LTO_DEBUG_TOKEN ("real")

  real_from_string (&value, str);
  return build_real (type, value);
}


/* Input the next integer constant of TYPE in IB.  */

static tree
input_integer (struct input_block *ib, tree type)
{
  HOST_WIDE_INT low = 0;
  HOST_WIDE_INT high = 0;
  int shift = 0;
  unsigned int byte;

  while (true)
    {
      byte = input_1_unsigned (ib);
      if (shift < HOST_BITS_PER_INT - 7)
	/* Working on the low part.  */
	low |= (byte & 0x7f) << shift;
      else if (shift >= HOST_BITS_PER_INT)
	/* Working on the high part.  */
	high |= (byte & 0x7f) << (shift - HOST_BITS_PER_INT);
      else
	{
	  /* Working on the transition between the low and high parts.  */
	  low |= (byte & 0x7f) << shift;
	  high |= (byte & 0x7f) >> (HOST_BITS_PER_INT - shift);
	}

      shift += 7;
      if ((byte & 0x80) == 0)
	{
	  if (byte & 0x40)
	    {
	      /* The number is negative.  */
	      if (shift < HOST_BITS_PER_INT)
		{
		  low |= - (1 << shift);
		  high = -1;
		}
	      else if (shift < (2 * HOST_BITS_PER_INT))
		high |= - (1 << shift);
	    }

#ifdef LTO_STREAM_DEBUGGING
	  /* Have to match the quick out in the lto writer.  */
	  if (((high == -1) && (low < 0))
	      || ((high == 0) && (low >= 0)))
	    LTO_DEBUG_WIDE ("S", low)
	  else 
	    LTO_DEBUG_INTEGER ("SS", high, low)
#endif	  
	  return build_int_cst_wide (type, low, high);
	}
    }
}


/* Return the next tag in the input block IB.  */

static unsigned int
input_record_start (struct input_block *ib)
{
  unsigned int tag = input_1_unsigned (ib);

#ifdef LTO_STREAM_DEBUGGING
  if (tag)
    LTO_DEBUG_INDENT (tag)
  else
    LTO_DEBUG_WIDE ("U", 0)
#endif    
  return tag;
} 


/* Build a tree list stopping when the tag is 0.  */

static tree 
input_list (struct input_block *ib, struct fun_in *fun_in)
{
  unsigned int tag = input_record_start (ib);
  tree first = NULL_TREE;
  if (tag)
    {
      first = build_tree_list (NULL_TREE, input_expr_operand (ib, fun_in, tag));
      tree next = first;
      tag = input_record_start (ib);
      while (tag)
	{
	  TREE_CHAIN (next) 
	    = build_tree_list (NULL_TREE, input_expr_operand (ib, fun_in, tag));
	  next = TREE_CHAIN (next);
	  tag = input_record_start (ib);
	}
    }

  LTO_DEBUG_UNDENT()
  return first;
}

/* Set up an empty cfg for THIS_FUN with BB_COUNT slots available.  */

static void 
init_cfg (struct function *this_fun, unsigned int bb_count)
{
  init_flow (this_fun);
  profile_status_for_function (this_fun) = PROFILE_ABSENT;
  n_basic_blocks_for_function (this_fun) = NUM_FIXED_BLOCKS;
  last_basic_block_for_function (this_fun) = bb_count;
  basic_block_info_for_function (this_fun)
    = VEC_alloc (basic_block, gc, bb_count);
  VEC_safe_grow (basic_block, gc, basic_block_info, bb_count);
  memset (VEC_address (basic_block, 
		       basic_block_info_for_function (this_fun)), 
	  0, sizeof (basic_block) * bb_count);

  /* Build a mapping of labels to their associated blocks.  */
  label_to_block_map_for_function (this_fun)
    = VEC_alloc (basic_block, gc, bb_count);
  VEC_safe_grow (basic_block, gc, 
		 label_to_block_map_for_function (this_fun), bb_count);
  memset (VEC_address (basic_block, 
		       label_to_block_map_for_function (this_fun)),
	  0, sizeof (basic_block) * bb_count);

  SET_BASIC_BLOCK_FOR_FUNCTION (this_fun, ENTRY_BLOCK, 
				ENTRY_BLOCK_PTR_FOR_FUNCTION (this_fun));
  SET_BASIC_BLOCK_FOR_FUNCTION (this_fun, EXIT_BLOCK, 
		   EXIT_BLOCK_PTR_FOR_FUNCTION (this_fun));
}


/* Link up the prev_bb and next_bb fields in the cfg.  */

static void 
finalize_cfg (struct function *this_fun, unsigned int bb_count)
{
  unsigned int i;
  basic_block p_bb = ENTRY_BLOCK_PTR_FOR_FUNCTION(this_fun);

  for (i=NUM_FIXED_BLOCKS; i<bb_count; i++)
    {
      basic_block bb = BASIC_BLOCK_FOR_FUNCTION (this_fun, i);
      if (bb)
	{
	  bb->prev_bb = p_bb;
	  p_bb->next_bb = bb;
	  p_bb = bb;
	}
    }

  p_bb->next_bb = EXIT_BLOCK_PTR_FOR_FUNCTION(this_fun);
  EXIT_BLOCK_PTR_FOR_FUNCTION(this_fun)->prev_bb = p_bb;
}


/* Get the label referenced by the next token in IB.  */

static tree 
get_label_decl (struct fun_in *fun_in, struct input_block *ib)
{
  int index = input_sleb128 (ib);
  if (index >= 0)
    return fun_in->labels[index];
  else
    return fun_in->labels[fun_in->num_named_labels - index];
}


/* Get the type referenced by the next token in IB.  */

static tree
get_type_ref (struct fun_in *fun_in, struct input_block *ib)
{
  int index;

  LTO_DEBUG_TOKEN ("type")
  index = input_uleb128 (ib);
  return fun_in->types[index];
}

/* Set all of the FLAGS for NODE.  */
#define CLEAROUT (HOST_BITS_PER_INT - 1)


/* Set all of the flag bits inside EXPR by unpacking FLAGS.  */

static void
process_flags (tree expr, unsigned HOST_WIDE_INT flags)
{
  enum tree_code code = TREE_CODE (expr);
  /* Shift the flags up so that the first flag is at the top of the
     flag word.  */
  flags <<= HOST_BITS_PER_INT - num_flags_for_code[code];

#define START_CLASS_SWITCH()              \
  {                                       \
                                          \
    switch (TREE_CODE_CLASS (code))       \
    {

#define START_CLASS_CASE(class)    case class:
#define ADD_CLASS_FLAG(flag_name) { expr->base. flag_name = flags >> CLEAROUT;  flags <<= 1; }
#define END_CLASS_CASE(class)      break;
#define END_CLASS_SWITCH()                \
    default:                              \
      gcc_unreachable ();                 \
    }


#define START_EXPR_SWITCH()               \
    switch (code)			  \
    {
#define START_EXPR_CASE(code)    case code:
#define ADD_EXPR_FLAG(flag_name) { expr->base. flag_name = (flags >> CLEAROUT);  flags <<= 1; }
#define ADD_DECL_FLAG(flag_name) { expr->decl_common. flag_name = flags >> CLEAROUT; flags <<= 1; }
#define ADD_VIS_FLAG(flag_name)  { expr->decl_with_vis. flag_name = (flags >> CLEAROUT); flags <<= 1; }
#define ADD_FUNC_FLAG(flag_name) { expr->function_decl. flag_name = (flags >> CLEAROUT); flags <<= 1; }
#define END_EXPR_CASE(class)      break;
#define END_EXPR_SWITCH()                 \
    default:                              \
      gcc_unreachable ();                 \
    }                                     \
  }

#include "lto-tree-flags.def"

#undef START_CLASS_SWITCH
#undef START_CLASS_CASE
#undef ADD_CLASS_FLAG
#undef END_CLASS_CASE
#undef END_CLASS_SWITCH
#undef START_EXPR_SWITCH
#undef START_EXPR_CASE
#undef ADD_EXPR_FLAG
#undef ADD_DECL_FLAG
#undef ADD_VIS_FLAG
#undef ADD_FUNC_FLAG
#undef END_EXPR_CASE
#undef END_EXPR_SWITCH
}


/* Read a node in the gimple tree from IB.  The TAG has already been
   read.  */

static tree
input_expr_operand (struct input_block *ib, struct fun_in *fun_in, 
		    unsigned int tag)
{
  enum tree_code code = tag_to_expr[tag];
  tree type = NULL_TREE;
  unsigned HOST_WIDE_INT flags;
  const char *new_file = NULL;
  int new_line = -1;
  gcc_assert (code);
  tree result = NULL_TREE;
  
  if (TEST_BIT (lto_types_needed_for, code))
    type = get_type_ref (fun_in, ib);

  if (TEST_BIT (lto_flags_needed_for, code))
    {
      LTO_DEBUG_TOKEN ("flags")
      flags = input_uleb128 (ib);
    }
  else
    flags = 0;

  /* FIXME! need to figure out how to set the file and line number.  */
  if (IS_EXPR_CODE_CLASS (TREE_CODE_CLASS (code)))
    {
      if (flags & 0x2)
	{
	  unsigned int len;
	  LTO_DEBUG_TOKEN ("file")
	  new_file = input_string_internal (fun_in, input_uleb128 (ib), &len);
	}
      if (flags & 0x1)
	{
	  LTO_DEBUG_TOKEN ("line")
	  new_line = input_uleb128 (ib);
	}
    }

  switch (code)
    {
    case COMPLEX_CST:
      result = build0 (code, type);
      if (tag == LTO_complex_cst1)
	{
	  TREE_REALPART (result) 
	    = input_real (fun_in, input_uleb128 (ib), type);
	  TREE_IMAGPART (result) 
	    = input_real (fun_in, input_uleb128 (ib), type);
	}
      else
	{
	  TREE_REALPART (result) = input_integer (ib, type);
	  TREE_IMAGPART (result) = input_integer (ib, type);
	}
      break;

    case INTEGER_CST:
      result = input_integer (ib, type);
      break;

    case REAL_CST:
      result = input_real (fun_in, input_uleb128 (ib), type);
      break;

    case STRING_CST:
      result = input_string (fun_in, input_uleb128 (ib));
      break;

    case VECTOR_CST:
      {
	tree chain = NULL_TREE;
	int len = input_uleb128 (ib);

	if (len && tag == LTO_vector_cst1)
	  {
	    int i;
	    tree last 
	      = build_tree_list (NULL_TREE, 
				 input_real (fun_in, 
					     input_uleb128 (ib), 
					     type));
	    chain = last; 
	    for (i = 1; i < len; i++)
	      {
		tree t 
		  = build_tree_list (NULL_TREE, 
				     input_real (fun_in, 
						 input_uleb128 (ib), 
						 type));
		TREE_CHAIN (last) = t;
		last = t;
	      }
	  }
	else
	  {
	    int i;
	    tree last = build_tree_list (NULL_TREE, input_integer (ib, type));
	    chain = last; 
	    for (i = 1; i < len; i++)
	      {
		tree t 
		  = build_tree_list (NULL_TREE, input_integer (ib, type));
		TREE_CHAIN (last) = t;
		last = t;
	      }
	  }
	result = build_vector (type, chain);
      }
      break;

    case CASE_LABEL_EXPR:
      {
	int variant = tag - LTO_case_label_expr0;
	tree op0 = NULL_TREE;
	tree op1 = NULL_TREE;
	
	if (variant & 0x1)
	  op0 = input_expr_operand (ib, fun_in, 
				    input_record_start (ib));

	if (variant & 0x2)
	  op1 = input_expr_operand (ib, fun_in, 
				    input_record_start (ib));

	result = build3 (code, void_type_node, 
			 op0, op1, get_label_decl (fun_in, ib));
      }
      break;

    case CONSTRUCTOR:
      {
	VEC(constructor_elt,gc) *vec = NULL;
	unsigned int len = input_uleb128 (ib);
	
	if (len)
	  {
	    tree purpose = NULL_TREE;
	    unsigned int i = 0;
	    vec = VEC_alloc (constructor_elt, gc, len);
	    while (i < len)
	      {
		unsigned int ctag = input_record_start (ib);
		if (ctag == LTO_constructor_range)
		  {
		    tree op0 = input_integer (ib, get_type_ref (fun_in, ib));
		    tree op1 = input_integer (ib, get_type_ref (fun_in, ib));
		    purpose = build2 (RANGE_EXPR, sizetype, op0, op1);
		  }
		else
		  {
		    tree value = 
		      input_expr_operand (ib, fun_in, ctag);
		    constructor_elt *elt 
		      = VEC_quick_push (constructor_elt, vec, NULL);
		    elt->index = purpose;
		    elt->value = value;
		    
		    /* Only use the range once.  */
		    purpose = NULL_TREE;
		    i++;
		  }
		LTO_DEBUG_UNDENT()
	      }
	  }
	result = build_constructor (type, vec);
      }
      break;

    case CONST_DECL:
      /* Just ignore these, Mark will make them disappear.  */
      break;

    case FIELD_DECL:
      result = fun_in->field_decls [input_uleb128 (ib)];
      break;

    case FUNCTION_DECL:
      result = fun_in->fn_decls [input_uleb128 (ib)];
      break;

    case VAR_DECL:
      if (tag == LTO_var_decl1)
	/* Static or externs are here.  */
	result = fun_in->var_decls [input_uleb128 (ib)];
      else 
	{
	  /* Locals are here.  */
	  int lv_index = input_uleb128 (ib);
	  result = fun_in->local_decls [lv_index];
	  /* There is a rare case where the local var decl in the
	     table will be NULL.  This is caused if the subtrees of
	     var_decls reference other local var decls.  Create an
	     empty one now and the local decl reading code will fill
	     in the fields later rather than creating its own.  */
	  if (result == NULL)
	    {
	      result = build_decl (VAR_DECL, NULL_TREE, NULL_TREE);
	      fun_in->local_decls [lv_index] = result;
	    }
	}
      break;

    case PARM_DECL:
      result = fun_in->local_decls [input_uleb128 (ib)];
      break;

    case LABEL_DECL:
      result = get_label_decl (fun_in, ib);
      break;

    case LABEL_EXPR:
      result = build1 (code, void_type_node, get_label_decl (fun_in, ib));
      break;

    case RESULT_DECL:
      result = build0 (code, NULL_TREE);
      break;

    case COMPONENT_REF:
      {
	tree op0;
	tree op1;
	op0 = input_expr_operand (ib, fun_in, 
				  input_record_start (ib));
	op1 = input_expr_operand (ib, fun_in, 
				  input_record_start (ib));
  
	/* Ignore 3 because it can be recomputed.  */
	result = build3 (code, type, op0, op1, NULL_TREE);
      }
      break;

    case CALL_EXPR:
      {
	unsigned int i;
	unsigned int count = input_uleb128 (ib);
	tree op1;
	tree op2 = NULL_TREE;

	/* The call chain.  */
	if (tag == LTO_call_expr1)
	  op2 = input_expr_operand (ib, fun_in, 
				    input_record_start (ib));

	/* The callee.  */
	op1 = input_expr_operand (ib, fun_in, 
				  input_record_start (ib));

	result = build_vl_exp (code, count);
	CALL_EXPR_FN (result) = op1;
	CALL_EXPR_STATIC_CHAIN (result) = op2;
	for (i = 3; i < count; i++)
	  TREE_OPERAND (result, i) 
	    = input_expr_operand (ib, fun_in, 
				  input_record_start (ib));
      }
      break;

    case BIT_FIELD_REF:
      {
	tree op0;
	tree op1;
	tree op2;
	if (tag == LTO_bit_field_ref1)
	  {
	    op1 = input_integer (ib, SIZETYPE);
	    op2 = input_integer (ib, SIZETYPE);
	    op0 = input_expr_operand (ib, fun_in, 
				      input_record_start (ib));
	  }
	else
	  {
	    op0 = input_expr_operand (ib, fun_in, 
				      input_record_start (ib));
	    op1 = input_expr_operand (ib, fun_in, 
				      input_record_start (ib));
	    op2 = input_expr_operand (ib, fun_in, 
				      input_record_start (ib));
	  }
	result = build3 (code, type, op0, op1, op2);
      }
      break;

    case ARRAY_REF:
    case ARRAY_RANGE_REF:
      /* Ignore operands 2 and 3 for ARRAY_REF and ARRAY_RANGE REF
	 because they can be recomputed.  */
      {
	tree op0 = input_expr_operand (ib, fun_in, 
				       input_record_start (ib));
	tree op1 = input_expr_operand (ib, fun_in, 
				       input_record_start (ib));
	result = build4 (code, type, op0, op1, NULL_TREE, NULL_TREE);
      }
      break;

    case ASM_EXPR:
      {
	tree str = input_string (fun_in, input_uleb128 (ib));
	tree ins = input_list (ib, fun_in); 
	tree outs = input_list (ib, fun_in); 
	tree clobbers = input_list (ib, fun_in);
	result = build4 (code, void_type_node, str, outs, ins, clobbers);
      }
      break;

    case RESX_EXPR:
      result = build1 (code, void_type_node, input_integer (ib, NULL_TREE));
      break;

    case RETURN_EXPR:
      switch (tag) 
	{
	case LTO_return_expr0:
	  result = build1 (code, NULL_TREE, NULL_TREE);
	  break;
	  
	case LTO_return_expr1:
	  result = build1 (code, NULL_TREE, 
			   input_expr_operand (ib, fun_in, 
					       input_record_start (ib)));
	  break;
	  
	case LTO_return_expr2:
	  {
	    tree op0 = input_expr_operand (ib, fun_in, 
					   input_record_start (ib));
	    tree op1 = input_expr_operand (ib, fun_in, 
					   input_record_start (ib));
	    result = build1 (code, NULL_TREE, 
			     build2 (MODIFY_EXPR, NULL_TREE, op0, op1));
	  }
	  break;
	}
      break;

    case SWITCH_EXPR:
      {
	unsigned int len = input_uleb128 (ib);
	unsigned int i;
	tree op0 = input_expr_operand (ib, fun_in, 
				       input_record_start (ib));
	tree op2 = make_tree_vec (len);
	
	for (i = 0; i < len; ++i)
	  TREE_VEC_ELT (op2, i) 
	    = input_expr_operand (ib, fun_in, 
				  input_record_start (ib));
	result = build3 (code, NULL_TREE, op0, NULL_TREE, op2);
      }
      break;

      /* This is the default case. All of the cases that can be done
	 completely mechanically are done here.  */
#define SET_NAME(a,b)
#define TREE_SINGLE_MECHANICAL_TRUE
#define MAP_EXPR_TAG(expr,tag) case expr:
#include "lto-tree-tags.def"
#undef MAP_EXPR_TAG
#undef TREE_SINGLE_MECHANICAL_TRUE
#undef SET_NAME
      {
	tree ops[7];
	int len = TREE_CODE_LENGTH (code);
	int i;
	for (i = 0; i<len; i++)
	  ops[i] = input_expr_operand (ib, fun_in, 
				       input_record_start (ib));
	switch (len)
	  {
	  case 0:
	    result = build0 (code, type);
	    break;
	  case 1:
	    result = build1 (code, type, ops[0]);
	    break;
	  case 2:
	    result = build2 (code, type, ops[0], ops[1]);
	    break;
	  case 3:
	    result = build3 (code, type, ops[0], ops[1], ops[2]);
	    break;
	  case 4:
	    result = build4 (code, type, ops[0], ops[1], ops[2], ops[3]);
	    break;
	  case 5:
	    result = build5 (code, type, ops[0], ops[1], ops[2], ops[3], 
			     ops[4]);
	    break;
	  case 7:
	    result = build7 (code, type, ops[0], ops[1], ops[2], ops[3], 
			     ops[4], ops[5], ops[6]);
	    break;
	  default:
	    gcc_unreachable ();
	  }
      }
      break;
      /* This is the error case, these are type codes that will either
	 never happen or that we have not gotten around to dealing
	 with are here.  */
    case BIND_EXPR:
    case BLOCK:
    case CATCH_EXPR:
    case EH_FILTER_EXPR:
    case NAME_MEMORY_TAG:
    case OMP_CONTINUE:
    case OMP_CRITICAL:
    case OMP_FOR:
    case OMP_MASTER:
    case OMP_ORDERED:
    case OMP_PARALLEL:
    case OMP_RETURN:
    case OMP_SECTIONS:
    case OMP_SINGLE:
    case SSA_NAME:
    case STRUCT_FIELD_TAG:
    case SYMBOL_MEMORY_TAG:
    case TARGET_MEM_REF:
    case TRY_CATCH_EXPR:
    case TRY_FINALLY_EXPR:
    default:
      /* We cannot have forms that are not explicity handled.  So when
	 this is triggered, there is some form that is not being
	 output.  */
      gcc_unreachable ();
    }

  LTO_DEBUG_UNDENT()
  process_flags (result, flags);
  return result;
}


/* Load in the global vars and all of the types from the main symbol
   table.  */

static void
input_globals (struct lto_function_header * header,
	      lto_info_fd *fd,
	      lto_context *context,	
	      struct fun_in *fun_in, 
	      lto_ref in_field_decls[] ATTRIBUTE_UNUSED,
	      lto_ref in_fn_decls[],
	      lto_ref in_var_decls[],
	      lto_ref in_types[])
{
  int i;
  fun_in->field_decls = xcalloc (header->num_field_decls, sizeof (tree*));
  fun_in->fn_decls    = xcalloc (header->num_fn_decls, sizeof (tree*));
  fun_in->var_decls   = xcalloc (header->num_var_decls, sizeof (tree*));
  fun_in->types       = xcalloc (header->num_types, sizeof (tree*));

  /* FIXME: The test for zero section can go away when everything gets
     working.  */
  /*
  for (i=0; i<header->num_field_decls; i++)
    if (in_field_decls[i].section)
      fun_in->field_decls[i] 
        = lto_resolve_field_ref (fd, context, in_field_decls[i]);
  */

  for (i=0; i<header->num_fn_decls; i++)
    if (in_fn_decls[i].section)
      fun_in->fn_decls[i] 
	= lto_resolve_fn_ref (fd, context, &in_fn_decls[i]);

  for (i=0; i<header->num_var_decls; i++)
    if (in_var_decls[i].section)
      fun_in->var_decls[i] 
	= lto_resolve_var_ref (fd, context, &in_var_decls[i]);

  for (i=0; i<header->num_types; i++)
    {
      fun_in->types[i]
	= lto_resolve_type_ref (fd, context, &in_types[i]);
      
      fprintf (stderr, "type %d = ", i);
      print_generic_expr (stderr, fun_in->types[i], TDF_VOPS|TDF_UID);
      fprintf (stderr, "\n");
      print_node (stderr, "", fun_in->types[i], 0);
      fprintf (stderr, "\n\n");
    }
}


/* Load NAMED_COUNT named labels and constuct UNNAMED_COUNT unnamed
   labels from DATA segment SIZE bytes long using FUN_IN.  */

static void 
input_labels (struct fun_in *fun_in, const char *data, 
	      unsigned int size, unsigned int named_count, 
	      unsigned int unnamed_count)
{
  struct input_block ib = {data, 0, size};
  unsigned int i;

  /* The named and unnamed labels share the same array.  In the lto
     code, the unnamed labels have a negative index.  Their position
     in the array can be found by subtracting that index from the
     number of named labels.  */
  fun_in->labels = xcalloc (named_count + unnamed_count, sizeof (tree*));
  for (i = 0; i < named_count; i++)
    {
      unsigned int name_index = input_uleb128 (&ib);
      unsigned int len;
      const char *s = input_string_internal (fun_in, name_index, &len);
      tree name = get_identifier_with_length (s, len);
      fun_in->labels[i] = build_decl (LABEL_DECL, name, void_type_node);
    }

  for (i = 0; i < unnamed_count; i++)
    fun_in->labels[i + named_count] 
      = build_decl (LABEL_DECL, NULL_TREE, void_type_node);
 }

/* Load COUNT local var_decls and parm_decls from a DATA segment SIZE
   bytes long using FUN_IN.  */

static void 
input_local_vars (struct fun_in *fun_in, const char *data, 
	     unsigned int size, unsigned int count)
{
  struct input_block ib = {data, 0, size};
  unsigned int i;

  fun_in->local_decls = xcalloc (count, sizeof (tree*));
  for (i = 0; i < count; i++)
    {
      unsigned int tag = input_record_start (&ib);
      unsigned int variant = tag & 0xF;
      bool is_var = ((tag & 0xFFF0) == LTO_local_var_decl_body0);

      unsigned int name_index;
      tree name;
      tree type;
      unsigned HOST_WIDE_INT flags;
      const char *new_file = NULL;
      int new_line = -1;
      tree result = fun_in->local_decls[i];

      name_index = input_uleb128 (&ib);
      if (name_index)
	{
	  unsigned int len;
	  const char *s = input_string_internal (fun_in, name_index, &len);
	  name = get_identifier_with_length (s, len);
	}
      else 
	name = NULL_TREE;

      type = get_type_ref (fun_in, &ib);

      /* The result may not be NULL here because if any of the
	 subtrees of some prior local var_decl referenced this local
	 decl, a blank var decl would have been created and inserted
	 here.  However, the normal case is that it will be NULL.  */ 
      if (result == NULL)
	{
	  if (is_var)
	    result = build_decl (VAR_DECL, name, type);
	  else
	    result = build_decl (PARM_DECL, name, type);
	}
      fun_in->local_decls[i] = result;

      if (!is_var)
	DECL_ARG_TYPE (result) = get_type_ref (fun_in, &ib);

      LTO_DEBUG_TOKEN ("flags")
      flags = input_uleb128 (&ib);

      /* FIXME: Need to figure out how to set the line number.  */
      if (flags & 0x2)
	{
	  unsigned int len;
	  LTO_DEBUG_TOKEN ("file")
	  new_file = input_string_internal (fun_in, input_uleb128 (&ib), &len);
	}
      if (flags & 0x1)
	{
	  LTO_DEBUG_TOKEN ("line")
	  new_line = input_uleb128 (&ib);
	}

      LTO_DEBUG_TOKEN ("align")
      DECL_ALIGN (result) = input_uleb128 (&ib);
      LTO_DEBUG_TOKEN ("size")
      DECL_SIZE (result) 
	= input_expr_operand (&ib, fun_in, input_record_start (&ib));

      if (variant & 0x1)
	{
	  LTO_DEBUG_TOKEN ("attributes")
          DECL_ATTRIBUTES (result) 
	    = input_expr_operand (&ib, fun_in, input_record_start (&ib));
	}
      if (variant & 0x2)
	DECL_SIZE_UNIT (result) 
	  = input_expr_operand (&ib, fun_in, input_record_start (&ib));
      if (variant & 0x4)
	SET_DECL_DEBUG_EXPR (result, 
			     input_expr_operand (&ib, fun_in, 
						 input_record_start (&ib)));
      if (variant & 0x8)
        DECL_ABSTRACT_ORIGIN (result) 
	  = input_expr_operand (&ib, fun_in, input_record_start (&ib));

      process_flags (result, flags);
      LTO_DEBUG_UNDENT()
    }
}


/* Read the exception table.  */

static void
input_eh_regions (struct input_block *ib, 
		  struct function *fn ATTRIBUTE_UNUSED, 
		  struct fun_in *fun_in ATTRIBUTE_UNUSED)
{
  /* Not ready to read exception records yet.  */
  input_uleb128 (ib);
}


/* Make a new basic block at INDEX in FN.  */

static basic_block
make_new_block (struct function *fn, unsigned int index)
{
  basic_block bb = alloc_block ();
  bb->index = index;
  SET_BASIC_BLOCK_FOR_FUNCTION (fn, index, bb);
  bb->il.tree = GGC_CNEW (struct tree_bb_info);
  bb->flags = 0;
  return bb;
}


/* Read in the next basic block.  */

static void
input_bb (struct input_block *ib, unsigned int tag, 
	  struct function *fn, struct fun_in *fun_in)
{
  unsigned int index;
  unsigned int edge_count;
  basic_block bb;
  unsigned int i;
  block_stmt_iterator bsi;

  LTO_DEBUG_TOKEN ("bbindex")
  index = input_uleb128 (ib);
  LTO_DEBUG_TOKEN ("edgecount")
  edge_count = input_uleb128 (ib);
  bb = BASIC_BLOCK_FOR_FUNCTION (fn, index);
  /* There are several reasons why the slot may already have a block.
     Either it is the entry or exit block or else it was the
     destination of a block that was created earlier.  */ 
  if (bb == NULL)
    make_new_block (fn, index);

  /* Connect up the cfg.  */
  for (i=0; i<edge_count; i++)
    {
      LTO_DEBUG_TOKEN ("dest")
      unsigned int dest_index = input_uleb128 (ib);
      LTO_DEBUG_TOKEN ("eflags")
      unsigned int edge_flags = input_uleb128 (ib);
      basic_block dest = BASIC_BLOCK_FOR_FUNCTION (fn, dest_index);
      if (dest == NULL) 
	dest = make_new_block (fn, dest_index);
      make_edge (bb, dest, edge_flags);
    }

  /* LTO_bb1 has stmts, LTO_bb0 does not.  */
  if (tag == LTO_bb0)
    {
      LTO_DEBUG_UNDENT()
      return;
    }

  bsi = bsi_start (bb);
  LTO_DEBUG_INDENT_TOKEN ("stmt")
  tag = input_record_start (ib);
  while (tag)
    {
      tree stmt = input_expr_operand (ib, fun_in, tag);
      bsi_insert_after (&bsi, stmt, BSI_NEW_STMT);
      LTO_DEBUG_INDENT_TOKEN ("stmt")
      tag = input_record_start (ib);
      /* FIXME, add code to handle the exception.  */
    }
  LTO_DEBUG_UNDENT()
}


/* Fill in the body of FN.  */

static void
input_function (tree fn_decl, struct fun_in *fun_in, 
		const char *data, unsigned int size)
{
  struct function *fn = DECL_STRUCT_FUNCTION (fn_decl);
  struct input_block ib = {data, 0, size};
  unsigned int tag = input_record_start (&ib);
  unsigned int last_bb_index;

  tree_register_cfg_hooks ();
  gcc_assert (tag == LTO_function);

  input_eh_regions (&ib, fn, fun_in);

  last_bb_index = input_uleb128 (&ib);
  init_cfg (fn, last_bb_index);
  tag = input_record_start (&ib);
  while (tag)
    {
      input_bb (&ib, tag, fn, fun_in);
      tag = input_record_start (&ib);
    }

  finalize_cfg (fn, last_bb_index);
  LTO_DEBUG_UNDENT()
}


static bool initialized_local = false;

/* Static initialization for the lto writer.  */

static void
lto_static_init_local (void)
{
  if (initialized_local)
    return;

  initialized_local = true;

  /* Initialize the expression to tag mapping.  */
#define MAP_EXPR_TAG(expr,tag)   tag_to_expr [tag] = expr;
#define MAP_EXPR_TAGS(expr,tag,count) \
  {                                   \
    int i;                            \
    for (i=0; i<count; i++)           \
      tag_to_expr [tag + i] = expr;   \
  }
#define TREE_MULTIPLE
#define TREE_SINGLE_MECHANICAL_TRUE
#define TREE_SINGLE_MECHANICAL_FALSE
#define SET_NAME(a,b)
#include "lto-tree-tags.def"

#undef MAP_EXPR_TAG
#undef MAP_EXPR_TAGS
#undef TREE_MULTIPLE
#undef TREE_SINGLE_MECHANICAL_TRUE
#undef TREE_SINGLE_MECHANICAL_FALSE
#undef SET_NAME
  /* Initialize num_flags_for_code.  */


#define START_CLASS_SWITCH()                  \
  {                                           \
    int code;				      \
    for (code=0; code<NUM_TREE_CODES; code++) \
      {                                       \
	/* The 2 leaves room for file and line number for exprs.  */ \
	if (IS_EXPR_CODE_CLASS (TREE_CODE_CLASS (code)))  \
          num_flags_for_code[code] = 2;	      \
	else                                  \
          num_flags_for_code[code] = 0;	      \
                                              \
        switch (TREE_CODE_CLASS (code))       \
          {

#define START_CLASS_CASE(class)    case class:
#define ADD_CLASS_FLAG(flag_name)    num_flags_for_code[code]++;
#define END_CLASS_CASE(class)      break;
#define END_CLASS_SWITCH()                    \
          default:                            \
            gcc_unreachable ();               \
          }


#define START_EXPR_SWITCH()                   \
        switch (code)			      \
          {
#define START_EXPR_CASE(code)    case code:
#define ADD_EXPR_FLAG(flag_name)    num_flags_for_code[code]++;
#define ADD_DECL_FLAG(flag_name)    num_flags_for_code[code]++;
#define ADD_VIS_FLAG(flag_name)     num_flags_for_code[code]++;
#define ADD_FUNC_FLAG(flag_name)    num_flags_for_code[code]++;
#define END_EXPR_CASE(class)      break;
#define END_EXPR_SWITCH()                     \
          default:                            \
            gcc_unreachable ();               \
          }                                   \
      }					      \
  }

#include "lto-tree-flags.def"

#undef START_CLASS_SWITCH
#undef START_CLASS_CASE
#undef ADD_CLASS_FLAG
#undef END_CLASS_CASE
#undef END_CLASS_SWITCH
#undef START_EXPR_SWITCH
#undef START_EXPR_CASE
#undef ADD_EXPR_FLAG
#undef ADD_DECL_FLAG
#undef ADD_VIS_FLAG
#undef ADD_FUNC_FLAG
#undef END_EXPR_CASE
#undef END_EXPR_SWITCH

  lto_static_init ();
}


/* Read the body form DATA for function FN and fill it in.  FD and
   CONTEXT are magic cookies used to resolve global decls and
   types.  */
 
void 
lto_read_function_body (lto_info_fd *fd,
			lto_context *context,
			tree fn_decl,
			const void *data)
{
  struct lto_function_header * header 
    = (struct lto_function_header *) data;
  struct fun_in fun_in;
  int32_t fields_offset = sizeof (struct lto_function_header); 
  int32_t fns_offset 
    = fields_offset + 
    (header->num_field_decls * sizeof (lto_ref));
  int32_t vars_offset 
    = fns_offset + 
    (header->num_fn_decls * sizeof (lto_ref));
  int32_t types_offset 
    = vars_offset + 
    (header->num_var_decls * sizeof (lto_ref));
  int32_t named_labels_offset 
    = types_offset + 
    (header->num_types * sizeof (lto_ref));
  int32_t locals_offset = named_labels_offset + header->named_label_size;
  int32_t main_offset = locals_offset + header->local_decls_size;
  int32_t string_offset = main_offset + header->main_size;

#ifdef LTO_STREAM_DEBUGGING
  int32_t debug_decl_offset = string_offset + header->string_size;
  int32_t debug_label_offset = debug_decl_offset + header->debug_decl_size;
  int32_t debug_main_offset = debug_label_offset + header->debug_label_size;

  struct input_block debug_decl 
    = {data + debug_decl_offset, 0, header->debug_decl_size};
  struct input_block debug_label 
    = {data + debug_label_offset, 0, header->debug_label_size};
  struct input_block debug_main 
    = {data + debug_main_offset, 0, header->debug_main_size};
#endif

  lto_ref *in_field_decls = (lto_ref*)(data + fields_offset);
  lto_ref *in_fn_decls    = (lto_ref*)(data + fns_offset);
  lto_ref *in_var_decls   = (lto_ref*)(data + vars_offset);
  lto_ref *in_types       = (lto_ref*)(data + types_offset);

  const char * named_labels = data + named_labels_offset;
  const char * local_decls  = data + locals_offset;
  const char * main_gimple  = data + main_offset;

#ifdef LTO_STREAM_DEBUGGING
  lto_debug_context.out = debug_out_fun;
  lto_debug_context.indent = 0;
  lto_debug_context.current_data = &debug_label;
#endif

  fun_in.strings            = data + string_offset;
  fun_in.strings_len        = header->string_size;

  lto_static_init_local ();

  /* No upward compatibility here.  */
  gcc_assert (header->major_version == LTO_major_version);
  gcc_assert (header->minor_version == LTO_minor_version);

  input_globals (header, fd, context, &fun_in, 
		in_field_decls, in_fn_decls, 
		in_var_decls, in_types);

  fun_in.num_named_labels = header->num_named_labels;
  input_labels (&fun_in, named_labels, 
		header->named_label_size, 
		header->num_named_labels, header->num_unnamed_labels);

#ifdef LTO_STREAM_DEBUGGING
  lto_debug_context.current_data = &debug_decl;
#endif
  input_local_vars (&fun_in, local_decls, 
		    header->local_decls_size, header->num_local_decls);

#ifdef LTO_STREAM_DEBUGGING
  lto_debug_context.current_data = &debug_main;
#if 0
  dump_debug_stream ((struct input_block *)lto_debug_context.current_data, 
		     ' ', ' ');
#endif
#endif

  /* Set up the struct function.  */
  input_function (fn_decl, &fun_in, main_gimple, header->main_size);
}


/* Dump the debug STREAM, and two characters B and C.  */

static void 
dump_debug_stream (struct input_block *stream, char b, char c)
{
  unsigned int i = 0;
  bool new_line = true;
  int chars = 0;
  int hit_pos = -1;
  fprintf (stderr, 
	   "stream failure: looking for '%c' found '%c' at stream->%d\n\n",
	   c, b, stream->p);
  
  while (i < stream->len)
    {
      char x;
      
      if (new_line)
	{
	  if (hit_pos >= 0)
	    {
	      int j;
	      fprintf (stderr, "             ");
	      for (j=0; j<hit_pos; j++)
		fputc (' ', stderr);
	      fprintf (stderr, "^\n             ");
	      for (j=0; j<hit_pos; j++)
		fputc (' ', stderr);
	      fprintf (stderr, "|\n");
	      hit_pos = -1;
	    }
	  
	  fprintf (stderr, "%6d   -->>", i);
	  new_line = false;
	  chars = 0;
	}
      
      x = stream->data[i++];
      if (x == '\n')
	{
	  fprintf (stderr, "<<--\n");
	  new_line = true;
	}
      else 
	fputc (x, stderr);
      
      if (i == stream->p)
	hit_pos = chars;
      chars++;
    }
}


#ifdef LTO_STREAM_DEBUGGING

/* The low level output routine to for a single character.  Unlike the
   version on the writing side, this does interesting processing.

   This call checks that the debugging information generated by
   lto-function-out matches the debugging information generated by the
   reader. Each character is checked and a call to abort is generated
   when the first mismatch is found.  
  */

static void
debug_out_fun (struct lto_debug_context *context, char c)
{
  struct input_block *stream = (struct input_block *)context->current_data;
  unsigned char b = input_1_unsigned (stream);

  if (b != c)
    {
      dump_debug_stream (stream, b, c);
      gcc_unreachable ();
    }
}
    
#endif
