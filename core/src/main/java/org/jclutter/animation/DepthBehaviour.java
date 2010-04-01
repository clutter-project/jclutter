package org.jclutter.animation;

public class DepthBehaviour extends Behaviour {
	
	public DepthBehaviour(Alpha alpha, int depthStart, int depthEnd){
		super(depthNew(alpha, depthStart, depthEnd));
	}

	protected static native int depthNew(Alpha alpha, int start, int end);
	
	public native void setBounds(int start, int end);
	
	public native int getStart();
	
	public native int getEnd();
	
}
