
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_event_DocumentListener__
#define __javax_swing_event_DocumentListener__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace swing
    {
      namespace event
      {
          class DocumentEvent;
          class DocumentListener;
      }
    }
  }
}

class javax::swing::event::DocumentListener : public ::java::lang::Object
{

public:
  virtual void changedUpdate(::javax::swing::event::DocumentEvent *) = 0;
  virtual void insertUpdate(::javax::swing::event::DocumentEvent *) = 0;
  virtual void removeUpdate(::javax::swing::event::DocumentEvent *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __javax_swing_event_DocumentListener__
