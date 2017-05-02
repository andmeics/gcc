/* -*- C++ -*- modules.  Experimental!
   Copyright (C) 2017 Free Software Foundation, Inc.
   Written by Nathan Sidwell <nathan@acm.org>

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   GCC is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "cp-tree.h"
#include "stringpool.h"
#include "dumpfile.h"
#include "bitmap.h"

/* State of a particular module. */
struct GTY(()) module_state
{
  /* We always import & export ourselves.  */
  bitmap imports;	/* Transitive modules we're importing.  */
  bitmap exports;	/* Subset of that, that we're exporting.  */
  tree name;		/* Name of the module.  */
  vec<tree, va_gc> *name_parts;  /* Split parts of name.  */
  int direct_import;	/* Direct import/rexport of main module.  */
  /* Don't need to record the module's index, yet.  */
  unsigned crc;		/* CRC we saw reading it in. */
  unsigned HOST_WIDE_INT stamp;	/* Timestamp we saw reading it in.  */

 public:
  module_state ();

 public:
  void set_index (unsigned index);
  void set_name (tree name);
  void do_import (unsigned index, bool is_export);

 public:
  void dump (FILE *, bool);
};

/* Vector of module state.  */
static GTY(()) vec<module_state *, va_gc> *modules;

/* We need a module state, even if we're not a module.  We promote
   this to a real module upon meeting the module declaration.  */
static GTY(()) module_state *this_module;

/* Map from identifier to module index. */
static GTY(()) hash_map<lang_identifier *, unsigned> *module_map;

module_state::module_state ()
  : imports (BITMAP_GGC_ALLOC ()), exports (BITMAP_GGC_ALLOC ()),
    name (NULL_TREE), name_parts (NULL), direct_import (0),
    crc (0), stamp (0)
{
}

/* We've been assigned INDEX.  Mark the self-import-export bits.  */

void
module_state::set_index (unsigned index)
{
  bitmap_set_bit (imports, index);
  bitmap_set_bit (exports, index);
}

/* Set NAME and PARTS fields from incoming NAME.  The name must have
   already been checked for well-formedness.  */

void
module_state::set_name (tree name_)
{
  name = name_;
  size_t len = IDENTIFIER_LENGTH (name);
  const char *ptr = IDENTIFIER_POINTER (name);
  const char *dot;

  do
    {
      dot = (const char *)memchr (ptr, '.', len);
      size_t l = dot ? dot - ptr : len;
      vec_safe_reserve (name_parts,
			vec_safe_length (name_parts) + 1,
			!name_parts && !dot);
      name_parts->quick_push (get_identifier_with_length (ptr, l));
      if (dot)
	l++;
      ptr += l;
      len -= l;
    }
  while (dot);
}

/* Return the IDENTIFIER_NODE naming module IX.  */

tree
module_name (unsigned ix)
{
  return (*modules)[ix]->name;
}

/* Return the vector of IDENTIFIER_NODES naming module IX.  */

vec<tree, va_gc> *
module_name_parts (unsigned ix)
{
  return (*modules)[ix]->name_parts;
}

/* We've just directly imported INDEX.  Update our import/export
   bitmaps.  TOP is true, if we're the main module.  IS_EXPORT is true
   if we're reexporting the module.  */

void
module_state::do_import (unsigned index, bool is_export)
{
  module_state *other = (*modules)[index];

  if (this == this_module)
    other->direct_import = 1 + is_export;
  bitmap_ior_into (imports, other->exports);
  if (is_export)
    bitmap_ior_into (exports, other->exports);
}

enum import_kind 
{
  ik_indirect,
  ik_direct,
  ik_interface,
  ik_implementation
};

static unsigned do_module_import (location_t, tree, import_kind,
				  unsigned HOST_WIDE_INT stamp,
				  unsigned crc, FILE * = NULL);

/* Byte serializer base.  */
class cpm_serial
{
protected:
  FILE *stream;
public:
  const char *name;
protected:
  char *buffer;
  size_t pos;
  size_t len;
  size_t alloc;
  int err;
  unsigned bit_val;
  unsigned bit_pos;
  unsigned crc;

public:
  cpm_serial (FILE *, const char *);
  ~cpm_serial ();

public:
  int error ()
  {
    return err;
  }

public:
  /* Set an error.  We store the first errno.  */
  void bad (int e = -1)
  {
    if (!err)
      err = e;
  }

protected:
  /* Finish bit packet.  Compute crc of bits used, rewind the bytes
     not used.  */
  void bit_flush ()
  {
    gcc_assert (bit_pos);
    unsigned bytes = (bit_pos + 7) / 8;
    pos -= 4 - bytes;
    crc_unsigned_n (bit_val, bytes);
    bit_pos = 0;
    bit_val = 0;
  }

protected:
  void crc_unsigned_n (unsigned v, unsigned n)
  {
    crc = crc32_unsigned_n (crc, v, n);
  }
  void crc_buffer (const char *ptr, size_t l);
  template<typename T> void crc_unsigned (T v)
  {
    unsigned bytes = sizeof (T);
    while (bytes > 4)
      {
	bytes -= 4;
	crc_unsigned_n (unsigned (v >> (bytes * 8)), 4);
      }
    crc_unsigned_n (unsigned (v), bytes);
  }
};

cpm_serial::cpm_serial (FILE *s, const char *n)
  :stream (s), name (n), pos (0), len (0),
   /* Force testing of buffer extension. */
   alloc (MODULE_STAMP ? 1 : 32768),
   err (0), bit_val (0), bit_pos (0), crc (0)
{
  buffer = XNEWVEC (char, alloc);
}

cpm_serial::~cpm_serial ()
{
  gcc_assert (pos == len || err);
  XDELETEVEC (buffer);
}

void
cpm_serial::crc_buffer (const char *ptr, size_t l)
{
  unsigned c = crc;
  for (size_t ix = 0; ix != l; ix++)
    c = crc32_byte (c, ptr[ix]);
  crc = c;
}

/* Byte stream writer.  */
class cpm_writer : public cpm_serial
{
public:
  cpm_writer (FILE *s, const char *n)
    : cpm_serial (s, n)
  {
  }
  ~cpm_writer ()
  {
  }

private:
  size_t reserve (size_t);
  void flush ();
  void bytes4 (unsigned);

public:
  int done ()
  {
    flush ();
    return error ();
  }

public:
  void checkpoint ();

public:
  void b (bool);
  void bflush ();

public:
  void c (unsigned char);
  void i (int);
  void u (unsigned);
  void s (size_t s);
  void wi (HOST_WIDE_INT);
  void wu (unsigned HOST_WIDE_INT);
  void str (const char *, size_t);
  void buf (const char *, size_t);
};

/* Byte stream reader.  */
class cpm_reader : public cpm_serial
{
public:
  cpm_reader (FILE *s, const char *n)
    : cpm_serial (s, n)
  {
  }
  ~cpm_reader ()
  {
  }

private:
  size_t fill (size_t);
  unsigned bytes4 ();

public:
  int done (bool atend = true)
  {
    if (atend && fill (1))
      bad ();
    return error ();
  }

public:
  bool checkpoint ();
  unsigned get_crc () const
  {
    return crc;
  }

public:
  bool b ();
  void bflush ();
private:
  void bfill ();

public:
  int c ();
  int i ();
  unsigned u ();
  size_t s ();
  HOST_WIDE_INT wi ();
  unsigned HOST_WIDE_INT wu ();
  const char *str (size_t * = NULL);
  const char *buf (size_t);
};

/* Checkpoint a crc.  */

inline void
cpm_writer::checkpoint ()
{
  bytes4 (crc);
}

bool
cpm_reader::checkpoint ()
{
  unsigned b = bytes4 ();
  bool ret = b == crc;
  if (!ret)
    {
      /* Map checksum error onto a reasonably specific errno.  */
#if defined (EPROTO)
      bad (EPROTO);
#elif defined (EBADMSG)
      bad (EBADMSG);
#elif defined (EIO)
      bad (EIO);
#else
      bad ();
#endif
    }
  return ret;
}

/* Finish a set of bools.  */

void
cpm_writer::bflush ()
{
  if (bit_pos)
    {
      bytes4 (bit_val);
      bit_flush ();
    }
}

void
cpm_reader::bflush ()
{
  if (bit_pos)
    bit_flush ();
}

/* When reading, we don't know how many bools we'll read in.  So read
   4 bytes-worth, and then rewind when flushing if we didn't need them
   all.  */

void
cpm_reader::bfill ()
{
  bit_val = bytes4 ();
}

/* Low level cpm_readers and cpm_writers.  I did think about making these
   templatized, but that started to look error prone, so went with
   type-specific names.
   b - bools,
   i, u - ints/unsigned
   wi/wu - wide ints/unsigned
   s - size_t
   buf - fixed size buffer
   str - variable length string  */

/* Bools are packed into bytes.  You cannot mix bools and non-bools.
   You must call bflush before emitting another type.  So batch your
   bools.  */

void
cpm_writer::b (bool x)
{
  bit_val |= unsigned (x) << bit_pos++;
  if (bit_pos == 32)
    bflush ();
}

