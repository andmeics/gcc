/* Standard problems for dataflow support routines.
   Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007,
   2008, 2009, 2010, 2011 Free Software Foundation, Inc.
   Originally contributed by Michael P. Hayes
             (m.hayes@elec.canterbury.ac.nz, mhayes@redhat.com)
   Major rewrite contributed by Danny Berlin (dberlin@dberlin.org)
             and Kenneth Zadeck (zadeck@naturalbridge.com).

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
#include "tm.h"
#include "rtl.h"
#include "tm_p.h"
#include "insn-config.h"
#include "recog.h"
#include "function.h"
#include "regs.h"
#include "output.h"
#include "alloc-pool.h"
#include "flags.h"
#include "hard-reg-set.h"
#include "basic-block.h"
#include "sbitmap.h"
#include "bitmap.h"
#include "target.h"
#include "timevar.h"
#include "df.h"
#include "except.h"
#include "dce.h"
#include "vecprim.h"

/* Note that turning REG_DEAD_DEBUGGING on will cause
   gcc.c-torture/unsorted/dump-noaddr.c to fail because it prints
   addresses in the dumps.  */
#if 0
#define REG_DEAD_DEBUGGING
#endif

#define DF_SPARSE_THRESHOLD 32

static bitmap_head seen_in_block;
static bitmap_head seen_in_insn;


/*----------------------------------------------------------------------------
   Public functions access functions for the dataflow problems.
----------------------------------------------------------------------------*/
/* Get the live at out set for BB no matter what problem happens to be
   defined.  This function is used by the register allocators who
   choose different dataflow problems depending on the optimization
   level.  */

bitmap
df_get_live_out (basic_block bb)
{
  gcc_assert (df_lr);

  if (df_live)
    return DF_LIVE_OUT (bb);
  else
    return DF_LR_OUT (bb);
}

/* Get the live at in set for BB no matter what problem happens to be
   defined.  This function is used by the register allocators who
   choose different dataflow problems depending on the optimization
   level.  */

bitmap
df_get_live_in (basic_block bb)
{
  gcc_assert (df_lr);

  if (df_live)
    return DF_LIVE_IN (bb);
  else
    return DF_LR_IN (bb);
}

/*----------------------------------------------------------------------------
   Utility functions.
----------------------------------------------------------------------------*/

/* Generic versions to get the void* version of the block info.  Only
   used inside the problem instance vectors.  */

/* Dump a def-use or use-def chain for REF to FILE.  */

void
df_chain_dump (struct df_link *link, FILE *file)
{
  fprintf (file, "{ ");
  for (; link; link = link->next)
    {
      fprintf (file, "%c%d(bb %d insn %d) ",
	       DF_REF_REG_DEF_P (link->ref)
	       ? 'd'
	       : (DF_REF_FLAGS (link->ref) & DF_REF_IN_NOTE) ? 'e' : 'u',
	       DF_REF_ID (link->ref),
	       DF_REF_BBNO (link->ref),
	       DF_REF_IS_ARTIFICIAL (link->ref)
	       ? -1 : DF_REF_INSN_UID (link->ref));
    }
  fprintf (file, "}");
}


/* Print some basic block info as part of df_dump.  */

void
df_print_bb_index (basic_block bb, FILE *file)
{
  edge e;
  edge_iterator ei;

  fprintf (file, "\n( ");
    FOR_EACH_EDGE (e, ei, bb->preds)
    {
      basic_block pred = e->src;
      fprintf (file, "%d%s ", pred->index, e->flags & EDGE_EH ? "(EH)" : "");
    }
  fprintf (file, ")->[%d]->( ", bb->index);
  FOR_EACH_EDGE (e, ei, bb->succs)
    {
      basic_block succ = e->dest;
      fprintf (file, "%d%s ", succ->index, e->flags & EDGE_EH ? "(EH)" : "");
    }
  fprintf (file, ")\n");
}


/*----------------------------------------------------------------------------
   REACHING DEFINITIONS

   Find the locations in the function where each definition site for a
   pseudo reaches.  In and out bitvectors are built for each basic
   block.  The id field in the ref is used to index into these sets.
   See df.h for details.
   ----------------------------------------------------------------------------*/

/* This problem plays a large number of games for the sake of
   efficiency.

   1) The order of the bits in the bitvectors.  After the scanning
   phase, all of the defs are sorted.  All of the defs for the reg 0
   are first, followed by all defs for reg 1 and so on.

   2) There are two kill sets, one if the number of defs is less or
   equal to DF_SPARSE_THRESHOLD and another if the number of defs is
   greater.

   <= : Data is built directly in the kill set.

   > : One level of indirection is used to keep from generating long
   strings of 1 bits in the kill sets.  Bitvectors that are indexed
   by the regnum are used to represent that there is a killing def
   for the register.  The confluence and transfer functions use
   these along with the bitmap_clear_range call to remove ranges of
   bits without actually generating a knockout vector.

   The kill and sparse_kill and the dense_invalidated_by_call and
   sparse_invalidated_by_call both play this game.  */

/* Private data used to compute the solution for this problem.  These
   data structures are not accessible outside of this module.  */
struct df_rd_problem_data
{
  /* The set of defs to regs invalidated by call.  */
  bitmap_head sparse_invalidated_by_call;
  /* The set of defs to regs invalidate by call for rd.  */
  bitmap_head dense_invalidated_by_call;
  /* An obstack for the bitmaps we need for this problem.  */
  bitmap_obstack rd_bitmaps;
};


/* Free basic block info.  */

static void
df_rd_free_bb_info (basic_block bb ATTRIBUTE_UNUSED,
		    void *vbb_info)
{
  struct df_rd_bb_info *bb_info = (struct df_rd_bb_info *) vbb_info;
  if (bb_info)
    {
      bitmap_clear (&bb_info->kill);
      bitmap_clear (&bb_info->sparse_kill);
      bitmap_clear (&bb_info->gen);
      bitmap_clear (&bb_info->in);
      bitmap_clear (&bb_info->out);
    }
}


/* Allocate or reset bitmaps for DF_RD blocks. The solution bits are
   not touched unless the block is new.  */

static void
df_rd_alloc (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;
  struct df_rd_problem_data *problem_data;

  if (df_rd->problem_data)
    {
      problem_data = (struct df_rd_problem_data *) df_rd->problem_data;
      bitmap_clear (&problem_data->sparse_invalidated_by_call);
      bitmap_clear (&problem_data->dense_invalidated_by_call);
    }
  else
    {
      problem_data = XNEW (struct df_rd_problem_data);
      df_rd->problem_data = problem_data;

      bitmap_obstack_initialize (&problem_data->rd_bitmaps);
      bitmap_initialize (&problem_data->sparse_invalidated_by_call,
			 &problem_data->rd_bitmaps);
      bitmap_initialize (&problem_data->dense_invalidated_by_call,
			 &problem_data->rd_bitmaps);
    }

  df_grow_bb_info (df_rd);

  /* Because of the clustering of all use sites for the same pseudo,
     we have to process all of the blocks before doing the
     analysis.  */

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      struct df_rd_bb_info *bb_info = df_rd_get_bb_info (bb_index);
      
      /* When bitmaps are already initialized, just clear them.  */
      if (bb_info->kill.obstack)
	{
	  bitmap_clear (&bb_info->kill);
	  bitmap_clear (&bb_info->sparse_kill);
	  bitmap_clear (&bb_info->gen);
	}
      else
	{
	  bitmap_initialize (&bb_info->kill, &problem_data->rd_bitmaps);
	  bitmap_initialize (&bb_info->sparse_kill, &problem_data->rd_bitmaps);
	  bitmap_initialize (&bb_info->gen, &problem_data->rd_bitmaps);
	  bitmap_initialize (&bb_info->in, &problem_data->rd_bitmaps);
	  bitmap_initialize (&bb_info->out, &problem_data->rd_bitmaps);
	}
    }
  df_rd->optional_p = true;
}


/* Add the effect of the top artificial defs of BB to the reaching definitions
   bitmap LOCAL_RD.  */

void
df_rd_simulate_artificial_defs_at_top (basic_block bb, bitmap local_rd)
{
  int bb_index = bb->index;
  df_ref *def_rec;
  for (def_rec = df_get_artificial_defs (bb_index); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      if (DF_REF_FLAGS (def) & DF_REF_AT_TOP)
	{
	  unsigned int dregno = DF_REF_REGNO (def);
	  if (!(DF_REF_FLAGS (def) & (DF_REF_PARTIAL | DF_REF_CONDITIONAL)))
	    bitmap_clear_range (local_rd,
				DF_DEFS_BEGIN (dregno),
				DF_DEFS_COUNT (dregno));
	  bitmap_set_bit (local_rd, DF_REF_ID (def));
	}
    }
}

/* Add the effect of the defs of INSN to the reaching definitions bitmap
   LOCAL_RD.  */

void
df_rd_simulate_one_insn (basic_block bb ATTRIBUTE_UNUSED, rtx insn,
			 bitmap local_rd)
{
  unsigned uid = INSN_UID (insn);
  df_ref *def_rec;

  for (def_rec = DF_INSN_UID_DEFS (uid); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      unsigned int dregno = DF_REF_REGNO (def);
      if ((!(df->changeable_flags & DF_NO_HARD_REGS))
          || (dregno >= FIRST_PSEUDO_REGISTER))
        {
          if (!(DF_REF_FLAGS (def) & (DF_REF_PARTIAL | DF_REF_CONDITIONAL)))
	    bitmap_clear_range (local_rd,
				DF_DEFS_BEGIN (dregno),
				DF_DEFS_COUNT (dregno));
	  if (!(DF_REF_FLAGS (def)
		& (DF_REF_MUST_CLOBBER | DF_REF_MAY_CLOBBER)))
	    bitmap_set_bit (local_rd, DF_REF_ID (def));
	}
    }
}

/* Process a list of DEFs for df_rd_bb_local_compute.  This is a bit
   more complicated than just simulating, because we must produce the
   gen and kill sets and hence deal with the two possible representations
   of kill sets.   */

static void
df_rd_bb_local_compute_process_def (struct df_rd_bb_info *bb_info,
				    df_ref *def_rec,
				    int top_flag)
{
  while (*def_rec)
    {
      df_ref def = *def_rec;
      if (top_flag == (DF_REF_FLAGS (def) & DF_REF_AT_TOP))
	{
	  unsigned int regno = DF_REF_REGNO (def);
	  unsigned int begin = DF_DEFS_BEGIN (regno);
	  unsigned int n_defs = DF_DEFS_COUNT (regno);

	  if ((!(df->changeable_flags & DF_NO_HARD_REGS))
	      || (regno >= FIRST_PSEUDO_REGISTER))
	    {
	      /* Only the last def(s) for a regno in the block has any
		 effect.  */
	      if (!bitmap_bit_p (&seen_in_block, regno))
		{
		  /* The first def for regno in insn gets to knock out the
		     defs from other instructions.  */
		  if ((!bitmap_bit_p (&seen_in_insn, regno))
		      /* If the def is to only part of the reg, it does
			 not kill the other defs that reach here.  */
		      && (!(DF_REF_FLAGS (def) &
			    (DF_REF_PARTIAL | DF_REF_CONDITIONAL | DF_REF_MAY_CLOBBER))))
		    {
		      if (n_defs > DF_SPARSE_THRESHOLD)
			{
			  bitmap_set_bit (&bb_info->sparse_kill, regno);
			  bitmap_clear_range(&bb_info->gen, begin, n_defs);
			}
		      else
			{
			  bitmap_set_range (&bb_info->kill, begin, n_defs);
			  bitmap_clear_range (&bb_info->gen, begin, n_defs);
			}
		    }

		  bitmap_set_bit (&seen_in_insn, regno);
		  /* All defs for regno in the instruction may be put into
		     the gen set.  */
		  if (!(DF_REF_FLAGS (def)
			& (DF_REF_MUST_CLOBBER | DF_REF_MAY_CLOBBER)))
		    bitmap_set_bit (&bb_info->gen, DF_REF_ID (def));
		}
	    }
	}
      def_rec++;
    }
}

/* Compute local reaching def info for basic block BB.  */

static void
df_rd_bb_local_compute (unsigned int bb_index)
{
  basic_block bb = BASIC_BLOCK (bb_index);
  struct df_rd_bb_info *bb_info = df_rd_get_bb_info (bb_index);
  rtx insn;

  bitmap_clear (&seen_in_block);
  bitmap_clear (&seen_in_insn);

  /* Artificials are only hard regs.  */
  if (!(df->changeable_flags & DF_NO_HARD_REGS))
    df_rd_bb_local_compute_process_def (bb_info,
					df_get_artificial_defs (bb_index),
					0);

  FOR_BB_INSNS_REVERSE (bb, insn)
    {
      unsigned int uid = INSN_UID (insn);

      if (!INSN_P (insn))
	continue;

      df_rd_bb_local_compute_process_def (bb_info,
					  DF_INSN_UID_DEFS (uid), 0);

      /* This complex dance with the two bitmaps is required because
	 instructions can assign twice to the same pseudo.  This
	 generally happens with calls that will have one def for the
	 result and another def for the clobber.  If only one vector
	 is used and the clobber goes first, the result will be
	 lost.  */
      bitmap_ior_into (&seen_in_block, &seen_in_insn);
      bitmap_clear (&seen_in_insn);
    }

  /* Process the artificial defs at the top of the block last since we
     are going backwards through the block and these are logically at
     the start.  */
  if (!(df->changeable_flags & DF_NO_HARD_REGS))
    df_rd_bb_local_compute_process_def (bb_info,
					df_get_artificial_defs (bb_index),
					DF_REF_AT_TOP);
}


/* Compute local reaching def info for each basic block within BLOCKS.  */

static void
df_rd_local_compute (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;
  unsigned int regno;
  struct df_rd_problem_data *problem_data
    = (struct df_rd_problem_data *) df_rd->problem_data;
  bitmap sparse_invalidated = &problem_data->sparse_invalidated_by_call;
  bitmap dense_invalidated = &problem_data->dense_invalidated_by_call;

  bitmap_initialize (&seen_in_block, &df_bitmap_obstack);
  bitmap_initialize (&seen_in_insn, &df_bitmap_obstack);

  df_maybe_reorganize_def_refs (DF_REF_ORDER_BY_REG);

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      df_rd_bb_local_compute (bb_index);
    }

  /* Set up the knockout bit vectors to be applied across EH_EDGES.  */
  EXECUTE_IF_SET_IN_BITMAP (regs_invalidated_by_call_regset, 0, regno, bi)
    {
      if (DF_DEFS_COUNT (regno) > DF_SPARSE_THRESHOLD)
	bitmap_set_bit (sparse_invalidated, regno);
      else
	bitmap_set_range (dense_invalidated,
			  DF_DEFS_BEGIN (regno),
			  DF_DEFS_COUNT (regno));
    }

  bitmap_clear (&seen_in_block);
  bitmap_clear (&seen_in_insn);
}


/* Initialize the solution bit vectors for problem.  */

static void
df_rd_init_solution (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      struct df_rd_bb_info *bb_info = df_rd_get_bb_info (bb_index);

      bitmap_copy (&bb_info->out, &bb_info->gen);
      bitmap_clear (&bb_info->in);
    }
}

/* In of target gets or of out of source.  */

static bool
df_rd_confluence_n (edge e)
{
  bitmap op1 = &df_rd_get_bb_info (e->dest->index)->in;
  bitmap op2 = &df_rd_get_bb_info (e->src->index)->out;
  bool changed = false;

  if (e->flags & EDGE_FAKE)
    return false;

  if (e->flags & EDGE_EH)
    {
      struct df_rd_problem_data *problem_data
	= (struct df_rd_problem_data *) df_rd->problem_data;
      bitmap sparse_invalidated = &problem_data->sparse_invalidated_by_call;
      bitmap dense_invalidated = &problem_data->dense_invalidated_by_call;
      bitmap_iterator bi;
      unsigned int regno;
      bitmap_head tmp;

      bitmap_initialize (&tmp, &df_bitmap_obstack);
      bitmap_copy (&tmp, op2);
      bitmap_and_compl_into (&tmp, dense_invalidated);

      EXECUTE_IF_SET_IN_BITMAP (sparse_invalidated, 0, regno, bi)
 	{
 	  bitmap_clear_range (&tmp,
 			      DF_DEFS_BEGIN (regno),
 			      DF_DEFS_COUNT (regno));
	}
      changed |= bitmap_ior_into (op1, &tmp);
      bitmap_clear (&tmp);
      return changed;
    }
  else
    return bitmap_ior_into (op1, op2);
}


/* Transfer function.  */

static bool
df_rd_transfer_function (int bb_index)
{
  struct df_rd_bb_info *bb_info = df_rd_get_bb_info (bb_index);
  unsigned int regno;
  bitmap_iterator bi;
  bitmap in = &bb_info->in;
  bitmap out = &bb_info->out;
  bitmap gen = &bb_info->gen;
  bitmap kill = &bb_info->kill;
  bitmap sparse_kill = &bb_info->sparse_kill;

  if (bitmap_empty_p (sparse_kill))
    return  bitmap_ior_and_compl (out, gen, in, kill);
  else
    {
      struct df_rd_problem_data *problem_data;
      bool changed = false;
      bitmap_head tmp;

      /* Note that TMP is _not_ a temporary bitmap if we end up replacing
	 OUT with TMP.  Therefore, allocate TMP in the RD bitmaps obstack.  */
      problem_data = (struct df_rd_problem_data *) df_rd->problem_data;
      bitmap_initialize (&tmp, &problem_data->rd_bitmaps);

      bitmap_copy (&tmp, in);
      EXECUTE_IF_SET_IN_BITMAP (sparse_kill, 0, regno, bi)
	{
	  bitmap_clear_range (&tmp,
			      DF_DEFS_BEGIN (regno),
			      DF_DEFS_COUNT (regno));
	}
      bitmap_and_compl_into (&tmp, kill);
      bitmap_ior_into (&tmp, gen);
      changed = !bitmap_equal_p (&tmp, out);
      if (changed)
	{
	  bitmap_clear (out);
	  bb_info->out = tmp;
	}
      else
	  bitmap_clear (&tmp);
      return changed;
    }
}


/* Free all storage associated with the problem.  */

