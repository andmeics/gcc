! { dg-do run }
program main
  real, dimension(3,2) :: a
  real, dimension(6) :: b
  real, dimension(3) :: res1
  real, dimension(:), allocatable :: c1, c2,c3
  real, dimension(2) :: res2

  data a /-2., 3., -5., 7., -11., 13./
  data b /17., -23., 29., -31., 37., -41./
  data res1 /201., -320., 336./
  data res2 /158., -353./

  c1 = matmul(a,[29.,37.])
  if (size(c1,1) /= 3) call abort
  if (any(c1/=res1)) call abort

  c2 = matmul(a,pack(b,[b>20.]))
  if (size(c1,1) /= 3) call abort
  if (any(c1/=res1)) call abort

  c3 = matmul(pack(b,[b<0.]),a)
  if (size(c3,1) /= 2) call abort
  if (any(c3 /= res2)) call abort

end program main
