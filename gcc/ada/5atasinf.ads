------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--                     S Y S T E M . T A S K _ I N F O                      --
--                                                                          --
--                                 S p e c                                  --
--                           (Compiler Interface)                           --
--                                                                          --
--                            $Revision: 1.1 $
--                                                                          --
--         Copyright (C) 1998-2000 Free Software Foundation, Inc.           --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 2,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License --
-- for  more details.  You should have  received  a copy of the GNU General --
-- Public License  distributed with GNAT;  see file COPYING.  If not, write --
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
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

--  This is a DEC Unix 4.0d version of this package.

--  This package contains the definitions and routines associated with the
--  implementation of the Task_Info pragma.

--  Note: the compiler generates direct calls to this interface, via Rtsfind.
--  Any changes to this interface may require corresponding compiler changes.

with Unchecked_Deallocation;
package System.Task_Info is
pragma Elaborate_Body;
--  To ensure that a body is allowed

   -----------------------------------------
   -- Implementation of Task_Info Feature --
   -----------------------------------------

   --  The Task_Info pragma:

   --    pragma Task_Info (EXPRESSION);

   --  allows the specification on a task by task basis of a value of type
   --  System.Task_Info.Task_Info_Type to be passed to a task when it is
   --  created. The specification of this type, and the effect on the task
   --  that is created is target dependent.

   --  The Task_Info pragma appears within a task definition (compare the
   --  definition and implementation of pragma Priority). If no such pragma
   --  appears, then the value Task_Info_Unspecified is passed. If a pragma
   --  is present, then it supplies an alternative value. If the argument of
   --  the pragma is a discriminant reference, then the value can be set on
   --  a task by task basis by supplying the appropriate discriminant value.

   --  Note that this means that the type used for Task_Info_Type must be
   --  suitable for use as a discriminant (i.e. a scalar or access type).

   ------------------
   -- Declarations --
   ------------------

   type Scope_Type is
     (Process_Scope,
      --  Contend only with threads in same process

      System_Scope,
      --  Contend with all threads on same CPU

      Default_Scope);

   type Thread_Attributes is record
      Bind_To_Cpu_Number : Integer;
      --   -1: Do nothing
      --    0: Unbind
      --  1-N: Bind all unbound threads to this CPU

      Contention_Scope   : Scope_Type;
   end record;

   type Task_Info_Type is access all Thread_Attributes;
   --  Type used for passing information to task create call, using the
   --  Task_Info pragma. This type may be specialized for individual
   --  implementations, but it must be a type that can be used as a
   --  discriminant (i.e. a scalar or access type).

   type Task_Image_Type is access String;
   --  Used to generate a meaningful identifier for tasks that are variables
   --  and components of variables.

   procedure Free_Task_Image is new
     Unchecked_Deallocation (String, Task_Image_Type);

   Unspecified_Thread_Attribute : aliased Thread_Attributes :=
     Thread_Attributes'(-1, Default_Scope);

   Unspecified_Task_Info : constant Task_Info_Type :=
     Unspecified_Thread_Attribute'Access;
   --  Value passed to task in the absence of a Task_Info pragma
   --  Don't call new here because the tasking run time has not been
   --  elaborated yet, so calling Task_Lock is unsafe.

end System.Task_Info;
