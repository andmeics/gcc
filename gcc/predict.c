/* Branch prediction routines for the GNU compiler.
   Copyright (C) 2000, 2001 Free Software Foundation, Inc.

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

/* References:

   [1] "Branch Prediction for Free"
       Ball and Larus; PLDI '93.
   [2] "Static Branch Frequency and Program Profile Analysis"
       Wu and Larus; MICRO-27.
   [3] "Corpus-based Static Branch Prediction"
       Calder, Grunwald, Lindsay, Martin, Mozer, and Zorn; PLDI '95.

*/


#include "config.h"
#include "system.h"
#include "tree.h"
#include "rtl.h"
#include "tm_p.h"
#include "hard-reg-set.h"
#include "basic-block.h"
#include "insn-config.h"
#include "regs.h"
#include "flags.h"
#include "output.h"
#include "function.h"
#include "except.h"
#include "toplev.h"
#include "recog.h"
#include "expr.h"
#include "predict.h"

/* Random guesstimation given names.  */
#define PROB_NEVER		(0)
#define PROB_VERY_UNLIKELY	(REG_BR_PROB_BASE / 10 - 1)
#define PROB_UNLIKELY		(REG_BR_PROB_BASE * 4 / 10 - 1)
#define PROB_EVEN		(REG_BR_PROB_BASE / 2)
#define PROB_LIKELY		(REG_BR_PROB_BASE - PROB_UNLIKELY)
#define PROB_VERY_LIKELY	(REG_BR_PROB_BASE - PROB_VERY_UNLIKELY)
#define PROB_ALWAYS		(REG_BR_PROB_BASE)

static void combine_predictions_for_insn PARAMS ((rtx, basic_block));
static void dump_prediction		 PARAMS ((enum br_predictor, int,
						  basic_block, bool));
static void estimate_loops_at_level	 PARAMS ((struct loop *loop));
static void propagate_freq		 PARAMS ((basic_block));
static void estimate_bb_frequencies	 PARAMS ((struct loops *));
static void counts_to_freqs		 PARAMS ((void));

/* Information we hold about each branch predictor.
   Filled using information from predict.def.  */
struct predictor_info
{
  const char *name;	/* Name used in the debugging dumps.  */
  int hitrate;		/* Expected hitrate used by
			   predict_insn_def call.  */
  int flags;
};

/* Use given predictor without Dempster-Shaffer theory if it matches
   using first_match heuristics.  */
#define PRED_FLAG_FIRST_MATCH 1

/* Recompute hitrate in percent to our representation.  */

#define HITRATE(VAL) ((int)((VAL) * REG_BR_PROB_BASE + 50) / 100)

#define DEF_PREDICTOR(ENUM, NAME, HITRATE, FLAGS) {NAME, HITRATE, FLAGS},
struct predictor_info predictor_info[] = {
#include "predict.def"

  /* Upper bound on predictors.  */
  {NULL, 0, 0}
};
#undef DEF_PREDICTOR

void
predict_insn (insn, predictor, probability)
     rtx insn;
     int probability;
     enum br_predictor predictor;
{
  if (!any_condjump_p (insn))
    abort ();
  REG_NOTES (insn)
    = gen_rtx_EXPR_LIST (REG_BR_PRED,
			 gen_rtx_CONCAT (VOIDmode,
					 GEN_INT ((int) predictor),
					 GEN_INT ((int) probability)),
			 REG_NOTES (insn));
}

/* Predict insn by given predictor.  */
void
predict_insn_def (insn, predictor, taken)
     rtx insn;
     enum br_predictor predictor;
     enum prediction taken;
{
   int probability = predictor_info[(int) predictor].hitrate;
   if (taken != TAKEN)
     probability = REG_BR_PROB_BASE - probability;
   predict_insn (insn, predictor, probability);
}

/* Predict edge E with given probability if possible.  */
void
predict_edge (e, predictor, probability)
     edge e;
     int probability;
     enum br_predictor predictor;
{
  rtx last_insn;
  last_insn = e->src->end;

