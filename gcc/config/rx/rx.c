/* Subroutines used for code generation on Renesas RX processors.
   Copyright (C) 2008, 2009 Free Software Foundation, Inc.
   Contributed by Red Hat.

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

/* To Do:

 * Re-enable memory-to-memory copies and fix up reload.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "rtl.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "real.h"
#include "insn-config.h"
#include "conditions.h"
#include "output.h"
#include "insn-attr.h"
#include "flags.h"
#include "function.h"
#include "expr.h"
#include "optabs.h"
#include "libfuncs.h"
#include "recog.h"
#include "toplev.h"
#include "reload.h"
#include "df.h"
#include "ggc.h"
#include "tm_p.h"
#include "debug.h"
#include "target.h"
#include "target-def.h"
#include "langhooks.h"

enum rx_cpu_types  rx_cpu_type = RX600;

/* Return true if OP is a reference to an object in a small data area.  */

static bool
rx_small_data_operand (rtx op)
{
  if (rx_small_data_limit == 0)
    return false;

  if (GET_CODE (op) == SYMBOL_REF)
    return SYMBOL_REF_SMALL_P (op);

  return false;
}

static bool
rx_is_legitimate_address (Mmode mode, rtx x, bool strict ATTRIBUTE_UNUSED)
{
  if (RTX_OK_FOR_BASE (x, strict))
    /* Register Indirect.  */
    return true;

  if (GET_MODE_SIZE (mode) == 4
      && (GET_CODE (x) == PRE_DEC || GET_CODE (x) == POST_INC))
    /* Pre-decrement Register Indirect or
       Post-increment Register Indirect.  */
    return RTX_OK_FOR_BASE (XEXP (x, 0), strict);

  if (GET_CODE (x) == PLUS)
    {
      rtx arg1 = XEXP (x, 0);
      rtx arg2 = XEXP (x, 1);
      rtx index = NULL_RTX;

      if (REG_P (arg1) && RTX_OK_FOR_BASE (arg1, strict))
	index = arg2;
      else if (REG_P (arg2) && RTX_OK_FOR_BASE (arg2, strict))
	index = arg1;
      else
	return false;

      switch (GET_CODE (index))
	{
	case CONST_INT:
	  {
	    /* Register Relative: REG + INT.
	       Only positive, mode-aligned, mode-sized
	       displacements are allowed.  */
	    HOST_WIDE_INT val = INTVAL (index);
	    int factor;

	    if (val < 0)
	      return false;
	    
	    switch (GET_MODE_SIZE (mode))
	      {
	      default: 
	      case 4: factor = 4; break;
	      case 2: factor = 2; break;
	      case 1: factor = 1; break;
	      }

	    if (val > (65535 * factor))
	      return false;
	    return (val % factor) == 0;
	  }

	case REG:
	  /* Unscaled Indexed Register Indirect: REG + REG
	     Size has to be "QI", REG has to be valid.  */
	  return GET_MODE_SIZE (mode) == 1 && RTX_OK_FOR_BASE (index, strict);

	case MULT:
	  {
	    /* Scaled Indexed Register Indirect: REG + (REG * FACTOR)
	       Factor has to equal the mode size, REG has to be valid.  */
	    rtx factor;

	    factor = XEXP (index, 1);
	    index = XEXP (index, 0);

	    return REG_P (index)
	      && RTX_OK_FOR_BASE (index, strict)
	      && CONST_INT_P (factor)
	      && GET_MODE_SIZE (mode) == INTVAL (factor);
	  }

	default:
	  return false;
	}
    }

  /* Small data area accesses turn into register relative offsets.  */
  return rx_small_data_operand (x);
}

/* Returns TRUE for simple memory addreses, ie ones
   that do not involve register indirect addressing
   or pre/post increment/decrement.  */

bool
rx_is_restricted_memory_address (rtx mem, enum machine_mode mode)
{
  rtx base, index;

  if (! rx_is_legitimate_address
      (mode, mem, reload_in_progress || reload_completed))
    return false;

  switch (GET_CODE (mem))
    {
    case REG:
      /* Simple memory addresses are OK.  */
      return true;

    case PRE_DEC:
    case POST_INC:
      return false;

    case PLUS:
      /* Only allow REG+INT addressing.  */
      base = XEXP (mem, 0);
      index = XEXP (mem, 1);

      return RX_REG_P (base) && CONST_INT_P (index);

    case SYMBOL_REF:
      /* Can happen when small data is being supported.
         Assume that it will be resolved into GP+INT.  */
      return true;

    default:
      gcc_unreachable ();
    }
}

bool
rx_is_mode_dependent_addr (rtx addr)
{
  if (GET_CODE (addr) == CONST)
    addr = XEXP (addr, 0);

  switch (GET_CODE (addr))
    {
      /* --REG and REG++ only work in SImode.  */
    case PRE_DEC:
    case POST_INC:
      return true;

    case MINUS:
    case PLUS:
      if (! REG_P (XEXP (addr, 0)))
	return true;

      addr = XEXP (addr, 1);

      switch (GET_CODE (addr))
	{
	case REG:
	  /* REG+REG only works in SImode.  */
	  return true;

	case CONST_INT:
	  /* REG+INT is only mode independent if INT is a
	     multiple of 4, positive and will fit into 8-bits.  */
	  if (((INTVAL (addr) & 3) == 0)
	      && IN_RANGE (INTVAL (addr), 4, 252))
	    return false;
	  return true;

	case SYMBOL_REF:
	case LABEL_REF:
	  return true;

	case MULT:
	  gcc_assert (REG_P (XEXP (addr, 0)));
	  gcc_assert (CONST_INT_P (XEXP (addr, 1)));
	  /* REG+REG*SCALE is always mode dependent.  */
	  return true;

	default:
	  /* Not recognized, so treat as mode dependent.  */
	  return true;
	}

    case CONST_INT:
    case SYMBOL_REF:
    case LABEL_REF:
    case REG:
      /* These are all mode independent.  */
      return false;

    default:
      /* Everything else is unrecognized,
	 so treat as mode dependent.  */
      return true;
    }
}

/* A C compound statement to output to stdio stream FILE the
   assembler syntax for an instruction operand that is a memory
   reference whose address is ADDR.  */

void
rx_print_operand_address (FILE * file, rtx addr)
{
  switch (GET_CODE (addr))
    {
    case REG:
      fprintf (file, "[");
      rx_print_operand (file, addr, 0);
      fprintf (file, "]");
      break;

    case PRE_DEC:
      fprintf (file, "[-");
      rx_print_operand (file, XEXP (addr, 0), 0);
      fprintf (file, "]");
      break;

    case POST_INC:
      fprintf (file, "[");
      rx_print_operand (file, XEXP (addr, 0), 0);
      fprintf (file, "+]");
      break;

    case PLUS:
      {
	rtx arg1 = XEXP (addr, 0);
	rtx arg2 = XEXP (addr, 1);
	rtx base, index;

	if (REG_P (arg1) && RTX_OK_FOR_BASE (arg1, true))
	  base = arg1, index = arg2;
	else if (REG_P (arg2) && RTX_OK_FOR_BASE (arg2, true))
	  base = arg2, index = arg1;
	else
	  {
	    rx_print_operand (file, arg1, 0);
	    fprintf (file, " + ");
	    rx_print_operand (file, arg2, 0);
	    break;
	  }

	if (REG_P (index) || GET_CODE (index) == MULT)
	  {
	    fprintf (file, "[");
	    rx_print_operand (file, index, 'A');
	    fprintf (file, ",");
	  }
	else /* GET_CODE (index) == CONST_INT  */
	  {
	    rx_print_operand (file, index, 'A');
	    fprintf (file, "[");
	  }
	rx_print_operand (file, base, 0);
	fprintf (file, "]");
	break;
      }

    case LABEL_REF:
    case SYMBOL_REF:
    case CONST:
      fprintf (file, "#");
    default:
      output_addr_const (file, addr);
      break;
    }
}

static void
rx_print_integer (FILE * file, HOST_WIDE_INT val)
{
  if (IN_RANGE (val, -64, 64))
    fprintf (file, HOST_WIDE_INT_PRINT_DEC, val);
  else
    fprintf (file,
	     TARGET_AS100_SYNTAX
	     ? "0%" HOST_WIDE_INT_PRINT "xH" : HOST_WIDE_INT_PRINT_HEX,
	     val);
}

static bool
rx_assemble_integer (rtx x, unsigned int size, int is_aligned)
{
  const char *  op = integer_asm_op (size, is_aligned);

  if (! CONST_INT_P (x))
    return default_assemble_integer (x, size, is_aligned);

  if (op == NULL)
    return false;
  fputs (op, asm_out_file);

  rx_print_integer (asm_out_file, INTVAL (x));
  fputc ('\n', asm_out_file);
  return true;
}


int rx_float_compare_mode;

/* Handles the insertion of a single operand into the assembler output.
   The %<letter> directives supported are:

     %A  Print an operand without a leading # character.
     %B  Print an integer comparison name.
     %C  Print a control register name.
     %F  Print a condition code flag name.
     %H  Print high part of a DImode register, integer or address.
     %L  Print low part of a DImode register, integer or address.
     %Q  If the operand is a MEM, then correctly generate
         register indirect or register relative addressing.  */

