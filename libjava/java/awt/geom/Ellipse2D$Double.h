
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_awt_geom_Ellipse2D$Double__
#define __java_awt_geom_Ellipse2D$Double__

#pragma interface

#include <java/awt/geom/Ellipse2D.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
      namespace geom
      {
          class Ellipse2D$Double;
          class Rectangle2D;
      }
    }
  }
}

class java::awt::geom::Ellipse2D$Double : public ::java::awt::geom::Ellipse2D
{

public:
  Ellipse2D$Double();
  Ellipse2D$Double(jdouble, jdouble, jdouble, jdouble);
  virtual ::java::awt::geom::Rectangle2D * getBounds2D();
  virtual jdouble getHeight();
  virtual jdouble getWidth();
  virtual jdouble getX();
  virtual jdouble getY();
  virtual jboolean isEmpty();
  virtual void setFrame(jdouble, jdouble, jdouble, jdouble);
  jdouble __attribute__((aligned(__alignof__( ::java::awt::geom::Ellipse2D)))) height;
  jdouble width;
  jdouble x;
  jdouble y;
  static ::java::lang::Class class$;
};

#endif // __java_awt_geom_Ellipse2D$Double__
