package org.jclutter.events;

import org.jclutter.Geometry;
import org.jclutter.Text;

public class TextAdapter extends ActorAdapter<Text> implements TextListener {

	public void onActivate(Text text) {}

	public void onCursorEvent(Text text, Geometry geom) {}

	public void onTextChanged(Text text) {}

}
