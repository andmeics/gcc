/* Loop unrolling and peeling.
   Copyright (C) 2002 Free Software Foundation, Inc.

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

#include "config.h"
#include "system.h"
#include "rtl.h"
#include "tm_p.h"
#include "obstack.h"
#include "function.h"
#include "expr.h"
#include "hard-reg-set.h"
#include "basic-block.h"
#include "insn-config.h"
#include "regs.h"
#include "recog.h"
#include "flags.h"
#include "real.h"
#include "cselib.h"
#include "except.h"
#include "toplev.h"
#include "predict.h"
#include "insn-flags.h"
#include "cfglayout.h"
#include "loop.h"
#include "params.h"
#include "output.h"

static void unroll_or_peel_loop PARAMS ((struct loops *, struct loop *, int));
static bool peel_loop_simple PARAMS ((struct loops *, struct loop *, int));
static bool peel_loop_completely PARAMS ((struct loops *, struct loop *,
					  struct loop_desc *));
static bool unroll_loop_stupid PARAMS ((struct loops *, struct loop *, int));
static bool unroll_loop_constant_iterations PARAMS ((struct loops *,
						     struct loop *,
						     int, struct loop_desc *));
static bool unroll_loop_runtime_iterations PARAMS ((struct loops *,
						    struct loop *, int,
						    struct loop_desc *));

/* Unroll and peel (depending on FLAGS) LOOPS.  */
void
unroll_and_peel_loops (loops, flags)
     struct loops *loops;
     int flags;
{
  struct loop *loop = loops->tree_root, *next;

  while (loop->inner)
    loop = loop->inner;

  /* Scan the loops, inner ones first.  */
  while (loop != loops->tree_root)
    {
      if (loop->next)
	{
	  next = loop->next;
	  while (next->inner)
	    next = next->inner;
	}
      else
	next = loop->outer;

      unroll_or_peel_loop (loops, loop, flags);
#ifdef ENABLE_CHECKING
      verify_dominators (loops->cfg.dom);
      verify_loop_structure (loops, VLS_FOR_LOOP_NEW);
#endif
      loop = next;
    }
}
/* Peel NPEEL iterations from LOOP, remove exit edges (and cancel the loop
   completely).  */
static bool
peel_loop_completely (loops, loop, desc)
     struct loops *loops;
     struct loop *loop;
     struct loop_desc *desc;
{
  sbitmap wont_exit;
  unsigned HOST_WIDE_INT npeel;
  edge e;
  int n_remove_edges, i;
  edge *remove_edges;
  
  npeel = desc->niter;

  wont_exit = sbitmap_alloc (npeel + 2);
  sbitmap_ones (wont_exit);
  RESET_BIT (wont_exit, 0);
  RESET_BIT (wont_exit, npeel + 1);
  if (desc->may_be_zero)
    RESET_BIT (wont_exit, 1);

  remove_edges = xcalloc (npeel, sizeof (edge));
  n_remove_edges = 0;

  if (!duplicate_loop_to_header_edge (loop, loop_preheader_edge (loop),
	loops, npeel + 1,
	wont_exit, desc->out_edge, remove_edges, &n_remove_edges,
	DLTHE_FLAG_ALL))
    abort ();

  free (wont_exit);

  /* Remove the exit edges.  */
  for (i = 0; i < n_remove_edges; i++)
    remove_path (loops, remove_edges[i]);
  free (remove_edges);

  /* Now remove the loop.  */
  for (e = RBI (desc->in_edge->src)->copy->succ;
       e && e->dest != RBI (desc->in_edge->dest)->copy;
       e = e->succ_next);

  if (!e)
    abort ();

  remove_path (loops, e);

  if (rtl_dump_file)
    fprintf (rtl_dump_file, ";; Peeled loop completely, %d times\n",npeel);

  return true;
}

/* Unroll LOOP with constant number of iterations described by DESC.
   MAX_UNROLL is maximal number of allowed unrollings.  */
static bool
unroll_loop_constant_iterations (loops, loop, max_unroll, desc)
     struct loops *loops;
     struct loop *loop;
     int max_unroll;
     struct loop_desc *desc;
{
  unsigned HOST_WIDE_INT niter, exit_mod;
  sbitmap wont_exit;
  int n_remove_edges, i, n_copies;
  edge *remove_edges;
  int best_copies, best_unroll = -1;

  niter = desc->niter;

  if (niter <= (unsigned) max_unroll + 1)
    abort ();  /* Should not get here.  */

