/* Convert tree expression to rtl instructions, for GNU compiler.
   Copyright (C) 1988, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,
   2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.

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
#include "coretypes.h"
#include "tm.h"
#include "machmode.h"
#include "real.h"
#include "rtl.h"
#include "tree.h"
#include "flags.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "except.h"
#include "function.h"
#include "insn-config.h"
#include "insn-attr.h"
/* Include expr.h after insn-config.h so we get HAVE_conditional_move.  */
#include "expr.h"
#include "optabs.h"
#include "libfuncs.h"
#include "recog.h"
#include "reload.h"
#include "output.h"
#include "typeclass.h"
#include "toplev.h"
#include "ggc.h"
#include "langhooks.h"
#include "intl.h"
#include "tm_p.h"
#include "tree-iterator.h"
#include "tree-pass.h"
#include "tree-flow.h"
#include "target.h"
#include "timevar.h"

/* Decide whether a function's arguments should be processed
   from first to last or from last to first.

   They should if the stack and args grow in opposite directions, but
   only if we have push insns.  */

#ifdef PUSH_ROUNDING

#ifndef PUSH_ARGS_REVERSED
#if defined (STACK_GROWS_DOWNWARD) != defined (ARGS_GROW_DOWNWARD)
#define PUSH_ARGS_REVERSED	/* If it's last to first.  */
#endif
#endif

#endif

#ifndef STACK_PUSH_CODE
#ifdef STACK_GROWS_DOWNWARD
#define STACK_PUSH_CODE PRE_DEC
#else
#define STACK_PUSH_CODE PRE_INC
#endif
#endif


/* If this is nonzero, we do not bother generating VOLATILE
   around volatile memory references, and we are willing to
   output indirect addresses.  If cse is to follow, we reject
   indirect addresses so a useful potential cse is generated;
   if it is used only once, instruction combination will produce
   the same indirect address eventually.  */
int cse_not_expected;

/* This structure is used by move_by_pieces to describe the move to
   be performed.  */
struct move_by_pieces
{
  rtx to;
  rtx to_addr;
  int autinc_to;
  int explicit_inc_to;
  rtx from;
  rtx from_addr;
  int autinc_from;
  int explicit_inc_from;
  unsigned HOST_WIDE_INT len;
  HOST_WIDE_INT offset;
  int reverse;
};

/* This structure is used by store_by_pieces to describe the clear to
   be performed.  */

struct store_by_pieces
{
  rtx to;
  rtx to_addr;
  int autinc_to;
  int explicit_inc_to;
  unsigned HOST_WIDE_INT len;
  HOST_WIDE_INT offset;
  rtx (*constfun) (void *, HOST_WIDE_INT, enum machine_mode);
  void *constfundata;
  int reverse;
};

static unsigned HOST_WIDE_INT move_by_pieces_ninsns (unsigned HOST_WIDE_INT,
						     unsigned int,
						     unsigned int);
static void move_by_pieces_1 (rtx (*) (rtx, ...), enum machine_mode,
			      struct move_by_pieces *);
static bool block_move_libcall_safe_for_call_parm (void);
static bool emit_block_move_via_movmem (rtx, rtx, rtx, unsigned);
static rtx emit_block_move_via_libcall (rtx, rtx, rtx);
static tree emit_block_move_libcall_fn (int);
static void emit_block_move_via_loop (rtx, rtx, rtx, unsigned);
static rtx clear_by_pieces_1 (void *, HOST_WIDE_INT, enum machine_mode);
static void clear_by_pieces (rtx, unsigned HOST_WIDE_INT, unsigned int);
static void store_by_pieces_1 (struct store_by_pieces *, unsigned int);
static void store_by_pieces_2 (rtx (*) (rtx, ...), enum machine_mode,
			       struct store_by_pieces *);
static bool clear_storage_via_clrmem (rtx, rtx, unsigned);
static rtx clear_storage_via_libcall (rtx, rtx);
static tree clear_storage_libcall_fn (int);
static rtx compress_float_constant (rtx, rtx);
static rtx get_subtarget (rtx);
static void store_constructor_field (rtx, unsigned HOST_WIDE_INT,
				     HOST_WIDE_INT, enum machine_mode,
				     tree, tree, int, int);
static void store_constructor (tree, rtx, int, HOST_WIDE_INT);
static rtx store_field (rtx, HOST_WIDE_INT, HOST_WIDE_INT, enum machine_mode,
			tree, enum machine_mode, int, tree, int);

static unsigned HOST_WIDE_INT highest_pow2_factor (tree);
static unsigned HOST_WIDE_INT highest_pow2_factor_for_target (tree, tree);

static int is_aligning_offset (tree, tree);
static void expand_operands (tree, tree, rtx, rtx*, rtx*,
			     enum expand_modifier);
static rtx reduce_to_bit_field_precision (rtx, rtx, tree);
static rtx do_store_flag (tree, rtx, enum machine_mode, int);
#ifdef PUSH_ROUNDING
static void emit_single_push_insn (enum machine_mode, rtx, tree);
#endif
static void do_tablejump (rtx, enum machine_mode, rtx, rtx, rtx);
static rtx const_vector_from_tree (tree);

/* Record for each mode whether we can move a register directly to or
   from an object of that mode in memory.  If we can't, we won't try
   to use that mode directly when accessing a field of that mode.  */

static char direct_load[NUM_MACHINE_MODES];
static char direct_store[NUM_MACHINE_MODES];

/* Record for each mode whether we can float-extend from memory.  */

static bool float_extend_from_mem[NUM_MACHINE_MODES][NUM_MACHINE_MODES];

/* This macro is used to determine whether move_by_pieces should be called
   to perform a structure copy.  */
#ifndef MOVE_BY_PIECES_P
#define MOVE_BY_PIECES_P(SIZE, ALIGN) \
  (move_by_pieces_ninsns (SIZE, ALIGN, MOVE_MAX_PIECES + 1) \
   < (unsigned int) MOVE_RATIO)
#endif

/* This macro is used to determine whether clear_by_pieces should be
   called to clear storage.  */
#ifndef CLEAR_BY_PIECES_P
#define CLEAR_BY_PIECES_P(SIZE, ALIGN) \
  (move_by_pieces_ninsns (SIZE, ALIGN, STORE_MAX_PIECES + 1) \
   < (unsigned int) CLEAR_RATIO)
#endif

/* This macro is used to determine whether store_by_pieces should be
   called to "memset" storage with byte values other than zero, or
   to "memcpy" storage when the source is a constant string.  */
#ifndef STORE_BY_PIECES_P
#define STORE_BY_PIECES_P(SIZE, ALIGN) \
  (move_by_pieces_ninsns (SIZE, ALIGN, STORE_MAX_PIECES + 1) \
   < (unsigned int) MOVE_RATIO)
#endif

/* This array records the insn_code of insns to perform block moves.  */
enum insn_code movmem_optab[NUM_MACHINE_MODES];

/* This array records the insn_code of insns to perform block clears.  */
enum insn_code clrmem_optab[NUM_MACHINE_MODES];

/* These arrays record the insn_code of two different kinds of insns
   to perform block compares.  */
enum insn_code cmpstr_optab[NUM_MACHINE_MODES];
enum insn_code cmpmem_optab[NUM_MACHINE_MODES];

/* SLOW_UNALIGNED_ACCESS is nonzero if unaligned accesses are very slow.  */

#ifndef SLOW_UNALIGNED_ACCESS
#define SLOW_UNALIGNED_ACCESS(MODE, ALIGN) STRICT_ALIGNMENT
#endif

/* This is run once per compilation to set up which modes can be used
   directly in memory and to initialize the block move optab.  */

void
init_expr_once (void)
{
  rtx insn, pat;
  enum machine_mode mode;
  int num_clobbers;
  rtx mem, mem1;
  rtx reg;

  /* Try indexing by frame ptr and try by stack ptr.
     It is known that on the Convex the stack ptr isn't a valid index.
     With luck, one or the other is valid on any machine.  */
  mem = gen_rtx_MEM (VOIDmode, stack_pointer_rtx);
  mem1 = gen_rtx_MEM (VOIDmode, frame_pointer_rtx);

  /* A scratch register we can modify in-place below to avoid
     useless RTL allocations.  */
  reg = gen_rtx_REG (VOIDmode, -1);

  insn = rtx_alloc (INSN);
  pat = gen_rtx_SET (0, NULL_RTX, NULL_RTX);
  PATTERN (insn) = pat;

  for (mode = VOIDmode; (int) mode < NUM_MACHINE_MODES;
       mode = (enum machine_mode) ((int) mode + 1))
    {
      int regno;

      direct_load[(int) mode] = direct_store[(int) mode] = 0;
      PUT_MODE (mem, mode);
      PUT_MODE (mem1, mode);
      PUT_MODE (reg, mode);

      /* See if there is some register that can be used in this mode and
	 directly loaded or stored from memory.  */

      if (mode != VOIDmode && mode != BLKmode)
	for (regno = 0; regno < FIRST_PSEUDO_REGISTER
	     && (direct_load[(int) mode] == 0 || direct_store[(int) mode] == 0);
	     regno++)
	  {
	    if (! HARD_REGNO_MODE_OK (regno, mode))
	      continue;

	    REGNO (reg) = regno;

	    SET_SRC (pat) = mem;
	    SET_DEST (pat) = reg;
	    if (recog (pat, insn, &num_clobbers) >= 0)
	      direct_load[(int) mode] = 1;

	    SET_SRC (pat) = mem1;
	    SET_DEST (pat) = reg;
	    if (recog (pat, insn, &num_clobbers) >= 0)
	      direct_load[(int) mode] = 1;

	    SET_SRC (pat) = reg;
	    SET_DEST (pat) = mem;
	    if (recog (pat, insn, &num_clobbers) >= 0)
	      direct_store[(int) mode] = 1;

	    SET_SRC (pat) = reg;
	    SET_DEST (pat) = mem1;
	    if (recog (pat, insn, &num_clobbers) >= 0)
	      direct_store[(int) mode] = 1;
	  }
    }

  mem = gen_rtx_MEM (VOIDmode, gen_rtx_raw_REG (Pmode, 10000));

  for (mode = GET_CLASS_NARROWEST_MODE (MODE_FLOAT); mode != VOIDmode;
       mode = GET_MODE_WIDER_MODE (mode))
    {
      enum machine_mode srcmode;
      for (srcmode = GET_CLASS_NARROWEST_MODE (MODE_FLOAT); srcmode != mode;
	   srcmode = GET_MODE_WIDER_MODE (srcmode))
	{
	  enum insn_code ic;

	  ic = can_extend_p (mode, srcmode, 0);
	  if (ic == CODE_FOR_nothing)
	    continue;

	  PUT_MODE (mem, srcmode);

	  if ((*insn_data[ic].operand[1].predicate) (mem, srcmode))
	    float_extend_from_mem[mode][srcmode] = true;
	}
    }
}

/* This is run at the start of compiling a function.  */

void
init_expr (void)
{
  cfun->expr = ggc_alloc_cleared (sizeof (struct expr_status));
}

/* Copy data from FROM to TO, where the machine modes are not the same.
   Both modes may be integer, or both may be floating.
   UNSIGNEDP should be nonzero if FROM is an unsigned type.
   This causes zero-extension instead of sign-extension.  */

void
convert_move (rtx to, rtx from, int unsignedp)
{
  enum machine_mode to_mode = GET_MODE (to);
  enum machine_mode from_mode = GET_MODE (from);
  int to_real = GET_MODE_CLASS (to_mode) == MODE_FLOAT;
  int from_real = GET_MODE_CLASS (from_mode) == MODE_FLOAT;
  enum insn_code code;
  rtx libcall;

  /* rtx code for making an equivalent value.  */
  enum rtx_code equiv_code = (unsignedp < 0 ? UNKNOWN
			      : (unsignedp ? ZERO_EXTEND : SIGN_EXTEND));


  if (to_real != from_real)
    abort ();

  /* If the source and destination are already the same, then there's
     nothing to do.  */
  if (to == from)
    return;

  /* If FROM is a SUBREG that indicates that we have already done at least
     the required extension, strip it.  We don't handle such SUBREGs as
     TO here.  */

  if (GET_CODE (from) == SUBREG && SUBREG_PROMOTED_VAR_P (from)
      && (GET_MODE_SIZE (GET_MODE (SUBREG_REG (from)))
	  >= GET_MODE_SIZE (to_mode))
      && SUBREG_PROMOTED_UNSIGNED_P (from) == unsignedp)
    from = gen_lowpart (to_mode, from), from_mode = to_mode;

  if (GET_CODE (to) == SUBREG && SUBREG_PROMOTED_VAR_P (to))
    abort ();

  if (to_mode == from_mode
      || (from_mode == VOIDmode && CONSTANT_P (from)))
    {
      emit_move_insn (to, from);
      return;
    }

  if (VECTOR_MODE_P (to_mode) || VECTOR_MODE_P (from_mode))
    {
      if (GET_MODE_BITSIZE (from_mode) != GET_MODE_BITSIZE (to_mode))
	abort ();

      if (VECTOR_MODE_P (to_mode))
	from = simplify_gen_subreg (to_mode, from, GET_MODE (from), 0);
      else
	to = simplify_gen_subreg (from_mode, to, GET_MODE (to), 0);

      emit_move_insn (to, from);
      return;
    }

  if (GET_CODE (to) == CONCAT && GET_CODE (from) == CONCAT)
    {
      convert_move (XEXP (to, 0), XEXP (from, 0), unsignedp);
      convert_move (XEXP (to, 1), XEXP (from, 1), unsignedp);
      return;
    }

  if (to_real)
    {
      rtx value, insns;
      convert_optab tab;

      if (GET_MODE_PRECISION (from_mode) < GET_MODE_PRECISION (to_mode))
	tab = sext_optab;
      else if (GET_MODE_PRECISION (from_mode) > GET_MODE_PRECISION (to_mode))
	tab = trunc_optab;
      else
	abort ();

      /* Try converting directly if the insn is supported.  */

      code = tab->handlers[to_mode][from_mode].insn_code;
      if (code != CODE_FOR_nothing)
	{
	  emit_unop_insn (code, to, from,
			  tab == sext_optab ? FLOAT_EXTEND : FLOAT_TRUNCATE);
	  return;
	}

      /* Otherwise use a libcall.  */
      libcall = tab->handlers[to_mode][from_mode].libfunc;

      if (!libcall)
	/* This conversion is not implemented yet.  */
	abort ();

      start_sequence ();
      value = emit_library_call_value (libcall, NULL_RTX, LCT_CONST, to_mode,
				       1, from, from_mode);
      insns = get_insns ();
      end_sequence ();
      emit_libcall_block (insns, to, value,
			  tab == trunc_optab ? gen_rtx_FLOAT_TRUNCATE (to_mode,
								       from)
			  : gen_rtx_FLOAT_EXTEND (to_mode, from));
      return;
    }

  /* Handle pointer conversion.  */			/* SPEE 900220.  */
  /* Targets are expected to provide conversion insns between PxImode and
     xImode for all MODE_PARTIAL_INT modes they use, but no others.  */
  if (GET_MODE_CLASS (to_mode) == MODE_PARTIAL_INT)
    {
      enum machine_mode full_mode
	= smallest_mode_for_size (GET_MODE_BITSIZE (to_mode), MODE_INT);

      if (trunc_optab->handlers[to_mode][full_mode].insn_code
	  == CODE_FOR_nothing)
	abort ();

      if (full_mode != from_mode)
	from = convert_to_mode (full_mode, from, unsignedp);
      emit_unop_insn (trunc_optab->handlers[to_mode][full_mode].insn_code,
		      to, from, UNKNOWN);
      return;
    }
  if (GET_MODE_CLASS (from_mode) == MODE_PARTIAL_INT)
    {
      enum machine_mode full_mode
	= smallest_mode_for_size (GET_MODE_BITSIZE (from_mode), MODE_INT);

      if (sext_optab->handlers[full_mode][from_mode].insn_code
	  == CODE_FOR_nothing)
	abort ();

      emit_unop_insn (sext_optab->handlers[full_mode][from_mode].insn_code,
		      to, from, UNKNOWN);
      if (to_mode == full_mode)
	return;

      /* else proceed to integer conversions below.  */
      from_mode = full_mode;
    }

  /* Now both modes are integers.  */

  /* Handle expanding beyond a word.  */
  if (GET_MODE_BITSIZE (from_mode) < GET_MODE_BITSIZE (to_mode)
      && GET_MODE_BITSIZE (to_mode) > BITS_PER_WORD)
    {
      rtx insns;
      rtx lowpart;
      rtx fill_value;
      rtx lowfrom;
      int i;
      enum machine_mode lowpart_mode;
      int nwords = CEIL (GET_MODE_SIZE (to_mode), UNITS_PER_WORD);

      /* Try converting directly if the insn is supported.  */
      if ((code = can_extend_p (to_mode, from_mode, unsignedp))
	  != CODE_FOR_nothing)
	{
	  /* If FROM is a SUBREG, put it into a register.  Do this
	     so that we always generate the same set of insns for
	     better cse'ing; if an intermediate assignment occurred,
	     we won't be doing the operation directly on the SUBREG.  */
	  if (optimize > 0 && GET_CODE (from) == SUBREG)
	    from = force_reg (from_mode, from);
	  emit_unop_insn (code, to, from, equiv_code);
	  return;
	}
      /* Next, try converting via full word.  */
      else if (GET_MODE_BITSIZE (from_mode) < BITS_PER_WORD
	       && ((code = can_extend_p (to_mode, word_mode, unsignedp))
		   != CODE_FOR_nothing))
	{
	  if (REG_P (to))
	    {
	      if (reg_overlap_mentioned_p (to, from))
		from = force_reg (from_mode, from);
	      emit_insn (gen_rtx_CLOBBER (VOIDmode, to));
	    }
	  convert_move (gen_lowpart (word_mode, to), from, unsignedp);
	  emit_unop_insn (code, to,
			  gen_lowpart (word_mode, to), equiv_code);
	  return;
	}

      /* No special multiword conversion insn; do it by hand.  */
      start_sequence ();

      /* Since we will turn this into a no conflict block, we must ensure
	 that the source does not overlap the target.  */

      if (reg_overlap_mentioned_p (to, from))
	from = force_reg (from_mode, from);

      /* Get a copy of FROM widened to a word, if necessary.  */
      if (GET_MODE_BITSIZE (from_mode) < BITS_PER_WORD)
	lowpart_mode = word_mode;
      else
	lowpart_mode = from_mode;

      lowfrom = convert_to_mode (lowpart_mode, from, unsignedp);

      lowpart = gen_lowpart (lowpart_mode, to);
      emit_move_insn (lowpart, lowfrom);

      /* Compute the value to put in each remaining word.  */
      if (unsignedp)
	fill_value = const0_rtx;
      else
	{
#ifdef HAVE_slt
	  if (HAVE_slt
	      && insn_data[(int) CODE_FOR_slt].operand[0].mode == word_mode
	      && STORE_FLAG_VALUE == -1)
	    {
	      emit_cmp_insn (lowfrom, const0_rtx, NE, NULL_RTX,
			     lowpart_mode, 0);
	      fill_value = gen_reg_rtx (word_mode);
	      emit_insn (gen_slt (fill_value));
	    }
	  else
#endif
	    {
	      fill_value
		= expand_shift (RSHIFT_EXPR, lowpart_mode, lowfrom,
				size_int (GET_MODE_BITSIZE (lowpart_mode) - 1),
				NULL_RTX, 0);
	      fill_value = convert_to_mode (word_mode, fill_value, 1);
	    }
	}

      /* Fill the remaining words.  */
      for (i = GET_MODE_SIZE (lowpart_mode) / UNITS_PER_WORD; i < nwords; i++)
	{
	  int index = (WORDS_BIG_ENDIAN ? nwords - i - 1 : i);
	  rtx subword = operand_subword (to, index, 1, to_mode);

	  if (subword == 0)
	    abort ();

	  if (fill_value != subword)
	    emit_move_insn (subword, fill_value);
	}

      insns = get_insns ();
      end_sequence ();

      emit_no_conflict_block (insns, to, from, NULL_RTX,
			      gen_rtx_fmt_e (equiv_code, to_mode, copy_rtx (from)));
      return;
    }

  /* Truncating multi-word to a word or less.  */
  if (GET_MODE_BITSIZE (from_mode) > BITS_PER_WORD
      && GET_MODE_BITSIZE (to_mode) <= BITS_PER_WORD)
    {
      if (!((MEM_P (from)
	     && ! MEM_VOLATILE_P (from)
	     && direct_load[(int) to_mode]
	     && ! mode_dependent_address_p (XEXP (from, 0)))
	    || REG_P (from)
	    || GET_CODE (from) == SUBREG))
	from = force_reg (from_mode, from);
      convert_move (to, gen_lowpart (word_mode, from), 0);
      return;
    }

  /* Now follow all the conversions between integers
     no more than a word long.  */

  /* For truncation, usually we can just refer to FROM in a narrower mode.  */
  if (GET_MODE_BITSIZE (to_mode) < GET_MODE_BITSIZE (from_mode)
      && TRULY_NOOP_TRUNCATION (GET_MODE_BITSIZE (to_mode),
				GET_MODE_BITSIZE (from_mode)))
    {
      if (!((MEM_P (from)
	     && ! MEM_VOLATILE_P (from)
	     && direct_load[(int) to_mode]
	     && ! mode_dependent_address_p (XEXP (from, 0)))
	    || REG_P (from)
	    || GET_CODE (from) == SUBREG))
	from = force_reg (from_mode, from);
      if (REG_P (from) && REGNO (from) < FIRST_PSEUDO_REGISTER
	  && ! HARD_REGNO_MODE_OK (REGNO (from), to_mode))
	from = copy_to_reg (from);
      emit_move_insn (to, gen_lowpart (to_mode, from));
      return;
    }

  /* Handle extension.  */
  if (GET_MODE_BITSIZE (to_mode) > GET_MODE_BITSIZE (from_mode))
    {
      /* Convert directly if that works.  */
      if ((code = can_extend_p (to_mode, from_mode, unsignedp))
	  != CODE_FOR_nothing)
	{
	  if (flag_force_mem)
	    from = force_not_mem (from);

	  emit_unop_insn (code, to, from, equiv_code);
	  return;
	}
      else
	{
	  enum machine_mode intermediate;
	  rtx tmp;
	  tree shift_amount;

	  /* Search for a mode to convert via.  */
	  for (intermediate = from_mode; intermediate != VOIDmode;
	       intermediate = GET_MODE_WIDER_MODE (intermediate))
	    if (((can_extend_p (to_mode, intermediate, unsignedp)
		  != CODE_FOR_nothing)
		 || (GET_MODE_SIZE (to_mode) < GET_MODE_SIZE (intermediate)
		     && TRULY_NOOP_TRUNCATION (GET_MODE_BITSIZE (to_mode),
					       GET_MODE_BITSIZE (intermediate))))
		&& (can_extend_p (intermediate, from_mode, unsignedp)
		    != CODE_FOR_nothing))
	      {
		convert_move (to, convert_to_mode (intermediate, from,
						   unsignedp), unsignedp);
		return;
	      }

	  /* No suitable intermediate mode.
	     Generate what we need with	shifts.  */
	  shift_amount = build_int_cst (NULL_TREE,
					GET_MODE_BITSIZE (to_mode)
					- GET_MODE_BITSIZE (from_mode), 0);
	  from = gen_lowpart (to_mode, force_reg (from_mode, from));
	  tmp = expand_shift (LSHIFT_EXPR, to_mode, from, shift_amount,
			      to, unsignedp);
	  tmp = expand_shift (RSHIFT_EXPR, to_mode, tmp, shift_amount,
			      to, unsignedp);
	  if (tmp != to)
	    emit_move_insn (to, tmp);
	  return;
	}
    }

  /* Support special truncate insns for certain modes.  */
  if (trunc_optab->handlers[to_mode][from_mode].insn_code != CODE_FOR_nothing)
    {
      emit_unop_insn (trunc_optab->handlers[to_mode][from_mode].insn_code,
		      to, from, UNKNOWN);
      return;
    }

  /* Handle truncation of volatile memrefs, and so on;
     the things that couldn't be truncated directly,
     and for which there was no special instruction.

     ??? Code above formerly short-circuited this, for most integer
     mode pairs, with a force_reg in from_mode followed by a recursive
     call to this routine.  Appears always to have been wrong.  */
  if (GET_MODE_BITSIZE (to_mode) < GET_MODE_BITSIZE (from_mode))
    {
      rtx temp = force_reg (to_mode, gen_lowpart (to_mode, from));
      emit_move_insn (to, temp);
      return;
    }

  /* Mode combination is not recognized.  */
  abort ();
}

/* Return an rtx for a value that would result
   from converting X to mode MODE.
   Both X and MODE may be floating, or both integer.
   UNSIGNEDP is nonzero if X is an unsigned value.
   This can be done by referring to a part of X in place
   or by copying to a new temporary with conversion.  */

rtx
convert_to_mode (enum machine_mode mode, rtx x, int unsignedp)
{
  return convert_modes (mode, VOIDmode, x, unsignedp);
}

/* Return an rtx for a value that would result
   from converting X from mode OLDMODE to mode MODE.
   Both modes may be floating, or both integer.
   UNSIGNEDP is nonzero if X is an unsigned value.

   This can be done by referring to a part of X in place
   or by copying to a new temporary with conversion.

   You can give VOIDmode for OLDMODE, if you are sure X has a nonvoid mode.  */

rtx
convert_modes (enum machine_mode mode, enum machine_mode oldmode, rtx x, int unsignedp)
{
  rtx temp;

  /* If FROM is a SUBREG that indicates that we have already done at least
     the required extension, strip it.  */

  if (GET_CODE (x) == SUBREG && SUBREG_PROMOTED_VAR_P (x)
      && GET_MODE_SIZE (GET_MODE (SUBREG_REG (x))) >= GET_MODE_SIZE (mode)
      && SUBREG_PROMOTED_UNSIGNED_P (x) == unsignedp)
    x = gen_lowpart (mode, x);

  if (GET_MODE (x) != VOIDmode)
    oldmode = GET_MODE (x);

  if (mode == oldmode)
    return x;

  /* There is one case that we must handle specially: If we are converting
     a CONST_INT into a mode whose size is twice HOST_BITS_PER_WIDE_INT and
     we are to interpret the constant as unsigned, gen_lowpart will do
     the wrong if the constant appears negative.  What we want to do is
     make the high-order word of the constant zero, not all ones.  */

  if (unsignedp && GET_MODE_CLASS (mode) == MODE_INT
      && GET_MODE_BITSIZE (mode) == 2 * HOST_BITS_PER_WIDE_INT
      && GET_CODE (x) == CONST_INT && INTVAL (x) < 0)
    {
      HOST_WIDE_INT val = INTVAL (x);

      if (oldmode != VOIDmode
	  && HOST_BITS_PER_WIDE_INT > GET_MODE_BITSIZE (oldmode))
	{
	  int width = GET_MODE_BITSIZE (oldmode);

	  /* We need to zero extend VAL.  */
	  val &= ((HOST_WIDE_INT) 1 << width) - 1;
	}

      return immed_double_const (val, (HOST_WIDE_INT) 0, mode);
    }

  /* We can do this with a gen_lowpart if both desired and current modes
     are integer, and this is either a constant integer, a register, or a
     non-volatile MEM.  Except for the constant case where MODE is no
     wider than HOST_BITS_PER_WIDE_INT, we must be narrowing the operand.  */

  if ((GET_CODE (x) == CONST_INT
       && GET_MODE_BITSIZE (mode) <= HOST_BITS_PER_WIDE_INT)
      || (GET_MODE_CLASS (mode) == MODE_INT
	  && GET_MODE_CLASS (oldmode) == MODE_INT
	  && (GET_CODE (x) == CONST_DOUBLE
	      || (GET_MODE_SIZE (mode) <= GET_MODE_SIZE (oldmode)
		  && ((MEM_P (x) && ! MEM_VOLATILE_P (x)
		       && direct_load[(int) mode])
		      || (REG_P (x)
			  && (! HARD_REGISTER_P (x)
			      || HARD_REGNO_MODE_OK (REGNO (x), mode))
			  && TRULY_NOOP_TRUNCATION (GET_MODE_BITSIZE (mode),
						    GET_MODE_BITSIZE (GET_MODE (x)))))))))
    {
      /* ?? If we don't know OLDMODE, we have to assume here that
	 X does not need sign- or zero-extension.   This may not be
	 the case, but it's the best we can do.  */
      if (GET_CODE (x) == CONST_INT && oldmode != VOIDmode
	  && GET_MODE_SIZE (mode) > GET_MODE_SIZE (oldmode))
	{
	  HOST_WIDE_INT val = INTVAL (x);
	  int width = GET_MODE_BITSIZE (oldmode);

	  /* We must sign or zero-extend in this case.  Start by
	     zero-extending, then sign extend if we need to.  */
	  val &= ((HOST_WIDE_INT) 1 << width) - 1;
	  if (! unsignedp
	      && (val & ((HOST_WIDE_INT) 1 << (width - 1))))
	    val |= (HOST_WIDE_INT) (-1) << width;

	  return gen_int_mode (val, mode);
	}

      return gen_lowpart (mode, x);
    }

  /* Converting from integer constant into mode is always equivalent to an
     subreg operation.  */
  if (VECTOR_MODE_P (mode) && GET_MODE (x) == VOIDmode)
    {
      if (GET_MODE_BITSIZE (mode) != GET_MODE_BITSIZE (oldmode))
	abort ();
      return simplify_gen_subreg (mode, x, oldmode, 0);
    }

  temp = gen_reg_rtx (mode);
  convert_move (temp, x, unsignedp);
  return temp;
}

/* STORE_MAX_PIECES is the number of bytes at a time that we can
   store efficiently.  Due to internal GCC limitations, this is
   MOVE_MAX_PIECES limited by the number of bytes GCC can represent
   for an immediate constant.  */

#define STORE_MAX_PIECES  MIN (MOVE_MAX_PIECES, 2 * sizeof (HOST_WIDE_INT))

/* Determine whether the LEN bytes can be moved by using several move
   instructions.  Return nonzero if a call to move_by_pieces should
   succeed.  */

int
can_move_by_pieces (unsigned HOST_WIDE_INT len,
		    unsigned int align ATTRIBUTE_UNUSED)
{
  return MOVE_BY_PIECES_P (len, align);
}

/* Generate several move instructions to copy LEN bytes from block FROM to
   block TO.  (These are MEM rtx's with BLKmode).

   If PUSH_ROUNDING is defined and TO is NULL, emit_single_push_insn is
   used to push FROM to the stack.

   ALIGN is maximum stack alignment we can assume.

   If ENDP is 0 return to, if ENDP is 1 return memory at the end ala
   mempcpy, and if ENDP is 2 return memory the end minus one byte ala
   stpcpy.  */

rtx
move_by_pieces (rtx to, rtx from, unsigned HOST_WIDE_INT len,
		unsigned int align, int endp)
{
  struct move_by_pieces data;
  rtx to_addr, from_addr = XEXP (from, 0);
  unsigned int max_size = MOVE_MAX_PIECES + 1;
  enum machine_mode mode = VOIDmode, tmode;
  enum insn_code icode;

  align = MIN (to ? MEM_ALIGN (to) : align, MEM_ALIGN (from));

  data.offset = 0;
  data.from_addr = from_addr;
  if (to)
    {
      to_addr = XEXP (to, 0);
      data.to = to;
      data.autinc_to
	= (GET_CODE (to_addr) == PRE_INC || GET_CODE (to_addr) == PRE_DEC
	   || GET_CODE (to_addr) == POST_INC || GET_CODE (to_addr) == POST_DEC);
      data.reverse
	= (GET_CODE (to_addr) == PRE_DEC || GET_CODE (to_addr) == POST_DEC);
    }
  else
    {
      to_addr = NULL_RTX;
      data.to = NULL_RTX;
      data.autinc_to = 1;
#ifdef STACK_GROWS_DOWNWARD
      data.reverse = 1;
#else
      data.reverse = 0;
#endif
    }
  data.to_addr = to_addr;
  data.from = from;
  data.autinc_from
    = (GET_CODE (from_addr) == PRE_INC || GET_CODE (from_addr) == PRE_DEC
       || GET_CODE (from_addr) == POST_INC
       || GET_CODE (from_addr) == POST_DEC);

  data.explicit_inc_from = 0;
  data.explicit_inc_to = 0;
  if (data.reverse) data.offset = len;
  data.len = len;

  /* If copying requires more than two move insns,
     copy addresses to registers (to make displacements shorter)
     and use post-increment if available.  */
  if (!(data.autinc_from && data.autinc_to)
      && move_by_pieces_ninsns (len, align, max_size) > 2)
    {
      /* Find the mode of the largest move...  */
      for (tmode = GET_CLASS_NARROWEST_MODE (MODE_INT);
	   tmode != VOIDmode; tmode = GET_MODE_WIDER_MODE (tmode))
	if (GET_MODE_SIZE (tmode) < max_size)
	  mode = tmode;

      if (USE_LOAD_PRE_DECREMENT (mode) && data.reverse && ! data.autinc_from)
	{
	  data.from_addr = copy_addr_to_reg (plus_constant (from_addr, len));
	  data.autinc_from = 1;
	  data.explicit_inc_from = -1;
	}
      if (USE_LOAD_POST_INCREMENT (mode) && ! data.autinc_from)
	{
	  data.from_addr = copy_addr_to_reg (from_addr);
	  data.autinc_from = 1;
	  data.explicit_inc_from = 1;
	}
      if (!data.autinc_from && CONSTANT_P (from_addr))
	data.from_addr = copy_addr_to_reg (from_addr);
      if (USE_STORE_PRE_DECREMENT (mode) && data.reverse && ! data.autinc_to)
	{
	  data.to_addr = copy_addr_to_reg (plus_constant (to_addr, len));
	  data.autinc_to = 1;
	  data.explicit_inc_to = -1;
	}
      if (USE_STORE_POST_INCREMENT (mode) && ! data.reverse && ! data.autinc_to)
	{
	  data.to_addr = copy_addr_to_reg (to_addr);
	  data.autinc_to = 1;
	  data.explicit_inc_to = 1;
	}
      if (!data.autinc_to && CONSTANT_P (to_addr))
	data.to_addr = copy_addr_to_reg (to_addr);
    }

  tmode = mode_for_size (MOVE_MAX_PIECES * BITS_PER_UNIT, MODE_INT, 1);
  if (align >= GET_MODE_ALIGNMENT (tmode))
    align = GET_MODE_ALIGNMENT (tmode);
  else
    {
      enum machine_mode xmode;

      for (tmode = GET_CLASS_NARROWEST_MODE (MODE_INT), xmode = tmode;
	   tmode != VOIDmode;
	   xmode = tmode, tmode = GET_MODE_WIDER_MODE (tmode))
	if (GET_MODE_SIZE (tmode) > MOVE_MAX_PIECES
	    || SLOW_UNALIGNED_ACCESS (tmode, align))
	  break;

      align = MAX (align, GET_MODE_ALIGNMENT (xmode));
    }

  /* First move what we can in the largest integer mode, then go to
     successively smaller modes.  */

  while (max_size > 1)
    {
      for (tmode = GET_CLASS_NARROWEST_MODE (MODE_INT);
	   tmode != VOIDmode; tmode = GET_MODE_WIDER_MODE (tmode))
	if (GET_MODE_SIZE (tmode) < max_size)
	  mode = tmode;

      if (mode == VOIDmode)
	break;

      icode = mov_optab->handlers[(int) mode].insn_code;
      if (icode != CODE_FOR_nothing && align >= GET_MODE_ALIGNMENT (mode))
	move_by_pieces_1 (GEN_FCN (icode), mode, &data);

      max_size = GET_MODE_SIZE (mode);
    }

  /* The code above should have handled everything.  */
  if (data.len > 0)
    abort ();

  if (endp)
    {
      rtx to1;

      if (data.reverse)
	abort ();
      if (data.autinc_to)
	{
	  if (endp == 2)
	    {
	      if (HAVE_POST_INCREMENT && data.explicit_inc_to > 0)
		emit_insn (gen_add2_insn (data.to_addr, constm1_rtx));
	      else
		data.to_addr = copy_addr_to_reg (plus_constant (data.to_addr,
								-1));
	    }
	  to1 = adjust_automodify_address (data.to, QImode, data.to_addr,
					   data.offset);
	}
      else
	{
	  if (endp == 2)
	    --data.offset;
	  to1 = adjust_address (data.to, QImode, data.offset);
	}
      return to1;
    }
  else
    return data.to;
}

/* Return number of insns required to move L bytes by pieces.
   ALIGN (in bits) is maximum alignment we can assume.  */

static unsigned HOST_WIDE_INT
move_by_pieces_ninsns (unsigned HOST_WIDE_INT l, unsigned int align,
		       unsigned int max_size)
{
  unsigned HOST_WIDE_INT n_insns = 0;
  enum machine_mode tmode;

  tmode = mode_for_size (MOVE_MAX_PIECES * BITS_PER_UNIT, MODE_INT, 1);
  if (align >= GET_MODE_ALIGNMENT (tmode))
    align = GET_MODE_ALIGNMENT (tmode);
  else
    {
      enum machine_mode tmode, xmode;

      for (tmode = GET_CLASS_NARROWEST_MODE (MODE_INT), xmode = tmode;
	   tmode != VOIDmode;
	   xmode = tmode, tmode = GET_MODE_WIDER_MODE (tmode))
	if (GET_MODE_SIZE (tmode) > MOVE_MAX_PIECES
	    || SLOW_UNALIGNED_ACCESS (tmode, align))
	  break;

      align = MAX (align, GET_MODE_ALIGNMENT (xmode));
    }

  while (max_size > 1)
    {
      enum machine_mode mode = VOIDmode;
      enum insn_code icode;

      for (tmode = GET_CLASS_NARROWEST_MODE (MODE_INT);
	   tmode != VOIDmode; tmode = GET_MODE_WIDER_MODE (tmode))
	if (GET_MODE_SIZE (tmode) < max_size)
	  mode = tmode;

      if (mode == VOIDmode)
	break;

      icode = mov_optab->handlers[(int) mode].insn_code;
      if (icode != CODE_FOR_nothing && align >= GET_MODE_ALIGNMENT (mode))
	n_insns += l / GET_MODE_SIZE (mode), l %= GET_MODE_SIZE (mode);

      max_size = GET_MODE_SIZE (mode);
    }

  if (l)
    abort ();
  return n_insns;
}

/* Subroutine of move_by_pieces.  Move as many bytes as appropriate
   with move instructions for mode MODE.  GENFUN is the gen_... function
   to make a move insn for that mode.  DATA has all the other info.  */

static void
move_by_pieces_1 (rtx (*genfun) (rtx, ...), enum machine_mode mode,
		  struct move_by_pieces *data)
{
  unsigned int size = GET_MODE_SIZE (mode);
  rtx to1 = NULL_RTX, from1;

  while (data->len >= size)
    {
      if (data->reverse)
	data->offset -= size;

      if (data->to)
	{
	  if (data->autinc_to)
	    to1 = adjust_automodify_address (data->to, mode, data->to_addr,
					     data->offset);
	  else
	    to1 = adjust_address (data->to, mode, data->offset);
	}

      if (data->autinc_from)
	from1 = adjust_automodify_address (data->from, mode, data->from_addr,
					   data->offset);
      else
	from1 = adjust_address (data->from, mode, data->offset);

      if (HAVE_PRE_DECREMENT && data->explicit_inc_to < 0)
	emit_insn (gen_add2_insn (data->to_addr,
				  GEN_INT (-(HOST_WIDE_INT)size)));
      if (HAVE_PRE_DECREMENT && data->explicit_inc_from < 0)
	emit_insn (gen_add2_insn (data->from_addr,
				  GEN_INT (-(HOST_WIDE_INT)size)));

      if (data->to)
	emit_insn ((*genfun) (to1, from1));
      else
	{
#ifdef PUSH_ROUNDING
	  emit_single_push_insn (mode, from1, NULL);
#else
	  abort ();
#endif
	}

      if (HAVE_POST_INCREMENT && data->explicit_inc_to > 0)
	emit_insn (gen_add2_insn (data->to_addr, GEN_INT (size)));
      if (HAVE_POST_INCREMENT && data->explicit_inc_from > 0)
	emit_insn (gen_add2_insn (data->from_addr, GEN_INT (size)));

      if (! data->reverse)
	data->offset += size;

      data->len -= size;
    }
}

/* Emit code to move a block Y to a block X.  This may be done with
   string-move instructions, with multiple scalar move instructions,
   or with a library call.

   Both X and Y must be MEM rtx's (perhaps inside VOLATILE) with mode BLKmode.
   SIZE is an rtx that says how long they are.
   ALIGN is the maximum alignment we can assume they have.
   METHOD describes what kind of copy this is, and what mechanisms may be used.

   Return the address of the new block, if memcpy is called and returns it,
   0 otherwise.  */

rtx
emit_block_move (rtx x, rtx y, rtx size, enum block_op_methods method)
{
  bool may_use_call;
  rtx retval = 0;
  unsigned int align;

  switch (method)
    {
    case BLOCK_OP_NORMAL:
      may_use_call = true;
      break;

    case BLOCK_OP_CALL_PARM:
      may_use_call = block_move_libcall_safe_for_call_parm ();

      /* Make inhibit_defer_pop nonzero around the library call
	 to force it to pop the arguments right away.  */
      NO_DEFER_POP;
      break;

    case BLOCK_OP_NO_LIBCALL:
      may_use_call = false;
      break;

    default:
      abort ();
    }

  align = MIN (MEM_ALIGN (x), MEM_ALIGN (y));

  if (!MEM_P (x))
    abort ();
  if (!MEM_P (y))
    abort ();
  if (size == 0)
    abort ();

  /* Make sure we've got BLKmode addresses; store_one_arg can decide that
     block copy is more efficient for other large modes, e.g. DCmode.  */
  x = adjust_address (x, BLKmode, 0);
  y = adjust_address (y, BLKmode, 0);

  /* Set MEM_SIZE as appropriate for this block copy.  The main place this
     can be incorrect is coming from __builtin_memcpy.  */
  if (GET_CODE (size) == CONST_INT)
    {
      if (INTVAL (size) == 0)
	return 0;

      x = shallow_copy_rtx (x);
      y = shallow_copy_rtx (y);
      set_mem_size (x, size);
      set_mem_size (y, size);
    }

  if (GET_CODE (size) == CONST_INT && MOVE_BY_PIECES_P (INTVAL (size), align))
    move_by_pieces (x, y, INTVAL (size), align, 0);
  else if (emit_block_move_via_movmem (x, y, size, align))
    ;
  else if (may_use_call)
    retval = emit_block_move_via_libcall (x, y, size);
  else
    emit_block_move_via_loop (x, y, size, align);

  if (method == BLOCK_OP_CALL_PARM)
    OK_DEFER_POP;

  return retval;
}

/* A subroutine of emit_block_move.  Returns true if calling the
   block move libcall will not clobber any parameters which may have
   already been placed on the stack.  */

static bool
block_move_libcall_safe_for_call_parm (void)
{
  /* If arguments are pushed on the stack, then they're safe.  */
  if (PUSH_ARGS)
    return true;

  /* If registers go on the stack anyway, any argument is sure to clobber
     an outgoing argument.  */
#if defined (REG_PARM_STACK_SPACE) && defined (OUTGOING_REG_PARM_STACK_SPACE)
  {
    tree fn = emit_block_move_libcall_fn (false);
    (void) fn;
    if (REG_PARM_STACK_SPACE (fn) != 0)
      return false;
  }
#endif

  /* If any argument goes in memory, then it might clobber an outgoing
     argument.  */
  {
    CUMULATIVE_ARGS args_so_far;
    tree fn, arg;

    fn = emit_block_move_libcall_fn (false);
    INIT_CUMULATIVE_ARGS (args_so_far, TREE_TYPE (fn), NULL_RTX, 0, 3);

    arg = TYPE_ARG_TYPES (TREE_TYPE (fn));
    for ( ; arg != void_list_node ; arg = TREE_CHAIN (arg))
      {
	enum machine_mode mode = TYPE_MODE (TREE_VALUE (arg));
	rtx tmp = FUNCTION_ARG (args_so_far, mode, NULL_TREE, 1);
	if (!tmp || !REG_P (tmp))
	  return false;
	if (FUNCTION_ARG_PARTIAL_NREGS (args_so_far, mode,
					NULL_TREE, 1))
	  return false;
	FUNCTION_ARG_ADVANCE (args_so_far, mode, NULL_TREE, 1);
      }
  }
  return true;
}

/* A subroutine of emit_block_move.  Expand a movmem pattern;
   return true if successful.  */

static bool
emit_block_move_via_movmem (rtx x, rtx y, rtx size, unsigned int align)
{
  rtx opalign = GEN_INT (align / BITS_PER_UNIT);
  int save_volatile_ok = volatile_ok;
  enum machine_mode mode;

  /* Since this is a move insn, we don't care about volatility.  */
  volatile_ok = 1;

  /* Try the most limited insn first, because there's no point
     including more than one in the machine description unless
     the more limited one has some advantage.  */

  for (mode = GET_CLASS_NARROWEST_MODE (MODE_INT); mode != VOIDmode;
       mode = GET_MODE_WIDER_MODE (mode))
    {
      enum insn_code code = movmem_optab[(int) mode];
      insn_operand_predicate_fn pred;

      if (code != CODE_FOR_nothing
	  /* We don't need MODE to be narrower than BITS_PER_HOST_WIDE_INT
	     here because if SIZE is less than the mode mask, as it is
	     returned by the macro, it will definitely be less than the
	     actual mode mask.  */
	  && ((GET_CODE (size) == CONST_INT
	       && ((unsigned HOST_WIDE_INT) INTVAL (size)
		   <= (GET_MODE_MASK (mode) >> 1)))
	      || GET_MODE_BITSIZE (mode) >= BITS_PER_WORD)
	  && ((pred = insn_data[(int) code].operand[0].predicate) == 0
	      || (*pred) (x, BLKmode))
	  && ((pred = insn_data[(int) code].operand[1].predicate) == 0
	      || (*pred) (y, BLKmode))
	  && ((pred = insn_data[(int) code].operand[3].predicate) == 0
	      || (*pred) (opalign, VOIDmode)))
	{
	  rtx op2;
	  rtx last = get_last_insn ();
	  rtx pat;

	  op2 = convert_to_mode (mode, size, 1);
	  pred = insn_data[(int) code].operand[2].predicate;
	  if (pred != 0 && ! (*pred) (op2, mode))
	    op2 = copy_to_mode_reg (mode, op2);

	  /* ??? When called via emit_block_move_for_call, it'd be
	     nice if there were some way to inform the backend, so
	     that it doesn't fail the expansion because it thinks
	     emitting the libcall would be more efficient.  */

	  pat = GEN_FCN ((int) code) (x, y, op2, opalign);
	  if (pat)
	    {
	      emit_insn (pat);
	      volatile_ok = save_volatile_ok;
	      return true;
	    }
	  else
	    delete_insns_since (last);
	}
    }

  volatile_ok = save_volatile_ok;
  return false;
}

/* A subroutine of emit_block_move.  Expand a call to memcpy.
   Return the return value from memcpy, 0 otherwise.  */

static rtx
emit_block_move_via_libcall (rtx dst, rtx src, rtx size)
{
  rtx dst_addr, src_addr;
  tree call_expr, arg_list, fn, src_tree, dst_tree, size_tree;
  enum machine_mode size_mode;
  rtx retval;

  /* Emit code to copy the addresses of DST and SRC and SIZE into new
     pseudos.  We can then place those new pseudos into a VAR_DECL and
     use them later.  */

  dst_addr = copy_to_mode_reg (Pmode, XEXP (dst, 0));
  src_addr = copy_to_mode_reg (Pmode, XEXP (src, 0));

  dst_addr = convert_memory_address (ptr_mode, dst_addr);
  src_addr = convert_memory_address (ptr_mode, src_addr);

  dst_tree = make_tree (ptr_type_node, dst_addr);
  src_tree = make_tree (ptr_type_node, src_addr);

  size_mode = TYPE_MODE (sizetype);

  size = convert_to_mode (size_mode, size, 1);
  size = copy_to_mode_reg (size_mode, size);

  /* It is incorrect to use the libcall calling conventions to call
     memcpy in this context.  This could be a user call to memcpy and
     the user may wish to examine the return value from memcpy.  For
     targets where libcalls and normal calls have different conventions
     for returning pointers, we could end up generating incorrect code.  */

  size_tree = make_tree (sizetype, size);

  fn = emit_block_move_libcall_fn (true);
  arg_list = tree_cons (NULL_TREE, size_tree, NULL_TREE);
  arg_list = tree_cons (NULL_TREE, src_tree, arg_list);
  arg_list = tree_cons (NULL_TREE, dst_tree, arg_list);

  /* Now we have to build up the CALL_EXPR itself.  */
  call_expr = build1 (ADDR_EXPR, build_pointer_type (TREE_TYPE (fn)), fn);
  call_expr = build3 (CALL_EXPR, TREE_TYPE (TREE_TYPE (fn)),
		      call_expr, arg_list, NULL_TREE);

  retval = expand_expr (call_expr, NULL_RTX, VOIDmode, 0);

  return retval;
}

/* A subroutine of emit_block_move_via_libcall.  Create the tree node
   for the function we use for block copies.  The first time FOR_CALL
   is true, we call assemble_external.  */

static GTY(()) tree block_move_fn;

void
init_block_move_fn (const char *asmspec)
{
  if (!block_move_fn)
    {
      tree args, fn;

      fn = get_identifier ("memcpy");
      args = build_function_type_list (ptr_type_node, ptr_type_node,
				       const_ptr_type_node, sizetype,
				       NULL_TREE);

      fn = build_decl (FUNCTION_DECL, fn, args);
      DECL_EXTERNAL (fn) = 1;
      TREE_PUBLIC (fn) = 1;
      DECL_ARTIFICIAL (fn) = 1;
      TREE_NOTHROW (fn) = 1;

      block_move_fn = fn;
    }

  if (asmspec)
    set_user_assembler_name (block_move_fn, asmspec);
}

static tree
emit_block_move_libcall_fn (int for_call)
{
  static bool emitted_extern;

  if (!block_move_fn)
    init_block_move_fn (NULL);

  if (for_call && !emitted_extern)
    {
      emitted_extern = true;
      make_decl_rtl (block_move_fn);
      assemble_external (block_move_fn);
    }

  return block_move_fn;
}

/* A subroutine of emit_block_move.  Copy the data via an explicit
   loop.  This is used only when libcalls are forbidden.  */
/* ??? It'd be nice to copy in hunks larger than QImode.  */

static void
emit_block_move_via_loop (rtx x, rtx y, rtx size,
			  unsigned int align ATTRIBUTE_UNUSED)
{
  rtx cmp_label, top_label, iter, x_addr, y_addr, tmp;
  enum machine_mode iter_mode;

  iter_mode = GET_MODE (size);
  if (iter_mode == VOIDmode)
    iter_mode = word_mode;

  top_label = gen_label_rtx ();
  cmp_label = gen_label_rtx ();
  iter = gen_reg_rtx (iter_mode);

  emit_move_insn (iter, const0_rtx);

  x_addr = force_operand (XEXP (x, 0), NULL_RTX);
  y_addr = force_operand (XEXP (y, 0), NULL_RTX);
  do_pending_stack_adjust ();

  emit_jump (cmp_label);
  emit_label (top_label);

  tmp = convert_modes (Pmode, iter_mode, iter, true);
  x_addr = gen_rtx_PLUS (Pmode, x_addr, tmp);
  y_addr = gen_rtx_PLUS (Pmode, y_addr, tmp);
  x = change_address (x, QImode, x_addr);
  y = change_address (y, QImode, y_addr);

  emit_move_insn (x, y);

  tmp = expand_simple_binop (iter_mode, PLUS, iter, const1_rtx, iter,
			     true, OPTAB_LIB_WIDEN);
  if (tmp != iter)
    emit_move_insn (iter, tmp);

  emit_label (cmp_label);

  emit_cmp_and_jump_insns (iter, size, LT, NULL_RTX, iter_mode,
			   true, top_label);
}

/* Copy all or part of a value X into registers starting at REGNO.
   The number of registers to be filled is NREGS.  */

void
move_block_to_reg (int regno, rtx x, int nregs, enum machine_mode mode)
{
  int i;
#ifdef HAVE_load_multiple
  rtx pat;
  rtx last;
#endif

  if (nregs == 0)
    return;

  if (CONSTANT_P (x) && ! LEGITIMATE_CONSTANT_P (x))
    x = validize_mem (force_const_mem (mode, x));

  /* See if the machine can do this with a load multiple insn.  */
#ifdef HAVE_load_multiple
  if (HAVE_load_multiple)
    {
      last = get_last_insn ();
      pat = gen_load_multiple (gen_rtx_REG (word_mode, regno), x,
			       GEN_INT (nregs));
      if (pat)
	{
	  emit_insn (pat);
	  return;
	}
      else
	delete_insns_since (last);
    }
#endif

  for (i = 0; i < nregs; i++)
    emit_move_insn (gen_rtx_REG (word_mode, regno + i),
		    operand_subword_force (x, i, mode));
}

/* Copy all or part of a BLKmode value X out of registers starting at REGNO.
   The number of registers to be filled is NREGS.  */

void
move_block_from_reg (int regno, rtx x, int nregs)
{
  int i;

  if (nregs == 0)
    return;

  /* See if the machine can do this with a store multiple insn.  */
#ifdef HAVE_store_multiple
  if (HAVE_store_multiple)
    {
      rtx last = get_last_insn ();
      rtx pat = gen_store_multiple (x, gen_rtx_REG (word_mode, regno),
				    GEN_INT (nregs));
      if (pat)
	{
	  emit_insn (pat);
	  return;
	}
      else
	delete_insns_since (last);
    }
#endif

  for (i = 0; i < nregs; i++)
    {
      rtx tem = operand_subword (x, i, 1, BLKmode);

      if (tem == 0)
	abort ();

      emit_move_insn (tem, gen_rtx_REG (word_mode, regno + i));
    }
}

/* Generate a PARALLEL rtx for a new non-consecutive group of registers from
   ORIG, where ORIG is a non-consecutive group of registers represented by
   a PARALLEL.  The clone is identical to the original except in that the
   original set of registers is replaced by a new set of pseudo registers.
   The new set has the same modes as the original set.  */

rtx
gen_group_rtx (rtx orig)
{
  int i, length;
  rtx *tmps;

  if (GET_CODE (orig) != PARALLEL)
    abort ();

  length = XVECLEN (orig, 0);
  tmps = alloca (sizeof (rtx) * length);

  /* Skip a NULL entry in first slot.  */
  i = XEXP (XVECEXP (orig, 0, 0), 0) ? 0 : 1;

  if (i)
    tmps[0] = 0;

  for (; i < length; i++)
    {
      enum machine_mode mode = GET_MODE (XEXP (XVECEXP (orig, 0, i), 0));
      rtx offset = XEXP (XVECEXP (orig, 0, i), 1);

      tmps[i] = gen_rtx_EXPR_LIST (VOIDmode, gen_reg_rtx (mode), offset);
    }

  return gen_rtx_PARALLEL (GET_MODE (orig), gen_rtvec_v (length, tmps));
}

/* Emit code to move a block ORIG_SRC of type TYPE to a block DST,
   where DST is non-consecutive registers represented by a PARALLEL.
   SSIZE represents the total size of block ORIG_SRC in bytes, or -1
   if not known.  */

void
emit_group_load (rtx dst, rtx orig_src, tree type ATTRIBUTE_UNUSED, int ssize)
{
  rtx *tmps, src;
  int start, i;

  if (GET_CODE (dst) != PARALLEL)
    abort ();

  /* Check for a NULL entry, used to indicate that the parameter goes
     both on the stack and in registers.  */
  if (XEXP (XVECEXP (dst, 0, 0), 0))
    start = 0;
  else
    start = 1;

  tmps = alloca (sizeof (rtx) * XVECLEN (dst, 0));

  /* Process the pieces.  */
  for (i = start; i < XVECLEN (dst, 0); i++)
    {
      enum machine_mode mode = GET_MODE (XEXP (XVECEXP (dst, 0, i), 0));
      HOST_WIDE_INT bytepos = INTVAL (XEXP (XVECEXP (dst, 0, i), 1));
      unsigned int bytelen = GET_MODE_SIZE (mode);
      int shift = 0;

      /* Handle trailing fragments that run over the size of the struct.  */
      if (ssize >= 0 && bytepos + (HOST_WIDE_INT) bytelen > ssize)
	{
	  /* Arrange to shift the fragment to where it belongs.
	     extract_bit_field loads to the lsb of the reg.  */
	  if (
#ifdef BLOCK_REG_PADDING
	      BLOCK_REG_PADDING (GET_MODE (orig_src), type, i == start)
	      == (BYTES_BIG_ENDIAN ? upward : downward)
#else
	      BYTES_BIG_ENDIAN
#endif
	      )
	    shift = (bytelen - (ssize - bytepos)) * BITS_PER_UNIT;
	  bytelen = ssize - bytepos;
	  if (bytelen <= 0)
	    abort ();
	}

      /* If we won't be loading directly from memory, protect the real source
	 from strange tricks we might play; but make sure that the source can
	 be loaded directly into the destination.  */
      src = orig_src;
      if (!MEM_P (orig_src)
	  && (!CONSTANT_P (orig_src)
	      || (GET_MODE (orig_src) != mode
		  && GET_MODE (orig_src) != VOIDmode)))
	{
	  if (GET_MODE (orig_src) == VOIDmode)
	    src = gen_reg_rtx (mode);
	  else
	    src = gen_reg_rtx (GET_MODE (orig_src));

	  emit_move_insn (src, orig_src);
	}

      /* Optimize the access just a bit.  */
      if (MEM_P (src)
	  && (! SLOW_UNALIGNED_ACCESS (mode, MEM_ALIGN (src))
	      || MEM_ALIGN (src) >= GET_MODE_ALIGNMENT (mode))
	  && bytepos * BITS_PER_UNIT % GET_MODE_ALIGNMENT (mode) == 0
	  && bytelen == GET_MODE_SIZE (mode))
	{
	  tmps[i] = gen_reg_rtx (mode);
	  emit_move_insn (tmps[i], adjust_address (src, mode, bytepos));
	}
      else if (GET_CODE (src) == CONCAT)
	{
	  unsigned int slen = GET_MODE_SIZE (GET_MODE (src));
	  unsigned int slen0 = GET_MODE_SIZE (GET_MODE (XEXP (src, 0)));

	  if ((bytepos == 0 && bytelen == slen0)
	      || (bytepos != 0 && bytepos + bytelen <= slen))
	    {
	      /* The following assumes that the concatenated objects all
		 have the same size.  In this case, a simple calculation
		 can be used to determine the object and the bit field
		 to be extracted.  */
	      tmps[i] = XEXP (src, bytepos / slen0);
	      if (! CONSTANT_P (tmps[i])
		  && (!REG_P (tmps[i]) || GET_MODE (tmps[i]) != mode))
		tmps[i] = extract_bit_field (tmps[i], bytelen * BITS_PER_UNIT,
					     (bytepos % slen0) * BITS_PER_UNIT,
					     1, NULL_RTX, mode, mode);
	    }
	  else if (bytepos == 0)
	    {
	      rtx mem = assign_stack_temp (GET_MODE (src), slen, 0);
	      emit_move_insn (mem, src);
	      tmps[i] = adjust_address (mem, mode, 0);
	    }
	  else
	    abort ();
	}
      /* FIXME: A SIMD parallel will eventually lead to a subreg of a
	 SIMD register, which is currently broken.  While we get GCC
	 to emit proper RTL for these cases, let's dump to memory.  */
      else if (VECTOR_MODE_P (GET_MODE (dst))
	       && REG_P (src))
	{
	  int slen = GET_MODE_SIZE (GET_MODE (src));
	  rtx mem;

	  mem = assign_stack_temp (GET_MODE (src), slen, 0);
	  emit_move_insn (mem, src);
	  tmps[i] = adjust_address (mem, mode, (int) bytepos);
	}
      else if (CONSTANT_P (src) && GET_MODE (dst) != BLKmode
               && XVECLEN (dst, 0) > 1)
        tmps[i] = simplify_gen_subreg (mode, src, GET_MODE(dst), bytepos);
      else if (CONSTANT_P (src)
	       || (REG_P (src) && GET_MODE (src) == mode))
	tmps[i] = src;
      else
	tmps[i] = extract_bit_field (src, bytelen * BITS_PER_UNIT,
				     bytepos * BITS_PER_UNIT, 1, NULL_RTX,
				     mode, mode);

      if (shift)
	tmps[i] = expand_shift (LSHIFT_EXPR, mode, tmps[i],
				build_int_cst (NULL_TREE,
					       shift, 0), tmps[i], 0);
    }

  /* Copy the extracted pieces into the proper (probable) hard regs.  */
  for (i = start; i < XVECLEN (dst, 0); i++)
    emit_move_insn (XEXP (XVECEXP (dst, 0, i), 0), tmps[i]);
}

/* Emit code to move a block SRC to block DST, where SRC and DST are
   non-consecutive groups of registers, each represented by a PARALLEL.  */

void
emit_group_move (rtx dst, rtx src)
{
  int i;

  if (GET_CODE (src) != PARALLEL
      || GET_CODE (dst) != PARALLEL
      || XVECLEN (src, 0) != XVECLEN (dst, 0))
    abort ();

  /* Skip first entry if NULL.  */
  for (i = XEXP (XVECEXP (src, 0, 0), 0) ? 0 : 1; i < XVECLEN (src, 0); i++)
    emit_move_insn (XEXP (XVECEXP (dst, 0, i), 0),
		    XEXP (XVECEXP (src, 0, i), 0));
}

/* Emit code to move a block SRC to a block ORIG_DST of type TYPE,
   where SRC is non-consecutive registers represented by a PARALLEL.
   SSIZE represents the total size of block ORIG_DST, or -1 if not
   known.  */

void
emit_group_store (rtx orig_dst, rtx src, tree type ATTRIBUTE_UNUSED, int ssize)
{
  rtx *tmps, dst;
  int start, i;

  if (GET_CODE (src) != PARALLEL)
    abort ();

  /* Check for a NULL entry, used to indicate that the parameter goes
     both on the stack and in registers.  */
  if (XEXP (XVECEXP (src, 0, 0), 0))
    start = 0;
  else
    start = 1;

  tmps = alloca (sizeof (rtx) * XVECLEN (src, 0));

  /* Copy the (probable) hard regs into pseudos.  */
  for (i = start; i < XVECLEN (src, 0); i++)
    {
      rtx reg = XEXP (XVECEXP (src, 0, i), 0);
      tmps[i] = gen_reg_rtx (GET_MODE (reg));
      emit_move_insn (tmps[i], reg);
    }

  /* If we won't be storing directly into memory, protect the real destination
     from strange tricks we might play.  */
  dst = orig_dst;
  if (GET_CODE (dst) == PARALLEL)
    {
      rtx temp;

      /* We can get a PARALLEL dst if there is a conditional expression in
	 a return statement.  In that case, the dst and src are the same,
	 so no action is necessary.  */
      if (rtx_equal_p (dst, src))
	return;

      /* It is unclear if we can ever reach here, but we may as well handle
	 it.  Allocate a temporary, and split this into a store/load to/from
	 the temporary.  */

      temp = assign_stack_temp (GET_MODE (dst), ssize, 0);
      emit_group_store (temp, src, type, ssize);
      emit_group_load (dst, temp, type, ssize);
      return;
    }
  else if (!MEM_P (dst) && GET_CODE (dst) != CONCAT)
    {
      dst = gen_reg_rtx (GET_MODE (orig_dst));
      /* Make life a bit easier for combine.  */
      emit_move_insn (dst, CONST0_RTX (GET_MODE (orig_dst)));
    }

  /* Process the pieces.  */
  for (i = start; i < XVECLEN (src, 0); i++)
    {
      HOST_WIDE_INT bytepos = INTVAL (XEXP (XVECEXP (src, 0, i), 1));
      enum machine_mode mode = GET_MODE (tmps[i]);
      unsigned int bytelen = GET_MODE_SIZE (mode);
      rtx dest = dst;

      /* Handle trailing fragments that run over the size of the struct.  */
      if (ssize >= 0 && bytepos + (HOST_WIDE_INT) bytelen > ssize)
	{
	  /* store_bit_field always takes its value from the lsb.
	     Move the fragment to the lsb if it's not already there.  */
	  if (
#ifdef BLOCK_REG_PADDING
	      BLOCK_REG_PADDING (GET_MODE (orig_dst), type, i == start)
	      == (BYTES_BIG_ENDIAN ? upward : downward)
#else
	      BYTES_BIG_ENDIAN
#endif
	      )
	    {
	      int shift = (bytelen - (ssize - bytepos)) * BITS_PER_UNIT;
	      tmps[i] = expand_shift (RSHIFT_EXPR, mode, tmps[i],
				      build_int_cst (NULL_TREE,
						     shift, 0), tmps[i], 0);
	    }
	  bytelen = ssize - bytepos;
	}

      if (GET_CODE (dst) == CONCAT)
	{
	  if (bytepos + bytelen <= GET_MODE_SIZE (GET_MODE (XEXP (dst, 0))))
	    dest = XEXP (dst, 0);
	  else if (bytepos >= GET_MODE_SIZE (GET_MODE (XEXP (dst, 0))))
	    {
	      bytepos -= GET_MODE_SIZE (GET_MODE (XEXP (dst, 0)));
	      dest = XEXP (dst, 1);
	    }
	  else if (bytepos == 0 && XVECLEN (src, 0))
	    {
	      dest = assign_stack_temp (GET_MODE (dest),
				        GET_MODE_SIZE (GET_MODE (dest)), 0);
	      emit_move_insn (adjust_address (dest, GET_MODE (tmps[i]), bytepos),
			      tmps[i]);
	      dst = dest;
	      break;
	    }
	  else
	    abort ();
	}

      /* Optimize the access just a bit.  */
      if (MEM_P (dest)
	  && (! SLOW_UNALIGNED_ACCESS (mode, MEM_ALIGN (dest))
	      || MEM_ALIGN (dest) >= GET_MODE_ALIGNMENT (mode))
	  && bytepos * BITS_PER_UNIT % GET_MODE_ALIGNMENT (mode) == 0
	  && bytelen == GET_MODE_SIZE (mode))
	emit_move_insn (adjust_address (dest, mode, bytepos), tmps[i]);
      else
	store_bit_field (dest, bytelen * BITS_PER_UNIT, bytepos * BITS_PER_UNIT,
			 mode, tmps[i]);
    }

  /* Copy from the pseudo into the (probable) hard reg.  */
  if (orig_dst != dst)
    emit_move_insn (orig_dst, dst);
}

/* Generate code to copy a BLKmode object of TYPE out of a
   set of registers starting with SRCREG into TGTBLK.  If TGTBLK
   is null, a stack temporary is created.  TGTBLK is returned.

   The purpose of this routine is to handle functions that return
   BLKmode structures in registers.  Some machines (the PA for example)
   want to return all small structures in registers regardless of the
   structure's alignment.  */

rtx
copy_blkmode_from_reg (rtx tgtblk, rtx srcreg, tree type)
{
  unsigned HOST_WIDE_INT bytes = int_size_in_bytes (type);
  rtx src = NULL, dst = NULL;
  unsigned HOST_WIDE_INT bitsize = MIN (TYPE_ALIGN (type), BITS_PER_WORD);
  unsigned HOST_WIDE_INT bitpos, xbitpos, padding_correction = 0;

  if (tgtblk == 0)
    {
      tgtblk = assign_temp (build_qualified_type (type,
						  (TYPE_QUALS (type)
						   | TYPE_QUAL_CONST)),
			    0, 1, 1);
      preserve_temp_slots (tgtblk);
    }

  /* This code assumes srcreg is at least a full word.  If it isn't, copy it
     into a new pseudo which is a full word.  */

  if (GET_MODE (srcreg) != BLKmode
      && GET_MODE_SIZE (GET_MODE (srcreg)) < UNITS_PER_WORD)
    srcreg = convert_to_mode (word_mode, srcreg, TYPE_UNSIGNED (type));

  /* If the structure doesn't take up a whole number of words, see whether
     SRCREG is padded on the left or on the right.  If it's on the left,
     set PADDING_CORRECTION to the number of bits to skip.

     In most ABIs, the structure will be returned at the least end of
     the register, which translates to right padding on little-endian
     targets and left padding on big-endian targets.  The opposite
     holds if the structure is returned at the most significant
     end of the register.  */
  if (bytes % UNITS_PER_WORD != 0
      && (targetm.calls.return_in_msb (type)
	  ? !BYTES_BIG_ENDIAN
	  : BYTES_BIG_ENDIAN))
    padding_correction
      = (BITS_PER_WORD - ((bytes % UNITS_PER_WORD) * BITS_PER_UNIT));

  /* Copy the structure BITSIZE bites at a time.

     We could probably emit more efficient code for machines which do not use
     strict alignment, but it doesn't seem worth the effort at the current
     time.  */
  for (bitpos = 0, xbitpos = padding_correction;
       bitpos < bytes * BITS_PER_UNIT;
       bitpos += bitsize, xbitpos += bitsize)
    {
      /* We need a new source operand each time xbitpos is on a
	 word boundary and when xbitpos == padding_correction
	 (the first time through).  */
      if (xbitpos % BITS_PER_WORD == 0
	  || xbitpos == padding_correction)
	src = operand_subword_force (srcreg, xbitpos / BITS_PER_WORD,
				     GET_MODE (srcreg));

      /* We need a new destination operand each time bitpos is on
	 a word boundary.  */
      if (bitpos % BITS_PER_WORD == 0)
	dst = operand_subword (tgtblk, bitpos / BITS_PER_WORD, 1, BLKmode);

      /* Use xbitpos for the source extraction (right justified) and
	 xbitpos for the destination store (left justified).  */
      store_bit_field (dst, bitsize, bitpos % BITS_PER_WORD, word_mode,
		       extract_bit_field (src, bitsize,
					  xbitpos % BITS_PER_WORD, 1,
					  NULL_RTX, word_mode, word_mode));
    }

  return tgtblk;
}

/* Add a USE expression for REG to the (possibly empty) list pointed
   to by CALL_FUSAGE.  REG must denote a hard register.  */

void
use_reg (rtx *call_fusage, rtx reg)
{
  if (!REG_P (reg)
      || REGNO (reg) >= FIRST_PSEUDO_REGISTER)
    abort ();

  *call_fusage
    = gen_rtx_EXPR_LIST (VOIDmode,
			 gen_rtx_USE (VOIDmode, reg), *call_fusage);
}

/* Add USE expressions to *CALL_FUSAGE for each of NREGS consecutive regs,
   starting at REGNO.  All of these registers must be hard registers.  */

void
use_regs (rtx *call_fusage, int regno, int nregs)
{
  int i;

  if (regno + nregs > FIRST_PSEUDO_REGISTER)
    abort ();

  for (i = 0; i < nregs; i++)
    use_reg (call_fusage, regno_reg_rtx[regno + i]);
}

/* Add USE expressions to *CALL_FUSAGE for each REG contained in the
   PARALLEL REGS.  This is for calls that pass values in multiple
   non-contiguous locations.  The Irix 6 ABI has examples of this.  */

void
use_group_regs (rtx *call_fusage, rtx regs)
{
  int i;

  for (i = 0; i < XVECLEN (regs, 0); i++)
    {
      rtx reg = XEXP (XVECEXP (regs, 0, i), 0);

      /* A NULL entry means the parameter goes both on the stack and in
	 registers.  This can also be a MEM for targets that pass values
	 partially on the stack and partially in registers.  */
      if (reg != 0 && REG_P (reg))
	use_reg (call_fusage, reg);
    }
}


/* Determine whether the LEN bytes generated by CONSTFUN can be
   stored to memory using several move instructions.  CONSTFUNDATA is
   a pointer which will be passed as argument in every CONSTFUN call.
   ALIGN is maximum alignment we can assume.  Return nonzero if a
   call to store_by_pieces should succeed.  */

int
can_store_by_pieces (unsigned HOST_WIDE_INT len,
		     rtx (*constfun) (void *, HOST_WIDE_INT, enum machine_mode),
		     void *constfundata, unsigned int align)
{
  unsigned HOST_WIDE_INT l;
  unsigned int max_size;
  HOST_WIDE_INT offset = 0;
  enum machine_mode mode, tmode;
  enum insn_code icode;
  int reverse;
  rtx cst;

  if (len == 0)
    return 1;

  if (! STORE_BY_PIECES_P (len, align))
    return 0;

  tmode = mode_for_size (STORE_MAX_PIECES * BITS_PER_UNIT, MODE_INT, 1);
  if (align >= GET_MODE_ALIGNMENT (tmode))
    align = GET_MODE_ALIGNMENT (tmode);
  else
    {
      enum machine_mode xmode;

      for (tmode = GET_CLASS_NARROWEST_MODE (MODE_INT), xmode = tmode;
	   tmode != VOIDmode;
	   xmode = tmode, tmode = GET_MODE_WIDER_MODE (tmode))
	if (GET_MODE_SIZE (tmode) > STORE_MAX_PIECES
	    || SLOW_UNALIGNED_ACCESS (tmode, align))
	  break;

      align = MAX (align, GET_MODE_ALIGNMENT (xmode));
    }

  /* We would first store what we can in the largest integer mode, then go to
     successively smaller modes.  */

  for (reverse = 0;
       reverse <= (HAVE_PRE_DECREMENT || HAVE_POST_DECREMENT);
       reverse++)
    {
      l = len;
      mode = VOIDmode;
      max_size = STORE_MAX_PIECES + 1;
      while (max_size > 1)
	{
	  for (tmode = GET_CLASS_NARROWEST_MODE (MODE_INT);
	       tmode != VOIDmode; tmode = GET_MODE_WIDER_MODE (tmode))
	    if (GET_MODE_SIZE (tmode) < max_size)
	      mode = tmode;

	  if (mode == VOIDmode)
	    break;

	  icode = mov_optab->handlers[(int) mode].insn_code;
	  if (icode != CODE_FOR_nothing
	      && align >= GET_MODE_ALIGNMENT (mode))
	    {
	      unsigned int size = GET_MODE_SIZE (mode);

	      while (l >= size)
		{
		  if (reverse)
		    offset -= size;

		  cst = (*constfun) (constfundata, offset, mode);
		  if (!LEGITIMATE_CONSTANT_P (cst))
		    return 0;

		  if (!reverse)
		    offset += size;

		  l -= size;
		}
	    }

	  max_size = GET_MODE_SIZE (mode);
	}

      /* The code above should have handled everything.  */
      if (l != 0)
	abort ();
    }

  return 1;
}

/* Generate several move instructions to store LEN bytes generated by
   CONSTFUN to block TO.  (A MEM rtx with BLKmode).  CONSTFUNDATA is a
   pointer which will be passed as argument in every CONSTFUN call.
   ALIGN is maximum alignment we can assume.
   If ENDP is 0 return to, if ENDP is 1 return memory at the end ala
   mempcpy, and if ENDP is 2 return memory the end minus one byte ala
   stpcpy.  */

rtx
store_by_pieces (rtx to, unsigned HOST_WIDE_INT len,
		 rtx (*constfun) (void *, HOST_WIDE_INT, enum machine_mode),
		 void *constfundata, unsigned int align, int endp)
{
  struct store_by_pieces data;

  if (len == 0)
    {
      if (endp == 2)
	abort ();
      return to;
    }

  if (! STORE_BY_PIECES_P (len, align))
    abort ();
  data.constfun = constfun;
  data.constfundata = constfundata;
  data.len = len;
  data.to = to;
  store_by_pieces_1 (&data, align);
  if (endp)
    {
      rtx to1;

      if (data.reverse)
	abort ();
      if (data.autinc_to)
	{
	  if (endp == 2)
	    {
	      if (HAVE_POST_INCREMENT && data.explicit_inc_to > 0)
		emit_insn (gen_add2_insn (data.to_addr, constm1_rtx));
	      else
		data.to_addr = copy_addr_to_reg (plus_constant (data.to_addr,
								-1));
	    }
	  to1 = adjust_automodify_address (data.to, QImode, data.to_addr,
					   data.offset);
	}
      else
	{
	  if (endp == 2)
	    --data.offset;
	  to1 = adjust_address (data.to, QImode, data.offset);
	}
      return to1;
    }
  else
    return data.to;
}

/* Generate several move instructions to clear LEN bytes of block TO.  (A MEM
   rtx with BLKmode).  ALIGN is maximum alignment we can assume.  */

static void
clear_by_pieces (rtx to, unsigned HOST_WIDE_INT len, unsigned int align)
{
  struct store_by_pieces data;

  if (len == 0)
    return;

  data.constfun = clear_by_pieces_1;
  data.constfundata = NULL;
  data.len = len;
  data.to = to;
  store_by_pieces_1 (&data, align);
}

/* Callback routine for clear_by_pieces.
   Return const0_rtx unconditionally.  */

static rtx
clear_by_pieces_1 (void *data ATTRIBUTE_UNUSED,
		   HOST_WIDE_INT offset ATTRIBUTE_UNUSED,
		   enum machine_mode mode ATTRIBUTE_UNUSED)
{
  return const0_rtx;
}

/* Subroutine of clear_by_pieces and store_by_pieces.
   Generate several move instructions to store LEN bytes of block TO.  (A MEM
   rtx with BLKmode).  ALIGN is maximum alignment we can assume.  */

static void
store_by_pieces_1 (struct store_by_pieces *data ATTRIBUTE_UNUSED,
		   unsigned int align ATTRIBUTE_UNUSED)
{
  rtx to_addr = XEXP (data->to, 0);
  unsigned int max_size = STORE_MAX_PIECES + 1;
  enum machine_mode mode = VOIDmode, tmode;
  enum insn_code icode;

  data->offset = 0;
  data->to_addr = to_addr;
  data->autinc_to
    = (GET_CODE (to_addr) == PRE_INC || GET_CODE (to_addr) == PRE_DEC
       || GET_CODE (to_addr) == POST_INC || GET_CODE (to_addr) == POST_DEC);

  data->explicit_inc_to = 0;
  data->reverse
    = (GET_CODE (to_addr) == PRE_DEC || GET_CODE (to_addr) == POST_DEC);
  if (data->reverse)
    data->offset = data->len;

  /* If storing requires more than two move insns,
     copy addresses to registers (to make displacements shorter)
     and use post-increment if available.  */
  if (!data->autinc_to
      && move_by_pieces_ninsns (data->len, align, max_size) > 2)
    {
      /* Determine the main mode we'll be using.  */
      for (tmode = GET_CLASS_NARROWEST_MODE (MODE_INT);
	   tmode != VOIDmode; tmode = GET_MODE_WIDER_MODE (tmode))
	if (GET_MODE_SIZE (tmode) < max_size)
	  mode = tmode;

      if (USE_STORE_PRE_DECREMENT (mode) && data->reverse && ! data->autinc_to)
	{
	  data->to_addr = copy_addr_to_reg (plus_constant (to_addr, data->len));
	  data->autinc_to = 1;
	  data->explicit_inc_to = -1;
	}

      if (USE_STORE_POST_INCREMENT (mode) && ! data->reverse
	  && ! data->autinc_to)
	{
	  data->to_addr = copy_addr_to_reg (to_addr);
	  data->autinc_to = 1;
	  data->explicit_inc_to = 1;
	}

      if ( !data->autinc_to && CONSTANT_P (to_addr))
	data->to_addr = copy_addr_to_reg (to_addr);
    }

  tmode = mode_for_size (STORE_MAX_PIECES * BITS_PER_UNIT, MODE_INT, 1);
  if (align >= GET_MODE_ALIGNMENT (tmode))
    align = GET_MODE_ALIGNMENT (tmode);
  else
    {
      enum machine_mode xmode;

      for (tmode = GET_CLASS_NARROWEST_MODE (MODE_INT), xmode = tmode;
	   tmode != VOIDmode;
	   xmode = tmode, tmode = GET_MODE_WIDER_MODE (tmode))
	if (GET_MODE_SIZE (tmode) > STORE_MAX_PIECES
	    || SLOW_UNALIGNED_ACCESS (tmode, align))
	  break;

      align = MAX (align, GET_MODE_ALIGNMENT (xmode));
    }

  /* First store what we can in the largest integer mode, then go to
     successively smaller modes.  */

  while (max_size > 1)
    {
      for (tmode = GET_CLASS_NARROWEST_MODE (MODE_INT);
	   tmode != VOIDmode; tmode = GET_MODE_WIDER_MODE (tmode))
	if (GET_MODE_SIZE (tmode) < max_size)
	  mode = tmode;

      if (mode == VOIDmode)
	break;

      icode = mov_optab->handlers[(int) mode].insn_code;
      if (icode != CODE_FOR_nothing && align >= GET_MODE_ALIGNMENT (mode))
	store_by_pieces_2 (GEN_FCN (icode), mode, data);

      max_size = GET_MODE_SIZE (mode);
    }

  /* The code above should have handled everything.  */
  if (data->len != 0)
    abort ();
}

/* Subroutine of store_by_pieces_1.  Store as many bytes as appropriate
   with move instructions for mode MODE.  GENFUN is the gen_... function
   to make a move insn for that mode.  DATA has all the other info.  */

static void
store_by_pieces_2 (rtx (*genfun) (rtx, ...), enum machine_mode mode,
		   struct store_by_pieces *data)
{
  unsigned int size = GET_MODE_SIZE (mode);
  rtx to1, cst;

  while (data->len >= size)
    {
      if (data->reverse)
	data->offset -= size;

      if (data->autinc_to)
	to1 = adjust_automodify_address (data->to, mode, data->to_addr,
					 data->offset);
      else
	to1 = adjust_address (data->to, mode, data->offset);

      if (HAVE_PRE_DECREMENT && data->explicit_inc_to < 0)
	emit_insn (gen_add2_insn (data->to_addr,
				  GEN_INT (-(HOST_WIDE_INT) size)));

      cst = (*data->constfun) (data->constfundata, data->offset, mode);
      emit_insn ((*genfun) (to1, cst));

      if (HAVE_POST_INCREMENT && data->explicit_inc_to > 0)
	emit_insn (gen_add2_insn (data->to_addr, GEN_INT (size)));

      if (! data->reverse)
	data->offset += size;

      data->len -= size;
    }
}

/* Write zeros through the storage of OBJECT.  If OBJECT has BLKmode, SIZE is
   its length in bytes.  */

rtx
clear_storage (rtx object, rtx size)
{
  rtx retval = 0;
  unsigned int align = (MEM_P (object) ? MEM_ALIGN (object)
			: GET_MODE_ALIGNMENT (GET_MODE (object)));

  /* If OBJECT is not BLKmode and SIZE is the same size as its mode,
     just move a zero.  Otherwise, do this a piece at a time.  */
  if (GET_MODE (object) != BLKmode
      && GET_CODE (size) == CONST_INT
      && INTVAL (size) == (HOST_WIDE_INT) GET_MODE_SIZE (GET_MODE (object)))
    emit_move_insn (object, CONST0_RTX (GET_MODE (object)));
  else
    {
      if (size == const0_rtx)
	;
      else if (GET_CODE (size) == CONST_INT
	  && CLEAR_BY_PIECES_P (INTVAL (size), align))
	clear_by_pieces (object, INTVAL (size), align);
      else if (clear_storage_via_clrmem (object, size, align))
	;
      else
	retval = clear_storage_via_libcall (object, size);
    }

  return retval;
}

/* A subroutine of clear_storage.  Expand a clrmem pattern;
   return true if successful.  */

static bool
clear_storage_via_clrmem (rtx object, rtx size, unsigned int align)
{
  /* Try the most limited insn first, because there's no point
     including more than one in the machine description unless
     the more limited one has some advantage.  */

  rtx opalign = GEN_INT (align / BITS_PER_UNIT);
  enum machine_mode mode;

  for (mode = GET_CLASS_NARROWEST_MODE (MODE_INT); mode != VOIDmode;
       mode = GET_MODE_WIDER_MODE (mode))
    {
      enum insn_code code = clrmem_optab[(int) mode];
      insn_operand_predicate_fn pred;

      if (code != CODE_FOR_nothing
	  /* We don't need MODE to be narrower than
	     BITS_PER_HOST_WIDE_INT here because if SIZE is less than
	     the mode mask, as it is returned by the macro, it will
	     definitely be less than the actual mode mask.  */
	  && ((GET_CODE (size) == CONST_INT
	       && ((unsigned HOST_WIDE_INT) INTVAL (size)
		   <= (GET_MODE_MASK (mode) >> 1)))
	      || GET_MODE_BITSIZE (mode) >= BITS_PER_WORD)
	  && ((pred = insn_data[(int) code].operand[0].predicate) == 0
	      || (*pred) (object, BLKmode))
	  && ((pred = insn_data[(int) code].operand[2].predicate) == 0
	      || (*pred) (opalign, VOIDmode)))
	{
	  rtx op1;
	  rtx last = get_last_insn ();
	  rtx pat;

	  op1 = convert_to_mode (mode, size, 1);
	  pred = insn_data[(int) code].operand[1].predicate;
	  if (pred != 0 && ! (*pred) (op1, mode))
	    op1 = copy_to_mode_reg (mode, op1);

	  pat = GEN_FCN ((int) code) (object, op1, opalign);
	  if (pat)
	    {
	      emit_insn (pat);
	      return true;
	    }
	  else
	    delete_insns_since (last);
	}
    }

  return false;
}

/* A subroutine of clear_storage.  Expand a call to memset.
   Return the return value of memset, 0 otherwise.  */

static rtx
clear_storage_via_libcall (rtx object, rtx size)
{
  tree call_expr, arg_list, fn, object_tree, size_tree;
  enum machine_mode size_mode;
  rtx retval;

  /* Emit code to copy OBJECT and SIZE into new pseudos.  We can then
     place those into new pseudos into a VAR_DECL and use them later.  */

  object = copy_to_mode_reg (Pmode, XEXP (object, 0));

  size_mode = TYPE_MODE (sizetype);
  size = convert_to_mode (size_mode, size, 1);
  size = copy_to_mode_reg (size_mode, size);

  /* It is incorrect to use the libcall calling conventions to call
     memset in this context.  This could be a user call to memset and
     the user may wish to examine the return value from memset.  For
     targets where libcalls and normal calls have different conventions
     for returning pointers, we could end up generating incorrect code.  */

  object_tree = make_tree (ptr_type_node, object);
  size_tree = make_tree (sizetype, size);

  fn = clear_storage_libcall_fn (true);
  arg_list = tree_cons (NULL_TREE, size_tree, NULL_TREE);
  arg_list = tree_cons (NULL_TREE, integer_zero_node, arg_list);
  arg_list = tree_cons (NULL_TREE, object_tree, arg_list);

  /* Now we have to build up the CALL_EXPR itself.  */
  call_expr = build1 (ADDR_EXPR, build_pointer_type (TREE_TYPE (fn)), fn);
  call_expr = build3 (CALL_EXPR, TREE_TYPE (TREE_TYPE (fn)),
		      call_expr, arg_list, NULL_TREE);

  retval = expand_expr (call_expr, NULL_RTX, VOIDmode, 0);

  return retval;
}

/* A subroutine of clear_storage_via_libcall.  Create the tree node
   for the function we use for block clears.  The first time FOR_CALL
   is true, we call assemble_external.  */

static GTY(()) tree block_clear_fn;

void
init_block_clear_fn (const char *asmspec)
{
  if (!block_clear_fn)
    {
      tree fn, args;

      fn = get_identifier ("memset");
      args = build_function_type_list (ptr_type_node, ptr_type_node,
				       integer_type_node, sizetype,
				       NULL_TREE);

      fn = build_decl (FUNCTION_DECL, fn, args);
      DECL_EXTERNAL (fn) = 1;
      TREE_PUBLIC (fn) = 1;
      DECL_ARTIFICIAL (fn) = 1;
      TREE_NOTHROW (fn) = 1;

      block_clear_fn = fn;
    }

  if (asmspec)
    set_user_assembler_name (block_clear_fn, asmspec);
}

static tree
clear_storage_libcall_fn (int for_call)
{
  static bool emitted_extern;

  if (!block_clear_fn)
    init_block_clear_fn (NULL);

  if (for_call && !emitted_extern)
    {
      emitted_extern = true;
      make_decl_rtl (block_clear_fn);
      assemble_external (block_clear_fn);
    }

  return block_clear_fn;
}

/* Generate code to copy Y into X.
   Both Y and X must have the same mode, except that
   Y can be a constant with VOIDmode.
   This mode cannot be BLKmode; use emit_block_move for that.

   Return the last instruction emitted.  */

rtx
emit_move_insn (rtx x, rtx y)
{
  enum machine_mode mode = GET_MODE (x);
  rtx y_cst = NULL_RTX;
  rtx last_insn, set;

  if (mode == BLKmode || (GET_MODE (y) != mode && GET_MODE (y) != VOIDmode))
    abort ();

  if (CONSTANT_P (y))
    {
      if (optimize
	  && SCALAR_FLOAT_MODE_P (GET_MODE (x))
	  && (last_insn = compress_float_constant (x, y)))
	return last_insn;

      y_cst = y;

      if (!LEGITIMATE_CONSTANT_P (y))
	{
	  y = force_const_mem (mode, y);

	  /* If the target's cannot_force_const_mem prevented the spill,
	     assume that the target's move expanders will also take care
	     of the non-legitimate constant.  */
	  if (!y)
	    y = y_cst;
	}
    }

  /* If X or Y are memory references, verify that their addresses are valid
     for the machine.  */
  if (MEM_P (x)
      && ((! memory_address_p (GET_MODE (x), XEXP (x, 0))
	   && ! push_operand (x, GET_MODE (x)))
	  || (flag_force_addr
	      && CONSTANT_ADDRESS_P (XEXP (x, 0)))))
    x = validize_mem (x);

  if (MEM_P (y)
      && (! memory_address_p (GET_MODE (y), XEXP (y, 0))
	  || (flag_force_addr
	      && CONSTANT_ADDRESS_P (XEXP (y, 0)))))
    y = validize_mem (y);

  if (mode == BLKmode)
    abort ();

  last_insn = emit_move_insn_1 (x, y);

  if (y_cst && REG_P (x)
      && (set = single_set (last_insn)) != NULL_RTX
      && SET_DEST (set) == x
      && ! rtx_equal_p (y_cst, SET_SRC (set)))
    set_unique_reg_note (last_insn, REG_EQUAL, y_cst);

  return last_insn;
}

/* Low level part of emit_move_insn.
   Called just like emit_move_insn, but assumes X and Y
   are basically valid.  */

rtx
emit_move_insn_1 (rtx x, rtx y)
{
  enum machine_mode mode = GET_MODE (x);
  enum machine_mode submode;
  enum mode_class class = GET_MODE_CLASS (mode);

  if ((unsigned int) mode >= (unsigned int) MAX_MACHINE_MODE)
    abort ();

  if (mov_optab->handlers[(int) mode].insn_code != CODE_FOR_nothing)
    return
      emit_insn (GEN_FCN (mov_optab->handlers[(int) mode].insn_code) (x, y));

  /* Expand complex moves by moving real part and imag part, if possible.  */
  else if ((class == MODE_COMPLEX_FLOAT || class == MODE_COMPLEX_INT)
	   && BLKmode != (submode = GET_MODE_INNER (mode))
	   && (mov_optab->handlers[(int) submode].insn_code
	       != CODE_FOR_nothing))
    {
      /* Don't split destination if it is a stack push.  */
      int stack = push_operand (x, GET_MODE (x));

#ifdef PUSH_ROUNDING
      /* In case we output to the stack, but the size is smaller than the
	 machine can push exactly, we need to use move instructions.  */
      if (stack
	  && (PUSH_ROUNDING (GET_MODE_SIZE (submode))
	      != GET_MODE_SIZE (submode)))
	{
	  rtx temp;
	  HOST_WIDE_INT offset1, offset2;

	  /* Do not use anti_adjust_stack, since we don't want to update
	     stack_pointer_delta.  */
	  temp = expand_binop (Pmode,
#ifdef STACK_GROWS_DOWNWARD
			       sub_optab,
#else
			       add_optab,
#endif
			       stack_pointer_rtx,
			       GEN_INT
				 (PUSH_ROUNDING
				  (GET_MODE_SIZE (GET_MODE (x)))),
			       stack_pointer_rtx, 0, OPTAB_LIB_WIDEN);

	  if (temp != stack_pointer_rtx)
	    emit_move_insn (stack_pointer_rtx, temp);

#ifdef STACK_GROWS_DOWNWARD
	  offset1 = 0;
	  offset2 = GET_MODE_SIZE (submode);
#else
	  offset1 = -PUSH_ROUNDING (GET_MODE_SIZE (GET_MODE (x)));
	  offset2 = (-PUSH_ROUNDING (GET_MODE_SIZE (GET_MODE (x)))
		     + GET_MODE_SIZE (submode));
#endif

	  emit_move_insn (change_address (x, submode,
					  gen_rtx_PLUS (Pmode,
						        stack_pointer_rtx,
							GEN_INT (offset1))),
			  gen_realpart (submode, y));
	  emit_move_insn (change_address (x, submode,
					  gen_rtx_PLUS (Pmode,
						        stack_pointer_rtx,
							GEN_INT (offset2))),
			  gen_imagpart (submode, y));
	}
      else
#endif
      /* If this is a stack, push the highpart first, so it
	 will be in the argument order.

	 In that case, change_address is used only to convert
	 the mode, not to change the address.  */
      if (stack)
	{
	  /* Note that the real part always precedes the imag part in memory
	     regardless of machine's endianness.  */
#ifdef STACK_GROWS_DOWNWARD
	  emit_move_insn (gen_rtx_MEM (submode, XEXP (x, 0)),
			  gen_imagpart (submode, y));
	  emit_move_insn (gen_rtx_MEM (submode, XEXP (x, 0)),
			  gen_realpart (submode, y));
#else
	  emit_move_insn (gen_rtx_MEM (submode, XEXP (x, 0)),
			  gen_realpart (submode, y));
	  emit_move_insn (gen_rtx_MEM (submode, XEXP (x, 0)),
			  gen_imagpart (submode, y));
#endif
	}
      else
	{
	  rtx realpart_x, realpart_y;
	  rtx imagpart_x, imagpart_y;

	  /* If this is a complex value with each part being smaller than a
	     word, the usual calling sequence will likely pack the pieces into
	     a single register.  Unfortunately, SUBREG of hard registers only
	     deals in terms of words, so we have a problem converting input
	     arguments to the CONCAT of two registers that is used elsewhere
	     for complex values.  If this is before reload, we can copy it into
	     memory and reload.  FIXME, we should see about using extract and
	     insert on integer registers, but complex short and complex char
	     variables should be rarely used.  */
	  if (GET_MODE_BITSIZE (mode) < 2 * BITS_PER_WORD
	      && (reload_in_progress | reload_completed) == 0)
	    {
	      int packed_dest_p
		= (REG_P (x) && REGNO (x) < FIRST_PSEUDO_REGISTER);
	      int packed_src_p
		= (REG_P (y) && REGNO (y) < FIRST_PSEUDO_REGISTER);

	      if (packed_dest_p || packed_src_p)
		{
		  enum mode_class reg_class = ((class == MODE_COMPLEX_FLOAT)
					       ? MODE_FLOAT : MODE_INT);

		  enum machine_mode reg_mode
		    = mode_for_size (GET_MODE_BITSIZE (mode), reg_class, 1);

		  if (reg_mode != BLKmode)
		    {
		      rtx mem = assign_stack_temp (reg_mode,
						   GET_MODE_SIZE (mode), 0);
		      rtx cmem = adjust_address (mem, mode, 0);

		      if (packed_dest_p)
			{
			  rtx sreg = gen_rtx_SUBREG (reg_mode, x, 0);

			  emit_move_insn_1 (cmem, y);
			  return emit_move_insn_1 (sreg, mem);
			}
		      else
			{
			  rtx sreg = gen_rtx_SUBREG (reg_mode, y, 0);

			  emit_move_insn_1 (mem, sreg);
			  return emit_move_insn_1 (x, cmem);
			}
		    }
		}
	    }

	  realpart_x = gen_realpart (submode, x);
	  realpart_y = gen_realpart (submode, y);
	  imagpart_x = gen_imagpart (submode, x);
	  imagpart_y = gen_imagpart (submode, y);

	  /* Show the output dies here.  This is necessary for SUBREGs
	     of pseudos since we cannot track their lifetimes correctly;
	     hard regs shouldn't appear here except as return values.
	     We never want to emit such a clobber after reload.  */
	  if (x != y
	      && ! (reload_in_progress || reload_completed)
	      && (GET_CODE (realpart_x) == SUBREG
		  || GET_CODE (imagpart_x) == SUBREG))
	    emit_insn (gen_rtx_CLOBBER (VOIDmode, x));

	  emit_move_insn (realpart_x, realpart_y);
	  emit_move_insn (imagpart_x, imagpart_y);
	}

      return get_last_insn ();
    }

  /* Handle MODE_CC modes:  If we don't have a special move insn for this mode,
     find a mode to do it in.  If we have a movcc, use it.  Otherwise,
     find the MODE_INT mode of the same width.  */
  else if (GET_MODE_CLASS (mode) == MODE_CC
	   && mov_optab->handlers[(int) mode].insn_code == CODE_FOR_nothing)
    {
      enum insn_code insn_code;
      enum machine_mode tmode = VOIDmode;
      rtx x1 = x, y1 = y;

      if (mode != CCmode
	  && mov_optab->handlers[(int) CCmode].insn_code != CODE_FOR_nothing)
	tmode = CCmode;
      else
	for (tmode = QImode; tmode != VOIDmode;
	     tmode = GET_MODE_WIDER_MODE (tmode))
	  if (GET_MODE_SIZE (tmode) == GET_MODE_SIZE (mode))
	    break;

      if (tmode == VOIDmode)
	abort ();

      /* Get X and Y in TMODE.  We can't use gen_lowpart here because it
	 may call change_address which is not appropriate if we were
	 called when a reload was in progress.  We don't have to worry
	 about changing the address since the size in bytes is supposed to
	 be the same.  Copy the MEM to change the mode and move any
	 substitutions from the old MEM to the new one.  */

      if (reload_in_progress)
	{
	  x = gen_lowpart_common (tmode, x1);
	  if (x == 0 && MEM_P (x1))
	    {
	      x = adjust_address_nv (x1, tmode, 0);
	      copy_replacements (x1, x);
	    }

	  y = gen_lowpart_common (tmode, y1);
	  if (y == 0 && MEM_P (y1))
	    {
	      y = adjust_address_nv (y1, tmode, 0);
	      copy_replacements (y1, y);
	    }
	}
      else
	{
	  x = gen_lowpart (tmode, x);
	  y = gen_lowpart (tmode, y);
	}

      insn_code = mov_optab->handlers[(int) tmode].insn_code;
      return emit_insn (GEN_FCN (insn_code) (x, y));
    }

  /* Try using a move pattern for the corresponding integer mode.  This is
     only safe when simplify_subreg can convert MODE constants into integer
     constants.  At present, it can only do this reliably if the value
     fits within a HOST_WIDE_INT.  */
  else if (GET_MODE_BITSIZE (mode) <= HOST_BITS_PER_WIDE_INT
	   && (submode = int_mode_for_mode (mode)) != BLKmode
	   && mov_optab->handlers[submode].insn_code != CODE_FOR_nothing)
    return emit_insn (GEN_FCN (mov_optab->handlers[submode].insn_code)
		      (simplify_gen_subreg (submode, x, mode, 0),
		       simplify_gen_subreg (submode, y, mode, 0)));

  /* This will handle any multi-word or full-word mode that lacks a move_insn
     pattern.  However, you will get better code if you define such patterns,
     even if they must turn into multiple assembler instructions.  */
  else if (GET_MODE_SIZE (mode) >= UNITS_PER_WORD)
    {
      rtx last_insn = 0;
      rtx seq, inner;
      int need_clobber;
      int i;

#ifdef PUSH_ROUNDING

      /* If X is a push on the stack, do the push now and replace
	 X with a reference to the stack pointer.  */
      if (push_operand (x, GET_MODE (x)))
	{
	  rtx temp;
	  enum rtx_code code;

	  /* Do not use anti_adjust_stack, since we don't want to update
	     stack_pointer_delta.  */
	  temp = expand_binop (Pmode,
#ifdef STACK_GROWS_DOWNWARD
			       sub_optab,
#else
			       add_optab,
#endif
			       stack_pointer_rtx,
			       GEN_INT
				 (PUSH_ROUNDING
				  (GET_MODE_SIZE (GET_MODE (x)))),
			       stack_pointer_rtx, 0, OPTAB_LIB_WIDEN);

	  if (temp != stack_pointer_rtx)
	    emit_move_insn (stack_pointer_rtx, temp);

	  code = GET_CODE (XEXP (x, 0));

	  /* Just hope that small offsets off SP are OK.  */
	  if (code == POST_INC)
	    temp = gen_rtx_PLUS (Pmode, stack_pointer_rtx,
				GEN_INT (-((HOST_WIDE_INT)
					   GET_MODE_SIZE (GET_MODE (x)))));
	  else if (code == POST_DEC)
	    temp = gen_rtx_PLUS (Pmode, stack_pointer_rtx,
				GEN_INT (GET_MODE_SIZE (GET_MODE (x))));
	  else
	    temp = stack_pointer_rtx;

	  x = change_address (x, VOIDmode, temp);
	}
#endif

      /* If we are in reload, see if either operand is a MEM whose address
	 is scheduled for replacement.  */
      if (reload_in_progress && MEM_P (x)
	  && (inner = find_replacement (&XEXP (x, 0))) != XEXP (x, 0))
	x = replace_equiv_address_nv (x, inner);
      if (reload_in_progress && MEM_P (y)
	  && (inner = find_replacement (&XEXP (y, 0))) != XEXP (y, 0))
	y = replace_equiv_address_nv (y, inner);

      start_sequence ();

      need_clobber = 0;
      for (i = 0;
	   i < (GET_MODE_SIZE (mode) + (UNITS_PER_WORD - 1)) / UNITS_PER_WORD;
	   i++)
	{
	  rtx xpart = operand_subword (x, i, 1, mode);
	  rtx ypart = operand_subword (y, i, 1, mode);

	  /* If we can't get a part of Y, put Y into memory if it is a
	     constant.  Otherwise, force it into a register.  If we still
	     can't get a part of Y, abort.  */
	  if (ypart == 0 && CONSTANT_P (y))
	    {
	      y = force_const_mem (mode, y);
	      ypart = operand_subword (y, i, 1, mode);
	    }
	  else if (ypart == 0)
	    ypart = operand_subword_force (y, i, mode);

	  if (xpart == 0 || ypart == 0)
	    abort ();

	  need_clobber |= (GET_CODE (xpart) == SUBREG);

	  last_insn = emit_move_insn (xpart, ypart);
	}

      seq = get_insns ();
      end_sequence ();

      /* Show the output dies here.  This is necessary for SUBREGs
	 of pseudos since we cannot track their lifetimes correctly;
	 hard regs shouldn't appear here except as return values.
	 We never want to emit such a clobber after reload.  */
      if (x != y
	  && ! (reload_in_progress || reload_completed)
	  && need_clobber != 0)
	emit_insn (gen_rtx_CLOBBER (VOIDmode, x));

      emit_insn (seq);

      return last_insn;
    }
  else
    abort ();
}

/* If Y is representable exactly in a narrower mode, and the target can
   perform the extension directly from constant or memory, then emit the
   move as an extension.  */

static rtx
compress_float_constant (rtx x, rtx y)
{
  enum machine_mode dstmode = GET_MODE (x);
  enum machine_mode orig_srcmode = GET_MODE (y);
  enum machine_mode srcmode;
  REAL_VALUE_TYPE r;

  REAL_VALUE_FROM_CONST_DOUBLE (r, y);

  for (srcmode = GET_CLASS_NARROWEST_MODE (GET_MODE_CLASS (orig_srcmode));
       srcmode != orig_srcmode;
       srcmode = GET_MODE_WIDER_MODE (srcmode))
    {
      enum insn_code ic;
      rtx trunc_y, last_insn;

      /* Skip if the target can't extend this way.  */
      ic = can_extend_p (dstmode, srcmode, 0);
      if (ic == CODE_FOR_nothing)
	continue;

      /* Skip if the narrowed value isn't exact.  */
      if (! exact_real_truncate (srcmode, &r))
	continue;

      trunc_y = CONST_DOUBLE_FROM_REAL_VALUE (r, srcmode);

      if (LEGITIMATE_CONSTANT_P (trunc_y))
	{
	  /* Skip if the target needs extra instructions to perform
	     the extension.  */
	  if (! (*insn_data[ic].operand[1].predicate) (trunc_y, srcmode))
	    continue;
	}
      else if (float_extend_from_mem[dstmode][srcmode])
	trunc_y = validize_mem (force_const_mem (srcmode, trunc_y));
      else
	continue;

      emit_unop_insn (ic, x, trunc_y, UNKNOWN);
      last_insn = get_last_insn ();

      if (REG_P (x))
	set_unique_reg_note (last_insn, REG_EQUAL, y);

      return last_insn;
    }

  return NULL_RTX;
}

/* Pushing data onto the stack.  */

/* Push a block of length SIZE (perhaps variable)
   and return an rtx to address the beginning of the block.
   The value may be virtual_outgoing_args_rtx.

   EXTRA is the number of bytes of padding to push in addition to SIZE.
   BELOW nonzero means this padding comes at low addresses;
   otherwise, the padding comes at high addresses.  */

rtx
push_block (rtx size, int extra, int below)
{
  rtx temp;

  size = convert_modes (Pmode, ptr_mode, size, 1);
  if (CONSTANT_P (size))
    anti_adjust_stack (plus_constant (size, extra));
  else if (REG_P (size) && extra == 0)
    anti_adjust_stack (size);
  else
    {
      temp = copy_to_mode_reg (Pmode, size);
      if (extra != 0)
	temp = expand_binop (Pmode, add_optab, temp, GEN_INT (extra),
			     temp, 0, OPTAB_LIB_WIDEN);
      anti_adjust_stack (temp);
    }

#ifndef STACK_GROWS_DOWNWARD
  if (0)
#else
  if (1)
#endif
    {
      temp = virtual_outgoing_args_rtx;
      if (extra != 0 && below)
	temp = plus_constant (temp, extra);
    }
  else
    {
      if (GET_CODE (size) == CONST_INT)
	temp = plus_constant (virtual_outgoing_args_rtx,
			      -INTVAL (size) - (below ? 0 : extra));
      else if (extra != 0 && !below)
	temp = gen_rtx_PLUS (Pmode, virtual_outgoing_args_rtx,
			     negate_rtx (Pmode, plus_constant (size, extra)));
      else
	temp = gen_rtx_PLUS (Pmode, virtual_outgoing_args_rtx,
			     negate_rtx (Pmode, size));
    }

  return memory_address (GET_CLASS_NARROWEST_MODE (MODE_INT), temp);
}

#ifdef PUSH_ROUNDING

/* Emit single push insn.  */

static void
emit_single_push_insn (enum machine_mode mode, rtx x, tree type)
{
  rtx dest_addr;
  unsigned rounded_size = PUSH_ROUNDING (GET_MODE_SIZE (mode));
  rtx dest;
  enum insn_code icode;
  insn_operand_predicate_fn pred;

  stack_pointer_delta += PUSH_ROUNDING (GET_MODE_SIZE (mode));
  /* If there is push pattern, use it.  Otherwise try old way of throwing
     MEM representing push operation to move expander.  */
  icode = push_optab->handlers[(int) mode].insn_code;
  if (icode != CODE_FOR_nothing)
    {
      if (((pred = insn_data[(int) icode].operand[0].predicate)
	   && !((*pred) (x, mode))))
	x = force_reg (mode, x);
      emit_insn (GEN_FCN (icode) (x));
      return;
    }
  if (GET_MODE_SIZE (mode) == rounded_size)
    dest_addr = gen_rtx_fmt_e (STACK_PUSH_CODE, Pmode, stack_pointer_rtx);
  /* If we are to pad downward, adjust the stack pointer first and
     then store X into the stack location using an offset.  This is
     because emit_move_insn does not know how to pad; it does not have
     access to type.  */
  else if (FUNCTION_ARG_PADDING (mode, type) == downward)
    {
      unsigned padding_size = rounded_size - GET_MODE_SIZE (mode);
      HOST_WIDE_INT offset;

      emit_move_insn (stack_pointer_rtx,
		      expand_binop (Pmode,
#ifdef STACK_GROWS_DOWNWARD
				    sub_optab,
#else
				    add_optab,
#endif
				    stack_pointer_rtx,
				    GEN_INT (rounded_size),
				    NULL_RTX, 0, OPTAB_LIB_WIDEN));

      offset = (HOST_WIDE_INT) padding_size;
#ifdef STACK_GROWS_DOWNWARD
      if (STACK_PUSH_CODE == POST_DEC)
	/* We have already decremented the stack pointer, so get the
	   previous value.  */
	offset += (HOST_WIDE_INT) rounded_size;
#else
      if (STACK_PUSH_CODE == POST_INC)
	/* We have already incremented the stack pointer, so get the
	   previous value.  */
	offset -= (HOST_WIDE_INT) rounded_size;
#endif
      dest_addr = gen_rtx_PLUS (Pmode, stack_pointer_rtx, GEN_INT (offset));
    }
  else
    {
#ifdef STACK_GROWS_DOWNWARD
      /* ??? This seems wrong if STACK_PUSH_CODE == POST_DEC.  */
      dest_addr = gen_rtx_PLUS (Pmode, stack_pointer_rtx,
				GEN_INT (-(HOST_WIDE_INT) rounded_size));
#else
      /* ??? This seems wrong if STACK_PUSH_CODE == POST_INC.  */
      dest_addr = gen_rtx_PLUS (Pmode, stack_pointer_rtx,
				GEN_INT (rounded_size));
#endif
      dest_addr = gen_rtx_PRE_MODIFY (Pmode, stack_pointer_rtx, dest_addr);
    }

  dest = gen_rtx_MEM (mode, dest_addr);

  if (type != 0)
    {
      set_mem_attributes (dest, type, 1);

      if (flag_optimize_sibling_calls)
	/* Function incoming arguments may overlap with sibling call
	   outgoing arguments and we cannot allow reordering of reads
	   from function arguments with stores to outgoing arguments
	   of sibling calls.  */
	set_mem_alias_set (dest, 0);
    }
  emit_move_insn (dest, x);
}
#endif

/* Generate code to push X onto the stack, assuming it has mode MODE and
   type TYPE.
   MODE is redundant except when X is a CONST_INT (since they don't
   carry mode info).
   SIZE is an rtx for the size of data to be copied (in bytes),
   needed only if X is BLKmode.

   ALIGN (in bits) is maximum alignment we can assume.

   If PARTIAL and REG are both nonzero, then copy that many of the first
   words of X into registers starting with REG, and push the rest of X.
   The amount of space pushed is decreased by PARTIAL words,
   rounded *down* to a multiple of PARM_BOUNDARY.
   REG must be a hard register in this case.
   If REG is zero but PARTIAL is not, take any all others actions for an
   argument partially in registers, but do not actually load any
   registers.

   EXTRA is the amount in bytes of extra space to leave next to this arg.
   This is ignored if an argument block has already been allocated.

   On a machine that lacks real push insns, ARGS_ADDR is the address of
   the bottom of the argument block for this call.  We use indexing off there
   to store the arg.  On machines with push insns, ARGS_ADDR is 0 when a
   argument block has not been preallocated.

   ARGS_SO_FAR is the size of args previously pushed for this call.

   REG_PARM_STACK_SPACE is nonzero if functions require stack space
   for arguments passed in registers.  If nonzero, it will be the number
   of bytes required.  */

void
emit_push_insn (rtx x, enum machine_mode mode, tree type, rtx size,
		unsigned int align, int partial, rtx reg, int extra,
		rtx args_addr, rtx args_so_far, int reg_parm_stack_space,
		rtx alignment_pad)
{
  rtx xinner;
  enum direction stack_direction
#ifdef STACK_GROWS_DOWNWARD
    = downward;
#else
    = upward;
#endif

  /* Decide where to pad the argument: `downward' for below,
     `upward' for above, or `none' for don't pad it.
     Default is below for small data on big-endian machines; else above.  */
  enum direction where_pad = FUNCTION_ARG_PADDING (mode, type);

  /* Invert direction if stack is post-decrement.
     FIXME: why?  */
  if (STACK_PUSH_CODE == POST_DEC)
    if (where_pad != none)
      where_pad = (where_pad == downward ? upward : downward);

  xinner = x;

  if (mode == BLKmode)
    {
      /* Copy a block into the stack, entirely or partially.  */

      rtx temp;
      int used = partial * UNITS_PER_WORD;
      int offset;
      int skip;

      if (reg && GET_CODE (reg) == PARALLEL)
	{
	  /* Use the size of the elt to compute offset.  */
	  rtx elt = XEXP (XVECEXP (reg, 0, 0), 0);
	  used = partial * GET_MODE_SIZE (GET_MODE (elt));
	  offset = used % (PARM_BOUNDARY / BITS_PER_UNIT);
	}
      else
	offset = used % (PARM_BOUNDARY / BITS_PER_UNIT);

      if (size == 0)
	abort ();

      used -= offset;

      /* USED is now the # of bytes we need not copy to the stack
	 because registers will take care of them.  */

      if (partial != 0)
	xinner = adjust_address (xinner, BLKmode, used);

      /* If the partial register-part of the arg counts in its stack size,
	 skip the part of stack space corresponding to the registers.
	 Otherwise, start copying to the beginning of the stack space,
	 by setting SKIP to 0.  */
      skip = (reg_parm_stack_space == 0) ? 0 : used;

#ifdef PUSH_ROUNDING
      /* Do it with several push insns if that doesn't take lots of insns
	 and if there is no difficulty with push insns that skip bytes
	 on the stack for alignment purposes.  */
      if (args_addr == 0
	  && PUSH_ARGS
	  && GET_CODE (size) == CONST_INT
	  && skip == 0
	  && MEM_ALIGN (xinner) >= align
	  && (MOVE_BY_PIECES_P ((unsigned) INTVAL (size) - used, align))
	  /* Here we avoid the case of a structure whose weak alignment
	     forces many pushes of a small amount of data,
	     and such small pushes do rounding that causes trouble.  */
	  && ((! SLOW_UNALIGNED_ACCESS (word_mode, align))
	      || align >= BIGGEST_ALIGNMENT
	      || (PUSH_ROUNDING (align / BITS_PER_UNIT)
		  == (align / BITS_PER_UNIT)))
	  && PUSH_ROUNDING (INTVAL (size)) == INTVAL (size))
	{
	  /* Push padding now if padding above and stack grows down,
	     or if padding below and stack grows up.
	     But if space already allocated, this has already been done.  */
	  if (extra && args_addr == 0
	      && where_pad != none && where_pad != stack_direction)
	    anti_adjust_stack (GEN_INT (extra));

	  move_by_pieces (NULL, xinner, INTVAL (size) - used, align, 0);
	}
      else
#endif /* PUSH_ROUNDING  */
	{
	  rtx target;

	  /* Otherwise make space on the stack and copy the data
	     to the address of that space.  */

	  /* Deduct words put into registers from the size we must copy.  */
	  if (partial != 0)
	    {
	      if (GET_CODE (size) == CONST_INT)
		size = GEN_INT (INTVAL (size) - used);
	      else
		size = expand_binop (GET_MODE (size), sub_optab, size,
				     GEN_INT (used), NULL_RTX, 0,
				     OPTAB_LIB_WIDEN);
	    }

	  /* Get the address of the stack space.
	     In this case, we do not deal with EXTRA separately.
	     A single stack adjust will do.  */
	  if (! args_addr)
	    {
	      temp = push_block (size, extra, where_pad == downward);
	      extra = 0;
	    }
	  else if (GET_CODE (args_so_far) == CONST_INT)
	    temp = memory_address (BLKmode,
				   plus_constant (args_addr,
						  skip + INTVAL (args_so_far)));
	  else
	    temp = memory_address (BLKmode,
				   plus_constant (gen_rtx_PLUS (Pmode,
								args_addr,
								args_so_far),
						  skip));

	  if (!ACCUMULATE_OUTGOING_ARGS)
	    {
	      /* If the source is referenced relative to the stack pointer,
		 copy it to another register to stabilize it.  We do not need
		 to do this if we know that we won't be changing sp.  */

	      if (reg_mentioned_p (virtual_stack_dynamic_rtx, temp)
		  || reg_mentioned_p (virtual_outgoing_args_rtx, temp))
		temp = copy_to_reg (temp);
	    }

	  target = gen_rtx_MEM (BLKmode, temp);

	  /* We do *not* set_mem_attributes here, because incoming arguments
	     may overlap with sibling call outgoing arguments and we cannot
	     allow reordering of reads from function arguments with stores
	     to outgoing arguments of sibling calls.  We do, however, want
	     to record the alignment of the stack slot.  */
	  /* ALIGN may well be better aligned than TYPE, e.g. due to
	     PARM_BOUNDARY.  Assume the caller isn't lying.  */
	  set_mem_align (target, align);

	  emit_block_move (target, xinner, size, BLOCK_OP_CALL_PARM);
	}
    }
  else if (partial > 0)
    {
      /* Scalar partly in registers.  */

      int size = GET_MODE_SIZE (mode) / UNITS_PER_WORD;
      int i;
      int not_stack;
      /* # words of start of argument
	 that we must make space for but need not store.  */
      int offset = partial % (PARM_BOUNDARY / BITS_PER_WORD);
      int args_offset = INTVAL (args_so_far);
      int skip;

      /* Push padding now if padding above and stack grows down,
	 or if padding below and stack grows up.
	 But if space already allocated, this has already been done.  */
      if (extra && args_addr == 0
	  && where_pad != none && where_pad != stack_direction)
	anti_adjust_stack (GEN_INT (extra));

      /* If we make space by pushing it, we might as well push
	 the real data.  Otherwise, we can leave OFFSET nonzero
	 and leave the space uninitialized.  */
      if (args_addr == 0)
	offset = 0;

      /* Now NOT_STACK gets the number of words that we don't need to
	 allocate on the stack.  */
      not_stack = partial - offset;

      /* If the partial register-part of the arg counts in its stack size,
	 skip the part of stack space corresponding to the registers.
	 Otherwise, start copying to the beginning of the stack space,
	 by setting SKIP to 0.  */
      skip = (reg_parm_stack_space == 0) ? 0 : not_stack;

      if (CONSTANT_P (x) && ! LEGITIMATE_CONSTANT_P (x))
	x = validize_mem (force_const_mem (mode, x));

      /* If X is a hard register in a non-integer mode, copy it into a pseudo;
	 SUBREGs of such registers are not allowed.  */
      if ((REG_P (x) && REGNO (x) < FIRST_PSEUDO_REGISTER
	   && GET_MODE_CLASS (GET_MODE (x)) != MODE_INT))
	x = copy_to_reg (x);

      /* Loop over all the words allocated on the stack for this arg.  */
      /* We can do it by words, because any scalar bigger than a word
	 has a size a multiple of a word.  */
#ifndef PUSH_ARGS_REVERSED
      for (i = not_stack; i < size; i++)
#else
      for (i = size - 1; i >= not_stack; i--)
#endif
	if (i >= not_stack + offset)
	  emit_push_insn (operand_subword_force (x, i, mode),
			  word_mode, NULL_TREE, NULL_RTX, align, 0, NULL_RTX,
			  0, args_addr,
			  GEN_INT (args_offset + ((i - not_stack + skip)
						  * UNITS_PER_WORD)),
			  reg_parm_stack_space, alignment_pad);
    }
  else
    {
      rtx addr;
      rtx dest;

      /* Push padding now if padding above and stack grows down,
	 or if padding below and stack grows up.
	 But if space already allocated, this has already been done.  */
      if (extra && args_addr == 0
	  && where_pad != none && where_pad != stack_direction)
	anti_adjust_stack (GEN_INT (extra));

#ifdef PUSH_ROUNDING
      if (args_addr == 0 && PUSH_ARGS)
	emit_single_push_insn (mode, x, type);
      else
#endif
	{
	  if (GET_CODE (args_so_far) == CONST_INT)
	    addr
	      = memory_address (mode,
				plus_constant (args_addr,
					       INTVAL (args_so_far)));
	  else
	    addr = memory_address (mode, gen_rtx_PLUS (Pmode, args_addr,
						       args_so_far));
	  dest = gen_rtx_MEM (mode, addr);

	  /* We do *not* set_mem_attributes here, because incoming arguments
	     may overlap with sibling call outgoing arguments and we cannot
	     allow reordering of reads from function arguments with stores
	     to outgoing arguments of sibling calls.  We do, however, want
	     to record the alignment of the stack slot.  */
	  /* ALIGN may well be better aligned than TYPE, e.g. due to
	     PARM_BOUNDARY.  Assume the caller isn't lying.  */
	  set_mem_align (dest, align);

	  emit_move_insn (dest, x);
	}
    }

  /* If part should go in registers, copy that part
     into the appropriate registers.  Do this now, at the end,
     since mem-to-mem copies above may do function calls.  */
  if (partial > 0 && reg != 0)
    {
      /* Handle calls that pass values in multiple non-contiguous locations.
	 The Irix 6 ABI has examples of this.  */
      if (GET_CODE (reg) == PARALLEL)
	emit_group_load (reg, x, type, -1);
      else
	move_block_to_reg (REGNO (reg), x, partial, mode);
    }

  if (extra && args_addr == 0 && where_pad == stack_direction)
    anti_adjust_stack (GEN_INT (extra));

  if (alignment_pad && args_addr == 0)
    anti_adjust_stack (alignment_pad);
}

/* Return X if X can be used as a subtarget in a sequence of arithmetic
   operations.  */

static rtx
get_subtarget (rtx x)
{
  return (optimize
          || x == 0
	   /* Only registers can be subtargets.  */
	   || !REG_P (x)
	   /* Don't use hard regs to avoid extending their life.  */
	   || REGNO (x) < FIRST_PSEUDO_REGISTER
	  ? 0 : x);
}

/* Expand an assignment that stores the value of FROM into TO.
   If WANT_VALUE is nonzero, return an rtx for the value of TO.
   (If the value is constant, this rtx is a constant.)
   Otherwise, the returned value is NULL_RTX.  */

rtx
expand_assignment (tree to, tree from, int want_value)
{
  rtx to_rtx = 0;
  rtx result;

  /* Don't crash if the lhs of the assignment was erroneous.  */

  if (TREE_CODE (to) == ERROR_MARK)
    {
      result = expand_expr (from, NULL_RTX, VOIDmode, 0);
      return want_value ? result : NULL_RTX;
    }

  /* Assignment of a structure component needs special treatment
     if the structure component's rtx is not simply a MEM.
     Assignment of an array element at a constant index, and assignment of
     an array element in an unaligned packed structure field, has the same
     problem.  */

  if (TREE_CODE (to) == COMPONENT_REF || TREE_CODE (to) == BIT_FIELD_REF
      || TREE_CODE (to) == ARRAY_REF || TREE_CODE (to) == ARRAY_RANGE_REF
      || TREE_CODE (TREE_TYPE (to)) == ARRAY_TYPE)
    {
      enum machine_mode mode1;
      HOST_WIDE_INT bitsize, bitpos;
      rtx orig_to_rtx;
      tree offset;
      int unsignedp;
      int volatilep = 0;
      tree tem;

      push_temp_slots ();
      tem = get_inner_reference (to, &bitsize, &bitpos, &offset, &mode1,
				 &unsignedp, &volatilep);

      /* If we are going to use store_bit_field and extract_bit_field,
	 make sure to_rtx will be safe for multiple use.  */

      if (mode1 == VOIDmode && want_value)
	tem = stabilize_reference (tem);

      orig_to_rtx = to_rtx = expand_expr (tem, NULL_RTX, VOIDmode, 0);

      if (offset != 0)
	{
	  rtx offset_rtx = expand_expr (offset, NULL_RTX, VOIDmode, EXPAND_SUM);

	  if (!MEM_P (to_rtx))
	    abort ();

#ifdef POINTERS_EXTEND_UNSIGNED
	  if (GET_MODE (offset_rtx) != Pmode)
	    offset_rtx = convert_to_mode (Pmode, offset_rtx, 0);
#else
	  if (GET_MODE (offset_rtx) != ptr_mode)
	    offset_rtx = convert_to_mode (ptr_mode, offset_rtx, 0);
#endif

	  /* A constant address in TO_RTX can have VOIDmode, we must not try
	     to call force_reg for that case.  Avoid that case.  */
	  if (MEM_P (to_rtx)
	      && GET_MODE (to_rtx) == BLKmode
	      && GET_MODE (XEXP (to_rtx, 0)) != VOIDmode
	      && bitsize > 0
	      && (bitpos % bitsize) == 0
	      && (bitsize % GET_MODE_ALIGNMENT (mode1)) == 0
	      && MEM_ALIGN (to_rtx) == GET_MODE_ALIGNMENT (mode1))
	    {
	      to_rtx = adjust_address (to_rtx, mode1, bitpos / BITS_PER_UNIT);
	      bitpos = 0;
	    }

	  to_rtx = offset_address (to_rtx, offset_rtx,
				   highest_pow2_factor_for_target (to,
				   				   offset));
	}

      if (MEM_P (to_rtx))
	{
	  /* If the field is at offset zero, we could have been given the
	     DECL_RTX of the parent struct.  Don't munge it.  */
	  to_rtx = shallow_copy_rtx (to_rtx);

	  set_mem_attributes_minus_bitpos (to_rtx, to, 0, bitpos);
	}

      /* Deal with volatile and readonly fields.  The former is only done
	 for MEM.  Also set MEM_KEEP_ALIAS_SET_P if needed.  */
      if (volatilep && MEM_P (to_rtx))
	{
	  if (to_rtx == orig_to_rtx)
	    to_rtx = copy_rtx (to_rtx);
	  MEM_VOLATILE_P (to_rtx) = 1;
	}

      if (MEM_P (to_rtx) && ! can_address_p (to))
	{
	  if (to_rtx == orig_to_rtx)
	    to_rtx = copy_rtx (to_rtx);
	  MEM_KEEP_ALIAS_SET_P (to_rtx) = 1;
	}

      /* Optimize bitfld op= val in certain cases.  */
      while (mode1 == VOIDmode && !want_value
	     && bitsize > 0 && bitsize < BITS_PER_WORD
	     && GET_MODE_BITSIZE (GET_MODE (to_rtx)) <= BITS_PER_WORD
	     && !TREE_SIDE_EFFECTS (to)
	     && !TREE_THIS_VOLATILE (to))
	{
	  tree src, op0, op1;
	  rtx value, str_rtx = to_rtx;
	  HOST_WIDE_INT bitpos1 = bitpos;
	  optab binop;

	  src = from;
	  STRIP_NOPS (src);
	  if (TREE_CODE (TREE_TYPE (src)) != INTEGER_TYPE
	      || TREE_CODE_CLASS (TREE_CODE (src)) != '2')
	    break;

	  op0 = TREE_OPERAND (src, 0);
	  op1 = TREE_OPERAND (src, 1);
	  STRIP_NOPS (op0);

	  if (! operand_equal_p (to, op0, 0))
	    break;

	  if (MEM_P (str_rtx))
	    {
	      enum machine_mode mode = GET_MODE (str_rtx);
	      HOST_WIDE_INT offset1;

	      if (GET_MODE_BITSIZE (mode) == 0
		  || GET_MODE_BITSIZE (mode) > BITS_PER_WORD)
		mode = word_mode;
	      mode = get_best_mode (bitsize, bitpos1, MEM_ALIGN (str_rtx),
				    mode, 0);
	      if (mode == VOIDmode)
		break;

	      offset1 = bitpos1;
	      bitpos1 %= GET_MODE_BITSIZE (mode);
	      offset1 = (offset1 - bitpos1) / BITS_PER_UNIT;
	      str_rtx = adjust_address (str_rtx, mode, offset1);
	    }
	  else if (!REG_P (str_rtx) && GET_CODE (str_rtx) != SUBREG)
	    break;

	  /* If the bit field covers the whole REG/MEM, store_field
	     will likely generate better code.  */
	  if (bitsize >= GET_MODE_BITSIZE (GET_MODE (str_rtx)))
	    break;

	  /* We can't handle fields split accross multiple entities.  */
	  if (bitpos1 + bitsize > GET_MODE_BITSIZE (GET_MODE (str_rtx)))
	    break;

	  if (BYTES_BIG_ENDIAN)
	    bitpos1 = GET_MODE_BITSIZE (GET_MODE (str_rtx)) - bitpos1
		      - bitsize;

	  /* Special case some bitfield op= exp.  */
	  switch (TREE_CODE (src))
	    {
	    case PLUS_EXPR:
	    case MINUS_EXPR:
	      /* For now, just optimize the case of the topmost bitfield
		 where we don't need to do any masking and also
		 1 bit bitfields where xor can be used.
		 We might win by one instruction for the other bitfields
		 too if insv/extv instructions aren't used, so that
		 can be added later.  */
	      if (bitpos1 + bitsize != GET_MODE_BITSIZE (GET_MODE (str_rtx))
		  && (bitsize != 1 || TREE_CODE (op1) != INTEGER_CST))
		break;
	      value = expand_expr (op1, NULL_RTX, GET_MODE (str_rtx), 0);
	      value = convert_modes (GET_MODE (str_rtx),
				     TYPE_MODE (TREE_TYPE (op1)), value,
				     TYPE_UNSIGNED (TREE_TYPE (op1)));

	      /* We may be accessing data outside the field, which means
		 we can alias adjacent data.  */
	      if (MEM_P (str_rtx))
		{
		  str_rtx = shallow_copy_rtx (str_rtx);
		  set_mem_alias_set (str_rtx, 0);
		  set_mem_expr (str_rtx, 0);
		}

	      binop = TREE_CODE (src) == PLUS_EXPR ? add_optab : sub_optab;
	      if (bitsize == 1
		  && bitpos1 + bitsize != GET_MODE_BITSIZE (GET_MODE (str_rtx)))
		{
		  value = expand_and (GET_MODE (str_rtx), value, const1_rtx,
				      NULL_RTX);
		  binop = xor_optab;
		}
	      value = expand_shift (LSHIFT_EXPR, GET_MODE (str_rtx), value,
				    build_int_cst (NULL_TREE,bitpos1, 0),
				    NULL_RTX, 1);
	      result = expand_binop (GET_MODE (str_rtx), binop, str_rtx,
				     value, str_rtx, 1, OPTAB_WIDEN);
	      if (result != str_rtx)
		emit_move_insn (str_rtx, result);
	      free_temp_slots ();
	      pop_temp_slots ();
	      return NULL_RTX;

	    default:
	      break;
	    }

	  break;
	}

      result = store_field (to_rtx, bitsize, bitpos, mode1, from,
			    (want_value
			     /* Spurious cast for HPUX compiler.  */
			     ? ((enum machine_mode)
				TYPE_MODE (TREE_TYPE (to)))
			     : VOIDmode),
			    unsignedp, TREE_TYPE (tem), get_alias_set (to));

      preserve_temp_slots (result);
      free_temp_slots ();
      pop_temp_slots ();

      /* If the value is meaningful, convert RESULT to the proper mode.
	 Otherwise, return nothing.  */
      return (want_value ? convert_modes (TYPE_MODE (TREE_TYPE (to)),
					  TYPE_MODE (TREE_TYPE (from)),
					  result,
					  TYPE_UNSIGNED (TREE_TYPE (to)))
	      : NULL_RTX);
    }

  /* If the rhs is a function call and its value is not an aggregate,
     call the function before we start to compute the lhs.
     This is needed for correct code for cases such as
     val = setjmp (buf) on machines where reference to val
     requires loading up part of an address in a separate insn.

     Don't do this if TO is a VAR_DECL or PARM_DECL whose DECL_RTL is REG
     since it might be a promoted variable where the zero- or sign- extension
     needs to be done.  Handling this in the normal way is safe because no
     computation is done before the call.  */
  if (TREE_CODE (from) == CALL_EXPR && ! aggregate_value_p (from, from)
      && TREE_CODE (TYPE_SIZE (TREE_TYPE (from))) == INTEGER_CST
      && ! ((TREE_CODE (to) == VAR_DECL || TREE_CODE (to) == PARM_DECL)
	    && REG_P (DECL_RTL (to))))
    {
      rtx value;

      push_temp_slots ();
      value = expand_expr (from, NULL_RTX, VOIDmode, 0);
      if (to_rtx == 0)
	to_rtx = expand_expr (to, NULL_RTX, VOIDmode, EXPAND_WRITE);

      /* Handle calls that return values in multiple non-contiguous locations.
	 The Irix 6 ABI has examples of this.  */
      if (GET_CODE (to_rtx) == PARALLEL)
	emit_group_load (to_rtx, value, TREE_TYPE (from),
			 int_size_in_bytes (TREE_TYPE (from)));
      else if (GET_MODE (to_rtx) == BLKmode)
	emit_block_move (to_rtx, value, expr_size (from), BLOCK_OP_NORMAL);
      else
	{
	  if (POINTER_TYPE_P (TREE_TYPE (to)))
	    value = convert_memory_address (GET_MODE (to_rtx), value);
	  emit_move_insn (to_rtx, value);
	}
      preserve_temp_slots (to_rtx);
      free_temp_slots ();
      pop_temp_slots ();
      return want_value ? to_rtx : NULL_RTX;
    }

  /* Ordinary treatment.  Expand TO to get a REG or MEM rtx.
     Don't re-expand if it was expanded already (in COMPONENT_REF case).  */

  if (to_rtx == 0)
    to_rtx = expand_expr (to, NULL_RTX, VOIDmode, EXPAND_WRITE);

  /* Don't move directly into a return register.  */
  if (TREE_CODE (to) == RESULT_DECL
      && (REG_P (to_rtx) || GET_CODE (to_rtx) == PARALLEL))
    {
      rtx temp;

      push_temp_slots ();
      temp = expand_expr (from, 0, GET_MODE (to_rtx), 0);

      if (GET_CODE (to_rtx) == PARALLEL)
	emit_group_load (to_rtx, temp, TREE_TYPE (from),
			 int_size_in_bytes (TREE_TYPE (from)));
      else
	emit_move_insn (to_rtx, temp);

      preserve_temp_slots (to_rtx);
      free_temp_slots ();
      pop_temp_slots ();
      return want_value ? to_rtx : NULL_RTX;
    }

  /* In case we are returning the contents of an object which overlaps
     the place the value is being stored, use a safe function when copying
     a value through a pointer into a structure value return block.  */
  if (TREE_CODE (to) == RESULT_DECL && TREE_CODE (from) == INDIRECT_REF
      && current_function_returns_struct
      && !current_function_returns_pcc_struct)
    {
      rtx from_rtx, size;

      push_temp_slots ();
      size = expr_size (from);
      from_rtx = expand_expr (from, NULL_RTX, VOIDmode, 0);

      emit_library_call (memmove_libfunc, LCT_NORMAL,
			 VOIDmode, 3, XEXP (to_rtx, 0), Pmode,
			 XEXP (from_rtx, 0), Pmode,
			 convert_to_mode (TYPE_MODE (sizetype),
					  size, TYPE_UNSIGNED (sizetype)),
			 TYPE_MODE (sizetype));

      preserve_temp_slots (to_rtx);
      free_temp_slots ();
      pop_temp_slots ();
      return want_value ? to_rtx : NULL_RTX;
    }

  /* Compute FROM and store the value in the rtx we got.  */

  push_temp_slots ();
  result = store_expr (from, to_rtx, want_value);
  preserve_temp_slots (result);
  free_temp_slots ();
  pop_temp_slots ();
  return want_value ? result : NULL_RTX;
}

/* Generate code for computing expression EXP,
   and storing the value into TARGET.

   If WANT_VALUE & 1 is nonzero, return a copy of the value
   not in TARGET, so that we can be sure to use the proper
   value in a containing expression even if TARGET has something
   else stored in it.  If possible, we copy the value through a pseudo
   and return that pseudo.  Or, if the value is constant, we try to
   return the constant.  In some cases, we return a pseudo
   copied *from* TARGET.

   If the mode is BLKmode then we may return TARGET itself.
   It turns out that in BLKmode it doesn't cause a problem.
   because C has no operators that could combine two different
   assignments into the same BLKmode object with different values
   with no sequence point.  Will other languages need this to
   be more thorough?

   If WANT_VALUE & 1 is 0, we return NULL, to make sure
   to catch quickly any cases where the caller uses the value
   and fails to set WANT_VALUE.

   If WANT_VALUE & 2 is set, this is a store into a call param on the
   stack, and block moves may need to be treated specially.  */

rtx
store_expr (tree exp, rtx target, int want_value)
{
  rtx temp;
  rtx alt_rtl = NULL_RTX;
  int dont_return_target = 0;
  int dont_store_target = 0;

  if (VOID_TYPE_P (TREE_TYPE (exp)))
    {
      /* C++ can generate ?: expressions with a throw expression in one
	 branch and an rvalue in the other. Here, we resolve attempts to
	 store the throw expression's nonexistent result.  */
      if (want_value)
	abort ();
      expand_expr (exp, const0_rtx, VOIDmode, 0);
      return NULL_RTX;
    }
  if (TREE_CODE (exp) == COMPOUND_EXPR)
    {
      /* Perform first part of compound expression, then assign from second
	 part.  */
      expand_expr (TREE_OPERAND (exp, 0), const0_rtx, VOIDmode,
		   want_value & 2 ? EXPAND_STACK_PARM : EXPAND_NORMAL);
      return store_expr (TREE_OPERAND (exp, 1), target, want_value);
    }
  else if (TREE_CODE (exp) == COND_EXPR && GET_MODE (target) == BLKmode)
    {
      /* For conditional expression, get safe form of the target.  Then
	 test the condition, doing the appropriate assignment on either
	 side.  This avoids the creation of unnecessary temporaries.
	 For non-BLKmode, it is more efficient not to do this.  */

      rtx lab1 = gen_label_rtx (), lab2 = gen_label_rtx ();

      do_pending_stack_adjust ();
      NO_DEFER_POP;
      jumpifnot (TREE_OPERAND (exp, 0), lab1);
      store_expr (TREE_OPERAND (exp, 1), target, want_value & 2);
      emit_jump_insn (gen_jump (lab2));
      emit_barrier ();
      emit_label (lab1);
      store_expr (TREE_OPERAND (exp, 2), target, want_value & 2);
      emit_label (lab2);
      OK_DEFER_POP;

      return want_value & 1 ? target : NULL_RTX;
    }
  else if ((want_value & 1) != 0
	   && MEM_P (target)
	   && ! MEM_VOLATILE_P (target)
	   && GET_MODE (target) != BLKmode)
    /* If target is in memory and caller wants value in a register instead,
       arrange that.  Pass TARGET as target for expand_expr so that,
       if EXP is another assignment, WANT_VALUE will be nonzero for it.
       We know expand_expr will not use the target in that case.
       Don't do this if TARGET is volatile because we are supposed
       to write it and then read it.  */
    {
      temp = expand_expr (exp, target, GET_MODE (target),
			  want_value & 2 ? EXPAND_STACK_PARM : EXPAND_NORMAL);
      if (GET_MODE (temp) != BLKmode && GET_MODE (temp) != VOIDmode)
	{
	  /* If TEMP is already in the desired TARGET, only copy it from
	     memory and don't store it there again.  */
	  if (temp == target
	      || (rtx_equal_p (temp, target)
		  && ! side_effects_p (temp) && ! side_effects_p (target)))
	    dont_store_target = 1;
	  temp = copy_to_reg (temp);
	}
      dont_return_target = 1;
    }
  else if (GET_CODE (target) == SUBREG && SUBREG_PROMOTED_VAR_P (target))
    /* If this is a scalar in a register that is stored in a wider mode
       than the declared mode, compute the result into its declared mode
       and then convert to the wider mode.  Our value is the computed
       expression.  */
    {
      rtx inner_target = 0;

      /* If we don't want a value, we can do the conversion inside EXP,
	 which will often result in some optimizations.  Do the conversion
	 in two steps: first change the signedness, if needed, then
	 the extend.  But don't do this if the type of EXP is a subtype
	 of something else since then the conversion might involve
	 more than just converting modes.  */
      if ((want_value & 1) == 0
	  && INTEGRAL_TYPE_P (TREE_TYPE (exp))
	  && TREE_TYPE (TREE_TYPE (exp)) == 0
	  && (!lang_hooks.reduce_bit_field_operations
	      || (GET_MODE_PRECISION (GET_MODE (target))
		  == TYPE_PRECISION (TREE_TYPE (exp)))))
	{
	  if (TYPE_UNSIGNED (TREE_TYPE (exp))
	      != SUBREG_PROMOTED_UNSIGNED_P (target))
	    exp = convert
	      (lang_hooks.types.signed_or_unsigned_type
	       (SUBREG_PROMOTED_UNSIGNED_P (target), TREE_TYPE (exp)), exp);

	  exp = convert (lang_hooks.types.type_for_mode
			 (GET_MODE (SUBREG_REG (target)),
			  SUBREG_PROMOTED_UNSIGNED_P (target)),
			 exp);

	  inner_target = SUBREG_REG (target);
	}

      temp = expand_expr (exp, inner_target, VOIDmode,
			  want_value & 2 ? EXPAND_STACK_PARM : EXPAND_NORMAL);

      /* If TEMP is a MEM and we want a result value, make the access
	 now so it gets done only once.  Strictly speaking, this is
	 only necessary if the MEM is volatile, or if the address
	 overlaps TARGET.  But not performing the load twice also
	 reduces the amount of rtl we generate and then have to CSE.  */
      if (MEM_P (temp) && (want_value & 1) != 0)
	temp = copy_to_reg (temp);

      /* If TEMP is a VOIDmode constant, use convert_modes to make
	 sure that we properly convert it.  */
      if (CONSTANT_P (temp) && GET_MODE (temp) == VOIDmode)
	{
	  temp = convert_modes (GET_MODE (target), TYPE_MODE (TREE_TYPE (exp)),
				temp, SUBREG_PROMOTED_UNSIGNED_P (target));
	  temp = convert_modes (GET_MODE (SUBREG_REG (target)),
			        GET_MODE (target), temp,
			        SUBREG_PROMOTED_UNSIGNED_P (target));
	}

      convert_move (SUBREG_REG (target), temp,
		    SUBREG_PROMOTED_UNSIGNED_P (target));

      /* If we promoted a constant, change the mode back down to match
	 target.  Otherwise, the caller might get confused by a result whose
	 mode is larger than expected.  */

      if ((want_value & 1) != 0 && GET_MODE (temp) != GET_MODE (target))
	{
	  if (GET_MODE (temp) != VOIDmode)
	    {
	      temp = gen_lowpart_SUBREG (GET_MODE (target), temp);
	      SUBREG_PROMOTED_VAR_P (temp) = 1;
	      SUBREG_PROMOTED_UNSIGNED_SET (temp,
		SUBREG_PROMOTED_UNSIGNED_P (target));
	    }
	  else
	    temp = convert_modes (GET_MODE (target),
				  GET_MODE (SUBREG_REG (target)),
				  temp, SUBREG_PROMOTED_UNSIGNED_P (target));
	}

      return want_value & 1 ? temp : NULL_RTX;
    }
  else
    {
      temp = expand_expr_real (exp, target, GET_MODE (target),
			       (want_value & 2
				? EXPAND_STACK_PARM : EXPAND_NORMAL),
			       &alt_rtl);
      /* Return TARGET if it's a specified hardware register.
	 If TARGET is a volatile mem ref, either return TARGET
	 or return a reg copied *from* TARGET; ANSI requires this.

	 Otherwise, if TEMP is not TARGET, return TEMP
	 if it is constant (for efficiency),
	 or if we really want the correct value.  */
      if (!(target && REG_P (target)
	    && REGNO (target) < FIRST_PSEUDO_REGISTER)
	  && !(MEM_P (target) && MEM_VOLATILE_P (target))
	  && ! rtx_equal_p (temp, target)
	  && (CONSTANT_P (temp) || (want_value & 1) != 0))
	dont_return_target = 1;
    }

  /* If TEMP is a VOIDmode constant and the mode of the type of EXP is not
     the same as that of TARGET, adjust the constant.  This is needed, for
     example, in case it is a CONST_DOUBLE and we want only a word-sized
     value.  */
  if (CONSTANT_P (temp) && GET_MODE (temp) == VOIDmode
      && TREE_CODE (exp) != ERROR_MARK
      && GET_MODE (target) != TYPE_MODE (TREE_TYPE (exp)))
    temp = convert_modes (GET_MODE (target), TYPE_MODE (TREE_TYPE (exp)),
			  temp, TYPE_UNSIGNED (TREE_TYPE (exp)));

  /* If value was not generated in the target, store it there.
     Convert the value to TARGET's type first if necessary and emit the
     pending incrementations that have been queued when expanding EXP.
     Note that we cannot emit the whole queue blindly because this will
     effectively disable the POST_INC optimization later.

     If TEMP and TARGET compare equal according to rtx_equal_p, but
     one or both of them are volatile memory refs, we have to distinguish
     two cases:
     - expand_expr has used TARGET.  In this case, we must not generate
       another copy.  This can be detected by TARGET being equal according
       to == .
     - expand_expr has not used TARGET - that means that the source just
       happens to have the same RTX form.  Since temp will have been created
       by expand_expr, it will compare unequal according to == .
       We must generate a copy in this case, to reach the correct number
       of volatile memory references.  */

  if ((! rtx_equal_p (temp, target)
       || (temp != target && (side_effects_p (temp)
			      || side_effects_p (target))))
      && TREE_CODE (exp) != ERROR_MARK
      && ! dont_store_target
      /* If store_expr stores a DECL whose DECL_RTL(exp) == TARGET,
	 but TARGET is not valid memory reference, TEMP will differ
	 from TARGET although it is really the same location.  */
      && !(alt_rtl && rtx_equal_p (alt_rtl, target))
      /* If there's nothing to copy, don't bother.  Don't call expr_size
	 unless necessary, because some front-ends (C++) expr_size-hook
	 aborts on objects that are not supposed to be bit-copied or
	 bit-initialized.  */
      && expr_size (exp) != const0_rtx)
    {
      if (GET_MODE (temp) != GET_MODE (target)
	  && GET_MODE (temp) != VOIDmode)
	{
	  int unsignedp = TYPE_UNSIGNED (TREE_TYPE (exp));
	  if (dont_return_target)
	    {
	      /* In this case, we will return TEMP,
		 so make sure it has the proper mode.
		 But don't forget to store the value into TARGET.  */
	      temp = convert_to_mode (GET_MODE (target), temp, unsignedp);
	      emit_move_insn (target, temp);
	    }
	  else
	    convert_move (target, temp, unsignedp);
	}

      else if (GET_MODE (temp) == BLKmode && TREE_CODE (exp) == STRING_CST)
	{
	  /* Handle copying a string constant into an array.  The string
	     constant may be shorter than the array.  So copy just the string's
	     actual length, and clear the rest.  First get the size of the data
	     type of the string, which is actually the size of the target.  */
	  rtx size = expr_size (exp);

	  if (GET_CODE (size) == CONST_INT
	      && INTVAL (size) < TREE_STRING_LENGTH (exp))
	    emit_block_move (target, temp, size,
			     (want_value & 2
			      ? BLOCK_OP_CALL_PARM : BLOCK_OP_NORMAL));
	  else
	    {
	      /* Compute the size of the data to copy from the string.  */
	      tree copy_size
		= size_binop (MIN_EXPR,
			      make_tree (sizetype, size),
			      size_int (TREE_STRING_LENGTH (exp)));
	      rtx copy_size_rtx
		= expand_expr (copy_size, NULL_RTX, VOIDmode,
			       (want_value & 2
				? EXPAND_STACK_PARM : EXPAND_NORMAL));
	      rtx label = 0;

	      /* Copy that much.  */
	      copy_size_rtx = convert_to_mode (ptr_mode, copy_size_rtx,
					       TYPE_UNSIGNED (sizetype));
	      emit_block_move (target, temp, copy_size_rtx,
			       (want_value & 2
				? BLOCK_OP_CALL_PARM : BLOCK_OP_NORMAL));

	      /* Figure out how much is left in TARGET that we have to clear.
		 Do all calculations in ptr_mode.  */
	      if (GET_CODE (copy_size_rtx) == CONST_INT)
		{
		  size = plus_constant (size, -INTVAL (copy_size_rtx));
		  target = adjust_address (target, BLKmode,
					   INTVAL (copy_size_rtx));
		}
	      else
		{
		  size = expand_binop (TYPE_MODE (sizetype), sub_optab, size,
				       copy_size_rtx, NULL_RTX, 0,
				       OPTAB_LIB_WIDEN);

#ifdef POINTERS_EXTEND_UNSIGNED
		  if (GET_MODE (copy_size_rtx) != Pmode)
		    copy_size_rtx = convert_to_mode (Pmode, copy_size_rtx,
						     TYPE_UNSIGNED (sizetype));
#endif

		  target = offset_address (target, copy_size_rtx,
					   highest_pow2_factor (copy_size));
		  label = gen_label_rtx ();
		  emit_cmp_and_jump_insns (size, const0_rtx, LT, NULL_RTX,
					   GET_MODE (size), 0, label);
		}

	      if (size != const0_rtx)
		clear_storage (target, size);

	      if (label)
		emit_label (label);
	    }
	}
      /* Handle calls that return values in multiple non-contiguous locations.
	 The Irix 6 ABI has examples of this.  */
      else if (GET_CODE (target) == PARALLEL)
	emit_group_load (target, temp, TREE_TYPE (exp),
			 int_size_in_bytes (TREE_TYPE (exp)));
      else if (GET_MODE (temp) == BLKmode)
	emit_block_move (target, temp, expr_size (exp),
			 (want_value & 2
			  ? BLOCK_OP_CALL_PARM : BLOCK_OP_NORMAL));
      else
	{
	  temp = force_operand (temp, target);
	  if (temp != target)
	    emit_move_insn (target, temp);
	}
    }

  /* If we don't want a value, return NULL_RTX.  */
  if ((want_value & 1) == 0)
    return NULL_RTX;

  /* If we are supposed to return TEMP, do so as long as it isn't a MEM.
     ??? The latter test doesn't seem to make sense.  */
  else if (dont_return_target && !MEM_P (temp))
    return temp;

  /* Return TARGET itself if it is a hard register.  */
  else if ((want_value & 1) != 0
	   && GET_MODE (target) != BLKmode
	   && ! (REG_P (target)
		 && REGNO (target) < FIRST_PSEUDO_REGISTER))
    return copy_to_reg (target);

  else
    return target;
}

/* Examine CTOR.  Discover how many scalar fields are set to nonzero
   values and place it in *P_NZ_ELTS.  Discover how many scalar fields
   are set to non-constant values and place it in  *P_NC_ELTS.  */

static void
categorize_ctor_elements_1 (tree ctor, HOST_WIDE_INT *p_nz_elts,
			    HOST_WIDE_INT *p_nc_elts)
{
  HOST_WIDE_INT nz_elts, nc_elts;
  tree list;

  nz_elts = 0;
  nc_elts = 0;

  for (list = CONSTRUCTOR_ELTS (ctor); list; list = TREE_CHAIN (list))
    {
      tree value = TREE_VALUE (list);
      tree purpose = TREE_PURPOSE (list);
      HOST_WIDE_INT mult;

      mult = 1;
      if (TREE_CODE (purpose) == RANGE_EXPR)
	{
	  tree lo_index = TREE_OPERAND (purpose, 0);
	  tree hi_index = TREE_OPERAND (purpose, 1);

	  if (host_integerp (lo_index, 1) && host_integerp (hi_index, 1))
	    mult = (tree_low_cst (hi_index, 1)
		    - tree_low_cst (lo_index, 1) + 1);
	}

      switch (TREE_CODE (value))
	{
	case CONSTRUCTOR:
	  {
	    HOST_WIDE_INT nz = 0, nc = 0;
	    categorize_ctor_elements_1 (value, &nz, &nc);
	    nz_elts += mult * nz;
	    nc_elts += mult * nc;
	  }
	  break;

	case INTEGER_CST:
	case REAL_CST:
	  if (!initializer_zerop (value))
	    nz_elts += mult;
	  break;
	case COMPLEX_CST:
	  if (!initializer_zerop (TREE_REALPART (value)))
	    nz_elts += mult;
	  if (!initializer_zerop (TREE_IMAGPART (value)))
	    nz_elts += mult;
	  break;
	case VECTOR_CST:
	  {
	    tree v;
	    for (v = TREE_VECTOR_CST_ELTS (value); v; v = TREE_CHAIN (v))
	      if (!initializer_zerop (TREE_VALUE (v)))
	        nz_elts += mult;
	  }
	  break;

	default:
	  nz_elts += mult;
	  if (!initializer_constant_valid_p (value, TREE_TYPE (value)))
	    nc_elts += mult;
	  break;
	}
    }

  *p_nz_elts += nz_elts;
  *p_nc_elts += nc_elts;
}

void
categorize_ctor_elements (tree ctor, HOST_WIDE_INT *p_nz_elts,
			  HOST_WIDE_INT *p_nc_elts)
{
  *p_nz_elts = 0;
  *p_nc_elts = 0;
  categorize_ctor_elements_1 (ctor, p_nz_elts, p_nc_elts);
}

/* Count the number of scalars in TYPE.  Return -1 on overflow or
   variable-sized.  */

HOST_WIDE_INT
count_type_elements (tree type)
{
  const HOST_WIDE_INT max = ~((HOST_WIDE_INT)1 << (HOST_BITS_PER_WIDE_INT-1));
  switch (TREE_CODE (type))
    {
    case ARRAY_TYPE:
      {
	tree telts = array_type_nelts (type);
	if (telts && host_integerp (telts, 1))
	  {
	    HOST_WIDE_INT n = tree_low_cst (telts, 1) + 1;
	    HOST_WIDE_INT m = count_type_elements (TREE_TYPE (type));
	    if (n == 0)
	      return 0;
	    else if (max / n > m)
	      return n * m;
	  }
	return -1;
      }

    case RECORD_TYPE:
      {
	HOST_WIDE_INT n = 0, t;
	tree f;

	for (f = TYPE_FIELDS (type); f ; f = TREE_CHAIN (f))
	  if (TREE_CODE (f) == FIELD_DECL)
	    {
	      t = count_type_elements (TREE_TYPE (f));
	      if (t < 0)
		return -1;
	      n += t;
	    }

	return n;
      }

    case UNION_TYPE:
    case QUAL_UNION_TYPE:
      {
	/* Ho hum.  How in the world do we guess here?  Clearly it isn't
	   right to count the fields.  Guess based on the number of words.  */
        HOST_WIDE_INT n = int_size_in_bytes (type);
	if (n < 0)
	  return -1;
	return n / UNITS_PER_WORD;
      }

    case COMPLEX_TYPE:
      return 2;

    case VECTOR_TYPE:
      return TYPE_VECTOR_SUBPARTS (type);

    case INTEGER_TYPE:
    case REAL_TYPE:
    case ENUMERAL_TYPE:
    case BOOLEAN_TYPE:
    case CHAR_TYPE:
    case POINTER_TYPE:
    case OFFSET_TYPE:
    case REFERENCE_TYPE:
      return 1;

    case VOID_TYPE:
    case METHOD_TYPE:
    case FILE_TYPE:
    case SET_TYPE:
    case FUNCTION_TYPE:
    case LANG_TYPE:
    default:
      abort ();
    }
}

/* Return 1 if EXP contains mostly (3/4)  zeros.  */

int
mostly_zeros_p (tree exp)
{
  if (TREE_CODE (exp) == CONSTRUCTOR)

    {
      HOST_WIDE_INT nz_elts, nc_elts, elts;

      /* If there are no ranges of true bits, it is all zero.  */
      if (TREE_TYPE (exp) && TREE_CODE (TREE_TYPE (exp)) == SET_TYPE)
	return CONSTRUCTOR_ELTS (exp) == NULL_TREE;

      categorize_ctor_elements (exp, &nz_elts, &nc_elts);
      elts = count_type_elements (TREE_TYPE (exp));

      return nz_elts < elts / 4;
    }

  return initializer_zerop (exp);
}

/* Helper function for store_constructor.
   TARGET, BITSIZE, BITPOS, MODE, EXP are as for store_field.
   TYPE is the type of the CONSTRUCTOR, not the element type.
   CLEARED is as for store_constructor.
   ALIAS_SET is the alias set to use for any stores.

   This provides a recursive shortcut back to store_constructor when it isn't
   necessary to go through store_field.  This is so that we can pass through
   the cleared field to let store_constructor know that we may not have to
   clear a substructure if the outer structure has already been cleared.  */

static void
store_constructor_field (rtx target, unsigned HOST_WIDE_INT bitsize,
			 HOST_WIDE_INT bitpos, enum machine_mode mode,
			 tree exp, tree type, int cleared, int alias_set)
{
  if (TREE_CODE (exp) == CONSTRUCTOR
      /* We can only call store_constructor recursively if the size and
	 bit position are on a byte boundary.  */
      && bitpos % BITS_PER_UNIT == 0
      && (bitsize > 0 && bitsize % BITS_PER_UNIT == 0)
      /* If we have a nonzero bitpos for a register target, then we just
	 let store_field do the bitfield handling.  This is unlikely to
	 generate unnecessary clear instructions anyways.  */
      && (bitpos == 0 || MEM_P (target)))
    {
      if (MEM_P (target))
	target
	  = adjust_address (target,
			    GET_MODE (target) == BLKmode
			    || 0 != (bitpos
				     % GET_MODE_ALIGNMENT (GET_MODE (target)))
			    ? BLKmode : VOIDmode, bitpos / BITS_PER_UNIT);


      /* Update the alias set, if required.  */
      if (MEM_P (target) && ! MEM_KEEP_ALIAS_SET_P (target)
	  && MEM_ALIAS_SET (target) != 0)
	{
	  target = copy_rtx (target);
	  set_mem_alias_set (target, alias_set);
	}

      store_constructor (exp, target, cleared, bitsize / BITS_PER_UNIT);
    }
  else
    store_field (target, bitsize, bitpos, mode, exp, VOIDmode, 0, type,
		 alias_set);
}

/* Store the value of constructor EXP into the rtx TARGET.
   TARGET is either a REG or a MEM; we know it cannot conflict, since
   safe_from_p has been called.
   CLEARED is true if TARGET is known to have been zero'd.
   SIZE is the number of bytes of TARGET we are allowed to modify: this
   may not be the same as the size of EXP if we are assigning to a field
   which has been packed to exclude padding bits.  */

static void
store_constructor (tree exp, rtx target, int cleared, HOST_WIDE_INT size)
{
  tree type = TREE_TYPE (exp);
#ifdef WORD_REGISTER_OPERATIONS
  HOST_WIDE_INT exp_size = int_size_in_bytes (type);
#endif

  if (TREE_CODE (type) == RECORD_TYPE || TREE_CODE (type) == UNION_TYPE
      || TREE_CODE (type) == QUAL_UNION_TYPE)
    {
      tree elt;

      /* If size is zero or the target is already cleared, do nothing.  */
      if (size == 0 || cleared)
	cleared = 1;
      /* We either clear the aggregate or indicate the value is dead.  */
      else if ((TREE_CODE (type) == UNION_TYPE
		|| TREE_CODE (type) == QUAL_UNION_TYPE)
	       && ! CONSTRUCTOR_ELTS (exp))
	/* If the constructor is empty, clear the union.  */
	{
	  clear_storage (target, expr_size (exp));
	  cleared = 1;
	}

      /* If we are building a static constructor into a register,
	 set the initial value as zero so we can fold the value into
	 a constant.  But if more than one register is involved,
	 this probably loses.  */
      else if (REG_P (target) && TREE_STATIC (exp)
	       && GET_MODE_SIZE (GET_MODE (target)) <= UNITS_PER_WORD)
	{
	  emit_move_insn (target, CONST0_RTX (GET_MODE (target)));
	  cleared = 1;
	}

      /* If the constructor has fewer fields than the structure
	 or if we are initializing the structure to mostly zeros,
	 clear the whole structure first.  Don't do this if TARGET is a
	 register whose mode size isn't equal to SIZE since clear_storage
	 can't handle this case.  */
      else if (size > 0
	       && ((list_length (CONSTRUCTOR_ELTS (exp)) != fields_length (type))
		   || mostly_zeros_p (exp))
	       && (!REG_P (target)
		   || ((HOST_WIDE_INT) GET_MODE_SIZE (GET_MODE (target))
		       == size)))
	{
	  clear_storage (target, GEN_INT (size));
	  cleared = 1;
	}

      if (! cleared)
	emit_insn (gen_rtx_CLOBBER (VOIDmode, target));

      /* Store each element of the constructor into
	 the corresponding field of TARGET.  */

      for (elt = CONSTRUCTOR_ELTS (exp); elt; elt = TREE_CHAIN (elt))
	{
	  tree field = TREE_PURPOSE (elt);
	  tree value = TREE_VALUE (elt);
	  enum machine_mode mode;
	  HOST_WIDE_INT bitsize;
	  HOST_WIDE_INT bitpos = 0;
	  tree offset;
	  rtx to_rtx = target;

	  /* Just ignore missing fields.
	     We cleared the whole structure, above,
	     if any fields are missing.  */
	  if (field == 0)
	    continue;

	  if (cleared && initializer_zerop (value))
	    continue;

	  if (host_integerp (DECL_SIZE (field), 1))
	    bitsize = tree_low_cst (DECL_SIZE (field), 1);
	  else
	    bitsize = -1;

	  mode = DECL_MODE (field);
	  if (DECL_BIT_FIELD (field))
	    mode = VOIDmode;

	  offset = DECL_FIELD_OFFSET (field);
	  if (host_integerp (offset, 0)
	      && host_integerp (bit_position (field), 0))
	    {
	      bitpos = int_bit_position (field);
	      offset = 0;
	    }
	  else
	    bitpos = tree_low_cst (DECL_FIELD_BIT_OFFSET (field), 0);

	  if (offset)
	    {
	      rtx offset_rtx;

	      offset
		= SUBSTITUTE_PLACEHOLDER_IN_EXPR (offset,
						  make_tree (TREE_TYPE (exp),
							     target));

	      offset_rtx = expand_expr (offset, NULL_RTX, VOIDmode, 0);
	      if (!MEM_P (to_rtx))
		abort ();

#ifdef POINTERS_EXTEND_UNSIGNED
	      if (GET_MODE (offset_rtx) != Pmode)
		offset_rtx = convert_to_mode (Pmode, offset_rtx, 0);
#else
	      if (GET_MODE (offset_rtx) != ptr_mode)
		offset_rtx = convert_to_mode (ptr_mode, offset_rtx, 0);
#endif

	      to_rtx = offset_address (to_rtx, offset_rtx,
				       highest_pow2_factor (offset));
	    }

#ifdef WORD_REGISTER_OPERATIONS
	  /* If this initializes a field that is smaller than a word, at the
	     start of a word, try to widen it to a full word.
	     This special case allows us to output C++ member function
	     initializations in a form that the optimizers can understand.  */
	  if (REG_P (target)
	      && bitsize < BITS_PER_WORD
	      && bitpos % BITS_PER_WORD == 0
	      && GET_MODE_CLASS (mode) == MODE_INT
	      && TREE_CODE (value) == INTEGER_CST
	      && exp_size >= 0
	      && bitpos + BITS_PER_WORD <= exp_size * BITS_PER_UNIT)
	    {
	      tree type = TREE_TYPE (value);

	      if (TYPE_PRECISION (type) < BITS_PER_WORD)
		{
		  type = lang_hooks.types.type_for_size
		    (BITS_PER_WORD, TYPE_UNSIGNED (type));
		  value = convert (type, value);
		}

	      if (BYTES_BIG_ENDIAN)
		value
		  = fold (build2 (LSHIFT_EXPR, type, value,
				  build_int_cst (NULL_TREE,
						 BITS_PER_WORD - bitsize, 0)));
	      bitsize = BITS_PER_WORD;
	      mode = word_mode;
	    }
#endif

	  if (MEM_P (to_rtx) && !MEM_KEEP_ALIAS_SET_P (to_rtx)
	      && DECL_NONADDRESSABLE_P (field))
	    {
	      to_rtx = copy_rtx (to_rtx);
	      MEM_KEEP_ALIAS_SET_P (to_rtx) = 1;
	    }

	  store_constructor_field (to_rtx, bitsize, bitpos, mode,
				   value, type, cleared,
				   get_alias_set (TREE_TYPE (field)));
	}
    }

  else if (TREE_CODE (type) == ARRAY_TYPE)
    {
      tree elt;
      int i;
      int need_to_clear;
      tree domain;
      tree elttype = TREE_TYPE (type);
      int const_bounds_p;
      HOST_WIDE_INT minelt = 0;
      HOST_WIDE_INT maxelt = 0;

      domain = TYPE_DOMAIN (type);
      const_bounds_p = (TYPE_MIN_VALUE (domain)
			&& TYPE_MAX_VALUE (domain)
			&& host_integerp (TYPE_MIN_VALUE (domain), 0)
			&& host_integerp (TYPE_MAX_VALUE (domain), 0));

      /* If we have constant bounds for the range of the type, get them.  */
      if (const_bounds_p)
	{
	  minelt = tree_low_cst (TYPE_MIN_VALUE (domain), 0);
	  maxelt = tree_low_cst (TYPE_MAX_VALUE (domain), 0);
	}

      /* If the constructor has fewer elements than the array,
         clear the whole array first.  Similarly if this is
         static constructor of a non-BLKmode object.  */
      if (cleared)
	need_to_clear = 0;
      else if (REG_P (target) && TREE_STATIC (exp))
	need_to_clear = 1;
      else
	{
	  HOST_WIDE_INT count = 0, zero_count = 0;
	  need_to_clear = ! const_bounds_p;

	  /* This loop is a more accurate version of the loop in
	     mostly_zeros_p (it handles RANGE_EXPR in an index).
	     It is also needed to check for missing elements.  */
	  for (elt = CONSTRUCTOR_ELTS (exp);
	       elt != NULL_TREE && ! need_to_clear;
	       elt = TREE_CHAIN (elt))
	    {
	      tree index = TREE_PURPOSE (elt);
	      HOST_WIDE_INT this_node_count;

	      if (index != NULL_TREE && TREE_CODE (index) == RANGE_EXPR)
		{
		  tree lo_index = TREE_OPERAND (index, 0);
		  tree hi_index = TREE_OPERAND (index, 1);

		  if (! host_integerp (lo_index, 1)
		      || ! host_integerp (hi_index, 1))
		    {
		      need_to_clear = 1;
		      break;
		    }

		  this_node_count = (tree_low_cst (hi_index, 1)
				     - tree_low_cst (lo_index, 1) + 1);
		}
	      else
		this_node_count = 1;

	      count += this_node_count;
	      if (mostly_zeros_p (TREE_VALUE (elt)))
		zero_count += this_node_count;
	    }

	  /* Clear the entire array first if there are any missing elements,
	     or if the incidence of zero elements is >= 75%.  */
	  if (! need_to_clear
	      && (count < maxelt - minelt + 1 || 4 * zero_count >= 3 * count))
	    need_to_clear = 1;
	}

      if (need_to_clear && size > 0)
	{
	  if (REG_P (target))
	    emit_move_insn (target,  CONST0_RTX (GET_MODE (target)));
	  else
	    clear_storage (target, GEN_INT (size));
	  cleared = 1;
	}

      if (!cleared && REG_P (target))
	/* Inform later passes that the old value is dead.  */
	emit_insn (gen_rtx_CLOBBER (VOIDmode, target));

      /* Store each element of the constructor into
	 the corresponding element of TARGET, determined
	 by counting the elements.  */
      for (elt = CONSTRUCTOR_ELTS (exp), i = 0;
	   elt;
	   elt = TREE_CHAIN (elt), i++)
	{
	  enum machine_mode mode;
	  HOST_WIDE_INT bitsize;
	  HOST_WIDE_INT bitpos;
	  int unsignedp;
	  tree value = TREE_VALUE (elt);
	  tree index = TREE_PURPOSE (elt);
	  rtx xtarget = target;

	  if (cleared && initializer_zerop (value))
	    continue;

	  unsignedp = TYPE_UNSIGNED (elttype);
	  mode = TYPE_MODE (elttype);
	  if (mode == BLKmode)
	    bitsize = (host_integerp (TYPE_SIZE (elttype), 1)
		       ? tree_low_cst (TYPE_SIZE (elttype), 1)
		       : -1);
	  else
	    bitsize = GET_MODE_BITSIZE (mode);

	  if (index != NULL_TREE && TREE_CODE (index) == RANGE_EXPR)
	    {
	      tree lo_index = TREE_OPERAND (index, 0);
	      tree hi_index = TREE_OPERAND (index, 1);
	      rtx index_r, pos_rtx;
	      HOST_WIDE_INT lo, hi, count;
	      tree position;

	      /* If the range is constant and "small", unroll the loop.  */
	      if (const_bounds_p
		  && host_integerp (lo_index, 0)
		  && host_integerp (hi_index, 0)
		  && (lo = tree_low_cst (lo_index, 0),
		      hi = tree_low_cst (hi_index, 0),
		      count = hi - lo + 1,
		      (!MEM_P (target)
		       || count <= 2
		       || (host_integerp (TYPE_SIZE (elttype), 1)
			   && (tree_low_cst (TYPE_SIZE (elttype), 1) * count
			       <= 40 * 8)))))
		{
		  lo -= minelt;  hi -= minelt;
		  for (; lo <= hi; lo++)
		    {
		      bitpos = lo * tree_low_cst (TYPE_SIZE (elttype), 0);

		      if (MEM_P (target)
			  && !MEM_KEEP_ALIAS_SET_P (target)
			  && TREE_CODE (type) == ARRAY_TYPE
			  && TYPE_NONALIASED_COMPONENT (type))
			{
			  target = copy_rtx (target);
			  MEM_KEEP_ALIAS_SET_P (target) = 1;
			}

		      store_constructor_field
			(target, bitsize, bitpos, mode, value, type, cleared,
			 get_alias_set (elttype));
		    }
		}
	      else
		{
		  rtx loop_start = gen_label_rtx ();
		  rtx loop_end = gen_label_rtx ();
		  tree exit_cond;

		  expand_expr (hi_index, NULL_RTX, VOIDmode, 0);
		  unsignedp = TYPE_UNSIGNED (domain);

		  index = build_decl (VAR_DECL, NULL_TREE, domain);

		  index_r
		    = gen_reg_rtx (promote_mode (domain, DECL_MODE (index),
						 &unsignedp, 0));
		  SET_DECL_RTL (index, index_r);
		  store_expr (lo_index, index_r, 0);

		  /* Build the head of the loop.  */
		  do_pending_stack_adjust ();
		  emit_label (loop_start);

		  /* Assign value to element index.  */
		  position
		    = convert (ssizetype,
			       fold (build2 (MINUS_EXPR, TREE_TYPE (index),
					     index, TYPE_MIN_VALUE (domain))));
		  position = size_binop (MULT_EXPR, position,
					 convert (ssizetype,
						  TYPE_SIZE_UNIT (elttype)));

		  pos_rtx = expand_expr (position, 0, VOIDmode, 0);
		  xtarget = offset_address (target, pos_rtx,
					    highest_pow2_factor (position));
		  xtarget = adjust_address (xtarget, mode, 0);
		  if (TREE_CODE (value) == CONSTRUCTOR)
		    store_constructor (value, xtarget, cleared,
				       bitsize / BITS_PER_UNIT);
		  else
		    store_expr (value, xtarget, 0);

		  /* Generate a conditional jump to exit the loop.  */
		  exit_cond = build2 (LT_EXPR, integer_type_node,
				      index, hi_index);
		  jumpif (exit_cond, loop_end);

		  /* Update the loop counter, and jump to the head of
		     the loop.  */
		  expand_assignment (index,
			             build2 (PLUS_EXPR, TREE_TYPE (index),
					     index, integer_one_node), 0);

		  emit_jump (loop_start);

		  /* Build the end of the loop.  */
		  emit_label (loop_end);
		}
	    }
	  else if ((index != 0 && ! host_integerp (index, 0))
		   || ! host_integerp (TYPE_SIZE (elttype), 1))
	    {
	      tree position;

	      if (index == 0)
		index = ssize_int (1);

	      if (minelt)
		index = fold_convert (ssizetype,
				      fold (build2 (MINUS_EXPR,
						    TREE_TYPE (index),
						    index,
						    TYPE_MIN_VALUE (domain))));

	      position = size_binop (MULT_EXPR, index,
				     convert (ssizetype,
					      TYPE_SIZE_UNIT (elttype)));
	      xtarget = offset_address (target,
					expand_expr (position, 0, VOIDmode, 0),
					highest_pow2_factor (position));
	      xtarget = adjust_address (xtarget, mode, 0);
	      store_expr (value, xtarget, 0);
	    }
	  else
	    {
	      if (index != 0)
		bitpos = ((tree_low_cst (index, 0) - minelt)
			  * tree_low_cst (TYPE_SIZE (elttype), 1));
	      else
		bitpos = (i * tree_low_cst (TYPE_SIZE (elttype), 1));

	      if (MEM_P (target) && !MEM_KEEP_ALIAS_SET_P (target)
		  && TREE_CODE (type) == ARRAY_TYPE
		  && TYPE_NONALIASED_COMPONENT (type))
		{
		  target = copy_rtx (target);
		  MEM_KEEP_ALIAS_SET_P (target) = 1;
		}
	      store_constructor_field (target, bitsize, bitpos, mode, value,
				       type, cleared, get_alias_set (elttype));
	    }
	}
    }

  else if (TREE_CODE (type) == VECTOR_TYPE)
    {
      tree elt;
      int i;
      int need_to_clear;
      int icode = 0;
      tree elttype = TREE_TYPE (type);
      int elt_size = tree_low_cst (TYPE_SIZE (elttype), 1);
      enum machine_mode eltmode = TYPE_MODE (elttype);
      HOST_WIDE_INT bitsize;
      HOST_WIDE_INT bitpos;
      rtx *vector = NULL;
      unsigned n_elts;

      if (eltmode == BLKmode)
	abort ();

      n_elts = TYPE_VECTOR_SUBPARTS (type);
      if (REG_P (target) && VECTOR_MODE_P (GET_MODE (target)))
	{
	  enum machine_mode mode = GET_MODE (target);

	  icode = (int) vec_init_optab->handlers[mode].insn_code;
	  if (icode != CODE_FOR_nothing)
	    {
	      unsigned int i;

	      vector = alloca (n_elts);
	      for (i = 0; i < n_elts; i++)
		vector [i] = CONST0_RTX (GET_MODE_INNER (mode));
	    }
	}

      /* If the constructor has fewer elements than the vector,
         clear the whole array first.  Similarly if this is
         static constructor of a non-BLKmode object.  */
      if (cleared)
	need_to_clear = 0;
      else if (REG_P (target) && TREE_STATIC (exp))
	need_to_clear = 1;
      else
	{
	  unsigned HOST_WIDE_INT count = 0, zero_count = 0;

	  for (elt = CONSTRUCTOR_ELTS (exp);
	       elt != NULL_TREE;
	       elt = TREE_CHAIN (elt))
	    {
	      int n_elts_here =
		tree_low_cst (
		  int_const_binop (TRUNC_DIV_EXPR,
				   TYPE_SIZE (TREE_TYPE (TREE_VALUE (elt))),
				   TYPE_SIZE (elttype), 0), 1);

	      count += n_elts_here;
	      if (mostly_zeros_p (TREE_VALUE (elt)))
	        zero_count += n_elts_here;
	    }

	  /* Clear the entire vector first if there are any missing elements,
	     or if the incidence of zero elements is >= 75%.  */
	  need_to_clear = (count < n_elts || 4 * zero_count >= 3 * count);
	}

      if (need_to_clear && size > 0 && !vector)
	{
	  if (REG_P (target))
	    emit_move_insn (target,  CONST0_RTX (GET_MODE (target)));
	  else
	    clear_storage (target, GEN_INT (size));
	  cleared = 1;
	}

      if (!cleared && REG_P (target))
	/* Inform later passes that the old value is dead.  */
	emit_insn (gen_rtx_CLOBBER (VOIDmode, target));

      /* Store each element of the constructor into the corresponding
	 element of TARGET, determined by counting the elements.  */
      for (elt = CONSTRUCTOR_ELTS (exp), i = 0;
	   elt;
	   elt = TREE_CHAIN (elt), i += bitsize / elt_size)
	{
	  tree value = TREE_VALUE (elt);
	  tree index = TREE_PURPOSE (elt);
	  HOST_WIDE_INT eltpos;

	  bitsize = tree_low_cst (TYPE_SIZE (TREE_TYPE (value)), 1);
	  if (cleared && initializer_zerop (value))
	    continue;

	  if (index != 0)
	    eltpos = tree_low_cst (index, 1);
	  else
	    eltpos = i;

	  if (vector)
	    {
	      /* Vector CONSTRUCTORs should only be built from smaller
		 vectors in the case of BLKmode vectors.  */
	      if (TREE_CODE (TREE_TYPE (value)) == VECTOR_TYPE)
		abort ();
	      vector[eltpos] = expand_expr (value, NULL_RTX, VOIDmode, 0);
	    }
	  else
	    {
	      enum machine_mode value_mode =
		TREE_CODE (TREE_TYPE (value)) == VECTOR_TYPE
		  ? TYPE_MODE (TREE_TYPE (value))
		  : eltmode;
	      bitpos = eltpos * elt_size;
	      store_constructor_field (target, bitsize, bitpos, value_mode, value,
				       type, cleared, get_alias_set (elttype));
	    }
	}

      if (vector)
	emit_insn (GEN_FCN (icode) (target,
				    gen_rtx_PARALLEL (GET_MODE (target),
						      gen_rtvec_v (n_elts, vector))));
    }

  /* Set constructor assignments.  */
  else if (TREE_CODE (type) == SET_TYPE)
    {
      tree elt = CONSTRUCTOR_ELTS (exp);
      unsigned HOST_WIDE_INT nbytes = int_size_in_bytes (type), nbits;
      tree domain = TYPE_DOMAIN (type);
      tree domain_min, domain_max, bitlength;

      /* The default implementation strategy is to extract the constant
	 parts of the constructor, use that to initialize the target,
	 and then "or" in whatever non-constant ranges we need in addition.

	 If a large set is all zero or all ones, it is
	 probably better to set it using memset.
	 Also, if a large set has just a single range, it may also be
	 better to first clear all the first clear the set (using
	 memset), and set the bits we want.  */

      /* Check for all zeros.  */
      if (elt == NULL_TREE && size > 0)
	{
	  if (!cleared)
	    clear_storage (target, GEN_INT (size));
	  return;
	}

      domain_min = convert (sizetype, TYPE_MIN_VALUE (domain));
      domain_max = convert (sizetype, TYPE_MAX_VALUE (domain));
      bitlength = size_binop (PLUS_EXPR,
			      size_diffop (domain_max, domain_min),
			      ssize_int (1));

      nbits = tree_low_cst (bitlength, 1);

      /* For "small" sets, or "medium-sized" (up to 32 bytes) sets that
	 are "complicated" (more than one range), initialize (the
	 constant parts) by copying from a constant.  */
      if (GET_MODE (target) != BLKmode || nbits <= 2 * BITS_PER_WORD
	  || (nbytes <= 32 && TREE_CHAIN (elt) != NULL_TREE))
	{
	  unsigned int set_word_size = TYPE_ALIGN (TREE_TYPE (exp));
	  enum machine_mode mode = mode_for_size (set_word_size, MODE_INT, 1);
	  char *bit_buffer = alloca (nbits);
	  HOST_WIDE_INT word = 0;
	  unsigned int bit_pos = 0;
	  unsigned int ibit = 0;
	  unsigned int offset = 0;  /* In bytes from beginning of set.  */

	  elt = get_set_constructor_bits (exp, bit_buffer, nbits);
	  for (;;)
	    {
	      if (bit_buffer[ibit])
		{
		  if (BYTES_BIG_ENDIAN)
		    word |= (1 << (set_word_size - 1 - bit_pos));
		  else
		    word |= 1 << bit_pos;
		}

	      bit_pos++;  ibit++;
	      if (bit_pos >= set_word_size || ibit == nbits)
		{
		  if (word != 0 || ! cleared)
		    {
		      rtx datum = gen_int_mode (word, mode);
		      rtx to_rtx;

		      /* The assumption here is that it is safe to use
			 XEXP if the set is multi-word, but not if
			 it's single-word.  */
		      if (MEM_P (target))
			to_rtx = adjust_address (target, mode, offset);
		      else if (offset == 0)
			to_rtx = target;
		      else
			abort ();
		      emit_move_insn (to_rtx, datum);
		    }

		  if (ibit == nbits)
		    break;
		  word = 0;
		  bit_pos = 0;
		  offset += set_word_size / BITS_PER_UNIT;
		}
	    }
	}
      else if (!cleared)
	/* Don't bother clearing storage if the set is all ones.  */
	if (TREE_CHAIN (elt) != NULL_TREE
	    || (TREE_PURPOSE (elt) == NULL_TREE
		? nbits != 1
		: ( ! host_integerp (TREE_VALUE (elt), 0)
		   || ! host_integerp (TREE_PURPOSE (elt), 0)
		   || (tree_low_cst (TREE_VALUE (elt), 0)
		       - tree_low_cst (TREE_PURPOSE (elt), 0) + 1
		       != (HOST_WIDE_INT) nbits))))
	  clear_storage (target, expr_size (exp));

      for (; elt != NULL_TREE; elt = TREE_CHAIN (elt))
	{
	  /* Start of range of element or NULL.  */
	  tree startbit = TREE_PURPOSE (elt);
	  /* End of range of element, or element value.  */
	  tree endbit   = TREE_VALUE (elt);
	  HOST_WIDE_INT startb, endb;
	  rtx bitlength_rtx, startbit_rtx, endbit_rtx, targetx;

	  bitlength_rtx = expand_expr (bitlength,
				       NULL_RTX, MEM, EXPAND_CONST_ADDRESS);

	  /* Handle non-range tuple element like [ expr ].  */
	  if (startbit == NULL_TREE)
	    {
	      startbit = save_expr (endbit);
	      endbit = startbit;
	    }

	  startbit = convert (sizetype, startbit);
	  endbit = convert (sizetype, endbit);
	  if (! integer_zerop (domain_min))
	    {
	      startbit = size_binop (MINUS_EXPR, startbit, domain_min);
	      endbit = size_binop (MINUS_EXPR, endbit, domain_min);
	    }
	  startbit_rtx = expand_expr (startbit, NULL_RTX, MEM,
				      EXPAND_CONST_ADDRESS);
	  endbit_rtx = expand_expr (endbit, NULL_RTX, MEM,
				    EXPAND_CONST_ADDRESS);

	  if (REG_P (target))
	    {
	      targetx
		= assign_temp
		  ((build_qualified_type (lang_hooks.types.type_for_mode
					  (GET_MODE (target), 0),
					  TYPE_QUAL_CONST)),
		   0, 1, 1);
	      emit_move_insn (targetx, target);
	    }

	  else if (MEM_P (target))
	    targetx = target;
	  else
	    abort ();

	  /* Optimization:  If startbit and endbit are constants divisible
	     by BITS_PER_UNIT, call memset instead.  */
	  if (TREE_CODE (startbit) == INTEGER_CST
	      && TREE_CODE (endbit) == INTEGER_CST
	      && (startb = TREE_INT_CST_LOW (startbit)) % BITS_PER_UNIT == 0
	      && (endb = TREE_INT_CST_LOW (endbit) + 1) % BITS_PER_UNIT == 0)
	    {
	      emit_library_call (memset_libfunc, LCT_NORMAL,
				 VOIDmode, 3,
				 plus_constant (XEXP (targetx, 0),
						startb / BITS_PER_UNIT),
				 Pmode,
				 constm1_rtx, TYPE_MODE (integer_type_node),
				 GEN_INT ((endb - startb) / BITS_PER_UNIT),
				 TYPE_MODE (sizetype));
	    }
	  else
	    emit_library_call (setbits_libfunc, LCT_NORMAL,
			       VOIDmode, 4, XEXP (targetx, 0),
			       Pmode, bitlength_rtx, TYPE_MODE (sizetype),
			       startbit_rtx, TYPE_MODE (sizetype),
			       endbit_rtx, TYPE_MODE (sizetype));

	  if (REG_P (target))
	    emit_move_insn (target, targetx);
	}
    }

  else
    abort ();
}

/* Store the value of EXP (an expression tree)
   into a subfield of TARGET which has mode MODE and occupies
   BITSIZE bits, starting BITPOS bits from the start of TARGET.
   If MODE is VOIDmode, it means that we are storing into a bit-field.

   If VALUE_MODE is VOIDmode, return nothing in particular.
   UNSIGNEDP is not used in this case.

   Otherwise, return an rtx for the value stored.  This rtx
   has mode VALUE_MODE if that is convenient to do.
   In this case, UNSIGNEDP must be nonzero if the value is an unsigned type.

   TYPE is the type of the underlying object,

   ALIAS_SET is the alias set for the destination.  This value will
   (in general) be different from that for TARGET, since TARGET is a
   reference to the containing structure.  */

static rtx
store_field (rtx target, HOST_WIDE_INT bitsize, HOST_WIDE_INT bitpos,
	     enum machine_mode mode, tree exp, enum machine_mode value_mode,
	     int unsignedp, tree type, int alias_set)
{
  HOST_WIDE_INT width_mask = 0;

  if (TREE_CODE (exp) == ERROR_MARK)
    return const0_rtx;

  /* If we have nothing to store, do nothing unless the expression has
     side-effects.  */
  if (bitsize == 0)
    return expand_expr (exp, const0_rtx, VOIDmode, 0);
  else if (bitsize >= 0 && bitsize < HOST_BITS_PER_WIDE_INT)
    width_mask = ((HOST_WIDE_INT) 1 << bitsize) - 1;

  /* If we are storing into an unaligned field of an aligned union that is
     in a register, we may have the mode of TARGET being an integer mode but
     MODE == BLKmode.  In that case, get an aligned object whose size and
     alignment are the same as TARGET and store TARGET into it (we can avoid
     the store if the field being stored is the entire width of TARGET).  Then
     call ourselves recursively to store the field into a BLKmode version of
     that object.  Finally, load from the object into TARGET.  This is not
     very efficient in general, but should only be slightly more expensive
     than the otherwise-required unaligned accesses.  Perhaps this can be
     cleaned up later.  It's tempting to make OBJECT readonly, but it's set
     twice, once with emit_move_insn and once via store_field.  */

  if (mode == BLKmode
      && (REG_P (target) || GET_CODE (target) == SUBREG))
    {
      rtx object = assign_temp (type, 0, 1, 1);
      rtx blk_object = adjust_address (object, BLKmode, 0);

      if (bitsize != (HOST_WIDE_INT) GET_MODE_BITSIZE (GET_MODE (target)))
	emit_move_insn (object, target);

      store_field (blk_object, bitsize, bitpos, mode, exp, VOIDmode, 0, type,
		   alias_set);

      emit_move_insn (target, object);

      /* We want to return the BLKmode version of the data.  */
      return blk_object;
    }

  if (GET_CODE (target) == CONCAT)
    {
      /* We're storing into a struct containing a single __complex.  */

      if (bitpos != 0)
	abort ();
      return store_expr (exp, target, value_mode != VOIDmode);
    }

  /* If the structure is in a register or if the component
     is a bit field, we cannot use addressing to access it.
     Use bit-field techniques or SUBREG to store in it.  */

  if (mode == VOIDmode
      || (mode != BLKmode && ! direct_store[(int) mode]
	  && GET_MODE_CLASS (mode) != MODE_COMPLEX_INT
	  && GET_MODE_CLASS (mode) != MODE_COMPLEX_FLOAT)
      || REG_P (target)
      || GET_CODE (target) == SUBREG
      /* If the field isn't aligned enough to store as an ordinary memref,
	 store it as a bit field.  */
      || (mode != BLKmode
	  && ((((MEM_ALIGN (target) < GET_MODE_ALIGNMENT (mode))
		|| bitpos % GET_MODE_ALIGNMENT (mode))
	       && SLOW_UNALIGNED_ACCESS (mode, MEM_ALIGN (target)))
	      || (bitpos % BITS_PER_UNIT != 0)))
      /* If the RHS and field are a constant size and the size of the
	 RHS isn't the same size as the bitfield, we must use bitfield
	 operations.  */
      || (bitsize >= 0
	  && TREE_CODE (TYPE_SIZE (TREE_TYPE (exp))) == INTEGER_CST
	  && compare_tree_int (TYPE_SIZE (TREE_TYPE (exp)), bitsize) != 0))
    {
      rtx temp = expand_expr (exp, NULL_RTX, VOIDmode, 0);

      /* If BITSIZE is narrower than the size of the type of EXP
	 we will be narrowing TEMP.  Normally, what's wanted are the
	 low-order bits.  However, if EXP's type is a record and this is
	 big-endian machine, we want the upper BITSIZE bits.  */
      if (BYTES_BIG_ENDIAN && GET_MODE_CLASS (GET_MODE (temp)) == MODE_INT
	  && bitsize < (HOST_WIDE_INT) GET_MODE_BITSIZE (GET_MODE (temp))
	  && TREE_CODE (TREE_TYPE (exp)) == RECORD_TYPE)
	temp = expand_shift (RSHIFT_EXPR, GET_MODE (temp), temp,
			     size_int (GET_MODE_BITSIZE (GET_MODE (temp))
				       - bitsize),
			     NULL_RTX, 1);

      /* Unless MODE is VOIDmode or BLKmode, convert TEMP to
	 MODE.  */
      if (mode != VOIDmode && mode != BLKmode
	  && mode != TYPE_MODE (TREE_TYPE (exp)))
	temp = convert_modes (mode, TYPE_MODE (TREE_TYPE (exp)), temp, 1);

      /* If the modes of TARGET and TEMP are both BLKmode, both
	 must be in memory and BITPOS must be aligned on a byte
	 boundary.  If so, we simply do a block copy.  */
      if (GET_MODE (target) == BLKmode && GET_MODE (temp) == BLKmode)
	{
	  if (!MEM_P (target) || !MEM_P (temp)
	      || bitpos % BITS_PER_UNIT != 0)
	    abort ();

	  target = adjust_address (target, VOIDmode, bitpos / BITS_PER_UNIT);
	  emit_block_move (target, temp,
			   GEN_INT ((bitsize + BITS_PER_UNIT - 1)
				    / BITS_PER_UNIT),
			   BLOCK_OP_NORMAL);

	  return value_mode == VOIDmode ? const0_rtx : target;
	}

      /* Store the value in the bitfield.  */
      store_bit_field (target, bitsize, bitpos, mode, temp);

      if (value_mode != VOIDmode)
	{
	  /* The caller wants an rtx for the value.
	     If possible, avoid refetching from the bitfield itself.  */
	  if (width_mask != 0
	      && ! (MEM_P (target) && MEM_VOLATILE_P (target)))
	    {
	      tree count;
	      enum machine_mode tmode;

	      tmode = GET_MODE (temp);
	      if (tmode == VOIDmode)
		tmode = value_mode;

	      if (unsignedp)
		return expand_and (tmode, temp,
				   gen_int_mode (width_mask, tmode),
				   NULL_RTX);

	      count = build_int_cst (NULL_TREE,
				     GET_MODE_BITSIZE (tmode) - bitsize, 0);
	      temp = expand_shift (LSHIFT_EXPR, tmode, temp, count, 0, 0);
	      return expand_shift (RSHIFT_EXPR, tmode, temp, count, 0, 0);
	    }

	  return extract_bit_field (target, bitsize, bitpos, unsignedp,
				    NULL_RTX, value_mode, VOIDmode);
	}
      return const0_rtx;
    }
  else
    {
      rtx addr = XEXP (target, 0);
      rtx to_rtx = target;

      /* If a value is wanted, it must be the lhs;
	 so make the address stable for multiple use.  */

      if (value_mode != VOIDmode && !REG_P (addr)
	  && ! CONSTANT_ADDRESS_P (addr)
	  /* A frame-pointer reference is already stable.  */
	  && ! (GET_CODE (addr) == PLUS
		&& GET_CODE (XEXP (addr, 1)) == CONST_INT
		&& (XEXP (addr, 0) == virtual_incoming_args_rtx
		    || XEXP (addr, 0) == virtual_stack_vars_rtx)))
	to_rtx = replace_equiv_address (to_rtx, copy_to_reg (addr));

      /* Now build a reference to just the desired component.  */

      to_rtx = adjust_address (target, mode, bitpos / BITS_PER_UNIT);

      if (to_rtx == target)
	to_rtx = copy_rtx (to_rtx);

      MEM_SET_IN_STRUCT_P (to_rtx, 1);
      if (!MEM_KEEP_ALIAS_SET_P (to_rtx) && MEM_ALIAS_SET (to_rtx) != 0)
	set_mem_alias_set (to_rtx, alias_set);

      return store_expr (exp, to_rtx, value_mode != VOIDmode);
    }
}

/* Given an expression EXP that may be a COMPONENT_REF, a BIT_FIELD_REF,
   an ARRAY_REF, or an ARRAY_RANGE_REF, look for nested operations of these
   codes and find the ultimate containing object, which we return.

   We set *PBITSIZE to the size in bits that we want, *PBITPOS to the
   bit position, and *PUNSIGNEDP to the signedness of the field.
   If the position of the field is variable, we store a tree
   giving the variable offset (in units) in *POFFSET.
   This offset is in addition to the bit position.
   If the position is not variable, we store 0 in *POFFSET.

   If any of the extraction expressions is volatile,
   we store 1 in *PVOLATILEP.  Otherwise we don't change that.

   If the field is a bit-field, *PMODE is set to VOIDmode.  Otherwise, it
   is a mode that can be used to access the field.  In that case, *PBITSIZE
   is redundant.

   If the field describes a variable-sized object, *PMODE is set to
   VOIDmode and *PBITSIZE is set to -1.  An access cannot be made in
   this case, but the address of the object can be found.  */

tree
get_inner_reference (tree exp, HOST_WIDE_INT *pbitsize,
		     HOST_WIDE_INT *pbitpos, tree *poffset,
		     enum machine_mode *pmode, int *punsignedp,
		     int *pvolatilep)
{
  tree size_tree = 0;
  enum machine_mode mode = VOIDmode;
  tree offset = size_zero_node;
  tree bit_offset = bitsize_zero_node;
  tree tem;

  /* First get the mode, signedness, and size.  We do this from just the
     outermost expression.  */
  if (TREE_CODE (exp) == COMPONENT_REF)
    {
      size_tree = DECL_SIZE (TREE_OPERAND (exp, 1));
      if (! DECL_BIT_FIELD (TREE_OPERAND (exp, 1)))
	mode = DECL_MODE (TREE_OPERAND (exp, 1));

      *punsignedp = DECL_UNSIGNED (TREE_OPERAND (exp, 1));
    }
  else if (TREE_CODE (exp) == BIT_FIELD_REF)
    {
      size_tree = TREE_OPERAND (exp, 1);
      *punsignedp = BIT_FIELD_REF_UNSIGNED (exp);
    }
  else
    {
      mode = TYPE_MODE (TREE_TYPE (exp));
      *punsignedp = TYPE_UNSIGNED (TREE_TYPE (exp));

      if (mode == BLKmode)
	size_tree = TYPE_SIZE (TREE_TYPE (exp));
      else
	*pbitsize = GET_MODE_BITSIZE (mode);
    }

  if (size_tree != 0)
    {
      if (! host_integerp (size_tree, 1))
	mode = BLKmode, *pbitsize = -1;
      else
	*pbitsize = tree_low_cst (size_tree, 1);
    }

  /* Compute cumulative bit-offset for nested component-refs and array-refs,
     and find the ultimate containing object.  */
  while (1)
    {
      if (TREE_CODE (exp) == BIT_FIELD_REF)
	bit_offset = size_binop (PLUS_EXPR, bit_offset, TREE_OPERAND (exp, 2));
      else if (TREE_CODE (exp) == COMPONENT_REF)
	{
	  tree field = TREE_OPERAND (exp, 1);
	  tree this_offset = component_ref_field_offset (exp);

	  /* If this field hasn't been filled in yet, don't go
	     past it.  This should only happen when folding expressions
	     made during type construction.  */
	  if (this_offset == 0)
	    break;

	  offset = size_binop (PLUS_EXPR, offset, this_offset);
	  bit_offset = size_binop (PLUS_EXPR, bit_offset,
				   DECL_FIELD_BIT_OFFSET (field));

	  /* ??? Right now we don't do anything with DECL_OFFSET_ALIGN.  */
	}

      else if (TREE_CODE (exp) == ARRAY_REF
	       || TREE_CODE (exp) == ARRAY_RANGE_REF)
	{
	  tree index = TREE_OPERAND (exp, 1);
	  tree low_bound = array_ref_low_bound (exp);
	  tree unit_size = array_ref_element_size (exp);

	  /* We assume all arrays have sizes that are a multiple of a byte.
	     First subtract the lower bound, if any, in the type of the
	     index, then convert to sizetype and multiply by the size of the
	     array element.  */
	  if (! integer_zerop (low_bound))
	    index = fold (build2 (MINUS_EXPR, TREE_TYPE (index),
				  index, low_bound));

	  offset = size_binop (PLUS_EXPR, offset,
			       size_binop (MULT_EXPR,
					   convert (sizetype, index),
					   unit_size));
	}

      /* We can go inside most conversions: all NON_VALUE_EXPRs, all normal
	 conversions that don't change the mode, and all view conversions
	 except those that need to "step up" the alignment.  */
      else if (TREE_CODE (exp) != NON_LVALUE_EXPR
	       && ! (TREE_CODE (exp) == VIEW_CONVERT_EXPR
		     && ! ((TYPE_ALIGN (TREE_TYPE (exp))
			    > TYPE_ALIGN (TREE_TYPE (TREE_OPERAND (exp, 0))))
			   && STRICT_ALIGNMENT
			   && (TYPE_ALIGN (TREE_TYPE (TREE_OPERAND (exp, 0)))
			       < BIGGEST_ALIGNMENT)
			   && (TYPE_ALIGN_OK (TREE_TYPE (exp))
			       || TYPE_ALIGN_OK (TREE_TYPE
						 (TREE_OPERAND (exp, 0))))))
	       && ! ((TREE_CODE (exp) == NOP_EXPR
		      || TREE_CODE (exp) == CONVERT_EXPR)
		     && (TYPE_MODE (TREE_TYPE (exp))
			 == TYPE_MODE (TREE_TYPE (TREE_OPERAND (exp, 0))))))
	break;

      /* If any reference in the chain is volatile, the effect is volatile.  */
      if (TREE_THIS_VOLATILE (exp))
	*pvolatilep = 1;

      exp = TREE_OPERAND (exp, 0);
    }

  /* If OFFSET is constant, see if we can return the whole thing as a
     constant bit position.  Otherwise, split it up.  */
  if (host_integerp (offset, 0)
      && 0 != (tem = size_binop (MULT_EXPR, convert (bitsizetype, offset),
				 bitsize_unit_node))
      && 0 != (tem = size_binop (PLUS_EXPR, tem, bit_offset))
      && host_integerp (tem, 0))
    *pbitpos = tree_low_cst (tem, 0), *poffset = 0;
  else
    *pbitpos = tree_low_cst (bit_offset, 0), *poffset = offset;

  *pmode = mode;
  return exp;
}

/* Return a tree of sizetype representing the size, in bytes, of the element
   of EXP, an ARRAY_REF.  */

tree
array_ref_element_size (tree exp)
{
  tree aligned_size = TREE_OPERAND (exp, 3);
  tree elmt_type = TREE_TYPE (TREE_TYPE (TREE_OPERAND (exp, 0)));

  /* If a size was specified in the ARRAY_REF, it's the size measured
     in alignment units of the element type.  So multiply by that value.  */
  if (aligned_size)
    return size_binop (MULT_EXPR, aligned_size,
		       size_int (TYPE_ALIGN (elmt_type) / BITS_PER_UNIT));

  /* Otherwise, take the size from that of the element type.  Substitute
     any PLACEHOLDER_EXPR that we have.  */
  else
    return SUBSTITUTE_PLACEHOLDER_IN_EXPR (TYPE_SIZE_UNIT (elmt_type), exp);
}

/* Return a tree representing the lower bound of the array mentioned in
   EXP, an ARRAY_REF.  */

tree
array_ref_low_bound (tree exp)
{
  tree domain_type = TYPE_DOMAIN (TREE_TYPE (TREE_OPERAND (exp, 0)));

  /* If a lower bound is specified in EXP, use it.  */
  if (TREE_OPERAND (exp, 2))
    return TREE_OPERAND (exp, 2);

  /* Otherwise, if there is a domain type and it has a lower bound, use it,
     substituting for a PLACEHOLDER_EXPR as needed.  */
  if (domain_type && TYPE_MIN_VALUE (domain_type))
    return SUBSTITUTE_PLACEHOLDER_IN_EXPR (TYPE_MIN_VALUE (domain_type), exp);

  /* Otherwise, return a zero of the appropriate type.  */
  return fold_convert (TREE_TYPE (TREE_OPERAND (exp, 1)), integer_zero_node);
}

/* Return a tree representing the upper bound of the array mentioned in
   EXP, an ARRAY_REF.  */

tree
array_ref_up_bound (tree exp)
{
  tree domain_type = TYPE_DOMAIN (TREE_TYPE (TREE_OPERAND (exp, 0)));

  /* If there is a domain type and it has an upper bound, use it, substituting
     for a PLACEHOLDER_EXPR as needed.  */
  if (domain_type && TYPE_MAX_VALUE (domain_type))
    return SUBSTITUTE_PLACEHOLDER_IN_EXPR (TYPE_MAX_VALUE (domain_type), exp);

  /* Otherwise fail.  */
  return NULL_TREE;
}

/* Return a tree representing the offset, in bytes, of the field referenced
   by EXP.  This does not include any offset in DECL_FIELD_BIT_OFFSET.  */

tree
component_ref_field_offset (tree exp)
{
  tree aligned_offset = TREE_OPERAND (exp, 2);
  tree field = TREE_OPERAND (exp, 1);

  /* If an offset was specified in the COMPONENT_REF, it's the offset measured
     in units of DECL_OFFSET_ALIGN / BITS_PER_UNIT.  So multiply by that
     value.  */
  if (aligned_offset)
    return size_binop (MULT_EXPR, aligned_offset,
		       size_int (DECL_OFFSET_ALIGN (field) / BITS_PER_UNIT));

  /* Otherwise, take the offset from that of the field.  Substitute
     any PLACEHOLDER_EXPR that we have.  */
  else
    return SUBSTITUTE_PLACEHOLDER_IN_EXPR (DECL_FIELD_OFFSET (field), exp);
}

/* Return 1 if T is an expression that get_inner_reference handles.  */

int
handled_component_p (tree t)
{
  switch (TREE_CODE (t))
    {
    case BIT_FIELD_REF:
    case COMPONENT_REF:
    case ARRAY_REF:
    case ARRAY_RANGE_REF:
    case NON_LVALUE_EXPR:
    case VIEW_CONVERT_EXPR:
      return 1;

    /* ??? Sure they are handled, but get_inner_reference may return
       a different PBITSIZE, depending upon whether the expression is
       wrapped up in a NOP_EXPR or not, e.g. for bitfields.  */
    case NOP_EXPR:
    case CONVERT_EXPR:
      return (TYPE_MODE (TREE_TYPE (t))
	      == TYPE_MODE (TREE_TYPE (TREE_OPERAND (t, 0))));

    default:
      return 0;
    }
}

/* Given an rtx VALUE that may contain additions and multiplications, return
   an equivalent value that just refers to a register, memory, or constant.
   This is done by generating instructions to perform the arithmetic and
   returning a pseudo-register containing the value.

   The returned value may be a REG, SUBREG, MEM or constant.  */

rtx
force_operand (rtx value, rtx target)
{
  rtx op1, op2;
  /* Use subtarget as the target for operand 0 of a binary operation.  */
  rtx subtarget = get_subtarget (target);
  enum rtx_code code = GET_CODE (value);

  /* Check for subreg applied to an expression produced by loop optimizer.  */
  if (code == SUBREG
      && !REG_P (SUBREG_REG (value))
      && !MEM_P (SUBREG_REG (value)))
    {
      value = simplify_gen_subreg (GET_MODE (value),
				   force_reg (GET_MODE (SUBREG_REG (value)),
					      force_operand (SUBREG_REG (value),
							     NULL_RTX)),
				   GET_MODE (SUBREG_REG (value)),
				   SUBREG_BYTE (value));
      code = GET_CODE (value);
    }

  /* Check for a PIC address load.  */
  if ((code == PLUS || code == MINUS)
      && XEXP (value, 0) == pic_offset_table_rtx
      && (GET_CODE (XEXP (value, 1)) == SYMBOL_REF
	  || GET_CODE (XEXP (value, 1)) == LABEL_REF
	  || GET_CODE (XEXP (value, 1)) == CONST))
    {
      if (!subtarget)
	subtarget = gen_reg_rtx (GET_MODE (value));
      emit_move_insn (subtarget, value);
      return subtarget;
    }

  if (code == ZERO_EXTEND || code == SIGN_EXTEND)
    {
      if (!target)
	target = gen_reg_rtx (GET_MODE (value));
      convert_move (target, force_operand (XEXP (value, 0), NULL),
		    code == ZERO_EXTEND);
      return target;
    }

  if (ARITHMETIC_P (value))
    {
      op2 = XEXP (value, 1);
      if (!CONSTANT_P (op2) && !(REG_P (op2) && op2 != subtarget))
	subtarget = 0;
      if (code == MINUS && GET_CODE (op2) == CONST_INT)
	{
	  code = PLUS;
	  op2 = negate_rtx (GET_MODE (value), op2);
	}

      /* Check for an addition with OP2 a constant integer and our first
         operand a PLUS of a virtual register and something else.  In that
         case, we want to emit the sum of the virtual register and the
         constant first and then add the other value.  This allows virtual
         register instantiation to simply modify the constant rather than
         creating another one around this addition.  */
      if (code == PLUS && GET_CODE (op2) == CONST_INT
	  && GET_CODE (XEXP (value, 0)) == PLUS
	  && REG_P (XEXP (XEXP (value, 0), 0))
	  && REGNO (XEXP (XEXP (value, 0), 0)) >= FIRST_VIRTUAL_REGISTER
	  && REGNO (XEXP (XEXP (value, 0), 0)) <= LAST_VIRTUAL_REGISTER)
	{
	  rtx temp = expand_simple_binop (GET_MODE (value), code,
					  XEXP (XEXP (value, 0), 0), op2,
					  subtarget, 0, OPTAB_LIB_WIDEN);
	  return expand_simple_binop (GET_MODE (value), code, temp,
				      force_operand (XEXP (XEXP (value,
								 0), 1), 0),
				      target, 0, OPTAB_LIB_WIDEN);
	}

      op1 = force_operand (XEXP (value, 0), subtarget);
      op2 = force_operand (op2, NULL_RTX);
      switch (code)
	{
	case MULT:
	  return expand_mult (GET_MODE (value), op1, op2, target, 1);
	case DIV:
	  if (!INTEGRAL_MODE_P (GET_MODE (value)))
	    return expand_simple_binop (GET_MODE (value), code, op1, op2,
					target, 1, OPTAB_LIB_WIDEN);
	  else
	    return expand_divmod (0,
				  FLOAT_MODE_P (GET_MODE (value))
				  ? RDIV_EXPR : TRUNC_DIV_EXPR,
				  GET_MODE (value), op1, op2, target, 0);
	  break;
	case MOD:
	  return expand_divmod (1, TRUNC_MOD_EXPR, GET_MODE (value), op1, op2,
				target, 0);
	  break;
	case UDIV:
	  return expand_divmod (0, TRUNC_DIV_EXPR, GET_MODE (value), op1, op2,
				target, 1);
	  break;
	case UMOD:
	  return expand_divmod (1, TRUNC_MOD_EXPR, GET_MODE (value), op1, op2,
				target, 1);
	  break;
	case ASHIFTRT:
	  return expand_simple_binop (GET_MODE (value), code, op1, op2,
				      target, 0, OPTAB_LIB_WIDEN);
	  break;
	default:
	  return expand_simple_binop (GET_MODE (value), code, op1, op2,
				      target, 1, OPTAB_LIB_WIDEN);
	}
    }
  if (UNARY_P (value))
    {
      op1 = force_operand (XEXP (value, 0), NULL_RTX);
      return expand_simple_unop (GET_MODE (value), code, op1, target, 0);
    }

#ifdef INSN_SCHEDULING
  /* On machines that have insn scheduling, we want all memory reference to be
     explicit, so we need to deal with such paradoxical SUBREGs.  */
  if (GET_CODE (value) == SUBREG && MEM_P (SUBREG_REG (value))
      && (GET_MODE_SIZE (GET_MODE (value))
	  > GET_MODE_SIZE (GET_MODE (SUBREG_REG (value)))))
    value
      = simplify_gen_subreg (GET_MODE (value),
			     force_reg (GET_MODE (SUBREG_REG (value)),
					force_operand (SUBREG_REG (value),
						       NULL_RTX)),
			     GET_MODE (SUBREG_REG (value)),
			     SUBREG_BYTE (value));
#endif

  return value;
}

/* Subroutine of expand_expr: return nonzero iff there is no way that
   EXP can reference X, which is being modified.  TOP_P is nonzero if this
   call is going to be used to determine whether we need a temporary
   for EXP, as opposed to a recursive call to this function.

   It is always safe for this routine to return zero since it merely
   searches for optimization opportunities.  */

int
safe_from_p (rtx x, tree exp, int top_p)
{
  rtx exp_rtl = 0;
  int i, nops;

  if (x == 0
      /* If EXP has varying size, we MUST use a target since we currently
	 have no way of allocating temporaries of variable size
	 (except for arrays that have TYPE_ARRAY_MAX_SIZE set).
	 So we assume here that something at a higher level has prevented a
	 clash.  This is somewhat bogus, but the best we can do.  Only
	 do this when X is BLKmode and when we are at the top level.  */
      || (top_p && TREE_TYPE (exp) != 0 && COMPLETE_TYPE_P (TREE_TYPE (exp))
	  && TREE_CODE (TYPE_SIZE (TREE_TYPE (exp))) != INTEGER_CST
	  && (TREE_CODE (TREE_TYPE (exp)) != ARRAY_TYPE
	      || TYPE_ARRAY_MAX_SIZE (TREE_TYPE (exp)) == NULL_TREE
	      || TREE_CODE (TYPE_ARRAY_MAX_SIZE (TREE_TYPE (exp)))
	      != INTEGER_CST)
	  && GET_MODE (x) == BLKmode)
      /* If X is in the outgoing argument area, it is always safe.  */
      || (MEM_P (x)
	  && (XEXP (x, 0) == virtual_outgoing_args_rtx
	      || (GET_CODE (XEXP (x, 0)) == PLUS
		  && XEXP (XEXP (x, 0), 0) == virtual_outgoing_args_rtx))))
    return 1;

  /* If this is a subreg of a hard register, declare it unsafe, otherwise,
     find the underlying pseudo.  */
  if (GET_CODE (x) == SUBREG)
    {
      x = SUBREG_REG (x);
      if (REG_P (x) && REGNO (x) < FIRST_PSEUDO_REGISTER)
	return 0;
    }

  /* Now look at our tree code and possibly recurse.  */
  switch (TREE_CODE_CLASS (TREE_CODE (exp)))
    {
    case 'd':
      exp_rtl = DECL_RTL_IF_SET (exp);
      break;

    case 'c':
      return 1;

    case 'x':
      if (TREE_CODE (exp) == TREE_LIST)
	{
	  while (1)
	    {
	      if (TREE_VALUE (exp) && !safe_from_p (x, TREE_VALUE (exp), 0))
		return 0;
	      exp = TREE_CHAIN (exp);
	      if (!exp)
		return 1;
	      if (TREE_CODE (exp) != TREE_LIST)
		return safe_from_p (x, exp, 0);
	    }
	}
      else if (TREE_CODE (exp) == ERROR_MARK)
	return 1;	/* An already-visited SAVE_EXPR? */
      else
	return 0;

    case 's':
      /* The only case we look at here is the DECL_INITIAL inside a
	 DECL_EXPR.  */
      return (TREE_CODE (exp) != DECL_EXPR
	      || TREE_CODE (DECL_EXPR_DECL (exp)) != VAR_DECL
	      || !DECL_INITIAL (DECL_EXPR_DECL (exp))
	      || safe_from_p (x, DECL_INITIAL (DECL_EXPR_DECL (exp)), 0));

    case '2':
    case '<':
      if (!safe_from_p (x, TREE_OPERAND (exp, 1), 0))
	return 0;
      /* Fall through.  */

    case '1':
      return safe_from_p (x, TREE_OPERAND (exp, 0), 0);

    case 'e':
    case 'r':
      /* Now do code-specific tests.  EXP_RTL is set to any rtx we find in
	 the expression.  If it is set, we conflict iff we are that rtx or
	 both are in memory.  Otherwise, we check all operands of the
	 expression recursively.  */

      switch (TREE_CODE (exp))
	{
	case ADDR_EXPR:
	  /* If the operand is static or we are static, we can't conflict.
	     Likewise if we don't conflict with the operand at all.  */
	  if (staticp (TREE_OPERAND (exp, 0))
	      || TREE_STATIC (exp)
	      || safe_from_p (x, TREE_OPERAND (exp, 0), 0))
	    return 1;

	  /* Otherwise, the only way this can conflict is if we are taking
	     the address of a DECL a that address if part of X, which is
	     very rare.  */
	  exp = TREE_OPERAND (exp, 0);
	  if (DECL_P (exp))
	    {
	      if (!DECL_RTL_SET_P (exp)
		  || !MEM_P (DECL_RTL (exp)))
		return 0;
	      else
		exp_rtl = XEXP (DECL_RTL (exp), 0);
	    }
	  break;

	case INDIRECT_REF:
	  if (MEM_P (x)
	      && alias_sets_conflict_p (MEM_ALIAS_SET (x),
					get_alias_set (exp)))
	    return 0;
	  break;

	case CALL_EXPR:
	  /* Assume that the call will clobber all hard registers and
	     all of memory.  */
	  if ((REG_P (x) && REGNO (x) < FIRST_PSEUDO_REGISTER)
	      || MEM_P (x))
	    return 0;
	  break;

	case WITH_CLEANUP_EXPR:
	case CLEANUP_POINT_EXPR:
	  /* Lowered by gimplify.c.  */
	  abort ();

	case SAVE_EXPR:
	  return safe_from_p (x, TREE_OPERAND (exp, 0), 0);

	default:
	  break;
	}

      /* If we have an rtx, we do not need to scan our operands.  */
      if (exp_rtl)
	break;

      nops = first_rtl_op (TREE_CODE (exp));
      for (i = 0; i < nops; i++)
	if (TREE_OPERAND (exp, i) != 0
	    && ! safe_from_p (x, TREE_OPERAND (exp, i), 0))
	  return 0;

      /* If this is a language-specific tree code, it may require
	 special handling.  */
      if ((unsigned int) TREE_CODE (exp)
	  >= (unsigned int) LAST_AND_UNUSED_TREE_CODE
	  && !lang_hooks.safe_from_p (x, exp))
	return 0;
    }

  /* If we have an rtl, find any enclosed object.  Then see if we conflict
     with it.  */
  if (exp_rtl)
    {
      if (GET_CODE (exp_rtl) == SUBREG)
	{
	  exp_rtl = SUBREG_REG (exp_rtl);
	  if (REG_P (exp_rtl)
	      && REGNO (exp_rtl) < FIRST_PSEUDO_REGISTER)
	    return 0;
	}

      /* If the rtl is X, then it is not safe.  Otherwise, it is unless both
	 are memory and they conflict.  */
      return ! (rtx_equal_p (x, exp_rtl)
		|| (MEM_P (x) && MEM_P (exp_rtl)
		    && true_dependence (exp_rtl, VOIDmode, x,
					rtx_addr_varies_p)));
    }

  /* If we reach here, it is safe.  */
  return 1;
}


/* Return the highest power of two that EXP is known to be a multiple of.
   This is used in updating alignment of MEMs in array references.  */

static unsigned HOST_WIDE_INT
highest_pow2_factor (tree exp)
{
  unsigned HOST_WIDE_INT c0, c1;

  switch (TREE_CODE (exp))
    {
    case INTEGER_CST:
      /* We can find the lowest bit that's a one.  If the low
	 HOST_BITS_PER_WIDE_INT bits are zero, return BIGGEST_ALIGNMENT.
	 We need to handle this case since we can find it in a COND_EXPR,
	 a MIN_EXPR, or a MAX_EXPR.  If the constant overflows, we have an
	 erroneous program, so return BIGGEST_ALIGNMENT to avoid any
	 later ICE.  */
      if (TREE_CONSTANT_OVERFLOW (exp))
	return BIGGEST_ALIGNMENT;
      else
	{
	  /* Note: tree_low_cst is intentionally not used here,
	     we don't care about the upper bits.  */
	  c0 = TREE_INT_CST_LOW (exp);
	  c0 &= -c0;
	  return c0 ? c0 : BIGGEST_ALIGNMENT;
	}
      break;

    case PLUS_EXPR:  case MINUS_EXPR:  case MIN_EXPR:  case MAX_EXPR:
      c0 = highest_pow2_factor (TREE_OPERAND (exp, 0));
      c1 = highest_pow2_factor (TREE_OPERAND (exp, 1));
      return MIN (c0, c1);

    case MULT_EXPR:
      c0 = highest_pow2_factor (TREE_OPERAND (exp, 0));
      c1 = highest_pow2_factor (TREE_OPERAND (exp, 1));
      return c0 * c1;

    case ROUND_DIV_EXPR:  case TRUNC_DIV_EXPR:  case FLOOR_DIV_EXPR:
    case CEIL_DIV_EXPR:
      if (integer_pow2p (TREE_OPERAND (exp, 1))
	  && host_integerp (TREE_OPERAND (exp, 1), 1))
	{
	  c0 = highest_pow2_factor (TREE_OPERAND (exp, 0));
	  c1 = tree_low_cst (TREE_OPERAND (exp, 1), 1);
	  return MAX (1, c0 / c1);
	}
      break;

    case NON_LVALUE_EXPR:  case NOP_EXPR:  case CONVERT_EXPR:
    case SAVE_EXPR:
      return highest_pow2_factor (TREE_OPERAND (exp, 0));

    case COMPOUND_EXPR:
      return highest_pow2_factor (TREE_OPERAND (exp, 1));

    case COND_EXPR:
      c0 = highest_pow2_factor (TREE_OPERAND (exp, 1));
      c1 = highest_pow2_factor (TREE_OPERAND (exp, 2));
      return MIN (c0, c1);

    default:
      break;
    }

  return 1;
}

/* Similar, except that the alignment requirements of TARGET are
   taken into account.  Assume it is at least as aligned as its
   type, unless it is a COMPONENT_REF in which case the layout of
   the structure gives the alignment.  */

static unsigned HOST_WIDE_INT
highest_pow2_factor_for_target (tree target, tree exp)
{
  unsigned HOST_WIDE_INT target_align, factor;

  factor = highest_pow2_factor (exp);
  if (TREE_CODE (target) == COMPONENT_REF)
    target_align = DECL_ALIGN (TREE_OPERAND (target, 1)) / BITS_PER_UNIT;
  else
    target_align = TYPE_ALIGN (TREE_TYPE (target)) / BITS_PER_UNIT;
  return MAX (factor, target_align);
}

/* Expands variable VAR.  */

void
expand_var (tree var)
{
  if (DECL_EXTERNAL (var))
    return;

  if (TREE_STATIC (var))
    /* If this is an inlined copy of a static local variable,
       look up the original decl.  */
    var = DECL_ORIGIN (var);

  if (TREE_STATIC (var)
      ? !TREE_ASM_WRITTEN (var)
      : !DECL_RTL_SET_P (var))
    {
      if (TREE_CODE (var) == VAR_DECL && DECL_VALUE_EXPR (var))
	/* Should be ignored.  */;
      else if (lang_hooks.expand_decl (var))
	/* OK.  */;
      else if (TREE_CODE (var) == VAR_DECL && !TREE_STATIC (var))
	expand_decl (var);
      else if (TREE_CODE (var) == VAR_DECL && TREE_STATIC (var))
	rest_of_decl_compilation (var, 0, 0);
      else if (TREE_CODE (var) == TYPE_DECL
	       || TREE_CODE (var) == CONST_DECL
	       || TREE_CODE (var) == FUNCTION_DECL
	       || TREE_CODE (var) == LABEL_DECL)
	/* No expansion needed.  */;
      else
	abort ();
    }
}

/* Subroutine of expand_expr.  Expand the two operands of a binary
   expression EXP0 and EXP1 placing the results in OP0 and OP1.
   The value may be stored in TARGET if TARGET is nonzero.  The
   MODIFIER argument is as documented by expand_expr.  */

static void
expand_operands (tree exp0, tree exp1, rtx target, rtx *op0, rtx *op1,
		 enum expand_modifier modifier)
{
  if (! safe_from_p (target, exp1, 1))
    target = 0;
  if (operand_equal_p (exp0, exp1, 0))
    {
      *op0 = expand_expr (exp0, target, VOIDmode, modifier);
      *op1 = copy_rtx (*op0);
    }
  else
    {
      /* If we need to preserve evaluation order, copy exp0 into its own
	 temporary variable so that it can't be clobbered by exp1.  */
      if (flag_evaluation_order && TREE_SIDE_EFFECTS (exp1))
	exp0 = save_expr (exp0);
      *op0 = expand_expr (exp0, target, VOIDmode, modifier);
      *op1 = expand_expr (exp1, NULL_RTX, VOIDmode, modifier);
    }
}


/* expand_expr: generate code for computing expression EXP.
   An rtx for the computed value is returned.  The value is never null.
   In the case of a void EXP, const0_rtx is returned.

   The value may be stored in TARGET if TARGET is nonzero.
   TARGET is just a suggestion; callers must assume that
   the rtx returned may not be the same as TARGET.

   If TARGET is CONST0_RTX, it means that the value will be ignored.

   If TMODE is not VOIDmode, it suggests generating the
   result in mode TMODE.  But this is done only when convenient.
   Otherwise, TMODE is ignored and the value generated in its natural mode.
   TMODE is just a suggestion; callers must assume that
   the rtx returned may not have mode TMODE.

   Note that TARGET may have neither TMODE nor MODE.  In that case, it
   probably will not be used.

   If MODIFIER is EXPAND_SUM then when EXP is an addition
   we can return an rtx of the form (MULT (REG ...) (CONST_INT ...))
   or a nest of (PLUS ...) and (MINUS ...) where the terms are
   products as above, or REG or MEM, or constant.
   Ordinarily in such cases we would output mul or add instructions
   and then return a pseudo reg containing the sum.

   EXPAND_INITIALIZER is much like EXPAND_SUM except that
   it also marks a label as absolutely required (it can't be dead).
   It also makes a ZERO_EXTEND or SIGN_EXTEND instead of emitting extend insns.
   This is used for outputting expressions used in initializers.

   EXPAND_CONST_ADDRESS says that it is okay to return a MEM
   with a constant address even if that address is not normally legitimate.
   EXPAND_INITIALIZER and EXPAND_SUM also have this effect.

   EXPAND_STACK_PARM is used when expanding to a TARGET on the stack for
   a call parameter.  Such targets require special care as we haven't yet
   marked TARGET so that it's safe from being trashed by libcalls.  We
   don't want to use TARGET for anything but the final result;
   Intermediate values must go elsewhere.   Additionally, calls to
   emit_block_move will be flagged with BLOCK_OP_CALL_PARM.

   If EXP is a VAR_DECL whose DECL_RTL was a MEM with an invalid
   address, and ALT_RTL is non-NULL, then *ALT_RTL is set to the
   DECL_RTL of the VAR_DECL.  *ALT_RTL is also set if EXP is a
   COMPOUND_EXPR whose second argument is such a VAR_DECL, and so on
   recursively.  */

static rtx expand_expr_real_1 (tree, rtx, enum machine_mode,
			       enum expand_modifier, rtx *);

rtx
expand_expr_real (tree exp, rtx target, enum machine_mode tmode,
		  enum expand_modifier modifier, rtx *alt_rtl)
{
  int rn = -1;
  rtx ret, last = NULL;

  /* Handle ERROR_MARK before anybody tries to access its type.  */
  if (TREE_CODE (exp) == ERROR_MARK
      || TREE_CODE (TREE_TYPE (exp)) == ERROR_MARK)
    {
      ret = CONST0_RTX (tmode);
      return ret ? ret : const0_rtx;
    }

  if (flag_non_call_exceptions)
    {
      rn = lookup_stmt_eh_region (exp);
      /* If rn < 0, then either (1) tree-ssa not used or (2) doesn't throw.  */
      if (rn >= 0)
	last = get_last_insn ();
    }

  /* If this is an expression of some kind and it has an associated line
     number, then emit the line number before expanding the expression.

     We need to save and restore the file and line information so that
     errors discovered during expansion are emitted with the right
     information.  It would be better of the diagnostic routines
     used the file/line information embedded in the tree nodes rather
     than globals.  */
  if (cfun && EXPR_HAS_LOCATION (exp))
    {
      location_t saved_location = input_location;
      input_location = EXPR_LOCATION (exp);
      emit_line_note (input_location);

      /* Record where the insns produced belong.  */
      record_block_change (TREE_BLOCK (exp));

      ret = expand_expr_real_1 (exp, target, tmode, modifier, alt_rtl);

      input_location = saved_location;
    }
  else
    {
      ret = expand_expr_real_1 (exp, target, tmode, modifier, alt_rtl);
    }

  /* If using non-call exceptions, mark all insns that may trap.
     expand_call() will mark CALL_INSNs before we get to this code,
     but it doesn't handle libcalls, and these may trap.  */
  if (rn >= 0)
    {
      rtx insn;
      for (insn = next_real_insn (last); insn;
	   insn = next_real_insn (insn))
	{
	  if (! find_reg_note (insn, REG_EH_REGION, NULL_RTX)
	      /* If we want exceptions for non-call insns, any
		 may_trap_p instruction may throw.  */
	      && GET_CODE (PATTERN (insn)) != CLOBBER
	      && GET_CODE (PATTERN (insn)) != USE
	      && (CALL_P (insn) || may_trap_p (PATTERN (insn))))
	    {
	      REG_NOTES (insn) = alloc_EXPR_LIST (REG_EH_REGION, GEN_INT (rn),
						  REG_NOTES (insn));
	    }
	}
    }

  return ret;
}

static rtx
expand_expr_real_1 (tree exp, rtx target, enum machine_mode tmode,
		    enum expand_modifier modifier, rtx *alt_rtl)
{
  rtx op0, op1, temp;
  tree type = TREE_TYPE (exp);
  int unsignedp;
  enum machine_mode mode;
  enum tree_code code = TREE_CODE (exp);
  optab this_optab;
  rtx subtarget, original_target;
  int ignore;
  tree context;
  bool reduce_bit_field = false;
#define REDUCE_BIT_FIELD(expr)	(reduce_bit_field && !ignore		  \
				 ? reduce_to_bit_field_precision ((expr), \
								  target, \
								  type)	  \
				 : (expr))

  mode = TYPE_MODE (type);
  unsignedp = TYPE_UNSIGNED (type);
  if (lang_hooks.reduce_bit_field_operations
      && TREE_CODE (type) == INTEGER_TYPE
      && GET_MODE_PRECISION (mode) > TYPE_PRECISION (type))
    {
      /* An operation in what may be a bit-field type needs the
	 result to be reduced to the precision of the bit-field type,
	 which is narrower than that of the type's mode.  */
      reduce_bit_field = true;
      if (modifier == EXPAND_STACK_PARM)
	target = 0;
    }

  /* Use subtarget as the target for operand 0 of a binary operation.  */
  subtarget = get_subtarget (target);
  original_target = target;
  ignore = (target == const0_rtx
	    || ((code == NON_LVALUE_EXPR || code == NOP_EXPR
		 || code == CONVERT_EXPR || code == COND_EXPR
		 || code == VIEW_CONVERT_EXPR)
		&& TREE_CODE (type) == VOID_TYPE));

  /* If we are going to ignore this result, we need only do something
     if there is a side-effect somewhere in the expression.  If there
     is, short-circuit the most common cases here.  Note that we must
     not call expand_expr with anything but const0_rtx in case this
     is an initial expansion of a size that contains a PLACEHOLDER_EXPR.  */

  if (ignore)
    {
      if (! TREE_SIDE_EFFECTS (exp))
	return const0_rtx;

      /* Ensure we reference a volatile object even if value is ignored, but
	 don't do this if all we are doing is taking its address.  */
      if (TREE_THIS_VOLATILE (exp)
	  && TREE_CODE (exp) != FUNCTION_DECL
	  && mode != VOIDmode && mode != BLKmode
	  && modifier != EXPAND_CONST_ADDRESS)
	{
	  temp = expand_expr (exp, NULL_RTX, VOIDmode, modifier);
	  if (MEM_P (temp))
	    temp = copy_to_reg (temp);
	  return const0_rtx;
	}

      if (TREE_CODE_CLASS (code) == '1' || code == COMPONENT_REF
	  || code == INDIRECT_REF)
	return expand_expr (TREE_OPERAND (exp, 0), const0_rtx, VOIDmode,
			    modifier);

      else if (TREE_CODE_CLASS (code) == '2' || TREE_CODE_CLASS (code) == '<'
	       || code == ARRAY_REF || code == ARRAY_RANGE_REF)
	{
	  expand_expr (TREE_OPERAND (exp, 0), const0_rtx, VOIDmode, modifier);
	  expand_expr (TREE_OPERAND (exp, 1), const0_rtx, VOIDmode, modifier);
	  return const0_rtx;
	}
      else if ((code == TRUTH_ANDIF_EXPR || code == TRUTH_ORIF_EXPR)
	       && ! TREE_SIDE_EFFECTS (TREE_OPERAND (exp, 1)))
	/* If the second operand has no side effects, just evaluate
	   the first.  */
	return expand_expr (TREE_OPERAND (exp, 0), const0_rtx, VOIDmode,
			    modifier);
      else if (code == BIT_FIELD_REF)
	{
	  expand_expr (TREE_OPERAND (exp, 0), const0_rtx, VOIDmode, modifier);
	  expand_expr (TREE_OPERAND (exp, 1), const0_rtx, VOIDmode, modifier);
	  expand_expr (TREE_OPERAND (exp, 2), const0_rtx, VOIDmode, modifier);
	  return const0_rtx;
	}

      target = 0;
    }

  /* If will do cse, generate all results into pseudo registers
     since 1) that allows cse to find more things
     and 2) otherwise cse could produce an insn the machine
     cannot support.  An exception is a CONSTRUCTOR into a multi-word
     MEM: that's much more likely to be most efficient into the MEM.
     Another is a CALL_EXPR which must return in memory.  */

  if (! cse_not_expected && mode != BLKmode && target
      && (!REG_P (target) || REGNO (target) < FIRST_PSEUDO_REGISTER)
      && ! (code == CONSTRUCTOR && GET_MODE_SIZE (mode) > UNITS_PER_WORD)
      && ! (code == CALL_EXPR && aggregate_value_p (exp, exp)))
    target = 0;

  switch (code)
    {
    case LABEL_DECL:
      {
	tree function = decl_function_context (exp);

	temp = label_rtx (exp);
	temp = gen_rtx_LABEL_REF (Pmode, temp);

	if (function != current_function_decl
	    && function != 0)
	  LABEL_REF_NONLOCAL_P (temp) = 1;

	temp = gen_rtx_MEM (FUNCTION_MODE, temp);
	return temp;
      }

    case PARM_DECL:
    case VAR_DECL:
      /* If a static var's type was incomplete when the decl was written,
	 but the type is complete now, lay out the decl now.  */
      if (DECL_SIZE (exp) == 0
	  && COMPLETE_OR_UNBOUND_ARRAY_TYPE_P (TREE_TYPE (exp))
	  && (TREE_STATIC (exp) || DECL_EXTERNAL (exp)))
	layout_decl (exp, 0);

      /* ... fall through ...  */

    case FUNCTION_DECL:
    case RESULT_DECL:
      if (DECL_RTL (exp) == 0)
	abort ();

      /* Ensure variable marked as used even if it doesn't go through
	 a parser.  If it hasn't be used yet, write out an external
	 definition.  */
      if (! TREE_USED (exp))
	{
	  assemble_external (exp);
	  TREE_USED (exp) = 1;
	}

      /* Show we haven't gotten RTL for this yet.  */
      temp = 0;

      /* Variables inherited from containing functions should have
	 been lowered by this point.  */
      context = decl_function_context (exp);
      if (context != 0
	  && context != current_function_decl
	  && !TREE_STATIC (exp)
	  /* ??? C++ creates functions that are not TREE_STATIC.  */
	  && TREE_CODE (exp) != FUNCTION_DECL)
	abort ();

      /* This is the case of an array whose size is to be determined
	 from its initializer, while the initializer is still being parsed.
	 See expand_decl.  */

      else if (MEM_P (DECL_RTL (exp))
	       && REG_P (XEXP (DECL_RTL (exp), 0)))
	temp = validize_mem (DECL_RTL (exp));

      /* If DECL_RTL is memory, we are in the normal case and either
	 the address is not valid or it is not a register and -fforce-addr
	 is specified, get the address into a register.  */

      else if (MEM_P (DECL_RTL (exp))
	       && modifier != EXPAND_CONST_ADDRESS
	       && modifier != EXPAND_SUM
	       && modifier != EXPAND_INITIALIZER
	       && (! memory_address_p (DECL_MODE (exp),
				       XEXP (DECL_RTL (exp), 0))
		   || (flag_force_addr
		       && !REG_P (XEXP (DECL_RTL (exp), 0)))))
	{
	  if (alt_rtl)
	    *alt_rtl = DECL_RTL (exp);
	  temp = replace_equiv_address (DECL_RTL (exp),
					copy_rtx (XEXP (DECL_RTL (exp), 0)));
	}

      /* If we got something, return it.  But first, set the alignment
	 if the address is a register.  */
      if (temp != 0)
	{
	  if (MEM_P (temp) && REG_P (XEXP (temp, 0)))
	    mark_reg_pointer (XEXP (temp, 0), DECL_ALIGN (exp));

	  return temp;
	}

      /* If the mode of DECL_RTL does not match that of the decl, it
	 must be a promoted value.  We return a SUBREG of the wanted mode,
	 but mark it so that we know that it was already extended.  */

      if (REG_P (DECL_RTL (exp))
	  && GET_MODE (DECL_RTL (exp)) != DECL_MODE (exp))
	{
	  /* Get the signedness used for this variable.  Ensure we get the
	     same mode we got when the variable was declared.  */
	  if (GET_MODE (DECL_RTL (exp))
	      != promote_mode (type, DECL_MODE (exp), &unsignedp,
			       (TREE_CODE (exp) == RESULT_DECL ? 1 : 0)))
	    abort ();

	  temp = gen_lowpart_SUBREG (mode, DECL_RTL (exp));
	  SUBREG_PROMOTED_VAR_P (temp) = 1;
	  SUBREG_PROMOTED_UNSIGNED_SET (temp, unsignedp);
	  return temp;
	}

      return DECL_RTL (exp);

    case INTEGER_CST:
      temp = immed_double_const (TREE_INT_CST_LOW (exp),
				 TREE_INT_CST_HIGH (exp), mode);

      /* ??? If overflow is set, fold will have done an incomplete job,
	 which can result in (plus xx (const_int 0)), which can get
	 simplified by validate_replace_rtx during virtual register
	 instantiation, which can result in unrecognizable insns.
	 Avoid this by forcing all overflows into registers.  */
      if (TREE_CONSTANT_OVERFLOW (exp)
	  && modifier != EXPAND_INITIALIZER)
	temp = force_reg (mode, temp);

      return temp;

    case VECTOR_CST:
      if (GET_MODE_CLASS (TYPE_MODE (TREE_TYPE (exp))) == MODE_VECTOR_INT
	  || GET_MODE_CLASS (TYPE_MODE (TREE_TYPE (exp))) == MODE_VECTOR_FLOAT)
	return const_vector_from_tree (exp);
      else
	return expand_expr (build1 (CONSTRUCTOR, TREE_TYPE (exp),
				    TREE_VECTOR_CST_ELTS (exp)),
			    ignore ? const0_rtx : target, tmode, modifier);

    case CONST_DECL:
      return expand_expr (DECL_INITIAL (exp), target, VOIDmode, modifier);

    case REAL_CST:
      /* If optimized, generate immediate CONST_DOUBLE
	 which will be turned into memory by reload if necessary.

	 We used to force a register so that loop.c could see it.  But
	 this does not allow gen_* patterns to perform optimizations with
	 the constants.  It also produces two insns in cases like "x = 1.0;".
	 On most machines, floating-point constants are not permitted in
	 many insns, so we'd end up copying it to a register in any case.

	 Now, we do the copying in expand_binop, if appropriate.  */
      return CONST_DOUBLE_FROM_REAL_VALUE (TREE_REAL_CST (exp),
					   TYPE_MODE (TREE_TYPE (exp)));

    case COMPLEX_CST:
      /* Handle evaluating a complex constant in a CONCAT target.  */
      if (original_target && GET_CODE (original_target) == CONCAT)
	{
	  enum machine_mode mode = TYPE_MODE (TREE_TYPE (TREE_TYPE (exp)));
	  rtx rtarg, itarg;

	  rtarg = XEXP (original_target, 0);
	  itarg = XEXP (original_target, 1);

	  /* Move the real and imaginary parts separately.  */
	  op0 = expand_expr (TREE_REALPART (exp), rtarg, mode, 0);
	  op1 = expand_expr (TREE_IMAGPART (exp), itarg, mode, 0);

	  if (op0 != rtarg)
	    emit_move_insn (rtarg, op0);
	  if (op1 != itarg)
	    emit_move_insn (itarg, op1);

	  return original_target;
	}

      /* ... fall through ...  */

    case STRING_CST:
      temp = output_constant_def (exp, 1);

      /* temp contains a constant address.
	 On RISC machines where a constant address isn't valid,
	 make some insns to get that address into a register.  */
      if (modifier != EXPAND_CONST_ADDRESS
	  && modifier != EXPAND_INITIALIZER
	  && modifier != EXPAND_SUM
	  && (! memory_address_p (mode, XEXP (temp, 0))
	      || flag_force_addr))
	return replace_equiv_address (temp,
				      copy_rtx (XEXP (temp, 0)));
      return temp;

    case SAVE_EXPR:
      {
	tree val = TREE_OPERAND (exp, 0);
	rtx ret = expand_expr_real_1 (val, target, tmode, modifier, alt_rtl);

	if (TREE_CODE (val) != VAR_DECL || !DECL_ARTIFICIAL (val))
	  {
	    /* We can indeed still hit this case, typically via builtin
	       expanders calling save_expr immediately before expanding
	       something.  Assume this means that we only have to deal
	       with non-BLKmode values.  */
	    if (GET_MODE (ret) == BLKmode)
	      abort ();

	    val = build_decl (VAR_DECL, NULL, TREE_TYPE (exp));
	    DECL_ARTIFICIAL (val) = 1;
	    TREE_OPERAND (exp, 0) = val;

	    if (!CONSTANT_P (ret))
	      ret = copy_to_reg (ret);
	    SET_DECL_RTL (val, ret);
	  }

        return ret;
      }

    case GOTO_EXPR:
      if (TREE_CODE (TREE_OPERAND (exp, 0)) == LABEL_DECL)
	expand_goto (TREE_OPERAND (exp, 0));
      else
	expand_computed_goto (TREE_OPERAND (exp, 0));
      return const0_rtx;

    case CONSTRUCTOR:
      /* If we don't need the result, just ensure we evaluate any
	 subexpressions.  */
      if (ignore)
	{
	  tree elt;

	  for (elt = CONSTRUCTOR_ELTS (exp); elt; elt = TREE_CHAIN (elt))
	    expand_expr (TREE_VALUE (elt), const0_rtx, VOIDmode, 0);

	  return const0_rtx;
	}

      /* All elts simple constants => refer to a constant in memory.  But
	 if this is a non-BLKmode mode, let it store a field at a time
	 since that should make a CONST_INT or CONST_DOUBLE when we
	 fold.  Likewise, if we have a target we can use, it is best to
	 store directly into the target unless the type is large enough
	 that memcpy will be used.  If we are making an initializer and
	 all operands are constant, put it in memory as well.

	FIXME: Avoid trying to fill vector constructors piece-meal.
	Output them with output_constant_def below unless we're sure
	they're zeros.  This should go away when vector initializers
	are treated like VECTOR_CST instead of arrays.
      */
      else if ((TREE_STATIC (exp)
		&& ((mode == BLKmode
		     && ! (target != 0 && safe_from_p (target, exp, 1)))
		    || TREE_ADDRESSABLE (exp)
		    || (host_integerp (TYPE_SIZE_UNIT (type), 1)
			&& (! MOVE_BY_PIECES_P
			    (tree_low_cst (TYPE_SIZE_UNIT (type), 1),
			     TYPE_ALIGN (type)))
			&& ! mostly_zeros_p (exp))))
	       || ((modifier == EXPAND_INITIALIZER
		    || modifier == EXPAND_CONST_ADDRESS)
		   && TREE_CONSTANT (exp)))
	{
	  rtx constructor = output_constant_def (exp, 1);

	  if (modifier != EXPAND_CONST_ADDRESS
	      && modifier != EXPAND_INITIALIZER
	      && modifier != EXPAND_SUM)
	    constructor = validize_mem (constructor);

	  return constructor;
	}
      else
	{
	  /* Handle calls that pass values in multiple non-contiguous
	     locations.  The Irix 6 ABI has examples of this.  */
	  if (target == 0 || ! safe_from_p (target, exp, 1)
	      || GET_CODE (target) == PARALLEL
	      || modifier == EXPAND_STACK_PARM)
	    target
	      = assign_temp (build_qualified_type (type,
						   (TYPE_QUALS (type)
						    | (TREE_READONLY (exp)
						       * TYPE_QUAL_CONST))),
			     0, TREE_ADDRESSABLE (exp), 1);

	  store_constructor (exp, target, 0, int_expr_size (exp));
	  return target;
	}

    case INDIRECT_REF:
      {
	tree exp1 = TREE_OPERAND (exp, 0);

	if (modifier != EXPAND_WRITE)
	  {
	    tree t;

	    t = fold_read_from_constant_string (exp);
	    if (t)
	      return expand_expr (t, target, tmode, modifier);
	  }

	op0 = expand_expr (exp1, NULL_RTX, VOIDmode, EXPAND_SUM);
	op0 = memory_address (mode, op0);
	temp = gen_rtx_MEM (mode, op0);
	set_mem_attributes (temp, exp, 0);

	return temp;
      }

    case ARRAY_REF:

#ifdef ENABLE_CHECKING
      if (TREE_CODE (TREE_TYPE (TREE_OPERAND (exp, 0))) != ARRAY_TYPE)
	abort ();
#endif

      {
	tree array = TREE_OPERAND (exp, 0);
	tree low_bound = array_ref_low_bound (exp);
	tree index = convert (sizetype, TREE_OPERAND (exp, 1));
	HOST_WIDE_INT i;

	/* Optimize the special-case of a zero lower bound.

	   We convert the low_bound to sizetype to avoid some problems
	   with constant folding.  (E.g. suppose the lower bound is 1,
	   and its mode is QI.  Without the conversion,  (ARRAY
	   +(INDEX-(unsigned char)1)) becomes ((ARRAY+(-(unsigned char)1))
	   +INDEX), which becomes (ARRAY+255+INDEX).  Oops!)  */

	if (! integer_zerop (low_bound))
	  index = size_diffop (index, convert (sizetype, low_bound));

	/* Fold an expression like: "foo"[2].
	   This is not done in fold so it won't happen inside &.
	   Don't fold if this is for wide characters since it's too
	   difficult to do correctly and this is a very rare case.  */

	if (modifier != EXPAND_CONST_ADDRESS
	    && modifier != EXPAND_INITIALIZER
	    && modifier != EXPAND_MEMORY)
	  {
	    tree t = fold_read_from_constant_string (exp);

	    if (t)
	      return expand_expr (t, target, tmode, modifier);
	  }

	/* If this is a constant index into a constant array,
	   just get the value from the array.  Handle both the cases when
	   we have an explicit constructor and when our operand is a variable
	   that was declared const.  */

	if (modifier != EXPAND_CONST_ADDRESS
	    && modifier != EXPAND_INITIALIZER
	    && modifier != EXPAND_MEMORY
	    && TREE_CODE (array) == CONSTRUCTOR
	    && ! TREE_SIDE_EFFECTS (array)
	    && TREE_CODE (index) == INTEGER_CST
	    && 0 > compare_tree_int (index,
				     list_length (CONSTRUCTOR_ELTS
						  (TREE_OPERAND (exp, 0)))))
	  {
	    tree elem;

	    for (elem = CONSTRUCTOR_ELTS (TREE_OPERAND (exp, 0)),
		 i = TREE_INT_CST_LOW (index);
		 elem != 0 && i != 0; i--, elem = TREE_CHAIN (elem))
	      ;

	    if (elem)
	      return expand_expr (fold (TREE_VALUE (elem)), target, tmode,
				  modifier);
	  }

	else if (optimize >= 1
		 && modifier != EXPAND_CONST_ADDRESS
		 && modifier != EXPAND_INITIALIZER
		 && modifier != EXPAND_MEMORY
		 && TREE_READONLY (array) && ! TREE_SIDE_EFFECTS (array)
		 && TREE_CODE (array) == VAR_DECL && DECL_INITIAL (array)
		 && TREE_CODE (DECL_INITIAL (array)) != ERROR_MARK
		 && targetm.binds_local_p (array))
	  {
	    if (TREE_CODE (index) == INTEGER_CST)
	      {
		tree init = DECL_INITIAL (array);

		if (TREE_CODE (init) == CONSTRUCTOR)
		  {
		    tree elem;

		    for (elem = CONSTRUCTOR_ELTS (init);
			 (elem
			  && !tree_int_cst_equal (TREE_PURPOSE (elem), index));
			 elem = TREE_CHAIN (elem))
		      ;

		    if (elem && !TREE_SIDE_EFFECTS (TREE_VALUE (elem)))
		      return expand_expr (fold (TREE_VALUE (elem)), target,
					  tmode, modifier);
		  }
		else if (TREE_CODE (init) == STRING_CST
			 && 0 > compare_tree_int (index,
						  TREE_STRING_LENGTH (init)))
		  {
		    tree type = TREE_TYPE (TREE_TYPE (init));
		    enum machine_mode mode = TYPE_MODE (type);

		    if (GET_MODE_CLASS (mode) == MODE_INT
			&& GET_MODE_SIZE (mode) == 1)
		      return gen_int_mode (TREE_STRING_POINTER (init)
					   [TREE_INT_CST_LOW (index)], mode);
		  }
	      }
	  }
      }
      goto normal_inner_ref;

    case COMPONENT_REF:
      /* If the operand is a CONSTRUCTOR, we can just extract the
	 appropriate field if it is present.  */
      if (TREE_CODE (TREE_OPERAND (exp, 0)) == CONSTRUCTOR)
	{
	  tree elt;

	  for (elt = CONSTRUCTOR_ELTS (TREE_OPERAND (exp, 0)); elt;
	       elt = TREE_CHAIN (elt))
	    if (TREE_PURPOSE (elt) == TREE_OPERAND (exp, 1)
		/* We can normally use the value of the field in the
		   CONSTRUCTOR.  However, if this is a bitfield in
		   an integral mode that we can fit in a HOST_WIDE_INT,
		   we must mask only the number of bits in the bitfield,
		   since this is done implicitly by the constructor.  If
		   the bitfield does not meet either of those conditions,
		   we can't do this optimization.  */
		&& (! DECL_BIT_FIELD (TREE_PURPOSE (elt))
		    || ((GET_MODE_CLASS (DECL_MODE (TREE_PURPOSE (elt)))
			 == MODE_INT)
			&& (GET_MODE_BITSIZE (DECL_MODE (TREE_PURPOSE (elt)))
			    <= HOST_BITS_PER_WIDE_INT))))
	      {
		if (DECL_BIT_FIELD (TREE_PURPOSE (elt))
		    && modifier == EXPAND_STACK_PARM)
		  target = 0;
		op0 = expand_expr (TREE_VALUE (elt), target, tmode, modifier);
		if (DECL_BIT_FIELD (TREE_PURPOSE (elt)))
		  {
		    HOST_WIDE_INT bitsize
		      = TREE_INT_CST_LOW (DECL_SIZE (TREE_PURPOSE (elt)));
		    enum machine_mode imode
		      = TYPE_MODE (TREE_TYPE (TREE_PURPOSE (elt)));

		    if (TYPE_UNSIGNED (TREE_TYPE (TREE_PURPOSE (elt))))
		      {
			op1 = GEN_INT (((HOST_WIDE_INT) 1 << bitsize) - 1);
			op0 = expand_and (imode, op0, op1, target);
		      }
		    else
		      {
			tree count
			  = build_int_cst (NULL_TREE,
					   GET_MODE_BITSIZE (imode) - bitsize,
					   0);

			op0 = expand_shift (LSHIFT_EXPR, imode, op0, count,
					    target, 0);
			op0 = expand_shift (RSHIFT_EXPR, imode, op0, count,
					    target, 0);
		      }
		  }

		return op0;
	      }
	}
      goto normal_inner_ref;

    case BIT_FIELD_REF:
    case ARRAY_RANGE_REF:
    normal_inner_ref:
      {
	enum machine_mode mode1;
	HOST_WIDE_INT bitsize, bitpos;
	tree offset;
	int volatilep = 0;
	tree tem = get_inner_reference (exp, &bitsize, &bitpos, &offset,
					&mode1, &unsignedp, &volatilep);
	rtx orig_op0;

	/* If we got back the original object, something is wrong.  Perhaps
	   we are evaluating an expression too early.  In any event, don't
	   infinitely recurse.  */
	if (tem == exp)
	  abort ();

	/* If TEM's type is a union of variable size, pass TARGET to the inner
	   computation, since it will need a temporary and TARGET is known
	   to have to do.  This occurs in unchecked conversion in Ada.  */

	orig_op0 = op0
	  = expand_expr (tem,
			 (TREE_CODE (TREE_TYPE (tem)) == UNION_TYPE
			  && (TREE_CODE (TYPE_SIZE (TREE_TYPE (tem)))
			      != INTEGER_CST)
			  && modifier != EXPAND_STACK_PARM
			  ? target : NULL_RTX),
			 VOIDmode,
			 (modifier == EXPAND_INITIALIZER
			  || modifier == EXPAND_CONST_ADDRESS
			  || modifier == EXPAND_STACK_PARM)
			 ? modifier : EXPAND_NORMAL);

	/* If this is a constant, put it into a register if it is a
	   legitimate constant and OFFSET is 0 and memory if it isn't.  */
	if (CONSTANT_P (op0))
	  {
	    enum machine_mode mode = TYPE_MODE (TREE_TYPE (tem));
	    if (mode != BLKmode && LEGITIMATE_CONSTANT_P (op0)
		&& offset == 0)
	      op0 = force_reg (mode, op0);
	    else
	      op0 = validize_mem (force_const_mem (mode, op0));
	  }

 	/* Otherwise, if this object not in memory and we either have an
 	   offset or a BLKmode result, put it there.  This case can't occur in
 	   C, but can in Ada if we have unchecked conversion of an expression
 	   from a scalar type to an array or record type or for an
 	   ARRAY_RANGE_REF whose type is BLKmode.  */
	else if (!MEM_P (op0)
		 && (offset != 0
		     || (code == ARRAY_RANGE_REF && mode == BLKmode)))
	  {
	    tree nt = build_qualified_type (TREE_TYPE (tem),
					    (TYPE_QUALS (TREE_TYPE (tem))
					     | TYPE_QUAL_CONST));
	    rtx memloc = assign_temp (nt, 1, 1, 1);

	    emit_move_insn (memloc, op0);
	    op0 = memloc;
	  }

	if (offset != 0)
	  {
	    rtx offset_rtx = expand_expr (offset, NULL_RTX, VOIDmode,
					  EXPAND_SUM);

	    if (!MEM_P (op0))
	      abort ();

#ifdef POINTERS_EXTEND_UNSIGNED
	    if (GET_MODE (offset_rtx) != Pmode)
	      offset_rtx = convert_to_mode (Pmode, offset_rtx, 0);
#else
	    if (GET_MODE (offset_rtx) != ptr_mode)
	      offset_rtx = convert_to_mode (ptr_mode, offset_rtx, 0);
#endif

	    if (GET_MODE (op0) == BLKmode
		/* A constant address in OP0 can have VOIDmode, we must
		   not try to call force_reg in that case.  */
		&& GET_MODE (XEXP (op0, 0)) != VOIDmode
		&& bitsize != 0
		&& (bitpos % bitsize) == 0
		&& (bitsize % GET_MODE_ALIGNMENT (mode1)) == 0
		&& MEM_ALIGN (op0) == GET_MODE_ALIGNMENT (mode1))
	      {
		op0 = adjust_address (op0, mode1, bitpos / BITS_PER_UNIT);
		bitpos = 0;
	      }

	    op0 = offset_address (op0, offset_rtx,
				  highest_pow2_factor (offset));
	  }

	/* If OFFSET is making OP0 more aligned than BIGGEST_ALIGNMENT,
	   record its alignment as BIGGEST_ALIGNMENT.  */
	if (MEM_P (op0) && bitpos == 0 && offset != 0
	    && is_aligning_offset (offset, tem))
	  set_mem_align (op0, BIGGEST_ALIGNMENT);

	/* Don't forget about volatility even if this is a bitfield.  */
	if (MEM_P (op0) && volatilep && ! MEM_VOLATILE_P (op0))
	  {
	    if (op0 == orig_op0)
	      op0 = copy_rtx (op0);

	    MEM_VOLATILE_P (op0) = 1;
	  }

	/* The following code doesn't handle CONCAT.
	   Assume only bitpos == 0 can be used for CONCAT, due to
	   one element arrays having the same mode as its element.  */
	if (GET_CODE (op0) == CONCAT)
	  {
	    if (bitpos != 0 || bitsize != GET_MODE_BITSIZE (GET_MODE (op0)))
	      abort ();
	    return op0;
	  }

	/* In cases where an aligned union has an unaligned object
	   as a field, we might be extracting a BLKmode value from
	   an integer-mode (e.g., SImode) object.  Handle this case
	   by doing the extract into an object as wide as the field
	   (which we know to be the width of a basic mode), then
	   storing into memory, and changing the mode to BLKmode.  */
	if (mode1 == VOIDmode
	    || REG_P (op0) || GET_CODE (op0) == SUBREG
	    || (mode1 != BLKmode && ! direct_load[(int) mode1]
		&& GET_MODE_CLASS (mode) != MODE_COMPLEX_INT
		&& GET_MODE_CLASS (mode) != MODE_COMPLEX_FLOAT
		&& modifier != EXPAND_CONST_ADDRESS
		&& modifier != EXPAND_INITIALIZER)
	    /* If the field isn't aligned enough to fetch as a memref,
	       fetch it as a bit field.  */
	    || (mode1 != BLKmode
		&& (((TYPE_ALIGN (TREE_TYPE (tem)) < GET_MODE_ALIGNMENT (mode)
		      || (bitpos % GET_MODE_ALIGNMENT (mode) != 0)
		      || (MEM_P (op0)
			  && (MEM_ALIGN (op0) < GET_MODE_ALIGNMENT (mode1)
			      || (bitpos % GET_MODE_ALIGNMENT (mode1) != 0))))
		     && ((modifier == EXPAND_CONST_ADDRESS
			  || modifier == EXPAND_INITIALIZER)
			 ? STRICT_ALIGNMENT
			 : SLOW_UNALIGNED_ACCESS (mode1, MEM_ALIGN (op0))))
		    || (bitpos % BITS_PER_UNIT != 0)))
	    /* If the type and the field are a constant size and the
	       size of the type isn't the same size as the bitfield,
	       we must use bitfield operations.  */
	    || (bitsize >= 0
		&& TYPE_SIZE (TREE_TYPE (exp))
		&& TREE_CODE (TYPE_SIZE (TREE_TYPE (exp))) == INTEGER_CST
		&& 0 != compare_tree_int (TYPE_SIZE (TREE_TYPE (exp)),
					  bitsize)))
	  {
	    enum machine_mode ext_mode = mode;

	    if (ext_mode == BLKmode
		&& ! (target != 0 && MEM_P (op0)
		      && MEM_P (target)
		      && bitpos % BITS_PER_UNIT == 0))
	      ext_mode = mode_for_size (bitsize, MODE_INT, 1);

	    if (ext_mode == BLKmode)
	      {
		if (target == 0)
		  target = assign_temp (type, 0, 1, 1);

		if (bitsize == 0)
		  return target;

		/* In this case, BITPOS must start at a byte boundary and
		   TARGET, if specified, must be a MEM.  */
		if (!MEM_P (op0)
		    || (target != 0 && !MEM_P (target))
		    || bitpos % BITS_PER_UNIT != 0)
		  abort ();

		emit_block_move (target,
				 adjust_address (op0, VOIDmode,
						 bitpos / BITS_PER_UNIT),
				 GEN_INT ((bitsize + BITS_PER_UNIT - 1)
					  / BITS_PER_UNIT),
				 (modifier == EXPAND_STACK_PARM
				  ? BLOCK_OP_CALL_PARM : BLOCK_OP_NORMAL));

		return target;
	      }

	    op0 = validize_mem (op0);

	    if (MEM_P (op0) && REG_P (XEXP (op0, 0)))
	      mark_reg_pointer (XEXP (op0, 0), MEM_ALIGN (op0));

	    op0 = extract_bit_field (op0, bitsize, bitpos, unsignedp,
				     (modifier == EXPAND_STACK_PARM
				      ? NULL_RTX : target),
				     ext_mode, ext_mode);

	    /* If the result is a record type and BITSIZE is narrower than
	       the mode of OP0, an integral mode, and this is a big endian
	       machine, we must put the field into the high-order bits.  */
	    if (TREE_CODE (type) == RECORD_TYPE && BYTES_BIG_ENDIAN
		&& GET_MODE_CLASS (GET_MODE (op0)) == MODE_INT
		&& bitsize < (HOST_WIDE_INT) GET_MODE_BITSIZE (GET_MODE (op0)))
	      op0 = expand_shift (LSHIFT_EXPR, GET_MODE (op0), op0,
				  size_int (GET_MODE_BITSIZE (GET_MODE (op0))
					    - bitsize),
				  op0, 1);

	    /* If the result type is BLKmode, store the data into a temporary
	       of the appropriate type, but with the mode corresponding to the
	       mode for the data we have (op0's mode).  It's tempting to make
	       this a constant type, since we know it's only being stored once,
	       but that can cause problems if we are taking the address of this
	       COMPONENT_REF because the MEM of any reference via that address
	       will have flags corresponding to the type, which will not
	       necessarily be constant.  */
	    if (mode == BLKmode)
	      {
		rtx new
		  = assign_stack_temp_for_type
		    (ext_mode, GET_MODE_BITSIZE (ext_mode), 0, type);

		emit_move_insn (new, op0);
		op0 = copy_rtx (new);
		PUT_MODE (op0, BLKmode);
		set_mem_attributes (op0, exp, 1);
	      }

	    return op0;
	  }

	/* If the result is BLKmode, use that to access the object
	   now as well.  */
	if (mode == BLKmode)
	  mode1 = BLKmode;

	/* Get a reference to just this component.  */
	if (modifier == EXPAND_CONST_ADDRESS
	    || modifier == EXPAND_SUM || modifier == EXPAND_INITIALIZER)
	  op0 = adjust_address_nv (op0, mode1, bitpos / BITS_PER_UNIT);
	else
	  op0 = adjust_address (op0, mode1, bitpos / BITS_PER_UNIT);

	if (op0 == orig_op0)
	  op0 = copy_rtx (op0);

	set_mem_attributes (op0, exp, 0);
	if (REG_P (XEXP (op0, 0)))
	  mark_reg_pointer (XEXP (op0, 0), MEM_ALIGN (op0));

	MEM_VOLATILE_P (op0) |= volatilep;
	if (mode == mode1 || mode1 == BLKmode || mode1 == tmode
	    || modifier == EXPAND_CONST_ADDRESS
	    || modifier == EXPAND_INITIALIZER)
	  return op0;
	else if (target == 0)
	  target = gen_reg_rtx (tmode != VOIDmode ? tmode : mode);

	convert_move (target, op0, unsignedp);
	return target;
      }

    case OBJ_TYPE_REF:
      return expand_expr (OBJ_TYPE_REF_EXPR (exp), target, tmode, modifier);

    case CALL_EXPR:
      /* Check for a built-in function.  */
      if (TREE_CODE (TREE_OPERAND (exp, 0)) == ADDR_EXPR
	  && (TREE_CODE (TREE_OPERAND (TREE_OPERAND (exp, 0), 0))
	      == FUNCTION_DECL)
	  && DECL_BUILT_IN (TREE_OPERAND (TREE_OPERAND (exp, 0), 0)))
	{
	  if (DECL_BUILT_IN_CLASS (TREE_OPERAND (TREE_OPERAND (exp, 0), 0))
	      == BUILT_IN_FRONTEND)
	    return lang_hooks.expand_expr (exp, original_target,
					   tmode, modifier,
					   alt_rtl);
	  else
	    return expand_builtin (exp, target, subtarget, tmode, ignore);
	}

      return expand_call (exp, target, ignore);

    case NON_LVALUE_EXPR:
    case NOP_EXPR:
    case CONVERT_EXPR:
      if (TREE_OPERAND (exp, 0) == error_mark_node)
	return const0_rtx;

      if (TREE_CODE (type) == UNION_TYPE)
	{
	  tree valtype = TREE_TYPE (TREE_OPERAND (exp, 0));

	  /* If both input and output are BLKmode, this conversion isn't doing
	     anything except possibly changing memory attribute.  */
	  if (mode == BLKmode && TYPE_MODE (valtype) == BLKmode)
	    {
	      rtx result = expand_expr (TREE_OPERAND (exp, 0), target, tmode,
					modifier);

	      result = copy_rtx (result);
	      set_mem_attributes (result, exp, 0);
	      return result;
	    }

	  if (target == 0)
	    {
	      if (TYPE_MODE (type) != BLKmode)
		target = gen_reg_rtx (TYPE_MODE (type));
	      else
		target = assign_temp (type, 0, 1, 1);
	    }

	  if (MEM_P (target))
	    /* Store data into beginning of memory target.  */
	    store_expr (TREE_OPERAND (exp, 0),
			adjust_address (target, TYPE_MODE (valtype), 0),
			modifier == EXPAND_STACK_PARM ? 2 : 0);

	  else if (REG_P (target))
	    /* Store this field into a union of the proper type.  */
	    store_field (target,
			 MIN ((int_size_in_bytes (TREE_TYPE
						  (TREE_OPERAND (exp, 0)))
			       * BITS_PER_UNIT),
			      (HOST_WIDE_INT) GET_MODE_BITSIZE (mode)),
			 0, TYPE_MODE (valtype), TREE_OPERAND (exp, 0),
			 VOIDmode, 0, type, 0);
	  else
	    abort ();

	  /* Return the entire union.  */
	  return target;
	}

      if (mode == TYPE_MODE (TREE_TYPE (TREE_OPERAND (exp, 0))))
	{
	  op0 = expand_expr (TREE_OPERAND (exp, 0), target, VOIDmode,
			     modifier);

	  /* If the signedness of the conversion differs and OP0 is
	     a promoted SUBREG, clear that indication since we now
	     have to do the proper extension.  */
	  if (TYPE_UNSIGNED (TREE_TYPE (TREE_OPERAND (exp, 0))) != unsignedp
	      && GET_CODE (op0) == SUBREG)
	    SUBREG_PROMOTED_VAR_P (op0) = 0;

	  return REDUCE_BIT_FIELD (op0);
	}

      op0 = expand_expr (TREE_OPERAND (exp, 0), NULL_RTX, mode, modifier);
      op0 = REDUCE_BIT_FIELD (op0);
      if (GET_MODE (op0) == mode)
	return op0;

      /* If OP0 is a constant, just convert it into the proper mode.  */
      if (CONSTANT_P (op0))
	{
	  tree inner_type = TREE_TYPE (TREE_OPERAND (exp, 0));
	  enum machine_mode inner_mode = TYPE_MODE (inner_type);

	  if (modifier == EXPAND_INITIALIZER)
	    return simplify_gen_subreg (mode, op0, inner_mode,
					subreg_lowpart_offset (mode,
							       inner_mode));
	  else
	    return convert_modes (mode, inner_mode, op0,
				  TYPE_UNSIGNED (inner_type));
	}

      if (modifier == EXPAND_INITIALIZER)
	return gen_rtx_fmt_e (unsignedp ? ZERO_EXTEND : SIGN_EXTEND, mode, op0);

      if (target == 0)
	return
	  convert_to_mode (mode, op0,
			   TYPE_UNSIGNED (TREE_TYPE (TREE_OPERAND (exp, 0))));
      else
	convert_move (target, op0,
		      TYPE_UNSIGNED (TREE_TYPE (TREE_OPERAND (exp, 0))));
      return target;

    case VIEW_CONVERT_EXPR:
      op0 = expand_expr (TREE_OPERAND (exp, 0), NULL_RTX, mode, modifier);

      /* If the input and output modes are both the same, we are done.
	 Otherwise, if neither mode is BLKmode and both are integral and within
	 a word, we can use gen_lowpart.  If neither is true, make sure the
	 operand is in memory and convert the MEM to the new mode.  */
      if (TYPE_MODE (type) == GET_MODE (op0))
	;
      else if (TYPE_MODE (type) != BLKmode && GET_MODE (op0) != BLKmode
	       && GET_MODE_CLASS (GET_MODE (op0)) == MODE_INT
	       && GET_MODE_CLASS (TYPE_MODE (type)) == MODE_INT
	       && GET_MODE_SIZE (TYPE_MODE (type)) <= UNITS_PER_WORD
	       && GET_MODE_SIZE (GET_MODE (op0)) <= UNITS_PER_WORD)
	op0 = gen_lowpart (TYPE_MODE (type), op0);
      else if (!MEM_P (op0))
	{
	  /* If the operand is not a MEM, force it into memory.  Since we
	     are going to be be changing the mode of the MEM, don't call
	     force_const_mem for constants because we don't allow pool
	     constants to change mode.  */
	  tree inner_type = TREE_TYPE (TREE_OPERAND (exp, 0));

	  if (TREE_ADDRESSABLE (exp))
	    abort ();

	  if (target == 0 || GET_MODE (target) != TYPE_MODE (inner_type))
	    target
	      = assign_stack_temp_for_type
		(TYPE_MODE (inner_type),
		 GET_MODE_SIZE (TYPE_MODE (inner_type)), 0, inner_type);

	  emit_move_insn (target, op0);
	  op0 = target;
	}

      /* At this point, OP0 is in the correct mode.  If the output type is such
	 that the operand is known to be aligned, indicate that it is.
	 Otherwise, we need only be concerned about alignment for non-BLKmode
	 results.  */
      if (MEM_P (op0))
	{
	  op0 = copy_rtx (op0);

	  if (TYPE_ALIGN_OK (type))
	    set_mem_align (op0, MAX (MEM_ALIGN (op0), TYPE_ALIGN (type)));
	  else if (TYPE_MODE (type) != BLKmode && STRICT_ALIGNMENT
		   && MEM_ALIGN (op0) < GET_MODE_ALIGNMENT (TYPE_MODE (type)))
	    {
	      tree inner_type = TREE_TYPE (TREE_OPERAND (exp, 0));
	      HOST_WIDE_INT temp_size
		= MAX (int_size_in_bytes (inner_type),
		       (HOST_WIDE_INT) GET_MODE_SIZE (TYPE_MODE (type)));
	      rtx new = assign_stack_temp_for_type (TYPE_MODE (type),
						    temp_size, 0, type);
	      rtx new_with_op0_mode = adjust_address (new, GET_MODE (op0), 0);

	      if (TREE_ADDRESSABLE (exp))
		abort ();

	      if (GET_MODE (op0) == BLKmode)
		emit_block_move (new_with_op0_mode, op0,
				 GEN_INT (GET_MODE_SIZE (TYPE_MODE (type))),
				 (modifier == EXPAND_STACK_PARM
				  ? BLOCK_OP_CALL_PARM : BLOCK_OP_NORMAL));
	      else
		emit_move_insn (new_with_op0_mode, op0);

	      op0 = new;
	    }

	  op0 = adjust_address (op0, TYPE_MODE (type), 0);
	}

      return op0;

    case PLUS_EXPR:
      /* If we are adding a constant, a VAR_DECL that is sp, fp, or ap, and
	 something else, make sure we add the register to the constant and
	 then to the other thing.  This case can occur during strength
	 reduction and doing it this way will produce better code if the
	 frame pointer or argument pointer is eliminated.

	 fold-const.c will ensure that the constant is always in the inner
	 PLUS_EXPR, so the only case we need to do anything about is if
	 sp, ap, or fp is our second argument, in which case we must swap
	 the innermost first argument and our second argument.  */

      if (TREE_CODE (TREE_OPERAND (exp, 0)) == PLUS_EXPR
	  && TREE_CODE (TREE_OPERAND (TREE_OPERAND (exp, 0), 1)) == INTEGER_CST
	  && TREE_CODE (TREE_OPERAND (exp, 1)) == VAR_DECL
	  && (DECL_RTL (TREE_OPERAND (exp, 1)) == frame_pointer_rtx
	      || DECL_RTL (TREE_OPERAND (exp, 1)) == stack_pointer_rtx
	      || DECL_RTL (TREE_OPERAND (exp, 1)) == arg_pointer_rtx))
	{
	  tree t = TREE_OPERAND (exp, 1);

	  TREE_OPERAND (exp, 1) = TREE_OPERAND (TREE_OPERAND (exp, 0), 0);
	  TREE_OPERAND (TREE_OPERAND (exp, 0), 0) = t;
	}

      /* If the result is to be ptr_mode and we are adding an integer to
	 something, we might be forming a constant.  So try to use
	 plus_constant.  If it produces a sum and we can't accept it,
	 use force_operand.  This allows P = &ARR[const] to generate
	 efficient code on machines where a SYMBOL_REF is not a valid
	 address.

	 If this is an EXPAND_SUM call, always return the sum.  */
      if (modifier == EXPAND_SUM || modifier == EXPAND_INITIALIZER
	  || (mode == ptr_mode && (unsignedp || ! flag_trapv)))
	{
	  if (modifier == EXPAND_STACK_PARM)
	    target = 0;
	  if (TREE_CODE (TREE_OPERAND (exp, 0)) == INTEGER_CST
	      && GET_MODE_BITSIZE (mode) <= HOST_BITS_PER_WIDE_INT
	      && TREE_CONSTANT (TREE_OPERAND (exp, 1)))
	    {
	      rtx constant_part;

	      op1 = expand_expr (TREE_OPERAND (exp, 1), subtarget, VOIDmode,
				 EXPAND_SUM);
	      /* Use immed_double_const to ensure that the constant is
		 truncated according to the mode of OP1, then sign extended
		 to a HOST_WIDE_INT.  Using the constant directly can result
		 in non-canonical RTL in a 64x32 cross compile.  */
	      constant_part
		= immed_double_const (TREE_INT_CST_LOW (TREE_OPERAND (exp, 0)),
				      (HOST_WIDE_INT) 0,
				      TYPE_MODE (TREE_TYPE (TREE_OPERAND (exp, 1))));
	      op1 = plus_constant (op1, INTVAL (constant_part));
	      if (modifier != EXPAND_SUM && modifier != EXPAND_INITIALIZER)
		op1 = force_operand (op1, target);
	      return REDUCE_BIT_FIELD (op1);
	    }

	  else if (TREE_CODE (TREE_OPERAND (exp, 1)) == INTEGER_CST
		   && GET_MODE_BITSIZE (mode) <= HOST_BITS_PER_INT
		   && TREE_CONSTANT (TREE_OPERAND (exp, 0)))
	    {
	      rtx constant_part;

	      op0 = expand_expr (TREE_OPERAND (exp, 0), subtarget, VOIDmode,
				 (modifier == EXPAND_INITIALIZER
				 ? EXPAND_INITIALIZER : EXPAND_SUM));
	      if (! CONSTANT_P (op0))
		{
		  op1 = expand_expr (TREE_OPERAND (exp, 1), NULL_RTX,
				     VOIDmode, modifier);
		  /* Return a PLUS if modifier says it's OK.  */
		  if (modifier == EXPAND_SUM
		      || modifier == EXPAND_INITIALIZER)
		    return simplify_gen_binary (PLUS, mode, op0, op1);
		  goto binop2;
		}
	      /* Use immed_double_const to ensure that the constant is
		 truncated according to the mode of OP1, then sign extended
		 to a HOST_WIDE_INT.  Using the constant directly can result
		 in non-canonical RTL in a 64x32 cross compile.  */
	      constant_part
		= immed_double_const (TREE_INT_CST_LOW (TREE_OPERAND (exp, 1)),
				      (HOST_WIDE_INT) 0,
				      TYPE_MODE (TREE_TYPE (TREE_OPERAND (exp, 0))));
	      op0 = plus_constant (op0, INTVAL (constant_part));
	      if (modifier != EXPAND_SUM && modifier != EXPAND_INITIALIZER)
		op0 = force_operand (op0, target);
	      return REDUCE_BIT_FIELD (op0);
	    }
	}

      /* No sense saving up arithmetic to be done
	 if it's all in the wrong mode to form part of an address.
	 And force_operand won't know whether to sign-extend or
	 zero-extend.  */
      if ((modifier != EXPAND_SUM && modifier != EXPAND_INITIALIZER)
	  || mode != ptr_mode)
	{
	  expand_operands (TREE_OPERAND (exp, 0), TREE_OPERAND (exp, 1),
			   subtarget, &op0, &op1, 0);
	  if (op0 == const0_rtx)
	    return op1;
	  if (op1 == const0_rtx)
	    return op0;
	  goto binop2;
	}

      expand_operands (TREE_OPERAND (exp, 0), TREE_OPERAND (exp, 1),
		       subtarget, &op0, &op1, modifier);
      return REDUCE_BIT_FIELD (simplify_gen_binary (PLUS, mode, op0, op1));

    case MINUS_EXPR:
      /* For initializers, we are allowed to return a MINUS of two
	 symbolic constants.  Here we handle all cases when both operands
	 are constant.  */
      /* Handle difference of two symbolic constants,
	 for the sake of an initializer.  */
      if ((modifier == EXPAND_SUM || modifier == EXPAND_INITIALIZER)
	  && really_constant_p (TREE_OPERAND (exp, 0))
	  && really_constant_p (TREE_OPERAND (exp, 1)))
	{
	  expand_operands (TREE_OPERAND (exp, 0), TREE_OPERAND (exp, 1),
			   NULL_RTX, &op0, &op1, modifier);

	  /* If the last operand is a CONST_INT, use plus_constant of
	     the negated constant.  Else make the MINUS.  */
	  if (GET_CODE (op1) == CONST_INT)
	    return REDUCE_BIT_FIELD (plus_constant (op0, - INTVAL (op1)));
	  else
	    return REDUCE_BIT_FIELD (gen_rtx_MINUS (mode, op0, op1));
	}

      /* No sense saving up arithmetic to be done
	 if it's all in the wrong mode to form part of an address.
	 And force_operand won't know whether to sign-extend or
	 zero-extend.  */
      if ((modifier != EXPAND_SUM && modifier != EXPAND_INITIALIZER)
	  || mode != ptr_mode)
	goto binop;

      expand_operands (TREE_OPERAND (exp, 0), TREE_OPERAND (exp, 1),
		       subtarget, &op0, &op1, modifier);

      /* Convert A - const to A + (-const).  */
      if (GET_CODE (op1) == CONST_INT)
	{
	  op1 = negate_rtx (mode, op1);
	  return REDUCE_BIT_FIELD (simplify_gen_binary (PLUS, mode, op0, op1));
	}

      goto binop2;

    case MULT_EXPR:
      /* If first operand is constant, swap them.
	 Thus the following special case checks need only
	 check the second operand.  */
      if (TREE_CODE (TREE_OPERAND (exp, 0)) == INTEGER_CST)
	{
	  tree t1 = TREE_OPERAND (exp, 0);
	  TREE_OPERAND (exp, 0) = TREE_OPERAND (exp, 1);
	  TREE_OPERAND (exp, 1) = t1;
	}

      /* Attempt to return something suitable for generating an
	 indexed address, for machines that support that.  */

      if (modifier == EXPAND_SUM && mode == ptr_mode
	  && host_integerp (TREE_OPERAND (exp, 1), 0))
	{
	  tree exp1 = TREE_OPERAND (exp, 1);

	  op0 = expand_expr (TREE_OPERAND (exp, 0), subtarget, VOIDmode,
			     EXPAND_SUM);

	  if (!REG_P (op0))
	    op0 = force_operand (op0, NULL_RTX);
	  if (!REG_P (op0))
	    op0 = copy_to_mode_reg (mode, op0);

	  return REDUCE_BIT_FIELD (gen_rtx_MULT (mode, op0,
			       gen_int_mode (tree_low_cst (exp1, 0),
					     TYPE_MODE (TREE_TYPE (exp1)))));
	}

      if (modifier == EXPAND_STACK_PARM)
	target = 0;

      /* Check for multiplying things that have been extended
	 from a narrower type.  If this machine supports multiplying
	 in that narrower type with a result in the desired type,
	 do it that way, and avoid the explicit type-conversion.  */
      if (TREE_CODE (TREE_OPERAND (exp, 0)) == NOP_EXPR
	  && TREE_CODE (type) == INTEGER_TYPE
	  && (TYPE_PRECISION (TREE_TYPE (TREE_OPERAND (TREE_OPERAND (exp, 0), 0)))
	      < TYPE_PRECISION (TREE_TYPE (TREE_OPERAND (exp, 0))))
	  && ((TREE_CODE (TREE_OPERAND (exp, 1)) == INTEGER_CST
	       && int_fits_type_p (TREE_OPERAND (exp, 1),
				   TREE_TYPE (TREE_OPERAND (TREE_OPERAND (exp, 0), 0)))
	       /* Don't use a widening multiply if a shift will do.  */
	       && ((GET_MODE_BITSIZE (TYPE_MODE (TREE_TYPE (TREE_OPERAND (exp, 1))))
		    > HOST_BITS_PER_WIDE_INT)
		   || exact_log2 (TREE_INT_CST_LOW (TREE_OPERAND (exp, 1))) < 0))
	      ||
	      (TREE_CODE (TREE_OPERAND (exp, 1)) == NOP_EXPR
	       && (TYPE_PRECISION (TREE_TYPE
				   (TREE_OPERAND (TREE_OPERAND (exp, 1), 0)))
		   == TYPE_PRECISION (TREE_TYPE
				      (TREE_OPERAND
				       (TREE_OPERAND (exp, 0), 0))))
	       /* If both operands are extended, they must either both
		  be zero-extended or both be sign-extended.  */
	       && (TYPE_UNSIGNED (TREE_TYPE
				  (TREE_OPERAND (TREE_OPERAND (exp, 1), 0)))
		   == TYPE_UNSIGNED (TREE_TYPE
				     (TREE_OPERAND
				      (TREE_OPERAND (exp, 0), 0)))))))
	{
	  tree op0type = TREE_TYPE (TREE_OPERAND (TREE_OPERAND (exp, 0), 0));
	  enum machine_mode innermode = TYPE_MODE (op0type);
	  bool zextend_p = TYPE_UNSIGNED (op0type);
	  optab other_optab = zextend_p ? smul_widen_optab : umul_widen_optab;
	  this_optab = zextend_p ? umul_widen_optab : smul_widen_optab;

	  if (mode == GET_MODE_WIDER_MODE (innermode))
	    {
	      if (this_optab->handlers[(int) mode].insn_code != CODE_FOR_nothing)
		{
		  if (TREE_CODE (TREE_OPERAND (exp, 1)) == INTEGER_CST)
		    expand_operands (TREE_OPERAND (TREE_OPERAND (exp, 0), 0),
				     TREE_OPERAND (exp, 1),
				     NULL_RTX, &op0, &op1, 0);
		  else
		    expand_operands (TREE_OPERAND (TREE_OPERAND (exp, 0), 0),
				     TREE_OPERAND (TREE_OPERAND (exp, 1), 0),
				     NULL_RTX, &op0, &op1, 0);
		  goto binop3;
		}
	      else if (other_optab->handlers[(int) mode].insn_code != CODE_FOR_nothing
		       && innermode == word_mode)
		{
		  rtx htem, hipart;
		  op0 = expand_expr (TREE_OPERAND (TREE_OPERAND (exp, 0), 0),
				     NULL_RTX, VOIDmode, 0);
		  if (TREE_CODE (TREE_OPERAND (exp, 1)) == INTEGER_CST)
		    op1 = convert_modes (innermode, mode,
					 expand_expr (TREE_OPERAND (exp, 1),
						      NULL_RTX, VOIDmode, 0),
					 unsignedp);
		  else
		    op1 = expand_expr (TREE_OPERAND (TREE_OPERAND (exp, 1), 0),
				       NULL_RTX, VOIDmode, 0);
		  temp = expand_binop (mode, other_optab, op0, op1, target,
				       unsignedp, OPTAB_LIB_WIDEN);
		  hipart = gen_highpart (innermode, temp);
		  htem = expand_mult_highpart_adjust (innermode, hipart,
						      op0, op1, hipart,
						      zextend_p);
		  if (htem != hipart)
		    emit_move_insn (hipart, htem);
		  return REDUCE_BIT_FIELD (temp);
		}
	    }
	}
      expand_operands (TREE_OPERAND (exp, 0), TREE_OPERAND (exp, 1),
		       subtarget, &op0, &op1, 0);
      return REDUCE_BIT_FIELD (expand_mult (mode, op0, op1, target, unsignedp));

    case TRUNC_DIV_EXPR:
    case FLOOR_DIV_EXPR:
    case CEIL_DIV_EXPR:
    case ROUND_DIV_EXPR:
    case EXACT_DIV_EXPR:
      if (modifier == EXPAND_STACK_PARM)
	target = 0;
      /* Possible optimization: compute the dividend with EXPAND_SUM
	 then if the divisor is constant can optimize the case
	 where some terms of the dividend have coeffs divisible by it.  */
      expand_operands (TREE_OPERAND (exp, 0), TREE_OPERAND (exp, 1),
		       subtarget, &op0, &op1, 0);
      return expand_divmod (0, code, mode, op0, op1, target, unsignedp);

    case RDIV_EXPR:
      /* Emit a/b as a*(1/b).  Later we may manage CSE the reciprocal saving
         expensive divide.  If not, combine will rebuild the original
         computation.  */
      if (flag_unsafe_math_optimizations && optimize && !optimize_size
	  && TREE_CODE (type) == REAL_TYPE
	  && !real_onep (TREE_OPERAND (exp, 0)))
        return expand_expr (build2 (MULT_EXPR, type, TREE_OPERAND (exp, 0),
				    build2 (RDIV_EXPR, type,
					    build_real (type, dconst1),
					    TREE_OPERAND (exp, 1))),
			    target, tmode, modifier);

      goto binop;

    case TRUNC_MOD_EXPR:
    case FLOOR_MOD_EXPR:
    case CEIL_MOD_EXPR:
    case ROUND_MOD_EXPR:
      if (modifier == EXPAND_STACK_PARM)
	target = 0;
      expand_operands (TREE_OPERAND (exp, 0), TREE_OPERAND (exp, 1),
		       subtarget, &op0, &op1, 0);
      return expand_divmod (1, code, mode, op0, op1, target, unsignedp);

    case FIX_ROUND_EXPR:
    case FIX_FLOOR_EXPR:
    case FIX_CEIL_EXPR:
      abort ();			/* Not used for C.  */

    case FIX_TRUNC_EXPR:
      op0 = expand_expr (TREE_OPERAND (exp, 0), NULL_RTX, VOIDmode, 0);
      if (target == 0 || modifier == EXPAND_STACK_PARM)
	target = gen_reg_rtx (mode);
      expand_fix (target, op0, unsignedp);
      return target;

    case FLOAT_EXPR:
      op0 = expand_expr (TREE_OPERAND (exp, 0), NULL_RTX, VOIDmode, 0);
      if (target == 0 || modifier == EXPAND_STACK_PARM)
	target = gen_reg_rtx (mode);
      /* expand_float can't figure out what to do if FROM has VOIDmode.
	 So give it the correct mode.  With -O, cse will optimize this.  */
      if (GET_MODE (op0) == VOIDmode)
	op0 = copy_to_mode_reg (TYPE_MODE (TREE_TYPE (TREE_OPERAND (exp, 0))),
				op0);
      expand_float (target, op0,
		    TYPE_UNSIGNED (TREE_TYPE (TREE_OPERAND (exp, 0))));
      return target;

    case NEGATE_EXPR:
      op0 = expand_expr (TREE_OPERAND (exp, 0), subtarget, VOIDmode, 0);
      if (modifier == EXPAND_STACK_PARM)
	target = 0;
      temp = expand_unop (mode,
      			  optab_for_tree_code (NEGATE_EXPR, type),
			  op0, target, 0);
      if (temp == 0)
	abort ();
      return REDUCE_BIT_FIELD (temp);

    case ABS_EXPR:
      op0 = expand_expr (TREE_OPERAND (exp, 0), subtarget, VOIDmode, 0);
      if (modifier == EXPAND_STACK_PARM)
	target = 0;

      /* ABS_EXPR is not valid for complex arguments.  */
      if (GET_MODE_CLASS (mode) == MODE_COMPLEX_INT
	  || GET_MODE_CLASS (mode) == MODE_COMPLEX_FLOAT)
	abort ();

      /* Unsigned abs is simply the operand.  Testing here means we don't
	 risk generating incorrect code below.  */
      if (TYPE_UNSIGNED (type))
	return op0;

      return expand_abs (mode, op0, target, unsignedp,
			 safe_from_p (target, TREE_OPERAND (exp, 0), 1));

    case MAX_EXPR:
    case MIN_EXPR:
      target = original_target;
      if (target == 0
	  || modifier == EXPAND_STACK_PARM
	  || (MEM_P (target) && MEM_VOLATILE_P (target))
	  || GET_MODE (target) != mode
	  || (REG_P (target)
	      && REGNO (target) < FIRST_PSEUDO_REGISTER))
	target = gen_reg_rtx (mode);
      expand_operands (TREE_OPERAND (exp, 0), TREE_OPERAND (exp, 1),
		       target, &op0, &op1, 0);

      /* First try to do it with a special MIN or MAX instruction.
	 If that does not win, use a conditional jump to select the proper
	 value.  */
      this_optab = optab_for_tree_code (code, type);
      temp = expand_binop (mode, this_optab, op0, op1, target, unsignedp,
			   OPTAB_WIDEN);
      if (temp != 0)
	return temp;

      /* At this point, a MEM target is no longer useful; we will get better
	 code without it.  */

      if (MEM_P (target))
	target = gen_reg_rtx (mode);

      /* If op1 was placed in target, swap op0 and op1.  */
      if (target != op0 && target == op1)
	{
	  rtx tem = op0;
	  op0 = op1;
	  op1 = tem;
	}

      if (target != op0)
	emit_move_insn (target, op0);

      op0 = gen_label_rtx ();

      /* If this mode is an integer too wide to compare properly,
	 compare word by word.  Rely on cse to optimize constant cases.  */
      if (GET_MODE_CLASS (mode) == MODE_INT
	  && ! can_compare_p (GE, mode, ccp_jump))
	{
	  if (code == MAX_EXPR)
	    do_jump_by_parts_greater_rtx (mode, unsignedp, target, op1,
					  NULL_RTX, op0);
	  else
	    do_jump_by_parts_greater_rtx (mode, unsignedp, op1, target,
					  NULL_RTX, op0);
	}
      else
	{
	  do_compare_rtx_and_jump (target, op1, code == MAX_EXPR ? GE : LE,
				   unsignedp, mode, NULL_RTX, NULL_RTX, op0);
	}
      emit_move_insn (target, op1);
      emit_label (op0);
      return target;

    case BIT_NOT_EXPR:
      op0 = expand_expr (TREE_OPERAND (exp, 0), subtarget, VOIDmode, 0);
      if (modifier == EXPAND_STACK_PARM)
	target = 0;
      temp = expand_unop (mode, one_cmpl_optab, op0, target, 1);
      if (temp == 0)
	abort ();
      return temp;

      /* ??? Can optimize bitwise operations with one arg constant.
	 Can optimize (a bitwise1 n) bitwise2 (a bitwise3 b)
	 and (a bitwise1 b) bitwise2 b (etc)
	 but that is probably not worth while.  */

      /* BIT_AND_EXPR is for bitwise anding.  TRUTH_AND_EXPR is for anding two
	 boolean values when we want in all cases to compute both of them.  In
	 general it is fastest to do TRUTH_AND_EXPR by computing both operands
	 as actual zero-or-1 values and then bitwise anding.  In cases where
	 there cannot be any side effects, better code would be made by
	 treating TRUTH_AND_EXPR like TRUTH_ANDIF_EXPR; but the question is
	 how to recognize those cases.  */

    case TRUTH_AND_EXPR:
      code = BIT_AND_EXPR;
    case BIT_AND_EXPR:
      goto binop;

    case TRUTH_OR_EXPR:
      code = BIT_IOR_EXPR;
    case BIT_IOR_EXPR:
      goto binop;

    case TRUTH_XOR_EXPR:
      code = BIT_XOR_EXPR;
    case BIT_XOR_EXPR:
      goto binop;

    case LSHIFT_EXPR:
    case RSHIFT_EXPR:
    case LROTATE_EXPR:
    case RROTATE_EXPR:
      if (! safe_from_p (subtarget, TREE_OPERAND (exp, 1), 1))
	subtarget = 0;
      if (modifier == EXPAND_STACK_PARM)
	target = 0;
      op0 = expand_expr (TREE_OPERAND (exp, 0), subtarget, VOIDmode, 0);
      return expand_shift (code, mode, op0, TREE_OPERAND (exp, 1), target,
			   unsignedp);

      /* Could determine the answer when only additive constants differ.  Also,
	 the addition of one can be handled by changing the condition.  */
    case LT_EXPR:
    case LE_EXPR:
    case GT_EXPR:
    case GE_EXPR:
    case EQ_EXPR:
    case NE_EXPR:
    case UNORDERED_EXPR:
    case ORDERED_EXPR:
    case UNLT_EXPR:
    case UNLE_EXPR:
    case UNGT_EXPR:
    case UNGE_EXPR:
    case UNEQ_EXPR:
    case LTGT_EXPR:
      temp = do_store_flag (exp,
			    modifier != EXPAND_STACK_PARM ? target : NULL_RTX,
			    tmode != VOIDmode ? tmode : mode, 0);
      if (temp != 0)
	return temp;

      /* For foo != 0, load foo, and if it is nonzero load 1 instead.  */
      if (code == NE_EXPR && integer_zerop (TREE_OPERAND (exp, 1))
	  && original_target
	  && REG_P (original_target)
	  && (GET_MODE (original_target)
	      == TYPE_MODE (TREE_TYPE (TREE_OPERAND (exp, 0)))))
	{
	  temp = expand_expr (TREE_OPERAND (exp, 0), original_target,
			      VOIDmode, 0);

	  /* If temp is constant, we can just compute the result.  */
	  if (GET_CODE (temp) == CONST_INT)
	    {
	      if (INTVAL (temp) != 0)
	        emit_move_insn (target, const1_rtx);
	      else
	        emit_move_insn (target, const0_rtx);

	      return target;
	    }

	  if (temp != original_target)
	    {
	      enum machine_mode mode1 = GET_MODE (temp);
	      if (mode1 == VOIDmode)
		mode1 = tmode != VOIDmode ? tmode : mode;

	      temp = copy_to_mode_reg (mode1, temp);
	    }

	  op1 = gen_label_rtx ();
	  emit_cmp_and_jump_insns (temp, const0_rtx, EQ, NULL_RTX,
				   GET_MODE (temp), unsignedp, op1);
	  emit_move_insn (temp, const1_rtx);
	  emit_label (op1);
	  return temp;
	}

      /* If no set-flag instruction, must generate a conditional store
	 into a temporary variable.  Drop through and handle this
	 like && and ||.  */

      if (! ignore
	  && (target == 0
	      || modifier == EXPAND_STACK_PARM
	      || ! safe_from_p (target, exp, 1)
	      /* Make sure we don't have a hard reg (such as function's return
		 value) live across basic blocks, if not optimizing.  */
	      || (!optimize && REG_P (target)
		  && REGNO (target) < FIRST_PSEUDO_REGISTER)))
	target = gen_reg_rtx (tmode != VOIDmode ? tmode : mode);

      if (target)
	emit_move_insn (target, const0_rtx);

      op1 = gen_label_rtx ();
      jumpifnot (exp, op1);

      if (target)
	emit_move_insn (target, const1_rtx);

      emit_label (op1);
      return ignore ? const0_rtx : target;

    case TRUTH_NOT_EXPR:
      if (modifier == EXPAND_STACK_PARM)
	target = 0;
      op0 = expand_expr (TREE_OPERAND (exp, 0), target, VOIDmode, 0);
      /* The parser is careful to generate TRUTH_NOT_EXPR
	 only with operands that are always zero or one.  */
      temp = expand_binop (mode, xor_optab, op0, const1_rtx,
			   target, 1, OPTAB_LIB_WIDEN);
      if (temp == 0)
	abort ();
      return temp;

    case STATEMENT_LIST:
      {
	tree_stmt_iterator iter;

	if (!ignore)
	  abort ();

	for (iter = tsi_start (exp); !tsi_end_p (iter); tsi_next (&iter))
	  expand_expr (tsi_stmt (iter), const0_rtx, VOIDmode, modifier);
      }
      return const0_rtx;

    case COND_EXPR:
      /* If it's void, we don't need to worry about computing a value.  */
      if (VOID_TYPE_P (TREE_TYPE (exp)))
	{
	  tree pred = TREE_OPERAND (exp, 0);
  	  tree then_ = TREE_OPERAND (exp, 1);
  	  tree else_ = TREE_OPERAND (exp, 2);
  
	  if (TREE_CODE (then_) != GOTO_EXPR
	      || TREE_CODE (GOTO_DESTINATION (then_)) != LABEL_DECL
	      || TREE_CODE (else_) != GOTO_EXPR
	      || TREE_CODE (GOTO_DESTINATION (else_)) != LABEL_DECL)
	    abort ();
  
	  jumpif (pred, label_rtx (GOTO_DESTINATION (then_)));
	  return expand_expr (else_, const0_rtx, VOIDmode, 0);
  	}
  
        /* Note that COND_EXPRs whose type is a structure or union
  	 are required to be constructed to contain assignments of
  	 a temporary variable, so that we can evaluate them here
  	 for side effect only.  If type is void, we must do likewise.  */

        if (TREE_ADDRESSABLE (type)
 	  || ignore
 	  || TREE_TYPE (TREE_OPERAND (exp, 1)) == void_type_node
 	  || TREE_TYPE (TREE_OPERAND (exp, 2)) == void_type_node)
 	abort ();
       
       /* If we are not to produce a result, we have no target.  Otherwise,
 	 if a target was specified use it; it will not be used as an
 	 intermediate target unless it is safe.  If no target, use a
 	 temporary.  */
       
       if (modifier != EXPAND_STACK_PARM
 	  && original_target
 	  && safe_from_p (original_target, TREE_OPERAND (exp, 0), 1)
 	  && GET_MODE (original_target) == mode
#ifdef HAVE_conditional_move
 	  && (! can_conditionally_move_p (mode)
 	      || REG_P (original_target))
#endif
 	  && !MEM_P (original_target))
 	temp = original_target;
       else
 	temp = assign_temp (type, 0, 0, 1);
       
       do_pending_stack_adjust ();
       NO_DEFER_POP;
       op0 = gen_label_rtx ();
       op1 = gen_label_rtx ();
       jumpifnot (TREE_OPERAND (exp, 0), op0);
       store_expr (TREE_OPERAND (exp, 1), temp,
 		  modifier == EXPAND_STACK_PARM ? 2 : 0);
       
       emit_jump_insn (gen_jump (op1));
       emit_barrier ();
       emit_label (op0);
       store_expr (TREE_OPERAND (exp, 2), temp,
 		  modifier == EXPAND_STACK_PARM ? 2 : 0);
       
       emit_label (op1);
       OK_DEFER_POP;
       return temp;
  
    case MODIFY_EXPR:
      {
	/* If lhs is complex, expand calls in rhs before computing it.
	   That's so we don't compute a pointer and save it over a
	   call.  If lhs is simple, compute it first so we can give it
	   as a target if the rhs is just a call.  This avoids an
	   extra temp and copy and that prevents a partial-subsumption
	   which makes bad code.  Actually we could treat
	   component_ref's of vars like vars.  */

	tree lhs = TREE_OPERAND (exp, 0);
	tree rhs = TREE_OPERAND (exp, 1);

	temp = 0;

	/* Check for |= or &= of a bitfield of size one into another bitfield
	   of size 1.  In this case, (unless we need the result of the
	   assignment) we can do this more efficiently with a
	   test followed by an assignment, if necessary.

	   ??? At this point, we can't get a BIT_FIELD_REF here.  But if
	   things change so we do, this code should be enhanced to
	   support it.  */
	if (ignore
	    && TREE_CODE (lhs) == COMPONENT_REF
	    && (TREE_CODE (rhs) == BIT_IOR_EXPR
		|| TREE_CODE (rhs) == BIT_AND_EXPR)
	    && TREE_OPERAND (rhs, 0) == lhs
	    && TREE_CODE (TREE_OPERAND (rhs, 1)) == COMPONENT_REF
	    && integer_onep (DECL_SIZE (TREE_OPERAND (lhs, 1)))
	    && integer_onep (DECL_SIZE (TREE_OPERAND (TREE_OPERAND (rhs, 1), 1))))
	  {
	    rtx label = gen_label_rtx ();

	    do_jump (TREE_OPERAND (rhs, 1),
		     TREE_CODE (rhs) == BIT_IOR_EXPR ? label : 0,
		     TREE_CODE (rhs) == BIT_AND_EXPR ? label : 0);
	    expand_assignment (lhs, convert (TREE_TYPE (rhs),
					     (TREE_CODE (rhs) == BIT_IOR_EXPR
					      ? integer_one_node
					      : integer_zero_node)),
			       0);
	    do_pending_stack_adjust ();
	    emit_label (label);
	    return const0_rtx;
	  }

	temp = expand_assignment (lhs, rhs, ! ignore);

	return temp;
      }

    case RETURN_EXPR:
      if (!TREE_OPERAND (exp, 0))
	expand_null_return ();
      else
	expand_return (TREE_OPERAND (exp, 0));
      return const0_rtx;

    case ADDR_EXPR:
      if (modifier == EXPAND_STACK_PARM)
	target = 0;
      /* If we are taking the address of something erroneous, just
	 return a zero.  */
      if (TREE_CODE (TREE_OPERAND (exp, 0)) == ERROR_MARK)
	return const0_rtx;
      /* If we are taking the address of a constant and are at the
	 top level, we have to use output_constant_def since we can't
	 call force_const_mem at top level.  */
      else if (cfun == 0
	       && (TREE_CODE (TREE_OPERAND (exp, 0)) == CONSTRUCTOR
		   || (TREE_CODE_CLASS (TREE_CODE (TREE_OPERAND (exp, 0)))
		       == 'c')))
	op0 = XEXP (output_constant_def (TREE_OPERAND (exp, 0), 0), 0);
      else
	{
	  /* We make sure to pass const0_rtx down if we came in with
	     ignore set, to avoid doing the cleanups twice for something.  */
	  op0 = expand_expr (TREE_OPERAND (exp, 0),
			     ignore ? const0_rtx : NULL_RTX, VOIDmode,
			     (modifier == EXPAND_INITIALIZER
			      ? modifier : EXPAND_CONST_ADDRESS));

	  /* If we are going to ignore the result, OP0 will have been set
	     to const0_rtx, so just return it.  Don't get confused and
	     think we are taking the address of the constant.  */
	  if (ignore)
	    return op0;

	  /* We would like the object in memory.  If it is a constant, we can
	     have it be statically allocated into memory.  For a non-constant,
	     we need to allocate some memory and store the value into it.  */

	  if (CONSTANT_P (op0))
	    op0 = force_const_mem (TYPE_MODE (TREE_TYPE (TREE_OPERAND (exp, 0))),
				   op0);
	  else if (REG_P (op0) || GET_CODE (op0) == SUBREG
		   || GET_CODE (op0) == CONCAT || GET_CODE (op0) == PARALLEL
		   || GET_CODE (op0) == LO_SUM)
	    {
	      /* If this object is in a register, it can't be BLKmode.  */
	      tree inner_type = TREE_TYPE (TREE_OPERAND (exp, 0));
	      rtx memloc = assign_temp (inner_type, 1, 1, 1);

	      if (GET_CODE (op0) == PARALLEL)
	        /* Handle calls that pass values in multiple
		   non-contiguous locations.  The Irix 6 ABI has examples
		   of this.  */
		emit_group_store (memloc, op0, inner_type,
				  int_size_in_bytes (inner_type));
	      else
		emit_move_insn (memloc, op0);

	      op0 = memloc;
	    }

	  if (!MEM_P (op0))
	    abort ();

	  mark_temp_addr_taken (op0);
	  if (modifier == EXPAND_SUM || modifier == EXPAND_INITIALIZER)
	    {
	      op0 = XEXP (op0, 0);
	      if (GET_MODE (op0) == Pmode && mode == ptr_mode)
		op0 = convert_memory_address (ptr_mode, op0);
	      return op0;
	    }

	  /* If OP0 is not aligned as least as much as the type requires, we
	     need to make a temporary, copy OP0 to it, and take the address of
	     the temporary.  We want to use the alignment of the type, not of
	     the operand.  Note that this is incorrect for FUNCTION_TYPE, but
	     the test for BLKmode means that can't happen.  The test for
	     BLKmode is because we never make mis-aligned MEMs with
	     non-BLKmode.

	     We don't need to do this at all if the machine doesn't have
	     strict alignment.  */
	  if (STRICT_ALIGNMENT && GET_MODE (op0) == BLKmode
	      && (TYPE_ALIGN (TREE_TYPE (TREE_OPERAND (exp, 0)))
		  > MEM_ALIGN (op0))
	      && MEM_ALIGN (op0) < BIGGEST_ALIGNMENT)
	    {
	      tree inner_type = TREE_TYPE (TREE_OPERAND (exp, 0));
	      rtx new;

	      if (TYPE_ALIGN_OK (inner_type))
		abort ();

	      if (TREE_ADDRESSABLE (inner_type))
		{
		  /* We can't make a bitwise copy of this object, so fail.  */
		  error ("cannot take the address of an unaligned member");
		  return const0_rtx;
		}

	      new = assign_stack_temp_for_type
		(TYPE_MODE (inner_type),
		 MEM_SIZE (op0) ? INTVAL (MEM_SIZE (op0))
		 : int_size_in_bytes (inner_type),
		 1, build_qualified_type (inner_type,
					  (TYPE_QUALS (inner_type)
					   | TYPE_QUAL_CONST)));

	      emit_block_move (new, op0, expr_size (TREE_OPERAND (exp, 0)),
			       (modifier == EXPAND_STACK_PARM
				? BLOCK_OP_CALL_PARM : BLOCK_OP_NORMAL));

	      op0 = new;
	    }

	  op0 = force_operand (XEXP (op0, 0), target);
	}

      if (flag_force_addr
	  && !REG_P (op0)
	  && modifier != EXPAND_CONST_ADDRESS
	  && modifier != EXPAND_INITIALIZER
	  && modifier != EXPAND_SUM)
	op0 = force_reg (Pmode, op0);

      if (REG_P (op0)
	  && ! REG_USERVAR_P (op0))
	mark_reg_pointer (op0, TYPE_ALIGN (TREE_TYPE (type)));

      if (GET_MODE (op0) == Pmode && mode == ptr_mode)
	op0 = convert_memory_address (ptr_mode, op0);

      return op0;

    /* COMPLEX type for Extended Pascal & Fortran  */
    case COMPLEX_EXPR:
      {
	enum machine_mode mode = TYPE_MODE (TREE_TYPE (TREE_TYPE (exp)));
	rtx insns;

	/* Get the rtx code of the operands.  */
	op0 = expand_expr (TREE_OPERAND (exp, 0), 0, VOIDmode, 0);
	op1 = expand_expr (TREE_OPERAND (exp, 1), 0, VOIDmode, 0);

	if (! target)
	  target = gen_reg_rtx (TYPE_MODE (TREE_TYPE (exp)));

	start_sequence ();

	/* Move the real (op0) and imaginary (op1) parts to their location.  */
	emit_move_insn (gen_realpart (mode, target), op0);
	emit_move_insn (gen_imagpart (mode, target), op1);

	insns = get_insns ();
	end_sequence ();

	/* Complex construction should appear as a single unit.  */
	/* If TARGET is a CONCAT, we got insns like RD = RS, ID = IS,
	   each with a separate pseudo as destination.
	   It's not correct for flow to treat them as a unit.  */
	if (GET_CODE (target) != CONCAT)
	  emit_no_conflict_block (insns, target, op0, op1, NULL_RTX);
	else
	  emit_insn (insns);

	return target;
      }

    case REALPART_EXPR:
      op0 = expand_expr (TREE_OPERAND (exp, 0), 0, VOIDmode, 0);
      return gen_realpart (mode, op0);

    case IMAGPART_EXPR:
      op0 = expand_expr (TREE_OPERAND (exp, 0), 0, VOIDmode, 0);
      return gen_imagpart (mode, op0);

    case RESX_EXPR:
      expand_resx_expr (exp);
      return const0_rtx;

    case TRY_CATCH_EXPR:
    case CATCH_EXPR:
    case EH_FILTER_EXPR:
    case TRY_FINALLY_EXPR:
      /* Lowered by tree-eh.c.  */
      abort ();

    case WITH_CLEANUP_EXPR:
    case CLEANUP_POINT_EXPR:
    case TARGET_EXPR:
    case CASE_LABEL_EXPR:
    case VA_ARG_EXPR:
    case BIND_EXPR:
    case INIT_EXPR:
    case CONJ_EXPR:
    case COMPOUND_EXPR:
    case PREINCREMENT_EXPR:
    case PREDECREMENT_EXPR:
    case POSTINCREMENT_EXPR:
    case POSTDECREMENT_EXPR:
    case LOOP_EXPR:
    case EXIT_EXPR:
    case LABELED_BLOCK_EXPR:
    case EXIT_BLOCK_EXPR:
    case TRUTH_ANDIF_EXPR:
    case TRUTH_ORIF_EXPR:
      /* Lowered by gimplify.c.  */
      abort ();

    case EXC_PTR_EXPR:
      return get_exception_pointer (cfun);

    case FILTER_EXPR:
      return get_exception_filter (cfun);

    case FDESC_EXPR:
      /* Function descriptors are not valid except for as
	 initialization constants, and should not be expanded.  */
      abort ();

    case SWITCH_EXPR:
      expand_case (exp);
      return const0_rtx;

    case LABEL_EXPR:
      expand_label (TREE_OPERAND (exp, 0));
      return const0_rtx;

    case ASM_EXPR:
      expand_asm_expr (exp);
      return const0_rtx;

    case WITH_SIZE_EXPR:
      /* WITH_SIZE_EXPR expands to its first argument.  The caller should
	 have pulled out the size to use in whatever context it needed.  */
      return expand_expr_real (TREE_OPERAND (exp, 0), original_target, tmode,
			       modifier, alt_rtl);

    default:
      return lang_hooks.expand_expr (exp, original_target, tmode,
				     modifier, alt_rtl);
    }

  /* Here to do an ordinary binary operator.  */
 binop:
  expand_operands (TREE_OPERAND (exp, 0), TREE_OPERAND (exp, 1),
		   subtarget, &op0, &op1, 0);
 binop2:
  this_optab = optab_for_tree_code (code, type);
 binop3:
  if (modifier == EXPAND_STACK_PARM)
    target = 0;
  temp = expand_binop (mode, this_optab, op0, op1, target,
		       unsignedp, OPTAB_LIB_WIDEN);
  if (temp == 0)
    abort ();
  return REDUCE_BIT_FIELD (temp);
}
#undef REDUCE_BIT_FIELD

/* Subroutine of above: reduce EXP to the precision of TYPE (in the
   signedness of TYPE), possibly returning the result in TARGET.  */
static rtx
reduce_to_bit_field_precision (rtx exp, rtx target, tree type)
{
  HOST_WIDE_INT prec = TYPE_PRECISION (type);
  if (target && GET_MODE (target) != GET_MODE (exp))
    target = 0;
  if (TYPE_UNSIGNED (type))
    {
      rtx mask;
      if (prec < HOST_BITS_PER_WIDE_INT)
	mask = immed_double_const (((unsigned HOST_WIDE_INT) 1 << prec) - 1, 0,
				   GET_MODE (exp));
      else
	mask = immed_double_const ((unsigned HOST_WIDE_INT) -1,
				   ((unsigned HOST_WIDE_INT) 1
				    << (prec - HOST_BITS_PER_WIDE_INT)) - 1,
				   GET_MODE (exp));
      return expand_and (GET_MODE (exp), exp, mask, target);
    }
  else
    {
      tree count = build_int_cst (NULL_TREE,
				  GET_MODE_BITSIZE (GET_MODE (exp)) - prec, 0);
      exp = expand_shift (LSHIFT_EXPR, GET_MODE (exp), exp, count, target, 0);
      return expand_shift (RSHIFT_EXPR, GET_MODE (exp), exp, count, target, 0);
    }
}

/* Subroutine of above: returns 1 if OFFSET corresponds to an offset that
   when applied to the address of EXP produces an address known to be
   aligned more than BIGGEST_ALIGNMENT.  */

static int
is_aligning_offset (tree offset, tree exp)
{
  /* Strip off any conversions.  */
  while (TREE_CODE (offset) == NON_LVALUE_EXPR
	 || TREE_CODE (offset) == NOP_EXPR
	 || TREE_CODE (offset) == CONVERT_EXPR)
    offset = TREE_OPERAND (offset, 0);

  /* We must now have a BIT_AND_EXPR with a constant that is one less than
     power of 2 and which is larger than BIGGEST_ALIGNMENT.  */
  if (TREE_CODE (offset) != BIT_AND_EXPR
      || !host_integerp (TREE_OPERAND (offset, 1), 1)
      || compare_tree_int (TREE_OPERAND (offset, 1),
			   BIGGEST_ALIGNMENT / BITS_PER_UNIT) <= 0
      || !exact_log2 (tree_low_cst (TREE_OPERAND (offset, 1), 1) + 1) < 0)
    return 0;

  /* Look at the first operand of BIT_AND_EXPR and strip any conversion.
     It must be NEGATE_EXPR.  Then strip any more conversions.  */
  offset = TREE_OPERAND (offset, 0);
  while (TREE_CODE (offset) == NON_LVALUE_EXPR
	 || TREE_CODE (offset) == NOP_EXPR
	 || TREE_CODE (offset) == CONVERT_EXPR)
    offset = TREE_OPERAND (offset, 0);

  if (TREE_CODE (offset) != NEGATE_EXPR)
    return 0;

  offset = TREE_OPERAND (offset, 0);
  while (TREE_CODE (offset) == NON_LVALUE_EXPR
	 || TREE_CODE (offset) == NOP_EXPR
	 || TREE_CODE (offset) == CONVERT_EXPR)
    offset = TREE_OPERAND (offset, 0);

  /* This must now be the address of EXP.  */
  return TREE_CODE (offset) == ADDR_EXPR && TREE_OPERAND (offset, 0) == exp;
}

/* Return the tree node if an ARG corresponds to a string constant or zero
   if it doesn't.  If we return nonzero, set *PTR_OFFSET to the offset
   in bytes within the string that ARG is accessing.  The type of the
   offset will be `sizetype'.  */

tree
string_constant (tree arg, tree *ptr_offset)
{
  STRIP_NOPS (arg);

  if (TREE_CODE (arg) == ADDR_EXPR
      && TREE_CODE (TREE_OPERAND (arg, 0)) == STRING_CST)
    {
      *ptr_offset = size_zero_node;
      return TREE_OPERAND (arg, 0);
    }
  if (TREE_CODE (arg) == ADDR_EXPR
      && TREE_CODE (TREE_OPERAND (arg, 0)) == ARRAY_REF
      && TREE_CODE (TREE_OPERAND (TREE_OPERAND (arg, 0), 0)) == STRING_CST)
    {
      *ptr_offset = convert (sizetype, TREE_OPERAND (TREE_OPERAND (arg, 0), 1));
      return TREE_OPERAND (TREE_OPERAND (arg, 0), 0);
    }
  else if (TREE_CODE (arg) == PLUS_EXPR)
    {
      tree arg0 = TREE_OPERAND (arg, 0);
      tree arg1 = TREE_OPERAND (arg, 1);

      STRIP_NOPS (arg0);
      STRIP_NOPS (arg1);

      if (TREE_CODE (arg0) == ADDR_EXPR
	  && TREE_CODE (TREE_OPERAND (arg0, 0)) == STRING_CST)
	{
	  *ptr_offset = convert (sizetype, arg1);
	  return TREE_OPERAND (arg0, 0);
	}
      else if (TREE_CODE (arg1) == ADDR_EXPR
	       && TREE_CODE (TREE_OPERAND (arg1, 0)) == STRING_CST)
	{
	  *ptr_offset = convert (sizetype, arg0);
	  return TREE_OPERAND (arg1, 0);
	}
    }

  return 0;
}

/* Generate code to calculate EXP using a store-flag instruction
   and return an rtx for the result.  EXP is either a comparison
   or a TRUTH_NOT_EXPR whose operand is a comparison.

   If TARGET is nonzero, store the result there if convenient.

   If ONLY_CHEAP is nonzero, only do this if it is likely to be very
   cheap.

   Return zero if there is no suitable set-flag instruction
   available on this machine.

   Once expand_expr has been called on the arguments of the comparison,
   we are committed to doing the store flag, since it is not safe to
   re-evaluate the expression.  We emit the store-flag insn by calling
   emit_store_flag, but only expand the arguments if we have a reason
   to believe that emit_store_flag will be successful.  If we think that
   it will, but it isn't, we have to simulate the store-flag with a
   set/jump/set sequence.  */

static rtx
do_store_flag (tree exp, rtx target, enum machine_mode mode, int only_cheap)
{
  enum rtx_code code;
  tree arg0, arg1, type;
  tree tem;
  enum machine_mode operand_mode;
  int invert = 0;
  int unsignedp;
  rtx op0, op1;
  enum insn_code icode;
  rtx subtarget = target;
  rtx result, label;

  /* If this is a TRUTH_NOT_EXPR, set a flag indicating we must invert the
     result at the end.  We can't simply invert the test since it would
     have already been inverted if it were valid.  This case occurs for
     some floating-point comparisons.  */

  if (TREE_CODE (exp) == TRUTH_NOT_EXPR)
    invert = 1, exp = TREE_OPERAND (exp, 0);

  arg0 = TREE_OPERAND (exp, 0);
  arg1 = TREE_OPERAND (exp, 1);

  /* Don't crash if the comparison was erroneous.  */
  if (arg0 == error_mark_node || arg1 == error_mark_node)
    return const0_rtx;

  type = TREE_TYPE (arg0);
  operand_mode = TYPE_MODE (type);
  unsignedp = TYPE_UNSIGNED (type);

  /* We won't bother with BLKmode store-flag operations because it would mean
     passing a lot of information to emit_store_flag.  */
  if (operand_mode == BLKmode)
    return 0;

  /* We won't bother with store-flag operations involving function pointers
     when function pointers must be canonicalized before comparisons.  */
#ifdef HAVE_canonicalize_funcptr_for_compare
  if (HAVE_canonicalize_funcptr_for_compare
      && ((TREE_CODE (TREE_TYPE (TREE_OPERAND (exp, 0))) == POINTER_TYPE
	   && (TREE_CODE (TREE_TYPE (TREE_TYPE (TREE_OPERAND (exp, 0))))
	       == FUNCTION_TYPE))
	  || (TREE_CODE (TREE_TYPE (TREE_OPERAND (exp, 1))) == POINTER_TYPE
	      && (TREE_CODE (TREE_TYPE (TREE_TYPE (TREE_OPERAND (exp, 1))))
		  == FUNCTION_TYPE))))
    return 0;
#endif

  STRIP_NOPS (arg0);
  STRIP_NOPS (arg1);

  /* Get the rtx comparison code to use.  We know that EXP is a comparison
     operation of some type.  Some comparisons against 1 and -1 can be
     converted to comparisons with zero.  Do so here so that the tests
     below will be aware that we have a comparison with zero.   These
     tests will not catch constants in the first operand, but constants
     are rarely passed as the first operand.  */

  switch (TREE_CODE (exp))
    {
    case EQ_EXPR:
      code = EQ;
      break;
    case NE_EXPR:
      code = NE;
      break;
    case LT_EXPR:
      if (integer_onep (arg1))
	arg1 = integer_zero_node, code = unsignedp ? LEU : LE;
      else
	code = unsignedp ? LTU : LT;
      break;
    case LE_EXPR:
      if (! unsignedp && integer_all_onesp (arg1))
	arg1 = integer_zero_node, code = LT;
      else
	code = unsignedp ? LEU : LE;
      break;
    case GT_EXPR:
      if (! unsignedp && integer_all_onesp (arg1))
	arg1 = integer_zero_node, code = GE;
      else
	code = unsignedp ? GTU : GT;
      break;
    case GE_EXPR:
      if (integer_onep (arg1))
	arg1 = integer_zero_node, code = unsignedp ? GTU : GT;
      else
	code = unsignedp ? GEU : GE;
      break;

    case UNORDERED_EXPR:
      code = UNORDERED;
      break;
    case ORDERED_EXPR:
      code = ORDERED;
      break;
    case UNLT_EXPR:
      code = UNLT;
      break;
    case UNLE_EXPR:
      code = UNLE;
      break;
    case UNGT_EXPR:
      code = UNGT;
      break;
    case UNGE_EXPR:
      code = UNGE;
      break;
    case UNEQ_EXPR:
      code = UNEQ;
      break;
    case LTGT_EXPR:
      code = LTGT;
      break;

    default:
      abort ();
    }

  /* Put a constant second.  */
  if (TREE_CODE (arg0) == REAL_CST || TREE_CODE (arg0) == INTEGER_CST)
    {
      tem = arg0; arg0 = arg1; arg1 = tem;
      code = swap_condition (code);
    }

  /* If this is an equality or inequality test of a single bit, we can
     do this by shifting the bit being tested to the low-order bit and
     masking the result with the constant 1.  If the condition was EQ,
     we xor it with 1.  This does not require an scc insn and is faster
     than an scc insn even if we have it.

     The code to make this transformation was moved into fold_single_bit_test,
     so we just call into the folder and expand its result.  */

  if ((code == NE || code == EQ)
      && TREE_CODE (arg0) == BIT_AND_EXPR && integer_zerop (arg1)
      && integer_pow2p (TREE_OPERAND (arg0, 1)))
    {
      tree type = lang_hooks.types.type_for_mode (mode, unsignedp);
      return expand_expr (fold_single_bit_test (code == NE ? NE_EXPR : EQ_EXPR,
						arg0, arg1, type),
			  target, VOIDmode, EXPAND_NORMAL);
    }

  /* Now see if we are likely to be able to do this.  Return if not.  */
  if (! can_compare_p (code, operand_mode, ccp_store_flag))
    return 0;

  icode = setcc_gen_code[(int) code];
  if (icode == CODE_FOR_nothing
      || (only_cheap && insn_data[(int) icode].operand[0].mode != mode))
    {
      /* We can only do this if it is one of the special cases that
	 can be handled without an scc insn.  */
      if ((code == LT && integer_zerop (arg1))
	  || (! only_cheap && code == GE && integer_zerop (arg1)))
	;
      else if (BRANCH_COST >= 0
	       && ! only_cheap && (code == NE || code == EQ)
	       && TREE_CODE (type) != REAL_TYPE
	       && ((abs_optab->handlers[(int) operand_mode].insn_code
		    != CODE_FOR_nothing)
		   || (ffs_optab->handlers[(int) operand_mode].insn_code
		       != CODE_FOR_nothing)))
	;
      else
	return 0;
    }

  if (! get_subtarget (target)
      || GET_MODE (subtarget) != operand_mode)
    subtarget = 0;

  expand_operands (arg0, arg1, subtarget, &op0, &op1, 0);

  if (target == 0)
    target = gen_reg_rtx (mode);

  result = emit_store_flag (target, code, op0, op1,
			    operand_mode, unsignedp, 1);

  if (result)
    {
      if (invert)
	result = expand_binop (mode, xor_optab, result, const1_rtx,
			       result, 0, OPTAB_LIB_WIDEN);
      return result;
    }

  /* If this failed, we have to do this with set/compare/jump/set code.  */
  if (!REG_P (target)
      || reg_mentioned_p (target, op0) || reg_mentioned_p (target, op1))
    target = gen_reg_rtx (GET_MODE (target));

  emit_move_insn (target, invert ? const0_rtx : const1_rtx);
  result = compare_from_rtx (op0, op1, code, unsignedp,
			     operand_mode, NULL_RTX);
  if (GET_CODE (result) == CONST_INT)
    return (((result == const0_rtx && ! invert)
	     || (result != const0_rtx && invert))
	    ? const0_rtx : const1_rtx);

  /* The code of RESULT may not match CODE if compare_from_rtx
     decided to swap its operands and reverse the original code.

     We know that compare_from_rtx returns either a CONST_INT or
     a new comparison code, so it is safe to just extract the
     code from RESULT.  */
  code = GET_CODE (result);

  label = gen_label_rtx ();
  if (bcc_gen_fctn[(int) code] == 0)
    abort ();

  emit_jump_insn ((*bcc_gen_fctn[(int) code]) (label));
  emit_move_insn (target, invert ? const1_rtx : const0_rtx);
  emit_label (label);

  return target;
}


/* Stubs in case we haven't got a casesi insn.  */
#ifndef HAVE_casesi
# define HAVE_casesi 0
# define gen_casesi(a, b, c, d, e) (0)
# define CODE_FOR_casesi CODE_FOR_nothing
#endif

/* If the machine does not have a case insn that compares the bounds,
   this means extra overhead for dispatch tables, which raises the
   threshold for using them.  */
#ifndef CASE_VALUES_THRESHOLD
#define CASE_VALUES_THRESHOLD (HAVE_casesi ? 4 : 5)
#endif /* CASE_VALUES_THRESHOLD */

unsigned int
case_values_threshold (void)
{
  return CASE_VALUES_THRESHOLD;
}

/* Attempt to generate a casesi instruction.  Returns 1 if successful,
   0 otherwise (i.e. if there is no casesi instruction).  */
int
try_casesi (tree index_type, tree index_expr, tree minval, tree range,
	    rtx table_label ATTRIBUTE_UNUSED, rtx default_label)
{
  enum machine_mode index_mode = SImode;
  int index_bits = GET_MODE_BITSIZE (index_mode);
  rtx op1, op2, index;
  enum machine_mode op_mode;

  if (! HAVE_casesi)
    return 0;

  /* Convert the index to SImode.  */
  if (GET_MODE_BITSIZE (TYPE_MODE (index_type)) > GET_MODE_BITSIZE (index_mode))
    {
      enum machine_mode omode = TYPE_MODE (index_type);
      rtx rangertx = expand_expr (range, NULL_RTX, VOIDmode, 0);

      /* We must handle the endpoints in the original mode.  */
      index_expr = build2 (MINUS_EXPR, index_type,
			   index_expr, minval);
      minval = integer_zero_node;
      index = expand_expr (index_expr, NULL_RTX, VOIDmode, 0);
      emit_cmp_and_jump_insns (rangertx, index, LTU, NULL_RTX,
			       omode, 1, default_label);
      /* Now we can safely truncate.  */
      index = convert_to_mode (index_mode, index, 0);
    }
  else
    {
      if (TYPE_MODE (index_type) != index_mode)
	{
	  index_expr = convert (lang_hooks.types.type_for_size
				(index_bits, 0), index_expr);
	  index_type = TREE_TYPE (index_expr);
	}

      index = expand_expr (index_expr, NULL_RTX, VOIDmode, 0);
    }

  do_pending_stack_adjust ();

  op_mode = insn_data[(int) CODE_FOR_casesi].operand[0].mode;
  if (! (*insn_data[(int) CODE_FOR_casesi].operand[0].predicate)
      (index, op_mode))
    index = copy_to_mode_reg (op_mode, index);

  op1 = expand_expr (minval, NULL_RTX, VOIDmode, 0);

  op_mode = insn_data[(int) CODE_FOR_casesi].operand[1].mode;
  op1 = convert_modes (op_mode, TYPE_MODE (TREE_TYPE (minval)),
		       op1, TYPE_UNSIGNED (TREE_TYPE (minval)));
  if (! (*insn_data[(int) CODE_FOR_casesi].operand[1].predicate)
      (op1, op_mode))
    op1 = copy_to_mode_reg (op_mode, op1);

  op2 = expand_expr (range, NULL_RTX, VOIDmode, 0);

  op_mode = insn_data[(int) CODE_FOR_casesi].operand[2].mode;
  op2 = convert_modes (op_mode, TYPE_MODE (TREE_TYPE (range)),
		       op2, TYPE_UNSIGNED (TREE_TYPE (range)));
  if (! (*insn_data[(int) CODE_FOR_casesi].operand[2].predicate)
      (op2, op_mode))
    op2 = copy_to_mode_reg (op_mode, op2);

  emit_jump_insn (gen_casesi (index, op1, op2,
			      table_label, default_label));
  return 1;
}

/* Attempt to generate a tablejump instruction; same concept.  */
#ifndef HAVE_tablejump
#define HAVE_tablejump 0
#define gen_tablejump(x, y) (0)
#endif

/* Subroutine of the next function.

   INDEX is the value being switched on, with the lowest value
   in the table already subtracted.
   MODE is its expected mode (needed if INDEX is constant).
   RANGE is the length of the jump table.
   TABLE_LABEL is a CODE_LABEL rtx for the table itself.

   DEFAULT_LABEL is a CODE_LABEL rtx to jump to if the
   index value is out of range.  */

static void
do_tablejump (rtx index, enum machine_mode mode, rtx range, rtx table_label,
	      rtx default_label)
{
  rtx temp, vector;

  if (INTVAL (range) > cfun->max_jumptable_ents)
    cfun->max_jumptable_ents = INTVAL (range);

  /* Do an unsigned comparison (in the proper mode) between the index
     expression and the value which represents the length of the range.
     Since we just finished subtracting the lower bound of the range
     from the index expression, this comparison allows us to simultaneously
     check that the original index expression value is both greater than
     or equal to the minimum value of the range and less than or equal to
     the maximum value of the range.  */

  emit_cmp_and_jump_insns (index, range, GTU, NULL_RTX, mode, 1,
			   default_label);

  /* If index is in range, it must fit in Pmode.
     Convert to Pmode so we can index with it.  */
  if (mode != Pmode)
    index = convert_to_mode (Pmode, index, 1);

  /* Don't let a MEM slip through, because then INDEX that comes
     out of PIC_CASE_VECTOR_ADDRESS won't be a valid address,
     and break_out_memory_refs will go to work on it and mess it up.  */
#ifdef PIC_CASE_VECTOR_ADDRESS
  if (flag_pic && !REG_P (index))
    index = copy_to_mode_reg (Pmode, index);
#endif

  /* If flag_force_addr were to affect this address
     it could interfere with the tricky assumptions made
     about addresses that contain label-refs,
     which may be valid only very near the tablejump itself.  */
  /* ??? The only correct use of CASE_VECTOR_MODE is the one inside the
     GET_MODE_SIZE, because this indicates how large insns are.  The other
     uses should all be Pmode, because they are addresses.  This code
     could fail if addresses and insns are not the same size.  */
  index = gen_rtx_PLUS (Pmode,
			gen_rtx_MULT (Pmode, index,
				      GEN_INT (GET_MODE_SIZE (CASE_VECTOR_MODE))),
			gen_rtx_LABEL_REF (Pmode, table_label));
#ifdef PIC_CASE_VECTOR_ADDRESS
  if (flag_pic)
    index = PIC_CASE_VECTOR_ADDRESS (index);
  else
#endif
    index = memory_address_noforce (CASE_VECTOR_MODE, index);
  temp = gen_reg_rtx (CASE_VECTOR_MODE);
  vector = gen_const_mem (CASE_VECTOR_MODE, index);
  convert_move (temp, vector, 0);

  emit_jump_insn (gen_tablejump (temp, table_label));

  /* If we are generating PIC code or if the table is PC-relative, the
     table and JUMP_INSN must be adjacent, so don't output a BARRIER.  */
  if (! CASE_VECTOR_PC_RELATIVE && ! flag_pic)
    emit_barrier ();
}

int
try_tablejump (tree index_type, tree index_expr, tree minval, tree range,
	       rtx table_label, rtx default_label)
{
  rtx index;

  if (! HAVE_tablejump)
    return 0;

  index_expr = fold (build2 (MINUS_EXPR, index_type,
			     convert (index_type, index_expr),
			     convert (index_type, minval)));
  index = expand_expr (index_expr, NULL_RTX, VOIDmode, 0);
  do_pending_stack_adjust ();

  do_tablejump (index, TYPE_MODE (index_type),
		convert_modes (TYPE_MODE (index_type),
			       TYPE_MODE (TREE_TYPE (range)),
			       expand_expr (range, NULL_RTX,
					    VOIDmode, 0),
			       TYPE_UNSIGNED (TREE_TYPE (range))),
		table_label, default_label);
  return 1;
}

/* Nonzero if the mode is a valid vector mode for this architecture.
   This returns nonzero even if there is no hardware support for the
   vector mode, but we can emulate with narrower modes.  */

int
vector_mode_valid_p (enum machine_mode mode)
{
  enum mode_class class = GET_MODE_CLASS (mode);
  enum machine_mode innermode;

  /* Doh!  What's going on?  */
  if (class != MODE_VECTOR_INT
      && class != MODE_VECTOR_FLOAT)
    return 0;

  /* Hardware support.  Woo hoo!  */
  if (VECTOR_MODE_SUPPORTED_P (mode))
    return 1;

  innermode = GET_MODE_INNER (mode);

  /* We should probably return 1 if requesting V4DI and we have no DI,
     but we have V2DI, but this is probably very unlikely.  */

  /* If we have support for the inner mode, we can safely emulate it.
     We may not have V2DI, but me can emulate with a pair of DIs.  */
  return mov_optab->handlers[innermode].insn_code != CODE_FOR_nothing;
}

/* Return a CONST_VECTOR rtx for a VECTOR_CST tree.  */
static rtx
const_vector_from_tree (tree exp)
{
  rtvec v;
  int units, i;
  tree link, elt;
  enum machine_mode inner, mode;

  mode = TYPE_MODE (TREE_TYPE (exp));

  if (initializer_zerop (exp))
    return CONST0_RTX (mode);

  units = GET_MODE_NUNITS (mode);
  inner = GET_MODE_INNER (mode);

  v = rtvec_alloc (units);

  link = TREE_VECTOR_CST_ELTS (exp);
  for (i = 0; link; link = TREE_CHAIN (link), ++i)
    {
      elt = TREE_VALUE (link);

      if (TREE_CODE (elt) == REAL_CST)
	RTVEC_ELT (v, i) = CONST_DOUBLE_FROM_REAL_VALUE (TREE_REAL_CST (elt),
							 inner);
      else
	RTVEC_ELT (v, i) = immed_double_const (TREE_INT_CST_LOW (elt),
					       TREE_INT_CST_HIGH (elt),
					       inner);
    }

  /* Initialize remaining elements to 0.  */
  for (; i < units; ++i)
    RTVEC_ELT (v, i) = CONST0_RTX (inner);

  return gen_rtx_raw_CONST_VECTOR (mode, v);
}
#include "gt-expr.h"
