/* AffineTransformOp.java --  This class performs affine 
 * transformation between two images or rasters in 2 
 * dimensions. Copyright (C) 2004 Free Software Foundation

This file is part of GNU Classpath.

GNU Classpath is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU Classpath is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU Classpath; see the file COPYING.  If not, write to the
Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
02111-1307 USA.

Linking this library statically or dynamically with other modules is
making a combined work based on this library.  Thus, the terms and
conditions of the GNU General Public License cover the whole
combination.

As a special exception, the copyright holders of this library give you
permission to link this library with independent modules to produce an
executable, regardless of the license terms of these independent
modules, and to copy and distribute the resulting executable under
terms of your choice, provided that you also meet, for each linked
independent module, the terms and conditions of the license of that
module.  An independent module is a module which is not derived from
or based on this library.  If you modify this library, you may extend
this exception to your version of the library, but you are not
obligated to do so.  If you do not wish to do so, delete this
exception statement from your version. */

package java.awt.image;

import java.awt.*;
import java.awt.Graphics;
import java.awt.geom.*;
import gnu.java.awt.peer.gtk.GdkGraphics2D;


/**
 * This class performs affine transformation between two images or 
 * rasters in 2 dimensions. 
 *
 * @author Olga Rodimina <rodimina@redhat.com> 
 */
 
public class AffineTransformOp implements BufferedImageOp, RasterOp
{

    public static final int TYPE_BILINEAR = 0;
    public static final int TYPE_NEAREST_NEIGHBOR = 1;

    private AffineTransform transform;
    private RenderingHints hints;

    
    /**
     * Construct AffineTransformOp with the given xform and interpolationType.
     * Interpolation type can be either TYPE_BILINEAR or TYPE_NEAREST_NEIGHBOR.
     *
     * @param xform AffineTransform that will applied to the source image 
     * @param interpolationType type of interpolation used
     */

    AffineTransformOp (AffineTransform xform, int interpolationType)
    {
      this.transform = xform;

      if (interpolationType == 0) 
        hints = new RenderingHints (RenderingHints.KEY_INTERPOLATION, 
                                    RenderingHints.VALUE_INTERPOLATION_BILINEAR);
				   
      else
        hints = new RenderingHints (RenderingHints.KEY_INTERPOLATION,
                                    RenderingHints.VALUE_INTERPOLATION_NEAREST_NEIGHBOR);

    }

    /**
     * Construct AffineTransformOp with the given xform and rendering hints.
     * 
     * @param xform AffineTransform that will applied to the source image
     * @param hints rendering hints that will be used during transformation
     */

    AffineTransformOp (AffineTransform xform, RenderingHints hints)
    {
      this.transform = xform;
      this.hints = hints;
    }

    /**
     * Creates empty BufferedImage with the size equal to that of the 
     * transformed image and correct number of bands. The newly created 
     * image is created with the specified ColorModel. 
     * If the ColorModel is equal to null, then image is created 
     * with the ColorModel of the source image.
     *
     * @param src source image
     * @param destCM color model for the destination image
     * @return new compatible destination image
     */

    public BufferedImage createCompatibleDestImage (BufferedImage src,
                                                    ColorModel destCM)
    {

      // if destCm is not specified, use color model of the source image

      if (destCM == null) 
        destCM = src.getColorModel ();

      return new BufferedImage (destCM, 
                                createCompatibleDestRaster (src.getRaster ()),
                                src.isAlphaPremultiplied (),
                                null);		             

    }

    /**
     * Creates empty WritableRaster with the size equal to the transformed 
     * source raster and correct number of bands 
     *
     * @param src source raster
     * @throws RasterFormatException if resulting width or height of raster is 0
     * @return new compatible raster
     */

    public WritableRaster createCompatibleDestRaster (Raster src)
    {
      Rectangle rect = (Rectangle) getBounds2D (src);
      
      // throw RasterFormatException if resulting width or height of the
      // transformed raster is 0

      if (rect.getWidth () == 0 || rect.getHeight () == 0) 
        throw new RasterFormatException("width or height is 0");

      return src.createCompatibleWritableRaster ((int) rect.getWidth (), 
                                                (int) rect.getHeight ());
    }

    /**
     * Transforms source image using transform specified at the constructor.
     * The resulting transformed image is stored in the destination image. 
     *
     * @param src source image
     * @param dst destination image
     * @return transformed source image
     */

    public BufferedImage filter (BufferedImage src, BufferedImage dst)
    {

      if (dst == src)
        throw new IllegalArgumentException ("src image cannot be the same as the dst image");

      // If the destination image is null, then BufferedImage is 
      // created with ColorModel of the source image

      if (dst == null)
        dst = createCompatibleDestImage(src, src.getColorModel ());

      // FIXME: Must check if color models of src and dst images are the same.
      // If it is not, then source image should be converted to color model
      // of the destination image

      GdkGraphics2D gr = (GdkGraphics2D) dst.createGraphics ();
      gr.setRenderingHints (hints);	
      gr.drawImage (src, transform, null);
      return dst;

    }

    /**
     * Transforms source raster using transform specified at the constructor.
     * The resulting raster is stored in the destination raster.
     *
     * @param src source raster
     * @param dst destination raster
     * @return transformed raster
     */

    public WritableRaster filter (Raster src, WritableRaster dst)
    {
      throw new UnsupportedOperationException ("not implemented yet");	
    }

    /**
     * Transforms source image using transform specified at the constructor and 
     * returns bounds of the transformed image.
     *
     * @param src image to be transformed
     * @return bounds of the transformed image.
     */

    public Rectangle2D getBounds2D (BufferedImage src)
    {
      return getBounds2D (src.getRaster());
    }
   
    /**
     * Returns bounds of the transformed raster.
     *
     * @param src raster to be transformed
     * @return bounds of the transformed raster.
     */

    public Rectangle2D getBounds2D (Raster src)
    {
      // determine new size for the transformed raster.
      // Need to calculate transformed coordinates of the lower right
      // corner of the raster. The upper left corner is always (0,0)
              
      double x2 = (double) src.getWidth () + src.getMinX ();
      double y2 = (double) src.getHeight () + src.getMinY ();
      Point2D p2 = getPoint2D (new Point2D.Double (x2,y2), null);

      Rectangle2D rect = new Rectangle (0, 0, (int) p2.getX (), (int) p2.getY ());
      return rect.getBounds ();
    }

    /**
     * Returns interpolation type used during transformations
     *
     * @return interpolation type
     */

    public int getInterpolationType ()
    {
      if(hints.containsValue (RenderingHints.VALUE_INTERPOLATION_BILINEAR))
        return TYPE_BILINEAR;
      else 
        return TYPE_NEAREST_NEIGHBOR;
    }

    /** 
     * Returns location of the transformed source point. The resulting point 
     * is stored in the dstPt if one is specified.
     *  
     * @param srcPt point to be transformed
     * @param dstPt destination point
     * @return the location of the transformed source point.
     */
     
    public Point2D getPoint2D (Point2D srcPt, Point2D dstPt)
    {
      return transform.transform (srcPt, dstPt);
    }

    /** Returns rendering hints that are used during transformation.
     *
     * @return rendering hints
     */

    public RenderingHints getRenderingHints ()
    {
      return hints;
    }

    /** Returns transform used in transformation between source and destination
     * image.
     *
     * @return transform
     */
     
    public AffineTransform getTransform ()
    {
      return transform;
    }
}
