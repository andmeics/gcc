/* File format for coverage information
   Copyright (C) 1996, 1997, 1998, 2000, 2002 Free Software Foundation, Inc.
   Contributed by Bob Manson <manson@cygnus.com>.
   Completely remangled by Nathan Sidwell <nathan@codesourcery.com>.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  */

/* Coverage information is held in two files.  A basic block graph
   file, which is generated by the compiler, and a counter file, which
   is generated by the program under test.  Both files use a similar
   structure.  We do not attempt to make these files backwards
   compatible with previous versions, as you only need coverage
   information when developing a program.  We do hold version
   information, so that mismatches can be detected, and we use a
   format that allows tools to skip information they do not understand
   or are not interested in.

   Numbers are recorded in big endian unsigned binary form.  Either in
   32 or 64 bits.  Strings are stored with a length count and NUL
   terminator, and 0 to 3 bytes of zero padding up to the next 4 byte
   boundary.  Zero length and NULL strings are simply stored as a
   length of zero (they have no trailing NUL or padding).

   	int32:  byte3 byte2 byte1 byte0
	int64:  byte7 byte6 byte5 byte4 byte3 byte2 byte1 byte0
	string: int32:0 | int32:length char* char:0 padding
	padding: | char:0 | char:0 char:0 | char:0 char:0 char:0
	item: int32 | int64 | string

   The basic format of the files is

   	file : int32:magic int32:version record*

   The magic ident is different for the bbg and the counter files.
   The version is the same for both files and is derived from gcc's
   version number.  Although the ident and version are formally 32 bit
   numbers, they are derived from 4 character ASCII strings.  The
   version number consists of the single character major version
   number, a two character minor version number (leading zero for
   versions less than 10), and a single character indicating the
   status of the release.  That will be 'e' experimental, 'p'
   prerelease and 'r' for release.  Because, by good fortune, these are
   in alphabetical order, string collating can be used to compare
   version strings, and because numbers are stored big endian, numeric
   comparison can be used when it is read as a 32 bit value.  Be aware
   that the 'e' designation will (naturally) be unstable and might be
   incompatible with itself.  For gcc 3.4 experimental, it would be
   '304e' (0x33303465).  When the major version reaches 10, the letters
   A-Z will be used.  Assuming minor increments releases every 6
   months, we have to make a major increment every 50 years.  Assuming
   major increments releases every 5 years, we're ok for the next 155
   years -- good enough for me.

   A record has a tag, length and variable amount of data.

   	record: header data
	header: int32:tag int32:length
	data: item*

   Records are not nested, but there is a record hierarchy.  Tag
   numbers reflect this hierarchy.  Tags are unique across bbg and da
   files.  Some record types have a varying amount of data.  The LENGTH
   is usually used to determine how much data.  The tag value is split
   into 4 8-bit fields, one for each of four possible levels.  The
   most significant is allocated first.  Unused levels are zero.
   Active levels are odd-valued, so that the LSB of the level is one.
   A sub-level incorporates the values of its superlevels.  This
   formatting allows you to determine the tag heirarchy, without
   understanding the tags themselves, and is similar to the standard
   section numbering used in technical documents.  Level values
   [1..3f] are used for common tags, values [41..9f] for the graph
   file and [a1..ff] for the counter file.

   The basic block graph file contains the following records
   	bbg:  function-graph*
	function-graph: announce_function basic_blocks {arcs | lines}*
	announce_function: header string:name int32:checksum
	basic_block: header int32:flags*
	arcs: header int32:block_no arc*
	arc:  int32:dest_block int32:flags
        lines: header int32:block_no line*
               int32:0 string:NULL
	line:  int32:line_no | int32:0 string:filename

   The BASIC_BLOCK record holds per-bb flags.  The number of blocks
   can be inferred from its data length.  There is one ARCS record per
   basic block.  The number of arcs from a bb is implicit from the
   data length.  It enumerates the destination bb and per-arc flags.
   There is one LINES record per basic block, it enumerates the source
   lines which belong to that basic block.  Source file names are
   introduced by a line number of 0, following lines are from the new
   source file.  The initial source file for the function is NULL, but
   the current source file should be remembered from one LINES record
   to the next.  The end of a block is indicated by an empty filename
   - this does not reset the current source file.  Note there is no
   ordering of the ARCS and LINES records: they may be in any order,
   interleaved in any manner.  The current filename follows the order
   the LINES records are stored in the file, *not* the ordering of the
   blocks they are for.

   The data file contains the following records.
        da:   {function-data* summary:object summary:program*}*
        function-data:	announce_function arc_counts
	announce_function: header string:name int32:checksum
	arc_counts: header int64:count*
	summary: in32:checksum int32:runs int32:arcs int64:sum int64:max \
		int64:max_sum int64:sum_max

   The ANNOUNCE_FUNCTION record is the same as that in the BBG file.
   The ARC_COUNTS gives the counter values for those arcs that are
   instrumented.  The SUMMARY records give information about the whole
   object file and about the whole program.  The checksum is used for
   whole program summaries, and disambiguates different programs which
   include the same instrumented object file.  There may be several
   program summaries, each with a unique checksum.  The object
   summary's checkum is zero.  Note that the da file might contain
   information from several runs concatenated, or the data might be
   merged.

   This file is included by both the compiler, gcov tools and the
   library.  The IN_LIBGCC2 define distinguishes these cases.  When
   IN_LIBGCC2 is nonzero, we're building libgcc2 for the target and
   know the compiler is (the just built) gcc.  Otherwise we're
   generating code for the host, and the compiler may or may not be
   gcc.  In this latter case, you must ensure that 'gcov_type' is
   typedefed to something suitable (unsigned HOST_WIDEST_INT is
   usually what you want).  */

