
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_plaf_metal_MetalFileChooserUI$IndentIcon__
#define __javax_swing_plaf_metal_MetalFileChooserUI$IndentIcon__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Component;
        class Graphics;
    }
  }
  namespace javax
  {
    namespace swing
    {
        class Icon;
      namespace plaf
      {
        namespace metal
        {
            class MetalFileChooserUI;
            class MetalFileChooserUI$IndentIcon;
        }
      }
    }
  }
}

class javax::swing::plaf::metal::MetalFileChooserUI$IndentIcon : public ::java::lang::Object
{

public: // actually package-private
  MetalFileChooserUI$IndentIcon(::javax::swing::plaf::metal::MetalFileChooserUI *);
  virtual void setIcon(::javax::swing::Icon *);
  virtual void setDepth(jint);
public:
  virtual jint getIconHeight();
  virtual jint getIconWidth();
  virtual void paintIcon(::java::awt::Component *, ::java::awt::Graphics *, jint, jint);
private:
  static const jint INDENT = 10;
  ::javax::swing::Icon * __attribute__((aligned(__alignof__( ::java::lang::Object)))) icon;
  jint depth;
public: // actually package-private
  ::javax::swing::plaf::metal::MetalFileChooserUI * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_plaf_metal_MetalFileChooserUI$IndentIcon__
