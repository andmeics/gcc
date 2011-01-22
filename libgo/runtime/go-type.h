/* go-type.h -- basic information for a Go type.

   Copyright 2009 The Go Authors. All rights reserved.
   Use of this source code is governed by a BSD-style
   license that can be found in the LICENSE file.  */

#ifndef LIBGO_GO_TYPE_H
#define LIBGO_GO_TYPE_H

#include <stddef.h>
#include <stdint.h>

#include "go-string.h"
#include "array.h"

/* Many of the types in this file must match the data structures
   generated by the compiler, and must also match the Go types which
   appear in go/runtime/type.go and go/reflect/type.go.  */

/* Type kinds.  These are used to get the type descriptor to use for
   the type itself, when using unsafe.Typeof or unsafe.Reflect.  The
   values here must match the values generated by the compiler (the
   RUNTIME_TYPE_KIND_xxx values in gcc/go/types.h).  These are macros
   rather than an enum to make it easy to change values in the future
   and hard to get confused about it.

   These correspond to the kind values used by the gc compiler.  */

#define GO_BOOL 1
#define GO_INT 2
#define GO_INT8 3
#define GO_INT16 4
#define GO_INT32 5
#define GO_INT64 6
#define GO_UINT 7
#define GO_UINT8 8
#define GO_UINT16 9
#define GO_UINT32 10
#define GO_UINT64 11
#define GO_UINTPTR 12
#define GO_FLOAT32 13
#define GO_FLOAT64 14
#define GO_COMPLEX64 15
#define GO_COMPLEX128 16
#define GO_ARRAY 17
#define GO_CHAN 18
#define GO_FUNC 19
#define GO_INTERFACE 20
#define GO_MAP 21
#define GO_PTR 22
#define GO_SLICE 23
#define GO_STRING 24
#define GO_STRUCT 25
#define GO_UNSAFE_POINTER 26

/* For each Go type the compiler constructs one of these structures.
   This is used for type reflectin, interfaces, maps, and reference
   counting.  */

struct __go_type_descriptor
{
  /* The type code for this type, a value in enum __go_type_codes.
     This is used by unsafe.Reflect and unsafe.Typeof to determine the
     type descriptor to return for this type itself.  It is also used
     by reflect.toType when mapping to a reflect Type structure.  */
  unsigned char __code;

  /* The alignment in bytes of a variable with this type.  */
  unsigned char __align;

  /* The alignment in bytes of a struct field with this type.  */
  unsigned char __field_align;

  /* The size in bytes of a value of this type.  Note that all types
     in Go have a fixed size.  */
  uintptr_t __size;

  /* The type's hash code.  */
  uint32_t __hash;

  /* This function takes a pointer to a value of this type, and the
     size of this type, and returns a hash code.  We pass the size
     explicitly becaues it means that we can share a single instance
     of this function for various different types.  */
  size_t (*__hashfn) (const void *, size_t);

  /* This function takes two pointers to values of this type, and the
     size of this type, and returns whether the values are equal.  */
  _Bool (*__equalfn) (const void *, const void *, size_t);

  /* A string describing this type.  This is only used for
     debugging.  */
  const struct __go_string *__reflection;

  /* A pointer to fields which are only used for some types.  */
  const struct __go_uncommon_type *__uncommon;
};

/* The information we store for each method of a type.  */

struct __go_method
{
  /* The name of the method.  */
  const struct __go_string *__name;

  /* This is NULL for an exported method, or the name of the package
     where it lives.  */
  const struct __go_string *__pkg_path;

  /* The type of the method, without the receiver.  This will be a
     function type.  */
  const struct __go_type_descriptor *__mtype;

  /* The type of the method, with the receiver.  This will be a
     function type.  */
  const struct __go_type_descriptor *__type;

  /* A pointer to the code which implements the method.  This is
     really a function pointer.  */
  const void *__function;
};

/* Additional information that we keep for named types and for types
   with methods.  */

struct __go_uncommon_type
{
  /* The name of the type.  */
  const struct __go_string *__name;

  /* The type's package.  This is NULL for builtin types.  */
  const struct __go_string *__pkg_path;

  /* The type's methods.  This is an array of struct __go_method.  */
  struct __go_open_array __methods;
};

/* The type descriptor for a fixed array type.  */

struct __go_array_type
{
  /* Starts like all type descriptors.  */
  struct __go_type_descriptor __common;

