
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_naming_spi_NamingManager__
#define __javax_naming_spi_NamingManager__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace naming
    {
        class CannotProceedException;
        class Context;
        class Name;
      namespace spi
      {
          class InitialContextFactoryBuilder;
          class NamingManager;
          class ObjectFactoryBuilder;
      }
    }
  }
}

class javax::naming::spi::NamingManager : public ::java::lang::Object
{

public: // actually package-private
  NamingManager();
public:
  static jboolean hasInitialContextFactoryBuilder();
  static ::javax::naming::Context * getInitialContext(::java::util::Hashtable *);
public: // actually package-private
  static ::javax::naming::Context * getURLContext(::java::lang::Object *, ::javax::naming::Name *, ::javax::naming::Context *, ::java::lang::String *, ::java::util::Hashtable *);
  static ::java::lang::Class * forName(::java::lang::String *);
public:
  static ::javax::naming::Context * getURLContext(::java::lang::String *, ::java::util::Hashtable *);
  static void setObjectFactoryBuilder(::javax::naming::spi::ObjectFactoryBuilder *);
public: // actually package-private
  static ::java::util::StringTokenizer * getPlusPath(::java::lang::String *, ::java::util::Hashtable *, ::javax::naming::Context *);
public:
  static ::java::lang::Object * getObjectInstance(::java::lang::Object *, ::javax::naming::Name *, ::javax::naming::Context *, ::java::util::Hashtable *);
  static void setInitialContextFactoryBuilder(::javax::naming::spi::InitialContextFactoryBuilder *);
  static ::javax::naming::Context * getContinuationContext(::javax::naming::CannotProceedException *);
  static ::java::lang::Object * getStateToBind(::java::lang::Object *, ::javax::naming::Name *, ::javax::naming::Context *, ::java::util::Hashtable *);
  static ::java::lang::String * CPE;
private:
  static ::javax::naming::spi::InitialContextFactoryBuilder * icfb;
public: // actually package-private
  static ::javax::naming::spi::ObjectFactoryBuilder * ofb;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_naming_spi_NamingManager__
