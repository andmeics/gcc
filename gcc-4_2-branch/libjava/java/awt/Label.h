
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_Label__
#define __java_awt_Label__

#pragma interface

#include <java/awt/Component.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Label;
    }
  }
  namespace javax
  {
    namespace accessibility
    {
        class AccessibleContext;
    }
  }
}

class java::awt::Label : public ::java::awt::Component
{

public:
  Label();
  Label(::java::lang::String *);
  Label(::java::lang::String *, jint);
  virtual jint getAlignment();
  virtual void setAlignment(jint);
  virtual ::java::lang::String * getText();
  virtual void setText(::java::lang::String *);
  virtual void addNotify();
public: // actually protected
  virtual ::java::lang::String * paramString();
public:
  virtual ::javax::accessibility::AccessibleContext * getAccessibleContext();
public: // actually package-private
  virtual ::java::lang::String * generateName();
private:
  static jlong getUniqueLong();
public:
  static const jint LEFT = 0;
  static const jint CENTER = 1;
  static const jint RIGHT = 2;
private:
  static const jlong serialVersionUID = 3094126758329070636LL;
  jint __attribute__((aligned(__alignof__( ::java::awt::Component)))) alignment;
  ::java::lang::String * text;
  static jlong nextLabelNumber;
public:
  static ::java::lang::Class class$;
};

#endif // __java_awt_Label__
