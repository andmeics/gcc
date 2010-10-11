/* LTO plugin for gold and/or GNU ld.
   Copyright (C) 2009, 2010 Free Software Foundation, Inc.
   Contributed by Rafael Avila de Espindola (espindola@google.com).

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* The plugin has only one external function: onload. Gold passes it an array of
   function that the plugin uses to communicate back to gold.

   With the functions provided by gold, the plugin can be notified when
   gold first analyzes a file and pass a symbol table back to gold. The plugin
   is also notified when all symbols have been read and it is time to generate
   machine code for the necessary symbols.

   More information at http://gcc.gnu.org/wiki/whopr/driver.

   This plugin should be passed the lto-wrapper options and will forward them.
   It also has 2 options of its own:
   -debug: Print the command line used to run lto-wrapper.
   -nop: Instead of running lto-wrapper, pass the original to the plugin. This
   only works if the input files are hybrid.  */

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <libiberty.h>
#include <hashtab.h>
#include "../gcc/lto/common.h"

/* Common definitions for/from the object format dependent code.  */
#include "lto-plugin.h"

static char *arguments_file_name;
static ld_plugin_register_claim_file register_claim_file;
static ld_plugin_register_all_symbols_read register_all_symbols_read;
static ld_plugin_get_symbols get_symbols;
static ld_plugin_register_cleanup register_cleanup;
static ld_plugin_add_input_file add_input_file;
static ld_plugin_add_input_library add_input_library;
static ld_plugin_message message;

/* These are not static because the object format dependent
   claim_file hooks in lto-plugin-{coff,elf}.c need them.  */
ld_plugin_add_symbols add_symbols;

struct plugin_file_info *claimed_files = NULL;
unsigned int num_claimed_files = 0;

static char **output_files = NULL;
static unsigned int num_output_files = 0;

static char **lto_wrapper_argv;
static int lto_wrapper_num_args;

static char **pass_through_items = NULL;
static unsigned int num_pass_through_items;

static bool debug;
static bool nop;
static char *resolution_file = NULL;

void
check (bool gate, enum ld_plugin_level level, const char *text)
{
  if (gate)
    return;

  if (message)
    message (level, text);
  else
    {
      /* If there is no nicer way to inform the user, fallback to stderr. */
      fprintf (stderr, "%s\n", text);
      if (level == LDPL_FATAL)
	abort ();
    }
}

/* Parse an entry of the IL symbol table. The data to be parsed is pointed
   by P and the result is written in ENTRY. The slot number is stored in SLOT.
   Returns the address of the next entry. */

char *
parse_table_entry (char *p, struct ld_plugin_symbol *entry, 
		   struct sym_aux *aux)
{
  unsigned char t;
  enum ld_plugin_symbol_kind translate_kind[] =
    {
      LDPK_DEF,
      LDPK_WEAKDEF,
      LDPK_UNDEF,
      LDPK_WEAKUNDEF,
      LDPK_COMMON
    };

  enum ld_plugin_symbol_visibility translate_visibility[] =
    {
      LDPV_DEFAULT,
      LDPV_PROTECTED,
      LDPV_INTERNAL,
      LDPV_HIDDEN
    };

  entry->name = xstrdup (p);
  while (*p)
    p++;
  p++;

  entry->version = NULL;

  entry->comdat_key = p;
  while (*p)
    p++;
  p++;

  if (strlen (entry->comdat_key) == 0)
    entry->comdat_key = NULL;
  else
    entry->comdat_key = xstrdup (entry->comdat_key);

  t = *p;
  check (t <= 4, LDPL_FATAL, "invalid symbol kind found");
  entry->def = translate_kind[t];
  p++;

  t = *p;
  check (t <= 3, LDPL_FATAL, "invalid symbol visibility found");
  entry->visibility = translate_visibility[t];
  p++;

  entry->size = *(uint64_t *) p;
  p += 8;

  aux->slot = *(uint32_t *) p;
  p += 4;

  entry->resolution = LDPR_UNKNOWN;

  aux->next_conflict = -1;

  return p;
}

/* Translate the IL symbol table located between DATA and END. Append the
   slots and symbols to OUT. */

