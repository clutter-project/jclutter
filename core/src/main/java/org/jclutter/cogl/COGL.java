package org.jclutter.cogl;

import org.jclutter.pango.Layout;
import org.jclutter.pango.Line;

public class COGL {
	
	
	// COGL Feature flags
	public static final int FEATURE_TEXTURE_RECTANGLE      = (1 << 1);
	public static final int FEATURE_TEXTURE_NPOT           = (1 << 2);
	public static final int FEATURE_TEXTURE_YUV            = (1 << 3);
	public static final int FEATURE_TEXTURE_READ_PIXELS    = (1 << 4);
	public static final int FEATURE_SHADERS_GLSL           = (1 << 5);
	public static final int FEATURE_OFFSCREEN              = (1 << 6);
	public static final int FEATURE_OFFSCREEN_MULTISAMPLE  = (1 << 7);
	public static final int FEATURE_OFFSCREEN_BLIT         = (1 << 8);
	public static final int FEATURE_FOUR_CLIP_PLANES       = (1 << 9);
	public static final int FEATURE_STENCIL_BUFFER         = (1 << 10);
	public static final int FEATURE_VBOS		           = (1 << 11);
	
	// COGL Fog Modes
	public static final int FOG_MODE_LINEAR = 0;
	public static final int FOG_MODE_EXPONENTIAL = 1;
	public static final int FOG_MODE_EXPONENTIAL_SQUARED = 2;

	// COGL Texture flags
	public static final int TEXTURE_NONE           = 0;
	public static final int TEXTURE_NO_AUTO_MIPMAP = 1 << 0;
	public static final int TEXTURE_NO_SLICING     = 1 << 1;
	
	public static final long BUFFER_BIT_COLOR   = 1L<<0;
	public static final long BUFFER_BIT_DEPTH   = 1L<<1;
	public static final long BUFFER_BIT_STENCIL = 1L<<2;
	
	public static final int PIXEL_FORMAT_24 = 2;
	public static final int PIXEL_FORMAT_32 = 3;
	public static final int A_BIT           = 1 << 4;
	public static final int BGR_BIT         = 1 << 5;
	public static final int AFIRST_BIT      = 1 << 6;
	public static final int PREMULT_BIT     = 1 << 7;
	public static final int UNORDERED_MASK  = 0x0F;
	public static final int UNPREMULT_MASK  = 0x7F;
	
	public static final int PIXEL_FORMAT_ANY           = 0;
	public static final int PIXEL_FORMAT_A_8           = 1 | A_BIT;
	public static final int PIXEL_FORMAT_RGB_565       = 4;
	public static final int PIXEL_FORMAT_RGBA_4444     = 5 | A_BIT;
	public static final int PIXEL_FORMAT_RGBA_5551     = 6 | A_BIT;
	public static final int PIXEL_FORMAT_YUV           = 7;
	public static final int PIXEL_FORMAT_G_8           = 8;
	public static final int PIXEL_FORMAT_RGB_888       =  PIXEL_FORMAT_24;
	public static final int PIXEL_FORMAT_BGR_888       = (PIXEL_FORMAT_24 | BGR_BIT);
	public static final int PIXEL_FORMAT_RGBA_8888     = (PIXEL_FORMAT_32 | A_BIT);
	public static final int PIXEL_FORMAT_BGRA_8888     = (PIXEL_FORMAT_32 | A_BIT | BGR_BIT);
	public static final int PIXEL_FORMAT_ARGB_8888     = (PIXEL_FORMAT_32 | A_BIT | AFIRST_BIT);
	public static final int PIXEL_FORMAT_ABGR_8888     = (PIXEL_FORMAT_32 | A_BIT | BGR_BIT | AFIRST_BIT);
	public static final int PIXEL_FORMAT_RGBA_8888_PRE = (PIXEL_FORMAT_32 | A_BIT | PREMULT_BIT);
	public static final int PIXEL_FORMAT_BGRA_8888_PRE = (PIXEL_FORMAT_32 | A_BIT | PREMULT_BIT | BGR_BIT);
	public static final int PIXEL_FORMAT_ARGB_8888_PRE = (PIXEL_FORMAT_32 | A_BIT | PREMULT_BIT | AFIRST_BIT);
	public static final int PIXEL_FORMAT_ABGR_8888_PRE = (PIXEL_FORMAT_32 | A_BIT | PREMULT_BIT | BGR_BIT | AFIRST_BIT);
	public static final int PIXEL_FORMAT_RGBA_4444_PRE = (PIXEL_FORMAT_RGBA_4444 | A_BIT | PREMULT_BIT);
	public static final int PIXEL_FORMAT_RGBA_5551_PRE = (PIXEL_FORMAT_RGBA_5551 | A_BIT | PREMULT_BIT);


	public enum AttributeType {
		  BYTE,
		  UNSIGNED_BYTE,
		  SHORT,
		  UNSIGNED_SHORT,
		  FLOAT
	}
	  
	
	/** General API */

