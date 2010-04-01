package org.jclutter.cairo;


public class CairoTexture extends org.jclutter.Texture {
	
	
	public CairoTexture(float width, float height) {
		super(newInstance((int)width, (int)height));
	}
	
	public CairoTexture(int width, int height) {
		super(newInstance(width, height));
	}
	
	protected static native int newInstance(int width, int height);

	public native void setSurfaceSize(int width, int height);
	
	public native int getSurfaceWidth();
	
	public native int getSurfaceHeight();
	
	public native void clear();
	
	public native CairoContext createContext();
	
	public CairoContext createContext(int x_offset, int y_offset, int width, int height){
		return createRegion(x_offset, y_offset, width, height);
	}
	
	private native CairoContext createRegion(int x_offset, int y_offset, int width, int height);
	
	
}
