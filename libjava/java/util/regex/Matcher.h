
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_regex_Matcher__
#define __java_util_regex_Matcher__

#pragma interface

#include <java/lang/Object.h>
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
            class CharIndexed;
            class REMatch;
        }
      }
    }
  }
}

class java::util::regex::Matcher : public ::java::lang::Object
{

public: // actually package-private
  Matcher(::java::util::regex::Pattern *, ::java::lang::CharSequence *);
public:
  ::java::util::regex::Matcher * appendReplacement(::java::lang::StringBuffer *, ::java::lang::String *);
  ::java::lang::StringBuffer * appendTail(::java::lang::StringBuffer *);
  jint end();
  jint end(jint);
  jboolean find();
  jboolean find(jint);
  ::java::lang::String * group();
  ::java::lang::String * group(jint);
  ::java::lang::String * replaceFirst(::java::lang::String *);
  ::java::lang::String * replaceAll(::java::lang::String *);
  jint groupCount();
  jboolean lookingAt();
  jboolean matches();
  ::java::util::regex::Pattern * pattern();
  ::java::util::regex::Matcher * reset();
  ::java::util::regex::Matcher * reset(::java::lang::CharSequence *);
  jint start();
  jint start(jint);
  jboolean hitEnd();
  ::java::lang::String * toString();
private:
  void assertMatchOp();
  ::java::util::regex::Pattern * __attribute__((aligned(__alignof__( ::java::lang::Object)))) pattern__;
  ::java::lang::CharSequence * input;
  ::gnu::java::util::regex::CharIndexed * inputCharIndexed;
  jint position;
  jint appendPosition;
  ::gnu::java::util::regex::REMatch * match;
public:
  static ::java::lang::Class class$;
};

#endif // __java_util_regex_Matcher__
