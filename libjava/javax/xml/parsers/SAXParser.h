
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_xml_parsers_SAXParser__
#define __javax_xml_parsers_SAXParser__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace xml
    {
      namespace parsers
      {
          class SAXParser;
      }
      namespace validation
      {
          class Schema;
      }
    }
  }
  namespace org
  {
    namespace xml
    {
      namespace sax
      {
          class HandlerBase;
          class InputSource;
          class Parser;
          class XMLReader;
        namespace helpers
        {
            class DefaultHandler;
        }
      }
    }
  }
}

class javax::xml::parsers::SAXParser : public ::java::lang::Object
{

public: // actually protected
  SAXParser();
public:
  virtual void parse(::java::io::InputStream *, ::org::xml::sax::HandlerBase *);
  virtual void parse(::java::io::InputStream *, ::org::xml::sax::HandlerBase *, ::java::lang::String *);
  virtual void parse(::java::io::InputStream *, ::org::xml::sax::helpers::DefaultHandler *);
  virtual void parse(::java::io::InputStream *, ::org::xml::sax::helpers::DefaultHandler *, ::java::lang::String *);
  virtual void parse(::java::lang::String *, ::org::xml::sax::HandlerBase *);
  virtual void parse(::java::lang::String *, ::org::xml::sax::helpers::DefaultHandler *);
  virtual void parse(::java::io::File *, ::org::xml::sax::HandlerBase *);
  virtual void parse(::java::io::File *, ::org::xml::sax::helpers::DefaultHandler *);
  virtual void parse(::org::xml::sax::InputSource *, ::org::xml::sax::HandlerBase *);
  virtual void parse(::org::xml::sax::InputSource *, ::org::xml::sax::helpers::DefaultHandler *);
  virtual ::org::xml::sax::Parser * getParser() = 0;
  virtual ::org::xml::sax::XMLReader * getXMLReader() = 0;
  virtual jboolean isNamespaceAware() = 0;
  virtual jboolean isValidating() = 0;
  virtual void setProperty(::java::lang::String *, ::java::lang::Object *) = 0;
  virtual ::java::lang::Object * getProperty(::java::lang::String *) = 0;
  virtual void reset();
  virtual ::javax::xml::validation::Schema * getSchema();
  virtual jboolean isXIncludeAware();
  static ::java::lang::Class class$;
};

#endif // __javax_xml_parsers_SAXParser__
