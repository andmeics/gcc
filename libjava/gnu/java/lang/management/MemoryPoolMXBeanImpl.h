
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_lang_management_MemoryPoolMXBeanImpl__
#define __gnu_java_lang_management_MemoryPoolMXBeanImpl__

#pragma interface

#include <gnu/java/lang/management/BeanImpl.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace lang
      {
        namespace management
        {
            class MemoryPoolMXBeanImpl;
        }
      }
    }
  }
}

class gnu::java::lang::management::MemoryPoolMXBeanImpl : public ::gnu::java::lang::management::BeanImpl
{

public:
  MemoryPoolMXBeanImpl(::java::lang::String *);
  ::java::lang::management::MemoryUsage * getCollectionUsage();
  jlong getCollectionUsageThreshold();
  jlong getCollectionUsageThresholdCount();
  JArray< ::java::lang::String * > * getMemoryManagerNames();
  ::java::lang::String * getName();
  ::java::lang::management::MemoryUsage * getPeakUsage();
  ::java::lang::management::MemoryType * getType();
  ::java::lang::management::MemoryUsage * getUsage();
  jlong getUsageThreshold();
  jlong getUsageThresholdCount();
  jboolean isCollectionUsageThresholdExceeded();
  jboolean isCollectionUsageThresholdSupported();
  jboolean isUsageThresholdExceeded();
  jboolean isUsageThresholdSupported();
  jboolean isValid();
  void resetPeakUsage();
  void setCollectionUsageThreshold(jlong);
  void setUsageThreshold(jlong);
private:
  ::java::lang::String * __attribute__((aligned(__alignof__( ::gnu::java::lang::management::BeanImpl)))) name;
  static ::java::lang::String * COLLECTION_USAGE_THRESHOLD;
  static ::java::lang::String * USAGE_THRESHOLD;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_lang_management_MemoryPoolMXBeanImpl__
