
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_awt_peer_KDEDesktopPeer__
#define __gnu_java_awt_peer_KDEDesktopPeer__

#pragma interface

#include <gnu/java/awt/peer/ClasspathDesktopPeer.h>
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
            class KDEDesktopPeer;
        }
      }
    }
  }
}

class gnu::java::awt::peer::KDEDesktopPeer : public ::gnu::java::awt::peer::ClasspathDesktopPeer
{

public:
  KDEDesktopPeer();
public: // actually protected
  virtual ::java::lang::String * getCommand(::java::lang::String *);
  virtual jboolean supportCommand(::java::lang::String *);
public:
  virtual void mail();
public: // actually protected
  virtual ::java::lang::String * execQuery(::java::lang::String *);
private:
  static ::java::lang::String * BROWSER_QUERY_GNOME;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_awt_peer_KDEDesktopPeer__
