
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_beans_PropertyChangeListener__
#define __java_beans_PropertyChangeListener__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace beans
    {
        class PropertyChangeEvent;
        class PropertyChangeListener;
    }
  }
}

class java::beans::PropertyChangeListener : public ::java::lang::Object
{

public:
  virtual void propertyChange(::java::beans::PropertyChangeEvent *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __java_beans_PropertyChangeListener__
