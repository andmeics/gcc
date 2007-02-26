
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_JPasswordField__
#define __javax_swing_JPasswordField__

#pragma interface

#include <javax/swing/JTextField.h>
#include <gcj/array.h>

extern "Java"
{
  namespace javax
  {
    namespace accessibility
    {
        class AccessibleContext;
    }
    namespace swing
    {
        class JPasswordField;
      namespace text
      {
          class Document;
      }
    }
  }
}

class javax::swing::JPasswordField : public ::javax::swing::JTextField
{

public:
  JPasswordField();
  JPasswordField(::java::lang::String *);
  JPasswordField(jint);
  JPasswordField(::java::lang::String *, jint);
  JPasswordField(::javax::swing::text::Document *, ::java::lang::String *, jint);
private:
  void writeObject(::java::io::ObjectOutputStream *);
public:
  virtual ::java::lang::String * getUIClassID();
  virtual jchar getEchoChar();
  virtual void setEchoChar(jchar);
  virtual jboolean echoCharIsSet();
  virtual void copy();
  virtual void cut();
  virtual ::java::lang::String * getText();
  virtual ::java::lang::String * getText(jint, jint);
  virtual JArray< jchar > * getPassword();
public: // actually protected
  virtual ::java::lang::String * paramString();
public:
  virtual ::javax::accessibility::AccessibleContext * getAccessibleContext();
private:
  jchar __attribute__((aligned(__alignof__( ::javax::swing::JTextField)))) echoChar;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_JPasswordField__