static void
df_rd_free (void)
{
  struct df_rd_problem_data *problem_data
    = (struct df_rd_problem_data *) df_rd->problem_data;

  if (problem_data)
    {
      bitmap_obstack_release (&problem_data->rd_bitmaps);

      df_rd->block_info_size = 0;
      free (df_rd->block_info);
      df_rd->block_info = NULL;
      free (df_rd->problem_data);
    }
  free (df_rd);
}


/* Debugging info.  */

static void
df_rd_start_dump (FILE *file)
{
  struct df_rd_problem_data *problem_data
    = (struct df_rd_problem_data *) df_rd->problem_data;
  unsigned int m = DF_REG_SIZE(df);
  unsigned int regno;

  if (!df_rd->block_info)
    return;

  fprintf (file, ";; Reaching defs:\n\n");

  fprintf (file, "  sparse invalidated \t");
  dump_bitmap (file, &problem_data->sparse_invalidated_by_call);
  fprintf (file, "  dense invalidated \t");
  dump_bitmap (file, &problem_data->dense_invalidated_by_call);

  for (regno = 0; regno < m; regno++)
    if (DF_DEFS_COUNT (regno))
      fprintf (file, "%d[%d,%d] ", regno,
	       DF_DEFS_BEGIN (regno),
	       DF_DEFS_COUNT (regno));
  fprintf (file, "\n");

}


/* Debugging info at top of bb.  */

static void
df_rd_top_dump (basic_block bb, FILE *file)
{
  struct df_rd_bb_info *bb_info = df_rd_get_bb_info (bb->index);
  if (!bb_info)
    return;

  fprintf (file, ";; rd  in  \t(%d)\n", (int) bitmap_count_bits (&bb_info->in));
  dump_bitmap (file, &bb_info->in);
  fprintf (file, ";; rd  gen \t(%d)\n", (int) bitmap_count_bits (&bb_info->gen));
  dump_bitmap (file, &bb_info->gen);
  fprintf (file, ";; rd  kill\t(%d)\n", (int) bitmap_count_bits (&bb_info->kill));
  dump_bitmap (file, &bb_info->kill);
}


/* Debugging info at top of bb.  */

static void
df_rd_bottom_dump (basic_block bb, FILE *file)
{
  struct df_rd_bb_info *bb_info = df_rd_get_bb_info (bb->index);
  if (!bb_info)
    return;

  fprintf (file, ";; rd  out \t(%d)\n", (int) bitmap_count_bits (&bb_info->out));
  dump_bitmap (file, &bb_info->out);
}

/* All of the information associated with every instance of the problem.  */

static struct df_problem problem_RD =
{
  DF_RD,                      /* Problem id.  */
  DF_FORWARD,                 /* Direction.  */
  df_rd_alloc,                /* Allocate the problem specific data.  */
  NULL,                       /* Reset global information.  */
  df_rd_free_bb_info,         /* Free basic block info.  */
  df_rd_local_compute,        /* Local compute function.  */
  df_rd_init_solution,        /* Init the solution specific data.  */
  df_worklist_dataflow,       /* Worklist solver.  */
  NULL,                       /* Confluence operator 0.  */
  df_rd_confluence_n,         /* Confluence operator n.  */
  df_rd_transfer_function,    /* Transfer function.  */
  NULL,                       /* Finalize function.  */
  df_rd_free,                 /* Free all of the problem information.  */
  df_rd_free,                 /* Remove this problem from the stack of dataflow problems.  */
  df_rd_start_dump,           /* Debugging.  */
  df_rd_top_dump,             /* Debugging start block.  */
  df_rd_bottom_dump,          /* Debugging end block.  */
  NULL,                       /* Incremental solution verify start.  */
  NULL,                       /* Incremental solution verify end.  */
  NULL,                       /* Dependent problem.  */
  sizeof (struct df_rd_bb_info),/* Size of entry of block_info array.  */
  TV_DF_RD,                   /* Timing variable.  */
  true                        /* Reset blocks on dropping out of blocks_to_analyze.  */
};



/* Create a new RD instance and add it to the existing instance
   of DF.  */

void
df_rd_add_problem (void)
{
  df_add_problem (&problem_RD);
}



/*----------------------------------------------------------------------------
   LIVE REGISTERS

   Find the locations in the function where any use of a pseudo can
   reach in the backwards direction.  In and out bitvectors are built
   for each basic block.  The regno is used to index into these sets.
   See df.h for details.
   ----------------------------------------------------------------------------*/

/* Private data used to verify the solution for this problem.  */
struct df_lr_problem_data
{
  bitmap_head *in;
  bitmap_head *out;
  /* An obstack for the bitmaps we need for this problem.  */
  bitmap_obstack lr_bitmaps;
};

/* Free basic block info.  */

static void
df_lr_free_bb_info (basic_block bb ATTRIBUTE_UNUSED,
		    void *vbb_info)
{
  struct df_lr_bb_info *bb_info = (struct df_lr_bb_info *) vbb_info;
  if (bb_info)
    {
      bitmap_clear (&bb_info->use);
      bitmap_clear (&bb_info->def);
      bitmap_clear (&bb_info->in);
      bitmap_clear (&bb_info->out);
    }
}


/* Allocate or reset bitmaps for DF_LR blocks. The solution bits are
   not touched unless the block is new.  */

static void
df_lr_alloc (bitmap all_blocks ATTRIBUTE_UNUSED)
{
  unsigned int bb_index;
  bitmap_iterator bi;
  struct df_lr_problem_data *problem_data;

  df_grow_bb_info (df_lr);
  if (df_lr->problem_data)
    problem_data = (struct df_lr_problem_data *) df_lr->problem_data;
  else
    {
      problem_data = XNEW (struct df_lr_problem_data);
      df_lr->problem_data = problem_data;

      problem_data->out = NULL;
      problem_data->in = NULL;
      bitmap_obstack_initialize (&problem_data->lr_bitmaps);
    }

  EXECUTE_IF_SET_IN_BITMAP (df_lr->out_of_date_transfer_functions, 0, bb_index, bi)
    {
      struct df_lr_bb_info *bb_info = df_lr_get_bb_info (bb_index);
      
      /* When bitmaps are already initialized, just clear them.  */
      if (bb_info->use.obstack)
	{
	  bitmap_clear (&bb_info->def);
	  bitmap_clear (&bb_info->use);
	}
      else
	{
	  bitmap_initialize (&bb_info->use, &problem_data->lr_bitmaps);
	  bitmap_initialize (&bb_info->def, &problem_data->lr_bitmaps);
	  bitmap_initialize (&bb_info->in, &problem_data->lr_bitmaps);
	  bitmap_initialize (&bb_info->out, &problem_data->lr_bitmaps);
	}
    }

  df_lr->optional_p = false;
}


/* Reset the global solution for recalculation.  */

static void
df_lr_reset (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      struct df_lr_bb_info *bb_info = df_lr_get_bb_info (bb_index);
      gcc_assert (bb_info);
      bitmap_clear (&bb_info->in);
      bitmap_clear (&bb_info->out);
    }
}


/* Compute local live register info for basic block BB.  */

static void
df_lr_bb_local_compute (unsigned int bb_index)
{
  basic_block bb = BASIC_BLOCK (bb_index);
  struct df_lr_bb_info *bb_info = df_lr_get_bb_info (bb_index);
  rtx insn;
  df_ref *def_rec;
  df_ref *use_rec;

  /* Process the registers set in an exception handler.  */
  for (def_rec = df_get_artificial_defs (bb_index); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      if ((DF_REF_FLAGS (def) & DF_REF_AT_TOP) == 0)
	{
	  unsigned int dregno = DF_REF_REGNO (def);
	  bitmap_set_bit (&bb_info->def, dregno);
	  bitmap_clear_bit (&bb_info->use, dregno);
	}
    }

  /* Process the hardware registers that are always live.  */
  for (use_rec = df_get_artificial_uses (bb_index); *use_rec; use_rec++)
    {
      df_ref use = *use_rec;
      /* Add use to set of uses in this BB.  */
      if ((DF_REF_FLAGS (use) & DF_REF_AT_TOP) == 0)
	bitmap_set_bit (&bb_info->use, DF_REF_REGNO (use));
    }

  FOR_BB_INSNS_REVERSE (bb, insn)
    {
      unsigned int uid = INSN_UID (insn);

      if (!NONDEBUG_INSN_P (insn))
	continue;

      for (def_rec = DF_INSN_UID_DEFS (uid); *def_rec; def_rec++)
	{
	  df_ref def = *def_rec;
	  /* If the def is to only part of the reg, it does
	     not kill the other defs that reach here.  */
	  if (!(DF_REF_FLAGS (def) & (DF_REF_PARTIAL | DF_REF_CONDITIONAL)))
	    {
	      unsigned int dregno = DF_REF_REGNO (def);
	      bitmap_set_bit (&bb_info->def, dregno);
	      bitmap_clear_bit (&bb_info->use, dregno);
	    }
	}

      for (use_rec = DF_INSN_UID_USES (uid); *use_rec; use_rec++)
	{
	  df_ref use = *use_rec;
	  /* Add use to set of uses in this BB.  */
	  bitmap_set_bit (&bb_info->use, DF_REF_REGNO (use));
	}
    }

  /* Process the registers set in an exception handler or the hard
     frame pointer if this block is the target of a non local
     goto.  */
  for (def_rec = df_get_artificial_defs (bb_index); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      if (DF_REF_FLAGS (def) & DF_REF_AT_TOP)
	{
	  unsigned int dregno = DF_REF_REGNO (def);
	  bitmap_set_bit (&bb_info->def, dregno);
	  bitmap_clear_bit (&bb_info->use, dregno);
	}
    }

#ifdef EH_USES
  /* Process the uses that are live into an exception handler.  */
  for (use_rec = df_get_artificial_uses (bb_index); *use_rec; use_rec++)
    {
      df_ref use = *use_rec;
      /* Add use to set of uses in this BB.  */
      if (DF_REF_FLAGS (use) & DF_REF_AT_TOP)
	bitmap_set_bit (&bb_info->use, DF_REF_REGNO (use));
    }
#endif

  /* If the df_live problem is not defined, such as at -O0 and -O1, we
     still need to keep the luids up to date.  This is normally done
     in the df_live problem since this problem has a forwards
     scan.  */
  if (!df_live)
    df_recompute_luids (bb);
}


/* Compute local live register info for each basic block within BLOCKS.  */

static void
df_lr_local_compute (bitmap all_blocks ATTRIBUTE_UNUSED)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  bitmap_clear (&df->hardware_regs_used);

  /* The all-important stack pointer must always be live.  */
  bitmap_set_bit (&df->hardware_regs_used, STACK_POINTER_REGNUM);

  /* Before reload, there are a few registers that must be forced
     live everywhere -- which might not already be the case for
     blocks within infinite loops.  */
  if (!reload_completed)
    {
      unsigned int pic_offset_table_regnum = PIC_OFFSET_TABLE_REGNUM;
      /* Any reference to any pseudo before reload is a potential
	 reference of the frame pointer.  */
      bitmap_set_bit (&df->hardware_regs_used, FRAME_POINTER_REGNUM);

#if FRAME_POINTER_REGNUM != ARG_POINTER_REGNUM
      /* Pseudos with argument area equivalences may require
	 reloading via the argument pointer.  */
      if (fixed_regs[ARG_POINTER_REGNUM])
	bitmap_set_bit (&df->hardware_regs_used, ARG_POINTER_REGNUM);
#endif

      /* Any constant, or pseudo with constant equivalences, may
	 require reloading from memory using the pic register.  */
      if (pic_offset_table_regnum != INVALID_REGNUM
	  && fixed_regs[pic_offset_table_regnum])
	bitmap_set_bit (&df->hardware_regs_used, pic_offset_table_regnum);
    }

  EXECUTE_IF_SET_IN_BITMAP (df_lr->out_of_date_transfer_functions, 0, bb_index, bi)
    {
      if (bb_index == EXIT_BLOCK)
	{
	  /* The exit block is special for this problem and its bits are
	     computed from thin air.  */
	  struct df_lr_bb_info *bb_info = df_lr_get_bb_info (EXIT_BLOCK);
	  bitmap_copy (&bb_info->use, df->exit_block_uses);
	}
      else
	df_lr_bb_local_compute (bb_index);
    }

  bitmap_clear (df_lr->out_of_date_transfer_functions);
}


/* Initialize the solution vectors.  */

static void
df_lr_init (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      struct df_lr_bb_info *bb_info = df_lr_get_bb_info (bb_index);
      bitmap_copy (&bb_info->in, &bb_info->use);
      bitmap_clear (&bb_info->out);
    }
}


/* Confluence function that processes infinite loops.  This might be a
   noreturn function that throws.  And even if it isn't, getting the
   unwind info right helps debugging.  */
static void
df_lr_confluence_0 (basic_block bb)
{
  bitmap op1 = &df_lr_get_bb_info (bb->index)->out;
  if (bb != EXIT_BLOCK_PTR)
    bitmap_copy (op1, &df->hardware_regs_used);
}


/* Confluence function that ignores fake edges.  */

static bool
df_lr_confluence_n (edge e)
{
  bitmap op1 = &df_lr_get_bb_info (e->src->index)->out;
  bitmap op2 = &df_lr_get_bb_info (e->dest->index)->in;
  bool changed = false;

  /* Call-clobbered registers die across exception and call edges.  */
  /* ??? Abnormal call edges ignored for the moment, as this gets
     confused by sibling call edges, which crashes reg-stack.  */
  if (e->flags & EDGE_EH)
    changed = bitmap_ior_and_compl_into (op1, op2, regs_invalidated_by_call_regset);
  else
    changed = bitmap_ior_into (op1, op2);

  changed |= bitmap_ior_into (op1, &df->hardware_regs_used);
  return changed;
}


/* Transfer function.  */

static bool
df_lr_transfer_function (int bb_index)
{
  struct df_lr_bb_info *bb_info = df_lr_get_bb_info (bb_index);
  bitmap in = &bb_info->in;
  bitmap out = &bb_info->out;
  bitmap use = &bb_info->use;
  bitmap def = &bb_info->def;

  return bitmap_ior_and_compl (in, use, out, def);
}


/* Run the fast dce as a side effect of building LR.  */

static void
df_lr_finalize (bitmap all_blocks)
{
  df_lr->solutions_dirty = false;
  if (df->changeable_flags & DF_LR_RUN_DCE)
    {
      run_fast_df_dce ();

      /* If dce deletes some instructions, we need to recompute the lr
	 solution before proceeding further.  The problem is that fast
	 dce is a pessimestic dataflow algorithm.  In the case where
	 it deletes a statement S inside of a loop, the uses inside of
	 S may not be deleted from the dataflow solution because they
	 were carried around the loop.  While it is conservatively
	 correct to leave these extra bits, the standards of df
	 require that we maintain the best possible (least fixed
	 point) solution.  The only way to do that is to redo the
	 iteration from the beginning.  See PR35805 for an
	 example.  */
      if (df_lr->solutions_dirty)
	{
	  df_clear_flags (DF_LR_RUN_DCE);
	  df_lr_alloc (all_blocks);
	  df_lr_local_compute (all_blocks);
	  df_worklist_dataflow (df_lr, all_blocks, df->postorder, df->n_blocks);
	  df_lr_finalize (all_blocks);
	  df_set_flags (DF_LR_RUN_DCE);
	}
    }
}


/* Free all storage associated with the problem.  */

static void
df_lr_free (void)
{
  struct df_lr_problem_data *problem_data
    = (struct df_lr_problem_data *) df_lr->problem_data;
  if (df_lr->block_info)
    {

      df_lr->block_info_size = 0;
      free (df_lr->block_info);
      df_lr->block_info = NULL;
      bitmap_obstack_release (&problem_data->lr_bitmaps);
      free (df_lr->problem_data);
      df_lr->problem_data = NULL;
    }

  BITMAP_FREE (df_lr->out_of_date_transfer_functions);
  free (df_lr);
}


/* Debugging info at top of bb.  */

static void
df_lr_top_dump (basic_block bb, FILE *file)
{
  struct df_lr_bb_info *bb_info = df_lr_get_bb_info (bb->index);
  struct df_lr_problem_data *problem_data;
  if (!bb_info)
    return;

  fprintf (file, ";; lr  in  \t");
  df_print_regset (file, &bb_info->in);
  if (df_lr->problem_data)
    {
      problem_data = (struct df_lr_problem_data *)df_lr->problem_data;
      if (problem_data->in)
	{
      	  fprintf (file, ";;  old in  \t");
      	  df_print_regset (file, &problem_data->in[bb->index]);
	}
    }
  fprintf (file, ";; lr  use \t");
  df_print_regset (file, &bb_info->use);
  fprintf (file, ";; lr  def \t");
  df_print_regset (file, &bb_info->def);
}


/* Debugging info at bottom of bb.  */

static void
df_lr_bottom_dump (basic_block bb, FILE *file)
{
  struct df_lr_bb_info *bb_info = df_lr_get_bb_info (bb->index);
  struct df_lr_problem_data *problem_data;
  if (!bb_info)
    return;

  fprintf (file, ";; lr  out \t");
  df_print_regset (file, &bb_info->out);
  if (df_lr->problem_data)
    {
      problem_data = (struct df_lr_problem_data *)df_lr->problem_data;
      if (problem_data->out)
	{
          fprintf (file, ";;  old out  \t");
          df_print_regset (file, &problem_data->out[bb->index]);
	}
    }
}


/* Build the datastructure to verify that the solution to the dataflow
   equations is not dirty.  */

static void
df_lr_verify_solution_start (void)
{
  basic_block bb;
  struct df_lr_problem_data *problem_data;
  if (df_lr->solutions_dirty)
    return;

  /* Set it true so that the solution is recomputed.  */
  df_lr->solutions_dirty = true;

  problem_data = (struct df_lr_problem_data *)df_lr->problem_data;
  problem_data->in = XNEWVEC (bitmap_head, last_basic_block);
  problem_data->out = XNEWVEC (bitmap_head, last_basic_block);

  FOR_ALL_BB (bb)
    {
      bitmap_initialize (&problem_data->in[bb->index], &problem_data->lr_bitmaps);
      bitmap_initialize (&problem_data->out[bb->index], &problem_data->lr_bitmaps);
      bitmap_copy (&problem_data->in[bb->index], DF_LR_IN (bb));
      bitmap_copy (&problem_data->out[bb->index], DF_LR_OUT (bb));
    }
}


