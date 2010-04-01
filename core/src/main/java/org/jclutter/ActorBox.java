package org.jclutter;

public class ActorBox {
	
	public float x1, y1, x2, y2;
	
	public ActorBox() {
	}

	public ActorBox(float x1, float y1, float x2, float y2) {
		super();
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
	}
	
	public Dimension getSize(){
		return new Dimension(x2 - x1, y2 - y1);
	}
	
	public float getWidth(){
		return x2 -x1;
	}
	
	public float getHeight(){
		return y2 - y1;
	}
	
}