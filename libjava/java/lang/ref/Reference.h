
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_lang_ref_Reference__
#define __java_lang_ref_Reference__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace gcj
    {
        class RawData;
    }
  }
}

class java::lang::ref::Reference : public ::java::lang::Object
{

public: // actually package-private
  Reference(::java::lang::Object *);
  Reference(::java::lang::Object *, ::java::lang::ref::ReferenceQueue *);
private:
  void create(::java::lang::Object *);
public:
  virtual ::java::lang::Object * get();
  virtual void clear();
  virtual jboolean isEnqueued();
  virtual jboolean enqueue();
public: // actually package-private
  ::gnu::gcj::RawData * __attribute__((aligned(__alignof__( ::java::lang::Object)))) referent;
  ::gnu::gcj::RawData * copy;
  jboolean cleared;
  ::java::lang::ref::ReferenceQueue * queue;
  ::java::lang::ref::Reference * nextOnQueue;
  static ::java::lang::Object * lock;
public:
  static ::java::lang::Class class$;
};

#endif // __java_lang_ref_Reference__
