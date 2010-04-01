package org.jclutter;

import org.jclutter.glib.GObject;


public class Backend extends GObject {

	private static Backend def;

	private Backend() {
		super(getDefaultBackend());
	}

	protected static native int getDefaultBackend();

	// public native void init(EGLDisplay display, EGLContext context);

	public static Backend getDefault() {
		if (def == null) {
			def = new Backend();
		}
		return def;
	}

	public native double getResolution();

	public native void setResolution(double dpi);

	public native void setDoubleClickTime(int msec);

	public native int getDoubleClickTime();

	public native void setDoubleClickDistance(int distance);

	public native int getDoubleClickDistance();

	public native void setFontname(String fontname);

	public native String getFontname();

	// TODO : set and get cairo font options

}
