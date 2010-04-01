package org.jclutter.events;

import org.jclutter.Actor;
import org.jclutter.InputDevice;
import org.jclutter.Point;


public class CrossingEvent extends Event {

	protected CrossingEvent(int id) {
		super(id);
	}

	@Override
	public Point getPoint() {
		return super.getPoint();
	}
	
	@Override
	public float getX() {
		return super.getX();
	}
	
	@Override
	public float getY() {
		return super.getY();
	}
	
	@Override
	public InputDevice getInputDevice() {
		return super.getInputDevice();
	}
	
	@Override
	public Actor getRelated() {
		return super.getRelated();
	}
	
}
