
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_event_MouseInputListener__
#define __javax_swing_event_MouseInputListener__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace event
      {
          class MouseEvent;
      }
    }
  }
  namespace javax
  {
    namespace swing
    {
      namespace event
      {
          class MouseInputListener;
      }
    }
  }
}

class javax::swing::event::MouseInputListener : public ::java::lang::Object
{

public:
  virtual void mouseClicked(::java::awt::event::MouseEvent *) = 0;
  virtual void mousePressed(::java::awt::event::MouseEvent *) = 0;
  virtual void mouseReleased(::java::awt::event::MouseEvent *) = 0;
  virtual void mouseEntered(::java::awt::event::MouseEvent *) = 0;
  virtual void mouseExited(::java::awt::event::MouseEvent *) = 0;
  virtual void mouseDragged(::java::awt::event::MouseEvent *) = 0;
  virtual void mouseMoved(::java::awt::event::MouseEvent *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __javax_swing_event_MouseInputListener__
