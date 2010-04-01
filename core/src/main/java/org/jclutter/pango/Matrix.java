package org.jclutter.pango;

public class Matrix {

	public double xx;
	public double xy;
	public double yx;
	public double yy;
	public double x0;
	public double y0;

	public Matrix() {
	}

	public Matrix(double xx, double xy, double yx, double yy, double x0,
			double y0) {
		super();
		this.xx = xx;
		this.xy = xy;
		this.yx = yx;
		this.yy = yy;
		this.x0 = x0;
		this.y0 = y0;
	}

}
