
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_util_WeakIdentityHashMap$WeakBucket__
#define __gnu_java_util_WeakIdentityHashMap$WeakBucket__

#pragma interface

#include <java/lang/ref/WeakReference.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace util
      {
          class WeakIdentityHashMap$WeakBucket;
          class WeakIdentityHashMap$WeakBucket$WeakEntry;
      }
    }
  }
}

class gnu::java::util::WeakIdentityHashMap$WeakBucket : public ::java::lang::ref::WeakReference
{

public:
  WeakIdentityHashMap$WeakBucket(::java::lang::Object *, ::java::lang::ref::ReferenceQueue *, ::java::lang::Object *, jint);
public: // actually package-private
  virtual ::gnu::java::util::WeakIdentityHashMap$WeakBucket$WeakEntry * getEntry();
  ::java::lang::Object * __attribute__((aligned(__alignof__( ::java::lang::ref::WeakReference)))) value;
  ::gnu::java::util::WeakIdentityHashMap$WeakBucket * next;
  jint slot;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_util_WeakIdentityHashMap$WeakBucket__
