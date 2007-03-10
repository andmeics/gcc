
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_Session__
#define __gnu_javax_net_ssl_provider_Session__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace net
      {
        namespace ssl
        {
            class SRPTrustManager;
          namespace provider
          {
              class Alert;
              class CipherSuite;
              class ProtocolVersion;
              class SecurityParameters;
              class Session;
              class Session$ID;
              class SessionContext;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace security
    {
        class Principal;
        class SecureRandom;
      namespace cert
      {
          class Certificate;
      }
    }
  }
  namespace javax
  {
    namespace net
    {
      namespace ssl
      {
          class SSLPermission;
          class SSLSessionContext;
          class X509KeyManager;
          class X509TrustManager;
      }
    }
    namespace security
    {
      namespace cert
      {
          class X509Certificate;
      }
    }
  }
}

class gnu::javax::net::ssl::provider::Session : public ::java::lang::Object
{

public: // actually package-private
  Session();
  Session(jlong);
public: // actually protected
  ::java::lang::Object * clone();
public:
  ::java::lang::String * getCipherSuite();
  jlong getCreationTime();
  JArray< jbyte > * getId();
  jlong getLastAccessedTime();
  JArray< ::java::security::cert::Certificate * > * getLocalCertificates();
  JArray< ::java::security::cert::Certificate * > * getPeerCertificates();
  JArray< ::javax::security::cert::X509Certificate * > * getPeerCertificateChain();
  ::java::lang::String * getPeerHost();
  ::java::lang::String * getProtocol();
  ::javax::net::ssl::SSLSessionContext * getSessionContext();
  JArray< ::java::lang::String * > * getValueNames();
  ::java::lang::Object * getValue(::java::lang::String *);
  void putValue(::java::lang::String *, ::java::lang::Object *);
  void removeValue(::java::lang::String *);
  void invalidate();
public: // actually package-private
  void access();
  void setLastAccessedTime(jlong);
public:
  jint getApplicationBufferSize() = 0;
  ::java::security::Principal * getLocalPrincipal() = 0;
  jint getPacketBufferSize() = 0;
  jint getPeerPort() = 0;
  ::java::security::Principal * getPeerPrincipal() = 0;
  jboolean isValid() = 0;
private:
  static ::javax::net::ssl::SSLPermission * GET_SESSION_CONTEXT_PERMISSION;
  jlong __attribute__((aligned(__alignof__( ::java::lang::Object)))) creationTime;
  ::java::util::Date * lastAccessedTime;
public: // actually package-private
  ::gnu::javax::net::ssl::provider::Session$ID * sessionId;
  JArray< ::java::security::cert::Certificate * > * localCerts;
  JArray< ::java::security::cert::Certificate * > * peerCerts;
  JArray< ::javax::security::cert::X509Certificate * > * peerCertChain;
  ::java::lang::String * peerHost;
  jboolean peerVerified;
  ::gnu::javax::net::ssl::provider::SessionContext * context;
  ::java::util::HashMap * values;
  jboolean valid;
  ::java::util::List * enabledSuites;
  ::gnu::javax::net::ssl::provider::CipherSuite * cipherSuite;
  ::java::util::SortedSet * enabledProtocols;
  ::gnu::javax::net::ssl::provider::ProtocolVersion * protocol;
  JArray< jbyte > * masterSecret;
  ::gnu::javax::net::ssl::SRPTrustManager * srpTrustManager;
  ::javax::net::ssl::X509TrustManager * trustManager;
  ::javax::net::ssl::X509KeyManager * keyManager;
  ::java::security::SecureRandom * random;
  ::gnu::javax::net::ssl::provider::SecurityParameters * params;
  ::gnu::javax::net::ssl::provider::Alert * currentAlert;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_Session__
