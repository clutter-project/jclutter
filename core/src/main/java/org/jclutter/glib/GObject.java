package org.jclutter.glib;

import java.lang.ref.WeakReference;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;

import org.jclutter.events.EventCallback;
import org.jclutter.events.EventListener;

/**
 * 
 * The Glib base object representation with functions used by Clutter notably the signal handling API.
 * 
 *
 */
public abstract class GObject {
	
	/** whether the handler should be called before the default handler of the signal. */
	public static final int CONNECT_BEFORE = 0;
	
	/** whether the handler should be called after the default handler of the signal. */
	public static final int CONNECT_AFTER = 1 << 0;
	
	/** whether the handler should be called before or after the default handler of the signal. */
	public static final int CONNECT_SWAPPED = 1 << 1;

	
	protected static final int G_TYPE_INVALID = 0;
	protected static final int G_TYPE_NONE = 1;
	protected static final int G_TYPE_INTERFACE = 2;
	protected static final int G_TYPE_CHAR = 3;
	protected static final int G_TYPE_UCHAR = 4;
	protected static final int G_TYPE_BOOLEAN = 5;
	protected static final int G_TYPE_INT = 6;
	protected static final int G_TYPE_UINT = 7;
	protected static final int G_TYPE_LONG = 8;
	protected static final int G_TYPE_ULONG = 9;
	protected static final int G_TYPE_INT64 = 10;
	protected static final int G_TYPE_UINT64 = 11;
	protected static final int G_TYPE_ENUM = 12;
	protected static final int G_TYPE_FLAGS = 13;
	protected static final int G_TYPE_FLOAT = 14;
	protected static final int G_TYPE_DOUBLE = 15;
	protected static final int G_TYPE_STRING = 16;
	protected static final int G_TYPE_POINTER = 17;
	protected static final int G_TYPE_BOXED = 18;
	protected static final int G_TYPE_PARAM = 19;
	protected static final int G_TYPE_OBJECT = 20;
	protected static final int G_TYPE_GTYPE = 21;

	/** this is the map of all gobjects created through this api - with weak references - 
	 so they can be found by the native layer callback system. */
	private static final Map<Integer, WeakReference<GObject>> CACHE = new Hashtable<Integer, WeakReference<GObject>>();
	
	/**
	 * the c pointer is used to synchronize with the native layer.
	 */
	protected final int pointer;
	
	private EventListener listener;
	
	private List<SignalHandler> signals = null;
	
	private String id;
	
	protected GObject(int id){
		pointer = id;
		if (id != 0)
		CACHE.put(pointer, new WeakReference<GObject>(this));
		registerListener(this);
	}
	
	/*public final void setId(String id) {
		this.id = id;
	}
	
	public final String getId() {
		return id;
	}*/
	
	protected SignalHandler findSignalHandler(String signalName){
		if (signals!=null){
			for(SignalHandler h : signals){
				if (h.getSignal().equals(signalName)) return h;
			}
		}
		return null;
	}
	
	/**
	 * 
	 * @param listener the listener instance
	 */
	public void setListener(EventListener li) {
		// TODO register declared methods
		this.listener = li;
		if (signals != null){
			for(SignalHandler h : signals){
				h.disconnect();
			}
			signals = null;
		}
		
		if (listener != null){
			registerListener(listener);
		}
	}
	
	private void registerListener(Object o) {
		Class<?> clazz = o.getClass();
		Method [] methods = clazz.getDeclaredMethods();
		
		for (Method m : methods) {
			if (m.isAnnotationPresent(EventCallback.class)){
				EventCallback cb = (EventCallback) m.getAnnotation(EventCallback.class);
				if (cb.ignore()) continue;
				String signal = cb.signal();
				if (cb.signal().equals("")){
					signal = methodNameToSignal(m.getName());
				}
				if (signal == null) {
					System.err.println("Signal not found for method : "+m);
					continue;
				}
				connectSignal(signal, findLocalMethod(m.getName()), cb.when());
			} else if (m.getName().startsWith("on")){
				String signal = methodNameToSignal(m.getName());
				connectSignal(signal, findLocalMethod(m.getName()), CONNECT_BEFORE);
			}
		}
	}