void
rx_print_operand (FILE * file, rtx op, int letter)
{
  switch (letter)
    {
    case 'A':
      /* Print an operand without a leading #.  */
      if (MEM_P (op))
	op = XEXP (op, 0);

      switch (GET_CODE (op))
	{
	case LABEL_REF:
	case SYMBOL_REF:
	  output_addr_const (file, op);
	  break;
	case CONST_INT:
	  fprintf (file, "%ld", (long) INTVAL (op));
	  break;
	default:
	  rx_print_operand (file, op, 0);
	  break;
	}
      break;

    case 'B':
      switch (GET_CODE (op))
	{
	case LT:  fprintf (file, "lt"); break;
	case GE:  fprintf (file, "ge"); break;
	case GT:  fprintf (file, "gt"); break;
	case LE:  fprintf (file, "le"); break;
	case GEU: fprintf (file, "geu"); break;
	case LTU: fprintf (file, "ltu"); break;
	case GTU: fprintf (file, "gtu"); break;
	case LEU: fprintf (file, "leu"); break;
	case EQ:  fprintf (file, "eq"); break;
	case NE:  fprintf (file, "ne"); break;
	default:  debug_rtx (op); gcc_unreachable ();
	}
      break;

    case 'C':
      gcc_assert (CONST_INT_P (op));
      switch (INTVAL (op))
	{
	case 0:   fprintf (file, "psw"); break;
	case 2:   fprintf (file, "usp"); break;
	case 3:   fprintf (file, "fpsw"); break;
	case 4:   fprintf (file, "cpen"); break;
	case 8:   fprintf (file, "bpsw"); break;
	case 9:   fprintf (file, "bpc"); break;
	case 0xa: fprintf (file, "isp"); break;
	case 0xb: fprintf (file, "fintv"); break;
	case 0xc: fprintf (file, "intb"); break;
	default:
	  gcc_unreachable ();
	}
      break;

    case 'F':
      gcc_assert (CONST_INT_P (op));
      switch (INTVAL (op))
	{
	case 0: case 'c': case 'C': fprintf (file, "C"); break;
	case 1:	case 'z': case 'Z': fprintf (file, "Z"); break;
	case 2: case 's': case 'S': fprintf (file, "S"); break;
	case 3: case 'o': case 'O': fprintf (file, "O"); break;
	case 8: case 'i': case 'I': fprintf (file, "I"); break;
	case 9: case 'u': case 'U': fprintf (file, "U"); break;
	default:
	  gcc_unreachable ();
	}
      break;

    case 'H':
      if (REG_P (op))
	fprintf (file, "%s", reg_names [REGNO (op) + (WORDS_BIG_ENDIAN ? 0 : 1)]);
      else if (CONST_INT_P (op))
	{
	  HOST_WIDE_INT v = INTVAL (op);

	  fprintf (file, "#");
	  /* Trickery to avoid problems with shifting 32 bits at a time.  */
	  v = v >> 16;
	  v = v >> 16;	  
	  rx_print_integer (file, v);
	}
      else
	{
	  gcc_assert (MEM_P (op));

	  if (! WORDS_BIG_ENDIAN)
	    op = adjust_address (op, SImode, 4);
	  output_address (XEXP (op, 0));
	}
      break;

    case 'L':
      if (REG_P (op))
	fprintf (file, "%s", reg_names [REGNO (op) + (WORDS_BIG_ENDIAN ? 1 : 0)]);
      else if (CONST_INT_P (op))
	{
	  fprintf (file, "#");
	  rx_print_integer (file, INTVAL (op) & 0xffffffff);
	}
      else
	{
	  gcc_assert (MEM_P (op));

	  if (WORDS_BIG_ENDIAN)
	    op = adjust_address (op, SImode, 4);
	  output_address (XEXP (op, 0));
	}
      break;

    case 'Q':
      if (MEM_P (op))
	{
	  HOST_WIDE_INT offset;

	  op = XEXP (op, 0);

	  if (REG_P (op))
	    offset = 0;
	  else if (GET_CODE (op) == PLUS)
	    {
	      rtx displacement;

	      if (REG_P (XEXP (op, 0)))
		{
		  displacement = XEXP (op, 1);
		  op = XEXP (op, 0);
		}
	      else
		{
		  displacement = XEXP (op, 0);
		  op = XEXP (op, 1);
		  gcc_assert (REG_P (op));
		}

	      gcc_assert (CONST_INT_P (displacement));
	      offset = INTVAL (displacement);
	      gcc_assert (offset >= 0);

	      fprintf (file, "%ld", offset);
	    }
	  else
	    gcc_unreachable ();

	  fprintf (file, "[");
	  rx_print_operand (file, op, 0);
	  fprintf (file, "].");

	  switch (GET_MODE_SIZE (GET_MODE (op)))
	    {
	    case 1:
	      gcc_assert (offset < 65535 * 1);
	      fprintf (file, "B");
	      break;
	    case 2:
	      gcc_assert (offset % 2 == 0);
	      gcc_assert (offset < 65535 * 2);
	      fprintf (file, "W");
	      break;
	    default:
	      gcc_assert (offset % 4 == 0);
	      gcc_assert (offset < 65535 * 4);
	      fprintf (file, "L");
	      break;
	    }
	  break;
	}

      /* Fall through.  */

    default:
      switch (GET_CODE (op))
	{
	case MULT:
	  /* Should be the scaled part of an
	     indexed register indirect address.  */
	  {
	    rtx base = XEXP (op, 0);
	    rtx index = XEXP (op, 1);

	    /* Check for a swaped index register and scaling factor.
	       Not sure if this can happen, but be prepared to handle it.  */
	    if (CONST_INT_P (base) && REG_P (index))
	      {
		rtx tmp = base;
		base = index;
		index = tmp;
	      }

	    gcc_assert (REG_P (base));
	    gcc_assert (REGNO (base) < FIRST_PSEUDO_REGISTER);
	    gcc_assert (CONST_INT_P (index));
	    /* Do not try to verify the value of the scalar as it is based
	       on the mode of the MEM not the mode of the MULT.  (Which
	       will always be SImode).  */
	    fprintf (file, "%s", reg_names [REGNO (base)]);
	    break;
	  }

	case MEM:
	  output_address (XEXP (op, 0));
	  break;

	case PLUS:
	  output_address (op);
	  break;

	case REG:
	  gcc_assert (REGNO (op) < FIRST_PSEUDO_REGISTER);
	  fprintf (file, "%s", reg_names [REGNO (op)]);
	  break;

	case SUBREG:
	  gcc_assert (subreg_regno (op) < FIRST_PSEUDO_REGISTER);
	  fprintf (file, "%s", reg_names [subreg_regno (op)]);
	  break;

	  /* This will only be single precision....  */
	case CONST_DOUBLE:
	  {
	    unsigned long val;
	    REAL_VALUE_TYPE rv;

	    REAL_VALUE_FROM_CONST_DOUBLE (rv, op);
	    REAL_VALUE_TO_TARGET_SINGLE (rv, val);
	    fprintf (file, TARGET_AS100_SYNTAX ? "#0%lxH" : "#0x%lx", val);
	    break;
	  }

	case CONST_INT:
	  fprintf (file, "#");
	  rx_print_integer (file, INTVAL (op));
	  break;

	case SYMBOL_REF:
	case CONST:
	case LABEL_REF:
	case CODE_LABEL:
	case UNSPEC:
	  rx_print_operand_address (file, op);
	  break;

	default:
	  gcc_unreachable ();
	}
      break;
    }
}

/* Returns an assembler template for a move instruction.  */

char *
rx_gen_move_template (rtx * operands, bool is_movu)
{
  static char  template [64];
  const char * extension = TARGET_AS100_SYNTAX ? ".L" : "";
  const char * src_template;
  const char * dst_template;
  rtx          dest = operands[0];
  rtx          src  = operands[1];

  /* Decide which extension, if any, should be given to the move instruction.  */
  switch (CONST_INT_P (src) ? GET_MODE (dest) : GET_MODE (src))
    {
    case QImode:
      /* The .B extension is not valid when
	 loading an immediate into a register.  */
      if (! REG_P (dest) || ! CONST_INT_P (src))
	extension = ".B";
      break;
    case HImode:
      if (! REG_P (dest) || ! CONST_INT_P (src))
	/* The .W extension is not valid when
	   loading an immediate into a register.  */
	extension = ".W";
      break;
    case SFmode:
    case SImode:
      extension = ".L";
      break;
    case VOIDmode:
      /* This mode is used by constants.  */
      break;
    default:
      debug_rtx (src);
      gcc_unreachable ();
    }

  if (MEM_P (src) && rx_small_data_operand (XEXP (src, 0)))
    src_template = "%%gp(%A1)[r13]";
  else
    src_template = "%1";

  if (MEM_P (dest) && rx_small_data_operand (XEXP (dest, 0)))
    dst_template = "%%gp(%A0)[r13]";
  else
    dst_template = "%0";

  sprintf (template, "%s%s\t%s, %s", is_movu ? "movu" : "mov",
	   extension, src_template, dst_template);
  return template;
}

/* Returns an assembler template for a conditional branch instruction.  */

const char *
rx_gen_cond_branch_template (rtx condition, bool reversed)
{
  enum rtx_code code = GET_CODE (condition);


  if ((cc_status.flags & CC_NO_OVERFLOW) && ! rx_float_compare_mode)
    gcc_assert (code != GT && code != GE && code != LE && code != LT);

  if ((cc_status.flags & CC_NO_CARRY) || rx_float_compare_mode)
    gcc_assert (code != GEU && code != GTU && code != LEU && code != LTU);

  if (reversed)
    {
      if (rx_float_compare_mode)
	code = reverse_condition_maybe_unordered (code);
      else
	code = reverse_condition (code);
    }

  /* We do not worry about encoding the branch length here as GAS knows
     how to choose the smallest version, and how to expand a branch that
     is to a destination that is out of range.  */

  switch (code)
    {
    case UNEQ:	    return "bo\t1f\n\tbeq\t%0\n1:";
    case LTGT:	    return "bo\t1f\n\tbne\t%0\n1:";
    case UNLT:      return "bo\t1f\n\tbn\t%0\n1:";
    case UNGE:      return "bo\t1f\n\tbpz\t%0\n1:";
    case UNLE:      return "bo\t1f\n\tbgt\t1f\n\tbra\t%0\n1:";
    case UNGT:      return "bo\t1f\n\tble\t1f\n\tbra\t%0\n1:";
    case UNORDERED: return "bo\t%0";
    case ORDERED:   return "bno\t%0";

    case LT:        return rx_float_compare_mode ? "bn\t%0" : "blt\t%0";
    case GE:        return rx_float_compare_mode ? "bpz\t%0" : "bge\t%0";
    case GT:        return "bgt\t%0";
    case LE:        return "ble\t%0";
    case GEU:       return "bgeu\t%0";
    case LTU:       return "bltu\t%0";
    case GTU:       return "bgtu\t%0";
    case LEU:       return "bleu\t%0";
    case EQ:        return "beq\t%0";
    case NE:        return "bne\t%0";
    default:
      gcc_unreachable ();
    }
}

/* Return VALUE rounded up to the next ALIGNMENT boundary.  */

static inline unsigned int
rx_round_up (unsigned int value, unsigned int alignment)
{
  alignment -= 1;
  return (value + alignment) & (~ alignment);
}

/* Return the number of bytes in the argument registers
   occupied by an argument of type TYPE and mode MODE.  */

