
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_rmi_activation_ActivationInstantiator__
#define __java_rmi_activation_ActivationInstantiator__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace rmi
    {
        class MarshalledObject;
      namespace activation
      {
          class ActivationDesc;
          class ActivationID;
          class ActivationInstantiator;
      }
    }
  }
}

class java::rmi::activation::ActivationInstantiator : public ::java::lang::Object
{

public:
  virtual ::java::rmi::MarshalledObject * newInstance(::java::rmi::activation::ActivationID *, ::java::rmi::activation::ActivationDesc *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __java_rmi_activation_ActivationInstantiator__
