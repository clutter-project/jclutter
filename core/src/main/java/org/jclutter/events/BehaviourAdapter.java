package org.jclutter.events;

import org.jclutter.animation.Behaviour;

public class BehaviourAdapter<T extends Behaviour> implements BehaviourListener<T> {

	public void onApplied(T behaviour) {}

	public void onRemoved(T behaviour) {}

}
