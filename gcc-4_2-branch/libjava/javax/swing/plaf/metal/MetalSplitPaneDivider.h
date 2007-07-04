
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_plaf_metal_MetalSplitPaneDivider__
#define __javax_swing_plaf_metal_MetalSplitPaneDivider__

#pragma interface

#include <javax/swing/plaf/basic/BasicSplitPaneDivider.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Color;
        class Graphics;
    }
  }
  namespace javax
  {
    namespace swing
    {
        class JButton;
        class JSplitPane;
      namespace plaf
      {
        namespace metal
        {
            class MetalSplitPaneDivider;
            class MetalSplitPaneUI;
        }
      }
    }
  }
}

class javax::swing::plaf::metal::MetalSplitPaneDivider : public ::javax::swing::plaf::basic::BasicSplitPaneDivider
{

public:
  MetalSplitPaneDivider(::javax::swing::plaf::metal::MetalSplitPaneUI *, ::java::awt::Color *, ::java::awt::Color *);
  virtual void paint(::java::awt::Graphics *);
public: // actually protected
  virtual ::javax::swing::JButton * createLeftOneTouchButton();
  virtual ::javax::swing::JButton * createRightOneTouchButton();
public: // actually package-private
  static JArray< JArray< jbyte > * > * BUTTON_SPRITE_L;
  static JArray< JArray< jbyte > * > * BUTTON_SPRITE_R;
  ::java::awt::Color * __attribute__((aligned(__alignof__( ::javax::swing::plaf::basic::BasicSplitPaneDivider)))) dark;
  ::java::awt::Color * light;
  ::javax::swing::JSplitPane * splitPane;
  jint orientation;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_plaf_metal_MetalSplitPaneDivider__