  /* Find good number of unrollings.  */
  best_copies = 2 * max_unroll + 10;

  i = 2 * max_unroll + 2;
  if ((unsigned) i - 1 >= niter)
    i = niter - 2;

  for (; i >= max_unroll; i--)
    {
      exit_mod = niter % (i + 1);

      if (desc->postincr)
	n_copies = exit_mod + i + 1;
      else if (exit_mod != (unsigned) i || desc->may_be_zero)
	n_copies = exit_mod + i + 2;
      else
	n_copies = i + 1;

      if (n_copies < best_copies)
	{
	  best_copies = n_copies;
	  best_unroll = i;
	}
    }

  if (rtl_dump_file)
    fprintf (rtl_dump_file, ";; max_unroll %d (%d copies, initial %d).\n",
	     best_unroll, best_copies, max_unroll);
  max_unroll = best_unroll;

  exit_mod = niter % (max_unroll + 1);

  wont_exit = sbitmap_alloc (max_unroll + 1);
  sbitmap_ones (wont_exit);

  remove_edges = xcalloc (max_unroll + exit_mod + 1, sizeof (edge));
  n_remove_edges = 0;

  if (desc->postincr)
    {
      /* Counter is incremented after the exit test; leave exit test
	 in the first copy.  */

      if (rtl_dump_file)
	fprintf (rtl_dump_file, ";; Condition on beginning of loop.\n");

      /* Peel exit_mod iterations.  */
      RESET_BIT (wont_exit, 0);
      if (desc->may_be_zero)
	RESET_BIT (wont_exit, 1);

      if (exit_mod
	  && !duplicate_loop_to_header_edge (loop, loop_preheader_edge (loop),
		loops, exit_mod,
		wont_exit, desc->out_edge, remove_edges, &n_remove_edges,
		DLTHE_FLAG_ALL))
	abort ();

      SET_BIT (wont_exit, 1);
    }
  else
    {
      /* Leave exit test in last copy.  */

      if (rtl_dump_file)
	fprintf (rtl_dump_file, ";; Condition on end of loop.\n");

      /* We know that niter >= max_unroll + 2; so we do not need to care of
	 case when we would exit before reaching the loop.  So just peel
	 exit_mod + 1 iterations.
	 */
      if (exit_mod != (unsigned) max_unroll || desc->may_be_zero)
	{
	  RESET_BIT (wont_exit, 0);
	  if (desc->may_be_zero)
	    RESET_BIT (wont_exit, 1);

	  if (!duplicate_loop_to_header_edge (loop, loop_preheader_edge (loop),
		loops, exit_mod + 1,
		wont_exit, desc->out_edge, remove_edges, &n_remove_edges,
		DLTHE_FLAG_ALL))
	    abort ();

	  SET_BIT (wont_exit, 0);
	  SET_BIT (wont_exit, 1);
	}

      RESET_BIT (wont_exit, max_unroll);
    }

  /* Now unroll the loop.  */
  if (!duplicate_loop_to_header_edge (loop, loop_latch_edge (loop),
		loops, max_unroll,
		wont_exit, desc->out_edge, remove_edges, &n_remove_edges,
		DLTHE_FLAG_ALL))
    abort ();

  free (wont_exit);

  /* Remove the edges.  */
  for (i = 0; i < n_remove_edges; i++)
    remove_path (loops, remove_edges[i]);
  free (remove_edges);

  if (rtl_dump_file)
    fprintf (rtl_dump_file, ";; Unrolled loop %d times, constant # of iterations %i insns\n",max_unroll, num_loop_insns (loop));
  
  return true;
}

/* Unroll LOOP for that we are able to count number of iterations in runtime.
   MAX_UNROLL is maximal number of allowed unrollings.  DESC describes the loop.  */
static bool
unroll_loop_runtime_iterations (loops, loop, max_unroll, desc)
     struct loops *loops;
     struct loop *loop;
     int max_unroll;
     struct loop_desc *desc;
{
  rtx niter, init_code, branch_code;
  rtx loop_beg_label;
  int i, j;
  basic_block fake, preheader, *body, dom, *dom_bbs;
  int n_dom_bbs;
  edge e;
  sbitmap wont_exit;
  int may_exit_copy, n_peel, n_remove_edges;
  edge *remove_edges;
  bool skip_first_test;

  /* Remember blocks whose dominators will have to be updated.  */
  dom_bbs = xcalloc (n_basic_blocks, sizeof (basic_block));
  n_dom_bbs = 0;

