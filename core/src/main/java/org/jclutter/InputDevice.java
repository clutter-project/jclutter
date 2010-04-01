package org.jclutter;

import org.jclutter.glib.GObject;


public final class InputDevice extends GObject {
	
	public enum Type {
		POINTER, KEYBOARD, EXTENSION, N_DEVICE
	}
	
	protected InputDevice(int id) {
		super(id);
	}
	
	public Type getDeviceType(){
		return Type.values()[getDeviceTypeInt()];
	}
	
	public native int getDeviceTypeInt();
	
	public native int getDeviceId();

}
