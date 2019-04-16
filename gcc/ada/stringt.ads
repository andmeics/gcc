------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--                              S T R I N G T                               --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--          Copyright (C) 1992-2019, Free Software Foundation, Inc.         --
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

with Namet;  use Namet;
with System; use System;
with Types;  use Types;

package Stringt is
   pragma Elaborate_Body;
   --  This is to make sure Null_String_Id is properly initialized

--  This package contains routines for handling the strings table which is
--  used to store string constants encountered in the source, and also those
--  additional string constants generated by compile time concatenation and
--  other similar processing.

--  A string constant in this table consists of a series of Char_Code values,
--  so that 16-bit character codes can be properly handled if this feature
--  is implemented in the scanner.

--  There is no guarantee that hashing is used in the implementation, although
--  it may be. This means that the caller cannot count on having the same Id
--  value for two identical strings stored separately and also cannot count on
--  the two such Id values being different.

   Null_String_Id : String_Id;
   --  Gets set to a null string with length zero

   --------------------------------------
   -- String Table Access Subprograms --
   --------------------------------------

   procedure Initialize;
   --  Initializes the strings table for a new compilation. Note that
   --  Initialize must not be called if Tree_Read is used.

   procedure Lock;
   --  Lock internal tables before calling back end

   procedure Unlock;
   --  Unlock internal tables, in case back end needs to modify them

   procedure Mark;
   --  Take a snapshot of the internal tables. Used in conjunction with Release
   --  when computing temporary string values that need not be preserved.

   procedure Release;
   --  Restore the internal tables to the situation when Mark was last called.
   --  If Release is called with no prior call to Mark, the entire string table
   --  is cleared to its initial (empty) setting.

   procedure Start_String;
   --  Sets up for storing a new string in the table. To store a string, a
   --  call is first made to Start_String, then successive calls are
   --  made to Store_String_Character to store the characters of the string.
   --  Finally, a call to End_String terminates the entry and returns it Id.

   procedure Start_String (S : String_Id);
   --  Like Start_String with no parameter, except that the contents of the
   --  new string is initialized to be a copy of the given string. A test is
   --  made to see if S is the last created string, and if so it is shared,
   --  rather than copied, this can be particularly helpful for the case of
   --  a continued concatenation of string constants.

   procedure Store_String_Char (C : Char_Code);
   procedure Store_String_Char (C : Character);
   --  Store next character of string, see description above for Start_String

   procedure Store_String_Chars (S : String);
   procedure Store_String_Chars (S : String_Id);
   --  Store character codes of given string in sequence

   procedure Store_String_Int (N : Int);
   --  Stored decimal representation of integer with possible leading minus

   procedure Unstore_String_Char;
   --  Undoes effect of previous Store_String_Char call, used in some error
   --  situations of unterminated string constants.

   function End_String return String_Id;
   --  Terminates current string and returns its Id

   function String_Length (Id : String_Id) return Nat;
   --  Returns length of previously stored string

   function Get_String_Char (Id : String_Id; Index : Int) return Char_Code;
   pragma Inline (Get_String_Char);
   --  Obtains the specified character from a stored string. The lower bound
   --  of stored strings is always 1, so the range is 1 .. String_Length (Id).

   function String_Equal (L, R : String_Id) return Boolean;
   --  Determines if two string literals represent the same string

   function String_To_Name (S : String_Id) return Name_Id;
   --  Convert String_Id to Name_Id

   procedure Append (Buf : in out Bounded_String; S : String_Id);
   --  Append characters of given string to Buf. Error if any characters are
   --  out of Character range. Does not attempt to do any encoding of
   --  characters.

   procedure String_To_Name_Buffer (S : String_Id);
   --  Place characters of given string in Name_Buffer, setting Name_Len.
   --  Error if any characters are out of Character range. Does not attempt
   --  to do any encoding of any characters.

   function String_Chars_Address return System.Address;
   --  Return address of String_Chars table (used by Back_End call to Gigi)

   function String_From_Name_Buffer
     (Buf : Bounded_String := Global_Name_Buffer) return String_Id;
   --  Given a name stored in Buf, returns a string of the corresponding value.

   function Strings_Address return System.Address;
   --  Return address of Strings table (used by Back_End call to Gigi)

   procedure Tree_Read;
   --  Initializes internal tables from current tree file using the relevant
   --  Table.Tree_Read routines. Note that Initialize should not be called if
   --  Tree_Read is used. Tree_Read includes all necessary initialization.

   procedure Tree_Write;
   --  Writes out internal tables to current tree file using the relevant
   --  Table.Tree_Write routines.

   procedure Write_Char_Code (Code : Char_Code);
   --  Procedure to write a character code value, used for debugging purposes
   --  for writing character codes. If the character code is in the range
   --  16#20# .. 16#7E#, then the single graphic character corresponding to
   --  the code is output. For any other codes in the range 16#00# .. 16#FF#,
   --  the code is output as ["hh"] where hh is the two digit hex value for
   --  the code. Codes greater than 16#FF# are output as ["hhhh"] where hhhh
   --  is the four digit hex representation of the code value (high order
   --  byte first). Hex letters are always in lower case.

   procedure Write_String_Table_Entry (Id : String_Id);
   --  Writes a string value with enclosing quotes to the current file using
   --  routines in package Output. Does not write an end of line character.
   --  This procedure is used for debug output purposes, and also for output
   --  of strings specified by pragma Linker Option to the ali file. 7-bit
   --  ASCII graphics (except for double quote) are output literally.
   --  The double quote appears as two successive double quotes.
   --  All other codes, are output as described for Write_Char_Code. For
   --  example, the string created by folding "A" & ASCII.HT & "Hello" will
   --  print as "A["09"]Hello". A No_String value prints simply as "no string"
   --  without surrounding quote marks.

private
   pragma Inline (End_String);
   pragma Inline (String_Length);

end Stringt;
