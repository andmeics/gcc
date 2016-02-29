! { dg-additional-options "-O2" }

program main
   implicit none

   integer :: a(100,100), b(100,100)
   integer :: i, j, d

   !$acc kernels
   do i=1,100
     do j=1,100
       a(i,j) = 1
       b(i,j) = 2
       a(i,j) = a(i,j) + b(i,j)
     end do
   end do
   !$acc end kernels

   d = sum(a)

   print *,d
end program main
