package org.jclutter.tests.interactive;

import java.util.Hashtable;
import java.util.List;

import org.jclutter.Actor;
import org.jclutter.Color;
import org.jclutter.InputDevice;
import org.jclutter.InputDeviceManager;
import org.jclutter.Stage;
import org.jclutter.Texture;
import org.jclutter.events.MotionEvent;
import org.jclutter.tests.TestGroup;

public class DevicesTest extends TestGroup {

	List<InputDevice> devices = InputDeviceManager.getDefault().listDevices();

	Hashtable<InputDevice, Actor> deviceActorMap = new Hashtable<InputDevice, Actor>();
	
	@Override
	public void init() {
		Stage.getDefault().setColor(new Color(0x61, 0x64, 0x8c, 0xff));

		if (devices == null) {
			System.err.println("No extended input devices found.");
			return;
		}

		for (InputDevice device : devices) {
			if (device.getDeviceType() == InputDevice.Type.POINTER) {
				System.out.println("Got a pointer device with id : "
						+ device.getDeviceId());
				Texture hand = Texture.createFromFile("src/test/resources/redhand.png");
				deviceActorMap.put(device, hand);
				add(hand);
			}
		}
	}
	
	@Override
	public boolean onMotionEvent(MotionEvent event) {
		InputDevice device = event.getInputDevice();
		Actor hand = deviceActorMap.get(device);
		if (hand != null) {
			hand.setPosition(event.getX(), event.getY());
			return true;
		}
		return false;
	}

}
