/* Exception handling semantics and decomposition for trees.
   Copyright (C) 2003, 2004, 2005, 2006, 2007 Free Software Foundation, Inc.

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
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "rtl.h"
#include "tm_p.h"
#include "flags.h"
#include "function.h"
#include "except.h"
#include "tree-flow.h"
#include "tree-dump.h"
#include "tree-inline.h"
#include "tree-iterator.h"
#include "tree-pass.h"
#include "timevar.h"
#include "langhooks.h"
#include "ggc.h"
#include "toplev.h"
#include "gimple.h"

/* In some instances a tree and a gimple need to be stored in a same table,
   i.e. in hash tables. This is a structure to do this. */
typedef union {tree t; gimple g;} treemple;

/* Nonzero if we are using EH to handle cleanups.  */
static int using_eh_for_cleanups_p = 0;

void
using_eh_for_cleanups (void)
{
  using_eh_for_cleanups_p = 1;
}

/* Misc functions used in this file.  */

/* Compare and hash for any structure which begins with a canonical
   pointer.  Assumes all pointers are interchangeable, which is sort
   of already assumed by gcc elsewhere IIRC.  */

static int
struct_ptr_eq (const void *a, const void *b)
{
  const void * const * x = (const void * const *) a;
  const void * const * y = (const void * const *) b;
  return *x == *y;
}

static hashval_t
struct_ptr_hash (const void *a)
{
  const void * const * x = (const void * const *) a;
  return (size_t)*x >> 4;
}


/* Remember and lookup EH region data for arbitrary statements.
   Really this means any statement that could_throw_p.  We could
   stuff this information into the stmt_ann data structure, but:

   (1) We absolutely rely on this information being kept until
   we get to rtl.  Once we're done with lowering here, if we lose
   the information there's no way to recover it!

   (2) There are many more statements that *cannot* throw as
   compared to those that can.  We should be saving some amount
   of space by only allocating memory for those that can throw.  */

static void
record_stmt_eh_region (struct eh_region *region, gimple t)
{
  if (!region)
    return;

  add_stmt_to_eh_region (t, get_eh_region_number (region));
}


/* Add statement T in function IFUN to EH region NUM.  */

void
add_stmt_to_eh_region_fn (struct function *ifun, gimple t, int num)
{
  struct throw_stmt_node *n;
  void **slot;

  gcc_assert (num >= 0);
  gcc_assert (gimple_code (t) != GIMPLE_RESX);

  n = GGC_NEW (struct throw_stmt_node);
  n->stmt = t;
  n->region_nr = num;

  if (!get_eh_throw_stmt_table (ifun))
    set_eh_throw_stmt_table (ifun, htab_create_ggc (31, struct_ptr_hash,
						    struct_ptr_eq,
						    ggc_free));

  slot = htab_find_slot (get_eh_throw_stmt_table (ifun), n, INSERT);
  gcc_assert (!*slot);
  *slot = n;
}


/* Add statement T in the current function (cfun) to EH region number
   NUM.  */

void
add_stmt_to_eh_region (gimple t, int num)
{
  add_stmt_to_eh_region_fn (cfun, t, num);
}


/* Remove statement T in function IFUN from the EH region holding it.  */

bool
remove_stmt_from_eh_region_fn (struct function *ifun, gimple t)
{
  struct throw_stmt_node dummy;
  void **slot;

  if (!get_eh_throw_stmt_table (ifun))
    return false;

  dummy.stmt = t;
  slot = htab_find_slot (get_eh_throw_stmt_table (ifun), &dummy,
                        NO_INSERT);
  if (slot)
    {
      htab_clear_slot (get_eh_throw_stmt_table (ifun), slot);
      return true;
    }
  else
    return false;
}


/* Remove statement T in the current function (cfun) from the EH
   region holding it.  */

bool
remove_stmt_from_eh_region (gimple t)
{
  return remove_stmt_from_eh_region_fn (cfun, t);
}

/* Determine if statement T is inside an EH region in function IFUN.
   Return the EH region number if found, return -2 if IFUN does not
   have an EH table and -1 if T could not be found in IFUN's EH region
   table.  */

int
lookup_stmt_eh_region_fn (struct function *ifun, gimple t)
{
  struct throw_stmt_node *p, n;

  if (!get_eh_throw_stmt_table (ifun))
    return -2;

  n.stmt = t;
  p = (struct throw_stmt_node *) htab_find (get_eh_throw_stmt_table (ifun), &n);
  return (p ? p->region_nr : -1);
}


/* Determine if statement T is inside an EH region in the current
   function (cfun).  Return the EH region number if found, return -2
   if IFUN does not have an EH table and -1 if T could not be found in
   IFUN's EH region table.  */

int
lookup_stmt_eh_region (gimple t)
{
  /* We can get called from initialized data when -fnon-call-exceptions
     is on; prevent crash.  */
  if (!cfun)
    return -1;

  return lookup_stmt_eh_region_fn (cfun, t);
}

/* Determine if expression T is inside an EH region in the current
   function (cfun).  Return the EH region number if found, return -2
   if IFUN does not have an EH table and -1 if T could not be found in
   IFUN's EH region table.

   FIXME tuples.  This is horrid.  It's used by gimple_to_tree to
   record an EH region number on the generated expression statement.  */

int
lookup_expr_eh_region (tree t)
{
  if (EXPR_P (t))
    {
      tree_ann_common_t ann = get_tree_common_ann (t);
      return (int) ann->rn;
    }

  return -1;
}


/* First pass of EH node decomposition.  Build up a tree of GIMPLE_TRY_FINALLY
   nodes and LABEL_DECL nodes.  We will use this during the second phase to
   determine if a goto leaves the body of a TRY_FINALLY_EXPR node.  */

struct finally_tree_node
{
  /* When storing a GIMPLE_TRY, we have to record a gimple.  However
     when deciding whether a GOTO to a certain LABEL_DECL (which is a
     tree) leaves the TRY block, its necessary to record a tree in
     this field.  Thus a treemple is used. */
  treemple child; 
  gimple parent;
};

/* Note that this table is *not* marked GTY.  It is short-lived.  */
static htab_t finally_tree;

static void
record_in_finally_tree (treemple child, gimple parent)
{
  struct finally_tree_node *n;
  void **slot;

  n = XNEW (struct finally_tree_node);
  n->child = child;
  n->parent = parent;

  slot = htab_find_slot (finally_tree, n, INSERT);
  gcc_assert (!*slot);
  *slot = n;
}

static void
collect_finally_tree (gimple stmt, gimple region);

/* Go through the gimple sequence. Works with collect_finally_tree() to 
   record all GIMPLE_LABEL and GIMPLE_TRY statements. */

static void
collect_finally_tree_1 (gimple_seq seq, gimple region)
{
  gimple_stmt_iterator gsi;

  for (gsi = gsi_start (seq); !gsi_end_p (gsi); gsi_next (&gsi))
    collect_finally_tree (gsi_stmt (gsi), region);
}

static void
collect_finally_tree (gimple stmt, gimple region)
{
  size_t i, n;
  switch (gimple_code (stmt))
    {
    /* FIXME tuples: Why is GIMLE_SWITCH necessary? */
    case GIMPLE_SWITCH:
      n = gimple_switch_num_labels (stmt);
      for (i = 0; i < n; i++)
      {
        tree lab = gimple_switch_label (stmt, i);
        record_in_finally_tree ((treemple) lab, region);
      }
      break;

    case GIMPLE_LABEL:
      record_in_finally_tree ((treemple) gimple_label_label (stmt), region);
      break;

    case GIMPLE_TRY:
      if (gimple_try_kind (stmt) == GIMPLE_TRY_FINALLY)
        {
          record_in_finally_tree ( (treemple) stmt, region);
          collect_finally_tree_1 (gimple_try_eval (stmt), stmt);
          collect_finally_tree_1 (gimple_try_cleanup (stmt), stmt);
        }
      else if (gimple_try_kind (stmt) == GIMPLE_TRY_CATCH)
        {
          collect_finally_tree_1 (gimple_try_eval (stmt), region);
          collect_finally_tree_1 (gimple_try_cleanup (stmt), region);
        }
      break;

    case GIMPLE_CATCH:
      collect_finally_tree_1 (gimple_catch_handler (stmt), region);
      break;

    case GIMPLE_EH_FILTER:
      collect_finally_tree_1 (gimple_eh_filter_failure (stmt), region);
      break;

    default:
      /* A type, a decl, or some kind of statement that we're not
	 interested in.  Don't walk them.  */
      break;
    }
}


/* Use the finally tree to determine if a jump from START to TARGET
   would leave the try_finally node that START lives in.  */

static bool
outside_finally_tree (treemple start, gimple target)
{
  struct finally_tree_node n, *p;

  do
    {
      n.child = start;
      p = (struct finally_tree_node *) htab_find (finally_tree, &n);
      if (!p)
	return true;
      start.g = p->parent;
    }
  while (start.g != target);

  return false;
}

/* Second pass of EH node decomposition.  Actually transform the GIMPLE_TRY
   nodes into a set of gotos, magic labels, and eh regions.
   The eh region creation is straight-forward, but frobbing all the gotos
   and such into shape isn't.  */

/* State of the world while lowering.  */

struct leh_state
{
  /* What's "current" while constructing the eh region tree.  These
     correspond to variables of the same name in cfun->eh, which we
     don't have easy access to.  */
  struct eh_region *cur_region;
  struct eh_region *prev_try;

  /* Processing of TRY_FINALLY requires a bit more state.  This is
     split out into a separate structure so that we don't have to
     copy so much when processing other nodes.  */
  struct leh_tf_state *tf;
};

