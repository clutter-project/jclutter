package org.jclutter;

public class Units {
	
	public enum Type {
		PIXEL, EM, MM, POINT
	}
	
	private int pointer;
	
	protected Units(int pointer) {
		this.pointer = pointer;
	}
	
	@Override
	public int hashCode() {
		return pointer;
	}
	
	public static native Units fromMillimeters(float mm);
	
	public static native Units fromPoints(float pt);
	
	public static native Units fromEm(float em);
	
	public static native Units fromEmForFont(String fontname, float em);
	
	public static native Units fromPixels(int px);
	
	public static native Units fromString(String s);
	
	public native float toPixels();
	
	public native Units copy();
	
	protected native void free();
	
	public native Type getUnitType();
	
	public native float getUnitValue();
	
	public native String toString();
	
	@Override
	protected void finalize() throws Throwable {
		free();
	}
	
	

}
