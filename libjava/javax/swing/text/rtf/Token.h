
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_text_rtf_Token__
#define __javax_swing_text_rtf_Token__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace swing
    {
      namespace text
      {
        namespace rtf
        {
            class Token;
        }
      }
    }
  }
}

class javax::swing::text::rtf::Token : public ::java::lang::Object
{

public:
  Token(jint);
  static const jint EOF = -1;
  static const jint LCURLY = 1;
  static const jint RCURLY = 2;
  static const jint CONTROL_WORD = 3;
  static const jint TEXT = 4;
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) type;
  static ::java::lang::Class class$;
};

#endif // __javax_swing_text_rtf_Token__
