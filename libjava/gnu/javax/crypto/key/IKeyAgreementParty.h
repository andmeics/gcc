
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_crypto_key_IKeyAgreementParty__
#define __gnu_javax_crypto_key_IKeyAgreementParty__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace crypto
      {
        namespace key
        {
            class IKeyAgreementParty;
            class IncomingMessage;
            class OutgoingMessage;
        }
      }
    }
  }
}

class gnu::javax::crypto::key::IKeyAgreementParty : public ::java::lang::Object
{

public:
  virtual ::java::lang::String * name() = 0;
  virtual void init(::java::util::Map *) = 0;
  virtual ::gnu::javax::crypto::key::OutgoingMessage * processMessage(::gnu::javax::crypto::key::IncomingMessage *) = 0;
  virtual jboolean isComplete() = 0;
  virtual JArray< jbyte > * getSharedSecret() = 0;
  virtual void reset() = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __gnu_javax_crypto_key_IKeyAgreementParty__