/* Compare the saved datastructure and the new solution to the dataflow
   equations.  */

static void
df_lr_verify_solution_end (void)
{
  struct df_lr_problem_data *problem_data;
  basic_block bb;

  problem_data = (struct df_lr_problem_data *)df_lr->problem_data;

  if (!problem_data->out)
    return;

  if (df_lr->solutions_dirty)
    /* Do not check if the solution is still dirty.  See the comment
       in df_lr_finalize for details.  */
    df_lr->solutions_dirty = false;
  else
    FOR_ALL_BB (bb)
      {
	if ((!bitmap_equal_p (&problem_data->in[bb->index], DF_LR_IN (bb)))
	    || (!bitmap_equal_p (&problem_data->out[bb->index], DF_LR_OUT (bb))))
	  {
	    /*df_dump (stderr);*/
	    gcc_unreachable ();
	  }
      }

  /* Cannot delete them immediately because you may want to dump them
     if the comparison fails.  */
  FOR_ALL_BB (bb)
    {
      bitmap_clear (&problem_data->in[bb->index]);
      bitmap_clear (&problem_data->out[bb->index]);
    }

  free (problem_data->in);
  free (problem_data->out);
  problem_data->in = NULL;
  problem_data->out = NULL;
}


/* All of the information associated with every instance of the problem.  */

static struct df_problem problem_LR =
{
  DF_LR,                      /* Problem id.  */
  DF_BACKWARD,                /* Direction.  */
  df_lr_alloc,                /* Allocate the problem specific data.  */
  df_lr_reset,                /* Reset global information.  */
  df_lr_free_bb_info,         /* Free basic block info.  */
  df_lr_local_compute,        /* Local compute function.  */
  df_lr_init,                 /* Init the solution specific data.  */
  df_worklist_dataflow,       /* Worklist solver.  */
  df_lr_confluence_0,         /* Confluence operator 0.  */
  df_lr_confluence_n,         /* Confluence operator n.  */
  df_lr_transfer_function,    /* Transfer function.  */
  df_lr_finalize,             /* Finalize function.  */
  df_lr_free,                 /* Free all of the problem information.  */
  NULL,                       /* Remove this problem from the stack of dataflow problems.  */
  NULL,                       /* Debugging.  */
  df_lr_top_dump,             /* Debugging start block.  */
  df_lr_bottom_dump,          /* Debugging end block.  */
  df_lr_verify_solution_start,/* Incremental solution verify start.  */
  df_lr_verify_solution_end,  /* Incremental solution verify end.  */
  NULL,                       /* Dependent problem.  */
  sizeof (struct df_lr_bb_info),/* Size of entry of block_info array.  */
  TV_DF_LR,                   /* Timing variable.  */
  false                       /* Reset blocks on dropping out of blocks_to_analyze.  */
};


/* Create a new DATAFLOW instance and add it to an existing instance
   of DF.  The returned structure is what is used to get at the
   solution.  */

void
df_lr_add_problem (void)
{
  df_add_problem (&problem_LR);
  /* These will be initialized when df_scan_blocks processes each
     block.  */
  df_lr->out_of_date_transfer_functions = BITMAP_ALLOC (NULL);
}


/* Verify that all of the lr related info is consistent and
   correct.  */

void
df_lr_verify_transfer_functions (void)
{
  basic_block bb;
  bitmap_head saved_def;
  bitmap_head saved_use;
  bitmap_head all_blocks;

  if (!df)
    return;

  bitmap_initialize (&saved_def, &bitmap_default_obstack); 
  bitmap_initialize (&saved_use, &bitmap_default_obstack);
  bitmap_initialize (&all_blocks, &bitmap_default_obstack);

  FOR_ALL_BB (bb)
    {
      struct df_lr_bb_info *bb_info = df_lr_get_bb_info (bb->index);
      bitmap_set_bit (&all_blocks, bb->index);

      if (bb_info)
	{
	  /* Make a copy of the transfer functions and then compute
	     new ones to see if the transfer functions have
	     changed.  */
	  if (!bitmap_bit_p (df_lr->out_of_date_transfer_functions,
			     bb->index))
	    {
	      bitmap_copy (&saved_def, &bb_info->def);
	      bitmap_copy (&saved_use, &bb_info->use);
	      bitmap_clear (&bb_info->def);
	      bitmap_clear (&bb_info->use);

	      df_lr_bb_local_compute (bb->index);
	      gcc_assert (bitmap_equal_p (&saved_def, &bb_info->def));
	      gcc_assert (bitmap_equal_p (&saved_use, &bb_info->use));
	    }
	}
      else
	{
	  /* If we do not have basic block info, the block must be in
	     the list of dirty blocks or else some one has added a
	     block behind our backs. */
	  gcc_assert (bitmap_bit_p (df_lr->out_of_date_transfer_functions,
				    bb->index));
	}
      /* Make sure no one created a block without following
	 procedures.  */
      gcc_assert (df_scan_get_bb_info (bb->index));
    }

  /* Make sure there are no dirty bits in blocks that have been deleted.  */
  gcc_assert (!bitmap_intersect_compl_p (df_lr->out_of_date_transfer_functions,
					 &all_blocks));

  bitmap_clear (&saved_def);
  bitmap_clear (&saved_use);
  bitmap_clear (&all_blocks);
}



/*----------------------------------------------------------------------------
   LIVE AND MUST-INITIALIZED REGISTERS.

   This problem first computes the IN and OUT bitvectors for the
   must-initialized registers problems, which is a forward problem.
   It gives the set of registers for which we MUST have an available
   definition on any path from the entry block to the entry/exit of
   a basic block.  Sets generate a definition, while clobbers kill
   a definition.

   In and out bitvectors are built for each basic block and are indexed by
   regnum (see df.h for details).  In and out bitvectors in struct
   df_live_bb_info actually refers to the must-initialized problem;

   Then, the in and out sets for the LIVE problem itself are computed.
   These are the logical AND of the IN and OUT sets from the LR problem
   and the must-initialized problem.
----------------------------------------------------------------------------*/

/* Private data used to verify the solution for this problem.  */
struct df_live_problem_data
{
  bitmap_head *in;
  bitmap_head *out;
  /* An obstack for the bitmaps we need for this problem.  */
  bitmap_obstack live_bitmaps;
};

/* Scratch var used by transfer functions.  This is used to implement
   an optimization to reduce the amount of space used to compute the
   combined lr and live analysis.  */
static bitmap_head df_live_scratch;


/* Free basic block info.  */

static void
df_live_free_bb_info (basic_block bb ATTRIBUTE_UNUSED,
		    void *vbb_info)
{
  struct df_live_bb_info *bb_info = (struct df_live_bb_info *) vbb_info;
  if (bb_info)
    {
      bitmap_clear (&bb_info->gen);
      bitmap_clear (&bb_info->kill);
      bitmap_clear (&bb_info->in);
      bitmap_clear (&bb_info->out);
    }
}


/* Allocate or reset bitmaps for DF_LIVE blocks. The solution bits are
   not touched unless the block is new.  */

static void
df_live_alloc (bitmap all_blocks ATTRIBUTE_UNUSED)
{
  unsigned int bb_index;
  bitmap_iterator bi;
  struct df_live_problem_data *problem_data;

  if (df_live->problem_data)
    problem_data = (struct df_live_problem_data *) df_live->problem_data;
  else
    {
      problem_data = XNEW (struct df_live_problem_data);
      df_live->problem_data = problem_data;

      problem_data->out = NULL;
      problem_data->in = NULL;
      bitmap_obstack_initialize (&problem_data->live_bitmaps);
      bitmap_initialize (&df_live_scratch, &problem_data->live_bitmaps);
    }

  df_grow_bb_info (df_live);

  EXECUTE_IF_SET_IN_BITMAP (df_live->out_of_date_transfer_functions, 0, bb_index, bi)
    {
      struct df_live_bb_info *bb_info = df_live_get_bb_info (bb_index);
      
      /* When bitmaps are already initialized, just clear them.  */
      if (bb_info->kill.obstack)
	{
	  bitmap_clear (&bb_info->kill);
	  bitmap_clear (&bb_info->gen);
	}
      else
	{
	  bitmap_initialize (&bb_info->kill, &problem_data->live_bitmaps);
	  bitmap_initialize (&bb_info->gen, &problem_data->live_bitmaps);
	  bitmap_initialize (&bb_info->in, &problem_data->live_bitmaps);
	  bitmap_initialize (&bb_info->out, &problem_data->live_bitmaps);
	}
    }
  df_live->optional_p = (optimize <= 1);
}


/* Reset the global solution for recalculation.  */

static void
df_live_reset (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      struct df_live_bb_info *bb_info = df_live_get_bb_info (bb_index);
      gcc_assert (bb_info);
      bitmap_clear (&bb_info->in);
      bitmap_clear (&bb_info->out);
    }
}


/* Compute local uninitialized register info for basic block BB.  */

static void
df_live_bb_local_compute (unsigned int bb_index)
{
  basic_block bb = BASIC_BLOCK (bb_index);
  struct df_live_bb_info *bb_info = df_live_get_bb_info (bb_index);
  rtx insn;
  df_ref *def_rec;
  int luid = 0;

  FOR_BB_INSNS (bb, insn)
    {
      unsigned int uid = INSN_UID (insn);
      struct df_insn_info *insn_info = DF_INSN_UID_GET (uid);

      /* Inserting labels does not always trigger the incremental
	 rescanning.  */
      if (!insn_info)
	{
	  gcc_assert (!INSN_P (insn));
	  insn_info = df_insn_create_insn_record (insn);
	}

      DF_INSN_INFO_LUID (insn_info) = luid;
      if (!INSN_P (insn))
	continue;

      luid++;
      for (def_rec = DF_INSN_INFO_DEFS (insn_info); *def_rec; def_rec++)
	{
	  df_ref def = *def_rec;
	  unsigned int regno = DF_REF_REGNO (def);

	  if (DF_REF_FLAGS_IS_SET (def,
				   DF_REF_PARTIAL | DF_REF_CONDITIONAL))
	    /* All partial or conditional def
	       seen are included in the gen set. */
	    bitmap_set_bit (&bb_info->gen, regno);
	  else if (DF_REF_FLAGS_IS_SET (def, DF_REF_MUST_CLOBBER))
	    /* Only must clobbers for the entire reg destroy the
	       value.  */
	    bitmap_set_bit (&bb_info->kill, regno);
	  else if (! DF_REF_FLAGS_IS_SET (def, DF_REF_MAY_CLOBBER))
	    bitmap_set_bit (&bb_info->gen, regno);
	}
    }

  for (def_rec = df_get_artificial_defs (bb_index); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      bitmap_set_bit (&bb_info->gen, DF_REF_REGNO (def));
    }
}


/* Compute local uninitialized register info.  */

static void
df_live_local_compute (bitmap all_blocks ATTRIBUTE_UNUSED)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  df_grow_insn_info ();

  EXECUTE_IF_SET_IN_BITMAP (df_live->out_of_date_transfer_functions,
			    0, bb_index, bi)
    {
      df_live_bb_local_compute (bb_index);
    }

  bitmap_clear (df_live->out_of_date_transfer_functions);
}


/* Initialize the solution vectors.  */

static void
df_live_init (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      struct df_live_bb_info *bb_info = df_live_get_bb_info (bb_index);
      struct df_lr_bb_info *bb_lr_info = df_lr_get_bb_info (bb_index);

      /* No register may reach a location where it is not used.  Thus
	 we trim the rr result to the places where it is used.  */
      bitmap_and (&bb_info->out, &bb_info->gen, &bb_lr_info->out);
      bitmap_clear (&bb_info->in);
    }
}

/* Forward confluence function that ignores fake edges.  */

static bool
df_live_confluence_n (edge e)
{
  bitmap op1 = &df_live_get_bb_info (e->dest->index)->in;
  bitmap op2 = &df_live_get_bb_info (e->src->index)->out;

  if (e->flags & EDGE_FAKE)
    return false;

  return bitmap_ior_into (op1, op2);
}


/* Transfer function for the forwards must-initialized problem.  */

static bool
df_live_transfer_function (int bb_index)
{
  struct df_live_bb_info *bb_info = df_live_get_bb_info (bb_index);
  struct df_lr_bb_info *bb_lr_info = df_lr_get_bb_info (bb_index);
  bitmap in = &bb_info->in;
  bitmap out = &bb_info->out;
  bitmap gen = &bb_info->gen;
  bitmap kill = &bb_info->kill;

  /* We need to use a scratch set here so that the value returned from this
     function invocation properly reflects whether the sets changed in a
     significant way; i.e. not just because the lr set was anded in.  */
  bitmap_and (&df_live_scratch, gen, &bb_lr_info->out);
  /* No register may reach a location where it is not used.  Thus
     we trim the rr result to the places where it is used.  */
  bitmap_and_into (in, &bb_lr_info->in);

  return bitmap_ior_and_compl (out, &df_live_scratch, in, kill);
}


/* And the LR info with the must-initialized registers, to produce the LIVE info.  */

static void
df_live_finalize (bitmap all_blocks)
{

  if (df_live->solutions_dirty)
    {
      bitmap_iterator bi;
      unsigned int bb_index;

      EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
	{
	  struct df_lr_bb_info *bb_lr_info = df_lr_get_bb_info (bb_index);
	  struct df_live_bb_info *bb_live_info = df_live_get_bb_info (bb_index);

	  /* No register may reach a location where it is not used.  Thus
	     we trim the rr result to the places where it is used.  */
	  bitmap_and_into (&bb_live_info->in, &bb_lr_info->in);
	  bitmap_and_into (&bb_live_info->out, &bb_lr_info->out);
	}

      df_live->solutions_dirty = false;
    }
}


/* Free all storage associated with the problem.  */

static void
df_live_free (void)
{
  struct df_live_problem_data *problem_data
    = (struct df_live_problem_data *) df_live->problem_data;
  if (df_live->block_info)
    {
      df_live->block_info_size = 0;
      free (df_live->block_info);
      df_live->block_info = NULL;
      bitmap_clear (&df_live_scratch);
      bitmap_obstack_release (&problem_data->live_bitmaps);
      free (problem_data);
      df_live->problem_data = NULL;
    }
  BITMAP_FREE (df_live->out_of_date_transfer_functions);
  free (df_live);
}


/* Debugging info at top of bb.  */

static void
df_live_top_dump (basic_block bb, FILE *file)
{
  struct df_live_bb_info *bb_info = df_live_get_bb_info (bb->index);
  struct df_live_problem_data *problem_data;

  if (!bb_info)
    return;

  fprintf (file, ";; live  in  \t");
  df_print_regset (file, &bb_info->in);
  if (df_live->problem_data)
    {
      problem_data = (struct df_live_problem_data *)df_live->problem_data;
      if (problem_data->in)
	{
	  fprintf (file, ";;  old in  \t");
	  df_print_regset (file, &problem_data->in[bb->index]);
	}
    }
  fprintf (file, ";; live  gen \t");
  df_print_regset (file, &bb_info->gen);
  fprintf (file, ";; live  kill\t");
  df_print_regset (file, &bb_info->kill);
}


/* Debugging info at bottom of bb.  */

static void
df_live_bottom_dump (basic_block bb, FILE *file)
{
  struct df_live_bb_info *bb_info = df_live_get_bb_info (bb->index);
  struct df_live_problem_data *problem_data;

  if (!bb_info)
    return;

  fprintf (file, ";; live  out \t");
  df_print_regset (file, &bb_info->out);
  if (df_live->problem_data)
    {
      problem_data = (struct df_live_problem_data *)df_live->problem_data;
      if (problem_data->out)
	{
	  fprintf (file, ";;  old out  \t");
	  df_print_regset (file, &problem_data->out[bb->index]);
	}
    }
}


/* Build the datastructure to verify that the solution to the dataflow
   equations is not dirty.  */

static void
df_live_verify_solution_start (void)
{
  basic_block bb;
  struct df_live_problem_data *problem_data;
  if (df_live->solutions_dirty)
    return;

  /* Set it true so that the solution is recomputed.  */
  df_live->solutions_dirty = true;

  problem_data = (struct df_live_problem_data *)df_live->problem_data;
  problem_data->in = XNEWVEC (bitmap_head, last_basic_block);
  problem_data->out = XNEWVEC (bitmap_head, last_basic_block);

  FOR_ALL_BB (bb)
    {
      bitmap_initialize (&problem_data->in[bb->index], &problem_data->live_bitmaps);
      bitmap_initialize (&problem_data->out[bb->index], &problem_data->live_bitmaps);
      bitmap_copy (&problem_data->in[bb->index], DF_LIVE_IN (bb));
      bitmap_copy (&problem_data->out[bb->index], DF_LIVE_OUT (bb));
    }
}


/* Compare the saved datastructure and the new solution to the dataflow
   equations.  */

static void
df_live_verify_solution_end (void)
{
  struct df_live_problem_data *problem_data;
  basic_block bb;

  problem_data = (struct df_live_problem_data *)df_live->problem_data;
  if (!problem_data->out)
    return;

  FOR_ALL_BB (bb)
    {
      if ((!bitmap_equal_p (&problem_data->in[bb->index], DF_LIVE_IN (bb)))
	  || (!bitmap_equal_p (&problem_data->out[bb->index], DF_LIVE_OUT (bb))))
	{
	  /*df_dump (stderr);*/
	  gcc_unreachable ();
	}
    }

  /* Cannot delete them immediately because you may want to dump them
     if the comparison fails.  */
  FOR_ALL_BB (bb)
    {
      bitmap_clear (&problem_data->in[bb->index]);
      bitmap_clear (&problem_data->out[bb->index]);
    }

  free (problem_data->in);
  free (problem_data->out);
  free (problem_data);
  df_live->problem_data = NULL;
}


/* All of the information associated with every instance of the problem.  */

