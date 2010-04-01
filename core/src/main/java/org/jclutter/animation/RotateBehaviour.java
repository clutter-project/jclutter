package org.jclutter.animation;


public class RotateBehaviour extends Behaviour {
	
	// DIRECTION
	public static final int CLOCKWISE         = 0;
	public static final int COUNTER_CLOCKWISE = 1;
	
	public RotateBehaviour(Alpha alpha, int axis, int direction, double start, double end) {
		super(behaviourRotateNew(alpha,axis,direction,start,end));
	}
	
	public static native int behaviourRotateNew(Alpha alpha, int rotateaxis, int rotatedirection, double start, double end);
	
	public native void setAxis(int rotateaxis);
	
	public native int getAxis();
	
	public native void setDirection(int rotatedirection);
	
	public native int getDirection();
	
	public native void setBounds(double start, double end);

	public native void setCenter(int x, int y, int z);
	
	public native int getCenterX();
	
	public native int getCenterY();

}
