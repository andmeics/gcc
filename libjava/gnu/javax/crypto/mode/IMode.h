
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_crypto_mode_IMode__
#define __gnu_javax_crypto_mode_IMode__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace javax
    {
      namespace crypto
      {
        namespace mode
        {
            class IMode;
        }
      }
    }
  }
}

class gnu::javax::crypto::mode::IMode : public ::java::lang::Object
{

public:
  virtual void update(JArray< jbyte > *, jint, JArray< jbyte > *, jint) = 0;
  virtual ::java::lang::String * name() = 0;
  virtual jint defaultBlockSize() = 0;
  virtual jint defaultKeySize() = 0;
  virtual ::java::util::Iterator * blockSizes() = 0;
  virtual ::java::util::Iterator * keySizes() = 0;
  virtual void init(::java::util::Map *) = 0;
  virtual jint currentBlockSize() = 0;
  virtual void reset() = 0;
  virtual void encryptBlock(JArray< jbyte > *, jint, JArray< jbyte > *, jint) = 0;
  virtual void decryptBlock(JArray< jbyte > *, jint, JArray< jbyte > *, jint) = 0;
  virtual jboolean selfTest() = 0;
  static ::java::lang::String * STATE;
  static ::java::lang::String * MODE_BLOCK_SIZE;
  static ::java::lang::String * IV;
  static const jint ENCRYPTION = 1;
  static const jint DECRYPTION = 2;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __gnu_javax_crypto_mode_IMode__
