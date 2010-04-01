package org.jclutter;

import org.jclutter.cogl.CoglTexture;
import org.jclutter.glib.GObject;


public final class Shader extends GObject {
	
	public Shader() {
		super(shaderNew());
	}
	
	protected Shader(int id){
		super(id);
	}
	
	public static final native int shaderNew();
	
	public native void setVertexSource(String data);
	
	public native String getVertexSource();
	
	public native void setFragmentSource(String data);
	
	public native String getFragmentSource();
	
	public native boolean compile() throws ClutterException;
	
	public native void release();
	
	public native boolean isCompiled();
	
	public native void setEnabled(boolean enabled);
	
	public native boolean isEnabled();
	
	/**
	 * Sets a user configurable variable in the shader programs attached to a Shader.
	 * @param name
	 * @param value
	 */
	public void setUniform(String name, int value){
		setUniformInt(name, value);
	}
	
	public void setUniform(String name, float value){
		setUniformFloat(name, value);
	}
	
	public void setUniform(String name, float [] value){
		setUniformFloatArray(name, value);
	}
	
	private native void setUniformInt(String name, int value);
	
	private native void setUniformFloat(String name, float value);
	
	private native void setUniformFloatArray(String name, float [] value);
	
	public native CoglTexture getCoglProgram();
	
	public native CoglTexture getCoglFragmentShader();
	
	public native CoglTexture getCoglVertexShader();

}
