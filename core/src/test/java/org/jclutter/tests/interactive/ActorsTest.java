package org.jclutter.tests.interactive;

import org.jclutter.Actor;
import org.jclutter.Clone;
import org.jclutter.Color;
import org.jclutter.Gravity;
import org.jclutter.Rotation;
import org.jclutter.Stage;
import org.jclutter.Texture;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.Behaviour;
import org.jclutter.animation.Mode;
import org.jclutter.animation.ScaleBehaviour;
import org.jclutter.animation.Timeline;
import org.jclutter.tests.TestGroup;

public class ActorsTest extends TestGroup {

	private static final int NHANDS = 6;

	private Actor[] hands = new Actor[NHANDS];
	private Actor bgtex;
	private float radius;

	private Behaviour scaler1, scaler2;
	private Timeline timeline;
	
	@Override
	public void init() {
		Stage.getDefault().setColor(new Color(0x61, 0x64, 0x8c, 0xff));

		timeline = new Timeline(6000, 0) {
			public void onNewFrame(int elapsedTime) {
				float rotation = (float) (getProgress() * 360f);
				getParent().setRotation(new Rotation(Rotation.Z_AXIS, rotation, getWidth() / 2,
						getHeight() / 2, 0));

				for (int i = 0; i < NHANDS; i++) {
					hands[i].setRotation(new Rotation(Rotation.Z_AXIS, -6 * rotation, 0, 0, 0));
				}
			}
		};
		timeline.setLoop(true);
		Alpha alpha = new Alpha(timeline, Mode.EASE_IN_CIRC);
		scaler1 = new ScaleBehaviour(alpha, 0.5, 0.5, 1.0, 1.0);
		scaler2 = new ScaleBehaviour(alpha, 1.0, 1.0, 0.5, 0.5);

		Texture realHand = Texture.createFromFile("src/test/resources/redhand.png");

		radius = (getWidth() + getHeight()) / NHANDS;

		for (int i = 0; i < NHANDS; i++) {
			if (i == 0)
				hands[0] = realHand;
			else
				hands[i] = new Clone(realHand);

			hands[i].setReactive(true);
			hands[i].setSize(200, 213);

			/* Place around a circle */
			float w = hands[i].getWidth();
			float h = hands[i].getHeight();

			float x = (getWidth() / 2 + radius
					* (float)Math.cos(i * Math.PI / (NHANDS / 2)) - w / 2);

			float y = (getHeight() / 2 + radius
					* (float)Math.sin(i * Math.PI / (NHANDS / 2)) - h / 2);

			hands[i].setPosition(x, y);
			hands[i].setAnchorPointFromGravity(Gravity.CENTER);
			
			add(hands[i]);

			((i % 2 == 1) ? scaler1 : scaler2).apply(hands[i]);
		}
		
		timeline.start();
	}

}
