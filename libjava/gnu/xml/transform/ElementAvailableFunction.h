
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_xml_transform_ElementAvailableFunction__
#define __gnu_xml_transform_ElementAvailableFunction__

#pragma interface

#include <gnu/xml/xpath/Expr.h>
extern "Java"
{
  namespace gnu
  {
    namespace xml
    {
      namespace transform
      {
          class ElementAvailableFunction;
      }
      namespace xpath
      {
          class Expr;
      }
    }
  }
  namespace javax
  {
    namespace xml
    {
      namespace namespace
      {
          class NamespaceContext;
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

class gnu::xml::transform::ElementAvailableFunction : public ::gnu::xml::xpath::Expr
{

public: // actually package-private
  ElementAvailableFunction(::javax::xml::namespace::NamespaceContext *);
public:
  virtual ::java::lang::Object * evaluate(::java::util::List *);
  virtual void setArguments(::java::util::List *);
  virtual ::java::lang::Object * evaluate(::org::w3c::dom::Node *, jint, jint);
  virtual ::gnu::xml::xpath::Expr * clone(::java::lang::Object *);
  virtual jboolean references(::javax::xml::namespace::QName *);
  virtual ::java::lang::String * toString();
public: // actually package-private
  static ::java::util::Collection * elements;
  ::javax::xml::namespace::NamespaceContext * __attribute__((aligned(__alignof__( ::gnu::xml::xpath::Expr)))) nsctx;
  ::java::util::List * args;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_xml_transform_ElementAvailableFunction__
