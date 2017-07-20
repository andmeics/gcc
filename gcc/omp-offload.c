/* Bits of OpenMP and OpenACC handling that is specific to device offloading
   and a lowering pass for OpenACC device directives.

   Copyright (C) 2005-2017 Free Software Foundation, Inc.

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

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "target.h"
#include "tree.h"
#include "gimple.h"
#include "tree-pass.h"
#include "ssa.h"
#include "cgraph.h"
#include "pretty-print.h"
#include "diagnostic-core.h"
#include "fold-const.h"
#include "internal-fn.h"
#include "langhooks.h"
#include "gimplify.h"
#include "gimple-iterator.h"
#include "gimplify-me.h"
#include "gimple-walk.h"
#include "tree-cfg.h"
#include "tree-into-ssa.h"
#include "tree-nested.h"
#include "stor-layout.h"
#include "common/common-target.h"
#include "omp-general.h"
#include "omp-offload.h"
#include "lto-section-names.h"
#include "gomp-constants.h"
#include "gimple-pretty-print.h"
#include "intl.h"

/* Describe the OpenACC looping structure of a function.  The entire
   function is held in a 'NULL' loop.  */

struct oacc_loop
{
  oacc_loop *parent; /* Containing loop.  */

  oacc_loop *child; /* First inner loop.  */

  oacc_loop *sibling; /* Next loop within same parent.  */

  location_t loc; /* Location of the loop start.  */

  gcall *marker; /* Initial head marker.  */

  gcall *heads[GOMP_DIM_MAX];  /* Head marker functions.  */
  gcall *tails[GOMP_DIM_MAX];  /* Tail marker functions.  */

  tree routine;  /* Pseudo-loop enclosing a routine.  */

  unsigned mask;   /* Partitioning mask.  */
  unsigned e_mask; /* Partitioning of element loops (when tiling).  */
  unsigned inner;  /* Partitioning of inner loops.  */
  unsigned flags;  /* Partitioning flags.  */
  vec<gcall *> ifns;  /* Contained loop abstraction functions.  */
  tree chunk_size; /* Chunk size.  */
  gcall *head_end; /* Final marker of head sequence.  */
};

/* Holds offload tables with decls.  */
vec<tree, va_gc> *offload_funcs, *offload_vars;

/* Return level at which oacc routine may spawn a partitioned loop, or
   -1 if it is not a routine (i.e. is an offload fn).  */

static int
oacc_fn_attrib_level (tree attr)
{
  tree pos = TREE_VALUE (attr);

  if (!TREE_PURPOSE (pos))
    return -1;

  int ix = 0;
  for (ix = 0; ix != GOMP_DIM_MAX;
       ix++, pos = TREE_CHAIN (pos))
    if (!integer_zerop (TREE_PURPOSE (pos)))
      break;

  return ix;
}

/* Helper function for omp_finish_file routine.  Takes decls from V_DECLS and
   adds their addresses and sizes to constructor-vector V_CTOR.  */

static void
add_decls_addresses_to_decl_constructor (vec<tree, va_gc> *v_decls,
					 vec<constructor_elt, va_gc> *v_ctor)
{
  unsigned len = vec_safe_length (v_decls);
  for (unsigned i = 0; i < len; i++)
    {
      tree it = (*v_decls)[i];
      bool is_var = VAR_P (it);
      bool is_link_var
	= is_var
#ifdef ACCEL_COMPILER
	  && DECL_HAS_VALUE_EXPR_P (it)
#endif
	  && lookup_attribute ("omp declare target link", DECL_ATTRIBUTES (it));

      tree size = NULL_TREE;
      if (is_var)
	size = fold_convert (const_ptr_type_node, DECL_SIZE_UNIT (it));

      tree addr;
      if (!is_link_var)
	addr = build_fold_addr_expr (it);
      else
	{
#ifdef ACCEL_COMPILER
	  /* For "omp declare target link" vars add address of the pointer to
	     the target table, instead of address of the var.  */
	  tree value_expr = DECL_VALUE_EXPR (it);
	  tree link_ptr_decl = TREE_OPERAND (value_expr, 0);
	  varpool_node::finalize_decl (link_ptr_decl);
	  addr = build_fold_addr_expr (link_ptr_decl);
#else
	  addr = build_fold_addr_expr (it);
#endif

	  /* Most significant bit of the size marks "omp declare target link"
	     vars in host and target tables.  */
	  unsigned HOST_WIDE_INT isize = tree_to_uhwi (size);
	  isize |= 1ULL << (int_size_in_bytes (const_ptr_type_node)
			    * BITS_PER_UNIT - 1);
	  size = wide_int_to_tree (const_ptr_type_node, isize);
	}

      CONSTRUCTOR_APPEND_ELT (v_ctor, NULL_TREE, addr);
      if (is_var)
	CONSTRUCTOR_APPEND_ELT (v_ctor, NULL_TREE, size);
    }
}

/* Create new symbols containing (address, size) pairs for global variables,
   marked with "omp declare target" attribute, as well as addresses for the
   functions, which are outlined offloading regions.  */
void
omp_finish_file (void)
{
  unsigned num_funcs = vec_safe_length (offload_funcs);
  unsigned num_vars = vec_safe_length (offload_vars);

  if (num_funcs == 0 && num_vars == 0)
    return;

  if (targetm_common.have_named_sections)
    {
      vec<constructor_elt, va_gc> *v_f, *v_v;
      vec_alloc (v_f, num_funcs);
      vec_alloc (v_v, num_vars * 2);

      add_decls_addresses_to_decl_constructor (offload_funcs, v_f);
      add_decls_addresses_to_decl_constructor (offload_vars, v_v);

      tree vars_decl_type = build_array_type_nelts (pointer_sized_int_node,
						    num_vars * 2);
      tree funcs_decl_type = build_array_type_nelts (pointer_sized_int_node,
						     num_funcs);
      SET_TYPE_ALIGN (vars_decl_type, TYPE_ALIGN (pointer_sized_int_node));
      SET_TYPE_ALIGN (funcs_decl_type, TYPE_ALIGN (pointer_sized_int_node));
      tree ctor_v = build_constructor (vars_decl_type, v_v);
      tree ctor_f = build_constructor (funcs_decl_type, v_f);
      TREE_CONSTANT (ctor_v) = TREE_CONSTANT (ctor_f) = 1;
      TREE_STATIC (ctor_v) = TREE_STATIC (ctor_f) = 1;
      tree funcs_decl = build_decl (UNKNOWN_LOCATION, VAR_DECL,
				    get_identifier (".offload_func_table"),
				    funcs_decl_type);
      tree vars_decl = build_decl (UNKNOWN_LOCATION, VAR_DECL,
				   get_identifier (".offload_var_table"),
				   vars_decl_type);
      TREE_STATIC (funcs_decl) = TREE_STATIC (vars_decl) = 1;
      /* Do not align tables more than TYPE_ALIGN (pointer_sized_int_node),
	 otherwise a joint table in a binary will contain padding between
	 tables from multiple object files.  */
      DECL_USER_ALIGN (funcs_decl) = DECL_USER_ALIGN (vars_decl) = 1;
      SET_DECL_ALIGN (funcs_decl, TYPE_ALIGN (funcs_decl_type));
      SET_DECL_ALIGN (vars_decl, TYPE_ALIGN (vars_decl_type));
      DECL_INITIAL (funcs_decl) = ctor_f;
      DECL_INITIAL (vars_decl) = ctor_v;
      set_decl_section_name (funcs_decl, OFFLOAD_FUNC_TABLE_SECTION_NAME);
      set_decl_section_name (vars_decl, OFFLOAD_VAR_TABLE_SECTION_NAME);

      varpool_node::finalize_decl (vars_decl);
      varpool_node::finalize_decl (funcs_decl);
    }
  else
    {
      for (unsigned i = 0; i < num_funcs; i++)
	{
	  tree it = (*offload_funcs)[i];
	  targetm.record_offload_symbol (it);
	}
      for (unsigned i = 0; i < num_vars; i++)
	{
	  tree it = (*offload_vars)[i];
	  targetm.record_offload_symbol (it);
	}
    }
}

/* Call dim_pos (POS == true) or dim_size (POS == false) builtins for
   axis DIM.  Return a tmp var holding the result.  */

static tree
oacc_dim_call (bool pos, int dim, gimple_seq *seq)
{
  tree arg = build_int_cst (unsigned_type_node, dim);
  tree size = create_tmp_var (integer_type_node);
  enum internal_fn fn = pos ? IFN_GOACC_DIM_POS : IFN_GOACC_DIM_SIZE;
  gimple *call = gimple_build_call_internal (fn, 1, arg);

  gimple_call_set_lhs (call, size);
  gimple_seq_add_stmt (seq, call);

  return size;
}

