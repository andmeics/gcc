
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_JMenu$WinListener__
#define __javax_swing_JMenu$WinListener__

#pragma interface

#include <java/awt/event/WindowAdapter.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace event
      {
          class WindowEvent;
      }
    }
  }
  namespace javax
  {
    namespace swing
    {
        class JMenu;
        class JMenu$WinListener;
        class JPopupMenu;
    }
  }
}

class javax::swing::JMenu$WinListener : public ::java::awt::event::WindowAdapter
{

public:
  JMenu$WinListener(::javax::swing::JMenu *, ::javax::swing::JPopupMenu *);
  virtual void windowClosing(::java::awt::event::WindowEvent *);
private:
  static const jlong serialVersionUID = -6415815570638474823LL;
public: // actually package-private
  ::javax::swing::JMenu * __attribute__((aligned(__alignof__( ::java::awt::event::WindowAdapter)))) this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_JMenu$WinListener__