static struct df_problem problem_LIVE =
{
  DF_LIVE,                      /* Problem id.  */
  DF_FORWARD,                   /* Direction.  */
  df_live_alloc,                /* Allocate the problem specific data.  */
  df_live_reset,                /* Reset global information.  */
  df_live_free_bb_info,         /* Free basic block info.  */
  df_live_local_compute,        /* Local compute function.  */
  df_live_init,                 /* Init the solution specific data.  */
  df_worklist_dataflow,         /* Worklist solver.  */
  NULL,                         /* Confluence operator 0.  */
  df_live_confluence_n,         /* Confluence operator n.  */
  df_live_transfer_function,    /* Transfer function.  */
  df_live_finalize,             /* Finalize function.  */
  df_live_free,                 /* Free all of the problem information.  */
  df_live_free,                 /* Remove this problem from the stack of dataflow problems.  */
  NULL,                         /* Debugging.  */
  df_live_top_dump,             /* Debugging start block.  */
  df_live_bottom_dump,          /* Debugging end block.  */
  df_live_verify_solution_start,/* Incremental solution verify start.  */
  df_live_verify_solution_end,  /* Incremental solution verify end.  */
  &problem_LR,                  /* Dependent problem.  */
  sizeof (struct df_live_bb_info),/* Size of entry of block_info array.  */
  TV_DF_LIVE,                   /* Timing variable.  */
  false                         /* Reset blocks on dropping out of blocks_to_analyze.  */
};


/* Create a new DATAFLOW instance and add it to an existing instance
   of DF.  The returned structure is what is used to get at the
   solution.  */

void
df_live_add_problem (void)
{
  df_add_problem (&problem_LIVE);
  /* These will be initialized when df_scan_blocks processes each
     block.  */
  df_live->out_of_date_transfer_functions = BITMAP_ALLOC (NULL);
}


/* Set all of the blocks as dirty.  This needs to be done if this
   problem is added after all of the insns have been scanned.  */

void
df_live_set_all_dirty (void)
{
  basic_block bb;
  FOR_ALL_BB (bb)
    bitmap_set_bit (df_live->out_of_date_transfer_functions,
		    bb->index);
}


/* Verify that all of the lr related info is consistent and
   correct.  */

void
df_live_verify_transfer_functions (void)
{
  basic_block bb;
  bitmap_head saved_gen;
  bitmap_head saved_kill;
  bitmap_head all_blocks;

  if (!df)
    return;

  bitmap_initialize (&saved_gen, &bitmap_default_obstack);
  bitmap_initialize (&saved_kill, &bitmap_default_obstack);
  bitmap_initialize (&all_blocks, &bitmap_default_obstack);

  df_grow_insn_info ();

  FOR_ALL_BB (bb)
    {
      struct df_live_bb_info *bb_info = df_live_get_bb_info (bb->index);
      bitmap_set_bit (&all_blocks, bb->index);

      if (bb_info)
	{
	  /* Make a copy of the transfer functions and then compute
	     new ones to see if the transfer functions have
	     changed.  */
	  if (!bitmap_bit_p (df_live->out_of_date_transfer_functions,
			     bb->index))
	    {
	      bitmap_copy (&saved_gen, &bb_info->gen);
	      bitmap_copy (&saved_kill, &bb_info->kill);
	      bitmap_clear (&bb_info->gen);
	      bitmap_clear (&bb_info->kill);

	      df_live_bb_local_compute (bb->index);
	      gcc_assert (bitmap_equal_p (&saved_gen, &bb_info->gen));
	      gcc_assert (bitmap_equal_p (&saved_kill, &bb_info->kill));
	    }
	}
      else
	{
	  /* If we do not have basic block info, the block must be in
	     the list of dirty blocks or else some one has added a
	     block behind our backs. */
	  gcc_assert (bitmap_bit_p (df_live->out_of_date_transfer_functions,
				    bb->index));
	}
      /* Make sure no one created a block without following
	 procedures.  */
      gcc_assert (df_scan_get_bb_info (bb->index));
    }

  /* Make sure there are no dirty bits in blocks that have been deleted.  */
  gcc_assert (!bitmap_intersect_compl_p (df_live->out_of_date_transfer_functions,
					 &all_blocks));
  bitmap_clear (&saved_gen);
  bitmap_clear (&saved_kill);
  bitmap_clear (&all_blocks);
}

/*----------------------------------------------------------------------------
   CREATE DEF_USE (DU) and / or USE_DEF (UD) CHAINS

   Link either the defs to the uses and / or the uses to the defs.

   These problems are set up like the other dataflow problems so that
   they nicely fit into the framework.  They are much simpler and only
   involve a single traversal of instructions and an examination of
   the reaching defs information (the dependent problem).
----------------------------------------------------------------------------*/

#define df_chain_problem_p(FLAG) (((enum df_chain_flags)df_chain->local_flags)&(FLAG))

/* Create a du or ud chain from SRC to DST and link it into SRC.   */

struct df_link *
df_chain_create (df_ref src, df_ref dst)
{
  struct df_link *head = DF_REF_CHAIN (src);
  struct df_link *link = (struct df_link *) pool_alloc (df_chain->block_pool);

  DF_REF_CHAIN (src) = link;
  link->next = head;
  link->ref = dst;
  return link;
}


/* Delete any du or ud chains that start at REF and point to
   TARGET.  */
static void
df_chain_unlink_1 (df_ref ref, df_ref target)
{
  struct df_link *chain = DF_REF_CHAIN (ref);
  struct df_link *prev = NULL;

  while (chain)
    {
      if (chain->ref == target)
	{
	  if (prev)
	    prev->next = chain->next;
	  else
	    DF_REF_CHAIN (ref) = chain->next;
	  pool_free (df_chain->block_pool, chain);
	  return;
	}
      prev = chain;
      chain = chain->next;
    }
}


/* Delete a du or ud chain that leave or point to REF.  */

void
df_chain_unlink (df_ref ref)
{
  struct df_link *chain = DF_REF_CHAIN (ref);
  while (chain)
    {
      struct df_link *next = chain->next;
      /* Delete the other side if it exists.  */
      df_chain_unlink_1 (chain->ref, ref);
      pool_free (df_chain->block_pool, chain);
      chain = next;
    }
  DF_REF_CHAIN (ref) = NULL;
}


/* Copy the du or ud chain starting at FROM_REF and attach it to
   TO_REF.  */

void
df_chain_copy (df_ref to_ref,
	       struct df_link *from_ref)
{
  while (from_ref)
    {
      df_chain_create (to_ref, from_ref->ref);
      from_ref = from_ref->next;
    }
}


/* Remove this problem from the stack of dataflow problems.  */

static void
df_chain_remove_problem (void)
{
  bitmap_iterator bi;
  unsigned int bb_index;

  /* Wholesale destruction of the old chains.  */
  if (df_chain->block_pool)
    free_alloc_pool (df_chain->block_pool);

  EXECUTE_IF_SET_IN_BITMAP (df_chain->out_of_date_transfer_functions, 0, bb_index, bi)
    {
      rtx insn;
      df_ref *def_rec;
      df_ref *use_rec;
      basic_block bb = BASIC_BLOCK (bb_index);

      if (df_chain_problem_p (DF_DU_CHAIN))
	for (def_rec = df_get_artificial_defs (bb->index); *def_rec; def_rec++)
	  DF_REF_CHAIN (*def_rec) = NULL;
      if (df_chain_problem_p (DF_UD_CHAIN))
	for (use_rec = df_get_artificial_uses (bb->index); *use_rec; use_rec++)
	  DF_REF_CHAIN (*use_rec) = NULL;

      FOR_BB_INSNS (bb, insn)
	{
	  unsigned int uid = INSN_UID (insn);

	  if (INSN_P (insn))
	    {
	      if (df_chain_problem_p (DF_DU_CHAIN))
		for (def_rec = DF_INSN_UID_DEFS (uid); *def_rec; def_rec++)
		  DF_REF_CHAIN (*def_rec) = NULL;
	      if (df_chain_problem_p (DF_UD_CHAIN))
		{
		  for (use_rec = DF_INSN_UID_USES (uid); *use_rec; use_rec++)
		    DF_REF_CHAIN (*use_rec) = NULL;
		  for (use_rec = DF_INSN_UID_EQ_USES (uid); *use_rec; use_rec++)
		    DF_REF_CHAIN (*use_rec) = NULL;
		}
	    }
	}
    }

  bitmap_clear (df_chain->out_of_date_transfer_functions);
  df_chain->block_pool = NULL;
}


/* Remove the chain problem completely.  */

static void
df_chain_fully_remove_problem (void)
{
  df_chain_remove_problem ();
  BITMAP_FREE (df_chain->out_of_date_transfer_functions);
  free (df_chain);
}


/* Create def-use or use-def chains.  */

static void
df_chain_alloc (bitmap all_blocks ATTRIBUTE_UNUSED)
{
  df_chain_remove_problem ();
  df_chain->block_pool = create_alloc_pool ("df_chain_block pool",
					 sizeof (struct df_link), 50);
  df_chain->optional_p = true;
}


/* Reset all of the chains when the set of basic blocks changes.  */

static void
df_chain_reset (bitmap blocks_to_clear ATTRIBUTE_UNUSED)
{
  df_chain_remove_problem ();
}


/* Create the chains for a list of USEs.  */

static void
df_chain_create_bb_process_use (bitmap local_rd,
				df_ref *use_rec,
				int top_flag)
{
  bitmap_iterator bi;
  unsigned int def_index;

  while (*use_rec)
    {
      df_ref use = *use_rec;
      unsigned int uregno = DF_REF_REGNO (use);
      if ((!(df->changeable_flags & DF_NO_HARD_REGS))
	  || (uregno >= FIRST_PSEUDO_REGISTER))
	{
	  /* Do not want to go through this for an uninitialized var.  */
	  int count = DF_DEFS_COUNT (uregno);
	  if (count)
	    {
	      if (top_flag == (DF_REF_FLAGS (use) & DF_REF_AT_TOP))
		{
		  unsigned int first_index = DF_DEFS_BEGIN (uregno);
		  unsigned int last_index = first_index + count - 1;

		  EXECUTE_IF_SET_IN_BITMAP (local_rd, first_index, def_index, bi)
		    {
		      df_ref def;
		      if (def_index > last_index)
			break;

		      def = DF_DEFS_GET (def_index);
		      if (df_chain_problem_p (DF_DU_CHAIN))
			df_chain_create (def, use);
		      if (df_chain_problem_p (DF_UD_CHAIN))
			df_chain_create (use, def);
		    }
		}
	    }
	}

      use_rec++;
    }
}


/* Create chains from reaching defs bitmaps for basic block BB.  */

static void
df_chain_create_bb (unsigned int bb_index)
{
  basic_block bb = BASIC_BLOCK (bb_index);
  struct df_rd_bb_info *bb_info = df_rd_get_bb_info (bb_index);
  rtx insn;
  bitmap_head cpy;

  bitmap_initialize (&cpy, &bitmap_default_obstack);
  bitmap_copy (&cpy, &bb_info->in);
  bitmap_set_bit (df_chain->out_of_date_transfer_functions, bb_index);

  /* Since we are going forwards, process the artificial uses first
     then the artificial defs second.  */

#ifdef EH_USES
  /* Create the chains for the artificial uses from the EH_USES at the
     beginning of the block.  */

  /* Artificials are only hard regs.  */
  if (!(df->changeable_flags & DF_NO_HARD_REGS))
    df_chain_create_bb_process_use (&cpy,
				    df_get_artificial_uses (bb->index),
				    DF_REF_AT_TOP);
#endif

  df_rd_simulate_artificial_defs_at_top (bb, &cpy);

  /* Process the regular instructions next.  */
  FOR_BB_INSNS (bb, insn)
    if (INSN_P (insn))
      {
        unsigned int uid = INSN_UID (insn);

        /* First scan the uses and link them up with the defs that remain
	   in the cpy vector.  */
        df_chain_create_bb_process_use (&cpy, DF_INSN_UID_USES (uid), 0);
        if (df->changeable_flags & DF_EQ_NOTES)
	  df_chain_create_bb_process_use (&cpy, DF_INSN_UID_EQ_USES (uid), 0);

        /* Since we are going forwards, process the defs second.  */
        df_rd_simulate_one_insn (bb, insn, &cpy);
      }

  /* Create the chains for the artificial uses of the hard registers
     at the end of the block.  */
  if (!(df->changeable_flags & DF_NO_HARD_REGS))
    df_chain_create_bb_process_use (&cpy,
				    df_get_artificial_uses (bb->index),
				    0);

  bitmap_clear (&cpy);
}

/* Create def-use chains from reaching use bitmaps for basic blocks
   in BLOCKS.  */

static void
df_chain_finalize (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      df_chain_create_bb (bb_index);
    }
}


/* Free all storage associated with the problem.  */

static void
df_chain_free (void)
{
  free_alloc_pool (df_chain->block_pool);
  BITMAP_FREE (df_chain->out_of_date_transfer_functions);
  free (df_chain);
}


/* Debugging info.  */

static void
df_chain_top_dump (basic_block bb, FILE *file)
{
  if (df_chain_problem_p (DF_DU_CHAIN))
    {
      rtx insn;
      df_ref *def_rec = df_get_artificial_defs (bb->index);
      if (*def_rec)
	{

	  fprintf (file, ";;  DU chains for artificial defs\n");
	  while (*def_rec)
	    {
	      df_ref def = *def_rec;
	      fprintf (file, ";;   reg %d ", DF_REF_REGNO (def));
	      df_chain_dump (DF_REF_CHAIN (def), file);
	      fprintf (file, "\n");
	      def_rec++;
	    }
	}

      FOR_BB_INSNS (bb, insn)
	{
	  if (INSN_P (insn))
	    {
	      struct df_insn_info *insn_info = DF_INSN_INFO_GET (insn);
	      def_rec = DF_INSN_INFO_DEFS (insn_info);
	      if (*def_rec)
		{
		  fprintf (file, ";;   DU chains for insn luid %d uid %d\n",
			   DF_INSN_INFO_LUID (insn_info), INSN_UID (insn));

		  while (*def_rec)
		    {
		      df_ref def = *def_rec;
		      fprintf (file, ";;      reg %d ", DF_REF_REGNO (def));
		      if (DF_REF_FLAGS (def) & DF_REF_READ_WRITE)
			fprintf (file, "read/write ");
		      df_chain_dump (DF_REF_CHAIN (def), file);
		      fprintf (file, "\n");
		      def_rec++;
		    }
		}
	    }
	}
    }
}


static void
df_chain_bottom_dump (basic_block bb, FILE *file)
{
  if (df_chain_problem_p (DF_UD_CHAIN))
    {
      rtx insn;
      df_ref *use_rec = df_get_artificial_uses (bb->index);

      if (*use_rec)
	{
	  fprintf (file, ";;  UD chains for artificial uses\n");
	  while (*use_rec)
	    {
	      df_ref use = *use_rec;
	      fprintf (file, ";;   reg %d ", DF_REF_REGNO (use));
	      df_chain_dump (DF_REF_CHAIN (use), file);
	      fprintf (file, "\n");
	      use_rec++;
	    }
	}

      FOR_BB_INSNS (bb, insn)
	{
	  if (INSN_P (insn))
	    {
	      struct df_insn_info *insn_info = DF_INSN_INFO_GET (insn);
	      df_ref *eq_use_rec = DF_INSN_INFO_EQ_USES (insn_info);
	      use_rec = DF_INSN_INFO_USES (insn_info);
	      if (*use_rec || *eq_use_rec)
		{
		  fprintf (file, ";;   UD chains for insn luid %d uid %d\n",
			   DF_INSN_INFO_LUID (insn_info), INSN_UID (insn));

		  while (*use_rec)
		    {
		      df_ref use = *use_rec;
		      fprintf (file, ";;      reg %d ", DF_REF_REGNO (use));
		      if (DF_REF_FLAGS (use) & DF_REF_READ_WRITE)
			fprintf (file, "read/write ");
		      df_chain_dump (DF_REF_CHAIN (use), file);
		      fprintf (file, "\n");
		      use_rec++;
		    }
		  while (*eq_use_rec)
		    {
		      df_ref use = *eq_use_rec;
		      fprintf (file, ";;   eq_note reg %d ", DF_REF_REGNO (use));
		      df_chain_dump (DF_REF_CHAIN (use), file);
		      fprintf (file, "\n");
		      eq_use_rec++;
		    }
		}
	    }
	}
    }
}


static struct df_problem problem_CHAIN =
{
  DF_CHAIN,                   /* Problem id.  */
  DF_NONE,                    /* Direction.  */
  df_chain_alloc,             /* Allocate the problem specific data.  */
  df_chain_reset,             /* Reset global information.  */
  NULL,                       /* Free basic block info.  */
  NULL,                       /* Local compute function.  */
  NULL,                       /* Init the solution specific data.  */
  NULL,                       /* Iterative solver.  */
  NULL,                       /* Confluence operator 0.  */
  NULL,                       /* Confluence operator n.  */
  NULL,                       /* Transfer function.  */
  df_chain_finalize,          /* Finalize function.  */
  df_chain_free,              /* Free all of the problem information.  */
  df_chain_fully_remove_problem,/* Remove this problem from the stack of dataflow problems.  */
  NULL,                       /* Debugging.  */
  df_chain_top_dump,          /* Debugging start block.  */
  df_chain_bottom_dump,       /* Debugging end block.  */
  NULL,                       /* Incremental solution verify start.  */
  NULL,                       /* Incremental solution verify end.  */
  &problem_RD,                /* Dependent problem.  */
  sizeof (struct df_scan_bb_info),/* Size of entry of block_info array.  */
  TV_DF_CHAIN,                /* Timing variable.  */
  false                       /* Reset blocks on dropping out of blocks_to_analyze.  */
};


/* Create a new DATAFLOW instance and add it to an existing instance
   of DF.  The returned structure is what is used to get at the
   solution.  */

void
df_chain_add_problem (unsigned int chain_flags)
{
  df_add_problem (&problem_CHAIN);
  df_chain->local_flags = chain_flags;
  df_chain->out_of_date_transfer_functions = BITMAP_ALLOC (NULL);
}

#undef df_chain_problem_p


/*----------------------------------------------------------------------------
   WORD LEVEL LIVE REGISTERS

   Find the locations in the function where any use of a pseudo can
   reach in the backwards direction.  In and out bitvectors are built
   for each basic block.  We only track pseudo registers that have a
   size of 2 * UNITS_PER_WORD; bitmaps are indexed by 2 * regno and
   contain two bits corresponding to each of the subwords.

   ----------------------------------------------------------------------------*/

