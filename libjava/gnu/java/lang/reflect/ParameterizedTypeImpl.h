
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_lang_reflect_ParameterizedTypeImpl__
#define __gnu_java_lang_reflect_ParameterizedTypeImpl__

#pragma interface

#include <gnu/java/lang/reflect/TypeImpl.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace lang
      {
        namespace reflect
        {
            class ParameterizedTypeImpl;
        }
      }
    }
  }
}

class gnu::java::lang::reflect::ParameterizedTypeImpl : public ::gnu::java::lang::reflect::TypeImpl
{

public: // actually package-private
  ParameterizedTypeImpl(::java::lang::String *, ::java::lang::ClassLoader *, ::java::lang::reflect::Type *, JArray< ::java::lang::reflect::Type * > *);
  ::java::lang::reflect::Type * resolve();
public:
  JArray< ::java::lang::reflect::Type * > * getActualTypeArguments();
  ::java::lang::reflect::Type * getRawType();
  ::java::lang::reflect::Type * getOwnerType();
  jboolean equals(::java::lang::Object *);
  jint hashCode();
  ::java::lang::String * toString();
private:
  ::java::lang::String * __attribute__((aligned(__alignof__( ::gnu::java::lang::reflect::TypeImpl)))) rawTypeName;
  ::java::lang::ClassLoader * loader;
  ::java::lang::Class * rawType;
  ::java::lang::reflect::Type * owner;
  JArray< ::java::lang::reflect::Type * > * typeArgs;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_lang_reflect_ParameterizedTypeImpl__
