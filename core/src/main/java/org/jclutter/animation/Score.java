package org.jclutter.animation;

import java.util.List;

import org.jclutter.glib.GObject;

public class Score extends GObject {
	
	public Score(){
		super(scoreNew());
	}
	
	protected static native int scoreNew();
	
	public native boolean isLoop();
	
	public native void setLoop(boolean loop);
	
	public native long append(Timeline parent, Timeline timeline);
	public native long appendAtMarker(Timeline parent, String markerName, Timeline timeline); 
	public native void remove(long id);
	public native void removeAll();
	public native Timeline getTimeline(long id);
	public native List<Timeline> listTimelines();
	public native void start();
	public native void pause();
	public native void stop();
	public native void rewind();
	public native boolean isPlaying();
	
	// signals
	public void onCompleted(){}
	public void onPaused(){}
	public void onStarted(){}
	public void onTimelineCompleted(Timeline timeline){}
	public void onTimelineStarted(Timeline timeline){}
	
	
}
