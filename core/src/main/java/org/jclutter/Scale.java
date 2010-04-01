package org.jclutter;

public class Scale {


	public double x;
	public double y;
	
	public Point center;
	
	public Scale() {
	}
	
	public Scale(double x, double y) {
		super();
		this.x = x;
		this.y = y;
	}
	
	public Scale(double x, double y, Point center) {
		super();
		this.x = x;
		this.y = y;
		this.center = center;
	}
	
	public Scale(double x, double y, float centerx, float centery) {
		super();
		this.x = x;
		this.y = y;
		this.center = new Point(centerx, centery);
	}
	
}
