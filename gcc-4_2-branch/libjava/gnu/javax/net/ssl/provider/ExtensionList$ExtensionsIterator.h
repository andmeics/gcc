
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_javax_net_ssl_provider_ExtensionList$ExtensionsIterator__
#define __gnu_javax_net_ssl_provider_ExtensionList$ExtensionsIterator__

#pragma interface

#include <java/lang/Object.h>
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
              class Extension;
              class ExtensionList;
              class ExtensionList$ExtensionsIterator;
          }
        }
      }
    }
  }
}

class gnu::javax::net::ssl::provider::ExtensionList$ExtensionsIterator : public ::java::lang::Object
{

public:
  ExtensionList$ExtensionsIterator(::gnu::javax::net::ssl::provider::ExtensionList *);
  jboolean hasNext();
  jboolean hasPrevious();
  ::gnu::javax::net::ssl::provider::Extension * target$next();
  ::gnu::javax::net::ssl::provider::Extension * target$previous();
  jint nextIndex();
  jint previousIndex();
  void target$add(::gnu::javax::net::ssl::provider::Extension *);
  void remove();
  void target$set(::gnu::javax::net::ssl::provider::Extension *);
  ::java::lang::Object * next();
  ::java::lang::Object * previous();
  void add(::java::lang::Object *);
  void set(::java::lang::Object *);
private:
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) modCount;
  jint index;
  jint size;
public: // actually package-private
  ::gnu::javax::net::ssl::provider::ExtensionList * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_javax_net_ssl_provider_ExtensionList$ExtensionsIterator__
