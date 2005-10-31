/* Lowering pass for OpenMP directives.  Converts OpenMP directives
   into explicit calls to the runtime library (libgomp) and data
   marshalling to implement data sharing and copying clauses.
   Contributed by Diego Novillo <dnovillo@redhat.com>

   Copyright (C) 2005 Free Software Foundation, Inc.

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
Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
02110-1301, USA.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "rtl.h"
#include "tree-gimple.h"
#include "tree-inline.h"
#include "langhooks.h"
#include "diagnostic.h"
#include "tree-flow.h"
#include "timevar.h"
#include "flags.h"
#include "function.h"
#include "expr.h"
#include "toplev.h"
#include "tree-pass.h"
#include "ggc.h"
#include "except.h"


/* Lowering of OpenMP parallel and workshare constructs proceeds in two 
   phases.  The first phase scans the function looking for OMP statements
   and then for variables that must be replaced to satisfy data sharing
   clauses.  The second phase expands code for the constructs, as well as
   re-gimplifing things when variables have been replaced with complex
   expressions.

   Lowering of a parallel statement results in the contents of the 
   parallel being moved to a new function, to be invoked by the thread
   library.  The variable remapping process is complex enough that only
   one level of parallel statement is handled at one time.  If there are
   nested parallel statements, those nested statements are handled when
   the new function is lowered and optimized.  The result is not 100%
   optimal, but lexically nested parallels effectively only happens in
   test suites.  */


typedef struct omp_context
{
  /* This field must be at the beginning, as we do "inheritance".  */
  copy_body_data cb;

  /* The tree of contexts corresponding to the encountered constructs.  */
  struct omp_context *outer;
  tree stmt;

  /* Map variables to fields in a structure that allows communication 
     between sending and receiving threads.  */
  splay_tree field_map;
  tree record_type;
  tree sender_decl;
  tree receiver_decl;

  /* A chain of variables to add to the top-level block surrounding the
     construct.  In the case of a parallel, this is in the child function.  */
  tree block_vars;

  /* What to do with variables with implicitly determined sharing
     attributes.  */
  enum omp_clause_default_kind default_kind;

  /* Nesting depth of this context.  Used to beautify error messages re
     invalid gotos.  The outermost ctx is depth 1, with depth 0 being
     reserved for the main body of the function.  */
  int depth;

  bool is_parallel;
  bool is_nested;
} omp_context;

static splay_tree all_contexts;
static int parallel_nesting_level;

static void scan_omp (tree *, omp_context *);
static void expand_omp (tree *, omp_context *);


/* Find an OpenMP clause of type KIND within CLAUSES.  */

tree
find_omp_clause (tree clauses, enum tree_code kind)
{
  for (; clauses ; clauses = OMP_CLAUSE_CHAIN (clauses))
    if (TREE_CODE (clauses) == kind)
      return clauses;

  return NULL_TREE;
}

/* Return true if CTX is for an omp parallel.  */

static inline bool
is_parallel_ctx (omp_context *ctx)
{
  return ctx->is_parallel;
}

/* Return true if EXPR is variable sized.  */

static inline bool
is_variable_sized (tree expr)
{
  return !TREE_CONSTANT (TYPE_SIZE_UNIT (TREE_TYPE (expr)));
}

/* Return true if DECL is a reference type.  */

static inline bool
is_reference (tree decl)
{
  return lang_hooks.decls.omp_privatize_by_reference (decl);
}

/* Lookup variables in the decl or field splay trees.  The "maybe" form
   allows for the variable form to not have been entered, otherwise we
   assert that the variable must have been entered.  */

static inline tree
lookup_decl (tree var, omp_context *ctx)
{
  splay_tree_node n;
  n = splay_tree_lookup (ctx->cb.decl_map, (splay_tree_key) var);
  return (tree) n->value;
}

static inline tree
maybe_lookup_decl (tree var, omp_context *ctx)
{
  splay_tree_node n;
  n = splay_tree_lookup (ctx->cb.decl_map, (splay_tree_key) var);
  return n ? (tree) n->value : NULL_TREE;
}

static inline tree
lookup_field (tree var, omp_context *ctx)
{
  splay_tree_node n;
  n = splay_tree_lookup (ctx->field_map, (splay_tree_key) var);
  return (tree) n->value;
}

static inline tree
maybe_lookup_field (tree var, omp_context *ctx)
{
  splay_tree_node n;
  n = splay_tree_lookup (ctx->field_map, (splay_tree_key) var);
  return n ? (tree) n->value : NULL_TREE;
}

/* Return true if DECL should be copied by pointer.  SHARED_P is true
   if DECL is to be shared.  */

static bool
use_pointer_for_field (tree decl, bool shared_p)
{
  if (AGGREGATE_TYPE_P (TREE_TYPE (decl)))
    return true;

  /* We can only use copy-in/copy-out semantics for shared varibles
     when we know the value is not accessible from an outer scope.  */
  if (shared_p)
    {
      /* ??? Trivially accessible from anywhere.  But why would we even
	 be passing an address in this case?  Should we simply assert
	 this to be false, or should we have a cleanup pass that removes
	 these from the list of mappings?  */
      if (TREE_STATIC (decl) || DECL_EXTERNAL (decl))
	return true;

      /* For variables with DECL_HAS_VALUE_EXPR_P set, we cannot tell
	 without analyzing the expression whether or not its location
	 is accessible to anyone else.  In the case of nested parallel
	 regions it certainly may be.  */
      if (DECL_HAS_VALUE_EXPR_P (decl))
	return true;

      /* Do not use copy-in/copy-out for variables that have their
	 address taken.  */
      if (TREE_ADDRESSABLE (decl))
	return true;
    }

  return false;
}

/* Construct a new automatic decl similar to VAR.  */

static tree
omp_copy_decl_2 (tree var, tree name, tree type, omp_context *ctx)
{
  tree copy = build_decl (VAR_DECL, name, type);

  TREE_ADDRESSABLE (copy) = TREE_ADDRESSABLE (var);
  DECL_COMPLEX_GIMPLE_REG_P (copy) = DECL_COMPLEX_GIMPLE_REG_P (var);
  DECL_ARTIFICIAL (copy) = DECL_ARTIFICIAL (var);
  DECL_IGNORED_P (copy) = DECL_IGNORED_P (var);
  TREE_USED (copy) = 1;
  DECL_CONTEXT (copy) = ctx->cb.dst_fn;
  DECL_SEEN_IN_BIND_EXPR_P (copy) = 1;

  TREE_CHAIN (copy) = ctx->block_vars;
  ctx->block_vars = copy;

  return copy;
}

static tree
omp_copy_decl_1 (tree var, omp_context *ctx)
{
  return omp_copy_decl_2 (var, DECL_NAME (var), TREE_TYPE (var), ctx);
}

/* Build tree nodes to access the field for VAR on the receiver side.  */

static tree
build_receiver_ref (tree var, bool by_ref, omp_context *ctx)
{
  tree x, field = lookup_field (var, ctx);

  /* If the receiver record type was remapped in the child function,
     remap the field into the new record type.  */
  x = maybe_lookup_field (field, ctx);
  if (x != NULL)
    field = x;

  x = build_fold_indirect_ref (ctx->receiver_decl);
  x = build3 (COMPONENT_REF, TREE_TYPE (field), x, field, NULL);
  if (by_ref)
    x = build_fold_indirect_ref (x);

  return x;
}

/* Build tree nodes to access VAR in the scope outer to CTX.  In the case
   of a parallel, this is a component reference; for workshare constructs
   this is some variable.  */

static tree
build_outer_var_ref (tree var, omp_context *ctx)
{
  tree x;

  if (is_variable_sized (var))
    {
      x = TREE_OPERAND (DECL_VALUE_EXPR (var), 0);
      x = build_outer_var_ref (x, ctx);
      x = build_fold_indirect_ref (x);
    }
  else if (is_parallel_ctx (ctx))
    {
      bool by_ref = use_pointer_for_field (var, false);
      x = build_receiver_ref (var, by_ref, ctx);
    }
  else if (ctx->outer)
    x = lookup_decl (var, ctx->outer);
  else
    x = var;

  if (is_reference (var))
    x = build_fold_indirect_ref (x);

  return x;
}

/* Build tree nodes to access the field for VAR on the sender side.  */

static tree
build_sender_ref (tree var, omp_context *ctx)
{
  tree field = lookup_field (var, ctx);
  return build3 (COMPONENT_REF, TREE_TYPE (field),
		 ctx->sender_decl, field, NULL);
}

/* Add a new field for VAR inside the structure CTX->SENDER_DECL.  */

static void
install_var_field (tree var, bool by_ref, omp_context *ctx)
{
  tree field, type;

  gcc_assert (!splay_tree_lookup (ctx->field_map, (splay_tree_key) var));

  type = TREE_TYPE (var);
  if (by_ref)
    type = build_pointer_type (type);

  field = build_decl (FIELD_DECL, DECL_NAME (var), type);

  /* Remember what variable this field was created for.  This does have a
     side effect of making dwarf2out ignore this member, so for helpful
     debugging we clear it later in delete_omp_context.  */
  DECL_ABSTRACT_ORIGIN (field) = var;

  insert_field_into_struct (ctx->record_type, field);

  splay_tree_insert (ctx->field_map, (splay_tree_key) var,
		     (splay_tree_value) field);
}

static tree
install_var_local (tree var, omp_context *ctx)
{
  tree new_var = omp_copy_decl_1 (var, ctx);
  insert_decl_map (&ctx->cb, var, new_var);
  return new_var;
}

/* Adjust the replacement for DECL in CTX for the new context.  This means
   copying the DECL_VALUE_EXPR, and fixing up the type.  */

static void
fixup_remapped_decl (tree decl, omp_context *ctx)
{
  tree new_decl, size;

  new_decl = lookup_decl (decl, ctx);

  TREE_TYPE (new_decl) = remap_type (TREE_TYPE (decl), &ctx->cb);

  if (!TREE_CONSTANT (DECL_SIZE (new_decl)))
    {
      if (DECL_HAS_VALUE_EXPR_P (decl))
	{
	  tree ve = DECL_VALUE_EXPR (decl);
	  walk_tree (&ve, copy_body_r, &ctx->cb, NULL);
	  SET_DECL_VALUE_EXPR (new_decl, ve);
	  DECL_HAS_VALUE_EXPR_P (new_decl) = 1;
	}

      size = remap_decl (DECL_SIZE (decl), &ctx->cb);
      if (size == error_mark_node)
	size = TYPE_SIZE (TREE_TYPE (new_decl));
      DECL_SIZE (new_decl) = size;

      size = remap_decl (DECL_SIZE_UNIT (decl), &ctx->cb);
      if (size == error_mark_node)
	size = TYPE_SIZE_UNIT (TREE_TYPE (new_decl));
      DECL_SIZE_UNIT (new_decl) = size;
    }
}

/* The callback for remap_decl.  Search all containing contexts for a
   mapping of the variable; this avoids having to duplicate the splay
   tree ahead of time.  We know a mapping doesn't already exist in the
   given context.  Create new mappings to implement default semantics.  */

static tree
omp_copy_decl (tree var, copy_body_data *cb)
{
  omp_context *ctx = (omp_context *) cb;
  tree new_var;

  if (is_global_var (var) || decl_function_context (var) != ctx->cb.src_fn)
    return var;

  if (TREE_CODE (var) == LABEL_DECL)
    {
      new_var = create_artificial_label ();
      DECL_CONTEXT (new_var) = ctx->cb.dst_fn;
      insert_decl_map (&ctx->cb, var, new_var);
      return new_var;
    }

  while (!is_parallel_ctx (ctx))
    {
      ctx = ctx->outer;
      if (ctx == NULL)
	return var;
      new_var = maybe_lookup_decl (var, ctx);
      if (new_var)
	return new_var;
    }

  return error_mark_node;
}

/* Create a new context, with OUTER_CTX being the surrounding context.  */

static omp_context *
new_omp_context (tree stmt, omp_context *outer_ctx)
{
  omp_context *ctx = XCNEW (omp_context);

  splay_tree_insert (all_contexts, (splay_tree_key) stmt,
		     (splay_tree_value) ctx);
  ctx->stmt = stmt;

  if (outer_ctx)
    {
      ctx->outer = outer_ctx;
      ctx->cb = outer_ctx->cb;
      ctx->cb.block = NULL;
      ctx->depth = outer_ctx->depth + 1;
    }
  else
    {
      ctx->cb.src_fn = current_function_decl;
      ctx->cb.dst_fn = current_function_decl;
      ctx->cb.src_node = cgraph_node (current_function_decl);
      ctx->cb.dst_node = ctx->cb.src_node;
      ctx->cb.src_cfun = cfun;
      ctx->cb.copy_decl = omp_copy_decl;
      ctx->cb.eh_region = -1;
      ctx->cb.transform_call_graph_edges = CB_CGE_MOVE;
      ctx->depth = 1;
    }

  ctx->cb.decl_map = splay_tree_new (splay_tree_compare_pointers, 0, 0);

  return ctx;
}

/* Destroy a omp_context data structures.  Called through the splay tree
   value delete callback.  */

static void
delete_omp_context (splay_tree_value value)
{
  omp_context *ctx = (omp_context *) value;

  splay_tree_delete (ctx->cb.decl_map);

  if (ctx->field_map)
    splay_tree_delete (ctx->field_map);

  /* We hijacked DECL_ABSTRACT_ORIGIN earlier.  We need to clear it before
     it produces corrupt debug information.  */
  if (ctx->record_type)
    {
      tree t;
      for (t = TYPE_FIELDS (ctx->record_type); t ; t = TREE_CHAIN (t))
	DECL_ABSTRACT_ORIGIN (t) = NULL;
    }

  XDELETE (ctx);
}

/* Fix up RECEIVER_DECL with a type that has been remapped to the child
   context.  */