  body = get_loop_body (loop);
  for (i = 0; i < loop->num_nodes; i++)
    {
      int nldom;
      basic_block *ldom;

      nldom = get_dominated_by (loops->cfg.dom, body[i], &ldom);
      for (j = 0; j < nldom; j++)
	dom_bbs[n_dom_bbs++] = ldom[j];

      free (ldom);
    }
  free (body);

  /* Force max_unroll + 1 to be power of 2.  */
  for (i = 1; 2 * i <= max_unroll + 1; i *= 2);
  max_unroll = i - 1;

  /* Normalization.  */
  start_sequence ();
  niter = count_loop_iterations (desc, NULL, NULL);
  if (!niter)
    abort ();
  niter = force_operand (niter, NULL);

  /* Count modulo by ANDing it with max_unroll.  */
  niter = expand_simple_binop (GET_MODE (desc->var), AND,
			       niter,
			       GEN_INT (max_unroll),
			       NULL_RTX, 0, OPTAB_LIB_WIDEN);

  if (desc->postincr)
    {
      /* Leave exit in first copy.  */
      may_exit_copy = 0;
      n_peel = max_unroll;
      skip_first_test = false;
    }
  else
    {
      /* Leave exit in last copy.  */
      may_exit_copy = max_unroll;
      niter = expand_simple_binop (GET_MODE (desc->var), PLUS,
				   niter,
				   const1_rtx, NULL_RTX, 0, OPTAB_LIB_WIDEN);
      n_peel = max_unroll + 1;
      skip_first_test = true;
      /* First check for zero is obviously unnecessary now; it might seem
	 we could do better by increasing it before AND; but we must have
	 guaranteed that exit condition will be checked in first iteration,
	 so that we won't miscompile loop with negative number of iterations.  */
    }

  niter = expand_simple_binop (GET_MODE (desc->var), PLUS,
			       niter,
			       const1_rtx, NULL_RTX, 0, OPTAB_LIB_WIDEN);

  init_code = gen_sequence ();
  end_sequence ();

  /* Precondition the loop.  */
  loop_split_edge_with (loop_preheader_edge (loop), init_code, loops);

  /* Fake block, to record edges we need to redirect.  */
  fake = create_basic_block (NULL, NULL, EXIT_BLOCK_PTR->prev_bb);
  add_to_dominance_info (loops->cfg.dom, fake);
  loop_beg_label = block_label (fake);

  remove_edges = xcalloc (max_unroll + n_peel, sizeof (edge));
  n_remove_edges = 0;

  wont_exit = sbitmap_alloc (2);

  for (i = 0; i < n_peel; i++)
    {
      start_sequence ();
      niter = expand_simple_binop (GET_MODE (desc->var), MINUS,
				   niter, const1_rtx,
				   NULL_RTX, 0, OPTAB_LIB_WIDEN);
      if (i || !skip_first_test)
	{
	  do_compare_rtx_and_jump (copy_rtx (niter), const0_rtx, EQ, 0,
		GET_MODE (desc->var), NULL_RTX, NULL_RTX,
		loop_beg_label);
	  JUMP_LABEL (get_last_insn ()) = loop_beg_label;
	  LABEL_NUSES (loop_beg_label)++;
	}
      branch_code = gen_sequence ();
      end_sequence ();

      preheader =
	loop_split_edge_with (loop_preheader_edge (loop), branch_code, loops);

      if (i || !skip_first_test)
	make_edge (preheader, fake, 0);

      /* We must be a bit careful here, as we might have negative
	 number of iterations.  Also, in case of postincrement we do
	 not know whether we should not exit before reaching the loop.  */
      sbitmap_zero (wont_exit);
      if (desc->postincr && (i || desc->cond == NE))
	SET_BIT (wont_exit, 1);

      if (!duplicate_loop_to_header_edge (loop, loop_preheader_edge (loop),
		loops, 1,
		wont_exit, desc->out_edge, remove_edges, &n_remove_edges,
		DLTHE_FLAG_ALL))
	abort ();
    }
  free (wont_exit);

  /* Now redirect the edges from fake.  */
  preheader =
    loop_split_edge_with (loop_preheader_edge (loop), NULL_RTX, loops);
  loop_beg_label = block_label (preheader);

  for (e = fake->pred; e; e = fake->pred)
    {
      if (!redirect_edge_and_branch (e, preheader))
	abort ();
    }

  dom = recount_dominator (loops->cfg.dom, preheader);
  set_immediate_dominator (loops->cfg.dom, preheader, dom);

