
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_lang_annotation_AnnotationTypeMismatchException__
#define __java_lang_annotation_AnnotationTypeMismatchException__

#pragma interface

#include <java/lang/RuntimeException.h>

class java::lang::annotation::AnnotationTypeMismatchException : public ::java::lang::RuntimeException
{

public:
  AnnotationTypeMismatchException(::java::lang::reflect::Method *, ::java::lang::String *);
  virtual ::java::lang::reflect::Method * element();
  virtual ::java::lang::String * foundType();
private:
  static const jlong serialVersionUID = 8125925355765570191LL;
  ::java::lang::reflect::Method * __attribute__((aligned(__alignof__( ::java::lang::RuntimeException)))) element__;
  ::java::lang::String * foundType__;
public:
  static ::java::lang::Class class$;
};

#endif // __java_lang_annotation_AnnotationTypeMismatchException__
