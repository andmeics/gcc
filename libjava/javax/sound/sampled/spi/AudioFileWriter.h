
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_sound_sampled_spi_AudioFileWriter__
#define __javax_sound_sampled_spi_AudioFileWriter__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace javax
  {
    namespace sound
    {
      namespace sampled
      {
          class AudioFileFormat$Type;
          class AudioInputStream;
        namespace spi
        {
            class AudioFileWriter;
        }
      }
    }
  }
}

class javax::sound::sampled::spi::AudioFileWriter : public ::java::lang::Object
{

public:
  AudioFileWriter();
  virtual JArray< ::javax::sound::sampled::AudioFileFormat$Type * > * getAudioFileTypes() = 0;
  virtual JArray< ::javax::sound::sampled::AudioFileFormat$Type * > * getAudioFileTypes(::javax::sound::sampled::AudioInputStream *) = 0;
  virtual jboolean isFileTypeSupported(::javax::sound::sampled::AudioFileFormat$Type *);
  virtual jboolean isFileTypeSupported(::javax::sound::sampled::AudioFileFormat$Type *, ::javax::sound::sampled::AudioInputStream *);
  virtual jint write(::javax::sound::sampled::AudioInputStream *, ::javax::sound::sampled::AudioFileFormat$Type *, ::java::io::File *) = 0;
  virtual jint write(::javax::sound::sampled::AudioInputStream *, ::javax::sound::sampled::AudioFileFormat$Type *, ::java::io::OutputStream *) = 0;
  static ::java::lang::Class class$;
};

#endif // __javax_sound_sampled_spi_AudioFileWriter__