bool
cpm_reader::b ()
{
  if (!bit_pos)
    bfill ();
  bool v = (bit_val >> bit_pos++) & 1;
  if (bit_pos == 32)
    bflush ();
  return v;
}

/* Exactly 4 bytes.  Used internally for bool packing and crc
   transfer -- hence no crc here.  */

void
cpm_writer::bytes4 (unsigned val)
{
  reserve (4);
  buffer[pos++] = val;
  buffer[pos++] = val >> 8;
  buffer[pos++] = val >> 16;
  buffer[pos++] = val >> 24;
}

unsigned
cpm_reader::bytes4 ()
{
  unsigned val = 0;
  if (fill (4) != 4)
    bad ();
  else
    {
      val |= (unsigned char)buffer[pos++];
      val |= (unsigned char)buffer[pos++] << 8;
      val |= (unsigned char)buffer[pos++] << 16;
      val |= (unsigned char)buffer[pos++] << 24;
    }

  return val;
}

/* Chars are unsigned and written as single bytes. */

void
cpm_writer::c (unsigned char v)
{
  reserve (1);
  buffer[pos++] = v;
  crc_unsigned (v);
}

int
cpm_reader::c ()
{
  int v = 0;
  if (fill (1))
    v = (unsigned char)buffer[pos++];
  else
    bad ();
  crc_unsigned (v);
  return v;
}

/* Ints are written as sleb128.  I suppose we could pack the first
   few bits into any partially-filled bool buffer.  */

void
cpm_writer::i (int v)
{
  crc_unsigned (v);
  reserve ((sizeof (v) * 8 + 6) / 7);

  int end = v < 0 ? -1 : 0;
  bool more;

  do
    {
      unsigned byte = v & 127;
      v >>= 6; /* Signed shift.  */
      more = v != end;
      buffer[pos++] = byte | (more << 7);
      v >>= 1; /* Signed shift.  */
    }
  while (more);
}

int
cpm_reader::i ()
{
  int v = 0;
  unsigned bit = 0;
  size_t bytes = fill ((sizeof (v) * 8 + 6) / 7);
  unsigned byte;

  do
    {
      if (!bytes--)
	{
	  bad ();
	  return v;
	}
      byte = buffer[pos++];
      v |= (byte & 127) << bit;
      bit += 7;
    }
  while (byte & 128);

  if (byte & 0x40 && bit < sizeof (v) * 8)
    v |= ~(unsigned)0 << bit;
  crc_unsigned (v);
  return v;
}

/* Unsigned are written as uleb128.  */

void
cpm_writer::u (unsigned v)
{
  crc_unsigned (v);
  reserve ((sizeof (v) * 8 + 6) / 7);

  bool more;
  do
    {
      unsigned byte = v & 127;
      v >>= 7;
      more = v != 0;
      buffer[pos++] = byte | (more << 7);
    }
  while (more);
}

unsigned
cpm_reader::u ()
{
  unsigned v = 0;
  unsigned bit = 0;
  size_t bytes = fill ((sizeof (v) * 8 + 6) / 7);
  unsigned byte;

  do
    {
      if (!bytes--)
	{
	  bad ();
	  return v;
	}
      byte = buffer[pos++];
      v |= (byte & 127) << bit;
      bit += 7;
    }
  while (byte & 128);
  crc_unsigned (v);

  return v;
}

void
cpm_writer::wi (HOST_WIDE_INT v)
{
  crc_unsigned (v);
  reserve ((sizeof (v) * 8 + 6) / 7);

  int end = v < 0 ? -1 : 0;
  bool more;

  do
    {
      unsigned byte = v & 127;
      v >>= 6; /* Signed shift.  */
      more = v != end;
      buffer[pos++] = byte | (more << 7);
      v >>= 1; /* Signed shift.  */
    }
  while (more);
}

HOST_WIDE_INT
cpm_reader::wi ()
{
  HOST_WIDE_INT v = 0;
  unsigned bit = 0;
  size_t bytes = fill ((sizeof (v) * 8 + 6) / 7);
  unsigned byte;

  do
    {
      if (!bytes--)
	{
	  bad ();
	  return v;
	}
      byte = buffer[pos++];
      v |= (byte & 127) << bit;
      bit += 7;
    }
  while (byte & 128);

  if (byte & 0x40 && bit < sizeof (v) * 8)
    v |= ~(unsigned HOST_WIDE_INT)0 << bit;
  crc_unsigned (v);
  return v;
}

inline void
cpm_writer::wu (unsigned HOST_WIDE_INT v)
{
  wi ((HOST_WIDE_INT) v);
}

inline unsigned HOST_WIDE_INT
cpm_reader::wu ()
{
  return (unsigned HOST_WIDE_INT) wi ();
}

inline void
cpm_writer::s (size_t s)
{
  if (sizeof (s) == sizeof (unsigned))
    u (s);
  else
    wu (s);
}

inline size_t
cpm_reader::s ()
{
  if (sizeof (size_t) == sizeof (unsigned))
    return u ();
  else
    return wu ();
}

void
cpm_writer::buf (const char *buf, size_t len)
{
  crc_buffer (buf, len);
  reserve (len);
  memcpy (buffer + pos, buf, len);
  pos += len;
}

const char *
cpm_reader::buf (size_t len)
{
  size_t have = fill (len);
  char *buf = &buffer[pos];
  if (have < len)
    {
      memset (buf + have, 0, len - have);
      bad ();
    }
  pos += have;
  crc_buffer (buf, len);
  return buf;
}

/* Strings:
   u:length
   checkpoint
   buf:bytes
*/

void
cpm_writer::str (const char *string, size_t len)
{
  s (len);
  checkpoint ();
  buf (string, len + 1);
}

const char *
cpm_reader::str (size_t *len_p)
{
  size_t len = s ();

  /* We're about to trust some user data.  */
  if (!checkpoint ())
    len = 0;
  *len_p = len;
  const char *str = buf (len + 1);
  if (str[len])
    {
      /* Force read string to be not totally broken.  */
      buffer[pos-1] = 0;
      bad ();
    }
  return str;
}

void
cpm_writer::flush ()
{
  size_t bytes = fwrite (buffer, 1, pos, stream);

  if (bytes != pos && !err)
    err = errno;
  pos = 0;
}

size_t
cpm_writer::reserve (size_t want)
{
  size_t have = alloc - pos;
  if (have < want)
    {
      flush ();
      if (alloc < want)
	{
	  alloc = want + (want / 8); /* Some hysteresis.  */
	  buffer = XRESIZEVEC (char, buffer, alloc);
	}
      have = alloc;
    }
  return have;
}

size_t
cpm_reader::fill (size_t want)
{
  size_t have = len - pos;
  if (have < want)
    {
      memmove (buffer, buffer + pos, len - pos);
      len -= pos;
      pos = 0;
      if (alloc < want)
	{
	  alloc = want + (want / 8); /* Some hysteresis.  */
	  buffer = XRESIZEVEC (char, buffer, alloc);
	}
      size_t bytes = fread (buffer + len, 1, alloc - len, stream);
      len += bytes;
      have = len;
    }
  return have < want ? have : want;
}

/* Module cpm_stream base.  */
class cpm_stream
{
public:
  /* Record tags.  */
  enum record_tag
  {
    /* Module-specific records.  */
    rt_eof,  /* End Of File.  duh! */
    rt_conf, /* Config info (baked in stuff like target-triplet) */
    rt_stamp, /* Date stamp etc.  */
    rt_flags, /* Flags that affect AST generation, such as fshort-enum.  */
    rt_import, /* An import. */
    rt_binding, /* A name-binding.  */
    rt_trees, /* Global trees.  */
    rt_tree_base = 0x100,      /* Tree codes.  */
    rt_ref_base = 0x1000    /* Back-reference indices.  */
  };
  struct gtp 
  {
    const tree *ptr;
    unsigned num;
  };

public:
  static const gtp global_tree_arys[];

private:
  unsigned index;

public:
  cpm_stream () : index (rt_ref_base)
  {
    gcc_assert (MAX_TREE_CODES <= rt_ref_base - rt_tree_base);
  }

protected:
  /* Allocate a new reference index.  */
  unsigned next ()
  {
    return index++;
  }

public:
  static const char *ident ();
  static int version ();

  /* Version to date. */
  static unsigned v2d (int v)
  {
    if (MODULE_STAMP && v < 0)
      return -v / 10000 + 20000000;
    else
      return v;
  }

  /* Version to time. */
  static unsigned v2t (int v)
  {
    if (MODULE_STAMP && v < 0)
      return -v % 10000;
    else
      return 0;
  }
};

const char *
cpm_stream::ident ()
{
  return "g++m";
}

int
cpm_stream::version ()
{
  /* If the on-disk format changes, update the version number.  */
  int version = 20170210;

#if defined (MODULE_STAMP)
  /* MODULE_STAMP is a decimal encoding YYMMDDhhmm in local timezone.
     Using __TIME__ doesnt work very well with boostrapping!  */
  version = -MODULE_STAMP;
#endif
  return version;
}

