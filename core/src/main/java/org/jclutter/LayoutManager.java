package org.jclutter;

import org.jclutter.animation.Alpha;
import org.jclutter.animation.Mode;
import org.jclutter.glib.GObject;

public abstract class LayoutManager extends GObject {
	
	public static final String SIGNAL_LAYOUT_CHANGED = "layout-changed";

	protected LayoutManager(int id) {
		super(id);
	}

	public native float getPreferredWidth(Container container, float for_height);
	
	public native float getMinimumWidth(Container container, float for_height);

	public native float getPreferredHeight(Container container, float for_width);
	
	public native float getMinimumHeight(Container container, float for_width);

	public native void allocate(Container container, ActorBox allocation, int flags);
	
	public abstract void setConstraint(Container container, Actor actor, Object constraint);
	
	public abstract Object getConstraint(Container container, Actor actor);

	public native void layoutChanged();

	public native void setContainer(Container container);

	public native Alpha beginAnimation(int duration, Mode mode);

	public native void endAnimation();

	public native double getAnimationProgress();
	
	public void onLayoutChanged(Actor actor){ // TODO : container ?
	}

}
