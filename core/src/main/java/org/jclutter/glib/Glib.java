package org.jclutter.glib;

public class Glib {

	/**
	 * Forces the text direction of every Pango layout inside Clutter. Valid values are: ltr or rtl
	 */
	public static final String CLUTTER_TEXT_DIRECTION = "CLUTTER_TEXT_DIRECTION";
	/**
	 * Prints out the frames per second achieved by Clutter.
	 */
	public static final String CLUTTER_SHOW_FPS = "CLUTTER_SHOW_FPS";
	/**
	 * Sets the default framerate.
	 */
	public static final String CLUTTER_DEFAULT_FPS = "CLUTTER_DEFAULT_FPS";
	/**
	 * Disables mipmapping when rendering text.
	 */
	public static final String CLUTTER_DISABLE_MIPMAPPED_TEXT = "CLUTTER_DISABLE_MIPMAPPED_TEXT";
	/**
	 * Enables "fuzzy picking".
	 */
	public static final String CLUTTER_FUZZY_PICK = "CLUTTER_FUZZY_PICK";
	/**
	 * Enables debugging modes for Clutter.
	 */
	public static final String CLUTTER_DEBUG = "CLUTTER_DEBUG";
		
	/**
	 * Enables debugging modes for COGL.
	 */
	public static final String COGL_DEBUG = "COGL_DEBUG";
	
	/**
	 * Selects the sync-to-vblank mode to be used. Valid values are: none, dri or glx
	 */
	public static final String CLUTTER_VBLANK = "CLUTTER_VBLANK";
	
	private static final String [] PROPERTIES = {
		CLUTTER_TEXT_DIRECTION, CLUTTER_SHOW_FPS, CLUTTER_DEFAULT_FPS,
		CLUTTER_DISABLE_MIPMAPPED_TEXT, CLUTTER_FUZZY_PICK, CLUTTER_DEBUG, COGL_DEBUG
	};
		
	/**
	 * Initialize GLib's threading support.
	 */
	public static native void threadInit();
	/**
	 * Checks if any sources have pending events for the default context
	 * @return true if events are pending
	 */
	public static native boolean mainContextPending();

	/**
	 * Runs a single iteration with the default context.
	 * @param block wether the call may block
	 */
	public static native boolean mainContextIteration(boolean block);
	
	/**
	 * Sets an environment variable
	 * @param variable, must not contain '='.
	 * @param value
	 * @param overwrite whether to change the variable if it already exists
	 */
	public static native boolean setEnv(String variable, String value, boolean overwrite);
	
	public static native void unsetEnv(String variable);
	
	public static native String getEnv(String variable);
	
	/**
	 * This will copy properties passed as system properties (-DXXXX=YYY)
	 * to the Glib environment.
	 */
	public static void copyEnvFromSystem(){
		for(String variable : PROPERTIES){
			String value = System.getProperty(variable);
			if (value != null){
				setEnv(variable, value, true);
			}
		}
	}
	
	

}