void
translate (char *data, char *end, struct plugin_symtab *out)
{
  struct sym_aux *aux;
  struct ld_plugin_symbol *syms = NULL;
  int n, len;

  /* This overestimates the output buffer sizes, but at least 
     the algorithm is O(1) now. */

  len = (end - data)/8 + out->nsyms + 1;
  syms = xrealloc (out->syms, len * sizeof (struct ld_plugin_symbol));
  aux = xrealloc (out->aux, len * sizeof (struct sym_aux));
  
  for (n = out->nsyms; data < end; n++) 
    { 
      aux[n].id = out->id; 
      data = parse_table_entry (data, &syms[n], &aux[n]);
    }

  assert(n < len);

  out->nsyms = n;
  out->syms = syms;
  out->aux = aux;
}

/* Free all memory that is no longer needed after writing the symbol
   resolution. */

static void
free_1 (void)
{
  unsigned int i;
  for (i = 0; i < num_claimed_files; i++)
    {
      struct plugin_file_info *info = &claimed_files[i];
      struct plugin_symtab *symtab = &info->symtab;
      unsigned int j;
      for (j = 0; j < symtab->nsyms; j++)
	{
	  struct ld_plugin_symbol *s = &symtab->syms[j];
	  free (s->name);
	  if (s->comdat_key)
	    free (s->comdat_key);
	}
      free (symtab->syms);
      symtab->syms = NULL;
    }
}

/* Free all remaining memory. */

static void
free_2 (void)
{
  unsigned int i;
  for (i = 0; i < num_claimed_files; i++)
    {
      struct plugin_file_info *info = &claimed_files[i];
      struct plugin_symtab *symtab = &info->symtab;
      free (symtab->aux);
      free (info->name);
    }

  for (i = 0; i < num_output_files; i++)
    free (output_files[i]);
  free (output_files);

  free (claimed_files);
  claimed_files = NULL;
  num_claimed_files = 0;

  if (arguments_file_name)
    free (arguments_file_name);
  arguments_file_name = NULL;
}

/* Dump SYMTAB to resolution file F. */

static void
dump_symtab (FILE *f, struct plugin_symtab *symtab)
{
  unsigned j;

  for (j = 0; j < symtab->nsyms; j++)
    {
      uint32_t slot = symtab->aux[j].slot;
      unsigned int resolution = symtab->syms[j].resolution;
      
      assert (resolution != LDPR_UNKNOWN);

      fprintf (f, "%u %x %s %s\n", (unsigned int) slot, symtab->aux[j].id,
	       lto_resolution_str[resolution], 
	       symtab->syms[j].name);
    }
}

/* Finish the conflicts' resolution information after the linker resolved
   the original symbols */

static void
finish_conflict_resolution (struct plugin_symtab *symtab, 
			   struct plugin_symtab *conflicts)
{
  int i, j;

  if (conflicts->nsyms == 0)
    return;

  for (i = 0; i < symtab->nsyms; i++)
    { 
      int resolution = LDPR_UNKNOWN;

      if (symtab->aux[i].next_conflict == -1)
	continue;

      switch (symtab->syms[i].def) 
	{
	case LDPK_DEF:
	case LDPK_COMMON: /* ??? */
	  resolution = LDPR_RESOLVED_IR; 
	  break;
	case LDPK_WEAKDEF:
	  resolution = LDPR_PREEMPTED_IR;
	  break;
	case LDPK_UNDEF:
	case LDPK_WEAKUNDEF:
	  resolution = symtab->syms[i].resolution;
	  break;
	default:
	  assert (0);
	}

      assert (resolution != LDPR_UNKNOWN);

      for (j = symtab->aux[i].next_conflict; 
	   j != -1; 
	   j = conflicts->aux[j].next_conflict)
	conflicts->syms[j].resolution = resolution;
    }
}

/* Free symbol table SYMTAB. */

static void
free_symtab (struct plugin_symtab *symtab)
{
  free (symtab->syms);
  symtab->syms = NULL;
  free (symtab->aux);
  symtab->aux = NULL;
}

/*  Writes the relocations to disk. */

static void
write_resolution (void)
{
  unsigned int i;
  FILE *f;

  check (resolution_file, LDPL_FATAL, "resolution file not specified");
  f = fopen (resolution_file, "w");
  check (f, LDPL_FATAL, "could not open file");

  fprintf (f, "%d\n", num_claimed_files);

  for (i = 0; i < num_claimed_files; i++)
    {
      struct plugin_file_info *info = &claimed_files[i];
      struct plugin_symtab *symtab = &info->symtab;
      struct ld_plugin_symbol *syms = symtab->syms;

      get_symbols (info->handle, symtab->nsyms, syms);

      finish_conflict_resolution (symtab, &info->conflicts);

      fprintf (f, "%s %d\n", info->name, symtab->nsyms + info->conflicts.nsyms);
      dump_symtab (f, symtab);
      if (info->conflicts.nsyms)
	{
	  dump_symtab (f, &info->conflicts);
	  free_symtab (&info->conflicts);
	}
    }
  fclose (f);
}

