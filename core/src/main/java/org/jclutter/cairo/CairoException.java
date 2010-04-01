package org.jclutter.cairo;

public class CairoException extends Exception {

	private static final long serialVersionUID = 1L;

	public enum Type {
	    NO_MEMORY,
	    INVALID_RESTORE,
	    INVALID_POP_GROUP,
	    NO_CURRENT_POINT,
	    INVALID_MATRIX,
	    INVALID_STATUS,
	    NULL_POINTER,
	    INVALID_STRING,
	    INVALID_PATH_DATA,
	    READ_ERROR,
	    WRITE_ERROR,
	    SURFACE_FINISHED,
	    SURFACE_TYPE_MISMATCH,
	    PATTERN_TYPE_MISMATCH,
	    INVALID_CONTENT,
	    INVALID_FORMAT,
	    INVALID_VISUAL,
	    FILE_NOT_FOUND,
	    INVALID_DASH,
	    INVALID_DSC_COMMENT,
	    INVALID_INDEX,
	    CLIP_NOT_REPRESENTABLE,
	    TEMP_FILE_ERROR,
	    INVALID_STRIDE,
	    FONT_TYPE_MISMATCH,
	    USER_FONT_IMMUTABLE,
	    USER_FONT_ERROR,
	    NEGATIVE_COUNT,
	    INVALID_CLUSTERS,
	    INVALID_SLANT,
	    INVALID_WEIGHT
	}
	
	private Type type;
	
	protected CairoException(int t){
		this(Type.values()[t]);
	}
	
	public CairoException(Type t) {
		super("Error status: "+t.toString());
		this.type = t;
	}
	
	public Type getType() {
		return type;
	}
}