/* cpm_stream cpms_out.  */
class cpms_out : public cpm_stream
{
  cpm_writer w;
  hash_map<tree,unsigned> map; /* trees to ids  */
  
public:
  cpms_out (FILE *, const char *);
  ~cpms_out ();

public:
  void header (FILE *, tree);
  void tag_eof ();
  void tag_conf (FILE *);
  void tag_import (FILE *, unsigned ix, const module_state *);
  void tag_trees (FILE *);
  void tag_binding (FILE *, tree ns, tree name, tree ovl);
  int done ()
  {
    return w.done ();
  }

private:
  void start (tree_code, tree);
  void write_loc (location_t);
  void write_tree_ary (FILE *, unsigned, const gtp *);
  void write_core_bools (FILE *, tree);
  void write_core_vals (FILE *, tree);
  void write_decl_lang_bools (FILE *, tree);

public:
  void write_tree (FILE *, tree);
  void write_bindings (FILE *d, tree ns);
};

cpms_out::cpms_out (FILE *s, const char *n)
  :w (s, n)
{
}

cpms_out::~cpms_out ()
{
}

/* Cpm_Stream in.  */
class cpms_in : public cpm_stream
{
  cpm_reader r;

  /* Module state being initialized.  */
  module_state *state;

  // FIXME: specialize default_hash_traits
  typedef unbounded_int_hashmap_traits<unsigned,tree> traits;
  hash_map<unsigned,tree,traits> map; /* ids to trees  */

  tree scope;
  unsigned index; /* Module index.  */
  unsigned HOST_WIDE_INT stamp;  /* Expected time stamp.  */

public:
  cpms_in (FILE *, const char *, module_state *, unsigned HOST_WIDE_INT stamp);
  ~cpms_in ();

public:
  bool header (FILE *);
  int tag_eof (FILE *);
  bool tag_conf (FILE *);
  bool tag_import (FILE *);
  bool tag_binding (FILE *);
  bool tag_trees (FILE *);
  int read_item (FILE *);
  int done ()
  {
    return r.done ();
  }
  unsigned get_index () const
  {
    return index;
  }

private:
  tree finish_namespace (FILE *, tree);
  tree finish_function (FILE *, tree);
  tree finish_type (FILE *, tree);

private:
  tree start (tree_code);
  tree finish (FILE *, tree);
  location_t read_loc ();
  bool read_tree_ary (FILE *, unsigned, const gtp *);
  bool read_core_bools (FILE *, tree);
  bool read_core_vals (FILE *, tree);
  bool read_decl_lang_bools (FILE *, tree);

private:
  void set_scope (tree);

public:
  bool read_tree (FILE *, tree *, unsigned = 0);
};

cpms_in::cpms_in (FILE *s, const char *n,
		  module_state *state_, unsigned HOST_WIDE_INT stmp)
  :r (s, n), state (state_), scope (NULL_TREE), index (GLOBAL_MODULE_INDEX),
   stamp (stmp)
{
}

cpms_in::~cpms_in ()
{
  if (scope)
    pop_inner_scope (global_namespace, scope);
}

/* File header
   buf:ident
   u:version
   wu:timestamp
   str:module
*/

void
cpms_out::header (FILE *d, tree name)
{
  char const *id = ident ();
  w.buf (id, strlen (id));

  int v = version ();
  gcc_assert (v < 0); /* Not ready for prime-time.  */
  w.i (v);

  /* Although -1 is a legitimate time, it's not going to be a very
     common problem.  */
  time_t now = time (NULL);
  if ((time_t)-1 == now)
    now = 0;
  w.wu ((unsigned HOST_WIDE_INT)now);

  if (d)
    fprintf (d, "Writing \"%s\" version=%d:%04d stamp=%lu\n",
	     id, v2d (v), v2t (v), (unsigned long)now);

  w.str (IDENTIFIER_POINTER (name), IDENTIFIER_LENGTH (name));
}

static const char *
time2str (unsigned HOST_WIDE_INT t)
{
  const char *str = "<unknown>";
  if (t)
    {
      time_t e_time = (time_t)t;
      struct tm *l_time = localtime (&e_time);
      char buf[24];
      sprintf (buf, "%04d/%02d/%02d %02d:%02d:%02d",
	       l_time->tm_year + 1900, l_time->tm_mon + 1, l_time->tm_mday,
	       l_time->tm_hour, l_time->tm_min, l_time->tm_sec);
      str = xstrdup (buf);
    }
  return str;
}

/* Diagnose mismatched timestamps.  */

static void
timestamp_mismatch (tree name, unsigned HOST_WIDE_INT expected,
		    unsigned HOST_WIDE_INT actual)
{
  const char *e_str = time2str (expected);
  const char *a_str = time2str (actual);
  
  error ("module %qE time stamp expected %qs, discovered %qs",
	 name, e_str, a_str);

  /* We leak memory, but we're dying.  */
}

bool
cpms_in::header (FILE *d)
{
  const char *id = ident ();
  const char *i = r.buf (strlen (id));
  if (memcmp (id, i, strlen (id)))
    {
      error ("%qs is not a module file", r.name);
      return false;
    }

  /* Check version.  */
  int ver = version ();
  int v = r.i ();
  int ver_date = v2d (ver);
  int ver_time = v2t (ver);
  int v_date = v2d (v);
  int v_time = v2t (v);
  if (v != ver)
    {
      bool have_a_go = false;
      if (ver_date != v_date)
	/* Dates differ, decline.  */
	error ("%qs is version %d, require version %d",
	       r.name, v_date, ver_date);
      else
	{
	  /* Times differ, give it a go.  */
	  warning (0, "%qs is version %d, but build time is %d, not %d",
		   r.name, v_date, v_time, ver_time);
	  have_a_go = true;
	}
      if (!have_a_go)
	{
	  r.bad (-1);
	  return false;
	}
    }
  if (d)
    fprintf (d, "Expecting %d:%04d found %d:%04d\n", ver_date, ver_time,
	     v_date, v_time);

  /* Check timestamp.  */
  state->stamp = r.wu ();
  if (stamp && stamp != state->stamp)
    {
      timestamp_mismatch (state->name, stamp, state->stamp);
      return false;
    }

  /* Check module name.  */
  size_t l;
  const char *n = r.str (&l);
  if (l != IDENTIFIER_LENGTH (state->name)
      || memcmp (n, IDENTIFIER_POINTER (state->name), l))
    {
      error ("%qs is module %qs, expected module %qE", r.name, n, state->name);
      return false;
    }

  return true;
}

void
cpms_out::tag_eof ()
{
  w.u (rt_eof);
  w.checkpoint ();
}

int
cpms_in::tag_eof (FILE *d)
{
  if (d)
    fprintf (d, "Read eof\n");
  if (!r.checkpoint ())
    return false;
  /* Record the crc.  */
  state->crc = r.get_crc ();
  return -1; /* Denote EOF.  */
}

/* Record config info
   str:<target-triplet>
   str:<host-triplet>  ; lock this for now.
*/

void
cpms_out::tag_conf (FILE *d)
{
  if (d)
    fprintf (d, "Writing target='%s', host='%s'\n",
	     TARGET_MACHINE, HOST_MACHINE);
  w.u (rt_conf);
  w.str (TARGET_MACHINE, strlen (TARGET_MACHINE));
  w.str (HOST_MACHINE, strlen (HOST_MACHINE));
  w.checkpoint ();
}

bool
cpms_in::tag_conf (FILE *d)
{
  size_t l;
  const char *targ = r.str (&l);
  if (strcmp (targ, TARGET_MACHINE))
    {
      error ("%qs is target %qs, expected %qs", r.name, targ, TARGET_MACHINE);
      return false;
    }
  const char *host = r.str (&l);
  if (strcmp (host, HOST_MACHINE))
    {
      error ("%qs is host %qs, expected %qs", r.name, host, HOST_MACHINE);
      return false;
    }

  if (!r.checkpoint ())
    return false;

  if (d)
    fprintf (d, "Read target='%s', host='%s'\n", TARGET_MACHINE, HOST_MACHINE);

  return true;
}

/* Dump the global trees directly to save encoding them for no reason.
   Further types such as sizetype and global_namespace are oddly
   recursive, and this avoids having to deal with that in the
   cpm_reader.

   u:count
   <ary>*
*/

const cpm_stream::gtp cpm_stream::global_tree_arys[] =
  {
    {global_trees, TI_MAX},
    {cp_global_trees, CPTI_MAX},
    {&global_namespace, 1},
    {NULL, 0}
  };

void
cpms_out::tag_trees (FILE *d)
{
  w.u (rt_trees);
  unsigned ix;
  for (ix = 0; global_tree_arys[ix].ptr; ix++)
    continue;
  w.u (ix);
  for (ix = 0; global_tree_arys[ix].ptr; ix++)
    write_tree_ary (d, ix, &global_tree_arys[ix]);
  w.checkpoint ();
}

bool
cpms_in::tag_trees (FILE *d)
{
  unsigned n = r.u ();
  unsigned ix;

  for (ix = 0; ix != n && global_tree_arys[ix].ptr; ix++)
    if (!read_tree_ary (d, ix, &global_tree_arys[ix]))
      return false;

  if (ix != n || global_tree_arys[ix].ptr)
    {
      error ("%qs has %u arrays, expected %u", r.name, n, ix);
      return false;
    }
  return r.checkpoint ();
}

