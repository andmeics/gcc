/* Subroutines for code generation on Motorola 68HC11 and 68HC12.
   Copyright (C) 1999, 2000 Free Software Foundation, Inc.
   Contributed by Stephane Carrez (stcarrez@worldnet.fr)

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
Boston, MA 02111-1307, USA.

Note:
   A first 68HC11 port was made by Otto Lind (otto@coactive.com)
   on gcc 2.6.3.  I have used it as a starting point for this port.
   However, this new port is a complete re-write.  Its internal
   design is completely different.  The generated code is not
   compatible with the gcc 2.6.3 port.

   The gcc 2.6.3 port is available at:

   ftp.unina.it/pub/electronics/motorola/68hc11/gcc/gcc-6811-fsf.tar.gz

*/

#include <stdio.h>
#include "config.h"
#include "system.h"
#include "rtl.h"
#include "tree.h"
#if GCC_VERSION > 2095
#include "tm_p.h"
#endif
#include "regs.h"
#include "hard-reg-set.h"
#include "real.h"
#include "insn-config.h"
#include "conditions.h"
#include "insn-flags.h"
#include "output.h"
#include "insn-attr.h"
#include "flags.h"
#include "recog.h"
#include "expr.h"
#include "toplev.h"
#include "basic-block.h"
#if GCC_VERSION > 2095
#include "function.h"
#include "ggc.h"
#else
#include "m68hc11-protos.h"
#endif

#if GCC_VERSION == 2095
extern char *version_string;
#endif

static void print_options PARAMS ((FILE *));
static void emit_move_after_reload PARAMS ((rtx, rtx, rtx));
static rtx simplify_logical PARAMS ((enum machine_mode, int, rtx, rtx *));
static void m68hc11_emit_logical PARAMS ((enum machine_mode, int, rtx *));
static int go_if_legitimate_address_internal PARAMS((rtx, enum machine_mode,
                                                     int));
static int register_indirect_p PARAMS((rtx, enum machine_mode, int));
static rtx m68hc11_expand_compare PARAMS((enum rtx_code, rtx, rtx));
static int must_parenthesize PARAMS ((rtx));

static int m68hc11_auto_inc_p PARAMS ((rtx));

void create_regs_rtx PARAMS ((void));

static void asm_print_register PARAMS ((FILE *, int));

rtx m68hc11_soft_tmp_reg;

/* Must be set to 1 to produce debug messages. */
int debug_m6811 = 0;

extern FILE *asm_out_file;

rtx ix_reg;
rtx iy_reg;
rtx d_reg;
rtx da_reg;
rtx stack_push_word;
rtx stack_pop_word;
static int regs_inited = 0;
static rtx z_reg;

/* Set to 1 by expand_prologue() when the function is an interrupt handler.  */
int current_function_interrupt;

/* Set to 1 by expand_prologue() when the function is a trap handler.  */
int current_function_trap;

/* Min offset that is valid for the indirect addressing mode.  */
HOST_WIDE_INT m68hc11_min_offset = 0;

/* Max offset that is valid for the indirect addressing mode.  */
HOST_WIDE_INT m68hc11_max_offset = 256;

/* The class value for base registers.  */
enum reg_class m68hc11_base_reg_class = A_REGS;

/* The class value for index registers.  This is NO_REGS for 68HC11.  */
enum reg_class m68hc11_index_reg_class = NO_REGS;

enum reg_class m68hc11_tmp_regs_class = NO_REGS;

/* Tables that tell whether a given hard register is valid for
   a base or an index register.  It is filled at init time depending
   on the target processor.  */
unsigned char m68hc11_reg_valid_for_base[FIRST_PSEUDO_REGISTER];
unsigned char m68hc11_reg_valid_for_index[FIRST_PSEUDO_REGISTER];

/* A correction offset which is applied to the stack pointer.
   This is 1 for 68HC11 and 0 for 68HC12.  */
int m68hc11_sp_correction;

/* Comparison operands saved by the "tstxx" and "cmpxx" expand patterns.  */
rtx m68hc11_compare_op0;
rtx m68hc11_compare_op1;


/* Machine specific options */

const char *m68hc11_regparm_string;
const char *m68hc11_reg_alloc_order;
const char *m68hc11_soft_reg_count;

static void m68hc11_add_gc_roots PARAMS ((void));

static int nb_soft_regs;

#if GCC_VERSION > 2095
/* Flag defined in c-decl.c

   Nonzero means don't recognize the non-ANSI builtin functions.
   -ansi sets this.

   It is set by 'm68hc11_override_options' to ensure that bcmp() and
   bzero() are not defined.  Their prototype are wrong and they
   conflict with newlib definition.  Don't define as external to
   avoid a link problem for f77.  */
int flag_no_nonansi_builtin;
#endif

int
m68hc11_override_options ()
{
  m68hc11_add_gc_roots ();

#if GCC_VERSION > 2095
  flag_no_nonansi_builtin = 1;
#endif
  
  memset (m68hc11_reg_valid_for_index, 0,
	  sizeof (m68hc11_reg_valid_for_index));
  memset (m68hc11_reg_valid_for_base, 0, sizeof (m68hc11_reg_valid_for_base));

  /* Configure for a 68hc11 processor.  */
  if (TARGET_M6811)
    {
      /* If gcc was built for a 68hc12, invalidate that because
         a -m68hc11 option was specified on the command line.  */
      if (TARGET_DEFAULT != MASK_M6811)
        target_flags &= ~TARGET_DEFAULT;
      
      m68hc11_min_offset = 0;
      m68hc11_max_offset = 256;
      m68hc11_index_reg_class = NO_REGS;
      m68hc11_base_reg_class = A_REGS;
      m68hc11_reg_valid_for_base[HARD_X_REGNUM] = 1;
      m68hc11_reg_valid_for_base[HARD_Y_REGNUM] = 1;
      m68hc11_reg_valid_for_base[HARD_Z_REGNUM] = 1;
      m68hc11_sp_correction = 1;
      m68hc11_tmp_regs_class = D_REGS;
      if (m68hc11_soft_reg_count == 0 && !TARGET_M6812)
	m68hc11_soft_reg_count = "4";
    }

  /* Configure for a 68hc12 processor.  */
  if (TARGET_M6812)
    {
      m68hc11_min_offset = 0;
      m68hc11_max_offset = 65536;
      m68hc11_index_reg_class = D_REGS;
      m68hc11_base_reg_class = A_OR_SP_REGS;
      m68hc11_reg_valid_for_base[HARD_X_REGNUM] = 1;
      m68hc11_reg_valid_for_base[HARD_Y_REGNUM] = 1;
      m68hc11_reg_valid_for_base[HARD_Z_REGNUM] = 1;
      m68hc11_reg_valid_for_base[HARD_SP_REGNUM] = 1;
      m68hc11_reg_valid_for_index[HARD_D_REGNUM] = 1;
      m68hc11_sp_correction = 0;
      m68hc11_tmp_regs_class = TMP_REGS;
      target_flags &= ~MASK_M6811;
      if (m68hc11_soft_reg_count == 0)
	m68hc11_soft_reg_count = "2";
    }
  return 0;
}


void
m68hc11_conditional_register_usage ()
{
  int i;
  int cnt = atoi (m68hc11_soft_reg_count);

  if (cnt < 0)
    cnt = 0;
  if (cnt > SOFT_REG_LAST - SOFT_REG_FIRST)
    cnt = SOFT_REG_LAST - SOFT_REG_FIRST;

  nb_soft_regs = cnt;
  for (i = SOFT_REG_FIRST + cnt; i < SOFT_REG_LAST; i++)
    {
      fixed_regs[i] = 1;
      call_used_regs[i] = 1;
    }
}


/* Reload and register operations. */

static const char *reg_class_names[] = REG_CLASS_NAMES;


void
create_regs_rtx ()
{
  /*  regs_inited = 1; */
  ix_reg = gen_rtx (REG, HImode, HARD_X_REGNUM);
  iy_reg = gen_rtx (REG, HImode, HARD_Y_REGNUM);
  d_reg = gen_rtx (REG, HImode, HARD_D_REGNUM);
  da_reg = gen_rtx (REG, QImode, HARD_A_REGNUM);
  m68hc11_soft_tmp_reg = gen_rtx (REG, HImode, SOFT_TMP_REGNUM);

  stack_push_word = gen_rtx (MEM, HImode,
			     gen_rtx (PRE_DEC, HImode,
				      gen_rtx (REG, HImode, HARD_SP_REGNUM)));
  stack_pop_word = gen_rtx (MEM, HImode,
			    gen_rtx (POST_INC, HImode,
				     gen_rtx (REG, HImode, HARD_SP_REGNUM)));

}

/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.
    - 8 bit values are stored anywhere (except the SP register).
    - 16 bit values can be stored in any register whose mode is 16
    - 32 bit values can be stored in D, X registers or in a soft register
      (except the last one because we need 2 soft registers)
    - Values whose size is > 32 bit are not stored in real hard
      registers.  They may be stored in soft registers if there are
      enough of them.  */
int
hard_regno_mode_ok (regno, mode)
     int regno;
     enum machine_mode mode;
{
  switch (GET_MODE_SIZE (mode))
    {
    case 8:
      return S_REGNO_P (regno) && nb_soft_regs >= 4;

    case 4:
      return X_REGNO_P (regno) || (S_REGNO_P (regno) && nb_soft_regs >= 2);

    case 2:
      return G_REGNO_P (regno);

    case 1:
      /* We have to accept a QImode in X or Y registers.  Otherwise, the
         reload pass will fail when some (SUBREG:QI (REG:HI X)) are defined
         in the insns.  Reload fails if the insn rejects the register class 'a'
         as well as if it accepts it.  Patterns that failed were
         zero_extend_qihi2 and iorqi3.  */

      return G_REGNO_P (regno) && !SP_REGNO_P (regno);

    default:
      return 0;
    }
}

enum reg_class
limit_reload_class (mode, class)
     enum machine_mode mode;
     enum reg_class class;
{
  if (mode == Pmode)
    {
      if (class == m68hc11_base_reg_class || class == SP_REGS
	  || class == Y_REGS || class == X_REGS
	  || class == X_OR_SP_REGS || class == Y_OR_S_REGS
	  || class == A_OR_SP_REGS)
	return class;

      if (debug_m6811)
	{
	  printf ("Forcing to A_REGS\n");
	  fflush (stdout);
	}
      return m68hc11_base_reg_class;
    }
  return class;
}

enum reg_class
preferred_reload_class (operand, class)
     rtx operand;
     enum reg_class class;
{
  enum machine_mode mode;

  mode = GET_MODE (operand);

  if (debug_m6811)
    {
      printf ("Preferred reload: (class=%s): ", reg_class_names[class]);
    }

  if (class == D_OR_A_OR_S_REGS && SP_REG_P (operand))
    return m68hc11_base_reg_class;

  if (class >= S_REGS && (GET_CODE (operand) == MEM
			  || GET_CODE (operand) == CONST_INT))
    {
      /* S_REGS class must not be used.  The movhi template does not
         work to move a memory to a soft register.
         Restrict to a hard reg.  */
      switch (class)
	{
	default:
	case G_REGS:
	case D_OR_A_OR_S_REGS:
	  class = A_OR_D_REGS;
	  break;
	case A_OR_S_REGS:
	  class = A_REGS;
	  break;
	case D_OR_SP_OR_S_REGS:
	  class = D_OR_SP_REGS;
	  break;
	case D_OR_Y_OR_S_REGS:
	  class = D_OR_Y_REGS;
	  break;
	case D_OR_X_OR_S_REGS:
	  class = D_OR_X_REGS;
	  break;
	case SP_OR_S_REGS:
	  class = SP_REGS;
	  break;
	case Y_OR_S_REGS:
	  class = Y_REGS;
	  break;
	case X_OR_S_REGS:
	  class = X_REGS;
	  break;
	case D_OR_S_REGS:
	  class = D_REGS;
	}
    }
  else if (class == Y_REGS && GET_CODE (operand) == MEM)
    {
      class = Y_REGS;
    }
  else if (class == A_OR_D_REGS && GET_MODE_SIZE (mode) == 4)
    {
      class = D_OR_X_REGS;
    }
  else if (class >= S_REGS && S_REG_P (operand))
    {
      switch (class)
	{
	default:
	case G_REGS:
	case D_OR_A_OR_S_REGS:
	  class = A_OR_D_REGS;
	  break;
	case A_OR_S_REGS:
	  class = A_REGS;
	  break;
	case D_OR_SP_OR_S_REGS:
	  class = D_OR_SP_REGS;
	  break;
	case D_OR_Y_OR_S_REGS:
	  class = D_OR_Y_REGS;
	  break;
	case D_OR_X_OR_S_REGS:
	  class = D_OR_X_REGS;
	  break;
	case SP_OR_S_REGS:
	  class = SP_REGS;
	  break;
	case Y_OR_S_REGS:
	  class = Y_REGS;
	  break;
	case X_OR_S_REGS:
	  class = X_REGS;
	  break;
	case D_OR_S_REGS:
	  class = D_REGS;
	}
    }
  else if (class >= S_REGS)
    {
      if (debug_m6811)
	{
	  printf ("Class = %s for: ", reg_class_names[class]);
	  fflush (stdout);
	  debug_rtx (operand);
	}
    }

  if (debug_m6811)
    {
      printf (" => class=%s\n", reg_class_names[class]);
      fflush (stdout);
      debug_rtx (operand);
    }

  return class;
}

/* Return 1 if the operand is a valid indexed addressing mode.
   For 68hc11:  n,r    with n in [0..255] and r in A_REGS class
   For 68hc12:  n,r    no constraint on the constant, r in A_REGS class.  */
static int
register_indirect_p (operand, mode, strict)
     rtx operand;
     enum machine_mode mode;
     int strict;
{
  rtx base, offset;

  switch (GET_CODE (operand))
    {
    case POST_INC:
    case PRE_INC:
    case POST_DEC:
    case PRE_DEC:
      if (TARGET_M6812 && TARGET_AUTO_INC_DEC)
	return register_indirect_p (XEXP (operand, 0), mode, strict);
      return 0;

    case PLUS:
      base = XEXP (operand, 0);
      if (GET_CODE (base) == MEM)
	return 0;

      offset = XEXP (operand, 1);
      if (GET_CODE (offset) == MEM)
	return 0;

      if (GET_CODE (base) == REG)
	{
	  if (!VALID_CONSTANT_OFFSET_P (offset, mode))
	    return 0;

	  if (strict == 0)
	    return 1;

	  return REGNO_OK_FOR_BASE_P2 (REGNO (base), strict);
	}
      if (GET_CODE (offset) == REG)
	{
	  if (!VALID_CONSTANT_OFFSET_P (base, mode))
	    return 0;

	  if (strict == 0)
	    return 1;

	  return REGNO_OK_FOR_BASE_P2 (REGNO (offset), strict);
	}
      return 0;

    case REG:
      return REGNO_OK_FOR_BASE_P2 (REGNO (operand), strict);

    default:
      return 0;
    }
}

/* Returns 1 if the operand fits in a 68HC11 indirect mode or in
   a 68HC12 1-byte index addressing mode.  */
int
m68hc11_small_indexed_indirect_p (operand, mode)
     rtx operand;
     enum machine_mode mode;
{
  rtx base, offset;

  if (GET_CODE (operand) != MEM)
    return 0;

  operand = XEXP (operand, 0);
  if (CONSTANT_ADDRESS_P (operand))
    return 1;

  if (PUSH_POP_ADDRESS_P (operand))
    return 1;

  if (!register_indirect_p (operand, mode,
                            (reload_completed | reload_in_progress)))
    return 0;

  if (TARGET_M6812 && GET_CODE (operand) == PLUS
      && (reload_completed | reload_in_progress))
    {
      base = XEXP (operand, 0);
      offset = XEXP (operand, 1);
      if (GET_CODE (base) == CONST_INT)
	offset = base;

      switch (GET_MODE_SIZE (mode))
	{
	case 8:
	  if (INTVAL (offset) < -16 + 6 || INTVAL (offset) > 15 - 6)
	    return 0;
	  break;

	case 4:
	  if (INTVAL (offset) < -16 + 2 || INTVAL (offset) > 15 - 2)
	    return 0;
	  break;

	default:
	  if (INTVAL (offset) < -16 || INTVAL (offset) > 15)
	    return 0;
	  break;
	}
    }
  return 1;
}

int
m68hc11_register_indirect_p (operand, mode)
     rtx operand;
     enum machine_mode mode;
{
  if (GET_CODE (operand) != MEM)
    return 0;

  operand = XEXP (operand, 0);
  return register_indirect_p (operand, mode,
                              (reload_completed | reload_in_progress));
}

static int
go_if_legitimate_address_internal (operand, mode, strict)
     rtx operand;
     enum machine_mode mode;
     int strict;
{
  if (CONSTANT_ADDRESS_P (operand))
    {
      /* Reject the global variables if they are too wide.  This forces
         a load of their address in a register and generates smaller code.  */
      if (GET_MODE_SIZE (mode) == 8)
	return 0;

      return 1;
    }
  if (register_indirect_p (operand, mode, strict))
    {
      return 1;
    }
  if (PUSH_POP_ADDRESS_P (operand))
    {
      return 1;
    }
  if (symbolic_memory_operand (operand, mode))
    {
      return 1;
    }
  return 0;
}

int
m68hc11_go_if_legitimate_address (operand, mode, strict)
     rtx operand;
     enum machine_mode mode;
     int strict;
{
  int result;

  if (debug_m6811)
    {
      printf ("Checking: ");
      fflush (stdout);
      debug_rtx (operand);
    }

  result = go_if_legitimate_address_internal (operand, mode, strict);

  if (debug_m6811)
    {
      printf (" -> %s\n", result == 0 ? "NO" : "YES");
    }

  if (result == 0)
    {
      if (debug_m6811)
	{
	  printf ("go_if_legitimate%s, ret 0: %d:",
		  (strict ? "_strict" : ""), mode);
	  fflush (stdout);
	  debug_rtx (operand);
	}
    }
  return result;
}

int
m68hc11_legitimize_address (operand, old_operand, mode)
     rtx *operand ATTRIBUTE_UNUSED;
     rtx old_operand ATTRIBUTE_UNUSED;
     enum machine_mode mode ATTRIBUTE_UNUSED;
{
  return 0;
}


