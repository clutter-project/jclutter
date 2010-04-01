package org.jclutter;

import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

import org.jclutter.animation.Alpha;
import org.jclutter.animation.Animation;
import org.jclutter.animation.Mode;
import org.jclutter.animation.Timeline;
import org.jclutter.events.ActorListener;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.CrossingEvent;
import org.jclutter.events.Event;
import org.jclutter.events.EventCallback;
import org.jclutter.events.KeyEvent;
import org.jclutter.events.MotionEvent;
import org.jclutter.events.ScrollEvent;
import org.jclutter.glib.GObject;
import org.jclutter.pango.Layout;
import org.jclutter.pango.PangoContext;


/**
 * Base abstract class for all visual stage actors.
 * 
 *
 */
public abstract class Actor extends GObject {
	
	/** Height for width requests */
	public static final int REQUEST_HEIGHT_FOR_WIDTH = 0;
	/** Width for height requests */
	public static final int REQUEST_WIDTH_FOR_HEIGHT = 1;
	
	/** Flags used to signal the state of an actor.
	 * the actor will be painted (is visible, and inside a toplevel, and all parents visible) */
	public static final int FLAG_MAPPED    = 1 << 1;
	/** the resources associated to the actor have been allocated  */
	public static final int FLAG_REALIZED  = 1 << 2;
	/** the actor 'reacts' to mouse events emmitting event signals */
	public static final int FLAG_REACTIVE  = 1 << 3;
	/** the actor has been shown by the application program */
	public static final int FLAG_VISIBLE   = 1 << 4;
	/** the actor provides an explicit layout management policy for its children; this flag will prevent Clutter from automatic queueing of relayout and will defer all layouting to the actor itself */
	public static final int FLAG_NO_LAYOUT = 1 << 5;

	
	public static final int ALLOCATION_NONE         = 0;
	public static final int ABSOLUTE_ORIGIN_CHANGED = 1 << 1;
	
	public static final int TEXT_DIRECTION_DEFAULT = 0;
	public static final int TEXT_DIRECTION_LTR     = 1;
	public static final int TEXT_DIRECTION_RT      = 2;
	
	public static final String SIGNAL_ALLOC_CHANGED =   "allocation-changed";
	public static final String SIGNAL_BUTTON_PRESS = "button-press-event";
	public static final String SIGNAL_BUTTON_RELEASE = "button-release-event";
	public static final String SIGNAL_CAPTURED = "captured-event";
	public static final String SIGNAL_DESTROY = "destroy";
	public static final String SIGNAL_ENTER = "enter-event";
	public static final String SIGNAL_EVENT = "event";
	public static final String SIGNAL_HIDE = "hide";
	public static final String SIGNAL_FOCUS_IN = "key-focus-in";
	public static final String SIGNAL_FOCUS_OUT = "key-focus-out";
	public static final String SIGNAL_KEY_PRESS = "key-press-event";
	public static final String SIGNAL_KEY_RELEASE = "key-release-event";
	public static final String SIGNAL_LEAVE = "leave-event";
	public static final String SIGNAL_MOTION = "motion-event";
	public static final String SIGNAL_PAINT = "paint";
	public static final String SIGNAL_PARENT_SET = "parent-set";
	public static final String SIGNAL_PICK = "pick";
	public static final String SIGNAL_QUEUE_REDRAW = "queue-redraw";
	public static final String SIGNAL_QUEUE_RELAYOUT = "queue-relayout";
	public static final String SIGNAL_REALIZE = "realize";
	public static final String SIGNAL_SCROLL = "scroll-event";
	public static final String SIGNAL_SHOW =  "show";
	public static final String SIGNAL_UNREALIZE =  "unrealize";
	
	
	private ActorListener<Actor> listener = null;
	
	private KeyBinding keyBinding = null;

	protected Actor(int id){
		super(id);
	}
	
	public void setListener(ActorListener<Actor> li) {
		listener = li;
		
		if (li.hasKeyBinding() & findSignalHandler(SIGNAL_KEY_PRESS)==null ){
			Method keyMethod = null;
			try {
				keyMethod = getClass().getMethod("onKeyPressEvent", new Class[]{KeyEvent.class});
			} catch (Exception e) {
			}
			super.connectSignal(Actor.SIGNAL_KEY_PRESS, keyMethod, 0);
		}
		
		super.setListener(listener);
	}
	
	/**
	 * Will create one if it s null.
	 * @return
	 */
	public synchronized KeyBinding getKeyBinding() {
		if (keyBinding == null){
			keyBinding = new KeyBinding();
		}
		return keyBinding;
	}
	
	public void setKeyBinding(KeyBinding keyBinding) {
		this.keyBinding = keyBinding;
	}
	
