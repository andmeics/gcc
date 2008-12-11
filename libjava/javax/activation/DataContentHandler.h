
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_activation_DataContentHandler__
#define __javax_activation_DataContentHandler__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace datatransfer
      {
          class DataFlavor;
      }
    }
  }
  namespace javax
  {
    namespace activation
    {
        class DataContentHandler;
        class DataSource;
    }
  }
}

class javax::activation::DataContentHandler : public ::java::lang::Object
{

public:
  virtual JArray< ::java::awt::datatransfer::DataFlavor * > * getTransferDataFlavors() = 0;
  virtual ::java::lang::Object * getTransferData(::java::awt::datatransfer::DataFlavor *, ::javax::activation::DataSource *) = 0;
  virtual ::java::lang::Object * getContent(::javax::activation::DataSource *) = 0;
  virtual void writeTo(::java::lang::Object *, ::java::lang::String *, ::java::io::OutputStream *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __javax_activation_DataContentHandler__