  /* Recount dominators for outer blocks.  */
  iterate_fix_dominators (loops->cfg.dom, dom_bbs, n_dom_bbs);
  free (dom_bbs);

  /* Get rid of fake.  */
  delete_from_dominance_info (loops->cfg.dom, fake);
  flow_delete_block (fake);

  /* And unroll loop.  */

  wont_exit = sbitmap_alloc (max_unroll + 1);
  sbitmap_ones (wont_exit);
  RESET_BIT (wont_exit, may_exit_copy);

  if (!duplicate_loop_to_header_edge (loop, loop_latch_edge (loop),
	 	loops, max_unroll,
		wont_exit, desc->out_edge, remove_edges, &n_remove_edges,
		DLTHE_FLAG_ALL))
    abort ();

  free (wont_exit);

  /* Remove the edges.  */
  for (i = 0; i < n_remove_edges; i++)
    remove_path (loops, remove_edges[i]);
  free (remove_edges);

  if (rtl_dump_file)
    fprintf (rtl_dump_file,
	     ";; Unrolled loop %d times, counting # of iterations in runtime, %i insns\n",
	     max_unroll, num_loop_insns (loop));

  return true;
}
  
/* Peel a LOOP.  Returs 0 if impossible, 1 otherwise.  */
static bool
peel_loop_simple (loops, loop, npeel)
     struct loops *loops;
     struct loop *loop;
     int npeel;
{
  sbitmap wont_exit;

  wont_exit = sbitmap_alloc (npeel + 1);
  sbitmap_zero (wont_exit);

  if (!duplicate_loop_to_header_edge (loop, loop_preheader_edge (loop),
		loops, npeel, wont_exit, NULL, NULL, NULL, DLTHE_FLAG_ALL))
    {
      if (rtl_dump_file)
	fprintf (rtl_dump_file, ";; Peeling unsuccessful\n");
      return false;
    }
  
  free (wont_exit);

  if (rtl_dump_file)
    fprintf (rtl_dump_file, ";; Peeling loop %d times\n", npeel);

  return true;
}
  
/* Unroll a LOOP.  Returs 0 if impossible, 1 otherwise.  */
static bool
unroll_loop_stupid (loops, loop, nunroll)
     struct loops *loops;
     struct loop *loop;
     int nunroll;
{
  sbitmap wont_exit;

  wont_exit = sbitmap_alloc (nunroll + 1);
  sbitmap_zero (wont_exit);

  if (!duplicate_loop_to_header_edge (loop, loop_latch_edge (loop),
		loops, nunroll, wont_exit, NULL, NULL, NULL, DLTHE_FLAG_ALL))
    {
      if (rtl_dump_file)
	fprintf (rtl_dump_file, ";;  Not unrolling loop, can't duplicate\n");
      return false;
    }

  free (wont_exit);
  if (rtl_dump_file)
    fprintf (rtl_dump_file, ";; Unrolled loop %d times, %i insns\n",
	     nunroll, num_loop_insns (loop));
	  
  return true;
}

