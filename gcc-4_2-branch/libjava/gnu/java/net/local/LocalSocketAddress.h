
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_net_local_LocalSocketAddress__
#define __gnu_java_net_local_LocalSocketAddress__

#pragma interface

#include <java/net/SocketAddress.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace net
      {
        namespace local
        {
            class LocalSocketAddress;
        }
      }
    }
  }
}

class gnu::java::net::local::LocalSocketAddress : public ::java::net::SocketAddress
{

public:
  LocalSocketAddress(::java::lang::String *);
  ::java::lang::String * getPath();
  jboolean equals(::java::lang::Object *);
  jint hashCode();
  ::java::lang::String * toString();
private:
  ::java::lang::String * __attribute__((aligned(__alignof__( ::java::net::SocketAddress)))) path;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_net_local_LocalSocketAddress__
