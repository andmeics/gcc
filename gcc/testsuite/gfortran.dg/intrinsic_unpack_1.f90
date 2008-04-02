! { dg-do run }
! Program to test the UNPACK intrinsic for the types usually present.
program intrinsic_unpack
   implicit none
   integer(kind=1), dimension(3, 3) :: a1, b1
   integer(kind=2), dimension(3, 3) :: a2, b2
   integer(kind=4), dimension(3, 3) :: a4, b4
   integer(kind=8), dimension(3, 3) :: a8, b8
   real(kind=4), dimension(3,3) :: ar4, br4
   real(kind=8), dimension(3,3) :: ar8, br8
   logical, dimension(3, 3) :: mask
   character(len=100) line1, line2
   integer i

   mask = reshape ((/.false.,.true.,.false.,.true.,.false.,.false.,&
                    &.false.,.false.,.true./), (/3, 3/));
   a1 = reshape ((/1, 0, 0, 0, 1, 0, 0, 0, 1/), (/3, 3/));
   b1 = unpack ((/2_1, 3_1, 4_1/), mask, a1)
   if (any (b1 .ne. reshape ((/1, 2, 0, 3, 1, 0, 0, 0, 4/), (/3, 3/)))) &
      call abort
   write (line1,'(10I4)') b1
   write (line2,'(10I4)') unpack((/2_1, 3_1, 4_1/), mask, a1)
   if (line1 .ne. line2) call abort
   b1 = -1
   b1 = unpack ((/2_1, 3_1, 4_1/), mask, 0_1)
   if (any (b1 .ne. reshape ((/0, 2, 0, 3, 0, 0, 0, 0, 4/), (/3, 3/)))) &
      call abort

   a2 = reshape ((/1, 0, 0, 0, 1, 0, 0, 0, 1/), (/3, 3/));
   b2 = unpack ((/2_2, 3_2, 4_2/), mask, a2)
   if (any (b2 .ne. reshape ((/1, 2, 0, 3, 1, 0, 0, 0, 4/), (/3, 3/)))) &
      call abort
   write (line1,'(10I4)') b2
   write (line2,'(10I4)') unpack((/2_2, 3_2, 4_2/), mask, a2)
   if (line1 .ne. line2) call abort
   b2 = -1
   b2 = unpack ((/2_2, 3_2, 4_2/), mask, 0_2)
   if (any (b2 .ne. reshape ((/0, 2, 0, 3, 0, 0, 0, 0, 4/), (/3, 3/)))) &
      call abort

   a4 = reshape ((/1, 0, 0, 0, 1, 0, 0, 0, 1/), (/3, 3/));
   b4 = unpack ((/2_4, 3_4, 4_4/), mask, a4)
   if (any (b4 .ne. reshape ((/1, 2, 0, 3, 1, 0, 0, 0, 4/), (/3, 3/)))) &
      call abort
   write (line1,'(10I4)') b4
   write (line2,'(10I4)') unpack((/2_4, 3_4, 4_4/), mask, a4)
   if (line1 .ne. line2) call abort
   b4 = -1
   b4 = unpack ((/2_4, 3_4, 4_4/), mask, 0_4)
   if (any (b4 .ne. reshape ((/0, 2, 0, 3, 0, 0, 0, 0, 4/), (/3, 3/)))) &
      call abort

   a8 = reshape ((/1, 0, 0, 0, 1, 0, 0, 0, 1/), (/3, 3/));
   b8 = unpack ((/2_8, 3_8, 4_8/), mask, a8)
   if (any (b8 .ne. reshape ((/1, 2, 0, 3, 1, 0, 0, 0, 4/), (/3, 3/)))) &
      call abort
   write (line1,'(10I4)') b8
   write (line2,'(10I4)') unpack((/2_8, 3_8, 4_8/), mask, a8)
   if (line1 .ne. line2) call abort
   b8 = -1
   b8 = unpack ((/2_8, 3_8, 4_8/), mask, 0_8)
   if (any (b8 .ne. reshape ((/0, 2, 0, 3, 0, 0, 0, 0, 4/), (/3, 3/)))) &
      call abort

   ar4 = reshape ((/1._4, 0._4, 0._4, 0._4, 1._4, 0._4, 0._4, 0._4, 1._4/), &
         (/3, 3/));
   br4 = unpack ((/2._4, 3._4, 4._4/), mask, ar4)
   if (any (br4 .ne. reshape ((/1._4, 2._4, 0._4, 3._4, 1._4, 0._4, &
                               0._4, 0._4, 4._4/), (/3, 3/)))) &
      call abort
   write (line1,'(9F9.5)') br4
   write (line2,'(9F9.5)') unpack((/2._4, 3._4, 4._4/), mask, ar4)
   if (line1 .ne. line2) call abort
   br4 = -1._4
   br4 = unpack ((/2._4, 3._4, 4._4/), mask, 0._4)
   if (any (br4 .ne. reshape ((/0._4, 2._4, 0._4, 3._4, 0._4, 0._4, &
      0._4, 0._4, 4._4/), (/3, 3/)))) &
      call abort

   ar8 = reshape ((/1._8, 0._8, 0._8, 0._8, 1._8, 0._8, 0._8, 0._8, 1._8/), &
         (/3, 3/));
   br8 = unpack ((/2._8, 3._8, 4._8/), mask, ar8)
   if (any (br8 .ne. reshape ((/1._8, 2._8, 0._8, 3._8, 1._8, 0._8, &
                               0._8, 0._8, 4._8/), (/3, 3/)))) &
      call abort
   write (line1,'(9F9.5)') br8
   write (line2,'(9F9.5)') unpack((/2._8, 3._8, 4._8/), mask, ar8)
   if (line1 .ne. line2) call abort
   br8 = -1._8
   br8 = unpack ((/2._8, 3._8, 4._8/), mask, 0._8)
   if (any (br8 .ne. reshape ((/0._8, 2._8, 0._8, 3._8, 0._8, 0._8, &
      0._8, 0._8, 4._8/), (/3, 3/)))) &
      call abort

end program
