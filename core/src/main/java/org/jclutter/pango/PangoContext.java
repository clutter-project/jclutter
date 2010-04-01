package org.jclutter.pango;

import org.jclutter.glib.GObject;

// http://docs.huihoo.com/api/gtk/2.6/pango/pango-Layout-Objects.html
public class PangoContext extends GObject {

	public static final int DIRECTION_LTR = 0;
	public static final int DIRECTION_RTL = 1;
	public static final int DIRECTION_TTB_LTR = 2;
	public static final int DIRECTION_TTB_RTL = 3;
	public static final int DIRECTION_WEAK_LTR = 4;
	public static final int DIRECTION_WEAK_RTL = 5;
	public static final int DIRECTION_NEUTRAL = 6;

	public static final int WRAP_WORD = 0;
	public static final int WRAP_CHAR = 1;
	public static final int WRAP_WORD_CHAR = 2;

	public static final int ELLIPSIZE_NONE = 0;
	public static final int ELLIPSIZE_START = 1;
	public static final int ELLIPSIZE_MIDDLE = 2;
	public static final int ELLIPSIZE_END = 3;

	public static final int ALIGN_LEFT = 0;
	public static final int ALIGN_CENTER = 1;
	public static final int ALIGN_RIGHT = 2;

	protected PangoContext(int id) {
		super(id);
	}

	public native void setLanguage(String lang);

	public native String getLanguage();

	public native void setBaseDirection(int dir);

	public native int getBaseDirection();

	public native Matrix getMatrix();

	public native void setMatrix(Matrix m);

}