static void
fixup_child_record_type (omp_context *ctx)
{
  tree f, type = ctx->record_type;

  /* ??? It isn't sufficient to just call remap_type here, because
     variably_modified_type_p doesn't work the way we expect for
     record types.  Testing each field for whether it needs remapping
     and creating a new record by hand works, however.  */
  for (f = TYPE_FIELDS (type); f ; f = TREE_CHAIN (f))
    if (variably_modified_type_p (TREE_TYPE (f), ctx->cb.src_fn))
      break;
  if (f)
    {
      tree name, new_fields = NULL;

      type = lang_hooks.types.make_type (RECORD_TYPE);
      name = DECL_NAME (TYPE_NAME (ctx->record_type));
      name = build_decl (TYPE_DECL, name, type);
      TYPE_NAME (type) = name;

      for (f = TYPE_FIELDS (ctx->record_type); f ; f = TREE_CHAIN (f))
	{
	  tree new_f = copy_node (f);
	  DECL_CONTEXT (new_f) = type;
	  TREE_TYPE (new_f) = remap_type (TREE_TYPE (f), &ctx->cb);
	  TREE_CHAIN (new_f) = new_fields;
	  new_fields = new_f;

	  /* Arrange to be able to look up the receiver field
	     given the sender field.  */
	  splay_tree_insert (ctx->field_map, (splay_tree_key) f,
			     (splay_tree_value) new_f);
	}
      TYPE_FIELDS (type) = nreverse (new_fields);
      layout_type (type);
    }

  TREE_TYPE (ctx->receiver_decl) = build_pointer_type (type);
}

/* Instantiate decls as necessary in CTX to satisfy the data sharing
   specified by CLAUSES.  */

static void
scan_sharing_clauses (tree clauses, omp_context *ctx)
{
  tree c, decl;

  for (c = clauses; c; c = OMP_CLAUSE_CHAIN (c))
    {
      bool by_ref;

      switch (TREE_CODE (c))
	{
	case OMP_CLAUSE_PRIVATE:
	  decl = OMP_CLAUSE_DECL (c);
	  if (!is_variable_sized (decl))
	    install_var_local (decl, ctx);
	  break;

	case OMP_CLAUSE_SHARED:
	  gcc_assert (is_parallel_ctx (ctx));
	  decl = OMP_CLAUSE_DECL (c);
	  gcc_assert (!is_variable_sized (decl));
	  by_ref = use_pointer_for_field (decl, true);
	  if (! TREE_READONLY (decl)
	      || TREE_ADDRESSABLE (decl)
	      || by_ref
	      || is_reference (decl))
	    {
	      install_var_field (decl, by_ref, ctx);
	      install_var_local (decl, ctx);
	      break;
	    }
	  /* We don't need to copy const scalar vars back.  */
	  TREE_SET_CODE (c, OMP_CLAUSE_FIRSTPRIVATE);
	  goto do_private;

	case OMP_CLAUSE_LASTPRIVATE:
	  /* Let the corresponding firstprivate clause create
	     the variable.  */
	  if (OMP_CLAUSE_LASTPRIVATE_FIRSTPRIVATE (c))
	    break;
	  /* FALLTHRU */

	case OMP_CLAUSE_FIRSTPRIVATE:
	case OMP_CLAUSE_REDUCTION:
	  decl = OMP_CLAUSE_DECL (c);
	do_private:
	  if (is_variable_sized (decl))
	    break;
	  else if (is_parallel_ctx (ctx))
	    {
	      by_ref = use_pointer_for_field (decl, false);
	      install_var_field (decl, by_ref, ctx);
	    }
	  install_var_local (decl, ctx);
	  break;

	case OMP_CLAUSE_COPYPRIVATE:
	  if (ctx->outer)
	    scan_omp (&OMP_CLAUSE_DECL (c), ctx->outer);
	  /* FALLTHRU */

	case OMP_CLAUSE_COPYIN:
	  decl = OMP_CLAUSE_DECL (c);
	  by_ref = use_pointer_for_field (decl, false);
	  install_var_field (decl, by_ref, ctx);
	  break;

	case OMP_CLAUSE_DEFAULT:
	  ctx->default_kind = OMP_CLAUSE_DEFAULT_KIND (c);
	  break;

	case OMP_CLAUSE_IF:
	case OMP_CLAUSE_NUM_THREADS:
	case OMP_CLAUSE_SCHEDULE:
	  if (ctx->outer)
	    scan_omp (&TREE_OPERAND (c, 0), ctx->outer);
	  break;

	case OMP_CLAUSE_NOWAIT:
	case OMP_CLAUSE_ORDERED:
	  break;

	default:
	  gcc_unreachable ();
	}
    }

  for (c = clauses; c; c = OMP_CLAUSE_CHAIN (c))
    {
      switch (TREE_CODE (c))
	{
	case OMP_CLAUSE_LASTPRIVATE:
	  /* Let the corresponding firstprivate clause create
	     the variable.  */
	  if (OMP_CLAUSE_LASTPRIVATE_FIRSTPRIVATE (c))
	    break;
	  /* FALLTHRU */

	case OMP_CLAUSE_PRIVATE:
	case OMP_CLAUSE_FIRSTPRIVATE:
	case OMP_CLAUSE_REDUCTION:
	  decl = OMP_CLAUSE_DECL (c);
	  if (is_variable_sized (decl))
	    install_var_local (decl, ctx);
	  fixup_remapped_decl (decl, ctx);
	  break;

	case OMP_CLAUSE_SHARED:
	  decl = OMP_CLAUSE_DECL (c);
	  fixup_remapped_decl (decl, ctx);
	  break;

	case OMP_CLAUSE_COPYPRIVATE:
	case OMP_CLAUSE_COPYIN:
	case OMP_CLAUSE_DEFAULT:
	case OMP_CLAUSE_IF:
	case OMP_CLAUSE_NUM_THREADS:
	case OMP_CLAUSE_SCHEDULE:
	case OMP_CLAUSE_NOWAIT:
	case OMP_CLAUSE_ORDERED:
	  break;

	default:
	  gcc_unreachable ();
	}
    }
}

/* Create a new name for omp child function.  Returns an identifier.  */

static GTY(()) unsigned int tmp_ompfn_id_num;

static tree
create_omp_child_function_name (void)
{
  tree name = DECL_ASSEMBLER_NAME (current_function_decl);
  size_t len = IDENTIFIER_LENGTH (name);
  char *tmp_name, *prefix;

  prefix = alloca (len + sizeof ("_omp_fn"));
  memcpy (prefix, IDENTIFIER_POINTER (name), len);
  strcpy (prefix + len, "_omp_fn");
#ifndef NO_DOT_IN_LABEL
  prefix[len] = '.';
#elif !defined NO_DOLLAR_IN_LABEL
  prefix[len] = '$';
#endif
  ASM_FORMAT_PRIVATE_NAME (tmp_name, prefix, tmp_ompfn_id_num++);
  return get_identifier (tmp_name);
}

/* Build a decl for the omp child function.  It'll not contain a body
   yet, just the bare decl.  */

static void
create_omp_child_function (omp_context *ctx)
{
  tree decl, type, name, t;

  name = create_omp_child_function_name ();
  type = build_function_type_list (void_type_node, ptr_type_node, NULL_TREE);

  decl = build_decl (FUNCTION_DECL, name, type);
  decl = lang_hooks.decls.pushdecl (decl);

  ctx->cb.dst_fn = decl;

  TREE_STATIC (decl) = 1;
  TREE_USED (decl) = 1;
  DECL_ARTIFICIAL (decl) = 1;
  DECL_IGNORED_P (decl) = 0;
  TREE_PUBLIC (decl) = 0;
  DECL_UNINLINABLE (decl) = 1;
  DECL_EXTERNAL (decl) = 0;
  DECL_CONTEXT (decl) = NULL_TREE;

  t = build_decl (RESULT_DECL, NULL_TREE, void_type_node);
  DECL_ARTIFICIAL (t) = 1;
  DECL_IGNORED_P (t) = 1;
  DECL_RESULT (decl) = t;

  t = build_decl (PARM_DECL, get_identifier (".omp_data_i"), ptr_type_node);
  DECL_ARTIFICIAL (t) = 1;
  DECL_ARG_TYPE (t) = ptr_type_node;
  DECL_CONTEXT (t) = decl;
  TREE_USED (t) = 1;
  DECL_ARGUMENTS (decl) = t;
  ctx->receiver_decl = t;

  /* Allocate memory for the function structure.  The call to 
     allocate_struct_function clobbers cfun, so we need to restore
     it afterward.  */
  allocate_struct_function (decl);
  DECL_SOURCE_LOCATION (decl) = EXPR_LOCATION (ctx->stmt);
  cfun->function_end_locus = EXPR_LOCATION (ctx->stmt);
  cfun = ctx->cb.src_cfun;
}

/* Scan an OpenMP parallel directive.  */

static void
scan_omp_parallel (tree *stmt_p, omp_context *outer_ctx)
{
  omp_context *ctx;
  tree name;

  ctx = new_omp_context (*stmt_p, outer_ctx);
  ctx->field_map = splay_tree_new (splay_tree_compare_pointers, 0, 0);
  ctx->is_parallel = true;
  ctx->default_kind = OMP_CLAUSE_DEFAULT_SHARED;
  ctx->record_type = lang_hooks.types.make_type (RECORD_TYPE);
  name = create_tmp_var_name (".omp_data_s");
  name = build_decl (TYPE_DECL, name, ctx->record_type);
  TYPE_NAME (ctx->record_type) = name;
  create_omp_child_function (ctx);

  scan_sharing_clauses (OMP_PARALLEL_CLAUSES (*stmt_p), ctx);
  scan_omp (&OMP_PARALLEL_BODY (*stmt_p), ctx);

  if (TYPE_FIELDS (ctx->record_type) == NULL)
    ctx->record_type = ctx->receiver_decl = NULL;
  else
    {
      layout_type (ctx->record_type);
      fixup_child_record_type (ctx);
    }
}

/* Scan an OpenMP loop directive.  */

static void
scan_omp_for (tree *stmt_p, omp_context *outer_ctx)
{
  omp_context *ctx;
  tree stmt = *stmt_p;

  ctx = new_omp_context (stmt, outer_ctx);
  scan_sharing_clauses (OMP_FOR_CLAUSES (stmt), ctx);

  scan_omp (&OMP_FOR_PRE_BODY (stmt), ctx);
  scan_omp (&OMP_FOR_INIT (stmt), ctx);
  scan_omp (&OMP_FOR_COND (stmt), ctx);
  scan_omp (&OMP_FOR_INCR (stmt), ctx);
  scan_omp (&OMP_FOR_BODY (stmt), ctx);
}

/* Scan an OpenMP sections directive.  */

static void
scan_omp_sections (tree *stmt_p, omp_context *outer_ctx)
{
  tree stmt = *stmt_p;
  omp_context *ctx;

  ctx = new_omp_context (stmt, outer_ctx);
  scan_sharing_clauses (OMP_SECTIONS_CLAUSES (stmt), ctx);
  scan_omp (&OMP_SECTIONS_BODY (stmt), ctx);
}

/* Scan an OpenMP single directive.  */

static void
scan_omp_single (tree *stmt_p, omp_context *outer_ctx)
{
  tree stmt = *stmt_p;
  omp_context *ctx;
  tree name;

  ctx = new_omp_context (stmt, outer_ctx);
  ctx->field_map = splay_tree_new (splay_tree_compare_pointers, 0, 0);
  ctx->record_type = lang_hooks.types.make_type (RECORD_TYPE);
  name = create_tmp_var_name (".omp_copy_s");
  name = build_decl (TYPE_DECL, name, ctx->record_type);
  TYPE_NAME (ctx->record_type) = name;

  scan_sharing_clauses (OMP_SINGLE_CLAUSES (stmt), ctx);
  scan_omp (&OMP_SINGLE_BODY (stmt), ctx);

  if (TYPE_FIELDS (ctx->record_type) == NULL)
    ctx->record_type = NULL;
  else
    layout_type (ctx->record_type);
}

/* Similar, except this is either a parallel nested within another
   parallel, or a workshare construct nested within a nested parallel.
   In this case we want to do minimal processing, as the real work 
   will be done during lowering of the function generated by the
   outermost parallel.

   The minimal amount of work is processing private clauses, and simply
   scanning the reset.  Private clauses are the only ones that don't
   also imply a reference in the outer parallel.  We must set up a
   translation lest the default behaviour in omp_copy_decl substitute
   error_mark_node.  */

static void
scan_omp_nested (tree *stmt_p, omp_context *outer_ctx)
{
  omp_context *ctx;
  tree var_sized_list = NULL;
  tree c, decl, stmt = *stmt_p;

  ctx = new_omp_context (stmt, outer_ctx);
  ctx->is_nested = true;

  for (c = OMP_CLAUSES (stmt); c ; c = OMP_CLAUSE_CHAIN (c))
    {
      switch (TREE_CODE (c))
	{
	case OMP_CLAUSE_PRIVATE:
	  decl = OMP_CLAUSE_DECL (c);
	  if (is_variable_sized (decl))
	    var_sized_list = tree_cons (NULL, decl, var_sized_list);
	  OMP_CLAUSE_DECL (c) = install_var_local (decl, ctx);
	  break;

	case OMP_CLAUSE_FIRSTPRIVATE:
	case OMP_CLAUSE_LASTPRIVATE:
	case OMP_CLAUSE_REDUCTION:
	case OMP_CLAUSE_SHARED:
	case OMP_CLAUSE_COPYPRIVATE:
	case OMP_CLAUSE_IF:
	case OMP_CLAUSE_NUM_THREADS:
	case OMP_CLAUSE_SCHEDULE:
	  scan_omp (&TREE_OPERAND (c, 0), ctx->outer);
	  break;

	case OMP_CLAUSE_COPYIN:
	case OMP_CLAUSE_NOWAIT:
	case OMP_CLAUSE_ORDERED:
	case OMP_CLAUSE_DEFAULT:
	  break;

	default:
	  gcc_unreachable ();
	}
    }

  /* Instantiate the VALUE_EXPR for variable sized variables.  We have
     to do this as a separate pass, since we need the pointer and size
     decls installed first.  */
  for (c = var_sized_list; c ; c = TREE_CHAIN (c))
    fixup_remapped_decl (TREE_VALUE (c), ctx);

  scan_omp (&OMP_BODY (stmt), ctx);

  if (TREE_CODE (stmt) == OMP_FOR)
    {
      scan_omp (&OMP_FOR_PRE_BODY (stmt), ctx);
      scan_omp (&OMP_FOR_INIT (stmt), ctx);
      scan_omp (&OMP_FOR_COND (stmt), ctx);
      scan_omp (&OMP_FOR_INCR (stmt), ctx);
    }
}