	public Color getColor() {
		return null;
	}

	public boolean setColor(Color color) {
		return false;
	}

	public native void setFlags(int flags);
	
	public native void unsetFlags(int flags);
	
	public native int getFlags();
	
	public native void show();

	public native void showAll();

	public native void hide();

	public native void hideAll();

	public native void realize();

	public native void unrealize();

	public native void paint();

	public native void queueRedraw();

	public native void queueRelayout();

	public native void destroy();

	public native void pick(int color);

	public native boolean shouldPickPaint();
	
	public native void map();
	
	public native void unmap();
	
	protected native void allocate(ActorBox box, int allocation);

    protected native void allocatePreferredSize(int allocation);

	public native ActorBox getAllocationBox();

	public native Geometry getAllocationGeometry();

	/**
	 * Calculates the transformed coordinates of the four corners of the actor in the plane of ancestor. The returned vertices relate to the ClutterActorBox coordinates as follows:
      v[0] contains (x1, y1)
      v[1] contains (x2, y1)
      v[2] contains (x1, y2)
      v[3] contains (x2, y2)
	 * @param ancestor
	 * @return positions
	 */
	public native Point [] getAllocationVertices(Actor ancestor);
	
	public native Dimension getPreferredSize();
	
	public native Dimension getMinimumSize();

	public native int getPreferredWidth(int forHeight);

	public native int getPreferredHeight(int forWidth);

	public native void setPositionFixed(boolean isSet);

	public native boolean isPositionFixed();

	public native void setGeometry(Geometry geom);

	public native Geometry getGeometry();

	
	public void setSize(Dimension dim){
		setSize(dim.width, dim.height);
	}
	/**
	 * @param width
	 * @param height
	 */
	public native void setSize(float width, float height);

	public void setSize(int x, int y){
		this.setSize((float)x, (float)y);
	}
	
	public native Dimension getSize();

	
	public void setPosition(Point p){
		setPosition(p.x, p.y);
	}
	/**
	 * 
	 * @param x
	 * @param y
	 */
	public native void setPosition(float x, float y);
	
	public void setPosition(int x, int y){
		this.setPosition((float)x, (float)y);
	}

	public native Point getPosition();

	/**
	 * 
	 * @param width
	 */
	public native void setWidth(float width);

	public native float getWidth();

	/**
	 * 
	 * @param height
	 */
	public native void setHeight(float height);

	public native float getHeight();

	public native void setX(float x);

	public native float getX();

	public native void setY(float y);

	public native float getY();
	
	public void moveBy(Point p){
		moveBy(p.x, p.y);
	}

	public native void moveBy(float dx, float dy);

	public void setRotation(Rotation rotation){
		setRotation(rotation.axis, rotation.angle, rotation.center.x, rotation.center.y, rotation.center.z);
	}
	
	public native void setRotation(int axis, double angle, float x, float y, float z);
	
	public void setZRotationFromGravity(double angle, Gravity gravity){
		this.setZRotationFromGravity(angle, gravity.ordinal());
	}
	
	private native void setZRotationFromGravity(double angle, int gravity);

	public native Rotation getRotationAtAxis(int axis);

	public native boolean isRotated();

	/**
	 * Sets the actor's opacity, with zero being completely transparent and 255 (0xff) being fully opaque.
	 * @param opacity
	 */
	public native void setOpacity(int opacity);

	public native int getOpacity();

	public native void setName(String string);

	public native String getName();

	public native int getGid();
	
	public void setClip(Point position, Dimension size){
		setClip(position.x, position.y, size.width, size.height);
	}

	public native void setClip(float xOff, float yOff, float width, float height);

	public native Point getClipPosition();
	
	public native Dimension getClipSize();

	public native void removeClip();

	public native boolean hasClip();
	
	public native Container getParent();

	public native void raise(Actor below);

	public native void lower(Actor above);

	public native void raiseTop();

	public native void lowerBottom();

	public native Stage getStage();

	public native void setDepth(float depth);

	public native float getDepth();
	
	public void setScale(Scale scale){
		setScale(scale.x, scale.y, scale.center);
	}

	public void setScale(double scaleX, double scaleY){
		setScale(scaleX, scaleY, null);
	}
	
	public native void setScale(double scaleX, double scaleY, Point center);
	
	// TODO native
	public native void setScaleWithGravity(double scaleX, double scaleY, Gravity gravity);

	public native Gravity getScaleGravity();
	
	public native Scale getScale();

	public native boolean isScaled();

	public native Point applyTransformToPoint(Point point);

	public native Point transformStagePoint(float x, float y);

	public native Point applyRelativeTransformToPoint(Actor ancestor,
			Point point);