  /* We can store the branch prediction information only about
     conditional jumps.  */
  if (!any_condjump_p (last_insn))
    return;

  /* We always store probability of branching.  */
  if (e->flags & EDGE_FALLTHRU)
    probability = REG_BR_PROB_BASE - probability;

  predict_insn (last_insn, predictor, probability);
}

/* Predict edge E by given predictor if possible.  */
void
predict_edge_def (e, predictor, taken)
     edge e;
     enum br_predictor predictor;
     enum prediction taken;
{
   int probability = predictor_info[(int) predictor].hitrate;

   if (taken != TAKEN)
     probability = REG_BR_PROB_BASE - probability;
   predict_edge (e, predictor, probability);
}

/* Invert all branch predictions or probability notes in the INSN.  This needs
   to be done each time we invert the condition used by the jump.  */
void
invert_br_probabilities (insn)
     rtx insn;
{
  rtx note = REG_NOTES (insn);

  while (note)
    {
      if (REG_NOTE_KIND (note) == REG_BR_PROB)
	XEXP (note, 0) = GEN_INT (REG_BR_PROB_BASE - INTVAL (XEXP (note, 0)));
      else if (REG_NOTE_KIND (note) == REG_BR_PRED)
	XEXP (XEXP (note, 0), 1)
	  = GEN_INT (REG_BR_PROB_BASE - INTVAL (XEXP (XEXP (note, 0), 1)));
      note = XEXP (note, 1);
    }
}

/* Dump information about the branch prediction to the output file.  */
static void
dump_prediction (predictor, probability, bb, used)
     enum br_predictor predictor;
     int probability;
     basic_block bb;
     bool used;
{
  edge e = bb->succ;

  if (!rtl_dump_file)
    return;

  while (e->flags & EDGE_FALLTHRU)
    e = e->succ_next;

  fprintf (rtl_dump_file, "  %s heuristics%s: %.1f%%",
	   predictor_info[predictor].name,
	   used ? "" : " (ignored)",
	   probability * 100.0 / REG_BR_PROB_BASE);

  if (bb->count)
    {
      fprintf (rtl_dump_file, "  exec ");
      fprintf (rtl_dump_file, HOST_WIDEST_INT_PRINT_DEC,
	       (HOST_WIDEST_INT) bb->count);
      fprintf (rtl_dump_file, " hit ");
      fprintf (rtl_dump_file, HOST_WIDEST_INT_PRINT_DEC,
	       (HOST_WIDEST_INT) e->count);
      fprintf (rtl_dump_file, " (%.1f%%)",
	       e->count * 100.0 / bb->count);
    }
  fprintf (rtl_dump_file, "\n");
}

/* Combine all REG_BR_PRED notes into single probability and attach REG_BR_PROB
   note if not already present.  Remove now useless REG_BR_PRED notes.  */