/* Lower OpenMP directives in CURRENT_FUNCTION_DECL.  */

static tree
scan_omp_1 (tree *tp, int *walk_subtrees, void *data)
{
  struct walk_stmt_info *wi = data;
  omp_context *ctx = wi->info;
  tree t = *tp;

  if (EXPR_HAS_LOCATION (t))
    input_location = EXPR_LOCATION (t);

  *walk_subtrees = 0;
  switch (TREE_CODE (t))
    {
    case OMP_PARALLEL:
      if (++parallel_nesting_level == 1)
	scan_omp_parallel (tp, ctx);
      else
	scan_omp_nested (tp, ctx);
      parallel_nesting_level--;
      break;

    case OMP_FOR:
      if (parallel_nesting_level <= 1)
	scan_omp_for (tp, ctx);
      else
	scan_omp_nested (tp, ctx);
      break;

    case OMP_SECTIONS:
      if (parallel_nesting_level <= 1)
	scan_omp_sections (tp, ctx);
      else
	scan_omp_nested (tp, ctx);
      break;

    case OMP_SINGLE:
      if (parallel_nesting_level <= 1)
	scan_omp_single (tp, ctx);
      else
	scan_omp_nested (tp, ctx);
      break;

    case OMP_SECTION:
    case OMP_MASTER:
    case OMP_ORDERED:
    case OMP_CRITICAL:
      ctx = new_omp_context (*tp, ctx);
      scan_omp (&OMP_BODY (*tp), ctx);
      break;

    case BIND_EXPR:
      {
	tree var;
	*walk_subtrees = 1;

	for (var = BIND_EXPR_VARS (t); var ; var = TREE_CHAIN (var))
	  {
	    if (DECL_CONTEXT (var) == ctx->cb.src_fn)
	      DECL_CONTEXT (var) = ctx->cb.dst_fn;
	    insert_decl_map (&ctx->cb, var, var);
	  }
      }
      break;

    case VAR_DECL:
    case PARM_DECL:
    case LABEL_DECL:
      if (ctx)
	*tp = remap_decl (t, &ctx->cb);
      break;

    default:
      if (ctx && TYPE_P (t))
	*tp = remap_type (t, &ctx->cb);
      else if (!DECL_P (t))
	*walk_subtrees = 1;
      break;
    }

  return NULL_TREE;
}

static void
scan_omp (tree *stmt_p, omp_context *ctx)
{
  location_t saved_location;
  struct walk_stmt_info wi;

  memset (&wi, 0, sizeof (wi));
  wi.callback = scan_omp_1;
  wi.info = ctx;
  wi.want_bind_expr = (ctx != NULL);
  wi.want_locations = true;

  saved_location = input_location;
  walk_stmts (&wi, stmt_p);
  input_location = saved_location;
}

/* Re-gimplification and code generation routines.  */

/* Build a call to GOMP_barrier.  */

static void
build_omp_barrier (tree *stmt_list)
{
  tree t;

  t = built_in_decls[BUILT_IN_GOMP_BARRIER];
  t = build_function_call_expr (t, NULL);
  gimplify_and_add (t, stmt_list);
}

/* If a context was created for STMT when it was scanned, return it.  */

static omp_context *
maybe_lookup_ctx (tree stmt)
{
  splay_tree_node n;
  n = splay_tree_lookup (all_contexts, (splay_tree_key) stmt);
  return n ? (omp_context *) n->value : NULL;
}

/* Construct the initialization value for reduction CLAUSE.  */

static tree
build_reduction_init (tree clause, tree type)
{
  while (TREE_CODE (type) == ARRAY_TYPE)
    type = TREE_TYPE (type);

  switch (OMP_CLAUSE_REDUCTION_CODE (clause))
    {
    case PLUS_EXPR:
    case MINUS_EXPR:
    case BIT_IOR_EXPR:
    case BIT_XOR_EXPR:
    case TRUTH_OR_EXPR:
    case TRUTH_ORIF_EXPR:
    case TRUTH_XOR_EXPR:
    case NE_EXPR:
      return fold_convert (type, integer_zero_node);

    case MULT_EXPR:
    case TRUTH_AND_EXPR:
    case TRUTH_ANDIF_EXPR:
    case EQ_EXPR:
      return fold_convert (type, integer_one_node);

    case BIT_AND_EXPR:
      return fold_convert (type, integer_minus_one_node);

    case MAX_EXPR:
      if (SCALAR_FLOAT_TYPE_P (type))
	{
	  REAL_VALUE_TYPE max, min;
	  if (HONOR_INFINITIES (TYPE_MODE (type)))
	    {
	      real_inf (&max);
	      real_arithmetic (&min, NEGATE_EXPR, &max, NULL);
	    }
	  else
	    real_maxval (&min, 1, TYPE_MODE (type));
	  return build_real (type, min);
	}
      else
	{
	  gcc_assert (INTEGRAL_TYPE_P (type));
	  return TYPE_MIN_VALUE (type);
	}

    case MIN_EXPR:
      if (SCALAR_FLOAT_TYPE_P (type))
	{
	  REAL_VALUE_TYPE max;
	  if (HONOR_INFINITIES (TYPE_MODE (type)))
	    real_inf (&max);
	  else
	    real_maxval (&max, 0, TYPE_MODE (type));
	  return build_real (type, max);
	}
      else
	{
	  gcc_assert (INTEGRAL_TYPE_P (type));
	  return TYPE_MAX_VALUE (type);
	}

    default:
      gcc_unreachable ();
    }
}

/* Initialize all entries of array VAR to value X.  */

static void
array_reduction_init (tree var, tree x, tree *stmt_list)
{
  tree ptr_type, array = var, ptr;
  tree test_label = NULL, loop_label, end_label = NULL;
  tree stmt, end, cond;

  while (TREE_CODE (TREE_TYPE (array)) == ARRAY_TYPE)
    {
      tree type_domain = TYPE_DOMAIN (TREE_TYPE (array));
      tree min_val = size_zero_node;
      if (type_domain && TYPE_MIN_VALUE (type_domain))
	min_val = TYPE_MIN_VALUE (type_domain);
      array = build4 (ARRAY_REF, TREE_TYPE (TREE_TYPE (array)),
		      array, min_val, NULL_TREE, NULL_TREE);
    }
  array = build_fold_addr_expr (array);
  ptr_type = TREE_TYPE (array);
  ptr = create_tmp_var (ptr_type, NULL);

  stmt = build2 (MODIFY_EXPR, void_type_node, ptr, array);
  gimplify_and_add (stmt, stmt_list);

  append_to_statement_list (build_and_jump (&test_label), stmt_list);

  loop_label = create_artificial_label ();
  stmt = build1 (LABEL_EXPR, void_type_node, loop_label);
  append_to_statement_list (stmt, stmt_list);

  stmt = build2 (MODIFY_EXPR, void_type_node,
		 build_fold_indirect_ref (ptr), x);
  gimplify_and_add (stmt, stmt_list);

  stmt = build2 (POSTINCREMENT_EXPR, ptr_type, ptr,
		 fold_convert (ptr_type, TYPE_SIZE_UNIT (TREE_TYPE (x))));
  gimplify_and_add (stmt, stmt_list);

  stmt = build1 (LABEL_EXPR, void_type_node, test_label);
  append_to_statement_list (stmt, stmt_list);

  end = build2 (PLUS_EXPR, ptr_type, array,
		fold_convert (ptr_type, TYPE_SIZE_UNIT (TREE_TYPE (var))));
  cond = build2 (GT_EXPR, boolean_type_node, end, ptr);
  stmt = build3 (COND_EXPR, void_type_node, cond,
		 build_and_jump (&loop_label), build_and_jump (&end_label));
  gimplify_and_add (stmt, stmt_list);

  stmt = build1 (LABEL_EXPR, void_type_node, end_label);
  append_to_statement_list (stmt, stmt_list);
}

/* Generate code to implement the input clauses, FIRSTPRIVATE and COPYIN,
   from the receiver (aka child) side and initializers for REFERENCE_TYPE
   private variables.  Initialization statements go in ILIST, while calls
   to destructors go in DLIST.  */

static void
expand_rec_input_clauses (tree clauses, tree *ilist, tree *dlist,
			  omp_context *ctx)
{
  tree_stmt_iterator diter;
  tree c, dtor, copyin_seq, x, args, ptr;
  bool copyin_by_ref = false;
  int pass;

  *dlist = alloc_stmt_list ();
  diter = tsi_start (*dlist);
  copyin_seq = NULL;

  /* Do all the fixed sized types in the first pass, and the variable sized
     types in the second pass.  This makes sure that the scalar arguments to
     the variable sized types are processed before we use them in the 
     variable sized operations.  */
  for (pass = 0; pass < 2; ++pass)
    {
      for (c = clauses; c ; c = OMP_CLAUSE_CHAIN (c))
	{
	  enum tree_code c_kind = TREE_CODE (c);
	  tree var, new_var;
	  bool by_ref;

	  switch (c_kind)
	    {
	    case OMP_CLAUSE_SHARED:
	    case OMP_CLAUSE_PRIVATE:
	    case OMP_CLAUSE_FIRSTPRIVATE:
	    case OMP_CLAUSE_LASTPRIVATE:
	    case OMP_CLAUSE_COPYIN:
	    case OMP_CLAUSE_REDUCTION:
	      break;
	    default:
	      continue;
	    }

	  new_var = var = OMP_CLAUSE_DECL (c);
	  if (c_kind != OMP_CLAUSE_COPYIN)
	    new_var = lookup_decl (var, ctx);

	  if (c_kind == OMP_CLAUSE_SHARED || c_kind == OMP_CLAUSE_COPYIN)
	    {
	      if (pass != 0)
		continue;
	    }
	  /* For variable sized types, we need to allocate the actual
	     storage here.  Call alloca and store the result in the pointer
	     decl that we created elsewhere.  */
	  else if (is_variable_sized (var))
	    {
	      if (pass == 0)
		continue;

	      ptr = DECL_VALUE_EXPR (new_var);
	      gcc_assert (TREE_CODE (ptr) == INDIRECT_REF);
	      ptr = TREE_OPERAND (ptr, 0);
	      gcc_assert (DECL_P (ptr));

	      x = TYPE_SIZE_UNIT (TREE_TYPE (new_var));
	      args = tree_cons (NULL, x, NULL);
	      x = built_in_decls[BUILT_IN_ALLOCA];
	      x = build_function_call_expr (x, args);
	      x = fold_convert (TREE_TYPE (ptr), x);
	      x = build2 (MODIFY_EXPR, void_type_node, ptr, x);
	      gimplify_and_add (x, ilist);
	    }
	  /* For references that are being privatized for Fortran, allocate
	     new backing storage for the new pointer variable.  This allows
	     us to avoid changing all the code that expects a pointer to
	     something that expects a direct variable.  Note that this
	     doesn't apply to C++, since reference types are disallowed in
	     data sharing clauses there.  */
	  else if (is_reference (var))
	    {
	      if (pass == 0)
		continue;

	      x = TYPE_SIZE_UNIT (TREE_TYPE (TREE_TYPE (new_var)));
	      if (TREE_CONSTANT (x))
		{
		  const char *name = NULL;
		  if (DECL_NAME (var))
		    name = IDENTIFIER_POINTER (DECL_NAME (new_var));

		  x = create_tmp_var (TREE_TYPE (TREE_TYPE (new_var)), name);
		  x = build_fold_addr_expr_with_type (x, TREE_TYPE (new_var));
		}
	      else
		{
		  args = tree_cons (NULL, x, NULL);
		  x = built_in_decls[BUILT_IN_ALLOCA];
		  x = build_function_call_expr (x, args);
		  x = fold_convert (TREE_TYPE (new_var), x);
		}

	      x = build2 (MODIFY_EXPR, void_type_node, new_var, x);
	      gimplify_and_add (x, ilist);

	      new_var = build_fold_indirect_ref (new_var);
	    }
	  else if (pass != 0)
	    continue;

	  switch (TREE_CODE (c))
	    {
	    case OMP_CLAUSE_SHARED:
	      /* Set up the DECL_VALUE_EXPR for shared variables now.  This
		 needs to be delayed until after fixup_child_record_type so
		 that we get the correct type during the dereference.  */
	      by_ref = use_pointer_for_field (var, true);
	      x = build_receiver_ref (var, by_ref, ctx);
	      SET_DECL_VALUE_EXPR (new_var, x);
	      DECL_HAS_VALUE_EXPR_P (new_var) = 1;
	      break;

	    case OMP_CLAUSE_LASTPRIVATE:
	      if (OMP_CLAUSE_LASTPRIVATE_FIRSTPRIVATE (c))
		break;
	      /* FALLTHRU */

	    case OMP_CLAUSE_PRIVATE:
	      x = lang_hooks.decls.omp_clause_default_ctor (c, new_var);
	      if (x)
		gimplify_and_add (x, ilist);
	      /* FALLTHRU */

	    do_dtor:
	      x = lang_hooks.decls.omp_clause_dtor (c, new_var);
	      if (x)
		{
		  dtor = x;
		  gimplify_stmt (&dtor);
		  tsi_link_before (&diter, dtor, TSI_SAME_STMT);
		}
	      break;

	    case OMP_CLAUSE_FIRSTPRIVATE:
	      x = build_outer_var_ref (var, ctx);
	      x = lang_hooks.decls.omp_clause_copy_ctor (c, new_var, x);
	      gimplify_and_add (x, ilist);
	      goto do_dtor;
	      break;

	    case OMP_CLAUSE_COPYIN:
	      by_ref = use_pointer_for_field (var, false);
	      x = build_receiver_ref (var, by_ref, ctx);
	      x = lang_hooks.decls.omp_clause_assign_op (c, new_var, x);
	      append_to_statement_list (x, &copyin_seq);
	      copyin_by_ref |= by_ref;
	      break;

	    case OMP_CLAUSE_REDUCTION:
	      x = build_reduction_init (c, TREE_TYPE (new_var));
	      if (TREE_CODE (TREE_TYPE (new_var)) == ARRAY_TYPE)
		array_reduction_init (new_var, x, ilist);
	      else
		{
		  x = build2 (MODIFY_EXPR, void_type_node, new_var, x);
		  gimplify_and_add (x, ilist);
		}
	      break;

	    default:
	      gcc_unreachable ();
	    }
	}
    }

  /* The copyin sequence is not to be executed by the main thread, since
     that would result in self-copies.  Perhaps not visible to scalars,
     but it certainly is to C++ operator=.  */
  if (copyin_seq)
    {
      x = built_in_decls[BUILT_IN_OMP_GET_THREAD_NUM];
      x = build_function_call_expr (x, NULL);
      x = build2 (NE_EXPR, boolean_type_node, x,
		  build_int_cst (TREE_TYPE (x), 0));
      x = build3 (COND_EXPR, void_type_node, x, copyin_seq, NULL);
      gimplify_and_add (x, ilist);
    }

  /* If any copyin variable is passed by reference, we must ensure the
     master thread doesn't modify it before it is copied over in all
     threads.  */
  if (copyin_by_ref)
    build_omp_barrier (ilist);
}