int
m68hc11_reload_operands (operands)
     rtx operands[];
{
  enum machine_mode mode;

  if (regs_inited == 0)
    create_regs_rtx ();

  mode = GET_MODE (operands[1]);

  /* Input reload of indirect addressing (MEM (PLUS (REG) (CONST))). */
  if (A_REG_P (operands[0]) && memory_reload_operand (operands[1], mode))
    {
      rtx big_offset = XEXP (XEXP (operands[1], 0), 1);
      rtx base = XEXP (XEXP (operands[1], 0), 0);

      if (GET_CODE (base) != REG)
	{
	  rtx tmp = base;
	  base = big_offset;
	  big_offset = tmp;
	}

      /* If the offset is out of range, we have to compute the address
         with a separate add instruction.  We try to do with with an 8-bit
         add on the A register.  This is possible only if the lowest part
         of the offset (ie, big_offset % 256) is a valid constant offset
         with respect to the mode.  If it's not, we have to generate a
         16-bit add on the D register.  From:
       
         (SET (REG X (MEM (PLUS (REG X) (CONST_INT 1000)))))
       
         we generate:
        
         [(SET (REG D) (REG X)) (SET (REG X) (REG D))]
         (SET (REG A) (PLUS (REG A) (CONST_INT 1000 / 256)))
         [(SET (REG D) (REG X)) (SET (REG X) (REG D))]
         (SET (REG X) (MEM (PLUS (REG X) (CONST_INT 1000 % 256)))
       
         (SET (REG X) (PLUS (REG X) (CONST_INT 1000 / 256 * 256)))
         (SET (REG X) (MEM (PLUS (REG X) (CONST_INT 1000 % 256)))) 

      */
      if (!VALID_CONSTANT_OFFSET_P (big_offset, mode))
	{
	  int vh, vl;
	  rtx reg = operands[0];
	  rtx offset;
	  int val = INTVAL (big_offset);


	  /* We use the 'operands[0]' as a scratch register to compute the
	     address. Make sure 'base' is in that register.  */
	  if (!rtx_equal_p (base, operands[0]))
	    {
	      emit_move_insn (reg, base);
	    }

	  if (val > 0)
	    {
	      vh = val >> 8;
	      vl = val & 0x0FF;
	    }
	  else
	    {
	      vh = (val >> 8) & 0x0FF;
	      vl = val & 0x0FF;
	    }

	  /* Create the lowest part offset that still remains to be added.
	     If it's not a valid offset, do a 16-bit add.  */
	  offset = gen_rtx (CONST_INT, VOIDmode, vl);
	  if (!VALID_CONSTANT_OFFSET_P (offset, mode))
	    {
	      emit_insn (gen_rtx (SET, VOIDmode, reg,
				  gen_rtx (PLUS, HImode, reg, big_offset)));
	      offset = const0_rtx;
	    }
	  else
	    {
	      emit_insn (gen_rtx (SET, VOIDmode, reg,
				  gen_rtx (PLUS, HImode, reg,
					   gen_rtx (CONST_INT,
						    VOIDmode, vh << 8))));
	    }
	  emit_move_insn (operands[0],
			  gen_rtx (MEM, GET_MODE (operands[1]),
				   gen_rtx (PLUS, Pmode, reg, offset)));
	  return 1;
	}
    }

  /* Use the normal gen_movhi pattern. */
  return 0;
}

void
m68hc11_emit_libcall (name, code, dmode, smode, noperands, operands)
     const char *name;
     enum rtx_code code;
     enum machine_mode dmode;
     enum machine_mode smode;
     int noperands;
     rtx *operands;
{
  rtx ret;
  rtx insns;
  rtx libcall;
  rtx equiv;

  start_sequence ();
  libcall = gen_rtx_SYMBOL_REF (Pmode, name);
  switch (noperands)
    {
    case 2:
      ret = emit_library_call_value (libcall, NULL_RTX, 1, dmode, 1,
                                     operands[1], smode);
      equiv = gen_rtx (code, dmode, operands[1]);
      break;

    case 3:
      ret = emit_library_call_value (libcall, operands[0], 1, dmode, 2,
                                     operands[1], smode, operands[2],
                                     smode);
      equiv = gen_rtx (code, dmode, operands[1], operands[2]);
      break;

    default:
      fatal ("m68hc11_emit_libcall: Bad number of operands");
    }

  insns = get_insns ();
  end_sequence ();
  emit_libcall_block (insns, operands[0], ret, equiv);
}

/* Returns true if X is a PRE/POST increment decrement
   (same as auto_inc_p() in rtlanal.c but do not take into
   account the stack).  */
static int
m68hc11_auto_inc_p (x)
     rtx x;
{
  return GET_CODE (x) == PRE_DEC
    || GET_CODE (x) == POST_INC
    || GET_CODE (x) == POST_DEC || GET_CODE (x) == PRE_INC;
}


/* Predicates for machine description.  */

int
memory_reload_operand (operand, mode)
     rtx operand;
     enum machine_mode mode ATTRIBUTE_UNUSED;
{
  return GET_CODE (operand) == MEM
    && GET_CODE (XEXP (operand, 0)) == PLUS
    && ((GET_CODE (XEXP (XEXP (operand, 0), 0)) == REG
	 && GET_CODE (XEXP (XEXP (operand, 0), 1)) == CONST_INT)
	|| (GET_CODE (XEXP (XEXP (operand, 0), 1)) == REG
	    && GET_CODE (XEXP (XEXP (operand, 0), 0)) == CONST_INT));
}

int
tst_operand (operand, mode)
     rtx operand;
     enum machine_mode mode;
{
  if (GET_CODE (operand) == MEM)
    {
      rtx addr = XEXP (operand, 0);
      if (m68hc11_auto_inc_p (addr))
	return 0;
    }
  return nonimmediate_operand (operand, mode);
}

int
cmp_operand (operand, mode)
     rtx operand;
     enum machine_mode mode;
{
  if (GET_CODE (operand) == MEM)
    {
      rtx addr = XEXP (operand, 0);
      if (m68hc11_auto_inc_p (addr))
	return 0;
    }
  return general_operand (operand, mode);
}

int
non_push_operand (operand, mode)
     rtx operand;
     enum machine_mode mode;
{
  if (general_operand (operand, mode) == 0)
    return 0;

  if (push_operand (operand, mode) == 1)
    return 0;
  return 1;
}

int
reg_or_some_mem_operand (operand, mode)
     rtx operand;
     enum machine_mode mode;
{
  if (GET_CODE (operand) == MEM)
    {
      rtx op = XEXP (operand, 0);

      if (symbolic_memory_operand (op, mode))
	return 1;

      if (IS_STACK_PUSH (operand))
	return 1;

      if (m68hc11_register_indirect_p (operand, mode))
	return 1;

      return 0;
    }

  return register_operand (operand, mode);
}

int
stack_register_operand (operand, mode)
     rtx operand;
     enum machine_mode mode ATTRIBUTE_UNUSED;
{
  return SP_REG_P (operand);
}

int
d_register_operand (operand, mode)
     rtx operand;
     enum machine_mode mode ATTRIBUTE_UNUSED;
{
  if (GET_CODE (operand) == SUBREG)
    operand = XEXP (operand, 0);

  return GET_CODE (operand) == REG
    && (REGNO (operand) >= FIRST_PSEUDO_REGISTER
	|| REGNO (operand) == HARD_D_REGNUM);
}

int
hard_addr_reg_operand (operand, mode)
     rtx operand;
     enum machine_mode mode ATTRIBUTE_UNUSED;
{
  if (GET_CODE (operand) == SUBREG)
    operand = XEXP (operand, 0);

  return GET_CODE (operand) == REG
    && (REGNO (operand) == HARD_X_REGNUM
	|| REGNO (operand) == HARD_Y_REGNUM
	|| REGNO (operand) == HARD_Z_REGNUM);
}

int
hard_reg_operand (operand, mode)
     rtx operand;
     enum machine_mode mode ATTRIBUTE_UNUSED;
{
  if (GET_CODE (operand) == SUBREG)
    operand = XEXP (operand, 0);

  return GET_CODE (operand) == REG
    && (REGNO (operand) >= FIRST_PSEUDO_REGISTER
	|| H_REGNO_P (REGNO (operand)));
}

int
memory_indexed_operand (operand, mode)
     rtx operand;
     enum machine_mode mode ATTRIBUTE_UNUSED;
{
  if (GET_CODE (operand) != MEM)
    return 0;

  operand = XEXP (operand, 0);
  if (GET_CODE (operand) == PLUS)
    {
      if (GET_CODE (XEXP (operand, 0)) == REG)
	operand = XEXP (operand, 0);
      else if (GET_CODE (XEXP (operand, 1)) == REG)
	operand = XEXP (operand, 1);
    }
  return GET_CODE (operand) == REG
    && (REGNO (operand) >= FIRST_PSEUDO_REGISTER
	|| A_REGNO_P (REGNO (operand)));
}

int
push_pop_operand_p (operand)
     rtx operand;
{
  if (GET_CODE (operand) != MEM)
    {
      return 0;
    }
  operand = XEXP (operand, 0);
  return PUSH_POP_ADDRESS_P (operand);
}

/* Returns 1 if OP is either a symbol reference or a sum of a symbol
   reference and a constant.  */

int
symbolic_memory_operand (op, mode)
     register rtx op;
     enum machine_mode mode;
{
  switch (GET_CODE (op))
    {
    case SYMBOL_REF:
    case LABEL_REF:
      return 1;

    case CONST:
      return ((GET_CODE (XEXP (op, 0)) == SYMBOL_REF
	       || GET_CODE (XEXP (op, 0)) == LABEL_REF)
	      && GET_CODE (XEXP (op, 1)) == CONST_INT);

      /* ??? This clause seems to be irrelevant.  */
    case CONST_DOUBLE:
      return GET_MODE (op) == mode;

    case PLUS:
      return symbolic_memory_operand (XEXP (op, 0), mode)
	&& symbolic_memory_operand (XEXP (op, 1), mode);

    default:
      return 0;
    }
}

int
m68hc11_logical_operator (op, mode)
     register rtx op;
     enum machine_mode mode ATTRIBUTE_UNUSED;
{
  return GET_CODE (op) == AND || GET_CODE (op) == IOR || GET_CODE (op) == XOR;
}

int
m68hc11_arith_operator (op, mode)
     register rtx op;
     enum machine_mode mode ATTRIBUTE_UNUSED;
{
  return GET_CODE (op) == AND || GET_CODE (op) == IOR || GET_CODE (op) == XOR
    || GET_CODE (op) == PLUS || GET_CODE (op) == MINUS
    || GET_CODE (op) == ASHIFT || GET_CODE (op) == ASHIFTRT
    || GET_CODE (op) == LSHIFTRT || GET_CODE (op) == ROTATE
    || GET_CODE (op) == ROTATERT;
}

int
m68hc11_non_shift_operator (op, mode)
     register rtx op;
     enum machine_mode mode ATTRIBUTE_UNUSED;
{
  return GET_CODE (op) == AND || GET_CODE (op) == IOR || GET_CODE (op) == XOR
    || GET_CODE (op) == PLUS || GET_CODE (op) == MINUS;
}


int
m68hc11_unary_operator (op, mode)
     register rtx op;
     enum machine_mode mode ATTRIBUTE_UNUSED;
{
  return GET_CODE (op) == NEG || GET_CODE (op) == NOT
    || GET_CODE (op) == SIGN_EXTEND || GET_CODE (op) == ZERO_EXTEND;
}


/* Profiling.  */

int
m68hc11_block_profiler (out, blockno)
     FILE *out ATTRIBUTE_UNUSED;
     int blockno ATTRIBUTE_UNUSED;
{
  return 0;
}

int
m68hc11_function_block_profiler (out, block_or_label)
     FILE *out ATTRIBUTE_UNUSED;
     int block_or_label ATTRIBUTE_UNUSED;
{
  return 0;
}

/* Declaration of types.  */

/* If defined, a C expression whose value is nonzero if IDENTIFIER
   with arguments ARGS is a valid machine specific attribute for DECL.
   The attributes in ATTRIBUTES have previously been assigned to DECL.  */

int
m68hc11_valid_decl_attribute_p (decl, attributes, identifier, args)
     tree decl ATTRIBUTE_UNUSED;
     tree attributes ATTRIBUTE_UNUSED;
     tree identifier ATTRIBUTE_UNUSED;
     tree args ATTRIBUTE_UNUSED;
{
  return 0;
}

/* If defined, a C expression whose value is nonzero if IDENTIFIER
   with arguments ARGS is a valid machine specific attribute for TYPE.
   The attributes in ATTRIBUTES have previously been assigned to TYPE.  */

int
m68hc11_valid_type_attribute_p (type, attributes, identifier, args)
     tree type;
     tree attributes ATTRIBUTE_UNUSED;
     tree identifier;
     tree args;
{
  if (TREE_CODE (type) != FUNCTION_TYPE
      && TREE_CODE (type) != FIELD_DECL && TREE_CODE (type) != TYPE_DECL)
    return 0;

  if (TREE_CODE (type) == FUNCTION_TYPE)
    {
      if (is_attribute_p ("interrupt", identifier))
	return (args == NULL_TREE);
      if (is_attribute_p ("trap", identifier))
	return (args == NULL_TREE);
    }

  return 0;
}

/* If defined, a C expression whose value is zero if the attributes on
   TYPE1 and TYPE2 are incompatible, one if they are compatible, and
   two if they are nearly compatible (which causes a warning to be
   generated).  */

int
m68hc11_comp_type_attributes (type1, type2)
     tree type1 ATTRIBUTE_UNUSED;
     tree type2 ATTRIBUTE_UNUSED;
{
  return 1;
}

/* If defined, a C statement that assigns default attributes to newly
   defined TYPE.  */

void
m68hc11_set_default_type_attributes (type)
     tree type ATTRIBUTE_UNUSED;
{
}

/* Define this macro if references to a symbol must be treated
   differently depending on something about the variable or function
   named by the symbol (such as what section it is in).

   For the 68HC11, we want to recognize trap handlers so that we
   handle calls to traps in a special manner (by issuing the trap).
   This information is stored in SYMBOL_REF_FLAG.  */
void
m68hc11_encode_section_info (decl)
     tree decl;
{
  tree func_attr;
  int trap_handler;
  rtx rtl;

  if (TREE_CODE (decl) != FUNCTION_DECL)
    return;

  rtl = DECL_RTL (decl);

  func_attr = TYPE_ATTRIBUTES (TREE_TYPE (decl));
  trap_handler = lookup_attribute ("trap", func_attr) != NULL_TREE;
  SYMBOL_REF_FLAG (XEXP (rtl, 0)) = trap_handler;
}


/* Argument support functions.  */

/* Handle the FUNCTION_ARG_PASS_BY_REFERENCE macro.
   Arrays are passed by references and other types by value.

   SCz: I tried to pass DImode by reference but it seems that this
   does not work very well.  */
int
m68hc11_function_arg_pass_by_reference (cum, mode, type, named)
     const CUMULATIVE_ARGS *cum ATTRIBUTE_UNUSED;
     enum machine_mode mode ATTRIBUTE_UNUSED;
     tree type;
     int named ATTRIBUTE_UNUSED;
{
  return ((type && TREE_CODE (type) == ARRAY_TYPE)
	  /* Consider complex values as aggregates, so care for TCmode. */
	  /*|| GET_MODE_SIZE (mode) > 4 SCz, temporary */
	  /*|| (type && AGGREGATE_TYPE_P (type))) */ );
}


/* Define the offset between two registers, one to be eliminated, and the
   other its replacement, at the start of a routine.  */
int
m68hc11_initial_elimination_offset (from, to)
     int from;
     int to;
{
  int trap_handler;
  tree func_attr;
  int size;
  int regno;

  /* For a trap handler, we must take into account the registers which
     are pushed on the stack during the trap (except the PC).  */
  func_attr = TYPE_ATTRIBUTES (TREE_TYPE (current_function_decl));
  trap_handler = lookup_attribute ("trap", func_attr) != NULL_TREE;
  if (trap_handler && from == ARG_POINTER_REGNUM)
    size = 7;
  else
    size = 0;

  if (from == ARG_POINTER_REGNUM && to == HARD_FRAME_POINTER_REGNUM)
    {
      /* 2 is for the saved frame.
         1 is for the 'sts' correction when creating the frame.  */
      return get_frame_size () + 2 + m68hc11_sp_correction + size;
    }

  if (from == FRAME_POINTER_REGNUM && to == HARD_FRAME_POINTER_REGNUM)
    {
      return 0;
    }

  /* Push any 2 byte pseudo hard registers that we need to save.  */
  for (regno = SOFT_REG_FIRST; regno < SOFT_REG_LAST; regno++)
    {
      if (regs_ever_live[regno] && !call_used_regs[regno])
	{
	  size += 2;
	}
    }

  if (from == ARG_POINTER_REGNUM && to == HARD_SP_REGNUM)
    {
      return get_frame_size () + size;
    }

  if (from == FRAME_POINTER_REGNUM && to == HARD_SP_REGNUM)
    {
      return size - m68hc11_sp_correction;
    }
  return 0;
}

/* Initialize a variable CUM of type CUMULATIVE_ARGS
   for a call to a function whose data type is FNTYPE.
   For a library call, FNTYPE is 0.  */

void
m68hc11_init_cumulative_args (cum, fntype, libname)
     CUMULATIVE_ARGS *cum;
     tree fntype;
     rtx libname;
{
  tree ret_type;

  z_replacement_completed = 0;
  cum->words = 0;
  cum->nregs = 0;

  /* For a library call, we must find out the type of the return value.
     When the return value is bigger than 4 bytes, it is returned in
     memory.  In that case, the first argument of the library call is a
     pointer to the memory location.  Because the first argument is passed in
     register D, we have to identify this, so that the first function
     parameter is not passed in D either.  */
  if (fntype == 0)
    {
      const char *name;
      size_t len;

      if (libname == 0 || GET_CODE (libname) != SYMBOL_REF)
	return;

      /* If the library ends in 'di' or in 'df', we assume it's
         returning some DImode or some DFmode which are 64-bit wide.  */
      name = XSTR (libname, 0);
      len = strlen (name);
      if (len > 3
	  && ((name[len - 2] == 'd'
	       && (name[len - 1] == 'f' || name[len - 1] == 'i'))
	      || (name[len - 3] == 'd'
		  && (name[len - 2] == 'i' || name[len - 2] == 'f'))))
	{
	  /* We are in.  Mark the first parameter register as already used.  */
	  cum->words = 1;
	  cum->nregs = 1;
	}
      return;
    }

  ret_type = TREE_TYPE (fntype);

  if (ret_type && aggregate_value_p (ret_type))
    {
      cum->words = 1;
      cum->nregs = 1;
    }
}

/* Update the data in CUM to advance over an argument
   of mode MODE and data type TYPE.
   (TYPE is null for libcalls where that information may not be available.)  */

void
m68hc11_function_arg_advance (cum, mode, type, named)
     CUMULATIVE_ARGS *cum;
     enum machine_mode mode;
     tree type;
     int named ATTRIBUTE_UNUSED;
{
  if (mode != BLKmode)
    {
      if (cum->words == 0 && GET_MODE_SIZE (mode) == 4)
	{
	  cum->nregs = 2;
	  cum->words = GET_MODE_SIZE (mode);
	}
      else
	{
	  cum->words += GET_MODE_SIZE (mode);
	  if (cum->words <= HARD_REG_SIZE)
	    cum->nregs = 1;
	}
    }
  else
    {
      cum->words += int_size_in_bytes (type);
    }
  return;
}