/* Global tree array
   u:count
   b[]:insert_p  */

void
cpms_out::write_tree_ary (FILE *d, unsigned ary_num, const gtp *ary_p)
{
  const tree *ary = ary_p->ptr;
  unsigned num = ary_p->num;

  w.u (num);

  unsigned n = 0;
  for (unsigned ix = 0; ix != num; ix++)
    {
      bool insert = false;
  
      if (ary[ix])
	{
	  bool existed;
	  unsigned *val = &map.get_or_insert (ary[ix], &existed);
	  if (!existed)
	    {
	      n++;
	      *val = next ();
	      insert = true;
	    }
	  if (d)
	    fprintf (d, "Fixed %u:%u index %u is %p (%s)%s\n",
		     ary_num, ix, *val, (void *)ary[ix],
		     get_tree_code_name (TREE_CODE (ary[ix])),
		     insert ? " inserted" : "");
	}
      w.b (insert);
    }
  w.bflush ();
  if (d)
    fprintf (d, "Writing %u fixed trees (%d unique)\n", num, n);
}

bool
cpms_in::read_tree_ary (FILE *d, unsigned ary_num, const gtp *ary_p)
{
  const tree *ary = ary_p->ptr;
  unsigned num = ary_p->num;

  unsigned n = r.u ();
  if (n != num)
    {
      error ("%qs array %u %u trees, expected %u", r.name, ary_num, n, num);
      return false;
    }

  n = 0;
  for (unsigned ix = 0; ix != num; ix++)
    if (r.b ())
      {
	tree t = ary[ix];
	unsigned tag = next ();

	gcc_assert (t);
	n++;
	map.put (tag, t);
	if (d)
	  fprintf (d, "Fixed %u:%u index %u is %p (%s)\n",
		   ary_num, ix, tag, (void *)t,
		   get_tree_code_name (TREE_CODE (t)));
      }
  r.bflush ();

  if (d)
    fprintf (d, "Reading %u fixed trees (%d unique)\n", num, n);
  return true;
}

/* Item import
   u:index
   u:direct
   u:crc
   wu:stamp
   str:module_name  */

void
cpms_out::tag_import (FILE *d, unsigned ix, const module_state *state)
{
  if (d)
    fprintf (d, "Writing import '%s' (%d, %x)\n",
	     IDENTIFIER_POINTER (state->name),
	     state->direct_import, state->crc);
  w.u (rt_import);
  w.u (ix);
  w.u (state->direct_import);
  w.u (state->crc);
  w.wu (state->stamp);
  w.str (IDENTIFIER_POINTER (state->name), IDENTIFIER_LENGTH (state->name));
  w.checkpoint ();
}

bool
cpms_in::tag_import (FILE *d)
{
  unsigned ix = r.u ();
  unsigned direct = r.u ();
  unsigned crc = r.u ();
  unsigned HOST_WIDE_INT stamp = r.wu ();
  size_t l;
  const char *mod = r.str (&l);

  /* Validate name.  Dotted sequence of identifiers.  */
  size_t dot = 0;
  for (size_t ix = 0; ix != l; ix++)
    if (ISALPHA (mod[ix]) || mod[ix] == '_')
      continue;
    else if (dot == ix)
      goto bad;
    else if (mod[ix] == '.')
      dot = ix + 1;
    else if (!ISDIGIT (mod[ix]))
      goto bad;
  if (!l || dot == l)
    {
      bad:
      error ("module name %qs is malformed", mod);
      return false;
    }

  /* Not designed to import after having assigned our number. */
  if (index)
    {
      error ("misordered import %qs", mod);
      return false;
    }

  tree imp = get_identifier_with_length (mod, l);

  if (!r.checkpoint ())
    return false;

  if (d)
    fprintf (d, "Begin nested import '%s'\n", IDENTIFIER_POINTER (imp));
  int index = do_module_import (UNKNOWN_LOCATION, imp,
				direct ? ik_direct : ik_indirect,
				stamp, crc, d);
  if (index != GLOBAL_MODULE_INDEX && direct)
    state->do_import (index, direct == 2);

  if (d)
    fprintf (d, "Completed nested import '%s' #%u %s\n",
	     IDENTIFIER_POINTER (imp), index,
	     index != GLOBAL_MODULE_INDEX ? "ok" : "failed");
  return index != GLOBAL_MODULE_INDEX;
}

/* NAME is bound to OVL in namespace NS.  Write out the binding.
   NS must have already have a binding somewhere.

   tree:ns 
   tree:name
   tree:ovl
*/

void
cpms_out::tag_binding (FILE *d, tree ns, tree name, tree ovl)
{
  if (d)
    fprintf (d, "Writing bindings for %s\n", IDENTIFIER_POINTER (name));

  w.u (rt_binding);
  write_tree (d, ns);
  write_tree (d, name);
  write_tree (d, ovl);
}

bool
cpms_in::tag_binding (FILE *d)
{
  tree name, ns, ovl;
  if (!read_tree (d, &ns)
      || !read_tree (d, &name)
      || !read_tree (d, &ovl))
    return false;

  if (d)
    fprintf (d, "Reading binding for %s in %s\n",
	     IDENTIFIER_POINTER (name), IDENTIFIER_POINTER (DECL_NAME (ns)));
  return push_module_binding (ns, GLOBAL_MODULE_INDEX, name, ovl);
}

int
cpms_in::read_item (FILE *d)
{
  unsigned rt = r.u ();

  switch (rt)
    {
    case rt_conf:
      return tag_conf (d);
    case rt_import:
      return tag_import (d);

    default:
      break;
    }
  
  if (index == GLOBAL_MODULE_INDEX)
    {
      if (state == this_module)
	{
	  index = THIS_MODULE_INDEX;
	  (*modules)[index] = state;
	}
      else
	{
	  index = modules->length ();
	  if (index == MODULE_INDEX_LIMIT)
	    {
	      sorry ("too many modules loaded (limit is %u)", index);
	      r.bad (-1);
	      return -1;
	    }
	  vec_safe_push (modules, state);
	  state->set_index (index);
	}
      if (d)
	fprintf (d, "Assigning module index %u\n", index);
    }

  switch (rt)
    {
    case rt_eof:
      return tag_eof (d);
    case rt_binding:
      return tag_binding (d);
    case rt_trees:
      return tag_trees (d);

    default:
      break;
    }

  tree t;
  if (!read_tree (d, &t, rt))
    {
      if (t == error_mark_node)
	error ("unknown key %qd", rt);
      r.bad ();
      return false;
    }
  // FIXME: read body
  return true;
}

/* Read & write locations.  */

void
cpms_out::write_loc (location_t)
{
  // FIXME:Do something
}

location_t
cpms_in::read_loc ()
{
  // FIXME:Do something^-1
  return UNKNOWN_LOCATION;
}

void
cpms_in::set_scope (tree ctx)
{
  if (ctx != scope)
    {
      if (scope)
	pop_inner_scope (global_namespace, scope);
      else
	gcc_assert (current_scope () == global_namespace);
      scope = ctx;
      tree pop = push_inner_scope (ctx);
      gcc_assert (pop == global_namespace);
    }
}

/* Start tree write.  Write information to allocate the receiving
   node.  */

void
cpms_out::start (tree_code code, tree t)
{
  switch (code)
    {
    default:
      break;
    case IDENTIFIER_NODE:
      w.str (IDENTIFIER_POINTER (t), IDENTIFIER_LENGTH (t));
      break;
    case TREE_BINFO:
      w.u (BINFO_N_BASE_BINFOS (t));
      break;
    case TREE_VEC:
      w.u (TREE_VEC_LENGTH (t));
      break;
    case CALL_EXPR:
      w.u (VL_EXP_OPERAND_LENGTH (t));
      break;
    case STRING_CST:
      w.str (TREE_STRING_POINTER (t), TREE_STRING_LENGTH (t));
      break;
    case VECTOR_CST:
      w.u (VECTOR_CST_NELTS (t));
      break;
    case INTEGER_CST:
      w.u (TREE_INT_CST_NUNITS (t));
      w.u (TREE_INT_CST_EXT_NUNITS (t));
      break;
    case OMP_CLAUSE:
      gcc_unreachable (); // FIXME:
    }
}

/* Start tree read.  Allocate the receiving node.  */

tree
cpms_in::start (tree_code code)
{
  tree t = NULL_TREE;
  
  switch (code)
    {
    default:
      t = make_node (code);
      break;
    case IDENTIFIER_NODE:
    case STRING_CST:
      {
	size_t l;
	const char *str = r.str (&l);
	if (code == IDENTIFIER_NODE)
	  t = get_identifier_with_length (str, l);
	else
	  t = build_string (l, str);
      }
      break;
    case TREE_BINFO:
      t = make_tree_binfo (r.u ());
      break;
    case TREE_VEC:
      t = make_tree_vec (r.u ());
      break;
    case CALL_EXPR:
      t = build_vl_exp (CALL_EXPR, r.s ());
      break;
    case VECTOR_CST:
      t = make_vector (r.u ());
      break;
    case INTEGER_CST:
      {
	unsigned n = r.u ();
	unsigned e = r.u ();
	t = make_int_cst (n, e);
      }
      break;
    case OMP_CLAUSE:
      gcc_unreachable (); // FIXME:
    }
  
  return t;
}

