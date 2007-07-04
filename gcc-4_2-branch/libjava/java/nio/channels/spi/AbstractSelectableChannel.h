
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_nio_channels_spi_AbstractSelectableChannel__
#define __java_nio_channels_spi_AbstractSelectableChannel__

#pragma interface

#include <java/nio/channels/SelectableChannel.h>
extern "Java"
{
  namespace java
  {
    namespace nio
    {
      namespace channels
      {
          class SelectableChannel;
          class SelectionKey;
          class Selector;
        namespace spi
        {
            class AbstractSelectableChannel;
            class SelectorProvider;
        }
      }
    }
  }
}

class java::nio::channels::spi::AbstractSelectableChannel : public ::java::nio::channels::SelectableChannel
{

public: // actually protected
  AbstractSelectableChannel(::java::nio::channels::spi::SelectorProvider *);
public:
  virtual ::java::lang::Object * blockingLock();
  virtual ::java::nio::channels::SelectableChannel * configureBlocking(jboolean);
public: // actually protected
  virtual void implCloseChannel();
  virtual void implCloseSelectableChannel() = 0;
  virtual void implConfigureBlocking(jboolean) = 0;
public:
  virtual jboolean isBlocking();
  virtual jboolean isRegistered();
  virtual ::java::nio::channels::SelectionKey * keyFor(::java::nio::channels::Selector *);
  virtual ::java::nio::channels::spi::SelectorProvider * provider();
private:
  ::java::nio::channels::SelectionKey * locate(::java::nio::channels::Selector *);
public:
  virtual ::java::nio::channels::SelectionKey * register$(::java::nio::channels::Selector *, jint, ::java::lang::Object *);
public: // actually package-private
  virtual void addSelectionKey(::java::nio::channels::SelectionKey *);
  virtual void removeSelectionKey(::java::nio::channels::SelectionKey *);
private:
  jboolean __attribute__((aligned(__alignof__( ::java::nio::channels::SelectableChannel)))) blocking;
  ::java::lang::Object * LOCK;
  ::java::nio::channels::spi::SelectorProvider * provider__;
  ::java::util::LinkedList * keys;
public:
  static ::java::lang::Class class$;
};

#endif // __java_nio_channels_spi_AbstractSelectableChannel__
