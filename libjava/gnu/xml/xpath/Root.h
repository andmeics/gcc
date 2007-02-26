
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_xml_xpath_Root__
#define __gnu_xml_xpath_Root__

#pragma interface

#include <gnu/xml/xpath/Path.h>
extern "Java"
{
  namespace gnu
  {
    namespace xml
    {
      namespace xpath
      {
          class Expr;
          class Root;
      }
    }
  }
  namespace javax
  {
    namespace xml
    {
      namespace namespace
      {
          class QName;
      }
    }
  }
  namespace org
  {
    namespace w3c
    {
      namespace dom
      {
          class Node;
      }
    }
  }
}

class gnu::xml::xpath::Root : public ::gnu::xml::xpath::Path
{

public:
  Root();
  jboolean matches(::org::w3c::dom::Node *);
  ::java::lang::Object * evaluate(::org::w3c::dom::Node *, jint, jint);
public: // actually package-private
  ::java::util::Collection * evaluate(::org::w3c::dom::Node *, ::java::util::Collection *);
public:
  ::gnu::xml::xpath::Expr * clone(::java::lang::Object *);
  jboolean references(::javax::xml::namespace::QName *);
  ::java::lang::String * toString();
  static ::java::lang::Class class$;
};

#endif // __gnu_xml_xpath_Root__
