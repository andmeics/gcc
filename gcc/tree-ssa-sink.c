/* Code sinking for trees
   Copyright (C) 2001, 2002, 2003, 2004, 2007, 2008, 2009, 2010
   Free Software Foundation, Inc.
   Contributed by Daniel Berlin <dan@dberlin.org>

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
#include "basic-block.h"
#include "gimple-pretty-print.h"
#include "tree-inline.h"
#include "tree-flow.h"
#include "gimple.h"
#include "tree-dump.h"
#include "timevar.h"
#include "fibheap.h"
#include "hashtab.h"
#include "tree-iterator.h"
#include "alloc-pool.h"
#include "tree-pass.h"
#include "flags.h"
#include "bitmap.h"
#include "langhooks.h"
#include "cfgloop.h"

/* TODO:
   1. Sinking store only using scalar promotion (IE without moving the RHS):

   *q = p;
   p = p + 1;
   if (something)
     *q = <not p>;
   else
     y = *q;


   should become
   sinktemp = p;
   p = p + 1;
   if (something)
     *q = <not p>;
   else
   {
     *q = sinktemp;
     y = *q
   }
   Store copy propagation will take care of the store elimination above.


   2. Sinking using Partial Dead Code Elimination.  */


static struct
{
  /* The number of statements sunk down the flowgraph by code sinking.  */
  int sunk;

} sink_stats;


/* Given a PHI, and one of its arguments (DEF), find the edge for
   that argument and return it.  If the argument occurs twice in the PHI node,
   we return NULL.  */

static basic_block
find_bb_for_arg (gimple phi, tree def)
{
  size_t i;
  bool foundone = false;
  basic_block result = NULL;
  for (i = 0; i < gimple_phi_num_args (phi); i++)
    if (PHI_ARG_DEF (phi, i) == def)
      {
	if (foundone)
	  return NULL;
	foundone = true;
	result = gimple_phi_arg_edge (phi, i)->src;
      }
  return result;
}

/* When the first immediate use is in a statement, then return true if all
   immediate uses in IMM are in the same statement.
   We could also do the case where  the first immediate use is in a phi node,
   and all the other uses are in phis in the same basic block, but this
   requires some expensive checking later (you have to make sure no def/vdef
   in the statement occurs for multiple edges in the various phi nodes it's
   used in, so that you only have one place you can sink it to.  */

static bool
all_immediate_uses_same_place (gimple stmt)
{
  gimple firstuse = NULL;
  ssa_op_iter op_iter;
  imm_use_iterator imm_iter;
  use_operand_p use_p;
  tree var;

  FOR_EACH_SSA_TREE_OPERAND (var, stmt, op_iter, SSA_OP_ALL_DEFS)
    {
      FOR_EACH_IMM_USE_FAST (use_p, imm_iter, var)
        {
	  if (is_gimple_debug (USE_STMT (use_p)))
	    continue;
	  if (firstuse == NULL)
	    firstuse = USE_STMT (use_p);
	  else
	    if (firstuse != USE_STMT (use_p))
	      return false;
	}
    }

  return true;
}

/* Some global stores don't necessarily have VDEF's of global variables,
   but we still must avoid moving them around.  */

bool
is_hidden_global_store (gimple stmt)
{
  /* Check virtual definitions.  If we get here, the only virtual
     definitions we should see are those generated by assignment or call
     statements.  */
  if (gimple_vdef (stmt))
    {
      tree lhs;

      gcc_assert (is_gimple_assign (stmt) || is_gimple_call (stmt));

      /* Note that we must not check the individual virtual operands
	 here.  In particular, if this is an aliased store, we could
	 end up with something like the following (SSA notation
	 redacted for brevity):

	 	foo (int *p, int i)
		{
		  int x;
		  p_1 = (i_2 > 3) ? &x : p;

		  # x_4 = VDEF <x_3>
		  *p_1 = 5;

		  return 2;
		}

	 Notice that the store to '*p_1' should be preserved, if we
	 were to check the virtual definitions in that store, we would
	 not mark it needed.  This is because 'x' is not a global
	 variable.

	 Therefore, we check the base address of the LHS.  If the
	 address is a pointer, we check if its name tag or symbol tag is
	 a global variable.  Otherwise, we check if the base variable
	 is a global.  */
      lhs = gimple_get_lhs (stmt);

      if (REFERENCE_CLASS_P (lhs))
	lhs = get_base_address (lhs);

      if (lhs == NULL_TREE)
	{
	  /* If LHS is NULL, it means that we couldn't get the base
	     address of the reference.  In which case, we should not
	     move this store.  */
	  return true;
	}
      else if (DECL_P (lhs))
	{
	  /* If the store is to a global symbol, we need to keep it.  */
	  if (is_global_var (lhs))
	    return true;

	}
      else if (INDIRECT_REF_P (lhs)
	       || TREE_CODE (lhs) == MEM_REF
	       || TREE_CODE (lhs) == TARGET_MEM_REF)
	return ptr_deref_may_alias_global_p (TREE_OPERAND (lhs, 0));
      else if (CONSTANT_CLASS_P (lhs))
	return true;
      else
	gcc_unreachable ();
    }

  return false;
}