/* Define where to put the arguments to a function.
   Value is zero to push the argument on the stack,
   or a hard register in which to store the argument.

   MODE is the argument's machine mode.
   TYPE is the data type of the argument (as a tree).
    This is null for libcalls where that information may
    not be available.
   CUM is a variable of type CUMULATIVE_ARGS which gives info about
    the preceding args and about the function being called.
   NAMED is nonzero if this argument is a named parameter
    (otherwise it is an extra parameter matching an ellipsis).  */

struct rtx_def *
m68hc11_function_arg (cum, mode, type, named)
     const CUMULATIVE_ARGS *cum;
     enum machine_mode mode;
     tree type ATTRIBUTE_UNUSED;
     int named ATTRIBUTE_UNUSED;
{
  if (cum->words != 0)
    {
      return NULL_RTX;
    }

  if (mode != BLKmode)
    {
      if (GET_MODE_SIZE (mode) == 2 * HARD_REG_SIZE)
	return gen_rtx (REG, mode, HARD_X_REGNUM);

      if (GET_MODE_SIZE (mode) > HARD_REG_SIZE)
	{
	  return NULL_RTX;
	}
      return gen_rtx (REG, mode, HARD_D_REGNUM);
    }
  return NULL_RTX;
}

#if GCC_VERSION > 2095

/* The "standard" implementation of va_start: just assign `nextarg' to
   the variable.  */
void
m68hc11_expand_builtin_va_start (stdarg_p, valist, nextarg)
     int stdarg_p ATTRIBUTE_UNUSED;
     tree valist;
     rtx nextarg;
{
  tree t;

  /* SCz: the default implementation in builtins.c adjust the
     nextarg using UNITS_PER_WORD.  This works only with -mshort
     and fails when integers are 32-bit.  Here is the correct way.  */
  if (!stdarg_p)
    nextarg = plus_constant (nextarg, -INT_TYPE_SIZE / 8);

  t = build (MODIFY_EXPR, TREE_TYPE (valist), valist,
	     make_tree (ptr_type_node, nextarg));
  TREE_SIDE_EFFECTS (t) = 1;

  expand_expr (t, const0_rtx, VOIDmode, EXPAND_NORMAL);
}

rtx
m68hc11_va_arg (valist, type)
     tree valist;
     tree type;
{
  tree addr_tree, t;
  HOST_WIDE_INT align;
  HOST_WIDE_INT rounded_size;
  rtx addr;
  int pad_direction;

  /* Compute the rounded size of the type.  */
  align = PARM_BOUNDARY / BITS_PER_UNIT;
  rounded_size = (((int_size_in_bytes (type) + align - 1) / align) * align);

  /* Get AP.  */
  addr_tree = valist;
  pad_direction = m68hc11_function_arg_padding (TYPE_MODE (type), type);

  if (pad_direction == downward)
    {
      /* Small args are padded downward.  */

      HOST_WIDE_INT adj;
      adj = TREE_INT_CST_LOW (TYPE_SIZE (type)) / BITS_PER_UNIT;
      if (rounded_size > align)
	adj = rounded_size;

      addr_tree = build (PLUS_EXPR, TREE_TYPE (addr_tree), addr_tree,
			 build_int_2 (rounded_size - adj, 0));
    }

  addr = expand_expr (addr_tree, NULL_RTX, Pmode, EXPAND_NORMAL);
  addr = copy_to_reg (addr);

  /* Compute new value for AP.  */
  t = build (MODIFY_EXPR, TREE_TYPE (valist), valist,
	     build (PLUS_EXPR, TREE_TYPE (valist), valist,
		    build_int_2 (rounded_size, 0)));
  TREE_SIDE_EFFECTS (t) = 1;
  expand_expr (t, const0_rtx, VOIDmode, EXPAND_NORMAL);

  return addr;
}
#endif

/* If defined, a C expression which determines whether, and in which direction,
   to pad out an argument with extra space.  The value should be of type
   `enum direction': either `upward' to pad above the argument,
   `downward' to pad below, or `none' to inhibit padding.

   Structures are stored left shifted in their argument slot.  */
int
m68hc11_function_arg_padding (mode, type)
     enum machine_mode mode;
     tree type;
{
  if (type != 0 && AGGREGATE_TYPE_P (type))
    return upward;

  /* This is the default definition.  */
  return (!BYTES_BIG_ENDIAN
	  ? upward
	  : ((mode == BLKmode
	      ? (type && TREE_CODE (TYPE_SIZE (type)) == INTEGER_CST
		 && int_size_in_bytes (type) <
		 (PARM_BOUNDARY / BITS_PER_UNIT)) : GET_MODE_BITSIZE (mode) <
	      PARM_BOUNDARY) ? downward : upward));
}


/* Function prologue and epilogue.  */

/* Emit a move after the reload pass has completed.  This is used to
   emit the prologue and epilogue.  */
static void
emit_move_after_reload (to, from, scratch)
     rtx to, from, scratch;
{
  rtx insn;

  if (TARGET_M6812 || H_REG_P (to) || H_REG_P (from))
    {
      insn = emit_move_insn (to, from);
    }
  else
    {
      emit_move_insn (scratch, from);
      insn = emit_move_insn (to, scratch);
    }

  /* Put a REG_INC note to tell the flow analysis that the instruction
     is necessary.  */
  if (IS_STACK_PUSH (to))
    {
      REG_NOTES (insn) = gen_rtx_EXPR_LIST (REG_INC,
					    XEXP (XEXP (to, 0), 0),
					    REG_NOTES (insn));
    }
  else if (IS_STACK_POP (from))
    {
      REG_NOTES (insn) = gen_rtx_EXPR_LIST (REG_INC,
					    XEXP (XEXP (from, 0), 0),
					    REG_NOTES (insn));
    }
}

int
m68hc11_total_frame_size ()
{
  int size;
  int regno;

  size = get_frame_size ();
  if (current_function_interrupt)
    {
      size += 3 * HARD_REG_SIZE;
    }
  if (frame_pointer_needed)
    size += HARD_REG_SIZE;

  for (regno = SOFT_REG_FIRST; regno <= SOFT_REG_LAST; regno++)
    if (regs_ever_live[regno] && !call_used_regs[regno])
      size += HARD_REG_SIZE;

  return size;
}

void
m68hc11_function_epilogue (out, size)
     FILE *out ATTRIBUTE_UNUSED;
     int size ATTRIBUTE_UNUSED;
{
  /* We catch the function epilogue generation to have a chance
     to clear the z_replacement_completed flag.  */
  z_replacement_completed = 0;
}

void
expand_prologue ()
{
  tree func_attr;
  int size;
  int regno;
  rtx scratch;

  if (reload_completed != 1)
    abort ();

  size = get_frame_size ();

  create_regs_rtx ();

  /* Generate specific prologue for interrupt handlers.  */
  func_attr = TYPE_ATTRIBUTES (TREE_TYPE (current_function_decl));
  current_function_interrupt = lookup_attribute ("interrupt",
						 func_attr) != NULL_TREE;
  current_function_trap = lookup_attribute ("trap", func_attr) != NULL_TREE;

  /* Get the scratch register to build the frame and push registers.
     If the first argument is a 32-bit quantity, the D+X registers
     are used.  Use Y to compute the frame.  Otherwise, X is cheaper.
     For 68HC12, this scratch register is not used.  */
  if (current_function_args_info.nregs == 2)
    scratch = iy_reg;
  else
    scratch = ix_reg;

  /* For an interrupt handler, we must preserve _.tmp, _.z and _.xy.
     Other soft registers in page0 need not to be saved because they
     will be restored by C functions.  For a trap handler, we don't
     need to preserve these registers because this is a synchronous call.  */
  if (current_function_interrupt)
    {
      emit_move_after_reload (stack_push_word, m68hc11_soft_tmp_reg, scratch);
      emit_move_after_reload (stack_push_word,
			      gen_rtx (REG, HImode, SOFT_Z_REGNUM), scratch);
      emit_move_after_reload (stack_push_word,
			      gen_rtx (REG, HImode, SOFT_SAVED_XY_REGNUM),
			      scratch);
    }

  /* Save current stack frame.  */
  if (frame_pointer_needed)
    emit_move_after_reload (stack_push_word, hard_frame_pointer_rtx, scratch);

  /* Allocate local variables.  */
  if (TARGET_M6812 && size >= 2)
    {
      emit_insn (gen_addhi3 (stack_pointer_rtx,
			     stack_pointer_rtx, GEN_INT (-size)));
    }
  else if (size > 8)
    {
      rtx insn;

      insn = gen_rtx_PARALLEL
	(VOIDmode,
	 gen_rtvec (2,
		    gen_rtx_SET (VOIDmode,
				 stack_pointer_rtx,
				 gen_rtx_PLUS (HImode,
					       stack_pointer_rtx,
					       GEN_INT (-size))),
		    gen_rtx_CLOBBER (VOIDmode, scratch)));
      emit_insn (insn);
    }
  else
    {
      int i;

      /* Allocate by pushing scratch values.  */
      for (i = 2; i <= size; i += 2)
	emit_move_after_reload (stack_push_word, ix_reg, 0);

      if (size & 1)
	emit_insn (gen_addhi3 (stack_pointer_rtx,
			       stack_pointer_rtx, GEN_INT (-1)));
    }

  /* Create the frame pointer.  */
  if (frame_pointer_needed)
    emit_move_after_reload (hard_frame_pointer_rtx,
			    stack_pointer_rtx, scratch);

  /* Push any 2 byte pseudo hard registers that we need to save.  */
  for (regno = SOFT_REG_FIRST; regno <= SOFT_REG_LAST; regno++)
    {
      if (regs_ever_live[regno] && !call_used_regs[regno])
	{
	  emit_move_after_reload (stack_push_word,
				  gen_rtx (REG, HImode, regno), scratch);
	}
    }
}

void
expand_epilogue ()
{
  int size;
  register int regno;
  int return_size;
  rtx scratch;

  if (reload_completed != 1)
    abort ();

  size = get_frame_size ();

  /* If we are returning a value in two registers, we have to preserve the
     X register and use the Y register to restore the stack and the saved
     registers.  Otherwise, use X because it's faster (and smaller).  */
  if (current_function_return_rtx == 0)
    return_size = 0;
  else if (GET_CODE (current_function_return_rtx) == MEM)
    return_size = HARD_REG_SIZE;
  else
    return_size = GET_MODE_SIZE (GET_MODE (current_function_return_rtx));

  if (return_size > HARD_REG_SIZE)
    scratch = iy_reg;
  else
    scratch = ix_reg;

  /* Pop any 2 byte pseudo hard registers that we saved.  */
  for (regno = SOFT_REG_LAST; regno >= SOFT_REG_FIRST; regno--)
    {
      if (regs_ever_live[regno] && !call_used_regs[regno])
	{
	  emit_move_after_reload (gen_rtx (REG, HImode, regno),
				  stack_pop_word, scratch);
	}
    }

  /* de-allocate auto variables */
  if (TARGET_M6812 && size >= 2)
    {
      emit_insn (gen_addhi3 (stack_pointer_rtx,
			     stack_pointer_rtx, GEN_INT (size)));
    }
  else if (size > 8)
    {
      rtx insn;

      insn = gen_rtx_PARALLEL
	(VOIDmode,
	 gen_rtvec (2,
		    gen_rtx_SET (VOIDmode,
				 stack_pointer_rtx,
				 gen_rtx_PLUS (HImode,
					       stack_pointer_rtx,
					       GEN_INT (size))),
		    gen_rtx_CLOBBER (VOIDmode, scratch)));
      emit_insn (insn);
    }
  else
    {
      int i;

      for (i = 2; i <= size; i += 2)
	emit_move_after_reload (scratch, stack_pop_word, scratch);
      if (size & 1)
	emit_insn (gen_addhi3 (stack_pointer_rtx,
			       stack_pointer_rtx, GEN_INT (1)));
    }

  /* Restore previous frame pointer.  */
  if (frame_pointer_needed)
    emit_move_after_reload (hard_frame_pointer_rtx, stack_pop_word, scratch);

  /* For an interrupt handler, restore ZTMP, ZREG and XYREG.  */
  if (current_function_interrupt)
    {
      emit_move_after_reload (gen_rtx (REG, HImode, SOFT_SAVED_XY_REGNUM),
			      stack_pop_word, scratch);
      emit_move_after_reload (gen_rtx (REG, HImode, SOFT_Z_REGNUM),
			      stack_pop_word, scratch);
      emit_move_after_reload (m68hc11_soft_tmp_reg, stack_pop_word, scratch);
    }

  /* If the trap handler returns some value, copy the value
     in D, X onto the stack so that the rti will pop the return value
     correctly.  */
  else if (current_function_trap && return_size != 0)
    {
      rtx addr_reg = stack_pointer_rtx;

      if (!TARGET_M6812)
	{
	  emit_move_after_reload (scratch, stack_pointer_rtx, 0);
	  addr_reg = scratch;
	}
      emit_move_after_reload (gen_rtx (MEM, HImode,
				       gen_rtx (PLUS, HImode, addr_reg,
						GEN_INT (1))), d_reg, 0);
      if (return_size > HARD_REG_SIZE)
	emit_move_after_reload (gen_rtx (MEM, HImode,
					 gen_rtx (PLUS, HImode, addr_reg,
						  GEN_INT (3))), ix_reg, 0);
    }

  emit_jump_insn (gen_return ());
}


/* Low and High part extraction for 68HC11.  These routines are
   similar to gen_lowpart and gen_highpart but they have been
   fixed to work for constants and 68HC11 specific registers.  */

rtx
m68hc11_gen_lowpart (mode, x)
     enum machine_mode mode;
     rtx x;
{
  /* We assume that the low part of an auto-inc mode is the same with
     the mode changed and that the caller split the larger mode in the
     correct order.  */
  if (GET_CODE (x) == MEM && m68hc11_auto_inc_p (XEXP (x, 0)))
    {
      return gen_rtx (MEM, mode, XEXP (x, 0));
    }

  /* Note that a CONST_DOUBLE rtx could represent either an integer or a
     floating-point constant.  A CONST_DOUBLE is used whenever the
     constant requires more than one word in order to be adequately
     represented.  */
  if (GET_CODE (x) == CONST_DOUBLE)
    {
      long l[2];

      if (GET_MODE_CLASS (GET_MODE (x)) == MODE_FLOAT)
	{
	  REAL_VALUE_TYPE r;

	  if (GET_MODE (x) == SFmode)
	    {
	      REAL_VALUE_FROM_CONST_DOUBLE (r, x);
	      REAL_VALUE_TO_TARGET_SINGLE (r, l[0]);
	    }
	  else
	    {
	      rtx first, second;

	      split_double (x, &first, &second);
	      return second;
	    }
	  if (mode == SImode)
	    return gen_rtx (CONST_INT, VOIDmode, l[0]);

	  return gen_rtx (CONST_INT, VOIDmode, l[0] & 0x0ffff);
	}
      else
	{
	  l[0] = CONST_DOUBLE_LOW (x);
	}
      if (mode == SImode)
	return gen_rtx (CONST_INT, VOIDmode, l[0]);
      else if (mode == HImode && GET_MODE (x) == SFmode)
	return gen_rtx (CONST_INT, VOIDmode, l[0] & 0x0FFFF);
      else
	abort ();
    }

  if (mode == QImode && D_REG_P (x))
    return gen_rtx (REG, mode, HARD_B_REGNUM);

  /* gen_lowpart crashes when it is called with a SUBREG.  */
  if (GET_CODE (x) == SUBREG && SUBREG_WORD (x) != 0)
    {
      if (mode == SImode)
	return gen_rtx_SUBREG (mode, SUBREG_REG (x), SUBREG_WORD (x) + 2);
      else if (mode == HImode)
	return gen_rtx_SUBREG (mode, SUBREG_REG (x), SUBREG_WORD (x) + 1);
      else
	abort ();
    }
  x = gen_lowpart (mode, x);

  /* Return a different rtx to avoid to share it in several insns
     (when used by a split pattern).  Sharing addresses within
     a MEM breaks the Z register replacement (and reloading).  */
  if (GET_CODE (x) == MEM)
    x = copy_rtx (x);
  return x;
}

rtx
m68hc11_gen_highpart (mode, x)
     enum machine_mode mode;
     rtx x;
{
  /* We assume that the high part of an auto-inc mode is the same with
     the mode changed and that the caller split the larger mode in the
     correct order.  */
  if (GET_CODE (x) == MEM && m68hc11_auto_inc_p (XEXP (x, 0)))
    {
      return gen_rtx (MEM, mode, XEXP (x, 0));
    }

  /* Note that a CONST_DOUBLE rtx could represent either an integer or a
     floating-point constant.  A CONST_DOUBLE is used whenever the
     constant requires more than one word in order to be adequately
     represented.  */
  if (GET_CODE (x) == CONST_DOUBLE)
    {
      long l[2];

      if (GET_MODE_CLASS (GET_MODE (x)) == MODE_FLOAT)
	{
	  REAL_VALUE_TYPE r;

	  if (GET_MODE (x) == SFmode)
	    {
	      REAL_VALUE_FROM_CONST_DOUBLE (r, x);
	      REAL_VALUE_TO_TARGET_SINGLE (r, l[1]);
	    }
	  else
	    {
	      rtx first, second;

	      split_double (x, &first, &second);
	      return first;
	    }
	  if (mode == SImode)
	    return gen_rtx (CONST_INT, VOIDmode, l[1]);

	  return gen_rtx (CONST_INT, VOIDmode, (l[1] >> 16) & 0x0ffff);
	}
      else
	{
	  l[1] = CONST_DOUBLE_HIGH (x);
	}

      if (mode == SImode)
	return gen_rtx (CONST_INT, VOIDmode, l[1]);
      else if (mode == HImode && GET_MODE_CLASS (GET_MODE (x)) == MODE_FLOAT)
	return gen_rtx (CONST_INT, VOIDmode, (l[0] >> 16) & 0x0FFFF);
      else
	abort ();
    }
  if (GET_CODE (x) == CONST_INT)
    {
      HOST_WIDE_INT val = INTVAL (x);

      if (mode == QImode)
	{
	  return gen_rtx (CONST_INT, VOIDmode, val >> 8);
	}
      else if (mode == HImode)
	{
	  return gen_rtx (CONST_INT, VOIDmode, val >> 16);
	}
    }
  if (mode == QImode && D_REG_P (x))
    return gen_rtx (REG, mode, HARD_A_REGNUM);

  /* There is no way in GCC to represent the upper part of a word register.
     To obtain the 8-bit upper part of a soft register, we change the
     reg into a mem rtx.  This is possible because they are physically
     located in memory.  There is no offset because we are big-endian.  */
  if (mode == QImode && S_REG_P (x))
    {
      int pos;

      /* For 68HC12, avoid the '*' for direct addressing mode.  */
      pos = TARGET_M6812 ? 1 : 0;
      return gen_rtx (MEM, QImode,
		      gen_rtx (SYMBOL_REF, Pmode,
			       &reg_names[REGNO (x)][pos]));
    }

  /* gen_highpart crashes when it is called with a SUBREG.  */
  if (GET_CODE (x) == SUBREG && SUBREG_WORD (x) != 0)
    {
      return gen_rtx (SUBREG, mode, XEXP (x, 0), XEXP (x, 1));
    }
  x = gen_highpart (mode, x);

  /* Return a different rtx to avoid to share it in several insns
     (when used by a split pattern).  Sharing addresses within
     a MEM breaks the Z register replacement (and reloading).  */
  if (GET_CODE (x) == MEM)
    x = copy_rtx (x);
  return x;
}