/* Semantic processing.  Add to symbol table etc.  Return
   possibly-remapped tree.  */

tree
cpms_in::finish (FILE *d, tree t)
{
  if (TYPE_P (t))
    return finish_type (d, t);

  switch (TREE_CODE (t))
    {
    default: break;

    case NAMESPACE_DECL:
      return finish_namespace (d, t);

    case FUNCTION_DECL:
      return finish_function (d, t);
    }
  
  return t;
}

/* Read & write the core boolean flags.  */

void
cpms_out::write_core_bools (FILE *, tree t)
{
#define WB(X) (w.b (X))
  WB (TREE_ADDRESSABLE (t));
  WB (TREE_THIS_VOLATILE (t));
  WB (TREE_PUBLIC (t));
  WB (TREE_PRIVATE (t));
  WB (TREE_PROTECTED (t));
  WB (TREE_DEPRECATED (t));

  if (TREE_CODE (t) != TREE_VEC)
    {
      WB (TREE_LANG_FLAG_0 (t));
      WB (TREE_LANG_FLAG_1 (t));
      WB (TREE_LANG_FLAG_2 (t));
      WB (TREE_LANG_FLAG_3 (t));
      WB (TREE_LANG_FLAG_4 (t));
      WB (TREE_LANG_FLAG_5 (t));
      WB (TREE_LANG_FLAG_6 (t));
    }
  
  if (TYPE_P (t))
    {
      WB (TYPE_UNSIGNED (t));
      WB (TYPE_ARTIFICIAL (t));
      WB (TYPE_LANG_FLAG_0 (t));
      WB (TYPE_LANG_FLAG_1 (t));
      WB (TYPE_LANG_FLAG_2 (t));
      WB (TYPE_LANG_FLAG_3 (t));
      WB (TYPE_LANG_FLAG_4 (t));
      WB (TYPE_LANG_FLAG_5 (t));
      WB (TYPE_LANG_FLAG_6 (t));
      WB (TYPE_LANG_FLAG_7 (t));
    }
  else
    {
      WB (TREE_SIDE_EFFECTS (t));
      WB (TREE_CONSTANT (t));
      WB (TREE_READONLY (t));
      WB (TREE_NO_WARNING (t));
    }
  
  if (DECL_P (t))
    {
      WB (DECL_UNSIGNED (t));
      WB (DECL_NAMELESS (t));
    }

  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_TYPE_COMMON))
    {
      WB (TYPE_STRING_FLAG (t));
      WB (TYPE_NEEDS_CONSTRUCTING (t));
      WB (TYPE_PACKED (t));
      WB (TYPE_RESTRICT (t));
      WB (TYPE_USER_ALIGN (t));
      WB (TYPE_READONLY (t));
    }

  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_COMMON))
    {
      WB (DECL_NONLOCAL (t));
      WB (DECL_VIRTUAL_P (t));
      WB (DECL_IGNORED_P (t));
      WB (DECL_ABSTRACT_P (t));
      WB (DECL_ARTIFICIAL (t));
      WB (DECL_USER_ALIGN (t));
      WB (DECL_PRESERVE_P (t));
      WB (DECL_EXTERNAL (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_WITH_VIS))
    {
      WB (DECL_COMMON (t));
      WB (DECL_DLLIMPORT_P (t));
      WB (DECL_WEAK (t));
      WB (DECL_SEEN_IN_BIND_EXPR_P (t));
      WB (DECL_COMDAT (t));
      WB (DECL_VISIBILITY_SPECIFIED (t));

      switch (TREE_CODE (t))
	{
	default:
	  break;
	case VAR_DECL:
	  WB (DECL_HARD_REGISTER (t));
	  WB (DECL_IN_CONSTANT_POOL (t));
	  break;
	case FUNCTION_DECL:
	  WB (DECL_FINAL_P (t));
	  WB (DECL_CXX_CONSTRUCTOR_P (t));
	  WB (DECL_CXX_DESTRUCTOR_P (t));
	  break;
	}
    }
  // FIXME: Add more
#undef WB
}

bool
cpms_in::read_core_bools (FILE *, tree t)
{
#define RB(X) ((X) = r.b ())
  RB (TREE_ADDRESSABLE (t));
  RB (TREE_THIS_VOLATILE (t));
  RB (TREE_PUBLIC (t));
  RB (TREE_PRIVATE (t));
  RB (TREE_PROTECTED (t));
  RB (TREE_DEPRECATED (t));

  if (TREE_CODE (t) != TREE_VEC)
    {
      RB (TREE_LANG_FLAG_0 (t));
      RB (TREE_LANG_FLAG_1 (t));
      RB (TREE_LANG_FLAG_2 (t));
      RB (TREE_LANG_FLAG_3 (t));
      RB (TREE_LANG_FLAG_4 (t));
      RB (TREE_LANG_FLAG_5 (t));
      RB (TREE_LANG_FLAG_6 (t));
    }
  
  if (TYPE_P (t))
    {
      RB (TYPE_UNSIGNED (t));
      RB (TYPE_ARTIFICIAL (t));
      RB (TYPE_LANG_FLAG_0 (t));
      RB (TYPE_LANG_FLAG_1 (t));
      RB (TYPE_LANG_FLAG_2 (t));
      RB (TYPE_LANG_FLAG_3 (t));
      RB (TYPE_LANG_FLAG_4 (t));
      RB (TYPE_LANG_FLAG_5 (t));
      RB (TYPE_LANG_FLAG_6 (t));
      RB (TYPE_LANG_FLAG_7 (t));
    }
  else
    {
      RB (TREE_SIDE_EFFECTS (t));
      RB (TREE_CONSTANT (t));
      RB (TREE_READONLY (t));
      RB (TREE_NO_WARNING (t));
    }
  
  if (DECL_P (t))
    {
      RB (DECL_UNSIGNED (t));
      RB (DECL_NAMELESS (t));
    }

  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_TYPE_COMMON))
    {
      RB (TYPE_STRING_FLAG (t));
      RB (TYPE_NEEDS_CONSTRUCTING (t));
      RB (TYPE_PACKED (t));
      RB (TYPE_RESTRICT (t));
      RB (TYPE_USER_ALIGN (t));
      RB (TYPE_READONLY (t));
    }

  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_COMMON))
    {
      RB (DECL_NONLOCAL (t));
      RB (DECL_VIRTUAL_P (t));
      RB (DECL_IGNORED_P (t));
      RB (DECL_ABSTRACT_P (t));
      RB (DECL_ARTIFICIAL (t));
      RB (DECL_USER_ALIGN (t));
      RB (DECL_PRESERVE_P (t));
      RB (DECL_EXTERNAL (t));
    }

  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_WITH_VIS))
    {
      RB (DECL_COMMON (t));
      RB (DECL_DLLIMPORT_P (t));
      RB (DECL_WEAK (t));
      RB (DECL_SEEN_IN_BIND_EXPR_P (t));
      RB (DECL_COMDAT (t));
      RB (DECL_VISIBILITY_SPECIFIED (t));

      switch (TREE_CODE (t))
	{
	default:
	  break;
	case VAR_DECL:
	  RB (DECL_HARD_REGISTER (t));
	  RB (DECL_IN_CONSTANT_POOL (t));
	  break;
	case FUNCTION_DECL:
	  RB (DECL_FINAL_P (t));
	  RB (DECL_CXX_CONSTRUCTOR_P (t));
	  RB (DECL_CXX_DESTRUCTOR_P (t));
	  break;
	}
    }
      
  // Add more
#undef RB
  return true;
}

void
cpms_out::write_decl_lang_bools (FILE *, tree t)
{
#define WB(X) (w.b (X))
  WB (DECL_LANGUAGE (t) == lang_cplusplus);
#undef WB
}

bool
cpms_in::read_decl_lang_bools (FILE *, tree t)
{
#define RB(X) ((X) = r.b ())
  SET_DECL_LANGUAGE (t, r.b () ? lang_cplusplus : lang_c);
#undef RB
  return true;
}

/* Read & write the core values and pointers.  */

