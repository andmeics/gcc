
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_sound_midi_Synthesizer__
#define __javax_sound_midi_Synthesizer__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace javax
  {
    namespace sound
    {
      namespace midi
      {
          class Instrument;
          class MidiChannel;
          class MidiDevice$Info;
          class Patch;
          class Receiver;
          class Soundbank;
          class Synthesizer;
          class Transmitter;
          class VoiceStatus;
      }
    }
  }
}

class javax::sound::midi::Synthesizer : public ::java::lang::Object
{

public:
  virtual jint getMaxPolyphony() = 0;
  virtual jlong getLatency() = 0;
  virtual JArray< ::javax::sound::midi::MidiChannel * > * getChannels() = 0;
  virtual JArray< ::javax::sound::midi::VoiceStatus * > * getVoiceStatus() = 0;
  virtual jboolean isSoundbankSupported(::javax::sound::midi::Soundbank *) = 0;
  virtual jboolean loadInstrument(::javax::sound::midi::Instrument *) = 0;
  virtual void unloadInstrument(::javax::sound::midi::Instrument *) = 0;
  virtual jboolean remapInstrument(::javax::sound::midi::Instrument *, ::javax::sound::midi::Instrument *) = 0;
  virtual ::javax::sound::midi::Soundbank * getDefaultSoundbank() = 0;
  virtual JArray< ::javax::sound::midi::Instrument * > * getAvailableInstruments() = 0;
  virtual JArray< ::javax::sound::midi::Instrument * > * getLoadedInstruments() = 0;
  virtual jboolean loadAllInstruments(::javax::sound::midi::Soundbank *) = 0;
  virtual void unloadAllInstruments(::javax::sound::midi::Soundbank *) = 0;
  virtual jboolean loadInstruments(::javax::sound::midi::Soundbank *, JArray< ::javax::sound::midi::Patch * > *) = 0;
  virtual void unloadInstruments(::javax::sound::midi::Soundbank *, JArray< ::javax::sound::midi::Patch * > *) = 0;
  virtual ::javax::sound::midi::MidiDevice$Info * getDeviceInfo() = 0;
  virtual void open() = 0;
  virtual void close() = 0;
  virtual jboolean isOpen() = 0;
  virtual jlong getMicrosecondPosition() = 0;
  virtual jint getMaxReceivers() = 0;
  virtual jint getMaxTransmitters() = 0;
  virtual ::javax::sound::midi::Receiver * getReceiver() = 0;
  virtual ::javax::sound::midi::Transmitter * getTransmitter() = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __javax_sound_midi_Synthesizer__
