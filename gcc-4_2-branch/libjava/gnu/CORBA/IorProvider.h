
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_CORBA_IorProvider__
#define __gnu_CORBA_IorProvider__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace CORBA
    {
        class IOR;
        class IorProvider;
    }
  }
}

class gnu::CORBA::IorProvider : public ::java::lang::Object
{

public:
  virtual ::gnu::CORBA::IOR * getIor() = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __gnu_CORBA_IorProvider__
