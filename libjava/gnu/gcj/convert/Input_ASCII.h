
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_gcj_convert_Input_ASCII__
#define __gnu_gcj_convert_Input_ASCII__

#pragma interface

#include <gnu/gcj/convert/BytesToUnicode.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace gcj
    {
      namespace convert
      {
          class Input_ASCII;
      }
    }
  }
}

class gnu::gcj::convert::Input_ASCII : public ::gnu::gcj::convert::BytesToUnicode
{

public:
  Input_ASCII();
  virtual ::java::lang::String * getName();
  virtual jint read(JArray< jchar > *, jint, jint);
  static ::java::lang::Class class$;
};

#endif // __gnu_gcj_convert_Input_ASCII__
