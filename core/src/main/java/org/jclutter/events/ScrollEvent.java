package org.jclutter.events;

import org.jclutter.InputDevice;
import org.jclutter.Point;


public class ScrollEvent extends Event {
	
	// TODO: refactor to direction
	public static final int SCROLL_UP = 0;
	public static final int SCROLL_DOWN = 1;
	public static final int SCROLL_LEFT = 2;
	public static final int SCROLL_RIGHT = 3;

	
	protected ScrollEvent(int nid) {
		super(nid);
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
	
	@Override
	public int getDirection() {
		return super.getDirection();
	}
}