/* Obscure register manipulation.  */

/* Finds backward in the instructions to see if register 'reg' is
   dead.  This is used when generating code to see if we can use 'reg'
   as a scratch register.  This allows us to choose a better generation
   of code when we know that some register dies or can be clobbered.  */

int
dead_register_here (x, reg)
     rtx x;
     rtx reg;
{
  rtx x_reg;
  rtx p;

  if (D_REG_P (reg))
    x_reg = gen_rtx (REG, SImode, HARD_X_REGNUM);
  else
    x_reg = 0;

  for (p = PREV_INSN (x); p && GET_CODE (p) != CODE_LABEL; p = PREV_INSN (p))
    if (GET_RTX_CLASS (GET_CODE (p)) == 'i')
      {
	rtx body;

	body = PATTERN (p);

	if (GET_CODE (body) == CALL_INSN)
	  break;
	if (GET_CODE (body) == JUMP_INSN)
	  break;

	if (GET_CODE (body) == SET)
	  {
	    rtx dst = XEXP (body, 0);

	    if (GET_CODE (dst) == REG && REGNO (dst) == REGNO (reg))
	      break;
	    if (x_reg && rtx_equal_p (dst, x_reg))
	      break;

	    if (find_regno_note (p, REG_DEAD, REGNO (reg)))
	      return 1;
	  }
	else if (reg_mentioned_p (reg, p)
		 || (x_reg && reg_mentioned_p (x_reg, p)))
	  break;
      }

  /* Scan forward to see if the register is set in some insns and never
     used since then. */
  for (p = x /*NEXT_INSN (x) */ ; p; p = NEXT_INSN (p))
    {
      rtx body;

      if (GET_CODE (p) == CODE_LABEL
	  || GET_CODE (p) == JUMP_INSN
	  || GET_CODE (p) == CALL_INSN || GET_CODE (p) == BARRIER)
	break;

      if (GET_CODE (p) != INSN)
	continue;

      body = PATTERN (p);
      if (GET_CODE (body) == SET)
	{
	  rtx src = XEXP (body, 1);
	  rtx dst = XEXP (body, 0);

	  if (GET_CODE (dst) == REG
	      && REGNO (dst) == REGNO (reg) && !reg_mentioned_p (reg, src))
	    return 1;
	}

      /* Register is used (may be in source or in dest). */
      if (reg_mentioned_p (reg, p)
	  || (x_reg != 0 && GET_MODE (p) == SImode
	      && reg_mentioned_p (x_reg, p)))
	break;
    }
  return p == 0 ? 1 : 0;
}


/* Code generation operations called from machine description file.  */

/* Print the name of register 'regno' in the assembly file.  */
static void
asm_print_register (file, regno)
     FILE *file;
     int regno;
{
  const char *name = reg_names[regno];

  if (TARGET_M6812 && name[0] == '*')
    name++;

  asm_fprintf (file, "%s", name);
}

/* A C compound statement to output to stdio stream STREAM the
   assembler syntax for an instruction operand X.  X is an RTL
   expression.

   CODE is a value that can be used to specify one of several ways
   of printing the operand.  It is used when identical operands
   must be printed differently depending on the context.  CODE
   comes from the `%' specification that was used to request
   printing of the operand.  If the specification was just `%DIGIT'
   then CODE is 0; if the specification was `%LTR DIGIT' then CODE
   is the ASCII code for LTR.

   If X is a register, this macro should print the register's name.
   The names can be found in an array `reg_names' whose type is
   `char *[]'.  `reg_names' is initialized from `REGISTER_NAMES'.

   When the machine description has a specification `%PUNCT' (a `%'
   followed by a punctuation character), this macro is called with
   a null pointer for X and the punctuation character for CODE.

   The M68HC11 specific codes are:

   'b' for the low part of the operand.
   'h' for the high part of the operand
       The 'b' or 'h' modifiers have no effect if the operand has
       the QImode and is not a S_REG_P (soft register).  If the
       operand is a hard register, these two modifiers have no effect.
   't' generate the temporary scratch register.  The operand is
       ignored.
   'T' generate the low-part temporary scratch register.  The operand is
       ignored.   */

void
print_operand (file, op, letter)
     FILE *file;
     rtx op;
     int letter;
{
  if (letter == 't')
    {
      asm_print_register (file, SOFT_TMP_REGNUM);
      return;
    }
  else if (letter == 'T')
    {
      asm_print_register (file, SOFT_TMP_REGNUM);
      asm_fprintf (file, "+1");
      return;
    }
  else if (letter == '#')
    {
      asm_fprintf (file, "%0I");
    }

  if (GET_CODE (op) == REG)
    {
      if (letter == 'b' && S_REG_P (op))
	{
	  asm_print_register (file, REGNO (op));
	  asm_fprintf (file, "+1");
	}
      else
	{
	  asm_print_register (file, REGNO (op));
	}
      return;
    }

  if (GET_CODE (op) == SYMBOL_REF && (letter == 'b' || letter == 'h'))
    {
      if (letter == 'b')
	asm_fprintf (file, "%0I%%lo(");
      else
	asm_fprintf (file, "%0I%%hi(");

      output_addr_const (file, op);
      asm_fprintf (file, ")");
      return;
    }

  /* Get the low or high part of the operand when 'b' or 'h' modifiers
     are specified.  If we already have a QImode, there is nothing to do.  */
  if (GET_MODE (op) == HImode || GET_MODE (op) == VOIDmode)
    {
      if (letter == 'b')
	{
	  op = m68hc11_gen_lowpart (QImode, op);
	}
      else if (letter == 'h')
	{
	  op = m68hc11_gen_highpart (QImode, op);
	}
    }

  if (GET_CODE (op) == MEM)
    {
      rtx base = XEXP (op, 0);
      switch (GET_CODE (base))
	{
	case PRE_DEC:
	  if (TARGET_M6812)
	    {
	      asm_fprintf (file, "%u,-", GET_MODE_SIZE (GET_MODE (op)));
	      asm_print_register (file, REGNO (XEXP (base, 0)));
	    }
	  else
	    abort ();
	  break;

	case POST_DEC:
	  if (TARGET_M6812)
	    {
	      asm_fprintf (file, "%u,", GET_MODE_SIZE (GET_MODE (op)));
	      asm_print_register (file, REGNO (XEXP (base, 0)));
	      asm_fprintf (file, "-");
	    }
	  else
	    abort ();
	  break;

	case POST_INC:
	  if (TARGET_M6812)
	    {
	      asm_fprintf (file, "%u,", GET_MODE_SIZE (GET_MODE (op)));
	      asm_print_register (file, REGNO (XEXP (base, 0)));
	      asm_fprintf (file, "+");
	    }
	  else
	    abort ();
	  break;

	case PRE_INC:
	  if (TARGET_M6812)
	    {
	      asm_fprintf (file, "%u,+", GET_MODE_SIZE (GET_MODE (op)));
	      asm_print_register (file, REGNO (XEXP (base, 0)));
	    }
	  else
	    abort ();
	  break;

	default:
	  output_address (base);
	  break;
	}
    }
  else if (GET_CODE (op) == CONST_DOUBLE && GET_MODE (op) == SFmode)
    {
      REAL_VALUE_TYPE r;
      REAL_VALUE_FROM_CONST_DOUBLE (r, op);
      ASM_OUTPUT_FLOAT_OPERAND (letter, file, r);
    }
  else if (GET_CODE (op) == CONST_DOUBLE && GET_MODE (op) == XFmode)
    {
      REAL_VALUE_TYPE r;
      REAL_VALUE_FROM_CONST_DOUBLE (r, op);
      ASM_OUTPUT_LONG_DOUBLE_OPERAND (file, r);
    }
  else if (GET_CODE (op) == CONST_DOUBLE && GET_MODE (op) == DFmode)
    {
      REAL_VALUE_TYPE r;
      REAL_VALUE_FROM_CONST_DOUBLE (r, op);
      ASM_OUTPUT_DOUBLE_OPERAND (file, r);
    }
  else
    {
      if (letter != 'i')
	asm_fprintf (file, "%0I");
      output_addr_const (file, op);
    }
}

/* Returns true if the operand 'op' must be printed with parenthesis
   arround it.  This must be done only if there is a symbol whose name
   is a processor register.  */
static int
must_parenthesize (op)
     rtx op;
{
  const char *name;

  switch (GET_CODE (op))
    {
    case SYMBOL_REF:
      name = XSTR (op, 0);
      /* Avoid a conflict between symbol name and a possible
         register.  */
      return (strcasecmp (name, "a") == 0
	      || strcasecmp (name, "b") == 0
	      || strcasecmp (name, "d") == 0
	      || strcasecmp (name, "x") == 0
	      || strcasecmp (name, "y") == 0
	      || strcasecmp (name, "pc") == 0
	      || strcasecmp (name, "sp") == 0
	      || strcasecmp (name, "ccr") == 0) ? 1 : 0;

    case PLUS:
    case MINUS:
      return must_parenthesize (XEXP (op, 0))
	|| must_parenthesize (XEXP (op, 1));

    case MEM:
    case CONST:
    case ZERO_EXTEND:
    case SIGN_EXTEND:
      return must_parenthesize (XEXP (op, 0));

    case CONST_DOUBLE:
    case CONST_INT:
    case LABEL_REF:
    case CODE_LABEL:
    default:
      return 0;
    }
}

/* A C compound statement to output to stdio stream STREAM the
   assembler syntax for an instruction operand that is a memory
   reference whose address is ADDR.  ADDR is an RTL expression.  */

void
print_operand_address (file, addr)
     FILE *file;
     rtx addr;
{
  rtx base;
  rtx offset;
  int need_parenthesis = 0;

  switch (GET_CODE (addr))
    {
    case REG:
      if (!REG_P (addr) || !REG_OK_FOR_BASE_STRICT_P (addr))
	abort ();

      asm_fprintf (file, "0,");
      asm_print_register (file, REGNO (addr));
      break;

    case MEM:
      base = XEXP (addr, 0);
      switch (GET_CODE (base))
	{
	case PRE_DEC:
	  if (TARGET_M6812)
	    {
	      asm_fprintf (file, "%u,-", GET_MODE_SIZE (GET_MODE (addr)));
	      asm_print_register (file, REGNO (XEXP (base, 0)));
	    }
	  else
	    abort ();
	  break;

	case POST_DEC:
	  if (TARGET_M6812)
	    {
	      asm_fprintf (file, "%u,", GET_MODE_SIZE (GET_MODE (addr)));
	      asm_print_register (file, REGNO (XEXP (base, 0)));
	      asm_fprintf (file, "-");
	    }
	  else
	    abort ();
	  break;

	case POST_INC:
	  if (TARGET_M6812)
	    {
	      asm_fprintf (file, "%u,", GET_MODE_SIZE (GET_MODE (addr)));
	      asm_print_register (file, REGNO (XEXP (base, 0)));
	      asm_fprintf (file, "+");
	    }
	  else
	    abort ();
	  break;

	case PRE_INC:
	  if (TARGET_M6812)
	    {
	      asm_fprintf (file, "%u,+", GET_MODE_SIZE (GET_MODE (addr)));
	      asm_print_register (file, REGNO (XEXP (base, 0)));
	    }
	  else
	    abort ();
	  break;

	default:
	  need_parenthesis = must_parenthesize (base);
	  if (need_parenthesis)
	    asm_fprintf (file, "(");

	  output_addr_const (file, base);
	  if (need_parenthesis)
	    asm_fprintf (file, ")");
	  break;
	}
      break;

    case PLUS:
      base = XEXP (addr, 0);
      offset = XEXP (addr, 1);
      if (!G_REG_P (base) && G_REG_P (offset))
	{
	  base = XEXP (addr, 1);
	  offset = XEXP (addr, 0);
	}
      if ((CONSTANT_ADDRESS_P (base)) && (CONSTANT_ADDRESS_P (offset)))
	{
	  need_parenthesis = must_parenthesize (addr);

	  if (need_parenthesis)
	    asm_fprintf (file, "(");

	  output_addr_const (file, base);
	  asm_fprintf (file, "+");
	  output_addr_const (file, offset);
	  if (need_parenthesis)
	    asm_fprintf (file, ")");
	}
      else if (REG_P (base) && REG_OK_FOR_BASE_STRICT_P (base))
	{
	  if (REG_P (offset))
	    {
	      if (TARGET_M6812)
		{
		  asm_print_register (file, REGNO (offset));
		  asm_fprintf (file, ",");
		  asm_print_register (file, REGNO (base));
		}
	      else
		abort ();
	    }
	  else
	    {
	      output_addr_const (file, offset);
	      asm_fprintf (file, ",");
	      asm_print_register (file, REGNO (base));
	    }
	}
      else
	{
	  abort ();
	}
      break;

    default:
      if (GET_CODE (addr) == CONST_INT
	  && INTVAL (addr) < 0x8000 && INTVAL (addr) >= -0x8000)
	{
	  asm_fprintf (file, "%d", INTVAL (addr));
	}
      else
	{
	  need_parenthesis = must_parenthesize (addr);
	  if (need_parenthesis)
	    asm_fprintf (file, "(");

	  output_addr_const (file, addr);
	  if (need_parenthesis)
	    asm_fprintf (file, ")");
	}
      break;
    }
}


/* Splitting of some instructions.  */

static rtx
m68hc11_expand_compare (code, op0, op1)
     enum rtx_code code;
     rtx op0, op1;
{
  rtx ret = 0;

  if (GET_MODE_CLASS (GET_MODE (op0)) == MODE_FLOAT)
    abort ();
  else
    {
      emit_insn (gen_rtx_SET (VOIDmode, cc0_rtx,
			      gen_rtx_COMPARE (VOIDmode, op0, op1)));
      ret = gen_rtx (code, VOIDmode, cc0_rtx, const0_rtx);
    }

  return ret;
}

rtx
m68hc11_expand_compare_and_branch (code, op0, op1, label)
     enum rtx_code code;
     rtx op0, op1, label;
{
  rtx tmp;

  switch (GET_MODE (op0))
    {
    case QImode:
    case HImode:
      tmp = m68hc11_expand_compare (code, op0, op1);
      tmp = gen_rtx_IF_THEN_ELSE (VOIDmode, tmp,
				  gen_rtx_LABEL_REF (VOIDmode, label),
				  pc_rtx);
      emit_jump_insn (gen_rtx_SET (VOIDmode, pc_rtx, tmp));
      return 0;
#if 0

      /* SCz: from i386.c  */
    case SFmode:
    case DFmode:
      /* Don't expand the comparison early, so that we get better code
         when jump or whoever decides to reverse the comparison.  */
      {
	rtvec vec;
	int use_fcomi;

	code = m68hc11_prepare_fp_compare_args (code, &m68hc11_compare_op0,
						&m68hc11_compare_op1);

	tmp = gen_rtx_fmt_ee (code, m68hc11_fp_compare_mode (code),
			      m68hc11_compare_op0, m68hc11_compare_op1);
	tmp = gen_rtx_IF_THEN_ELSE (VOIDmode, tmp,
				    gen_rtx_LABEL_REF (VOIDmode, label),
				    pc_rtx);
	tmp = gen_rtx_SET (VOIDmode, pc_rtx, tmp);

	use_fcomi = ix86_use_fcomi_compare (code);
	vec = rtvec_alloc (3 + !use_fcomi);
	RTVEC_ELT (vec, 0) = tmp;
	RTVEC_ELT (vec, 1)
	  = gen_rtx_CLOBBER (VOIDmode, gen_rtx_REG (CCFPmode, 18));
	RTVEC_ELT (vec, 2)
	  = gen_rtx_CLOBBER (VOIDmode, gen_rtx_REG (CCFPmode, 17));
	if (!use_fcomi)
	  RTVEC_ELT (vec, 3)
	    = gen_rtx_CLOBBER (VOIDmode, gen_rtx_SCRATCH (HImode));

	emit_jump_insn (gen_rtx_PARALLEL (VOIDmode, vec));
	return;
      }
#endif

    case SImode:
      /* Expand SImode branch into multiple compare+branch.  */
      {
	rtx lo[2], hi[2], label2;
	enum rtx_code code1, code2, code3;

	if (CONSTANT_P (op0) && !CONSTANT_P (op1))
	  {
	    tmp = op0;
	    op0 = op1;
	    op1 = tmp;
	    code = swap_condition (code);
	  }
	lo[0] = m68hc11_gen_lowpart (HImode, op0);
	lo[1] = m68hc11_gen_lowpart (HImode, op1);
	hi[0] = m68hc11_gen_highpart (HImode, op0);
	hi[1] = m68hc11_gen_highpart (HImode, op1);

	/* Otherwise, if we are doing less-than, op1 is a constant and the
	   low word is zero, then we can just examine the high word.  */

	if (GET_CODE (hi[1]) == CONST_INT && lo[1] == const0_rtx
	    && (code == LT || code == LTU))
	  {
	    return m68hc11_expand_compare_and_branch (code, hi[0], hi[1],
						      label);
	  }

	/* Otherwise, we need two or three jumps.  */

	label2 = gen_label_rtx ();

	code1 = code;
	code2 = swap_condition (code);
	code3 = unsigned_condition (code);

	switch (code)
	  {
	  case LT:
	  case GT:
	  case LTU:
	  case GTU:
	    break;

	  case LE:
	    code1 = LT;
	    code2 = GT;
	    break;
	  case GE:
	    code1 = GT;
	    code2 = LT;
	    break;
	  case LEU:
	    code1 = LTU;
	    code2 = GTU;
	    break;
	  case GEU:
	    code1 = GTU;
	    code2 = LTU;
	    break;

	  case EQ:
	    code1 = NIL;
	    code2 = NE;
	    break;
	  case NE:
	    code2 = NIL;
	    break;

	  default:
	    abort ();
	  }

	/*
	 * a < b =>
	 *    if (hi(a) < hi(b)) goto true;
	 *    if (hi(a) > hi(b)) goto false;
	 *    if (lo(a) < lo(b)) goto true;
	 *  false:
	 */
	if (code1 != NIL)
	  m68hc11_expand_compare_and_branch (code1, hi[0], hi[1], label);
	if (code2 != NIL)
	  m68hc11_expand_compare_and_branch (code2, hi[0], hi[1], label2);

	m68hc11_expand_compare_and_branch (code3, lo[0], lo[1], label);

	if (code2 != NIL)
	  emit_label (label2);
	return 0;
      }

    default:
      abort ();
    }
  return 0;
}