unsigned int
rx_function_arg_size (Mmode mode, const_tree type)
{
  unsigned int num_bytes;

  num_bytes = (mode == BLKmode)
    ? int_size_in_bytes (type) : GET_MODE_SIZE (mode);
  return rx_round_up (num_bytes, UNITS_PER_WORD);
}

#define NUM_ARG_REGS		4
#define MAX_NUM_ARG_BYTES	(NUM_ARG_REGS * UNITS_PER_WORD)

/* Return an RTL expression describing the register holding a function
   parameter of mode MODE and type TYPE or NULL_RTX if the parameter should
   be passed on the stack.  CUM describes the previous parameters to the
   function and NAMED is false if the parameter is part of a variable
   parameter list, or the last named parameter before the start of a
   variable parameter list.  */

rtx
rx_function_arg (Fargs * cum, Mmode mode, const_tree type, bool named)
{
  unsigned int next_reg;
  unsigned int bytes_so_far = *cum;
  unsigned int size;
  unsigned int rounded_size;

  /* An exploded version of rx_function_arg_size.  */
  size = (mode == BLKmode) ? int_size_in_bytes (type) : GET_MODE_SIZE (mode);

  rounded_size = rx_round_up (size, UNITS_PER_WORD);

  /* Don't pass this arg via registers if there
     are insufficient registers to hold all of it.  */
  if (rounded_size + bytes_so_far > MAX_NUM_ARG_BYTES)
    return NULL_RTX;

  /* Unnamed arguments and the last named argument in a
     variadic function are always passed on the stack.  */
  if (!named)
    return NULL_RTX;

  /* Structures must occupy an exact number of registers,
     otherwise they are passed on the stack.  */
  if ((type == NULL || AGGREGATE_TYPE_P (type))
      && (size % UNITS_PER_WORD) != 0)
    return NULL_RTX;

  next_reg = (bytes_so_far / UNITS_PER_WORD) + 1;

  return gen_rtx_REG (mode, next_reg);
}

/* Return an RTL describing where a function return value of type RET_TYPE
   is held.  */

static rtx
rx_function_value (const_tree ret_type,
		   const_tree fn_decl_or_type ATTRIBUTE_UNUSED,
		   bool       outgoing ATTRIBUTE_UNUSED)
{
  return gen_rtx_REG (TYPE_MODE (ret_type), FUNC_RETURN_REGNUM);
}

static bool
rx_return_in_memory (const_tree type, const_tree fntype ATTRIBUTE_UNUSED)
{
  HOST_WIDE_INT size;

  if (TYPE_MODE (type) != BLKmode
      && ! AGGREGATE_TYPE_P (type))
    return false;

  size = int_size_in_bytes (type);
  /* Large structs and those whose size is not an
     exact multiple of 4 are returned in memory.  */
  return size < 1
    || size > 16
    || (size % UNITS_PER_WORD) != 0;
}

static rtx
rx_struct_value_rtx (tree fndecl ATTRIBUTE_UNUSED,
		     int incoming ATTRIBUTE_UNUSED)
{
  return gen_rtx_REG (Pmode, STRUCT_VAL_REGNUM);
}

static bool
rx_return_in_msb (const_tree valtype)
{
  return TARGET_BIG_ENDIAN_DATA
    && (AGGREGATE_TYPE_P (valtype) || TREE_CODE (valtype) == COMPLEX_TYPE);
}

/* Returns true if the provided function has the specified attribute.  */

static inline bool
has_func_attr (const_tree decl, const char * func_attr)
{
  if (decl == NULL_TREE)
    decl = current_function_decl;

  return lookup_attribute (func_attr, DECL_ATTRIBUTES (decl)) != NULL_TREE;
}

/* Returns true if the provided function has the "fast_interrupt" attribute.  */

static inline bool
is_fast_interrupt_func (const_tree decl)
{
  return has_func_attr (decl, "fast_interrupt");
}

/* Returns true if the provided function has the "interrupt" attribute.  */

static inline bool
is_interrupt_func (const_tree decl)
{
  return has_func_attr (decl, "interrupt");
}

/* Returns true if the provided function has the "naked" attribute.  */

static inline bool
is_naked_func (const_tree decl)
{
  return has_func_attr (decl, "naked");
}

static bool use_fixed_regs = false;

void
rx_conditional_register_usage (void)
{
  static bool using_fixed_regs = false;

  if (rx_small_data_limit > 0)
    fixed_regs[GP_BASE_REGNUM] = call_used_regs [GP_BASE_REGNUM] = 1;

  if (use_fixed_regs != using_fixed_regs)
    {
      static char saved_fixed_regs[FIRST_PSEUDO_REGISTER];
      static char saved_call_used_regs[FIRST_PSEUDO_REGISTER];

      if (use_fixed_regs)
	{
	  unsigned int switched = 0;
	  unsigned int r;

	  /* This is for fast interrupt handlers.  Any register in
	     the range r10 to r13 (inclusive) that is currently
	     marked as fixed is now a viable, call-saved register.
	     All other registers are fixed.  */
	  memcpy (saved_fixed_regs, fixed_regs, sizeof fixed_regs);
	  memcpy (saved_call_used_regs, call_used_regs, sizeof call_used_regs);
	  
	  for (r = 1; r < 10; r++)
	    fixed_regs[r] = call_used_regs[r] = 1;
	  
	  for (r = 10; r <= 13; r++)
	    if (fixed_regs[r])
	      {
		fixed_regs[r] = 0;
		call_used_regs[r] = 1;
		++ switched;
	      }
	    else
	      {
		fixed_regs[r] = 1;
		call_used_regs[r] = 1;
	      }

	  fixed_regs[14] = call_used_regs[14] = 1;
	  fixed_regs[15] = call_used_regs[15] = 1;

	  if (switched == 0)
	    {
	      static bool warned = false;

	      if (! warned)
		{
		  warning (0, "no fixed registers available "
			   "for use by fast interrupt handler");
		  warned = true;
		}
	    }
	}
      else
	{
	  /* Restore the normal register masks.  */
	  memcpy (fixed_regs, saved_fixed_regs, sizeof fixed_regs);
	  memcpy (call_used_regs, saved_call_used_regs, sizeof call_used_regs);
	}

      using_fixed_regs = use_fixed_regs;
    }
}

/* Perform any actions necessary before starting to compile FNDECL.
   For the RX we use this to make sure that we have the correct
   set of register masks selected.  If FNDECL is NULL then we are
   compiling top level things.  */

static void
rx_set_current_function (tree fndecl)
{
  /* Remember the last target of rx_set_current_function.  */
  static tree rx_previous_fndecl;
  bool prev_was_fast_interrupt;
  bool current_is_fast_interrupt;

  /* Only change the context if the function changes.  This hook is called
     several times in the course of compiling a function, and we don't want
     to slow things down too much or call target_reinit when it isn't safe.  */
  if (fndecl == rx_previous_fndecl)
    return;

  prev_was_fast_interrupt
    = rx_previous_fndecl
    ? is_fast_interrupt_func (rx_previous_fndecl) : false;

  current_is_fast_interrupt
    = fndecl ? is_fast_interrupt_func (fndecl) : false;
      
  if (prev_was_fast_interrupt != current_is_fast_interrupt)
    {
      use_fixed_regs = current_is_fast_interrupt;
      target_reinit ();
    }

  rx_previous_fndecl = fndecl;
}

/* Typical stack layout should looks like this after the function's prologue:

                            |    |
                              --                       ^
                            |    | \                   |
                            |    |   arguments saved   | Increasing
                            |    |   on the stack      |  addresses
    PARENT   arg pointer -> |    | /
  -------------------------- ---- -------------------
    CHILD                   |ret |   return address
                              --
                            |    | \
                            |    |   call saved
                            |    |   registers
			    |    | /
                              --
                            |    | \
                            |    |   local
                            |    |   variables
        frame pointer ->    |    | /
                              --
                            |    | \
                            |    |   outgoing          | Decreasing
                            |    |   arguments         |  addresses
   current stack pointer -> |    | /                   |
  -------------------------- ---- ------------------   V
                            |    |                 */

static unsigned int
bit_count (unsigned int x)
{
  const unsigned int m1 = 0x55555555;
  const unsigned int m2 = 0x33333333;
  const unsigned int m4 = 0x0f0f0f0f;

  x -= (x >> 1) & m1;
  x = (x & m2) + ((x >> 2) & m2);
  x = (x + (x >> 4)) & m4;
  x += x >>  8;

  return (x + (x >> 16)) & 0x3f;
}

/* Returns either the lowest numbered and highest numbered registers that
   occupy the call-saved area of the stack frame, if the registers are
   stored as a contiguous block, or else a bitmask of the individual
   registers if they are stored piecemeal.

   Also computes the size of the frame and the size of the outgoing
   arguments block (in bytes).  */

