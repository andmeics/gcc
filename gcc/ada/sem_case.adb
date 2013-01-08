------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--                             S E M _ C A S E                              --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--          Copyright (C) 1996-2012, Free Software Foundation, Inc.         --
--                                                                          --
-- GNAT is free software;  you can  redistribute it  and/or modify it under --
-- terms of the  GNU General Public License as published  by the Free Soft- --
-- ware  Foundation;  either version 3,  or (at your option) any later ver- --
-- sion.  GNAT is distributed in the hope that it will be useful, but WITH- --
-- OUT ANY WARRANTY;  without even the  implied warranty of MERCHANTABILITY --
-- or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License --
-- for  more details.  You should have  received  a copy of the GNU General --
-- Public License  distributed with GNAT; see file COPYING3.  If not, go to --
-- http://www.gnu.org/licenses for a complete copy of the license.          --
--                                                                          --
-- GNAT was originally developed  by the GNAT team at  New York University. --
-- Extensive contributions were provided by Ada Core Technologies Inc.      --
--                                                                          --
------------------------------------------------------------------------------

with Atree;    use Atree;
with Einfo;    use Einfo;
with Errout;   use Errout;
with Namet;    use Namet;
with Nlists;   use Nlists;
with Nmake;    use Nmake;
with Opt;      use Opt;
with Sem;      use Sem;
with Sem_Aux;  use Sem_Aux;
with Sem_Eval; use Sem_Eval;
with Sem_Res;  use Sem_Res;
with Sem_Util; use Sem_Util;
with Sem_Type; use Sem_Type;
with Snames;   use Snames;
with Stand;    use Stand;
with Sinfo;    use Sinfo;
with Tbuild;   use Tbuild;
with Uintp;    use Uintp;

with Ada.Unchecked_Deallocation;

with GNAT.Heap_Sort_G;

