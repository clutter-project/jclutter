package org.jclutter;

import org.jclutter.events.ActorAdapter;


public class Rectangle extends Actor {
	
	public Rectangle() {
		super(rectangleNew());
	}
	
	public Rectangle(Color color){
		super(rectangleNewWithColor(color));
	}
	
	protected Rectangle(int nid){
		super(nid);
		super.setListener(new ActorAdapter<Rectangle>());
	}

	/**
	 * @return pointer
	 */
	private static native int rectangleNew();
	
	private static native int rectangleNewWithColor(Color color);

	@Override
	public native Color getColor();

	@Override
	public native boolean setColor(Color color);

	public native Color getBorderColor();

	public native void setBorderColor(Color color);

	// NOTE: ret value was guint??
	public native int getBorderWidth();

	public native void setBorderWidth(int width);

}