struct leh_tf_state
{
  /* Pointer to the GIMPLE_TRY_FINALLY node under discussion.  The
     try_finally_expr is the original GIMPLE_TRY_FINALLY.  We need to retain
     this so that outside_finally_tree can reliably reference the tree used
     in the collect_finally_tree data structures.  */
  gimple try_finally_expr;
  gimple top_p;
  /* While lowering a top_p usually it is expanded into multiple statements,
     thus we need the following field to store them. */
  gimple_seq top_p_seq;

  /* The state outside this try_finally node.  */
  struct leh_state *outer;

  /* The exception region created for it.  */
  struct eh_region *region;

  /* The GOTO_QUEUE is is an array of GIMPLE_GOTO and GIMPLE_RETURN statements
     that are seen to escape this GIMPLE_TRY_FINALLY node.
     The idea is to record a gimple statement for everything except for 
     the conditionals, which get their labels recorded. Since labels are of
     type 'tree', we need this node to store both gimple and tree objects. */
  struct goto_queue_node {
    treemple stmt;
    gimple_seq repl_stmt;
    treemple cont_stmt;
    int index;
    /* this is used when index >= 0 to indicate that stmt is a label(as
       opposed to a goto stmt) */
    int is_label;
  } *goto_queue;
  size_t goto_queue_size;
  size_t goto_queue_active;

  /* Pointer map to help in searching qoto_queue when it is large.  */
  struct pointer_map_t *goto_queue_map;

  /* The set of unique labels seen as entries in the goto queue.  */
  VEC(tree,heap) *dest_array;

  /* A label to be added at the end of the completed transformed
     sequence.  It will be set if may_fallthru was true *at one time*,
     though subsequent transformations may have cleared that flag.  */
  tree fallthru_label;

  /* A label that has been registered with except.c to be the
     landing pad for this try block.  */
  tree eh_label;

  /* True if it is possible to fall out the bottom of the try block.
     Cleared if the fallthru is converted to a goto.  */
  bool may_fallthru;

  /* True if any entry in goto_queue is a GIMPLE_RETURN.  */
  bool may_return;

  /* True if the finally block can receive an exception edge.
     Cleared if the exception case is handled by code duplication.  */
  bool may_throw;
};

static gimple_seq lower_eh_filter (struct leh_state *, gimple);

/* Search for STMT in the goto queue.  Return the replacement,
   or null if the statement isn't in the queue.  */

#define LARGE_GOTO_QUEUE 20

static void lower_eh_constructs_1 (struct leh_state *state, gimple_seq seq);

static gimple_seq
find_goto_replacement (struct leh_tf_state *tf, treemple stmt)
{
  unsigned int i;
  void **slot;

  if (tf->goto_queue_active < LARGE_GOTO_QUEUE)
    {
      for (i = 0; i < tf->goto_queue_active; i++)
	if ( tf->goto_queue[i].stmt.t == stmt.t)
	  return tf->goto_queue[i].repl_stmt;
      return NULL;
    }

  /* If we have a large number of entries in the goto_queue, create a
     pointer map and use that for searching.  */

  if (!tf->goto_queue_map)
    {
      tf->goto_queue_map = pointer_map_create ();
      for (i = 0; i < tf->goto_queue_active; i++)
	{
	  slot = pointer_map_insert (tf->goto_queue_map,
                                     tf->goto_queue[i].stmt.t);
          gcc_assert (*slot == NULL);
	  *slot = &tf->goto_queue[i];
	}
    }

  slot = pointer_map_contains (tf->goto_queue_map, stmt.t);
  if (slot != NULL)
    return (((struct goto_queue_node *) *slot)->repl_stmt);

  return NULL;
}

/* A subroutine of replace_goto_queue_1.  Handles the sub-clauses of a
   lowered GIMPLE_COND.  If, by chance, the replacement is a simple goto,
   then we can just splat it in, otherwise we add the new stmts immediately
   after the GIMPLE_COND and redirect.  */

static void
replace_goto_queue_cond_clause (tree *tp, struct leh_tf_state *tf,
				gimple_stmt_iterator *gsi)
{
  tree label;
  gimple_seq new;

  new = find_goto_replacement (tf, (treemple)*tp);
  if (!new)
    return;

  if (gimple_seq_singleton_p (new)
      && gimple_code (gimple_seq_first_stmt (new)) == GIMPLE_GOTO)
    {
      *tp = gimple_goto_dest (gimple_seq_first_stmt (new));
      return;
    }

  label = build1 (LABEL_EXPR, void_type_node, NULL_TREE);
  /* Set the new label for the GIMPLE_COND */
  *tp = label;

  gsi_insert_after (gsi, gimple_build_label (label), GSI_CONTINUE_LINKING);
  gsi_insert_seq_after (gsi, new, GSI_CONTINUE_LINKING);
}

/* The real work of replace_goto_queue.  Returns with TSI updated to
   point to the next statement.  */

static void replace_goto_queue_stmt_list (gimple_seq, struct leh_tf_state *);

static void
replace_goto_queue_1 (gimple stmt, struct leh_tf_state *tf,
		      gimple_stmt_iterator *gsi)
{
  gimple_seq seq;
  switch (gimple_code (stmt))
    {
    case GIMPLE_GOTO:
    case GIMPLE_RETURN:
      seq = find_goto_replacement (tf, (treemple) stmt);
      if (seq)
	{
	  gsi_insert_seq_before (gsi, seq, GSI_SAME_STMT);
	  gsi_remove (gsi, false);
	  return;
	}
      break;

    case GIMPLE_COND:
      replace_goto_queue_cond_clause (gimple_op_ptr (stmt, 2), tf, gsi);
      replace_goto_queue_cond_clause (gimple_op_ptr (stmt, 3), tf, gsi);
      break;

    case GIMPLE_TRY:
      replace_goto_queue_stmt_list (gimple_try_eval (stmt), tf);
      replace_goto_queue_stmt_list (gimple_try_cleanup (stmt), tf);
      break;
    case GIMPLE_CATCH:
      replace_goto_queue_stmt_list (gimple_catch_handler (stmt), tf);
      break;
    case GIMPLE_EH_FILTER:
      replace_goto_queue_stmt_list (gimple_eh_filter_failure (stmt), tf);
      break;

    default:
      /* These won't have gotos in them.  */
      break;
    }

  gsi_next (gsi);
}

/* A subroutine of replace_goto_queue.  Handles GIMPLE_SEQ.  */

static void
replace_goto_queue_stmt_list (gimple_seq seq, struct leh_tf_state *tf)
{
  gimple_stmt_iterator gsi = gsi_start (seq);

  while (!gsi_end_p (gsi))
    replace_goto_queue_1 (gsi_stmt (gsi), tf, &gsi);
}

/* Replace all goto queue members.  */

static void
replace_goto_queue (struct leh_tf_state *tf)
{
  if (tf->goto_queue_active == 0)
    return;
  replace_goto_queue_stmt_list (tf->top_p_seq, tf);
}

/* For any GIMPLE_GOTO or GIMPLE_RETURN, decide whether it leaves a try_finally
   node, and if so record that fact in the goto queue associated with that
   try_finally node.  */

static void
maybe_record_in_goto_queue (struct leh_state *state, gimple stmt)
{
  struct leh_tf_state *tf = state->tf;
  struct goto_queue_node *q;
  treemple new_stmt;
  int new_is_label;
  size_t active, size;
  int index;

  if (!tf)
    return;

  switch (gimple_code (stmt))
    {
    case GIMPLE_GOTO:
      {
	tree lab = gimple_goto_dest (stmt);

	/* Computed and non-local gotos do not get processed.  Given
	   their nature we can neither tell whether we've escaped the
	   finally block nor redirect them if we knew.  */
	if (TREE_CODE (lab) != LABEL_DECL)
	  return;

	/* No need to record gotos that don't leave the try block.  */
	if (! outside_finally_tree ( (treemple) lab, tf->try_finally_expr))
	  return;

	if (! tf->dest_array)
	  {
	    tf->dest_array = VEC_alloc (tree, heap, 10);
	    VEC_quick_push (tree, tf->dest_array, lab);
	    index = 0;
	  }
	else
	  {
	    int n = VEC_length (tree, tf->dest_array);
	    for (index = 0; index < n; ++index)
	      if (VEC_index (tree, tf->dest_array, index) == lab)
		break;
	    if (index == n)
	      VEC_safe_push (tree, heap, tf->dest_array, lab);
	  }
        
        /* In the case of a GOTO we want to record the destination label,
	   since with a GIMPLE_COND we have an easy access to the then/else
	   labels. */
        new_stmt.t = lab;
        new_is_label = 1;
      }
      break;

    case GIMPLE_RETURN:
      tf->may_return = true;
      index = -1;
      new_stmt.g = stmt;
      new_is_label = 0;
      break;

    default:
      gcc_unreachable ();
    }

  gcc_assert (!tf->goto_queue_map);

  active = tf->goto_queue_active;
  size = tf->goto_queue_size;
  if (active >= size)
    {
      size = (size ? size * 2 : 32);
      tf->goto_queue_size = size;
      tf->goto_queue
         = XRESIZEVEC (struct goto_queue_node, tf->goto_queue, size);
    }

  q = &tf->goto_queue[active];
  tf->goto_queue_active = active + 1;

  memset (q, 0, sizeof (*q));
  q->stmt = new_stmt;
  q->is_label = new_is_label;
  q->index = index;
}

#ifdef ENABLE_CHECKING
/* We do not process GIMPLE_SWITCHes for now.  As long as the original source
   was in fact structured, and we've not yet done jump threading, then none
   of the labels will leave outer GIMPLE_TRY_FINALLY nodes. Verify this.  */

static void
verify_norecord_switch_expr (struct leh_state *state, gimple switch_expr)
{
  struct leh_tf_state *tf = state->tf;
  size_t i, n;

  if (!tf)
    return;

  n = gimple_switch_num_labels (switch_expr);

  for (i = 0; i < n; ++i)
    {
      tree lab = gimple_switch_label (switch_expr, i);
      gcc_assert (!outside_finally_tree ( (treemple) lab,
                                          tf->try_finally_expr));
    }
}
#else
#define verify_norecord_switch_expr(state, switch_expr)
#endif