/* Split a DI, SI or HI move into several smaller move operations.
   The scratch register 'scratch' is used as a temporary to load
   store intermediate values.  It must be a hard register.  */
void
m68hc11_split_move (to, from, scratch)
     rtx to, from, scratch;
{
  rtx low_to, low_from;
  rtx high_to, high_from;
  enum machine_mode mode;

  mode = GET_MODE (to);
  if (GET_MODE_SIZE (mode) == 8)
    mode = SImode;
  else if (GET_MODE_SIZE (mode) == 4)
    mode = HImode;
  else
    mode = QImode;

  low_to = m68hc11_gen_lowpart (mode, to);
  high_to = m68hc11_gen_highpart (mode, to);

  low_from = m68hc11_gen_lowpart (mode, from);
  if (mode == SImode && GET_CODE (from) == CONST_INT)
    {
      if (INTVAL (from) >= 0)
	high_from = const0_rtx;
      else
	high_from = constm1_rtx;
    }
  else
    high_from = m68hc11_gen_highpart (mode, from);

  if (mode == SImode)
    {
      m68hc11_split_move (low_to, low_from, scratch);
      m68hc11_split_move (high_to, high_from, scratch);
    }
  else if (H_REG_P (to) || H_REG_P (from)
	   || (TARGET_M6812
	       && (!m68hc11_register_indirect_p (from, GET_MODE (from))
		   || m68hc11_small_indexed_indirect_p (from,
							GET_MODE (from)))
	       && (!m68hc11_register_indirect_p (to, GET_MODE (to))
		   || m68hc11_small_indexed_indirect_p (to, GET_MODE (to)))))
    {
      emit_move_insn (low_to, low_from);
      emit_move_insn (high_to, high_from);
    }
  else
    {
      rtx insn;

      emit_move_insn (scratch, low_from);
      insn = emit_move_insn (low_to, scratch);

      emit_move_insn (scratch, high_from);
      insn = emit_move_insn (high_to, scratch);
    }
}

static rtx
simplify_logical (mode, code, operand, result)
     enum machine_mode mode;
     int code;
     rtx operand;
     rtx *result;
{
  int val;
  int mask;

  *result = 0;
  if (GET_CODE (operand) != CONST_INT)
    return operand;

  if (mode == HImode)
    mask = 0x0ffff;
  else
    mask = 0x0ff;

  val = INTVAL (operand);
  switch (code)
    {
    case IOR:
      if ((val & mask) == 0)
	return 0;
      if ((val & mask) == mask)
	*result = constm1_rtx;
      break;

    case AND:
      if ((val & mask) == 0)
	*result = const0_rtx;
      if ((val & mask) == mask)
	return 0;
      break;

    case XOR:
      if ((val & mask) == 0)
	return 0;
      break;
    }
  return operand;
}

static void
m68hc11_emit_logical (mode, code, operands)
     enum machine_mode mode;
     int code;
     rtx *operands;
{
  rtx result;
  int need_copy;

  need_copy = (rtx_equal_p (operands[0], operands[1])
	       || rtx_equal_p (operands[0], operands[2])) ? 0 : 1;

  operands[1] = simplify_logical (mode, code, operands[1], &result);
  operands[2] = simplify_logical (mode, code, operands[2], &result);

  if (result && GET_CODE (result) == CONST_INT)
    {
      if (!H_REG_P (operands[0]) && operands[3]
	  && (INTVAL (result) != 0 || IS_STACK_PUSH (operands[0])))
	{
	  emit_move_insn (operands[3], result);
	  emit_move_insn (operands[0], operands[3]);
	}
      else
	{
	  emit_move_insn (operands[0], result);
	}
    }
  else if (operands[1] != 0 && operands[2] != 0)
    {
      rtx insn;

      if (!H_REG_P (operands[0]) && operands[3])
	{
	  emit_move_insn (operands[3], operands[1]);
	  emit_insn (gen_rtx (SET, mode,
			      operands[3],
			      gen_rtx (code, mode,
				       operands[3], operands[2])));
	  insn = emit_move_insn (operands[0], operands[3]);
	}
      else
	{
	  insn = emit_insn (gen_rtx (SET, mode,
				     operands[0],
				     gen_rtx (code, mode,
					      operands[0], operands[2])));
	}
    }

  /* The logical operation is similar to a copy. */
  else if (need_copy)
    {
      rtx src;

      if (GET_CODE (operands[1]) == CONST_INT)
	src = operands[2];
      else
	src = operands[1];

      if (!H_REG_P (operands[0]) && !H_REG_P (src))
	{
	  emit_move_insn (operands[3], src);
	  emit_move_insn (operands[0], operands[3]);
	}
      else
	{
	  emit_move_insn (operands[0], src);
	}
    }
}

void
m68hc11_split_logical (mode, code, operands)
     enum machine_mode mode;
     int code;
     rtx *operands;
{
  rtx low[4];
  rtx high[4];

  low[0] = m68hc11_gen_lowpart (mode, operands[0]);
  low[1] = m68hc11_gen_lowpart (mode, operands[1]);
  low[2] = m68hc11_gen_lowpart (mode, operands[2]);

  high[0] = m68hc11_gen_highpart (mode, operands[0]);

  if (mode == SImode && GET_CODE (operands[1]) == CONST_INT)
    {
      if (INTVAL (operands[1]) >= 0)
	high[1] = const0_rtx;
      else
	high[1] = constm1_rtx;
    }
  else
    high[1] = m68hc11_gen_highpart (mode, operands[1]);

  if (mode == SImode && GET_CODE (operands[2]) == CONST_INT)
    {
      if (INTVAL (operands[2]) >= 0)
	high[2] = const0_rtx;
      else
	high[2] = constm1_rtx;
    }
  else
    high[2] = m68hc11_gen_highpart (mode, operands[2]);

  low[3] = operands[3];
  high[3] = operands[3];
  if (mode == SImode)
    {
      m68hc11_split_logical (HImode, code, low);
      m68hc11_split_logical (HImode, code, high);
      return;
    }

  m68hc11_emit_logical (mode, code, low);
  m68hc11_emit_logical (mode, code, high);
}


/* Code generation.  */

void
m68hc11_output_swap (insn, operands)
     rtx insn ATTRIBUTE_UNUSED;
     rtx operands[];
{
  /* We have to be careful with the cc_status.  An address register swap
     is generated for some comparison.  The comparison is made with D
     but the branch really uses the address register.  See the split
     pattern for compare.  The xgdx/xgdy preserve the flags but after
     the exchange, the flags will reflect to the value of X and not D.
     Tell this by setting the cc_status according to the cc_prev_status.  */
  if (X_REG_P (operands[1]) || X_REG_P (operands[0]))
    {
      if (cc_prev_status.value1 != 0
	  && (D_REG_P (cc_prev_status.value1)
	      || X_REG_P (cc_prev_status.value1)))
	{
	  cc_status = cc_prev_status;
	  if (D_REG_P (cc_status.value1))
	    cc_status.value1 = gen_rtx (REG, GET_MODE (cc_status.value1),
					HARD_X_REGNUM);
	  else
	    cc_status.value1 = gen_rtx (REG, GET_MODE (cc_status.value1),
					HARD_D_REGNUM);
	}
      else
	CC_STATUS_INIT;

      output_asm_insn ("xgdx", operands);
    }
  else
    {
      if (cc_prev_status.value1 != 0
	  && (D_REG_P (cc_prev_status.value1)
	      || Y_REG_P (cc_prev_status.value1)))
	{
	  cc_status = cc_prev_status;
	  if (D_REG_P (cc_status.value1))
	    cc_status.value1 = gen_rtx (REG, GET_MODE (cc_status.value1),
					HARD_Y_REGNUM);
	  else
	    cc_status.value1 = gen_rtx (REG, GET_MODE (cc_status.value1),
					HARD_D_REGNUM);
	}
      else
	CC_STATUS_INIT;

      output_asm_insn ("xgdy", operands);
    }
}

/* Returns 1 if the next insn after 'insn' is a test of the register 'reg'.
   This is used to decide whether a move that set flags should be used
   instead.  */
int
next_insn_test_reg (insn, reg)
     rtx insn;
     rtx reg;
{
  rtx body;

  insn = next_nonnote_insn (insn);
  if (GET_CODE (insn) != INSN)
    return 0;

  body = PATTERN (insn);
  if (sets_cc0_p (body) != 1)
    return 0;

  if (rtx_equal_p (XEXP (body, 1), reg) == 0)
    return 0;

  return 1;
}

/* Generate the code to move a 16-bit operand into another one.  */

void
m68hc11_gen_movhi (insn, operands)
     rtx insn;
     rtx *operands;
{
  int reg;

  /* Move a register or memory to the same location.
     This is possible because such insn can appear
     in a non-optimizing mode.  */
  if (operands[0] == operands[1] || rtx_equal_p (operands[0], operands[1]))
    {
      cc_status = cc_prev_status;
      return;
    }

  if (TARGET_M6812)
    {
      if (IS_STACK_PUSH (operands[0]) && H_REG_P (operands[1]))
	{
	  switch (REGNO (operands[1]))
	    {
	    case HARD_X_REGNUM:
	    case HARD_Y_REGNUM:
	    case HARD_D_REGNUM:
	      output_asm_insn ("psh%1", operands);
	      break;
	    default:
	      abort ();
	    }
	  return;
	}
      if (IS_STACK_POP (operands[1]) && H_REG_P (operands[0]))
	{
	  switch (REGNO (operands[0]))
	    {
	    case HARD_X_REGNUM:
	    case HARD_Y_REGNUM:
	    case HARD_D_REGNUM:
	      output_asm_insn ("pul%0", operands);
	      break;
	    default:
	      abort ();
	    }
	  return;
	}
      if (H_REG_P (operands[0]) && H_REG_P (operands[1]))
	{
	  output_asm_insn ("tfr\t%1,%0", operands);
	}
      else if (H_REG_P (operands[0]))
	{
	  if (SP_REG_P (operands[0]))
	    output_asm_insn ("lds\t%1", operands);
	  else
	    output_asm_insn ("ld%0\t%1", operands);
	}
      else if (H_REG_P (operands[1]))
	{
	  if (SP_REG_P (operands[1]))
	    output_asm_insn ("sts\t%0", operands);
	  else
	    output_asm_insn ("st%1\t%0", operands);
	}
      else
	{
	  rtx from = operands[1];
	  rtx to = operands[0];

	  if ((m68hc11_register_indirect_p (from, GET_MODE (from))
	       && !m68hc11_small_indexed_indirect_p (from, GET_MODE (from)))
	      || (m68hc11_register_indirect_p (to, GET_MODE (to))
		  && !m68hc11_small_indexed_indirect_p (to, GET_MODE (to))))
	    {
	      rtx ops[3];

	      if (operands[2])
		{
		  ops[0] = operands[2];
		  ops[1] = from;
		  ops[2] = 0;
		  m68hc11_gen_movhi (insn, ops);
		  ops[0] = to;
		  ops[1] = operands[2];
		  m68hc11_gen_movhi (insn, ops);
		}
	      else
		{
		  /* !!!! SCz wrong here.  */
		}
	    }
	  else
	    {
	      if (GET_CODE (from) == CONST_INT && INTVAL (from) == 0)
		{
		  output_asm_insn ("clr\t%h0", operands);
		  output_asm_insn ("clr\t%b0", operands);
		}
	      else
		{
		  output_asm_insn ("movw\t%1,%0", operands);
		}
	    }
	}
      return;
    }

  if (IS_STACK_POP (operands[1]) && H_REG_P (operands[0]))
    {
      switch (REGNO (operands[0]))
	{
	case HARD_X_REGNUM:
	case HARD_Y_REGNUM:
	  output_asm_insn ("pul%0", operands);
	  break;
	case HARD_D_REGNUM:
	  output_asm_insn ("pula", operands);
	  output_asm_insn ("pulb", operands);
	  break;
	default:
	  abort ();
	}
      return;
    }
  /* Some moves to a hard register are special. Not all of them
     are really supported and we have to use a temporary
     location to provide them (either the stack of a temp var). */
  if (H_REG_P (operands[0]))
    {
      switch (REGNO (operands[0]))
	{
	case HARD_D_REGNUM:
	  if (X_REG_P (operands[1]))
	    {
	      if (optimize && find_regno_note (insn, REG_DEAD, HARD_X_REGNUM))
		{
		  m68hc11_output_swap (insn, operands);
		}
	      else if (next_insn_test_reg (insn, operands[0]))
		{
		  output_asm_insn ("stx\t%t0\n\tldd\t%t0", operands);
		}
	      else
		{
		  cc_status = cc_prev_status;
		  output_asm_insn ("pshx\n\tpula\n\tpulb", operands);
		}
	    }
	  else if (Y_REG_P (operands[1]))
	    {
	      if (optimize && find_regno_note (insn, REG_DEAD, HARD_Y_REGNUM))
		{
		  m68hc11_output_swap (insn, operands);
		}
	      else
		{
		  /* %t means *ZTMP scratch register. */
		  output_asm_insn ("sty\t%t1", operands);
		  output_asm_insn ("ldd\t%t1", operands);
		}
	    }
	  else if (SP_REG_P (operands[1]))
	    {
	      CC_STATUS_INIT;
	      if (ix_reg == 0)
		create_regs_rtx ();
	      if (optimize == 0 || dead_register_here (insn, ix_reg) == 0)
		output_asm_insn ("xgdx", operands);
	      output_asm_insn ("tsx", operands);
	      output_asm_insn ("xgdx", operands);
	    }
	  else if (IS_STACK_POP (operands[1]))
	    {
	      output_asm_insn ("pula\n\tpulb", operands);
	    }
	  else if (GET_CODE (operands[1]) == CONST_INT
		   && INTVAL (operands[1]) == 0)
	    {
	      output_asm_insn ("clra\n\tclrb", operands);
	    }
	  else
	    {
	      output_asm_insn ("ldd\t%1", operands);
	    }
	  break;

	case HARD_X_REGNUM:
	  if (D_REG_P (operands[1]))
	    {
	      if (optimize && find_regno_note (insn, REG_DEAD, HARD_D_REGNUM))
		{
		  m68hc11_output_swap (insn, operands);
		}
	      else if (next_insn_test_reg (insn, operands[0]))
		{
		  output_asm_insn ("std\t%t0\n\tldx\t%t0", operands);
		}
	      else
		{
		  cc_status = cc_prev_status;
		  output_asm_insn ("pshb", operands);
		  output_asm_insn ("psha", operands);
		  output_asm_insn ("pulx", operands);
		}
	    }
	  else if (Y_REG_P (operands[1]))
	    {
	      output_asm_insn ("sty\t%t1", operands);
	      output_asm_insn ("ldx\t%t1", operands);
	    }
	  else if (SP_REG_P (operands[1]))
	    {
	      /* tsx, tsy preserve the flags */
	      cc_status = cc_prev_status;
	      output_asm_insn ("tsx", operands);
	    }
	  else
	    {
	      output_asm_insn ("ldx\t%1", operands);
	    }
	  break;

	case HARD_Y_REGNUM:
	  if (D_REG_P (operands[1]))
	    {
	      if (optimize && find_regno_note (insn, REG_DEAD, HARD_D_REGNUM))
		{
		  m68hc11_output_swap (insn, operands);
		}
	      else
		{
		  output_asm_insn ("std\t%t1", operands);
		  output_asm_insn ("ldy\t%t1", operands);
		}
	    }
	  else if (X_REG_P (operands[1]))
	    {
	      output_asm_insn ("stx\t%t1", operands);
	      output_asm_insn ("ldy\t%t1", operands);
	    }
	  else if (SP_REG_P (operands[1]))
	    {
	      /* tsx, tsy preserve the flags */
	      cc_status = cc_prev_status;
	      output_asm_insn ("tsy", operands);
	    }
	  else
	    {
	      output_asm_insn ("ldy\t%1", operands);
	    }
	  break;

	case HARD_SP_REGNUM:
	  if (D_REG_P (operands[1]))
	    {
	      cc_status = cc_prev_status;
	      output_asm_insn ("xgdx", operands);
	      output_asm_insn ("txs", operands);
	      output_asm_insn ("xgdx", operands);
	    }
	  else if (X_REG_P (operands[1]))
	    {
	      /* tys, txs preserve the flags */
	      cc_status = cc_prev_status;
	      output_asm_insn ("txs", operands);
	    }
	  else if (Y_REG_P (operands[1]))
	    {
	      /* tys, txs preserve the flags */
	      cc_status = cc_prev_status;
	      output_asm_insn ("tys", operands);
	    }
	  else
	    {
	      /* lds sets the flags but the des does not.  */
	      CC_STATUS_INIT;
	      output_asm_insn ("lds\t%1", operands);
	      output_asm_insn ("des", operands);
	    }
	  break;

	default:
	  fatal_insn ("Invalid register in the move instruction", insn);
	  break;
	}
      return;
    }
  if (SP_REG_P (operands[1]) && REG_P (operands[0])
      && REGNO (operands[0]) == HARD_FRAME_POINTER_REGNUM)
    {
      output_asm_insn ("sts\t%0", operands);
      return;
    }

  if (IS_STACK_PUSH (operands[0]) && H_REG_P (operands[1]))
    {
      switch (REGNO (operands[1]))
	{
	case HARD_X_REGNUM:
	case HARD_Y_REGNUM:
	  output_asm_insn ("psh%1", operands);
	  break;
	case HARD_D_REGNUM:
	  output_asm_insn ("pshb", operands);
	  output_asm_insn ("psha", operands);
	  break;
	default:
	  abort ();
	}
      return;
    }

  /* Operand 1 must be a hard register.  */
  if (!H_REG_P (operands[1]))
    {
      fatal_insn ("Invalid operand in the instruction", insn);
    }

  reg = REGNO (operands[1]);
  switch (reg)
    {
    case HARD_D_REGNUM:
      output_asm_insn ("std\t%0", operands);
      break;

    case HARD_X_REGNUM:
      output_asm_insn ("stx\t%0", operands);
      break;

    case HARD_Y_REGNUM:
      output_asm_insn ("sty\t%0", operands);
      break;

    case HARD_SP_REGNUM:
      if (ix_reg == 0)
	create_regs_rtx ();

      if (reg_mentioned_p (ix_reg, operands[0]))
	{
	  output_asm_insn ("sty\t%t0", operands);
	  output_asm_insn ("tsy", operands);
	  output_asm_insn ("sty\t%0", operands);
	  output_asm_insn ("ldy\t%t0", operands);
	}
      else
	{
	  output_asm_insn ("stx\t%t0", operands);
	  output_asm_insn ("tsx", operands);
	  output_asm_insn ("stx\t%0", operands);
	  output_asm_insn ("ldx\t%t0", operands);
	}
      CC_STATUS_INIT;
      break;

    default:
      fatal_insn ("Invalid register in the move instruction", insn);
      break;
    }
}