/* Generate code to implement the LASTPRIVATE clauses.  This is used for
   both parallel and workshare constructs.  PREDICATE may be NULL if it's
   always true.   */

static void
expand_lastprivate_clauses (tree clauses, tree predicate, tree *stmt_list,
			    omp_context *ctx)
{
  tree sub_list, x, c;

  /* Early exit if there are no lastprivate clauses.  */
  clauses = find_omp_clause (clauses, OMP_CLAUSE_LASTPRIVATE);
  if (clauses == NULL)
    {
      /* If this was a workshare clause, see if it had been combined
	 with its parallel.  In that case, look for the clauses on the
	 parallel statement itself.  */
      if (is_parallel_ctx (ctx))
	return;

      ctx = ctx->outer;
      if (ctx == NULL || !is_parallel_ctx (ctx))
	return;

      clauses = find_omp_clause (OMP_PARALLEL_CLAUSES (ctx->stmt),
				 OMP_CLAUSE_LASTPRIVATE);
      if (clauses == NULL)
	return;
    }

  sub_list = alloc_stmt_list ();

  for (c = clauses; c ; c = OMP_CLAUSE_CHAIN (c))
    {
      tree var, new_var;

      if (TREE_CODE (c) != OMP_CLAUSE_LASTPRIVATE)
	continue;

      var = OMP_CLAUSE_DECL (c);
      new_var = lookup_decl (var, ctx);

      x = build_outer_var_ref (var, ctx);
      x = lang_hooks.decls.omp_clause_assign_op (c, x, new_var);
      append_to_statement_list (x, &sub_list);
    }

  if (predicate)
    x = build3 (COND_EXPR, void_type_node, predicate, sub_list, NULL);
  else
    x = sub_list;
  gimplify_and_add (x, stmt_list);
}

/* Perform DST[x] = DST[x] OP SRC[x] on all entries of the arrays.  */

static void
array_reduction_op (enum tree_code op, tree dst, tree src, tree *stmt_list)
{
  tree ptr_type, dst_array = dst, src_array = src, dstp, srcp;
  tree test_label = NULL, loop_label, end_label = NULL;
  tree stmt, end, cond, x, size;

  while (TREE_CODE (TREE_TYPE (src_array)) == ARRAY_TYPE)
    {
      tree type_domain = TYPE_DOMAIN (TREE_TYPE (src_array));
      tree min_val = size_zero_node;
      if (type_domain && TYPE_MIN_VALUE (type_domain))
	min_val = TYPE_MIN_VALUE (type_domain);
      src_array = build4 (ARRAY_REF, TREE_TYPE (TREE_TYPE (src_array)),
			  src_array, min_val, NULL_TREE, NULL_TREE);
    }
  while (TREE_CODE (TREE_TYPE (dst_array)) == ARRAY_TYPE)
    {
      tree type_domain = TYPE_DOMAIN (TREE_TYPE (dst_array));
      tree min_val = size_zero_node;
      if (type_domain && TYPE_MIN_VALUE (type_domain))
	min_val = TYPE_MIN_VALUE (type_domain);
      dst_array = build4 (ARRAY_REF, TREE_TYPE (TREE_TYPE (dst_array)),
			  dst_array, min_val, NULL_TREE, NULL_TREE);
    }
  src_array = build_fold_addr_expr (src_array);
  dst_array = build_fold_addr_expr (dst_array);
  ptr_type = TREE_TYPE (src_array);
  srcp = create_tmp_var (ptr_type, NULL);
  dstp = create_tmp_var (ptr_type, NULL);

  stmt = build2 (MODIFY_EXPR, void_type_node, srcp, src_array);
  gimplify_and_add (stmt, stmt_list);

  stmt = build2 (MODIFY_EXPR, void_type_node, dstp, dst_array);
  gimplify_and_add (stmt, stmt_list);

  append_to_statement_list (build_and_jump (&test_label), stmt_list);

  loop_label = create_artificial_label ();
  stmt = build1 (LABEL_EXPR, void_type_node, loop_label);
  append_to_statement_list (stmt, stmt_list);

  x = build2 (op, TREE_TYPE (ptr_type), build_fold_indirect_ref (dstp),
	      build_fold_indirect_ref (srcp));
  stmt = build2 (MODIFY_EXPR, void_type_node,
		 build_fold_indirect_ref (dstp), x);
  gimplify_and_add (stmt, stmt_list);

  size = fold_convert (ptr_type, TYPE_SIZE_UNIT (TREE_TYPE (ptr_type)));
  stmt = build2 (POSTINCREMENT_EXPR, ptr_type, srcp, size);
  gimplify_and_add (stmt, stmt_list);

  stmt = build2 (POSTINCREMENT_EXPR, ptr_type, dstp, size);
  gimplify_and_add (stmt, stmt_list);

  stmt = build1 (LABEL_EXPR, void_type_node, test_label);
  append_to_statement_list (stmt, stmt_list);

  end = build2 (PLUS_EXPR, ptr_type, src_array,
		fold_convert (ptr_type, TYPE_SIZE_UNIT (TREE_TYPE (src))));
  cond = build2 (GT_EXPR, boolean_type_node, end, srcp);
  stmt = build3 (COND_EXPR, void_type_node, cond,
		 build_and_jump (&loop_label), build_and_jump (&end_label));
  gimplify_and_add (stmt, stmt_list);

  stmt = build1 (LABEL_EXPR, void_type_node, end_label);
  append_to_statement_list (stmt, stmt_list);
}

/* Generate code to implement the REDUCTION clauses.  */

static void
expand_reduction_clauses (tree clauses, tree *stmt_list, omp_context *ctx)
{
  tree sub_list = NULL, x, c;
  int count = 0;

  /* First see if there is exactly one reduction clause.  Use OMP_ATOMIC
     update in that case, otherwise use a lock.  */
  for (c = clauses; c && count < 2; c = OMP_CLAUSE_CHAIN (c))
    if (TREE_CODE (c) == OMP_CLAUSE_REDUCTION)
      {
	tree type = TREE_TYPE (OMP_CLAUSE_DECL (c));
	if (is_reference (OMP_CLAUSE_DECL (c)))
	  type = TREE_TYPE (type);
	/* Never use OMP_ATOMIC for array reductions.  */
	if (TREE_CODE (type) == ARRAY_TYPE)
	  {
	    count = -1;
	    break;
	  }
	count++;
      }

  if (count == 0)
    return;

  for (c = clauses; c ; c = OMP_CLAUSE_CHAIN (c))
    {
      tree var, ref, new_var;

      if (TREE_CODE (c) != OMP_CLAUSE_REDUCTION)
	continue;

      var = OMP_CLAUSE_DECL (c);
      new_var = lookup_decl (var, ctx);
      if (is_reference (var))
	new_var = build_fold_indirect_ref (new_var);
      ref = build_outer_var_ref (var, ctx);

      if (count == 1)
	{
	  tree addr = build_fold_addr_expr (ref);

	  addr = save_expr (addr);
	  ref = build1 (INDIRECT_REF, TREE_TYPE (TREE_TYPE (addr)), addr);
	  x = fold_build2 (OMP_CLAUSE_REDUCTION_CODE (c), TREE_TYPE (ref),
			   ref, new_var);
	  x = build2 (OMP_ATOMIC, void_type_node, addr, x);
	  gimplify_and_add (x, stmt_list);
	  return;
	}

      if (TREE_CODE (TREE_TYPE (new_var)) == ARRAY_TYPE)
	array_reduction_op (OMP_CLAUSE_REDUCTION_CODE (c),
			    ref, new_var, &sub_list);
      else
	{
	  x = build2 (OMP_CLAUSE_REDUCTION_CODE (c),
		      TREE_TYPE (ref), ref, new_var);
	  ref = build_outer_var_ref (var, ctx);
	  x = build2 (MODIFY_EXPR, void_type_node, ref, x);
	  append_to_statement_list (x, &sub_list);
	}
    }

  x = built_in_decls[BUILT_IN_GOMP_ATOMIC_START];
  x = build_function_call_expr (x, NULL);
  gimplify_and_add (x, stmt_list);

  gimplify_and_add (sub_list, stmt_list);

  x = built_in_decls[BUILT_IN_GOMP_ATOMIC_END];
  x = build_function_call_expr (x, NULL);
  gimplify_and_add (x, stmt_list);
}

/* Generate code to implement the COPYPRIVATE clauses.  */

static void
expand_copyprivate_clauses (tree clauses, tree *slist, tree *rlist,
			    omp_context *ctx)
{
  tree c;

  for (c = clauses; c ; c = OMP_CLAUSE_CHAIN (c))
    {
      tree var, ref, x;
      bool by_ref;

      if (TREE_CODE (c) != OMP_CLAUSE_COPYPRIVATE)
	continue;

      var = OMP_CLAUSE_DECL (c);
      by_ref = use_pointer_for_field (var, false);

      ref = build_sender_ref (var, ctx);
      x = by_ref ? build_fold_addr_expr (var) : var;
      x = build2 (MODIFY_EXPR, void_type_node, ref, x);
      gimplify_and_add (x, slist);

      ref = build_receiver_ref (var, by_ref, ctx);
      if (is_reference (var))
	{
	  ref = build_fold_indirect_ref (ref);
	  var = build_fold_indirect_ref (var);
	}
      x = lang_hooks.decls.omp_clause_assign_op (c, var, ref);
      gimplify_and_add (x, rlist);
    }
}

/* Generate code to implement the clauses, FIRSTPRIVATE, COPYIN, LASTPRIVATE,
   and REDUCTION from the sender (aka parent) side.  */

static void
expand_send_clauses (tree clauses, tree *ilist, tree *olist, omp_context *ctx)
{
  tree c;

  for (c = clauses; c ; c = OMP_CLAUSE_CHAIN (c))
    {
      tree val, ref, x;
      bool by_ref, do_in = false, do_out = false;

      switch (TREE_CODE (c))
	{
	case OMP_CLAUSE_FIRSTPRIVATE:
	case OMP_CLAUSE_COPYIN:
	case OMP_CLAUSE_LASTPRIVATE:
	case OMP_CLAUSE_REDUCTION:
	  break;
	default:
	  continue;
	}

      val = OMP_CLAUSE_DECL (c);
      if (is_variable_sized (val))
	continue;
      by_ref = use_pointer_for_field (val, false);

      switch (TREE_CODE (c))
	{
	case OMP_CLAUSE_FIRSTPRIVATE:
	case OMP_CLAUSE_COPYIN:
	  do_in = true;
	  break;

	case OMP_CLAUSE_LASTPRIVATE:
	  if (by_ref || is_reference (val))
	    {
	      if (OMP_CLAUSE_LASTPRIVATE_FIRSTPRIVATE (c))
		continue;
	      do_in = true;
	    }
	  else
	    do_out = true;
	  break;

	case OMP_CLAUSE_REDUCTION:
	  do_in = true;
	  do_out = !(by_ref || is_reference (val));
	  break;

	default:
	  gcc_unreachable ();
	}

      if (do_in)
	{
	  ref = build_sender_ref (val, ctx);
	  x = by_ref ? build_fold_addr_expr (val) : val;
	  x = build2 (MODIFY_EXPR, void_type_node, ref, x);
	  gimplify_and_add (x, ilist);
	}
      if (do_out)
	{
	  ref = build_sender_ref (val, ctx);
	  x = build2 (MODIFY_EXPR, void_type_node, val, ref);
	  gimplify_and_add (x, olist);
	}
    }
}

/* Generate code to implement SHARED from the sender (aka parent) side.
   This is trickier, since OMP_PARALLEL_CLAUSES doesn't list things that
   got automatically shared.  */