/* Redirect a RETURN_EXPR pointed to by STMT_P to FINLAB.  Place in CONT_P
   whatever is needed to finish the return.  If MOD is non-null, insert it
   before the new branch.  RETURN_VALUE_P is a cache containing a temporary
   variable to be used in manipulating the value returned from the function.  */

static void
do_return_redirection (struct goto_queue_node *q, tree finlab, gimple_seq mod,
		       tree *return_value_p)
{
  tree ret_expr;
  gimple x;

  /* In the case of a return, the queue node must be a gimple statement. */
  gcc_assert (q->is_label);

  ret_expr = gimple_return_retval (q->stmt.g);

  if (ret_expr)
    {

      if (!*return_value_p)
        *return_value_p = ret_expr;
      else
        gcc_assert (*return_value_p == ret_expr);
      q->cont_stmt = q->stmt;
	      /* The nasty part about redirecting the return value is that the
	 return value itself is to be computed before the FINALLY block
	 is executed.  e.g.

		int x;
		int foo (void)
		{
		  x = 0;
		  try {
		    return x;
		  } finally {
		    x++;
		  }
		}

	  should return 0, not 1.  Arrange for this to happen by copying
	  computed the return value into a local temporary.  This also
	  allows us to redirect multiple return statements through the
	  same destination block; whether this is a net win or not really
	  depends, I guess, but it does make generation of the switch in
	  lower_try_finally_switch easier.  */

      if (TREE_CODE (ret_expr) == RESULT_DECL)
	{
	  if (!*return_value_p)
	    *return_value_p = ret_expr;
	  else
	    gcc_assert (*return_value_p == ret_expr);
	  q->cont_stmt = q->stmt;
	}
      else
	  gcc_unreachable ();
    }
  else
      /* If we don't return a value, all return statements are the same.  */
      q->cont_stmt = q->stmt;

  if (!q->repl_stmt)
    q->repl_stmt = gimple_seq_alloc ();

  if (mod)
    gimple_seq_add_seq (&q->repl_stmt, mod);

  x = gimple_build_goto (finlab);
  gimple_seq_add_stmt (&q->repl_stmt, x);
}

/* Similar, but easier, for GIMPLE_GOTO.  */

static void
do_goto_redirection (struct goto_queue_node *q, tree finlab, gimple_seq mod)
{
  gimple x;

  if (!q->repl_stmt)
    q->repl_stmt = gimple_seq_alloc ();
  q->cont_stmt = q->stmt;
  if (mod)
    gimple_seq_add_seq (&q->repl_stmt, mod);

  x = gimple_build_goto (finlab);
  gimple_seq_add_stmt (&q->repl_stmt, x);
}

/* We want to transform
	try { body; } catch { stuff; }
   to
	body; goto over; lab: stuff; over:

   TP is a GIMPLE_TRY node.  LAB is the label that
   should be placed before the second operand, or NULL.  OVER is
   an existing label that should be put at the exit, or NULL.  */

static gimple_seq
frob_into_branch_around (gimple tp, tree lab, tree over)
{
  gimple x;
  gimple_seq cleanup, result;

  cleanup = gimple_try_cleanup (tp);
  result = gimple_try_eval (tp);

  if (gimple_seq_may_fallthru (result))
    {
      if (!over)
	over = create_artificial_label ();
      x = gimple_build_goto (over);
      gimple_seq_add_stmt (&result, x);
    }

  if (lab)
    {
      x = gimple_build_label (lab);
      gimple_seq_add_stmt (&result, x);
    }

  gimple_seq_add_seq (&result, cleanup);

  if (over)
    {
      x = gimple_build_label (over);
      gimple_seq_add_stmt (&result, x);
    }
  return result;
}

/* A subroutine of lower_try_finally.  Duplicate the tree rooted at T.
   Make sure to record all new labels found.  */

static gimple_seq
lower_try_finally_dup_block (gimple_seq seq, struct leh_state *outer_state)
{
  gimple region = NULL;
  gimple_seq new_seq;

  new_seq = gimple_seq_deep_copy (seq);

  if (outer_state->tf)
    region = outer_state->tf->try_finally_expr;
  collect_finally_tree_1 (new_seq, region);

  return new_seq;
}

/* A subroutine of lower_try_finally.  Create a fallthru label for
   the given try_finally state.  The only tricky bit here is that
   we have to make sure to record the label in our outer context.  */

static tree
lower_try_finally_fallthru_label (struct leh_tf_state *tf)
{
  tree label = tf->fallthru_label;
  if (!label)
    {
      label = create_artificial_label ();
      tf->fallthru_label = label;
      if (tf->outer->tf)
        record_in_finally_tree ( (treemple) label,
                                 tf->outer->tf->try_finally_expr);
    }
  return label;
}

/* A subroutine of lower_try_finally.  If lang_protect_cleanup_actions
   returns non-null, then the language requires that the exception path out
   of a try_finally be treated specially.  To wit: the code within the
   finally block may not itself throw an exception.  We have two choices here.
   First we can duplicate the finally block and wrap it in a must_not_throw
   region.  Second, we can generate code like

	try {
	  finally_block;
	} catch {
	  if (fintmp == eh_edge)
	    protect_cleanup_actions;
	}

   where "fintmp" is the temporary used in the switch statement generation
   alternative considered below.  For the nonce, we always choose the first
   option.

   THIS_STATE may be null if this is a try-cleanup, not a try-finally.  */

static void
honor_protect_cleanup_actions (struct leh_state *outer_state,
			       struct leh_state *this_state,
			       struct leh_tf_state *tf)
{
  gimple protect_cleanup_actions;
  gimple_stmt_iterator gsi;
  bool finally_may_fallthru;
  gimple_seq finally;
  gimple x;

  /* First check for nothing to do.  */
  if (lang_protect_cleanup_actions)
    protect_cleanup_actions = lang_protect_cleanup_actions ();
  else
    protect_cleanup_actions = NULL;

  finally = gimple_try_cleanup (tf->top_p);

  /* If the EH case of the finally block can fall through, this may be a
     structure of the form
	try {
	  try {
	    throw ...;
	  } cleanup {
	    try {
	      throw ...;
	    } catch (...) {
	    }
	  }
	} catch (...) {
	  yyy;
	}
    E.g. with an inline destructor with an embedded try block.  In this
    case we must save the runtime EH data around the nested exception.

    This complication means that any time the previous runtime data might
    be used (via fallthru from the finally) we handle the eh case here,
    whether or not protect_cleanup_actions is active.  */

  finally_may_fallthru = gimple_seq_may_fallthru (finally);
  if (!finally_may_fallthru && !protect_cleanup_actions)
    return;

  /* Duplicate the FINALLY block.  Only need to do this for try-finally,
     and not for cleanups.  */
  if (this_state)
    finally = lower_try_finally_dup_block (finally, outer_state);

  /* If this cleanup consists of a TRY_CATCH_EXPR with TRY_CATCH_IS_CLEANUP
     set, the handler of the TRY_CATCH_EXPR is another cleanup which ought
     to be in an enclosing scope, but needs to be implemented at this level
     to avoid a nesting violation (see wrap_temporary_cleanups in
     cp/decl.c).  Since it's logically at an outer level, we should call
     terminate before we get to it, so strip it away before adding the
     MUST_NOT_THROW filter.  */
  gsi = gsi_start (finally);
  x = gsi_stmt (gsi);
  if (protect_cleanup_actions
      && gimple_code (x) == GIMPLE_TRY
      && gimple_try_kind (x) == GIMPLE_TRY_CATCH
      && gimple_try_catch_is_cleanup (x))
    {
      gsi_insert_seq_before (&gsi, gimple_try_eval (x), GSI_SAME_STMT);
      gsi_remove (&gsi, false);
    }

  /* Resume execution after the exception.  Adding this now lets
     lower_eh_filter not add unnecessary gotos, as it is clear that
     we never fallthru from this copy of the finally block.  */
  if (finally_may_fallthru)
    {
      tree save_eptr, save_filt;
      tree tmp;

      save_eptr = create_tmp_var (ptr_type_node, "save_eptr");
      save_filt = create_tmp_var (integer_type_node, "save_filt");

      gsi = gsi_start (finally);
      tmp = build0 (EXC_PTR_EXPR, ptr_type_node);
      x = gimple_build_assign (save_eptr, tmp);
      gsi_insert_before (&gsi, x, GSI_CONTINUE_LINKING);

      tmp = build0 (FILTER_EXPR, integer_type_node);
      x = gimple_build_assign (save_filt, tmp);
      gsi_insert_before (&gsi, x, GSI_CONTINUE_LINKING);

      gsi = gsi_last (finally);
      tmp = build0 (EXC_PTR_EXPR, ptr_type_node);
      x = gimple_build_assign (tmp, save_eptr);
      gsi_insert_after (&gsi, x, GSI_CONTINUE_LINKING);

      tmp = build0 (FILTER_EXPR, integer_type_node);
      x = gimple_build_assign (tmp, save_filt);
      gsi_insert_after (&gsi, x, GSI_CONTINUE_LINKING);

      x = gimple_build_resx (get_eh_region_number (tf->region));
      gsi_insert_after (&gsi, x, GSI_CONTINUE_LINKING);
    }

  /* Wrap the block with protect_cleanup_actions as the action.  */
  if (protect_cleanup_actions)
    {
      gimple_seq seq = NULL, failure = NULL;

      gimple_seq_add_stmt (&failure, protect_cleanup_actions);
      x = gimple_build_eh_filter (NULL, failure);
      gimple_eh_filter_set_must_not_throw (x, 1);

      gimple_seq_add_stmt (&seq, x);
      x = gimple_build_try (finally, seq, GIMPLE_TRY_CATCH);
      finally = lower_eh_filter (outer_state, x);
    }
  else
    lower_eh_constructs_1 (outer_state, finally);

