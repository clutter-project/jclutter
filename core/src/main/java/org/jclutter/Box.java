package org.jclutter;

public class Box extends Container {

	// TODO check clutter version
	public Box() {
		super(newInstance(new FixedLayout()));
	}
	
	public Box(LayoutManager layout){
		super(newInstance(layout));
	}

	private native static int newInstance(LayoutManager layout);
	
	public native void setLayoutManager(LayoutManager layout);
	
	public native LayoutManager getLayoutManager();
	
	@Override
	public native Color getColor();

	@Override
	public native boolean setColor(Color color);
	
	
	public void setColor(int color){
		setColor(new Color(color));
	}
	
	@Override
	public boolean isTopContainer() {
		return false;
	}
	
	public void add(Actor actor, Object constraint){
		add(actor);
		getLayoutManager().setConstraint(this, actor, constraint);
	}
	/* use raise and lower instead ?
	public native void packAfter(Actor actor, Actor sibling, Object constraint);
	
	public native void packBefore(Actor actor, Actor sibling, Object constraint);
	
	public native void packAt(Actor actor, int position, Object constraint);
	*/
}
