package org.jclutter.script;

import java.util.HashMap;
import java.util.Map;

import org.jclutter.BinLayout;
import org.jclutter.Box;
import org.jclutter.BoxLayout;
import org.jclutter.Clone;
import org.jclutter.FixedLayout;
import org.jclutter.FlowLayout;
import org.jclutter.Group;
import org.jclutter.Rectangle;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.Texture;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.Animation;
import org.jclutter.animation.DepthBehaviour;
import org.jclutter.animation.OpacityBehaviour;
import org.jclutter.animation.PathBehaviour;
import org.jclutter.animation.RotateBehaviour;
import org.jclutter.animation.ScaleBehaviour;
import org.jclutter.animation.Timeline;
import org.jclutter.glib.GObject;

public class DefaultGObjectFactory implements GObjectFactory {
	
	private Map<String, Class<? extends GObject>> typeMap = new HashMap<String, Class<? extends GObject>>();
	
	public DefaultGObjectFactory() {
		typeMap.put("Animation", Animation.class);
		typeMap.put("Alpha", Alpha.class);
		typeMap.put("Timeline", Timeline.class);
		typeMap.put("BehaviourRotate", RotateBehaviour.class);
		typeMap.put("BehaviourDepth", DepthBehaviour.class);
		typeMap.put("BehaviourOpacity", OpacityBehaviour.class);
		typeMap.put("BehaviourPath", PathBehaviour.class);
		typeMap.put("BehaviourScale", ScaleBehaviour.class);
		typeMap.put("BehaviourEllipse", Animation.class);
		typeMap.put("Rectangle", Rectangle.class);
		typeMap.put("Texture", Texture.class);
		typeMap.put("Clone", Clone.class);
		typeMap.put("Text", Text.class);
		typeMap.put("Group", Group.class);
		typeMap.put("Stage", Stage.class);
		typeMap.put("Box", Box.class);
		typeMap.put("FixedLayout", FixedLayout.class);
		typeMap.put("FlowLayout", FlowLayout.class);
		typeMap.put("BoxLayout", BoxLayout.class);
		typeMap.put("BinLayout", BinLayout.class);
	}
	
	@SuppressWarnings("unchecked")
	public GObject create(String typeName) {
		try {
			Class<? extends GObject> c = null;
			c = typeMap.get(typeName);
			if (c == null & typeName.indexOf('.')!=-1){
				c = (Class<? extends GObject>) Class.forName(typeName);
			}
			if (c == null & typeName.startsWith("Clutter")){
				c = typeMap.get(typeName.substring(7));
			}
			return c.newInstance();
		} catch (Exception e) {
			System.err.println("Type not found:"+typeName);
			return null;
		}
	}
	
	@Override
	public void register(String typeName, Class<? extends GObject> c) {
		typeMap.put(typeName, c);
	}

}