/* Find the nearest common dominator of all of the immediate uses in IMM.  */

static basic_block
nearest_common_dominator_of_uses (gimple stmt, bool *debug_stmts)
{
  bitmap blocks = BITMAP_ALLOC (NULL);
  basic_block commondom;
  unsigned int j;
  bitmap_iterator bi;
  ssa_op_iter op_iter;
  imm_use_iterator imm_iter;
  use_operand_p use_p;
  tree var;

  bitmap_clear (blocks);
  FOR_EACH_SSA_TREE_OPERAND (var, stmt, op_iter, SSA_OP_ALL_DEFS)
    {
      FOR_EACH_IMM_USE_FAST (use_p, imm_iter, var)
        {
	  gimple usestmt = USE_STMT (use_p);
	  basic_block useblock;

	  if (gimple_code (usestmt) == GIMPLE_PHI)
	    {
	      int idx = PHI_ARG_INDEX_FROM_USE (use_p);

	      useblock = gimple_phi_arg_edge (usestmt, idx)->src;
	    }
	  else if (is_gimple_debug (usestmt))
	    {
	      *debug_stmts = true;
	      continue;
	    }
	  else
	    {
	      useblock = gimple_bb (usestmt);
	    }

	  /* Short circuit. Nothing dominates the entry block.  */
	  if (useblock == ENTRY_BLOCK_PTR)
	    {
	      BITMAP_FREE (blocks);
	      return NULL;
	    }
	  bitmap_set_bit (blocks, useblock->index);
	}
    }
  commondom = BASIC_BLOCK (bitmap_first_set_bit (blocks));
  EXECUTE_IF_SET_IN_BITMAP (blocks, 0, j, bi)
    commondom = nearest_common_dominator (CDI_DOMINATORS, commondom,
					  BASIC_BLOCK (j));
  BITMAP_FREE (blocks);
  return commondom;
}

/* Given a statement (STMT) and the basic block it is currently in (FROMBB),
   determine the location to sink the statement to, if any.
   Returns true if there is such location; in that case, TOGSI points to the
   statement before that STMT should be moved.  */