static void
combine_predictions_for_insn (insn, bb)
     rtx insn;
     basic_block bb;
{
  rtx prob_note = find_reg_note (insn, REG_BR_PROB, 0);
  rtx *pnote = &REG_NOTES (insn);
  rtx note = REG_NOTES (insn);
  int best_probability = PROB_EVEN;
  int best_predictor = END_PREDICTORS;
  int combined_probability = REG_BR_PROB_BASE / 2;
  int d;
  bool first_match = false;
  bool found = false;

  if (rtl_dump_file)
    fprintf (rtl_dump_file, "Predictions for insn %i bb %i\n", INSN_UID (insn),
	     bb->index);

  /* We implement "first match" heuristics and use probability guessed
     by predictor with smallest index.  In the future we will use better
     probability combination techniques.  */
  while (note)
    {
      if (REG_NOTE_KIND (note) == REG_BR_PRED)
	{
	  int predictor = INTVAL (XEXP (XEXP (note, 0), 0));
	  int probability = INTVAL (XEXP (XEXP (note, 0), 1));

	  found = true;
	  if (best_predictor > predictor)
	    best_probability = probability, best_predictor = predictor;

	  d = (combined_probability * probability
	       + (REG_BR_PROB_BASE - combined_probability)
	       * (REG_BR_PROB_BASE - probability));
	  /* An FP math to avoid overflows of 32bit integers.  */
	  combined_probability = (((double)combined_probability) * probability
				  * REG_BR_PROB_BASE / d + 0.5);
	}
      note = XEXP (note, 1);
    }

  /* Decide heuristic to use.  In case we didn't match anything, use
     no_prediction heuristic, in case we did match, use either
     first match or Dempster-Shaffer theory depending on the flags.  */

  if (predictor_info [best_predictor].flags & PRED_FLAG_FIRST_MATCH)
    first_match = true;

  if (!found)
    dump_prediction (PRED_NO_PREDICTION, combined_probability, bb, true);
  else
    {
      dump_prediction (PRED_DS_THEORY, combined_probability, bb,
		       !first_match);
      dump_prediction (PRED_FIRST_MATCH, best_probability, bb, first_match);
    }

  if (first_match)
    combined_probability = best_probability;
  dump_prediction (PRED_COMBINED, combined_probability, bb, true);

  while (*pnote)
    {
      if (REG_NOTE_KIND (*pnote) == REG_BR_PRED)
	{
	  int predictor = INTVAL (XEXP (XEXP (*pnote, 0), 0));
	  int probability = INTVAL (XEXP (XEXP (*pnote, 0), 1));

	  dump_prediction (predictor, probability, bb,
			   !first_match || best_predictor == predictor);
          *pnote = XEXP (*pnote, 1);
	}
      else
        pnote = &XEXP (*pnote, 1);
    }
  if (!prob_note)
    {
      REG_NOTES (insn)
	= gen_rtx_EXPR_LIST (REG_BR_PROB,
			     GEN_INT (combined_probability), REG_NOTES (insn));
      /* Save the prediction into CFG in case we are seeing non-degenerated
	 conditional jump.  */
      if (bb->succ->succ_next)
	{
	  BRANCH_EDGE (bb)->probability = combined_probability;
	  FALLTHRU_EDGE (bb)->probability = REG_BR_PROB_BASE - combined_probability;
	}
    }
}

/* Statically estimate the probability that a branch will be taken.
   ??? In the next revision there will be a number of other predictors added
   from the above references. Further, each heuristic will be factored out
   into its own function for clarity (and to facilitate the combination of
   predictions).  */

void
estimate_probability (loops_info)
     struct loops *loops_info;
{
  sbitmap *dominators, *post_dominators;
  int i;
  int found_noreturn = 0;

  dominators = sbitmap_vector_alloc (n_basic_blocks, n_basic_blocks);
  post_dominators = sbitmap_vector_alloc (n_basic_blocks, n_basic_blocks);
  calculate_dominance_info (NULL, dominators, CDI_DOMINATORS);
  calculate_dominance_info (NULL, post_dominators, CDI_POST_DOMINATORS);

  /* Try to predict out blocks in a loop that are not part of a
     natural loop.  */
  for (i = 0; i < loops_info->num; i++)
    {
      int j;

      for (j = loops_info->array[i].first->index;
	   j <= loops_info->array[i].last->index;
	   ++j)
	{
	  if (TEST_BIT (loops_info->array[i].nodes, j))
	    {
	      int header_found = 0;
	      edge e;

	      /* Loop branch heuristics - predict as taken an edge back to
	         a loop's head.  */
	      for (e = BASIC_BLOCK(j)->succ; e; e = e->succ_next)
		if (e->dest == loops_info->array[i].header
		    && e->src == loops_info->array[i].latch)
		  {
		    header_found = 1;
		    predict_edge_def (e, PRED_LOOP_BRANCH, TAKEN);
		  }
	      /* Loop exit heuristics - predict as not taken an edge
	         exiting the loop if the conditinal has no loop header
	         successors.  */
	      if (!header_found)
		for (e = BASIC_BLOCK(j)->succ; e; e = e->succ_next)
		  if (e->dest->index <= 0
		      || !TEST_BIT (loops_info->array[i].nodes, e->dest->index))
		    predict_edge_def (e, PRED_LOOP_EXIT, NOT_TAKEN);
	    }
	}
    }

