
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_plaf_basic_BasicInternalFrameTitlePane$SizeAction__
#define __javax_swing_plaf_basic_BasicInternalFrameTitlePane$SizeAction__

#pragma interface

#include <javax/swing/AbstractAction.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace event
      {
          class ActionEvent;
      }
    }
  }
  namespace javax
  {
    namespace swing
    {
      namespace plaf
      {
        namespace basic
        {
            class BasicInternalFrameTitlePane;
            class BasicInternalFrameTitlePane$SizeAction;
        }
      }
    }
  }
}

class javax::swing::plaf::basic::BasicInternalFrameTitlePane$SizeAction : public ::javax::swing::AbstractAction
{

public:
  BasicInternalFrameTitlePane$SizeAction(::javax::swing::plaf::basic::BasicInternalFrameTitlePane *);
  virtual void actionPerformed(::java::awt::event::ActionEvent *);
public: // actually package-private
  ::javax::swing::plaf::basic::BasicInternalFrameTitlePane * __attribute__((aligned(__alignof__( ::javax::swing::AbstractAction)))) this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_plaf_basic_BasicInternalFrameTitlePane$SizeAction__
