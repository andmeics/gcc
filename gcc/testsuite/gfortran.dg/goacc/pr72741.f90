SUBROUTINE v_1
  !$ACC ROUTINE VECTOR WORKER ! { dg-error "Multiple loop axes" }
  !$ACC ROUTINE VECTOR ! { dg-error "\\!\\\$ACC ROUTINE already applied" }
  !$ACC ROUTINE ! { dg-error "\\!\\\$ACC ROUTINE already applied" }
  !$ACC ROUTINE GANG VECTOR ! { dg-error "Multiple loop axes" }
  ! { dg-error "\\!\\\$ACC ROUTINE already applied" "already" { target *-*-* } 5 }
END SUBROUTINE v_1

SUBROUTINE sub_1
  IMPLICIT NONE
  EXTERNAL :: g_1
  !$ACC ROUTINE (g_1) GANG WORKER ! { dg-error "Multiple loop axes" }
  !$ACC ROUTINE (g_1) GANG ! { dg-error "\\!\\\$ACC ROUTINE already applied" }
  !$ACC ROUTINE (g_1) ! { dg-error "\\!\\\$ACC ROUTINE already applied" }
  !$ACC ROUTINE (g_1) VECTOR GANG ! { dg-error "Multiple loop axes" }
  ! { dg-error "\\!\\\$ACC ROUTINE already applied" "already" { target *-*-* } 15 }

  CALL v_1
  CALL g_1
  CALL ABORT
END SUBROUTINE sub_1

MODULE m_w_1
  IMPLICIT NONE
  EXTERNAL :: w_1
  !$ACC ROUTINE (w_1) WORKER SEQ ! { dg-error "Multiple loop axes" }
  !$ACC ROUTINE (w_1) WORKER ! { dg-error "\\!\\\$ACC ROUTINE already applied" }
  !$ACC ROUTINE (w_1) ! { dg-error "\\!\\\$ACC ROUTINE already applied" }
  !$ACC ROUTINE (w_1) VECTOR WORKER ! { dg-error "Multiple loop axes" }
  ! { dg-error "\\!\\\$ACC ROUTINE already applied" "already" { target *-*-* } 29 }

CONTAINS
  SUBROUTINE sub_2
    CALL v_1
    CALL w_1
    CALL ABORT
  END SUBROUTINE sub_2
END MODULE m_w_1
