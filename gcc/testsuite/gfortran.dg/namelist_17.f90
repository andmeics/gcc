!{ dg-do run }
! Tests namelist on logical variables
! provided by Paul Thomas - pault@gcc.gnu.org

program namelist_17
  logical, dimension(2)        ::   l
  namelist /mynml/ l
  l = (/.true., .false./)

  open (10, status = "scratch")
  write (10, '(A)') "&mynml l = F T /"
  rewind (10)
  
  read (10, mynml, iostat = ier)
  if (ier .ne. 0) call abort ()
  close (10)

  open (10, status = "scratch")
  write (10, mynml, iostat = ier)
  if (ier .ne. 0) call abort ()
  rewind (10)

  l = (/.true., .false./)
  read (10, mynml, iostat = ier)
  if (ier .ne. 0) call abort ()
  close (10)

  if (l(1) .or. (.not.l(2))) call abort ()

end program namelist_17 
