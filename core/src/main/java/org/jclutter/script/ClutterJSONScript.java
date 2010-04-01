package org.jclutter.script;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import org.jclutter.animation.Mode;
import org.jclutter.glib.GObject;
import org.json.JSONArray;
import org.json.JSONObject;

public class ClutterJSONScript implements Parser {

	private GObjectFactory objFact = new DefaultGObjectFactory();

	public ClutterJSONScript() {	
	}
	
	public void setObjectFactory(GObjectFactory objFact) {
		this.objFact = objFact;
	}
	
	@Override
	public void parse(InputStream in, Map<String, GObject> map) throws ParserException {
		try {
			String string = toString(in).trim();
			
			
			JSONObject jobj = null;
			JSONArray jarr = null;
			if (string.startsWith("{"))
			jobj = new JSONObject(string);
			else jarr = new JSONArray(string);
			
			if (jarr != null){
				for (int i = 0; i < jarr.length(); i++) {
					add(map, jarr.getJSONObject(i));
				}	
			} else {
				add(map, jobj);
			}
		} catch (Exception e) {
			throw new ParserException(e);
		}
	}

	private void add(Map<String, GObject> objectMap,
			JSONObject o) throws Exception {
		String type = null;
		String id = null;
		Iterator<String> iter = o.keys();
		HashMap<String, Object> values = new HashMap<String, Object>();
		while(iter.hasNext()){
			String key = iter.next();
			if (key.equals("id")){
				id = o.getString(key);
			} else if (key.equals("type")){
				type = o.getString(key);
			} else {
				values.put(key, o.get(key));
			}
		}
		GObject obj = objFact.create(type);
		if (id != null) objectMap.put(id, obj);
		// TODO applyValues(obj, values);
	}


	protected static String toString(InputStream in) throws IOException {
		InputStreamReader re = new InputStreamReader(in);
		BufferedReader br = new BufferedReader(re);
		String l = null;
		String s = "";
		while((l = br.readLine())!=null){
			s += l + "\n";
		}
		br.close();
		return s;
	}
	
	protected static Mode getAnimationMode(String mode){
		char [] arr = mode.toCharArray();
		String s = "";
		boolean lastisuppercase = false; // last char
		for (int i = 0; i < arr.length; i++) {
			boolean uppercase = Character.isUpperCase(arr[i]);
			if ( uppercase&!lastisuppercase | !uppercase&lastisuppercase ){
				s += "_";
			}
			lastisuppercase = uppercase;
			s += Character.toUpperCase(arr[i]);
		}
		return Mode.valueOf(s);
	}
	

}
