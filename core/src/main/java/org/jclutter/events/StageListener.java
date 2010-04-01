package org.jclutter.events;

import org.jclutter.Stage;

public interface StageListener extends ActorListener<Stage> {
	
	public void onActivate(Stage stage);

	public void onDeactivate(Stage stage);

	public void onFullscreen(Stage stage);

	public void onUnfullscreen(Stage stage);

}
