
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_imageio_ImageIO$ImageReaderIterator__
#define __javax_imageio_ImageIO$ImageReaderIterator__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace imageio
    {
        class ImageIO$ImageReaderIterator;
        class ImageReader;
    }
  }
}

class javax::imageio::ImageIO$ImageReaderIterator : public ::java::lang::Object
{

public:
  ImageIO$ImageReaderIterator(::java::util::Iterator *, ::java::lang::Object *);
  ImageIO$ImageReaderIterator(::java::util::Iterator *);
  jboolean hasNext();
  ::javax::imageio::ImageReader * target$next();
  void remove();
  ::java::lang::Object * next();
public: // actually package-private
  ::java::util::Iterator * __attribute__((aligned(__alignof__( ::java::lang::Object)))) it;
  ::java::lang::Object * readerExtension;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_imageio_ImageIO$ImageReaderIterator__