  /* Attempt to predict conditional jumps using a number of heuristics.  */
  for (i = 0; i < n_basic_blocks; i++)
    {
      basic_block bb = BASIC_BLOCK (i);
      rtx last_insn = bb->end;
      rtx cond, earliest;
      edge e;

      /* If block has no sucessor, predict all possible paths to
         it as improbable, as the block contains a call to a noreturn
	 function and thus can be executed only once.  */
      if (bb->succ == NULL && !found_noreturn)
	{
	  int y;

	  /* ??? Postdominator claims each noreturn block to be postdominated
	     by each, so we need to run only once.  This needs to be changed
	     once postdominace algorithm is updated to say something more sane.
	     */
	  found_noreturn = 1;
	  for (y = 0; y < n_basic_blocks; y++)
	    if (!TEST_BIT (post_dominators[y], i))
	      {
		for (e = BASIC_BLOCK (y)->succ; e; e = e->succ_next)
		if (e->dest->index >= 0
		    && TEST_BIT (post_dominators[e->dest->index], i))
		  predict_edge_def (e, PRED_NORETURN, NOT_TAKEN);
	      }
	}

      if (GET_CODE (last_insn) != JUMP_INSN
	  || ! any_condjump_p (last_insn))
	continue;

      for (e = bb->succ; e; e = e->succ_next)
	{
	  /* Predict edges to blocks that return immediately to be
	     improbable.  These are usually used to signal error states.  */
	  if (e->dest == EXIT_BLOCK_PTR
	      || (e->dest->succ && !e->dest->succ->succ_next
		  && e->dest->succ->dest == EXIT_BLOCK_PTR))
	    predict_edge_def (e, PRED_ERROR_RETURN, NOT_TAKEN);

	  /* Look for block we are guarding (ie we dominate it,
	     but it doesn't postdominate us).  */
	  if (e->dest != EXIT_BLOCK_PTR
	      && e->dest != bb
	      && TEST_BIT (dominators[e->dest->index], e->src->index)
	      && !TEST_BIT (post_dominators[e->src->index], e->dest->index))
	    {
	      rtx insn;
	      /* The call heuristic claims that a guarded function call
		 is improbable.  This is because such calls are often used
		 to signal exceptional situations such as printing error
		 messages.  */
	      for (insn = e->dest->head; insn != NEXT_INSN (e->dest->end);
		   insn = NEXT_INSN (insn))
		if (GET_CODE (insn) == CALL_INSN
		    /* Constant and pure calls are hardly used to signalize
		       something exceptional.  */
		    && ! CONST_OR_PURE_CALL_P (insn))
		  {
		    predict_edge_def (e, PRED_CALL, NOT_TAKEN);
		    break;
		  }
	    }
	}

      cond = get_condition (last_insn, &earliest);
      if (! cond)
	continue;

      /* Try "pointer heuristic."
	 A comparison ptr == 0 is predicted as false.
	 Similarly, a comparison ptr1 == ptr2 is predicted as false.  */
      switch (GET_CODE (cond))
	{
	case EQ:
	  if (GET_CODE (XEXP (cond, 0)) == REG
	      && REG_POINTER (XEXP (cond, 0))
	      && (XEXP (cond, 1) == const0_rtx
		  || (GET_CODE (XEXP (cond, 1)) == REG
		      && REG_POINTER (XEXP (cond, 1)))))

	    predict_insn_def (last_insn, PRED_POINTER, NOT_TAKEN);
	  break;
	case NE:
	  if (GET_CODE (XEXP (cond, 0)) == REG
	      && REG_POINTER (XEXP (cond, 0))
	      && (XEXP (cond, 1) == const0_rtx
		  || (GET_CODE (XEXP (cond, 1)) == REG
		      && REG_POINTER (XEXP (cond, 1)))))
	    predict_insn_def (last_insn, PRED_POINTER, TAKEN);
	  break;

	default:
	  break;
	}

      /* Try "opcode heuristic."
	 EQ tests are usually false and NE tests are usually true. Also,
	 most quantities are positive, so we can make the appropriate guesses
	 about signed comparisons against zero.  */
      switch (GET_CODE (cond))
	{
	case CONST_INT:
	  /* Unconditional branch.  */
	  predict_insn_def (last_insn, PRED_UNCONDITIONAL,
			    cond == const0_rtx ? NOT_TAKEN : TAKEN);
	  break;

	case EQ:
	case UNEQ:
	  predict_insn_def (last_insn, PRED_OPCODE, NOT_TAKEN);
	  break;
	case NE:
	case LTGT:
	  predict_insn_def (last_insn, PRED_OPCODE, TAKEN);
	  break;
	case ORDERED:
	  predict_insn_def (last_insn, PRED_OPCODE, TAKEN);
	  break;
	case UNORDERED:
	  predict_insn_def (last_insn, PRED_OPCODE, NOT_TAKEN);
	  break;
	case LE:
	case LT:
	  if (XEXP (cond, 1) == const0_rtx
	      || (GET_CODE (XEXP (cond, 1)) == CONST_INT
		  && INTVAL (XEXP (cond, 1)) == -1))
	    predict_insn_def (last_insn, PRED_OPCODE, NOT_TAKEN);
	  break;
	case GE:
	case GT:
	  if (XEXP (cond, 1) == const0_rtx
	      || (GET_CODE (XEXP (cond, 1)) == CONST_INT
		  && INTVAL (XEXP (cond, 1)) == -1))
	    predict_insn_def (last_insn, PRED_OPCODE, TAKEN);
	  break;

	default:
	  break;
	}
    }

