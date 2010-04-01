package org.jclutter.awt;

import java.awt.Canvas;
import java.awt.Graphics;

public class JClutterCanvas extends Canvas {

	private static final long serialVersionUID = 1L;

	static {
		System.loadLibrary("jclutter-awt");
	}
	
	public native void paint(Graphics g);

}
