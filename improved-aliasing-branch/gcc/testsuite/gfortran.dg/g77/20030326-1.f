! { dg-do compile }
! { dg-options -pedantic }
!      PR fortran/9793
!      larson@w6yx.stanford.edu
!
! For gfortran, see PR 13490
!
       integer c
       c = -2147483648 / (-1) ! { dg-warning "outside symmetric range" "" }
       end
