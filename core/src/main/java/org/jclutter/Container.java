package org.jclutter;

import java.util.ArrayList;
import java.util.List;


/**
 * This abstract class represents the gobject base inteface for container actors.
 * 
 */
public abstract class Container extends Actor {
	
	protected List<Actor> refs = new ArrayList<Actor>();
	
	public abstract boolean isTopContainer();

	protected Container(int nid) {
		super(nid);
	}
	
	public void add(Actor ... actors){
		for (int i = 0; i < actors.length; i++) {
			refs.add(actors[i]);
		}
		addActors(actors);
	}
	
	private native void addActors(Actor ... actors);
	
	public void remove(Actor ... actors){
		for (int i = 0; i < actors.length; i++) {
			refs.remove(actors[i]);
		}
		removeActors(actors);
	}
	
	private native void removeActors(Actor ... actors);
	
	/**
	 * 
	 */
	public List<Actor> getChildren(){
		return new ArrayList<Actor>(refs);
	}

	public native Actor findChildByName(String childName);
	
	public void raise(Actor child, Actor sibling){
		raiseChild(child, sibling);
	}

	public void lower(Actor child, Actor sibling){
		lowerChild(child, sibling);
	}

	private native void raiseChild(Actor actor, Actor sibling);

	private native void lowerChild(Actor actor, Actor sibling);

	public native void sortDepthOrder();

//	void childSet(Actor actor, String propname, Object value);
//
//	Object childGet(Actor actor, String propertyName);

}