/* Find the number of threads (POS = false), or thread number (POS =
   true) for an OpenACC region partitioned as MASK.  Setup code
   required for the calculation is added to SEQ.  */

static tree
oacc_thread_numbers (bool pos, int mask, gimple_seq *seq)
{
  tree res = pos ? NULL_TREE : build_int_cst (unsigned_type_node, 1);
  unsigned ix;

  /* Start at gang level, and examine relevant dimension indices.  */
  for (ix = GOMP_DIM_GANG; ix != GOMP_DIM_MAX; ix++)
    if (GOMP_DIM_MASK (ix) & mask)
      {
	if (res)
	  {
	    /* We had an outer index, so scale that by the size of
	       this dimension.  */
	    tree n = oacc_dim_call (false, ix, seq);
	    res = fold_build2 (MULT_EXPR, integer_type_node, res, n);
	  }
	if (pos)
	  {
	    /* Determine index in this dimension.  */
	    tree id = oacc_dim_call (true, ix, seq);
	    if (res)
	      res = fold_build2 (PLUS_EXPR, integer_type_node, res, id);
	    else
	      res = id;
	  }
      }

  if (res == NULL_TREE)
    res = integer_zero_node;

  return res;
}

/* Transform IFN_GOACC_LOOP calls to actual code.  See
   expand_oacc_for for where these are generated.  At the vector
   level, we stride loops, such that each member of a warp will
   operate on adjacent iterations.  At the worker and gang level,
   each gang/warp executes a set of contiguous iterations.  Chunking
   can override this such that each iteration engine executes a
   contiguous chunk, and then moves on to stride to the next chunk.  */

static void
oacc_xform_loop (gcall *call)
{
  gimple_stmt_iterator gsi = gsi_for_stmt (call);
  enum ifn_goacc_loop_kind code
    = (enum ifn_goacc_loop_kind) TREE_INT_CST_LOW (gimple_call_arg (call, 0));
  tree dir = gimple_call_arg (call, 1);
  tree range = gimple_call_arg (call, 2);
  tree step = gimple_call_arg (call, 3);
  tree chunk_size = NULL_TREE;
  unsigned mask = (unsigned) TREE_INT_CST_LOW (gimple_call_arg (call, 5));
  tree lhs = gimple_call_lhs (call);
  tree type = TREE_TYPE (lhs);
  tree diff_type = TREE_TYPE (range);
  tree r = NULL_TREE;
  gimple_seq seq = NULL;
  bool chunking = false, striding = true;
  unsigned outer_mask = mask & (~mask + 1); // Outermost partitioning
  unsigned inner_mask = mask & ~outer_mask; // Inner partitioning (if any)

#ifdef ACCEL_COMPILER
  chunk_size = gimple_call_arg (call, 4);
  if (integer_minus_onep (chunk_size)  /* Force static allocation.  */
      || integer_zerop (chunk_size))   /* Default (also static).  */
    {
      /* If we're at the gang level, we want each to execute a
	 contiguous run of iterations.  Otherwise we want each element
	 to stride.  */
      striding = !(outer_mask & GOMP_DIM_MASK (GOMP_DIM_GANG));
      chunking = false;
    }
  else
    {
      /* Chunk of size 1 is striding.  */
      striding = integer_onep (chunk_size);
      chunking = !striding;
    }
#endif

  /* striding=true, chunking=true
       -> invalid.
     striding=true, chunking=false
       -> chunks=1
     striding=false,chunking=true
       -> chunks=ceil (range/(chunksize*threads*step))
     striding=false,chunking=false
       -> chunk_size=ceil(range/(threads*step)),chunks=1  */
  push_gimplify_context (true);

  switch (code)
    {
    default: gcc_unreachable ();

    case IFN_GOACC_LOOP_CHUNKS:
      if (!chunking)
	r = build_int_cst (type, 1);
      else
	{
	  /* chunk_max
	     = (range - dir) / (chunks * step * num_threads) + dir  */
	  tree per = oacc_thread_numbers (false, mask, &seq);
	  per = fold_convert (type, per);
	  chunk_size = fold_convert (type, chunk_size);
	  per = fold_build2 (MULT_EXPR, type, per, chunk_size);
	  per = fold_build2 (MULT_EXPR, type, per, step);
	  r = build2 (MINUS_EXPR, type, range, dir);
	  r = build2 (PLUS_EXPR, type, r, per);
	  r = build2 (TRUNC_DIV_EXPR, type, r, per);
	}
      break;

    case IFN_GOACC_LOOP_STEP:
      {
	/* If striding, step by the entire compute volume, otherwise
	   step by the inner volume.  */
	unsigned volume = striding ? mask : inner_mask;

	r = oacc_thread_numbers (false, volume, &seq);
	r = build2 (MULT_EXPR, type, fold_convert (type, r), step);
      }
      break;

    case IFN_GOACC_LOOP_OFFSET:
      if (striding)
	{
	  r = oacc_thread_numbers (true, mask, &seq);
	  r = fold_convert (diff_type, r);
	}
      else
	{
	  tree inner_size = oacc_thread_numbers (false, inner_mask, &seq);
	  tree outer_size = oacc_thread_numbers (false, outer_mask, &seq);
	  tree volume = fold_build2 (MULT_EXPR, TREE_TYPE (inner_size),
				     inner_size, outer_size);

	  volume = fold_convert (diff_type, volume);
	  if (chunking)
	    chunk_size = fold_convert (diff_type, chunk_size);
	  else
	    {
	      tree per = fold_build2 (MULT_EXPR, diff_type, volume, step);

	      chunk_size = build2 (MINUS_EXPR, diff_type, range, dir);
	      chunk_size = build2 (PLUS_EXPR, diff_type, chunk_size, per);
	      chunk_size = build2 (TRUNC_DIV_EXPR, diff_type, chunk_size, per);
	    }

	  tree span = build2 (MULT_EXPR, diff_type, chunk_size,
			      fold_convert (diff_type, inner_size));
	  r = oacc_thread_numbers (true, outer_mask, &seq);
	  r = fold_convert (diff_type, r);
	  r = build2 (MULT_EXPR, diff_type, r, span);

	  tree inner = oacc_thread_numbers (true, inner_mask, &seq);
	  inner = fold_convert (diff_type, inner);
	  r = fold_build2 (PLUS_EXPR, diff_type, r, inner);

	  if (chunking)
	    {
	      tree chunk = fold_convert (diff_type, gimple_call_arg (call, 6));
	      tree per
		= fold_build2 (MULT_EXPR, diff_type, volume, chunk_size);
	      per = build2 (MULT_EXPR, diff_type, per, chunk);

	      r = build2 (PLUS_EXPR, diff_type, r, per);
	    }
	}
      r = fold_build2 (MULT_EXPR, diff_type, r, step);
      if (type != diff_type)
	r = fold_convert (type, r);
      break;

    case IFN_GOACC_LOOP_BOUND:
      if (striding)
	r = range;
      else
	{
	  tree inner_size = oacc_thread_numbers (false, inner_mask, &seq);
	  tree outer_size = oacc_thread_numbers (false, outer_mask, &seq);
	  tree volume = fold_build2 (MULT_EXPR, TREE_TYPE (inner_size),
				     inner_size, outer_size);

	  volume = fold_convert (diff_type, volume);
	  if (chunking)
	    chunk_size = fold_convert (diff_type, chunk_size);
	  else
	    {
	      tree per = fold_build2 (MULT_EXPR, diff_type, volume, step);

	      chunk_size = build2 (MINUS_EXPR, diff_type, range, dir);
	      chunk_size = build2 (PLUS_EXPR, diff_type, chunk_size, per);
	      chunk_size = build2 (TRUNC_DIV_EXPR, diff_type, chunk_size, per);
	    }

	  tree span = build2 (MULT_EXPR, diff_type, chunk_size,
			      fold_convert (diff_type, inner_size));

	  r = fold_build2 (MULT_EXPR, diff_type, span, step);

	  tree offset = gimple_call_arg (call, 6);
	  r = build2 (PLUS_EXPR, diff_type, r,
		      fold_convert (diff_type, offset));
	  r = build2 (integer_onep (dir) ? MIN_EXPR : MAX_EXPR,
		      diff_type, r, range);
	}
      if (diff_type != type)
	r = fold_convert (type, r);
      break;
    }

  gimplify_assign (lhs, r, &seq);

  pop_gimplify_context (NULL);

  gsi_replace_with_seq (&gsi, seq, true);
}

