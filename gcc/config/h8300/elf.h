/* Undefine some macros defined in h8300 that conflict with elfos.h .  */
#undef SDB_DEBUGGING_INFO
#undef DBX_DEBUGGING_INFO
#undef ASM_OUTPUT_IDENT
#undef IDENT_ASM_OP
#undef CTORS_SECTION_ASM_OP
#undef DTORS_SECTION_ASM_OP
#undef INIT_SECTION_ASM_OP
#undef READONLY_DATA_SECTION_ASM_OP
#undef TARGET_ASM_NAMED_SECTION
#undef TARGET_MEM_FUNCTIONS
#undef PREFERRED_DEBUGGING_TYPE
/* ??? h8300.h defines PCC_BITFIELD_TYPE_MATTERS to 0, but it
   doesn't define STRUCTURE_SIZE_BOUNDARY, nor does h8300.md
   have a full set of bit field instructions.  */
#undef PCC_BITFIELD_TYPE_MATTERS

#define PREFERRED_DEBUGGING_TYPE DWARF2_DEBUG

#include "dbxelf.h"
#include "elfos.h"


#undef  ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s %{pg:gcrtn.o%s}%{!pg:crtn.o%s}"

#undef	STARTFILE_SPEC
#define STARTFILE_SPEC "%{!shared: \
			 %{!symbolic: \
			  %{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}}}\
			%{pg:gcrti.o%s}%{!pg:crti.o%s} \
			crtbegin.o%s"

#undef USER_LABEL_PREFIX
#define USER_LABEL_PREFIX "_"

#define JUMP_TABLES_IN_TEXT_SECTION (flag_pic)

#undef LINK_SPEC
#define LINK_SPEC "%{mh:%{mn:-m h8300hnelf}} %{mh:%{!mn:-m h8300helf}} %{ms:%{mn:-m h8300snelf}} %{ms:%{!mn:-m h8300self}}"
