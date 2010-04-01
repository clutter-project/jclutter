package org.jclutter.events;

import org.jclutter.Actor;
import org.jclutter.InputDevice;
import org.jclutter.Point;
import org.jclutter.Stage;

public class Event {

	public static final int FLAG_NONE = 0;
	public static final int FLAG_SYNTHETIC = 1 << 0;

	// enum ClutterEventType
	public static final int TYPE_NOTHING = 0;
	public static final int TYPE_KEY_PRESS = 1;
	public static final int TYPE_KEY_RELEASE = 2;
	public static final int TYPE_MOTION = 3;
	public static final int TYPE_ENTER = 4;
	public static final int TYPE_LEAVE = 5;
	public static final int TYPE_BUTTON_PRESS = 6;
	public static final int TYPE_BUTTON_RELEASE = 7;
	public static final int TYPE_SCROLL = 8;
	public static final int TYPE_STAGE_STATE = 9;
	public static final int TYPE_DESTROY_NOTIFY = 10;
	public static final int TYPE_CLIENT_MESSAGE = 11;
	public static final int TYPE_DELETE = 12;

	// ClutterModifierType
	public static final int STATE_SHIFT_MASK = 1 << 0;
	public static final int STATE_LOCK_MASK = 1 << 1;
	public static final int STATE_CONTROL_MASK = 1 << 2;
	public static final int STATE_MOD1_MASK = 1 << 3;
	public static final int STATE_MOD2_MASK = 1 << 4;
	public static final int STATE_MOD3_MASK = 1 << 5;
	public static final int STATE_MOD4_MASK = 1 << 6;
	public static final int STATE_MOD5_MASK = 1 << 7;
	public static final int STATE_BUTTON1_MASK = 1 << 8;
	public static final int STATE_BUTTON2_MASK = 1 << 9;
	public static final int STATE_BUTTON3_MASK = 1 << 10;
	public static final int STATE_BUTTON4_MASK = 1 << 11;
	public static final int STATE_BUTTON5_MASK = 1 << 12;
	
	protected int pointer;

	private Point point;
	
	protected Event(int nid) {
		pointer = nid;
	}
	/**
	 * 
	 * @return eventType
	 */
	public native int getType();

	public native int getTime();

	public native int getFlag();

	public native Stage getStage();

	public native Actor getSource();

	private native void free();
	
	public static final native boolean eventsPending();
	
	protected native int getClickCount();

	protected native int getButton();
	
	protected Point getPoint(){
		if (point == null) point = getCoords();
		return point;
	}
	
	protected native Point getCoords();

	protected float getY(){
		return getPoint().x;
	}
	
	protected float getX(){
		return getPoint().y;
	}
	
	protected native int getKeySymbol();
	
	protected native int getKeyCode();
	
	protected native char getKeyUnicode();

	protected native int getModifierState();
	
	protected native int getDeviceId();
	
	protected native int getDirection();
	
	protected native Actor getRelated();

	protected native InputDevice getInputDevice();
	
	@Override
	protected void finalize() throws Throwable {
		free();
	}
	
	protected final static Event createEvent(int type, int id){
		switch (type) {
		case TYPE_KEY_PRESS:
			return new KeyEvent(id);
		case TYPE_KEY_RELEASE:
			return new KeyEvent(id);
		case TYPE_MOTION:
			return new MotionEvent(id);
		case TYPE_ENTER:
			return new CrossingEvent(id);
		case TYPE_LEAVE:
			return new CrossingEvent(id);
		case TYPE_BUTTON_PRESS:
			return new ButtonEvent(id);
		case TYPE_BUTTON_RELEASE:
			return new ButtonEvent(id);
		case TYPE_SCROLL:
			return new ScrollEvent(id);
		case TYPE_STAGE_STATE:
			return null; // TODO
		default:
			return new Event(id);
		}
	}
	
}
