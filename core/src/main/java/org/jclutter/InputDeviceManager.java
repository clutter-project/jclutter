package org.jclutter;

import java.util.List;

import org.jclutter.glib.GObject;

public class InputDeviceManager extends GObject {
	
	public static final String SIGNAL_DEVICE_ADDED = "device-added";
	public static final String SIGNAL_DEVICE_REMOVED = "device-removed";

	private static InputDeviceManager singleton = null;
	
	private InputDeviceManager(int id) {
		super(id);
	}
	
	private static native int getDefaultId();
	
	public synchronized static InputDeviceManager getDefault(){
		if (singleton == null){
			singleton = new InputDeviceManager(getDefaultId());
		}
		return singleton;
	}
	
	public native List<InputDevice> listDevices();
	
	public native InputDevice getInputDevice(int id);
	
	

}