/* Pass files generated by the lto-wrapper to the linker. FD is lto-wrapper's
   stdout. */

static void
add_output_files (FILE *f)
{
  for (;;)
    {
      const unsigned piece = 32;
      char *buf, *s = xmalloc (piece);
      size_t len;

      buf = s;
cont:
      if (!fgets (buf, piece, f))
	break;
      len = strlen (s);
      if (s[len - 1] != '\n')
	{
	  s = xrealloc (s, len + piece);
	  buf = s + len;
	  goto cont;
	}
      s[len - 1] = '\0';

      num_output_files++;
      output_files
	= xrealloc (output_files, num_output_files * sizeof (char *));
      output_files[num_output_files - 1] = s;
      add_input_file (output_files[num_output_files - 1]);
    }
}

/* Execute the lto-wrapper. ARGV[0] is the binary. The rest of ARGV is the
   argument list. */

static void
exec_lto_wrapper (char *argv[])
{
  int t, i;
  int status;
  char *at_args;
  FILE *args;
  FILE *wrapper_output;
  char *new_argv[3];
  struct pex_obj *pex;
  const char *errmsg;

  /* Write argv to a file to avoid a command line that is too long. */
  arguments_file_name = make_temp_file ("");
  check (arguments_file_name, LDPL_FATAL,
         "Failed to generate a temorary file name");

  args = fopen (arguments_file_name, "w");
  check (args, LDPL_FATAL, "could not open arguments file");

  t = writeargv (&argv[1], args);
  check (t == 0, LDPL_FATAL, "could not write arguments");
  t = fclose (args);
  check (t == 0, LDPL_FATAL, "could not close arguments file");

  at_args = concat ("@", arguments_file_name, NULL);
  check (at_args, LDPL_FATAL, "could not allocate");

  for (i = 1; argv[i]; i++)
    {
      char *a = argv[i];
      if (a[0] == '-' && a[1] == 'v' && a[2] == '\0')
	{
	  for (i = 0; argv[i]; i++)
	    fprintf (stderr, "%s ", argv[i]);
	  fprintf (stderr, "\n");
	  break;
	}
    }

  new_argv[0] = argv[0];
  new_argv[1] = at_args;
  new_argv[2] = NULL;

  if (debug)
    {
      for (i = 0; new_argv[i]; i++)
	fprintf (stderr, "%s ", new_argv[i]);
      fprintf (stderr, "\n");
    }


  pex = pex_init (PEX_USE_PIPES, "lto-wrapper", NULL);
  check (pex != NULL, LDPL_FATAL, "could not pex_init lto-wrapper");

  errmsg = pex_run (pex, 0, new_argv[0], new_argv, NULL, NULL, &t);
  check (errmsg == NULL, LDPL_FATAL, "could not run lto-wrapper");
  check (t == 0, LDPL_FATAL, "could not run lto-wrapper");

  wrapper_output = pex_read_output (pex, 0);
  check (wrapper_output, LDPL_FATAL, "could not read lto-wrapper output");

  add_output_files (wrapper_output);

  t = pex_get_status (pex, 1, &status);
  check (t == 1, LDPL_FATAL, "could not get lto-wrapper exit status");
  check (WIFEXITED (status) && WEXITSTATUS (status) == 0, LDPL_FATAL,
         "lto-wrapper failed");

  pex_free (pex);

  free (at_args);
}

/* Pass the original files back to the linker. */

static void
use_original_files (void)
{
  unsigned i;
  for (i = 0; i < num_claimed_files; i++)
    {
      struct plugin_file_info *info = &claimed_files[i];
      add_input_file (info->name);
    }
}


/* Called by the linker once all symbols have been read. */

