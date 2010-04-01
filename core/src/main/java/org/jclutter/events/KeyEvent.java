package org.jclutter.events;

import org.jclutter.InputDevice;



public class KeyEvent extends Event {
	
	protected KeyEvent(int nid) {
		super(nid);
	}
	
	@Override
	public int getModifierState() {
		return super.getModifierState();
	}
	
	@Override
	public int getKeyCode() {
		return super.getKeyCode();
	}
	
	@Override
	public int getKeySymbol() {
		return super.getKeySymbol();
	}
	
	@Override
	public char getKeyUnicode() {
		return super.getKeyUnicode();
	}
	
	@Override
	public InputDevice getInputDevice() {
		return super.getInputDevice();
	}
	
}