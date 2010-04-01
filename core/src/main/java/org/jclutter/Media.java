package org.jclutter;

/**
 * An interface for actors controlling playback of media data.
 * Its methods are implemented by the MediaSupport class.
 * Actual implementations are not provided in jclutter and may be found in subprojects. 
 * 
 */
public interface Media {
	
	public static final String SIGNAL_ERROR         = "error";
	public static final String SIGNAL_END_OF_STREAM = "eos";

	public void setUri(String uri);
	
	public String getUri();
	
	public void setSubtitleUri(String uri);
	
	public String getSubtitleUri();
	
	public void setSubtitleFontname(String font);
	
	public String getSubtitleFontname();
	
	public void setPlaying(boolean playing);
	
	public boolean isPlaying();
	
	public void setProgress(double progress);
	
	public double getProgress();
	
	public void setAudioVolume(double volume);
	
	public double getAudioVolume();
	
	public boolean isCanSeek();
	
	public double getBufferFill();
	
	public int getDuration();
	
	public void setFilename(String filename);
	
}