static enum ld_plugin_status
all_symbols_read_handler (void)
{
  unsigned i;
  unsigned num_lto_args = num_claimed_files + lto_wrapper_num_args + 1;
  char **lto_argv;
  const char **lto_arg_ptr;
  if (num_claimed_files == 0)
    return LDPS_OK;

  if (nop)
    {
      use_original_files ();
      return LDPS_OK;
    }

  lto_argv = (char **) xcalloc (sizeof (char *), num_lto_args);
  lto_arg_ptr = (const char **) lto_argv;
  assert (lto_wrapper_argv);

  write_resolution ();

  free_1 ();

  for (i = 0; i < lto_wrapper_num_args; i++)
    *lto_arg_ptr++ = lto_wrapper_argv[i];

  for (i = 0; i < num_claimed_files; i++)
    {
      struct plugin_file_info *info = &claimed_files[i];

      *lto_arg_ptr++ = info->name;
    }

  *lto_arg_ptr++ = NULL;
  exec_lto_wrapper (lto_argv);

  free (lto_argv);

  if (pass_through_items)
    {
      unsigned int i;
      for (i = 0; i < num_pass_through_items; i++)
        {
          if (strncmp (pass_through_items[i], "-l", 2) == 0)
            add_input_library (pass_through_items[i] + 2);
          else
            add_input_file (pass_through_items[i]);
          free (pass_through_items[i]);
          pass_through_items[i] = NULL;
        }
      free (pass_through_items);
      pass_through_items = NULL;
    }

  return LDPS_OK;
}

/* Remove temporary files at the end of the link. */

static enum ld_plugin_status
cleanup_handler (void)
{
  unsigned int i;
  int t;

  if (debug)
    return LDPS_OK;

  if (arguments_file_name)
    {
      t = unlink (arguments_file_name);
      check (t == 0, LDPL_FATAL, "could not unlink arguments file");
    }

  for (i = 0; i < num_output_files; i++)
    {
      t = unlink (output_files[i]);
      check (t == 0, LDPL_FATAL, "could not unlink output file");
    }

  free_2 ();
  return LDPS_OK;
}

#define SWAP(type, a, b) \
  do { type tmp_; tmp_ = (a); (a) = (b); (b) = tmp_; } while(0)

/* Compare two hash table entries */

static int eq_sym (const void *a, const void *b)
{
  const struct ld_plugin_symbol *as = (const struct ld_plugin_symbol *)a;
  const struct ld_plugin_symbol *bs = (const struct ld_plugin_symbol *)b;

  return !strcmp (as->name, bs->name);
}

/* Hash a symbol */

static hashval_t hash_sym (const void *a)
{
  const struct ld_plugin_symbol *as = (const struct ld_plugin_symbol *)a;

  return htab_hash_string (as->name);
}

/* Determine how strong a symbol is */

static int symbol_strength (struct ld_plugin_symbol *s)
{
  switch (s->def) 
    { 
    case LDPK_UNDEF:
    case LDPK_WEAKUNDEF:
      return 0;
    case LDPK_WEAKDEF:
      return 1;
    default:
      return 2;
    }
}

/* In the ld -r case we can get dups in the LTO symbol tables, where
   the same symbol can have different resolutions (e.g. undefined and defined).

   We have to keep that in the LTO symbol tables, but the dups confuse
   gold and then finally gcc by supplying incorrect resolutions.

   Problem is that the main gold symbol table doesn't know about subids
   and does not distingush the same symbols in different states.

   So we drop duplicates from the linker visible symbol table
   and keep them in a private table. Then later do own symbol
   resolution for the duplicated based on the results for the
   originals.

   Then when writing out the resolution file readd the dropped symbols.
   
   XXX how to handle common? */

void
resolve_conflicts (struct plugin_symtab *t, struct plugin_symtab *conflicts)
{
  htab_t symtab = htab_create (t->nsyms, hash_sym, eq_sym, NULL);
  int i;
  int out;
  int outlen;

  outlen = t->nsyms;
  conflicts->syms = xmalloc (sizeof (struct ld_plugin_symbol) * outlen);
  conflicts->aux = xmalloc (sizeof (struct sym_aux) * outlen);

  /* Move all duplicate symbols into the auxillary conflicts table. */
  out = 0;
  for (i = 0; i < t->nsyms; i++) 
    {
      struct ld_plugin_symbol *s = &t->syms[i];
      struct sym_aux *aux = &t->aux[i];
      void **slot;

      slot = htab_find_slot (symtab, s, INSERT);
      if (*slot != NULL)
	{
	  int cnf;
	  struct ld_plugin_symbol *orig = (struct ld_plugin_symbol *)*slot;
	  struct sym_aux *orig_aux = &t->aux[orig - t->syms];

	  /* Always let the linker resolve the strongest symbol */
	  if (symbol_strength (orig) < symbol_strength (s)) 
	    {
	      SWAP (struct ld_plugin_symbol, *orig, *s);
	      SWAP (uint32_t, orig_aux->slot, aux->slot);
	      SWAP (unsigned, orig_aux->id, aux->id);
	      /* Don't swap conflict chain pointer */
	    } 

	  /* Move current symbol into the conflicts table */
	  cnf = conflicts->nsyms++;
	  conflicts->syms[cnf] = *s;
	  conflicts->aux[cnf] = *aux;
	  aux = &conflicts->aux[cnf];

	  /* Update conflicts chain of the original symbol */
	  aux->next_conflict = orig_aux->next_conflict;
	  orig_aux->next_conflict = cnf;

	  continue;
	}

      /* Remove previous duplicates in the main table */
      if (out < i)
	{
	  t->syms[out] = *s;
	  t->aux[out] = *aux;
	}

      /* Put original into the hash table */
      *slot = &t->syms[out];
      out++;
    }

  assert (conflicts->nsyms <= outlen);
  assert (conflicts->nsyms + out == t->nsyms);
  
  t->nsyms = out;
  htab_delete (symtab);
}