static void
rx_get_stack_layout (unsigned int * lowest,
		     unsigned int * highest,
		     unsigned int * register_mask,
		     unsigned int * frame_size,
		     unsigned int * stack_size)
{
  unsigned int reg;
  unsigned int low;
  unsigned int high;
  unsigned int fixed_reg = 0;
  unsigned int save_mask;
  unsigned int pushed_mask;
  unsigned int unneeded_pushes;

  if (is_naked_func (NULL_TREE)
      || is_fast_interrupt_func (NULL_TREE))
    {
      /* Naked functions do not create their own stack frame.
	 Instead the programmer must do that for us.

	 Fast interrupt handlers use fixed registers that have
	 been epsecially released to the function, so they do
	 not need or want a stack frame.  */
      * lowest = 0;
      * highest = 0;
      * register_mask = 0;
      * frame_size = 0;
      * stack_size = 0;
      return;
    }

  for (save_mask = high = low = 0, reg = 1; reg < FIRST_PSEUDO_REGISTER; reg++)
    {
      if (df_regs_ever_live_p (reg)
	  && (! call_used_regs[reg]
	      /* Even call clobbered registered must
		 be pushed inside interrupt handlers.  */
	      || is_interrupt_func (NULL_TREE)))
	{
	  if (low == 0)
	    low = reg;
	  high = reg;

	  save_mask |= 1 << reg;
	}

      /* Remember if we see a fixed register
	 after having found the low register.  */
      if (low != 0 && fixed_reg == 0 && fixed_regs [reg])
	fixed_reg = reg;
    }

  /* Decide if it would be faster fill in the call-saved area of the stack
     frame using multiple PUSH instructions instead of a single PUSHM
     instruction.

     SAVE_MASK is a bitmask of the registers that must be stored in the
     call-save area.  PUSHED_MASK is a bitmask of the registers that would
     be pushed into the area if we used a PUSHM instruction.  UNNEEDED_PUSHES
     is a bitmask of those registers in pushed_mask that are not in
     save_mask.

     We use a simple heuristic that says that it is better to use
     multiple PUSH instructions if the number of unnecessary pushes is
     greater than the number of necessary pushes.

     We also use multiple PUSH instructions if there are any fixed registers
     between LOW and HIGH.  The only way that this can happen is if the user
     has specified --fixed-<reg-name> on the command line and in such
     circumstances we do not want to touch the fixed registers at all.

     FIXME: Is it worth improving this heuristic ?  */
  pushed_mask = (-1 << low) & ~(-1 << (high + 1));
  unneeded_pushes = (pushed_mask & (~ save_mask)) & pushed_mask;

  if ((fixed_reg && fixed_reg <= high)
      || (optimize_function_for_speed_p (cfun)
	  && bit_count (save_mask) < bit_count (unneeded_pushes)))
    {
      /* Use multiple pushes.  */
      * lowest = 0;
      * highest = 0;
      * register_mask = save_mask;
    }
  else
    {
      /* Use one push multiple instruction.  */
      * lowest = low;
      * highest = high;
      * register_mask = 0;
    }

  * frame_size = rx_round_up
    (get_frame_size (), STACK_BOUNDARY / BITS_PER_UNIT);

  if (crtl->args.size > 0)
    * frame_size += rx_round_up
      (crtl->args.size, STACK_BOUNDARY / BITS_PER_UNIT);

  * stack_size = rx_round_up
    (crtl->outgoing_args_size, STACK_BOUNDARY / BITS_PER_UNIT);
}

/* Generate a PUSHM instruction that matches the given operands.  */

void
rx_emit_stack_pushm (rtx * operands)
{
  HOST_WIDE_INT last_reg;
  rtx first_push;

  gcc_assert (CONST_INT_P (operands[0]));
  last_reg = (INTVAL (operands[0]) / UNITS_PER_WORD) - 1;

  gcc_assert (GET_CODE (operands[1]) == PARALLEL);
  first_push = XVECEXP (operands[1], 0, 1);
  gcc_assert (SET_P (first_push));
  first_push = SET_SRC (first_push);
  gcc_assert (REG_P (first_push));

  asm_fprintf (asm_out_file, "\tpushm\t%s-%s\n",
	       reg_names [REGNO (first_push) - last_reg],
	       reg_names [REGNO (first_push)]);
}

/* Generate a PARALLEL that will pass the rx_store_multiple_vector predicate.  */

static rtx
gen_rx_store_vector (unsigned int low, unsigned int high)
{
  unsigned int i;
  unsigned int count = (high - low) + 2;
  rtx vector;

  vector = gen_rtx_PARALLEL (VOIDmode, rtvec_alloc (count));

  XVECEXP (vector, 0, 0) =
    gen_rtx_SET (SImode, stack_pointer_rtx,
		 gen_rtx_MINUS (SImode, stack_pointer_rtx,
				GEN_INT ((count - 1) * UNITS_PER_WORD)));

  for (i = 0; i < count - 1; i++)
    XVECEXP (vector, 0, i + 1) =
      gen_rtx_SET (SImode,
		   gen_rtx_MEM (SImode,
				gen_rtx_MINUS (SImode, stack_pointer_rtx,
					       GEN_INT ((i + 1) * UNITS_PER_WORD))),
		   gen_rtx_REG (SImode, high - i));
  return vector;
}

/* Mark INSN as being frame related.  If it is a PARALLEL
   then mark each element as being frame related as well.  */

static void
mark_frame_related (rtx insn)
{
  RTX_FRAME_RELATED_P (insn) = 1;
  insn = PATTERN (insn);

  if (GET_CODE (insn) == PARALLEL)
    {
      unsigned int i;

      for (i = 0; i < XVECLEN (insn, 0); i++)
	RTX_FRAME_RELATED_P (XVECEXP (insn, 0, i)) = 1;
    }
}

void
rx_expand_prologue (void)
{
  unsigned int stack_size;
  unsigned int frame_size;
  unsigned int mask;
  unsigned int low;
  unsigned int high;
  unsigned int reg;
  rtx insn;

  /* Naked functions use their own, programmer provided prologues.  */
  if (is_naked_func (NULL_TREE)
      /* Fast interrupt functions never use the stack.  */
      || is_fast_interrupt_func (NULL_TREE))
    return;

  rx_get_stack_layout (& low, & high, & mask, & frame_size, & stack_size);

  /* If we use any of the callee-saved registers, save them now.  */
  if (mask)
    {
      /* Push registers in reverse order.  */
      for (reg = FIRST_PSEUDO_REGISTER; reg --;)
	if (mask & (1 << reg))
	  {
	    insn = emit_insn (gen_stack_push (gen_rtx_REG (SImode, reg)));
	    mark_frame_related (insn);
	  }
    }
  else if (low)
    {
      if (high == low)
	insn = emit_insn (gen_stack_push (gen_rtx_REG (SImode, low)));
      else
	insn = emit_insn (gen_stack_pushm (GEN_INT (((high - low) + 1)
						    * UNITS_PER_WORD),
					   gen_rx_store_vector (low, high)));
      mark_frame_related (insn);
    }

  if (is_interrupt_func (NULL_TREE) && TARGET_SAVE_ACC_REGISTER)
    {
      unsigned int acc_high, acc_low;

      /* Interrupt handlers have to preserve the accumulator
	 register if so requested by the user.  Use the first
         two pushed register as intermediaries.  */
      if (mask)
	{
	  acc_low = acc_high = 0;

	  for (reg = 1; reg < FIRST_PSEUDO_REGISTER; reg ++)
	    if (mask & (1 << reg))
	      {
		if (acc_low == 0)
		  acc_low = reg;
		else
		  {
		    acc_high = reg;
		    break;
		  }
	      }
	    
	  /* We have assumed that there are at least two registers pushed... */
	  gcc_assert (acc_high != 0);

	  /* Note - the bottom 16 bits of the accumulator are inaccessible.
	     We just assume that they are zero.  */
	  emit_insn (gen_mvfacmi (gen_rtx_REG (SImode, acc_low)));
	  emit_insn (gen_mvfachi (gen_rtx_REG (SImode, acc_high)));
	  emit_insn (gen_stack_push (gen_rtx_REG (SImode, acc_low)));
	  emit_insn (gen_stack_push (gen_rtx_REG (SImode, acc_high)));
	}
      else
	{
	  acc_low = low;
	  acc_high = low + 1;

	  /* We have assumed that there are at least two registers pushed... */
	  gcc_assert (acc_high <= high);

	  emit_insn (gen_mvfacmi (gen_rtx_REG (SImode, acc_low)));
	  emit_insn (gen_mvfachi (gen_rtx_REG (SImode, acc_high)));
	  emit_insn (gen_stack_pushm (GEN_INT (2 * UNITS_PER_WORD),
				      gen_rx_store_vector (acc_low, acc_high)));
	}

      frame_size += 2 * UNITS_PER_WORD;
    }

  /* If needed, set up the frame pointer.  */
  if (frame_pointer_needed)
    {
      if (frame_size)
	insn = emit_insn (gen_addsi3 (frame_pointer_rtx, stack_pointer_rtx,
				      GEN_INT (- (HOST_WIDE_INT) frame_size)));
      else
	insn = emit_move_insn (frame_pointer_rtx, stack_pointer_rtx);

      RTX_FRAME_RELATED_P (insn) = 1;
    }

  insn = NULL_RTX;

  /* Allocate space for the outgoing args.
     If the stack frame has not already been set up then handle this as well.  */
  if (stack_size)
    {
      if (frame_size)
	{
	  if (frame_pointer_needed)
	    insn = emit_insn (gen_addsi3 (stack_pointer_rtx, frame_pointer_rtx,
					  GEN_INT (- (HOST_WIDE_INT)
						   stack_size)));
	  else
	    insn = emit_insn (gen_addsi3 (stack_pointer_rtx, stack_pointer_rtx,
					  GEN_INT (- (HOST_WIDE_INT)
						   (frame_size + stack_size))));
	}
      else
	insn = emit_insn (gen_addsi3 (stack_pointer_rtx, stack_pointer_rtx,
				      GEN_INT (- (HOST_WIDE_INT) stack_size)));
    }
  else if (frame_size)
    {
      if (! frame_pointer_needed)
	insn = emit_insn (gen_addsi3 (stack_pointer_rtx, stack_pointer_rtx,
				      GEN_INT (- (HOST_WIDE_INT) frame_size)));
      else
	insn = emit_move_insn (stack_pointer_rtx, frame_pointer_rtx);
    }

  if (insn != NULL_RTX)
    RTX_FRAME_RELATED_P (insn) = 1;
}

static void
rx_output_function_prologue (FILE * file,
			     HOST_WIDE_INT frame_size ATTRIBUTE_UNUSED)
{
  if (is_fast_interrupt_func (NULL_TREE))
    asm_fprintf (file, "\t; Note: Fast Interrupt Handler\n");

  if (is_interrupt_func (NULL_TREE))
    asm_fprintf (file, "\t; Note: Interrupt Handler\n");

  if (is_naked_func (NULL_TREE))
    asm_fprintf (file, "\t; Note: Naked Function\n");

  if (cfun->static_chain_decl != NULL)
    asm_fprintf (file, "\t; Note: Nested function declared "
		 "inside another function.\n");

  if (crtl->calls_eh_return)
    asm_fprintf (file, "\t; Note: Calls __builtin_eh_return.\n");
}

/* Generate a POPM or RTSD instruction that matches the given operands.  */

