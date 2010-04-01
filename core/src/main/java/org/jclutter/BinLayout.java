package org.jclutter;

public class BinLayout extends LayoutManager {

	public static final int FIXED = 0;
	public static final int FILL = 1;
	public static final int START = 2;
	public static final int END = 3;
	public static final int CENTER = 4;

	public BinLayout(int def_x_align, int def_y_align) {
		super(newInstance(def_x_align, def_y_align));
	}

	private static native int newInstance(int x, int y);

	public native void setAlignment(Actor child,
			int x_align, int y_align);

	public Alignment getAlignment(Actor child){
		return new Alignment(getAlignmentX(child), getAlignmentY(child));
	}
	
	private native int getAlignmentX(Actor child);
	
	private native int getAlignmentY(Actor child);

	public native void add(Actor child, int x_align,
			int y_align);

	@Override
	public Alignment getConstraint(Container container, Actor child) {
		return getAlignment(child);
	}

	@Override
	public void setConstraint(Container container, Actor child,
			Object c) {
		Alignment a = (Alignment)c;
		setAlignment(child, a.x_align, a.y_align);
	}
	
	public static class Alignment {
		public Alignment(int x, int y) {
			this.x_align = x;
			this.y_align = y;
		}
		int x_align;
		int y_align;
	}

}
