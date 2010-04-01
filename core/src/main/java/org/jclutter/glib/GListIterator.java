package org.jclutter.glib;

import java.util.ListIterator;

public class GListIterator<T extends GObject> implements ListIterator<T> {
	
	protected int pointer;
	
	protected GListIterator(int handle){
		this.pointer = handle;
	}
	
	@Override
	public native boolean hasNext();
	
	@Override
	public native T next();
	
	public native T previous();
	
	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public native void add(T e);

	@Override
	public native boolean hasPrevious();

	@Override
	public native int nextIndex();

	@Override
	public native int previousIndex();

	@Override
	public native void set(T e);

}
