package org.jclutter;

/**
 * 
 * The rectangle containing an actor's bounding box, measured in pixels.
 * 
 */
public class Geometry {
	
	public int x, y, width, height;
	
	public Geometry() {
	}
	
	public Geometry(int x, int y, int width, int height) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}
	
}