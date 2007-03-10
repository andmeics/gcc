
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_Component$AccessibleAWTComponent__
#define __java_awt_Component$AccessibleAWTComponent__

#pragma interface

#include <javax/accessibility/AccessibleContext.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Color;
        class Component;
        class Component$AccessibleAWTComponent;
        class Cursor;
        class Dimension;
        class Font;
        class FontMetrics;
        class Point;
        class Rectangle;
      namespace event
      {
          class ComponentListener;
          class FocusListener;
      }
    }
    namespace beans
    {
        class PropertyChangeListener;
    }
  }
  namespace javax
  {
    namespace accessibility
    {
        class Accessible;
        class AccessibleComponent;
        class AccessibleRole;
        class AccessibleStateSet;
    }
  }
}

class java::awt::Component$AccessibleAWTComponent : public ::javax::accessibility::AccessibleContext
{

public: // actually protected
  Component$AccessibleAWTComponent(::java::awt::Component *);
public:
  virtual void addPropertyChangeListener(::java::beans::PropertyChangeListener *);
  virtual void removePropertyChangeListener(::java::beans::PropertyChangeListener *);
  virtual ::java::lang::String * getAccessibleName();
  virtual ::java::lang::String * getAccessibleDescription();
  virtual ::javax::accessibility::AccessibleRole * getAccessibleRole();
  virtual ::javax::accessibility::AccessibleStateSet * getAccessibleStateSet();
  virtual ::javax::accessibility::Accessible * getAccessibleParent();
  virtual jint getAccessibleIndexInParent();
  virtual jint getAccessibleChildrenCount();
  virtual ::javax::accessibility::Accessible * getAccessibleChild(jint);
  virtual ::java::util::Locale * getLocale();
  virtual ::javax::accessibility::AccessibleComponent * getAccessibleComponent();
  virtual ::java::awt::Color * getBackground();
  virtual void setBackground(::java::awt::Color *);
  virtual ::java::awt::Color * getForeground();
  virtual void setForeground(::java::awt::Color *);
  virtual ::java::awt::Cursor * getCursor();
  virtual void setCursor(::java::awt::Cursor *);
  virtual ::java::awt::Font * getFont();
  virtual void setFont(::java::awt::Font *);
  virtual ::java::awt::FontMetrics * getFontMetrics(::java::awt::Font *);
  virtual jboolean isEnabled();
  virtual void setEnabled(jboolean);
  virtual jboolean isVisible();
  virtual void setVisible(jboolean);
  virtual jboolean isShowing();
  virtual jboolean contains(::java::awt::Point *);
  virtual ::java::awt::Point * getLocationOnScreen();
  virtual ::java::awt::Point * getLocation();
  virtual void setLocation(::java::awt::Point *);
  virtual ::java::awt::Rectangle * getBounds();
  virtual void setBounds(::java::awt::Rectangle *);
  virtual ::java::awt::Dimension * getSize();
  virtual void setSize(::java::awt::Dimension *);
  virtual ::javax::accessibility::Accessible * getAccessibleAt(::java::awt::Point *);
  virtual jboolean isFocusTraversable();
  virtual void requestFocus();
  virtual void addFocusListener(::java::awt::event::FocusListener *);
  virtual void removeFocusListener(::java::awt::event::FocusListener *);
private:
  static const jlong serialVersionUID = 642321655757800191LL;
public: // actually protected
  ::java::awt::event::ComponentListener * __attribute__((aligned(__alignof__( ::javax::accessibility::AccessibleContext)))) accessibleAWTComponentHandler;
  ::java::awt::event::FocusListener * accessibleAWTFocusHandler;
public: // actually package-private
  ::java::awt::Component * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __java_awt_Component$AccessibleAWTComponent__