#ifndef GCC_GCOV_IO_H
#define GCC_GCOV_IO_H

#if IN_LIBGCC2
#if LONG_TYPE_SIZE == GCOV_TYPE_SIZE
typedef long gcov_type;
#else
typedef long long gcov_type;
#endif
#endif /* IN_LIBGCC2 */

/* File suffixes.  */
#define GCOV_DATA_SUFFIX ".da"
#define GCOV_GRAPH_SUFFIX ".bbg"

/* File magic.  */
#define GCOV_DATA_MAGIC  0x67636f76 /* "gcov" */
#define GCOV_GRAPH_MAGIC 0x67626267 /* "gbbg" */

/* gcov-iov.h is automatically generated by the makefile from
   version.c, it looks like
   	#define GCOV_VERSION ((unsigned)0x89abcdef)
*/
#include "gcov-iov.h"

/* The record tags.  Values [1..3f] are for tags which may be in either
   file.  Values [41..9f] for those in the bbg file and [a1..ff] for
   the data file.  */

#define GCOV_TAG_FUNCTION	 ((unsigned)0x01000000)
#define GCOV_TAG_BLOCKS		 ((unsigned)0x01410000)
#define GCOV_TAG_ARCS		 ((unsigned)0x01430000)
#define GCOV_TAG_LINES		 ((unsigned)0x01450000)
#define GCOV_TAG_ARC_COUNTS  	 ((unsigned)0x01a10000)
#define GCOV_TAG_OBJECT_SUMMARY  ((unsigned)0xa1000000)
#define GCOV_TAG_PROGRAM_SUMMARY ((unsigned)0xa3000000)
#define GCOV_TAG_PLACEHOLDER_SUMMARY ((unsigned)0xa5000000)
#define GCOV_TAG_INCORRECT_SUMMARY ((unsigned)0xa7000000)

/* The tag level mask has 1's in the position of the inner levels, &
   the lsb of the current level, and zero on the current and outer
   levels.  */
#define GCOV_TAG_MASK(TAG) (((TAG) - 1) ^ (TAG))

/* Return nonzero if SUB is an immediate subtag of TAG.  */
#define GCOV_TAG_IS_SUBTAG(TAG,SUB)				\
	(GCOV_TAG_MASK (TAG) >> 8 == GCOV_TAG_MASK (SUB) 	\
	 && !(((SUB) ^ (TAG)) & ~GCOV_TAG_MASK(TAG)))

/* Return nonzero if SUB is at a sublevel to TAG.  */
#define GCOV_TAG_IS_SUBLEVEL(TAG,SUB)				\
     	(GCOV_TAG_MASK (TAG) > GCOV_TAG_MASK (SUB))

/* Basic block flags.  */
#define GCOV_BLOCK_UNEXPECTED	(1 << 0)

/* Arc flags.  */
#define GCOV_ARC_ON_TREE 	(1 << 0)
#define GCOV_ARC_FAKE		(1 << 1)
#define GCOV_ARC_FALLTHROUGH	(1 << 2)

/* Structured records.  */

/* Object & program summary record.  */
struct gcov_summary
{
  unsigned checksum;	  /* checksum of program */
  unsigned runs;	  /* number of program runs */
  unsigned arcs;	  /* number of instrumented arcs */
  gcov_type arc_sum;      /* sum of all arc counters */
  gcov_type arc_max_one;  /* max counter on any one run */
  gcov_type arc_max_sum;  /* maximum arc_sum */
  gcov_type arc_sum_max;  /* sum of max_one */
};

/* Structures embedded in coveraged program.  The structures generated
   by write_profile must match these.  */

