! { dg-do compile }
! Verifies that the c_loc scalar pointer tests recognize the string of length
! greater than one as not being allowable for the parameter to c_loc.
module x
use iso_c_binding
contains
SUBROUTINE glutInit_f03()
  TYPE(C_PTR), DIMENSION(1), TARGET :: argv=C_NULL_PTR
  character(kind=c_char, len=5), target :: string="hello"
  argv(1)=C_LOC(string) ! { dg-error "must have a length of 1" }
END SUBROUTINE
end module x