/* Unroll or peel (depending on FLAGS) LOOP.  */
static void
unroll_or_peel_loop (loops, loop, flags)
     struct loops *loops;
     struct loop *loop;
     int flags;
{
  int ninsns;
  unsigned HOST_WIDE_INT nunroll, npeel, niter = 0;
  struct loop_desc desc;
  bool simple, exact;

  /* Do not unroll/peel cold areas.  */
  if (!maybe_hot_bb_p (loop->header))
    {
      if (rtl_dump_file)
	fprintf (rtl_dump_file, ";; Not unrolling/peeling loop, cold area\n");
      return;
    }

  /* Can the loop be manipulated?  */
  if (!can_duplicate_loop_p (loop))
    {
      if (rtl_dump_file)
	fprintf (rtl_dump_file,
		 ";; Not unrolling/peeling loop, cannot duplicate\n");
      return;
    }

  /* Only peel innermost loops.  */
  if (loop->inner)
    {
      if ((flags & UAP_PEEL) && rtl_dump_file)
	fprintf (rtl_dump_file, ";; Not peeling loop, not innermost loop\n");
      flags &= ~UAP_PEEL;
    }

  /* Count maximal number of unrollings/peelings.  */
  ninsns = num_loop_insns (loop);

  /* npeel = number of iterations to peel. */
  npeel = PARAM_VALUE (PARAM_MAX_PEELED_INSNS) / ninsns;
  if (npeel > (unsigned) PARAM_VALUE (PARAM_MAX_PEEL_TIMES))
    npeel = PARAM_VALUE (PARAM_MAX_PEEL_TIMES);

  /* nunroll = total number of copies of the original loop body in
     unrolled loop (i.e. if it is 2, we have to duplicate loop body once.  */
  nunroll = PARAM_VALUE (PARAM_MAX_UNROLLED_INSNS) / ninsns;
  if (nunroll > (unsigned) PARAM_VALUE (PARAM_MAX_UNROLL_TIMES))
    nunroll = PARAM_VALUE (PARAM_MAX_UNROLL_TIMES);

  /* Skip big loops.  */
  if (nunroll <= 1)
    {
      if ((flags & UAP_UNROLL) && rtl_dump_file)
	fprintf (rtl_dump_file, ";; Not unrolling loop, is too big\n");
      flags &= ~(UAP_UNROLL | UAP_UNROLL_ALL);
    }

  if (npeel <= 0)
    {
      if ((flags & UAP_PEEL) && rtl_dump_file)
	fprintf (rtl_dump_file, ";; Not peeling loop, is too big\n");
      flags &= ~UAP_PEEL;
    }

  /* Shortcut.  */
  if (!flags)
    return;

  /* Check for simple loops.  */
  simple = simple_loop_p (loops, loop, &desc);
  if (!simple && !(flags & UAP_UNROLL_ALL))
    {
      if ((flags & UAP_UNROLL) && rtl_dump_file)
	fprintf (rtl_dump_file, ";;  Not unrolling loop, isn't simple\n");
      flags &= ~UAP_UNROLL;
    }

  /* Try to guess number of iterations.  */
  exact = false;
  if (simple)
    {
      /* Loop iterating 0 times.  These should really be eliminated earlier,
	 but we may create them by other transformations.  */

      if (desc.const_iter && desc.niter == 0)
	{
	  flags |= UAP_PEEL;
	  exact = true;
	  niter = 0;
	}
      else 
	{
	  exact = desc.const_iter;
	  niter = desc.niter;
	}
    }

  if (!exact)
    {
      /* Use profile information.  */
      niter = expected_loop_iterations (loop);
      if (loop->header->count)
	exact = true;
    }

  if (exact)
    {
      /* If estimate is good, use it to decide and bound number of peelings.  */
      if (niter + 1 > npeel)
	{
	  if ((flags & UAP_PEEL) && rtl_dump_file)
	    fprintf (rtl_dump_file,
		     ";; Not peeling loop, rolls too much (%d iterations > %d [maximum peelings])\n",
		     niter, npeel);
	  flags &= ~UAP_PEEL;
	}
      npeel = niter + 1;

      /* And unrollings.  */
      if (niter < 2 * nunroll)
	{
	  if (rtl_dump_file)
	    fprintf (rtl_dump_file, ";; Not unrolling loop, doesn't roll\n");
	  flags &= ~(UAP_UNROLL | UAP_UNROLL_ALL);
	}
    }
  else
    {
      /* For now we have no good heuristics to decide whether loop peeling
         will be effective, so disable it.  */
      if ((flags & UAP_PEEL) && rtl_dump_file)
	fprintf (rtl_dump_file,
		 ";; Not peeling loop, no evidence it will be profitable\n");
      flags &= ~UAP_PEEL;
    }

  /* Shortcut.  */
  if (!flags)
    return;

  /* If we still may both unroll and peel, then unroll.  */
  if ((flags & UAP_UNROLL) && (flags & UAP_PEEL))
    {
      if (rtl_dump_file)
	fprintf (rtl_dump_file, ";;  Not peelling loop, unrolling instead\n");
      flags &= ~UAP_PEEL;
    }

  /* Now we have several cases:  */
  if (flags & UAP_UNROLL)
    {
      /* Unrolling:  */

      if (simple)
	{
	  if (desc.const_iter)
	    /* Loops with constant number of iterations.  */
	    unroll_loop_constant_iterations (loops, loop, (int) nunroll,
					     &desc);
	  else
	    /* Loops with countable number of iterations.  */
	    unroll_loop_runtime_iterations (loops, loop, (int) nunroll,
					    &desc);
	}
      else
	/* Stupid unrolling.  */
	unroll_loop_stupid (loops, loop, (int) nunroll);
    }
  else
    {
      /* Peeling:  */

      if (simple && desc.const_iter)
	/* Peel and remove the loop completely.  */
	peel_loop_completely (loops, loop, &desc);
      else
	/* Simple loop peeling.  */
	peel_loop_simple (loops, loop, (int) npeel);
    }

  return;
}