/* Transform a GOACC_TILE call.  Determines the element loop span for
   the specified loop of the nest.  This is 1 if we're not tiling.
   
   GOACC_TILE (collapse_count, loop_no, tile_arg, gwv_tile, gwv_element);  */

static void
oacc_xform_tile (gcall *call)
{
  gimple_stmt_iterator gsi = gsi_for_stmt (call);
  unsigned collapse = tree_to_uhwi (gimple_call_arg (call, 0));
  /* Inner loops have higher loop_nos.  */
  unsigned loop_no = tree_to_uhwi (gimple_call_arg (call, 1));
  tree tile_size = gimple_call_arg (call, 2);
  unsigned e_mask = tree_to_uhwi (gimple_call_arg (call, 4));
  tree lhs = gimple_call_lhs (call);
  tree type = TREE_TYPE (lhs);
  gimple_seq seq = NULL;
  tree span = build_int_cst (type, 1);

  gcc_assert (!(e_mask
		& ~(GOMP_DIM_MASK (GOMP_DIM_VECTOR)
		    | GOMP_DIM_MASK (GOMP_DIM_WORKER))));
  push_gimplify_context (!seen_error ());

#ifndef ACCEL_COMPILER
  /* Partitioning disabled on host compilers.  */
  e_mask = 0;
#endif
  if (!e_mask)
    /* Not paritioning.  */
    span = integer_one_node;
  else if (!integer_zerop (tile_size))
    /* User explicitly specified size.  */
    span = tile_size;
  else
    {
      /* Pick a size based on the paritioning of the element loop and
	 the number of loop nests.  */
      tree first_size = NULL_TREE;
      tree second_size = NULL_TREE;

      if (e_mask & GOMP_DIM_MASK (GOMP_DIM_VECTOR))
	first_size = oacc_dim_call (false, GOMP_DIM_VECTOR, &seq);
      if (e_mask & GOMP_DIM_MASK (GOMP_DIM_WORKER))
	second_size = oacc_dim_call (false, GOMP_DIM_WORKER, &seq);

      if (!first_size)
	{
	  first_size = second_size;
	  second_size = NULL_TREE;
	}

      if (loop_no + 1 == collapse)
	{
	  span = first_size;
	  if (!loop_no && second_size)
	    span = fold_build2 (MULT_EXPR, TREE_TYPE (span),
				span, second_size);
	}
      else if (loop_no + 2 == collapse)
	span = second_size;
      else
	span = NULL_TREE;

      if (!span)
	/* There's no obvious element size for this loop.  Options
	   are 1, first_size or some non-unity constant (32 is my
	   favourite).   We should gather some statistics.  */
	span = first_size;
    }

  span = fold_convert (type, span);
  gimplify_assign (lhs, span, &seq);

  pop_gimplify_context (NULL);

  gsi_replace_with_seq (&gsi, seq, true);
}

/* Default partitioned and minimum partitioned dimensions.  */

static int oacc_default_dims[GOMP_DIM_MAX];
static int oacc_min_dims[GOMP_DIM_MAX];

/* Parse the default dimension parameter.  This is a set of
   :-separated optional compute dimensions.  Each specified dimension
   is a positive integer.  When device type support is added, it is
   planned to be a comma separated list of such compute dimensions,
   with all but the first prefixed by the colon-terminated device
   type.  */

static void
oacc_parse_default_dims (const char *dims)
{
  int ix;

  for (ix = GOMP_DIM_MAX; ix--;)
    {
      oacc_default_dims[ix] = -1;
      oacc_min_dims[ix] = 1;
    }

#ifndef ACCEL_COMPILER
  /* Cannot be overridden on the host.  */
  dims = NULL;
#endif
  if (dims)
    {
      const char *pos = dims;

      for (ix = 0; *pos && ix != GOMP_DIM_MAX; ix++)
	{
	  if (ix)
	    {
	      if (*pos != ':')
		goto malformed;
	      pos++;
	    }

	  if (*pos != ':')
	    {
	      long val;
	      const char *eptr;

	      errno = 0;
	      val = strtol (pos, CONST_CAST (char **, &eptr), 10);
	      if (errno || val <= 0 || (int) val != val)
		goto malformed;
	      pos = eptr;
	      oacc_default_dims[ix] = (int) val;
	    }
	}
      if (*pos)
	{
	malformed:
	  error_at (UNKNOWN_LOCATION,
		    "-fopenacc-dim operand is malformed at '%s'", pos);
	}
    }

  /* Allow the backend to validate the dimensions.  */
  targetm.goacc.validate_dims (NULL_TREE, oacc_default_dims, -1);
  targetm.goacc.validate_dims (NULL_TREE, oacc_min_dims, -2);
}

/* Validate and update the dimensions for offloaded FN.  ATTRS is the
   raw attribute.  DIMS is an array of dimensions, which is filled in.
   LEVEL is the partitioning level of a routine, or -1 for an offload
   region itself.  USED is the mask of partitioned execution in the
   function.  */

static void
oacc_validate_dims (tree fn, tree attrs, int *dims, int level, unsigned used)
{
  tree purpose[GOMP_DIM_MAX];
  unsigned ix;
  tree pos = TREE_VALUE (attrs);

  /* Make sure the attribute creator attached the dimension
     information.  */
  gcc_assert (pos);

  for (ix = 0; ix != GOMP_DIM_MAX; ix++)
    {
      purpose[ix] = TREE_PURPOSE (pos);
      tree val = TREE_VALUE (pos);
      dims[ix] = val ? TREE_INT_CST_LOW (val) : -1;
      pos = TREE_CHAIN (pos);
    }

  bool changed = targetm.goacc.validate_dims (fn, dims, level);

  /* Default anything left to 1 or a partitioned default.  */
  for (ix = 0; ix != GOMP_DIM_MAX; ix++)
    if (dims[ix] < 0)
      {
	/* The OpenACC spec says 'If the [num_gangs] clause is not
	   specified, an implementation-defined default will be used;
	   the default may depend on the code within the construct.'
	   (2.5.6).  Thus an implementation is free to choose
	   non-unity default for a parallel region that doesn't have
	   any gang-partitioned loops.  However, it appears that there
	   is a sufficient body of user code that expects non-gang
	   partitioned regions to not execute in gang-redundant mode.
	   So we (a) don't warn about the non-portability and (b) pick
	   the minimum permissible dimension size when there is no
	   partitioned execution.  Otherwise we pick the global
	   default for the dimension, which the user can control.  The
	   same wording and logic applies to num_workers and
	   vector_length, however the worker- or vector- single
	   execution doesn't have the same impact as gang-redundant
	   execution.  (If the minimum gang-level partioning is not 1,
	   the target is probably too confusing.)  */
	dims[ix] = (used & GOMP_DIM_MASK (ix)
		    ? oacc_default_dims[ix] : oacc_min_dims[ix]);
	changed = true;
      }

  if (changed)
    {
      /* Replace the attribute with new values.  */
      pos = NULL_TREE;
      for (ix = GOMP_DIM_MAX; ix--;)
	pos = tree_cons (purpose[ix],
			 build_int_cst (integer_type_node, dims[ix]), pos);
      oacc_replace_fn_attrib (fn, pos);
    }
}

/* Create an empty OpenACC loop structure at LOC.  */

static oacc_loop *
new_oacc_loop_raw (oacc_loop *parent, location_t loc)
{
  oacc_loop *loop = XCNEW (oacc_loop);

  loop->parent = parent;

  if (parent)
    {
      loop->sibling = parent->child;
      parent->child = loop;
    }

  loop->loc = loc;
  return loop;
}

/* Create an outermost, dummy OpenACC loop for offloaded function
   DECL.  */

static oacc_loop *
new_oacc_loop_outer (tree decl)
{
  return new_oacc_loop_raw (NULL, DECL_SOURCE_LOCATION (decl));
}

/* Start a new OpenACC loop  structure beginning at head marker HEAD.
   Link into PARENT loop.  Return the new loop.  */

static oacc_loop *
new_oacc_loop (oacc_loop *parent, gcall *marker)
{
  oacc_loop *loop = new_oacc_loop_raw (parent, gimple_location (marker));

  loop->marker = marker;

  /* TODO: This is where device_type flattening would occur for the loop
     flags.  */

  loop->flags = TREE_INT_CST_LOW (gimple_call_arg (marker, 3));

  tree chunk_size = integer_zero_node;
  if (loop->flags & OLF_GANG_STATIC)
    chunk_size = gimple_call_arg (marker, 4);
  loop->chunk_size = chunk_size;

  return loop;
}

/* Create a dummy loop encompassing a call to a openACC routine.
   Extract the routine's partitioning requirements.  */

