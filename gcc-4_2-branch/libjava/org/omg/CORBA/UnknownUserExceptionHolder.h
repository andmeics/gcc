
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_omg_CORBA_UnknownUserExceptionHolder__
#define __org_omg_CORBA_UnknownUserExceptionHolder__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace org
  {
    namespace omg
    {
      namespace CORBA
      {
          class TypeCode;
          class UnknownUserException;
          class UnknownUserExceptionHolder;
        namespace portable
        {
            class InputStream;
            class OutputStream;
        }
      }
    }
  }
}

class org::omg::CORBA::UnknownUserExceptionHolder : public ::java::lang::Object
{

public:
  UnknownUserExceptionHolder();
  UnknownUserExceptionHolder(::org::omg::CORBA::UnknownUserException *);
  void _read(::org::omg::CORBA::portable::InputStream *);
  void _write(::org::omg::CORBA::portable::OutputStream *);
  ::org::omg::CORBA::TypeCode * _type();
  ::org::omg::CORBA::UnknownUserException * __attribute__((aligned(__alignof__( ::java::lang::Object)))) value;
  static ::java::lang::Class class$;
};

#endif // __org_omg_CORBA_UnknownUserExceptionHolder__
