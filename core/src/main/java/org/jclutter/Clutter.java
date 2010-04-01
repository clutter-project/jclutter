package org.jclutter;



/**
 * 
 * Clutter general API, with versioning macros.
 *
 */
public class Clutter {
	
	public static final int FONT_MIPMAPPING = (1 << 0);
	public static final int FONT_HINTING    = (1 << 1);
	
	public static final int TEXTURE_NPOT           = (1 << 2);
	public static final int SYNC_TO_VBLANK         = (1 << 3);
	public static final int TEXTURE_YUV            = (1 << 4);
	public static final int TEXTURE_READ_PIXELS    = (1 << 5);
	public static final int STAGE_STATIC           = (1 << 6);
	public static final int STAGE_USER_RESIZE      = (1 << 7);
	public static final int STAGE_CURSOR           = (1 << 8);
	public static final int SHADERS_GLSL           = (1 << 9);
	public static final int OFFSCREEN              = (1 << 10);
	public static final int STAGE_MULTIPLE         = (1 << 11);
	public static final int SWAP_EVENTS            = (1 << 12);

	
	static {
		System.loadLibrary("jclutter");
	}
	
	public static final void init(){
		init(new String [] {});
	}
	
	private static final native void init(String [] args) throws ClutterException;
	/**
	 * 
	 */
	public static final native void mainStart() throws ClutterException;

	public static final native void mainQuit();
	
	public static final native int mainLevel();
	
	public static final native boolean isDebugEnabled();
	
	public static final native boolean isShowFps();
	
	public static final native long getTimestamp();
	
	public static final native int getActorPointerByGID(int gid);
	
	public static final native void setDefaultFrameRate(int frames_per_sec);
	
	public static final native int getDefaultFrameRate();
	
	public static final native boolean isMotionEventsEnabled();
	
	public static final native void setMotionEventsEnabled(boolean enable);
	
	public static final native void clearGlyphCache();
	
	public static final native int getFontFlags();
	
	public static final native void setFontFlags(int flags);
	
	public static final native Actor getKeyboardGrab();
	public static final native Actor getPointerGrab();
	public static final native void grabKeyboard(Actor actor);
	public static final native void grabPointer(Actor actor);
	public static final native void ungrabKeyboard();
	public static final native void ungrabPointer();

	public static final native void grabPointerForDevice(Actor actor, int id);
	public static final native void ungrabPointerForDevice(int id);
	
	public static final native int getDefaultTextDirection();
	
	// VERSIONING
	
	public static final native int getMajorVersion();
	public static final native int getMinorVersion();
	public static final native int getMicroVersion();
	public static final native String getVersion();
	public static final native boolean checkVersion(int major, int minor, int micro);
	
	// FEATURES
	
	public static final native boolean hasFeature(int featureflag);
	public static final native int getFeatures();
	
	
//	private static final Map<Integer, Object> callbacks = new HashMap<Integer, Object>();
//
//	private static int INCR = 1000;
//	
//	/**
//	 * Register a callback. Used internally.
//	 * @param cb an object containing a callback method
//	 * @return the callback id
//	 */
//	public synchronized static int registerCallback(Object cb){
//		int callbackId = ++INCR;
//		callbacks.put(callbackId, cb);
//		return callbackId;
//	}
//	
//	/**
//	 * Unregister callback. Used internally.
//	 * @param cb the callback id
//	 */
//	public synchronized static void unregisterCallback(int cb){
//		callbacks.remove(cb);
//	}
//	
//	protected static Object getCallback(int id){
//		return callbacks.get(id);
//	}
	
}
