
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_font_autofit_AxisHints__
#define __gnu_java_awt_font_autofit_AxisHints__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        namespace font
        {
          namespace autofit
          {
              class AxisHints;
              class Segment;
          }
        }
      }
    }
  }
}

class gnu::java::awt::font::autofit::AxisHints : public ::java::lang::Object
{

public: // actually package-private
  AxisHints();
  JArray< ::gnu::java::awt::font::autofit::Segment * > * __attribute__((aligned(__alignof__( ::java::lang::Object)))) segments;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_font_autofit_AxisHints__
