package org.jclutter.cogl;


public class Color {

	private int pointer;
	
	public Color() {
		pointer = newInstance();
	}
	
	public Color(int red, int green, int blue, int alpha) {
		pointer = newInstance();
		setFrom(red, green, blue, alpha);
	}
	
	private Color(int p){
		pointer = p;
	}
	
	private static native int newInstance();
	
	public Color copy() {
		return new Color(copyNative());
	}
	
	private native int copyNative();
	
	private native void free();
	
	@Override
	protected void finalize() throws Throwable {
		free();
	}
	@Override
	public int hashCode() {
		return pointer;
	}
	
//	public void setFrom(Color color){
//		setFrom(color.red, color.green, color.blue, color.alpha);
//	}
	
	public native void setFrom(int red, int green, int blue, int alpha);
	
	public native int getRed();
	
	public native int getGreen();
	
	public native int getBlue();
	
	public native int getAlpha();
	
	
	
	
}
