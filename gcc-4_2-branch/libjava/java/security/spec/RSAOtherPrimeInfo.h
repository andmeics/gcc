
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_security_spec_RSAOtherPrimeInfo__
#define __java_security_spec_RSAOtherPrimeInfo__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace math
    {
        class BigInteger;
    }
    namespace security
    {
      namespace spec
      {
          class RSAOtherPrimeInfo;
      }
    }
  }
}

class java::security::spec::RSAOtherPrimeInfo : public ::java::lang::Object
{

public:
  RSAOtherPrimeInfo(::java::math::BigInteger *, ::java::math::BigInteger *, ::java::math::BigInteger *);
  virtual ::java::math::BigInteger * getPrime();
  virtual ::java::math::BigInteger * getExponent();
  virtual ::java::math::BigInteger * getCrtCoefficient();
private:
  ::java::math::BigInteger * __attribute__((aligned(__alignof__( ::java::lang::Object)))) prime;
  ::java::math::BigInteger * primeExponent;
  ::java::math::BigInteger * crtCoefficient;
public:
  static ::java::lang::Class class$;
};

#endif // __java_security_spec_RSAOtherPrimeInfo__
