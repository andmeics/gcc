/* DWARF2 EH unwinding support for TPF OS.
   Copyright (C) 2004 Free Software Foundation, Inc.
   Contributed by P.J. Darcy (darcypj@us.ibm.com).

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file into combinations with other programs,
and to distribute those combinations without any restriction coming
from the use of this file.  (The General Public License restrictions
do apply in other respects; for example, they cover modification of
the file, and distribution when not linked into a combined
executable.)

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  */

#define __USE_GNU 1
#define _GNU_SOURCE
#include <dlfcn.h>
#undef __USE_GNU
#undef _GNU_SOURCE

/* Function Name: __isPATrange
   Parameters passed into it:  address to check
   Return Value: A 1 if address is in pat code "range", 0 if not
   Description: This function simply checks to see if the address
   passed to it is in the CP pat code range.  */

#define MIN_PATRANGE 0x10000
#define MAX_PATRANGE 0x800000

static inline unsigned int
__isPATrange (void *addr)
{
  if (addr > (void *)MIN_PATRANGE && addr < (void *)MAX_PATRANGE)
    return 1;
  else
    return 0;
}

/* TPF stack placeholder offset.  */
#define TPF_LOC_DIFF_OFFSET 168

/* Exceptions macro defined for TPF so that functions without 
   dwarf frame information can be used with exceptions.  */
#define MD_FALLBACK_FRAME_STATE_FOR s390_fallback_frame_state

static _Unwind_Reason_Code
s390_fallback_frame_state (struct _Unwind_Context *context,
			   _Unwind_FrameState *fs)
{
  unsigned long int regs;
  unsigned long int new_cfa;
  int i;

  if (context->cfa == NULL)
    return _URC_END_OF_STACK;

  /* Are we going through special linkage code?  */
  if (__isPATrange (context->ra))
    {
      /* No stack frame.  */
      fs->cfa_how = CFA_REG_OFFSET;
      fs->cfa_reg = 15;
      fs->cfa_offset = STACK_POINTER_OFFSET;

      /* All registers remain unchanged ...  */
      for (i = 0; i < 32; i++)
	{
	  fs->regs.reg[i].how = REG_SAVED_REG;
	  fs->regs.reg[i].loc.reg = i;
	}

      /* ... except for %r14, which is stored at CFA-112
	 and used as return address.  */
      fs->regs.reg[14].how = REG_SAVED_OFFSET;
      fs->regs.reg[14].loc.offset = TPF_LOC_DIFF_OFFSET - STACK_POINTER_OFFSET;
      fs->retaddr_column = 14;

      return _URC_NO_REASON;
    }

  regs = *((unsigned long int *)
        (((unsigned long int) context->cfa) - STACK_POINTER_OFFSET));
  new_cfa = regs + STACK_POINTER_OFFSET;

  fs->cfa_how = CFA_REG_OFFSET;
  fs->cfa_reg = 15;
  fs->cfa_offset = new_cfa -
        (unsigned long int) context->cfa + STACK_POINTER_OFFSET;

  for (i = 0; i < 16; i++)
    {
      fs->regs.reg[i].how = REG_SAVED_OFFSET;
      fs->regs.reg[i].loc.offset = regs + i*8 - new_cfa;
    }

  for (i = 0; i < 4; i++)
    {
      fs->regs.reg[16 + i].how = REG_SAVED_OFFSET;
      fs->regs.reg[16 + i].loc.offset = regs + 16*8 + i*8 - new_cfa;
    }

  fs->retaddr_column = 14;

  return _URC_NO_REASON;
}

/* Function Name: __tpf_eh_return
   Parameters passed into it: Destination address to jump to.
   Return Value: Converted Destination address if a Pat Stub exists.
   Description: This function swaps the unwinding return address
      with the cp stub code.  The original target return address is
      then stored into the tpf return address field.  The cp stub
      code is searched for by climbing back up the stack and
      comparing the tpf stored return address object address to
      that of the targets object address.  */

#define CURRENT_STACK_PTR() \
  ({ register unsigned long int *stack_ptr asm ("%r15"); stack_ptr; })

#define PREVIOUS_STACK_PTR() \
  ((unsigned long int *)(*(CURRENT_STACK_PTR())))