void
rx_emit_stack_popm (rtx * operands, bool is_popm)
{
  HOST_WIDE_INT stack_adjust;
  HOST_WIDE_INT last_reg;
  rtx first_push;

  gcc_assert (CONST_INT_P (operands[0]));
  stack_adjust = INTVAL (operands[0]);
  
  gcc_assert (GET_CODE (operands[1]) == PARALLEL);
  last_reg = XVECLEN (operands[1], 0) - (is_popm ? 2 : 3);

  first_push = XVECEXP (operands[1], 0, 1);
  gcc_assert (SET_P (first_push));
  first_push = SET_DEST (first_push);
  gcc_assert (REG_P (first_push));

  if (is_popm)
    asm_fprintf (asm_out_file, "\tpopm\t%s-%s\n",
		 reg_names [REGNO (first_push)],
		 reg_names [REGNO (first_push) + last_reg]);
  else
    asm_fprintf (asm_out_file, "\trtsd\t#%d, %s-%s\n",
		 (int) stack_adjust,
		 reg_names [REGNO (first_push)],
		 reg_names [REGNO (first_push) + last_reg]);
}

/* Generate a PARALLEL which will satisfy the rx_rtsd_vector predicate.  */

static rtx
gen_rx_rtsd_vector (unsigned int adjust, unsigned int low, unsigned int high)
{
  unsigned int i;
  unsigned int bias = 3;
  unsigned int count = (high - low) + bias;
  rtx vector;

  vector = gen_rtx_PARALLEL (VOIDmode, rtvec_alloc (count));

  XVECEXP (vector, 0, 0) =
    gen_rtx_SET (SImode, stack_pointer_rtx,
		 plus_constant (stack_pointer_rtx, adjust));

  for (i = 0; i < count - 2; i++)
    XVECEXP (vector, 0, i + 1) =
      gen_rtx_SET (SImode,
		   gen_rtx_REG (SImode, low + i),
		   gen_rtx_MEM (SImode,
				i == 0 ? stack_pointer_rtx
				: plus_constant (stack_pointer_rtx,
						 i * UNITS_PER_WORD)));

  XVECEXP (vector, 0, count - 1) = gen_rtx_RETURN (VOIDmode);

  return vector;
}
  
/* Generate a PARALLEL which will satisfy the rx_load_multiple_vector predicate.  */

static rtx
gen_rx_popm_vector (unsigned int low, unsigned int high)
{
  unsigned int i;  
  unsigned int count = (high - low) + 2;
  rtx vector;

  vector = gen_rtx_PARALLEL (VOIDmode, rtvec_alloc (count));

  XVECEXP (vector, 0, 0) =
    gen_rtx_SET (SImode, stack_pointer_rtx,
		 plus_constant (stack_pointer_rtx,
				(count - 1) * UNITS_PER_WORD));

  for (i = 0; i < count - 1; i++)
    XVECEXP (vector, 0, i + 1) =
      gen_rtx_SET (SImode,
		   gen_rtx_REG (SImode, low + i),
		   gen_rtx_MEM (SImode,
				i == 0 ? stack_pointer_rtx
				: plus_constant (stack_pointer_rtx,
						 i * UNITS_PER_WORD)));

  return vector;
}
  
void
rx_expand_epilogue (bool is_sibcall)
{
  unsigned int low;
  unsigned int high;
  unsigned int frame_size;
  unsigned int stack_size;
  unsigned int register_mask;
  unsigned int regs_size;
  unsigned int reg;
  unsigned HOST_WIDE_INT total_size;

  if (is_naked_func (NULL_TREE))
    {
      /* Naked functions use their own, programmer provided epilogues.
	 But, in order to keep gcc happy we have to generate some kind of
	 epilogue RTL.  */
      emit_jump_insn (gen_naked_return ());
      return;
    }

  rx_get_stack_layout (& low, & high, & register_mask,
		       & frame_size, & stack_size);

  total_size = frame_size + stack_size;
  regs_size = ((high - low) + 1) * UNITS_PER_WORD;

  /* See if we are unable to use the special stack frame deconstruct and
     return instructions.  In most cases we can use them, but the exceptions
     are:

     - Sibling calling functions deconstruct the frame but do not return to
       their caller.  Instead they branch to their sibling and allow their
       return instruction to return to this function's parent.

     - Fast and normal interrupt handling functions have to use special
       return instructions.

     - Functions where we have pushed a fragmented set of registers into the
       call-save area must have the same set of registers popped.  */
  if (is_sibcall
      || is_fast_interrupt_func (NULL_TREE)
      || is_interrupt_func (NULL_TREE)
      || register_mask)
    {
      /* Cannot use the special instructions - deconstruct by hand.  */
      if (total_size)
	emit_insn (gen_addsi3 (stack_pointer_rtx, stack_pointer_rtx,
			       GEN_INT (total_size)));

      if (is_interrupt_func (NULL_TREE) && TARGET_SAVE_ACC_REGISTER)
	{
	  unsigned int acc_low, acc_high;

	  /* Reverse the saving of the accumulator register onto the stack.
	     Note we must adjust the saved "low" accumulator value as it
	     is really the middle 32-bits of the accumulator.  */
	  if (register_mask)
	    {
	      acc_low = acc_high = 0;
	      for (reg = 1; reg < FIRST_PSEUDO_REGISTER; reg ++)
		if (register_mask & (1 << reg))
		  {
		    if (acc_low == 0)
		      acc_low = reg;
		    else
		      {
			acc_high = reg;
			break;
		      }
		  }
	      emit_insn (gen_stack_pop (gen_rtx_REG (SImode, acc_high)));
	      emit_insn (gen_stack_pop (gen_rtx_REG (SImode, acc_low)));
	    }
	  else
	    {
	      acc_low = low;
	      acc_high = low + 1;
	      emit_insn (gen_stack_popm (GEN_INT (2 * UNITS_PER_WORD),
					 gen_rx_popm_vector (acc_low, acc_high)));
	    }

	  emit_insn (gen_ashlsi3 (gen_rtx_REG (SImode, acc_low),
				  gen_rtx_REG (SImode, acc_low),
				  GEN_INT (16)));
	  emit_insn (gen_mvtaclo (gen_rtx_REG (SImode, acc_low)));
	  emit_insn (gen_mvtachi (gen_rtx_REG (SImode, acc_high)));
	}

      if (register_mask)
	{
	  for (reg = 0; reg < FIRST_PSEUDO_REGISTER; reg ++)
	    if (register_mask & (1 << reg))
	      emit_insn (gen_stack_pop (gen_rtx_REG (SImode, reg)));
	}
      else if (low)
	{
	  if (high == low)
	    emit_insn (gen_stack_pop (gen_rtx_REG (SImode, low)));
	  else
	    emit_insn (gen_stack_popm (GEN_INT (regs_size),
				       gen_rx_popm_vector (low, high)));
	}

      if (is_fast_interrupt_func (NULL_TREE))
	emit_jump_insn (gen_fast_interrupt_return ());
      else if (is_interrupt_func (NULL_TREE))
	emit_jump_insn (gen_exception_return ());
      else if (! is_sibcall)
	emit_jump_insn (gen_simple_return ());

      return;
    }

  /* If we allocated space on the stack, free it now.  */
  if (total_size)
    {
      unsigned HOST_WIDE_INT rtsd_size;

      /* See if we can use the RTSD instruction.  */
      rtsd_size = total_size + regs_size;
      if (rtsd_size < 1024 && (rtsd_size % 4) == 0)
	{
	  if (low)
	    emit_jump_insn (gen_pop_and_return
			    (GEN_INT (rtsd_size),
			     gen_rx_rtsd_vector (rtsd_size, low, high)));
	  else
	    emit_jump_insn (gen_deallocate_and_return (GEN_INT (total_size)));

	  return;
	}

      emit_insn (gen_addsi3 (stack_pointer_rtx, stack_pointer_rtx,
			     GEN_INT (total_size)));
    }

  if (low)
    emit_jump_insn (gen_pop_and_return (GEN_INT (regs_size),
					gen_rx_rtsd_vector (regs_size,
							    low, high)));
  else
    emit_jump_insn (gen_simple_return ());
}


/* Compute the offset (in words) between FROM (arg pointer
   or frame pointer) and TO (frame pointer or stack pointer).
   See ASCII art comment at the start of rx_expand_prologue
   for more information.  */

int
rx_initial_elimination_offset (int from, int to)
{
  unsigned int low;
  unsigned int high;
  unsigned int frame_size;
  unsigned int stack_size;
  unsigned int mask;

  rx_get_stack_layout (& low, & high, & mask, & frame_size, & stack_size);

  if (from == ARG_POINTER_REGNUM)
    {
      /* Extend the computed size of the stack frame to
	 include the registers pushed in the prologue.  */
      if (low)
	frame_size += ((high - low) + 1) * UNITS_PER_WORD;
      else
	frame_size += bit_count (mask) * UNITS_PER_WORD;

      /* Remember to include the return address.  */
      frame_size += 1 * UNITS_PER_WORD;

      if (to == FRAME_POINTER_REGNUM)
	return frame_size;

      gcc_assert (to == STACK_POINTER_REGNUM);
      return frame_size + stack_size;
    }

  gcc_assert (from == FRAME_POINTER_REGNUM && to == STACK_POINTER_REGNUM);
  return stack_size;
}

/* Update the status of the condition
   codes (cc0) based on the given INSN.  */

void
rx_notice_update_cc (rtx body, rtx insn)
{
  switch (get_attr_cc (insn))
    {
    case CC_NONE:
      /* Insn does not affect cc0 at all.  */
      break;
    case CC_CLOBBER:
      /* Insn doesn't leave cc0 in a usable state.  */
      CC_STATUS_INIT;
      break;
    case CC_SET_ZSOC:
      /* The insn sets all the condition code bits.  */
      CC_STATUS_INIT;
      cc_status.value1 = SET_SRC (body);
      break;
    case CC_SET_ZSO:
      /* Insn sets the Z,S and O flags, but not the C flag.  */
      CC_STATUS_INIT;
      cc_status.flags |= CC_NO_CARRY;
      /* Do not set the value1 field in this case.  The final_scan_insn()
	 function naively believes that if cc_status.value1 is set then
	 it can eliminate *any* comparison against that value, even if
	 the type of comparison cannot be satisfied by the range of flag
	 bits being set here.  See gcc.c-torture/execute/20041210-1.c
	 for an example of this in action.  */
      break;
    case CC_SET_ZS:
      /* Insn sets the Z and S flags, but not the O or C flags.  */
      CC_STATUS_INIT;
      cc_status.flags |= (CC_NO_CARRY | CC_NO_OVERFLOW);
      /* See comment above regarding cc_status.value1.  */
      break;
    default:
      gcc_unreachable ();
    }
}

