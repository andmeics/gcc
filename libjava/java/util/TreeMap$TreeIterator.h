
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_TreeMap$TreeIterator__
#define __java_util_TreeMap$TreeIterator__

#pragma interface

#include <java/lang/Object.h>

class java::util::TreeMap$TreeIterator : public ::java::lang::Object
{

public: // actually package-private
  TreeMap$TreeIterator(::java::util::TreeMap *, jint);
  TreeMap$TreeIterator(::java::util::TreeMap *, jint, ::java::util::TreeMap$Node *, ::java::util::TreeMap$Node *);
public:
  jboolean hasNext();
  ::java::lang::Object * next();
  void remove();
private:
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) type;
  jint knownMod;
  ::java::util::TreeMap$Node * last;
  ::java::util::TreeMap$Node * next__;
  ::java::util::TreeMap$Node * max;
public: // actually package-private
  ::java::util::TreeMap * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __java_util_TreeMap$TreeIterator__
