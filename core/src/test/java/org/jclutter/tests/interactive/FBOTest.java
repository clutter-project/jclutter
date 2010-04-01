package org.jclutter.tests.interactive;

import org.jclutter.Color;
import org.jclutter.Group;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.Texture;
import org.jclutter.animation.Animation;
import org.jclutter.animation.Mode;
import org.jclutter.tests.TestGroup;

public class FBOTest extends TestGroup {

	@Override
	public void init() {
		Texture fbo = null;
		Color blue = new Color(0x33, 0x44, 0x55, 0xff);
		Stage.getDefault().setColor(blue);
		Group onscreen = makeSource();
		onscreen.showAll();
		add(onscreen);
		float xpos = 0;
		float ypos = (getHeight() - onscreen.getHeight())/2;
		onscreen.setPosition(xpos, ypos);
		xpos += onscreen.getWidth();
		Animation anim = onscreen.animate(Mode.LINEAR, 5000, "rotation-angle-y", 360.0f);
		anim.setLoop(true);
		
		fbo = new Texture(onscreen); // should throw exception if fail
		fbo.setPosition(xpos, ypos);
		
		xpos += fbo.getWidth(); // why ?
		
		add(fbo);
	}
	
	static Group makeSource(){
		Group source = new Group();
		Texture image = new Texture("src/test/resources/redhand.png");
		source.add(image);
		
		Text text = new Text("Sans Bold 50px", "Clutter");
		text.setColor(Color.YELLOW);
		text.setY(source.getHeight() + 5);
		
		source.add(text);
		
		return source;
	}
}
