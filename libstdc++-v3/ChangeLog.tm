2010-04-19  Aldy Hernandez  <aldyh@redhat.com>

	* libstdc++-v3/testsuite/util/testsuite_abi.cc (check_version):
	Add CXXABI_TM_1.

2009-07-22  Richard Henderson  <rth@redhat.com>

	* libstdc++-v3/libsupc++/eh_tm.cc: New file.
	* libstdc++-v3/libsupc++/unwind-cxx.h (__cxa_tm_cleanup): Declare.
	* libstdc++-v3/config/abi/pre/gnu.ver: Export __cxa_tm_cleanup.
	* libstdc++-v3/config/abi/pre/gnu-versioned-namespace.ver: Likewise.
	* libstdc++-v3/libsupc++/Makefile.am (sources): Add eh_tm.cc.
	* libstdc++-v3/libsupc++/Makefile.in: Rebuild.
