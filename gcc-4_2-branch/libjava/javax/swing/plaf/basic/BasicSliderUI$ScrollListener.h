
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_plaf_basic_BasicSliderUI$ScrollListener__
#define __javax_swing_plaf_basic_BasicSliderUI$ScrollListener__

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
            class BasicSliderUI;
            class BasicSliderUI$ScrollListener;
        }
      }
    }
  }
}

class javax::swing::plaf::basic::BasicSliderUI$ScrollListener : public ::java::lang::Object
{

public:
  BasicSliderUI$ScrollListener(::javax::swing::plaf::basic::BasicSliderUI *);
  BasicSliderUI$ScrollListener(::javax::swing::plaf::basic::BasicSliderUI *, jint, jboolean);
  virtual void actionPerformed(::java::awt::event::ActionEvent *);
  virtual void setDirection(jint);
  virtual void setScrollByBlock(jboolean);
private:
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) direction;
  jboolean block;
public: // actually package-private
  ::javax::swing::plaf::basic::BasicSliderUI * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_plaf_basic_BasicSliderUI$ScrollListener__
