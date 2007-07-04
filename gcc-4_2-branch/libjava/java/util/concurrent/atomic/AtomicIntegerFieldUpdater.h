
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_concurrent_atomic_AtomicIntegerFieldUpdater__
#define __java_util_concurrent_atomic_AtomicIntegerFieldUpdater__

#pragma interface

#include <java/lang/Object.h>

class java::util::concurrent::atomic::AtomicIntegerFieldUpdater : public ::java::lang::Object
{

public:
  static ::java::util::concurrent::atomic::AtomicIntegerFieldUpdater * newUpdater(::java::lang::Class *, ::java::lang::String *);
public: // actually protected
  AtomicIntegerFieldUpdater();
public:
  virtual jboolean compareAndSet(::java::lang::Object *, jint, jint) = 0;
  virtual jboolean weakCompareAndSet(::java::lang::Object *, jint, jint) = 0;
  virtual void set(::java::lang::Object *, jint) = 0;
  virtual void lazySet(::java::lang::Object *, jint) = 0;
  virtual jint get(::java::lang::Object *) = 0;
  virtual jint getAndSet(::java::lang::Object *, jint);
  virtual jint getAndIncrement(::java::lang::Object *);
  virtual jint getAndDecrement(::java::lang::Object *);
  virtual jint getAndAdd(::java::lang::Object *, jint);
  virtual jint incrementAndGet(::java::lang::Object *);
  virtual jint decrementAndGet(::java::lang::Object *);
  virtual jint addAndGet(::java::lang::Object *, jint);
  static ::java::lang::Class class$;
};

#endif // __java_util_concurrent_atomic_AtomicIntegerFieldUpdater__
