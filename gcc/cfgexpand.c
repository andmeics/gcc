/* A pass for lowering trees to RTL.
   Copyright (C) 2004 Free Software Foundation, Inc.

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
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "rtl.h"
#include "tm_p.h"
#include "basic-block.h"
#include "function.h"
#include "expr.h"
#include "langhooks.h"
#include "tree-flow.h"
#include "timevar.h"
#include "tree-dump.h"
#include "tree-pass.h"
#include "except.h"
#include "flags.h"

/* Expand basic block BB from GIMPLE trees to RTL.  */

static basic_block
expand_block (basic_block bb, FILE * dump_file)
{
  block_stmt_iterator bsi = bsi_start (bb);
  tree stmt = NULL;
  rtx note, last;
  edge e;

  if (dump_file)
    {
      tree_register_cfg_hooks ();
      dump_bb (bb, dump_file, 0);
      rtl_register_cfg_hooks ();
    }

  if (!bsi_end_p (bsi))
    stmt = bsi_stmt (bsi);

  if (stmt && TREE_CODE (stmt) == LABEL_EXPR)
    {
      last = get_last_insn ();

      (*lang_hooks.rtl_expand.stmt) (stmt);

      /* Java emits line number notes in the top of labels. 
         ??? Make this go away once line number notes are obsoleted.  */
      BB_HEAD (bb) = NEXT_INSN (last);
      if (GET_CODE (BB_HEAD (bb)) == NOTE)
	BB_HEAD (bb) = NEXT_INSN (BB_HEAD (bb));
      bsi_next (&bsi);
      note = emit_note_after (NOTE_INSN_BASIC_BLOCK, BB_HEAD (bb));
    }
  else
    note = BB_HEAD (bb) = emit_note (NOTE_INSN_BASIC_BLOCK);

  NOTE_BASIC_BLOCK (note) = bb;

  for (e = bb->succ; e; e = e->succ_next)
    {
      /* Clear EDGE_EXECUTABLE.  This flag is never used in the backend.  */
      e->flags &= ~EDGE_EXECUTABLE;

      /* At the moment not all abnormal edges match the RTL representation.
         It is safe to remove them here as find_sub_basic_blocks will
         rediscover them.  In the future we should get this fixed properly.  */
      if (e->flags & EDGE_ABNORMAL)
	remove_edge (e);
    }

  for (; !bsi_end_p (bsi); bsi_next (&bsi))
    {
      tree stmt = bsi_stmt (bsi);

      last = get_last_insn ();

      if (!stmt)
	continue;

      /* Expand this statement, then evaluate the resulting RTL and
	 fixup the CFG accordingly.  */
      (*lang_hooks.rtl_expand.stmt) (stmt);
      switch (TREE_CODE (stmt))
	{
	case COND_EXPR:
	  {
	    basic_block new_bb, dest;
	    edge new_edge;
	    edge true_edge;
	    edge false_edge;
	    tree pred = COND_EXPR_COND (stmt);
	    tree then_exp = COND_EXPR_THEN (stmt);
	    tree else_exp = COND_EXPR_ELSE (stmt);

	    extract_true_false_edges_from_block (bb, &true_edge, &false_edge);

	    /* These flags have no purpose in RTL land.  */
	    true_edge->flags &= ~EDGE_TRUE_VALUE;
	    false_edge->flags &= ~EDGE_FALSE_VALUE;

	    /* We can either have a pure conditional jump with one fallthru
	       edge or two-way jump that needs to be decomposed into two
	       basic blocks.  */
	    if (TREE_CODE (then_exp) == GOTO_EXPR
		&& TREE_CODE (else_exp) == NOP_EXPR)
	      {
		jumpif (pred, label_rtx (GOTO_DESTINATION (then_exp)));
		break;
	      }
	    if (TREE_CODE (else_exp) == GOTO_EXPR
		&& TREE_CODE (then_exp) == NOP_EXPR)
	      {
		jumpifnot (pred, label_rtx (GOTO_DESTINATION (else_exp)));
		break;
	      }
	    if (TREE_CODE (then_exp) != GOTO_EXPR
		|| TREE_CODE (else_exp) != GOTO_EXPR)
	      abort ();

	    jumpif (pred, label_rtx (GOTO_DESTINATION (then_exp)));
	    last = get_last_insn ();
	    expand_expr (else_exp, const0_rtx, VOIDmode, 0);

	    BB_END (bb) = last;
	    if (GET_CODE (BB_END (bb)) == BARRIER)
	      BB_END (bb) = PREV_INSN (BB_END (bb));
	    update_bb_for_insn (bb);

	    new_bb = create_basic_block (NEXT_INSN (last), get_last_insn (), bb);
	    dest = false_edge->dest;
	    redirect_edge_succ (false_edge, new_bb);
	    false_edge->flags |= EDGE_FALLTHRU;
	    new_bb->count = false_edge->count;
	    new_bb->frequency = EDGE_FREQUENCY (false_edge);
	    new_edge = make_edge (new_bb, dest, 0);
	    new_edge->probability = REG_BR_PROB_BASE;
	    new_edge->count = new_bb->count;
	    if (GET_CODE (BB_END (new_bb)) == BARRIER)
	      BB_END (new_bb) = PREV_INSN (BB_END (new_bb));
	    update_bb_for_insn (new_bb);

	    if (dump_file)
	      {
		dump_bb (bb, dump_file, 0);
		dump_bb (new_bb, dump_file, 0);
	      }
	    return new_bb;
	  }

	/* Update after expansion of sibling call.  */
	case CALL_EXPR:
	case MODIFY_EXPR:
	case RETURN_EXPR:
	  for (last = NEXT_INSN (last); last; last = NEXT_INSN (last))
	    {
	      if (GET_CODE (last) == CALL_INSN && SIBLING_CALL_P (last))
		{
		  edge e;
		  int probability = 0;
		  gcov_type count = 0;

		  do_pending_stack_adjust ();
		  for (e = bb->succ; e; e = e->succ_next)
		    if (!(e->flags & (EDGE_ABNORMAL | EDGE_EH)))
		      {
			count += e->count;
			probability += e->probability;
			remove_edge (e);
		      }

		  e = make_edge (bb, EXIT_BLOCK_PTR,
				     EDGE_ABNORMAL | EDGE_SIBCALL);
		  e->probability += probability;
		  e->count += count;
		  BB_END (bb) = last;

		  last = NEXT_INSN (last);
		  if (GET_CODE (last) != BARRIER)
		    abort ();
		  while (NEXT_INSN (last))
		    delete_insn (NEXT_INSN (last));
		  update_bb_for_insn (bb);
		  if (dump_file)
		    dump_bb (bb, dump_file, 0);
		  return bb;
		}
	    }
	  break;

	default:
	  break;
	}
    }

  do_pending_stack_adjust ();

  /* Find the the block tail.  The last insn is the block is the insn
     before a barrier and/or table jump insn.  */
  last = get_last_insn ();
  if (GET_CODE (last) == BARRIER)
    last = PREV_INSN (last);
  if (JUMP_TABLE_DATA_P (last))
    last = PREV_INSN (PREV_INSN (last));
  BB_END (bb) = last;
 
  if (dump_file)
    dump_bb (bb, dump_file, 0);
  update_bb_for_insn (bb);
  return bb;
}