/* Private data used to verify the solution for this problem.  */
struct df_word_lr_problem_data
{
  /* An obstack for the bitmaps we need for this problem.  */
  bitmap_obstack word_lr_bitmaps;
};


/* Free basic block info.  */

static void
df_word_lr_free_bb_info (basic_block bb ATTRIBUTE_UNUSED,
			 void *vbb_info)
{
  struct df_word_lr_bb_info *bb_info = (struct df_word_lr_bb_info *) vbb_info;
  if (bb_info)
    {
      bitmap_clear (&bb_info->use);
      bitmap_clear (&bb_info->def);
      bitmap_clear (&bb_info->in);
      bitmap_clear (&bb_info->out);
    }
}


/* Allocate or reset bitmaps for DF_WORD_LR blocks. The solution bits are
   not touched unless the block is new.  */

static void
df_word_lr_alloc (bitmap all_blocks ATTRIBUTE_UNUSED)
{
  unsigned int bb_index;
  bitmap_iterator bi;
  basic_block bb;
  struct df_word_lr_problem_data *problem_data
    = XNEW (struct df_word_lr_problem_data);

  df_word_lr->problem_data = problem_data;

  df_grow_bb_info (df_word_lr);

  /* Create the mapping from regnos to slots. This does not change
     unless the problem is destroyed and recreated.  In particular, if
     we end up deleting the only insn that used a subreg, we do not
     want to redo the mapping because this would invalidate everything
     else.  */

  bitmap_obstack_initialize (&problem_data->word_lr_bitmaps);

  FOR_EACH_BB (bb)
    bitmap_set_bit (df_word_lr->out_of_date_transfer_functions, bb->index);

  bitmap_set_bit (df_word_lr->out_of_date_transfer_functions, ENTRY_BLOCK);
  bitmap_set_bit (df_word_lr->out_of_date_transfer_functions, EXIT_BLOCK);

  EXECUTE_IF_SET_IN_BITMAP (df_word_lr->out_of_date_transfer_functions, 0, bb_index, bi)
    {
      struct df_word_lr_bb_info *bb_info = df_word_lr_get_bb_info (bb_index);
      
      /* When bitmaps are already initialized, just clear them.  */
      if (bb_info->use.obstack)
	{
	  bitmap_clear (&bb_info->def);
	  bitmap_clear (&bb_info->use);
	}
      else
	{
	  bitmap_initialize (&bb_info->use, &problem_data->word_lr_bitmaps);
	  bitmap_initialize (&bb_info->def, &problem_data->word_lr_bitmaps);
	  bitmap_initialize (&bb_info->in, &problem_data->word_lr_bitmaps);
	  bitmap_initialize (&bb_info->out, &problem_data->word_lr_bitmaps);
	}
    }

  df_word_lr->optional_p = true;
}


/* Reset the global solution for recalculation.  */

static void
df_word_lr_reset (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      struct df_word_lr_bb_info *bb_info = df_word_lr_get_bb_info (bb_index);
      gcc_assert (bb_info);
      bitmap_clear (&bb_info->in);
      bitmap_clear (&bb_info->out);
    }
}

/* Examine REF, and if it is for a reg we're interested in, set or
   clear the bits corresponding to its subwords from the bitmap
   according to IS_SET.  LIVE is the bitmap we should update.  We do
   not track hard regs or pseudos of any size other than 2 *
   UNITS_PER_WORD.
   We return true if we changed the bitmap, or if we encountered a register
   we're not tracking.  */

bool
df_word_lr_mark_ref (df_ref ref, bool is_set, regset live)
{
  rtx orig_reg = DF_REF_REG (ref);
  rtx reg = orig_reg;
  enum machine_mode reg_mode;
  unsigned regno;
  /* Left at -1 for whole accesses.  */
  int which_subword = -1;
  bool changed = false;

  if (GET_CODE (reg) == SUBREG)
    reg = SUBREG_REG (orig_reg);
  regno = REGNO (reg);
  reg_mode = GET_MODE (reg);
  if (regno < FIRST_PSEUDO_REGISTER
      || GET_MODE_SIZE (reg_mode) != 2 * UNITS_PER_WORD)
    return true;

  if (GET_CODE (orig_reg) == SUBREG
      && df_read_modify_subreg_p (orig_reg))
    {
      gcc_assert (DF_REF_FLAGS_IS_SET (ref, DF_REF_PARTIAL));
      if (subreg_lowpart_p (orig_reg))
	which_subword = 0;
      else
	which_subword = 1;
    }
  if (is_set)
    {
      if (which_subword != 1)
	changed |= bitmap_set_bit (live, regno * 2);
      if (which_subword != 0)
	changed |= bitmap_set_bit (live, regno * 2 + 1);
    }
  else
    {
      if (which_subword != 1)
	changed |= bitmap_clear_bit (live, regno * 2);
      if (which_subword != 0)
	changed |= bitmap_clear_bit (live, regno * 2 + 1);
    }
  return changed;
}

/* Compute local live register info for basic block BB.  */

static void
df_word_lr_bb_local_compute (unsigned int bb_index)
{
  basic_block bb = BASIC_BLOCK (bb_index);
  struct df_word_lr_bb_info *bb_info = df_word_lr_get_bb_info (bb_index);
  rtx insn;
  df_ref *def_rec;
  df_ref *use_rec;

  /* Ensure that artificial refs don't contain references to pseudos.  */
  for (def_rec = df_get_artificial_defs (bb_index); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      gcc_assert (DF_REF_REGNO (def) < FIRST_PSEUDO_REGISTER);
    }

  for (use_rec = df_get_artificial_uses (bb_index); *use_rec; use_rec++)
    {
      df_ref use = *use_rec;
      gcc_assert (DF_REF_REGNO (use) < FIRST_PSEUDO_REGISTER);
    }

  FOR_BB_INSNS_REVERSE (bb, insn)
    {
      unsigned int uid = INSN_UID (insn);

      if (!NONDEBUG_INSN_P (insn))
	continue;
      for (def_rec = DF_INSN_UID_DEFS (uid); *def_rec; def_rec++)
	{
	  df_ref def = *def_rec;
	  /* If the def is to only part of the reg, it does
	     not kill the other defs that reach here.  */
	  if (!(DF_REF_FLAGS (def) & (DF_REF_CONDITIONAL)))
	    {
	      df_word_lr_mark_ref (def, true, &bb_info->def);
	      df_word_lr_mark_ref (def, false, &bb_info->use);
	    }
	}
      for (use_rec = DF_INSN_UID_USES (uid); *use_rec; use_rec++)
	{
	  df_ref use = *use_rec;
	  df_word_lr_mark_ref (use, true, &bb_info->use);
	}
    }
}


/* Compute local live register info for each basic block within BLOCKS.  */

static void
df_word_lr_local_compute (bitmap all_blocks ATTRIBUTE_UNUSED)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  EXECUTE_IF_SET_IN_BITMAP (df_word_lr->out_of_date_transfer_functions, 0, bb_index, bi)
    {
      if (bb_index == EXIT_BLOCK)
	{
	  unsigned regno;
	  bitmap_iterator bi;
	  EXECUTE_IF_SET_IN_BITMAP (df->exit_block_uses, FIRST_PSEUDO_REGISTER,
				    regno, bi)
	    gcc_unreachable ();
	}
      else
	df_word_lr_bb_local_compute (bb_index);
    }

  bitmap_clear (df_word_lr->out_of_date_transfer_functions);
}


/* Initialize the solution vectors.  */

static void
df_word_lr_init (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      struct df_word_lr_bb_info *bb_info = df_word_lr_get_bb_info (bb_index);
      bitmap_copy (&bb_info->in, &bb_info->use);
      bitmap_clear (&bb_info->out);
    }
}


/* Confluence function that ignores fake edges.  */

static bool
df_word_lr_confluence_n (edge e)
{
  bitmap op1 = &df_word_lr_get_bb_info (e->src->index)->out;
  bitmap op2 = &df_word_lr_get_bb_info (e->dest->index)->in;

  return bitmap_ior_into (op1, op2);
}


/* Transfer function.  */

static bool
df_word_lr_transfer_function (int bb_index)
{
  struct df_word_lr_bb_info *bb_info = df_word_lr_get_bb_info (bb_index);
  bitmap in = &bb_info->in;
  bitmap out = &bb_info->out;
  bitmap use = &bb_info->use;
  bitmap def = &bb_info->def;

  return bitmap_ior_and_compl (in, use, out, def);
}


/* Free all storage associated with the problem.  */

static void
df_word_lr_free (void)
{
  struct df_word_lr_problem_data *problem_data
    = (struct df_word_lr_problem_data *)df_word_lr->problem_data;

  if (df_word_lr->block_info)
    {
      df_word_lr->block_info_size = 0;
      free (df_word_lr->block_info);
      df_word_lr->block_info = NULL;
    }

  BITMAP_FREE (df_word_lr->out_of_date_transfer_functions);
  bitmap_obstack_release (&problem_data->word_lr_bitmaps);
  free (problem_data);
  free (df_word_lr);
}


/* Debugging info at top of bb.  */

static void
df_word_lr_top_dump (basic_block bb, FILE *file)
{
  struct df_word_lr_bb_info *bb_info = df_word_lr_get_bb_info (bb->index);
  if (!bb_info)
    return;

  fprintf (file, ";; blr  in  \t");
  df_print_word_regset (file, &bb_info->in);
  fprintf (file, ";; blr  use \t");
  df_print_word_regset (file, &bb_info->use);
  fprintf (file, ";; blr  def \t");
  df_print_word_regset (file, &bb_info->def);
}


/* Debugging info at bottom of bb.  */

static void
df_word_lr_bottom_dump (basic_block bb, FILE *file)
{
  struct df_word_lr_bb_info *bb_info = df_word_lr_get_bb_info (bb->index);
  if (!bb_info)
    return;

  fprintf (file, ";; blr  out \t");
  df_print_word_regset (file, &bb_info->out);
}


/* All of the information associated with every instance of the problem.  */

static struct df_problem problem_WORD_LR =
{
  DF_WORD_LR,                      /* Problem id.  */
  DF_BACKWARD,                     /* Direction.  */
  df_word_lr_alloc,                /* Allocate the problem specific data.  */
  df_word_lr_reset,                /* Reset global information.  */
  df_word_lr_free_bb_info,         /* Free basic block info.  */
  df_word_lr_local_compute,        /* Local compute function.  */
  df_word_lr_init,                 /* Init the solution specific data.  */
  df_worklist_dataflow,            /* Worklist solver.  */
  NULL,                            /* Confluence operator 0.  */
  df_word_lr_confluence_n,         /* Confluence operator n.  */
  df_word_lr_transfer_function,    /* Transfer function.  */
  NULL,                            /* Finalize function.  */
  df_word_lr_free,                 /* Free all of the problem information.  */
  df_word_lr_free,                 /* Remove this problem from the stack of dataflow problems.  */
  NULL,                            /* Debugging.  */
  df_word_lr_top_dump,             /* Debugging start block.  */
  df_word_lr_bottom_dump,          /* Debugging end block.  */
  NULL,                            /* Incremental solution verify start.  */
  NULL,                            /* Incremental solution verify end.  */
  NULL,                       /* Dependent problem.  */
  sizeof (struct df_word_lr_bb_info),/* Size of entry of block_info array.  */
  TV_DF_WORD_LR,                   /* Timing variable.  */
  false                            /* Reset blocks on dropping out of blocks_to_analyze.  */
};


/* Create a new DATAFLOW instance and add it to an existing instance
   of DF.  The returned structure is what is used to get at the
   solution.  */

void
df_word_lr_add_problem (void)
{
  df_add_problem (&problem_WORD_LR);
  /* These will be initialized when df_scan_blocks processes each
     block.  */
  df_word_lr->out_of_date_transfer_functions = BITMAP_ALLOC (NULL);
}


/* Simulate the effects of the defs of INSN on LIVE.  Return true if we changed
   any bits, which is used by the caller to determine whether a set is
   necessary.  We also return true if there are other reasons not to delete
   an insn.  */

bool
df_word_lr_simulate_defs (rtx insn, bitmap live)
{
  bool changed = false;
  df_ref *def_rec;
  unsigned int uid = INSN_UID (insn);

  for (def_rec = DF_INSN_UID_DEFS (uid); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      if (DF_REF_FLAGS (def) & DF_REF_CONDITIONAL)
	changed = true;
      else
	changed |= df_word_lr_mark_ref (*def_rec, false, live);
    }
  return changed;
}


/* Simulate the effects of the uses of INSN on LIVE.  */

void
df_word_lr_simulate_uses (rtx insn, bitmap live)
{
  df_ref *use_rec;
  unsigned int uid = INSN_UID (insn);

  for (use_rec = DF_INSN_UID_USES (uid); *use_rec; use_rec++)
    df_word_lr_mark_ref (*use_rec, true, live);
}

/*----------------------------------------------------------------------------
   This problem computes REG_DEAD and REG_UNUSED notes.
   ----------------------------------------------------------------------------*/

static void
df_note_alloc (bitmap all_blocks ATTRIBUTE_UNUSED)
{
  df_note->optional_p = true;
}

#ifdef REG_DEAD_DEBUGGING
static void
df_print_note (const char *prefix, rtx insn, rtx note)
{
  if (dump_file)
    {
      fprintf (dump_file, "%s %d ", prefix, INSN_UID (insn));
      print_rtl (dump_file, note);
      fprintf (dump_file, "\n");
    }
}
#endif


/* After reg-stack, the x86 floating point stack regs are difficult to
   analyze because of all of the pushes, pops and rotations.  Thus, we
   just leave the notes alone. */

#ifdef STACK_REGS
static inline bool
df_ignore_stack_reg (int regno)
{
  return regstack_completed
    && IN_RANGE (regno, FIRST_STACK_REG, LAST_STACK_REG);
}
#else
static inline bool
df_ignore_stack_reg (int regno ATTRIBUTE_UNUSED)
{
  return false;
}
#endif


/* Remove all of the REG_DEAD or REG_UNUSED notes from INSN and add
   them to OLD_DEAD_NOTES and OLD_UNUSED_NOTES.  */

static void
df_kill_notes (rtx insn)
{
  rtx *pprev = &REG_NOTES (insn);
  rtx link = *pprev;

  while (link)
    {
      switch (REG_NOTE_KIND (link))
	{
	case REG_DEAD:
	  /* After reg-stack, we need to ignore any unused notes
	     for the stack registers.  */
	  if (df_ignore_stack_reg (REGNO (XEXP (link, 0))))
	    {
	      pprev = &XEXP (link, 1);
	      link = *pprev;
	    }
	  else
	    {
	      rtx next = XEXP (link, 1);
#ifdef REG_DEAD_DEBUGGING
	      df_print_note ("deleting: ", insn, link);
#endif
	      free_EXPR_LIST_node (link);
	      *pprev = link = next;
	    }
	  break;

	case REG_UNUSED:
	  /* After reg-stack, we need to ignore any unused notes
	     for the stack registers.  */
	  if (df_ignore_stack_reg (REGNO (XEXP (link, 0))))
	    {
	      pprev = &XEXP (link, 1);
	      link = *pprev;
	    }
	  else
	    {
	      rtx next = XEXP (link, 1);
#ifdef REG_DEAD_DEBUGGING
	      df_print_note ("deleting: ", insn, link);
#endif
	      free_EXPR_LIST_node (link);
	      *pprev = link = next;
	    }
	  break;

	default:
	  pprev = &XEXP (link, 1);
	  link = *pprev;
	  break;
	}
    }
}


/* Set a NOTE_TYPE note for REG in INSN.  */

static inline void
df_set_note (enum reg_note note_type, rtx insn, rtx reg)
{
  gcc_checking_assert (!DEBUG_INSN_P (insn));
  add_reg_note (insn, note_type, reg);
}

/* A subroutine of df_set_unused_notes_for_mw, with a selection of its
   arguments.  Return true if the register value described by MWS's
   mw_reg is known to be completely unused, and if mw_reg can therefore
   be used in a REG_UNUSED note.  */

static bool
df_whole_mw_reg_unused_p (struct df_mw_hardreg *mws,
			  bitmap live, bitmap artificial_uses)
{
  unsigned int r;

  /* If MWS describes a partial reference, create REG_UNUSED notes for
     individual hard registers.  */
  if (mws->flags & DF_REF_PARTIAL)
    return false;

  /* Likewise if some part of the register is used.  */
  for (r = mws->start_regno; r <= mws->end_regno; r++)
    if (bitmap_bit_p (live, r)
	|| bitmap_bit_p (artificial_uses, r))
      return false;

  gcc_assert (REG_P (mws->mw_reg));
  return true;
}


/* Node of a linked list of uses of dead REGs in debug insns.  */
struct dead_debug_use
{
  df_ref use;
  struct dead_debug_use *next;
};

/* Linked list of the above, with a bitmap of the REGs in the
   list.  */
struct dead_debug
{
  struct dead_debug_use *head;
  bitmap used;
  bitmap to_rescan;
};

static void dead_debug_reset (struct dead_debug *, unsigned int);


/* Set the REG_UNUSED notes for the multiword hardreg defs in INSN
   based on the bits in LIVE.  Do not generate notes for registers in
   artificial uses.  DO_NOT_GEN is updated so that REG_DEAD notes are
   not generated if the reg is both read and written by the
   instruction.
*/

static void
df_set_unused_notes_for_mw (rtx insn, struct df_mw_hardreg *mws,
			    bitmap live, bitmap do_not_gen,
			    bitmap artificial_uses,
			    struct dead_debug *debug)
{
  unsigned int r;

#ifdef REG_DEAD_DEBUGGING
  if (dump_file)
    fprintf (dump_file, "mw_set_unused looking at mws[%d..%d]\n",
	     mws->start_regno, mws->end_regno);
#endif

