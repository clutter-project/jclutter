package org.jclutter.animation;

import org.jclutter.Actor;
import org.jclutter.glib.GObject;

public class Animator extends GObject {
	
	private static final int INTERPOLATION_LINEAR = 0;
	private static final int INTERPOLATION_CUBIC  = 1;

	protected Animator() {
		super(newInstance());
	}

	private static native int newInstance();
	
	public native Timeline run();
	
	public native Timeline getTimeline();
	
	public native void setTimeline(Timeline t);
	
	public native int getDuration();
	
	public native void setDuration(int duration);

	public native void setEaseIn(Actor actor, String property, boolean easeIn);
	
	public native boolean isEaseIn(Actor actor, String property);
	
	private Animator setKey(Actor actor, String property, Mode mode, double progress, Object value){
		// TODO finish
		if (value.getClass() == int.class){
			setKeyInt(actor, property, mode.ordinal(), progress, (Integer) value);
		} else if (value.getClass() == float.class){
			setKeyFloat(actor, property, mode.ordinal(), progress, (Float) value);
		} else if (value.getClass() == double.class){
			setKeyDouble(actor, property, mode.ordinal(), progress, (Double) value);
		} else if (value.getClass() == boolean.class){
			setKeyBoolean(actor, property, mode.ordinal(), progress, (Boolean) value);
		} else {
			System.err.println("Class not supported :"+ value.getClass()+" with property :"+property);
		}
		return this;
	}
	
	
	private native void setKeyInt(Actor actor, String property, int mode, double progress, int value);
	
	private native void setKeyFloat(Actor actor, String property, int mode, double progress, float value);

	private native void setKeyDouble(Actor actor, String property, int mode, double progress, double value);
	
	private native void setKeyBoolean(Actor actor, String property, int mode, double progress, boolean value);

}
