package org.jclutter;

import java.util.HashSet;
import java.util.Set;

//import javax.microedition.khronos.egl.EGLSurface;



public class Stage extends Group {

	private static final Set<Stage> HARD_REFS = new HashSet<Stage>();
	
	public static final int PICK_NONE     = 0;
	public static final int PICK_REACTIVE = 1;
	public static final int PICK_ALL      = 2;

	/**
	 * Creates a new, non-default stage. 
	 * Use Stage(null) or Stage.getDefault() to get the default stage.
	 */
	private Stage() {
		this(newInstance());
	}
	
	public static Stage createStage(){
		return new Stage();
	}
	
	private native static int newInstance();

	private Stage(int id){
		super(getId(id));
		// stage references are always kept in memory as they as top containers.
		HARD_REFS.add(this);
	}
	
	@Override
	public final boolean isTopContainer() {
		return true;
	}
	
	private static int getId(int id) {
		if (id == 0) return getDefaultId();
		else return id;
	}
	
	protected static final Stage createStage(int stageid){
		return new Stage(stageid);
	}

	private static native int getDefaultId();
	
	public static native Stage getDefault();
	
	public native void setFullscreen(boolean fullscreen);
	
	public native boolean isFullscreen();

	// Actor new ();
	public native boolean isDefault();

	public native void showCursor();

	public native void hideCursor();
	
	public native Actor getActorAtPos(int pickMode, float x,float y);

	/**
	 * This function essentially makes sure the right GL context is current for the passed stage.
	 * It is not intended to be used by applications. Useful for porting ?
	 */
	public native void ensureCurrent();

	public native void queueRedraw();

	public native void setKeyFocus(Actor actor);

	public native Actor getKeyFocus();
	
	public native void setThrottleMotionEvents(boolean throttle);
	
	public native boolean isThrottleMotionEvents();
	
	public native void setUseAlpha(boolean usealpha);
	
	public native boolean isUseAlpha();

	public native void setPerspective(float fovy, float aspect, float zNear,
			float zFar);

	public void setPerspective(Perspective p){
		setPerspective(p.fovy, p.aspect, p.zNear, p.zFar);
	}

	public native Perspective getPerspective();

	public native void setTitle(String title);

	public native char getTitle();

	public native void setUserResizable(boolean resizable);

	public native boolean getUserResizable();

	public native void setUseFog(boolean fog);

	public native boolean getUseFog();

	public native void setFog(Fog fog);
	
	public native void setFog(float z_near, float z_far);

	public native Fog getFog();
	
	@Override
	public native Color getColor();

	@Override
	public native boolean setColor(Color color);
	
	public void setColor(int color){
		setColor(new Color(color));
	}
	
	public void setOffscreen(boolean offscreen){
		setProperty("offscreen", offscreen);
	}
	
	public boolean isOffscreen(){
		return getBooleanProperty("offscreen");
	}
	
	public native void setMinimumSize(float width, float height);
	
	public void setMinimumSize(Dimension d){
		setMinimumSize(d.width, d.height);
	}
	
	public native Dimension getMinimumSize();
	
	
	
	public void onActivate(){}
	
	public void onDeactivate(){}
	
	public void onFullscreen(){}
	
	public void onUnfullscreen(){}

}