static bool
statement_sink_location (gimple stmt, basic_block frombb,
			 gimple_stmt_iterator *togsi)
{
  gimple use;
  tree def;
  use_operand_p one_use = NULL_USE_OPERAND_P;
  basic_block sinkbb;
  use_operand_p use_p;
  def_operand_p def_p;
  ssa_op_iter iter;
  imm_use_iterator imm_iter;

  FOR_EACH_SSA_TREE_OPERAND (def, stmt, iter, SSA_OP_ALL_DEFS)
    {
      FOR_EACH_IMM_USE_FAST (one_use, imm_iter, def)
	{
	  if (is_gimple_debug (USE_STMT (one_use)))
	    continue;

	  break;
	}
      if (one_use != NULL_USE_OPERAND_P)
        break;
    }

  /* Return if there are no immediate uses of this stmt.  */
  if (one_use == NULL_USE_OPERAND_P)
    return false;

  if (gimple_code (stmt) != GIMPLE_ASSIGN)
    return false;

  /* There are a few classes of things we can't or don't move, some because we
     don't have code to handle it, some because it's not profitable and some
     because it's not legal.

     We can't sink things that may be global stores, at least not without
     calculating a lot more information, because we may cause it to no longer
     be seen by an external routine that needs it depending on where it gets
     moved to.

     We don't want to sink loads from memory.

     We can't sink statements that end basic blocks without splitting the
     incoming edge for the sink location to place it there.

     We can't sink statements that have volatile operands.

     We don't want to sink dead code, so anything with 0 immediate uses is not
     sunk.

     Don't sink BLKmode assignments if current function has any local explicit
     register variables, as BLKmode assignments may involve memcpy or memset
     calls or, on some targets, inline expansion thereof that sometimes need
     to use specific hard registers.

  */
  if (stmt_ends_bb_p (stmt)
      || gimple_has_side_effects (stmt)
      || is_hidden_global_store (stmt)
      || gimple_has_volatile_ops (stmt)
      || gimple_vuse (stmt)
      || (cfun->has_local_explicit_reg_vars
	  && TYPE_MODE (TREE_TYPE (gimple_assign_lhs (stmt))) == BLKmode))
    return false;

  FOR_EACH_SSA_DEF_OPERAND (def_p, stmt, iter, SSA_OP_ALL_DEFS)
    {
      tree def = DEF_FROM_PTR (def_p);
      if (is_global_var (SSA_NAME_VAR (def))
	  || SSA_NAME_OCCURS_IN_ABNORMAL_PHI (def))
	return false;
    }

  FOR_EACH_SSA_USE_OPERAND (use_p, stmt, iter, SSA_OP_ALL_USES)
    {
      tree use = USE_FROM_PTR (use_p);
      if (SSA_NAME_OCCURS_IN_ABNORMAL_PHI (use))
	return false;
    }

  /* If all the immediate uses are not in the same place, find the nearest
     common dominator of all the immediate uses.  For PHI nodes, we have to
     find the nearest common dominator of all of the predecessor blocks, since
     that is where insertion would have to take place.  */
  if (!all_immediate_uses_same_place (stmt))
    {
      bool debug_stmts = false;
      basic_block commondom = nearest_common_dominator_of_uses (stmt,
								&debug_stmts);

      if (commondom == frombb)
	return false;

      /* Our common dominator has to be dominated by frombb in order to be a
	 trivially safe place to put this statement, since it has multiple
	 uses.  */
      if (!dominated_by_p (CDI_DOMINATORS, commondom, frombb))
	return false;

      /* It doesn't make sense to move to a dominator that post-dominates
	 frombb, because it means we've just moved it into a path that always
	 executes if frombb executes, instead of reducing the number of
	 executions .  */
      if (dominated_by_p (CDI_POST_DOMINATORS, frombb, commondom))
	{
	  if (dump_file && (dump_flags & TDF_DETAILS))
	    fprintf (dump_file, "Not moving store, common dominator post-dominates from block.\n");
	  return false;
	}

      if (commondom == frombb || commondom->loop_depth > frombb->loop_depth)
	return false;
      if (dump_file && (dump_flags & TDF_DETAILS))
	{
	  fprintf (dump_file, "Common dominator of all uses is %d\n",
		   commondom->index);
	}

      *togsi = gsi_after_labels (commondom);

      return true;
    }

  use = USE_STMT (one_use);
  if (gimple_code (use) != GIMPLE_PHI)
    {
      sinkbb = gimple_bb (use);
      if (sinkbb == frombb || sinkbb->loop_depth > frombb->loop_depth
	  || sinkbb->loop_father != frombb->loop_father)
	return false;

      /* Move the expression to a post dominator can't reduce the number of
         executions.  */
      if (dominated_by_p (CDI_POST_DOMINATORS, frombb, sinkbb))
        return false;

      *togsi = gsi_for_stmt (use);

      return true;
    }

  /* Note that at this point, all uses must be in the same statement, so it
     doesn't matter which def op we choose, pick the first one.  */
  FOR_EACH_SSA_TREE_OPERAND (def, stmt, iter, SSA_OP_ALL_DEFS)
    break;

  sinkbb = find_bb_for_arg (use, def);
  if (!sinkbb)
    return false;

  /* This will happen when you have
     a_3 = PHI <a_13, a_26>

     a_26 = VDEF <a_3>

     If the use is a phi, and is in the same bb as the def,
     we can't sink it.  */

  if (gimple_bb (use) == frombb)
    return false;
  if (sinkbb == frombb || sinkbb->loop_depth > frombb->loop_depth
      || sinkbb->loop_father != frombb->loop_father)
    return false;

  /* Move the expression to a post dominator can't reduce the number of
     executions.  */
  if (dominated_by_p (CDI_POST_DOMINATORS, frombb, sinkbb))
    return false;

  *togsi = gsi_after_labels (sinkbb);

  return true;
}

/* Perform code sinking on BB */