  /* Attach the combined probability to each conditional jump.  */
  for (i = 0; i < n_basic_blocks; i++)
    {
      rtx last_insn = BLOCK_END (i);

      if (GET_CODE (last_insn) != JUMP_INSN
	  || ! any_condjump_p (last_insn))
	continue;
      combine_predictions_for_insn (last_insn, BASIC_BLOCK (i));
    }
  sbitmap_vector_free (post_dominators);
  sbitmap_vector_free (dominators);

  estimate_bb_frequencies (loops_info);
}

/* __builtin_expect dropped tokens into the insn stream describing
   expected values of registers.  Generate branch probabilities
   based off these values.  */

void
expected_value_to_br_prob ()
{
  rtx insn, cond, ev = NULL_RTX, ev_reg = NULL_RTX;

  for (insn = get_insns (); insn ; insn = NEXT_INSN (insn))
    {
      switch (GET_CODE (insn))
	{
	case NOTE:
	  /* Look for expected value notes.  */
	  if (NOTE_LINE_NUMBER (insn) == NOTE_INSN_EXPECTED_VALUE)
	    {
	      ev = NOTE_EXPECTED_VALUE (insn);
	      ev_reg = XEXP (ev, 0);
	    }
	  continue;

	case CODE_LABEL:
	  /* Never propagate across labels.  */
	  ev = NULL_RTX;
	  continue;

	default:
	  /* Look for insns that clobber the EV register.  */
	  if (ev && reg_set_p (ev_reg, insn))
	    ev = NULL_RTX;
	  continue;

	case JUMP_INSN:
	  /* Look for simple conditional branches.  If we havn't got an
	     expected value yet, no point going further.  */
	  if (GET_CODE (insn) != JUMP_INSN || ev == NULL_RTX)
	    continue;
	  if (! any_condjump_p (insn))
	    continue;
	  break;
	}

      /* Collect the branch condition, hopefully relative to EV_REG.  */
      /* ???  At present we'll miss things like
		(expected_value (eq r70 0))
		(set r71 -1)
		(set r80 (lt r70 r71))
		(set pc (if_then_else (ne r80 0) ...))
	 as canonicalize_condition will render this to us as
		(lt r70, r71)
	 Could use cselib to try and reduce this further.  */
      cond = XEXP (SET_SRC (PATTERN (insn)), 0);
      cond = canonicalize_condition (insn, cond, 0, NULL, ev_reg);
      if (! cond
	  || XEXP (cond, 0) != ev_reg
	  || GET_CODE (XEXP (cond, 1)) != CONST_INT)
	continue;

      /* Substitute and simplify.  Given that the expression we're
	 building involves two constants, we should wind up with either
	 true or false.  */
      cond = gen_rtx_fmt_ee (GET_CODE (cond), VOIDmode,
			     XEXP (ev, 1), XEXP (cond, 1));
      cond = simplify_rtx (cond);

      /* Turn the condition into a scaled branch probability.  */
      if (cond != const_true_rtx && cond != const0_rtx)
	abort ();
      predict_insn_def (insn, PRED_BUILTIN_EXPECT,
		        cond == const_true_rtx ? TAKEN : NOT_TAKEN);
    }
}

