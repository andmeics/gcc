
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_rmi_server_ObjID__
#define __java_rmi_server_ObjID__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace rmi
    {
      namespace server
      {
          class ObjID;
          class UID;
      }
    }
  }
}

class java::rmi::server::ObjID : public ::java::lang::Object
{

public:
  ObjID();
  ObjID(jint);
  void write(::java::io::ObjectOutput *);
  static ::java::rmi::server::ObjID * read(::java::io::ObjectInput *);
  jint hashCode();
  jboolean equals(::java::lang::Object *);
public: // actually package-private
  static jboolean eq(::java::lang::Object *, ::java::lang::Object *);
public:
  ::java::lang::String * toString();
public: // actually package-private
  static const jlong serialVersionUID = -6386392263968365220LL;
private:
  static jlong next;
  static ::java::lang::Object * lock;
public:
  static const jint REGISTRY_ID = 0;
  static const jint ACTIVATOR_ID = 1;
  static const jint DGC_ID = 2;
public: // actually package-private
  jlong __attribute__((aligned(__alignof__( ::java::lang::Object)))) objNum;
  ::java::rmi::server::UID * space;
public:
  static ::java::lang::Class class$;
};

#endif // __java_rmi_server_ObjID__
