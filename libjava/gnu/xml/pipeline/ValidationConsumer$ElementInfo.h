
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_xml_pipeline_ValidationConsumer$ElementInfo__
#define __gnu_xml_pipeline_ValidationConsumer$ElementInfo__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace xml
    {
      namespace pipeline
      {
          class ValidationConsumer;
          class ValidationConsumer$ElementInfo;
          class ValidationConsumer$Recognizer;
      }
    }
  }
}

class gnu::xml::pipeline::ValidationConsumer$ElementInfo : public ::java::lang::Object
{

public: // actually package-private
  ValidationConsumer$ElementInfo(::java::lang::String *);
  ::gnu::xml::pipeline::ValidationConsumer$Recognizer * getRecognizer(::gnu::xml::pipeline::ValidationConsumer *);
  ::java::lang::String * __attribute__((aligned(__alignof__( ::java::lang::Object)))) name;
  ::java::lang::String * model;
  ::java::util::Hashtable * attributes;
private:
  ::gnu::xml::pipeline::ValidationConsumer$Recognizer * recognizer;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_xml_pipeline_ValidationConsumer$ElementInfo__
