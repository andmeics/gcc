
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_print_ipp_IppPrintService__
#define __gnu_javax_print_ipp_IppPrintService__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace print
      {
        namespace ipp
        {
            class IppPrintService;
            class IppResponse;
        }
      }
    }
  }
  namespace java
  {
    namespace net
    {
        class URI;
    }
  }
  namespace javax
  {
    namespace print
    {
        class DocFlavor;
        class DocPrintJob;
        class ServiceUIFactory;
      namespace attribute
      {
          class Attribute;
          class AttributeSet;
          class PrintServiceAttribute;
          class PrintServiceAttributeSet;
        namespace standard
        {
            class JobName;
            class PrinterURI;
            class RequestingUserName;
        }
      }
      namespace event
      {
          class PrintServiceAttributeListener;
      }
    }
  }
}

class gnu::javax::print::ipp::IppPrintService : public ::java::lang::Object
{

public:
  IppPrintService(::java::net::URI *, ::java::lang::String *, ::java::lang::String *);
private:
  ::java::util::Map * getPrinterAttributes();
  ::java::util::Set * getPrinterAttributeSet(::java::lang::Class *);
  ::javax::print::attribute::Attribute * getPrinterDefaultAttribute(::java::lang::Class *);
  void processResponse();
public:
  virtual ::javax::print::DocPrintJob * createPrintJob();
  virtual ::javax::print::attribute::PrintServiceAttribute * getAttribute(::java::lang::Class *);
  virtual ::javax::print::attribute::PrintServiceAttributeSet * getAttributes();
  virtual ::java::lang::Object * getDefaultAttributeValue(::java::lang::Class *);
  virtual ::java::lang::String * getName();
  virtual ::javax::print::ServiceUIFactory * getServiceUIFactory();
  virtual JArray< ::java::lang::Class * > * getSupportedAttributeCategories();
  virtual ::java::lang::Object * getSupportedAttributeValues(::java::lang::Class *, ::javax::print::DocFlavor *, ::javax::print::attribute::AttributeSet *);
public: // actually protected
  virtual ::java::lang::Object * handleSupportedAttributeValuesResponse(::gnu::javax::print::ipp::IppResponse *, ::java::lang::Class *);
public:
  virtual JArray< ::javax::print::DocFlavor * > * getSupportedDocFlavors();
  virtual ::javax::print::attribute::AttributeSet * getUnsupportedAttributes(::javax::print::DocFlavor *, ::javax::print::attribute::AttributeSet *);
  virtual jboolean isAttributeCategorySupported(::java::lang::Class *);
  virtual jboolean isAttributeValueSupported(::javax::print::attribute::Attribute *, ::javax::print::DocFlavor *, ::javax::print::attribute::AttributeSet *);
  virtual jboolean isDocFlavorSupported(::javax::print::DocFlavor *);
  virtual void addPrintServiceAttributeListener(::javax::print::event::PrintServiceAttributeListener *);
  virtual void removePrintServiceAttributeListener(::javax::print::event::PrintServiceAttributeListener *);
  virtual ::java::lang::String * toString();
  virtual ::javax::print::attribute::standard::PrinterURI * getPrinterURI();
private:
  ::java::util::Map * __attribute__((aligned(__alignof__( ::java::lang::Object)))) printerAttr;
  ::java::util::HashSet * printServiceAttributeListener;
  ::java::lang::String * user;
  ::java::lang::String * passwd;
  ::java::lang::String * name;
  ::java::util::List * flavors;
  ::javax::print::attribute::standard::PrinterURI * printerUri;
  ::java::util::ArrayList * printerUris;
public: // actually package-private
  static ::java::util::logging::Logger * logger;
public:
  static ::javax::print::attribute::standard::RequestingUserName * REQUESTING_USER_NAME;
  static ::javax::print::attribute::standard::JobName * JOB_NAME;
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_print_ipp_IppPrintService__
