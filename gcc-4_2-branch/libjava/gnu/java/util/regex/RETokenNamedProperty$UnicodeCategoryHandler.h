
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_util_regex_RETokenNamedProperty$UnicodeCategoryHandler__
#define __gnu_java_util_regex_RETokenNamedProperty$UnicodeCategoryHandler__

#pragma interface

#include <gnu/java/util/regex/RETokenNamedProperty$Handler.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace util
      {
        namespace regex
        {
            class RETokenNamedProperty$UnicodeCategoryHandler;
        }
      }
    }
  }
}

class gnu::java::util::regex::RETokenNamedProperty$UnicodeCategoryHandler : public ::gnu::java::util::regex::RETokenNamedProperty$Handler
{

public:
  RETokenNamedProperty$UnicodeCategoryHandler(jbyte);
  virtual jboolean includes(jchar);
private:
  jint __attribute__((aligned(__alignof__( ::gnu::java::util::regex::RETokenNamedProperty$Handler)))) category;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_util_regex_RETokenNamedProperty$UnicodeCategoryHandler__
