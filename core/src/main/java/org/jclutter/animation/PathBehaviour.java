package org.jclutter.animation;


public class PathBehaviour extends Behaviour {
	
	public PathBehaviour(Alpha alpha, Path path){
		super(behaviourPathNew(alpha, path));
	}
	
	public PathBehaviour(Alpha alpha, Knot [] knots){
		super(behaviourPathNewWithKnots(alpha, knots));
	}
	
	public PathBehaviour(Alpha alpha, String description){
		super(behaviourPathNewWithDescription(alpha, description));
	}

	private static native int behaviourPathNew(Alpha alpha, Path path);
	
	private static native int behaviourPathNewWithKnots(Alpha alpha, Knot [] knots);
	
	private static native int behaviourPathNewWithDescription(Alpha alpha, String desc);
	
	public native void setPath(Path p);
	
	public native Path getPath();

}
