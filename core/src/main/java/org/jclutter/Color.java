/**
 * 
 */
package org.jclutter;

public class Color implements Cloneable {

	public static final Color BLACK = new Color();
	public static final Color WHITE = new Color(255, 255, 255);
	public static final Color BLUE = new Color(0, 0, 255);
	public static final Color RED = new Color(255, 0, 0);
	public static final Color GREEN = new Color(0, 255, 0);
	public static final Color YELLOW = new Color(255, 255, 0);
	public static final Color CYAN = new Color(0, 255, 255);
	public static final Color MAGENTA = new Color(255, 0, 255);

	public int red;
	public int green;
	public int blue;
	public int alpha = 255;

	private static final double FACTOR = 0.7;

	public Color() {
	}

	public Color(int r, int g, int b) {
		this.red = r;
		this.green = g;
		this.blue = b;
	}

	public Color(int rgb) {
		setRgb(rgb);
	}

	public void setRgb(int rgb) {
		red = (rgb >> 16) & 0xFF;
		green = (rgb >> 8) & 0xFF;
		blue = (rgb >> 0) & 0xFF;
		alpha = (rgb >> 24) & 0xFF;
	}

	public Color(int r, int g, int b, int a) {
		this.red = r;
		this.green = g;
		this.blue = b;
		this.alpha = a;
	}

	public int getRgb() {
		return ((alpha & 0xFF) << 24) | ((red & 0xFF) << 16)
				| ((green & 0xFF) << 8) | ((blue & 0xFF) << 0);
	}

	public static native Color getColor(String name);

	public static void main(String[] args) {
		int r = 0xFF;
		int g = 0xDD;
		int b = 0xEE;
		int a = 0x00;
		int i = (((r << 24)) | ((g << 16)) | ((b << 8)) | a);
		String s = Integer.toHexString(i);
		System.out.println(s);
	}

	public Color copy() {
		try {
			return (Color) clone();
		} catch (CloneNotSupportedException e) {
			return new Color(red, green, blue, alpha);
		}
	}
	
	public Color red(int r){
		this.red = r;
		return this;
	}
	
	public Color green(int g){
		this.green = g;
		return this;
	}
	
	public Color blue(int b){
		this.blue = b;
		return this;
	}
	
	public Color alpha(int a){
		this.alpha = a;
		return this;
	}

	// public static final int parse(String stringcolor){
	//		
	// }

	public String toString() {
		return "Color[" + red + "," + green + "," + blue + "," + alpha + "]";
	}

	public void setHls(float hue, float luminance, float saturation) {
		if (saturation == 0) {
			red = green = blue = (int) (luminance * 255.0f + 0.5f);
		} else {
			float h = (hue - (float) Math.floor(hue)) * 6.0f;
			float f = h - (float) Math.floor(h);
			float p = luminance * (1.0f - saturation);
			float q = luminance * (1.0f - saturation * f);
			float t = luminance * (1.0f - (saturation * (1.0f - f)));
			switch ((int) h) {
			case 0:
				red = (int) (luminance * 255.0f + 0.5f);
				green = (int) (t * 255.0f + 0.5f);
				blue = (int) (p * 255.0f + 0.5f);
				break;
			case 1:
				red = (int) (q * 255.0f + 0.5f);
				green = (int) (luminance * 255.0f + 0.5f);
				blue = (int) (p * 255.0f + 0.5f);
				break;
			case 2:
				red = (int) (p * 255.0f + 0.5f);
				green = (int) (luminance * 255.0f + 0.5f);
				blue = (int) (t * 255.0f + 0.5f);
				break;
			case 3:
				red = (int) (p * 255.0f + 0.5f);
				green = (int) (q * 255.0f + 0.5f);
				blue = (int) (luminance * 255.0f + 0.5f);
				break;
			case 4:
				red = (int) (t * 255.0f + 0.5f);
				green = (int) (p * 255.0f + 0.5f);
				blue = (int) (luminance * 255.0f + 0.5f);
				break;
			case 5:
				red = (int) (luminance * 255.0f + 0.5f);
				green = (int) (p * 255.0f + 0.5f);
				blue = (int) (q * 255.0f + 0.5f);
				break;
			}
		}

	}

	//	
	// public int add(Color c1, Color c2);
	//	
	// public void substract(Color c1, Color c2);
	//	
	// public boolean equal(Color c2);
	//	
	// public void lighten(Color src);
	//
	// public void darken(Color src);
	//	
	// public void shade(Color src, double shade);

	public Color darker() {
		return new Color(Math.max((int) (red * FACTOR), 0), Math.max(
				(int) (green * FACTOR), 0), Math.max((int) (blue * FACTOR), 0));
	}

	public Color brighter() {
		int r = red;
		int g = green;
		int b = blue;

		/*
		 * From 2D group: 1. black.brighter() should return grey 2. applying
		 * brighter to blue will always return blue, brighter 3. non pure color
		 * (non zero rgb) will eventually return white
		 */
		int i = (int) (1.0 / (1.0 - FACTOR));
		if (r == 0 && g == 0 && b == 0) {
			return new Color(i, i, i);
		}
		if (r > 0 && r < i)
			r = i;
		if (g > 0 && g < i)
			g = i;
		if (b > 0 && b < i)
			b = i;

		return new Color(Math.min((int) (r / FACTOR), 255), Math.min(
				(int) (g / FACTOR), 255), Math.min((int) (b / FACTOR), 255));
	}
	
	public org.jclutter.cogl.Color toCoglColor(){
		return new org.jclutter.cogl.Color(red, green, blue, alpha);
	}
	
	

}