/* Decide if a variable should go into one of the small data sections.  */

static bool
rx_in_small_data (const_tree decl)
{
  int size;
  const_tree section;

  if (rx_small_data_limit == 0)
    return false;

  if (TREE_CODE (decl) != VAR_DECL)
    return false;

  /* We do not put read-only variables into a small data area because
     they would be placed with the other read-only sections, far away
     from the read-write data sections, and we only have one small
     data area pointer.
     Similarly commons are placed in the .bss section which might be
     far away (and out of alignment with respect to) the .data section.  */
  if (TREE_READONLY (decl) || DECL_COMMON (decl))
    return false;

  section = DECL_SECTION_NAME (decl);
  if (section)
    {
      const char * const name = TREE_STRING_POINTER (section);

      return (strcmp (name, "D_2") == 0) || (strcmp (name, "B_2") == 0);
    }

  size = int_size_in_bytes (TREE_TYPE (decl));

  return (size > 0) && (size <= rx_small_data_limit);
}

/* Return a section for X.
   The only special thing we do here is to honor small data.  */

static section *
rx_select_rtx_section (enum machine_mode mode,
		       rtx x,
		       unsigned HOST_WIDE_INT align)
{
  if (rx_small_data_limit > 0
      && GET_MODE_SIZE (mode) <= rx_small_data_limit
      && align <= (unsigned HOST_WIDE_INT) rx_small_data_limit * BITS_PER_UNIT)
    return sdata_section;

  return default_elf_select_rtx_section (mode, x, align);
}

static section *
rx_select_section (tree decl,
		   int reloc,
		   unsigned HOST_WIDE_INT align)
{
  if (rx_small_data_limit > 0)
    {
      switch (categorize_decl_for_section (decl, reloc))
	{
	case SECCAT_SDATA:	return sdata_section;
	case SECCAT_SBSS:	return sbss_section;
	case SECCAT_SRODATA:
	  /* Fall through.  We do not put small, read only
	     data into the C_2 section because we are not
	     using the C_2 section.  We do not use the C_2
	     section because it is located with the other
	     read-only data sections, far away from the read-write
	     data sections and we only have one small data
	     pointer (r13).  */
	default:
	  break;
	}
    }

  /* If we are supporting the Renesas assembler
     we cannot use mergeable sections.  */
  if (TARGET_AS100_SYNTAX)
    switch (categorize_decl_for_section (decl, reloc))
      {
      case SECCAT_RODATA_MERGE_CONST:
      case SECCAT_RODATA_MERGE_STR_INIT:
      case SECCAT_RODATA_MERGE_STR:
	return readonly_data_section;

      default:
	break;
      }

  return default_elf_select_section (decl, reloc, align);
}

enum rx_builtin
{
  RX_BUILTIN_BRK,
  RX_BUILTIN_CLRPSW,
  RX_BUILTIN_INT,
  RX_BUILTIN_MACHI,
  RX_BUILTIN_MACLO,
  RX_BUILTIN_MULHI,
  RX_BUILTIN_MULLO,
  RX_BUILTIN_MVFACHI,
  RX_BUILTIN_MVFACMI,
  RX_BUILTIN_MVFC,
  RX_BUILTIN_MVTACHI,
  RX_BUILTIN_MVTACLO,
  RX_BUILTIN_MVTC,
  RX_BUILTIN_MVTIPL,
  RX_BUILTIN_RACW,
  RX_BUILTIN_REVW,
  RX_BUILTIN_RMPA,
  RX_BUILTIN_ROUND,
  RX_BUILTIN_SAT,
  RX_BUILTIN_SETPSW,
  RX_BUILTIN_WAIT,
  RX_BUILTIN_max
};

static void
rx_init_builtins (void)
{
#define ADD_RX_BUILTIN1(UC_NAME, LC_NAME, RET_TYPE, ARG_TYPE)		\
  add_builtin_function ("__builtin_rx_" LC_NAME,			\
			build_function_type_list (RET_TYPE##_type_node, \
						  ARG_TYPE##_type_node, \
						  NULL_TREE),		\
			RX_BUILTIN_##UC_NAME,				\
			BUILT_IN_MD, NULL, NULL_TREE)

#define ADD_RX_BUILTIN2(UC_NAME, LC_NAME, RET_TYPE, ARG_TYPE1, ARG_TYPE2) \
  add_builtin_function ("__builtin_rx_" LC_NAME,			\
			build_function_type_list (RET_TYPE##_type_node, \
						  ARG_TYPE1##_type_node,\
						  ARG_TYPE2##_type_node,\
						  NULL_TREE),		\
			RX_BUILTIN_##UC_NAME,				\
			BUILT_IN_MD, NULL, NULL_TREE)

#define ADD_RX_BUILTIN3(UC_NAME,LC_NAME,RET_TYPE,ARG_TYPE1,ARG_TYPE2,ARG_TYPE3) \
  add_builtin_function ("__builtin_rx_" LC_NAME,			\
			build_function_type_list (RET_TYPE##_type_node, \
						  ARG_TYPE1##_type_node,\
						  ARG_TYPE2##_type_node,\
						  ARG_TYPE3##_type_node,\
						  NULL_TREE),		\
			RX_BUILTIN_##UC_NAME,				\
			BUILT_IN_MD, NULL, NULL_TREE)

  ADD_RX_BUILTIN1 (BRK,     "brk",     void,  void);
  ADD_RX_BUILTIN1 (CLRPSW,  "clrpsw",  void,  integer);
  ADD_RX_BUILTIN1 (SETPSW,  "setpsw",  void,  integer);
  ADD_RX_BUILTIN1 (INT,     "int",     void,  integer);
  ADD_RX_BUILTIN2 (MACHI,   "machi",   void,  intSI, intSI);
  ADD_RX_BUILTIN2 (MACLO,   "maclo",   void,  intSI, intSI);
  ADD_RX_BUILTIN2 (MULHI,   "mulhi",   void,  intSI, intSI);
  ADD_RX_BUILTIN2 (MULLO,   "mullo",   void,  intSI, intSI);
  ADD_RX_BUILTIN1 (MVFACHI, "mvfachi", intSI, void);
  ADD_RX_BUILTIN1 (MVFACMI, "mvfacmi", intSI, void);
  ADD_RX_BUILTIN1 (MVTACHI, "mvtachi", void,  intSI);
  ADD_RX_BUILTIN1 (MVTACLO, "mvtaclo", void,  intSI);
  ADD_RX_BUILTIN1 (RMPA,    "rmpa",    void,  void);
  ADD_RX_BUILTIN1 (MVFC,    "mvfc",    intSI, integer);
  ADD_RX_BUILTIN2 (MVTC,    "mvtc",    void,  integer, integer);
  ADD_RX_BUILTIN1 (MVTIPL,  "mvtipl",  void,  integer);
  ADD_RX_BUILTIN1 (RACW,    "racw",    void,  integer);
  ADD_RX_BUILTIN1 (ROUND,   "round",   intSI, float);
  ADD_RX_BUILTIN1 (REVW,    "revw",    intSI, intSI);
  ADD_RX_BUILTIN1 (SAT,     "sat",     intSI, intSI);
  ADD_RX_BUILTIN1 (WAIT,    "wait",    void,  void);
}

static rtx
rx_expand_void_builtin_1_arg (rtx arg, rtx (* gen_func)(rtx), bool reg)
{
  if (reg && ! REG_P (arg))
    arg = force_reg (SImode, arg);

  emit_insn (gen_func (arg));

  return NULL_RTX;
}

static rtx
rx_expand_builtin_mvtc (tree exp)
{
  rtx arg1 = expand_normal (CALL_EXPR_ARG (exp, 0));
  rtx arg2 = expand_normal (CALL_EXPR_ARG (exp, 1));

  if (! CONST_INT_P (arg1))
    return NULL_RTX;

  if (! REG_P (arg2))
    arg2 = force_reg (SImode, arg2);

  emit_insn (gen_mvtc (arg1, arg2));

  return NULL_RTX;
}

static rtx
rx_expand_builtin_mvfc (tree t_arg, rtx target)
{
  rtx arg = expand_normal (t_arg);

  if (! CONST_INT_P (arg))
    return NULL_RTX;

  if (! REG_P (target))
    target = force_reg (SImode, target);

  emit_insn (gen_mvfc (target, arg));

  return target;
}

static rtx
rx_expand_builtin_mvtipl (rtx arg)
{
  /* The RX610 does not support the MVTIPL instruction.  */
  if (rx_cpu_type == RX610)
    return NULL_RTX;

  if (! CONST_INT_P (arg) || ! IN_RANGE (arg, 0, (1 << 4) - 1))
    return NULL_RTX;

  emit_insn (gen_mvtipl (arg));

  return NULL_RTX;
}

static rtx
rx_expand_builtin_mac (tree exp, rtx (* gen_func)(rtx, rtx))
{
  rtx arg1 = expand_normal (CALL_EXPR_ARG (exp, 0));
  rtx arg2 = expand_normal (CALL_EXPR_ARG (exp, 1));

  if (! REG_P (arg1))
    arg1 = force_reg (SImode, arg1);

  if (! REG_P (arg2))
    arg2 = force_reg (SImode, arg2);

  emit_insn (gen_func (arg1, arg2));

  return NULL_RTX;
}

static rtx
rx_expand_int_builtin_1_arg (rtx arg,
			     rtx target,
			     rtx (* gen_func)(rtx, rtx),
			     bool mem_ok)
{
  if (! REG_P (arg))
    if (!mem_ok || ! MEM_P (arg))
      arg = force_reg (SImode, arg);

  if (target == NULL_RTX || ! REG_P (target))
    target = gen_reg_rtx (SImode);

  emit_insn (gen_func (target, arg));

  return target;
}

static rtx
rx_expand_int_builtin_0_arg (rtx target, rtx (* gen_func)(rtx))
{
  if (target == NULL_RTX || ! REG_P (target))
    target = gen_reg_rtx (SImode);

  emit_insn (gen_func (target));

  return target;
}

static rtx
rx_expand_builtin_round (rtx arg, rtx target)
{
  if ((! REG_P (arg) && ! MEM_P (arg))
      || GET_MODE (arg) != SFmode)
    arg = force_reg (SFmode, arg);

  if (target == NULL_RTX || ! REG_P (target))
    target = gen_reg_rtx (SImode);

  emit_insn (gen_lrintsf2 (target, arg));

  return target;
}

