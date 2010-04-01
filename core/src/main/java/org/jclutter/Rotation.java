package org.jclutter;

public class Rotation {

	// AXIS
	public static final int X_AXIS = 0;
	public static final int Y_AXIS = 1;
	public static final int Z_AXIS = 2;
	
	public final Point center = new Point();
	public double angle = 0;
	public int axis = X_AXIS;
	
	public Rotation() {
	}

	public Rotation(int axis, double angle, float x, float y, float z){
		this.center.x = x;
		this.center.y = y;
		this.center.z = z;
		this.axis = axis;
		this.angle = angle;
	}
	
}
