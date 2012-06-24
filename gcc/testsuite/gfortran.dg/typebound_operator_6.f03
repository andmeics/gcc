! { dg-do run }
!
! PR 45961: [4.6 Regression] [OOP] Problem with polymorphic type-bound operators
!
! Contributed by Mark Rashid <mmrashid@ucdavis.edu>

MODULE DAT_MOD

  TYPE :: DAT
    INTEGER :: NN
  CONTAINS
    PROCEDURE :: LESS_THAN
    GENERIC :: OPERATOR (.LT.) => LESS_THAN
  END TYPE DAT

CONTAINS

  LOGICAL FUNCTION LESS_THAN(A, B)
    CLASS (DAT), INTENT (IN) :: A, B
    LESS_THAN = (A%NN .LT. B%NN)
  END FUNCTION LESS_THAN

END MODULE DAT_MOD


MODULE NODE_MOD
  USE DAT_MOD

  TYPE NODE
    INTEGER :: KEY
    CLASS (DAT), POINTER :: PT
  CONTAINS
    PROCEDURE :: LST
    GENERIC :: OPERATOR (.LT.) => LST
  END TYPE NODE

CONTAINS

  LOGICAL FUNCTION LST(A, B)
    CLASS (NODE), INTENT (IN) :: A, B
    IF (A%KEY .GT. 0 .AND. B%KEY .GT. 0) THEN
      LST = (A%KEY .LT. B%KEY)
    ELSE
      LST = (A%PT .LT. B%PT)
    END IF
  END FUNCTION LST

END MODULE NODE_MOD


PROGRAM TEST
  USE NODE_MOD
  IMPLICIT NONE

  CLASS (DAT), POINTER :: POINTA => NULL(), POINTB => NULL()
  CLASS (NODE), POINTER :: NDA => NULL(), NDB => NULL()

  ALLOCATE (DAT :: POINTA)
  ALLOCATE (DAT :: POINTB)
  ALLOCATE (NODE :: NDA)
  ALLOCATE (NODE :: NDB)

  POINTA%NN = 5
  NDA%PT => POINTA
  NDA%KEY = 2
  POINTB%NN = 10
  NDB%PT => POINTB
  NDB%KEY = 3

  if (.NOT. NDA .LT. NDB) call abort()
END