/* Create a basic block for initialization code.  */

static basic_block
construct_init_block (void)
{
  basic_block init_block, first_block;
  edge e;
  tree bind_expr = DECL_SAVED_TREE (current_function_decl);
  tree block;

  /* Expand the start of the outermost BIND_EXPR.  */
  if (TREE_CODE (bind_expr) != BIND_EXPR)
    abort ();
  block = BIND_EXPR_BLOCK (bind_expr);
  expand_start_bindings_and_block (0, block);

  for (e = ENTRY_BLOCK_PTR->succ; e; e = e->succ_next)
    if (e->dest == ENTRY_BLOCK_PTR->next_bb)
      break;

  init_block = create_basic_block (NEXT_INSN (get_insns ()),
				   get_last_insn (),
				   ENTRY_BLOCK_PTR);
  if (e)
    {
      first_block = e->dest;
      redirect_edge_succ (e, init_block);
      make_edge (init_block, first_block, EDGE_FALLTHRU);
    }
  else
    make_edge (init_block, EXIT_BLOCK_PTR, EDGE_FALLTHRU);

  update_bb_for_insn (init_block);
  return init_block;
}


/* Create a block containing landing pads and similar stuff.  */

static void
construct_exit_block (void)
{
  rtx head = get_last_insn ();
  rtx end;
  basic_block exit_block;
  tree bind_expr = DECL_SAVED_TREE (current_function_decl);
  edge e, next;

  /* We hard-wired immediate_size_expand to zero above.
     expand_function_end will decrement this variable.  So, we set the
     variable to one here, so that after the decrement it will remain
     zero.  */
  immediate_size_expand = 1;

  /* Make sure the locus is set to the end of the function, so that 
     epilogue line numbers and warnings are set properly.  */
  if (cfun->function_end_locus.file)
    input_location = cfun->function_end_locus;

  /* The following insns belong to the top scope.  */
  record_block_change (DECL_INITIAL (current_function_decl));

  expand_end_bindings (BIND_EXPR_VARS (bind_expr), 1, 0);
  
  /* Allow language dialects to perform special processing.  */
  (*lang_hooks.rtl_expand.end) ();

  /* Generate rtl for function exit.  */
  expand_function_end ();

  end = get_last_insn ();
  if (head == end)
    return;
  exit_block = create_basic_block (NEXT_INSN (head), end, EXIT_BLOCK_PTR->prev_bb);
  for (e = EXIT_BLOCK_PTR->pred; e; e = next)
    {
      next = e->pred_next;
      if (!(e->flags & EDGE_ABNORMAL))
        redirect_edge_succ (e, exit_block);
    }
  make_edge (exit_block, EXIT_BLOCK_PTR, EDGE_FALLTHRU);
  update_bb_for_insn (exit_block);
}


