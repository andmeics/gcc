------------------------------------------------------------------------------
--                                                                          --
--                         GNAT RUN-TIME COMPONENTS                         --
--                                                                          --
--                   A D A . E X E C U T I O N _ T I M E                    --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--            Copyright (C) 2007, Free Software Foundation, Inc.            --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 2,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License --
-- for  more details.  You should have  received  a copy of the GNU General --
-- Public License  distributed with GNAT;  see file COPYING.  If not, write --
-- to  the  Free Software Foundation,  51  Franklin  Street,  Fifth  Floor, --
-- Boston, MA 02110-1301, USA.                                              --
--                                                                          --
-- As a special exception,  if other files  instantiate  generics from this --
-- unit, or you link  this unit with other files  to produce an executable, --
-- this  unit  does not  by itself cause  the resulting  executable  to  be --
-- covered  by the  GNU  General  Public  License.  This exception does not --
-- however invalidate  any other reasons why  the executable file  might be --
-- covered by the  GNU Public License.                                      --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

--  This is the Windows native version of this package

with Ada.Task_Identification;           use Ada.Task_Identification;
with Ada.Unchecked_Conversion;

with System.OS_Interface;               use System.OS_Interface;
with System.Task_Primitives.Operations; use System.Task_Primitives.Operations;
with System.Tasking;                    use System.Tasking;

package body Ada.Execution_Time is

   ---------
   -- "+" --
   ---------

   function "+"
     (Left  : CPU_Time;
      Right : Ada.Real_Time.Time_Span) return CPU_Time
   is
      use type Ada.Real_Time.Time;
   begin
      return CPU_Time (Ada.Real_Time.Time (Left) + Right);
   end "+";

   function "+"
     (Left  : Ada.Real_Time.Time_Span;
      Right : CPU_Time) return CPU_Time
   is
      use type Ada.Real_Time.Time;
   begin
      return CPU_Time (Left + Ada.Real_Time.Time (Right));
   end "+";

   ---------
   -- "-" --
   ---------

   function "-"
     (Left  : CPU_Time;
      Right : Ada.Real_Time.Time_Span) return CPU_Time
   is
      use type Ada.Real_Time.Time;
   begin
      return CPU_Time (Ada.Real_Time.Time (Left) - Right);
   end "-";

   function "-"
     (Left  : CPU_Time;
      Right : CPU_Time) return Ada.Real_Time.Time_Span
   is
      use type Ada.Real_Time.Time;
   begin
      return (Ada.Real_Time.Time (Left) - Ada.Real_Time.Time (Right));
   end "-";

   -----------
   -- Clock --
   -----------

   function Clock
     (T : Ada.Task_Identification.Task_Id :=
            Ada.Task_Identification.Current_Task) return CPU_Time
   is
      Hundreds_Nano_In_Sec : constant Long_Long_Float := 1.0E7;

      function To_Time is new Ada.Unchecked_Conversion
        (Duration, Ada.Real_Time.Time);

      function To_Task_Id is new Ada.Unchecked_Conversion
        (Ada.Task_Identification.Task_Id, System.Tasking.Task_Id);

      C_Time : aliased Long_Long_Integer;
      E_Time : aliased Long_Long_Integer;
      K_Time : aliased Long_Long_Integer;
      U_Time : aliased Long_Long_Integer;
      Res    : BOOL;

   begin
      if T = Ada.Task_Identification.Null_Task_Id then
         raise Program_Error;
      end if;

      Res :=
        GetThreadTimes
          (HANDLE (Get_Thread_Id (To_Task_Id (T))),
           C_Time'Access, E_Time'Access, K_Time'Access, U_Time'Access);

      if Res = False then
         raise Program_Error;
      end if;

      return
        CPU_Time
          (To_Time
             (Duration
                ((Long_Long_Float (K_Time) / Hundreds_Nano_In_Sec)
                 + (Long_Long_Float (U_Time) / Hundreds_Nano_In_Sec))));
   end Clock;

   -----------
   -- Split --
   -----------

   procedure Split
     (T  : CPU_Time;
      SC : out Ada.Real_Time.Seconds_Count;
      TS : out Ada.Real_Time.Time_Span)
   is
      use type Ada.Real_Time.Time;
   begin
      Ada.Real_Time.Split (Ada.Real_Time.Time (T), SC, TS);
   end Split;

   -------------
   -- Time_Of --
   -------------

   function Time_Of
     (SC : Ada.Real_Time.Seconds_Count;
      TS : Ada.Real_Time.Time_Span := Ada.Real_Time.Time_Span_Zero)
      return CPU_Time
   is
   begin
      return CPU_Time (Ada.Real_Time.Time_Of (SC, TS));
   end Time_Of;

end Ada.Execution_Time;
