
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_net_SocketImpl__
#define __java_net_SocketImpl__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace net
    {
        class InetAddress;
        class SocketAddress;
        class SocketImpl;
    }
  }
}

class java::net::SocketImpl : public ::java::lang::Object
{

public:
  SocketImpl();
public: // actually protected
  virtual void create(jboolean) = 0;
  virtual void connect(::java::lang::String *, jint) = 0;
  virtual void connect(::java::net::InetAddress *, jint) = 0;
  virtual void connect(::java::net::SocketAddress *, jint) = 0;
  virtual void bind(::java::net::InetAddress *, jint) = 0;
  virtual void listen(jint) = 0;
  virtual void accept(::java::net::SocketImpl *) = 0;
  virtual ::java::io::InputStream * getInputStream() = 0;
  virtual ::java::io::OutputStream * getOutputStream() = 0;
  virtual jint available() = 0;
  virtual void close() = 0;
  virtual ::java::io::FileDescriptor * getFileDescriptor();
  virtual ::java::net::InetAddress * getInetAddress();
  virtual jint getPort();
  virtual jboolean supportsUrgentData();
  virtual void sendUrgentData(jint) = 0;
  virtual jint getLocalPort();
public:
  virtual ::java::lang::String * toString();
public: // actually protected
  virtual void shutdownInput();
  virtual void shutdownOutput();
public:
  virtual void setOption(jint, ::java::lang::Object *) = 0;
  virtual ::java::lang::Object * getOption(jint) = 0;
public: // actually protected
  ::java::net::InetAddress * __attribute__((aligned(__alignof__( ::java::lang::Object)))) address;
  ::java::io::FileDescriptor * fd;
  jint localport;
  jint port;
public:
  static ::java::lang::Class class$;
};

#endif // __java_net_SocketImpl__
