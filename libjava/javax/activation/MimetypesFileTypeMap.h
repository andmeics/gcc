
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_activation_MimetypesFileTypeMap__
#define __javax_activation_MimetypesFileTypeMap__

#pragma interface

#include <javax/activation/FileTypeMap.h>
#include <gcj/array.h>

extern "Java"
{
  namespace javax
  {
    namespace activation
    {
        class MimetypesFileTypeMap;
    }
  }
}

class javax::activation::MimetypesFileTypeMap : public ::javax::activation::FileTypeMap
{

public:
  MimetypesFileTypeMap();
  MimetypesFileTypeMap(::java::lang::String *);
  MimetypesFileTypeMap(::java::io::InputStream *);
private:
  void init(::java::io::Reader *);
public:
  virtual void addMimeTypes(::java::lang::String *);
  virtual ::java::lang::String * getContentType(::java::io::File *);
  virtual ::java::lang::String * getContentType(::java::lang::String *);
private:
  void parseFile(::java::util::Map *, ::java::lang::String *);
  void parseResource(::java::util::Map *, ::java::lang::String *);
  void parse(::java::util::Map *, ::java::io::Reader *);
  void parseEntry(::java::util::Map *, ::java::lang::String *);
  ::java::util::List * getSystemResources(::java::lang::String *);
  static const jint PROG = 0;
  static const jint HOME = 1;
  static const jint SYS = 2;
  static const jint JAR = 3;
  static const jint DEF = 4;
  static ::java::lang::String * DEFAULT_MIME_TYPE;
  static jboolean debug;
  JArray< ::java::util::Map * > * __attribute__((aligned(__alignof__( ::javax::activation::FileTypeMap)))) mimetypes;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_activation_MimetypesFileTypeMap__
