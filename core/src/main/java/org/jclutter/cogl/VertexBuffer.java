package org.jclutter.cogl;

public class VertexBuffer extends CoglTexture {

	public enum VerticesMode {
		POINTS, LINE_STRIP, LINE_LOOP, LINES, TRIANGLE_STRIP, TRIANGLE_FAN, TRIANGLES
	}

	public enum IndicesType {
		UNSIGNED_BYTE, TYPE_UNSIGNED_SHORT
	}

	public VertexBuffer(int vertices) {
		super(newInstance(vertices));
	}

	// TODO missing functions
	
	private native static int newInstance(int vertices);

	public native int getVerticesCount();

	public native void delete(String attribute_name);

	public native void submit();

	public native void disable(String attribute_name);

	public native void enable(String attribute_name);

	public void draw(VerticesMode mode, int first, int count){
		draw(mode.ordinal(), first, count);
	}

	private native void draw(int mode, int first, int count);
	
	public void drawElements(VerticesMode mode, CoglTexture indices,
			int min_index, int max_index, int indices_offset, int count){
		drawElements(mode.ordinal(), indices, min_index, max_index, indices_offset, count);
	}
	public native void drawElements(int mode, CoglTexture indices,
			int min_index, int max_index, int indices_offset, int count);

	public static native CoglTexture indicesGetForQuads(int n_indices);

}
