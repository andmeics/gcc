
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_imageio_png_PNGData__
#define __gnu_javax_imageio_png_PNGData__

#pragma interface

#include <gnu/javax/imageio/png/PNGChunk.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace imageio
      {
        namespace png
        {
            class PNGData;
        }
      }
    }
  }
}

class gnu::javax::imageio::png::PNGData : public ::gnu::javax::imageio::png::PNGChunk
{

public: // actually protected
  PNGData(jint, JArray< jbyte > *, jint);
  PNGData(jint);
public:
  virtual void deflateToChunk(::java::util::zip::Deflater *);
  virtual jboolean chunkFull();
  virtual void shrink();
  virtual void feedToInflater(::java::util::zip::Inflater *);
  virtual ::java::lang::String * toString();
private:
  jint __attribute__((aligned(__alignof__( ::gnu::javax::imageio::png::PNGChunk)))) offset;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_imageio_png_PNGData__