static void
new_oacc_loop_routine (oacc_loop *parent, gcall *call, tree decl, tree attrs)
{
  oacc_loop *loop = new_oacc_loop_raw (parent, gimple_location (call));
  int level = oacc_fn_attrib_level (attrs);

  gcc_assert (level >= 0);

  loop->marker = call;
  loop->routine = decl;
  loop->mask = ((GOMP_DIM_MASK (GOMP_DIM_MAX) - 1)
		^ (GOMP_DIM_MASK (level) - 1));
}

/* Finish off the current OpenACC loop ending at tail marker TAIL.
   Return the parent loop.  */

static oacc_loop *
finish_oacc_loop (oacc_loop *loop)
{
  /* If the loop has been collapsed, don't partition it.  */
  if (loop->ifns.is_empty ())
    loop->mask = loop->flags = 0;
  return loop->parent;
}

/* Free all OpenACC loop structures within LOOP (inclusive).  */

static void
free_oacc_loop (oacc_loop *loop)
{
  if (loop->sibling)
    free_oacc_loop (loop->sibling);
  if (loop->child)
    free_oacc_loop (loop->child);

  loop->ifns.release ();
  free (loop);
}

/* Dump out the OpenACC loop head or tail beginning at FROM.  */

static void
dump_oacc_loop_part (FILE *file, gcall *from, int depth,
		     const char *title, int level)
{
  enum ifn_unique_kind kind
    = (enum ifn_unique_kind) TREE_INT_CST_LOW (gimple_call_arg (from, 0));

  fprintf (file, "%*s%s-%d:\n", depth * 2, "", title, level);
  for (gimple_stmt_iterator gsi = gsi_for_stmt (from);;)
    {
      gimple *stmt = gsi_stmt (gsi);

      if (gimple_call_internal_p (stmt, IFN_UNIQUE))
	{
	  enum ifn_unique_kind k
	    = ((enum ifn_unique_kind) TREE_INT_CST_LOW
	       (gimple_call_arg (stmt, 0)));

	  if (k == kind && stmt != from)
	    break;
	}
      print_gimple_stmt (file, stmt, depth * 2 + 2);

      gsi_next (&gsi);
      while (gsi_end_p (gsi))
	gsi = gsi_start_bb (single_succ (gsi_bb (gsi)));
    }
}

/* Dump OpenACC loops LOOP, its siblings and its children.  */

static void
dump_oacc_loop (FILE *file, oacc_loop *loop, int depth)
{
  int ix;

  fprintf (file, "%*sLoop %x(%x) %s:%u\n", depth * 2, "",
	   loop->flags, loop->mask,
	   LOCATION_FILE (loop->loc), LOCATION_LINE (loop->loc));

  if (loop->marker)
    print_gimple_stmt (file, loop->marker, depth * 2);

  if (loop->routine)
    fprintf (file, "%*sRoutine %s:%u:%s\n",
	     depth * 2, "", DECL_SOURCE_FILE (loop->routine),
	     DECL_SOURCE_LINE (loop->routine),
	     IDENTIFIER_POINTER (DECL_NAME (loop->routine)));

  for (ix = GOMP_DIM_GANG; ix != GOMP_DIM_MAX; ix++)
    if (loop->heads[ix])
      dump_oacc_loop_part (file, loop->heads[ix], depth, "Head", ix);
  for (ix = GOMP_DIM_MAX; ix--;)
    if (loop->tails[ix])
      dump_oacc_loop_part (file, loop->tails[ix], depth, "Tail", ix);

  if (loop->child)
    dump_oacc_loop (file, loop->child, depth + 1);
  if (loop->sibling)
    dump_oacc_loop (file, loop->sibling, depth);
}

void debug_oacc_loop (oacc_loop *);

/* Dump loops to stderr.  */

DEBUG_FUNCTION void
debug_oacc_loop (oacc_loop *loop)
{
  dump_oacc_loop (stderr, loop, 0);
}

/* DFS walk of basic blocks BB onwards, creating OpenACC loop
   structures as we go.  By construction these loops are properly
   nested.  */

static void
oacc_loop_discover_walk (oacc_loop *loop, basic_block bb)
{
  int marker = 0;
  int remaining = 0;

  if (bb->flags & BB_VISITED)
    return;

 follow:
  bb->flags |= BB_VISITED;

  /* Scan for loop markers.  */
  for (gimple_stmt_iterator gsi = gsi_start_bb (bb); !gsi_end_p (gsi);
       gsi_next (&gsi))
    {
      gimple *stmt = gsi_stmt (gsi);

      if (!is_gimple_call (stmt))
	continue;

      gcall *call = as_a <gcall *> (stmt);

      /* If this is a routine, make a dummy loop for it.  */
      if (tree decl = gimple_call_fndecl (call))
	if (tree attrs = oacc_get_fn_attrib (decl))
	  {
	    gcc_assert (!marker);
	    new_oacc_loop_routine (loop, call, decl, attrs);
	  }

      if (!gimple_call_internal_p (call))
	continue;

      switch (gimple_call_internal_fn (call))
	{
	default:
	  break;

	case IFN_GOACC_LOOP:
	case IFN_GOACC_TILE:
	  /* Record the abstraction function, so we can manipulate it
	     later.  */
	  loop->ifns.safe_push (call);
	  break;

	case IFN_UNIQUE:
	  enum ifn_unique_kind kind
	    = (enum ifn_unique_kind) (TREE_INT_CST_LOW
				      (gimple_call_arg (call, 0)));
	  if (kind == IFN_UNIQUE_OACC_HEAD_MARK
	      || kind == IFN_UNIQUE_OACC_TAIL_MARK)
	    {
	      if (gimple_call_num_args (call) == 2)
		{
		  gcc_assert (marker && !remaining);
		  marker = 0;
		  if (kind == IFN_UNIQUE_OACC_TAIL_MARK)
		    loop = finish_oacc_loop (loop);
		  else
		    loop->head_end = call;
		}
	      else
		{
		  int count = TREE_INT_CST_LOW (gimple_call_arg (call, 2));

		  if (!marker)
		    {
		      if (kind == IFN_UNIQUE_OACC_HEAD_MARK)
			loop = new_oacc_loop (loop, call);
		      remaining = count;
		    }
		  gcc_assert (count == remaining);
		  if (remaining)
		    {
		      remaining--;
		      if (kind == IFN_UNIQUE_OACC_HEAD_MARK)
			loop->heads[marker] = call;
		      else
			loop->tails[remaining] = call;
		    }
		  marker++;
		}
	    }
	}
    }
  if (remaining || marker)
    {
      bb = single_succ (bb);
      gcc_assert (single_pred_p (bb) && !(bb->flags & BB_VISITED));
      goto follow;
    }

  /* Walk successor blocks.  */
  edge e;
  edge_iterator ei;

  FOR_EACH_EDGE (e, ei, bb->succs)
    oacc_loop_discover_walk (loop, e->dest);
}

/* LOOP is the first sibling.  Reverse the order in place and return
   the new first sibling.  Recurse to child loops.  */

static oacc_loop *
oacc_loop_sibling_nreverse (oacc_loop *loop)
{
  oacc_loop *last = NULL;
  do
    {
      if (loop->child)
	loop->child = oacc_loop_sibling_nreverse (loop->child);

      oacc_loop *next = loop->sibling;
      loop->sibling = last;
      last = loop;
      loop = next;
    }
  while (loop);

  return last;
}

/* Discover the OpenACC loops marked up by HEAD and TAIL markers for
   the current function.  */

static oacc_loop *
oacc_loop_discovery ()
{
  /* Clear basic block flags, in particular BB_VISITED which we're going to use
     in the following.  */
  clear_bb_flags ();

  oacc_loop *top = new_oacc_loop_outer (current_function_decl);
  oacc_loop_discover_walk (top, ENTRY_BLOCK_PTR_FOR_FN (cfun));

  /* The siblings were constructed in reverse order, reverse them so
     that diagnostics come out in an unsurprising order.  */
  top = oacc_loop_sibling_nreverse (top);

  return top;
}

/* Transform the abstract internal function markers starting at FROM
   to be for partitioning level LEVEL.  Stop when we meet another HEAD
   or TAIL  marker.  */