#define RA_OFFSET_FROM_START_OF_STACK_FRAME 112
#define CURRENT_STACK_PTR_OFFSET 120
#define TPFRA_OFFSET_FROM_START_OF_STACK_FRAME 168
#define INVALID_RETURN 0

void * __tpf_eh_return (void *target);

void *
__tpf_eh_return (void *target)
{
  Dl_info targetcodeInfo, currentcodeInfo;
  int retval;
  void *current, *stackptr;
  unsigned long int shifter;

  /* Get code info for target return's address.  */
  retval = dladdr (target, &targetcodeInfo);

  /* Get the return address of the stack frame to be replaced by
     the exception unwinder.  So that the __cxa_throw return is
     replaced by the target return.  */
  current = (void *) *((unsigned long int *)
                 ((*((unsigned long int *)*(PREVIOUS_STACK_PTR()))) 
                             + RA_OFFSET_FROM_START_OF_STACK_FRAME));

  /* Ensure the code info is valid (for target).  */
  if (retval != INVALID_RETURN) 
    {
      /* Now check to see if the current RA is a PAT
         stub return address.  */
      if ( __isPATrange(current)) 
        {
          /* It was!  Then go into the TPF private stack area and fetch
             the real address.  */
          current = (void *) *((unsigned long int *) 
                           ((unsigned long int)*((unsigned long int *)
                           *(PREVIOUS_STACK_PTR())) 
                           +TPFRA_OFFSET_FROM_START_OF_STACK_FRAME));
        }

      /* Get code info for current return address.  */
      retval = dladdr (current, &currentcodeInfo);

      /* Ensure the code info is valid (for current frame).  */
      if (retval != INVALID_RETURN) 
        {
          /* Get the stack pointer of the stack frame to be replaced by
             the exception unwinder.  So that we can begin our climb
             there.  */
          stackptr = (void *) (*((unsigned long int *)
                      (*((unsigned long int *)(*(PREVIOUS_STACK_PTR()))))));

          /* Begin looping through stack frames.  Stop if invalid
             code information is retrieved or if a match between the
             current stack frame iteration shared object's address 
             matches that of the target, calculated above.  */
          while (retval != INVALID_RETURN
                 && targetcodeInfo.dli_fbase != currentcodeInfo.dli_fbase)
            {
              /* Get return address based on our stackptr iterator.  */
              current = (void *) *((unsigned long int *) 
                     (stackptr+RA_OFFSET_FROM_START_OF_STACK_FRAME));

              /* Is it a Pat Stub?  */
              if (__isPATrange (current)) 
                {
                  /* Yes it was, get real return address 
                     in TPF stack area.  */
                  current = (void *) *((unsigned long int *) 
                         (stackptr+TPFRA_OFFSET_FROM_START_OF_STACK_FRAME));
                }

              /* Get codeinfo on RA so that we can figure out
                 the module address.  */
              retval = dladdr (current, &currentcodeInfo);

              /* Check that codeinfo for current stack frame is valid.
                 Then compare the module address of current stack frame
                 to target stack frame to determine if we have the pat
                 stub address we want.  */
              if (retval != INVALID_RETURN
                  && targetcodeInfo.dli_fbase == currentcodeInfo.dli_fbase)
                {
                  /* Yes!  They are in the same module.  Now store the
                     real target address into the TPF stack area of
                     the target frame we are jumping to.  */
                  *((unsigned long int *)(*((unsigned long int *) 
                          (*PREVIOUS_STACK_PTR() + CURRENT_STACK_PTR_OFFSET))
                          + TPFRA_OFFSET_FROM_START_OF_STACK_FRAME)) 
                          = (unsigned long int) target;

                  /* Before returning the desired pat stub address to
                     the exception handling unwinder so that it can 
                     actually do the "leap" shift out the low order 
                     bit designated to determine if we are in 64BIT mode.
                     This is necessary for CTOA stubs.
                     Otherwise we leap one byte past where we want to 
                     go to in the TPF pat stub linkage code.  */
                  shifter = *((unsigned long int *) 
                       (stackptr + RA_OFFSET_FROM_START_OF_STACK_FRAME));

                  shifter &= ~1ul;

                  return (void *) shifter;
                }

              /* Desired module pat stub not found ...
                 Bump stack frame iterator.  */
              stackptr = (void *) *(unsigned long int *) stackptr;
            }
        }
    }

  /* No pat stub found, could be a problem?  Simply return unmodified
     target address.  */
  return target;
}


