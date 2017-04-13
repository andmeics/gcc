-- { dg-do run }
-- { dg-options "-O" }

with Array28_Pkg; use Array28_Pkg;

procedure Array28 is

  function Get return Outer_type is
    Ret : Outer_Type;
  begin
    Ret (Inner_Type'Range) := F;
    return Ret;
  end;

  A : Outer_Type := Get;
  B : Inner_Type := A (Inner_Type'Range);

begin
  if B /= "12345" then
    raise Program_Error;
  end if;
end;
