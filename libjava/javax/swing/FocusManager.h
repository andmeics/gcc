
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_FocusManager__
#define __javax_swing_FocusManager__

#pragma interface

#include <java/awt/DefaultKeyboardFocusManager.h>
extern "Java"
{
  namespace javax
  {
    namespace swing
    {
        class FocusManager;
    }
  }
}

class javax::swing::FocusManager : public ::java::awt::DefaultKeyboardFocusManager
{

public:
  FocusManager();
  static ::javax::swing::FocusManager * getCurrentManager();
  static void setCurrentManager(::javax::swing::FocusManager *);
  static void disableSwingFocusManager();
  static jboolean isFocusManagerEnabled();
  static ::java::lang::String * FOCUS_MANAGER_CLASS_PROPERTY;
  static ::java::lang::Class class$;
};

#endif // __javax_swing_FocusManager__
