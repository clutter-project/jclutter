package org.jclutter.cairo;

import org.jclutter.Color;

//from http://www.cairographics.org/manual/cairo-context.html
public final class CairoContext {

	public static final int ANTIALIAS_DEFAULT = 0;
	public static final int ANTIALIAS_NONE = 1;
	public static final int ANTIALIAS_GRAY = 2;
	public static final int ANTIALIAS_SUBPIXEL = 3;

	public static final int FILL_RULE_WINDING = 0;
	public static final int FILL_RULE_EVEN_ODD = 1;

	public static final int LINE_CAP_BUTT = 0;
	public static final int LINE_CAP_ROUND = 1;
	public static final int LINE_CAP_SQUARE = 2;

	public static final int OPERATOR_CLEAR = 0;
	public static final int OPERATOR_SOURCE = 1;
	public static final int OPERATOR_OVER = 2;
	public static final int OPERATOR_IN = 3;
	public static final int OPERATOR_OUT = 4;
	public static final int OPERATOR_ATOP = 5;
	public static final int OPERATOR_DEST = 6;
	public static final int OPERATOR_DEST_OVER = 7;
	public static final int OPERATOR_DEST_IN = 8;
	public static final int OPERATOR_DEST_OUT = 9;
	public static final int OPERATOR_DEST_ATOP = 10;
	public static final int OPERATOR_XOR = 11;
	public static final int OPERATOR_ADD = 12;
	public static final int OPERATOR_SATURATE = 13;

	protected int pointer;

	private CairoContext(int id) {
		this.pointer = id;
	}

	public void setSource(Color c) {
		setSource(c.red, c.green, c.blue, c.alpha);
	}

	public CairoException.Type getStatus() {
		return CairoException.Type.values()[status()];
	}

	public void checkStatus() throws CairoException {
		int status = status();
		if (status > 0) {
			throw new CairoException(status);
		}
	}

	private native int status();

	public native void destroy();

	public native void save();

	public native void restore();

	public native void pushGroup();

	public native CairoPattern popGroup();

	public native void popGroupToSource();

	public native void setSource(double red, double green, double blue);

	private native void setSource(double red, double green, double blue,
			double alpha);

	public native void setSource(CairoPattern source);

	public native CairoPattern getSource();

	public native void setAntialias(int antialias);

	public native int getAntialias();

	public native void setDash(double[] dashes, double offset);

	public native int getDashCount();

	public native void setFillRule(int fill_rule);

	public native int getFillRule();

	public native void setLineCap(int line_cap);

	public native int getLineCap();

	public native void setLineJoin(int line_join);

	public native int getLineJoin();

	public native void setLineWidth(double width);

	public native double getLineWidth();

	public native void setMiterLimit(double limit);

	public native double getMiterLimit();

	public native void setOperator(int op);

	public native int getOperator();

	public native void setTolerance(double tolerance);

	public native double getTolerance();

	public native void clip();

	public native void clipPreserve();

	public native void resetClip();

	public native void fill();

	public native void fillPreserve();

	public native boolean inFill(double x, double y);

	public native void mask(CairoPattern pattern);

	public native void paint();

	public void paint(double alpha) {
		paintWithAlpha(alpha);
	}

	private native void paintWithAlpha(double alpha);

	public native void stroke();

	public native void strokePreserve();

	public native boolean inStroke(double x, double y);

	public native void copyPage();

	public native void showPage();

	public native int getReferenceCount();

	// Transformations
	public native void tranaslate(double x, double y);

	public native void scale(double x, double y);

	public native void rotate(double angle);

	// Text
	public native void setFontSize(double size);

	public native void showText(String text);

	// Paths
	public native void newPath();

	public native void newSubPath();

	public native void closePath();

	public native void arc(double xc, double yc, double radius, double angle1,
			double angle2);

	public native void arcNegative(double xc, double yc, double radius,
			double angle1, double angle2);

	public native void curveTo(double x1, double y1, double x2, double y2,
			double x3, double y3);

	public native void lineTo(double x, double y);

	public native void moveTo(double x, double y);

	public native void rectangle(double x, double y, double width, double height);

	public native void textPath(String text);

	public native void relCurveTo(double dx1, double dy1, double dx2,
			double dy2, double dx3, double dy3);

	public native void relLineTo(double dx, double dy);

	public native void relMoveTo(double dx, double dy);

}
