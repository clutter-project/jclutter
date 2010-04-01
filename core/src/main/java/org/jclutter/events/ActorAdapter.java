package org.jclutter.events;

import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;

import org.jclutter.Actor;
import org.jclutter.ActorBox;
import org.jclutter.Color;
import org.jclutter.KeyAction;

public class ActorAdapter<T extends Actor> implements ActorListener<T> {
	
	private Map<KeyBinding, Method> keyBindings = null;
	
	public ActorAdapter() {
		Method [] ms = getClass().getDeclaredMethods();
		for(Method m : ms){
			if (m.isAnnotationPresent(KeyAction.class)){
				KeyAction ka = m.getAnnotation(KeyAction.class);
				KeyBinding kb = new KeyBinding();
				kb.key = ka.key();
				kb.modifier = ka.modifier();
				if (keyBindings == null) keyBindings = new HashMap<KeyBinding, Method>();
				keyBindings.put(kb, m);
			}
		}
	}
	
	public boolean hasKeyBinding(){
		return (keyBindings != null && keyBindings.size() > 0);
	}

	public boolean onAllocationChanged(T actor, ActorBox alloc, int flags) {
		return false;
	}

	public boolean onButtonPressEvent(T actor, ButtonEvent event) {
		return false;
	}

	public boolean onButtonReleaseEvent(T actor, ButtonEvent event) {
		return false;
	}

	public boolean onCapturedEvent(T actor, Event event) {
		return false;
	}

	public void onDestroy(T actor) {
	}

	public boolean onEnterEvent(T actor, CrossingEvent event) {
		return false;
	}

	public boolean onEvent(T actor, Event event) {
		return false;
	}

	public void onHide(T actor) {	
	}

	public void onKeyFocusIn(T actor) {
	}

	public void onKeyFocusOut(T actor) {	
	}

	public boolean onKeyPressEvent(T actor, KeyEvent event) {
		if (keyBindings != null){
			KeyBinding key = new KeyBinding();
			key.key = event.getKeyCode();
			key.modifier = event.getModifierState();
			if (keyBindings.containsKey(key)){
				Method m = keyBindings.get(key);
				try {
					m.invoke(this);
				} catch (Exception e) {
					e.printStackTrace();
				}
				return true;
			}
		}
		return false;
	}

	public boolean onKeyReleaseEvent(T actor, KeyEvent event) {
		return false;
	}

	public boolean onLeaveEvent(T actor, CrossingEvent event) {
		return false;
	}

	public boolean onMotionEvent(T actor, MotionEvent event) {
		return false;
	}

	public void onPaint(T actor) {	
	}

	public void onParentSet(T actor) {
	}

	public void onPick(T actor, Color color) {		
	}

	public void onQueueRedraw(T actor, Actor origin) {
	}

	public void onRealize(T actor) {		
	}

	public boolean onScrollEvent(T actor, ScrollEvent event) {
		return false;
	}

	public void onShow(T actor) {	
	}

	public void onUnrealize(T actor) {
	}
	
	private class KeyBinding {
		int key;
		int modifier;
		@Override
		public boolean equals(Object obj) {
			return ((KeyBinding)obj).key == key & ((KeyBinding)obj).modifier == modifier;
		}
		
	}

}
