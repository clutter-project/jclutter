package org.jclutter.script;

import org.jclutter.glib.GObject;

public interface GObjectFactory {
	
	public GObject create(String typeName);
	
	public void register(String typeName, Class<? extends GObject> c);

}
