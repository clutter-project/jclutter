package org.jclutter;



public class Text extends Actor {
	
	public static final int ELLIPSIZE_NONE   = 0;
	public static final int ELLIPSIZE_START  = 1;
	public static final int ELLIPSIZE_MIDDLE = 2;
	public static final int ELLIPSIZE_END    = 3;
	
	public static final int ALIGN_LEFT   = 0;
	public static final int ALIGN_CENTER = 1;
	public static final int ALIGN_RIGHT  = 2;
	
	public static final int WRAP_WORD = 0;
	public static final int WRAP_CHAR = 1;
	public static final int WRAP_WORD_CHAR = 2;

	
	public Text() {
		super(newInstance());
	}
	public Text(String font, String text) {
		super(newWithText(font, text));
	}

	public Text(String font, String text, Color c) {
		super(newFull(font, text, c));
	}
	
	private Text(int nid){
		super(nid);
	}
	
	protected static native int newInstance();

	protected static native int newFull(String font, String text, Color color);
	
	protected static native int newWithText(String font, String text);

	public native String getText();
	
	public native void setText(String text);
	
	public native void setMarkup(String markup);
	
	public native void setActivatable(boolean activatable);
	
	public native boolean isActivatable();
	
	@Override
	public native Color getColor();
	
	public void setColor(int color){
		setColor(new Color(color));
	}
	
	@Override
	public native boolean setColor(Color color);
	
	// TODO pango attributes and layout
	
	public native void setEllipsizeMode(int mode);
	
	public native int getEllipsizeMode();
	
	public native String getFontName();
	
	public native void setFontName(String fontName);
	
	public native void setPasswordChar(char c);
	
	public native char getPasswordChar();
	
	public native void setLineAlignment(int pango_align);
	
	public native int getLineAlignment();
	
	public native boolean isLineWrap();
	
	public native void setLineWrap(boolean wrap);
	
	public native void setLineWrapMode(int pango_wrap);
	
	public native int getLineWrapMode();
	
	public native void setMaxLength(int max);
	
	public native boolean isUseMarkup();
	
	public native void setUseMarkup(boolean setting);
	
	public native boolean isJustify();
	
	public native void setJustify(boolean justify);
	
	public native int getCursorPosition();
	
	public native void setCursorPosition(int position);
	
	public native void insertUnichar(char unichar);
	
	public native void deleteChars(int len);
	
	public native String getChars(int start, int end);
	
	public native void insertText(String text, int position);
	
	public native void deleteText(int startPos, int endPos);
	
	public native void deleteSelection();
	
	public native void setCursorVisible(boolean visible);
	
	public native boolean isCursorVisible();
	
	public native void setCursorColor(Color c);
	
	public native Color getCursorColor();
	
	public native void setCursorSize(int size);
	
	public native int getCursorSize();
	
	public native boolean activate();
	
	public native int getMaxLength();
	
	public native void setSelectionBound(int bound);
	
	public native int getSelectionBound();
	
	public native void setSelectionColor(Color c);
	
	public native Color getSelectionColor();
	
	public native void setSelectable(boolean selectable);
	
	public native boolean isSelectable();
	
	public native void setEditable(boolean editable);
	
	public native boolean isEditable();
	
	public native void setSingleLineMode(boolean singleLine);
	
	public native boolean isSingleLineMode();
	
	public native Point positionToCoords(int position);
	
	// TODO public native void setPreeditString(String string, attr, int cursorPos);
	
	// Events

	public static final String SIGNAL_ACTIVATE = "activate";
	public static final String SIGNAL_CURSOR_EVENT = "cursor-event";
	public static final String SIGNAL_TEXT_CHANGED = "text-changed";
	
	public void onActivate(){}
	public void onCursorEvent(Geometry geom){}
	public void onTextChanged(){}
	
}
