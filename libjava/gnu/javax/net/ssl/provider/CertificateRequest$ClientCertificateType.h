
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_CertificateRequest$ClientCertificateType__
#define __gnu_javax_net_ssl_provider_CertificateRequest$ClientCertificateType__

#pragma interface

#include <java/lang/Enum.h>
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
          namespace provider
          {
              class CertificateRequest$ClientCertificateType;
          }
        }
      }
    }
  }
}

class gnu::javax::net::ssl::provider::CertificateRequest$ClientCertificateType : public ::java::lang::Enum
{

  CertificateRequest$ClientCertificateType(::java::lang::String *, jint, jint);
public: // actually package-private
  static ::gnu::javax::net::ssl::provider::CertificateRequest$ClientCertificateType * forValue(jint);
public:
  jint getValue();
  static JArray< ::gnu::javax::net::ssl::provider::CertificateRequest$ClientCertificateType * > * values();
  static ::gnu::javax::net::ssl::provider::CertificateRequest$ClientCertificateType * valueOf(::java::lang::String *);
  static ::gnu::javax::net::ssl::provider::CertificateRequest$ClientCertificateType * RSA_SIGN;
  static ::gnu::javax::net::ssl::provider::CertificateRequest$ClientCertificateType * DSS_SIGN;
  static ::gnu::javax::net::ssl::provider::CertificateRequest$ClientCertificateType * RSA_FIXED_DH;
  static ::gnu::javax::net::ssl::provider::CertificateRequest$ClientCertificateType * DSS_FIXED_DH;
private:
  jint __attribute__((aligned(__alignof__( ::java::lang::Enum)))) value;
  static JArray< ::gnu::javax::net::ssl::provider::CertificateRequest$ClientCertificateType * > * ENUM$VALUES;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_CertificateRequest$ClientCertificateType__
