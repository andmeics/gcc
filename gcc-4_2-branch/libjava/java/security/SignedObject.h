
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_security_SignedObject__
#define __java_security_SignedObject__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace security
    {
        class PrivateKey;
        class PublicKey;
        class Signature;
        class SignedObject;
    }
  }
}

class java::security::SignedObject : public ::java::lang::Object
{

public:
  SignedObject(::java::io::Serializable *, ::java::security::PrivateKey *, ::java::security::Signature *);
  ::java::lang::Object * getObject();
  JArray< jbyte > * getSignature();
  ::java::lang::String * getAlgorithm();
  jboolean verify(::java::security::PublicKey *, ::java::security::Signature *);
private:
  void readObject(::java::io::ObjectInputStream *);
  static const jlong serialVersionUID = 720502720485447167LL;
  JArray< jbyte > * __attribute__((aligned(__alignof__( ::java::lang::Object)))) content;
  JArray< jbyte > * signature;
  ::java::lang::String * thealgorithm;
public:
  static ::java::lang::Class class$;
};

#endif // __java_security_SignedObject__