  /* Hook this up to the end of the existing try block.  If we
     previously fell through the end, we'll have to branch around.
     This means adding a new goto, and adding it to the queue.  */

  gsi = gsi_last (gimple_try_eval (tf->top_p));

  if (tf->may_fallthru)
    {
      tree tmp;
      tmp = lower_try_finally_fallthru_label (tf);
      x = gimple_build_goto (tmp);
      gsi_insert_after (&gsi, x, GSI_CONTINUE_LINKING);

      if (this_state)
        maybe_record_in_goto_queue (this_state, x);

      tf->may_fallthru = false;
    }

  x = gimple_build_label (tf->eh_label);
  gsi_insert_after (&gsi, x, GSI_CONTINUE_LINKING);
  gsi_insert_seq_after (&gsi, finally, GSI_CONTINUE_LINKING);

  /* Having now been handled, EH isn't to be considered with
     the rest of the outgoing edges.  */
  tf->may_throw = false;
}

/* A subroutine of lower_try_finally.  We have determined that there is
   no fallthru edge out of the finally block.  This means that there is
   no outgoing edge corresponding to any incoming edge.  Restructure the
   try_finally node for this special case.  */

static void
lower_try_finally_nofallthru (struct leh_state *state,
			      struct leh_tf_state *tf)
{
  tree lab, return_val;
  gimple x;
  gimple_seq finally;
  struct goto_queue_node *q, *qe;

  if (tf->may_throw)
    lab = tf->eh_label;
  else
    lab = create_artificial_label ();

  /* We expect that tf->top_p is a GIMPLE_TRY. */
  finally = gimple_try_cleanup (tf->top_p);
  tf->top_p_seq = gimple_try_eval (tf->top_p);

  x = gimple_build_label (lab);
  gimple_seq_add_stmt (&tf->top_p_seq, x);

  return_val = NULL;
  q = tf->goto_queue;
  qe = q + tf->goto_queue_active;
  for (; q < qe; ++q)
    if (q->index < 0)
      do_return_redirection (q, lab, NULL, &return_val);
    else
      do_goto_redirection (q, lab, NULL);

  replace_goto_queue (tf);

  lower_eh_constructs_1 (state, finally);
  gimple_seq_add_seq (&tf->top_p_seq, finally);
}

/* A subroutine of lower_try_finally.  We have determined that there is
   exactly one destination of the finally block.  Restructure the
   try_finally node for this special case.  */

static void
lower_try_finally_onedest (struct leh_state *state, struct leh_tf_state *tf)
{
  struct goto_queue_node *q, *qe;
  gimple x;
  gimple_seq finally;
  tree finally_label;

  finally = gimple_try_cleanup (tf->top_p);
  tf->top_p_seq = gimple_try_eval (tf->top_p);

  lower_eh_constructs_1 (state, finally);

  if (tf->may_throw)
    {
      /* Only reachable via the exception edge.  Add the given label to
         the head of the FINALLY block.  Append a RESX at the end.  */

      x = gimple_build_label (tf->eh_label);
      gimple_seq_add_stmt (&tf->top_p_seq, x);

      gimple_seq_add_seq (&tf->top_p_seq, finally);

      x = gimple_build_resx (get_eh_region_number (tf->region));

      gimple_seq_add_stmt (&tf->top_p_seq, x);

      return;
    }

  if (tf->may_fallthru)
    {
      /* Only reachable via the fallthru edge.  Do nothing but let
	 the two blocks run together; we'll fall out the bottom.  */
      gimple_seq_add_seq (&tf->top_p_seq, finally);
      return;
    }

  finally_label = create_artificial_label ();
  x = gimple_build_label (finally_label);
  gimple_seq_add_stmt (&tf->top_p_seq, x);

  gimple_seq_add_seq (&tf->top_p_seq, finally);

  q = tf->goto_queue;
  qe = q + tf->goto_queue_active;

  if (tf->may_return)
    {
      /* Reachable by return expressions only.  Redirect them.  */
      tree return_val = NULL;
      for (; q < qe; ++q)
	do_return_redirection (q, finally_label, NULL, &return_val);
      replace_goto_queue (tf);
    }
  else
    {
      /* Reachable by goto expressions only.  Redirect them.  */
      for (; q < qe; ++q)
	do_goto_redirection (q, finally_label, NULL);
      replace_goto_queue (tf);

      if (VEC_index (tree, tf->dest_array, 0) == tf->fallthru_label)
	{
	  /* Reachable by goto to fallthru label only.  Redirect it
	     to the new label (already created, sadly), and do not
	     emit the final branch out, or the fallthru label.  */
	  tf->fallthru_label = NULL;
	  return;
	}
    }

  /* Reset the locus of the goto since we're moving
     goto to a different block which might be on a different line. */
  gimple_set_locus (tf->goto_queue[0].cont_stmt.g, 0);
  gimple_seq_add_stmt (&tf->top_p_seq, tf->goto_queue[0].cont_stmt.g);
  maybe_record_in_goto_queue (state, tf->goto_queue[0].cont_stmt.g);
}

/* A subroutine of lower_try_finally.  There are multiple edges incoming
   and outgoing from the finally block.  Implement this by duplicating the
   finally block for every destination.  */

static void
lower_try_finally_copy (struct leh_state *state, struct leh_tf_state *tf)
{
  gimple_seq finally;
  gimple_seq new_stmt;
  gimple_seq seq;
  gimple x;
  tree tmp;

  finally = gimple_try_cleanup (tf->top_p);
  tf->top_p_seq = gimple_try_eval (tf->top_p);
  new_stmt = NULL;

  if (tf->may_fallthru)
    {
      seq = lower_try_finally_dup_block (finally, state);
      lower_eh_constructs_1 (state, seq);
      gimple_seq_add_seq (&new_stmt, seq);

      tmp = lower_try_finally_fallthru_label (tf);
      x = gimple_build_goto (tmp);
      gimple_seq_add_stmt (&new_stmt, x);
    }

  if (tf->may_throw)
    {
      x = gimple_build_label (tf->eh_label);
      gimple_seq_add_stmt (&new_stmt, x);

      seq = lower_try_finally_dup_block (finally, state);
      lower_eh_constructs_1 (state, seq);
      gimple_seq_add_seq (&new_stmt, seq);

      x = gimple_build_resx (get_eh_region_number (tf->region));
      gimple_seq_add_stmt (&new_stmt, x);
    }

  if (tf->goto_queue)
    {
      struct goto_queue_node *q, *qe;
      tree return_val = NULL;
      int return_index, index;
      struct labels_s
      {
	struct goto_queue_node *q;
	tree label;
      } *labels;

      return_index = VEC_length (tree, tf->dest_array);
      labels = XCNEWVEC (struct labels_s, return_index + 1);

      q = tf->goto_queue;
      qe = q + tf->goto_queue_active;
      for (; q < qe; q++)
	{
	  index = q->index < 0 ? return_index : q->index;

	  if (!labels[index].q)
	    labels[index].q = q;
	}

      for (index = 0; index < return_index + 1; index++)
	{
	  tree lab;

	  q = labels[index].q;
	  if (! q)
	    continue;

	  lab = labels[index].label = create_artificial_label ();

	  if (index == return_index)
	    do_return_redirection (q, lab, NULL, &return_val);
	  else
	    do_goto_redirection (q, lab, NULL);

	  x = gimple_build_label (lab);
          gimple_seq_add_stmt (&new_stmt, x);

	  seq = lower_try_finally_dup_block (finally, state);
	  lower_eh_constructs_1 (state, seq);
          gimple_seq_add_seq (&new_stmt, seq);

          gimple_seq_add_stmt (&new_stmt, q->cont_stmt.g);
	  maybe_record_in_goto_queue (state, q->cont_stmt.g);
	}

      for (q = tf->goto_queue; q < qe; q++)
	{
	  tree lab;

	  index = q->index < 0 ? return_index : q->index;

	  if (labels[index].q == q)
	    continue;

	  lab = labels[index].label;

	  if (index == return_index)
	    do_return_redirection (q, lab, NULL, &return_val);
	  else
	    do_goto_redirection (q, lab, NULL);
	}
	
      replace_goto_queue (tf);
      free (labels);
    }

  /* Need to link new stmts after running replace_goto_queue due
     to not wanting to process the same goto stmts twice.  */
  gimple_seq_add_seq (&tf->top_p_seq, new_stmt);
}

/* A subroutine of lower_try_finally.  There are multiple edges incoming
   and outgoing from the finally block.  Implement this by instrumenting
   each incoming edge and creating a switch statement at the end of the
   finally block that branches to the appropriate destination.  */

