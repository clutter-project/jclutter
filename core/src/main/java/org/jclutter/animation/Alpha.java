package org.jclutter.animation;

import org.jclutter.glib.GObject;


public class Alpha extends GObject {
	
//	public static final int FUNC_LINEAR         = 0;
//	public static final int FUNC_SINE           = 1;
//	public static final int FUNC_SINE_INC       = 2;
//	public static final int FUNC_SINE_DEC       = 3;
//	public static final int FUNC_SINE_HALF      = 4;
//	public static final int FUNC_SQUARE         = 5;
//	public static final int FUNC_SMOOTHSTEP_INC = 6;
//	public static final int FUNC_SMOOTHSTEP_DEC = 7;
//	public static final int FUNC_EXP_INC        = 8;
//	public static final int FUNC_EXP_DEC        = 9;
	
	public Alpha(){
		super(alphaNew());
	}
	
	public Alpha(Timeline timeline, Mode mode){
		super(alphaNewFull(timeline, mode.ordinal()));
	}
	
	public Alpha(Timeline timeline){
		super(alphaNewFull(timeline, 0));
	}
	
	public static native int alphaNew();
	
	private static native int alphaNewFull(Timeline timeline, int alphafunc);
	
	// TODO new full

	public native int getAlpha();
	
	public void setMode(Mode mode){
		setModeNative(mode.ordinal());
	}
	
	public native void setModeNative(int mode);
	
//	public native void setFunc(int alphafunc); // TODO set a function .. more param ?
	
//	public native void setClosure(); TODO set a closure
	
	public native void setTimeline(Timeline timeline);
	
	public native Timeline getTimeline();
	
	// TODO : dummy ?
	
}
