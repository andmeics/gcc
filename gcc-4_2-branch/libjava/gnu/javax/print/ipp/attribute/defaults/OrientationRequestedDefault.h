
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_print_ipp_attribute_defaults_OrientationRequestedDefault__
#define __gnu_javax_print_ipp_attribute_defaults_OrientationRequestedDefault__

#pragma interface

#include <javax/print/attribute/EnumSyntax.h>
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
          namespace attribute
          {
            namespace defaults
            {
                class OrientationRequestedDefault;
            }
          }
        }
      }
    }
  }
  namespace javax
  {
    namespace print
    {
      namespace attribute
      {
          class Attribute;
          class EnumSyntax;
      }
    }
  }
}

class gnu::javax::print::ipp::attribute::defaults::OrientationRequestedDefault : public ::javax::print::attribute::EnumSyntax
{

public: // actually protected
  OrientationRequestedDefault(jint);
public:
  ::java::lang::Class * getCategory();
  ::java::lang::String * getName();
public: // actually protected
  JArray< ::java::lang::String * > * getStringTable();
  JArray< ::javax::print::attribute::EnumSyntax * > * getEnumValueTable();
  jint getOffset();
public:
  ::javax::print::attribute::Attribute * getAssociatedAttribute();
  static ::gnu::javax::print::ipp::attribute::defaults::OrientationRequestedDefault * PORTRAIT;
  static ::gnu::javax::print::ipp::attribute::defaults::OrientationRequestedDefault * LANDSCAPE;
  static ::gnu::javax::print::ipp::attribute::defaults::OrientationRequestedDefault * REVERSE_LANDSCAPE;
  static ::gnu::javax::print::ipp::attribute::defaults::OrientationRequestedDefault * REVERSE_PORTRAIT;
private:
  static JArray< ::java::lang::String * > * stringTable;
  static JArray< ::gnu::javax::print::ipp::attribute::defaults::OrientationRequestedDefault * > * enumValueTable;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_print_ipp_attribute_defaults_OrientationRequestedDefault__
