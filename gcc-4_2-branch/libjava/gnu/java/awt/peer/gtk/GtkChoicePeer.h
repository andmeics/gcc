
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_peer_gtk_GtkChoicePeer__
#define __gnu_java_awt_peer_gtk_GtkChoicePeer__

#pragma interface

#include <gnu/java/awt/peer/gtk/GtkComponentPeer.h>
extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace awt
      {
        namespace peer
        {
          namespace gtk
          {
              class GtkChoicePeer;
          }
        }
      }
    }
  }
  namespace java
  {
    namespace awt
    {
        class AWTEvent;
        class Choice;
    }
  }
}

class gnu::java::awt::peer::gtk::GtkChoicePeer : public ::gnu::java::awt::peer::gtk::GtkComponentPeer
{

public:
  GtkChoicePeer(::java::awt::Choice *);
public: // actually package-private
  virtual void create();
  virtual jint nativeGetSelected();
  virtual void connectSignals();
  virtual void selectNative(jint);
  virtual void selectNativeUnlocked(jint);
public:
  virtual void add(::java::lang::String *, jint);
public: // actually package-private
  virtual void nativeRemove(jint);
  virtual void nativeRemoveAll();
public:
  virtual void select(jint);
  virtual void remove(jint);
  virtual void removeAll();
  virtual void addItem(::java::lang::String *, jint);
public: // actually protected
  virtual void postChoiceItemEvent(jint);
public:
  virtual void handleEvent(::java::awt::AWTEvent *);
private:
  jint __attribute__((aligned(__alignof__( ::gnu::java::awt::peer::gtk::GtkComponentPeer)))) selected;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_peer_gtk_GtkChoicePeer__
