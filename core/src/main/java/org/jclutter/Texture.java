package org.jclutter;



// TODO : handle errors and colg

public class Texture extends Actor {
	
	// ClutterTextureQuality
	public static final int QUALITY_LOW    = 0;
	public static final int QUALITY_MEDIUM = 1;
	public static final int QUALITY_HIGH   = 2;
	
	// ClutterTextureFlags
	public static final int RGB_FLAG_BGR     = 1 << 1;
	public static final int RGB_FLAG_PREMULT = 1 << 2;
	public static final int YUV_FLAG_YUV2    = 1 << 3;


	public Texture(){
		super(newInstance());
	}
	
	protected Texture(int nid){
		super(nid);
	}
	
	public Texture(String filename){
		super(newFromFile(filename));
	}
	
	public Texture(Actor actor){
		super(newFromActor(actor));
	}
	
	private static native int newInstance();
	
	public static Texture createFromFile(String filename) throws ClutterException {
		return new Texture(newFromFile(filename));
	}
	private static native int newFromFile(String filename);
	private static native int newFromActor(Actor actor);
	
	public native boolean setFromFile(String filename) throws ClutterException;
	
	public native boolean setFromRgbData(String data, boolean hasAlpha, int width, int height, int rowstride, int bpp, int textureflags);
	
	public native boolean setFromYuvData(String data, int width, int height, int textureflags);
	
	public native boolean setAreaFromRgbData(String data, boolean hasAlpha, int x, int y,
			int width, int height, int rowstride, int bpp, int flags);
	
	public native Dimension getBaseSize();
	
	// LOW = 0, MEDIUM = 1, HIGH = 2
	public native int getFilterQuality();
	
	public native void setFilterQuality(int texturequality);
	
	public native int getMaxTileWaste();
	
	public native void setLoadAsync(boolean loadasync);
	
	public native void isLoadAsync();
	
	public native void setLoadDataAsync(boolean loadasync);
	
	public native void isLoadDataAsync();
	
	public native void setRepeat(boolean x, boolean y);
	
	public native boolean isRepeatX();
	
	public native boolean isRepeatY();
	
	public native void setKeepAspectRatio(boolean kar);
	
	public native boolean isKeepAspectRatio();
	
	public native void setSyncSize(boolean sync);
	
	public native boolean isSyncSize();
	
	/**
	 * 
	 * @return any COGL.PIXEL_FORMAT_XXX value.
	 * @see org.jclutter.cogl.COGL
	 */
	public native int getCoglPixelFormat();
	
	public native void setCoglTexture(org.jclutter.cogl.CoglTexture texture);
	
	public native org.jclutter.cogl.CoglTexture getCoglTexture();
	
	public native void setCoglMaterial(org.jclutter.cogl.CoglTexture texture);
	
	// TODO cast 
	public native org.jclutter.cogl.CoglTexture getCoglMaterial();
	
	// Events
	public void onLoadFinished(boolean success, String messageIfAny){}
	public void onPixbufChange(){}
	public void onSizeChange(int width, int height){}
	
}
