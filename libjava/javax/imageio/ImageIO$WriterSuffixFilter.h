
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_imageio_ImageIO$WriterSuffixFilter__
#define __javax_imageio_ImageIO$WriterSuffixFilter__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace imageio
    {
        class ImageIO$WriterSuffixFilter;
    }
  }
}

class javax::imageio::ImageIO$WriterSuffixFilter : public ::java::lang::Object
{

public:
  ImageIO$WriterSuffixFilter(::java::lang::String *);
  jboolean filter(::java::lang::Object *);
private:
  ::java::lang::String * __attribute__((aligned(__alignof__( ::java::lang::Object)))) fileSuffix;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_imageio_ImageIO$WriterSuffixFilter__