/* This is used to carry information about basic blocks.  It is
   attached to the AUX field of the standard CFG block.  */

typedef struct block_info_def
{
  /* Estimated frequency of execution of basic_block.  */
  double frequency;

  /* To keep queue of basic blocks to process.  */
  basic_block next;

  /* True if block already converted.  */
  int visited:1;

  /* Number of block proceeded before adding basic block to the queue.  Used
     to recognize irregular regions.  */
  int nvisited;
} *block_info;

/* Similar information for edges.  */
typedef struct edge_info_def
{
  /* In case edge is an loopback edge, the probability edge will be reached
     in case header is.  Estimated number of iterations of the loop can be
     then computed as 1 / (1 - back_edge_prob).  */
  double back_edge_prob;
  /* True if the edge is an loopback edge in the natural loop.  */
  int back_edge:1;
} *edge_info;

#define BLOCK_INFO(B)	((block_info) (B)->aux)
#define EDGE_INFO(E)	((edge_info) (E)->aux)

/* Helper function for estimate_bb_frequencies.
   Propagate the frequencies for loops headed by HEAD.  */
static void
propagate_freq (head)
     basic_block head;
{
  basic_block bb = head;
  basic_block last = bb;
  edge e;
  basic_block nextbb;
  int nvisited = 0;

  BLOCK_INFO (head)->frequency = 1;
  for (; bb; bb = nextbb)
    {
      double cyclic_probability = 0, frequency = 0;

      nextbb = BLOCK_INFO (bb)->next;
      BLOCK_INFO (bb)->next = NULL;

      /* Compute frequency of basic block.  */
      if (bb != head)
	{
	  for (e = bb->pred; e; e = e->pred_next)
	    if (!BLOCK_INFO (e->src)->visited && !EDGE_INFO (e)->back_edge)
	      break;

	  /* We haven't proceeded all predecessors of edge e yet.
	     These may be waiting in the queue or we may hit an
	     irreducible region.

	     To avoid infinite looping on irrecudible regions, count
	     the number of blocks proceeded at the time the basic
	     block has been queued.  In the case the number doesn't
	     change, we've hit an irreducible region and we can forget
	     the backward edge.	 This can increase the time complexity
	     by the number of irreducible blocks, but in the same way
	     the standard the loop does, so it should not result in a
	     noticeable slowdown.

	     Alternatively we may distinguish backward and cross edges
	     in the DFS tree by the preprocessing pass and ignore the
	     existence of non-loop backward edges.  */
	  if (e && BLOCK_INFO (bb)->nvisited != nvisited)
	    {
	      if (!nextbb)
		nextbb = e->dest;
	      else
		BLOCK_INFO (last)->next = e->dest;
	      BLOCK_INFO (last)->nvisited = nvisited;
	      last = e->dest;
	      continue;
	    }
	  else if (e && rtl_dump_file)
	    fprintf (rtl_dump_file, "Irreducible region hit, ignoring edge to bb %i\n",
		     bb->index);

	  for (e = bb->pred; e; e = e->pred_next)
	    if (EDGE_INFO (e)->back_edge)
	      cyclic_probability += EDGE_INFO (e)->back_edge_prob;
	    else if (BLOCK_INFO (e->src)->visited)
	      frequency += (e->probability
			    * BLOCK_INFO (e->src)->frequency /
			    REG_BR_PROB_BASE);

	  if (cyclic_probability > 1.0 - 1.0 / REG_BR_PROB_BASE)
	    cyclic_probability = 1.0 - 1.0 / REG_BR_PROB_BASE;

	  BLOCK_INFO (bb)->frequency = frequency / (1 - cyclic_probability);
	}

      BLOCK_INFO (bb)->visited = 1;

      /* Compute back edge frequencies.  */
      for (e = bb->succ; e; e = e->succ_next)
	if (e->dest == head)
	  EDGE_INFO (e)->back_edge_prob = (e->probability
					   * BLOCK_INFO (bb)->frequency
					   / REG_BR_PROB_BASE);

      /* Propagate to successor blocks.  */
      for (e = bb->succ; e; e = e->succ_next)
	if (!EDGE_INFO (e)->back_edge
	    && !BLOCK_INFO (e->dest)->visited
	    && !BLOCK_INFO (e->dest)->next && e->dest != last)
	  {
	    if (!nextbb)
	      nextbb = e->dest;
	    else
	      BLOCK_INFO (last)->next = e->dest;
	    BLOCK_INFO (last)->nvisited = nvisited;
	    last = e->dest;
	  }
      nvisited ++;
    }
}

