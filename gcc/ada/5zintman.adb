------------------------------------------------------------------------------
--                                                                          --
--                GNU ADA RUN-TIME LIBRARY (GNARL) COMPONENTS               --
--                                                                          --
--           S Y S T E M . I N T E R R U P T _ M A N A G E M E N T          --
--                                                                          --
--                                  B o d y                                 --
--                                                                          --
--          Copyright (C) 1992-2003 Free Software Foundation, Inc.          --
--                                                                          --
-- GNARL is free software; you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 2,  or (at your option) any later ver- --
-- sion. GNARL is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License --
-- for  more details.  You should have  received  a copy of the GNU General --
-- Public License  distributed with GNARL; see file COPYING.  If not, write --
-- to  the Free Software Foundation,  59 Temple Place - Suite 330,  Boston, --
-- MA 02111-1307, USA.                                                      --
--                                                                          --
-- As a special exception,  if other files  instantiate  generics from this --
-- unit, or you link  this unit with other files  to produce an executable, --
-- this  unit  does not  by itself cause  the resulting  executable  to  be --
-- covered  by the  GNU  General  Public  License.  This exception does not --
-- however invalidate  any other reasons why  the executable file  might be --
-- covered by the  GNU Public License.                                      --
--                                                                          --
-- GNARL was developed by the GNARL team at Florida State University.       --
-- Extensive contributions were provided by Ada Core Technologies, Inc.     --
--                                                                          --
------------------------------------------------------------------------------

--  This is the VxWorks version of this package.

--  It is likely to need tailoring to fit each operating system
--  and machine architecture.

--  PLEASE DO NOT add any dependences on other packages.
--  This package is designed to work with or without tasking support.

--  See the other warnings in the package specification before making
--  any modifications to this file.

--  Make a careful study of all signals available under the OS,
--  to see which need to be reserved, kept always unmasked,
--  or kept always unmasked.
--  Be on the lookout for special signals that
--  may be used by the thread library.

with Interfaces.C;

with System.OS_Interface;
--  used for various Constants, Signal and types

with Ada.Exceptions;
--  used for Raise_Exception

package body System.Interrupt_Management is

   use Ada.Exceptions;
   use System.OS_Interface;
   use type Interfaces.C.int;

   type Signal_List is array (Signal_ID range <>) of Signal_ID;
   Exception_Signals : constant Signal_List (1 .. 4) :=
                         (SIGFPE, SIGILL, SIGSEGV, SIGBUS);

   --  Keep these variables global so that they are initialized only once
   --  What are "these variables" ???, I see only one

   Exception_Action : aliased struct_sigaction;

   -----------------------
   -- Local Subprograms --
   -----------------------

   procedure Notify_Exception (signo : Signal);
   --  Identify the Ada exception to be raised using
   --  the information when the system received a synchronous signal.

   ----------------------
   -- Notify_Exception --
   ----------------------

   procedure Notify_Exception (signo : Signal) is
      Mask   : aliased sigset_t;
      Result : int;
      My_Id  : t_id;

   begin
      Result := pthread_sigmask (SIG_SETMASK, null, Mask'Unchecked_Access);
      Result := sigdelset (Mask'Access, signo);
      Result := pthread_sigmask (SIG_SETMASK, Mask'Unchecked_Access, null);

      --  VxWorks will suspend the task when it gets a hardware
      --  exception.  We take the liberty of resuming the task
      --  for the application.

      My_Id := taskIdSelf;

      if taskIsSuspended (My_Id) /= 0 then
         Result := taskResume (My_Id);
      end if;

      case signo is
         when SIGFPE =>
            Raise_Exception (Constraint_Error'Identity, "SIGFPE");
         when SIGILL =>
            Raise_Exception (Constraint_Error'Identity, "SIGILL");
         when SIGSEGV =>
            Raise_Exception
              (Program_Error'Identity,
               "stack overflow or erroneous memory access");
         when SIGBUS =>
            Raise_Exception (Program_Error'Identity, "SIGBUS");
         when others =>
            Raise_Exception (Program_Error'Identity, "unhandled signal");
      end case;
   end Notify_Exception;

   ---------------------------
   -- Initialize_Interrupts --
   ---------------------------

   --  Since there is no signal inheritance between VxWorks tasks, we need
   --  to initialize signal handling in each task.

   procedure Initialize_Interrupts is
      Result  : int;
      old_act : aliased struct_sigaction;

   begin
      for J in Exception_Signals'Range loop
         Result :=
           sigaction
             (Signal (Exception_Signals (J)), Exception_Action'Access,
              old_act'Unchecked_Access);
         pragma Assert (Result = 0);
      end loop;
   end Initialize_Interrupts;

begin
   declare
      mask   : aliased sigset_t;
      Result : int;

      function State (Int : Interrupt_ID) return Character;
      pragma Import (C, State, "__gnat_get_interrupt_state");
      --  Get interrupt state.  Defined in a-init.c
      --  The input argument is the interrupt number,
      --  and the result is one of the following:

      Runtime : constant Character := 'r';
      Default : constant Character := 's';
      --    'n'   this interrupt not set by any Interrupt_State pragma
      --    'u'   Interrupt_State pragma set state to User
      --    'r'   Interrupt_State pragma set state to Runtime
      --    's'   Interrupt_State pragma set state to System (use "default"
      --           system handler)

   begin
      --  Initialize signal handling

      --  Change this if you want to use another signal for task abort.
      --  SIGTERM might be a good one.

      Abort_Task_Signal := SIGABRT;

      Exception_Action.sa_handler := Notify_Exception'Address;
      Exception_Action.sa_flags := SA_ONSTACK;
      Result := sigemptyset (mask'Access);
      pragma Assert (Result = 0);

      for J in Exception_Signals'Range loop
         Result := sigaddset (mask'Access, Signal (Exception_Signals (J)));
         pragma Assert (Result = 0);
      end loop;

      Exception_Action.sa_mask := mask;

      --  Initialize hardware interrupt handling

      pragma Assert (Reserve = (Interrupt_ID'Range => False));

      --  Check all interrupts for state that requires keeping them reserved

      for J in Interrupt_ID'Range loop
         if State (J) = Default or else State (J) = Runtime then
            Reserve (J) := True;
         end if;
      end loop;

      --  Add exception signals to the set of unmasked signals

      for J in Exception_Signals'Range loop
         Keep_Unmasked (Exception_Signals (J)) := True;
      end loop;

      --  The abort signal must also be unmasked

      Keep_Unmasked (Abort_Task_Signal) := True;
   end;
end System.Interrupt_Management;
