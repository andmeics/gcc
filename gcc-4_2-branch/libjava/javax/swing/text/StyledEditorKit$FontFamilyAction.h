
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_text_StyledEditorKit$FontFamilyAction__
#define __javax_swing_text_StyledEditorKit$FontFamilyAction__

#pragma interface

#include <javax/swing/text/StyledEditorKit$StyledTextAction.h>
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
      namespace text
      {
          class StyledEditorKit$FontFamilyAction;
      }
    }
  }
}

class javax::swing::text::StyledEditorKit$FontFamilyAction : public ::javax::swing::text::StyledEditorKit$StyledTextAction
{

public:
  StyledEditorKit$FontFamilyAction(::java::lang::String *, ::java::lang::String *);
  virtual void actionPerformed(::java::awt::event::ActionEvent *);
private:
  ::java::lang::String * __attribute__((aligned(__alignof__( ::javax::swing::text::StyledEditorKit$StyledTextAction)))) family;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_text_StyledEditorKit$FontFamilyAction__