/* Estimate probabilities of loopback edges in loops at same nest level.  */
static void
estimate_loops_at_level (first_loop)
     struct loop *first_loop;
{
  struct loop *l, *loop = first_loop;

  for (loop = first_loop; loop; loop = loop->next)
    {
      int n;
      edge e;

      estimate_loops_at_level (loop->inner);

      /* Find current loop back edge and mark it.  */
      for (e = loop->latch->succ; e->dest != loop->header; e = e->succ_next);

      EDGE_INFO (e)->back_edge = 1;

      /* In case the loop header is shared, ensure that it is the last
	 one sharing the same header, so we avoid redundant work.  */
      if (loop->shared)
	{
	  for (l = loop->next; l; l = l->next)
	    if (l->header == loop->header)
	      break;
	  if (l)
	    continue;
	}

      /* Now merge all nodes of all loops with given header as not visited.  */
      for (l = loop->shared ? first_loop : loop; l != loop->next; l = l->next)
	if (loop->header == l->header)
	  EXECUTE_IF_SET_IN_SBITMAP (l->nodes, 0, n,
				     BLOCK_INFO (BASIC_BLOCK (n))->visited =
				     0);
      propagate_freq (loop->header);
    }
}

/* Convert counts measured by profile driven feedback to frequencies.  */
static void
counts_to_freqs ()
{
  HOST_WIDEST_INT count_max = 1;
  int i;

  for (i = 0; i < n_basic_blocks; i++)
    if (BASIC_BLOCK (i)->count > count_max)
      count_max = BASIC_BLOCK (i)->count;

  for (i = -2; i < n_basic_blocks; i++)
    {
      basic_block bb;
      if (i == -2)
	bb = ENTRY_BLOCK_PTR;
      else if (i == -1)
	bb = EXIT_BLOCK_PTR;
      else
	bb = BASIC_BLOCK (i);
      bb->frequency = ((bb->count * BB_FREQ_MAX + count_max / 2)
		       / count_max);
    }
}

/* Estimate basic blocks frequency by given branch probabilities.  */
static void
estimate_bb_frequencies (loops)
     struct loops *loops;
{
  block_info bi;
  edge_info ei;
  int edgenum = 0;
  int i;
  double freq_max = 0;

  if (flag_branch_probabilities)
    {
      counts_to_freqs ();
      return;
    }