	private Method findLocalMethod(String methodname){
		Method [] ms = getClass().getMethods();
		Method found = null;
		for(Method m : ms){
			if (m.getName().equals(methodname)){
				found = m;
				break;
			}
		}
		return found;
	}
	
	protected native int getGType(String property);
	
	private native void unref();
	
	protected native boolean hasProperty(String name);
	
	protected void setProperty(String name, Object value){
		if (name == null) throw new NullPointerException("name is null");
		if (value == null) throw new NullPointerException("value is null");
		if (!hasProperty(name)) throw new IllegalArgumentException("property doesnt exist :"+name);
		switch (getGType(name)) {
		case G_TYPE_BOOLEAN:
			setBooleanProperty(name, asBoolean(value));
			break;
		case G_TYPE_FLOAT:
			setFloatProperty(name, asFloat(value));
			break;
		case G_TYPE_INT:
			setIntProperty(name, asInt(value));
			break;
		case G_TYPE_CHAR:
			setCharProperty(name, asChar(value));
			break;
		case G_TYPE_STRING:
			setStringProperty(name, value.toString());
			break;
		case G_TYPE_LONG:
			setLongProperty(name, asLong(value));
			break;
		case G_TYPE_DOUBLE:
			setDoubleProperty(name, asDouble(value));
			break;
		default: throw new IllegalArgumentException("value type not supported by jclutter");
		}
	}
	
	public Object getProperty(String name){
		if (!hasProperty(name)) throw new IllegalArgumentException("property doesnt exist :"+name);
		if (name == null) throw new NullPointerException("name is null");
		switch (getGType(name)) {
		case G_TYPE_BOOLEAN:
			return getBooleanProperty(name);
		case G_TYPE_FLOAT:
			return getFloatProperty(name);
		case G_TYPE_INT:
			return getIntProperty(name);
		case G_TYPE_CHAR:
			return getCharProperty(name);
		case G_TYPE_STRING:
			return getStringProperty(name);
		case G_TYPE_LONG:
			return getLongProperty(name);
		case G_TYPE_DOUBLE:
			return getDoubleProperty(name);
		default: throw new IllegalArgumentException("value type not supported by jclutter");
		}
	}
	
	private native void setBooleanProperty(String name, boolean value);
	private native void setStringProperty(String name, String value);
	private native void setFloatProperty(String name, float value);
	private native void setDoubleProperty(String name, double value);
	private native void setIntProperty(String name, int value);
	private native void setLongProperty(String name, long value);
	private native void setCharProperty(String name, char value);
	
	protected native boolean getBooleanProperty(String name);
	protected native String getStringProperty(String name);
	protected native float getFloatProperty(String name);
	protected native double getDoubleProperty(String name);
	protected native int getIntProperty(String name);
	protected native long getLongProperty(String name);
	protected native char getCharProperty(String name);
	
	@Override
	public int hashCode() {
		return pointer;
	}
	
	@Override
	public boolean equals(Object obj) {
		if (obj == null) return false;
		return hashCode() == obj.hashCode();
	}
	
	@Override
	protected void finalize() throws Throwable {
		setListener(null);
		unref();
	}

	/**
	 * Method is used internally.
	 * @param pointer
	 * @return
	 */
	protected final static GObject getByPointer(int pointer){
		WeakReference<GObject> w = CACHE.get(pointer);
		if (w == null) return null;
		else return w.get();
	}
	
	
	private static String methodNameToSignal(String name) {
		if (!name.startsWith("on")) return null;
		char [] arr = name.substring(2).toCharArray();
		String s = "";
		for (int i = 0; i < arr.length; i++) {
			if (Character.isLowerCase(arr[i]))
				s += arr[i];
			else {
				if (i > 0) s += "-";
				s += Character.toLowerCase(arr[i]);
			}
		}
		return s;
	}
	
