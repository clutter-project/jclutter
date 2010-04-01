package org.jclutter.tests.interactive;

import java.util.Timer;
import java.util.TimerTask;

import org.jclutter.Actor;
import org.jclutter.Clone;
import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Container;
import org.jclutter.Group;
import org.jclutter.Rectangle;
import org.jclutter.Rotation;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.Texture;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.DepthBehaviour;
import org.jclutter.animation.Mode;
import org.jclutter.animation.RotateBehaviour;
import org.jclutter.animation.Timeline;
import org.jclutter.events.ButtonEvent;
import org.jclutter.tests.TestGroup;

public class DepthTest extends TestGroup {


	@Override
	public boolean onButtonPressEvent(ButtonEvent event) {
		Clutter.mainQuit();
		return true;
	}
	
	@Override
	public void init() {
		Stage.getDefault().setColor(new Color(0xcccccc));
		Group group = new Group();
		add(group);
		Text label = new Text("Mono 26", "Clutter");
		label.setPosition(120, 200);
		label.show();
		Texture hand = Texture.createFromFile("src/test/resources/redhand.png");
		hand.setPosition(240, 100);
		hand.show();
		
		Rectangle rect = new Rectangle(new Color(0x88000000));
		rect.setPosition(340, 100);
		rect.setSize(200, 200);
		rect.show();
		
		group.add(hand, rect);
		add(label);
		
		Timeline timeline = new Timeline(3000, 0){
			@Override
			public void onCompleted() {
				setDirection (getDirection() == DIRECTION_BACKWARD ? DIRECTION_FORWARD : DIRECTION_BACKWARD);
				start();
			}
		};
		
		DepthBehaviour dbehave = new DepthBehaviour(new Alpha(timeline, Mode.LINEAR), -100, 100);
		dbehave.apply(label);
		
		Group janus = janusGroup("GREEN", "RED");
		add(janus);
		janus.setPosition(300, 350);
		RotateBehaviour rbehave = new RotateBehaviour(new Alpha(timeline, Mode.LINEAR), Rotation.Y_AXIS, RotateBehaviour.CLOCKWISE, 0, 360);
		rbehave.apply(janus);
		
		Group box = cloneBox(hand);
		add(box);
		box.setPosition(200, 250);
		box.setScale(0.5, 0.5);
		box.setRotation(new Rotation(Rotation.X_AXIS, 45, 0, 0, 0));
		box.setOpacity((byte) 0x44);
		
		rbehave = new RotateBehaviour(new Alpha(timeline, Mode.LINEAR), Rotation.Y_AXIS, RotateBehaviour.CLOCKWISE, 0, 360);
		rbehave.apply(box);
		
		timeline.start();
		
		final Actor [] raiseActors = {rect, hand};
		Timer timer = new Timer();
		timer.schedule(new TimerTask(){
			@Override
			public void run() {
				Actor temp = raiseActors[0];
				temp.raiseTop();
				raiseActors[0] = raiseActors[1];
				raiseActors[1] = temp;
			}
		}, 2000);
		
	}
	
	static Group janusGroup(String frontText, String backText){
		Group group = new Group();
		Rectangle rect = new Rectangle(new Color(0x000000));
		Text front = new Text("Sans 50px", frontText);
		Text back = new Text("Sans 50px", backText);
		front.setColor(0xff0000);
		back.setColor(0x00ff00);
		
		float width = front.getWidth();
		float height = front.getHeight();
		float width2 = back.getWidth();
		float height2 = back.getHeight();
		
		if (width2 > width)
			width = width2;
		if (height2 > height)
		    height = height2;
		rect.setSize(width, height);
		back.setRotation(new Rotation(Rotation.Y_AXIS, 180, (int)width / 2, 0, 0));
		group.add(back, rect, front);
		
		group.showAll();
		return group;
	}
	
	static Group cloneBox(Actor original){
		Group group = new Group();
		float width = original.getWidth();
		float height = original.getHeight();
		Actor clone = new Clone(original);
		  group.add(clone);
		  clone.setDepth ((int)width / 2);

		  clone = new Clone(original);
		  group.add(clone);
		  clone.setRotation(new Rotation(Rotation.Y_AXIS, 180, (int)width / 2, 0, 0));
		  clone.setDepth (-(int)width / 2);

		  clone = new Clone(original);
		  group.add(clone);
		  clone.setRotation(new Rotation(Rotation.Y_AXIS, 90, 0, 0, 0));
		  clone.setDepth ((int)width / 2);
		  clone.setPosition (0, 0);

		  clone = new Clone(original);
		  group.add(clone);
		  clone.setRotation(new Rotation(Rotation.Y_AXIS, 90, 0, 0, 0));
		  clone.setDepth ((int)width / 2);
		  clone.setPosition (width, 0);

		  clone = new Clone(original);
		  group.add(clone);
		  clone.setRotation(new Rotation(Rotation.X_AXIS, 90, 0, 0, 0));
		  clone.setDepth (- (int)width / 2);
		  clone.setPosition (0, height);

		  clone = new Clone(original);
		  group.add(clone);
		  clone.setRotation(new Rotation(Rotation.X_AXIS, 90, 0, 0, 0));
		  clone.setDepth (-1 * (int)width / 2);
		  clone.setPosition (0, 0);

		  group.showAll();
		
		return group;
	}
	
}
