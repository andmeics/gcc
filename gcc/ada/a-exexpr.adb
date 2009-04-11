------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--  A D A . E X C E P T I O N S . E X C E P T I O N _ P R O P A G A T I O N --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--          Copyright (C) 1992-2009, Free Software Foundation, Inc.         --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 3,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.                                     --
--                                                                          --
-- As a special exception under Section 7 of GPL version 3, you are granted --
-- additional permissions described in the GCC Runtime Library Exception,   --
-- version 3.1, as published by the Free Software Foundation.               --
--                                                                          --
-- You should have received a copy of the GNU General Public License and    --
-- a copy of the GCC Runtime Library Exception along with this program;     --
-- see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see    --
-- <http://www.gnu.org/licenses/>.                                          --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

--  This is the default version, using the __builtin_setjmp/longjmp EH
--  mechanism.

with System.Storage_Elements;  use System.Storage_Elements;

pragma Warnings (Off);
--  Since several constructs give warnings in 3.14a1, including unreferenced
--  variables and pragma Unreferenced itself.

separate (Ada.Exceptions)
package body Exception_Propagation is

   procedure builtin_longjmp (buffer : Address; Flag : Integer);
   pragma No_Return (builtin_longjmp);
   pragma Import (C, builtin_longjmp, "_gnat_builtin_longjmp");

   ---------------------
   -- Setup_Exception --
   ---------------------

   procedure Setup_Exception
     (Excep    : EOA;
      Current  : EOA;
      Reraised : Boolean := False)
   is
      pragma Unreferenced (Excep, Current, Reraised);
   begin
      --  In the GNAT-SJLJ case this "stack" only exists implicitly, by way of
      --  local occurrence declarations together with save/restore operations
      --  generated by the front-end, and this routine has nothing to do.

      null;
   end Setup_Exception;

   -------------------------
   -- Propagate_Exception --
   -------------------------

   procedure Propagate_Exception
     (E                   : Exception_Id;
      From_Signal_Handler : Boolean)
   is
      pragma Inspection_Point (E);

      Jumpbuf_Ptr : constant Address := Get_Jmpbuf_Address.all;
      Excep       : constant EOA := Get_Current_Excep.all;
   begin
      --  Compute the backtrace for this occurrence if corresponding binder
      --  option has been set. Call_Chain takes care of the reraise case.

      Call_Chain (Excep);

      --  Note on above call to Call_Chain:

      --  We used to only do this if From_Signal_Handler was not set,
      --  based on the assumption that backtracing from a signal handler
      --  would not work due to stack layout oddities. However, since

      --   1. The flag is never set in tasking programs (Notify_Exception
      --      performs regular raise statements), and

      --   2. No problem has shown up in tasking programs around here so
      --      far, this turned out to be too strong an assumption.

      --  As, in addition, the test was

      --   1. preventing the production of backtraces in non-tasking
      --      programs, and

      --   2. introducing a behavior inconsistency between
      --      the tasking and non-tasking cases,

      --  we have simply removed it

      --  If the jump buffer pointer is non-null, transfer control using
      --  it. Otherwise announce an unhandled exception (note that this
      --  means that we have no finalizations to do other than at the outer
      --  level). Perform the necessary notification tasks in both cases.

      if Jumpbuf_Ptr /= Null_Address then
         if not Excep.Exception_Raised then
            Excep.Exception_Raised := True;
            Exception_Traces.Notify_Handled_Exception;
         end if;

         builtin_longjmp (Jumpbuf_Ptr, 1);

      else
         Exception_Traces.Notify_Unhandled_Exception;
         Exception_Traces.Unhandled_Exception_Terminate;
      end if;
   end Propagate_Exception;

end Exception_Propagation;
