package org.jclutter;

import java.util.List;

import org.jclutter.glib.GObject;

public class StageManager extends GObject {
	
	public static final String SIGNAL_STAGE_ADDED = "stage-added";
	public static final String SIGNAL_STAGE_REMOVED = "stage-removed";

	private StageManager(int i) {
		super(i);
	}
	
	
	
	private static native int getDefaultId();
	
	// utilize the stage manager functions
	public static native void setDefault(Stage stage);
	
	public static native List<Stage> listStages();
	
}
