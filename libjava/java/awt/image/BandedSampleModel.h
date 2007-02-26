
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_image_BandedSampleModel__
#define __java_awt_image_BandedSampleModel__

#pragma interface

#include <java/awt/image/ComponentSampleModel.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace image
      {
          class BandedSampleModel;
          class DataBuffer;
          class SampleModel;
      }
    }
  }
}

class java::awt::image::BandedSampleModel : public ::java::awt::image::ComponentSampleModel
{

  static JArray< jint > * createBankArray(jint);
public:
  BandedSampleModel(jint, jint, jint, jint);
  BandedSampleModel(jint, jint, jint, jint, JArray< jint > *, JArray< jint > *);
  ::java::awt::image::DataBuffer * createDataBuffer();
  ::java::awt::image::SampleModel * createCompatibleSampleModel(jint, jint);
  ::java::awt::image::SampleModel * createSubsetSampleModel(JArray< jint > *);
  ::java::lang::Object * getDataElements(jint, jint, ::java::lang::Object *, ::java::awt::image::DataBuffer *);
  JArray< jint > * getPixel(jint, jint, JArray< jint > *, ::java::awt::image::DataBuffer *);
  JArray< jint > * getPixels(jint, jint, jint, jint, JArray< jint > *, ::java::awt::image::DataBuffer *);
  jint getSample(jint, jint, jint, ::java::awt::image::DataBuffer *);
  jfloat getSampleFloat(jint, jint, jint, ::java::awt::image::DataBuffer *);
  jdouble getSampleDouble(jint, jint, jint, ::java::awt::image::DataBuffer *);
  JArray< jint > * getSamples(jint, jint, jint, jint, jint, JArray< jint > *, ::java::awt::image::DataBuffer *);
  void setDataElements(jint, jint, ::java::lang::Object *, ::java::awt::image::DataBuffer *);
  void setPixel(jint, jint, JArray< jint > *, ::java::awt::image::DataBuffer *);
  void setPixels(jint, jint, jint, jint, JArray< jint > *, ::java::awt::image::DataBuffer *);
  void setSample(jint, jint, jint, jint, ::java::awt::image::DataBuffer *);
  void setSample(jint, jint, jint, jfloat, ::java::awt::image::DataBuffer *);
  void setSample(jint, jint, jint, jdouble, ::java::awt::image::DataBuffer *);
  void setSamples(jint, jint, jint, jint, jint, JArray< jint > *, ::java::awt::image::DataBuffer *);
  ::java::lang::String * toString();
private:
  JArray< jint > * __attribute__((aligned(__alignof__( ::java::awt::image::ComponentSampleModel)))) bitMasks;
  JArray< jint > * bitOffsets;
  JArray< jint > * sampleSize;
  jint dataBitOffset;
  jint elemBits;
  jint numberOfBits;
  jint numElems;
public:
  static ::java::lang::Class class$;
};

#endif // __java_awt_image_BandedSampleModel__
