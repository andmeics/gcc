! { dg-do run }
!
! PR fortran/33197
!
! Fortran 2008 complex trigonometric functions: tan, cosh, sinh, tanh
!
implicit none
real(4), parameter :: pi  = 2*acos(0.0_4)
real(8), parameter :: pi8 = 2*acos(0.0_8)
real(4), parameter :: eps  = 10*epsilon(0.0_4)
real(8), parameter :: eps8 = 10*epsilon(0.0_8)
complex(4), volatile :: z0_0  = cmplx(0.0_4, 0.0_4, kind=4)
complex(4), volatile :: z1_1  = cmplx(1.0_4, 1.0_4, kind=4)
complex(4), volatile :: zp_p  = cmplx(pi,    pi,    kind=4)
complex(8), volatile :: z80_0 = cmplx(0.0_8, 0.0_8, kind=8)
complex(8), volatile :: z81_1 = cmplx(1.0_8, 1.0_8, kind=8)
complex(8), volatile :: z8p_p = cmplx(pi8,   pi8,   kind=8)

if (abs(tan(z0_0)  - cmplx(0.0,0.0,4)) > eps) call abort()
if (abs(tan(z1_1)  - cmplx(0.27175257,1.0839232,4)) > eps) call abort()
if (abs(tan(z80_0) - cmplx(0.0_8,0.0_8,8)) > eps8) call abort()
if (abs(tan(z81_1) - cmplx(0.27175258531951174_8,1.0839233273386946_8,8)) > eps8) call abort()

if (abs(cosh(z0_0)  - cmplx(1.0,0.0,4)) > eps) call abort()
if (abs(cosh(z1_1)  - cmplx(0.83372992,0.98889768,4)) > eps) call abort()
if (abs(cosh(z80_0) - cmplx(1.0_8,0.0_8,8)) > eps8) call abort()
if (abs(cosh(z81_1) - cmplx(0.83373002513114913_8,0.98889770576286506_8,8)) > eps8) call abort()

if (abs(sinh(z0_0)  - cmplx(0.0,0.0,4)) > eps) call abort()
if (abs(sinh(z1_1)  - cmplx(0.63496387,1.2984575,4)) > eps) call abort()
if (abs(sinh(z80_0) - cmplx(0.0_8,0.0_8,8)) > eps8) call abort()
if (abs(sinh(z81_1) - cmplx(0.63496391478473613_8,1.2984575814159773_8,8)) > eps8) call abort()

if (abs(tanh(z0_0)  - cmplx(0.0,0.0,4)) > eps) call abort()
if (abs(tanh(z1_1)  - cmplx(1.0839232,0.27175257,4)) > eps) call abort()
if (abs(tanh(z80_0) - cmplx(0.0_8,0.0_8,8)) > eps8) call abort()
if (abs(tanh(z81_1) - cmplx(1.0839233273386946_8,0.27175258531951174_8,8)) > eps8) call abort()

end
