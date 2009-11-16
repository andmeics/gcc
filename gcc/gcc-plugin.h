/* Public header file for plugins to include.
   Copyright (C) 2009 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef GCC_PLUGIN_H
#define GCC_PLUGIN_H

#ifndef IN_GCC
#define IN_GCC
#endif

#include "config.h"
#include "system.h"
#include "highlev-plugin-common.h"

/* Event names.  Keep in sync with plugin_event_name[].  */
enum plugin_event
{
  PLUGIN_PASS_MANAGER_SETUP,    /* To hook into pass manager.  */
  PLUGIN_FINISH_TYPE,           /* After finishing parsing a type.  */
  PLUGIN_FINISH_UNIT,           /* Useful for summary processing.  */
  PLUGIN_CXX_CP_PRE_GENERICIZE, /* Allows to see low level AST in C++ FE.  */
  PLUGIN_FINISH,                /* Called before GCC exits.  */
  PLUGIN_INFO,                  /* Information about the plugin. */
  PLUGIN_GGC_START,		/* Called at start of GCC Garbage Collection. */
  PLUGIN_GGC_MARKING,		/* Extend the GGC marking. */
  PLUGIN_GGC_END,		/* Called at end of GGC. */
  PLUGIN_REGISTER_GGC_ROOTS,	/* Register an extra GGC root table. */
  PLUGIN_REGISTER_GGC_CACHES,	/* Register an extra GGC cache table. */
  PLUGIN_ATTRIBUTES,            /* Called during attribute registration.  */
  PLUGIN_START_UNIT,            /* Called before processing a translation unit.  */
  PLUGIN_PRAGMAS,	        /* Called during pragma registration.  */

  /* The following events might be subject to change or deletion without
     prior notice.  Plugins should only use them by name.  */
  PLUGIN_FIRST_EXPERIMENTAL,
  PLUGIN_UNROLL_PARAMETER_HANDLER = PLUGIN_FIRST_EXPERIMENTAL,
  PLUGIN_ALL_PASSES_START,
  PLUGIN_ALL_PASSES_EXECUTION,
  PLUGIN_ALL_PASSES_END,
  PLUGIN_ALL_IPA_PASSES_START,
  PLUGIN_ALL_IPA_PASSES_EXECUTION,
  PLUGIN_ALL_IPA_PASSES_END,
  PLUGIN_AVOID_GATE,
  PLUGIN_PASS_EXECUTION,
  PLUGIN_EARLY_GIMPLE_PASSES_START,
  PLUGIN_EARLY_GIMPLE_PASSES_END,
  PLUGIN_FUNCTION_SPEC_LOADER,

  PLUGIN_EVENT_LAST             /* Dummy event used for indexing callback
                                   array.  */
};

extern const char **plugin_event_name;

struct plugin_argument
{
  char *key;    /* key of the argument.  */
  char *value;  /* value is optional and can be NULL.  */
};

/* Additional information about the plugin. Used by --help and --version. */

struct plugin_info
{
  const char *version;
  const char *help;
};

/* Represents the gcc version. Used to avoid using an incompatible plugin. */

struct plugin_gcc_version
{
  const char *basever;
  const char *datestamp;
  const char *devphase;
  const char *revision;
  const char *configuration_arguments;
};

/* Object that keeps track of the plugin name and its arguments. */
struct plugin_name_args
{
  char *base_name;              /* Short name of the plugin (filename without
                                   .so suffix). */
  const char *full_name;        /* Path to the plugin as specified with
                                   -fplugin=. */
  int argc;                     /* Number of arguments specified with
                                   -fplugin-arg-... */
  struct plugin_argument *argv; /* Array of ARGC key-value pairs. */
  const char *version;          /* Version string provided by plugin. */
  const char *help;             /* Help string provided by plugin. */
};

/* The default version check. Compares every field in VERSION. */

extern bool plugin_default_version_check (struct plugin_gcc_version *,
					  struct plugin_gcc_version *);

/* Function type for the plugin initialization routine. Each plugin module
   should define this as an externally-visible function with name
   "plugin_init."

   PLUGIN_INFO - plugin invocation information.
   VERSION     - the plugin_gcc_version symbol of GCC.

   Returns 0 if initialization finishes successfully.  */

typedef int (*plugin_init_func) (struct plugin_name_args *plugin_info,
                                 struct plugin_gcc_version *version);

/* Declaration for "plugin_init" function so that it doesn't need to be
   duplicated in every plugin.  */
extern int plugin_init (struct plugin_name_args *plugin_info,
                        struct plugin_gcc_version *version);

/* Function type for a plugin callback routine.

   GCC_DATA  - event-specific data provided by GCC
   USER_DATA - plugin-specific data provided by the plugin  */

typedef void (*plugin_callback_func) (void *gcc_data, void *user_data);

/* Called from the plugin's initialization code. Register a single callback.
   This function can be called multiple times.

   PLUGIN_NAME - display name for this plugin
   EVENT       - which event the callback is for
   CALLBACK    - the callback to be called at the event
   USER_DATA   - plugin-provided data.
*/

/* Number of event ids / names registered so far.  */

extern int event_last;

int get_named_event_id (const char *name, enum insert_option insert);

/* This is also called without a callback routine for the
   PLUGIN_PASS_MANAGER_SETUP, PLUGIN_INFO, PLUGIN_REGISTER_GGC_ROOTS and
   PLUGIN_REGISTER_GGC_CACHES pseudo-events, with a specific user_data.
  */

extern void register_callback (const char *plugin_name,
                               int event,
                               plugin_callback_func callback,
                               void *user_data);

extern int unregister_callback (const char *plugin_name, int event);

#endif /* GCC_PLUGIN_H */
