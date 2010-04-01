package org.jclutter.animation;

import org.jclutter.Actor;
import org.jclutter.glib.GObject;

public class Animation extends GObject {
	
	public Animation() {
		super(newInstance());
	}
	
	protected Animation(int nid) {
		super(nid);
	}
	
	public native void setActor(Actor actor);
	
	public native Actor getActor();
	
	protected static native int newInstance();
	
	public void setMode(Mode mode){
		setNativeMode(mode.ordinal());
	}
	
	private native void setNativeMode(int am);
	
	public Mode getMode(){
		return Mode.values()[getNativeMode()];
	}
	
	private native int getNativeMode();
	
	public native void setDuration(int msecs);
	
	public native int getDuration();
	
	public native void setLoop(boolean loop);
	
	public native boolean isLoop();
	
	public native void setTimeline(Timeline timeline);
	
	public native Timeline getTimeline();
	
	public native void setAlpha(Alpha alpha);
	
	public native Alpha getAlpha();
	
	public void stop(){
		completed();
	}
	
	protected native void completed();
	
	public Animation bind(String property, Object value) {
		if (value.getClass() == int.class){
			bindInteger(property, (int[]) value);
		}
		return this;
	}
	
	public Animation bind(String property, double ... value){
		bindDouble(property, value);
		return this;
	}
	
	public Animation bind(String property, int ... value){
		bindInteger(property, value);
		return this;
	}
	
	public Animation bind(String property, float ... value){
		bindFloat(property, value);
		return this;
	}
	
	public Animation bind(String property, boolean ... value){
		bindBoolean(property, value);
		return this;
	}
	
	public native void bindBoolean(String property, boolean ... value);
	
	public native void bindLong(String property, long ... value);
	
	public native void bindDouble(String property, double ... value);
	
	public native void bindChar(String property, char ... value);
	
	public native void bindInteger(String property, int ... value);
	
	public native void bindFloat(String property, float ... value);
	
	public native boolean hasProperty(String property);
	
	public native void unbindProperty(String property);
	
	public void onCompleted(){
	}
	
	public void onStarted(){
	}
	
	
	

}
