
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_awt_xlib_XFramePeer__
#define __gnu_awt_xlib_XFramePeer__

#pragma interface

#include <gnu/awt/xlib/XCanvasPeer.h>
extern "Java"
{
  namespace gnu
  {
    namespace awt
    {
      namespace xlib
      {
          class XFramePeer;
      }
    }
    namespace gcj
    {
      namespace xlib
      {
          class Window;
          class XConfigureEvent;
      }
    }
  }
  namespace java
  {
    namespace awt
    {
        class Frame;
        class Image;
        class Insets;
        class MenuBar;
        class Rectangle;
    }
  }
}

class gnu::awt::xlib::XFramePeer : public ::gnu::awt::xlib::XCanvasPeer
{

public:
  XFramePeer(::java::awt::Frame *);
public: // actually package-private
  virtual ::gnu::gcj::xlib::Window * locateParentWindow(::java::awt::Rectangle *);
  virtual void initWindowProperties();
  virtual jlong getBasicEventMask();
  virtual void configureNotify(::gnu::gcj::xlib::XConfigureEvent *);
public:
  virtual void setBounds(jint, jint, jint, jint);
  virtual ::java::awt::Insets * getInsets();
  virtual ::java::awt::Insets * insets();
  virtual void beginValidate();
  virtual void endValidate();
  virtual void toBack();
  virtual void toFront();
  virtual void setIconImage(::java::awt::Image *);
  virtual void setMenuBar(::java::awt::MenuBar *);
  virtual void setTitle(::java::lang::String *);
  virtual void setResizable(jboolean);
  virtual jint getState();
  virtual void setState(jint);
  virtual void setMaximizedBounds(::java::awt::Rectangle *);
  virtual void beginLayout();
  virtual void endLayout();
  virtual jboolean isPaintPending();
  virtual void setBoundsPrivate(jint, jint, jint, jint);
  virtual void updateAlwaysOnTop();
  virtual jboolean requestWindowFocus();
private:
  jboolean __attribute__((aligned(__alignof__( ::gnu::awt::xlib::XCanvasPeer)))) processingConfigureNotify;
public: // actually package-private
  static ::java::awt::Insets * INSETS_0_PROTOTYPE;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_awt_xlib_XFramePeer__