static void
oacc_loop_xform_head_tail (gcall *from, int level)
{
  enum ifn_unique_kind kind
    = (enum ifn_unique_kind) TREE_INT_CST_LOW (gimple_call_arg (from, 0));
  tree replacement = build_int_cst (unsigned_type_node, level);

  for (gimple_stmt_iterator gsi = gsi_for_stmt (from);;)
    {
      gimple *stmt = gsi_stmt (gsi);

      if (gimple_call_internal_p (stmt, IFN_UNIQUE))
	{
	  enum ifn_unique_kind k
	    = ((enum ifn_unique_kind)
	       TREE_INT_CST_LOW (gimple_call_arg (stmt, 0)));

	  if (k == IFN_UNIQUE_OACC_FORK || k == IFN_UNIQUE_OACC_JOIN)
	    *gimple_call_arg_ptr (stmt, 2) = replacement;
	  else if (k == kind && stmt != from)
	    break;
	}
      else if (gimple_call_internal_p (stmt, IFN_GOACC_REDUCTION))
	*gimple_call_arg_ptr (stmt, 3) = replacement;

      gsi_next (&gsi);
      while (gsi_end_p (gsi))
	gsi = gsi_start_bb (single_succ (gsi_bb (gsi)));
    }
}

/* Process the discovered OpenACC loops, setting the correct
   partitioning level etc.  */

static void
oacc_loop_process (oacc_loop *loop)
{
  if (loop->child)
    oacc_loop_process (loop->child);

  if (loop->mask && !loop->routine)
    {
      int ix;
      tree mask_arg = build_int_cst (unsigned_type_node, loop->mask);
      tree e_mask_arg = build_int_cst (unsigned_type_node, loop->e_mask);
      tree chunk_arg = loop->chunk_size;
      gcall *call;
      
      for (ix = 0; loop->ifns.iterate (ix, &call); ix++)
	switch (gimple_call_internal_fn (call))
	  {
	  case IFN_GOACC_LOOP:
	    {
	      bool is_e = gimple_call_arg (call, 5) == integer_minus_one_node;
	      gimple_call_set_arg (call, 5, is_e ? e_mask_arg : mask_arg);
	      if (!is_e)
		gimple_call_set_arg (call, 4, chunk_arg);
	    }
	    break;

	  case IFN_GOACC_TILE:
	    gimple_call_set_arg (call, 3, mask_arg);
	    gimple_call_set_arg (call, 4, e_mask_arg);
	    break;

	  default:
	    gcc_unreachable ();
	  }

      unsigned dim = GOMP_DIM_GANG;
      unsigned mask = loop->mask | loop->e_mask;
      for (ix = 0; ix != GOMP_DIM_MAX && mask; ix++)
	{
	  while (!(GOMP_DIM_MASK (dim) & mask))
	    dim++;

	  oacc_loop_xform_head_tail (loop->heads[ix], dim);
	  oacc_loop_xform_head_tail (loop->tails[ix], dim);

	  mask ^= GOMP_DIM_MASK (dim);
	}
    }

  if (loop->sibling)
    oacc_loop_process (loop->sibling);
}

/* Walk the OpenACC loop heirarchy checking and assigning the
   programmer-specified partitionings.  OUTER_MASK is the partitioning
   this loop is contained within.  Return mask of partitioning
   encountered.  If any auto loops are discovered, set GOMP_DIM_MAX
   bit.  */

static unsigned
oacc_loop_fixed_partitions (oacc_loop *loop, unsigned outer_mask)
{
  unsigned this_mask = loop->mask;
  unsigned mask_all = 0;
  bool noisy = true;

#ifdef ACCEL_COMPILER
  /* When device_type is supported, we want the device compiler to be
     noisy, if the loop parameters are device_type-specific.  */
  noisy = false;
#endif

  if (!loop->routine)
    {
      bool auto_par = (loop->flags & OLF_AUTO) != 0;
      bool seq_par = (loop->flags & OLF_SEQ) != 0;
      bool tiling = (loop->flags & OLF_TILE) != 0;
      
      this_mask = ((loop->flags >> OLF_DIM_BASE)
		   & (GOMP_DIM_MASK (GOMP_DIM_MAX) - 1));

      /* Apply auto partitioning if this is a non-partitioned regular
	 loop, or (no more than) single axis tiled loop.  */
      bool maybe_auto
	= !seq_par && this_mask == (tiling ? this_mask & -this_mask : 0);

      if ((this_mask != 0) + auto_par + seq_par > 1)
	{
	  if (noisy)
	    error_at (loop->loc,
		      seq_par
		      ? G_("%<seq%> overrides other OpenACC loop specifiers")
		      : G_("%<auto%> conflicts with other OpenACC loop "
			   "specifiers"));
	  maybe_auto = false;
	  loop->flags &= ~OLF_AUTO;
	  if (seq_par)
	    {
	      loop->flags
		&= ~((GOMP_DIM_MASK (GOMP_DIM_MAX) - 1) << OLF_DIM_BASE);
	      this_mask = 0;
	    }
	}

      if (maybe_auto && (loop->flags & OLF_INDEPENDENT))
	{
	  loop->flags |= OLF_AUTO;
	  mask_all |= GOMP_DIM_MASK (GOMP_DIM_MAX);
	}
    }

  if (this_mask & outer_mask)
    {
      const oacc_loop *outer;
      for (outer = loop->parent; outer; outer = outer->parent)
	if ((outer->mask | outer->e_mask) & this_mask)
	  break;

      if (noisy)
	{
	  if (outer)
	    {
	      error_at (loop->loc,
			loop->routine
			? G_("routine call uses same OpenACC parallelism"
			     " as containing loop")
			: G_("inner loop uses same OpenACC parallelism"
			     " as containing loop"));
	      inform (outer->loc, "containing loop here");
	    }
	  else
	    error_at (loop->loc,
		      loop->routine
		      ? G_("routine call uses OpenACC parallelism disallowed"
			   " by containing routine")
		      : G_("loop uses OpenACC parallelism disallowed"
			   " by containing routine"));

	  if (loop->routine)
	    inform (DECL_SOURCE_LOCATION (loop->routine),
		    "routine %qD declared here", loop->routine);
	}
      this_mask &= ~outer_mask;
    }
  else
    {
      unsigned outermost = least_bit_hwi (this_mask);

      if (outermost && outermost <= outer_mask)
	{
	  if (noisy)
	    {
	      error_at (loop->loc,
			"incorrectly nested OpenACC loop parallelism");

	      const oacc_loop *outer;
	      for (outer = loop->parent;
		   outer->flags && outer->flags < outermost;
		   outer = outer->parent)
		continue;
	      inform (outer->loc, "containing loop here");
	    }

	  this_mask &= ~outermost;
	}
    }

  mask_all |= this_mask;

  if (loop->flags & OLF_TILE)
    {
      /* When tiling, vector goes to the element loop, and failing
	 that we put worker there.  The std doesn't contemplate
	 specifying all three.  We choose to put worker and vector on
	 the element loops in that case.  */
      unsigned this_e_mask = this_mask & GOMP_DIM_MASK (GOMP_DIM_VECTOR);
      if (!this_e_mask || this_mask & GOMP_DIM_MASK (GOMP_DIM_GANG))
	this_e_mask |= this_mask & GOMP_DIM_MASK (GOMP_DIM_WORKER);

      loop->e_mask = this_e_mask;
      this_mask ^= this_e_mask;
    }

  loop->mask = this_mask;

  if (dump_file)
    fprintf (dump_file, "Loop %s:%d user specified %d & %d\n",
	     LOCATION_FILE (loop->loc), LOCATION_LINE (loop->loc),
	     loop->mask, loop->e_mask);

  if (loop->child)
    {
      unsigned tmp_mask = outer_mask | this_mask | loop->e_mask;
      loop->inner = oacc_loop_fixed_partitions (loop->child, tmp_mask);
      mask_all |= loop->inner;
    }

  if (loop->sibling)
    mask_all |= oacc_loop_fixed_partitions (loop->sibling, outer_mask);

  return mask_all;
}

/* Walk the OpenACC loop heirarchy to assign auto-partitioned loops.
   OUTER_MASK is the partitioning this loop is contained within.
   OUTER_ASSIGN is true if an outer loop is being auto-partitioned.
   Return the cumulative partitioning used by this loop, siblings and
   children.  */

