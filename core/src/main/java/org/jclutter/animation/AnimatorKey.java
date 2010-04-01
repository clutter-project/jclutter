package org.jclutter.animation;

import org.jclutter.Actor;

public class AnimatorKey {
	
	public native Actor getActor();
	public native String getPropertyName();
	public native int getPropertyType();
	public Mode getMode(){
		return Mode.values()[getModeInt()];
	}
	private native int getModeInt();
	public native double getProgress();
	

}
