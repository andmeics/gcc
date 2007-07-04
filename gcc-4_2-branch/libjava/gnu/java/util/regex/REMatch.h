
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_util_regex_REMatch__
#define __gnu_java_util_regex_REMatch__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

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
            class BacktrackStack;
            class CharIndexed;
            class REMatch;
        }
      }
    }
  }
}

class gnu::java::util::regex::REMatch : public ::java::lang::Object
{

public:
  ::java::lang::Object * clone();
public: // actually package-private
  void assignFrom(::gnu::java::util::regex::REMatch *);
  REMatch(jint, jint, jint);
  void finish(::gnu::java::util::regex::CharIndexed *);
  void clear(jint);
public:
  ::java::lang::String * toString();
  jint getStartIndex();
  jint getEndIndex();
  ::java::lang::String * toString(jint);
  jint getSubStartIndex(jint);
  jint getStartIndex(jint);
  jint getSubEndIndex(jint);
  jint getEndIndex(jint);
  ::java::lang::String * substituteInto(::java::lang::String *);
private:
  ::java::lang::String * __attribute__((aligned(__alignof__( ::java::lang::Object)))) matchedText;
  ::gnu::java::util::regex::CharIndexed * matchedCharIndexed;
public: // actually package-private
  jint eflags;
  jint offset;
  jint anchor;
  jint index;
  JArray< jint > * start;
  JArray< jint > * start1;
  JArray< jint > * end;
  jboolean empty;
  ::gnu::java::util::regex::BacktrackStack * backtrackStack;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_util_regex_REMatch__