static void
lower_try_finally_switch (struct leh_state *state, struct leh_tf_state *tf)
{
  struct goto_queue_node *q, *qe;
  tree return_val = NULL;
  tree finally_tmp, finally_label;
  int return_index, eh_index, fallthru_index;
  int nlabels, ndests, j, last_case_index;
  tree last_case;
  VEC (tree,heap) *case_label_vec;
  gimple_seq switch_body;
  gimple x;
  tree tmp;
  gimple switch_stmt;
  gimple_seq finally;

  switch_body = gimple_seq_alloc ();

  /* Mash the TRY block to the head of the chain.  */
  finally = gimple_try_cleanup (tf->top_p);
  tf->top_p_seq = gimple_try_eval (tf->top_p);

  /* Lower the finally block itself.  */
  lower_eh_constructs_1 (state, finally);

  /* Prepare for switch statement generation.  */
  nlabels = VEC_length (tree, tf->dest_array);
  return_index = nlabels;
  eh_index = return_index + tf->may_return;
  fallthru_index = eh_index + tf->may_throw;
  ndests = fallthru_index + tf->may_fallthru;

  finally_tmp = create_tmp_var (integer_type_node, "finally_tmp");
  finally_label = create_artificial_label ();

  case_label_vec = VEC_alloc (tree, heap, ndests);
  last_case = NULL;
  last_case_index = 0;

  /* Begin inserting code for getting to the finally block.  Things
     are done in this order to correspond to the sequence the code is
     layed out.  */

  if (tf->may_fallthru)
    {
      x = gimple_build_assign (finally_tmp, build_int_cst (integer_type_node,
					                   fallthru_index));
      gimple_seq_add_stmt (&tf->top_p_seq, x);

      if (tf->may_throw)
	{
	  x = gimple_build_goto (finally_label);
          gimple_seq_add_stmt (&tf->top_p_seq, x);
	}


      last_case = build3 (CASE_LABEL_EXPR, void_type_node,
			  build_int_cst (NULL_TREE, fallthru_index), NULL,
			  create_artificial_label ());
      VEC_replace (tree, case_label_vec, last_case_index, last_case);
      last_case_index++;

      x = gimple_build_label (CASE_LABEL (last_case));
      gimple_seq_add_stmt (&switch_body, x);

      tmp = lower_try_finally_fallthru_label (tf);
      x = gimple_build_goto (tmp);
      gimple_seq_add_stmt (&switch_body, x);
    }

  if (tf->may_throw)
    {
      x = gimple_build_label (tf->eh_label);
      gimple_seq_add_stmt (&tf->top_p_seq, x);

      x = gimple_build_assign (finally_tmp, build_int_cst (integer_type_node,
                                                           eh_index));
      gimple_seq_add_stmt (&tf->top_p_seq, x);

      last_case = build3 (CASE_LABEL_EXPR, void_type_node,
			  build_int_cst (NULL_TREE, eh_index), NULL,
			  create_artificial_label ());
      VEC_replace (tree, case_label_vec, last_case_index, last_case);
      last_case_index++;

      x = gimple_build_label (CASE_LABEL (last_case));
      gimple_seq_add_stmt (&switch_body, x);
      x = gimple_build_resx (get_eh_region_number (tf->region));
      gimple_seq_add_stmt (&switch_body, x);
    }

  x = gimple_build_label (finally_label);
  gimple_seq_add_stmt (&tf->top_p_seq, x);

  gimple_seq_add_seq (&tf->top_p_seq, finally);

  /* Redirect each incoming goto edge.  */
  q = tf->goto_queue;
  qe = q + tf->goto_queue_active;
  j = last_case_index + tf->may_return;
  /* Prepare the assignments to finally_tmp that are executed upon the
     entrance through a particular edge. */
  for (; q < qe; ++q)
    {
      gimple_seq mod;
      int switch_id, case_index;

      mod = gimple_seq_alloc ();

      if (q->index < 0)
	{
	  x = gimple_build_assign (finally_tmp,
				   build_int_cst (integer_type_node,
						  return_index));
	  gimple_seq_add_stmt (&mod, x);
	  do_return_redirection (q, finally_label, mod, &return_val);
	  switch_id = return_index;
	}
      else
	{
	  x = gimple_build_assign (finally_tmp,
				   build_int_cst (integer_type_node, q->index));
	  gimple_seq_add_stmt (&mod, x);
	  do_goto_redirection (q, finally_label, mod);
	  switch_id = q->index;
	}

      case_index = j + q->index;
      if (!VEC_index (tree, case_label_vec, case_index))
        {
	  VEC_replace (tree, case_label_vec, case_index,
	      build3 (CASE_LABEL_EXPR, void_type_node,
		      build_int_cst (NULL_TREE, switch_id), NULL,
		      /* We store the cont_stmt in the
		         CASE_LABEL, so that we can recover it
			 in the loop below.  We don't create
			 the new label while walking the
			 goto_queue because pointers don't
			 offer a stable order.  */
		      q->cont_stmt.t));
	}
    }
  for (j = last_case_index; j < last_case_index + nlabels; j++)
    {
      tree label;
      treemple cont_stmt;

      last_case = VEC_index (tree, case_label_vec, j);

      gcc_assert (last_case);

      /* As the comment above suggests, CASE_LABEL (last_case) was just a
         placeholder, it does not store an actual label, yet. */
      cont_stmt.t = CASE_LABEL (last_case);

      label = create_artificial_label ();
      CASE_LABEL (last_case) = label;

      x = gimple_build_label (label);
      gimple_seq_add_stmt (&switch_body, x);
      gimple_seq_add_stmt (&switch_body, cont_stmt.g);
      maybe_record_in_goto_queue (state, cont_stmt.g);
    }
  replace_goto_queue (tf);

  /* Make sure that the last case is the default label, as one is required.
     Then sort the labels, which is also required in GIMPLE.  */
  CASE_LOW (last_case) = NULL;
  sort_case_labels (case_label_vec);

  /* We'll set the default label at the end. */
  switch_stmt = gimple_build_switch_vec (finally_tmp, last_case,
                                         case_label_vec);

  /* Need to link SWITCH_STMT after running replace_goto_queue
     due to not wanting to process the same goto stmts twice.  */
  gimple_seq_add_stmt (&tf->top_p_seq, switch_stmt);
  gimple_seq_add_seq (&tf->top_p_seq, switch_body);
}

/* Decide whether or not we are going to duplicate the finally block.
   There are several considerations.

   First, if this is Java, then the finally block contains code
   written by the user.  It has line numbers associated with it,
   so duplicating the block means it's difficult to set a breakpoint.
   Since controlling code generation via -g is verboten, we simply
   never duplicate code without optimization.

   Second, we'd like to prevent egregious code growth.  One way to
   do this is to estimate the size of the finally block, multiply
   that by the number of copies we'd need to make, and compare against
   the estimate of the size of the switch machinery we'd have to add.  */

static bool
decide_copy_try_finally (int ndests, gimple_seq finally)
{
  int f_estimate, sw_estimate;

  if (!optimize)
    return false;

  /* Finally estimate N times, plus N gotos.  */
  f_estimate = count_insns_seq (finally, &eni_size_weights);
  f_estimate = (f_estimate + 1) * ndests;

  /* Switch statement (cost 10), N variable assignments, N gotos.  */
  sw_estimate = 10 + 2 * ndests;

  /* Optimize for size clearly wants our best guess.  */
  if (optimize_size)
    return f_estimate < sw_estimate;

  /* ??? These numbers are completely made up so far.  */
  if (optimize > 1)
    return f_estimate < 100 || f_estimate < sw_estimate * 2;
  else
    return f_estimate < 40 || f_estimate * 2 < sw_estimate * 3;
}


/* A subroutine of lower_eh_constructs_1.  Lower a GIMPLE_TRY_FINALLY nodes
   to a sequence of labels and blocks, plus the exception region trees
   that record all the magic.  This is complicated by the need to
   arrange for the FINALLY block to be executed on all exits.  */

static gimple_seq
lower_try_finally (struct leh_state *state, gimple tp)
{
  struct leh_tf_state this_tf;
  struct leh_state this_state;
  int ndests;

  /* Process the try block.  */

  memset (&this_tf, 0, sizeof (this_tf));
  this_tf.try_finally_expr = tp;
  this_tf.top_p = tp;
  this_tf.outer = state;
  if (using_eh_for_cleanups_p)
    this_tf.region
      = gen_eh_region_cleanup (state->cur_region, state->prev_try);
  else
    this_tf.region = NULL;

  this_state.cur_region = this_tf.region;
  this_state.prev_try = state->prev_try;
  this_state.tf = &this_tf;

  lower_eh_constructs_1 (&this_state, gimple_try_eval(tp));

  /* Determine if the try block is escaped through the bottom.  */
  this_tf.may_fallthru = gimple_seq_may_fallthru (gimple_try_eval (tp));

  /* Determine if any exceptions are possible within the try block.  */
  if (using_eh_for_cleanups_p)
    this_tf.may_throw = get_eh_region_may_contain_throw (this_tf.region);
  if (this_tf.may_throw)
    {
      this_tf.eh_label = create_artificial_label ();
      set_eh_region_tree_label (this_tf.region, this_tf.eh_label);
      honor_protect_cleanup_actions (state, &this_state, &this_tf);
    }

  /* Determine how many edges (still) reach the finally block.  Or rather,
     how many destinations are reached by the finally block.  Use this to
     determine how we process the finally block itself.  */

  ndests = VEC_length (tree, this_tf.dest_array);
  ndests += this_tf.may_fallthru;
  ndests += this_tf.may_return;
  ndests += this_tf.may_throw;

  /* If the FINALLY block is not reachable, dike it out.  */
  if (ndests == 0)
      gimple_try_set_cleanup (tp, NULL);
  /* If the finally block doesn't fall through, then any destination
     we might try to impose there isn't reached either.  There may be
     some minor amount of cleanup and redirection still needed.  */
  else if (!gimple_seq_may_fallthru (gimple_try_cleanup (tp)))
    lower_try_finally_nofallthru (state, &this_tf);

  /* We can easily special-case redirection to a single destination.  */
  else if (ndests == 1)
    lower_try_finally_onedest (state, &this_tf);

  else if (decide_copy_try_finally (ndests, gimple_try_cleanup (tp)))
    lower_try_finally_copy (state, &this_tf);
  else
    lower_try_finally_switch (state, &this_tf);

  /* If someone requested we add a label at the end of the transformed
     block, do so.  */
  if (this_tf.fallthru_label)
    {
      /* This must be reached only if ndests == 0. */
      gimple x = gimple_build_label (this_tf.fallthru_label);
      gimple_seq_add_stmt (&this_tf.top_p_seq, x);
    }

  VEC_free (tree, heap, this_tf.dest_array);
  if (this_tf.goto_queue)
    free (this_tf.goto_queue);
  if (this_tf.goto_queue_map)
    pointer_map_destroy (this_tf.goto_queue_map);

  return this_tf.top_p_seq;
}