static unsigned
oacc_loop_auto_partitions (oacc_loop *loop, unsigned outer_mask,
			   bool outer_assign)
{
  bool assign = (loop->flags & OLF_AUTO) && (loop->flags & OLF_INDEPENDENT);
  bool noisy = true;
  bool tiling = loop->flags & OLF_TILE;

#ifdef ACCEL_COMPILER
  /* When device_type is supported, we want the device compiler to be
     noisy, if the loop parameters are device_type-specific.  */
  noisy = false;
#endif

  if (assign && (!outer_assign || loop->inner))
    {
      /* Allocate outermost and non-innermost loops at the outermost
	 non-innermost available level.  */
      unsigned this_mask = GOMP_DIM_MASK (GOMP_DIM_GANG);

      /* Find the first outermost available partition. */
      while (this_mask <= outer_mask)
	this_mask <<= 1;
      
      /* Grab two axes if tiling, and we've not assigned anything  */
      if (tiling && !(loop->mask | loop->e_mask))
	this_mask |= this_mask << 1;

      /* Prohibit the innermost partitioning at the moment.  */
      this_mask &= GOMP_DIM_MASK (GOMP_DIM_MAX - 1) - 1;

      /* Don't use any dimension explicitly claimed by an inner loop. */
      this_mask &= ~loop->inner;

      if (tiling && !loop->e_mask)
	{
	  /* If we got two axes, allocate the inner one to the element
	     loop.  */
	  loop->e_mask = this_mask & (this_mask << 1);
	  this_mask ^= loop->e_mask;
	}

      loop->mask |= this_mask;
    }

  if (loop->child)
    {
      unsigned tmp_mask = outer_mask | loop->mask | loop->e_mask;
      loop->inner = oacc_loop_auto_partitions (loop->child, tmp_mask,
					       outer_assign | assign);
    }

  if (assign && (!loop->mask || (tiling && !loop->e_mask) || !outer_assign))
    {
      /* Allocate the loop at the innermost available level.  Note
	 that we do this even if we already assigned this loop the
	 outermost available level above.  That way we'll partition
	 this along 2 axes, if they are available.  */
      unsigned this_mask = 0;

      /* Determine the outermost partitioning used within this loop.  */
      this_mask = loop->inner | GOMP_DIM_MASK (GOMP_DIM_MAX);
      this_mask = least_bit_hwi (this_mask);

      /* Pick the partitioning just inside that one.  */
      this_mask >>= 1;

      /* And avoid picking one use by an outer loop.  */
      this_mask &= ~outer_mask;

      /* If tiling and we failed completely above, grab the next one
	 too.  Making sure it doesn't hit an outer loop.  */
      if (tiling)
	{
	  this_mask &= ~(loop->e_mask | loop->mask);
	  unsigned tile_mask = ((this_mask >> 1)
				& ~(outer_mask | loop->e_mask | loop->mask));

	  if (tile_mask || loop->mask)
	    {
	      loop->e_mask |= this_mask;
	      this_mask = tile_mask;
	    }
	  if (!loop->e_mask && noisy)
	    warning_at (loop->loc, 0,
			"insufficient partitioning available"
			" to parallelize element loop");
	}

      loop->mask |= this_mask;
      if (!loop->mask && noisy)
	warning_at (loop->loc, 0,
		    tiling
		    ? G_("insufficient partitioning available"
			 " to parallelize tile loop")
		    : G_("insufficient partitioning available"
			 " to parallelize loop"));
    }

  if (assign && dump_file)
    fprintf (dump_file, "Auto loop %s:%d assigned %d & %d\n",
	     LOCATION_FILE (loop->loc), LOCATION_LINE (loop->loc),
	     loop->mask, loop->e_mask);

  unsigned inner_mask = 0;

  if (loop->sibling)
    inner_mask |= oacc_loop_auto_partitions (loop->sibling,
					     outer_mask, outer_assign);

  inner_mask |= loop->inner | loop->mask | loop->e_mask;

  return inner_mask;
}

/* Walk the OpenACC loop heirarchy to check and assign partitioning
   axes.  Return mask of partitioning.  */

static unsigned
oacc_loop_partition (oacc_loop *loop, unsigned outer_mask)
{
  unsigned mask_all = oacc_loop_fixed_partitions (loop, outer_mask);

  if (mask_all & GOMP_DIM_MASK (GOMP_DIM_MAX))
    {
      mask_all ^= GOMP_DIM_MASK (GOMP_DIM_MAX);
      mask_all |= oacc_loop_auto_partitions (loop, outer_mask, false);
    }
  return mask_all;
}

/* Default fork/join early expander.  Delete the function calls if
   there is no RTL expander.  */

bool
default_goacc_fork_join (gcall *ARG_UNUSED (call),
			 const int *ARG_UNUSED (dims), bool is_fork)
{
  if (is_fork)
    return targetm.have_oacc_fork ();
  else
    return targetm.have_oacc_join ();
}

/* Default goacc.reduction early expander.

   LHS-opt = IFN_REDUCTION (KIND, RES_PTR, VAR, LEVEL, OP, OFFSET)
   If RES_PTR is not integer-zerop:
       SETUP - emit 'LHS = *RES_PTR', LHS = NULL
       TEARDOWN - emit '*RES_PTR = VAR'
   If LHS is not NULL
       emit 'LHS = VAR'   */

void
default_goacc_reduction (gcall *call)
{
  unsigned code = (unsigned)TREE_INT_CST_LOW (gimple_call_arg (call, 0));
  gimple_stmt_iterator gsi = gsi_for_stmt (call);
  tree lhs = gimple_call_lhs (call);
  tree var = gimple_call_arg (call, 2);
  gimple_seq seq = NULL;

  if (code == IFN_GOACC_REDUCTION_SETUP
      || code == IFN_GOACC_REDUCTION_TEARDOWN)
    {
      /* Setup and Teardown need to copy from/to the receiver object,
	 if there is one.  */
      tree ref_to_res = gimple_call_arg (call, 1);

      if (!integer_zerop (ref_to_res))
	{
	  tree dst = build_simple_mem_ref (ref_to_res);
	  tree src = var;

	  if (code == IFN_GOACC_REDUCTION_SETUP)
	    {
	      src = dst;
	      dst = lhs;
	      lhs = NULL;
	    }
	  gimple_seq_add_stmt (&seq, gimple_build_assign (dst, src));
	}
    }

  /* Copy VAR to LHS, if there is an LHS.  */
  if (lhs)
    gimple_seq_add_stmt (&seq, gimple_build_assign (lhs, var));

  gsi_replace_with_seq (&gsi, seq, true);
}

/* Main entry point for oacc transformations which run on the device
   compiler after LTO, so we know what the target device is at this
   point (including the host fallback).  */