	public native Point getTransformedPosition();

	public native Dimension getTransformedSize();

	public native int getPaintOpacity();
	
	public native boolean getPaintVisibility();

	public native Point[] getAbsAllocationVertices();
	
	public native void setAnchorPoint(float anchor_x, float anchor_y);

	public native Point getAnchorPoint();

	public void setAnchorPointFromGravity(Gravity gravity){
		setAnchorPointFromGravity(gravity.ordinal());
	}
	
	private native void setAnchorPointFromGravity(int gravity);

	public native void moveAnchorPoint(float anchor_x, float anchor_y);

	public void moveAnchorPointFromGravity(Gravity gravity){
		moveAnchorPointFromGravity(gravity.ordinal());
	}
	
	private native void moveAnchorPointFromGravity(int gravity);

	public native void setReactive(boolean reactive);

	public native boolean isReactive();

	public native boolean setShader(Shader shader);

	public native Shader getShader();
	
	public void setShaderParam(String param, float value){
		setShaderParamFloat(param, value);
	}
	
	public void setShaderParam(String param, int value){
		setShaderParamInt(param, value);
	}

	protected native void setShaderParamFloat(String param, float value);
	
	protected native void setShaderParamInt(String param, int value);
	
	public native void grabKeyFocus();
	
	public native PangoContext getPangoContext();
	
	public native PangoContext createPangoContext();
	
	public native Layout createPangoLayout(String text);
	
	public native boolean isInClonePaint();
	
	public native void setTextDirection(int direction);
	
	public native int getTextDirection();
	
	@Override
	protected void finalize() throws Throwable {
		getParent().refs.remove(this);
		destroy();
		super.finalize(); // not sure
	}
	
	public native boolean isMapped();
	
	public Animation animate(Mode mode, int duration, Object ... props){
		return animate(mode, null, null, duration, props);
	}
	
	public Animation animate(Mode mode, Timeline timeline, Object ... props){
		return animate(mode, null, timeline, -1, props);
	}
	
	public Animation animate(Alpha alpha, Object ... props){
		return animate(null, alpha, null, -1, props);
	}

	
	protected Animation animate(Mode mode, Alpha alpha, Timeline timeline, int duration, Object ... propvals){
		Animation animation = new Animation();
		animation.setActor(this);
		animation.setTimeline(timeline);
		if (alpha != null)
		animation.setAlpha(alpha);
		if (mode != null)
		animation.setMode(mode);
		if (duration > 0)
		animation.setDuration(duration);
		
		ValuesHolder vh = new ValuesHolder();
		vh.property = (String)propvals[0];
		vh.type = super.getGType(vh.property);
		List<ValuesHolder> li = new ArrayList<ValuesHolder>();
		int j = 0;
		for (int i = 1; i < propvals.length; i++) {
			if (propvals[i].getClass() == String.class){
				li.add(vh);
				vh = new ValuesHolder();
				vh.property = (String) propvals[i];
				vh.type = super.getGType((String)propvals[i]);
				if (vh.type == -1){
					throw new IllegalArgumentException("No type associated to property "+propvals[i]);
				}
			} else {
				j = (vh.objs[0] == null) ? 0:1;
				vh.objs[j] = propvals[i];
			}
		}
		li.add(vh);
		for (ValuesHolder h: li){
			switch (h.type) {
			case G_TYPE_FLOAT:
				animation.bindFloat(h.property, h.asFloat());
				break;
			case G_TYPE_INT:
				animation.bindInteger(h.property, h.asInt());
				break;
			case G_TYPE_DOUBLE:
				animation.bindDouble(h.property, h.asDouble());
				break;
			case G_TYPE_LONG:
				animation.bindLong(h.property, h.asLong());
				break;
			case G_TYPE_UCHAR:
				animation.bindChar(h.property, h.asChar());
				break;
			case G_TYPE_BOOLEAN:
				animation.bindBoolean(h.property, h.asBoolean());
				break;

			default:
				break;
			}
		}
		vh = null;
		li = null;
		System.out.println("start");
		timeline = animation.getTimeline();
		System.out.println("timeline ="+timeline);
		timeline.start();
		System.out.println("started");
		return animation;
	}

	public native Animation getAnimation();
	
	@Override
	public String toString() {
		return getClass().getSimpleName()+ "("+super.hashCode()+")";
	}
	// events
	
