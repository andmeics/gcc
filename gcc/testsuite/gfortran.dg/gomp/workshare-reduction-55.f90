! { dg-do compile }
! { dg-options "-O2 -fopenmp -fdump-tree-optimized" }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_loop_doacross_start \[^\n\r]*, (?:2147483648|-2147483648), 0, " 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_loop_end " 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_doacross_post " 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_doacross_wait " 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_loop_runtime_next " 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_workshare_task_reduction_unregister \\(0\\)" 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_parallel " 1 "optimized" } }

module m
  implicit none (type, external)
  integer :: j
  interface
    subroutine bar(i)
      integer :: i
    end subroutine
  end interface
end module m

subroutine foo(a, b, c)
  use m
  implicit none (type, external)
  integer :: a, b ,c
  integer :: i
  !$omp parallel
  !$omp do ordered(1) reduction (task, *: j) schedule (runtime)
  do i = a, b, c
    call bar (j)
    !$omp ordered depend(sink: i - 1)
    j = j + 1
    !$omp ordered depend(source)
  end do
  !$omp end parallel
end
