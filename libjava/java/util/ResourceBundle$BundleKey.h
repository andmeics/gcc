
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_util_ResourceBundle$BundleKey__
#define __java_util_ResourceBundle$BundleKey__

#pragma interface

#include <java/lang/Object.h>

class java::util::ResourceBundle$BundleKey : public ::java::lang::Object
{

public: // actually package-private
  ResourceBundle$BundleKey();
  ResourceBundle$BundleKey(::java::util::Locale *, ::java::lang::String *, ::java::util::Locale *, ::java::lang::ClassLoader *);
  virtual void set(::java::util::Locale *, ::java::lang::String *, ::java::util::Locale *, ::java::lang::ClassLoader *);
public:
  virtual jint hashCode();
  virtual jboolean equals(::java::lang::Object *);
public: // actually package-private
  ::java::util::Locale * __attribute__((aligned(__alignof__( ::java::lang::Object)))) defaultLocale;
  ::java::lang::String * baseName;
  ::java::util::Locale * locale;
  ::java::lang::ClassLoader * classLoader;
  jint hashcode;
public:
  static ::java::lang::Class class$;
};

#endif // __java_util_ResourceBundle$BundleKey__
