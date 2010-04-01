package org.jclutter.events;

import org.jclutter.InputDevice;
import org.jclutter.Point;



public class ButtonEvent extends Event {
	
	protected ButtonEvent(int nid) {
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
	public int getButton() {
		return super.getButton();
	}
	
	@Override
	public int getClickCount() {
		return super.getClickCount();
	}
	
	@Override
	public InputDevice getInputDevice() {
		return super.getInputDevice();
	}
	
}
