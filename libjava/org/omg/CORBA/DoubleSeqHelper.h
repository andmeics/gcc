
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_omg_CORBA_DoubleSeqHelper__
#define __org_omg_CORBA_DoubleSeqHelper__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace org
  {
    namespace omg
    {
      namespace CORBA
      {
          class Any;
          class DoubleSeqHelper;
          class TypeCode;
        namespace portable
        {
            class InputStream;
            class OutputStream;
        }
      }
    }
  }
}

class org::omg::CORBA::DoubleSeqHelper : public ::java::lang::Object
{

public:
  DoubleSeqHelper();
  static JArray< jdouble > * extract(::org::omg::CORBA::Any *);
  static ::java::lang::String * id();
  static void insert(::org::omg::CORBA::Any *, JArray< jdouble > *);
  static JArray< jdouble > * read(::org::omg::CORBA::portable::InputStream *);
  static ::org::omg::CORBA::TypeCode * type();
  static void write(::org::omg::CORBA::portable::OutputStream *, JArray< jdouble > *);
  static ::java::lang::Class class$;
};

#endif // __org_omg_CORBA_DoubleSeqHelper__
