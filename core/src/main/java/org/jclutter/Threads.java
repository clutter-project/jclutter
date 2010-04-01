package org.jclutter;

import java.util.HashMap;
import java.util.Map;

public class Threads {
	
	private static Map<Integer, Task> tasks = new HashMap<Integer, Task>();
	
	private static int MAXID = 0;

	public static final native void init();

	public static final native void enter();

	public static final native void leave();

	private static int registerCallback(Task task) {
		int id = -1;
		synchronized(tasks){
			id = MAXID++;
			tasks.put(id, task);
		}
		return id;
	}

	public static final int addIdleTask(Task task, int priority) {
		return addIdleTask(registerCallback(task), priority);
	}

	private static native int addIdleTask(int func, int priority);

	public static final int addTimeoutTask(Task task, int priority,
			int interval) {
		return addTimeoutTask(registerCallback(task), priority, interval);
	}

	private static native int addTimeoutTask(int func, int priority, int interval);

	public static final int addFrameTask(Task task, int priority,
			int fps) {
		return addFrameTask(registerCallback(task), priority, fps);
	}

	private static native int addFrameTask(int func, int priority, int fps);

	public static final int addRepaint(Task task) {
		return addRepaint(registerCallback(task));
	}

	private static native int addRepaint(int func);
	
	@SuppressWarnings("unused")
	private static boolean execute(int id){
		try {
			return tasks.get(id).execute();
		} catch (Exception e) {
			e.printStackTrace();
			return false;
		}
	}
	
	@SuppressWarnings("unused")
	private static void destroy(int id){
		try {
			tasks.get(id).destroy();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
