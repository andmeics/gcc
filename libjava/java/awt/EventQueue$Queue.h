
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_EventQueue$Queue__
#define __java_awt_EventQueue$Queue__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class AWTEvent;
        class EventQueue;
        class EventQueue$Queue;
    }
  }
}

class java::awt::EventQueue$Queue : public ::java::lang::Object
{

  EventQueue$Queue(::java::awt::EventQueue *);
public: // actually package-private
  EventQueue$Queue(::java::awt::EventQueue *, ::java::awt::EventQueue$Queue *);
  ::java::awt::AWTEvent * __attribute__((aligned(__alignof__( ::java::lang::Object)))) queueHead;
  ::java::awt::AWTEvent * queueTail;
  ::java::awt::EventQueue * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __java_awt_EventQueue$Queue__
