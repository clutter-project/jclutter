package org.jclutter.events;

import org.jclutter.animation.Behaviour;

public interface BehaviourListener<T extends Behaviour> extends EventListener {
	
	public void onApplied(T behaviour);

	public void onRemoved(T behaviour);

}
