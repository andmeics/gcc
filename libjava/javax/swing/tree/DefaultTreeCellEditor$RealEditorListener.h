
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_tree_DefaultTreeCellEditor$RealEditorListener__
#define __javax_swing_tree_DefaultTreeCellEditor$RealEditorListener__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace swing
    {
      namespace event
      {
          class ChangeEvent;
      }
      namespace tree
      {
          class DefaultTreeCellEditor;
          class DefaultTreeCellEditor$RealEditorListener;
      }
    }
  }
}

class javax::swing::tree::DefaultTreeCellEditor$RealEditorListener : public ::java::lang::Object
{

public: // actually package-private
  DefaultTreeCellEditor$RealEditorListener(::javax::swing::tree::DefaultTreeCellEditor *);
public:
  virtual void editingCanceled(::javax::swing::event::ChangeEvent *);
  virtual void editingStopped(::javax::swing::event::ChangeEvent *);
public: // actually package-private
  ::javax::swing::tree::DefaultTreeCellEditor * __attribute__((aligned(__alignof__( ::java::lang::Object)))) this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_tree_DefaultTreeCellEditor$RealEditorListener__
