
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_text_html_FormView__
#define __javax_swing_text_html_FormView__

#pragma interface

#include <javax/swing/text/ComponentView.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Component;
        class Point;
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
      namespace text
      {
          class AttributeSet;
          class Element;
        namespace html
        {
            class FormView;
        }
      }
    }
  }
}

class javax::swing::text::html::FormView : public ::javax::swing::text::ComponentView
{

public:
  FormView(::javax::swing::text::Element *);
public: // actually protected
  virtual ::java::awt::Component * createComponent();
public:
  virtual jfloat getMaximumSpan(jint);
  virtual void actionPerformed(::java::awt::event::ActionEvent *);
public: // actually protected
  virtual void submitData(::java::lang::String *);
  virtual void imageSubmit(::java::lang::String *);
public: // actually package-private
  virtual ::java::lang::String * getImageData(::java::awt::Point *);
  virtual ::javax::swing::text::Element * getFormElement();
private:
  ::java::lang::String * getFormData();
  void getElementFormData(::javax::swing::text::Element *, ::java::lang::StringBuilder *);
  void getSelectData(::javax::swing::text::AttributeSet *, ::java::lang::StringBuilder *);
  ::java::lang::String * getTextAreaData(::javax::swing::text::AttributeSet *);
  ::java::lang::String * getInputFormData(::javax::swing::text::AttributeSet *);
  void addData(::java::lang::StringBuilder *, ::java::lang::String *, ::java::lang::String *);
  void resetForm();
public:
  static ::java::lang::String * SUBMIT;
  static ::java::lang::String * RESET;
private:
  jboolean __attribute__((aligned(__alignof__( ::javax::swing::text::ComponentView)))) maxIsPreferred;
public: // actually package-private
  static jboolean $assertionsDisabled;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_text_html_FormView__
