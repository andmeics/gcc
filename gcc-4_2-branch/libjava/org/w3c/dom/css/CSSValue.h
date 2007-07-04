
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_w3c_dom_css_CSSValue__
#define __org_w3c_dom_css_CSSValue__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace org
  {
    namespace w3c
    {
      namespace dom
      {
        namespace css
        {
            class CSSValue;
        }
      }
    }
  }
}

class org::w3c::dom::css::CSSValue : public ::java::lang::Object
{

public:
  virtual ::java::lang::String * getCssText() = 0;
  virtual void setCssText(::java::lang::String *) = 0;
  virtual jshort getCssValueType() = 0;
  static const jshort CSS_INHERIT = 0;
  static const jshort CSS_PRIMITIVE_VALUE = 1;
  static const jshort CSS_VALUE_LIST = 2;
  static const jshort CSS_CUSTOM = 3;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __org_w3c_dom_css_CSSValue__