void
m68hc11_gen_movqi (insn, operands)
     rtx insn;
     rtx *operands;
{
  /* Move a register or memory to the same location.
     This is possible because such insn can appear
     in a non-optimizing mode. */
  if (operands[0] == operands[1] || rtx_equal_p (operands[0], operands[1]))
    {
      cc_status = cc_prev_status;
      return;
    }

  if (TARGET_M6812)
    {

      if (H_REG_P (operands[0]) && H_REG_P (operands[1]))
	{
	  output_asm_insn ("tfr\t%1,%0", operands);
	}
      else if (H_REG_P (operands[0]))
	{
	  if (Q_REG_P (operands[0]))
	    output_asm_insn ("lda%0\t%1", operands);
	  else if (D_REG_P (operands[0]))
	    output_asm_insn ("ldab\t%1", operands);
	  else
	    output_asm_insn ("ld%0\t%1", operands);
	}
      else if (H_REG_P (operands[1]))
	{
	  if (Q_REG_P (operands[1]))
	    output_asm_insn ("sta%1\t%0", operands);
	  else if (D_REG_P (operands[1]))
	    output_asm_insn ("staa\t%0", operands);
	  else
	    output_asm_insn ("st%1\t%0", operands);
	}
      else
	{
	  rtx from = operands[1];
	  rtx to = operands[0];

	  if ((m68hc11_register_indirect_p (from, GET_MODE (from))
	       && !m68hc11_small_indexed_indirect_p (from, GET_MODE (from)))
	      || (m68hc11_register_indirect_p (to, GET_MODE (to))
		  && !m68hc11_small_indexed_indirect_p (to, GET_MODE (to))))
	    {
	      rtx ops[3];

	      if (operands[2])
		{
		  ops[0] = operands[2];
		  ops[1] = from;
		  ops[2] = 0;
		  m68hc11_gen_movqi (insn, ops);
		  ops[0] = to;
		  ops[1] = operands[2];
		  m68hc11_gen_movqi (insn, ops);
		}
	      else
		{
		  /* !!!! SCz wrong here.  */
		}
	    }
	  else
	    {
	      if (GET_CODE (from) == CONST_INT && INTVAL (from) == 0)
		{
		  output_asm_insn ("clr\t%b0", operands);
		}
	      else
		{
		  output_asm_insn ("movb\t%1,%0", operands);
		}
	    }
	}
      return;
    }

  if (H_REG_P (operands[0]))
    {
      switch (REGNO (operands[0]))
	{
	case HARD_B_REGNUM:
	case HARD_D_REGNUM:
	  if (X_REG_P (operands[1]))
	    {
	      if (optimize && find_regno_note (insn, REG_DEAD, HARD_X_REGNUM))
		{
		  m68hc11_output_swap (insn, operands);
		}
	      else
		{
		  output_asm_insn ("stx\t%t1", operands);
		  output_asm_insn ("ldab\t%T0", operands);
		}
	    }
	  else if (Y_REG_P (operands[1]))
	    {
	      if (optimize && find_regno_note (insn, REG_DEAD, HARD_Y_REGNUM))
		{
		  m68hc11_output_swap (insn, operands);
		}
	      else
		{
		  output_asm_insn ("sty\t%t1", operands);
		  output_asm_insn ("ldab\t%T0", operands);
		}
	    }
	  else if (!DB_REG_P (operands[1]) && !D_REG_P (operands[1])
		   && !DA_REG_P (operands[1]))
	    {
	      output_asm_insn ("ldab\t%b1", operands);
	    }
	  else if (DA_REG_P (operands[1]))
	    {
	      output_asm_insn ("tab", operands);
	    }
	  else
	    {
	      cc_status = cc_prev_status;
	      return;
	    }
	  break;

	case HARD_A_REGNUM:
	  if (X_REG_P (operands[1]))
	    {
	      output_asm_insn ("stx\t%t1", operands);
	      output_asm_insn ("ldaa\t%T0", operands);
	    }
	  else if (Y_REG_P (operands[1]))
	    {
	      output_asm_insn ("sty\t%t1", operands);
	      output_asm_insn ("ldaa\t%T0", operands);
	    }
	  else if (!DB_REG_P (operands[1]) && !D_REG_P (operands[1])
		   && !DA_REG_P (operands[1]))
	    {
	      output_asm_insn ("ldaa\t%b1", operands);
	    }
	  else if (!DA_REG_P (operands[1]))
	    {
	      output_asm_insn ("tba", operands);
	    }
	  else
	    {
	      cc_status = cc_prev_status;
	    }
	  break;

	case HARD_X_REGNUM:
	  if (D_REG_P (operands[1]))
	    {
	      if (optimize && find_regno_note (insn, REG_DEAD, HARD_D_REGNUM))
		{
		  m68hc11_output_swap (insn, operands);
		}
	      else
		{
		  output_asm_insn ("stab\t%T1", operands);
		  output_asm_insn ("ldx\t%t1", operands);
		}
	      CC_STATUS_INIT;
	    }
	  else if (Y_REG_P (operands[1]))
	    {
	      output_asm_insn ("sty\t%t0", operands);
	      output_asm_insn ("ldx\t%t0", operands);
	    }
	  else if (GET_CODE (operands[1]) == CONST_INT)
	    {
	      output_asm_insn ("ldx\t%1", operands);
	    }
	  else if (dead_register_here (insn, d_reg))
	    {
	      output_asm_insn ("ldab\t%b1", operands);
	      output_asm_insn ("xgdx", operands);
	    }
	  else if (!reg_mentioned_p (operands[0], operands[1]))
	    {
	      output_asm_insn ("xgdx", operands);
	      output_asm_insn ("ldab\t%b1", operands);
	      output_asm_insn ("xgdx", operands);
	    }
	  else
	    {
	      output_asm_insn ("pshb", operands);
	      output_asm_insn ("ldab\t%b1", operands);
	      output_asm_insn ("stab\t%T1", operands);
	      output_asm_insn ("ldx\t%t1", operands);
	      output_asm_insn ("pulb", operands);
	      CC_STATUS_INIT;
	    }
	  break;

	case HARD_Y_REGNUM:
	  if (D_REG_P (operands[1]))
	    {
	      output_asm_insn ("stab\t%T1", operands);
	      output_asm_insn ("ldy\t%t1", operands);
	      CC_STATUS_INIT;
	    }
	  else if (X_REG_P (operands[1]))
	    {
	      output_asm_insn ("stx\t%t1", operands);
	      output_asm_insn ("ldy\t%t1", operands);
	      CC_STATUS_INIT;
	    }
	  else if (GET_CODE (operands[1]) == CONST_INT)
	    {
	      output_asm_insn ("ldy\t%1", operands);
	    }
	  else if (dead_register_here (insn, d_reg))
	    {
	      output_asm_insn ("ldab\t%b1", operands);
	      output_asm_insn ("xgdy", operands);
	    }
	  else if (!reg_mentioned_p (operands[0], operands[1]))
	    {
	      output_asm_insn ("xgdy", operands);
	      output_asm_insn ("ldab\t%b1", operands);
	      output_asm_insn ("xgdy", operands);
	    }
	  else
	    {
	      output_asm_insn ("pshb", operands);
	      output_asm_insn ("ldab\t%b1", operands);
	      output_asm_insn ("stab\t%T1", operands);
	      output_asm_insn ("ldy\t%t1", operands);
	      output_asm_insn ("pulb", operands);
	      CC_STATUS_INIT;
	    }
	  break;

	default:
	  fatal_insn ("Invalid register in the instruction", insn);
	  break;
	}
    }
  else if (H_REG_P (operands[1]))
    {
      switch (REGNO (operands[1]))
	{
	case HARD_D_REGNUM:
	case HARD_B_REGNUM:
	  output_asm_insn ("stab\t%b0", operands);
	  break;

	case HARD_A_REGNUM:
	  output_asm_insn ("staa\t%b0", operands);
	  break;

	case HARD_X_REGNUM:
	  output_asm_insn ("xgdx\n\tstab\t%b0\n\txgdx", operands);
	  break;

	case HARD_Y_REGNUM:
	  output_asm_insn ("xgdy\n\tstab\t%b0\n\txgdy", operands);
	  break;

	default:
	  fatal_insn ("Invalid register in the move instruction", insn);
	  break;
	}
      return;
    }
  else
    {
      fatal_insn ("Operand 1 must be a hard register", insn);
    }
}

/* Generate the code for a ROTATE or ROTATERT on a QI or HI mode.
   The source and destination must be D or A and the shift must
   be a constant.  */
void
m68hc11_gen_rotate (code, insn, operands)
     enum rtx_code code;
     rtx insn;
     rtx operands[];
{
  int val;
  
  if (GET_CODE (operands[2]) != CONST_INT
      || (!D_REG_P (operands[0]) && !DA_REG_P (operands[0])))
    fatal_insn ("Invalid rotate insn", insn);

  val = INTVAL (operands[2]);
  if (code == ROTATERT)
    val = GET_MODE_SIZE (GET_MODE (operands[0])) * BITS_PER_UNIT - val;

  if (GET_MODE (operands[0]) != QImode)
    CC_STATUS_INIT;

  /* Rotate by 8-bits if the shift is within [5..11].  */
  if (val >= 5 && val <= 11)
    {
      output_asm_insn ("psha", operands);
      output_asm_insn ("tba", operands);
      output_asm_insn ("pulb", operands);
      val -= 8;
    }

  /* If the shift is big, invert the rotation.  */
  else if (val >= 12)
    {
      val = val - 16;
    }

  if (val > 0)
    {
      /* Set the carry to bit-15, but don't change D yet.  */
      if (GET_MODE (operands[0]) != QImode)
        {
          output_asm_insn ("asra", operands);
          output_asm_insn ("rola", operands);
        }

      while (--val >= 0)
        {
          /* Rotate B first to move the carry to bit-0.  */
          if (D_REG_P (operands[0]))
            output_asm_insn ("rolb", operands);

          if (GET_MODE (operands[0]) != QImode || DA_REG_P (operands[0]))
            output_asm_insn ("rola", operands);
        }
    }
  else
    {
      /* Set the carry to bit-8 of D.  */
      if (val != 0 && GET_MODE (operands[0]) != QImode)
        {
          output_asm_insn ("tap", operands);
        }
      
      while (++val <= 0)
        {
          /* Rotate B first to move the carry to bit-7.  */
          if (D_REG_P (operands[0]))
            output_asm_insn ("rorb", operands);

          if (GET_MODE (operands[0]) != QImode || DA_REG_P (operands[0]))
            output_asm_insn ("rora", operands);
        }
    }
}



/* Store in cc_status the expressions that the condition codes will
   describe after execution of an instruction whose pattern is EXP.
   Do not alter them if the instruction would not alter the cc's.  */

void
m68hc11_notice_update_cc (exp, insn)
     rtx exp;
     rtx insn ATTRIBUTE_UNUSED;
{
  /* recognize SET insn's.  */
  if (GET_CODE (exp) == SET)
    {
      /* Jumps do not alter the cc's.  */
      if (SET_DEST (exp) == pc_rtx)
	;

      /* NOTE: most instructions don't affect the carry bit, but the
         bhi/bls/bhs/blo instructions use it.  This isn't mentioned in
         the conditions.h header.  */

      /* Function calls clobber the cc's.  */
      else if (GET_CODE (SET_SRC (exp)) == CALL)
	{
	  CC_STATUS_INIT;
	}

      /* Tests and compares set the cc's in predictable ways.  */
      else if (SET_DEST (exp) == cc0_rtx)
	{
	  cc_status.flags = 0;
	  cc_status.value1 = XEXP (exp, 0);
	  cc_status.value2 = XEXP (exp, 1);
	}
      else
	{
	  /* All other instructions affect the condition codes.  */
	  cc_status.flags = 0;
	  cc_status.value1 = XEXP (exp, 0);
	  cc_status.value2 = XEXP (exp, 1);
	}
    }
  else
    {
      /* Default action if we haven't recognized something
         and returned earlier.  */
      CC_STATUS_INIT;
    }

  if (cc_status.value2 != 0)
    switch (GET_CODE (cc_status.value2))
      {
	/* These logical operations can generate several insns.
	   The flags are setup according to what is generated.  */
      case IOR:
      case XOR:
      case AND:
	break;

	/* The (not ...) generates several 'com' instructions for
	   non QImode.  We have to invalidate the flags.  */
      case NOT:
	if (GET_MODE (cc_status.value2) != QImode)
	  CC_STATUS_INIT;
	break;

      case PLUS:
      case MINUS:
      case MULT:
      case DIV:
      case UDIV:
      case MOD:
      case UMOD:
      case NEG:
	if (GET_MODE (cc_status.value2) != VOIDmode)
	  cc_status.flags |= CC_NO_OVERFLOW;
	break;

	/* The asl sets the overflow bit in such a way that this
	   makes the flags unusable for a next compare insn.  */
      case ASHIFT:
      case ROTATE:
      case ROTATERT:
	if (GET_MODE (cc_status.value2) != VOIDmode)
	  cc_status.flags |= CC_NO_OVERFLOW;
	break;

	/* A load/store instruction does not affect the carry.  */
      case MEM:
      case SYMBOL_REF:
      case REG:
      case CONST_INT:
	cc_status.flags |= CC_NO_OVERFLOW;
	break;

      default:
	break;
      }
  if (cc_status.value1 && GET_CODE (cc_status.value1) == REG
      && cc_status.value2
      && reg_overlap_mentioned_p (cc_status.value1, cc_status.value2))
    cc_status.value2 = 0;
}


/* Machine Specific Reorg. */

/* Z register replacement:

   GCC treats the Z register as an index base address register like
   X or Y.  In general, it uses it during reload to compute the address
   of some operand.  This helps the reload pass to avoid to fall into the
   register spill failure.

   The Z register is in the A_REGS class.  In the machine description,
   the 'A' constraint matches it.  The 'x' or 'y' constraints do not.

   It can appear everywhere an X or Y register can appear, except for
   some templates in the clobber section (when a clobber of X or Y is asked).
   For a given instruction, the template must ensure that no more than
   2 'A' registers are used.  Otherwise, the register replacement is not
   possible.

   To replace the Z register, the algorithm is not terrific:
   1. Insns that do not use the Z register are not changed
   2. When a Z register is used, we scan forward the insns to see
   a potential register to use: either X or Y and sometimes D.
   We stop when a call, a label or a branch is seen, or when we
   detect that both X and Y are used (probably at different times, but it does
   not matter).
   3. The register that will be used for the replacement of Z is saved
   in a .page0 register or on the stack.  If the first instruction that
   used Z, uses Z as an input, the value is loaded from another .page0
   register.  The replacement register is pushed on the stack in the
   rare cases where a compare insn uses Z and we couldn't find if X/Y
   are dead.
   4. The Z register is replaced in all instructions until we reach
   the end of the Z-block, as detected by step 2.
   5. If we detect that Z is still alive, its value is saved.
   If the replacement register is alive, its old value is loaded.

   The Z register can be disabled with -ffixed-z.
*/

struct replace_info
{
  rtx first;
  rtx replace_reg;
  int need_save_z;
  int must_load_z;
  int must_save_reg;
  int must_restore_reg;
  rtx last;
  int regno;
  int x_used;
  int y_used;
  int can_use_d;
  int found_call;
  int z_died;
  int z_set_count;
  rtx z_value;
  int must_push_reg;
  int save_before_last;
  int z_loaded_with_sp;
};

static rtx z_reg_qi;

static int m68hc11_check_z_replacement PARAMS ((rtx, struct replace_info *));
static void m68hc11_find_z_replacement PARAMS ((rtx, struct replace_info *));
static void m68hc11_z_replacement PARAMS ((rtx));
static void m68hc11_reassign_regs PARAMS ((rtx));

int z_replacement_completed = 0;

/* Analyze the insn to find out which replacement register to use and
   the boundaries of the replacement.
   Returns 0 if we reached the last insn to be replaced, 1 if we can
   continue replacement in next insns. */

static int
m68hc11_check_z_replacement (insn, info)
     rtx insn;
     struct replace_info *info;
{
  int this_insn_uses_ix;
  int this_insn_uses_iy;
  int this_insn_uses_z;
  int this_insn_uses_d;
  rtx body;
  int z_dies_here;

  /* A call is said to clobber the Z register, we don't need
     to save the value of Z.  We also don't need to restore
     the replacement register (unless it is used by the call).  */
  if (GET_CODE (insn) == CALL_INSN)
    {
      body = PATTERN (insn);

      info->can_use_d = 0;

      /* If the call is an indirect call with Z, we have to use the
         Y register because X can be used as an input (D+X).
         We also must not save Z nor restore Y.  */
      if (reg_mentioned_p (z_reg, body))
	{
	  insn = NEXT_INSN (insn);
	  info->x_used = 1;
	  info->y_used = 0;
	  info->found_call = 1;
	  info->must_restore_reg = 0;
	  info->last = NEXT_INSN (insn);
	}
      info->need_save_z = 0;
      return 0;
    }
  if (GET_CODE (insn) == CODE_LABEL
      || GET_CODE (insn) == BARRIER || GET_CODE (insn) == ASM_INPUT)
    return 0;

  if (GET_CODE (insn) == JUMP_INSN)
    {
      if (reg_mentioned_p (z_reg, insn) == 0)
	return 0;

      info->can_use_d = 0;
      info->must_save_reg = 0;
      info->must_restore_reg = 0;
      info->need_save_z = 0;
      info->last = NEXT_INSN (insn);
      return 0;
    }
  if (GET_CODE (insn) != INSN && GET_CODE (insn) != JUMP_INSN)
    {
      return 1;
    }

  /* Z register dies here.  */
  z_dies_here = find_regno_note (insn, REG_DEAD, HARD_Z_REGNUM) != NULL;