  /* The element type.  */
  struct __go_type_descriptor *__element_type;

  /* The length of the array.  */
  uintptr_t __len;
};

/* The type descriptor for a slice.  */

struct __go_slice_type
{
  /* Starts like all other type descriptors.  */
  struct __go_type_descriptor __common;

  /* The element type.  */
  struct __go_type_descriptor *__element_type;
};

/* The direction of a channel.  */
#define CHANNEL_RECV_DIR 1
#define CHANNEL_SEND_DIR 2
#define CHANNEL_BOTH_DIR (CHANNEL_RECV_DIR | CHANNEL_SEND_DIR)

/* The type descriptor for a channel.  */

struct __go_channel_type
{
  /* Starts like all other type descriptors.  */
  struct __go_type_descriptor __common;

  /* The element type.  */
  const struct __go_type_descriptor *__element_type;

  /* The direction.  */
  uintptr_t __dir;
};

/* The type descriptor for a function.  */

struct __go_func_type
{
  /* Starts like all other type descriptors.  */
  struct __go_type_descriptor __common;

  /* Whether this is a varargs function.  If this is true, there will
     be at least one parameter.  For "..." the last parameter type is
     "interface{}".  For "... T" the last parameter type is "[]T".  */
  _Bool __dotdotdot;

  /* The input parameter types.  This is an array of pointers to
     struct __go_type_descriptor.  */
  struct __go_open_array __in;

  /* The output parameter types.  This is an array of pointers to
     struct __go_type_descriptor.  */
  struct __go_open_array __out;
};

/* A method on an interface type.  */

struct __go_interface_method
{
  /* The name of the method.  */
  const struct __go_string *__name;

  /* This is NULL for an exported method, or the name of the package
     where it lives.  */
  const struct __go_string *__pkg_path;

  /* The real type of the method.  */
  struct __go_type_descriptor *__type;
};

/* An interface type.  */

struct __go_interface_type
{
  /* Starts like all other type descriptors.  */
  struct __go_type_descriptor __common;

  /* Array of __go_interface_method .  The methods are sorted in the
     same order that they appear in the definition of the
     interface.  */
  struct __go_open_array __methods;
};

/* A map type.  */

struct __go_map_type
{
  /* Starts like all other type descriptors.  */
  struct __go_type_descriptor __common;

  /* The map key type.  */
  const struct __go_type_descriptor *__key_type;

  /* The map value type.  */
  const struct __go_type_descriptor *__val_type;
};

/* A pointer type.  */

struct __go_ptr_type
{
  /* Starts like all other type descriptors.  */
  struct __go_type_descriptor __common;

  /* The type to which this points.  */
  const struct __go_type_descriptor *__element_type;
};

/* A field in a structure.  */

struct __go_struct_field
{
  /* The name of the field--NULL for an anonymous field.  */
  const struct __go_string *__name;

  /* This is NULL for an exported method, or the name of the package
     where it lives.  */
  const struct __go_string *__pkg_path;

  /* The type of the field.  */
  const struct __go_type_descriptor *__type;

  /* The field tag, or NULL.  */
  const struct __go_string *__tag;

  /* The offset of the field in the struct.  */
  uintptr_t __offset;
};

/* A struct type.  */

struct __go_struct_type
{
  /* Starts like all other type descriptors.  */
  struct __go_type_descriptor __common;

  /* An array of struct __go_struct_field.  */
  struct __go_open_array __fields;
};

/* Whether a type descriptor is a pointer.  */

static inline _Bool
__go_is_pointer_type (const struct __go_type_descriptor *td)
{
  return td->__code == GO_PTR || td->__code == GO_UNSAFE_POINTER;
}

extern _Bool
__go_type_descriptors_equal(const struct __go_type_descriptor*,
			    const struct __go_type_descriptor*);

extern size_t __go_type_hash_identity (const void *, size_t);
extern _Bool __go_type_equal_identity (const void *, const void *, size_t);
extern size_t __go_type_hash_string (const void *, size_t);
extern _Bool __go_type_equal_string (const void *, const void *, size_t);
extern size_t __go_type_hash_interface (const void *, size_t);
extern _Bool __go_type_equal_interface (const void *, const void *, size_t);
extern size_t __go_type_hash_error (const void *, size_t);
extern _Bool __go_type_equal_error (const void *, const void *, size_t);

#endif /* !defined(LIBGO_GO_TYPE_H) */
