
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_EnumMap$6__
#define __java_util_EnumMap$6__

#pragma interface

#include <java/lang/Object.h>

class java::util::EnumMap$6 : public ::java::lang::Object
{

public: // actually package-private
  EnumMap$6(::java::util::EnumMap$5 *);
public:
  jboolean hasNext();
  ::java::util::Map$Entry * target$next();
  void remove();
  ::java::lang::Object * next();
public: // actually package-private
  static ::java::util::EnumMap$5 * access$1(::java::util::EnumMap$6 *);
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) count;
  jint index;
  ::java::util::EnumMap$5 * this$1;
public:
  static ::java::lang::Class class$;
};

#endif // __java_util_EnumMap$6__
