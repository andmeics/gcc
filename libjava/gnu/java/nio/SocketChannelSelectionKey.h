
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_nio_SocketChannelSelectionKey__
#define __gnu_java_nio_SocketChannelSelectionKey__

#pragma interface

#include <gnu/java/nio/SelectionKeyImpl.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace nio
      {
          class SelectorImpl;
          class SocketChannelSelectionKey;
      }
    }
  }
  namespace java
  {
    namespace nio
    {
      namespace channels
      {
        namespace spi
        {
            class AbstractSelectableChannel;
        }
      }
    }
  }
}

class gnu::java::nio::SocketChannelSelectionKey : public ::gnu::java::nio::SelectionKeyImpl
{

public:
  SocketChannelSelectionKey(::java::nio::channels::spi::AbstractSelectableChannel *, ::gnu::java::nio::SelectorImpl *);
  jint getNativeFD();
  static ::java::lang::Class class$;
};

#endif // __gnu_java_nio_SocketChannelSelectionKey__
