
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_xml_datatype_Duration__
#define __javax_xml_datatype_Duration__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace math
    {
        class BigDecimal;
    }
  }
  namespace javax
  {
    namespace xml
    {
      namespace datatype
      {
          class DatatypeConstants$Field;
          class Duration;
      }
      namespace namespace$
      {
          class QName;
      }
    }
  }
}

class javax::xml::datatype::Duration : public ::java::lang::Object
{

public:
  Duration();
  virtual ::javax::xml::namespace$::QName * getXMLSchemaType();
  virtual jint getSign() = 0;
  virtual jint getYears();
  virtual jint getMonths();
  virtual jint getDays();
  virtual jint getHours();
  virtual jint getMinutes();
  virtual jint getSeconds();
  virtual jlong getTimeInMillis(::java::util::Calendar *);
  virtual jlong getTimeInMillis(::java::util::Date *);
  virtual ::java::lang::Number * getField(::javax::xml::datatype::DatatypeConstants$Field *) = 0;
  virtual jboolean isSet(::javax::xml::datatype::DatatypeConstants$Field *) = 0;
  virtual ::javax::xml::datatype::Duration * add(::javax::xml::datatype::Duration *) = 0;
  virtual void addTo(::java::util::Calendar *) = 0;
  virtual void addTo(::java::util::Date *);
  virtual ::javax::xml::datatype::Duration * subtract(::javax::xml::datatype::Duration *);
  virtual ::javax::xml::datatype::Duration * multiply(jint);
  virtual ::javax::xml::datatype::Duration * multiply(::java::math::BigDecimal *) = 0;
  virtual ::javax::xml::datatype::Duration * negate() = 0;
  virtual ::javax::xml::datatype::Duration * normalizeWith(::java::util::Calendar *) = 0;
  virtual jint compare(::javax::xml::datatype::Duration *) = 0;
  virtual jboolean isLongerThan(::javax::xml::datatype::Duration *);
  virtual jboolean isShorterThan(::javax::xml::datatype::Duration *);
  virtual jboolean equals(::java::lang::Object *);
  virtual jint hashCode() = 0;
  virtual ::java::lang::String * toString();
  static ::java::lang::Class class$;
};

#endif // __javax_xml_datatype_Duration__
