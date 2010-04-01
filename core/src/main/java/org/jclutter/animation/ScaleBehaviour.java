package org.jclutter.animation;

public class ScaleBehaviour extends Behaviour {


	public static final int GRAVITY_NORTH_EAST = 0;
	public static final int GRAVITY_NORTH      = 1;
	public static final int GRAVITY_NORTH_WEST = 2;
	public static final int GRAVITY_WEST       = 3;
	public static final int GRAVITY_SOUTH_WEST = 4;
	public static final int GRAVITY_SOUTH      = 5;
	public static final int GRAVITY_SOUTH_EAST = 6;
	public static final int GRAVITY_EAST       = 7;
	public static final int GRAVITY_CENTER     = 8;
	public static final int GRAVITY_NONE       = 9;
	
	
	public ScaleBehaviour(Alpha alpha, double xstart, double ystart, double xend, double yend) {
		super(behaviourScaleNew(alpha,xstart,ystart,xend,yend));
	}

	public static final native int behaviourScaleNew(Alpha alpha,
			double x_scale_start,
            double y_scale_start,
            double x_scale_end,
            double y_scale_end);
	
	public native void setBounds(double x_scale_start,
            double y_scale_start,
            double x_scale_end,
            double y_scale_end);
	
	// TODO: get bounds
	
	public native void setBoundsFixed(int x_scale_start,
            int y_scale_start,
            int x_scale_end,
            int y_scale_end);
	
}
