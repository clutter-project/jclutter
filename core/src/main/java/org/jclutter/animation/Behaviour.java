package org.jclutter.animation;

import java.util.List;

import org.jclutter.Actor;
import org.jclutter.glib.GObject;

/**
 * Class for providing behaviours to actors
 */
public abstract class Behaviour extends GObject {
	
	protected Behaviour(int ptr) {
		super(ptr);
	}
	
	public native void apply(Actor actor);
	
	public native void remove(Actor actor);
	
	public native void removeAll();
	
	public native boolean isApplied(Actor actor);
	
	public native int getActorCount();
	
	public native List<Actor> getActors();
	
	// TODO : For Each function
	
	public native Actor getActorAt(int index);
	
	public native Alpha getAlpha();

	public native void setAlpha(Alpha alpha);
	
	public void onApplied(){}
	
	public void onRemoved(){}
	
}
