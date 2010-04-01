package org.jclutter.cogl;

public class Matrix {

	private int pointer;
	
	public Matrix() {
		this(createMatrix());
	}
	
	private native static int createMatrix();

	protected Matrix(int p) {
		pointer = p;
		initIdentity();
	}
	
	@Override
	public int hashCode() {
		return pointer;
	}
	
	public native void initIdentity();

	public native void frustum(float left, float right, float bottom,
			float top, float z_near, float z_far);

	public native void ortho(float left, float right, float bottom, float top,
			float z_near, float z_far);

	public native void perspective(float fov_y, float aspect, float z_near,
			float z_far);

	// public native void transformPoint ()
	
	public native Matrix multiply(Matrix b);

	public native void rotate(float angle, float x, float y, float z);

	public native void translate(float x, float y, float z);

	public native void scale(float sx, float sy, float sz);

	public native void initFromArray(float[] array);

	public native float[] getArray();

	public native Matrix getInverse();

}
