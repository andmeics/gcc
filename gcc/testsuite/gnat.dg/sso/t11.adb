-- { dg-do run }

with Init11; use Init11;
with Text_IO; use Text_IO;
with Dump;

procedure T11 is

  Local_R1 : R1;
  Local_R2 : R2;

begin
  Local_R1.I    := My_R1.I + 1;
  Local_R1.A(1) := My_R1.A(1) + 1;
  Local_R1.A(2) := My_R1.A(2) + 1;
  Local_R1.A(3) := My_R1.A(3) + 1;

  Put ("Local_R1 :");
  Dump (Local_R1'Address, R1'Max_Size_In_Storage_Elements);
  New_Line;
  -- { dg-output "Local_R1 : 79 56 34 12 13 00 ab 00 35 00 cd 00 57 00 ef 00.*\n" }

  Local_R2.I    := My_R2.I + 1;
  Local_R2.A(1) := My_R2.A(1) + 1;
  Local_R2.A(2) := My_R2.A(2) + 1;
  Local_R2.A(3) := My_R2.A(3) + 1;

  Put ("Local_R2 :");
  Dump (Local_R2'Address, R2'Max_Size_In_Storage_Elements);
  New_Line;
  -- { dg-output "Local_R2 : 12 34 56 79 00 ab 00 13 00 cd 00 35 00 ef 00 57.*\n" }

  Local_R1 := (I => 16#12345678#,
               A => (16#AB0012#, 16#CD0034#, 16#EF0056#));
  Put ("Local_R1 :");
  Dump (Local_R1'Address, R1'Max_Size_In_Storage_Elements);
  New_Line;
  -- { dg-output "Local_R1 : 78 56 34 12 12 00 ab 00 34 00 cd 00 56 00 ef 00.*\n" }

  Local_R2 := (I => 16#12345678#,
               A => (16#AB0012#, 16#CD0034#, 16#EF0056#));
  Put ("Local_R2 :");
  Dump (Local_R2'Address, R2'Max_Size_In_Storage_Elements);
  New_Line;
  -- { dg-output "Local_R2 : 12 34 56 78 00 ab 00 12 00 cd 00 34 00 ef 00 56.*\n" }

  Local_R1.I    := Local_R1.I + 1;
  Local_R1.A(1) := Local_R1.A(1) + 1;
  Local_R1.A(2) := Local_R1.A(2) + 1;
  Local_R1.A(3) := Local_R1.A(3) + 1;

  Put ("Local_R1 :");
  Dump (Local_R1'Address, R1'Max_Size_In_Storage_Elements);
  New_Line;
  -- { dg-output "Local_R1 : 79 56 34 12 13 00 ab 00 35 00 cd 00 57 00 ef 00.*\n" }

  Local_R2.I    := Local_R2.I + 1;
  Local_R2.A(1) := Local_R2.A(1) + 1;
  Local_R2.A(2) := Local_R2.A(2) + 1;
  Local_R2.A(3) := Local_R2.A(3) + 1;

  Put ("Local_R2 :");
  Dump (Local_R2'Address, R2'Max_Size_In_Storage_Elements);
  New_Line;
  -- { dg-output "Local_R2 : 12 34 56 79 00 ab 00 13 00 cd 00 35 00 ef 00 57.*\n" }

end;
