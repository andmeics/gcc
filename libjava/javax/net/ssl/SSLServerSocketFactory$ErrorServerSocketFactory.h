
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_net_ssl_SSLServerSocketFactory$ErrorServerSocketFactory__
#define __javax_net_ssl_SSLServerSocketFactory$ErrorServerSocketFactory__

#pragma interface

#include <javax/net/ssl/SSLServerSocketFactory.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace net
    {
        class InetAddress;
        class ServerSocket;
    }
  }
  namespace javax
  {
    namespace net
    {
      namespace ssl
      {
          class SSLServerSocketFactory$ErrorServerSocketFactory;
      }
    }
  }
}

class javax::net::ssl::SSLServerSocketFactory$ErrorServerSocketFactory : public ::javax::net::ssl::SSLServerSocketFactory
{

public: // actually package-private
  SSLServerSocketFactory$ErrorServerSocketFactory(::java::lang::RuntimeException *);
public:
  ::java::net::ServerSocket * createServerSocket();
  ::java::net::ServerSocket * createServerSocket(jint);
  ::java::net::ServerSocket * createServerSocket(jint, jint);
  ::java::net::ServerSocket * createServerSocket(jint, jint, ::java::net::InetAddress *);
  JArray< ::java::lang::String * > * getDefaultCipherSuites();
  JArray< ::java::lang::String * > * getSupportedCipherSuites();
private:
  ::java::lang::RuntimeException * __attribute__((aligned(__alignof__( ::javax::net::ssl::SSLServerSocketFactory)))) x;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_net_ssl_SSLServerSocketFactory$ErrorServerSocketFactory__
