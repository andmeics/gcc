
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_xml_transform_URIResolverEntityResolver__
#define __gnu_xml_transform_URIResolverEntityResolver__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace xml
    {
      namespace transform
      {
          class URIResolverEntityResolver;
      }
    }
  }
  namespace javax
  {
    namespace xml
    {
      namespace transform
      {
          class URIResolver;
      }
    }
  }
  namespace org
  {
    namespace xml
    {
      namespace sax
      {
          class InputSource;
      }
    }
  }
}

class gnu::xml::transform::URIResolverEntityResolver : public ::java::lang::Object
{

public: // actually package-private
  URIResolverEntityResolver(::javax::xml::transform::URIResolver *);
public:
  virtual ::org::xml::sax::InputSource * resolveEntity(::java::lang::String *, ::java::lang::String *);
public: // actually package-private
  ::javax::xml::transform::URIResolver * __attribute__((aligned(__alignof__( ::java::lang::Object)))) resolver;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_xml_transform_URIResolverEntityResolver__
