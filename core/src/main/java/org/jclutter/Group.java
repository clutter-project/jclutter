package org.jclutter;




public class Group extends Container {
		
	public Group() {
		super(groupNew());
	}

	public Group(int id) {
		super(id);
	}
	
	public static native int groupNew();
	
	public native void removeAll();
	
	public native int getChildrenCount();
	
	public native Actor getChild(int index);
	
	@Override
	public boolean isTopContainer() {
		return false;
	}

}
