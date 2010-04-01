package org.jclutter.animation;

import org.jclutter.glib.GObject;

public class Timeline extends GObject {

	public static final int DIRECTION_FORWARD  = 0;
	public static final int DIRECTION_BACKWARD = 1;
	
	public static final String SIGNAL_NEW_FRAME      = "new-frame";
	public static final String SIGNAL_COMPLETED      = "completed";
	public static final String SIGNAL_MARKER_REACHED = "marker-reached";
	public static final String SIGNAL_PAUSED         = "paused";
	public static final String SIGNAL_STARTED        = "started";
	
	public Timeline(int duration, int delay, boolean loop){
		super(timelineNew(duration));
		setDelay(delay);
		setLoop(loop);
	}
	
	public Timeline(int duration, int delay){
		this(duration, delay, false);
	}
	
	// To be used only by native
	private Timeline(int id){
		super(id);
	}
	
	protected final static Timeline createTimeline(int id){
		return new Timeline(id);
	}

	private static native int timelineNew(int durationInSec);
	
	public native Timeline clone();
	
	public native int getDuration();
	
	public native void setDuration(int duration);
	
	public native boolean isLoop();
	
	public native void setLoop(boolean loop);
	
	public native int getDelay();
	
	public native void setDelay(int msecs);
	
	// FORWARD = 0 .. BACKWARD = 1
	public native int getDirection();
	
	public void swapDirection(){
		if (getDirection()==DIRECTION_FORWARD) setDirection(DIRECTION_BACKWARD);
		else setDirection(DIRECTION_FORWARD);
	}
	
	public native void setDirection(int timelinedirection);
	
	public native void start();
	public native void pause();
	public native void stop();
	public native void rewind();
	public native void skip(int msecs);
	public native void advance(int msecs);
	public native int getCurrentFrame();
	public native int getDelta();
	public native double getProgress();
	public native boolean isPlaying();
	public native int getElapsedTime();
	
	public native void addMarkerAtTime(String name, int msecs);
	
	public native boolean hasMarker(String name);
	
	public native void removeMarker(String name);
	
	public native String [] listMarkers();
	
	public native void advanceToMarker(String name);
	
	public void onCompleted(){}
	
	public void onMarkerReached(String markerName, int elapsedTime){}
	
	public void onNewFrame(int elapsedTime){}
	
	public void onPaused(){}
	
	public void onStarted(){}
	
}