  if (df_whole_mw_reg_unused_p (mws, live, artificial_uses))
    {
      unsigned int regno = mws->start_regno;
      df_set_note (REG_UNUSED, insn, mws->mw_reg);
      dead_debug_reset (debug, regno);

#ifdef REG_DEAD_DEBUGGING
      df_print_note ("adding 1: ", insn, REG_NOTES (insn));
#endif
      bitmap_set_bit (do_not_gen, regno);
      /* Only do this if the value is totally dead.  */
    }
  else
    for (r = mws->start_regno; r <= mws->end_regno; r++)
      {
	if (!bitmap_bit_p (live, r)
	    && !bitmap_bit_p (artificial_uses, r))
	  {
	    df_set_note (REG_UNUSED, insn, regno_reg_rtx[r]);
	    dead_debug_reset (debug, r);
#ifdef REG_DEAD_DEBUGGING
	    df_print_note ("adding 2: ", insn, REG_NOTES (insn));
#endif
	  }
	bitmap_set_bit (do_not_gen, r);
      }
}


/* A subroutine of df_set_dead_notes_for_mw, with a selection of its
   arguments.  Return true if the register value described by MWS's
   mw_reg is known to be completely dead, and if mw_reg can therefore
   be used in a REG_DEAD note.  */

static bool
df_whole_mw_reg_dead_p (struct df_mw_hardreg *mws,
			bitmap live, bitmap artificial_uses,
			bitmap do_not_gen)
{
  unsigned int r;

  /* If MWS describes a partial reference, create REG_DEAD notes for
     individual hard registers.  */
  if (mws->flags & DF_REF_PARTIAL)
    return false;

  /* Likewise if some part of the register is not dead.  */
  for (r = mws->start_regno; r <= mws->end_regno; r++)
    if (bitmap_bit_p (live, r)
	|| bitmap_bit_p (artificial_uses, r)
	|| bitmap_bit_p (do_not_gen, r))
      return false;

  gcc_assert (REG_P (mws->mw_reg));
  return true;
}

/* Set the REG_DEAD notes for the multiword hardreg use in INSN based
   on the bits in LIVE.  DO_NOT_GEN is used to keep REG_DEAD notes
   from being set if the instruction both reads and writes the
   register.  */

static void
df_set_dead_notes_for_mw (rtx insn, struct df_mw_hardreg *mws,
			  bitmap live, bitmap do_not_gen,
			  bitmap artificial_uses, bool *added_notes_p)
{
  unsigned int r;
  bool is_debug = *added_notes_p;

  *added_notes_p = false;

#ifdef REG_DEAD_DEBUGGING
  if (dump_file)
    {
      fprintf (dump_file, "mw_set_dead looking at mws[%d..%d]\n  do_not_gen =",
	       mws->start_regno, mws->end_regno);
      df_print_regset (dump_file, do_not_gen);
      fprintf (dump_file, "  live =");
      df_print_regset (dump_file, live);
      fprintf (dump_file, "  artificial uses =");
      df_print_regset (dump_file, artificial_uses);
    }
#endif

  if (df_whole_mw_reg_dead_p (mws, live, artificial_uses, do_not_gen))
    {
      /* Add a dead note for the entire multi word register.  */
      if (is_debug)
	{
	  *added_notes_p = true;
	  return;
	}
      df_set_note (REG_DEAD, insn, mws->mw_reg);
#ifdef REG_DEAD_DEBUGGING
      df_print_note ("adding 1: ", insn, REG_NOTES (insn));
#endif
    }
  else
    {
      for (r = mws->start_regno; r <= mws->end_regno; r++)
	if (!bitmap_bit_p (live, r)
	    && !bitmap_bit_p (artificial_uses, r)
	    && !bitmap_bit_p (do_not_gen, r))
	  {
	    if (is_debug)
	      {
		*added_notes_p = true;
		return;
	      }
	    df_set_note (REG_DEAD, insn, regno_reg_rtx[r]);
#ifdef REG_DEAD_DEBUGGING
	    df_print_note ("adding 2: ", insn, REG_NOTES (insn));
#endif
	  }
    }
  return;
}


/* Create a REG_UNUSED note if necessary for DEF in INSN updating
   LIVE.  Do not generate notes for registers in ARTIFICIAL_USES.  */

static void
df_create_unused_note (rtx insn, df_ref def,
		       bitmap live, bitmap artificial_uses,
		       struct dead_debug *debug)
{
  unsigned int dregno = DF_REF_REGNO (def);

#ifdef REG_DEAD_DEBUGGING
  if (dump_file)
    {
      fprintf (dump_file, "  regular looking at def ");
      df_ref_debug (def, dump_file);
    }
#endif

  if (!((DF_REF_FLAGS (def) & DF_REF_MW_HARDREG)
	|| bitmap_bit_p (live, dregno)
	|| bitmap_bit_p (artificial_uses, dregno)
	|| df_ignore_stack_reg (dregno)))
    {
      rtx reg = (DF_REF_LOC (def))
                ? *DF_REF_REAL_LOC (def): DF_REF_REG (def);
      df_set_note (REG_UNUSED, insn, reg);
      dead_debug_reset (debug, dregno);
#ifdef REG_DEAD_DEBUGGING
      df_print_note ("adding 3: ", insn, REG_NOTES (insn));
#endif
    }

  return;
}


/* Initialize DEBUG to an empty list, and clear USED, if given.  */
static inline void
dead_debug_init (struct dead_debug *debug, bitmap used)
{
  debug->head = NULL;
  debug->used = used;
  debug->to_rescan = NULL;
  if (used)
    bitmap_clear (used);
}

/* Reset all debug insns with pending uses.  Release the bitmap in it,
   unless it is USED.  USED must be the same bitmap passed to
   dead_debug_init.  */
static inline void
dead_debug_finish (struct dead_debug *debug, bitmap used)
{
  struct dead_debug_use *head;
  rtx insn = NULL;

  if (debug->used != used)
    BITMAP_FREE (debug->used);

  while ((head = debug->head))
    {
      insn = DF_REF_INSN (head->use);
      if (!head->next || DF_REF_INSN (head->next->use) != insn)
	{
	  INSN_VAR_LOCATION_LOC (insn) = gen_rtx_UNKNOWN_VAR_LOC ();
	  df_insn_rescan_debug_internal (insn);
	  if (debug->to_rescan)
	    bitmap_clear_bit (debug->to_rescan, INSN_UID (insn));
	}
      debug->head = head->next;
      XDELETE (head);
    }

  if (debug->to_rescan)
    {
      bitmap_iterator bi;
      unsigned int uid;

      EXECUTE_IF_SET_IN_BITMAP (debug->to_rescan, 0, uid, bi)
	{
	  struct df_insn_info *insn_info = DF_INSN_UID_SAFE_GET (uid);
	  if (insn_info)
	    df_insn_rescan (insn_info->insn);
	}
      BITMAP_FREE (debug->to_rescan);
    }
}

/* Reset DEBUG_INSNs with pending uses of DREGNO.  */
static void
dead_debug_reset (struct dead_debug *debug, unsigned int dregno)
{
  struct dead_debug_use **tailp = &debug->head;
  struct dead_debug_use *cur;
  rtx insn;

  if (!debug->used || !bitmap_clear_bit (debug->used, dregno))
    return;

  while ((cur = *tailp))
    {
      if (DF_REF_REGNO (cur->use) == dregno)
	{
	  *tailp = cur->next;
	  insn = DF_REF_INSN (cur->use);
	  INSN_VAR_LOCATION_LOC (insn) = gen_rtx_UNKNOWN_VAR_LOC ();
	  if (debug->to_rescan == NULL)
	    debug->to_rescan = BITMAP_ALLOC (NULL);
	  bitmap_set_bit (debug->to_rescan, INSN_UID (insn));
	  XDELETE (cur);
	}
      else
	tailp = &(*tailp)->next;
    }
}

/* Add USE to DEBUG.  It must be a dead reference to UREGNO in a debug
   insn.  Create a bitmap for DEBUG as needed.  */
static inline void
dead_debug_add (struct dead_debug *debug, df_ref use, unsigned int uregno)
{
  struct dead_debug_use *newddu = XNEW (struct dead_debug_use);

  newddu->use = use;
  newddu->next = debug->head;
  debug->head = newddu;

  if (!debug->used)
    debug->used = BITMAP_ALLOC (NULL);

  bitmap_set_bit (debug->used, uregno);
}

/* If UREGNO is referenced by any entry in DEBUG, emit a debug insn
   before INSN that binds the REG to a debug temp, and replace all
   uses of UREGNO in DEBUG with uses of the debug temp.  INSN must be
   the insn where UREGNO dies.  */
static inline void
dead_debug_insert_before (struct dead_debug *debug, unsigned int uregno,
			  rtx insn)
{
  struct dead_debug_use **tailp = &debug->head;
  struct dead_debug_use *cur;
  struct dead_debug_use *uses = NULL;
  struct dead_debug_use **usesp = &uses;
  rtx reg = NULL;
  rtx dval;
  rtx bind;

  if (!debug->used || !bitmap_clear_bit (debug->used, uregno))
    return;

  /* Move all uses of uregno from debug->head to uses, setting mode to
     the widest referenced mode.  */
  while ((cur = *tailp))
    {
      if (DF_REF_REGNO (cur->use) == uregno)
	{
	  *usesp = cur;
	  usesp = &cur->next;
	  *tailp = cur->next;
	  cur->next = NULL;
	  if (!reg
	      || (GET_MODE_BITSIZE (GET_MODE (reg))
		  < GET_MODE_BITSIZE (GET_MODE (*DF_REF_REAL_LOC (cur->use)))))
	    reg = *DF_REF_REAL_LOC (cur->use);
	}
      else
	tailp = &(*tailp)->next;
    }

  gcc_assert (reg);

  /* Create DEBUG_EXPR (and DEBUG_EXPR_DECL).  */
  dval = make_debug_expr_from_rtl (reg);

  /* Emit a debug bind insn before the insn in which reg dies.  */
  bind = gen_rtx_VAR_LOCATION (GET_MODE (reg),
			       DEBUG_EXPR_TREE_DECL (dval), reg,
			       VAR_INIT_STATUS_INITIALIZED);

  bind = emit_debug_insn_before (bind, insn);
  df_insn_rescan (bind);

  /* Adjust all uses.  */
  while ((cur = uses))
    {
      if (GET_MODE (*DF_REF_REAL_LOC (cur->use)) == GET_MODE (reg))
	*DF_REF_REAL_LOC (cur->use) = dval;
      else
	*DF_REF_REAL_LOC (cur->use)
	  = gen_lowpart_SUBREG (GET_MODE (*DF_REF_REAL_LOC (cur->use)), dval);
      /* ??? Should we simplify subreg of subreg?  */
      if (debug->to_rescan == NULL)
	debug->to_rescan = BITMAP_ALLOC (NULL);
      bitmap_set_bit (debug->to_rescan, INSN_UID (DF_REF_INSN (cur->use)));
      uses = cur->next;
      XDELETE (cur);
    }
}

/* Recompute the REG_DEAD and REG_UNUSED notes and compute register
   info: lifetime, bb, and number of defs and uses for basic block
   BB.  The three bitvectors are scratch regs used here.  */

static void
df_note_bb_compute (unsigned int bb_index,
		    bitmap live, bitmap do_not_gen, bitmap artificial_uses)
{
  basic_block bb = BASIC_BLOCK (bb_index);
  rtx insn;
  df_ref *def_rec;
  df_ref *use_rec;
  struct dead_debug debug;

  dead_debug_init (&debug, NULL);

  bitmap_copy (live, df_get_live_out (bb));
  bitmap_clear (artificial_uses);

#ifdef REG_DEAD_DEBUGGING
  if (dump_file)
    {
      fprintf (dump_file, "live at bottom ");
      df_print_regset (dump_file, live);
    }
#endif

  /* Process the artificial defs and uses at the bottom of the block
     to begin processing.  */
  for (def_rec = df_get_artificial_defs (bb_index); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
#ifdef REG_DEAD_DEBUGGING
      if (dump_file)
	fprintf (dump_file, "artificial def %d\n", DF_REF_REGNO (def));
#endif

      if ((DF_REF_FLAGS (def) & DF_REF_AT_TOP) == 0)
	bitmap_clear_bit (live, DF_REF_REGNO (def));
    }

  for (use_rec = df_get_artificial_uses (bb_index); *use_rec; use_rec++)
    {
      df_ref use = *use_rec;
      if ((DF_REF_FLAGS (use) & DF_REF_AT_TOP) == 0)
	{
	  unsigned int regno = DF_REF_REGNO (use);
	  bitmap_set_bit (live, regno);

	  /* Notes are not generated for any of the artificial registers
	     at the bottom of the block.  */
	  bitmap_set_bit (artificial_uses, regno);
	}
    }

#ifdef REG_DEAD_DEBUGGING
  if (dump_file)
    {
      fprintf (dump_file, "live before artificials out ");
      df_print_regset (dump_file, live);
    }
#endif

  FOR_BB_INSNS_REVERSE (bb, insn)
    {
      unsigned int uid = INSN_UID (insn);
      struct df_mw_hardreg **mws_rec;
      int debug_insn;

      if (!INSN_P (insn))
	continue;

      debug_insn = DEBUG_INSN_P (insn);

      bitmap_clear (do_not_gen);
      df_kill_notes (insn);

      /* Process the defs.  */
      if (CALL_P (insn))
	{
#ifdef REG_DEAD_DEBUGGING
	  if (dump_file)
	    {
	      fprintf (dump_file, "processing call %d\n  live =", INSN_UID (insn));
	      df_print_regset (dump_file, live);
	    }
#endif
	  /* We only care about real sets for calls.  Clobbers cannot
	     be depended on to really die.  */
	  mws_rec = DF_INSN_UID_MWS (uid);
	  while (*mws_rec)
	    {
	      struct df_mw_hardreg *mws = *mws_rec;
	      if ((DF_MWS_REG_DEF_P (mws))
		  && !df_ignore_stack_reg (mws->start_regno))
	      df_set_unused_notes_for_mw (insn,
					  mws, live, do_not_gen,
					  artificial_uses, &debug);
	      mws_rec++;
	    }

	  /* All of the defs except the return value are some sort of
	     clobber.  This code is for the return.  */
	  for (def_rec = DF_INSN_UID_DEFS (uid); *def_rec; def_rec++)
	    {
	      df_ref def = *def_rec;
	      unsigned int dregno = DF_REF_REGNO (def);
	      if (!DF_REF_FLAGS_IS_SET (def, DF_REF_MUST_CLOBBER | DF_REF_MAY_CLOBBER))
		{
		  df_create_unused_note (insn,
					 def, live, artificial_uses, &debug);
		  bitmap_set_bit (do_not_gen, dregno);
		}

	      if (!DF_REF_FLAGS_IS_SET (def, DF_REF_PARTIAL | DF_REF_CONDITIONAL))
		bitmap_clear_bit (live, dregno);
	    }
	}
      else
	{
	  /* Regular insn.  */
	  mws_rec = DF_INSN_UID_MWS (uid);
	  while (*mws_rec)
	    {
	      struct df_mw_hardreg *mws = *mws_rec;
	      if (DF_MWS_REG_DEF_P (mws))
		df_set_unused_notes_for_mw (insn,
					    mws, live, do_not_gen,
					    artificial_uses, &debug);
	      mws_rec++;
	    }

	  for (def_rec = DF_INSN_UID_DEFS (uid); *def_rec; def_rec++)
	    {
	      df_ref def = *def_rec;
	      unsigned int dregno = DF_REF_REGNO (def);
	      df_create_unused_note (insn,
				     def, live, artificial_uses, &debug);

	      if (!DF_REF_FLAGS_IS_SET (def, DF_REF_MUST_CLOBBER | DF_REF_MAY_CLOBBER))
		bitmap_set_bit (do_not_gen, dregno);

	      if (!DF_REF_FLAGS_IS_SET (def, DF_REF_PARTIAL | DF_REF_CONDITIONAL))
		bitmap_clear_bit (live, dregno);
	    }
	}

      /* Process the uses.  */
      mws_rec = DF_INSN_UID_MWS (uid);
      while (*mws_rec)
	{
	  struct df_mw_hardreg *mws = *mws_rec;
	  if ((DF_MWS_REG_DEF_P (mws))
	      && !df_ignore_stack_reg (mws->start_regno))
	    {
	      bool really_add_notes = debug_insn != 0;

	      df_set_dead_notes_for_mw (insn,
					mws, live, do_not_gen,
					artificial_uses,
					&really_add_notes);

	      if (really_add_notes)
		debug_insn = -1;
	    }
	  mws_rec++;
	}

      for (use_rec = DF_INSN_UID_USES (uid); *use_rec; use_rec++)
	{
	  df_ref use = *use_rec;
	  unsigned int uregno = DF_REF_REGNO (use);

#ifdef REG_DEAD_DEBUGGING
	  if (dump_file && !debug_insn)
	    {
	      fprintf (dump_file, "  regular looking at use ");
	      df_ref_debug (use, dump_file);
	    }
#endif
	  if (!bitmap_bit_p (live, uregno))
	    {
	      if (debug_insn)
		{
		  if (debug_insn > 0)
		    {
		      dead_debug_add (&debug, use, uregno);
		      continue;
		    }
		  break;
		}
	      else
		dead_debug_insert_before (&debug, uregno, insn);

	      if ( (!(DF_REF_FLAGS (use)
		      & (DF_REF_MW_HARDREG | DF_REF_READ_WRITE)))
		   && (!bitmap_bit_p (do_not_gen, uregno))
		   && (!bitmap_bit_p (artificial_uses, uregno))
		   && (!df_ignore_stack_reg (uregno)))
		{
		  rtx reg = (DF_REF_LOC (use))
                            ? *DF_REF_REAL_LOC (use) : DF_REF_REG (use);
		  df_set_note (REG_DEAD, insn, reg);

#ifdef REG_DEAD_DEBUGGING
		  df_print_note ("adding 4: ", insn, REG_NOTES (insn));
#endif
		}
	      /* This register is now live.  */
	      bitmap_set_bit (live, uregno);
	    }
	}

      if (debug_insn == -1)
	{
	  /* ??? We could probably do better here, replacing dead
	     registers with their definitions.  */
	  INSN_VAR_LOCATION_LOC (insn) = gen_rtx_UNKNOWN_VAR_LOC ();
	  df_insn_rescan_debug_internal (insn);
	}
    }

  dead_debug_finish (&debug, NULL);
}


