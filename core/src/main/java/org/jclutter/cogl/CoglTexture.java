package org.jclutter.cogl;


public class CoglTexture {
	
	public static final int FLAG_NONE           = 0;
	public static final int FLAG_NO_AUTO_MIPMAP = 1 << 0;
	public static final int FLAG_NO_SLICING     = 1 << 1;
	
	private int pointer;
	
	protected CoglTexture(int nid){
		this.pointer = nid;
		//ref();
	}
	
	public CoglTexture(int width, int height, int flags,
			int internal_format) {
		this(newWithSize(width, height, flags, internal_format));
	}
	
	public CoglTexture(String filename, int flags,
			int internal_format) {
		this(newFromFile(filename, flags, internal_format));
	}
	
	public CoglTexture(int width, int height, int flags,
			int format, int internal_format, int rowstride, String data){
		this(newFromData(width, height, flags, format, internal_format, rowstride, data));
	}

	@Override
	public int hashCode() {
		return pointer;
	}
	
	@Override
	protected void finalize() throws Throwable {
		unref();
	}
	
	private static native int newWithSize(int width, int height, int flags,
			int internal_format);

	private static native int newFromFile(String filename, int flags,
			int internal_format);

	private static native int newFromData(int width, int height, int flags,
			int format, int internal_format, int rowstride, String data);
	
	private native void ref();
	
	private native void unref();

	public native int getWidth();

	public native int getHeight();

	public native int getFormat();

	public native int getRowstride();

	public native int getMaxWaste();

	public native boolean isSliced();

	public native String getData(int format, int rowstride);

	public native boolean setRegion(int src_x, int src_y, int dst_x,
			int dst_y, int dst_width, int dst_height, int width, int height,
			int format, int rowstride, String data);
	
	public native boolean isOffscreen();
	
	public native boolean isShader();
	
	public native boolean isVertexBuffer();
	
	public native boolean isMaterial();
	
	public Material toMaterial(){
		if (isMaterial()) return new Material(pointer);
		else return null;
	}
	
	public Shader toShader(){
		if (isShader()) return new Shader(pointer);
		else return null;
	}
	
	public VertexBuffer toVertexBuffer(){
		if (isVertexBuffer()) return new VertexBuffer(pointer);
		else return null;
	}
	
	public native CoglTexture createOffscreen();

}