static void
expand_send_shared_vars (tree *ilist, tree *olist, omp_context *ctx)
{
  tree ovar, nvar, f, x;

  if (ctx->record_type == NULL)
    return;
  
  for (f = TYPE_FIELDS (ctx->record_type); f ; f = TREE_CHAIN (f))
    {
      ovar = DECL_ABSTRACT_ORIGIN (f);
      nvar = maybe_lookup_decl (ovar, ctx);
      if (!nvar || !DECL_HAS_VALUE_EXPR_P (nvar))
	continue;

      if (use_pointer_for_field (ovar, true))
	{
	  x = build_sender_ref (ovar, ctx);
	  ovar = build_fold_addr_expr (ovar);
	  x = build2 (MODIFY_EXPR, void_type_node, x, ovar);
	  gimplify_and_add (x, ilist);
	}
      else
	{
	  x = build_sender_ref (ovar, ctx);
	  x = build2 (MODIFY_EXPR, void_type_node, x, ovar);
	  gimplify_and_add (x, ilist);

	  x = build_sender_ref (ovar, ctx);
	  x = build2 (MODIFY_EXPR, void_type_node, ovar, x);
	  gimplify_and_add (x, olist);
	}
    }
}

/* Build the function calls to GOMP_parallel_start etc to actually 
   generate the parallel operation.  */

static void
build_parallel_call (tree clauses, tree *stmt_list, omp_context *ctx)
{
  tree t, args, val, cond, c;

  /* By default, the value of NUM_THREADS is zero (selected at run time)
     and there is no conditional.  */
  cond = NULL_TREE;
  val = build_int_cst (unsigned_type_node, 0);

  c = find_omp_clause (clauses, OMP_CLAUSE_IF);
  if (c)
    cond = OMP_CLAUSE_IF_EXPR (c);

  c = find_omp_clause (clauses, OMP_CLAUSE_NUM_THREADS);
  if (c)
    val = OMP_CLAUSE_NUM_THREADS_EXPR (c);

  /* Ensure 'val' is of the correct type.  */
  val = fold_convert (unsigned_type_node, val);

  /* If we found the clause 'if (cond)', build either
     (cond != 0) or (cond ? val : 1u).  */
  if (cond)
    {
      if (integer_zerop (val))
	val = build2 (EQ_EXPR, unsigned_type_node, cond,
		      build_int_cst (TREE_TYPE (cond), 0));
      else
	val = build3 (COND_EXPR, unsigned_type_node, cond, val,
		      build_int_cst (unsigned_type_node, 1));
    }

  args = tree_cons (NULL, val, NULL);
  t = ctx->sender_decl;
  if (t == NULL)
    t = null_pointer_node;
  else
    t = build_fold_addr_expr (t);
  args = tree_cons (NULL, t, args);
  t = build_fold_addr_expr (ctx->cb.dst_fn);
  args = tree_cons (NULL, t, args);
  t = built_in_decls[BUILT_IN_GOMP_PARALLEL_START];
  t = build_function_call_expr (t, args);
  gimplify_and_add (t, stmt_list);

  t = ctx->sender_decl;
  if (t == NULL)
    t = null_pointer_node;
  else
    t = build_fold_addr_expr (t);
  args = tree_cons (NULL, t, NULL);
  t = build_function_call_expr (ctx->cb.dst_fn, args);
  gimplify_and_add (t, stmt_list);

  t = built_in_decls[BUILT_IN_GOMP_PARALLEL_END];
  t = build_function_call_expr (t, NULL);
  gimplify_and_add (t, stmt_list);
}

/* If exceptions are enabled, wrap *STMT_P in a MUST_NOT_THROW catch
   handler.  This prevents programs from violating the structured
   block semantics with throws.  */

static void
maybe_catch_exception (tree *stmt_p)
{
  tree f, t;

  if (!flag_exceptions)
    return;

  if (lang_protect_cleanup_actions)
    t = lang_protect_cleanup_actions ();
  else
    {
      t = built_in_decls[BUILT_IN_TRAP];
      t = build_function_call_expr (t, NULL);
    }
  f = build2 (EH_FILTER_EXPR, void_type_node, NULL, NULL);
  EH_FILTER_MUST_NOT_THROW (f) = 1;
  gimplify_and_add (t, &EH_FILTER_FAILURE (f));
  
  t = build2 (TRY_CATCH_EXPR, void_type_node, *stmt_p, NULL);
  append_to_statement_list (f, &TREE_OPERAND (t, 1));

  *stmt_p = NULL;
  append_to_statement_list (t, stmt_p);
}

/* Expand an OpenMP parallel directive.  */

static void
expand_omp_parallel (tree *stmt_p, omp_context *ctx)
{
  tree clauses, block, bind, body, olist;

  current_function_decl = ctx->cb.dst_fn;
  cfun = DECL_STRUCT_FUNCTION (current_function_decl);

  push_gimplify_context ();

  clauses = OMP_PARALLEL_CLAUSES (*stmt_p);
  bind = OMP_PARALLEL_BODY (*stmt_p);
  block = BIND_EXPR_BLOCK (bind);
  body = BIND_EXPR_BODY (bind);
  BIND_EXPR_BODY (bind) = alloc_stmt_list ();

  expand_rec_input_clauses (clauses, &BIND_EXPR_BODY (bind), &olist, ctx);

  expand_omp (&body, ctx);
  append_to_statement_list (body, &BIND_EXPR_BODY (bind));

  expand_reduction_clauses (clauses, &BIND_EXPR_BODY (bind), ctx);
  append_to_statement_list (olist, &BIND_EXPR_BODY (bind));
  maybe_catch_exception (&BIND_EXPR_BODY (bind));

  pop_gimplify_context (bind);
  BIND_EXPR_VARS (bind) = chainon (BIND_EXPR_VARS (bind), ctx->block_vars);
  BLOCK_VARS (block) = BIND_EXPR_VARS (bind);

  DECL_INITIAL (ctx->cb.dst_fn) = block;
  DECL_SAVED_TREE (ctx->cb.dst_fn) = bind;
  cgraph_add_new_function (ctx->cb.dst_fn);

  current_function_decl = ctx->cb.src_fn;
  cfun = DECL_STRUCT_FUNCTION (current_function_decl);

  block = make_node (BLOCK);
  bind = build3 (BIND_EXPR, void_type_node, NULL, NULL, block);
  *stmt_p = bind;

  push_gimplify_context ();

  /* Build the sender decl now that we're in the correct context.  */
  if (ctx->record_type)
    ctx->sender_decl = create_tmp_var (ctx->record_type, ".omp_data_o");

  olist = NULL;
  expand_send_clauses (clauses, &BIND_EXPR_BODY (bind), &olist, ctx);
  expand_send_shared_vars (&BIND_EXPR_BODY (bind), &olist, ctx);
  build_parallel_call (clauses, &BIND_EXPR_BODY (bind), ctx);
  append_to_statement_list (olist, &BIND_EXPR_BODY (bind));

  pop_gimplify_context (bind);
  BLOCK_VARS (block) = BIND_EXPR_VARS (bind);
}

/* A structure to communicate between the various subroutines of 
   expand_omp_for_1.  */

struct expand_omp_for_data
{
  tree v, n1, n2, step, chunk_size, for_stmt;
  enum tree_code cond_code;
  tree pre;
  omp_context *ctx;
};

/* A subroutine of expand_omp_for_1.  Generate code to emit the
   for for a lastprivate clause.  Given a loop control predicate
   of (V cond N2), we gate the clause on (!(V cond N2)).  */

static void
expand_omp_for_lastprivate (struct expand_omp_for_data *fd)
{
  tree clauses, cond;
  enum tree_code cond_code;
  
  cond_code = fd->cond_code;
  cond_code = cond_code == LT_EXPR ? GE_EXPR : LE_EXPR;

  /* When possible, use a strict equality expression.  This can let VRP
     type optimizations deduce the value and remove a copy.  */
  if (host_integerp (fd->step, 0))
    {
      HOST_WIDE_INT step = TREE_INT_CST_LOW (fd->step);
      if (step == 1 || step == -1)
	cond_code = EQ_EXPR;
    }

  cond = build2 (cond_code, boolean_type_node, fd->v, fd->n2);

  clauses = OMP_FOR_CLAUSES (fd->for_stmt);
  expand_lastprivate_clauses (clauses, cond, &fd->pre, fd->ctx);
}

/* A subroutine of expand_omp_for_1.  Generate code for a parallel
   loop with any schedule.  Given parameters:

	for (V = N1; V cond N2; V += STEP) BODY;

   where COND is "<" or ">", we generate pseudocode

	more = GOMP_loop_foo_start (N1, N2, STEP, CHUNK, &istart0, &iend0);
	if (more) goto L0; else goto L3;
    L0:
	V = istart0;
	iend = iend0;
    L1:
	BODY;
	V += STEP;
	if (V cond iend) goto L1;
	more = GOMP_loop_foo_next (&istart0, &iend0);
	if (more) goto L0;
	lastprivate;
    L3:
*/

static void
expand_omp_for_generic (struct expand_omp_for_data *fd,
			enum built_in_function start_fn,
			enum built_in_function next_fn)
{
  tree l0, l1, l3;
  tree type, istart0, iend0, iend;
  tree t, args;

  type = TREE_TYPE (fd->v);

  istart0 = create_tmp_var (long_integer_type_node, ".istart0");
  iend0 = create_tmp_var (long_integer_type_node, ".istart0");

  l0 = create_artificial_label ();
  l1 = create_artificial_label ();
  l3 = create_artificial_label ();
  iend = create_tmp_var (type, NULL);

  t = build_fold_addr_expr (iend0);
  args = tree_cons (NULL, t, NULL);
  t = build_fold_addr_expr (istart0);
  args = tree_cons (NULL, t, args);
  if (fd->chunk_size)
    {
      t = fold_convert (long_integer_type_node, fd->chunk_size);
      args = tree_cons (NULL, t, args);
    }
  t = fold_convert (long_integer_type_node, fd->step);
  args = tree_cons (NULL, t, args);
  t = fold_convert (long_integer_type_node, fd->n2);
  args = tree_cons (NULL, t, args);
  t = fold_convert (long_integer_type_node, fd->n1);
  args = tree_cons (NULL, t, args);
  t = build_function_call_expr (built_in_decls[start_fn], args);
  t = build3 (COND_EXPR, void_type_node, t,
	      build_and_jump (&l0), build_and_jump (&l3));
  gimplify_and_add (t, &fd->pre);

  t = build1 (LABEL_EXPR, void_type_node, l0);
  gimplify_and_add (t, &fd->pre);

  t = fold_convert (type, istart0);
  t = build2 (MODIFY_EXPR, void_type_node, fd->v, t);
  gimplify_and_add (t, &fd->pre);

  t = fold_convert (type, iend0);
  t = build2 (MODIFY_EXPR, void_type_node, iend, t);
  gimplify_and_add (t, &fd->pre);

  t = build1 (LABEL_EXPR, void_type_node, l1);
  gimplify_and_add (t, &fd->pre);

  append_to_statement_list (OMP_FOR_BODY (fd->for_stmt), &fd->pre);

  t = build2 (PLUS_EXPR, type, fd->v, fd->step);
  t = build2 (MODIFY_EXPR, void_type_node, fd->v, t);
  gimplify_and_add (t, &fd->pre);
  
  t = build2 (fd->cond_code, boolean_type_node, fd->v, iend);
  t = build3 (COND_EXPR, void_type_node, t, build_and_jump (&l1), NULL);
  gimplify_and_add (t, &fd->pre);

  t = build_fold_addr_expr (iend0);
  args = tree_cons (NULL, t, NULL);
  t = build_fold_addr_expr (istart0);
  args = tree_cons (NULL, t, args);
  t = build_function_call_expr (built_in_decls[next_fn], args);
  t = build3 (COND_EXPR, void_type_node, t, build_and_jump (&l0), NULL);
  gimplify_and_add (t, &fd->pre);

  expand_omp_for_lastprivate (fd);
  
  t = build1 (LABEL_EXPR, void_type_node, l3);
  gimplify_and_add (t, &fd->pre);
}

/* A subroutine of expand_omp_for_1.  Generate code for a parallel
   loop with static schedule and no specified chunk size.  Given parameters:

	for (V = N1; V cond N2; V += STEP) BODY;

   where COND is "<" or ">", we generate pseudocode

	if (cond is <)
	  adj = STEP - 1;
	else
	  adj = STEP + 1;
	n = (adj + N2 - N1) / STEP;
	q = n / nthreads;
	q += (q * nthreads != n);
	s0 = q * threadid;
	e0 = min(s0 + q, n);
	if (s0 >= e0) goto L2; else goto L0;
    L0:
	V = s0 * STEP + N1;
	e = e0 * STEP + N1;
    L1:
	BODY;
	V += STEP;
	if (V cond e) goto L1;
	lastprivate;
    L2:
*/

