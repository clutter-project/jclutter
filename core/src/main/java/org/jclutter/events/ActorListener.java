package org.jclutter.events;

import org.jclutter.Actor;
import org.jclutter.ActorBox;
import org.jclutter.Color;

public interface ActorListener<T extends Actor> extends EventListener {
	
	public boolean hasKeyBinding();
	
	public boolean onAllocationChanged(T actor, ActorBox alloc, int flags);

	public boolean onButtonPressEvent(T actor, ButtonEvent event);

	public boolean onButtonReleaseEvent(T actor, ButtonEvent event);
	
	public boolean onCapturedEvent(T actor, Event event);

	public void onDestroy(T actor);

	public boolean onEnterEvent(T actor, CrossingEvent event);

	public boolean onEvent(T actor, Event event);

	public void onHide(T actor);

	public void onKeyFocusIn(T actor);

	public void onKeyFocusOut(T actor);

	public boolean onKeyPressEvent(T actor, KeyEvent event);

	public boolean onKeyReleaseEvent(T actor, KeyEvent event);

	public boolean onLeaveEvent(T actor, CrossingEvent event);

	public boolean onMotionEvent(T actor, MotionEvent event);

	public void onPaint(T actor);

	public void onParentSet(T actor);

	public void onPick(T actor, Color color);

	public void onQueueRedraw(T actor, Actor origin);

	public void onRealize(T actor);

	public boolean onScrollEvent(T actor, ScrollEvent event);

	public void onShow(T actor);

	public void onUnrealize(T actor);
}
