
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_crypto_Mac__
#define __javax_crypto_Mac__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace nio
    {
        class ByteBuffer;
    }
    namespace security
    {
        class Key;
        class Provider;
      namespace spec
      {
          class AlgorithmParameterSpec;
      }
    }
  }
  namespace javax
  {
    namespace crypto
    {
        class Mac;
        class MacSpi;
    }
  }
}

class javax::crypto::Mac : public ::java::lang::Object
{

public: // actually protected
  Mac(::javax::crypto::MacSpi *, ::java::security::Provider *, ::java::lang::String *);
public:
  static ::javax::crypto::Mac * getInstance(::java::lang::String *);
  static ::javax::crypto::Mac * getInstance(::java::lang::String *, ::java::lang::String *);
  static ::javax::crypto::Mac * getInstance(::java::lang::String *, ::java::security::Provider *);
  virtual JArray< jbyte > * doFinal();
  virtual JArray< jbyte > * doFinal(JArray< jbyte > *);
  virtual void doFinal(JArray< jbyte > *, jint);
  virtual ::java::lang::String * getAlgorithm();
  virtual jint getMacLength();
  virtual ::java::security::Provider * getProvider();
  virtual void init(::java::security::Key *);
  virtual void init(::java::security::Key *, ::java::security::spec::AlgorithmParameterSpec *);
  virtual void reset();
  virtual void update(jbyte);
  virtual void update(JArray< jbyte > *);
  virtual void update(JArray< jbyte > *, jint, jint);
  virtual void update(::java::nio::ByteBuffer *);
  virtual ::java::lang::Object * clone();
private:
  static ::java::lang::String * SERVICE;
  ::javax::crypto::MacSpi * __attribute__((aligned(__alignof__( ::java::lang::Object)))) macSpi;
  ::java::security::Provider * provider;
  ::java::lang::String * algorithm;
  jboolean virgin;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_crypto_Mac__