  body = PATTERN (insn);
  if (GET_CODE (body) == SET)
    {
      rtx src = XEXP (body, 1);
      rtx dst = XEXP (body, 0);

      /* Condition code is set here. We have to restore the X/Y and
         save into Z before any test/compare insn because once we save/restore
         we can change the condition codes. When the compare insn uses Z and
         we can't use X/Y, the comparison is made with the *ZREG soft register
         (this is supported by cmphi, cmpqi, tsthi, tstqi patterns).  */
      if (dst == cc0_rtx)
	{
	  if ((GET_CODE (src) == REG && REGNO (src) == HARD_Z_REGNUM)
	      || (GET_CODE (src) == COMPARE &&
		  (rtx_equal_p (XEXP (src, 0), z_reg)
		   || rtx_equal_p (XEXP (src, 1), z_reg))))
	    {
	      if (insn == info->first)
		{
		  info->must_load_z = 0;
		  info->must_save_reg = 0;
		  info->must_restore_reg = 0;
		  info->need_save_z = 0;
		  info->found_call = 1;
		  info->regno = SOFT_Z_REGNUM;
		  info->last = insn;
		}
	      return 0;
	    }
	  if (reg_mentioned_p (z_reg, src) == 0)
	    {
	      info->can_use_d = 0;
	      return 0;
	    }

	  if (insn != info->first)
	    return 0;

	  /* Compare insn which uses Z.  We have to save/restore the X/Y
	     register without modifying the condition codes.  For this
	     we have to use a push/pop insn.  */
	  info->must_push_reg = 1;
	  info->last = insn;
	}

      /* Z reg is set to something new. We don't need to load it.  */
      if (Z_REG_P (dst))
	{
	  if (!reg_mentioned_p (z_reg, src))
	    {
	      if (insn == info->first)
		{
		  info->must_load_z = 0;
		}
	    }
	  info->z_set_count++;
	  info->z_value = src;
	  if (SP_REG_P (src))
	    info->z_loaded_with_sp = 1;
	}
      else if (reg_mentioned_p (z_reg, dst))
	info->can_use_d = 0;

      this_insn_uses_d = reg_mentioned_p (d_reg, src)
	| reg_mentioned_p (d_reg, dst);
      this_insn_uses_ix = reg_mentioned_p (ix_reg, src)
	| reg_mentioned_p (ix_reg, dst);
      this_insn_uses_iy = reg_mentioned_p (iy_reg, src)
	| reg_mentioned_p (iy_reg, dst);
      this_insn_uses_z = reg_mentioned_p (z_reg, src);

      /* If z is used as an address operand (like (MEM (reg z))),
         we can't replace it with d.  */
      if (this_insn_uses_z && !Z_REG_P (src))
	info->can_use_d = 0;
      this_insn_uses_z |= reg_mentioned_p (z_reg, dst);

      if (this_insn_uses_z && this_insn_uses_ix && this_insn_uses_iy)
	{
	  fatal_insn ("Registers IX, IY and Z used in the same INSN", insn);
	}

      if (this_insn_uses_d)
	info->can_use_d = 0;

      /* IX and IY are used at the same time, we have to restore
         the value of the scratch register before this insn.  */
      if (this_insn_uses_ix && this_insn_uses_iy)
	{
	  return 0;
	}

      if (info->x_used == 0 && this_insn_uses_ix)
	{
	  if (info->y_used)
	    {
	      /* We have a (set (REG:HI X) (REG:HI Z)).
	         Since we use Z as the replacement register, this insn
	         is no longer necessary.  We turn it into a note.  We must
	         not reload the old value of X.  */
	      if (X_REG_P (dst) && rtx_equal_p (src, z_reg))
		{
		  if (z_dies_here)
		    {
		      info->need_save_z = 0;
		      info->z_died = 1;
		    }
		  info->must_save_reg = 0;
		  info->must_restore_reg = 0;
		  info->found_call = 1;
		  info->can_use_d = 0;
		  PUT_CODE (insn, NOTE);
		  NOTE_LINE_NUMBER (insn) = NOTE_INSN_DELETED;
		  NOTE_SOURCE_FILE (insn) = 0;
		  info->last = NEXT_INSN (insn);
		  return 0;
		}

	      if (X_REG_P (dst)
		  && (rtx_equal_p (src, z_reg)
		      || (z_dies_here && !reg_mentioned_p (ix_reg, src))))
		{
		  if (z_dies_here)
		    {
		      info->need_save_z = 0;
		      info->z_died = 1;
		    }
		  info->last = NEXT_INSN (insn);
		  info->must_save_reg = 0;
		  info->must_restore_reg = 0;
		}
	      else if (X_REG_P (dst) && reg_mentioned_p (z_reg, src)
		       && !reg_mentioned_p (ix_reg, src))
		{
		  if (z_dies_here)
		    {
		      info->z_died = 1;
		      info->need_save_z = 0;
		    }
		  else
		    {
		      info->save_before_last = 1;
		    }
		  info->must_restore_reg = 0;
		  info->last = NEXT_INSN (insn);
		}
	      else if (info->can_use_d)
		{
		  info->last = NEXT_INSN (insn);
		  info->x_used = 1;
		}
	      return 0;
	    }
	  info->x_used = 1;
	  if (z_dies_here && !reg_mentioned_p (src, ix_reg)
	      && GET_CODE (src) == REG && REGNO (src) == HARD_X_REGNUM)
	    {
	      info->need_save_z = 0;
	      info->z_died = 1;
	      info->last = NEXT_INSN (insn);
	      info->regno = HARD_X_REGNUM;
	      info->must_save_reg = 0;
	      info->must_restore_reg = 0;
	      return 0;
	    }
	}
      if (info->y_used == 0 && this_insn_uses_iy)
	{
	  if (info->x_used)
	    {
	      if (Y_REG_P (dst) && rtx_equal_p (src, z_reg))
		{
		  if (z_dies_here)
		    {
		      info->need_save_z = 0;
		      info->z_died = 1;
		    }
		  info->must_save_reg = 0;
		  info->must_restore_reg = 0;
		  info->found_call = 1;
		  info->can_use_d = 0;
		  PUT_CODE (insn, NOTE);
		  NOTE_LINE_NUMBER (insn) = NOTE_INSN_DELETED;
		  NOTE_SOURCE_FILE (insn) = 0;
		  info->last = NEXT_INSN (insn);
		  return 0;
		}

	      if (Y_REG_P (dst)
		  && (rtx_equal_p (src, z_reg)
		      || (z_dies_here && !reg_mentioned_p (iy_reg, src))))
		{
		  if (z_dies_here)
		    {
		      info->z_died = 1;
		      info->need_save_z = 0;
		    }
		  info->last = NEXT_INSN (insn);
		  info->must_save_reg = 0;
		  info->must_restore_reg = 0;
		}
	      else if (Y_REG_P (dst) && reg_mentioned_p (z_reg, src)
		       && !reg_mentioned_p (iy_reg, src))
		{
		  if (z_dies_here)
		    {
		      info->z_died = 1;
		      info->need_save_z = 0;
		    }
		  else
		    {
		      info->save_before_last = 1;
		    }
		  info->must_restore_reg = 0;
		  info->last = NEXT_INSN (insn);
		}
	      else if (info->can_use_d)
		{
		  info->last = NEXT_INSN (insn);
		  info->y_used = 1;
		}

	      return 0;
	    }
	  info->y_used = 1;
	  if (z_dies_here && !reg_mentioned_p (src, iy_reg)
	      && GET_CODE (src) == REG && REGNO (src) == HARD_Y_REGNUM)
	    {
	      info->need_save_z = 0;
	      info->z_died = 1;
	      info->last = NEXT_INSN (insn);
	      info->regno = HARD_Y_REGNUM;
	      info->must_save_reg = 0;
	      info->must_restore_reg = 0;
	      return 0;
	    }
	}
      if (z_dies_here)
	{
	  info->need_save_z = 0;
	  info->z_died = 1;
	  if (info->last == 0)
	    info->last = NEXT_INSN (insn);
	  return 0;
	}
      return info->last != NULL_RTX ? 0 : 1;
    }
  if (GET_CODE (body) == PARALLEL)
    {
      int i;
      char ix_clobber = 0;
      char iy_clobber = 0;
      char z_clobber = 0;
      this_insn_uses_iy = 0;
      this_insn_uses_ix = 0;
      this_insn_uses_z = 0;

      for (i = XVECLEN (body, 0) - 1; i >= 0; i--)
	{
	  rtx x;
	  int uses_ix, uses_iy, uses_z;

	  x = XVECEXP (body, 0, i);

	  if (info->can_use_d && reg_mentioned_p (d_reg, x))
	    info->can_use_d = 0;

	  uses_ix = reg_mentioned_p (ix_reg, x);
	  uses_iy = reg_mentioned_p (iy_reg, x);
	  uses_z = reg_mentioned_p (z_reg, x);
	  if (GET_CODE (x) == CLOBBER)
	    {
	      ix_clobber |= uses_ix;
	      iy_clobber |= uses_iy;
	      z_clobber |= uses_z;
	    }
	  else
	    {
	      this_insn_uses_ix |= uses_ix;
	      this_insn_uses_iy |= uses_iy;
	      this_insn_uses_z |= uses_z;
	    }
	  if (uses_z && GET_CODE (x) == SET)
	    {
	      rtx dst = XEXP (x, 0);

	      if (Z_REG_P (dst))
		info->z_set_count++;
	    }
	  if (z_clobber)
	    info->need_save_z = 0;
	}
      if (debug_m6811)
	{
	  printf ("Uses X:%d Y:%d Z:%d CX:%d CY:%d CZ:%d\n",
		  this_insn_uses_ix, this_insn_uses_iy,
		  this_insn_uses_z, ix_clobber, iy_clobber, z_clobber);
	  debug_rtx (insn);
	}
      if (this_insn_uses_z)
	info->can_use_d = 0;

      if (z_clobber && info->first != insn)
	{
	  info->need_save_z = 0;
	  info->last = insn;
	  return 0;
	}
      if (z_clobber && info->x_used == 0 && info->y_used == 0)
	{
	  if (this_insn_uses_z == 0 && insn == info->first)
	    {
	      info->must_load_z = 0;
	    }
	  if (dead_register_here (insn, d_reg))
	    {
	      info->regno = HARD_D_REGNUM;
	      info->must_save_reg = 0;
	      info->must_restore_reg = 0;
	    }
	  else if (dead_register_here (insn, ix_reg))
	    {
	      info->regno = HARD_X_REGNUM;
	      info->must_save_reg = 0;
	      info->must_restore_reg = 0;
	    }
	  else if (dead_register_here (insn, iy_reg))
	    {
	      info->regno = HARD_Y_REGNUM;
	      info->must_save_reg = 0;
	      info->must_restore_reg = 0;
	    }
	  if (info->regno >= 0)
	    {
	      info->last = NEXT_INSN (insn);
	      return 0;
	    }
	  if (this_insn_uses_ix == 0)
	    {
	      info->regno = HARD_X_REGNUM;
	      info->must_save_reg = 1;
	      info->must_restore_reg = 1;
	    }
	  else if (this_insn_uses_iy == 0)
	    {
	      info->regno = HARD_Y_REGNUM;
	      info->must_save_reg = 1;
	      info->must_restore_reg = 1;
	    }
	  else
	    {
	      info->regno = HARD_D_REGNUM;
	      info->must_save_reg = 1;
	      info->must_restore_reg = 1;
	    }
	  info->last = NEXT_INSN (insn);
	  return 0;
	}

      if (((info->x_used || this_insn_uses_ix) && iy_clobber)
	  || ((info->y_used || this_insn_uses_iy) && ix_clobber))
	{
	  if (this_insn_uses_z)
	    {
	      if (info->y_used == 0 && iy_clobber)
		{
		  info->regno = HARD_Y_REGNUM;
		  info->must_save_reg = 0;
		  info->must_restore_reg = 0;
		}
	      info->last = NEXT_INSN (insn);
	      info->save_before_last = 1;
	    }
	  return 0;
	}
      if (this_insn_uses_ix && this_insn_uses_iy)
	{
          if (this_insn_uses_z)
            {
              fatal_insn ("Cannot do z-register replacement", insn);
            }
	  return 0;
	}
      if (info->x_used == 0 && (this_insn_uses_ix || ix_clobber))
	{
	  if (info->y_used)
	    {
	      return 0;
	    }
	  info->x_used = 1;
	  if (iy_clobber || z_clobber)
	    {
	      info->last = NEXT_INSN (insn);
	      info->save_before_last = 1;
	      return 0;
	    }
	}

      if (info->y_used == 0 && (this_insn_uses_iy || iy_clobber))
	{
	  if (info->x_used)
	    {
	      return 0;
	    }
	  info->y_used = 1;
	  if (ix_clobber || z_clobber)
	    {
	      info->last = NEXT_INSN (insn);
	      info->save_before_last = 1;
	      return 0;
	    }
	}
      if (z_dies_here)
	{
	  info->z_died = 1;
	  info->need_save_z = 0;
	}
      return 1;
    }
  if (GET_CODE (body) == CLOBBER)
    {

      /* IX and IY are used at the same time, we have to restore
         the value of the scratch register before this insn.  */
      if (this_insn_uses_ix && this_insn_uses_iy)
	{
	  return 0;
	}
      if (info->x_used == 0 && this_insn_uses_ix)
	{
	  if (info->y_used)
	    {
	      return 0;
	    }
	  info->x_used = 1;
	}
      if (info->y_used == 0 && this_insn_uses_iy)
	{
	  if (info->x_used)
	    {
	      return 0;
	    }
	  info->y_used = 1;
	}
      return 1;
    }
  return 1;
}

static void
m68hc11_find_z_replacement (insn, info)
     rtx insn;
     struct replace_info *info;
{
  int reg;

  info->replace_reg = NULL_RTX;
  info->must_load_z = 1;
  info->need_save_z = 1;
  info->must_save_reg = 1;
  info->must_restore_reg = 1;
  info->first = insn;
  info->x_used = 0;
  info->y_used = 0;
  info->can_use_d = TARGET_M6811 ? 1 : 0;
  info->found_call = 0;
  info->z_died = 0;
  info->last = 0;
  info->regno = -1;
  info->z_set_count = 0;
  info->z_value = NULL_RTX;
  info->must_push_reg = 0;
  info->save_before_last = 0;
  info->z_loaded_with_sp = 0;

  /* Scan the insn forward to find an address register that is not used.
     Stop when:
     - the flow of the program changes,
     - when we detect that both X and Y are necessary,
     - when the Z register dies,
     - when the condition codes are set.  */

  for (; insn && info->z_died == 0; insn = NEXT_INSN (insn))
    {
      if (m68hc11_check_z_replacement (insn, info) == 0)
	break;
    }

  /* May be we can use Y or X if they contain the same value as Z.
     This happens very often after the reload.  */
  if (info->z_set_count == 1)
    {
      rtx p = info->first;
      rtx v = 0;

      if (info->x_used)
	{
	  v = find_last_value (iy_reg, &p, insn, 1);
	}
      else if (info->y_used)
	{
	  v = find_last_value (ix_reg, &p, insn, 1);
	}
      if (v && (v != iy_reg && v != ix_reg) && rtx_equal_p (v, info->z_value))
	{
	  if (info->x_used)
	    info->regno = HARD_Y_REGNUM;
	  else
	    info->regno = HARD_X_REGNUM;
	  info->must_load_z = 0;
	  info->must_save_reg = 0;
	  info->must_restore_reg = 0;
	  info->found_call = 1;
	}
    }
  if (info->z_set_count == 0)
    info->need_save_z = 0;

  if (insn == 0)
    info->need_save_z = 0;

  if (info->last == 0)
    info->last = insn;

  if (info->regno >= 0)
    {
      reg = info->regno;
      info->replace_reg = gen_rtx (REG, HImode, reg);
    }
  else if (info->can_use_d)
    {
      reg = HARD_D_REGNUM;
      info->replace_reg = d_reg;
    }
  else if (info->x_used)
    {
      reg = HARD_Y_REGNUM;
      info->replace_reg = iy_reg;
    }
  else
    {
      reg = HARD_X_REGNUM;
      info->replace_reg = ix_reg;
    }
  info->regno = reg;

  if (info->must_save_reg && info->must_restore_reg)
    {
      if (insn && dead_register_here (insn, info->replace_reg))
	{
	  info->must_save_reg = 0;
	  info->must_restore_reg = 0;
	}
    }
}

/* The insn uses the Z register.  Find a replacement register for it
   (either X or Y) and replace it in the insn and the next ones until
   the flow changes or the replacement register is used.  Instructions
   are emited before and after the Z-block to preserve the value of
   Z and of the replacement register.  */

