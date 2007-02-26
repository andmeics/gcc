
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_plaf_basic_BasicSplitPaneDivider__
#define __javax_swing_plaf_basic_BasicSplitPaneDivider__

#pragma interface

#include <java/awt/Container.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Component;
        class Dimension;
        class Graphics;
        class Insets;
    }
    namespace beans
    {
        class PropertyChangeEvent;
    }
  }
  namespace javax
  {
    namespace swing
    {
        class JButton;
        class JSplitPane;
      namespace border
      {
          class Border;
      }
      namespace plaf
      {
        namespace basic
        {
            class BasicSplitPaneDivider;
            class BasicSplitPaneDivider$DragController;
            class BasicSplitPaneDivider$MouseHandler;
            class BasicSplitPaneUI;
        }
      }
    }
  }
}

class javax::swing::plaf::basic::BasicSplitPaneDivider : public ::java::awt::Container
{

public:
  BasicSplitPaneDivider(::javax::swing::plaf::basic::BasicSplitPaneUI *);
  virtual void setBasicSplitPaneUI(::javax::swing::plaf::basic::BasicSplitPaneUI *);
  virtual ::javax::swing::plaf::basic::BasicSplitPaneUI * getBasicSplitPaneUI();
  virtual void setDividerSize(jint);
  virtual jint getDividerSize();
  virtual void setBorder(::javax::swing::border::Border *);
  virtual ::javax::swing::border::Border * getBorder();
  virtual ::java::awt::Insets * getInsets();
  virtual ::java::awt::Dimension * getPreferredSize();
  virtual ::java::awt::Dimension * getMinimumSize();
  virtual void propertyChange(::java::beans::PropertyChangeEvent *);
  virtual void paint(::java::awt::Graphics *);
public: // actually protected
  virtual void oneTouchExpandableChanged();
  virtual ::javax::swing::JButton * createLeftOneTouchButton();
  virtual ::javax::swing::JButton * createRightOneTouchButton();
  virtual void prepareForDragging();
  virtual void dragDividerTo(jint);
  virtual void finishDraggingTo(jint);
public: // actually package-private
  virtual void moveDividerTo(jint);
  static const jlong serialVersionUID = 1463404307042803342LL;
public: // actually protected
  static const jint ONE_TOUCH_SIZE = 6;
  static const jint ONE_TOUCH_OFFSET = 2;
  ::javax::swing::plaf::basic::BasicSplitPaneDivider$DragController * __attribute__((aligned(__alignof__( ::java::awt::Container)))) dragger;
  ::javax::swing::plaf::basic::BasicSplitPaneUI * splitPaneUI;
  jint dividerSize;
  ::java::awt::Component * hiddenDivider;
  ::javax::swing::JSplitPane * splitPane;
  ::javax::swing::plaf::basic::BasicSplitPaneDivider$MouseHandler * mouseHandler;
  jint orientation;
  ::javax::swing::JButton * leftButton;
  ::javax::swing::JButton * rightButton;
private:
  ::javax::swing::border::Border * border;
public: // actually package-private
  jint currentDividerLocation;
  jboolean centerOneTouchButtons;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_plaf_basic_BasicSplitPaneDivider__