static rtx
rx_expand_builtin (tree exp,
		   rtx target,
		   rtx subtarget ATTRIBUTE_UNUSED,
		   enum machine_mode mode ATTRIBUTE_UNUSED,
		   int ignore ATTRIBUTE_UNUSED)
{
  tree fndecl = TREE_OPERAND (CALL_EXPR_FN (exp), 0);
  tree arg    = CALL_EXPR_ARGS (exp) ? CALL_EXPR_ARG (exp, 0) : NULL_TREE;
  rtx  op     = arg ? expand_normal (arg) : NULL_RTX;
  unsigned int fcode = DECL_FUNCTION_CODE (fndecl);

  switch (fcode)
    {
    case RX_BUILTIN_BRK:     emit_insn (gen_brk ()); return NULL_RTX;
    case RX_BUILTIN_CLRPSW:  return rx_expand_void_builtin_1_arg
	(op, gen_clrpsw, false);
    case RX_BUILTIN_SETPSW:  return rx_expand_void_builtin_1_arg
	(op, gen_setpsw, false);
    case RX_BUILTIN_INT:     return rx_expand_void_builtin_1_arg
	(op, gen_int, false);
    case RX_BUILTIN_MACHI:   return rx_expand_builtin_mac (exp, gen_machi);
    case RX_BUILTIN_MACLO:   return rx_expand_builtin_mac (exp, gen_maclo);
    case RX_BUILTIN_MULHI:   return rx_expand_builtin_mac (exp, gen_mulhi);
    case RX_BUILTIN_MULLO:   return rx_expand_builtin_mac (exp, gen_mullo);
    case RX_BUILTIN_MVFACHI: return rx_expand_int_builtin_0_arg
	(target, gen_mvfachi);
    case RX_BUILTIN_MVFACMI: return rx_expand_int_builtin_0_arg
	(target, gen_mvfacmi);
    case RX_BUILTIN_MVTACHI: return rx_expand_void_builtin_1_arg
	(op, gen_mvtachi, true);
    case RX_BUILTIN_MVTACLO: return rx_expand_void_builtin_1_arg
	(op, gen_mvtaclo, true);
    case RX_BUILTIN_RMPA:    emit_insn (gen_rmpa ()); return NULL_RTX;
    case RX_BUILTIN_MVFC:    return rx_expand_builtin_mvfc (arg, target);
    case RX_BUILTIN_MVTC:    return rx_expand_builtin_mvtc (exp);
    case RX_BUILTIN_MVTIPL:  return rx_expand_builtin_mvtipl (op);
    case RX_BUILTIN_RACW:    return rx_expand_void_builtin_1_arg
	(op, gen_racw, false);
    case RX_BUILTIN_ROUND:   return rx_expand_builtin_round (op, target);
    case RX_BUILTIN_REVW:    return rx_expand_int_builtin_1_arg
	(op, target, gen_revw, false);
    case RX_BUILTIN_SAT:     return rx_expand_int_builtin_1_arg
	(op, target, gen_sat, false);
    case RX_BUILTIN_WAIT:    emit_insn (gen_wait ()); return NULL_RTX;

    default:
      internal_error ("bad builtin code");
      break;
    }

  return NULL_RTX;
}

/* Place an element into a constructor or destructor section.
   Like default_ctor_section_asm_out_constructor in varasm.c
   except that it uses .init_array (or .fini_array) and it
   handles constructor priorities.  */

static void
rx_elf_asm_cdtor (rtx symbol, int priority, bool is_ctor)
{
  section * s;

  if (priority != DEFAULT_INIT_PRIORITY)
    {
      char buf[18];

      sprintf (buf, "%s.%.5u",
	       is_ctor ? ".init_array" : ".fini_array",
	       priority);
      s = get_section (buf, SECTION_WRITE, NULL_TREE);
    }
  else if (is_ctor)
    s = ctors_section;
  else
    s = dtors_section;

  switch_to_section (s);
  assemble_align (POINTER_SIZE);
  assemble_integer (symbol, POINTER_SIZE / BITS_PER_UNIT, POINTER_SIZE, 1);
}

static void
rx_elf_asm_constructor (rtx symbol, int priority)
{
  rx_elf_asm_cdtor (symbol, priority, /* is_ctor= */true);
}

static void
rx_elf_asm_destructor (rtx symbol, int priority)
{
  rx_elf_asm_cdtor (symbol, priority, /* is_ctor= */false);
}

/* Check "fast_interrupt", "interrupt" and "naked" attributes.  */

static tree
rx_handle_func_attribute (tree * node,
			  tree   name,
			  tree   args,
			  int    flags ATTRIBUTE_UNUSED,
			  bool * no_add_attrs)
{
  gcc_assert (DECL_P (* node));
  gcc_assert (args == NULL_TREE);

  if (TREE_CODE (* node) != FUNCTION_DECL)
    {
      warning (OPT_Wattributes, "%qE attribute only applies to functions",
	       name);
      * no_add_attrs = true;
    }

  /* FIXME: We ought to check for conflicting attributes.  */

  /* FIXME: We ought to check that the interrupt and exception
     handler attributes have been applied to void functions.  */
  return NULL_TREE;
}

/* Table of RX specific attributes.  */
const struct attribute_spec rx_attribute_table[] =
{
  /* Name, min_len, max_len, decl_req, type_req, fn_type_req, handler.  */
  { "fast_interrupt", 0, 0, true, false, false, rx_handle_func_attribute },
  { "interrupt",      0, 0, true, false, false, rx_handle_func_attribute },
  { "naked",          0, 0, true, false, false, rx_handle_func_attribute },
  { NULL,             0, 0, false, false, false, NULL }
};

static bool
rx_allocate_stack_slots_for_args (void)
{
  /* Naked functions should not allocate stack slots for arguments.  */
  return ! is_naked_func (NULL_TREE);
}

static bool
rx_func_attr_inlinable (const_tree decl)
{
  return ! is_fast_interrupt_func (decl)
    &&   ! is_interrupt_func (decl)
    &&   ! is_naked_func (decl);  
}

static void
rx_file_start (void)
{
  if (! TARGET_AS100_SYNTAX)
    default_file_start ();
}

static bool
rx_is_ms_bitfield_layout (const_tree record_type ATTRIBUTE_UNUSED)
{
  return TRUE;
}

/* Try to generate code for the "isnv" pattern which inserts bits
   into a word.
     operands[0] => Location to be altered.
     operands[1] => Number of bits to change.
     operands[2] => Starting bit.
     operands[3] => Value to insert.
   Returns TRUE if successful, FALSE otherwise.  */

bool
rx_expand_insv (rtx * operands)
{
  if (INTVAL (operands[1]) != 1
      || ! CONST_INT_P (operands[3]))
    return false;

  if (MEM_P (operands[0])
      && INTVAL (operands[2]) > 7)
    return false;

  switch (INTVAL (operands[3]))
    {
    case 0:
      if (MEM_P (operands[0]))
	emit_insn (gen_bitclr_in_memory (operands[0], operands[0],
					 operands[2]));
      else
	emit_insn (gen_bitclr (operands[0], operands[0], operands[2]));
      break;
    case 1:
    case -1:
      if (MEM_P (operands[0]))
	emit_insn (gen_bitset_in_memory (operands[0], operands[0],
					 operands[2]));
      else
	emit_insn (gen_bitset (operands[0], operands[0], operands[2]));
      break;
   default:
      return false;
    }
  return true;
}

/* Returns true if X a legitimate constant for an immediate
   operand on the RX.  X is already known to satisfy CONSTANT_P.  */

bool
rx_is_legitimate_constant (rtx x)
{
  HOST_WIDE_INT val;

  switch (GET_CODE (x))
    {
    case CONST:
      x = XEXP (x, 0);

      if (GET_CODE (x) == PLUS)
	{
	  if (! CONST_INT_P (XEXP (x, 1)))
	    return false;

	  /* GCC would not pass us CONST_INT + CONST_INT so we
	     know that we have {SYMBOL|LABEL} + CONST_INT.  */
	  x = XEXP (x, 0);
	  gcc_assert (! CONST_INT_P (x));
	}

      switch (GET_CODE (x))
	{
	case LABEL_REF:
	case SYMBOL_REF:
	  return true;

	  /* One day we may have to handle UNSPEC constants here.  */
	default:
	  /* FIXME: Can this ever happen ?  */
	  abort ();
	  return false;
	}
      break;
      
    case LABEL_REF:
    case SYMBOL_REF:
      return true;
    case CONST_DOUBLE:
      return rx_max_constant_size == 0;
    case CONST_VECTOR:
      return false;
    default:
      gcc_assert (CONST_INT_P (x));
      break;
    }

  if (rx_max_constant_size == 0)
    /* If there is no constraint on the size of constants
       used as operands, then any value is legitimate.  */
    return true;

  val = INTVAL (x);

  /* rx_max_constant_size specifies the maximum number
     of bytes that can be used to hold a signed value.  */
  return IN_RANGE (val, (-1 << (rx_max_constant_size * 8)),
		        ( 1 << (rx_max_constant_size * 8)));
}

/* This is a tri-state variable.  The default value of 0 means that the user
   has specified neither -mfpu nor -mnofpu on the command line.  In this case
   the selection of RX FPU instructions is entirely based upon the size of
   the floating point object and whether unsafe math optimizations were
   enabled.  If 32-bit doubles have been enabled then both floats and doubles
   can make use of FPU instructions, otherwise only floats may do so.

   If the value is 1 then the user has specified -mfpu and the FPU
   instructions should be used.  Unsafe math optimizations will automatically
   be enabled and doubles set to 32-bits.  If the value is -1 then -mnofpu
   has been specified and FPU instructions will not be used, even if unsafe
   math optimizations have been enabled.  */
int rx_enable_fpu = 0;

/* Extra processing for target specific command line options.  */

