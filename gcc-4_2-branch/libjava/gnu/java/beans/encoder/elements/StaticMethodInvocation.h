
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_beans_encoder_elements_StaticMethodInvocation__
#define __gnu_java_beans_encoder_elements_StaticMethodInvocation__

#pragma interface

#include <gnu/java/beans/encoder/elements/Element.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace beans
      {
        namespace encoder
        {
            class Writer;
          namespace elements
          {
              class StaticMethodInvocation;
          }
        }
      }
    }
  }
}

class gnu::java::beans::encoder::elements::StaticMethodInvocation : public ::gnu::java::beans::encoder::elements::Element
{

public:
  StaticMethodInvocation(::java::lang::String *, ::java::lang::String *);
  virtual void writeStart(::gnu::java::beans::encoder::Writer *);
public: // actually package-private
  ::java::lang::String * __attribute__((aligned(__alignof__( ::gnu::java::beans::encoder::elements::Element)))) className;
  ::java::lang::String * methodName;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_beans_encoder_elements_StaticMethodInvocation__
