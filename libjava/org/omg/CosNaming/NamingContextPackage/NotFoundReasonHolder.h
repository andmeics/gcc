
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_omg_CosNaming_NamingContextPackage_NotFoundReasonHolder__
#define __org_omg_CosNaming_NamingContextPackage_NotFoundReasonHolder__

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
        namespace portable
        {
            class InputStream;
            class OutputStream;
        }
      }
      namespace CosNaming
      {
        namespace NamingContextPackage
        {
            class NotFoundReason;
            class NotFoundReasonHolder;
        }
      }
    }
  }
}

class org::omg::CosNaming::NamingContextPackage::NotFoundReasonHolder : public ::java::lang::Object
{

public:
  NotFoundReasonHolder();
  NotFoundReasonHolder(::org::omg::CosNaming::NamingContextPackage::NotFoundReason *);
  void _read(::org::omg::CORBA::portable::InputStream *);
  ::org::omg::CORBA::TypeCode * _type();
  void _write(::org::omg::CORBA::portable::OutputStream *);
  ::org::omg::CosNaming::NamingContextPackage::NotFoundReason * __attribute__((aligned(__alignof__( ::java::lang::Object)))) value;
  static ::java::lang::Class class$;
};

#endif // __org_omg_CosNaming_NamingContextPackage_NotFoundReasonHolder__