	@SuppressWarnings("unused")
	private static String signalToMethodName(String signal){
		char [] arr = signal.toCharArray();
		String s = "on";
		boolean upper = true;
		for (int i = 0; i < arr.length; i++) {
			if (upper) {
				s += Character.toUpperCase(arr[i]);
				upper = false;
			} else if (arr[i] == '-'){
				upper = true;
				continue;
			}	else s += arr[i];
		}
		return s;
	}

//	private void autoconnect(){
//		connect(this);
//	}
	
//	public List<SignalHandler> connect(Object handler){
//		return connect(handler.getClass(), handler);
//	}

	/**
	 * Connect signals passed through this object annotations.
	 * @param callback
	 * @see Callback
	 */
//	private List<SignalHandler> connectSignals(Class<?> clazz){
//		Method [] methods = clazz.getDeclaredMethods();
//		List<SignalHandler> li = new ArrayList<SignalHandler>();
//		for (Method m : methods) {
//			if (m.isAnnotationPresent(Callback.class)){
//				Callback cb = (Callback) m.getAnnotation(Callback.class);
//				String signal = cb.signal();
//				if (cb.signal().equals("")){
//					signal = methodNameToSignal(m.getName());
//				}
//				if (signal == null) {
//					System.err.println("Signal not found for method : "+m);
//					continue;
//				}
//				li.add(connect(signal, m, cb.when()));
//			}
//		}
//		return li;
//	}
	
	/**
	 * More advanced use of connect() without the annotation.
	 * @param signal
	 * @param method
	 * @param whenflags a combination of the CONNECT_*** flags.
	 */
	protected synchronized SignalHandler connectSignal(String signal, Method method, int whenflags){
		long id = connect(signal, method.getName(), getSignature(method), whenflags);
		SignalHandler h = new SignalHandler(id, this, signal, whenflags);
		if (signals == null) signals = new ArrayList<SignalHandler>();
		signals.add(h);
		return h;
	}

	private static String getSignature(Method m) {
		String s = "(";
		Class<?> [] types = m.getParameterTypes();		
		for(Class<?> t : types){
			s += toString(t);
		}
		s += ")";
		s += toString(m.getReturnType());
		return s;
	}
	
	private static String toString(Class<?> t){ // TODO maybe array
		if (t == int.class) return "I";
		else if (t == long.class) return "J";
		else if (t == float.class) return "F";
		else if (t == double.class) return "D";
		else if (t == char.class) return "C";
		else if (t == byte.class) return "B";
		else if (t == boolean.class) return "Z";
		else if (t == short.class) return "S";
		else if (t == void.class) return "V";
		else return "L" + t.getName().replace('.', '/') + ";";
	}

	private native long connect(String signal, String method, String signature, int whenflags);
	
	/**
	 * Only used by SignalHandler.
	 * @param id
	 */
	protected final native void disconnect(long id);
	/**
	 * Only used by SignalHandler.
	 * @param id
	 */
	protected final native boolean isConnected(long id);
	/**
	 * Only used by SignalHandler.
	 * @param id
	 */
	protected final native void block(long id);
	/**
	 * Only used by SignalHandler.
	 * @param id
	 */
	protected final native void unblock(long id);
	
	
	private static float asFloat(Object obj){
		return ((Number)obj).floatValue();
	}
	
	private static double asDouble(Object obj){
		return ((Number)obj).doubleValue();
	}
	
	private static int asInt(Object obj){
		return ((Number)obj).intValue();
	}
	
	@SuppressWarnings("unused")
	private static byte asByte(Object obj){
		return ((Number)obj).byteValue();
	}
	
	private static long asLong(Object obj){
		return ((Number)obj).longValue();
	}
	
	private static boolean asBoolean(Object obj){
		if (obj instanceof Number) return ((Number)obj).intValue() == 1;
		else return (Boolean)obj;
	}
	
	private static char asChar(Object obj){
		return (Character)obj;
	}
	
	
}
