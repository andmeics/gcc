! { dg-do run }
!
! PR 36704: Procedure pointer as function result
!
! Contributed by Janus Weil <janus@gcc.gnu.org>

module mo
contains

  function j()
    implicit none
    procedure(),pointer :: j
    intrinsic iabs
    j => iabs
  end function

  subroutine sub(y)
    integer,intent(inout) :: y
    y = y**2
  end subroutine

end module


program proc_ptr_14
use mo
implicit none
intrinsic :: iabs
integer :: x
procedure(integer),pointer :: p,p2
procedure(sub),pointer :: ps

p => a()
if (p(-1)/=1) call abort()
p => b()
if (p(-2)/=2) call abort()
p => c()
if (p(-3)/=3) call abort()
p => d()
if (p(-4)/=4) call abort()
p => dd()
if (p(-4)/=4) call abort()
p => e(iabs)
if (p(-5)/=5) call abort()
p => ee()
if (p(-5)/=5) call abort()
p => f()
if (p(-6)/=6) call abort()
p => g()
if (p(-7)/=7) call abort()

ps => h(sub)
x = 2
call ps(x)
if (x/=4) call abort()

p => i()
if (p(-8)/=8) call abort()
p => j()
if (p(-9)/=9) call abort()

p => k(p2)
if (p(-10)/=p2(-10)) call abort()

p => l()
if (p(-11)/=11) call abort()

contains

  function a()
    procedure(integer),pointer :: a
    a => iabs
  end function

  function b()
    procedure(integer) :: b
    pointer :: b
    b => iabs
  end function

  function c()
    pointer :: c
    procedure(integer) :: c
    c => iabs
  end function

  function d()
    pointer :: d
    external d
    d => iabs
  end function

  function dd()
    pointer :: dd
    external :: dd
    integer :: dd
    dd => iabs
  end function

  function e(arg)
    external :: e,arg
    pointer :: e
    e => arg
  end function

  function ee()
    integer :: ee
    external :: ee
    pointer :: ee
    ee => iabs
  end function

  function f()
    pointer :: f
    interface
      integer function f(x)
        integer :: x
      end function
    end interface
    f => iabs
  end function

  function g()
    interface
      integer function g(x)
        integer :: x
      end function g
    end interface
    pointer :: g
    g => iabs
  end function

  function h(arg)
    interface
      subroutine arg(b)
        integer :: b
      end subroutine arg
    end interface
    pointer :: h
    interface
      subroutine h(a)
        integer :: a
      end subroutine h
    end interface
    h => arg
  end function

  function i()
    pointer :: i
    interface
      function i(x)
        integer :: i,x
      end function i
    end interface
    i => iabs
  end function

  function k(arg)
    procedure(),pointer :: k,arg
    k => iabs
    arg => k
  end function

  function l()
    procedure(iabs),pointer :: l
    integer :: i
    l => iabs
    if (l(-11)/=11) call abort()
  end function 

end

! { dg-final { cleanup-modules "mo" } }

