
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_xml_validation_xmlschema_XMLSchemaTypeInfoProvider__
#define __gnu_xml_validation_xmlschema_XMLSchemaTypeInfoProvider__

#pragma interface

#include <javax/xml/validation/TypeInfoProvider.h>
extern "Java"
{
  namespace gnu
  {
    namespace xml
    {
      namespace validation
      {
        namespace xmlschema
        {
            class XMLSchemaTypeInfoProvider;
            class XMLSchemaValidatorHandler;
        }
      }
    }
  }
  namespace org
  {
    namespace w3c
    {
      namespace dom
      {
          class TypeInfo;
      }
    }
  }
}

class gnu::xml::validation::xmlschema::XMLSchemaTypeInfoProvider : public ::javax::xml::validation::TypeInfoProvider
{

public: // actually package-private
  XMLSchemaTypeInfoProvider(::gnu::xml::validation::xmlschema::XMLSchemaValidatorHandler *);
public:
  ::org::w3c::dom::TypeInfo * getElementTypeInfo();
  ::org::w3c::dom::TypeInfo * getAttributeTypeInfo(jint);
  jboolean isIdAttribute(jint);
  jboolean isSpecified(jint);
public: // actually package-private
  ::gnu::xml::validation::xmlschema::XMLSchemaValidatorHandler * __attribute__((aligned(__alignof__( ::javax::xml::validation::TypeInfoProvider)))) handler;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_xml_validation_xmlschema_XMLSchemaTypeInfoProvider__
