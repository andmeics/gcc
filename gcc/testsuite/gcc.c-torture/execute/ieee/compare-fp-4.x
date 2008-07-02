# The ARM VxWorks kernel uses an external floating-point library in
# which routines like __ledf2 are just aliases for __cmpdf2.  These
# routines therefore don't handle NaNs correctly.
if [istarget "arm*-*-vxworks*"] {
    set torture_eval_before_execute {
	global compiler_conditional_xfail_data
	set compiler_conditional_xfail_data {
	    "The ARM kernel uses a flawed floating-point library."
	    { "*-*-*" }
	    {}
	    { "-mrtp" }
	}
    }
}

if [istarget "spu-*-*"] {
    # The SPU single-precision floating point format does not
    # support Nan & Inf.
    return 1
}

lappend additional_flags "-fno-trapping-math"
return 0
