package org.jclutter;

/**
 * Clutter vertex of an actor in 3D space, expressed in pixels.
 * 
 */
public class Point {

	public float x, y, z;
	
	public Point() {
	}
	
	public Point(float x, float y) {
		super();
		this.x = x;
		this.y = y;
	}

	public Point(float x, float y, float z) {
		super();
		this.x = x;
		this.y = y;
		this.z = z;
	}
	
	
}
