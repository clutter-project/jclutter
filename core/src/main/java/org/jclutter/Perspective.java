package org.jclutter;

/**
 * Stage perspective.
 * 
 */
public class Perspective {
	
	public float fovy;
	public float aspect;
	public float zNear;
	public float zFar;
	
	public Perspective() {
	}
	
	public Perspective(float fovy, float aspect, float near, float far) {
		super();
		this.fovy = fovy;
		this.aspect = aspect;
		zNear = near;
		zFar = far;
	}

}
