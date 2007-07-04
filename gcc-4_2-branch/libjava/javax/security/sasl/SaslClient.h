
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_security_sasl_SaslClient__
#define __javax_security_sasl_SaslClient__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace javax
  {
    namespace security
    {
      namespace sasl
      {
          class SaslClient;
      }
    }
  }
}

class javax::security::sasl::SaslClient : public ::java::lang::Object
{

public:
  virtual ::java::lang::String * getMechanismName() = 0;
  virtual jboolean hasInitialResponse() = 0;
  virtual JArray< jbyte > * evaluateChallenge(JArray< jbyte > *) = 0;
  virtual jboolean isComplete() = 0;
  virtual JArray< jbyte > * unwrap(JArray< jbyte > *, jint, jint) = 0;
  virtual JArray< jbyte > * wrap(JArray< jbyte > *, jint, jint) = 0;
  virtual ::java::lang::Object * getNegotiatedProperty(::java::lang::String *) = 0;
  virtual void dispose() = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __javax_security_sasl_SaslClient__
