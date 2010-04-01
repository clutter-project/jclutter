package org.jclutter.cogl;

public class Shader extends CoglTexture {

	// CGL_VERTEX_SHADER or CGL_FRAGMENT_SHADER. 
	public Shader(int type) {
		super(newInstance(type));
	}

	private native static int newInstance(int type);
}
