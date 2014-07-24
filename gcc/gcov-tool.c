/* Gcc offline profile processing tool support. */
/* Copyright (C) 2014 Free Software Foundation, Inc.
   Contributed by Rong Xu <xur@google.com>.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "intl.h"
#include "diagnostic.h"
#include "version.h"
#include "gcov-io.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ftw.h>
#include <getopt.h>

extern struct gcov_info *gcov_list;

extern int gcov_profile_merge (struct gcov_info*, struct gcov_info*, int, int);
extern int gcov_profile_normalize (struct gcov_info*, gcov_type);
extern int gcov_profile_scale (struct gcov_info*, float, int, int);
extern struct gcov_info* gcov_read_profile_dir (const char*, int);
extern void gcov_exit (void);
extern void gcov_set_verbose (void);

/* Set to verbose output mode.  */
static bool verbose;

/* Remove file NAME if it has a gcda suffix. */

static int
unlink_gcda_file (const char *name,
                  const struct stat *status ATTRIBUTE_UNUSED,
                  int type ATTRIBUTE_UNUSED,
                  struct FTW *ftwbuf ATTRIBUTE_UNUSED)
{
  int ret = 0;
  int len = strlen (name);
  int len1 = strlen (GCOV_DATA_SUFFIX);

  if (len > len1 && !strncmp (len -len1 + name, GCOV_DATA_SUFFIX, len1))
    ret = remove (name);

  if (ret)
    fatal_error ("error in removing %s\n", name);

  return ret;
}

/* Remove the gcda files in PATH recursively.  */

static int
unlink_profile_dir (const char *path)
{
    return nftw(path, unlink_gcda_file, 64, FTW_DEPTH | FTW_PHYS);
}

/* Output GCOV_INFO lists PROFILE to directory OUT. Note that
   we will remove all the gcda files in OUT.  */

static void
gcov_output_files (const char *out, struct gcov_info *profile)
{
  char *pwd;
  int ret;

  /* Try to make directory if it doesn't already exist.  */
  if (access (out, F_OK) == -1)
    {
#if !defined(_WIN32)
      if (mkdir (out, S_IRWXU | S_IRWXG | S_IRWXO) == -1 && errno != EEXIST)
#else
      if (mkdir (out) == -1 && errno != EEXIST)
#endif
        fatal_error ("Cannot make directory %s", out);
    } else
      unlink_profile_dir (out);

  /* Output new profile.  */
  pwd = getcwd (NULL, 0);

  if (pwd == NULL)
    fatal_error ("Cannot get current directory name");

  ret = chdir (out);
  if (ret)
    fatal_error ("Cannot change directory to %s", out);

  gcov_list = profile;
  gcov_exit ();

  ret = chdir (pwd);
  if (ret)
    fatal_error ("Cannot change directory to %s", pwd);

  free (pwd);
}

/* Merging profile D1 and D2 with weight as W1 and W2, respectively.
   The result profile is written to directory OUT.
   Return 0 on success.  */

static int
profile_merge (const char *d1, const char *d2, const char *out, int w1, int w2)
{
  struct gcov_info *d1_profile;
  struct gcov_info *d2_profile;
  int ret;

  d1_profile = gcov_read_profile_dir (d1, 0);
  if (!d1_profile)
    return 1;

  if (d2)
    {
      d2_profile = gcov_read_profile_dir (d2, 0);
      if (!d2_profile)
        return 1;

      /* The actual merge: we overwrite to d1_profile.  */
      ret = gcov_profile_merge (d1_profile, d2_profile, w1, w2);

      if (ret)
        return ret;
    }

  gcov_output_files (out, d1_profile);

  return 0;
}

/* Usage message for profile merge.  */

static void
print_merge_usage_message (int error_p)
{
  FILE *file = error_p ? stderr : stdout;

  fnotice (file, "  merge [options] <dir1> <dir2>         Merge coverage file contents\n");
  fnotice (file, "    -v, --verbose                       Verbose mode\n");
  fnotice (file, "    -o, --output <dir>                  Output directory\n");
  fnotice (file, "    -w, --weight <w1,w2>                Set weights (float point values)\n");
}

