------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--                              G N A T V S N                               --
--                                                                          --
--                                 S p e c                                  --
--                                                                          --
--                                                                          --
--          Copyright (C) 1992-2002 Free Software Foundation, Inc.          --
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
-- It is now maintained by Ada Core Technologies Inc (http://www.gnat.com). --
--                                                                          --
------------------------------------------------------------------------------

--  This package spec holds version information for GNAT, GNATBIND and
--  GNATMAKE. It is updated whenever the release number is changed.

package Gnatvsn is

   Gnat_Version_String : constant String := "3.2 20020613 (experimental)";
   --  Version output when GNAT (compiler), or its related tools, including
   --  GNATBIND, GNATCHOP, GNATFIND, GNATLINK, GNATMAKE, GNATXREF, are run
   --  (with appropriate verbose option switch set).
   --
   --  WARNING: some scripts rely on the format of this string. Any change
   --  must be coordinated with a script maintainer. Furthermore, no
   --  other variable in this package may have a name starting with
   --  Gnat_Version_String.

   Gnat_Version_Type : constant String := "FSF    ";
   --  This string is set to one of three values:
   --
   --    "FSF    "
   --       GNAT FSF version. This version of GNAT is part of a Free Software
   --       Foundation release of the GNU Compiler Collection (GCC). The binder
   --       will not output informational messages regarding intended use.
   --       and the bug box generated by Comperr will give information on
   --       how to report bugs and list the "no warranty" information.
   --
   --    "GNATPRO"
   --       GNAT Professional version. This version of GNAT is supported
   --       by Ada Core Technologies. The binder will not output the
   --       usual "no warranty" messages, and the bug box generated by
   --       package Comperr will give instructions on bug submission
   --       that include references to customer number, ftp site etc.
   --
   --    "PUBLIC "
   --       GNAT Public version. This is a public version of GNAT, released
   --       by Ada Core Technologies and intended for educational use.
   --       The binder will output informational messages, and the bug box
   --       generated by the package Comperr will give appropriate bug
   --       submission instructions that do not reference customer number etc.
   --
   --  These are the only allowable settings for this string

   Ver_Len_Max : constant := 32;
   --  Longest possible length for Gnat_Version_String in this or any
   --  other version of GNAT. This is used by the binder to establish
   --  space to store any possible version string value for checks. This
   --  value should never be decreased in the future, but it would be
   --  OK to increase it if absolutely necessary.

   Library_Version : constant String := "GNAT Lib v3.15";
   --  Library version. This value must be updated whenever any change to the
   --  compiler affects the library formats in such a way as to obsolete
   --  previously compiled library modules.
   --
   --  Note: Makefile.in relies on the precise format of the library version
   --  string in order to correctly construct the soname value.

end Gnatvsn;
