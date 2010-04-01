package org.jclutter.animation;



public class PathNode {
	
	public enum Type {
		MOVE_TO(_MOVE_TO, 1), LINE_TO(_LINE_TO, 1), CURVE_TO(_CURVE_TO, 3), CLOSE(_CLOSE, 0);
		
		private int id, points;
		Type (int i, int p){
			id = i;
			points = p;
		}
	}
	
	public PathNode(Type type, boolean relative, Knot ... knots ) {
		if (knots == null) knots = new Knot[]{};
		if (type.points != knots.length) throw new IllegalArgumentException("Number of knots should be "+type.points);
		this.type = type;
		this.relative = relative;
		this.knots = knots;
	}
	
	public PathNode(Type type, boolean relative, int ... coords ) {
		this(type, relative, toKnots(coords));
	}
	
	public PathNode(Type type, Knot ... knots ) {
		this(type, true, knots);
	}
	
	public PathNode(Type type, int ... coords ) {
		this(type, true, toKnots(coords));
	}
	
	private static Knot [] toKnots(int ... coords){
		Knot [] ks = new Knot[coords.length/2];
		for (int i = 0; i < ks.length; i++) {
			ks[i] = new Knot(coords[i*2], coords[i*2+1]);
		}
		return ks;
	}
	
	/**
	 * With no arguments, it creates a closing node.
	 */
	public PathNode() {
		this(Type.CLOSE, true, (Knot [])null);
	}
	
	
	private final static int _MOVE_TO  = 0;
	private final static int _LINE_TO  = 1;
	private final static int _CURVE_TO = 2;
	private final static int _CLOSE    = 3;
	private final static int _RELATIVE = 32; // IS NOT A TYPE

	//private final static int _REL_MOVE_TO  = _MOVE_TO | _RELATIVE;
	//private final static int _REL_LINE_TO  = _LINE_TO | _RELATIVE;
	//private final static int _REL_CURVE_TO = _CURVE_TO | _RELATIVE;
	
	private boolean relative;
	private Type type = Type.MOVE_TO;
	
	private Knot [] knots;
	
	protected int getTypeId(){
		if (Type.CLOSE == type) return Type.CLOSE.id;
		if (!relative)
		return type.id;
		else return type.id |_RELATIVE;
	}
	
	public Knot[] getKnots() {
		return knots;
	}
	
	public Type getType() {
		return type;
	}
	
	public boolean isRelative() {
		return relative;
	}
	
}
