
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_net_HeaderFieldHelper__
#define __gnu_java_net_HeaderFieldHelper__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace net
      {
          class HeaderFieldHelper;
      }
    }
  }
}

class gnu::java::net::HeaderFieldHelper : public ::java::lang::Object
{

public:
  HeaderFieldHelper();
  HeaderFieldHelper(jint);
  virtual void addHeaderField(::java::lang::String *, ::java::lang::String *);
  virtual ::java::lang::String * getHeaderFieldKeyByIndex(jint);
  virtual ::java::lang::String * getHeaderFieldValueByIndex(jint);
  virtual ::java::lang::String * getHeaderFieldValueByKey(::java::lang::String *);
  virtual ::java::util::Map * getHeaderFields();
  virtual jint getNumberOfEntries();
private:
  ::java::util::Vector * __attribute__((aligned(__alignof__( ::java::lang::Object)))) headerFieldKeys;
  ::java::util::Vector * headerFieldValues;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_net_HeaderFieldHelper__
