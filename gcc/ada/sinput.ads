------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--                               S I N P U T                                --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--                            $Revision: 1.3 $
--                                                                          --
--          Copyright (C) 1992-2001 Free Software Foundation, Inc.          --
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

--  This package contains the input routines used for reading the
--  input source file. The actual I/O routines are in OS_Interface,
--  with this module containing only the system independent processing.

--  General Note: throughout the compiler, we use the term line or source
--  line to refer to a physical line in the source, terminated by the end of
--  physical line sequence. See Skip_Line_Terminators procedure for a full
--  description of the difference between logical and physical lines.

with Alloc;
with Casing; use Casing;
with Table;
with Types;  use Types;

package Sinput is

   ----------------------------
   -- Source License Control --
   ----------------------------

   --  The following type indicates the license state of a source if it
   --  is known.

   type License_Type is
     (Unknown,
      --  Licensing status of this source unit is unknown

      Restricted,
      --  This is a non-GPL'ed unit that is restricted from depending
      --  on GPL'ed units (e.g. proprietary code is in this category)

      GPL,
      --  This file is licensed under the unmodified GPL. It is not allowed
      --  to depend on Non_GPL units, and Non_GPL units may not depend on
      --  this source unit.

      Modified_GPL,
      --  This file is licensed under the GNAT modified GPL (see header of
      --  This file for wording of the modification). It may depend on other
      --  Modified_GPL units or on unrestricted units.

      Unrestricted);
      --  The license on this file is permitted to depend on any other
      --  units, or have other units depend on it, without violating the
      --  license of this unit. Examples are public domain units, and
      --  units defined in the RM).

   --  The above license status is checked when the appropriate check is
   --  activated and one source depends on another, and the licensing state
   --  of both files is known:

   --  The prohibited combinations are:

   --    Restricted file may not depend on GPL file

   --    GPL file may not depend on Restricted file

   --    Modified GPL file may not depend on Restricted file
   --    Modified_GPL file may not depend on GPL file

   --  The reason for the last restriction here is that a client depending
   --  on a modified GPL file must be sure that the license condition is
   --  correct considered transitively.

   --  The licensing status is determined either by the presence of a
   --  specific pragma License, or by scanning the header for a predefined
   --  file, or any file if compiling in -gnatg mode.

   -----------------------
   -- Source File Table --
   -----------------------

   --  The source file table has an entry for each source file read in for
   --  this run of the compiler. This table is (default) initialized when
   --  the compiler is loaded, and simply accumulates entries as compilation
   --  proceeds and the Sinput.L.Load_Source_File procedure is called to load
   --  required source files.

   --  Virtual entries are also created for generic templates when they are
   --  instantiated, as described in a separate section later on.

   --  In the case where there are multiple main units (e.g. in the case of
   --  the cross-reference tool), this table is not reset between these units,
   --  so that a given source file is only read once if it is used by two
   --  separate main units.

   --  The entries in the table are accessed using a Source_File_Index that
   --  ranges from 1 to Last_Source_File. Each entry has the following fields

   --  Note that entry 1 is always for system.ads (see Targparm for details
   --  of why we always read this source file first), and we have defined a
   --  constant Types.System_Source_File_Index as 1 to reflect this fact.

   --  File_Name : File_Name_Type
   --    Name of the source file (simple name with no directory information).
   --    Set by Sinput.L.Load_Source_File and cannot be subequently changed.

   --  Full_File_Name : File_Name_Type
   --    Full file name (full name with directory info), used for generation
   --    of error messages, etc. Set by Sinput.L.Load_Source_File and cannot
   --    be subsequently changed.

   --  Reference_Name : File_Name_Type
   --    Name to be used for source file references in error messages where
   --    only the simple name of the file is required. Identical to File_Name
   --    unless pragma Source_Reference is used to change it. Only processing
   --    for the Source_Reference pragma circuit may set this field.

   --  Full_Ref_Name : File_Name_Type
   --    Name to be used for source file references in error messages where
   --    the full name of the file is required. Identical to Full_File_Name
   --    unless pragma Source_Reference is used to change it. Only processing
   --    for the Source_Reference pragma may set this field.

   --  Debug_Source_Name : File_Name_Type
   --    Name to be used for source file references in debugging information
   --    where only the simple name of the file is required. Identical to
   --    Full_Ref_Name unless the -gnatD (debug source file) switch is used.
   --    Only processing in Sprint that generates this file is permitted to
   --    set this field.

   --  License : License_Type;
   --    License status of source file

   --  Num_SRef_Pragmas : Nat;
   --    Number of source reference pragmas present in source file

   --  First_Mapped_Line : Logical_Line_Number;
   --    This field stores logical line number of the first line in the
   --    file that is not a Source_Reference pragma. If no source reference
   --    pragmas are used, then the value is set to No_Line_Number.

   --  Source_Text : Source_Buffer_Ptr
   --    Text of source file. Note that every source file has a distinct set
   --    of non-overlapping logical bounds, so it is possible to determine
   --    which file is referenced from a given subscript (Source_Ptr) value.
   --    Set by Sinput.L.Load_Source_File and cannot be subsequently changed.

   --  Source_First : Source_Ptr;
   --    Subscript of first character in Source_Text. Note that this cannot
   --    be obtained as Source_Text'First, because we use virtual origin
   --    addressing. Set by Sinput.L procedures when the entry is first
   --    created and never subsequently changed.

   --  Source_Last : Source_Ptr;
   --    Subscript of last character in Source_Text. Note that this cannot
   --    be obtained as Source_Text'Last, because we use virtual origin
   --    addressing, so this value is always Source_Ptr'Last. Set by
   --    Sinput.L procedures when the entry is first created and never
   --    subsequently changed.

   --  Time_Stamp : Time_Stamp_Type;
   --    Time stamp of the source file. Set by Sinput.L.Load_Source_File,
   --    and cannot be subsequently changed.

   --  Source_Checksum : Word;
   --    Computed checksum for contents of source file. See separate section
   --    later on in this spec for a description of the checksum algorithm.

   --  Last_Source_Line : Physical_Line_Number;
   --    Physical line number of last source line. Whlie a file is being
   --    read, this refers to the last line scanned. Once a file has been
   --    completely scanned, it is the number of the last line in the file,
   --    and hence also gives the number of source lines in the file.

   --  Keyword_Casing : Casing_Type;
   --    Casing style used in file for keyword casing. This is initialized
   --    to Unknown, and then set from the first occurrence of a keyword.
   --    This value is used only for formatting of error messages.

   --  Identifier_Casing : Casing_Type;
   --    Casing style used in file for identifier casing. This is initialized
   --    to Unknown, and then set from an identifier in the program as soon as
   --    one is found whose casing is sufficiently clear to make a decision.
   --    This value is used for formatting of error messages, and also is used
   --    in the detection of keywords misused as identifiers.

   --  Instantiation : Source_Ptr;
   --    Source file location of the instantiation if this source file entry
   --    represents a generic instantiation. Set to No_Location for the case
   --    of a normal non-instantiation entry. See section below for details.
   --    This field is read-only for clients.

   --  Template : Source_File_Index;
   --    Source file index of the source file containing the template if this
   --    is a generic instantiation. Set to No_Source_File for the normal case
   --    of a non-instantiation entry. See Sinput-L for details. This field is
   --    read-only for clients.

   --  The source file table is accessed by clients using the following
   --  subprogram interface:

   subtype SFI is Source_File_Index;

   function Debug_Source_Name (S : SFI) return File_Name_Type;
   function File_Name         (S : SFI) return File_Name_Type;
   function First_Mapped_Line (S : SFI) return Logical_Line_Number;
   function Full_File_Name    (S : SFI) return File_Name_Type;
   function Full_Ref_Name     (S : SFI) return File_Name_Type;
   function Identifier_Casing (S : SFI) return Casing_Type;
   function Instantiation     (S : SFI) return Source_Ptr;
   function Keyword_Casing    (S : SFI) return Casing_Type;
   function Last_Source_Line  (S : SFI) return Physical_Line_Number;
   function License           (S : SFI) return License_Type;
   function Num_SRef_Pragmas  (S : SFI) return Nat;
   function Reference_Name    (S : SFI) return File_Name_Type;
   function Source_Checksum   (S : SFI) return Word;
   function Source_First      (S : SFI) return Source_Ptr;
   function Source_Last       (S : SFI) return Source_Ptr;
   function Source_Text       (S : SFI) return Source_Buffer_Ptr;
   function Template          (S : SFI) return Source_File_Index;
   function Time_Stamp        (S : SFI) return Time_Stamp_Type;

   procedure Set_Keyword_Casing    (S : SFI; C : Casing_Type);
   procedure Set_Identifier_Casing (S : SFI; C : Casing_Type);
   procedure Set_License           (S : SFI; L : License_Type);

   function Last_Source_File return Source_File_Index;
   --  Index of last source file table entry

   function Num_Source_Files return Nat;
   --  Number of source file table entries

   procedure Initialize;
   --  Initialize internal tables

   procedure Lock;
   --  Lock internal tables

   Main_Source_File : Source_File_Index;
   --  This is set to the source file index of the main unit

   -----------------------
   -- Checksum Handling --
   -----------------------

   --  As a source file is scanned, a checksum is computed by taking all the
   --  non-blank characters in the file, excluding comment characters, the
   --  minus-minus sequence starting a comment, and all control characters
   --  except ESC.

   --  The checksum algorithm used is the standard CRC-32 algorithm, as
   --  implemented by System.CRC32, except that we do not bother with the
   --  final XOR with all 1 bits.

   --  This algorithm ensures that the checksum includes all semantically
   --  significant aspects of the program represented by the source file,
   --  but is insensitive to layout, presence or contents of comments, wide
   --  character representation method, or casing conventions outside strings.

   --  Scans.Checksum is initialized appropriately at the start of scanning
   --  a file, and copied into the Source_Checksum field of the file table
   --  entry when the end of file is encountered.

   -------------------------------------
   -- Handling Generic Instantiations --
   -------------------------------------

   --  As described in Sem_Ch12, a generic instantiation involves making a
   --  copy of the tree of the generic template. The source locations in
   --  this tree directly reference the source of the template. However it
   --  is also possible to find the location of the instantiation.

   --  This is achieved as follows. When an instantiation occurs, a new entry
   --  is made in the source file table. This entry points to the same source
   --  text, i.e. the file that contains the instantiation, but has a distinct
   --  set of Source_Ptr index values. The separate range of Sloc values avoids
   --  confusion, and means that the Sloc values can still be used to uniquely
   --  identify the source file table entry. It is possible for both entries
   --  to point to the same text, because of the virtual origin pointers used
   --  in the source table.

   --  The Instantiation field of this source file index entry, usually set
   --  to No_Source_File, instead contains the Sloc of the instantiation. In
   --  the case of nested instantiations, this Sloc may itself refer to an
   --  instantiation, so the complete chain can be traced.

   --  Two routines are used to build these special entries in the source
   --  file table. Create_Instantiation_Source is first called to build
   --  the virtual source table entry for the instantiation, and then the
   --  Sloc values in the copy are adjusted using Adjust_Instantiation_Sloc.
   --  See child unit Sinput.L for details on these two routines.

   -----------------
   -- Global Data --
   -----------------

   Current_Source_File : Source_File_Index;
   --  Source_File table index of source file currently being scanned

   Current_Source_Unit : Unit_Number_Type;
   --  Unit number of source file currently being scanned. The special value
   --  of No_Unit indicates that the configuration pragma file is currently
   --  being scanned (this has no entry in the unit table).

   Source_gnat_adc : Source_File_Index := No_Source_File;
   --  This is set if a gnat.adc file is present to reference this file

   Source : Source_Buffer_Ptr;
   --  Current source (copy of Source_File.Table (Current_Source_Unit).Source)

   Internal_Source : aliased Source_Buffer (1 .. 81);
   --  This buffer is used internally in the compiler when the lexical analyzer
   --  is used to scan a string from within the compiler. The procedure is to
   --  establish Internal_Source_Ptr as the value of Source, set the string to
   --  be scanned, appropriately terminated, in this buffer, and set Scan_Ptr
   --  to point to the start of the buffer. It is a fatal error if the scanner
   --  signals an error while scanning a token in this internal buffer.

   Internal_Source_Ptr : constant Source_Buffer_Ptr :=
                           Internal_Source'Unrestricted_Access;
   --  Pointer to internal source buffer

   -----------------
   -- Subprograms --
   -----------------

   procedure Backup_Line (P : in out Source_Ptr);
   --  Back up the argument pointer to the start of the previous line. On
   --  entry, P points to the start of a physical line in the source buffer.
   --  On return, P is updated to point to the start of the previous line.
   --  The caller has checked that a Line_Terminator character precedes P so
   --  that there definitely is a previous line in the source buffer.

   procedure Build_Location_String (Loc : Source_Ptr);
   --  This function builds a string literal of the form "name:line",
   --  where name is the file name corresponding to Loc, and line is
   --  the line number. In the event that instantiations are involved,
   --  additional suffixes of the same form are appended after the
   --  separating string " instantiated at ". The returned string is
   --  stored in Name_Buffer, terminated by ASCII.Nul, with Name_Length
   --  indicating the length not including the terminating Nul.

   function Get_Column_Number (P : Source_Ptr) return Column_Number;
   --  The ones-origin column number of the specified Source_Ptr value is
   --  determined and returned. Tab characters if present are assumed to
   --  represent the standard 1,9,17.. spacing pattern.

   function Get_Logical_Line_Number
     (P    : Source_Ptr)
      return Logical_Line_Number;
   --  The line number of the specified source position is obtained by
   --  doing a binary search on the source positions in the lines table
   --  for the unit containing the given source position. The returned
   --  value is the logical line number, already adjusted for the effect
   --  of source reference pragmas. If P refers to the line of a source
   --  reference pragma itself, then No_Line is returned. If no source
   --  reference pragmas have been encountered, the value returned is
   --  the same as the physical line number.

   function Get_Physical_Line_Number
     (P    : Source_Ptr)
      return Physical_Line_Number;
   --  The line number of the specified source position is obtained by
   --  doing a binary search on the source positions in the lines table
   --  for the unit containing the given source position. The returned
   --  value is the physical line number in the source being compiled.

   function Get_Source_File_Index (S : Source_Ptr) return Source_File_Index;
   --  Return file table index of file identified by given source pointer
   --  value. This call must always succeed, since any valid source pointer
   --  value belongs to some previously loaded source file.

   function Instantiation_Depth (S : Source_Ptr) return Nat;
   --  Determine instantiation depth for given Sloc value. A value of
   --  zero means that the given Sloc is not in an instantiation.

   function Line_Start (P : Source_Ptr) return Source_Ptr;
   --  Finds the source position of the start of the line containing the
   --  given source location.

   function Line_Start
     (L    : Physical_Line_Number;
      S    : Source_File_Index)
      return Source_Ptr;
   --  Finds the source position of the start of the given line in the
   --  given source file, using a physical line number to identify the line.

   function Num_Source_Lines (S : Source_File_Index) return Nat;
   --  Returns the number of source lines (this is equivalent to reading
   --  the value of Last_Source_Line, but returns Nat rathern than a
   --  physical line number.

   procedure Register_Source_Ref_Pragma
     (File_Name          : Name_Id;
      Stripped_File_Name : Name_Id;
      Mapped_Line        : Nat;
      Line_After_Pragma  : Physical_Line_Number);
   --  Register a source reference pragma, the parameter File_Name is the
   --  file name from the pragma, and Stripped_File_Name is this name with
   --  the directory information stripped. Both these parameters are set
   --  to No_Name if no file name parameter was given in the pragma.
   --  (which can only happen for the second and subsequent pragmas).
   --  Mapped_Line is the line number parameter from the pragma, and
   --  Line_After_Pragma is the physical line number of the line that
   --  follows the line containing the Source_Reference pragma.

   function Original_Location (S : Source_Ptr) return Source_Ptr;
   --  Given a source pointer S, returns the corresponding source pointer
   --  value ignoring instantiation copies. For locations that do not
   --  correspond to instantiation copies of templates, the argument is
   --  returned unchanged. For locations that do correspond to copies of
   --  templates from instantiations, the location within the original
   --  template is returned. This is useful in canonicalizing locations.

   function Instantiation_Location (S : Source_Ptr) return Source_Ptr;
   pragma Inline (Instantiation_Location);
   --  Given a source pointer S, returns the corresponding source pointer
   --  value of the instantiation if this location is within an instance.
   --  If S is not within an instance, then this returns No_Location.

   function Top_Level_Location (S : Source_Ptr) return Source_Ptr;
   --  Given a source pointer S, returns the argument unchanged if it is
   --  not in an instantiation. If S is in an instantiation, then it returns
   --  the location of the top level instantiation, i.e. the outer level
   --  instantiation in the nested case.

   function Physical_To_Logical
     (Line : Physical_Line_Number;
      S    : Source_File_Index)
      return Logical_Line_Number;
   --  Given a physical line number in source file whose source index is S,
   --  return the corresponding logical line number. If the physical line
   --  number is one containing a Source_Reference pragma, the result will
   --  be No_Line_Number.

   procedure Skip_Line_Terminators
     (P        : in out Source_Ptr;
      Physical : out Boolean);
   --  On entry, Source (P) points to the line terminator character that
   --  terminates a line. The result set in P is the location of the first
   --  character of the following line (after skipping the sequence of line
   --  terminator characters terminating the current line). In addition, if
   --  the terminator sequence ends a physical line (the definition of what
   --  constitutes a physical line is embodied in the implementation of this
   --  function), and it is the first time this sequence is encountered, then
   --  an entry is made in the lines table to record the location for further
   --  use by functions such as Get_Line_Number. Physical is set to True if
   --  the line terminator was the end of a physical line.

   function Source_Offset (S : Source_Ptr) return Nat;
   --  Returns the zero-origin offset of the given source location from the
   --  start of its corresponding unit. This is used for creating canonical
   --  names in some situations.

   procedure Write_Location (P : Source_Ptr);
   --  Writes out a string of the form fff:nn:cc, where fff, nn, cc are the
   --  file name, line number and column corresponding to the given source
   --  location. No_Location and Standard_Location appear as the strings
   --  <no location> and <standard location>. If the location is within an
   --  instantiation, then the instance location is appended, enclosed in
   --  square brackets (which can nest if necessary). Note that this routine
   --  is used only for internal compiler debugging output purposes (which
   --  is why the somewhat cryptic use of brackets is acceptable).

   procedure wl (P : Source_Ptr);
   --  Equivalent to Write_Location (P); Write_Eol; for calls from GDB

   procedure Write_Time_Stamp (S : Source_File_Index);
   --  Writes time stamp of specified file in YY-MM-DD HH:MM.SS format

   procedure Tree_Write;
   --  Writes out internal tables to current tree file using Tree_Write

   procedure Tree_Read;
   --  Initializes internal tables from current tree file using Tree_Read

private
   pragma Inline (File_Name);
   pragma Inline (First_Mapped_Line);
   pragma Inline (Full_File_Name);
   pragma Inline (Identifier_Casing);
   pragma Inline (Instantiation);
   pragma Inline (Keyword_Casing);
   pragma Inline (Last_Source_Line);
   pragma Inline (Last_Source_File);
   pragma Inline (License);
   pragma Inline (Num_SRef_Pragmas);
   pragma Inline (Num_Source_Files);
   pragma Inline (Num_Source_Lines);
   pragma Inline (Reference_Name);
   pragma Inline (Set_Keyword_Casing);
   pragma Inline (Set_Identifier_Casing);
   pragma Inline (Source_First);
   pragma Inline (Source_Last);
   pragma Inline (Source_Text);
   pragma Inline (Template);
   pragma Inline (Time_Stamp);

   -------------------------
   -- Source_Lines Tables --
   -------------------------

   type Lines_Table_Type is
     array (Physical_Line_Number) of Source_Ptr;
   --  Type used for lines table. The entries are indexed by physical line
   --  numbers. The values are the starting Source_Ptr values for the start
   --  of the corresponding physical line. Note that we make this a bogus
   --  big array, sized as required, so that we avoid the use of fat pointers.

   type Lines_Table_Ptr is access all Lines_Table_Type;
   --  Type used for pointers to line tables

   type Logical_Lines_Table_Type is
     array (Physical_Line_Number) of Logical_Line_Number;
   --  Type used for logical lines table. This table is used if a source
   --  reference pragma is present. It is indexed by physical line numbers,
   --  and contains the corresponding logical line numbers. An entry that
   --  corresponds to a source reference pragma is set to No_Line_Number.
   --  Note that we make this a bogus big array, sized as required, so that
   --  we avoid the use of fat pointers.

   type Logical_Lines_Table_Ptr is access all Logical_Lines_Table_Type;
   --  Type used for pointers to logical line tables.

   -----------------------
   -- Source_File Table --
   -----------------------

   --  See earlier descriptions for meanings of public fields

   type Source_File_Record is record

      File_Name         : File_Name_Type;
      Reference_Name    : File_Name_Type;
      Debug_Source_Name : File_Name_Type;
      Full_File_Name    : File_Name_Type;
      Full_Ref_Name     : File_Name_Type;
      License           : License_Type;
      Num_SRef_Pragmas  : Nat;
      First_Mapped_Line : Logical_Line_Number;
      Source_Text       : Source_Buffer_Ptr;
      Source_First      : Source_Ptr;
      Source_Last       : Source_Ptr;
      Time_Stamp        : Time_Stamp_Type;
      Source_Checksum   : Word;
      Last_Source_Line  : Physical_Line_Number;
      Keyword_Casing    : Casing_Type;
      Identifier_Casing : Casing_Type;
      Instantiation     : Source_Ptr;
      Template          : Source_File_Index;

      --  The following fields are for internal use only (i.e. only in the
      --  body of Sinput or its children, with no direct access by clients).

      Sloc_Adjust : Source_Ptr;
      --  A value to be added to Sloc values for this file to reference the
      --  corresponding lines table. This is zero for the non-instantiation
      --  case, and set so that the adition references the ultimate template
      --  for the instantiation case. See Sinput-L for further details.

      Lines_Table : Lines_Table_Ptr;
      --  Pointer to lines table for this source. Updated as additional
      --  lines are accessed using the Skip_Line_Terminators procedure.
      --  Note: the lines table for an instantiation entry refers to the
      --  original line numbers of the template see Sinput-L for details.

      Logical_Lines_Table : Logical_Lines_Table_Ptr;
      --  Pointer to logical lines table for this source. Non-null only if
      --  a source reference pragma has been processed. Updated as lines
      --  are accessed using the Skip_Line_Terminators procedure.

      Lines_Table_Max : Physical_Line_Number;
      --  Maximum subscript values for currently allocated Lines_Table
      --  and (if present) the allocated Logical_Lines_Table. The value
      --  Max_Source_Line gives the maximum used value, this gives the
      --  maximum allocated value.

   end record;

   package Source_File is new Table.Table (
     Table_Component_Type => Source_File_Record,
     Table_Index_Type     => Source_File_Index,
     Table_Low_Bound      => 1,
     Table_Initial        => Alloc.Source_File_Initial,
     Table_Increment      => Alloc.Source_File_Increment,
     Table_Name           => "Source_File");

   -----------------
   -- Subprograms --
   -----------------

   procedure Alloc_Line_Tables
     (S       : in out Source_File_Record;
      New_Max : Nat);
   --  Allocate or reallocate the lines table for the given source file so
   --  that it can accommodate at least New_Max lines. Also allocates or
   --  reallocates logical lines table if source ref pragmas are present.

   procedure Add_Line_Tables_Entry
     (S : in out Source_File_Record;
      P : Source_Ptr);
   --  Increment line table size by one (reallocating the lines table if
   --  needed) and set the new entry to contain the value P. Also bumps
   --  the Source_Line_Count field. If source reference pragmas are
   --  present, also increments logical lines table size by one, and
   --  sets new entry.

end Sinput;
