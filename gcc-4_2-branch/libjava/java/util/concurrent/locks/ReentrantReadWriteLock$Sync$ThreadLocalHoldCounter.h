
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_concurrent_locks_ReentrantReadWriteLock$Sync$ThreadLocalHoldCounter__
#define __java_util_concurrent_locks_ReentrantReadWriteLock$Sync$ThreadLocalHoldCounter__

#pragma interface

#include <java/lang/ThreadLocal.h>

class java::util::concurrent::locks::ReentrantReadWriteLock$Sync$ThreadLocalHoldCounter : public ::java::lang::ThreadLocal
{

public: // actually package-private
  ReentrantReadWriteLock$Sync$ThreadLocalHoldCounter();
public:
  ::java::util::concurrent::locks::ReentrantReadWriteLock$Sync$HoldCounter * target$initialValue();
  ::java::lang::Object * initialValue();
  static ::java::lang::Class class$;
};

#endif // __java_util_concurrent_locks_ReentrantReadWriteLock$Sync$ThreadLocalHoldCounter__
