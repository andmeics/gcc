!pr 14056
       INTRINSIC  IABS
       INTEGER FF324
       IVCOMP = FF324(IABS,-7)
       IF (IVCOMP.NE.8) STOP 1
       END
      INTEGER FUNCTION FF324(NINT, IDON03)
      FF324 = NINT(IDON03) + 1
!          **** THE NAME NINT IS A DUMMY ARGUMENT
!                   AND NOT AN INTRINSIC FUNCTION REFERENCE *****
      RETURN
      END
