package org.jclutter.cairo;

import org.jclutter.Color;

public final class CairoPattern {

	public static final int EXTEND_NONE = 0;
	public static final int EXTEND_REPEAT = 1;
	public static final int EXTEND_REFLECT = 2;
	public static final int EXTEND_PAD = 3;

	public static final int PATTERN_TYPE_SOLID = 0;
	public static final int PATTERN_TYPE_SURFACE = 1;
	public static final int PATTERN_TYPE_LINEAR = 2;
	public static final int PATTERN_TYPE_RADIAL = 3;

	public static final int FILTER_FAST = 0;
	public static final int FILTER_GOOD = 1;
	public static final int FILTER_BEST = 2;
	public static final int FILTER_NEAREST = 3;
	public static final int FILTER_BILINEAR = 4;
	public static final int FILTER_GAUSSIAN = 5;

	@SuppressWarnings("unused")
	private int pointer;

	private CairoPattern(int i) {
		pointer = i;
	}
	
	/**
	 * Solid
	 * @param red
	 * @param green
	 * @param blue
	 */
	public CairoPattern(double red, double green, double blue){
		this(create(red, green, blue));
	}
	
	/**
	 * With alpha
	 * @param c
	 */
	public CairoPattern(Color c){
		this(createWithAlpha(c.red, c.green, c.blue, c.alpha));
	}
	
	/**
	 * Linear
	 * @param x0
	 * @param y0
	 * @param x1
	 * @param y1
	 */
	public CairoPattern(double x0, double y0,
			double x1, double y1){
		this(createLinear(x0, y0, x1, y1));
	}
	
	/**
	 * Radial
	 * @param cx0
	 * @param cy0
	 * @param radius0
	 * @param cx1
	 * @param cy1
	 * @param radius1
	 */
	public CairoPattern(double cx0, double cy0,
			double radius0, double cx1, double cy1, double radius1){
		this(createRadial(cx0, cy0, radius0, cx1, cy1, radius1));
	}

	public native void addColorStop(double offset, double red,
			double green, double blue);

	public native void addColorStopWithAlpha(double offset, double red,
			double green, double blue, double alpha);

	public native int getColorStopCount() throws CairoException;

	private static native int create(double red, double green,
			double blue);

	private static native int createWithAlpha(double red, double green,
			double blue, double alpha);

	private static native int createLinear(double x0, double y0,
			double x1, double y1);

	private static native int createRadial(double cx0, double cy0,
			double radius0, double cx1, double cy1, double radius1);

	public native void reference();

	public native void destroy();
	
	public CairoException.Type getStatus(){
		return CairoException.Type.values()[status()];
	}
	
	public void checkStatus() throws CairoException {
		int status = status();
		if (status > 0){
			throw new CairoException(status);
		}
	}

	private native int status();

	public native void setExtend(int extend);

	public native int getExtend();

	public native void setFilter(int filter);

	public native int getFilter();

	public native int getType();

	public native int getReferenceCount();

}