/* Compute register info: lifetime, bb, and number of defs and uses.  */
static void
df_note_compute (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;
  bitmap_head live, do_not_gen, artificial_uses;

  bitmap_initialize (&live, &df_bitmap_obstack);
  bitmap_initialize (&do_not_gen, &df_bitmap_obstack);
  bitmap_initialize (&artificial_uses, &df_bitmap_obstack);

#ifdef REG_DEAD_DEBUGGING
  if (dump_file)
    print_rtl_with_bb (dump_file, get_insns());
#endif

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
  {
    df_note_bb_compute (bb_index, &live, &do_not_gen, &artificial_uses);
  }

  bitmap_clear (&live);
  bitmap_clear (&do_not_gen);
  bitmap_clear (&artificial_uses);
}


/* Free all storage associated with the problem.  */

static void
df_note_free (void)
{
  free (df_note);
}


/* All of the information associated every instance of the problem.  */

static struct df_problem problem_NOTE =
{
  DF_NOTE,                    /* Problem id.  */
  DF_NONE,                    /* Direction.  */
  df_note_alloc,              /* Allocate the problem specific data.  */
  NULL,                       /* Reset global information.  */
  NULL,                       /* Free basic block info.  */
  df_note_compute,            /* Local compute function.  */
  NULL,                       /* Init the solution specific data.  */
  NULL,                       /* Iterative solver.  */
  NULL,                       /* Confluence operator 0.  */
  NULL,                       /* Confluence operator n.  */
  NULL,                       /* Transfer function.  */
  NULL,                       /* Finalize function.  */
  df_note_free,               /* Free all of the problem information.  */
  df_note_free,               /* Remove this problem from the stack of dataflow problems.  */
  NULL,                       /* Debugging.  */
  NULL,                       /* Debugging start block.  */
  NULL,                       /* Debugging end block.  */
  NULL,                       /* Incremental solution verify start.  */
  NULL,                       /* Incremental solution verify end.  */
  &problem_LR,                /* Dependent problem.  */
  sizeof (struct df_scan_bb_info),/* Size of entry of block_info array.  */
  TV_DF_NOTE,                 /* Timing variable.  */
  false                       /* Reset blocks on dropping out of blocks_to_analyze.  */
};


/* Create a new DATAFLOW instance and add it to an existing instance
   of DF.  The returned structure is what is used to get at the
   solution.  */

void
df_note_add_problem (void)
{
  df_add_problem (&problem_NOTE);
}




/*----------------------------------------------------------------------------
   Functions for simulating the effects of single insns.

   You can either simulate in the forwards direction, starting from
   the top of a block or the backwards direction from the end of the
   block.  If you go backwards, defs are examined first to clear bits,
   then uses are examined to set bits.  If you go forwards, defs are
   examined first to set bits, then REG_DEAD and REG_UNUSED notes
   are examined to clear bits.  In either case, the result of examining
   a def can be undone (respectively by a use or a REG_UNUSED note).

   If you start at the top of the block, use one of DF_LIVE_IN or
   DF_LR_IN.  If you start at the bottom of the block use one of
   DF_LIVE_OUT or DF_LR_OUT.  BE SURE TO PASS A COPY OF THESE SETS,
   THEY WILL BE DESTROYED.
----------------------------------------------------------------------------*/


/* Find the set of DEFs for INSN.  */

void
df_simulate_find_defs (rtx insn, bitmap defs)
{
  df_ref *def_rec;
  unsigned int uid = INSN_UID (insn);

  for (def_rec = DF_INSN_UID_DEFS (uid); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      bitmap_set_bit (defs, DF_REF_REGNO (def));
    }
}

/* Find the set of uses for INSN.  This includes partial defs.  */

static void
df_simulate_find_uses (rtx insn, bitmap uses)
{
  df_ref *rec;
  unsigned int uid = INSN_UID (insn);

  for (rec = DF_INSN_UID_DEFS (uid); *rec; rec++)
    {
      df_ref def = *rec;
      if (DF_REF_FLAGS (def) & (DF_REF_PARTIAL | DF_REF_CONDITIONAL))
	bitmap_set_bit (uses, DF_REF_REGNO (def));
    }
  for (rec = DF_INSN_UID_USES (uid); *rec; rec++)
    {
      df_ref use = *rec;
      bitmap_set_bit (uses, DF_REF_REGNO (use));
    }
}

/* Find the set of real DEFs, which are not clobbers, for INSN.  */

void
df_simulate_find_noclobber_defs (rtx insn, bitmap defs)
{
  df_ref *def_rec;
  unsigned int uid = INSN_UID (insn);

  for (def_rec = DF_INSN_UID_DEFS (uid); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      if (!(DF_REF_FLAGS (def) & (DF_REF_MUST_CLOBBER | DF_REF_MAY_CLOBBER)))
	bitmap_set_bit (defs, DF_REF_REGNO (def));
    }
}


/* Simulate the effects of the defs of INSN on LIVE.  */

void
df_simulate_defs (rtx insn, bitmap live)
{
  df_ref *def_rec;
  unsigned int uid = INSN_UID (insn);

  for (def_rec = DF_INSN_UID_DEFS (uid); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      unsigned int dregno = DF_REF_REGNO (def);

      /* If the def is to only part of the reg, it does
	 not kill the other defs that reach here.  */
      if (!(DF_REF_FLAGS (def) & (DF_REF_PARTIAL | DF_REF_CONDITIONAL)))
	bitmap_clear_bit (live, dregno);
    }
}


/* Simulate the effects of the uses of INSN on LIVE.  */

void
df_simulate_uses (rtx insn, bitmap live)
{
  df_ref *use_rec;
  unsigned int uid = INSN_UID (insn);

  if (DEBUG_INSN_P (insn))
    return;

  for (use_rec = DF_INSN_UID_USES (uid); *use_rec; use_rec++)
    {
      df_ref use = *use_rec;
      /* Add use to set of uses in this BB.  */
      bitmap_set_bit (live, DF_REF_REGNO (use));
    }
}


/* Add back the always live regs in BB to LIVE.  */

static inline void
df_simulate_fixup_sets (basic_block bb, bitmap live)
{
  /* These regs are considered always live so if they end up dying
     because of some def, we need to bring the back again.  */
  if (bb_has_eh_pred (bb))
    bitmap_ior_into (live, &df->eh_block_artificial_uses);
  else
    bitmap_ior_into (live, &df->regular_block_artificial_uses);
}


/*----------------------------------------------------------------------------
   The following three functions are used only for BACKWARDS scanning:
   i.e. they process the defs before the uses.

   df_simulate_initialize_backwards should be called first with a
   bitvector copyied from the DF_LIVE_OUT or DF_LR_OUT.  Then
   df_simulate_one_insn_backwards should be called for each insn in
   the block, starting with the last one.  Finally,
   df_simulate_finalize_backwards can be called to get a new value
   of the sets at the top of the block (this is rarely used).
   ----------------------------------------------------------------------------*/

/* Apply the artificial uses and defs at the end of BB in a backwards
   direction.  */

void
df_simulate_initialize_backwards (basic_block bb, bitmap live)
{
  df_ref *def_rec;
  df_ref *use_rec;
  int bb_index = bb->index;

  for (def_rec = df_get_artificial_defs (bb_index); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      if ((DF_REF_FLAGS (def) & DF_REF_AT_TOP) == 0)
	bitmap_clear_bit (live, DF_REF_REGNO (def));
    }

  for (use_rec = df_get_artificial_uses (bb_index); *use_rec; use_rec++)
    {
      df_ref use = *use_rec;
      if ((DF_REF_FLAGS (use) & DF_REF_AT_TOP) == 0)
	bitmap_set_bit (live, DF_REF_REGNO (use));
    }
}


/* Simulate the backwards effects of INSN on the bitmap LIVE.  */

void
df_simulate_one_insn_backwards (basic_block bb, rtx insn, bitmap live)
{
  if (!NONDEBUG_INSN_P (insn))
    return;

  df_simulate_defs (insn, live);
  df_simulate_uses (insn, live);
  df_simulate_fixup_sets (bb, live);
}


/* Apply the artificial uses and defs at the top of BB in a backwards
   direction.  */

void
df_simulate_finalize_backwards (basic_block bb, bitmap live)
{
  df_ref *def_rec;
#ifdef EH_USES
  df_ref *use_rec;
#endif
  int bb_index = bb->index;

  for (def_rec = df_get_artificial_defs (bb_index); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      if (DF_REF_FLAGS (def) & DF_REF_AT_TOP)
	bitmap_clear_bit (live, DF_REF_REGNO (def));
    }

#ifdef EH_USES
  for (use_rec = df_get_artificial_uses (bb_index); *use_rec; use_rec++)
    {
      df_ref use = *use_rec;
      if (DF_REF_FLAGS (use) & DF_REF_AT_TOP)
	bitmap_set_bit (live, DF_REF_REGNO (use));
    }
#endif
}
/*----------------------------------------------------------------------------
   The following three functions are used only for FORWARDS scanning:
   i.e. they process the defs and the REG_DEAD and REG_UNUSED notes.
   Thus it is important to add the DF_NOTES problem to the stack of
   problems computed before using these functions.

   df_simulate_initialize_forwards should be called first with a
   bitvector copyied from the DF_LIVE_IN or DF_LR_IN.  Then
   df_simulate_one_insn_forwards should be called for each insn in
   the block, starting with the first one.
   ----------------------------------------------------------------------------*/

/* Initialize the LIVE bitmap, which should be copied from DF_LIVE_IN or
   DF_LR_IN for basic block BB, for forward scanning by marking artificial
   defs live.  */

void
df_simulate_initialize_forwards (basic_block bb, bitmap live)
{
  df_ref *def_rec;
  int bb_index = bb->index;

  for (def_rec = df_get_artificial_defs (bb_index); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      if (DF_REF_FLAGS (def) & DF_REF_AT_TOP)
	bitmap_set_bit (live, DF_REF_REGNO (def));
    }
}

/* Simulate the forwards effects of INSN on the bitmap LIVE.  */

void
df_simulate_one_insn_forwards (basic_block bb, rtx insn, bitmap live)
{
  rtx link;
  if (! INSN_P (insn))
    return;

  /* Make sure that DF_NOTE really is an active df problem.  */
  gcc_assert (df_note);

  /* Note that this is the opposite as how the problem is defined, because
     in the LR problem defs _kill_ liveness.  However, they do so backwards,
     while here the scan is performed forwards!  So, first assume that the
     def is live, and if this is not true REG_UNUSED notes will rectify the
     situation.  */
  df_simulate_find_noclobber_defs (insn, live);

  /* Clear all of the registers that go dead.  */
  for (link = REG_NOTES (insn); link; link = XEXP (link, 1))
    {
      switch (REG_NOTE_KIND (link))
	{
	case REG_DEAD:
	case REG_UNUSED:
	  {
	    rtx reg = XEXP (link, 0);
	    int regno = REGNO (reg);
	    if (HARD_REGISTER_NUM_P (regno))
	      bitmap_clear_range (live, regno,
				  hard_regno_nregs[regno][GET_MODE (reg)]);
	    else
	      bitmap_clear_bit (live, regno);
	  }
	  break;
	default:
	  break;
	}
    }
  df_simulate_fixup_sets (bb, live);
}

/* Used by the next two functions to encode information about the
   memory references we found.  */
#define MEMREF_NORMAL 1
#define MEMREF_VOLATILE 2

/* A subroutine of can_move_insns_across_p called through for_each_rtx.
   Return either MEMREF_NORMAL or MEMREF_VOLATILE if a memory is found.  */

static int
find_memory (rtx *px, void *data ATTRIBUTE_UNUSED)
{
  rtx x = *px;

  if (GET_CODE (x) == ASM_OPERANDS && MEM_VOLATILE_P (x))
    return MEMREF_VOLATILE;

  if (!MEM_P (x))
    return 0;
  if (MEM_VOLATILE_P (x))
    return MEMREF_VOLATILE;
  if (MEM_READONLY_P (x))
    return 0;

  return MEMREF_NORMAL;
}

/* A subroutine of can_move_insns_across_p called through note_stores.
   DATA points to an integer in which we set either the bit for
   MEMREF_NORMAL or the bit for MEMREF_VOLATILE if we find a MEM
   of either kind.  */

static void
find_memory_stores (rtx x, const_rtx pat ATTRIBUTE_UNUSED,
		    void *data ATTRIBUTE_UNUSED)
{
  int *pflags = (int *)data;
  if (GET_CODE (x) == SUBREG)
    x = XEXP (x, 0);
  /* Treat stores to SP as stores to memory, this will prevent problems
     when there are references to the stack frame.  */
  if (x == stack_pointer_rtx)
    *pflags |= MEMREF_VOLATILE;
  if (!MEM_P (x))
    return;
  *pflags |= MEM_VOLATILE_P (x) ? MEMREF_VOLATILE : MEMREF_NORMAL;
}

/* Scan BB backwards, using df_simulate functions to keep track of
   lifetimes, up to insn POINT.  The result is stored in LIVE.  */

void
simulate_backwards_to_point (basic_block bb, regset live, rtx point)
{
  rtx insn;
  bitmap_copy (live, df_get_live_out (bb));
  df_simulate_initialize_backwards (bb, live);

  /* Scan and update life information until we reach the point we're
     interested in.  */
  for (insn = BB_END (bb); insn != point; insn = PREV_INSN (insn))
    df_simulate_one_insn_backwards (bb, insn, live);
}

/* Return true if it is safe to move a group of insns, described by
   the range FROM to TO, backwards across another group of insns,
   described by ACROSS_FROM to ACROSS_TO.  It is assumed that there
   are no insns between ACROSS_TO and FROM, but they may be in
   different basic blocks; MERGE_BB is the block from which the
   insns will be moved.  The caller must pass in a regset MERGE_LIVE
   which specifies the registers live after TO.

   This function may be called in one of two cases: either we try to
   move identical instructions from all successor blocks into their
   predecessor, or we try to move from only one successor block.  If
   OTHER_BRANCH_LIVE is nonnull, it indicates that we're dealing with
   the second case.  It should contain a set of registers live at the
   end of ACROSS_TO which must not be clobbered by moving the insns.
   In that case, we're also more careful about moving memory references
   and trapping insns.

   We return false if it is not safe to move the entire group, but it
   may still be possible to move a subgroup.  PMOVE_UPTO, if nonnull,
   is set to point at the last moveable insn in such a case.  */

bool
can_move_insns_across (rtx from, rtx to, rtx across_from, rtx across_to,
		       basic_block merge_bb, regset merge_live,
		       regset other_branch_live, rtx *pmove_upto)
{
  rtx insn, next, max_to;
  bitmap merge_set, merge_use, local_merge_live;
  bitmap test_set, test_use;
  unsigned i, fail = 0;
  bitmap_iterator bi;
  int memrefs_in_across = 0;
  int mem_sets_in_across = 0;
  bool trapping_insns_in_across = false;

  if (pmove_upto != NULL)
    *pmove_upto = NULL_RTX;

  /* Find real bounds, ignoring debug insns.  */
  while (!NONDEBUG_INSN_P (from) && from != to)
    from = NEXT_INSN (from);
  while (!NONDEBUG_INSN_P (to) && from != to)
    to = PREV_INSN (to);

  for (insn = across_to; ; insn = next)
    {
      if (NONDEBUG_INSN_P (insn))
	{
	  memrefs_in_across |= for_each_rtx (&PATTERN (insn), find_memory,
					     NULL);
	  note_stores (PATTERN (insn), find_memory_stores,
		       &mem_sets_in_across);
	  /* This is used just to find sets of the stack pointer.  */
	  memrefs_in_across |= mem_sets_in_across;
	  trapping_insns_in_across |= may_trap_p (PATTERN (insn));
	}
      next = PREV_INSN (insn);
      if (insn == across_from)
	break;
    }

  /* Collect:
     MERGE_SET = set of registers set in MERGE_BB
     MERGE_USE = set of registers used in MERGE_BB and live at its top
     MERGE_LIVE = set of registers live at the point inside the MERGE
     range that we've reached during scanning
     TEST_SET = set of registers set between ACROSS_FROM and ACROSS_END.
     TEST_USE = set of registers used between ACROSS_FROM and ACROSS_END,
     and live before ACROSS_FROM.  */

  merge_set = BITMAP_ALLOC (&reg_obstack);
  merge_use = BITMAP_ALLOC (&reg_obstack);
  local_merge_live = BITMAP_ALLOC (&reg_obstack);
  test_set = BITMAP_ALLOC (&reg_obstack);
  test_use = BITMAP_ALLOC (&reg_obstack);

  /* Compute the set of registers set and used in the ACROSS range.  */
  if (other_branch_live != NULL)
    bitmap_copy (test_use, other_branch_live);
  df_simulate_initialize_backwards (merge_bb, test_use);
  for (insn = across_to; ; insn = next)
    {
      if (NONDEBUG_INSN_P (insn))
	{
	  df_simulate_find_defs (insn, test_set);
	  df_simulate_defs (insn, test_use);
	  df_simulate_uses (insn, test_use);
	}
      next = PREV_INSN (insn);
      if (insn == across_from)
	break;
    }

  /* Compute an upper bound for the amount of insns moved, by finding
     the first insn in MERGE that sets a register in TEST_USE, or uses
     a register in TEST_SET.  We also check for calls, trapping operations,
     and memory references.  */
  max_to = NULL_RTX;
  for (insn = from; ; insn = next)
    {
      if (CALL_P (insn))
	break;
      if (NOTE_P (insn) && NOTE_KIND (insn) == NOTE_INSN_EPILOGUE_BEG)
	break;
      if (NONDEBUG_INSN_P (insn))
	{
	  if (may_trap_or_fault_p (PATTERN (insn))
	      && (trapping_insns_in_across || other_branch_live != NULL))
	    break;

	  /* We cannot move memory stores past each other, or move memory
	     reads past stores, at least not without tracking them and
	     calling true_dependence on every pair.

	     If there is no other branch and no memory references or
	     sets in the ACROSS range, we can move memory references
	     freely, even volatile ones.

	     Otherwise, the rules are as follows: volatile memory
	     references and stores can't be moved at all, and any type
	     of memory reference can't be moved if there are volatile
	     accesses or stores in the ACROSS range.  That leaves
	     normal reads, which can be moved, as the trapping case is
	     dealt with elsewhere.  */
	  if (other_branch_live != NULL || memrefs_in_across != 0)
	    {
	      int mem_ref_flags = 0;
	      int mem_set_flags = 0;
	      note_stores (PATTERN (insn), find_memory_stores, &mem_set_flags);
	      mem_ref_flags = for_each_rtx (&PATTERN (insn), find_memory,
					    NULL);
	      /* Catch sets of the stack pointer.  */
	      mem_ref_flags |= mem_set_flags;

	      if ((mem_ref_flags | mem_set_flags) & MEMREF_VOLATILE)
		break;
	      if ((memrefs_in_across & MEMREF_VOLATILE) && mem_ref_flags != 0)
		break;
	      if (mem_set_flags != 0
		  || (mem_sets_in_across != 0 && mem_ref_flags != 0))
		break;
	    }
	  df_simulate_find_uses (insn, merge_use);
	  /* We're only interested in uses which use a value live at
	     the top, not one previously set in this block.  */
	  bitmap_and_compl_into (merge_use, merge_set);
	  df_simulate_find_defs (insn, merge_set);
	  if (bitmap_intersect_p (merge_set, test_use)
	      || bitmap_intersect_p (merge_use, test_set))
	    break;
#ifdef HAVE_cc0
	  if (!sets_cc0_p (insn))
#endif
	    max_to = insn;
	}
      next = NEXT_INSN (insn);
      if (insn == to)
	break;
    }
  if (max_to != to)
    fail = 1;

  if (max_to == NULL_RTX || (fail && pmove_upto == NULL))
    goto out;

  /* Now, lower this upper bound by also taking into account that
     a range of insns moved across ACROSS must not leave a register
     live at the end that will be clobbered in ACROSS.  We need to
     find a point where TEST_SET & LIVE == 0.

     Insns in the MERGE range that set registers which are also set
     in the ACROSS range may still be moved as long as we also move
     later insns which use the results of the set, and make the
     register dead again.  This is verified by the condition stated
     above.  We only need to test it for registers that are set in
     the moved region.

     MERGE_LIVE is provided by the caller and holds live registers after
     TO.  */
  bitmap_copy (local_merge_live, merge_live);
  for (insn = to; insn != max_to; insn = PREV_INSN (insn))
    df_simulate_one_insn_backwards (merge_bb, insn, local_merge_live);

  /* We're not interested in registers that aren't set in the moved
     region at all.  */
  bitmap_and_into (local_merge_live, merge_set);
  for (;;)
    {
      if (NONDEBUG_INSN_P (insn))
	{
	  if (!bitmap_intersect_p (test_set, local_merge_live)
#ifdef HAVE_cc0
	      && !sets_cc0_p (insn)
#endif
	      )
	    {
	      max_to = insn;
	      break;
	    }

	  df_simulate_one_insn_backwards (merge_bb, insn,
					  local_merge_live);
	}
      if (insn == from)
	{
	  fail = 1;
	  goto out;
	}
      insn = PREV_INSN (insn);
    }

  if (max_to != to)
    fail = 1;

  if (pmove_upto)
    *pmove_upto = max_to;

  /* For small register class machines, don't lengthen lifetimes of
     hard registers before reload.  */
  if (! reload_completed
      && targetm.small_register_classes_for_mode_p (VOIDmode))
    {
      EXECUTE_IF_SET_IN_BITMAP (merge_set, 0, i, bi)
	{
	  if (i < FIRST_PSEUDO_REGISTER
	      && ! fixed_regs[i]
	      && ! global_regs[i])
	    fail = 1;
	}
    }

 out:
  BITMAP_FREE (merge_set);
  BITMAP_FREE (merge_use);
  BITMAP_FREE (local_merge_live);
  BITMAP_FREE (test_set);
  BITMAP_FREE (test_use);

  return !fail;
}


