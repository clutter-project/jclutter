package org.jclutter.animation;

public class OpacityBehaviour extends Behaviour {
	
	public OpacityBehaviour(Alpha alpha, int opacityStart, int opacityEnd){
		super(behaviourOpacityNew(alpha, opacityStart, opacityEnd));
	}

	protected static native int behaviourOpacityNew(Alpha alpha, int start, int end);
	
	public native void setBounds(int start, int end);
	
	public native int getStart();
	
	public native int getEnd();
	
}
