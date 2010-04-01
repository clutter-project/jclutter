package org.jclutter;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
public @interface KeyAction {
	
	public int key();
	
	public int modifier() default 0;
	
	public boolean pressed() default true;

}