  /* Fill in the probability values in flowgraph based on the REG_BR_PROB
     notes.  */
  for (i = 0; i < n_basic_blocks; i++)
    {
      rtx last_insn = BLOCK_END (i);
      int probability;
      edge fallthru, branch;

      if (GET_CODE (last_insn) != JUMP_INSN || !any_condjump_p (last_insn)
	  /* Avoid handling of conditional jumps jumping to fallthru edge.  */
	  || BASIC_BLOCK (i)->succ->succ_next == NULL)
	{
	  /* We can predict only conditional jumps at the moment.
	     Expect each edge to be equally probable.
	     ?? In the future we want to make abnormal edges improbable.  */
	  int nedges = 0;
	  edge e;

	  for (e = BASIC_BLOCK (i)->succ; e; e = e->succ_next)
	    {
	      nedges++;
	      if (e->probability != 0)
		break;
	    }
	  if (!e)
	    for (e = BASIC_BLOCK (i)->succ; e; e = e->succ_next)
	      e->probability = (REG_BR_PROB_BASE + nedges / 2) / nedges;
	}
      else
	{
	  probability = INTVAL (XEXP (find_reg_note (last_insn,
						     REG_BR_PROB, 0), 0));
	  fallthru = BASIC_BLOCK (i)->succ;
	  if (!fallthru->flags & EDGE_FALLTHRU)
	    fallthru = fallthru->succ_next;
	  branch = BASIC_BLOCK (i)->succ;
	  if (branch->flags & EDGE_FALLTHRU)
	    branch = branch->succ_next;

	  branch->probability = probability;
	  fallthru->probability = REG_BR_PROB_BASE - probability;
	}
    }
  ENTRY_BLOCK_PTR->succ->probability = REG_BR_PROB_BASE;

  /* Set up block info for each basic block.  */
  bi = (block_info) xcalloc ((n_basic_blocks + 2), sizeof (*bi));
  ei = (edge_info) xcalloc ((n_edges), sizeof (*ei));
  for (i = -2; i < n_basic_blocks; i++)
    {
      edge e;
      basic_block bb;

      if (i == -2)
	bb = ENTRY_BLOCK_PTR;
      else if (i == -1)
	bb = EXIT_BLOCK_PTR;
      else
	bb = BASIC_BLOCK (i);
      bb->aux = bi + i + 2;
      BLOCK_INFO (bb)->visited = 1;
      for (e = bb->succ; e; e = e->succ_next)
	{
	  e->aux = ei + edgenum, edgenum++;
	  EDGE_INFO (e)->back_edge_prob = ((double) e->probability
					   / REG_BR_PROB_BASE);
	}
    }
  /* First compute probabilities locally for each loop from innermost
     to outermost to examine probabilities for back edges.  */
  estimate_loops_at_level (loops->tree_root);

  /* Now fake loop around whole function to finalize probabilities.  */
  for (i = 0; i < n_basic_blocks; i++)
    BLOCK_INFO (BASIC_BLOCK (i))->visited = 0;
  BLOCK_INFO (ENTRY_BLOCK_PTR)->visited = 0;
  BLOCK_INFO (EXIT_BLOCK_PTR)->visited = 0;
  propagate_freq (ENTRY_BLOCK_PTR);

  for (i = 0; i < n_basic_blocks; i++)
    if (BLOCK_INFO (BASIC_BLOCK (i))->frequency > freq_max)
      freq_max = BLOCK_INFO (BASIC_BLOCK (i))->frequency;
  for (i = -2; i < n_basic_blocks; i++)
    {
      basic_block bb;
      if (i == -2)
	bb = ENTRY_BLOCK_PTR;
      else if (i == -1)
	bb = EXIT_BLOCK_PTR;
      else
	bb = BASIC_BLOCK (i);
      bb->frequency = (BLOCK_INFO (bb)->frequency * BB_FREQ_MAX / freq_max
		       + 0.5);
    }

  free (ei);
  free (bi);
}
