# Copyright (C) 2016-2017 Free Software Foundation, Inc.
#
# This file is part of GCC.
#
# GCC is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free
# Software Foundation; either version 3, or (at your option) any later
# version.
#
# GCC is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
#
# You should have received a copy of the GNU General Public License
# along with GCC; see the file COPYING3.  If not see
# <http://www.gnu.org/licenses/>.

##################################################################
#
# This file is using AVR's genmultilib.awk idea.
#
##################################################################

BEGIN {
  FS ="[(, \t)]+"
  comment = 1
  n_cores = 0
}

##################################################################
# Add some Comments to the generated Files and copy-paste
# Copyright Notice from above.
##################################################################
/^#/ {
  if (!comment)
    next
  else if (comment == 1)
    {
      if (FORMAT == "Makefile")
	{
	  print "; Auto-generated Makefile Snip"
	  print "; Generated by    : ./gcc/config/arc/genoptions.awk"
	  print "; Generated from  : ./gcc/config/arc/arc-cpu.def"
	  print ";"
	}
    }

  comment = 2;

  gsub ("^#", ";", $0)
  print
}

/^$/ {
    # The first empty line stops copy-pasting the GPL comments
    # from this file to the generated file.
    comment = 0
}

/^ARC_CPU/ {
  name = $2
  cores[n_cores] = name;
  n_cores++
}

END {
  m_option = ""
  for (c = 0; c < n_cores; c++)
    {
      m_options = m_options "EnumValue\nEnum(processor_type) String(" \
	cores[c] ") Value(PROCESSOR_" cores[c] ")\n\n"
    }

  ############################################################
  # Output that Stuff
  ############################################################

  if (FORMAT == "Makefile")
    {
	print "\nEnum"
	print "Name(processor_type) Type(enum processor_type)"
	print "Known ARC CPUs (for use with the -mcpu= option):\n"
	print m_options
    }
}
