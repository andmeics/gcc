
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_net_protocol_http_Request__
#define __gnu_java_net_protocol_http_Request__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace net
      {
        namespace protocol
        {
          namespace http
          {
              class Authenticator;
              class HTTPConnection;
              class Headers;
              class Request;
              class RequestBodyWriter;
              class Response;
              class ResponseHeaderHandler;
          }
        }
      }
    }
  }
}

class gnu::java::net::protocol::http::Request : public ::java::lang::Object
{

public: // actually protected
  Request(::gnu::java::net::protocol::http::HTTPConnection *, ::java::lang::String *, ::java::lang::String *);
public:
  virtual ::gnu::java::net::protocol::http::HTTPConnection * getConnection();
  virtual ::java::lang::String * getMethod();
  virtual ::java::lang::String * getPath();
  virtual ::java::lang::String * getRequestURI();
  virtual ::gnu::java::net::protocol::http::Headers * getHeaders();
  virtual ::java::lang::String * getHeader(::java::lang::String *);
  virtual jint getIntHeader(::java::lang::String *);
  virtual ::java::util::Date * getDateHeader(::java::lang::String *);
  virtual void setHeader(::java::lang::String *, ::java::lang::String *);
  virtual void setRequestBody(JArray< jbyte > *);
  virtual void setRequestBodyWriter(::gnu::java::net::protocol::http::RequestBodyWriter *);
  virtual void setResponseHeaderHandler(::java::lang::String *, ::gnu::java::net::protocol::http::ResponseHeaderHandler *);
  virtual void setAuthenticator(::gnu::java::net::protocol::http::Authenticator *);
  virtual ::gnu::java::net::protocol::http::Response * dispatch();
public: // actually package-private
  virtual ::gnu::java::net::protocol::http::Response * readResponse(::java::io::InputStream *);
  virtual void notifyHeaderHandlers(::gnu::java::net::protocol::http::Headers *);
private:
  ::java::io::InputStream * createResponseBodyStream(::gnu::java::net::protocol::http::Headers *, jint, jint, ::java::io::InputStream *, jboolean);
public: // actually package-private
  virtual jboolean authenticate(::gnu::java::net::protocol::http::Response *, jint);
  virtual ::java::util::Properties * parseAuthParams(::java::lang::String *);
  virtual ::java::lang::String * unquote(::java::lang::String *);
  virtual ::java::lang::String * getNonceCount(::java::lang::String *);
  virtual JArray< jbyte > * generateNonce();
  virtual ::java::lang::String * toHexString(JArray< jbyte > *);
  virtual void handleSetCookie(::java::lang::String *);
public: // actually protected
  ::gnu::java::net::protocol::http::HTTPConnection * __attribute__((aligned(__alignof__( ::java::lang::Object)))) connection;
  ::java::lang::String * method;
  ::java::lang::String * path;
  ::gnu::java::net::protocol::http::Headers * requestHeaders;
  ::gnu::java::net::protocol::http::RequestBodyWriter * requestBodyWriter;
  ::java::util::Map * responseHeaderHandlers;
  ::gnu::java::net::protocol::http::Authenticator * authenticator;
private:
  jboolean dispatched;
public: // actually package-private
  JArray< jbyte > * nonce;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_net_protocol_http_Request__