	@EventCallback(ignore=true)
	public boolean onAllocationChanged(ActorBox box, int flags){
		return listener.onAllocationChanged(this, box, flags);
	}
	@EventCallback(ignore=true)
	public boolean onButtonPressEvent(ButtonEvent event){
		return listener.onButtonPressEvent(this, event);
	}
	@EventCallback(ignore=true)
	public boolean onButtonReleaseEvent(ButtonEvent event){
		return listener.onButtonReleaseEvent(this, event);
	}
	@EventCallback(ignore=true)
	public boolean onCapturedEvent(Event event){
		return listener.onCapturedEvent(this, event);
	}
	@EventCallback(ignore=true)
	public void onDestroy(){
		listener.onDestroy(this);
	}
	@EventCallback(ignore=true)
	public boolean onEnterEvent(CrossingEvent event){
		return listener.onEnterEvent(this, event);
	}
	@EventCallback(ignore=true)
	public boolean onEvent(Event event){
		return listener.onEvent(this, event);
	}
	@EventCallback(ignore=true)
	public void onHide(){
		listener.onHide(this);
	}
	@EventCallback(ignore=true)
	public void onKeyFocusIn(){
		listener.onKeyFocusIn(this);
	}
	@EventCallback(ignore=true)
	public void onKeyFocusOut(){
		listener.onKeyFocusOut(this);
	}
	@EventCallback(ignore=true)
	public boolean onKeyPressEvent(KeyEvent event){
		if (keyBinding != null) keyBinding.activate(event.getKeyCode(), event.getModifierState(), true);
		return listener.onKeyPressEvent(this, event);
	}
	@EventCallback(ignore=true)
	public boolean onKeyReleaseEvent(KeyEvent event){
		return listener.onKeyReleaseEvent(this, event);
	}
	@EventCallback(ignore=true)
	public boolean onLeaveEvent(CrossingEvent event){ 
		return listener.onLeaveEvent(this, event);
	}
	@EventCallback(ignore=true)
	public boolean onMotionEvent(MotionEvent event){
		return listener.onMotionEvent(this, event);
	}
	@EventCallback(ignore=true)
	public void onPaint(){
		listener.onPaint(this);
	}
	@EventCallback(ignore=true)
	public void onParentSet(){
		listener.onParentSet(this);
	}
	@EventCallback(ignore=true)
	public void onPick(Color color){
		listener.onPick(this, color);
	}
	@EventCallback(ignore=true)
	public void onQueueRedraw(Actor origin){
		listener.onQueueRedraw(this, origin);
	}
	@EventCallback(ignore=true)
	public void onRealize(){
		listener.onRealize(this);
	}
	@EventCallback(ignore=true)
	public boolean onScrollEvent(ScrollEvent event){
		return listener.onScrollEvent(this, event);
	}
	@EventCallback(ignore=true)
	public void onShow(){
		listener.onShow(this);
	}
	@EventCallback(ignore=true)
	public void onUnrealize(){
		listener.onUnrealize(this);
	}
	
	
	private class ValuesHolder {
		
		Object [] objs = new Object[2];
		int type;
		String property;
		
		boolean isInterval(){
			return objs[1]!=null;
		}
		
		float [] asFloat(){
			if (isInterval()) return new float[]{asFloat(0), asFloat(1)};
			else return new float[]{asFloat(0)};
		}
		
		double [] asDouble(){
			if (isInterval()) return new double[]{asDouble(0), asDouble(1)};
			else return new double[]{asDouble(0)};
		}
		
		int [] asInt(){
			if (isInterval()) return new int[]{asInt(0), asInt(1)};
			else return new int[]{asInt(0)};
		}
		
		@SuppressWarnings("unused")
		byte [] asByte(){
			if (isInterval()) return new byte[]{asByte(0), asByte(1)};
			else return new byte[]{asByte(0)};
		}
		
		long [] asLong(){
			if (isInterval()) return new long[]{asLong(0), asLong(1)};
			else return new long[]{asLong(0)};
		}
		
		boolean [] asBoolean(){
			if (isInterval()) return new boolean[]{asBoolean(0), asBoolean(1)};
			else return new boolean[]{asBoolean(0)};
		}
		
		float asFloat(int i){
			return ((Number)objs[i]).floatValue();
		}
		
		double asDouble(int i){
			return ((Number)objs[i]).doubleValue();
		}
		
		int asInt(int i){
			return ((Number)objs[i]).intValue();
		}
		
		byte asByte(int i){
			return ((Number)objs[i]).byteValue();
		}
		
		long asLong(int i){
			return ((Number)objs[i]).longValue();
		}
		
		boolean asBoolean(int i){
			if (objs[i] instanceof Number) return ((Number)objs[i]).intValue() == 1;
			else return (Boolean)objs[i];
		}
		
		char [] asChar(){
			if (isInterval()) return new char[]{asChar(0), asChar(1)};
			else return new char[]{asChar(0)};
		}
		
		char asChar(int i){
			return (Character)objs[i];
		}
		
	}	
	
}
