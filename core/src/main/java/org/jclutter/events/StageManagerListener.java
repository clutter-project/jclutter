package org.jclutter.events;

import org.jclutter.Stage;
import org.jclutter.StageManager;

public interface StageManagerListener {
	
	public void onStageAdded(StageManager mgr, Stage stage);
	
	public void onStageRemoved(StageManager mgr, Stage stage);

}
