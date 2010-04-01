package org.jclutter.events;

import org.jclutter.animation.Timeline;

public interface TimelineListener extends EventListener {

	public void onCompleted(Timeline timeline);

	public void onMarkerReached(Timeline timeline, String markerName,
			int elapsedTime);

	public void onNewFrame(Timeline timeline, int elapsedTime);

	public void onPaused(Timeline timeline);

	public void onStarted(Timeline timeline);
	
}