/*----------------------------------------------------------------------------
   MULTIPLE DEFINITIONS

   Find the locations in the function reached by multiple definition sites
   for a live pseudo.  In and out bitvectors are built for each basic
   block.  They are restricted for efficiency to live registers.

   The gen and kill sets for the problem are obvious.  Together they
   include all defined registers in a basic block; the gen set includes
   registers where a partial or conditional or may-clobber definition is
   last in the BB, while the kill set includes registers with a complete
   definition coming last.  However, the computation of the dataflow
   itself is interesting.

   The idea behind it comes from SSA form's iterated dominance frontier
   criterion for inserting PHI functions.  Just like in that case, we can use
   the dominance frontier to find places where multiple definitions meet;
   a register X defined in a basic block BB1 has multiple definitions in
   basic blocks in BB1's dominance frontier.

   So, the in-set of a basic block BB2 is not just the union of the
   out-sets of BB2's predecessors, but includes some more bits that come
   from the basic blocks of whose dominance frontier BB2 is part (BB1 in
   the previous paragraph).  I called this set the init-set of BB2.

      (Note: I actually use the kill-set only to build the init-set.
      gen bits are anyway propagated from BB1 to BB2 by dataflow).

    For example, if you have

       BB1 : r10 = 0
             r11 = 0
             if <...> goto BB2 else goto BB3;

       BB2 : r10 = 1
             r12 = 1
             goto BB3;

       BB3 :

    you have BB3 in BB2's dominance frontier but not in BB1's, so that the
    init-set of BB3 includes r10 and r12, but not r11.  Note that we do
    not need to iterate the dominance frontier, because we do not insert
    anything like PHI functions there!  Instead, dataflow will take care of
    propagating the information to BB3's successors.
   ---------------------------------------------------------------------------*/

/* Private data used to verify the solution for this problem.  */
struct df_md_problem_data
{
  /* An obstack for the bitmaps we need for this problem.  */
  bitmap_obstack md_bitmaps;
};

/* Scratch var used by transfer functions.  This is used to do md analysis
   only for live registers.  */
static bitmap_head df_md_scratch;


static void
df_md_free_bb_info (basic_block bb ATTRIBUTE_UNUSED,
                    void *vbb_info)
{
  struct df_md_bb_info *bb_info = (struct df_md_bb_info *) vbb_info;
  if (bb_info)
    {
      bitmap_clear (&bb_info->kill);
      bitmap_clear (&bb_info->gen);
      bitmap_clear (&bb_info->init);
      bitmap_clear (&bb_info->in);
      bitmap_clear (&bb_info->out);
    }
}


/* Allocate or reset bitmaps for DF_MD. The solution bits are
   not touched unless the block is new.  */

static void
df_md_alloc (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;
  struct df_md_problem_data *problem_data;

  df_grow_bb_info (df_md);
  if (df_md->problem_data)
    problem_data = (struct df_md_problem_data *) df_md->problem_data;
  else
    {
      problem_data = XNEW (struct df_md_problem_data);
      df_md->problem_data = problem_data;
      bitmap_obstack_initialize (&problem_data->md_bitmaps);
    }
  bitmap_initialize (&df_md_scratch, &problem_data->md_bitmaps);

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      struct df_md_bb_info *bb_info = df_md_get_bb_info (bb_index);
      /* When bitmaps are already initialized, just clear them.  */
      if (bb_info->init.obstack)
        {
          bitmap_clear (&bb_info->init);
          bitmap_clear (&bb_info->gen);
          bitmap_clear (&bb_info->kill);
          bitmap_clear (&bb_info->in);
          bitmap_clear (&bb_info->out);
        }
      else
        {
	  bitmap_initialize (&bb_info->init, &problem_data->md_bitmaps);
	  bitmap_initialize (&bb_info->gen, &problem_data->md_bitmaps);
	  bitmap_initialize (&bb_info->kill, &problem_data->md_bitmaps);
	  bitmap_initialize (&bb_info->in, &problem_data->md_bitmaps);
	  bitmap_initialize (&bb_info->out, &problem_data->md_bitmaps);
        }
    }

  df_md->optional_p = true;
}

/* Add the effect of the top artificial defs of BB to the multiple definitions
   bitmap LOCAL_MD.  */

void
df_md_simulate_artificial_defs_at_top (basic_block bb, bitmap local_md)
{
  int bb_index = bb->index;
  df_ref *def_rec;
  for (def_rec = df_get_artificial_defs (bb_index); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      if (DF_REF_FLAGS (def) & DF_REF_AT_TOP)
	{
	  unsigned int dregno = DF_REF_REGNO (def);
	  if (DF_REF_FLAGS (def)
	      & (DF_REF_PARTIAL | DF_REF_CONDITIONAL | DF_REF_MAY_CLOBBER))
	    bitmap_set_bit (local_md, dregno);
	  else
	    bitmap_clear_bit (local_md, dregno);
	}
    }
}


/* Add the effect of the defs of INSN to the reaching definitions bitmap
   LOCAL_MD.  */

void
df_md_simulate_one_insn (basic_block bb ATTRIBUTE_UNUSED, rtx insn,
                        bitmap local_md)
{
  unsigned uid = INSN_UID (insn);
  df_ref *def_rec;

  for (def_rec = DF_INSN_UID_DEFS (uid); *def_rec; def_rec++)
    {
      df_ref def = *def_rec;
      unsigned int dregno = DF_REF_REGNO (def);
      if ((!(df->changeable_flags & DF_NO_HARD_REGS))
          || (dregno >= FIRST_PSEUDO_REGISTER))
        {
          if (DF_REF_FLAGS (def)
	      & (DF_REF_PARTIAL | DF_REF_CONDITIONAL | DF_REF_MAY_CLOBBER))
           bitmap_set_bit (local_md, DF_REF_ID (def));
         else
           bitmap_clear_bit (local_md, DF_REF_ID (def));
        }
    }
}

static void
df_md_bb_local_compute_process_def (struct df_md_bb_info *bb_info,
                                    df_ref *def_rec,
                                    int top_flag)
{
  df_ref def;
  bitmap_clear (&seen_in_insn);

  while ((def = *def_rec++) != NULL)
    {
      unsigned int dregno = DF_REF_REGNO (def);
      if (((!(df->changeable_flags & DF_NO_HARD_REGS))
	    || (dregno >= FIRST_PSEUDO_REGISTER))
	  && top_flag == (DF_REF_FLAGS (def) & DF_REF_AT_TOP))
	{
          if (!bitmap_bit_p (&seen_in_insn, dregno))
	    {
	      if (DF_REF_FLAGS (def)
	          & (DF_REF_PARTIAL | DF_REF_CONDITIONAL | DF_REF_MAY_CLOBBER))
	        {
	          bitmap_set_bit (&bb_info->gen, dregno);
	          bitmap_clear_bit (&bb_info->kill, dregno);
	        }
	      else
	        {
		  /* When we find a clobber and a regular def,
		     make sure the regular def wins.  */
	          bitmap_set_bit (&seen_in_insn, dregno);
	          bitmap_set_bit (&bb_info->kill, dregno);
	          bitmap_clear_bit (&bb_info->gen, dregno);
	        }
	    }
	}
    }
}


/* Compute local multiple def info for basic block BB.  */

static void
df_md_bb_local_compute (unsigned int bb_index)
{
  basic_block bb = BASIC_BLOCK (bb_index);
  struct df_md_bb_info *bb_info = df_md_get_bb_info (bb_index);
  rtx insn;

  /* Artificials are only hard regs.  */
  if (!(df->changeable_flags & DF_NO_HARD_REGS))
    df_md_bb_local_compute_process_def (bb_info,
                                        df_get_artificial_defs (bb_index),
                                        DF_REF_AT_TOP);

  FOR_BB_INSNS (bb, insn)
    {
      unsigned int uid = INSN_UID (insn);
      if (!INSN_P (insn))
        continue;

      df_md_bb_local_compute_process_def (bb_info, DF_INSN_UID_DEFS (uid), 0);
    }

  if (!(df->changeable_flags & DF_NO_HARD_REGS))
    df_md_bb_local_compute_process_def (bb_info,
                                        df_get_artificial_defs (bb_index),
                                        0);
}

/* Compute local reaching def info for each basic block within BLOCKS.  */

static void
df_md_local_compute (bitmap all_blocks)
{
  unsigned int bb_index, df_bb_index;
  bitmap_iterator bi1, bi2;
  basic_block bb;
  bitmap_head *frontiers;

  bitmap_initialize (&seen_in_insn, &bitmap_default_obstack);

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi1)
    {
      df_md_bb_local_compute (bb_index);
    }

  bitmap_clear (&seen_in_insn);

  frontiers = XNEWVEC (bitmap_head, last_basic_block);
  FOR_ALL_BB (bb)
    bitmap_initialize (&frontiers[bb->index], &bitmap_default_obstack);

  compute_dominance_frontiers (frontiers);

  /* Add each basic block's kills to the nodes in the frontier of the BB.  */
  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi1)
    {
      bitmap kill = &df_md_get_bb_info (bb_index)->kill;
      EXECUTE_IF_SET_IN_BITMAP (&frontiers[bb_index], 0, df_bb_index, bi2)
	{
	  basic_block bb = BASIC_BLOCK (df_bb_index);
	  if (bitmap_bit_p (all_blocks, df_bb_index))
	    bitmap_ior_and_into (&df_md_get_bb_info (df_bb_index)->init, kill,
				 df_get_live_in (bb));
	}
    }

  FOR_ALL_BB (bb)
    bitmap_clear (&frontiers[bb->index]);
  free (frontiers);
}


/* Reset the global solution for recalculation.  */

static void
df_md_reset (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      struct df_md_bb_info *bb_info = df_md_get_bb_info (bb_index);
      gcc_assert (bb_info);
      bitmap_clear (&bb_info->in);
      bitmap_clear (&bb_info->out);
    }
}

static bool
df_md_transfer_function (int bb_index)
{
  basic_block bb = BASIC_BLOCK (bb_index);
  struct df_md_bb_info *bb_info = df_md_get_bb_info (bb_index);
  bitmap in = &bb_info->in;
  bitmap out = &bb_info->out;
  bitmap gen = &bb_info->gen;
  bitmap kill = &bb_info->kill;

  /* We need to use a scratch set here so that the value returned from this
     function invocation properly reflects whether the sets changed in a
     significant way; i.e. not just because the live set was anded in.  */
  bitmap_and (&df_md_scratch, gen, df_get_live_out (bb));

  /* Multiple definitions of a register are not relevant if it is not
     live.  Thus we trim the result to the places where it is live.  */
  bitmap_and_into (in, df_get_live_in (bb));

  return bitmap_ior_and_compl (out, &df_md_scratch, in, kill);
}

/* Initialize the solution bit vectors for problem.  */

static void
df_md_init (bitmap all_blocks)
{
  unsigned int bb_index;
  bitmap_iterator bi;

  EXECUTE_IF_SET_IN_BITMAP (all_blocks, 0, bb_index, bi)
    {
      struct df_md_bb_info *bb_info = df_md_get_bb_info (bb_index);

      bitmap_copy (&bb_info->in, &bb_info->init);
      df_md_transfer_function (bb_index);
    }
}

static void
df_md_confluence_0 (basic_block bb)
{
  struct df_md_bb_info *bb_info = df_md_get_bb_info (bb->index);
  bitmap_copy (&bb_info->in, &bb_info->init);
}

/* In of target gets or of out of source.  */

static bool
df_md_confluence_n (edge e)
{
  bitmap op1 = &df_md_get_bb_info (e->dest->index)->in;
  bitmap op2 = &df_md_get_bb_info (e->src->index)->out;

  if (e->flags & EDGE_FAKE)
    return false;

  if (e->flags & EDGE_EH)
    return bitmap_ior_and_compl_into (op1, op2,
				      regs_invalidated_by_call_regset);
  else
    return bitmap_ior_into (op1, op2);
}

/* Free all storage associated with the problem.  */

static void
df_md_free (void)
{
  struct df_md_problem_data *problem_data
    = (struct df_md_problem_data *) df_md->problem_data;

  bitmap_obstack_release (&problem_data->md_bitmaps);
  free (problem_data);
  df_md->problem_data = NULL;

  df_md->block_info_size = 0;
  free (df_md->block_info);
  df_md->block_info = NULL;
  free (df_md);
}


/* Debugging info at top of bb.  */

static void
df_md_top_dump (basic_block bb, FILE *file)
{
  struct df_md_bb_info *bb_info = df_md_get_bb_info (bb->index);
  if (!bb_info)
    return;

  fprintf (file, ";; md  in  \t");
  df_print_regset (file, &bb_info->in);
  fprintf (file, ";; md  init  \t");
  df_print_regset (file, &bb_info->init);
  fprintf (file, ";; md  gen \t");
  df_print_regset (file, &bb_info->gen);
  fprintf (file, ";; md  kill \t");
  df_print_regset (file, &bb_info->kill);
}

/* Debugging info at bottom of bb.  */

static void
df_md_bottom_dump (basic_block bb, FILE *file)
{
  struct df_md_bb_info *bb_info = df_md_get_bb_info (bb->index);
  if (!bb_info)
    return;

  fprintf (file, ";; md  out \t");
  df_print_regset (file, &bb_info->out);
}

static struct df_problem problem_MD =
{
  DF_MD,                      /* Problem id.  */
  DF_FORWARD,                 /* Direction.  */
  df_md_alloc,                /* Allocate the problem specific data.  */
  df_md_reset,                /* Reset global information.  */
  df_md_free_bb_info,         /* Free basic block info.  */
  df_md_local_compute,        /* Local compute function.  */
  df_md_init,                 /* Init the solution specific data.  */
  df_worklist_dataflow,       /* Worklist solver.  */
  df_md_confluence_0,         /* Confluence operator 0.  */
  df_md_confluence_n,         /* Confluence operator n.  */
  df_md_transfer_function,    /* Transfer function.  */
  NULL,                       /* Finalize function.  */
  df_md_free,                 /* Free all of the problem information.  */
  df_md_free,                 /* Remove this problem from the stack of dataflow problems.  */
  NULL,                       /* Debugging.  */
  df_md_top_dump,             /* Debugging start block.  */
  df_md_bottom_dump,          /* Debugging end block.  */
  NULL,			      /* Incremental solution verify start.  */
  NULL,			      /* Incremental solution verify end.  */
  NULL,                       /* Dependent problem.  */
  sizeof (struct df_md_bb_info),/* Size of entry of block_info array.  */
  TV_DF_MD,                   /* Timing variable.  */
  false                       /* Reset blocks on dropping out of blocks_to_analyze.  */
};

/* Create a new MD instance and add it to the existing instance
   of DF.  */

void
df_md_add_problem (void)
{
  df_add_problem (&problem_MD);
}



