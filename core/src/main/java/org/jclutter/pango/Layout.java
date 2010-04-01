package org.jclutter.pango;

import org.jclutter.Dimension;
import org.jclutter.glib.GObject;

/**
 * Partial implementation of PangoLayout
 * http://docs.huihoo.com/api/gtk/2.6/pango/pango-Layout-Objects.html#PangoLayout
 */
public class Layout extends GObject {

	protected Layout(int id) {
		super(id);
	}
	
	public native void setText(String text);
	
	public native String getText();
	
	public native void setMarkup(String markup);
	
	public native String getMarkup();
	
	public native boolean isAutoDir();
	
	public native void setAutoDir(boolean ad);
	
	public native Dimension getSize();

	public native int getWidth();
	
	public native int getHeight();
	
	public native void setWidth(int w);
	
	public native void setHeight(int h);
	
	public native void setEllipsizeMode();
	
	public native int getEllipsizeMode();
	
	public native void setWrapMode(int wrap);
	
	public native int getWrapMode();
	
	public native void setIndent(int indent);
	
	public native int getIndent();
	
	public native void setSpacing(int spacing);
	
	public native int getSpacing();
	
	public native void setJustify(boolean justify);

	public native boolean isJustify();
	
	public native void setAutodir(boolean autodir);

	public native boolean isAutodir();
	
	public native void setAlignment(int align);

	public native int getAlignment();
	
}
