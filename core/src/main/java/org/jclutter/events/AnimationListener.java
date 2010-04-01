package org.jclutter.events;

import org.jclutter.animation.Animation;

public interface AnimationListener extends EventListener {
	
	public void onStarted(Animation animation);
	
	public void onCompleted(Animation animation);

}
