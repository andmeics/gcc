
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_security_prng_RandomEvent__
#define __gnu_java_security_prng_RandomEvent__

#pragma interface

#include <java/util/EventObject.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace security
      {
        namespace prng
        {
            class RandomEvent;
        }
      }
    }
  }
}

class gnu::java::security::prng::RandomEvent : public ::java::util::EventObject
{

public:
  RandomEvent(::java::lang::Object *, jbyte, jbyte, JArray< jbyte > *);
  virtual jbyte getSourceNumber();
  virtual jbyte getPoolNumber();
  virtual JArray< jbyte > * getData();
private:
  jbyte __attribute__((aligned(__alignof__( ::java::util::EventObject)))) sourceNumber;
  jbyte poolNumber;
  JArray< jbyte > * data;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_security_prng_RandomEvent__
