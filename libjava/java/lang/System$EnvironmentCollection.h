
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_lang_System$EnvironmentCollection__
#define __java_lang_System$EnvironmentCollection__

#pragma interface

#include <java/util/AbstractCollection.h>

class java::lang::System$EnvironmentCollection : public ::java::util::AbstractCollection
{

public:
  System$EnvironmentCollection(::java::util::Collection *);
  virtual jboolean contains(::java::lang::Object *);
  virtual jboolean containsAll(::java::util::Collection *);
  virtual ::java::util::Iterator * iterator();
  virtual jboolean remove(::java::lang::Object *);
  virtual jboolean removeAll(::java::util::Collection *);
  virtual jboolean retainAll(::java::util::Collection *);
  virtual jint size();
public: // actually protected
  ::java::util::Collection * __attribute__((aligned(__alignof__( ::java::util::AbstractCollection)))) c;
public:
  static ::java::lang::Class class$;
};

#endif // __java_lang_System$EnvironmentCollection__