static void
expand_omp_for_static_nochunk (struct expand_omp_for_data *fd)
{
  tree l0, l1, l2, n, q, s0, e0, e, t, nthreads, threadid;
  tree type, utype;

  l0 = create_artificial_label ();
  l1 = create_artificial_label ();
  l2 = create_artificial_label ();
  
  type = TREE_TYPE (fd->v);
  utype = lang_hooks.types.unsigned_type (type);

  t = built_in_decls[BUILT_IN_OMP_GET_NUM_THREADS];
  t = build_function_call_expr (t, NULL);
  t = fold_convert (utype, t);
  nthreads = get_formal_tmp_var (t, &fd->pre);
  
  t = built_in_decls[BUILT_IN_OMP_GET_THREAD_NUM];
  t = build_function_call_expr (t, NULL);
  t = fold_convert (utype, t);
  threadid = get_formal_tmp_var (t, &fd->pre);

  fd->n1 = fold_convert (type, fd->n1);
  if (!is_gimple_val (fd->n1))
    fd->n1 = get_formal_tmp_var (fd->n1, &fd->pre);

  fd->n2 = fold_convert (type, fd->n2);
  if (!is_gimple_val (fd->n2))
    fd->n2 = get_formal_tmp_var (fd->n2, &fd->pre);

  fd->step = fold_convert (type, fd->step);
  if (!is_gimple_val (fd->step))
    fd->step = get_formal_tmp_var (fd->step, &fd->pre);

  t = build_int_cst (type, (fd->cond_code == LT_EXPR ? -1 : 1));
  t = fold_build2 (PLUS_EXPR, type, fd->step, t);
  t = fold_build2 (PLUS_EXPR, type, t, fd->n2);
  t = fold_build2 (MINUS_EXPR, type, t, fd->n1);
  t = fold_build2 (TRUNC_DIV_EXPR, type, t, fd->step);
  t = fold_convert (utype, t);
  if (is_gimple_val (t))
    n = t;
  else
    n = get_formal_tmp_var (t, &fd->pre);

  t = build2 (TRUNC_DIV_EXPR, utype, n, nthreads);
  q = get_formal_tmp_var (t, &fd->pre);

  t = build2 (MULT_EXPR, utype, q, nthreads);
  t = build2 (NE_EXPR, utype, t, n);
  t = build2 (PLUS_EXPR, utype, q, t);
  q = get_formal_tmp_var (t, &fd->pre);

  t = build2 (MULT_EXPR, utype, q, threadid);
  s0 = get_formal_tmp_var (t, &fd->pre);

  t = build2 (PLUS_EXPR, utype, s0, q);
  t = build2 (MIN_EXPR, utype, t, n);
  e0 = get_formal_tmp_var (t, &fd->pre);

  t = build2 (GE_EXPR, boolean_type_node, s0, e0);
  t = build3 (COND_EXPR, void_type_node, t,
	      build_and_jump (&l2), build_and_jump (&l0));
  gimplify_and_add (t, &fd->pre);

  t = build1 (LABEL_EXPR, void_type_node, l0);
  gimplify_and_add (t, &fd->pre);

  t = fold_convert (type, s0);
  t = build2 (MULT_EXPR, type, t, fd->step);
  t = build2 (PLUS_EXPR, type, t, fd->n1);
  t = build2 (MODIFY_EXPR, void_type_node, fd->v, t);
  gimplify_and_add (t, &fd->pre);

  t = fold_convert (type, e0);
  t = build2 (MULT_EXPR, type, t, fd->step);
  t = build2 (PLUS_EXPR, type, t, fd->n1);
  e = get_formal_tmp_var (t, &fd->pre);

  t = build1 (LABEL_EXPR, void_type_node, l1);
  gimplify_and_add (t, &fd->pre);

  append_to_statement_list (OMP_FOR_BODY (fd->for_stmt), &fd->pre);

  t = build2 (PLUS_EXPR, type, fd->v, fd->step);
  t = build2 (MODIFY_EXPR, void_type_node, fd->v, t);
  gimplify_and_add (t, &fd->pre);

  t = build2 (fd->cond_code, boolean_type_node, fd->v, e);
  t = build3 (COND_EXPR, void_type_node, t, build_and_jump (&l1), NULL);
  gimplify_and_add (t, &fd->pre);

  expand_omp_for_lastprivate (fd);
  
  t = build1 (LABEL_EXPR, void_type_node, l2);
  gimplify_and_add (t, &fd->pre);
}

/* A subroutine of expand_omp_for_1.  Generate code for a parallel
   loop with static schedule and a specified chunk size.  Given parameters:

	for (V = N1; V cond N2; V += STEP) BODY;

   where COND is "<" or ">", we generate pseudocode

	if (cond is <)
	  adj = STEP - 1;
	else
	  adj = STEP + 1;
	n = (adj + N2 - N1) / STEP;
	trip = 0;
    L0:
	s0 = (trip * nthreads + threadid) * CHUNK;
	e0 = min(s0 + CHUNK, n);
	if (s0 < n) goto L1; else goto L4;
    L1:
	V = s0 * STEP + N1;
	e = e0 * STEP + N1;
    L2:
	BODY;
	V += STEP;
	if (V cond e) goto L2; else goto L3;
    L3:
	trip += 1;
	goto L0;
    L4:
	if (trip == 0) goto L5;
	lastprivate;
    L5:
*/

static void
expand_omp_for_static_chunk (struct expand_omp_for_data *fd)
{
  tree l0, l1, l2, l3, l4, l5, n, s0, e0, e, t;
  tree trip, nthreads, threadid;
  tree type, utype;

  l0 = create_artificial_label ();
  l1 = create_artificial_label ();
  l2 = create_artificial_label ();
  l3 = create_artificial_label ();
  l4 = create_artificial_label ();
  l5 = create_artificial_label ();
  
  type = TREE_TYPE (fd->v);
  utype = lang_hooks.types.unsigned_type (type);

  t = built_in_decls[BUILT_IN_OMP_GET_NUM_THREADS];
  t = build_function_call_expr (t, NULL);
  t = fold_convert (utype, t);
  nthreads = get_formal_tmp_var (t, &fd->pre);
  
  t = built_in_decls[BUILT_IN_OMP_GET_THREAD_NUM];
  t = build_function_call_expr (t, NULL);
  t = fold_convert (utype, t);
  threadid = get_formal_tmp_var (t, &fd->pre);

  fd->n1 = fold_convert (type, fd->n1);
  if (!is_gimple_val (fd->n1))
    fd->n1 = get_formal_tmp_var (fd->n1, &fd->pre);

  fd->n2 = fold_convert (type, fd->n2);
  if (!is_gimple_val (fd->n2))
    fd->n2 = get_formal_tmp_var (fd->n2, &fd->pre);

  fd->step = fold_convert (type, fd->step);
  if (!is_gimple_val (fd->step))
    fd->step = get_formal_tmp_var (fd->step, &fd->pre);

  fd->chunk_size = fold_convert (utype, fd->chunk_size);
  if (!is_gimple_val (fd->chunk_size))
    fd->chunk_size = get_formal_tmp_var (fd->chunk_size, &fd->pre);

  t = build_int_cst (type, (fd->cond_code == LT_EXPR ? -1 : 1));
  t = fold_build2 (PLUS_EXPR, type, fd->step, t);
  t = fold_build2 (PLUS_EXPR, type, t, fd->n2);
  t = fold_build2 (MINUS_EXPR, type, t, fd->n1);
  t = fold_build2 (TRUNC_DIV_EXPR, type, t, fd->step);
  t = fold_convert (utype, t);
  if (is_gimple_val (t))
    n = t;
  else
    n = get_formal_tmp_var (t, &fd->pre);

  t = build_int_cst (utype, 0);
  trip = get_initialized_tmp_var (t, &fd->pre, NULL);

  t = build1 (LABEL_EXPR, void_type_node, l0);
  gimplify_and_add (t, &fd->pre);

  t = build2 (MULT_EXPR, utype, trip, nthreads);
  t = build2 (PLUS_EXPR, utype, t, threadid);
  t = build2 (MULT_EXPR, utype, t, fd->chunk_size);
  s0 = get_formal_tmp_var (t, &fd->pre);

  t = build2 (PLUS_EXPR, utype, s0, fd->chunk_size);
  t = build2 (MIN_EXPR, utype, t, n);
  e0 = get_formal_tmp_var (t, &fd->pre);

  t = build2 (LT_EXPR, boolean_type_node, s0, n);
  t = build3 (COND_EXPR, void_type_node, t,
	      build_and_jump (&l1), build_and_jump (&l4));
  gimplify_and_add (t, &fd->pre);

  t = build1 (LABEL_EXPR, void_type_node, l1);
  gimplify_and_add (t, &fd->pre);

  t = fold_convert (type, s0);
  t = build2 (MULT_EXPR, type, t, fd->step);
  t = build2 (PLUS_EXPR, type, t, fd->n1);
  t = build2 (MODIFY_EXPR, void_type_node, fd->v, t);
  gimplify_and_add (t, &fd->pre);

  t = fold_convert (type, e0);
  t = build2 (MULT_EXPR, type, t, fd->step);
  t = build2 (PLUS_EXPR, type, t, fd->n1);
  e = get_formal_tmp_var (t, &fd->pre);

  t = build1 (LABEL_EXPR, void_type_node, l2);
  gimplify_and_add (t, &fd->pre);

  append_to_statement_list (OMP_FOR_BODY (fd->for_stmt), &fd->pre);

  t = build2 (PLUS_EXPR, type, fd->v, fd->step);
  t = build2 (MODIFY_EXPR, void_type_node, fd->v, t);
  gimplify_and_add (t, &fd->pre);

  t = build2 (fd->cond_code, boolean_type_node, fd->v, e);
  t = build3 (COND_EXPR, void_type_node, t,
	      build_and_jump (&l2), build_and_jump (&l3));
  gimplify_and_add (t, &fd->pre);

  t = build1 (LABEL_EXPR, void_type_node, l3);
  gimplify_and_add (t, &fd->pre);

  t = build_int_cst (utype, 1);
  t = build2 (PLUS_EXPR, utype, trip, t);
  t = build2 (MODIFY_EXPR, void_type_node, trip, t);
  gimplify_and_add (t, &fd->pre);

  t = build1 (GOTO_EXPR, void_type_node, l0);
  gimplify_and_add (t, &fd->pre);

  t = build1 (LABEL_EXPR, void_type_node, l4);
  gimplify_and_add (t, &fd->pre);

  t = build_int_cst (utype, 0);
  t = build2 (EQ_EXPR, boolean_type_node, trip, t);
  t = build3 (COND_EXPR, void_type_node, t, build_and_jump (&l5), NULL);

  expand_omp_for_lastprivate (fd);
  
  t = build1 (LABEL_EXPR, void_type_node, l5);
  gimplify_and_add (t, &fd->pre);
}

/* A subroutine of expand_omp_for.  Expand the logic of the loop itself.  */

static tree
expand_omp_for_1 (tree *stmt_p, omp_context *ctx)
{
  struct expand_omp_for_data fd;
  bool have_nowait, have_ordered;
  enum omp_clause_schedule_kind sched_kind;
  tree t, dlist;

  fd.for_stmt = *stmt_p;
  fd.pre = NULL;
  fd.ctx = ctx;

  t = OMP_FOR_INIT (fd.for_stmt);
  gcc_assert (TREE_CODE (t) == MODIFY_EXPR);
  fd.v = TREE_OPERAND (t, 0);
  gcc_assert (DECL_P (fd.v));
  gcc_assert (TREE_CODE (TREE_TYPE (fd.v)) == INTEGER_TYPE);
  fd.n1 = TREE_OPERAND (t, 1);

  t = OMP_FOR_COND (fd.for_stmt);
  fd.cond_code = TREE_CODE (t);
  gcc_assert (TREE_OPERAND (t, 0) == fd.v);
  fd.n2 = TREE_OPERAND (t, 1);
  switch (fd.cond_code)
    {
    case LT_EXPR:
    case GT_EXPR:
      break;
    case LE_EXPR:
      fd.n2 = fold_build2 (PLUS_EXPR, TREE_TYPE (fd.n2), fd.n2,
			   build_int_cst (TREE_TYPE (fd.n2), 1));
      fd.cond_code = LT_EXPR;
      break;
    case GE_EXPR:
      fd.n2 = fold_build2 (MINUS_EXPR, TREE_TYPE (fd.n2), fd.n2,
			   build_int_cst (TREE_TYPE (fd.n2), 1));
      fd.cond_code = GT_EXPR;
      break;
    default:
      gcc_unreachable ();
    }

  t = OMP_FOR_INCR (fd.for_stmt);
  gcc_assert (TREE_CODE (t) == MODIFY_EXPR);
  gcc_assert (TREE_OPERAND (t, 0) == fd.v);
  t = TREE_OPERAND (t, 1);
  gcc_assert (TREE_OPERAND (t, 0) == fd.v);
  switch (TREE_CODE (t))
    {
    case PLUS_EXPR:
      fd.step = TREE_OPERAND (t, 1);
      break;
    case MINUS_EXPR:
      fd.step = TREE_OPERAND (t, 1);
      fd.step = fold_build1 (NEGATE_EXPR, TREE_TYPE (fd.step), fd.step);
      break;
    default:
      gcc_unreachable ();
    }

  have_nowait = have_ordered = false;
  sched_kind = OMP_CLAUSE_SCHEDULE_STATIC;
  fd.chunk_size = NULL_TREE;

  for (t = OMP_FOR_CLAUSES (fd.for_stmt); t ; t = OMP_CLAUSE_CHAIN (t))
    switch (TREE_CODE (t))
      {
      case OMP_CLAUSE_NOWAIT:
	have_nowait = true;
	break;
      case OMP_CLAUSE_ORDERED:
	have_ordered = true;
	break;
      case OMP_CLAUSE_SCHEDULE:
	sched_kind = OMP_CLAUSE_SCHEDULE_KIND (t);
	fd.chunk_size = OMP_CLAUSE_SCHEDULE_CHUNK_EXPR (t);
	break;
      default:
	break;
      }

  expand_rec_input_clauses (OMP_FOR_CLAUSES (fd.for_stmt),
			    &fd.pre, &dlist, ctx);

  expand_omp (&OMP_FOR_PRE_BODY (fd.for_stmt), ctx);
  append_to_statement_list (OMP_FOR_PRE_BODY (fd.for_stmt), &fd.pre);

  if (sched_kind == OMP_CLAUSE_SCHEDULE_STATIC && !have_ordered)
    {
      if (fd.chunk_size == NULL)
	expand_omp_for_static_nochunk (&fd);
      else
	expand_omp_for_static_chunk (&fd);
    }
  else
    {
      int fn_index;

      if (sched_kind == OMP_CLAUSE_SCHEDULE_RUNTIME)
	gcc_assert (fd.chunk_size == NULL);
      else if (fd.chunk_size == NULL)
	fd.chunk_size = (sched_kind == OMP_CLAUSE_SCHEDULE_STATIC)
			? integer_zero_node : integer_one_node;

      fn_index = sched_kind + have_ordered * 4;

      expand_omp_for_generic (&fd, BUILT_IN_GOMP_LOOP_STATIC_START + fn_index,
			     BUILT_IN_GOMP_LOOP_STATIC_NEXT + fn_index);
    }

  expand_reduction_clauses (OMP_FOR_CLAUSES (fd.for_stmt), &fd.pre, ctx);
  append_to_statement_list (dlist, &fd.pre);

  if (!have_nowait)
    build_omp_barrier (&fd.pre);

  return fd.pre;
}

/* Expand code for an OpenMP loop directive.  */

