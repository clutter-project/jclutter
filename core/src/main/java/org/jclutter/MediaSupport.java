package org.jclutter;

public class MediaSupport {

	public static native void setUri(Actor actor, String uri);
	
	public static native String getUri(Actor actor);
	
	public static native void setSubtitleUri(Actor actor, String uri);
	
	public static native String getSubtitleUri(Actor actor);
	
	public static native void setSubtitleFontname(Actor actor, String font);
	
	public static native String getSubtitleFontname(Actor actor);
	
	public static native void setPlaying(Actor actor, boolean playing);
	
	public static native boolean isPlaying(Actor actor);
	
	public static native void setProgress(Actor actor, double progress);
	
	public static native double getProgress(Actor actor);
	
	public static native void setAudioVolume(Actor actor, double volume);
	
	public static native double getAudioVolume(Actor actor);
	
	public static native boolean isCanSeek(Actor actor);
	
	public static native double getBufferFill(Actor actor);
	
	public static native int getDuration(Actor actor);
	
	public static native void setFilename(Actor actor, String filename);

}
