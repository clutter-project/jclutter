package org.jclutter;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class KeyBinding {
	
	

	public void bind() {

	}

	public void activate(int key, int modifier, boolean press) {

	}

	private class KeyBindingHandler {
		int key;
		int modifier;
		boolean press = true;
		Object target;
		Method method;
		
		@Override
		public boolean equals(Object obj) {
			KeyBindingHandler h = (KeyBindingHandler) obj;
			return h.key == key & h.modifier == modifier & h.press == press;
		}
		
		public void execute(){
			try {
				method.invoke(target);
			} catch (IllegalArgumentException e) {
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				e.printStackTrace();
			} catch (InvocationTargetException e) {
				e.printStackTrace();
			}
		}
	}

}
