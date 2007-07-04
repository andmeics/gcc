
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_classpath_jdwp_util_Value__
#define __gnu_classpath_jdwp_util_Value__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace classpath
    {
      namespace jdwp
      {
        namespace util
        {
            class Value;
        }
      }
    }
  }
  namespace java
  {
    namespace nio
    {
        class ByteBuffer;
    }
  }
}

class gnu::classpath::jdwp::util::Value : public ::java::lang::Object
{

public:
  Value();
  static void writeUntaggedValue(::java::io::DataOutputStream *, ::java::lang::Object *);
  static void writeTaggedValue(::java::io::DataOutputStream *, ::java::lang::Object *);
private:
  static void writeValue(::java::io::DataOutputStream *, ::java::lang::Object *, jboolean);
public:
  static ::java::lang::Object * getObj(::java::nio::ByteBuffer *);
  static ::java::lang::Object * getUntaggedObj(::java::nio::ByteBuffer *, ::java::lang::Class *);
  static ::java::lang::Object * getUntaggedObj(::java::nio::ByteBuffer *, jbyte);
  static ::java::lang::Class class$;
};

#endif // __gnu_classpath_jdwp_util_Value__
