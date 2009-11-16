/* Compiler-side interface for high-level plugins in GCC.
   Copyright (C) 2009 Free Software Foundation, Inc.
   
   Contributed by Inria.

   Authors: Grigori Fursin <grigori.fursin@inria.fr>, Cupertino Miranda
   <cupertinomiranda@gmail.com>, Zbigniew Chamski <zbigniew.chamski@gmail.com>.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef HIGHLEV_PLUGIN_INTERNAL
#define HIGHLEV_PLUGIN_INTERNAL

/* Callback type for high-level argument-less event callbacks */
typedef void (*event_callback_t) (void);

/* Manipulation of events and event handlers */
extern void register_plugin_event (const char *name, event_callback_t func);
extern void unregister_plugin_event (const char *name);
extern const char **list_plugin_events (void);
extern int call_plugin_event (const char *event_name);

/* return codes for call_plugin_event */
#define PLUGEVT_SUCCESS         0
#define PLUGEVT_NO_EVENTS       1
#define PLUGEVT_NO_SUCH_EVENT   2
#define PLUGEVT_NO_CALLBACK     3

/* Datatype of event parameter structure.  */
typedef enum
{
  EP_SILENT, /* Used to pass infomation between ICI and plugin,
		parameter of this type will not be recorded.
		The data type is int.  */
  EP_VOID,
  EP_CHAR,
  EP_UNSIGNED_CHAR,
  EP_INT,
  EP_UNSIGNED,
  EP_LONG,
  EP_UNSIGNED_LONG
} event_parameter_type;

/* Manipulation of event parameters (callback arguments) */
extern void register_event_parameter (const char *name, void *param,
				      event_parameter_type type);
extern void unregister_event_parameter (const char *name);
extern const char **list_event_parameters (void);
extern void *get_event_parameter (const char *name);

/* ICI-specific, environment-based plugin loading */
extern void load_ici_plugin (void);

/* Info needed by adaptation.  */
typedef struct {
  int numofclonefun;
  char **clone_function_list;
  char **function_filename_list;
  int *clones;
  char **clone_extension;
  char **adaptation_function;
  char **clone_option;
  char *external_libraries;
} cloneinfo ;

typedef struct {
  int numofinstrfun;
  char **instrument_function_list;
  char **function_filename_list;
  char **timer1;
  char **timer2;
  char *cloned;
} instrinfo ;

#endif /* HIGHLEV_PLUGIN_INTERNAL_H*/
