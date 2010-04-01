package org.jclutter;

public class FixedLayout extends LayoutManager {
	
	public FixedLayout() {
		super(newInstance());
	}

	private static native int newInstance();

	@Override
	public Object getConstraint(Container container, Actor actor) {
		return null;
	}

	@Override
	public void setConstraint(Container container, Actor actor,
			Object constraint) {
	}

}
