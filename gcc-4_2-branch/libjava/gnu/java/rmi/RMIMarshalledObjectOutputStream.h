
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_rmi_RMIMarshalledObjectOutputStream__
#define __gnu_java_rmi_RMIMarshalledObjectOutputStream__

#pragma interface

#include <gnu/java/rmi/server/RMIObjectOutputStream.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace rmi
      {
          class RMIMarshalledObjectOutputStream;
      }
    }
  }
}

class gnu::java::rmi::RMIMarshalledObjectOutputStream : public ::gnu::java::rmi::server::RMIObjectOutputStream
{

public:
  RMIMarshalledObjectOutputStream(::java::io::OutputStream *);
public: // actually protected
  virtual void setAnnotation(::java::lang::String *);
public:
  virtual void flush();
  virtual JArray< jbyte > * getLocBytes();
private:
  ::java::io::ObjectOutputStream * __attribute__((aligned(__alignof__( ::gnu::java::rmi::server::RMIObjectOutputStream)))) locStream;
  ::java::io::ByteArrayOutputStream * locBytesStream;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_rmi_RMIMarshalledObjectOutputStream__
