package org.jclutter.script;

import java.io.InputStream;
import java.util.Map;

import org.jclutter.glib.GObject;

public interface Parser {
	
	public void parse(InputStream in, Map<String, GObject> map) throws ParserException;
	
}