static void
expand_omp_for (tree *stmt_p, omp_context *ctx)
{
  tree bind, block, stmt_list;

  push_gimplify_context ();

  expand_omp (&OMP_FOR_BODY (*stmt_p), ctx);

  stmt_list = expand_omp_for_1 (stmt_p, ctx);
  block = make_node (BLOCK);
  bind = build3 (BIND_EXPR, void_type_node, NULL, stmt_list, block);
  maybe_catch_exception (&BIND_EXPR_BODY (bind));
  *stmt_p = bind;

  pop_gimplify_context (bind);
  BIND_EXPR_VARS (bind) = chainon (BIND_EXPR_VARS (bind), ctx->block_vars);
  BLOCK_VARS (block) = BIND_EXPR_VARS (bind);
}

/* Expand code for an OpenMP sections directive.  In pseudo code, we generate

	firstprivate;
	v = GOMP_sections_start (n);
    L0:
	switch (v)
	  {
	  case 0:
	    goto L2;
	  case 1:
	    section 1;
	    goto L1;
	  case 2:
	    ...
	  case n:
	    ...
	    lastprivate;
	  default:
	    abort ();
	  }
    L1:
	v = GOMP_sections_next ();
	goto L0;
    L2:
	reduction;
*/

static void
expand_omp_sections (tree *stmt_p, omp_context *ctx)
{
  tree sec_stmt, label_vec, bind, block, stmt_list, l0, l1, l2, t, u, v;
  tree_stmt_iterator tsi;
  tree dlist;
  unsigned i, len;

  sec_stmt = *stmt_p;
  stmt_list = NULL;

  push_gimplify_context ();

  expand_rec_input_clauses (OMP_SECTIONS_CLAUSES (sec_stmt),
			    &stmt_list, &dlist, ctx);

  tsi = tsi_start (OMP_SECTIONS_BODY (sec_stmt));
  for (len = 0; !tsi_end_p (tsi); len++, tsi_next (&tsi))
    continue;

  l0 = create_artificial_label ();
  l1 = create_artificial_label ();
  l2 = create_artificial_label ();
  v = create_tmp_var (unsigned_type_node, ".section");
  label_vec = make_tree_vec (len + 2);

  t = build_int_cst (unsigned_type_node, len);
  t = tree_cons (NULL, t, NULL);
  u = built_in_decls[BUILT_IN_GOMP_SECTIONS_START];
  t = build_function_call_expr (u, t);
  t = build2 (MODIFY_EXPR, void_type_node, v, t);
  gimplify_and_add (t, &stmt_list);

  t = build1 (LABEL_EXPR, void_type_node, l0);
  gimplify_and_add (t, &stmt_list);

  t = build3 (SWITCH_EXPR, void_type_node, v, NULL, label_vec);
  gimplify_and_add (t, &stmt_list);

  t = build3 (CASE_LABEL_EXPR, void_type_node,
	      build_int_cst (unsigned_type_node, 0), NULL, l2);
  TREE_VEC_ELT (label_vec, 0) = t;
  
  tsi = tsi_start (OMP_SECTIONS_BODY (sec_stmt));
  for (i = 0; i < len; i++, tsi_next (&tsi))
    {
      omp_context *sctx;

      t = create_artificial_label ();
      u = build_int_cst (unsigned_type_node, i + 1);
      u = build3 (CASE_LABEL_EXPR, void_type_node, u, NULL, t);
      TREE_VEC_ELT (label_vec, i + 1) = u;
      t = build1 (LABEL_EXPR, void_type_node, t);
      gimplify_and_add (t, &stmt_list);
  
      t = tsi_stmt (tsi);
      sctx = maybe_lookup_ctx (t);
      gcc_assert (sctx);
      expand_omp (&OMP_SECTION_BODY (t), sctx);
      append_to_statement_list (OMP_SECTION_BODY (t), &stmt_list);

      if (i == len - 1)
	expand_lastprivate_clauses (OMP_SECTIONS_CLAUSES (sec_stmt),
				    NULL, &stmt_list, ctx);

      t = build1 (GOTO_EXPR, void_type_node, l1);
      gimplify_and_add (t, &stmt_list);
    }

  t = create_artificial_label ();
  u = build3 (CASE_LABEL_EXPR, void_type_node, NULL, NULL, t);
  TREE_VEC_ELT (label_vec, len + 1) = u;
  t = build1 (LABEL_EXPR, void_type_node, t);
  gimplify_and_add (t, &stmt_list);

  t = built_in_decls[BUILT_IN_TRAP];
  t = build_function_call_expr (t, NULL);
  gimplify_and_add (t, &stmt_list);

  t = build1 (LABEL_EXPR, void_type_node, l1);
  gimplify_and_add (t, &stmt_list);

  t = built_in_decls[BUILT_IN_GOMP_SECTIONS_NEXT];
  t = build_function_call_expr (t, NULL);
  t = build2 (MODIFY_EXPR, void_type_node, v, t);
  gimplify_and_add (t, &stmt_list);

  t = build1 (GOTO_EXPR, void_type_node, l0);
  gimplify_and_add (t, &stmt_list);

  t = build1 (LABEL_EXPR, void_type_node, l2);
  gimplify_and_add (t, &stmt_list);

  expand_reduction_clauses (OMP_SECTIONS_CLAUSES (sec_stmt), &stmt_list, ctx);
  append_to_statement_list (dlist, &stmt_list);

  /* Unless there's a nowait clause, add a barrier afterward.  */
  if (!find_omp_clause (OMP_SECTIONS_CLAUSES (sec_stmt), OMP_CLAUSE_NOWAIT))
    build_omp_barrier (&stmt_list);

  block = make_node (BLOCK);
  bind = build3 (BIND_EXPR, void_type_node, NULL, stmt_list, block);
  maybe_catch_exception (&BIND_EXPR_BODY (bind));
  *stmt_p = bind;

  pop_gimplify_context (bind);
  BIND_EXPR_VARS (bind) = chainon (BIND_EXPR_VARS (bind), ctx->block_vars);
  BLOCK_VARS (block) = BIND_EXPR_VARS (bind);
}

/* A subroutine of expand_omp_single.  Expand the simple form of
   an OMP_SINGLE, without a copyprivate clause:

     	if (GOMP_single_start ())
	  BODY;
	[ GOMP_barrier (); ]	-> unless 'nowait' is present.
*/

static void
expand_omp_single_simple (tree single_stmt, tree *pre_p)
{
  tree t;

  t = built_in_decls[BUILT_IN_GOMP_SINGLE_START];
  t = build_function_call_expr (t, NULL);
  t = build3 (COND_EXPR, void_type_node, t,
	      OMP_SINGLE_BODY (single_stmt), NULL);
  gimplify_and_add (t, pre_p);

  if (!find_omp_clause (OMP_SINGLE_CLAUSES (single_stmt), OMP_CLAUSE_NOWAIT))
    build_omp_barrier (pre_p);
}

/* A subroutine of expand_omp_single.  Expand the simple form of
   an OMP_SINGLE, with a copyprivate clause:

	#pragma omp single copyprivate (a, b, c)

   Create a new structure to hold copies of 'a', 'b' and 'c' and emit:

      {
	if ((copyout_p = GOMP_single_copy_start ()) == NULL)
	  {
	    BODY;
	    copyout.a = a;
	    copyout.b = b;
	    copyout.c = c;
	    GOMP_single_copy_end (&copyout);
	  }
	else
	  {
	    a = copyout_p->a;
	    b = copyout_p->b;
	    c = copyout_p->c;
	  }
	GOMP_barrier ();
      }
*/

static void
expand_omp_single_copy (tree single_stmt, tree *pre_p, omp_context *ctx)
{
  tree ptr_type, t, args, l0, l1, l2, copyin_seq;

  ctx->sender_decl = create_tmp_var (ctx->record_type, ".omp_copy_o");

  ptr_type = build_pointer_type (ctx->record_type);
  ctx->receiver_decl = create_tmp_var (ptr_type, ".omp_copy_i");

  l0 = create_artificial_label ();
  l1 = create_artificial_label ();
  l2 = create_artificial_label ();

  t = built_in_decls[BUILT_IN_GOMP_SINGLE_COPY_START];
  t = build_function_call_expr (t, NULL);
  t = fold_convert (ptr_type, t);
  t = build2 (MODIFY_EXPR, void_type_node, ctx->receiver_decl, t);
  gimplify_and_add (t, pre_p);

  t = build (EQ_EXPR, boolean_type_node, ctx->receiver_decl,
	     build_int_cst (ptr_type, 0));
  t = build (COND_EXPR, void_type_node, t,
	     build_and_jump (&l0), build_and_jump (&l1));
  gimplify_and_add (t, pre_p);

  t = build1 (LABEL_EXPR, void_type_node, l0);
  gimplify_and_add (t, pre_p);

  append_to_statement_list (OMP_SINGLE_BODY (single_stmt), pre_p);

  copyin_seq = NULL;
  expand_copyprivate_clauses (OMP_SINGLE_CLAUSES (single_stmt), pre_p,
			      &copyin_seq, ctx);

  t = build_fold_addr_expr (ctx->sender_decl);
  args = tree_cons (NULL, t, NULL);
  t = built_in_decls[BUILT_IN_GOMP_SINGLE_COPY_END];
  t = build_function_call_expr (t, args);
  gimplify_and_add (t, pre_p);

  t = build_and_jump (&l2);
  gimplify_and_add (t, pre_p);

  t = build1 (LABEL_EXPR, void_type_node, l1);
  gimplify_and_add (t, pre_p);

  append_to_statement_list (copyin_seq, pre_p);

  t = build1 (LABEL_EXPR, void_type_node, l2);
  gimplify_and_add (t, pre_p);

  build_omp_barrier (pre_p);
}

/* Expand code for an OpenMP single directive.  */

static void
expand_omp_single (tree *stmt_p, omp_context *ctx)
{
  tree bind, block, single_stmt = *stmt_p, dlist;

  push_gimplify_context ();

  block = make_node (BLOCK);
  bind = build3 (BIND_EXPR, void_type_node, NULL, NULL, block);
  *stmt_p = bind;

  expand_rec_input_clauses (OMP_SINGLE_CLAUSES (single_stmt),
			    &BIND_EXPR_BODY (bind), &dlist, ctx);

  expand_omp (&OMP_SINGLE_BODY (single_stmt), ctx);

  if (ctx->record_type)
    expand_omp_single_copy (single_stmt, &BIND_EXPR_BODY (bind), ctx);
  else
    expand_omp_single_simple (single_stmt, &BIND_EXPR_BODY (bind));

  append_to_statement_list (dlist, &BIND_EXPR_BODY (bind));

  maybe_catch_exception (&BIND_EXPR_BODY (bind));
  pop_gimplify_context (bind);
  BIND_EXPR_VARS (bind) = chainon (BIND_EXPR_VARS (bind), ctx->block_vars);
  BLOCK_VARS (block) = BIND_EXPR_VARS (bind);
}

/* Expand code for an OpenMP master directive.  */

static void
expand_omp_master (tree *stmt_p, omp_context *ctx)
{
  tree bind, block, stmt = *stmt_p, lab = NULL, x;

  push_gimplify_context ();

  block = make_node (BLOCK);
  bind = build3 (BIND_EXPR, void_type_node, NULL, NULL, block);
  *stmt_p = bind;

  x = built_in_decls[BUILT_IN_OMP_GET_THREAD_NUM];
  x = build_function_call_expr (x, NULL);
  x = build2 (EQ_EXPR, boolean_type_node, x, integer_zero_node);
  x = build3 (COND_EXPR, void_type_node, x, NULL, build_and_jump (&lab));
  gimplify_and_add (x, &BIND_EXPR_BODY (bind));

  expand_omp (&OMP_MASTER_BODY (stmt), ctx);
  append_to_statement_list (OMP_MASTER_BODY (stmt), &BIND_EXPR_BODY (bind));

  x = build1 (LABEL_EXPR, void_type_node, lab);
  gimplify_and_add (x, &BIND_EXPR_BODY (bind));

  maybe_catch_exception (&BIND_EXPR_BODY (bind));
  pop_gimplify_context (bind);
  BIND_EXPR_VARS (bind) = chainon (BIND_EXPR_VARS (bind), ctx->block_vars);
  BLOCK_VARS (block) = BIND_EXPR_VARS (bind);
}

/* Expand code for an OpenMP ordered directive.  */

static void
expand_omp_ordered (tree *stmt_p, omp_context *ctx)
{
  tree bind, block, stmt = *stmt_p, x;

  push_gimplify_context ();

  block = make_node (BLOCK);
  bind = build3 (BIND_EXPR, void_type_node, NULL, NULL, block);
  *stmt_p = bind;

  x = built_in_decls[BUILT_IN_GOMP_ORDERED_START];
  x = build_function_call_expr (x, NULL);
  gimplify_and_add (x, &BIND_EXPR_BODY (bind));

  expand_omp (&OMP_ORDERED_BODY (stmt), ctx);
  append_to_statement_list (OMP_ORDERED_BODY (stmt), &BIND_EXPR_BODY (bind));

  x = built_in_decls[BUILT_IN_GOMP_ORDERED_END];
  x = build_function_call_expr (x, NULL);
  gimplify_and_add (x, &BIND_EXPR_BODY (bind));

  maybe_catch_exception (&BIND_EXPR_BODY (bind));
  pop_gimplify_context (bind);
  BIND_EXPR_VARS (bind) = chainon (BIND_EXPR_VARS (bind), ctx->block_vars);
  BLOCK_VARS (block) = BIND_EXPR_VARS (bind);
}

/* Expand code for an OpenMP critical directive.  */

/* Gimplify an OMP_CRITICAL statement.  This is a relatively simple
   substitution of a couple of function calls.  But in the NAMED case,
   requires that languages coordinate a symbol name.  It is therefore
   best put here in common code.  */

static GTY((param1_is (tree), param2_is (tree)))
  splay_tree critical_name_mutexes;