/* Translate the intermediate representation contained in the CFG
   from GIMPLE trees to RTL.

   We do conversion per basic block and preserve/update the tree CFG.
   This implies we have to do some magic as the CFG can simultaneously
   consist of basic blocks containing RTL and GIMPLE trees.  This can
   confuse the CFG hooks, so be curefull to not manipulate CFG during
   the expansion.  */

void
tree_expand_cfg (void)
{
  basic_block bb, init_block;
  sbitmap blocks;
  int dump_flags;
  FILE *dump_file = dump_begin (TDI_expand, &dump_flags);

  /* Code updating conditional jumps rely that no conditionals will be
     simplified into unconditional jumps.  This also serve as usefull sanity
     checking.  */
  cleanup_control_flow ();

  /* Write the flowgraph to a dot file.  */
  rtl_register_cfg_hooks ();

  init_block = construct_init_block ();

  FOR_BB_BETWEEN (bb, init_block->next_bb, EXIT_BLOCK_PTR, next_bb)
    bb = expand_block (bb, dump_file);

  construct_exit_block ();

  /* Convert from NOTE_INSN_EH_REGION style notes, and do other
     sorts of eh initialization.  Delay this until after the
     initial rtl dump so that we can see the original nesting.  */
  convert_from_eh_region_ranges ();

  rebuild_jump_labels (get_insns ());
  find_exception_handler_labels ();

  blocks = sbitmap_alloc (last_basic_block);
  sbitmap_ones (blocks);
  find_many_sub_basic_blocks (blocks);
  purge_all_dead_edges (0);
  sbitmap_free (blocks);

  compact_blocks ();
  if (dump_file)
    {
      dump_flow_info (dump_file);
      fprintf (dump_file, "\n\n\nExpanded body:\n\n\n");
      print_rtl_with_bb (dump_file, get_insns ());
    }
#ifdef ENABLE_CHECKING
  verify_flow_info();
#endif
}

