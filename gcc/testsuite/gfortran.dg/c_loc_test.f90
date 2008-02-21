! { dg-do run }
! { dg-additional-sources c_loc_driver.c }
module c_loc_test
implicit none

contains
  subroutine test0() bind(c)
    use, intrinsic :: iso_c_binding
    implicit none
    integer, target :: x
    type(c_ptr) :: my_c_ptr
    interface
       subroutine test_address(x, expected_value) bind(c)
         use, intrinsic :: iso_c_binding
         type(c_ptr), value :: x
         integer(c_int), value :: expected_value
       end subroutine test_address
    end interface
    x = 100
    my_c_ptr = c_loc(x)
    call test_address(my_c_ptr, 100)
  end subroutine test0
end module c_loc_test
! { dg-final { cleanup-modules "c_loc_test" } }
