package org.jclutter;

public class FlowLayout extends LayoutManager {

	public static final int HORIZONTAL = 0;
	public static final int VERTICAL = 1;

	public FlowLayout() {
		this(VERTICAL);
	}
	
	public FlowLayout(int flowOrientation) {
		super(newInstance(flowOrientation));
	}

	private static native int newInstance(int flowOrientation);

	public native void setHomogeneous(boolean homogeneous);

	public native boolean isHomogeneous();

	public native void setOrientation(int orientation);

	public native int getOrientation();

	public native void setColumnSpacing(float spacing);

	public native float getColumnSpacing();

	public native void setRowSpacing(float spacing);

	public native float getRowSpacing();

	public native void setColumnWidth(float min_width, float max_width);

	public native float getColumnMaxWidth();

	public native float getColumnMinWidth();

	public native void setRowHeight(float min_height, float max_height);

	public native float getRowMaxHeight();

	public native float getRowMinHeight();

	@Override
	public Object getConstraint(Container container, Actor actor) {
		return null;
	}

	@Override
	public void setConstraint(Container container, Actor actor,
			Object constraint) {}

}
