package org.jclutter.events;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

import org.jclutter.glib.GObject;

/**
 * 
 * Associates any method to a specific signal name.
 * Connect with the source of that signal with {@link GObject} connect(). 
 * If no signal name is specified, the method name will be used using the following transformation:
 * "onMethodName" will become "method-name". "onPaint" is for "paint" signal if no name is specified, etc...
 * 
 */
@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
public @interface EventCallback {

	/***
	 * 
	 * @return the signal name
	 */
	String signal() default "";
	
	/**
	 * 
	 * @return the flags for when to call the callback.
	 * @see GObject.CONNECT_BEFORE (default) , GObject.CONNECT_AFTER, GObject.CONNECT_SWAPPED
	 */
	int when() default 0;
	
	
	boolean ignore() default false;
	
}
