------------------------------------------------------------------------------
--                                                                          --
--                         GNAT COMPILER COMPONENTS                         --
--                                                                          --
--                              R E P I N F O                               --
--                                                                          --
--                                 B o d y                                  --
--                                                                          --
--                            $Revision: 1.2 $
--                                                                          --
--          Copyright (C) 1999-2001 Free Software Foundation, Inc.          --
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

with Alloc;    use Alloc;
with Atree;    use Atree;
with Casing;   use Casing;
with Debug;    use Debug;
with Einfo;    use Einfo;
with Lib;      use Lib;
with Namet;    use Namet;
with Opt;      use Opt;
with Output;   use Output;
with Sinfo;    use Sinfo;
with Sinput;   use Sinput;
with Table;    use Table;
with Uname;    use Uname;
with Urealp;   use Urealp;

package body Repinfo is

   SSU : constant := 8;
   --  Value for Storage_Unit, we do not want to get this from TTypes, since
   --  this introduces problematic dependencies in ASIS, and in any case this
   --  value is assumed to be 8 for the implementation of the DDA.
   --  This is wrong for AAMP???

   ---------------------------------------
   -- Representation of gcc Expressions --
   ---------------------------------------

   --    This table is used only if Frontend_Layout_On_Target is False,
   --    so that gigi lays out dynamic size/offset fields using encoded
   --    gcc expressions.

   --    A table internal to this unit is used to hold the values of
   --    back annotated expressions. This table is written out by -gnatt
   --    and read back in for ASIS processing.

   --    Node values are stored as Uint values which are the negative of
   --    the node index in this table. Constants appear as non-negative
   --    Uint values.

   type Exp_Node is record
      Expr : TCode;
      Op1  : Node_Ref_Or_Val;
      Op2  : Node_Ref_Or_Val;
      Op3  : Node_Ref_Or_Val;
   end record;

   package Rep_Table is new Table.Table (
      Table_Component_Type => Exp_Node,
      Table_Index_Type     => Nat,
      Table_Low_Bound      => 1,
      Table_Initial        => Alloc.Rep_Table_Initial,
      Table_Increment      => Alloc.Rep_Table_Increment,
      Table_Name           => "BE_Rep_Table");

   --------------------------------------------------------------
   -- Representation of Front-End Dynamic Size/Offset Entities --
   --------------------------------------------------------------

   package Dynamic_SO_Entity_Table is new Table.Table (
      Table_Component_Type => Entity_Id,
      Table_Index_Type     => Nat,
      Table_Low_Bound      => 1,
      Table_Initial        => Alloc.Rep_Table_Initial,
      Table_Increment      => Alloc.Rep_Table_Increment,
      Table_Name           => "FE_Rep_Table");

   -----------------------
   -- Local Subprograms --
   -----------------------

   Unit_Casing : Casing_Type;
   --  Identifier casing for current unit

   procedure Spaces (N : Natural);
   --  Output given number of spaces

   function Back_End_Layout return Boolean;
   --  Test for layout mode, True = back end, False = front end. This
   --  function is used rather than checking the configuration parameter
   --  because we do not want Repinfo to depend on Targparm (for ASIS)

   procedure List_Entities (Ent : Entity_Id);
   --  This procedure lists the entities associated with the entity E,
   --  starting with the First_Entity and using the Next_Entity link.
   --  If a nested package is found, entities within the package are
   --  recursively processed.

   procedure List_Name (Ent : Entity_Id);
   --  List name of entity Ent in appropriate case. The name is listed with
   --  full qualification up to but not including the compilation unit name.

   procedure List_Array_Info (Ent : Entity_Id);
   --  List representation info for array type Ent

   procedure List_Object_Info (Ent : Entity_Id);
   --  List representation info for object Ent

   procedure List_Record_Info (Ent : Entity_Id);
   --  List representation info for record type Ent

   procedure List_Type_Info (Ent : Entity_Id);
   --  List type info for type Ent

   function Rep_Not_Constant (Val : Node_Ref_Or_Val) return Boolean;
   --  Returns True if Val represents a variable value, and False if it
   --  represents a value that is fixed at compile time.

   procedure Write_Val (Val : Node_Ref_Or_Val; Paren : Boolean := False);
   --  Given a representation value, write it out. No_Uint values or values
   --  dependent on discriminants are written as two question marks. If the
   --  flag Paren is set, then the output is surrounded in parentheses if
   --  it is other than a simple value.

   ---------------------
   -- Back_End_Layout --
   ---------------------

   function Back_End_Layout return Boolean is
   begin
      --  We have back end layout if the back end has made any entries in
      --  the table of GCC expressions, otherwise we have front end layout.

      return Rep_Table.Last > 0;
   end Back_End_Layout;

   ------------------------
   -- Create_Discrim_Ref --
   ------------------------

   function Create_Discrim_Ref
     (Discr : Entity_Id)
      return  Node_Ref
   is
      N : constant Uint := Discriminant_Number (Discr);
      T : Nat;

   begin
      Rep_Table.Increment_Last;
      T := Rep_Table.Last;
      Rep_Table.Table (T).Expr := Discrim_Val;
      Rep_Table.Table (T).Op1  := N;
      Rep_Table.Table (T).Op2  := No_Uint;
      Rep_Table.Table (T).Op3  := No_Uint;
      return UI_From_Int (-T);
   end Create_Discrim_Ref;

   ---------------------------
   -- Create_Dynamic_SO_Ref --
   ---------------------------

   function Create_Dynamic_SO_Ref
     (E    : Entity_Id)
      return Dynamic_SO_Ref
   is
      T : Nat;

   begin
      Dynamic_SO_Entity_Table.Increment_Last;
      T := Dynamic_SO_Entity_Table.Last;
      Dynamic_SO_Entity_Table.Table (T) := E;
      return UI_From_Int (-T);
   end Create_Dynamic_SO_Ref;

   -----------------
   -- Create_Node --
   -----------------

   function Create_Node
     (Expr : TCode;
      Op1  : Node_Ref_Or_Val;
      Op2  : Node_Ref_Or_Val := No_Uint;
      Op3  : Node_Ref_Or_Val := No_Uint)
      return  Node_Ref
   is
      T : Nat;

   begin
      Rep_Table.Increment_Last;
      T := Rep_Table.Last;
      Rep_Table.Table (T).Expr := Expr;
      Rep_Table.Table (T).Op1  := Op1;
      Rep_Table.Table (T).Op2  := Op2;
      Rep_Table.Table (T).Op3  := Op3;

      return UI_From_Int (-T);
   end Create_Node;

   ---------------------------
   -- Get_Dynamic_SO_Entity --
   ---------------------------

   function Get_Dynamic_SO_Entity
     (U    : Dynamic_SO_Ref)
      return Entity_Id
   is
   begin
      return Dynamic_SO_Entity_Table.Table (-UI_To_Int (U));
   end Get_Dynamic_SO_Entity;

   -----------------------
   -- Is_Dynamic_SO_Ref --
   -----------------------

   function Is_Dynamic_SO_Ref (U : SO_Ref) return Boolean is
   begin
      return U < Uint_0;
   end Is_Dynamic_SO_Ref;

   ----------------------
   -- Is_Static_SO_Ref --
   ----------------------

   function Is_Static_SO_Ref (U : SO_Ref) return Boolean is
   begin
      return U >= Uint_0;
   end Is_Static_SO_Ref;

   ---------
   -- lgx --
   ---------

   procedure lgx (U : Node_Ref_Or_Val) is
   begin
      List_GCC_Expression (U);
      Write_Eol;
   end lgx;

   ----------------------
   -- List_Array_Info --
   ----------------------

   procedure List_Array_Info (Ent : Entity_Id) is
   begin
      List_Type_Info (Ent);

      Write_Str ("for ");
      List_Name (Ent);
      Write_Str ("'Component_Size use ");
      Write_Val (Component_Size (Ent));
      Write_Line (";");
   end List_Array_Info;

   -------------------
   -- List_Entities --
   -------------------

   procedure List_Entities (Ent : Entity_Id) is
      E : Entity_Id;

   begin
      if Present (Ent) then
         E := First_Entity (Ent);
         while Present (E) loop
            if Comes_From_Source (E) or else Debug_Flag_AA then

               if Is_Record_Type (E) then
                  List_Record_Info (E);

               elsif Is_Array_Type (E) then
                  List_Array_Info (E);

               elsif List_Representation_Info >= 2 then

                  if Is_Type (E) then
                     List_Type_Info (E);

                  elsif Ekind (E) = E_Variable
                          or else
                        Ekind (E) = E_Constant
                          or else
                        Ekind (E) = E_Loop_Parameter
                          or else
                        Is_Formal (E)
                  then
                     List_Object_Info (E);
                  end if;
               end if;

               --  Recurse over nested package, but not if they are
               --  package renamings (in particular renamings of the
               --  enclosing package, as for some Java bindings and
               --  for generic instances).

               if (Ekind (E) = E_Package
                         and then No (Renamed_Object (E)))
                       or else
                     Ekind (E) = E_Protected_Type
                       or else
                     Ekind (E) = E_Task_Type
                       or else
                     Ekind (E) = E_Subprogram_Body
                       or else
                     Ekind (E) = E_Package_Body
                       or else
                     Ekind (E) = E_Task_Body
                       or else
                     Ekind (E) = E_Protected_Body
               then
                  List_Entities (E);
               end if;
            end if;

            E := Next_Entity (E);
         end loop;
      end if;
   end List_Entities;

   -------------------------
   -- List_GCC_Expression --
   -------------------------

   procedure List_GCC_Expression (U : Node_Ref_Or_Val) is

      procedure P (Val : Node_Ref_Or_Val);
      --  Internal recursive procedure to print expression

      procedure P (Val : Node_Ref_Or_Val) is
      begin
         if Val >= 0 then
            UI_Write (Val, Decimal);

         else
            declare
               Node : Exp_Node renames Rep_Table.Table (-UI_To_Int (Val));

               procedure Binop (S : String);
               --  Output text for binary operator with S being operator name

               procedure Binop (S : String) is
               begin
                  Write_Char ('(');
                  P (Node.Op1);
                  Write_Str (S);
                  P (Node.Op2);
                  Write_Char (')');
               end Binop;

            --  Start of processing for P

            begin
               case Node.Expr is
                  when Cond_Expr =>
                     Write_Str ("(if ");
                     P (Node.Op1);
                     Write_Str (" then ");
                     P (Node.Op2);
                     Write_Str (" else ");
                     P (Node.Op3);
                     Write_Str (" end)");

                  when Plus_Expr =>
                     Binop (" + ");

                  when Minus_Expr =>
                     Binop (" - ");

                  when Mult_Expr =>
                     Binop (" * ");

                  when Trunc_Div_Expr =>
                     Binop (" /t ");

                  when Ceil_Div_Expr =>
                     Binop (" /c ");

                  when Floor_Div_Expr =>
                     Binop (" /f ");

                  when Trunc_Mod_Expr =>
                     Binop (" modt ");

                  when Floor_Mod_Expr =>
                     Binop (" modf ");

                  when Ceil_Mod_Expr =>
                     Binop (" modc ");

                  when Exact_Div_Expr =>
                     Binop (" /e ");

                  when Negate_Expr =>
                     Write_Char ('-');
                     P (Node.Op1);

                  when Min_Expr =>
                     Binop (" min ");

                  when Max_Expr =>
                     Binop (" max ");

                  when Abs_Expr =>
                     Write_Str ("abs ");
                     P (Node.Op1);

                  when Truth_Andif_Expr =>
                     Binop (" and if ");

                  when Truth_Orif_Expr =>
                     Binop (" or if ");

                  when Truth_And_Expr =>
                     Binop (" and ");

                  when Truth_Or_Expr =>
                     Binop (" or ");

                  when Truth_Xor_Expr =>
                     Binop (" xor ");

                  when Truth_Not_Expr =>
                     Write_Str ("not ");
                     P (Node.Op1);

                  when Lt_Expr =>
                     Binop (" < ");

                  when Le_Expr =>
                     Binop (" <= ");

                  when Gt_Expr =>
                     Binop (" > ");

                  when Ge_Expr =>
                     Binop (" >= ");

                  when Eq_Expr =>
                     Binop (" == ");

                  when Ne_Expr =>
                     Binop (" != ");

                  when Discrim_Val =>
                     Write_Char ('#');
                     UI_Write (Node.Op1);

               end case;
            end;
         end if;
      end P;

   --  Start of processing for List_GCC_Expression

   begin
      if U = No_Uint then
         Write_Line ("??");
      else
         P (U);
      end if;
   end List_GCC_Expression;

   ---------------
   -- List_Name --
   ---------------

   procedure List_Name (Ent : Entity_Id) is
   begin
      if not Is_Compilation_Unit (Scope (Ent)) then
         List_Name (Scope (Ent));
         Write_Char ('.');
      end if;

      Get_Unqualified_Decoded_Name_String (Chars (Ent));
      Set_Casing (Unit_Casing);
      Write_Str (Name_Buffer (1 .. Name_Len));
   end List_Name;

   ---------------------
   -- List_Object_Info --
   ---------------------

   procedure List_Object_Info (Ent : Entity_Id) is
   begin
      Write_Eol;

      if Known_Esize (Ent) then
         Write_Str ("for ");
         List_Name (Ent);
         Write_Str ("'Size use ");
         Write_Val (Esize (Ent));
         Write_Line (";");
      end if;

      if Known_Alignment (Ent) then
         Write_Str ("for ");
         List_Name (Ent);
         Write_Str ("'Alignment use ");
         Write_Val (Alignment (Ent));
         Write_Line (";");
      end if;
   end List_Object_Info;

   ----------------------
   -- List_Record_Info --
   ----------------------

   procedure List_Record_Info (Ent : Entity_Id) is
      Comp  : Entity_Id;
      Esiz  : Uint;
      Cfbit : Uint;
      Sunit : Uint;

      Max_Name_Length : Natural;
      Max_Suni_Length : Natural;

   begin
      List_Type_Info (Ent);

      Write_Str ("for ");
      List_Name (Ent);
      Write_Line (" use record");

      --  First loop finds out max line length and max starting position
      --  length, for the purpose of lining things up nicely.

      Max_Name_Length := 0;
      Max_Suni_Length   := 0;

      Comp := First_Entity (Ent);
      while Present (Comp) loop
         if Ekind (Comp) = E_Component
           or else Ekind (Comp) = E_Discriminant
         then
            Get_Decoded_Name_String (Chars (Comp));
            Max_Name_Length := Natural'Max (Max_Name_Length, Name_Len);

            Cfbit := Component_Bit_Offset (Comp);

            if Rep_Not_Constant (Cfbit) then
               UI_Image_Length := 2;

            else
               --  Complete annotation in case not done

               Set_Normalized_Position (Comp, Cfbit / SSU);
               Set_Normalized_First_Bit (Comp, Cfbit mod SSU);

               Esiz  := Esize (Comp);
               Sunit := Cfbit / SSU;
               UI_Image (Sunit);
            end if;

            if Unknown_Normalized_First_Bit (Comp) then
               Set_Normalized_First_Bit (Comp, Uint_0);
            end if;

            Max_Suni_Length :=
              Natural'Max (Max_Suni_Length, UI_Image_Length);
         end if;

         Comp := Next_Entity (Comp);
      end loop;

      --  Second loop does actual output based on those values

      Comp := First_Entity (Ent);
      while Present (Comp) loop
         if Ekind (Comp) = E_Component
           or else Ekind (Comp) = E_Discriminant
         then
            declare
               Esiz : constant Uint := Esize (Comp);
               Bofs : constant Uint := Component_Bit_Offset (Comp);
               Npos : constant Uint := Normalized_Position (Comp);
               Fbit : constant Uint := Normalized_First_Bit (Comp);
               Lbit : Uint;

            begin
               Write_Str ("   ");
               Get_Decoded_Name_String (Chars (Comp));
               Set_Casing (Unit_Casing);
               Write_Str (Name_Buffer (1 .. Name_Len));

               for J in 1 .. Max_Name_Length - Name_Len loop
                  Write_Char (' ');
               end loop;

               Write_Str (" at ");

               if Known_Static_Normalized_Position (Comp) then
                  UI_Image (Npos);
                  Spaces (Max_Suni_Length - UI_Image_Length);
                  Write_Str (UI_Image_Buffer (1 .. UI_Image_Length));

               elsif Known_Component_Bit_Offset (Comp)
                 and then List_Representation_Info = 3
               then
                  Spaces (Max_Suni_Length - 2);
                  Write_Val (Bofs, Paren => True);
                  Write_Str (" / 8");

               elsif Known_Normalized_Position (Comp)
                 and then List_Representation_Info = 3
               then
                  Spaces (Max_Suni_Length - 2);
                  Write_Val (Npos);

               else
                  Write_Str ("??");
               end if;

               Write_Str (" range  ");
               UI_Write (Fbit);
               Write_Str (" .. ");

               if not Is_Dynamic_SO_Ref (Esize (Comp)) then
                  Lbit := Fbit + Esiz - 1;

                  if Lbit < 10 then
                     Write_Char (' ');
                  end if;

                  UI_Write (Lbit);

               elsif List_Representation_Info < 3 then
                  Write_Str ("??");

               else -- List_Representation >= 3

                  Write_Val (Esiz, Paren => True);

                  --  If in front end layout mode, then dynamic size is
                  --  stored in storage units, so renormalize for output

                  if not Back_End_Layout then
                     Write_Str (" * ");
                     Write_Int (SSU);
                  end if;

                  --  Add appropriate first bit offset

                  if Fbit = 0 then
                     Write_Str (" - 1");

                  elsif Fbit = 1 then
                     null;

                  else
                     Write_Str (" + ");
                     Write_Int (UI_To_Int (Fbit) - 1);
                  end if;
               end if;

               Write_Line (";");
            end;
         end if;

         Comp := Next_Entity (Comp);
      end loop;

      Write_Line ("end record;");
   end List_Record_Info;

   -------------------
   -- List_Rep_Info --
   -------------------

   procedure List_Rep_Info is
      Col : Nat;

   begin
      for U in Main_Unit .. Last_Unit loop
         if In_Extended_Main_Source_Unit (Cunit_Entity (U)) then
            Unit_Casing := Identifier_Casing (Source_Index (U));
            Write_Eol;
            Write_Str ("Representation information for unit ");
            Write_Unit_Name (Unit_Name (U));
            Col := Column;
            Write_Eol;

            for J in 1 .. Col - 1 loop
               Write_Char ('-');
            end loop;

            Write_Eol;
            List_Entities (Cunit_Entity (U));
         end if;
      end loop;
   end List_Rep_Info;

   --------------------
   -- List_Type_Info --
   --------------------

   procedure List_Type_Info (Ent : Entity_Id) is
   begin
      Write_Eol;

      --  If Esize and RM_Size are the same and known, list as Size. This
      --  is a common case, which we may as well list in simple form.

      if Esize (Ent) = RM_Size (Ent) then
         if Known_Esize (Ent) then
            Write_Str ("for ");
            List_Name (Ent);
            Write_Str ("'Size use ");
            Write_Val (Esize (Ent));
            Write_Line (";");
         end if;

      --  For now, temporary case, to be removed when gigi properly back
      --  annotates RM_Size, if RM_Size is not set, then list Esize as
      --  Size. This avoids odd Object_Size output till we fix things???

      elsif Unknown_RM_Size (Ent) then
         if Known_Esize (Ent) then
            Write_Str ("for ");
            List_Name (Ent);
            Write_Str ("'Size use ");
            Write_Val (Esize (Ent));
            Write_Line (";");
         end if;

      --  Otherwise list size values separately if they are set

      else
         if Known_Esize (Ent) then
            Write_Str ("for ");
            List_Name (Ent);
            Write_Str ("'Object_Size use ");
            Write_Val (Esize (Ent));
            Write_Line (";");
         end if;

         --  Note on following check: The RM_Size of a discrete type can
         --  legitimately be set to zero, so a special check is needed.

         if Known_RM_Size (Ent) or else Is_Discrete_Type (Ent) then
            Write_Str ("for ");
            List_Name (Ent);
            Write_Str ("'Value_Size use ");
            Write_Val (RM_Size (Ent));
            Write_Line (";");
         end if;
      end if;

      if Known_Alignment (Ent) then
         Write_Str ("for ");
         List_Name (Ent);
         Write_Str ("'Alignment use ");
         Write_Val (Alignment (Ent));
         Write_Line (";");
      end if;
   end List_Type_Info;

   ----------------------
   -- Rep_Not_Constant --
   ----------------------

   function Rep_Not_Constant (Val : Node_Ref_Or_Val) return Boolean is
   begin
      if Val = No_Uint or else Val < 0 then
         return True;
      else
         return False;
      end if;
   end Rep_Not_Constant;

   ---------------
   -- Rep_Value --
   ---------------

   function Rep_Value
     (Val  : Node_Ref_Or_Val;
      D    : Discrim_List)
      return Uint
   is
      function B (Val : Boolean) return Uint;
      --  Returns Uint_0 for False, Uint_1 for True

      function T (Val : Node_Ref_Or_Val) return Boolean;
      --  Returns True for 0, False for any non-zero (i.e. True)

      function V (Val : Node_Ref_Or_Val) return Uint;
      --  Internal recursive routine to evaluate tree

      -------
      -- B --
      -------

      function B (Val : Boolean) return Uint is
      begin
         if Val then
            return Uint_1;
         else
            return Uint_0;
         end if;
      end B;

      -------
      -- T --
      -------

      function T (Val : Node_Ref_Or_Val) return Boolean is
      begin
         if V (Val) = 0 then
            return False;
         else
            return True;
         end if;
      end T;

      -------
      -- V --
      -------

      function V (Val : Node_Ref_Or_Val) return Uint is
         L, R, Q : Uint;

      begin
         if Val >= 0 then
            return Val;

         else
            declare
               Node : Exp_Node renames Rep_Table.Table (-UI_To_Int (Val));

            begin
               case Node.Expr is
                  when Cond_Expr =>
                     if T (Node.Op1) then
                        return V (Node.Op2);
                     else
                        return V (Node.Op3);
                     end if;

                  when Plus_Expr =>
                     return V (Node.Op1) + V (Node.Op2);

                  when Minus_Expr =>
                     return V (Node.Op1) - V (Node.Op2);

                  when Mult_Expr =>
                     return V (Node.Op1) * V (Node.Op2);

                  when Trunc_Div_Expr =>
                     return V (Node.Op1) / V (Node.Op2);

                  when Ceil_Div_Expr =>
                     return
                       UR_Ceiling
                         (V (Node.Op1) / UR_From_Uint (V (Node.Op2)));

                  when Floor_Div_Expr =>
                     return
                       UR_Floor
                         (V (Node.Op1) / UR_From_Uint (V (Node.Op2)));

                  when Trunc_Mod_Expr =>
                     return V (Node.Op1) rem V (Node.Op2);

                  when Floor_Mod_Expr =>
                     return V (Node.Op1) mod V (Node.Op2);

                  when Ceil_Mod_Expr =>
                     L := V (Node.Op1);
                     R := V (Node.Op2);
                     Q := UR_Ceiling (L / UR_From_Uint (R));
                     return L - R * Q;

                  when Exact_Div_Expr =>
                     return V (Node.Op1) / V (Node.Op2);

                  when Negate_Expr =>
                     return -V (Node.Op1);

                  when Min_Expr =>
                     return UI_Min (V (Node.Op1), V (Node.Op2));

                  when Max_Expr =>
                     return UI_Max (V (Node.Op1), V (Node.Op2));

                  when Abs_Expr =>
                     return UI_Abs (V (Node.Op1));

                  when Truth_Andif_Expr =>
                     return B (T (Node.Op1) and then T (Node.Op2));

                  when Truth_Orif_Expr =>
                     return B (T (Node.Op1) or else T (Node.Op2));

                  when Truth_And_Expr =>
                     return B (T (Node.Op1) and T (Node.Op2));

                  when Truth_Or_Expr =>
                     return B (T (Node.Op1) or T (Node.Op2));

                  when Truth_Xor_Expr =>
                     return B (T (Node.Op1) xor T (Node.Op2));

                  when Truth_Not_Expr =>
                     return B (not T (Node.Op1));

                  when Lt_Expr =>
                     return B (V (Node.Op1) < V (Node.Op2));

                  when Le_Expr =>
                     return B (V (Node.Op1) <= V (Node.Op2));

                  when Gt_Expr =>
                     return B (V (Node.Op1) > V (Node.Op2));

                  when Ge_Expr =>
                     return B (V (Node.Op1) >= V (Node.Op2));

                  when Eq_Expr =>
                     return B (V (Node.Op1) = V (Node.Op2));

                  when Ne_Expr =>
                     return B (V (Node.Op1) /= V (Node.Op2));

                  when Discrim_Val =>
                     declare
                        Sub : constant Int := UI_To_Int (Node.Op1);

                     begin
                        pragma Assert (Sub in D'Range);
                        return D (Sub);
                     end;

               end case;
            end;
         end if;
      end V;

   --  Start of processing for Rep_Value

   begin
      if Val = No_Uint then
         return No_Uint;

      else
         return V (Val);
      end if;
   end Rep_Value;

   ------------
   -- Spaces --
   ------------

   procedure Spaces (N : Natural) is
   begin
      for J in 1 .. N loop
         Write_Char (' ');
      end loop;
   end Spaces;

   ---------------
   -- Tree_Read --
   ---------------

   procedure Tree_Read is
   begin
      Rep_Table.Tree_Read;
   end Tree_Read;

   ----------------
   -- Tree_Write --
   ----------------

   procedure Tree_Write is
   begin
      Rep_Table.Tree_Write;
   end Tree_Write;

   ---------------
   -- Write_Val --
   ---------------

   procedure Write_Val (Val : Node_Ref_Or_Val; Paren : Boolean := False) is
   begin
      if Rep_Not_Constant (Val) then
         if List_Representation_Info < 3 then
            Write_Str ("??");
         else
            if Back_End_Layout then
               Write_Char (' ');
               List_GCC_Expression (Val);
               Write_Char (' ');
            else
               Write_Name_Decoded (Chars (Get_Dynamic_SO_Entity (Val)));
            end if;
         end if;

      else
         UI_Write (Val);
      end if;
   end Write_Val;

end Repinfo;
