
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_beans_ExplicitBeanInfo__
#define __gnu_java_beans_ExplicitBeanInfo__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace beans
      {
          class ExplicitBeanInfo;
      }
    }
  }
  namespace java
  {
    namespace awt
    {
        class Image;
    }
    namespace beans
    {
        class BeanDescriptor;
        class BeanInfo;
        class EventSetDescriptor;
        class MethodDescriptor;
        class PropertyDescriptor;
    }
  }
}

class gnu::java::beans::ExplicitBeanInfo : public ::java::lang::Object
{

public:
  ExplicitBeanInfo(::java::beans::BeanDescriptor *, JArray< ::java::beans::BeanInfo * > *, JArray< ::java::beans::PropertyDescriptor * > *, jint, JArray< ::java::beans::EventSetDescriptor * > *, jint, JArray< ::java::beans::MethodDescriptor * > *, JArray< ::java::awt::Image * > *);
  virtual ::java::beans::BeanDescriptor * getBeanDescriptor();
  virtual JArray< ::java::beans::EventSetDescriptor * > * getEventSetDescriptors();
  virtual jint getDefaultEventIndex();
  virtual JArray< ::java::beans::PropertyDescriptor * > * getPropertyDescriptors();
  virtual jint getDefaultPropertyIndex();
  virtual JArray< ::java::beans::MethodDescriptor * > * getMethodDescriptors();
  virtual JArray< ::java::beans::BeanInfo * > * getAdditionalBeanInfo();
  virtual ::java::awt::Image * getIcon(jint);
public: // actually protected
  ::java::beans::BeanDescriptor * __attribute__((aligned(__alignof__( ::java::lang::Object)))) beanDescriptor;
  JArray< ::java::beans::EventSetDescriptor * > * eventSetDescriptors;
  JArray< ::java::beans::PropertyDescriptor * > * propertyDescriptors;
  JArray< ::java::beans::MethodDescriptor * > * methodDescriptors;
  jint defaultPropertyIndex;
  jint defaultEventIndex;
  JArray< ::java::beans::BeanInfo * > * additionalBeanInfo;
  JArray< ::java::awt::Image * > * icons;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_beans_ExplicitBeanInfo__
