package org.jclutter.tests.interactive;

import org.jclutter.Color;
import org.jclutter.Rotation;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.Texture;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.Mode;
import org.jclutter.animation.RotateBehaviour;
import org.jclutter.animation.Timeline;
import org.jclutter.tests.TestGroup;

public class RotateTest extends TestGroup {

	
	@Override
	public void init() {
		Color stage_color = new Color(0xcc, 0xcc, 0xcc, 0xff);

		Stage stage = Stage.getDefault();

		stage.setColor(stage_color);

		/* Make a hand */
		Texture hand = new Texture("src/test/resources/redhand.png");

		hand.setPosition(240, 140);
		hand.show();
		stage.add(hand);

		Text label = new Text("Mono 16", "The Wonder\n" + "of the\n"
				+ "Spinning Hand");
		// TODO label.setLineAlignment (PANGO_ALIGN_CENTER);
		label.setPosition(150, 150);
		label.setSize(500, 100);
		label.show();
		stage.add(label);

		/* Make a timeltine */
		Timeline timeline = new Timeline(7692, 0);
		timeline.setLoop(true);

		/* Set an alpha func to power behaviour */
		Alpha alpha = new Alpha(timeline, Mode.LINEAR);

		/* Create a behaviour for that alpha */
		RotateBehaviour r_behave = new RotateBehaviour(alpha, 
				Rotation.Z_AXIS, RotateBehaviour.CLOCKWISE, 
				0.0, 360.0);

		r_behave.setCenter(86, 125, 0);

		/* Apply it to our actor */
		r_behave.apply(hand);
		r_behave.apply(label);

		/* start the timeline and thus the animations */
		timeline.start();
	}

}
