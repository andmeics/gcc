
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_classpath_jdwp_JdwpConstants$CommandSet$ObjectReference__
#define __gnu_classpath_jdwp_JdwpConstants$CommandSet$ObjectReference__

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
          class JdwpConstants$CommandSet$ObjectReference;
      }
    }
  }
}

class gnu::classpath::jdwp::JdwpConstants$CommandSet$ObjectReference : public ::java::lang::Object
{

public:
  JdwpConstants$CommandSet$ObjectReference();
  static const jbyte CS_VALUE = 9;
  static const jbyte REFERENCE_TYPE = 1;
  static const jbyte GET_VALUES = 2;
  static const jbyte SET_VALUES = 3;
  static const jbyte MONITOR_INFO = 5;
  static const jbyte INVOKE_METHOD = 6;
  static const jbyte DISABLE_COLLECTION = 7;
  static const jbyte ENABLE_COLLECTION = 8;
  static const jbyte IS_COLLECTED = 9;
  static ::java::lang::Class class$;
};

#endif // __gnu_classpath_jdwp_JdwpConstants$CommandSet$ObjectReference__
