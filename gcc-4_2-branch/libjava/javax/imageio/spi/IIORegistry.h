
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_imageio_spi_IIORegistry__
#define __javax_imageio_spi_IIORegistry__

#pragma interface

#include <javax/imageio/spi/ServiceRegistry.h>
extern "Java"
{
  namespace javax
  {
    namespace imageio
    {
      namespace spi
      {
          class IIORegistry;
      }
    }
  }
}

class javax::imageio::spi::IIORegistry : public ::javax::imageio::spi::ServiceRegistry
{

public:
  static ::javax::imageio::spi::IIORegistry * getDefaultInstance();
private:
  IIORegistry();
public:
  void registerApplicationClasspathSpis();
private:
  static ::java::util::HashSet * defaultCategories;
  static ::java::util::HashMap * instances;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_imageio_spi_IIORegistry__