static void
expand_omp_critical (tree *stmt_p, omp_context *ctx)
{
  tree bind, block, stmt = *stmt_p;
  tree lock, unlock, name;

  name = OMP_CRITICAL_NAME (stmt);
  if (name)
    {
      tree decl, args;
      splay_tree_node n;

      if (!critical_name_mutexes)
	critical_name_mutexes
	  = splay_tree_new_ggc (splay_tree_compare_pointers);

      n = splay_tree_lookup (critical_name_mutexes, (splay_tree_key) name);
      if (n == NULL)
	{
	  char *new_str;

	  decl = create_tmp_var_raw (ptr_type_node, NULL);

	  new_str = ACONCAT ((".gomp_critical_user_",
			      IDENTIFIER_POINTER (name), NULL));
	  DECL_NAME (decl) = get_identifier (new_str);
	  TREE_PUBLIC (decl) = 1;
	  TREE_STATIC (decl) = 1;
	  DECL_COMMON (decl) = 1;
	  DECL_ARTIFICIAL (decl) = 1;
	  DECL_IGNORED_P (decl) = 1;
	  cgraph_varpool_finalize_decl (decl);

	  splay_tree_insert (critical_name_mutexes, (splay_tree_key) name,
			     (splay_tree_value) decl);
	}
      else
	decl = (tree) n->value;

      args = tree_cons (NULL, build_fold_addr_expr (decl), NULL);
      lock = built_in_decls[BUILT_IN_GOMP_CRITICAL_NAME_START];
      lock = build_function_call_expr (lock, args);

      args = tree_cons (NULL, build_fold_addr_expr (decl), NULL);
      unlock = built_in_decls[BUILT_IN_GOMP_CRITICAL_NAME_END];
      unlock = build_function_call_expr (unlock, args);
    }
  else
    {
      lock = built_in_decls[BUILT_IN_GOMP_CRITICAL_START];
      lock = build_function_call_expr (lock, NULL);

      unlock = built_in_decls[BUILT_IN_GOMP_CRITICAL_END];
      unlock = build_function_call_expr (unlock, NULL);
    }

  push_gimplify_context ();

  block = make_node (BLOCK);
  bind = build3 (BIND_EXPR, void_type_node, NULL, NULL, block);
  *stmt_p = bind;

  gimplify_and_add (lock, &BIND_EXPR_BODY (bind));

  expand_omp (&OMP_CRITICAL_BODY (stmt), ctx);
  maybe_catch_exception (&OMP_CRITICAL_BODY (stmt));
  append_to_statement_list (OMP_CRITICAL_BODY (stmt), &BIND_EXPR_BODY (bind));

  gimplify_and_add (unlock, &BIND_EXPR_BODY (bind));

  pop_gimplify_context (bind);
  BIND_EXPR_VARS (bind) = chainon (BIND_EXPR_VARS (bind), ctx->block_vars);
  BLOCK_VARS (block) = BIND_EXPR_VARS (bind);
}

/* Pass *TP back through the gimplifier within the context determined by WI.
   This handles replacement of DECL_VALUE_EXPR, as well as adjusting the 
   flags on ADDR_EXPR.  */

static void
expand_regimplify (tree *tp, struct walk_stmt_info *wi)
{
  enum gimplify_status gs;
  tree pre = NULL;

  if (wi->is_lhs)
    gs = gimplify_expr (tp, &pre, NULL, is_gimple_lvalue, fb_lvalue);
  else if (wi->val_only)
    gs = gimplify_expr (tp, &pre, NULL, is_gimple_val, fb_rvalue);
  else
    gs = gimplify_expr (tp, &pre, NULL, is_gimple_formal_tmp_var, fb_rvalue);
  gcc_assert (gs == GS_ALL_DONE);

  if (pre)
    tsi_link_before (&wi->tsi, pre, TSI_SAME_STMT);
}

static tree
expand_omp_1 (tree *tp, int *walk_subtrees, void *data)
{
  struct walk_stmt_info *wi = data;
  omp_context *ctx = wi->info;
  tree t = *tp;

  *walk_subtrees = 0;
  switch (TREE_CODE (*tp))
    {
    case OMP_PARALLEL:
      ctx = maybe_lookup_ctx (t);
      if (!ctx->is_nested)
	expand_omp_parallel (tp, ctx);
      break;

    case OMP_FOR:
      ctx = maybe_lookup_ctx (t);
      gcc_assert (ctx);
      expand_omp_for (tp, ctx);
      break;

    case OMP_SECTIONS:
      ctx = maybe_lookup_ctx (t);
      gcc_assert (ctx);
      expand_omp_sections (tp, ctx);
      break;

    case OMP_SINGLE:
      ctx = maybe_lookup_ctx (t);
      gcc_assert (ctx);
      expand_omp_single (tp, ctx);
      break;

    case OMP_MASTER:
      ctx = maybe_lookup_ctx (t);
      gcc_assert (ctx);
      expand_omp_master (tp, ctx);
      break;

    case OMP_ORDERED:
      ctx = maybe_lookup_ctx (t);
      gcc_assert (ctx);
      expand_omp_ordered (tp, ctx);
      break;

    case OMP_CRITICAL:
      ctx = maybe_lookup_ctx (t);
      gcc_assert (ctx);
      expand_omp_critical (tp, ctx);
      break;

    case VAR_DECL:
      if (ctx && DECL_HAS_VALUE_EXPR_P (t))
	expand_regimplify (tp, wi);
      break;

    case ADDR_EXPR:
      if (ctx)
	expand_regimplify (tp, wi);
      break;

    case ARRAY_REF:
    case ARRAY_RANGE_REF:
    case REALPART_EXPR:
    case IMAGPART_EXPR:
    case COMPONENT_REF:
    case VIEW_CONVERT_EXPR:
      if (ctx)
	expand_regimplify (tp, wi);
      break;

    case INDIRECT_REF:
      if (ctx)
	{
	  wi->is_lhs = false;
	  wi->val_only = true;
	  expand_regimplify (&TREE_OPERAND (t, 0), wi);
	}
      break;

    default:
      if (!TYPE_P (t) && !DECL_P (t))
	*walk_subtrees = 1;
      break;
    }

  return NULL_TREE;
}

static void
expand_omp (tree *stmt_p, omp_context *ctx)
{
  struct walk_stmt_info wi;

  memset (&wi, 0, sizeof (wi));
  wi.callback = expand_omp_1;
  wi.info = ctx;
  wi.val_only = true;
  wi.want_locations = true;

  walk_stmts (&wi, stmt_p);
}

/* Main entry point.  */

static void
execute_lower_omp (void)
{
  all_contexts = splay_tree_new (splay_tree_compare_pointers, 0,
				 delete_omp_context);

  scan_omp (&DECL_SAVED_TREE (current_function_decl), NULL);
  gcc_assert (parallel_nesting_level == 0);

  if (all_contexts->root)
    expand_omp (&DECL_SAVED_TREE (current_function_decl), NULL);

  splay_tree_delete (all_contexts);
  all_contexts = NULL;
}

static bool
gate_lower_omp (void)
{
  return flag_openmp != 0;
}

struct tree_opt_pass pass_lower_omp = 
{
  "omplower",				/* name */
  gate_lower_omp,			/* gate */
  execute_lower_omp,			/* execute */
  NULL,					/* sub */
  NULL,					/* next */
  0,					/* static_pass_number */
  0,					/* tv_id */
  PROP_gimple_any,			/* properties_required */
  PROP_gimple_lomp,			/* properties_provided */
  0,					/* properties_destroyed */
  0,					/* todo_flags_start */
  TODO_dump_func,			/* todo_flags_finish */
  0					/* letter */
};


/* The following is a utility to diagnose OpenMP structured block violations.
   It's part of the "omplower" pass, as that's invoked too late.  It should
   be invoked by the respective front ends after gimplification.  */

static splay_tree all_labels;

/* Check for mismatched contexts and generate an error if needed.  Return
   true if an error is detected.  */

static bool
diagnose_sb_0 (tree *stmt_p, tree branch_ctx, tree label_ctx)
{
  bool exit_p = true;

  if ((label_ctx ? TREE_VALUE (label_ctx) : NULL) == branch_ctx)
    return false;

  /* Try to avoid confusing the user by producing and error message
     with correct "exit" or "enter" verbage.  We prefer "exit"
     unless we can show that LABEL_CTX is nested within BRANCH_CTX.  */
  if (branch_ctx == NULL)
    exit_p = false;
  else
    {
      while (label_ctx)
	{
	  if (TREE_VALUE (label_ctx) == branch_ctx)
	    {
	      exit_p = false;
	      break;
	    }
	  label_ctx = TREE_CHAIN (label_ctx);
	}
    }

  if (exit_p)
    error ("invalid exit from OpenMP structured block");
  else
    error ("invalid entry to OpenMP structured block");

  *stmt_p = build_empty_stmt ();
  return true;
}

/* Pass 1: Create a minimal tree of OpenMP structured blocks, and record
   where in the tree each label is found.  */

static tree
diagnose_sb_1 (tree *tp, int *walk_subtrees, void *data)
{
  struct walk_stmt_info *wi = data;
  tree context = (tree) wi->info;
  tree inner_context;
  tree t = *tp;

  *walk_subtrees = 0;
  switch (TREE_CODE (t))
    {
    case OMP_PARALLEL:
    case OMP_SECTIONS:
    case OMP_SINGLE:
      walk_tree (&OMP_CLAUSES (t), diagnose_sb_1, wi, NULL);
      /* FALLTHRU */
    case OMP_SECTION:
    case OMP_MASTER:
    case OMP_ORDERED:
    case OMP_CRITICAL:
      /* The minimal context here is just a tree of statements.  */
      inner_context = tree_cons (NULL, t, context);
      wi->info = inner_context;
      walk_stmts (wi, &OMP_BODY (t));
      wi->info = context;
      break;

    case OMP_FOR:
      walk_tree (&OMP_FOR_CLAUSES (t), diagnose_sb_1, wi, NULL);
      inner_context = tree_cons (NULL, t, context);
      wi->info = inner_context;
      walk_tree (&OMP_FOR_INIT (t), diagnose_sb_1, wi, NULL);
      walk_tree (&OMP_FOR_COND (t), diagnose_sb_1, wi, NULL);
      walk_tree (&OMP_FOR_INCR (t), diagnose_sb_1, wi, NULL);
      walk_stmts (wi, &OMP_FOR_PRE_BODY (t));
      walk_stmts (wi, &OMP_FOR_BODY (t));
      wi->info = context;
      break;

    case LABEL_EXPR:
      splay_tree_insert (all_labels, (splay_tree_key) LABEL_EXPR_LABEL (t),
			 (splay_tree_value) context);
      break;

    default:
      break;
    }

  return NULL_TREE;
}

/* Pass 2: Check each branch and see if its context differs from that of
   the destination label's context.  */

static tree
diagnose_sb_2 (tree *tp, int *walk_subtrees, void *data)
{
  struct walk_stmt_info *wi = data;
  tree context = (tree) wi->info;
  splay_tree_node n;
  tree t = *tp;

  *walk_subtrees = 0;
  switch (TREE_CODE (t))
    {
    case OMP_PARALLEL:
    case OMP_SECTIONS:
    case OMP_SINGLE:
      walk_tree (&OMP_CLAUSES (t), diagnose_sb_2, wi, NULL);
      /* FALLTHRU */
    case OMP_SECTION:
    case OMP_MASTER:
    case OMP_ORDERED:
    case OMP_CRITICAL:
      wi->info = t;
      walk_stmts (wi, &OMP_BODY (t));
      wi->info = context;
      break;

    case OMP_FOR:
      walk_tree (&OMP_FOR_CLAUSES (t), diagnose_sb_2, wi, NULL);
      wi->info = t;
      walk_tree (&OMP_FOR_INIT (t), diagnose_sb_2, wi, NULL);
      walk_tree (&OMP_FOR_COND (t), diagnose_sb_2, wi, NULL);
      walk_tree (&OMP_FOR_INCR (t), diagnose_sb_2, wi, NULL);
      walk_stmts (wi, &OMP_FOR_PRE_BODY (t));
      walk_stmts (wi, &OMP_FOR_BODY (t));
      wi->info = context;
      break;

    case GOTO_EXPR:
      {
	tree lab = GOTO_DESTINATION (t);
	if (TREE_CODE (lab) != LABEL_DECL)
	  break;

	n = splay_tree_lookup (all_labels, (splay_tree_key) lab);
	diagnose_sb_0 (tp, context, n ? (tree) n->value : NULL_TREE);
      }
      break;

    case SWITCH_EXPR:
      {
	tree vec = SWITCH_LABELS (t);
	int i, len = TREE_VEC_LENGTH (vec);
	for (i = 0; i < len; ++i)
	  {
	    tree lab = CASE_LABEL (TREE_VEC_ELT (vec, i));
	    n = splay_tree_lookup (all_labels, (splay_tree_key) lab);
	    if (diagnose_sb_0 (tp, context, (tree) n->value))
	      break;
	  }
      }
      break;

    case RETURN_EXPR:
      diagnose_sb_0 (tp, context, NULL_TREE);
      break;

    default:
      break;
    }

  return NULL_TREE;
}

void
diagnose_omp_structured_block_errors (tree fndecl)
{
  tree save_current = current_function_decl;
  struct walk_stmt_info wi;

  current_function_decl = fndecl;

  all_labels = splay_tree_new (splay_tree_compare_pointers, 0, 0);

  memset (&wi, 0, sizeof (wi));
  wi.callback = diagnose_sb_1;
  walk_stmts (&wi, &DECL_SAVED_TREE (fndecl));

  memset (&wi, 0, sizeof (wi));
  wi.callback = diagnose_sb_2;
  wi.want_locations = true;
  wi.want_return_expr = true;
  walk_stmts (&wi, &DECL_SAVED_TREE (fndecl));

  splay_tree_delete (all_labels);
  all_labels = NULL;

  current_function_decl = save_current;
}

#include "gt-omp-low.h"