static const struct option merge_options[] =
{
  { "verbose",                no_argument,       NULL, 'v' },
  { "output",                 required_argument, NULL, 'o' },
  { "weight",                 required_argument, NULL, 'w' },
  { 0, 0, 0, 0 }
};

/* Print merge usage and exit.  */

static void
merge_usage (void)
{
  fnotice (stderr, "Merge subcomand usage:");
  print_merge_usage_message (true);
  exit (FATAL_EXIT_CODE);
}

/* Driver for profile merge sub-command.  */

static int
do_merge (int argc, char **argv)
{
  int opt;
  int ret;
  const char *output_dir = 0;
  int w1 = 1, w2 = 1;

  optind = 0;
  while ((opt = getopt_long (argc, argv, "vo:w:", merge_options, NULL)) != -1)
    {
      switch (opt)
        {
        case 'v':
          verbose = true;
          gcov_set_verbose ();
          break;
        case 'o':
          output_dir = optarg;
          break;
        case 'w':
          sscanf (optarg, "%d,%d", &w1, &w2);
          if (w1 < 0 || w2 < 0)
            fatal_error ("weights need to be non-negative\n");
          break;
        default:
          merge_usage ();
        }
    }

  if (output_dir == NULL)
    output_dir = "merged_profile";

  if (argc - optind == 2)
    ret = profile_merge (argv[optind], argv[optind+1], output_dir, w1, w2);
  else
    merge_usage ();

  return ret;
}

/* If N_VAL is no-zero, normalize the profile by setting the largest counter
   counter value to N_VAL and scale others counters proportionally.
   Otherwise, multiply the all counters by SCALE.  */

static int
profile_rewrite (const char *d1, const char *out, long long n_val,
                 float scale, int n, int d)
{
  struct gcov_info * d1_profile;

  d1_profile = gcov_read_profile_dir (d1, 0);
  if (!d1_profile)
    return 1;

  if (n_val)
    gcov_profile_normalize (d1_profile, (gcov_type) n_val);
  else
    gcov_profile_scale (d1_profile, scale, n, d);

  gcov_output_files (out, d1_profile);
  return 0;
}

/* Usage function for profile rewrite.  */

static void
print_rewrite_usage_message (int error_p)
{
  FILE *file = error_p ? stderr : stdout;

  fnotice (file, "  rewrite [options] <dir>               Rewrite coverage file contents\n");
  fnotice (file, "    -v, --verbose                       Verbose mode\n");
  fnotice (file, "    -o, --output <dir>                  Output directory\n");
  fnotice (file, "    -s, --scale <float or simple-frac>  Scale the profile counters\n");
  fnotice (file, "    -n, --normalize <long long>         Normalize the profile\n");
}

static const struct option rewrite_options[] =
{
  { "verbose",                no_argument,       NULL, 'v' },
  { "output",                 required_argument, NULL, 'o' },
  { "scale",                  required_argument, NULL, 's' },
  { "normalize",              required_argument, NULL, 'n' },
  { 0, 0, 0, 0 }
};

/* Print profile rewrite usage and exit.  */

static void
rewrite_usage (void)
{
  fnotice (stderr, "Rewrite subcommand usage:");
  print_rewrite_usage_message (true);
  exit (FATAL_EXIT_CODE);
}

/* Driver for profile rewrite sub-command. */

