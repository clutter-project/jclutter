package org.jclutter;

import org.jclutter.animation.Mode;

public class BoxLayout extends LayoutManager {

	public static final int START = 0;
	public static final int END = 1;
	public static final int CENTER = 2;

	public BoxLayout() {
		super(newInstance());
	}

	private static native int newInstance();

	public native void setPackStart(boolean pack_start);

	public native boolean isPackStart();

	public native void setSpacing(int spacing);

	public native int getSpacing();

	public native void setVertical(boolean vertical);

	public native boolean isVertical();

	public native void pack(Actor actor, boolean expand, boolean x_fill,
			boolean y_fill, int x_align, int y_align);

	public native void setAlignment(Actor actor, int x_align, int y_align);

	public native int getAlignmentX(Actor actor);

	public native int getAlignmentY(Actor actor);

	public native void setExpand(Actor actor, boolean expand);

	public native boolean isExpand(Actor actor);

	public native void setFill(Actor actor, boolean x_fill, boolean y_fill);

	public native boolean isFillX(Actor actor);

	public native boolean isFillY(Actor actor);

	public native void setUseAnimations(boolean animate);

	public native boolean isUseAnimations();

	public native void setEasingDuration(int msecs);

	public native int getEasingDuration();

	public  void setEasingMode(Mode mode){
		setEasingMode(mode.ordinal());
	}
	
	private native void setEasingMode(int mode);

	public Mode getEasingMode(){
		return Mode.values()[getEasingModeNative()];
	}
	
	private native int getEasingModeNative();
	
	@Override
	public Constraint getConstraint(Container container, Actor actor) {
		Constraint c = new Constraint();
		c.expand = isExpand(actor);
		c.x_align = getAlignmentX(actor);
		c.y_align = getAlignmentY(actor);
		c.x_fill = isFillX(actor);
		c.y_fill = isFillY(actor);
		return c;
	}
	
	public void setConstraint(Container container, Actor actor, Object o) {
		Constraint c = (Constraint)o;
		setExpand(actor, c.expand);
		setAlignment(actor, c.x_align, c.y_align);
		setFill(actor, c.x_fill, c.y_fill);
	}
	
	public static final class Constraint {
		
		boolean expand; boolean x_fill;
		boolean y_fill; int x_align; int y_align;
		
		public Constraint() {
		}
		
		public Constraint(boolean expand, boolean xFill, boolean yFill,
				int xAlign, int yAlign) {
			super();
			this.expand = expand;
			x_fill = xFill;
			y_fill = yFill;
			x_align = xAlign;
			y_align = yAlign;
		}

		@Override
		public boolean equals(Object obj) {
			if (obj instanceof Constraint){
				Constraint c = (Constraint)obj;
				return (c.expand == expand & x_fill == c.x_fill & y_fill == c.y_fill & x_align == c.x_align & y_align == c.y_align);
			}
			return false;
		}
	}

}