/* Information about section of counters for a function.  */
struct counter_section
{
  unsigned tag;		/* Tag of the section.  */
  unsigned n_counters;	/* Number of counters in the section.  */
};

#if IN_LIBGCC2
/* Information about section of counters for an object file.  */
struct counter_section_data
{
  unsigned tag;		/* Tag of the section.  */
  unsigned n_counters;	/* Number of counters in the section.  */
  gcov_type *counters;	/* The data.  */
};

/* Information about a single function.  */
struct function_info
{
  const char *name;	        /* (mangled) name of function */
  unsigned checksum;		/* function checksum */
  unsigned n_counter_sections;	/* Number of types of counters */
  const struct counter_section *counter_sections;
  				/* The section descriptions */
};

/* Information about a single object file.  */
struct gcov_info
{
  unsigned long version;        /* expected version number */
  struct gcov_info *next;	/* link to next, used by libgcc */

  const char *filename;		/* output file name */
  long wkspc;	  	        /* libgcc workspace */

  unsigned n_functions;             /* number of functions */
  const struct function_info *functions; /* table of functions */

  unsigned n_counter_sections;	/* Number of types of counters */
  const struct counter_section_data *counter_sections;
  				/* The data to be put into the sections.  */
};

/* Register a new object file module.  */
extern void __gcov_init (struct gcov_info *);

/* Called before fork, to avoid double counting.  */
extern void __gcov_flush (void);

/* Since this file is used in both host and target files, and we don't
   include ansidecl.h in target files, provide some necessary macros.  */
#ifndef PARAMS
# define PARAMS(X) X
#endif
#ifndef ATTRIBUTE_UNUSED
# define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#endif

#endif /* IN_LIBGCC2 */

/* Functions for reading and writing gcov files.  */
static int gcov_write_unsigned PARAMS((FILE *, unsigned))
     ATTRIBUTE_UNUSED;
static int gcov_write_counter PARAMS((FILE *, gcov_type))
     ATTRIBUTE_UNUSED;
static int gcov_write_string PARAMS((FILE *, const char *, unsigned))
     ATTRIBUTE_UNUSED;
static int gcov_read_unsigned PARAMS((FILE *, unsigned *))
     ATTRIBUTE_UNUSED;
static int gcov_read_counter PARAMS((FILE *, gcov_type *))
     ATTRIBUTE_UNUSED;
#if !IN_LIBGCC2
static int gcov_read_string PARAMS((FILE *, char **, unsigned *))
     ATTRIBUTE_UNUSED;
#endif
static int gcov_read_summary PARAMS ((FILE *, struct gcov_summary *))
     ATTRIBUTE_UNUSED;
#if IN_LIBGCC2
static int gcov_write_summary PARAMS ((FILE *, unsigned,
				       const struct gcov_summary *))
     ATTRIBUTE_UNUSED;
#endif
#define gcov_save_position(STREAM) \
 	ftell (STREAM)
#define gcov_reserve_length(STREAM) \
	(gcov_write_unsigned (STREAM, 0) ? 0 : ftell (STREAM) - 4)
static int gcov_write_length PARAMS((FILE *, long))
     ATTRIBUTE_UNUSED;
#define gcov_resync(STREAM, BASE, LENGTH) \
	fseek (STREAM, BASE + (long)LENGTH, SEEK_SET)
#define gcov_skip(STREAM, LENGTH) \
	fseek (STREAM, LENGTH, SEEK_CUR)
#define gcov_skip_string(STREAM, LENGTH) \
	fseek (STREAM, (LENGTH) + 4 - ((LENGTH) & 3), SEEK_CUR)


/* Write VALUE to coverage file FILE.  Return nonzero if failed due to
   file i/o error, or value error.  */

static int
gcov_write_unsigned (file, value)
     FILE *file;
     unsigned value;
{
  char buffer[4];
  unsigned ix;

  for (ix = sizeof (buffer); ix--; )
    {
      buffer[ix] = value;
      value >>= 8;
    }
  return ((sizeof (value) > sizeof (buffer) && value)
	  || fwrite (buffer, sizeof (buffer), 1, file) != 1);
}

/* Write VALUE to coverage file FILE.  Return nonzero if failed due to
   file i/o error, or value error.  Negative values are not checked
   here -- they are checked in gcov_read_counter.  */

static int
gcov_write_counter (file, value)
     FILE *file;
     gcov_type value;
{
  char buffer[8];
  unsigned ix;

  for (ix = sizeof (buffer); ix--; )
    {
      buffer[ix] = value;
      value >>= 8;
    }
  return ((sizeof (value) > sizeof (buffer) && value != 0 && value != -1)
	  || fwrite (buffer, sizeof (buffer), 1, file) != 1);
}

