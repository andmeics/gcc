
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_CompatibilityFocusTraversalPolicy__
#define __javax_swing_CompatibilityFocusTraversalPolicy__

#pragma interface

#include <java/awt/FocusTraversalPolicy.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Component;
        class Container;
        class FocusTraversalPolicy;
    }
  }
  namespace javax
  {
    namespace swing
    {
        class CompatibilityFocusTraversalPolicy;
    }
  }
}

class javax::swing::CompatibilityFocusTraversalPolicy : public ::java::awt::FocusTraversalPolicy
{

public: // actually package-private
  CompatibilityFocusTraversalPolicy(::java::awt::FocusTraversalPolicy *);
public:
  virtual ::java::awt::Component * getComponentAfter(::java::awt::Container *, ::java::awt::Component *);
  virtual ::java::awt::Component * getComponentBefore(::java::awt::Container *, ::java::awt::Component *);
  virtual ::java::awt::Component * getFirstComponent(::java::awt::Container *);
  virtual ::java::awt::Component * getLastComponent(::java::awt::Container *);
  virtual ::java::awt::Component * getDefaultComponent(::java::awt::Container *);
public: // actually package-private
  virtual void setNextFocusableComponent(::java::awt::Component *, ::java::awt::Component *);
  virtual void addNextFocusableComponent(::java::awt::Component *, ::java::awt::Component *);
  virtual void removeNextFocusableComponent(::java::awt::Component *, ::java::awt::Component *);
private:
  ::java::awt::FocusTraversalPolicy * __attribute__((aligned(__alignof__( ::java::awt::FocusTraversalPolicy)))) fallback;
  ::java::util::HashMap * forward;
  ::java::util::HashMap * backward;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_CompatibilityFocusTraversalPolicy__
