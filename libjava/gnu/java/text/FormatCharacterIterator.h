
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_text_FormatCharacterIterator__
#define __gnu_java_text_FormatCharacterIterator__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace text
      {
          class FormatCharacterIterator;
      }
    }
  }
  namespace java
  {
    namespace text
    {
        class AttributedCharacterIterator;
        class AttributedCharacterIterator$Attribute;
    }
  }
}

class gnu::java::text::FormatCharacterIterator : public ::java::lang::Object
{

public:
  FormatCharacterIterator();
  FormatCharacterIterator(::java::lang::String *, JArray< jint > *, ::java::util::List *);
  virtual ::java::util::Set * getAllAttributeKeys();
  virtual ::java::util::Map * getAttributes();
  virtual ::java::lang::Object * getAttribute(::java::text::AttributedCharacterIterator$Attribute *);
  virtual jint getRunLimit(::java::util::Set *);
  virtual jint getRunLimit(::java::text::AttributedCharacterIterator$Attribute *);
  virtual jint getRunLimit();
  virtual jint getRunStart(::java::util::Set *);
  virtual jint getRunStart();
  virtual jint getRunStart(::java::text::AttributedCharacterIterator$Attribute *);
  virtual ::java::lang::Object * clone();
  virtual jchar current();
  virtual jchar first();
  virtual jint getBeginIndex();
  virtual jint getEndIndex();
  virtual jint getIndex();
  virtual jchar last();
  virtual jchar next();
  virtual jchar previous();
  virtual jchar setIndex(jint);
  virtual void mergeAttributes(::java::util::List *, JArray< jint > *);
  virtual void append(::java::text::AttributedCharacterIterator *);
  virtual void append(::java::lang::String *, ::java::util::HashMap *);
  virtual void append(::java::lang::String *);
  virtual void addAttributes(::java::util::Map *, jint, jint);
private:
  void debug(::java::lang::String *);
  void dumpTable();
  ::java::lang::String * __attribute__((aligned(__alignof__( ::java::lang::Object)))) formattedString;
  jint charIndex;
  jint attributeIndex;
  JArray< jint > * ranges;
  ::java::util::List * attributes;
  static const jboolean DEBUG = 0;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_text_FormatCharacterIterator__
