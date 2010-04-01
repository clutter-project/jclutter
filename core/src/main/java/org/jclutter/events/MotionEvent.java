package org.jclutter.events;

import org.jclutter.InputDevice;
import org.jclutter.Point;


public class MotionEvent extends Event {

	public MotionEvent(int id) {
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
	public int getModifierState() {
		return super.getModifierState();
	}
	
	@Override
	public InputDevice getInputDevice() {
		return super.getInputDevice();
	}

}
