
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_rmi_activation_ActivationException__
#define __java_rmi_activation_ActivationException__

#pragma interface

#include <java/lang/Exception.h>
extern "Java"
{
  namespace java
  {
    namespace rmi
    {
      namespace activation
      {
          class ActivationException;
      }
    }
  }
}

class java::rmi::activation::ActivationException : public ::java::lang::Exception
{

public:
  ActivationException();
  ActivationException(::java::lang::String *);
  ActivationException(::java::lang::String *, ::java::lang::Throwable *);
  virtual ::java::lang::String * getMessage();
  virtual ::java::lang::Throwable * getCause();
private:
  static const jlong serialVersionUID = -4320118837291406071LL;
public:
  ::java::lang::Throwable * __attribute__((aligned(__alignof__( ::java::lang::Exception)))) detail;
  static ::java::lang::Class class$;
};

#endif // __java_rmi_activation_ActivationException__