/* Parse the plugin options. */

static void
process_option (const char *option)
{
  if (strcmp (option, "-debug") == 0)
    debug = 1;
  else if (strcmp (option, "-nop") == 0)
    nop = 1;
  else if (!strncmp (option, "-pass-through=", strlen("-pass-through=")))
    {
      num_pass_through_items++;
      pass_through_items = xrealloc (pass_through_items,
				     num_pass_through_items * sizeof (char *));
      pass_through_items[num_pass_through_items - 1] =
          xstrdup (option + strlen ("-pass-through="));
    }
  else
    {
      int size;
      char *opt = xstrdup (option);
      lto_wrapper_num_args += 1;
      size = lto_wrapper_num_args * sizeof (char *);
      lto_wrapper_argv = (char **) xrealloc (lto_wrapper_argv, size);
      lto_wrapper_argv[lto_wrapper_num_args - 1] = opt;
      if (strncmp (option, "-fresolution=", sizeof ("-fresolution=") - 1) == 0)
	resolution_file = opt + sizeof ("-fresolution=") - 1;
    }
}

/* Called by gold after loading the plugin. TV is the transfer vector. */

enum ld_plugin_status
onload (struct ld_plugin_tv *tv)
{
  struct ld_plugin_tv *p;
  enum ld_plugin_status status;

  status = onload_format_checks (tv);
  if (status != LDPS_OK)
    return status;

  p = tv;
  while (p->tv_tag)
    {
      switch (p->tv_tag)
	{
        case LDPT_MESSAGE:
          message = p->tv_u.tv_message;
          break;
	case LDPT_REGISTER_CLAIM_FILE_HOOK:
	  register_claim_file = p->tv_u.tv_register_claim_file;
	  break;
	case LDPT_ADD_SYMBOLS:
	  add_symbols = p->tv_u.tv_add_symbols;
	  break;
	case LDPT_REGISTER_ALL_SYMBOLS_READ_HOOK:
	  register_all_symbols_read = p->tv_u.tv_register_all_symbols_read;
	  break;
	case LDPT_GET_SYMBOLS:
	  get_symbols = p->tv_u.tv_get_symbols;
	  break;
	case LDPT_REGISTER_CLEANUP_HOOK:
	  register_cleanup = p->tv_u.tv_register_cleanup;
	  break;
	case LDPT_ADD_INPUT_FILE:
	  add_input_file = p->tv_u.tv_add_input_file;
	  break;
	case LDPT_ADD_INPUT_LIBRARY:
	  add_input_library = p->tv_u.tv_add_input_library;
	  break;
	case LDPT_OPTION:
	  process_option (p->tv_u.tv_string);
	  break;
	default:
	  break;
	}
      p++;
    }

  check (register_claim_file, LDPL_FATAL, "register_claim_file not found");
  check (add_symbols, LDPL_FATAL, "add_symbols not found");
  status = register_claim_file (claim_file_handler);
  check (status == LDPS_OK, LDPL_FATAL,
	 "could not register the claim_file callback");

  if (register_cleanup)
    {
      status = register_cleanup (cleanup_handler);
      check (status == LDPS_OK, LDPL_FATAL,
	     "could not register the cleanup callback");
    }

  if (register_all_symbols_read)
    {
      check (get_symbols, LDPL_FATAL, "get_symbols not found");
      status = register_all_symbols_read (all_symbols_read_handler);
      check (status == LDPS_OK, LDPL_FATAL,
	     "could not register the all_symbols_read callback");
    }

  return LDPS_OK;
}