static bool
rx_handle_option (size_t code, const char *  arg ATTRIBUTE_UNUSED, int value)
{
  switch (code)
    {
      /* -mfpu enables the use of RX FPU instructions.  This implies the use
	 of 32-bit doubles and also the enabling of fast math optimizations.
	 (Since the RX FPU instructions are not IEEE compliant).  The -mnofpu
	 option disables the use of RX FPU instructions, but does not make
	 place any constraints on the size of doubles or the use of fast math
	 optimizations.

	 The selection of 32-bit vs 64-bit doubles is handled by the setting
	 of the 32BIT_DOUBLES mask in the rx.opt file.  Enabling fast math
	 optimizations is performed in OVERRIDE_OPTIONS since if it was done
	 here it could be overridden by a -fno-fast-math option specified
	 *earlier* on the command line.  (Target specific options are
	 processed before generic ones).  */
    case OPT_fpu:
      rx_enable_fpu = 1;
      break;

    case OPT_nofpu:
      rx_enable_fpu = -1;
      break;

    case OPT_mint_register_:
      switch (value)
	{
	case 4:
	  fixed_regs[10] = call_used_regs [10] = 1;
	  /* Fall through.  */
	case 3:
	  fixed_regs[11] = call_used_regs [11] = 1;
	  /* Fall through.  */
	case 2:
	  fixed_regs[12] = call_used_regs [12] = 1;
	  /* Fall through.  */
	case 1:
	  fixed_regs[13] = call_used_regs [13] = 1;
	  /* Fall through.  */
	case 0:
	  return true;
	default:
	  return false;
	}
      break;

    case OPT_mmax_constant_size_:
      /* Make sure that the -mmax-constant_size option is in range.  */
      return IN_RANGE (value, 0, 4);

    case OPT_mcpu_:
    case OPT_patch_:
      if (strcasecmp (arg, "RX610") == 0)
	rx_cpu_type = RX610;
      /* FIXME: Should we check for non-RX cpu names here ?  */
      break;
      
    default:
      break;
    }

  return true;
}

static int
rx_address_cost (rtx addr, bool speed)
{
  rtx a, b;

  if (GET_CODE (addr) != PLUS)
    return COSTS_N_INSNS (1);

  a = XEXP (addr, 0);
  b = XEXP (addr, 1);

  if (REG_P (a) && REG_P (b))
    /* Try to discourage REG+REG addressing as it keeps two registers live.  */
    return COSTS_N_INSNS (4);

  if (speed)
    /* [REG+OFF] is just as fast as [REG].  */
    return COSTS_N_INSNS (1);

  if (CONST_INT_P (b)
      && ((INTVAL (b) > 128) || INTVAL (b) < -127))
    /* Try to discourage REG + <large OFF> when optimizing for size.  */
    return COSTS_N_INSNS (2);
    
  return COSTS_N_INSNS (1);
}

static bool
rx_can_eliminate (const int from ATTRIBUTE_UNUSED, const int to)
{
  /* We can always eliminate to the frame pointer.
     We can eliminate to the stack pointer unless a frame
     pointer is needed.  */

  return to == FRAME_POINTER_REGNUM
    || ( to == STACK_POINTER_REGNUM && ! frame_pointer_needed);
}


static void
rx_trampoline_template (FILE * file)
{
  /* Output assembler code for a block containing the constant
     part of a trampoline, leaving space for the variable parts.

     On the RX, (where r8 is the static chain regnum) the trampoline
     looks like:

	   mov 		#<static chain value>, r8
	   mov          #<function's address>, r9
	   jmp		r9

     In big-endian-data-mode however instructions are read into the CPU
     4 bytes at a time.  These bytes are then swapped around before being
     passed to the decoder.  So...we must partition our trampoline into
     4 byte packets and swap these packets around so that the instruction
     reader will reverse the process.  But, in order to avoid splitting
     the 32-bit constants across these packet boundaries, (making inserting
     them into the constructed trampoline very difficult) we have to pad the
     instruction sequence with NOP insns.  ie:

           nop
	   nop
           mov.l	#<...>, r8
	   nop
	   nop
           mov.l	#<...>, r9
           jmp		r9
	   nop
	   nop             */

  if (! TARGET_BIG_ENDIAN_DATA)
    {
      asm_fprintf (file, "\tmov.L\t#0deadbeefH, r%d\n", STATIC_CHAIN_REGNUM);
      asm_fprintf (file, "\tmov.L\t#0deadbeefH, r%d\n", TRAMPOLINE_TEMP_REGNUM);
      asm_fprintf (file, "\tjmp\tr%d\n",                TRAMPOLINE_TEMP_REGNUM);
    }
  else
    {
      char r8 = '0' + STATIC_CHAIN_REGNUM;
      char r9 = '0' + TRAMPOLINE_TEMP_REGNUM;

      if (TARGET_AS100_SYNTAX)
        {
          asm_fprintf (file, "\t.BYTE 0%c2H, 0fbH, 003H,  003H\n", r8);
          asm_fprintf (file, "\t.BYTE 0deH,  0adH, 0beH,  0efH\n");
          asm_fprintf (file, "\t.BYTE 0%c2H, 0fbH, 003H,  003H\n", r9);
          asm_fprintf (file, "\t.BYTE 0deH,  0adH, 0beH,  0efH\n");
          asm_fprintf (file, "\t.BYTE 003H,  003H, 00%cH, 07fH\n", r9);
        }
      else
        {
          asm_fprintf (file, "\t.byte 0x%c2, 0xfb, 0x03,  0x03\n", r8);
          asm_fprintf (file, "\t.byte 0xde,  0xad, 0xbe,  0xef\n");
          asm_fprintf (file, "\t.byte 0x%c2, 0xfb, 0x03,  0x03\n", r9);
          asm_fprintf (file, "\t.byte 0xde,  0xad, 0xbe,  0xef\n");
          asm_fprintf (file, "\t.byte 0x03,  0x03, 0x0%c, 0x7f\n", r9);
        }
    }
}

static void
rx_trampoline_init (rtx tramp, tree fndecl, rtx chain)
{
  rtx fnaddr = XEXP (DECL_RTL (fndecl), 0);

  emit_block_move (tramp, assemble_trampoline_template (),
		   GEN_INT (TRAMPOLINE_SIZE), BLOCK_OP_NORMAL);

  if (TARGET_BIG_ENDIAN_DATA)
    {
      emit_move_insn (adjust_address (tramp, SImode, 4), chain);
      emit_move_insn (adjust_address (tramp, SImode, 12), fnaddr);
    }
  else
    {
      emit_move_insn (adjust_address (tramp, SImode, 2), chain);
      emit_move_insn (adjust_address (tramp, SImode, 6 + 2), fnaddr);
    }
}

#undef  TARGET_FUNCTION_VALUE
#define TARGET_FUNCTION_VALUE		rx_function_value

#undef  TARGET_RETURN_IN_MSB
#define TARGET_RETURN_IN_MSB		rx_return_in_msb

#undef  TARGET_IN_SMALL_DATA_P
#define TARGET_IN_SMALL_DATA_P		rx_in_small_data

#undef  TARGET_RETURN_IN_MEMORY
#define TARGET_RETURN_IN_MEMORY		rx_return_in_memory

#undef  TARGET_HAVE_SRODATA_SECTION
#define TARGET_HAVE_SRODATA_SECTION	true

#undef	TARGET_ASM_SELECT_RTX_SECTION
#define	TARGET_ASM_SELECT_RTX_SECTION	rx_select_rtx_section

#undef	TARGET_ASM_SELECT_SECTION
#define	TARGET_ASM_SELECT_SECTION	rx_select_section

#undef  TARGET_INIT_BUILTINS
#define TARGET_INIT_BUILTINS		rx_init_builtins

#undef  TARGET_EXPAND_BUILTIN
#define TARGET_EXPAND_BUILTIN		rx_expand_builtin

#undef  TARGET_ASM_CONSTRUCTOR
#define TARGET_ASM_CONSTRUCTOR		rx_elf_asm_constructor

#undef  TARGET_ASM_DESTRUCTOR
#define TARGET_ASM_DESTRUCTOR		rx_elf_asm_destructor

#undef  TARGET_STRUCT_VALUE_RTX
#define TARGET_STRUCT_VALUE_RTX		rx_struct_value_rtx

#undef  TARGET_ATTRIBUTE_TABLE
#define TARGET_ATTRIBUTE_TABLE		rx_attribute_table

#undef  TARGET_ASM_FILE_START
#define TARGET_ASM_FILE_START			rx_file_start

#undef  TARGET_MS_BITFIELD_LAYOUT_P
#define TARGET_MS_BITFIELD_LAYOUT_P		rx_is_ms_bitfield_layout

#undef  TARGET_LEGITIMATE_ADDRESS_P
#define TARGET_LEGITIMATE_ADDRESS_P		rx_is_legitimate_address

#undef  TARGET_ALLOCATE_STACK_SLOTS_FOR_ARGS
#define TARGET_ALLOCATE_STACK_SLOTS_FOR_ARGS	rx_allocate_stack_slots_for_args

#undef  TARGET_ASM_FUNCTION_PROLOGUE
#define TARGET_ASM_FUNCTION_PROLOGUE 		rx_output_function_prologue

#undef  TARGET_FUNCTION_ATTRIBUTE_INLINABLE_P
#define TARGET_FUNCTION_ATTRIBUTE_INLINABLE_P 	rx_func_attr_inlinable

#undef  TARGET_SET_CURRENT_FUNCTION
#define TARGET_SET_CURRENT_FUNCTION		rx_set_current_function

#undef  TARGET_HANDLE_OPTION
#define TARGET_HANDLE_OPTION			rx_handle_option

#undef  TARGET_ASM_INTEGER
#define TARGET_ASM_INTEGER			rx_assemble_integer

#undef  TARGET_USE_BLOCKS_FOR_CONSTANT_P
#define TARGET_USE_BLOCKS_FOR_CONSTANT_P	hook_bool_mode_const_rtx_true

#undef  TARGET_MAX_ANCHOR_OFFSET
#define TARGET_MAX_ANCHOR_OFFSET		32

#undef  TARGET_ADDRESS_COST
#define TARGET_ADDRESS_COST			rx_address_cost

#undef  TARGET_CAN_ELIMINATE
#define TARGET_CAN_ELIMINATE			rx_can_eliminate

#undef  TARGET_ASM_TRAMPOLINE_TEMPLATE
#define TARGET_ASM_TRAMPOLINE_TEMPLATE		rx_trampoline_template

#undef  TARGET_TRAMPOLINE_INIT
#define TARGET_TRAMPOLINE_INIT			rx_trampoline_init

struct gcc_target targetm = TARGET_INITIALIZER;

/* #include "gt-rx.h" */