void
cpms_out::write_core_vals (FILE *d, tree t)
{
#define WU(X) (w.u (X))
#define WT(X) (write_tree (d, X))

  WT (TREE_TYPE (t));

  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_LIST))
    {
      WT (TREE_PURPOSE (t));
      WT (TREE_VALUE (t));
      WT (TREE_CHAIN (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_TYPE_COMMON))
    {
      /* By construction we want to make sure we have the canonical
	 and main variants already in the type table, so emit them
	 now.  */
      WT (TYPE_MAIN_VARIANT (t));
      WT (TYPE_CANONICAL (t));

      WU (TYPE_MODE_RAW (t));
      WU (TYPE_PRECISION (t));
      WU (TYPE_ALIGN (t));
      WT (TYPE_SIZE (t));
      WT (TYPE_SIZE_UNIT (t));
      WT (TYPE_ATTRIBUTES (t));
      WT (TYPE_NAME (t));
      WT (CP_TYPE_CONTEXT (t));
      WT (TYPE_STUB_DECL (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_TYPE_NON_COMMON))
    {
      switch (TREE_CODE (t))
	{
	default:
	  break;
	case ENUMERAL_TYPE:
	  WT (TYPE_VALUES (t));
	  break;
	case  ARRAY_TYPE:
	  WT (TYPE_DOMAIN (t));
	  break;
	case FUNCTION_TYPE:
	case METHOD_TYPE:
	  WT (TYPE_ARG_TYPES (t));
	  break;
	}
      if (!POINTER_TYPE_P (t))
	WT (TYPE_MINVAL (t));
      WT (TYPE_MAXVAL (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_MINIMAL))
    {
      WT (DECL_NAME (t));
      WT (CP_DECL_CONTEXT (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_COMMON))
    {
      WU (DECL_MODE (t));
      WU (DECL_ALIGN (t));
      WT (DECL_SIZE (t));
      WT (DECL_SIZE_UNIT (t));
      WT (DECL_ATTRIBUTES (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_NON_COMMON))
    {
      if (TREE_CODE (t) == TYPE_DECL)
	WT (DECL_ORIGINAL_TYPE (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_WITH_VIS))
    {
      WU (DECL_VISIBILITY (t));
      WT (DECL_ASSEMBLER_NAME_SET_P (t)
	  ? DECL_ASSEMBLER_NAME (t) : NULL_TREE);
    }
#undef WT
#undef WU
}

bool
cpms_in::read_core_vals (FILE *d, tree t)
{
#define RU(X) ((X) = r.u ())
#define RM(X) ((X) = machine_mode (r.u ()))
#define RT(X) if (!read_tree (d, &(X))) return false
  RT (TREE_TYPE (t));

   if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_LIST))
    {
      RT (TREE_PURPOSE (t));
      RT (TREE_VALUE (t));
      RT (TREE_CHAIN (t));
    }
 if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_TYPE_COMMON))
    {
      RT (TYPE_MAIN_VARIANT (t));
      RT (TYPE_CANONICAL (t));

      RM (TYPE_MODE_RAW (t));
      RU (TYPE_PRECISION (t));
      SET_TYPE_ALIGN (t, r.u ());
      RT (TYPE_SIZE (t));
      RT (TYPE_SIZE_UNIT (t));
      RT (TYPE_ATTRIBUTES (t));
      RT (TYPE_NAME (t));
      RT (TYPE_CONTEXT (t));
      RT (TYPE_STUB_DECL (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_TYPE_NON_COMMON))
    {
      switch (TREE_CODE (t))
	{
	default:
	  break;
	case ENUMERAL_TYPE:
	  RT (TYPE_VALUES (t));
	  break;
	case  ARRAY_TYPE:
	  RT (TYPE_DOMAIN (t));
	  break;
	case FUNCTION_TYPE:
	case METHOD_TYPE:
	  RT (TYPE_ARG_TYPES (t));
	  break;
	}
      if (!POINTER_TYPE_P (t))
	RT (TYPE_MINVAL (t));
      RT (TYPE_MAXVAL (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_MINIMAL))
    {
      RT (DECL_NAME (t));
      RT (DECL_CONTEXT (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_COMMON))
    {
      RM (DECL_MODE (t));
      SET_DECL_ALIGN (t, r.u ());
      RT (DECL_SIZE (t));
      RT (DECL_SIZE_UNIT (t));
      RT (DECL_ATTRIBUTES (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_NON_COMMON))
    {
      if (TREE_CODE (t) == TYPE_DECL)
	RT (DECL_ORIGINAL_TYPE (t));
    }
  if (CODE_CONTAINS_STRUCT (TREE_CODE (t), TS_DECL_WITH_VIS))
    {
      DECL_VISIBILITY (t) = symbol_visibility (r.u ());
      tree name;
      RT (name);
      if (name)
	SET_DECL_ASSEMBLER_NAME (t, name);
    }
#undef RT
#undef RM
#undef RU
  return true;
}

/* Write either the decl (as a declaration) itself (and create a
   mapping for it), or write the existing mapping or write null.  This
   is essentially the lisp self-referential structure pretty-printer,
   except that we implicitly number every node, so need neither two
   passes, nor explicit labelling.

   We emit in the following order:
     <tag>
     <core bools>
     <lang-specific-p>
     <bflush & checkpoint>
     if lang-specific-p
       <lang-specific bools>
       <bflush & checkpoint>
     <core vals & trees>
     if lang-specific-p
       <lang-specific vals & trees>
     <checkpoint>
*/

void
cpms_out::write_tree (FILE *d, tree t)
{
  if (!t)
    {
      w.u (0); /* This also matches t_eof, but we cannot be confused. */
      return;
    }
  
  bool existed;
  unsigned *val = &map.get_or_insert (t, &existed);
  if (existed)
    {
      w.u (*val);
      return;
    }

  *val = next ();
  tree_code code = TREE_CODE (t);
  if (d)
    {
      tree name = t;
      
      if (TYPE_P (name))
	name = TYPE_NAME (name);
      if (!name)
	;
      else if (DECL_P (name))
	name = DECL_NAME (name);
      else if (TREE_CODE (name) != IDENTIFIER_NODE)
	name = NULL_TREE;
      fprintf (d, "Writing:%u %p (%s:%s)\n", *val, (void *)t,
	       get_tree_code_name (TREE_CODE (t)),
	       name ? IDENTIFIER_POINTER (name) : "");
    }

  gcc_assert (rt_tree_base + code < rt_ref_base);
  w.u (rt_tree_base + code);
  start (code, t);

  if (code != IDENTIFIER_NODE)
    {
      write_core_bools (d, t);

      if (TYPE_P (t) || DECL_P (t))
	{
	  bool specific = (TYPE_P (t) ? TYPE_LANG_SPECIFIC (t) != NULL
			   : DECL_LANG_SPECIFIC (t) != NULL);
	  w.b (specific);
	  if (!specific)
	    ;
	  else if (TYPE_P (t))
	    ; // FIXME: write type lang bools
	  else if (DECL_P (t))
	    write_decl_lang_bools (d, t);
	}
      w.bflush ();
      w.checkpoint ();

      write_core_vals (d, t);
      // FIXME:Write lang_specific pointers & vals
    }

  w.checkpoint ();
}

/* Read in a tree using TAG.  TAG is either a back reference, or a
   TREE_CODE for a new TREE.  For any tree that is a DECL, this does
   not read in a definition (initial value, class defn, function body,
   instantiations, whatever).  Return true on success.  Sets *TP to
   error_mark_node if TAG is totally bogus.  */

bool
cpms_in::read_tree (FILE *d, tree *tp, unsigned tag)
{
  if (!tag)
    tag = r.u ();

  if (!tag)
    {
      *tp = NULL_TREE;
      return true;
    }

  if (tag >= rt_ref_base)
    {
      tree *val = map.get (tag);

      *tp = val ? *val : error_mark_node;
      if (d)
	fprintf (d, "Reading:%u found %p (%s)\n", tag, (void *)*tp,
		 *tp ? get_tree_code_name (TREE_CODE (*tp)) : "NULL");
      return val != NULL;
    }

  if (tag < rt_tree_base || tag >= rt_tree_base + MAX_TREE_CODES)
    {
      *tp = error_mark_node;
      return false;
    }

  tree_code code = tree_code (tag - rt_tree_base);

  tree t = start (code);

  /* Insert into map.  */
  tag = next ();
  bool existed = map.put (tag, t);
  gcc_assert (!existed);
  if (d)
    fprintf (d, "Reading:%u %s\n", tag, get_tree_code_name (code));

  if (code != IDENTIFIER_NODE)
    {
      if (!read_core_bools (d, t))
	return false;

      bool lied = false;
      if (TYPE_P (t) || DECL_P (t))
	{
	  bool specific = r.b ();
	  if (!specific)
	    ;
	  else if (TYPE_P (t))
	    {
	      if (!maybe_add_lang_type_raw (t))
		lied = true;
	      else
		{
		  // FIXME:read lang_specific bits
		}
	    }
	  else if (DECL_P (t))
	    {
	      if (!maybe_add_lang_decl_raw (t))
		lied = true;
	      else if (!read_decl_lang_bools (d, t))
		return false;
	    }
	}
      r.bflush ();
      if (!r.checkpoint ())
	return false;
      if (lied)
	{
	  r.bad ();
	  return false;
	}
      if (!read_core_vals (d, t))
	return false;

      // FIXME:Read lang_specific ptrs & vals
    }

  if (!r.checkpoint ())
    return false;

  tree found = finish (d, t);
  if (found != t)
    {
      /* Update the mapping.  */
      t = found;
      map.put (tag, t);
    }
  *tp = t ? t : error_mark_node;

  if (d && t)
    {
      tree name = found;
      
      if (TYPE_P (name))
	name = TYPE_NAME (name);
      if (!name)
	;
      else if (DECL_P (name))
	name = DECL_NAME (name);
      else if (TREE_CODE (name) != IDENTIFIER_NODE)
	name = NULL_TREE;
      fprintf (d, "Index %u inserting %p (%s:%s)\n", tag, (void *)found,
	       get_tree_code_name (TREE_CODE (found)),
	       name ? IDENTIFIER_POINTER (name) : "");
    }

  return t != NULL_TREE;
}

/* Walk the bindings of NS, writing out the bindings for the global
   module and the main module.  */

void
cpms_out::write_bindings (FILE *d, tree ns)
{
  bool mod_ns = CURRENT_MODULE_NAMESPACE_P (ns);

  /* Don't walk into other module's namespaces.  */
  if (MODULE_NAMESPACE_P (ns) && !mod_ns)
    {
      if (d)
	fprintf (d, "Skipping namespace '%s'\n",
		 IDENTIFIER_POINTER (DECL_NAME (ns)));
      return;
    }

  if (d)
    fprintf (d, "Walking namespace '%s'\n",
	     IDENTIFIER_POINTER (DECL_NAME (ns)));

  hash_map<lang_identifier *, tree>::iterator end
    (DECL_NAMESPACE_BINDINGS (ns)->end ());
  for (hash_map<lang_identifier *, tree>::iterator iter
	 (DECL_NAMESPACE_BINDINGS (ns)->begin ()); iter != end; ++iter)
    {
      std::pair<tree, tree> binding (*iter);

      tree name = binding.first;
      tree ovl = binding.second;

      tree type; // FIXME stop ignoring me
      tree decl = decapsulate_binding (binding.second, &type);

      if (OVL_P (decl))
	{
	  for (ovl_iterator iter (decl); iter; ++iter)
	    if (!iter.via_using_p ())
	      {
		tree fn = *iter;

		if (mod_ns || DECL_MODULE_EXPORT_P (fn)
		    // FIXME: set MODULE_EXPORT_P properly.  Utter hack here
		    || !DECL_EXTERN_C_P (fn))
		  {
		    gcc_assert (CP_DECL_CONTEXT (fn) == ns);

		    // FIXME:Add templates later
		    gcc_assert (TREE_CODE (fn) == FUNCTION_DECL);

		    // FIXME Hack alert, just one fn
		    tag_binding (d, ns, name, fn);
		    break;
		  }
	      }
	}
      else if (TREE_CODE (decl) == NAMESPACE_DECL)
	write_bindings (d, decl);
      else if (mod_ns || DECL_MODULE_EXPORT_P (decl)
	       // FIXME: set MODULE_EXPORT_P properly.  Utter hack here
	       || !DECL_EXTERN_C_P (decl))
	switch (TREE_CODE (decl))
	  {
	  case VAR_DECL:
	  case TYPE_DECL:
	    break;
	  default:
	    gcc_unreachable (); // FIXME: implement more
	  }
    }
  if (d)
    fprintf (d, "Walked namespace '%s'\n",
	     IDENTIFIER_POINTER (DECL_NAME (ns)));
}

/* Mangling for module files.  */
#define MOD_FNAME_PFX "g++-"
#define MOD_FNAME_SFX ".nms" /* New Module System.  Honest.  */
#define MOD_FNAME_DOT '-'

/* Mangling for module symbol.  */
#define MOD_SYM_PFX "_M"
#if !defined (NO_DOT_IN_LABEL)
#define MOD_SYM_DOT '.'
#elif !defined (NO_DOLLAR_IN_LABEL)
#define MOD_SYM_DOT '$'
#else
#define MOD_SYM_DOT '_'
#endif

static GTY(()) tree module_nm; /* Name for this module namespaces. */
static location_t module_loc;	 /* Location of the module decl.  */
static GTY(()) tree proclaimer;
static int export_depth; /* -1 for singleton export.  */

/* Rebuild a streamed in type.  */
// FIXME: c++-specific types are not in the canonical type hash.
// Perhaps that should be changed?

tree
cpms_in::finish_type (FILE *d, tree type)
{
  tree main = TYPE_MAIN_VARIANT (type);
  
  if (main != type)
    {
      /* See if we have this type already on the variant
	 list.  This could only happen if the originally read in main
	 variant was remapped, but we don't have that knowledge.
	 FIXME: Determine if this is a problem, and then maybe fix
	 it?  That would avoid a fruitless search along the variant
	 chain.  */
      for (tree probe = main; probe; probe = TYPE_NEXT_VARIANT (probe))
	if (check_base_type (type, probe)
	    && TYPE_QUALS (type) == TYPE_QUALS (probe)
	    && comp_except_specs (TYPE_RAISES_EXCEPTIONS (type),
				  TYPE_RAISES_EXCEPTIONS (probe), ce_exact)
	    && type_memfn_rqual (type) == type_memfn_rqual (probe))
	  {
	    if (d)
	      fprintf (d, "Type %p already found as %p variant of %p\n",
		       (void *)type, (void *)probe, (void *)main);
	    free_node (type);
	    type = probe;
	    goto found_variant;
	  }

      /* Splice it into the main variant list.  */
      if (d)
	fprintf (d, "Type %p added as variant of %p\n",
		 (void *)type, (void *)main);
      TYPE_NEXT_VARIANT (type) = TYPE_NEXT_VARIANT (main);
      TYPE_NEXT_VARIANT (main) = type;
      /* CANONICAL_TYPE is either already correctly remapped.  Or
         correctly already us.  FIXME:Are we sure abcpms_out this?  */
    found_variant:;
    }
  else if (!TYPE_STRUCTURAL_EQUALITY_P (type))
    {
      gcc_assert (TYPE_ALIGN (type));
      hashval_t hash = type_hash_default (type);
      /* type_hash_canon frees type, if we find it already.  */
      type = type_hash_canon (hash, type);
      // FIXME: This is where it'd be nice to determine if type
      // was already found.  See above.
      if (d)
	fprintf (d, "Adding type %p as canonical %p\n",
		 (void *)main, (void *)type);
    }

  return type;
}

/* Finish a function decl FN.  Insert into the symbol table or do
   duplicate decl processing.  */

tree
cpms_in::finish_function (FILE *d, tree fn)
{
  // FIXME: look in other imports for this decl.  If this is me, then
  // do nothing (we'll insert it below.)
  return fn;
  
  // FIXME: want to look exactly in scope,  no using decls etc.
  tree cur = lookup_qualified_name (DECL_CONTEXT (fn), DECL_NAME (fn),
				    false, false, false);
  if (cur == error_mark_node)
    cur = NULL_TREE;
  else
    {
      return fn;
      gcc_unreachable (); // FIXME: deal with overloads & duplicates
    }

  set_scope (DECL_CONTEXT (fn));
  fn = pushdecl (fn);
  if (fn == error_mark_node)
    return fn; // FIXME:why?
  if (DECL_CONTEXT (fn) == global_namespace)
    DECL_CONTEXT (fn) = DECL_CONTEXT (global_namespace);

  if (d)
    fprintf (d, "Inserting function decl %s (%p)\n",
	     IDENTIFIER_POINTER (DECL_NAME (fn)), (void *)fn);
  return fn;
}

/* NS has just been read in.  Insert or find the namespace.  */

tree
cpms_in::finish_namespace (FILE *d, tree ns)
{
  tree res = NULL_TREE;

  /* We will not have frobbed the namespace yet.  */
  set_scope (DECL_CONTEXT (ns));
  bool inline_p = DECL_NAMESPACE_INLINE_P (ns);
  bool module_p = MODULE_NAMESPACE_P (ns);
  if (module_p && (state != this_module || DECL_NAME (ns) != module_nm))
    DECL_NAMESPACE_INLINE_P (ns) = false;
  res = push_module_namespace (CP_DECL_CONTEXT (ns), GLOBAL_MODULE_INDEX, ns);
  if (!res)
    error ("failed to insert namespace %E", ns);
  else if (res == ns)
    {
      if (d)
	fprintf (d, "Creating%s namespace %s (%p)\n",
		 inline_p ? " inline" : "",
		 IDENTIFIER_POINTER (DECL_NAME (ns)), (void *)res);
    }
  else
    free_node (ns);

  return res;
}

/* If we're in the purview of a module, push its local namespace.  */

void
push_module_namespace (bool do_it)
{
  gcc_assert (TREE_CODE (current_scope ()) == NAMESPACE_DECL
	      && (!do_it || module_nm));
  if (do_it && push_namespace (module_nm, true))
    MODULE_NAMESPACE_P (current_namespace) = true;
}

/* If we're in the current module's local namespace, pop cpms_out of it.  */

bool
pop_module_namespace ()
{
  gcc_assert (TREE_CODE (current_scope ()) == NAMESPACE_DECL);
  bool do_it = CURRENT_MODULE_NAMESPACE_P (current_namespace);
  if (do_it)
    pop_namespace ();
  return do_it;
}

/* Nest a module export level.  Return true if we were already in a
   level.  */

int
push_module_export (bool singleton, tree proclaiming)
{
  int previous = export_depth;

  if (proclaiming)
    {
      proclaimer = proclaimer;
      export_depth = -2;
    }
  else if (singleton)
    export_depth = -1;
  else
    export_depth = +1;
  return previous;
}

/* Unnest a module export level.  */

void
pop_module_export (int previous)
{
  proclaimer = NULL;
  export_depth = previous;
}

int
module_exporting_level ()
{
  return export_depth;
}

/* Set the module EXPORT and INDEX fields on DECL.  */

void
decl_set_module (tree decl)
{
  if (export_depth)
    DECL_MODULE_EXPORT_P (decl) = true;
  if (this_module && this_module->name)
    DECL_MODULE_INDEX (decl) = THIS_MODULE_INDEX;
}

/* Return true iff we're in the purview of a named module.  */

bool
module_purview_p ()
{
  return this_module && this_module->name;
}

/* Return true iff we're the interface TU (this also means we're in a
   module perview.  */

bool
module_interface_p ()
{
  return this_module && this_module->direct_import;
}

/* Convert a module name into a file name.  The name is malloced.

   (for the moment) this replaces '.' with '-' adds a prefix and
   suffix.

   FIXME: Add host-applicable hooks.  */

static char *
module_to_ext (tree id, const char *pfx, const char *sfx, char dot)
{
  char *name = concat (pfx, IDENTIFIER_POINTER (id), sfx, NULL);
  char *ptr = name + strlen (pfx);
  size_t len = IDENTIFIER_LENGTH (id);

  if (dot != '.')
    for (; len--; ptr++)
      if (*ptr == '.')
	*ptr = dot;

  return name;
}

static char *
module_to_filename (tree id)
{
  return module_to_ext (id, MOD_FNAME_PFX, MOD_FNAME_SFX, MOD_FNAME_DOT);
}

/* Read a module NAME file name FNAME on STREAM.  Returns its module
   index, or 0 */

static unsigned
read_module (FILE *stream, const char *fname, module_state *state,
	     unsigned HOST_WIDE_INT stamp, FILE *d)
{
  cpms_in in (stream, fname, state, stamp);
  bool owning_dump = !d;

  if (owning_dump)
    d = dump_begin (TDI_lang, NULL);

  if (d)
    fprintf (d, "Importing '%s'\n", IDENTIFIER_POINTER (state->name));

  int ok = in.header (d);
  if (ok)
    do
      ok = in.read_item (d);
    while (ok > 0);

  if (int e = in.done ())
    {
      error ("failed to read module %qE (%qs): %s", state->name, fname,
	     e >= 0 ? xstrerror (e) : "Bad file data");
      ok = false;
    }

  if (owning_dump && d)
    dump_end (TDI_lang, d);

  if (ok)
    {
      ok = in.get_index ();
      gcc_assert (ok >= THIS_MODULE_INDEX);
    }

  return ok;
}

/* Import the module NAME into the current TU.  This includes the
   main module's interface and as implementation.  */

unsigned
do_module_import (location_t loc, tree name, import_kind kind,
		  unsigned HOST_WIDE_INT stamp, unsigned crc, FILE *d)
{
  if (!module_map)
    {
      module_map = hash_map<lang_identifier *, unsigned>::create_ggc (31);
      vec_safe_reserve (modules, IMPORTED_MODULE_BASE);
      for (unsigned ix = IMPORTED_MODULE_BASE; ix--;)
	modules->quick_push (NULL);
      this_module = new (ggc_alloc <module_state> ()) module_state ();
    }

  bool existed;
  unsigned *val = &module_map->get_or_insert (name, &existed);
  unsigned index = GLOBAL_MODULE_INDEX;
  module_state *state = NULL;

  if (existed)
    switch (*val)
      {
      case ~0U:
	error_at (loc, "circular dependency of module %qE", name);
	return GLOBAL_MODULE_INDEX;
      case GLOBAL_MODULE_INDEX:
	error_at (loc, "already failed to read module %qE", name);
	return GLOBAL_MODULE_INDEX;
      case THIS_MODULE_INDEX:
	error_at (loc, "already declared as module %qE", name);
	return GLOBAL_MODULE_INDEX;
      default:
	if (kind >= ik_interface)
	  {
	    error_at (loc, "module %qE already imported", name);
	    return GLOBAL_MODULE_INDEX;
	  }
	index = *val;
	state = (*modules)[index];
	if (stamp && stamp != state->stamp)
	  {
	    timestamp_mismatch (name, stamp, state->stamp);
	    index = GLOBAL_MODULE_INDEX;
	  }
      }
  else
    {
      if (kind == ik_indirect)
	warning_at (0, loc, "indirect import %qE not present", name);
      *val = ~0U;

      if (kind >= ik_interface)
	{
	  state = this_module;
	  state->set_index (THIS_MODULE_INDEX);
	  (*modules)[THIS_MODULE_INDEX] = state;
	}
      else
	state = new (ggc_alloc<module_state> ()) module_state ();

      state->set_name (name);
      if (kind == ik_interface)
	index = THIS_MODULE_INDEX;
      else
	{
	  // FIXME:Path search along the -I path
	  // FIXME: Think about make dependency generation
	  char *fname = module_to_filename (name);
	  FILE *stream = fopen (fname, "rb");

	  if (!stream)
	    error_at (loc, "cannot find module %qE (%qs): %m", name, fname);
	  else
	    {
	      push_to_top_level ();
	      index = read_module (stream, fname, state, stamp, d);
	      gcc_assert (global_namespace == current_scope ());
	      pop_from_top_level ();
	      fclose (stream);
	      gcc_assert (*val == ~0U);
	    }
	  free (fname);
	}
    }

  if (index != GLOBAL_MODULE_INDEX && stamp && crc != state->crc)
    {
      error ("module %qE crc mismatch", name);
      index = GLOBAL_MODULE_INDEX;
    }

  *val = index;
  return index;
}

/* Import the module NAME into the current TU and maybe re-export it.  */

void
import_export_module (location_t loc, tree name, tree, bool is_export)
{
  unsigned index = do_module_import (loc, name, ik_direct, 0, 0);
  if (index != GLOBAL_MODULE_INDEX)
    this_module->do_import (index, is_export);
}

/* Declare the name of the current module to be NAME. ATTRS is used to
   determine if this is the interface or not.  */

void
declare_module (location_t loc, tree name, tree attrs)
{
  if (this_module && this_module->name)
    {
      error_at (loc, "module %qE already declared", name);
      inform (module_loc, "existing declaration");
      return;
    }

  /* Look for 'interface' attribute.  There's no point caching the
     identifier, because module declaration occurs at most once.  */
  bool inter = lookup_attribute ("interface", attrs) != NULL_TREE;

  if (!inter)
    {
      // FIXME: Command line switches or file suffix check?
    }

  module_loc = loc;
  char *sym = module_to_ext (name, MOD_SYM_PFX, NULL, MOD_SYM_DOT);
  module_nm = get_identifier (sym);
  free (sym);

  unsigned index = do_module_import
    (loc, name, inter ? ik_interface : ik_implementation, 0, 0);
  if (index != GLOBAL_MODULE_INDEX)
    {
      gcc_assert (index == THIS_MODULE_INDEX);

      this_module->direct_import = inter;
      if (inter) // FIXME:we should do in both cases (or neither)
	push_module_namespace (true);
    }
}

static void
write_module (FILE *stream, const char *fname, tree name)
{
  cpms_out out (stream, fname);
  FILE *d = dump_begin (TDI_lang, NULL);

  if (d)
    fprintf (d, "Writing module '%s'\n", IDENTIFIER_POINTER (name));

  out.header (d, name);
  out.tag_conf (d);
  // FIXME:Write 'important' flags etc

  /* Write the direct imports.  Write in reverse order, so that when
     checking an indirect import we should have already read it.  */
  for (unsigned ix = modules->length (); --ix > THIS_MODULE_INDEX;)
    if (module_state *state = (*modules)[ix])
      out.tag_import (d, ix, state);

  out.tag_trees (d);

  /* Write decls.  */
  out.write_bindings (d, global_namespace);

  // FIXME:Write defns.  Probably fine just to do it during the first
  // namespace walk.

  out.tag_eof ();
  if (int e = out.done ())
    error ("failed to write module %qE (%qs): %s", name, fname,
	   e >= 0 ? xstrerror (errno) : "Bad file data");
  if (d)
    dump_end (TDI_lang, d);
}

/* Finalize the module at end of parsing.  */

void
finish_module ()
{
  if (this_module && this_module->direct_import)
    {
      // FIXME:option to specify location? take dirname from output file?
      char *fname = module_to_filename (this_module->name);

      if (!errorcount)
	{
	  FILE *stream = fopen (fname, "wb");

	  if (!stream)
	    error_at (module_loc, "cannot open module interface %qE (%qs): %m",
		      this_module->name, fname);
	  else
	    {
	      write_module (stream, fname, this_module->name);
	      fclose (stream);
	    }
	}
      if (errorcount)
	unlink (fname);
      free (fname);
    }

  /* GC can clean up the detritus.  */
  module_map = NULL;
  this_module = NULL;
}

#include "gt-cp-module.h"