static void
m68hc11_z_replacement (insn)
     rtx insn;
{
  rtx replace_reg_qi;
  rtx replace_reg;
  struct replace_info info;

  /* Find trivial case where we only need to replace z with the
     equivalent soft register.  */
  if (GET_CODE (insn) == INSN && GET_CODE (PATTERN (insn)) == SET)
    {
      rtx body = PATTERN (insn);
      rtx src = XEXP (body, 1);
      rtx dst = XEXP (body, 0);

      if (Z_REG_P (dst) && (H_REG_P (src) && !SP_REG_P (src)))
	{
	  XEXP (body, 0) = gen_rtx (REG, GET_MODE (dst), SOFT_Z_REGNUM);
	  return;
	}
      else if (Z_REG_P (src)
	       && ((H_REG_P (dst) && !SP_REG_P (src)) || dst == cc0_rtx))
	{
	  XEXP (body, 1) = gen_rtx (REG, GET_MODE (src), SOFT_Z_REGNUM);
	  return;
	}
      else if (D_REG_P (dst)
	       && m68hc11_arith_operator (src, GET_MODE (src))
	       && D_REG_P (XEXP (src, 0)) && Z_REG_P (XEXP (src, 1)))
	{
	  XEXP (src, 1) = gen_rtx (REG, GET_MODE (src), SOFT_Z_REGNUM);
	  return;
	}
      else if (Z_REG_P (dst) && GET_CODE (src) == CONST_INT
	       && INTVAL (src) == 0)
	{
	  XEXP (body, 0) = gen_rtx (REG, GET_MODE (dst), SOFT_Z_REGNUM);
	  return;
	}
    }

  m68hc11_find_z_replacement (insn, &info);

  replace_reg = info.replace_reg;
  replace_reg_qi = NULL_RTX;

  /* Save the X register in a .page0 location.  */
  if (info.must_save_reg && !info.must_push_reg)
    {
      rtx dst;

      if (info.must_push_reg && 0)
	dst = gen_rtx (MEM, HImode,
		       gen_rtx (PRE_DEC, HImode,
				gen_rtx (REG, HImode, HARD_SP_REGNUM)));
      else
	dst = gen_rtx (REG, HImode, SOFT_SAVED_XY_REGNUM);

      emit_insn_before (gen_movhi (dst,
				   gen_rtx (REG, HImode, info.regno)), insn);
    }
  if (info.must_load_z && !info.must_push_reg)
    {
      emit_insn_before (gen_movhi (gen_rtx (REG, HImode, info.regno),
				   gen_rtx (REG, HImode, SOFT_Z_REGNUM)),
			insn);
    }


  /* Replace all occurence of Z by replace_reg.
     Stop when the last instruction to replace is reached.
     Also stop when we detect a change in the flow (but it's not
     necessary; just safeguard).  */

  for (; insn && insn != info.last; insn = NEXT_INSN (insn))
    {
      rtx body;

      if (GET_CODE (insn) == CODE_LABEL || GET_CODE (insn) == BARRIER)
	break;

      if (GET_CODE (insn) != INSN
	  && GET_CODE (insn) != CALL_INSN && GET_CODE (insn) != JUMP_INSN)
	continue;

      body = PATTERN (insn);
      if (GET_CODE (body) == SET || GET_CODE (body) == PARALLEL
	  || GET_CODE (insn) == CALL_INSN || GET_CODE (insn) == JUMP_INSN)
	{
	  if (debug_m6811 && reg_mentioned_p (replace_reg, body))
	    {
	      printf ("Reg mentioned here...:\n");
	      fflush (stdout);
	      debug_rtx (insn);
	    }

	  /* Stack pointer was decremented by 2 due to the push.
	     Correct that by adding 2 to the destination.  */
	  if (info.must_push_reg
	      && info.z_loaded_with_sp && GET_CODE (body) == SET)
	    {
	      rtx src, dst;

	      src = SET_SRC (body);
	      dst = SET_DEST (body);
	      if (SP_REG_P (src) && Z_REG_P (dst))
		{
		  emit_insn_after (gen_addhi3 (dst,
					       dst,
					       gen_rtx (CONST_INT,
							VOIDmode, 2)), insn);
		}
	    }

	  /* Replace any (REG:HI Z) occurrence by either X or Y.  */
	  if (!validate_replace_rtx (z_reg, replace_reg, insn))
	    {
	      INSN_CODE (insn) = -1;
	      if (!validate_replace_rtx (z_reg, replace_reg, insn))
		fatal_insn ("Cannot do z-register replacement", insn);
	    }

	  /* Likewise for (REG:QI Z). */
	  if (reg_mentioned_p (z_reg, insn))
	    {
	      if (replace_reg_qi == NULL_RTX)
		replace_reg_qi = gen_rtx (REG, QImode, REGNO (replace_reg));
	      validate_replace_rtx (z_reg_qi, replace_reg_qi, insn);
	    }
	}
      if (GET_CODE (insn) == CALL_INSN || GET_CODE (insn) == JUMP_INSN)
	break;
    }

  /* Save Z before restoring the old value.  */
  if (insn && info.need_save_z && !info.must_push_reg)
    {
      rtx save_pos_insn = insn;

      /* If Z is clobber by the last insn, we have to save its value
         before the last instruction.  */
      if (info.save_before_last)
	save_pos_insn = PREV_INSN (save_pos_insn);

      emit_insn_before (gen_movhi (gen_rtx (REG, HImode, SOFT_Z_REGNUM),
				   gen_rtx (REG, HImode, info.regno)),
			save_pos_insn);
    }

  if (info.must_push_reg && info.last)
    {
      rtx new_body, body;

      body = PATTERN (info.last);
      new_body = gen_rtx (PARALLEL, VOIDmode,
			  gen_rtvec (3, body,
				     gen_rtx (USE, VOIDmode,
					      replace_reg),
				     gen_rtx (USE, VOIDmode,
					      gen_rtx (REG, HImode,
						       SOFT_Z_REGNUM))));
      PATTERN (info.last) = new_body;

      /* Force recognition on insn since we changed it.  */
      INSN_CODE (insn) = -1;

      if (!validate_replace_rtx (z_reg, replace_reg, info.last))
	{
	  fatal_insn ("Invalid Z register replacement for insn", insn);
	}
      insn = NEXT_INSN (info.last);
    }

  /* Restore replacement register unless it was died.  */
  if (insn && info.must_restore_reg && !info.must_push_reg)
    {
      rtx dst;

      if (info.must_push_reg && 0)
	dst = gen_rtx (MEM, HImode,
		       gen_rtx (POST_INC, HImode,
				gen_rtx (REG, HImode, HARD_SP_REGNUM)));
      else
	dst = gen_rtx (REG, HImode, SOFT_SAVED_XY_REGNUM);

      emit_insn_before (gen_movhi (gen_rtx (REG, HImode, info.regno),
				   dst), insn);
    }

}


/* Scan all the insn and re-affects some registers
    - The Z register (if it was used), is affected to X or Y depending
      on the instruction.  */

static void
m68hc11_reassign_regs (first)
     rtx first;
{
  rtx insn;

  ix_reg = gen_rtx (REG, HImode, HARD_X_REGNUM);
  iy_reg = gen_rtx (REG, HImode, HARD_Y_REGNUM);
  z_reg = gen_rtx (REG, HImode, HARD_Z_REGNUM);
  z_reg_qi = gen_rtx (REG, QImode, HARD_Z_REGNUM);

  /* Scan all insns to replace Z by X or Y preserving the old value
     of X/Y and restoring it afterward.  */

  for (insn = first; insn; insn = NEXT_INSN (insn))
    {
      rtx body;

      if (GET_CODE (insn) == CODE_LABEL
	  || GET_CODE (insn) == NOTE || GET_CODE (insn) == BARRIER)
	continue;

      if (GET_RTX_CLASS (GET_CODE (insn)) != 'i')
	continue;

      body = PATTERN (insn);
      if (GET_CODE (body) == CLOBBER || GET_CODE (body) == USE)
	continue;

      if (GET_CODE (body) == CONST_INT || GET_CODE (body) == ASM_INPUT
	  || GET_CODE (body) == ASM_OPERANDS
	  || GET_CODE (body) == UNSPEC || GET_CODE (body) == UNSPEC_VOLATILE)
	continue;

      if (GET_CODE (body) == SET || GET_CODE (body) == PARALLEL
	  || GET_CODE (insn) == CALL_INSN || GET_CODE (insn) == JUMP_INSN)
	{

	  /* If Z appears in this insn, replace it in the current insn
	     and the next ones until the flow changes or we have to
	     restore back the replacement register.  */

	  if (reg_mentioned_p (z_reg, body))
	    {
	      m68hc11_z_replacement (insn);
	    }
	}
      else
	{
	  printf ("Insn not handled by Z replacement:\n");
	  fflush (stdout);
	  debug_rtx (insn);
	}
    }
}

#if GCC_VERSION == 2095
/* Split all insns in the function.  If UPD_LIFE, update life info after.  */

static int
m68hc11_split_all_insns (first)
     rtx first;
{
  rtx insn;
  int split_done = 0;

  for (insn = first; insn; insn = NEXT_INSN (insn))
    {
      rtx last;

      if (INSN_DELETED_P (insn))
	continue;
      if (GET_RTX_CLASS (GET_CODE (insn)) != 'i')
	continue;

      last = try_split (PATTERN (insn), insn, 1);

      /* When not optimizing, the old insn will be still left around
         with only the 'deleted' bit set.  Transform it into a note
         to avoid confusion of subsequent processing.  */
      if (INSN_DELETED_P (insn))
	{
	  PUT_CODE (insn, NOTE);
	  NOTE_LINE_NUMBER (insn) = NOTE_INSN_DELETED;
	  NOTE_SOURCE_FILE (insn) = 0;
	  split_done = 1;
	}

      if (last != insn)
	{
	  PUT_CODE (insn, NOTE);
	  NOTE_SOURCE_FILE (insn) = 0;
	  NOTE_LINE_NUMBER (insn) = NOTE_INSN_DELETED;
	  split_done = 1;
	}
    }
  return split_done;
}
#endif /* GCC_VERSION == 2095 */

void
m68hc11_reorg (first)
     rtx first;
{
  int split_done = 0;

  z_replacement_completed = 0;
  z_reg = gen_rtx (REG, HImode, HARD_Z_REGNUM);

#if GCC_VERSION > 2095
  /* Some RTX are shared at this point.  This breaks the Z register
     replacement, unshare everything.  */
  unshare_all_rtl_again (first);
#endif

  /* Force a split of all splitable insn.  This is necessary for the
     Z register replacement mechanism because we end up with basic insns.  */
#if GCC_VERSION > 2095
  split_all_insns (0);
  split_done = 1;
#else
  split_done = m68hc11_split_all_insns (first);
#endif

  z_replacement_completed = 1;
  m68hc11_reassign_regs (first);

  /* After some splitting, there are some oportunities for CSE pass.
     This happens quite often when 32-bit or above patterns are split.  */
  if (optimize > 0 && split_done)
    reload_cse_regs (first);

  /* Re-create the REG_DEAD notes.  These notes are used in the machine
     description to use the best assembly directives.  */
  if (optimize)
    {
#if GCC_VERSION > 2095
      find_basic_blocks (first, max_reg_num (), 0);
      life_analysis (first, 0, PROP_REG_INFO | PROP_DEATH_NOTES);
#else
      find_basic_blocks (first, max_reg_num (), 0, 1);
      life_analysis (first, max_reg_num (), 0,
		     1 /* SCz: dead code elim fails. Must investigate. */ );
#endif
    }

  z_replacement_completed = 2;

  /* If optimizing, then go ahead and split insns that must be
     split after Z register replacement.  This gives more opportunities
     for peephole (in particular for consecutives xgdx/xgdy).  */
  if (optimize > 0)
#if GCC_VERSION > 2095
    split_all_insns (0);
#else
    m68hc11_split_all_insns (first);
#endif

  /* Once insns are split after the z_replacement_completed == 2,
     we must not re-run the life_analysis.  The xgdx/xgdy patterns
     are not recognized and the life_analysis pass removes some
     insns because it thinks some (SETs) are noops or made to dead
     stores (which is false due to the swap).

     Do a simple pass to eliminate the noop set that the final
     split could generate (because it was easier for split definition).  */
  {
    rtx insn;

    for (insn = first; insn; insn = NEXT_INSN (insn))
      {
	rtx body;

	if (INSN_DELETED_P (insn))
	  continue;
	if (GET_RTX_CLASS (GET_CODE (insn)) != 'i')
	  continue;

	/* Remove the (set (R) (R)) insns generated by some splits.  */
	body = PATTERN (insn);
	if (GET_CODE (body) == SET
	    && rtx_equal_p (SET_SRC (body), SET_DEST (body)))
	  {
	    PUT_CODE (insn, NOTE);
	    NOTE_LINE_NUMBER (insn) = NOTE_INSN_DELETED;
	    NOTE_SOURCE_FILE (insn) = 0;
	    continue;
	  }
      }
  }
}


/* Cost functions.  */

#define COSTS_N_INSNS(N) ((N) * 4 - 2)

/* Cost of moving memory. */
int
m68hc11_memory_move_cost (mode, class, in)
     enum machine_mode mode;
     enum reg_class class;
     int in ATTRIBUTE_UNUSED;
{
  if (class <= H_REGS)
    {
      if (GET_MODE_SIZE (mode) <= 2)
	return COSTS_N_INSNS (1) + (reload_completed | reload_in_progress);
      else
	return COSTS_N_INSNS (2) + (reload_completed | reload_in_progress);
    }
  else
    {
      if (GET_MODE_SIZE (mode) <= 2)
	return COSTS_N_INSNS (2);
      else
	return COSTS_N_INSNS (4);
    }
}


/* Cost of moving data from a register of class 'from' to on in class 'to'.
   Reload does not check the constraint of set insns when the two registers
   have a move cost of 2.  Setting a higher cost will force reload to check
   the constraints.  */
int
m68hc11_register_move_cost (from, to)
     enum reg_class from;
     enum reg_class to;
{
  if (from >= S_REGS && to >= S_REGS)
    {
      return COSTS_N_INSNS (3);
    }
  if (from <= S_REGS && to <= S_REGS)
    {
      return COSTS_N_INSNS (1) + (reload_completed | reload_in_progress);
    }
  return COSTS_N_INSNS (2);
}


/* Provide the costs of an addressing mode that contains ADDR.
   If ADDR is not a valid address, its cost is irrelevant.  */

int
m68hc11_address_cost (addr)
     rtx addr;
{
  int cost = 4;

  switch (GET_CODE (addr))
    {
    case REG:
      /* Make the cost of hard registers and specially SP, FP small. */
      if (REGNO (addr) < FIRST_PSEUDO_REGISTER)
	cost = 0;
      else
	cost = 1;
      break;

    case SYMBOL_REF:
      cost = 8;
      break;

    case LABEL_REF:
    case CONST:
      cost = 0;
      break;

    case PLUS:
      {
	register rtx plus0 = XEXP (addr, 0);
	register rtx plus1 = XEXP (addr, 1);

	if (GET_CODE (plus0) != REG)
	  break;

	switch (GET_CODE (plus1))
	  {
	  case CONST_INT:
	    if (INTVAL (plus1) >= 2 * m68hc11_max_offset
		|| INTVAL (plus1) < m68hc11_min_offset)
	      cost = 3;
	    else if (INTVAL (plus1) >= m68hc11_max_offset)
	      cost = 2;
	    else
	      cost = 0;
	    if (REGNO (plus0) < FIRST_PSEUDO_REGISTER)
	      cost += 0;
	    else
	      cost += 1;
	    break;

	  case SYMBOL_REF:
	    cost = 8;
	    break;

	  case CONST:
	  case LABEL_REF:
	    cost = 0;
	    break;

	  default:
	    break;
	  }
	break;
      }
    case PRE_DEC:
    case PRE_INC:
      if (SP_REG_P (XEXP (addr, 0)))
	cost = 1;
      break;

    default:
      break;
    }
  if (debug_m6811)
    {
      printf ("Address cost: %d for :", cost);
      fflush (stdout);
      debug_rtx (addr);
    }

  return cost;
}

int
m68hc11_rtx_costs (x, code, outer_code)
     rtx x;
     enum rtx_code code, outer_code;
{
  enum machine_mode mode = GET_MODE (x);
  int extra_cost = 0;
  int total;

  switch (code)
    {
    case MEM:
      return m68hc11_address_cost (XEXP (x, 0)) + 4;

    case ROTATE:
    case ROTATERT:
    case ASHIFT:
    case LSHIFTRT:
    case ASHIFTRT:
      if (GET_CODE (XEXP (x, 1)) == CONST_INT)
	{
	  int val = INTVAL (XEXP (x, 1));
	  int cost;

	  /* 8 or 16 shift instructions are fast.
	     Others are proportional to the shift counter.  */
	  if (val == 8 || val == 16 || val == -8 || val == -16)
	    {
	      val = 0;
	    }
	  cost = COSTS_N_INSNS (val + 1);
	  cost += rtx_cost (XEXP (x, 0), outer_code);
	  if (GET_MODE_SIZE (mode) >= 4 && val)
	    {
	      cost *= 4;
	    }
	  return cost;
	}
      total = rtx_cost (XEXP (x, 0), outer_code);
      if (GET_MODE_SIZE (mode) >= 4)
	{
	  total += COSTS_N_INSNS (16);
	}
      else
	{
	  total += COSTS_N_INSNS (8);
	}
      return total;

    case MINUS:
    case PLUS:
    case AND:
    case XOR:
    case IOR:
      extra_cost = 0;

      total = rtx_cost (XEXP (x, 0), outer_code)
	+ rtx_cost (XEXP (x, 1), outer_code);
      if (GET_MODE_SIZE (mode) <= 2)
	{
	  total += COSTS_N_INSNS (2);
	}
      else
	{
	  total += COSTS_N_INSNS (4);
	}
      return total;

    case DIV:
    case MOD:
      if (mode == QImode || mode == HImode)
	{
	  return 30;
	}
      else if (mode == SImode)
	{
	  return 100;
	}
      else
	{
	  return 150;
	}

    case MULT:
      if (mode == QImode)
	{
	  return TARGET_OP_TIME ? 10 : 2;
	}
      if (mode == HImode)
	{
	  return TARGET_OP_TIME ? 30 : 4;
	}
      if (mode == SImode)
	{
	  return TARGET_OP_TIME ? 100 : 20;
	}
      return 150;

    case NEG:
    case SIGN_EXTEND:
      extra_cost = COSTS_N_INSNS (2);

      /* Fall through */
    case NOT:
    case COMPARE:
    case ABS:
    case ZERO_EXTEND:
      total = rtx_cost (XEXP (x, 0), outer_code);
      if (mode == QImode)
	{
	  return total + extra_cost + COSTS_N_INSNS (1);
	}
      if (mode == HImode)
	{
	  return total + extra_cost + COSTS_N_INSNS (2);
	}
      if (mode == SImode)
	{
	  return total + extra_cost + COSTS_N_INSNS (4);
	}
      return total + extra_cost + COSTS_N_INSNS (8);

    case IF_THEN_ELSE:
      if (GET_CODE (XEXP (x, 1)) == PC || GET_CODE (XEXP (x, 2)) == PC)
	return COSTS_N_INSNS (1);

      return COSTS_N_INSNS (1);

    default:
      return COSTS_N_INSNS (4);
    }
}


/* print_options - called at the start of the code generation for a
   module. */

#if GCC_VERSION == 2095
extern char *main_input_filename;
#endif
extern char *asm_file_name;

#include <time.h>
#include <sys/types.h>

static void
print_options (out)
     FILE *out;
{
  char *a_time;
  long c_time;
  int i;
  extern int save_argc;
  extern char **save_argv;

  fprintf (out, ";;; Command:\t");
  for (i = 0; i < save_argc; i++)
    {
      fprintf (out, "%s", save_argv[i]);
      if (i + 1 < save_argc)
	fprintf (out, " ");
    }
  fprintf (out, "\n");
  c_time = time (0);
  a_time = ctime (&c_time);
  fprintf (out, ";;; Compiled:\t%s", a_time);
#ifdef __GNUC__
#ifndef __VERSION__
#define __VERSION__ "[unknown]"
#endif
  fprintf (out, ";;; (META)compiled by GNU C version %s.\n", __VERSION__);
#else
  fprintf (out, ";;; (META)compiled by CC.\n");
#endif
}

void
m68hc11_asm_file_start (out, main_file)
     FILE *out;
     char *main_file;
{
  fprintf (out, ";;;-----------------------------------------\n");
  fprintf (out, ";;; Start MC68HC11 gcc assembly output\n");
  fprintf (out, ";;; gcc compiler %s\n", version_string);
  print_options (out);
  fprintf (out, ";;;-----------------------------------------\n");
  output_file_directive (out, main_file);
}


static void
m68hc11_add_gc_roots ()
{
#if GCC_VERSION > 2095
  ggc_add_rtx_root (&m68hc11_soft_tmp_reg, 1);
  ggc_add_rtx_root (&ix_reg, 1);
  ggc_add_rtx_root (&iy_reg, 1);
  ggc_add_rtx_root (&d_reg, 1);
  ggc_add_rtx_root (&da_reg, 1);
  ggc_add_rtx_root (&z_reg, 1);
  ggc_add_rtx_root (&z_reg_qi, 1);
  ggc_add_rtx_root (&stack_push_word, 1);
  ggc_add_rtx_root (&stack_pop_word, 1);
#endif
}
