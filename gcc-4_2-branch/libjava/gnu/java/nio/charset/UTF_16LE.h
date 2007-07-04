
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_nio_charset_UTF_16LE__
#define __gnu_java_nio_charset_UTF_16LE__

#pragma interface

#include <java/nio/charset/Charset.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace nio
      {
        namespace charset
        {
            class UTF_16LE;
        }
      }
    }
  }
  namespace java
  {
    namespace nio
    {
      namespace charset
      {
          class Charset;
          class CharsetDecoder;
          class CharsetEncoder;
      }
    }
  }
}

class gnu::java::nio::charset::UTF_16LE : public ::java::nio::charset::Charset
{

public: // actually package-private
  UTF_16LE();
public:
  jboolean contains(::java::nio::charset::Charset *);
  ::java::nio::charset::CharsetDecoder * newDecoder();
  ::java::nio::charset::CharsetEncoder * newEncoder();
  static ::java::lang::Class class$;
};

#endif // __gnu_java_nio_charset_UTF_16LE__
