package org.jclutter.events;

import org.jclutter.InputDevice;
import org.jclutter.InputDeviceManager;

public interface InputDeviceManagerListener extends EventListener {
	
	public void onDeviceAdded(InputDeviceManager mgr, InputDevice device);
	
	public void onDeviceRemoved(InputDeviceManager mgr, InputDevice device);

}
