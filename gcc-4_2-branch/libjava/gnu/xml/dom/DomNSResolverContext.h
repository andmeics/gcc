
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_xml_dom_DomNSResolverContext__
#define __gnu_xml_dom_DomNSResolverContext__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace xml
    {
      namespace dom
      {
          class DomNSResolverContext;
      }
    }
  }
  namespace org
  {
    namespace w3c
    {
      namespace dom
      {
        namespace xpath
        {
            class XPathNSResolver;
        }
      }
    }
  }
}

class gnu::xml::dom::DomNSResolverContext : public ::java::lang::Object
{

public: // actually package-private
  DomNSResolverContext(::org::w3c::dom::xpath::XPathNSResolver *);
public:
  virtual ::java::lang::String * getNamespaceURI(::java::lang::String *);
  virtual ::java::lang::String * getPrefix(::java::lang::String *);
  virtual ::java::util::Iterator * getPrefixes(::java::lang::String *);
  virtual jboolean hasNext();
  virtual ::java::lang::Object * next();
  virtual void remove();
public: // actually package-private
  ::org::w3c::dom::xpath::XPathNSResolver * __attribute__((aligned(__alignof__( ::java::lang::Object)))) resolver;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_xml_dom_DomNSResolverContext__