static unsigned int
execute_oacc_device_lower ()
{
  tree attrs = oacc_get_fn_attrib (current_function_decl);

  if (!attrs)
    /* Not an offloaded function.  */
    return 0;

  /* Parse the default dim argument exactly once.  */
  if ((const void *)flag_openacc_dims != &flag_openacc_dims)
    {
      oacc_parse_default_dims (flag_openacc_dims);
      flag_openacc_dims = (char *)&flag_openacc_dims;
    }

  bool is_oacc_kernels
    = (lookup_attribute ("oacc kernels",
			 DECL_ATTRIBUTES (current_function_decl)) != NULL);
  bool is_oacc_kernels_parallelized
    = (lookup_attribute ("oacc kernels parallelized",
			 DECL_ATTRIBUTES (current_function_decl)) != NULL);

  /* Unparallelized OpenACC kernels constructs must get launched as 1 x 1 x 1
     kernels, so remove the parallelism dimensions function attributes
     potentially set earlier on.  */
  if (is_oacc_kernels && !is_oacc_kernels_parallelized)
    {
      oacc_set_fn_attrib (current_function_decl, NULL, NULL);
      attrs = oacc_get_fn_attrib (current_function_decl);
    }

  /* Discover, partition and process the loops.  */
  oacc_loop *loops = oacc_loop_discovery ();
  int fn_level = oacc_fn_attrib_level (attrs);

  if (dump_file)
    {
      if (fn_level >= 0)
	fprintf (dump_file, "Function is OpenACC routine level %d\n",
		 fn_level);
      else if (is_oacc_kernels)
	fprintf (dump_file, "Function is %s OpenACC kernels offload\n",
		 (is_oacc_kernels_parallelized
		  ? "parallelized" : "unparallelized"));
      else
	fprintf (dump_file, "Function is OpenACC parallel offload\n");
    }

  unsigned outer_mask = fn_level >= 0 ? GOMP_DIM_MASK (fn_level) - 1 : 0;
  unsigned used_mask = oacc_loop_partition (loops, outer_mask);
  /* OpenACC kernels constructs are special: they currently don't use the
     generic oacc_loop infrastructure and attribute/dimension processing.  */
  if (is_oacc_kernels && is_oacc_kernels_parallelized)
    {
      /* Parallelized OpenACC kernels constructs use gang parallelism.  See
	 also tree-parloops.c:create_parallel_loop.  */
      used_mask |= GOMP_DIM_MASK (GOMP_DIM_GANG);
    }

  int dims[GOMP_DIM_MAX];
  oacc_validate_dims (current_function_decl, attrs, dims, fn_level, used_mask);

  if (dump_file)
    {
      const char *comma = "Compute dimensions [";
      for (int ix = 0; ix != GOMP_DIM_MAX; ix++, comma = ", ")
	fprintf (dump_file, "%s%d", comma, dims[ix]);
      fprintf (dump_file, "]\n");
    }

  oacc_loop_process (loops);
  if (dump_file)
    {
      fprintf (dump_file, "OpenACC loops\n");
      dump_oacc_loop (dump_file, loops, 0);
      fprintf (dump_file, "\n");
    }

  /* Offloaded targets may introduce new basic blocks, which require
     dominance information to update SSA.  */
  calculate_dominance_info (CDI_DOMINATORS);

  /* Now lower internal loop functions to target-specific code
     sequences.  */
  basic_block bb;
  FOR_ALL_BB_FN (bb, cfun)
    for (gimple_stmt_iterator gsi = gsi_start_bb (bb); !gsi_end_p (gsi);)
      {
	gimple *stmt = gsi_stmt (gsi);
	if (!is_gimple_call (stmt))
	  {
	    gsi_next (&gsi);
	    continue;
	  }

	gcall *call = as_a <gcall *> (stmt);
	if (!gimple_call_internal_p (call))
	  {
	    gsi_next (&gsi);
	    continue;
	  }

	/* Rewind to allow rescan.  */
	gsi_prev (&gsi);
	bool rescan = false, remove = false;
	enum  internal_fn ifn_code = gimple_call_internal_fn (call);

	switch (ifn_code)
	  {
	  default: break;

	  case IFN_GOACC_TILE:
	    oacc_xform_tile (call);
	    rescan = true;
	    break;
	    
	  case IFN_GOACC_LOOP:
	    oacc_xform_loop (call);
	    rescan = true;
	    break;

	  case IFN_GOACC_REDUCTION:
	    /* Mark the function for SSA renaming.  */
	    mark_virtual_operands_for_renaming (cfun);

	    /* If the level is -1, this ended up being an unused
	       axis.  Handle as a default.  */
	    if (integer_minus_onep (gimple_call_arg (call, 3)))
	      default_goacc_reduction (call);
	    else
	      targetm.goacc.reduction (call);
	    rescan = true;
	    break;

	  case IFN_UNIQUE:
	    {
	      enum ifn_unique_kind kind
		= ((enum ifn_unique_kind)
		   TREE_INT_CST_LOW (gimple_call_arg (call, 0)));

	      switch (kind)
		{
		default:
		  break;

		case IFN_UNIQUE_OACC_FORK:
		case IFN_UNIQUE_OACC_JOIN:
		  if (integer_minus_onep (gimple_call_arg (call, 2)))
		    remove = true;
		  else if (!targetm.goacc.fork_join
			   (call, dims, kind == IFN_UNIQUE_OACC_FORK))
		    remove = true;
		  break;

		case IFN_UNIQUE_OACC_HEAD_MARK:
		case IFN_UNIQUE_OACC_TAIL_MARK:
		  remove = true;
		  break;
		}
	      break;
	    }
	  }

	if (gsi_end_p (gsi))
	  /* We rewound past the beginning of the BB.  */
	  gsi = gsi_start_bb (bb);
	else
	  /* Undo the rewind.  */
	  gsi_next (&gsi);

	if (remove)
	  {
	    if (gimple_vdef (call))
	      replace_uses_by (gimple_vdef (call), gimple_vuse (call));
	    if (gimple_call_lhs (call))
	      {
		/* Propagate the data dependency var.  */
		gimple *ass = gimple_build_assign (gimple_call_lhs (call),
						   gimple_call_arg (call, 1));
		gsi_replace (&gsi, ass,  false);
	      }
	    else
	      gsi_remove (&gsi, true);
	  }
	else if (!rescan)
	  /* If not rescanning, advance over the call.  */
	  gsi_next (&gsi);
      }

  free_oacc_loop (loops);

  return 0;
}

/* Default launch dimension validator.  Force everything to 1.  A
   backend that wants to provide larger dimensions must override this
   hook.  */

bool
default_goacc_validate_dims (tree ARG_UNUSED (decl), int *dims,
			     int ARG_UNUSED (fn_level))
{
  bool changed = false;

  for (unsigned ix = 0; ix != GOMP_DIM_MAX; ix++)
    {
      if (dims[ix] != 1)
	{
	  dims[ix] = 1;
	  changed = true;
	}
    }

  return changed;
}

/* Default dimension bound is unknown on accelerator and 1 on host.  */

int
default_goacc_dim_limit (int ARG_UNUSED (axis))
{
#ifdef ACCEL_COMPILER
  return 0;
#else
  return 1;
#endif
}

namespace {

const pass_data pass_data_oacc_device_lower =
{
  GIMPLE_PASS, /* type */
  "oaccdevlow", /* name */
  OPTGROUP_OMP, /* optinfo_flags */
  TV_NONE, /* tv_id */
  PROP_cfg, /* properties_required */
  0 /* Possibly PROP_gimple_eomp.  */, /* properties_provided */
  0, /* properties_destroyed */
  0, /* todo_flags_start */
  TODO_update_ssa | TODO_cleanup_cfg, /* todo_flags_finish */
};

class pass_oacc_device_lower : public gimple_opt_pass
{
public:
  pass_oacc_device_lower (gcc::context *ctxt)
    : gimple_opt_pass (pass_data_oacc_device_lower, ctxt)
  {}

  /* opt_pass methods: */
  virtual bool gate (function *) { return flag_openacc; };

  virtual unsigned int execute (function *)
    {
      return execute_oacc_device_lower ();
    }

}; // class pass_oacc_device_lower

} // anon namespace

gimple_opt_pass *
make_pass_oacc_device_lower (gcc::context *ctxt)
{
  return new pass_oacc_device_lower (ctxt);
}


/* Rewrite GOMP_SIMT_ENTER_ALLOC call given by GSI and remove the preceding
   GOMP_SIMT_ENTER call identifying the privatized variables, which are
   turned to structure fields and receive a DECL_VALUE_EXPR accordingly.
   Set *REGIMPLIFY to true, except if no privatized variables were seen.  */

static void
ompdevlow_adjust_simt_enter (gimple_stmt_iterator *gsi, bool *regimplify)
{
  gimple *alloc_stmt = gsi_stmt (*gsi);
  tree simtrec = gimple_call_lhs (alloc_stmt);
  tree simduid = gimple_call_arg (alloc_stmt, 0);
  gimple *enter_stmt = SSA_NAME_DEF_STMT (simduid);
  gcc_assert (gimple_call_internal_p (enter_stmt, IFN_GOMP_SIMT_ENTER));
  tree rectype = lang_hooks.types.make_type (RECORD_TYPE);
  TYPE_ARTIFICIAL (rectype) = TYPE_NAMELESS (rectype) = 1;
  TREE_ADDRESSABLE (rectype) = 1;
  TREE_TYPE (simtrec) = build_pointer_type (rectype);
  for (unsigned i = 1; i < gimple_call_num_args (enter_stmt); i++)
    {
      tree *argp = gimple_call_arg_ptr (enter_stmt, i);
      if (*argp == null_pointer_node)
	continue;
      gcc_assert (TREE_CODE (*argp) == ADDR_EXPR
		  && VAR_P (TREE_OPERAND (*argp, 0)));
      tree var = TREE_OPERAND (*argp, 0);

      tree field = build_decl (DECL_SOURCE_LOCATION (var), FIELD_DECL,
			       DECL_NAME (var), TREE_TYPE (var));
      SET_DECL_ALIGN (field, DECL_ALIGN (var));
      DECL_USER_ALIGN (field) = DECL_USER_ALIGN (var);
      TREE_THIS_VOLATILE (field) = TREE_THIS_VOLATILE (var);

      insert_field_into_struct (rectype, field);

      tree t = build_simple_mem_ref (simtrec);
      t = build3 (COMPONENT_REF, TREE_TYPE (var), t, field, NULL);
      TREE_THIS_VOLATILE (t) = TREE_THIS_VOLATILE (var);
      SET_DECL_VALUE_EXPR (var, t);
      DECL_HAS_VALUE_EXPR_P (var) = 1;
      *regimplify = true;
    }
  layout_type (rectype);
  tree size = TYPE_SIZE_UNIT (rectype);
  tree align = build_int_cst (TREE_TYPE (size), TYPE_ALIGN_UNIT (rectype));

  alloc_stmt
    = gimple_build_call_internal (IFN_GOMP_SIMT_ENTER_ALLOC, 2, size, align);
  gimple_call_set_lhs (alloc_stmt, simtrec);
  gsi_replace (gsi, alloc_stmt, false);
  gimple_stmt_iterator enter_gsi = gsi_for_stmt (enter_stmt);
  enter_stmt = gimple_build_assign (simduid, gimple_call_arg (enter_stmt, 0));
  gsi_replace (&enter_gsi, enter_stmt, false);

  use_operand_p use;
  gimple *exit_stmt;
  if (single_imm_use (simtrec, &use, &exit_stmt))
    {
      gcc_assert (gimple_call_internal_p (exit_stmt, IFN_GOMP_SIMT_EXIT));
      gimple_stmt_iterator exit_gsi = gsi_for_stmt (exit_stmt);
      tree clobber = build_constructor (rectype, NULL);
      TREE_THIS_VOLATILE (clobber) = 1;
      exit_stmt = gimple_build_assign (build_simple_mem_ref (simtrec), clobber);
      gsi_insert_before (&exit_gsi, exit_stmt, GSI_SAME_STMT);
    }
  else
    gcc_checking_assert (has_zero_uses (simtrec));
}

