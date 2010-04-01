package org.jclutter.tests.interactive;

import org.jclutter.Color;
import org.jclutter.Rotation;
import org.jclutter.Stage;
import org.jclutter.Texture;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.Mode;
import org.jclutter.animation.RotateBehaviour;
import org.jclutter.animation.Timeline;
import org.jclutter.tests.TestGroup;

public class ViewportTest extends TestGroup {

	@Override
	public void init() {
		Stage.getDefault().setColor(Color.BLACK);

		/* Make a hand */
		Texture hand = new Texture("src/test/resources/redhand.png");

		hand.setPosition(300, 200);
		hand.setClip(20, 21, 132, 170);
		hand.setAnchorPoint(86, 125);
		hand.show();
		add(hand);

		/* Make a timeline */
		Timeline timeline = new Timeline(7692, 0);
		timeline.setLoop(true);

		/* Set an alpha func to power behaviour */
		Alpha alpha = new Alpha(timeline, Mode.LINEAR);

		/* Create a behaviour for that alpha */
		RotateBehaviour r_behave = new RotateBehaviour(alpha,
				Rotation.Z_AXIS, RotateBehaviour.CLOCKWISE, 0.0, 360.0);

		/* Apply it to our actor */
		r_behave.apply(hand);

		/* start the timeline and thus the animations */
		timeline.start();
	}

}
