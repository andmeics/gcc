
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_swing_text_html_css_CSSParserCallback__
#define __gnu_javax_swing_text_html_css_CSSParserCallback__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace swing
      {
        namespace text
        {
          namespace html
          {
            namespace css
            {
                class CSSParserCallback;
                class Selector;
            }
          }
        }
      }
    }
  }
}

class gnu::javax::swing::text::html::css::CSSParserCallback : public ::java::lang::Object
{

public:
  virtual void startStatement(JArray< ::gnu::javax::swing::text::html::css::Selector * > *) = 0;
  virtual void endStatement() = 0;
  virtual void declaration(::java::lang::String *, ::java::lang::String *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __gnu_javax_swing_text_html_css_CSSParserCallback__