/* Callback for walk_gimple_stmt used to scan for SIMT-privatized variables.  */

static tree
find_simtpriv_var_op (tree *tp, int *walk_subtrees, void *)
{
  tree t = *tp;

  if (VAR_P (t)
      && DECL_HAS_VALUE_EXPR_P (t)
      && lookup_attribute ("omp simt private", DECL_ATTRIBUTES (t)))
    {
      *walk_subtrees = 0;
      return t;
    }
  return NULL_TREE;
}

/* Cleanup uses of SIMT placeholder internal functions: on non-SIMT targets,
   VF is 1 and LANE is 0; on SIMT targets, VF is folded to a constant, and
   LANE is kept to be expanded to RTL later on.  Also cleanup all other SIMT
   internal functions on non-SIMT targets, and likewise some SIMD internal
   functions on SIMT targets.  */

static unsigned int
execute_omp_device_lower ()
{
  int vf = targetm.simt.vf ? targetm.simt.vf () : 1;
  bool regimplify = false;
  basic_block bb;
  gimple_stmt_iterator gsi;
  FOR_EACH_BB_FN (bb, cfun)
    for (gsi = gsi_start_bb (bb); !gsi_end_p (gsi); gsi_next (&gsi))
      {
	gimple *stmt = gsi_stmt (gsi);
	if (!is_gimple_call (stmt) || !gimple_call_internal_p (stmt))
	  continue;
	tree lhs = gimple_call_lhs (stmt), rhs = NULL_TREE;
	tree type = lhs ? TREE_TYPE (lhs) : integer_type_node;
	switch (gimple_call_internal_fn (stmt))
	  {
	  case IFN_GOMP_USE_SIMT:
	    rhs = vf == 1 ? integer_zero_node : integer_one_node;
	    break;
	  case IFN_GOMP_SIMT_ENTER:
	    rhs = vf == 1 ? gimple_call_arg (stmt, 0) : NULL_TREE;
	    goto simtreg_enter_exit;
	  case IFN_GOMP_SIMT_ENTER_ALLOC:
	    if (vf != 1)
	      ompdevlow_adjust_simt_enter (&gsi, &regimplify);
	    rhs = vf == 1 ? null_pointer_node : NULL_TREE;
	    goto simtreg_enter_exit;
	  case IFN_GOMP_SIMT_EXIT:
	  simtreg_enter_exit:
	    if (vf != 1)
	      continue;
	    unlink_stmt_vdef (stmt);
	    break;
	  case IFN_GOMP_SIMT_LANE:
	  case IFN_GOMP_SIMT_LAST_LANE:
	    rhs = vf == 1 ? build_zero_cst (type) : NULL_TREE;
	    break;
	  case IFN_GOMP_SIMT_VF:
	    rhs = build_int_cst (type, vf);
	    break;
	  case IFN_GOMP_SIMT_ORDERED_PRED:
	    rhs = vf == 1 ? integer_zero_node : NULL_TREE;
	    if (rhs || !lhs)
	      unlink_stmt_vdef (stmt);
	    break;
	  case IFN_GOMP_SIMT_VOTE_ANY:
	  case IFN_GOMP_SIMT_XCHG_BFLY:
	  case IFN_GOMP_SIMT_XCHG_IDX:
	    rhs = vf == 1 ? gimple_call_arg (stmt, 0) : NULL_TREE;
	    break;
	  case IFN_GOMP_SIMD_LANE:
	  case IFN_GOMP_SIMD_LAST_LANE:
	    rhs = vf != 1 ? build_zero_cst (type) : NULL_TREE;
	    break;
	  case IFN_GOMP_SIMD_VF:
	    rhs = vf != 1 ? build_one_cst (type) : NULL_TREE;
	    break;
	  default:
	    continue;
	  }
	if (lhs && !rhs)
	  continue;
	stmt = lhs ? gimple_build_assign (lhs, rhs) : gimple_build_nop ();
	gsi_replace (&gsi, stmt, false);
      }
  if (regimplify)
    FOR_EACH_BB_REVERSE_FN (bb, cfun)
      for (gsi = gsi_last_bb (bb); !gsi_end_p (gsi); gsi_prev (&gsi))
	if (walk_gimple_stmt (&gsi, NULL, find_simtpriv_var_op, NULL))
	  {
	    if (gimple_clobber_p (gsi_stmt (gsi)))
	      gsi_remove (&gsi, true);
	    else
	      gimple_regimplify_operands (gsi_stmt (gsi), &gsi);
	  }
  if (vf != 1)
    cfun->has_force_vectorize_loops = false;
  return 0;
}

namespace {

const pass_data pass_data_omp_device_lower =
{
  GIMPLE_PASS, /* type */
  "ompdevlow", /* name */
  OPTGROUP_OMP, /* optinfo_flags */
  TV_NONE, /* tv_id */
  PROP_cfg, /* properties_required */
  PROP_gimple_lomp_dev, /* properties_provided */
  0, /* properties_destroyed */
  0, /* todo_flags_start */
  TODO_update_ssa, /* todo_flags_finish */
};

class pass_omp_device_lower : public gimple_opt_pass
{
public:
  pass_omp_device_lower (gcc::context *ctxt)
    : gimple_opt_pass (pass_data_omp_device_lower, ctxt)
  {}

  /* opt_pass methods: */
  virtual bool gate (function *fun)
    {
      return !(fun->curr_properties & PROP_gimple_lomp_dev);
    }
  virtual unsigned int execute (function *)
    {
      return execute_omp_device_lower ();
    }

}; // class pass_expand_omp_ssa

} // anon namespace

gimple_opt_pass *
make_pass_omp_device_lower (gcc::context *ctxt)
{
  return new pass_omp_device_lower (ctxt);
}

/* "omp declare target link" handling pass.  */

namespace {

const pass_data pass_data_omp_target_link =
{
  GIMPLE_PASS,			/* type */
  "omptargetlink",		/* name */
  OPTGROUP_OMP,			/* optinfo_flags */
  TV_NONE,			/* tv_id */
  PROP_ssa,			/* properties_required */
  0,				/* properties_provided */
  0,				/* properties_destroyed */
  0,				/* todo_flags_start */
  TODO_update_ssa,		/* todo_flags_finish */
};

class pass_omp_target_link : public gimple_opt_pass
{
public:
  pass_omp_target_link (gcc::context *ctxt)
    : gimple_opt_pass (pass_data_omp_target_link, ctxt)
  {}

  /* opt_pass methods: */
  virtual bool gate (function *fun)
    {
#ifdef ACCEL_COMPILER
      tree attrs = DECL_ATTRIBUTES (fun->decl);
      return lookup_attribute ("omp declare target", attrs)
	     || lookup_attribute ("omp target entrypoint", attrs);
#else
      (void) fun;
      return false;
#endif
    }

  virtual unsigned execute (function *);
};

/* Callback for walk_gimple_stmt used to scan for link var operands.  */

static tree
find_link_var_op (tree *tp, int *walk_subtrees, void *)
{
  tree t = *tp;

  if (VAR_P (t)
      && DECL_HAS_VALUE_EXPR_P (t)
      && is_global_var (t)
      && lookup_attribute ("omp declare target link", DECL_ATTRIBUTES (t)))
    {
      *walk_subtrees = 0;
      return t;
    }

  return NULL_TREE;
}

unsigned
pass_omp_target_link::execute (function *fun)
{
  basic_block bb;
  FOR_EACH_BB_FN (bb, fun)
    {
      gimple_stmt_iterator gsi;
      for (gsi = gsi_start_bb (bb); !gsi_end_p (gsi); gsi_next (&gsi))
	if (walk_gimple_stmt (&gsi, NULL, find_link_var_op, NULL))
	  gimple_regimplify_operands (gsi_stmt (gsi), &gsi);
    }

  return 0;
}

} // anon namespace

gimple_opt_pass *
make_pass_omp_target_link (gcc::context *ctxt)
{
  return new pass_omp_target_link (ctxt);
}