/* A subroutine of lower_eh_constructs_1.  Lower a GIMPLE_TRY_CATCH with a
   list of GIMPLE_CATCH to a sequence of labels and blocks, plus the
   exception region trees that records all the magic.  */

static gimple_seq
lower_catch (struct leh_state *state, gimple tp)
{
  struct eh_region *try_region;
  struct leh_state this_state;
  gimple_stmt_iterator gsi;
  tree out_label;

  try_region = gen_eh_region_try (state->cur_region);
  this_state.cur_region = try_region;
  this_state.prev_try = try_region;
  this_state.tf = state->tf;

  lower_eh_constructs_1 (&this_state, gimple_try_eval (tp));

  if (!get_eh_region_may_contain_throw (try_region))
    {
      return gimple_try_eval (tp);
    }

  out_label = NULL;
  for (gsi = gsi_start (gimple_catch_handler (tp)); !gsi_end_p (gsi); )
    {
      struct eh_region *catch_region;
      tree eh_label;
      gimple x, catch;

      catch = gsi_stmt (gsi);
      catch_region = gen_eh_region_catch (try_region,
                                          gimple_catch_types (catch));

      this_state.cur_region = catch_region;
      this_state.prev_try = state->prev_try;
      lower_eh_constructs_1 (&this_state, gimple_catch_handler (catch));

      eh_label = create_artificial_label ();
      set_eh_region_tree_label (catch_region, eh_label);

      x = gimple_build_label (eh_label);
      gsi_insert_before (&gsi, x, GSI_SAME_STMT);

      if (gimple_seq_may_fallthru (gimple_catch_handler (catch)))
	{
	  if (!out_label)
	    out_label = create_artificial_label ();

	  x = gimple_build_label (out_label);
	  gimple_seq_add_stmt (gimple_catch_handler_ptr (catch), x);
	}

      gsi_insert_seq_before (&gsi, gimple_catch_handler (catch),
			     GSI_SAME_STMT);
      gsi_remove (&gsi, false);
    }

  return frob_into_branch_around (tp, NULL, out_label);
}

/* A subroutine of lower_eh_constructs_1.  Lower a GIMPLE_TRY with a
   GIMPLE_EH_FILTER to a sequence of labels and blocks, plus the exception
   region trees that record all the magic.  */

static gimple_seq
lower_eh_filter (struct leh_state *state, gimple tp)
{
  struct leh_state this_state;
  struct eh_region *this_region;
  gimple inner;
  tree eh_label;

  inner = gimple_seq_first_stmt (gimple_try_cleanup (tp));

  if (gimple_eh_filter_must_not_throw (inner))
    this_region = gen_eh_region_must_not_throw (state->cur_region);
  else
    this_region = gen_eh_region_allowed (state->cur_region,
					 gimple_eh_filter_types (inner));
  this_state = *state;
  this_state.cur_region = this_region;
  /* For must not throw regions any cleanup regions inside it
     can't reach outer catch regions.  */
  if (gimple_eh_filter_must_not_throw (inner))
    this_state.prev_try = NULL;

  lower_eh_constructs_1 (&this_state, gimple_try_eval (tp));

  if (!get_eh_region_may_contain_throw (this_region))
    {
      return gimple_try_eval (tp);
    }

  lower_eh_constructs_1 (state, gimple_eh_filter_failure (inner));
  gimple_try_set_cleanup (tp, gimple_eh_filter_failure (inner));

  eh_label = create_artificial_label ();
  set_eh_region_tree_label (this_region, eh_label);

  return frob_into_branch_around (tp, eh_label, NULL);
}

/* Implement a cleanup expression.  This is similar to try-finally,
   except that we only execute the cleanup block for exception edges.  */

static gimple_seq
lower_cleanup (struct leh_state *state, gimple tp)
{
  struct leh_state this_state;
  struct eh_region *this_region;
  struct leh_tf_state fake_tf;
  gimple_seq result;

  /* If not using eh, then exception-only cleanups are no-ops.  */
  if (!flag_exceptions)
    {
      result = gimple_try_eval (tp);
      lower_eh_constructs_1 (state, result);
      return result;
    }

  this_region = gen_eh_region_cleanup (state->cur_region, state->prev_try);
  this_state = *state;
  this_state.cur_region = this_region;

  lower_eh_constructs_1 (&this_state, gimple_try_cleanup (tp));

  if (!get_eh_region_may_contain_throw (this_region))
    {
      return gimple_try_eval (tp);
    }

  /* Build enough of a try-finally state so that we can reuse
     honor_protect_cleanup_actions.  */
  memset (&fake_tf, 0, sizeof (fake_tf));
  fake_tf.top_p = tp;
  fake_tf.outer = state;
  fake_tf.region = this_region;
  fake_tf.may_fallthru = gimple_seq_may_fallthru (gimple_try_eval (tp));
  fake_tf.may_throw = true;

  fake_tf.eh_label = create_artificial_label ();
  set_eh_region_tree_label (this_region, fake_tf.eh_label);

  honor_protect_cleanup_actions (state, NULL, &fake_tf);

  if (fake_tf.may_throw)
    {
      /* In this case honor_protect_cleanup_actions had nothing to do,
	 and we should process this normally.  */
      lower_eh_constructs_1 (state, gimple_try_cleanup (tp));
      result = frob_into_branch_around (tp, fake_tf.eh_label,
                                       fake_tf.fallthru_label);
    }
  else
    {
      /* In this case honor_protect_cleanup_actions did nearly all of
	 the work.  All we have left is to append the fallthru_label.  */

      result = gimple_try_eval (tp);
      if (fake_tf.fallthru_label)
	{
	  gimple x = gimple_build_label (fake_tf.fallthru_label);
	  gimple_seq_add_stmt (&result, x);
	}
    }
  return result;
}



/* Main loop for lowering eh constructs. Also moves gsi to the next 
   statement. */

static void
lower_eh_constructs_2 (struct leh_state *state, gimple_stmt_iterator *gsi)
{
  gimple_seq replace;
  gimple x;
  gimple stmt = gsi_stmt (*gsi);

  switch (gimple_code (stmt))
    {
    case GIMPLE_CALL:
    case GIMPLE_ASSIGN:
      /* Look for things that can throw exceptions, and record them.  */
      if (state->cur_region && stmt_could_throw_p (stmt))
	{
	  record_stmt_eh_region (state->cur_region, stmt);
	  note_eh_region_may_contain_throw (state->cur_region);
	}
      break;

    case GIMPLE_GOTO:
    case GIMPLE_RETURN:
      maybe_record_in_goto_queue (state, stmt);
      break;

    case GIMPLE_SWITCH:
      verify_norecord_switch_expr (state, stmt);
      break;

    case GIMPLE_TRY:
      if (gimple_try_kind (stmt) == GIMPLE_TRY_FINALLY)
	replace = lower_try_finally (state, stmt);
      else
	{
	  x = gimple_seq_first_stmt (gimple_try_cleanup (stmt));
	  switch (gimple_code (x))
	    {
	    case CATCH_EXPR:
	      replace = lower_catch (state, stmt);
	      break;
	    case EH_FILTER_EXPR:
	      replace = lower_eh_filter (state, stmt);
	      break;
	    default:
	      replace = lower_cleanup (state, stmt);
	      break;
	    }
	}

      /* Remove the old stmt and insert the transformed sequence
	 instead. */
      gsi_insert_seq_before (gsi, replace, GSI_SAME_STMT);
      gsi_remove (gsi, true);

      /* Return since we don't want gsi_next () */
      return;

    default:
      /* A type, a decl, or some kind of statement that we're not
	 interested in.  Don't walk them.  */
      break;
    }

  gsi_next (gsi);
}

/* A helper to unwrap a gimple_seq and feed stmts to lower_eh_constructs_2. */

static void
lower_eh_constructs_1 (struct leh_state *state, gimple_seq seq)
{
  gimple_stmt_iterator gsi;
  for (gsi = gsi_start (seq); !gsi_end_p (gsi);)
    lower_eh_constructs_2 (state, &gsi);
}

static unsigned int
lower_eh_constructs (void)
{
  struct leh_state null_state;

  gimple_seq bodyp = gimple_body (current_function_decl);

  finally_tree = htab_create (31, struct_ptr_hash, struct_ptr_eq, free);

  collect_finally_tree_1 (bodyp, NULL);

  memset (&null_state, 0, sizeof (null_state));
  lower_eh_constructs_1 (&null_state, bodyp);

  htab_delete (finally_tree);

  collect_eh_region_array ();
  return 0;
}

struct tree_opt_pass pass_lower_eh =
{
  "eh",					/* name */
  NULL,					/* gate */
  lower_eh_constructs,			/* execute */
  NULL,					/* sub */
  NULL,					/* next */
  0,					/* static_pass_number */
  TV_TREE_EH,				/* tv_id */
  PROP_gimple_lcf,			/* properties_required */
  PROP_gimple_leh,			/* properties_provided */
  0,					/* properties_destroyed */
  0,					/* todo_flags_start */
  TODO_dump_func,			/* todo_flags_finish */
  0					/* letter */
};


/* Construct EH edges for STMT.  */

static void
make_eh_edge (struct eh_region *region, void *data)
{
  gimple stmt;
  tree lab;
  basic_block src, dst;

  stmt = (gimple) data;
  lab = get_eh_region_tree_label (region);

  src = gimple_bb (stmt);
  dst = label_to_block (lab);

  make_edge (src, dst, EDGE_ABNORMAL | EDGE_EH);
}

void
make_eh_edges (gimple stmt)
{
  int region_nr;
  bool is_resx;

  if (gimple_code (stmt) == GIMPLE_RESX)
    {
      region_nr = gimple_resx_region (stmt);
      is_resx = true;
    }
  else
    {
      region_nr = lookup_stmt_eh_region (stmt);
      if (region_nr < 0)
	return;
      is_resx = false;
    }

  foreach_reachable_handler (region_nr, is_resx, make_eh_edge, stmt);
}

