package org.jclutter.animation;

import java.util.List;

import org.jclutter.glib.GObject;

public class Path extends GObject {

	public Path() {
		super(pathNew());
	}
	
	public Path(String description) {
		super(pathNewWithDescription(description));
	}

	protected static native int pathNew();

	private static native int pathNewWithDescription(String desc);

	public native void addMoveTo(int x, int y);

	public native void addRelMoveTo(int x, int y);

	public native void addLineTo(int x, int y);

	public native void addRelLineTo(int x, int y);

	public native void addCurveTo(int x1, int y1, int x2, int y2, int x3, int y3);

	public native void addRelCurveTo(int x1, int y1, int x2, int y2, int x3, int y3);

	public native void addClose();

	public native void addString(String str);

	public native void addNode(PathNode node);

	public native int getNodeCount();

	public native PathNode getNodeAt(int index);

	public native List<PathNode> getNodes();

	public native void insertNodeAt(int index, PathNode node);

	public native void removeNodeAt(int index);

	public native void replaceNodeAt(int index, PathNode node);

	public native String getDescription();
	
	public native void setDescription(String desc);

	public native void clear();

	public native Knot getPosition(double progress);

	/**
	 * Retrieves an approximation of the total length of the path.
	 * @return
	 */
	public native int getLength();

	// TODO cairo path

}
