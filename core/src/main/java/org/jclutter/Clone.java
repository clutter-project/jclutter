package org.jclutter;


public class Clone extends Actor {
	
	public Clone(Actor src){
		super(newInstance(src));
	}
	
	protected Clone(int id) {
		super(id);
	}
	
	private static native int newInstance(Actor actor);

	public native void setSource(Actor src);
	
	public native Actor getSource();

}