static void
sink_code_in_bb (basic_block bb)
{
  basic_block son;
  gimple_stmt_iterator gsi;
  edge_iterator ei;
  edge e;
  bool last = true;

  /* If this block doesn't dominate anything, there can't be any place to sink
     the statements to.  */
  if (first_dom_son (CDI_DOMINATORS, bb) == NULL)
    goto earlyout;

  /* We can't move things across abnormal edges, so don't try.  */
  FOR_EACH_EDGE (e, ei, bb->succs)
    if (e->flags & EDGE_ABNORMAL)
      goto earlyout;

  for (gsi = gsi_last_bb (bb); !gsi_end_p (gsi);)
    {
      gimple stmt = gsi_stmt (gsi);
      gimple_stmt_iterator togsi;

      if (!statement_sink_location (stmt, bb, &togsi))
	{
	  if (!gsi_end_p (gsi))
	    gsi_prev (&gsi);
	  last = false;
	  continue;
	}
      if (dump_file)
	{
	  fprintf (dump_file, "Sinking ");
	  print_gimple_stmt (dump_file, stmt, 0, TDF_VOPS);
	  fprintf (dump_file, " from bb %d to bb %d\n",
		   bb->index, (gsi_bb (togsi))->index);
	}

      /* If this is the end of the basic block, we need to insert at the end
         of the basic block.  */
      if (gsi_end_p (togsi))
	gsi_move_to_bb_end (&gsi, gsi_bb (togsi));
      else
	gsi_move_before (&gsi, &togsi);

      sink_stats.sunk++;

      /* If we've just removed the last statement of the BB, the
	 gsi_end_p() test below would fail, but gsi_prev() would have
	 succeeded, and we want it to succeed.  So we keep track of
	 whether we're at the last statement and pick up the new last
	 statement.  */
      if (last)
	{
	  gsi = gsi_last_bb (bb);
	  continue;
	}

      last = false;
      if (!gsi_end_p (gsi))
	gsi_prev (&gsi);

    }
 earlyout:
  for (son = first_dom_son (CDI_POST_DOMINATORS, bb);
       son;
       son = next_dom_son (CDI_POST_DOMINATORS, son))
    {
      sink_code_in_bb (son);
    }
}

/* Perform code sinking.
   This moves code down the flowgraph when we know it would be
   profitable to do so, or it wouldn't increase the number of
   executions of the statement.

   IE given

   a_1 = b + c;
   if (<something>)
   {
   }
   else
   {
     foo (&b, &c);
     a_5 = b + c;
   }
   a_6 = PHI (a_5, a_1);
   USE a_6.

   we'll transform this into:

   if (<something>)
   {
      a_1 = b + c;
   }
   else
   {
      foo (&b, &c);
      a_5 = b + c;
   }
   a_6 = PHI (a_5, a_1);
   USE a_6.

   Note that this reduces the number of computations of a = b + c to 1
   when we take the else edge, instead of 2.
*/
static void
execute_sink_code (void)
{
  loop_optimizer_init (LOOPS_NORMAL);

  connect_infinite_loops_to_exit ();
  memset (&sink_stats, 0, sizeof (sink_stats));
  calculate_dominance_info (CDI_DOMINATORS);
  calculate_dominance_info (CDI_POST_DOMINATORS);
  sink_code_in_bb (EXIT_BLOCK_PTR);
  statistics_counter_event (cfun, "Sunk statements", sink_stats.sunk);
  free_dominance_info (CDI_POST_DOMINATORS);
  remove_fake_exit_edges ();
  loop_optimizer_finalize ();
}

/* Gate and execute functions for PRE.  */

static unsigned int
do_sink (void)
{
  execute_sink_code ();
  return 0;
}

static bool
gate_sink (void)
{
  return flag_tree_sink != 0;
}

struct gimple_opt_pass pass_sink_code =
{
 {
  GIMPLE_PASS,
  "sink",				/* name */
  gate_sink,				/* gate */
  do_sink,				/* execute */
  NULL,					/* sub */
  NULL,					/* next */
  0,					/* static_pass_number */
  TV_TREE_SINK,				/* tv_id */
  PROP_no_crit_edges | PROP_cfg
    | PROP_ssa,				/* properties_required */
  0,					/* properties_provided */
  0,					/* properties_destroyed */
  0,					/* todo_flags_start */
  TODO_update_ssa
    | TODO_dump_func
    | TODO_ggc_collect
    | TODO_verify_ssa			/* todo_flags_finish */
 }
};