static int
do_rewrite (int argc, char **argv)
{
  int opt;
  int ret;
  const char *output_dir = 0;
  long long normalize_val = 0;
  float scale = 0.0;
  int numerator = 1;
  int denominator = 1;
  int do_scaling = 0;

  optind = 0;
  while ((opt = getopt_long (argc, argv, "vo:s:n:", rewrite_options, NULL)) != -1)
    {
      switch (opt)
        {
        case 'v':
          verbose = true;
          gcov_set_verbose ();
          break;
        case 'o':
          output_dir = optarg;
          break;
        case 'n':
          if (!do_scaling)
            normalize_val = atoll (optarg);
          else
            fnotice (stderr, "scaling cannot co-exist with normalization,"
                " skipping\n");
          break;
        case 's':
          ret = 0;
          do_scaling = 1;
          if (strstr (optarg, "/"))
            {
              ret = sscanf (optarg, "%d/%d", &numerator, &denominator);
              if (ret == 2)
                {
                  if (numerator < 0 || denominator <= 0)
                    {
                      fnotice (stderr, "incorrect format in scaling, using 1/1\n");
                      denominator = 1;
                      numerator = 1;
                    }
                }
            }
          if (ret != 2)
            {
              ret = sscanf (optarg, "%f", &scale);
              if (ret != 1)
                fnotice (stderr, "incorrect format in scaling, using 1/1\n");
              else
                denominator = 0;
            }

          if (scale < 0.0)
            fatal_error ("scale needs to be non-negative\n");

          if (normalize_val != 0)
            {
              fnotice (stderr, "normalization cannot co-exist with scaling\n");
              normalize_val = 0;
            }
          break;
        default:
          rewrite_usage ();
        }
    }

  if (output_dir == NULL)
    output_dir = "rewrite_profile";

  if (argc - optind == 1)
    {
      if (denominator > 0)
        ret = profile_rewrite (argv[optind],  output_dir, 0, 0.0, numerator, denominator);
      else
        ret = profile_rewrite (argv[optind],  output_dir, normalize_val, scale, 0, 0);
    }
  else
    rewrite_usage ();

  return ret;
}

/* Print a usage message and exit.  If ERROR_P is nonzero, this is an error,
   otherwise the output of --help.  */

static void
print_usage (int error_p)
{
  FILE *file = error_p ? stderr : stdout;
  int status = error_p ? FATAL_EXIT_CODE : SUCCESS_EXIT_CODE;

  fnotice (file, "Usage: %s [OPTION]... SUB_COMMAND [OPTION]...\n\n", progname);
  fnotice (file, "Offline tool to handle gcda counts\n\n");
  fnotice (file, "  -h, --help                            Print this help, then exit\n");
  fnotice (file, "  -v, --version                         Print version number, then exit\n");
  print_merge_usage_message (error_p);
  print_rewrite_usage_message (error_p);
  fnotice (file, "\nFor bug reporting instructions, please see:\n%s.\n",
           bug_report_url);
  exit (status);
}

/* Print version information and exit.  */

static void
print_version (void)
{
  fnotice (stdout, "%s %s%s\n", progname, pkgversion_string, version_string);
  fnotice (stdout, "Copyright %s 2014 Free Software Foundation, Inc.\n",
           _("(C)"));
  fnotice (stdout,
           _("This is free software; see the source for copying conditions.\n"
             "There is NO warranty; not even for MERCHANTABILITY or \n"
             "FITNESS FOR A PARTICULAR PURPOSE.\n\n"));
  exit (SUCCESS_EXIT_CODE);
}

static const struct option options[] =
{
  { "help",                 no_argument,       NULL, 'h' },
  { "version",              no_argument,       NULL, 'v' },
  { 0, 0, 0, 0 }
};

/* Process args, return index to first non-arg.  */

static int
process_args (int argc, char **argv)
{
  int opt;

  while ((opt = getopt_long (argc, argv, "+hv", options, NULL)) != -1)
    {
      switch (opt)
        {
        case 'h':
          print_usage (false);
          /* Print_usage will exit.  */
        case 'v':
          print_version ();
          /* Print_version will exit.  */
        default:
          print_usage (true);
          /* Print_usage will exit.  */
        }
    }

  return optind;
}

/* Main function for gcov-tool.  */

int
main (int argc, char **argv)
{
  const char *p;
  const char *sub_command;

  p = argv[0] + strlen (argv[0]);
  while (p != argv[0] && !IS_DIR_SEPARATOR (p[-1]))
    --p;
  progname = p;

  xmalloc_set_program_name (progname);

  /* Unlock the stdio streams.  */
  unlock_std_streams ();

  gcc_init_libintl ();

  diagnostic_initialize (global_dc, 0);

  /* Handle response files.  */
  expandargv (&argc, &argv);

  process_args (argc, argv);
  if (optind >= argc)
    print_usage (true);

  sub_command = argv[optind];

  if (!strcmp (sub_command, "merge"))
    return do_merge (argc - optind, argv + optind);
  else if (!strcmp (sub_command, "rewrite"))
    return do_rewrite (argc - optind, argv + optind);

  print_usage (true);
}