/* Write VALUE to coverage file FILE.  Return nonzero if failed due to
   file i/o error, or value error.  */

static int
gcov_write_string (file, string, length)
     FILE *file;
     unsigned length;
     const char *string;
{
  unsigned pad = 0;

  if (string)
    return (gcov_write_unsigned (file, length)
	    || fwrite (string, length, 1, file) != 1
	    || fwrite (&pad, 4 - (length & 3), 1, file) != 1);
  else
    return gcov_write_unsigned (file, 0);
}

/* Read *VALUE_P from coverage file FILE.  Return nonzero if failed
   due to file i/o error, or range error.  */

static int
gcov_read_unsigned (file, value_p)
     FILE *file;
     unsigned *value_p;
{
  unsigned value = 0;
  unsigned ix;
  unsigned char buffer[4];

  if (fread (buffer, sizeof (buffer), 1, file) != 1)
    return 1;
  for (ix = sizeof (value); ix < sizeof (buffer); ix++)
    if (buffer[ix])
      return 1;
  for (ix = 0; ix != sizeof (buffer); ix++)
    {
      value <<= 8;
      value |= buffer[ix];
    }
  *value_p = value;
  return 0;
}

/* Read *VALUE_P from coverage file FILE.  Return nonzero if failed
   due to file i/o error, or range error.  */

static int
gcov_read_counter (file, value_p)
     FILE *file;
     gcov_type *value_p;
{
  gcov_type value = 0;
  unsigned ix;
  unsigned char buffer[8];

  if (fread (buffer, sizeof (buffer), 1, file) != 1)
    return 1;
  for (ix = sizeof (value); ix < sizeof (buffer); ix++)
    if (buffer[ix])
      return 1;
  for (ix = 0; ix != sizeof (buffer); ix++)
    {
      value <<= 8;
      value |= buffer[ix];
    }

  *value_p = value;
  return value < 0;
}

#if !IN_LIBGCC2

/* Read string from coverage file FILE.  Length is stored in *LENGTH_P
   (if non-null), a buffer is allocated and returned in *STRING_P.
   Return nonzero if failed due to file i/o error, or range
   error.  Uses xmalloc to allocate the string buffer.  */

static int
gcov_read_string (file, string_p, length_p)
     FILE *file;
     char **string_p;
     unsigned *length_p;
{
  unsigned length;

  if (gcov_read_unsigned (file, &length))
    return 1;

  if (length_p)
    *length_p = length;
  free (*string_p);

  *string_p = NULL;
  if (!length)
    return 0;

  length += 4 - (length & 3);
  *string_p = (char *) xmalloc (length);

  return fread (*string_p, length, 1, file) != 1;

}

#endif /* !IN_LIBGCC2 */

/* Write a record length at PLACE.  The current file position is the
   end of the record, and is restored before returning.  Returns
   nonzero on failure.  */

static int
gcov_write_length (file, place)
     FILE *file;
     long place;
{
  long here = ftell (file);
  int result = (!place || fseek (file, place, SEEK_SET)
		|| gcov_write_unsigned (file, here - place - 4));
  if (fseek (file, here, SEEK_SET))
    result = 1;
  return result;
}

#define GCOV_SUMMARY_LENGTH 44
static int
gcov_read_summary (da_file, summary)
     FILE *da_file;
     struct gcov_summary *summary;
{
  return (gcov_read_unsigned (da_file, &summary->checksum)
	  || gcov_read_unsigned (da_file, &summary->runs)
	  || gcov_read_unsigned (da_file, &summary->arcs)
	  || gcov_read_counter (da_file, &summary->arc_sum)
	  || gcov_read_counter (da_file, &summary->arc_max_one)
	  || gcov_read_counter (da_file, &summary->arc_max_sum)
	  || gcov_read_counter (da_file, &summary->arc_sum_max));
}

#if IN_LIBGCC2
static int
gcov_write_summary (da_file, tag, summary)
     FILE *da_file;
     unsigned tag;
     const struct gcov_summary *summary;
{
  long base;

  return (gcov_write_unsigned (da_file, tag)
	  || !(base = gcov_reserve_length (da_file))
	  || gcov_write_unsigned (da_file, summary->checksum)
	  || gcov_write_unsigned (da_file, summary->runs)
	  || gcov_write_unsigned (da_file, summary->arcs)
	  || gcov_write_counter (da_file, summary->arc_sum)
	  || gcov_write_counter (da_file, summary->arc_max_one)
	  || gcov_write_counter (da_file, summary->arc_max_sum)
	  || gcov_write_counter (da_file, summary->arc_sum_max)
	  || gcov_write_length (da_file, base));
}
#endif

#endif /* GCC_GCOV_IO_H */
