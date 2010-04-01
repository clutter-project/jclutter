package org.jclutter.ext.gst;

import org.jclutter.Media;
import org.jclutter.MediaSupport;
import org.jclutter.Texture;

/**
 * The GStreamer Video actor binding implementation.
 *
 */
public class Video extends Texture implements Media {

	static {
		// TODO pass environment parameters.
		init(null);
	}
	
	public Video() {
		super(newInstance());
	}
	
	protected static final native void init(String [] args);
	
	public static final native int getMajorVersion();
	public static final native int getMinorVersion();
	public static final native int getMicroVersion();
	public static final native String getVersion();
	public static final native boolean checkVersion(int major, int minor, int micro);
	
	// TODO Gst Element support ?
	
	private static final native int newInstance();
	
	@Override
	public double getAudioVolume() {
		return MediaSupport.getAudioVolume(this);
	}
	@Override
	public double getBufferFill() {
		return MediaSupport.getBufferFill(this);
	}
	@Override
	public int getDuration() {
		return MediaSupport.getDuration(this);
	}
	@Override
	public double getProgress() {
		return MediaSupport.getProgress(this);
	}
	@Override
	public String getUri() {
		return MediaSupport.getUri(this);
	}
	@Override
	public boolean isCanSeek() {
		return MediaSupport.isCanSeek(this);
	}
	@Override
	public boolean isPlaying() {
		return MediaSupport.isPlaying(this);
	}
	@Override
	public void setAudioVolume(double volume) {
		MediaSupport.setAudioVolume(this, volume);
	}
	@Override
	public void setFilename(String filename) {
		MediaSupport.setFilename(this, filename);
	}
	@Override
	public void setPlaying(boolean playing) {
		MediaSupport.setPlaying(this, playing);
	}
	@Override
	public void setProgress(double progress) {
		MediaSupport.setProgress(this, progress);
	}
	@Override
	public void setUri(String uri) {
		MediaSupport.setUri(this, uri);
	}

	@Override
	public String getSubtitleFontname() {
		return MediaSupport.getSubtitleFontname(this);
	}

	@Override
	public String getSubtitleUri() {
		return MediaSupport.getSubtitleUri(this);
	}

	@Override
	public void setSubtitleFontname(String font) {
		MediaSupport.setSubtitleFontname(this, font);
	}

	@Override
	public void setSubtitleUri(String uri) {
		MediaSupport.setSubtitleUri(this, uri);
	}
	
	

}