package body Sem_Case is

   type Choice_Bounds is record
     Lo   : Node_Id;
     Hi   : Node_Id;
     Node : Node_Id;
   end record;
   --  Represent one choice bounds entry with Lo and Hi values, Node points
   --  to the choice node itself.

   type Choice_Table_Type is array (Nat range <>) of Choice_Bounds;
   --  Table type used to sort the choices present in a case statement, array
   --  aggregate or record variant. The actual entries are stored in 1 .. Last,
   --  but we have a 0 entry for convenience in sorting.

   -----------------------
   -- Local Subprograms --
   -----------------------

   procedure Check_Choices
     (Choice_Table   : in out Choice_Table_Type;
      Bounds_Type    : Entity_Id;
      Subtyp         : Entity_Id;
      Others_Present : Boolean;
      Case_Node      : Node_Id);
   --  This is the procedure which verifies that a set of case alternatives
   --  or record variant choices has no duplicates, and covers the range
   --  specified by Bounds_Type. Choice_Table contains the discrete choices
   --  to check. These must start at position 1.
   --
   --  Furthermore Choice_Table (0) must exist. This element is used by
   --  the sorting algorithm as a temporary. Others_Present is a flag
   --  indicating whether or not an Others choice is present. Finally
   --  Msg_Sloc gives the source location of the construct containing the
   --  choices in the Choice_Table.
   --
   --  Bounds_Type is the type whose range must be covered by the alternatives
   --
   --  Subtyp is the subtype of the expression. If its bounds are non-static
   --  the alternatives must cover its base type.

   function Choice_Image (Value : Uint; Ctype : Entity_Id) return Name_Id;
   --  Given a Pos value of enumeration type Ctype, returns the name
   --  ID of an appropriate string to be used in error message output.

   procedure Expand_Others_Choice
     (Case_Table     : Choice_Table_Type;
      Others_Choice  : Node_Id;
      Choice_Type    : Entity_Id);
   --  The case table is the table generated by a call to Analyze_Choices
   --  (with just 1 .. Last_Choice entries present). Others_Choice is a
   --  pointer to the N_Others_Choice node (this routine is only called if
   --  an others choice is present), and Choice_Type is the discrete type
   --  of the bounds. The effect of this call is to analyze the cases and
   --  determine the set of values covered by others. This choice list is
   --  set in the Others_Discrete_Choices field of the N_Others_Choice node.

   -------------------
   -- Check_Choices --
   -------------------

   procedure Check_Choices
     (Choice_Table   : in out Choice_Table_Type;
      Bounds_Type    : Entity_Id;
      Subtyp         : Entity_Id;
      Others_Present : Boolean;
      Case_Node      : Node_Id)
   is
      procedure Explain_Non_Static_Bound;
      --  Called when we find a non-static bound, requiring the base type to
      --  be covered. Provides where possible a helpful explanation of why the
      --  bounds are non-static, since this is not always obvious.

      function Lt_Choice (C1, C2 : Natural) return Boolean;
      --  Comparison routine for comparing Choice_Table entries. Use the lower
      --  bound of each Choice as the key.

      procedure Move_Choice (From : Natural; To : Natural);
      --  Move routine for sorting the Choice_Table

      package Sorting is new GNAT.Heap_Sort_G (Move_Choice, Lt_Choice);

      procedure Issue_Msg (Value1 : Node_Id; Value2 : Node_Id);
      procedure Issue_Msg (Value1 : Node_Id; Value2 : Uint);
      procedure Issue_Msg (Value1 : Uint;    Value2 : Node_Id);
      procedure Issue_Msg (Value1 : Uint;    Value2 : Uint);
      --  Issue an error message indicating that there are missing choices,
      --  followed by the image of the missing choices themselves which lie
      --  between Value1 and Value2 inclusive.

      ---------------
      -- Issue_Msg --
      ---------------

      procedure Issue_Msg (Value1 : Node_Id; Value2 : Node_Id) is
      begin
         Issue_Msg (Expr_Value (Value1), Expr_Value (Value2));
      end Issue_Msg;

      procedure Issue_Msg (Value1 : Node_Id; Value2 : Uint) is
      begin
         Issue_Msg (Expr_Value (Value1), Value2);
      end Issue_Msg;

      procedure Issue_Msg (Value1 : Uint; Value2 : Node_Id) is
      begin
         Issue_Msg (Value1, Expr_Value (Value2));
      end Issue_Msg;

      procedure Issue_Msg (Value1 : Uint; Value2 : Uint) is
         Msg_Sloc : constant Source_Ptr := Sloc (Case_Node);

      begin
         --  AI05-0188 : within an instance the non-others choices do not
         --  have to belong to the actual subtype.

         if Ada_Version >= Ada_2012 and then In_Instance then
            return;
         end if;

         --  In some situations, we call this with a null range, and
         --  obviously we don't want to complain in this case!

         if Value1 > Value2 then
            return;
         end if;

         --  Case of only one value that is missing

         if Value1 = Value2 then
            if Is_Integer_Type (Bounds_Type) then
               Error_Msg_Uint_1 := Value1;
               Error_Msg ("missing case value: ^!", Msg_Sloc);
            else
               Error_Msg_Name_1 := Choice_Image (Value1, Bounds_Type);
               Error_Msg ("missing case value: %!", Msg_Sloc);
            end if;

         --  More than one choice value, so print range of values

         else
            if Is_Integer_Type (Bounds_Type) then
               Error_Msg_Uint_1 := Value1;
               Error_Msg_Uint_2 := Value2;
               Error_Msg ("missing case values: ^ .. ^!", Msg_Sloc);
            else
               Error_Msg_Name_1 := Choice_Image (Value1, Bounds_Type);
               Error_Msg_Name_2 := Choice_Image (Value2, Bounds_Type);
               Error_Msg ("missing case values: % .. %!", Msg_Sloc);
            end if;
         end if;
      end Issue_Msg;

      ---------------
      -- Lt_Choice --
      ---------------

      function Lt_Choice (C1, C2 : Natural) return Boolean is
      begin
         return
           Expr_Value (Choice_Table (Nat (C1)).Lo)
             <
           Expr_Value (Choice_Table (Nat (C2)).Lo);
      end Lt_Choice;

      -----------------
      -- Move_Choice --
      -----------------

      procedure Move_Choice (From : Natural; To : Natural) is
      begin
         Choice_Table (Nat (To)) := Choice_Table (Nat (From));
      end Move_Choice;

      ------------------------------
      -- Explain_Non_Static_Bound --
      ------------------------------

      procedure Explain_Non_Static_Bound is
         Expr : Node_Id;

      begin
         if Nkind (Case_Node) = N_Variant_Part then
            Expr := Name (Case_Node);
         else
            Expr := Expression (Case_Node);
         end if;

         if Bounds_Type /= Subtyp then

            --  If the case is a variant part, the expression is given by
            --  the discriminant itself, and the bounds are the culprits.

            if Nkind (Case_Node) = N_Variant_Part then
               Error_Msg_NE
                 ("bounds of & are not static," &
                     " alternatives must cover base type", Expr, Expr);

            --  If this is a case statement, the expression may be
            --  non-static or else the subtype may be at fault.

            elsif Is_Entity_Name (Expr) then
               Error_Msg_NE
                 ("bounds of & are not static," &
                    " alternatives must cover base type", Expr, Expr);

            else
               Error_Msg_N
                 ("subtype of expression is not static,"
                  & " alternatives must cover base type!", Expr);
            end if;

         --  Otherwise the expression is not static, even if the bounds of the
         --  type are, or else there are missing alternatives. If both, the
         --  additional information may be redundant but harmless.

         elsif not Is_Entity_Name (Expr) then
            Error_Msg_N
              ("subtype of expression is not static, "
               & "alternatives must cover base type!", Expr);
         end if;
      end Explain_Non_Static_Bound;

      --  Variables local to Check_Choices

      Choice    : Node_Id;
      Bounds_Lo : constant Node_Id := Type_Low_Bound  (Bounds_Type);
      Bounds_Hi : constant Node_Id := Type_High_Bound (Bounds_Type);

      Prev_Choice : Node_Id;

      Hi      : Uint;
      Lo      : Uint;
      Prev_Hi : Uint;

   --  Start of processing for Check_Choices

   begin
      --  Choice_Table must start at 0 which is an unused location used
      --  by the sorting algorithm. However the first valid position for
      --  a discrete choice is 1.

      pragma Assert (Choice_Table'First = 0);

      if Choice_Table'Last = 0 then
         if not Others_Present then
            Issue_Msg (Bounds_Lo, Bounds_Hi);
         end if;

         return;
      end if;

      Sorting.Sort (Positive (Choice_Table'Last));

      Lo      := Expr_Value (Choice_Table (1).Lo);
      Hi      := Expr_Value (Choice_Table (1).Hi);
      Prev_Hi := Hi;

      if not Others_Present and then Expr_Value (Bounds_Lo) < Lo then
         Issue_Msg (Bounds_Lo, Lo - 1);

         --  If values are missing outside of the subtype, add explanation.
         --  No additional message if only one value is missing.

         if Expr_Value (Bounds_Lo) < Lo - 1 then
            Explain_Non_Static_Bound;
         end if;
      end if;

      for J in 2 .. Choice_Table'Last loop
         Lo := Expr_Value (Choice_Table (J).Lo);
         Hi := Expr_Value (Choice_Table (J).Hi);

         if Lo <= Prev_Hi then
            Choice := Choice_Table (J).Node;

            --  Find first previous choice that overlaps

            for K in 1 .. J - 1 loop
               if Lo <= Expr_Value (Choice_Table (K).Hi) then
                  Prev_Choice := Choice_Table (K).Node;
                  exit;
               end if;
            end loop;

            if Sloc (Prev_Choice) <= Sloc (Choice) then
               Error_Msg_Sloc := Sloc (Prev_Choice);
               Error_Msg_N ("duplication of choice value#", Choice);
            else
               Error_Msg_Sloc := Sloc (Choice);
               Error_Msg_N ("duplication of choice value#", Prev_Choice);
            end if;

         elsif not Others_Present and then Lo /= Prev_Hi + 1 then
            Issue_Msg (Prev_Hi + 1, Lo - 1);
         end if;

         if Hi > Prev_Hi then
            Prev_Hi := Hi;
         end if;
      end loop;

      if not Others_Present and then Expr_Value (Bounds_Hi) > Hi then
         Issue_Msg (Hi + 1, Bounds_Hi);

         if Expr_Value (Bounds_Hi) > Hi + 1 then
            Explain_Non_Static_Bound;
         end if;
      end if;
   end Check_Choices;

   ------------------
   -- Choice_Image --
   ------------------

   function Choice_Image (Value : Uint; Ctype : Entity_Id) return Name_Id is
      Rtp : constant Entity_Id := Root_Type (Ctype);
      Lit : Entity_Id;
      C   : Int;

   begin
      --  For character, or wide [wide] character. If 7-bit ASCII graphic
      --  range, then build and return appropriate character literal name

      if Is_Standard_Character_Type (Ctype) then
         C := UI_To_Int (Value);

         if C in 16#20# .. 16#7E# then
            Set_Character_Literal_Name (Char_Code (UI_To_Int (Value)));
            return Name_Find;
         end if;

      --  For user defined enumeration type, find enum/char literal

      else
         Lit := First_Literal (Rtp);

         for J in 1 .. UI_To_Int (Value) loop
            Next_Literal (Lit);
         end loop;

         --  If enumeration literal, just return its value

         if Nkind (Lit) = N_Defining_Identifier then
            return Chars (Lit);

         --  For character literal, get the name and use it if it is
         --  for a 7-bit ASCII graphic character in 16#20#..16#7E#.

         else
            Get_Decoded_Name_String (Chars (Lit));

            if Name_Len = 3
              and then Name_Buffer (2) in
                Character'Val (16#20#) .. Character'Val (16#7E#)
            then
               return Chars (Lit);
            end if;
         end if;
      end if;

      --  If we fall through, we have a character literal which is not in
      --  the 7-bit ASCII graphic set. For such cases, we construct the
      --  name "type'val(nnn)" where type is the choice type, and nnn is
      --  the pos value passed as an argument to Choice_Image.

      Get_Name_String (Chars (First_Subtype (Ctype)));

      Add_Str_To_Name_Buffer ("'val(");
      UI_Image (Value);
      Add_Str_To_Name_Buffer (UI_Image_Buffer (1 .. UI_Image_Length));
      Add_Char_To_Name_Buffer (')');
      return Name_Find;
   end Choice_Image;

   --------------------------
   -- Expand_Others_Choice --
   --------------------------

   procedure Expand_Others_Choice
     (Case_Table    : Choice_Table_Type;
      Others_Choice : Node_Id;
      Choice_Type   : Entity_Id)
   is
      Loc         : constant Source_Ptr := Sloc (Others_Choice);
      Choice_List : constant List_Id    := New_List;
      Choice      : Node_Id;
      Exp_Lo      : Node_Id;
      Exp_Hi      : Node_Id;
      Hi          : Uint;
      Lo          : Uint;
      Previous_Hi : Uint;

      function Build_Choice (Value1, Value2 : Uint) return Node_Id;
      --  Builds a node representing the missing choices given by the
      --  Value1 and Value2. A N_Range node is built if there is more than
      --  one literal value missing. Otherwise a single N_Integer_Literal,
      --  N_Identifier or N_Character_Literal is built depending on what
      --  Choice_Type is.

      function Lit_Of (Value : Uint) return Node_Id;
      --  Returns the Node_Id for the enumeration literal corresponding to the
      --  position given by Value within the enumeration type Choice_Type.

      ------------------
      -- Build_Choice --
      ------------------

      function Build_Choice (Value1, Value2 : Uint) return Node_Id is
         Lit_Node : Node_Id;
         Lo, Hi   : Node_Id;

      begin
         --  If there is only one choice value missing between Value1 and
         --  Value2, build an integer or enumeration literal to represent it.

         if (Value2 - Value1) = 0 then
            if Is_Integer_Type (Choice_Type) then
               Lit_Node := Make_Integer_Literal (Loc, Value1);
               Set_Etype (Lit_Node, Choice_Type);
            else
               Lit_Node := Lit_Of (Value1);
            end if;

         --  Otherwise is more that one choice value that is missing between
         --  Value1 and Value2, therefore build a N_Range node of either
         --  integer or enumeration literals.

         else
            if Is_Integer_Type (Choice_Type) then
               Lo := Make_Integer_Literal (Loc, Value1);
               Set_Etype (Lo, Choice_Type);
               Hi := Make_Integer_Literal (Loc, Value2);
               Set_Etype (Hi, Choice_Type);
               Lit_Node :=
                 Make_Range (Loc,
                   Low_Bound  => Lo,
                   High_Bound => Hi);

            else
               Lit_Node :=
                 Make_Range (Loc,
                   Low_Bound  => Lit_Of (Value1),
                   High_Bound => Lit_Of (Value2));
            end if;
         end if;

         return Lit_Node;
      end Build_Choice;

      ------------
      -- Lit_Of --
      ------------

      function Lit_Of (Value : Uint) return Node_Id is
         Lit : Entity_Id;

      begin
         --  In the case where the literal is of type Character, there needs
         --  to be some special handling since there is no explicit chain
         --  of literals to search. Instead, a N_Character_Literal node
         --  is created with the appropriate Char_Code and Chars fields.

         if Is_Standard_Character_Type (Choice_Type) then
            Set_Character_Literal_Name (Char_Code (UI_To_Int (Value)));
            Lit := New_Node (N_Character_Literal, Loc);
            Set_Chars (Lit, Name_Find);
            Set_Char_Literal_Value (Lit, Value);
            Set_Etype (Lit, Choice_Type);
            Set_Is_Static_Expression (Lit, True);
            return Lit;

         --  Otherwise, iterate through the literals list of Choice_Type
         --  "Value" number of times until the desired literal is reached
         --  and then return an occurrence of it.

         else
            Lit := First_Literal (Choice_Type);
            for J in 1 .. UI_To_Int (Value) loop
               Next_Literal (Lit);
            end loop;

            return New_Occurrence_Of (Lit, Loc);
         end if;
      end Lit_Of;

   --  Start of processing for Expand_Others_Choice

   begin
      if Case_Table'Last = 0 then

         --  Special case: only an others case is present. The others case
         --  covers the full range of the type.

         if Is_Static_Subtype (Choice_Type) then
            Choice := New_Occurrence_Of (Choice_Type, Loc);
         else
            Choice := New_Occurrence_Of (Base_Type (Choice_Type), Loc);
         end if;

         Set_Others_Discrete_Choices (Others_Choice, New_List (Choice));
         return;
      end if;

      --  Establish the bound values for the choice depending upon whether the
      --  type of the case statement is static or not.

      if Is_OK_Static_Subtype (Choice_Type) then
         Exp_Lo := Type_Low_Bound (Choice_Type);
         Exp_Hi := Type_High_Bound (Choice_Type);
      else
         Exp_Lo := Type_Low_Bound (Base_Type (Choice_Type));
         Exp_Hi := Type_High_Bound (Base_Type (Choice_Type));
      end if;

      Lo := Expr_Value (Case_Table (1).Lo);
      Hi := Expr_Value (Case_Table (1).Hi);
      Previous_Hi := Expr_Value (Case_Table (1).Hi);

      --  Build the node for any missing choices that are smaller than any
      --  explicit choices given in the case.

      if Expr_Value (Exp_Lo) < Lo then
         Append (Build_Choice (Expr_Value (Exp_Lo), Lo - 1), Choice_List);
      end if;

      --  Build the nodes representing any missing choices that lie between
      --  the explicit ones given in the case.

      for J in 2 .. Case_Table'Last loop
         Lo := Expr_Value (Case_Table (J).Lo);
         Hi := Expr_Value (Case_Table (J).Hi);

         if Lo /= (Previous_Hi + 1) then
            Append_To (Choice_List, Build_Choice (Previous_Hi + 1, Lo - 1));
         end if;

         Previous_Hi := Hi;
      end loop;

      --  Build the node for any missing choices that are greater than any
      --  explicit choices given in the case.

      if Expr_Value (Exp_Hi) > Hi then
         Append (Build_Choice (Hi + 1, Expr_Value (Exp_Hi)), Choice_List);
      end if;

      Set_Others_Discrete_Choices (Others_Choice, Choice_List);

      --  Warn on null others list if warning option set

      if Warn_On_Redundant_Constructs
        and then Comes_From_Source (Others_Choice)
        and then Is_Empty_List (Choice_List)
      then
         Error_Msg_N ("?r?OTHERS choice is redundant", Others_Choice);
         Error_Msg_N ("\?r?previous choices cover all values", Others_Choice);
      end if;
   end Expand_Others_Choice;

   -----------
   -- No_OP --
   -----------

   procedure No_OP (C : Node_Id) is
      pragma Warnings (Off, C);
   begin
      null;
   end No_OP;

   --------------------------------
   -- Generic_Choices_Processing --
   --------------------------------

   package body Generic_Choices_Processing is

      --  The following type is used to gather the entries for the choice
      --  table, so that we can then allocate the right length.

      type Link;
      type Link_Ptr is access all Link;

      type Link is record
         Val : Choice_Bounds;
         Nxt : Link_Ptr;
      end record;

      procedure Free is new Ada.Unchecked_Deallocation (Link, Link_Ptr);

      ---------------------
      -- Analyze_Choices --
      ---------------------

      procedure Analyze_Choices
        (N              : Node_Id;
         Subtyp         : Entity_Id;
         Raises_CE      : out Boolean;
         Others_Present : out Boolean)
      is
         E : Entity_Id;

         Enode : Node_Id;
         --  This is where we post error messages for bounds out of range

         Choice_List : Link_Ptr := null;
         --  Gather list of choices

         Num_Choices : Nat := 0;
         --  Number of entries in Choice_List

         Choice_Type : constant Entity_Id := Base_Type (Subtyp);
         --  The actual type against which the discrete choices are resolved.
         --  Note that this type is always the base type not the subtype of the
         --  ruling expression, index or discriminant.

         Bounds_Type : Entity_Id;
         --  The type from which are derived the bounds of the values covered
         --  by the discrete choices (see 3.8.1 (4)). If a discrete choice
         --  specifies a value outside of these bounds we have an error.

         Bounds_Lo : Uint;
         Bounds_Hi : Uint;
         --  The actual bounds of the above type

         Expected_Type : Entity_Id;
         --  The expected type of each choice. Equal to Choice_Type, except if
         --  the expression is universal, in which case the choices can be of
         --  any integer type.

         Alt : Node_Id;
         --  A case statement alternative or a variant in a record type
         --  declaration.

         Choice : Node_Id;
         Kind   : Node_Kind;
         --  The node kind of the current Choice

         Delete_Choice : Boolean;
         --  Set to True to delete the current choice

         Others_Choice : Node_Id := Empty;
         --  Remember others choice if it is present (empty otherwise)

         procedure Check (Choice : Node_Id; Lo, Hi : Node_Id);
         --  Checks the validity of the bounds of a choice. When the bounds
         --  are static and no error occurred the bounds are collected for
         --  later entry into the choices table so that they can be sorted
         --  later on.

         -----------
         -- Check --
         -----------

         procedure Check (Choice : Node_Id; Lo, Hi : Node_Id) is
            Lo_Val : Uint;
            Hi_Val : Uint;

         begin
            --  First check if an error was already detected on either bounds

            if Etype (Lo) = Any_Type or else Etype (Hi) = Any_Type then
               return;

            --  Do not insert non static choices in the table to be sorted

            elsif not Is_Static_Expression (Lo)
                    or else
                  not Is_Static_Expression (Hi)
            then
               Process_Non_Static_Choice (Choice);
               return;

            --  Ignore range which raise constraint error

            elsif Raises_Constraint_Error (Lo)
              or else Raises_Constraint_Error (Hi)
            then
               Raises_CE := True;
               return;

            --  AI05-0188 : Within an instance the non-others choices do not
            --  have to belong to the actual subtype.

            elsif Ada_Version >= Ada_2012 and then In_Instance then
               return;

            --  Otherwise we have an OK static choice

            else
               Lo_Val := Expr_Value (Lo);
               Hi_Val := Expr_Value (Hi);

               --  Do not insert null ranges in the choices table

               if Lo_Val > Hi_Val then
                  Process_Empty_Choice (Choice);
                  return;
               end if;
            end if;

            --  Check for low bound out of range

            if Lo_Val < Bounds_Lo then

               --  If the choice is an entity name, then it is a type, and we
               --  want to post the message on the reference to this entity.
               --  Otherwise post it on the lower bound of the range.

               if Is_Entity_Name (Choice) then
                  Enode := Choice;
               else
                  Enode := Lo;
               end if;

               --  Specialize message for integer/enum type

               if Is_Integer_Type (Bounds_Type) then
                  Error_Msg_Uint_1 := Bounds_Lo;
                  Error_Msg_N ("minimum allowed choice value is^", Enode);
               else
                  Error_Msg_Name_1 := Choice_Image (Bounds_Lo, Bounds_Type);
                  Error_Msg_N ("minimum allowed choice value is%", Enode);
               end if;
            end if;

            --  Check for high bound out of range

            if Hi_Val > Bounds_Hi then

               --  If the choice is an entity name, then it is a type, and we
               --  want to post the message on the reference to this entity.
               --  Otherwise post it on the upper bound of the range.

               if Is_Entity_Name (Choice) then
                  Enode := Choice;
               else
                  Enode := Hi;
               end if;

               --  Specialize message for integer/enum type

               if Is_Integer_Type (Bounds_Type) then
                  Error_Msg_Uint_1 := Bounds_Hi;
                  Error_Msg_N ("maximum allowed choice value is^", Enode);
               else
                  Error_Msg_Name_1 := Choice_Image (Bounds_Hi, Bounds_Type);
                  Error_Msg_N ("maximum allowed choice value is%", Enode);
               end if;
            end if;

            --  Collect bounds in the list

            --  Note: we still store the bounds, even if they are out of range,
            --  since this may prevent unnecessary cascaded errors for values
            --  that are covered by such an excessive range.

            Choice_List :=
              new Link'(Val => (Lo, Hi, Choice), Nxt => Choice_List);
            Num_Choices := Num_Choices + 1;
         end Check;

      --  Start of processing for Analyze_Choices

      begin
         Raises_CE      := False;
         Others_Present := False;

         --  If Subtyp is not a static subtype Ada 95 requires then we use the
         --  bounds of its base type to determine the values covered by the
         --  discrete choices.

         --  In Ada 2012, if the subtype has a non-static predicate the full
         --  range of the base type must be covered as well.

         if Is_OK_Static_Subtype (Subtyp) then
            if not Has_Predicates (Subtyp)
              or else Present (Static_Predicate (Subtyp))
            then
               Bounds_Type := Subtyp;
            else
               Bounds_Type := Choice_Type;
            end if;

         else
            Bounds_Type := Choice_Type;
         end if;

         --  Obtain static bounds of type, unless this is a generic formal
         --  discrete type for which all choices will be non-static.

         if not Is_Generic_Type (Root_Type (Bounds_Type))
           or else Ekind (Bounds_Type) /= E_Enumeration_Type
         then
            Bounds_Lo := Expr_Value (Type_Low_Bound (Bounds_Type));
            Bounds_Hi := Expr_Value (Type_High_Bound (Bounds_Type));
         end if;

         if Choice_Type = Universal_Integer then
            Expected_Type := Any_Integer;
         else
            Expected_Type := Choice_Type;
         end if;

         --  Now loop through the case alternatives or record variants

         Alt := First (Get_Alternatives (N));
         while Present (Alt) loop

            --  If pragma, just analyze it

            if Nkind (Alt) = N_Pragma then
               Analyze (Alt);

            --  Otherwise check each choice against its base type

            else
               Choice := First (Get_Choices (Alt));
               while Present (Choice) loop
                  Delete_Choice := False;
                  Analyze (Choice);
                  Kind := Nkind (Choice);

                  --  Choice is a Range

                  if Kind = N_Range
                    or else (Kind = N_Attribute_Reference
                              and then Attribute_Name (Choice) = Name_Range)
                  then
                     Resolve (Choice, Expected_Type);
                     Check (Choice, Low_Bound (Choice), High_Bound (Choice));

                  --  Choice is a subtype name

                  elsif Is_Entity_Name (Choice)
                    and then Is_Type (Entity (Choice))
                  then
                     if not Covers (Expected_Type, Etype (Choice)) then
                        Wrong_Type (Choice, Choice_Type);

                     else
                        E := Entity (Choice);

                        --  Case of predicated subtype

                        if Has_Predicates (E) then

                           --  Use of non-static predicate is an error

                           if not Is_Discrete_Type (E)
                             or else No (Static_Predicate (E))
                           then
                              Bad_Predicated_Subtype_Use
                                ("cannot use subtype& with non-static "
                                 & "predicate as case alternative", Choice, E);

                              --  Static predicate case

                           else
                              declare
                                 Copy : constant List_Id := Empty_List;
                                 P    : Node_Id;
                                 C    : Node_Id;

                              begin
                                 --  Loop through entries in predicate list,
                                 --  converting to choices. Note that if the
                                 --  list is empty, corresponding to a False
                                 --  predicate, then no choices are inserted.

                                 P := First (Static_Predicate (E));
                                 while Present (P) loop
                                    C := New_Copy (P);
                                    Set_Sloc (C, Sloc (Choice));
                                    Append_To (Copy, C);
                                    Next (P);
                                 end loop;

                                 Insert_List_After (Choice, Copy);
                                 Delete_Choice := True;
                              end;
                           end if;

                        --  Not predicated subtype case

                        elsif not Is_Static_Subtype (E) then
                           Process_Non_Static_Choice (Choice);
                        else
                           Check
                             (Choice, Type_Low_Bound (E), Type_High_Bound (E));
                        end if;
                     end if;

                  --  Choice is a subtype indication

                  elsif Kind = N_Subtype_Indication then
                     Resolve_Discrete_Subtype_Indication
                       (Choice, Expected_Type);

                     --  Here for other than predicated subtype case

                     if Etype (Choice) /= Any_Type then
                        declare
                           C : constant Node_Id := Constraint (Choice);
                           R : constant Node_Id := Range_Expression (C);
                           L : constant Node_Id := Low_Bound (R);
                           H : constant Node_Id := High_Bound (R);

                        begin
                           E := Entity (Subtype_Mark (Choice));

                           if not Is_Static_Subtype (E) then
                              Process_Non_Static_Choice (Choice);

                           else
                              if Is_OK_Static_Expression (L)
                                and then Is_OK_Static_Expression (H)
                              then
                                 if Expr_Value (L) > Expr_Value (H) then
                                    Process_Empty_Choice (Choice);
                                 else
                                    if Is_Out_Of_Range (L, E) then
                                       Apply_Compile_Time_Constraint_Error
                                         (L, "static value out of range",
                                          CE_Range_Check_Failed);
                                    end if;

                                    if Is_Out_Of_Range (H, E) then
                                       Apply_Compile_Time_Constraint_Error
                                         (H, "static value out of range",
                                          CE_Range_Check_Failed);
                                    end if;
                                 end if;
                              end if;

                              Check (Choice, L, H);
                           end if;
                        end;
                     end if;

                  --  The others choice is only allowed for the last
                  --  alternative and as its only choice.

                  elsif Kind = N_Others_Choice then
                     if not (Choice = First (Get_Choices (Alt))
                             and then Choice = Last (Get_Choices (Alt))
                             and then Alt = Last (Get_Alternatives (N)))
                     then
                        Error_Msg_N
                          ("the choice OTHERS must appear alone and last",
                           Choice);
                        return;
                     end if;

                     Others_Present := True;
                     Others_Choice  := Choice;

                  --  Only other possibility is an expression

                  else
                     Resolve (Choice, Expected_Type);
                     Check (Choice, Choice, Choice);
                  end if;

                  --  Move to next choice, deleting the current one if the
                  --  flag requesting this deletion is set True.

                  declare
                     C : constant Node_Id := Choice;
                  begin
                     Next (Choice);

                     if Delete_Choice then
                        Remove (C);
                     end if;
                  end;
               end loop;

               Process_Associated_Node (Alt);
            end if;

            Next (Alt);
         end loop;

         --  Now we can create the Choice_Table, since we know how long
         --  it needs to be so we can allocate exactly the right length.

         declare
            Choice_Table : Choice_Table_Type (0 .. Num_Choices);

         begin
            --  Now copy the items we collected in the linked list into this
            --  newly allocated table (leave entry 0 unused for sorting).

            declare
               T : Link_Ptr;
            begin
               for J in 1 .. Num_Choices loop
                  T := Choice_List;
                  Choice_List := T.Nxt;
                  Choice_Table (J) := T.Val;
                  Free (T);
               end loop;
            end;

            Check_Choices
              (Choice_Table,
               Bounds_Type,
               Subtyp,
               Others_Present or else (Choice_Type = Universal_Integer),
               N);

            --  If no others choice we are all done, otherwise we have one more
            --  step, which is to set the Others_Discrete_Choices field of the
            --  others choice (to contain all otherwise unspecified choices).
            --  Skip this if CE is known to be raised.

            if Others_Present and not Raises_CE then
               Expand_Others_Choice
                 (Case_Table    => Choice_Table,
                  Others_Choice => Others_Choice,
                  Choice_Type   => Bounds_Type);
            end if;
         end;
      end Analyze_Choices;

   end Generic_Choices_Processing;

end Sem_Case;