/* FIXME tuples.  */
#if 0
static bool mark_eh_edge_found_error;

/* Mark edge make_eh_edge would create for given region by setting it aux
   field, output error if something goes wrong.  */
static void
mark_eh_edge (struct eh_region *region, void *data)
{
  tree stmt, lab;
  basic_block src, dst;
  edge e;

  stmt = (tree) data;
  lab = get_eh_region_tree_label (region);

  src = gimple_bb (stmt);
  dst = label_to_block (lab);

  e = find_edge (src, dst);
  if (!e)
    {
      error ("EH edge %i->%i is missing", src->index, dst->index);
      mark_eh_edge_found_error = true;
    }
  else if (!(e->flags & EDGE_EH))
    {
      error ("EH edge %i->%i miss EH flag", src->index, dst->index);
      mark_eh_edge_found_error = true;
    }
  else if (e->aux)
    {
      /* ??? might not be mistake.  */
      error ("EH edge %i->%i has duplicated regions", src->index, dst->index);
      mark_eh_edge_found_error = true;
    }
  else
    e->aux = (void *)1;
}

/* Verify that BB containing stmt as last stmt has precisely the edges
   make_eh_edges would create.  */
bool
verify_eh_edges (tree stmt)
{
  int region_nr;
  bool is_resx;
  basic_block bb = gimple_bb (stmt);
  edge_iterator ei;
  edge e;

  FOR_EACH_EDGE (e, ei, bb->succs)
    gcc_assert (!e->aux);
  mark_eh_edge_found_error = false;
  if (TREE_CODE (stmt) == RESX_EXPR)
    {
      region_nr = TREE_INT_CST_LOW (TREE_OPERAND (stmt, 0));
      is_resx = true;
    }
  else
    {
      region_nr = lookup_stmt_eh_region (stmt);
      if (region_nr < 0)
	{
	  FOR_EACH_EDGE (e, ei, bb->succs)
	    if (e->flags & EDGE_EH)
	      {
		error ("BB %i can not throw but has EH edges", bb->index);
		return true;
	      }
	   return false;
	}
      if (!tree_could_throw_p (stmt))
	{
	  error ("BB %i last statement has incorrectly set region", bb->index);
	  return true;
	}
      is_resx = false;
    }

  foreach_reachable_handler (region_nr, is_resx, mark_eh_edge, stmt);
  FOR_EACH_EDGE (e, ei, bb->succs)
    {
      if ((e->flags & EDGE_EH) && !e->aux)
	{
	  error ("unnecessary EH edge %i->%i", bb->index, e->dest->index);
	  mark_eh_edge_found_error = true;
	  return true;
	}
      e->aux = NULL;
    }

  return mark_eh_edge_found_error;
}
#endif


/* Return true if EXPR can trap, as in dereferencing an invalid pointer
   location or floating point arithmetic.  C.f. the rtl version, may_trap_p.
   This routine expects only GIMPLE lhs or rhs input.  */

bool
tree_could_trap_p (tree expr)
{
  enum tree_code code = TREE_CODE (expr);
  bool honor_nans = false;
  bool honor_snans = false;
  bool fp_operation = false;
  bool honor_trapv = false;
  tree t, base;

  if (TREE_CODE_CLASS (code) == tcc_comparison
      || TREE_CODE_CLASS (code) == tcc_unary
      || TREE_CODE_CLASS (code) == tcc_binary)
    {
      t = TREE_TYPE (expr);
      fp_operation = FLOAT_TYPE_P (t);
      if (fp_operation)
	{
	  honor_nans = flag_trapping_math && !flag_finite_math_only;
	  honor_snans = flag_signaling_nans != 0;
	}
      else if (INTEGRAL_TYPE_P (t) && TYPE_OVERFLOW_TRAPS (t))
	honor_trapv = true;
    }

 restart:
  switch (code)
    {
    case TARGET_MEM_REF:
      /* For TARGET_MEM_REFs use the information based on the original
	 reference.  */
      expr = TMR_ORIGINAL (expr);
      code = TREE_CODE (expr);
      goto restart;

    case COMPONENT_REF:
    case REALPART_EXPR:
    case IMAGPART_EXPR:
    case BIT_FIELD_REF:
    case VIEW_CONVERT_EXPR:
    case WITH_SIZE_EXPR:
      expr = TREE_OPERAND (expr, 0);
      code = TREE_CODE (expr);
      goto restart;

    case ARRAY_RANGE_REF:
      base = TREE_OPERAND (expr, 0);
      if (tree_could_trap_p (base))
	return true;

      if (TREE_THIS_NOTRAP (expr))
	return false;

      return !range_in_array_bounds_p (expr);

    case ARRAY_REF:
      base = TREE_OPERAND (expr, 0);
      if (tree_could_trap_p (base))
	return true;

      if (TREE_THIS_NOTRAP (expr))
	return false;

      return !in_array_bounds_p (expr);

    case INDIRECT_REF:
    case ALIGN_INDIRECT_REF:
    case MISALIGNED_INDIRECT_REF:
      return !TREE_THIS_NOTRAP (expr);

    case ASM_EXPR:
      return TREE_THIS_VOLATILE (expr);

    case TRUNC_DIV_EXPR:
    case CEIL_DIV_EXPR:
    case FLOOR_DIV_EXPR:
    case ROUND_DIV_EXPR:
    case EXACT_DIV_EXPR:
    case CEIL_MOD_EXPR:
    case FLOOR_MOD_EXPR:
    case ROUND_MOD_EXPR:
    case TRUNC_MOD_EXPR:
    case RDIV_EXPR:
      if (honor_snans || honor_trapv)
	return true;
      if (fp_operation)
	return flag_trapping_math;
      t = TREE_OPERAND (expr, 1);
      if (!TREE_CONSTANT (t) || integer_zerop (t))
        return true;
      return false;

    case LT_EXPR:
    case LE_EXPR:
    case GT_EXPR:
    case GE_EXPR:
    case LTGT_EXPR:
      /* Some floating point comparisons may trap.  */
      return honor_nans;

    case EQ_EXPR:
    case NE_EXPR:
    case UNORDERED_EXPR:
    case ORDERED_EXPR:
    case UNLT_EXPR:
    case UNLE_EXPR:
    case UNGT_EXPR:
    case UNGE_EXPR:
    case UNEQ_EXPR:
      return honor_snans;

    case CONVERT_EXPR:
    case FIX_TRUNC_EXPR:
      /* Conversion of floating point might trap.  */
      return honor_nans;

    case NEGATE_EXPR:
    case ABS_EXPR:
    case CONJ_EXPR:
      /* These operations don't trap with floating point.  */
      if (honor_trapv)
	return true;
      return false;

    case PLUS_EXPR:
    case MINUS_EXPR:
    case MULT_EXPR:
      /* Any floating arithmetic may trap.  */
      if (fp_operation && flag_trapping_math)
	return true;
      if (honor_trapv)
	return true;
      return false;

    case CALL_EXPR:
      t = get_callee_fndecl (expr);
      /* Assume that calls to weak functions may trap.  */
      if (!t || !DECL_P (t) || DECL_WEAK (t))
	return true;
      return false;

    default:
      /* Any floating arithmetic may trap.  */
      if (fp_operation && flag_trapping_math)
	return true;
      return false;
    }
}


/* Helper for stmt_could_throw_p.  Return true if STMT (assumed to be a
   an assignment or a conditional) may throw.  FIXME tuples, this is
   very similar to tree_could_trap_p but only works with GIMPLE
   operands.  Try to factor out common code.  */

static bool
stmt_could_throw_1_p (gimple stmt)
{
  enum tree_code code = gimple_subcode (stmt);
  bool honor_nans = false;
  bool honor_snans = false;
  bool fp_operation = false;
  bool honor_trapv = false;
  tree t;
  size_t i;

  if (TREE_CODE_CLASS (code) == tcc_comparison
      || TREE_CODE_CLASS (code) == tcc_unary
      || TREE_CODE_CLASS (code) == tcc_binary)
    {
      t = gimple_expr_type (stmt);
      fp_operation = FLOAT_TYPE_P (t);
      if (fp_operation)
	{
	  honor_nans = flag_trapping_math && !flag_finite_math_only;
	  honor_snans = flag_signaling_nans != 0;
	}
      else if (INTEGRAL_TYPE_P (t) && TYPE_OVERFLOW_TRAPS (t))
	honor_trapv = true;
    }

  /* Check if the main expression may trap.  */
  switch (code)
    {
    case TRUNC_DIV_EXPR:
    case CEIL_DIV_EXPR:
    case FLOOR_DIV_EXPR:
    case ROUND_DIV_EXPR:
    case EXACT_DIV_EXPR:
    case CEIL_MOD_EXPR:
    case FLOOR_MOD_EXPR:
    case ROUND_MOD_EXPR:
    case TRUNC_MOD_EXPR:
    case RDIV_EXPR:
      if (honor_snans || honor_trapv)
	return true;
      if (fp_operation)
	return flag_trapping_math;
      t = gimple_assign_rhs2 (stmt);
      if (!TREE_CONSTANT (t) || integer_zerop (t))
	return true;
      return false;

    case LT_EXPR:
    case LE_EXPR:
    case GT_EXPR:
    case GE_EXPR:
    case LTGT_EXPR:
      /* Some floating point comparisons may trap.  */
      return honor_nans;

    case EQ_EXPR:
    case NE_EXPR:
    case UNORDERED_EXPR:
    case ORDERED_EXPR:
    case UNLT_EXPR:
    case UNLE_EXPR:
    case UNGT_EXPR:
    case UNGE_EXPR:
    case UNEQ_EXPR:
      return honor_snans;

    case CONVERT_EXPR:
    case FIX_TRUNC_EXPR:
      /* Conversion of floating point might trap.  */
      return honor_nans;

    case NEGATE_EXPR:
    case ABS_EXPR:
    case CONJ_EXPR:
      /* These operations don't trap with floating point.  */
      if (honor_trapv)
	return true;
      return false;

    case PLUS_EXPR:
    case MINUS_EXPR:
    case MULT_EXPR:
      /* Any floating arithmetic may trap.  */
      if (fp_operation && flag_trapping_math)
	return true;
      if (honor_trapv)
	return true;
      return false;

    default:
      /* Any floating arithmetic may trap.  */
      if (fp_operation && flag_trapping_math)
	return true;
    }

  /* If the expression does not trap, see if any of the individual operands may
     trap.  */
  for (i = 0; i < gimple_num_ops (stmt); i++)
    if (tree_could_trap_p (gimple_op (stmt, i)))
      return true;

  return false;
}


