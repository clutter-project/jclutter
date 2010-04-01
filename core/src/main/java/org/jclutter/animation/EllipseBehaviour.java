package org.jclutter.animation;


// TODO : Tilt methods
public class EllipseBehaviour extends Behaviour {
	
	// direction = Rotate.CLOCKWISE or COUNTER_CLOCKWISE
	public EllipseBehaviour(Alpha alpha, int x, int y, int width, int height, int rotatedirection, double start, double end){
		super(behaviourEllipseNew(alpha,x,y,width,height,rotatedirection,start,end));
	}

	protected static native int behaviourEllipseNew(Alpha alpha, int x, int y, int width, int height, int rotatedirection, double start, double end);
	
	public native void setCenter(int x, int y);

	public native int getCenterX();
	
	public native int getCenterY();
	
	public native void setAngleStart(double angleStart);
	
	public native double getAngleStart();
	
	public native void setAngleEnd(double angleEnd);
	
	public native double getAngleEnd();
	
	public native void setAngleTilt(int rotateAxis, double angleTilt);
	
	public native void setTilt(double x, double y, double z);
	
	public native void setWidth(int width);
	public native int getWidth();
	
	public native void setHeight(int height);
	public native int getHeight();
	
	public native void setDirection(int direction);
	public native int getDirection();
}
