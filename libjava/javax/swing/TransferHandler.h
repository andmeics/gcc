
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_TransferHandler__
#define __javax_swing_TransferHandler__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace datatransfer
      {
          class Clipboard;
          class DataFlavor;
          class Transferable;
      }
      namespace event
      {
          class InputEvent;
      }
    }
    namespace beans
    {
        class PropertyDescriptor;
    }
  }
  namespace javax
  {
    namespace swing
    {
        class Action;
        class Icon;
        class JComponent;
        class TransferHandler;
        class TransferHandler$SwingDragGestureRecognizer;
    }
  }
}

class javax::swing::TransferHandler : public ::java::lang::Object
{

public:
  static ::javax::swing::Action * getCopyAction();
  static ::javax::swing::Action * getCutAction();
  static ::javax::swing::Action * getPasteAction();
public: // actually protected
  TransferHandler();
public:
  TransferHandler(::java::lang::String *);
  virtual jboolean canImport(::javax::swing::JComponent *, JArray< ::java::awt::datatransfer::DataFlavor * > *);
public: // actually protected
  virtual ::java::awt::datatransfer::Transferable * createTransferable(::javax::swing::JComponent *);
public:
  virtual void exportAsDrag(::javax::swing::JComponent *, ::java::awt::event::InputEvent *, jint);
public: // actually protected
  virtual void exportDone(::javax::swing::JComponent *, ::java::awt::datatransfer::Transferable *, jint);
public:
  virtual void exportToClipboard(::javax::swing::JComponent *, ::java::awt::datatransfer::Clipboard *, jint);
  virtual jint getSourceActions(::javax::swing::JComponent *);
  virtual ::javax::swing::Icon * getVisualRepresentation(::java::awt::datatransfer::Transferable *);
  virtual jboolean importData(::javax::swing::JComponent *, ::java::awt::datatransfer::Transferable *);
private:
  ::java::beans::PropertyDescriptor * getPropertyDescriptor(::javax::swing::JComponent *);
  ::java::awt::datatransfer::DataFlavor * getPropertyDataFlavor(::java::lang::Class *, JArray< ::java::awt::datatransfer::DataFlavor * > *);
  static const jlong serialVersionUID = -967749805571669910LL;
  static ::java::lang::String * COMMAND_COPY;
  static ::java::lang::String * COMMAND_CUT;
  static ::java::lang::String * COMMAND_PASTE;
public:
  static const jint NONE = 0;
  static const jint COPY = 1;
  static const jint MOVE = 2;
  static const jint COPY_OR_MOVE = 3;
private:
  static ::javax::swing::Action * copyAction;
  static ::javax::swing::Action * cutAction;
  static ::javax::swing::Action * pasteAction;
  jint __attribute__((aligned(__alignof__( ::java::lang::Object)))) sourceActions;
  ::javax::swing::Icon * visualRepresentation;
  ::java::lang::String * propertyName;
  ::javax::swing::TransferHandler$SwingDragGestureRecognizer * recognizer;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_TransferHandler__