/* Return true if statement STMT could throw an exception.  */

bool
stmt_could_throw_p (gimple stmt)
{
  enum gimple_code code;

  if (!flag_exceptions)
    return false;

  /* The only statements that can throw an exception are assignments,
     conditionals, calls and asms.  */
  code = gimple_code (stmt);
  if (code != GIMPLE_ASSIGN
      && code != GIMPLE_COND
      && code != GIMPLE_CALL
      && code != GIMPLE_ASM)
    return false;

  /* If exceptions can only be thrown by function calls and STMT is not a
     GIMPLE_CALL, the statement cannot throw.  */
  if (!flag_non_call_exceptions && code != GIMPLE_CALL)
    return false;

  if (code == GIMPLE_ASSIGN || code == GIMPLE_COND)
    return stmt_could_throw_1_p (stmt);
  else if (gimple_code (stmt) == GIMPLE_CALL)
    {
      tree t = gimple_call_fndecl (stmt);

      /* Assume that calls to weak functions may trap.  */
      if (!t || !DECL_P (t) || DECL_WEAK (t))
	return true;

      return (gimple_call_flags (stmt) & ECF_NOTHROW) == 0;
    }
  else if (gimple_code (stmt) == GIMPLE_ASM)
    return (gimple_asm_volatile_p (stmt));
  else
    gcc_unreachable ();

  return false;
}


/* Return true if expression T could throw an exception.  */

bool
tree_could_throw_p (tree t)
{
  if (!flag_exceptions)
    return false;
  if (TREE_CODE (t) == GIMPLE_MODIFY_STMT)
    {
      if (flag_non_call_exceptions
	  && tree_could_trap_p (GIMPLE_STMT_OPERAND (t, 0)))
	return true;
      t = GIMPLE_STMT_OPERAND (t, 1);
    }

  if (TREE_CODE (t) == WITH_SIZE_EXPR)
    t = TREE_OPERAND (t, 0);
  if (TREE_CODE (t) == CALL_EXPR)
    return (call_expr_flags (t) & ECF_NOTHROW) == 0;
  if (flag_non_call_exceptions)
    return tree_could_trap_p (t);
  return false;
}


/* Return true if STMT can throw an exception that is caught within
   the current function (CFUN).  */

bool
stmt_can_throw_internal (gimple stmt)
{
  int region_nr;
  bool is_resx = false;

  if (gimple_code (stmt) == GIMPLE_RESX)
    {
      region_nr = gimple_resx_region (stmt);
      is_resx = true;
    }
  else
    region_nr = lookup_stmt_eh_region (stmt);

  if (region_nr < 0)
    return false;

  return can_throw_internal_1 (region_nr, is_resx);
}


/* Return true if STMT can throw an exception that is visible outside
   the current function (CFUN).  */

bool
tree_can_throw_external (tree stmt ATTRIBUTE_UNUSED)
{
  /* FIXME tuples.  */
#if 0
  int region_nr;
  bool is_resx = false;

  if (TREE_CODE (stmt) == RESX_EXPR)
    region_nr = TREE_INT_CST_LOW (TREE_OPERAND (stmt, 0)), is_resx = true;
  else
    region_nr = lookup_stmt_eh_region (stmt);
  if (region_nr < 0)
    return tree_could_throw_p (stmt);
  else
    return can_throw_external_1 (region_nr, is_resx);
#else
  gimple_unreachable ();
  return false;
#endif
}


/* Given a statement OLD_STMT and a new statement NEW_STMT that has replaced
   OLD_STMT in the function, remove OLD_STMT from the EH table and put NEW_STMT
   in the table if it should be in there.  Return TRUE if a replacement was
   done that my require an EH edge purge.  */

bool 
maybe_clean_or_replace_eh_stmt (gimple old_stmt, gimple new_stmt) 
{
  int region_nr = lookup_stmt_eh_region (old_stmt);

  if (region_nr >= 0)
    {
      bool new_stmt_could_throw = stmt_could_throw_p (new_stmt);

      if (new_stmt == old_stmt && new_stmt_could_throw)
	return false;

      remove_stmt_from_eh_region (old_stmt);
      if (new_stmt_could_throw)
	{
	  add_stmt_to_eh_region (new_stmt, region_nr);
	  return false;
	}
      else
	return true;
    }

  return false;
}

/* Returns TRUE if oneh and twoh are exception handlers (op 1 of
   TRY_CATCH_EXPR or TRY_FINALLY_EXPR that are similar enough to be
   considered the same.  Currently this only handles handlers consisting of
   a single call, as that's the important case for C++: a destructor call
   for a particular object showing up in multiple handlers.  */

static bool
same_handler_p (tree oneh, tree twoh)
{
  tree_stmt_iterator i;
  tree ones, twos;
  int ai;

  i = tsi_start (oneh);
  if (!tsi_one_before_end_p (i))
    return false;
  ones = tsi_stmt (i);

  i = tsi_start (twoh);
  if (!tsi_one_before_end_p (i))
    return false;
  twos = tsi_stmt (i);

  if (TREE_CODE (ones) != CALL_EXPR
      || TREE_CODE (twos) != CALL_EXPR
      || !operand_equal_p (CALL_EXPR_FN (ones), CALL_EXPR_FN (twos), 0)
      || call_expr_nargs (ones) != call_expr_nargs (twos))
    return false;

  for (ai = 0; ai < call_expr_nargs (ones); ++ai)
    if (!operand_equal_p (CALL_EXPR_ARG (ones, ai),
			  CALL_EXPR_ARG (twos, ai), 0))
      return false;

  return true;
}

/* Optimize
    try { A() } finally { try { ~B() } catch { ~A() } }
    try { ... } finally { ~A() }
   into
    try { A() } catch { ~B() }
    try { ~B() ... } finally { ~A() }

   This occurs frequently in C++, where A is a local variable and B is a
   temporary used in the initializer for A.  */

static void
optimize_double_finally (tree one, tree two)
{
  tree oneh;
  tree_stmt_iterator i;

  i = tsi_start (TREE_OPERAND (one, 1));
  if (!tsi_one_before_end_p (i))
    return;

  oneh = tsi_stmt (i);
  if (TREE_CODE (oneh) != TRY_CATCH_EXPR)
    return;

  if (same_handler_p (TREE_OPERAND (oneh, 1), TREE_OPERAND (two, 1)))
    {
      tree b = TREE_OPERAND (oneh, 0);
      TREE_OPERAND (one, 1) = b;
      TREE_SET_CODE (one, TRY_CATCH_EXPR);

      i = tsi_start (TREE_OPERAND (two, 0));
      /* FIXME tuples.  */
#if 0
      tsi_link_before (&i, unsave_expr_now (b), TSI_SAME_STMT);
#else
      gimple_unreachable ();
#endif
    }
}

/* Perform EH refactoring optimizations that are simpler to do when code
   flow has been lowered but EH structures haven't.  */

static void
refactor_eh_r (tree t)
{
 tailrecurse:
  switch (TREE_CODE (t))
    {
    case TRY_FINALLY_EXPR:
    case TRY_CATCH_EXPR:
      refactor_eh_r (TREE_OPERAND (t, 0));
      t = TREE_OPERAND (t, 1);
      goto tailrecurse;

    case CATCH_EXPR:
      t = CATCH_BODY (t);
      goto tailrecurse;

    case EH_FILTER_EXPR:
      t = EH_FILTER_FAILURE (t);
      goto tailrecurse;

    case STATEMENT_LIST:
      {
	tree_stmt_iterator i;
	tree one = NULL_TREE, two = NULL_TREE;
	/* Try to refactor double try/finally.  */
	for (i = tsi_start (t); !tsi_end_p (i); tsi_next (&i))
	  {
	    one = two;
	    two = tsi_stmt (i);
	    if (one && two
		&& TREE_CODE (one) == TRY_FINALLY_EXPR
		&& TREE_CODE (two) == TRY_FINALLY_EXPR)
	      optimize_double_finally (one, two);
	    if (one)
	      refactor_eh_r (one);
	  }
	if (two)
	  {
	    t = two;
	    goto tailrecurse;
	  }
      }
      break;

    default:
      /* A type, a decl, or some kind of statement that we're not
	 interested in.  Don't walk them.  */
      break;
    }
}

static unsigned
refactor_eh (void)
{
  /* FIXME tuples.  DECL_SAVED_TREE needs to be changed to gimple_body.  */
  refactor_eh_r (DECL_SAVED_TREE (current_function_decl));
  return 0;
}

struct tree_opt_pass pass_refactor_eh =
{
  "ehopt",				/* name */
  NULL,					/* gate */
  refactor_eh,				/* execute */
  NULL,					/* sub */
  NULL,					/* next */
  0,					/* static_pass_number */
  TV_TREE_EH,				/* tv_id */
  PROP_gimple_lcf,			/* properties_required */
  0,					/* properties_provided */
  0,					/* properties_destroyed */
  0,					/* todo_flags_start */
  TODO_dump_func,			/* todo_flags_finish */
  0					/* letter */
};
