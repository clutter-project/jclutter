package org.jclutter.events;

import org.jclutter.Geometry;
import org.jclutter.Text;

public interface TextListener extends ActorListener<Text> {

	public void onActivate(Text text);

	public void onCursorEvent(Text text, Geometry geom);

	public void onTextChanged(Text text);
	
}
