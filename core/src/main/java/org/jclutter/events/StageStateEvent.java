package org.jclutter.events;

public class StageStateEvent extends Event {

	public static final int STAGE_STATE_FULLSCREEN       = (1<<1);
	public static final int STAGE_STATE_OFFSCREEN        = (1<<2);
	public static final int STAGE_STATE_ACTIVATED        = (1<<3);

	protected StageStateEvent(int nid) {
		super(nid);
	}

}
