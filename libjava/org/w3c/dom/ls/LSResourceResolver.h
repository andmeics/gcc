
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_w3c_dom_ls_LSResourceResolver__
#define __org_w3c_dom_ls_LSResourceResolver__

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
        namespace ls
        {
            class LSInput;
            class LSResourceResolver;
        }
      }
    }
  }
}

class org::w3c::dom::ls::LSResourceResolver : public ::java::lang::Object
{

public:
  virtual ::org::w3c::dom::ls::LSInput * resolveResource(::java::lang::String *, ::java::lang::String *, ::java::lang::String *, ::java::lang::String *, ::java::lang::String *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __org_w3c_dom_ls_LSResourceResolver__