	public static native int getFeatures();
	public static native boolean featuresAvailable(int features);
	public static native void pushMatrix();
	public static native void popMatrix();
	public static native void scale(float x, float y, float z);
	public static native void translate(float x,
	            float y,
	            float z);
	public static native void rotate(float angle,
	            float x,
	            float y,
	            float z);
	public static native void frustum(float left,
	            float right,
	            float bottom,
	            float top,
	            float z_near,
	            float z_far);
	public static native void perspective(float fovy,
	            float aspect,
	            float z_near,
	            float z_far);
	public static native void ortho(float left,
	            float right,
	            float bottom,
	            float top,
	            float near,
	            float far);
	public static native Matrix getModelviewMatrix();
	public static native void setModelViewMatrix(Matrix m);
	public static native Matrix getProjectionMatrix();
	public static native void setProjectionMatrix(Matrix m);
	public static native void viewPort(int width, int height);
	public static native float[] getViewPort();
	public static native void clear(Color color, long buffers);
	
	public static native void setDepthTestEnabled(boolean setting);
	public static native boolean isDepthTestEnabled();
	public static native void setBackfaceCullingEnabled(boolean setting);
	public static native boolean isBackfaceCullingEnabled();
	
	public static native void disableFog();
	
	public static void setSource(Color color){
		setSource(color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());
	}
	public static native void setSource(int red,
            int green,
            int blue,
            int alpha);
	
	public static native void setSourceTexture(CoglTexture texture);

	public static native void flush();
	public static native void beginGL();
	public static native void endGL();
	// end general API//
	
	
	
    // COGL Primitives 
	
	public static native void rectangle(float x_1,
            float y_1,
            float x_2,
            float y_2);
	public static native void rectangles(float [] verts);
	public static native void rectangleWithTextureCoords(float x1,
	            float y1,
	            float x2,
	            float y2,
	            float tx1,
	            float ty1,
	            float tx2,
	            float ty2);
	public static native void rectanglesWithTextureCoords (float [] verts);
	public static native void rectangleWithMultitextureCoords
	           (float x1,
	            float y1,
	            float x2,
	            float y2,
	            float [] tex_coords);
	public static native void polygon(TextureVertex [] vertices,
	           boolean use_color);
	
	public static native void pathNew();
	public static native void pathMoveTo(float x,
	            float y);
	public static native void pathClose  ();
	public static native void pathLineTo(float x,
	            float y);
	public static native void pathCurveTo(float x_1,
	            float y_1,
	            float x_2,
	            float y_2,
	            float x_3,
	            float y_3);
	public static native void pathArc(float center_x,
	            float center_y,
	            float radius_x,
	            float radius_y,
	            float angle_1,
	            float angle_2);
	public static native void pathRelMoveTo(float x,
	            float y);
	public static native void pathRelLineTo(float x,
	            float y);
	public static native void pathRelCurveTo(float x_1,
	            float y_1,
	            float x_2,
	            float y_2,
	            float x_3,
	            float y_3);
	public static native void pathLine (float x_1,
	            float y_1,
	            float x_2,
	            float y_2);
	public static native void path_polyline(float [] coords);
	public static native void path_polygon(float [] coords);
	public static native void pathRectangle(float x_1,
	            float y_1,
	            float x_2,
	            float y_2);
	public static native void pathRoundRectangle(float x_1,
	            float y_1,
	            float x_2,
	            float y_2,
	            float radius,
	            float arc_step);
	public static native void pathEllipse(float center_x,
	            float center_y,
	            float radius_x,
	            float radius_y);
	
	public static native void pathFill();
	public static native void pathFillPreserve();
	public static native void pathStroke();
	public static native void pathStrokePreserve();
	
	
	// Clipping
	public static native void clipPushRectangle(float x0,
            float y0,
            float x1,
            float y1);
	public static native void clipPushWindowRectangle(int x_offset,
	            int y_offset,
	            int width,
	            int height);
	public static native void clipPushFromPath();
	public static native void clipPushFromPathPreserve();
	public static native void clipPop();
	
	public static native void clipPush(float x_offset,
	            float y_offset,
	            float width,
	            float height);
	public static native void clipPushWindowRect(float x_offset,
	            float y_offset,
	            float width,
	            float height);
	public static native void clipEnsure();
	public static native void clipStackSave();
	public static native void clipStackRestore();


	/**
	 * 
	 * @clutter.version 1.2
	 * @param buffer
	 */
	public static native void setFramebuffer(CoglTexture onscreenoroffscreen);
	public static native void popFramebuffer();
	
	// Pango
	
	public static native void renderLayout(Layout layout, int x, int y, Color color, int flags);
	
	public static native void renderLayoutSubpixel(Layout layout, int x, int y, Color color, int flags);
	
	public static native void renderLayoutLine(Line line, int x, int y, Color color);

}
