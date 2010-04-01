package org.jclutter.tests.interactive;

import org.jclutter.Color;
import org.jclutter.Gravity;
import org.jclutter.Rectangle;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.Mode;
import org.jclutter.animation.ScaleBehaviour;
import org.jclutter.animation.Timeline;
import org.jclutter.tests.TestGroup;

public class ScaleTest extends TestGroup {

	static Gravity gravities[] = { Gravity.NORTH_EAST, Gravity.NORTH,
			Gravity.NORTH_WEST, Gravity.WEST, Gravity.SOUTH_WEST,
			Gravity.SOUTH, Gravity.SOUTH_EAST, Gravity.EAST, Gravity.CENTER,
			Gravity.NONE };

	int gindex = 0;
	Text label;
	Rectangle rect;

	@Override
	public void init() {
		Color rect_color = new Color(0xff, 0xff, 0xff, 0x99);

		Stage.getDefault().setColor(Color.BLACK);

		rect = new Rectangle(rect_color);
		rect.setSize(100, 100);
		rect.setPosition(100, 100);

		add(rect);

		label = new Text("Sans 20px", "");
		label.setColor(Color.WHITE);
		label.setPosition(rect.getX(), rect.getY() + rect.getHeight());

		add(label);

		rect_color.alpha = 0xff;
		rect = new Rectangle(rect_color);
		rect.setPosition(100, 100);
		rect.setSize(100, 100);

		add(rect);

		Timeline timeline = new Timeline(750, 0) {
			
			public void onCompleted() {
				Gravity gravity = gravities[gindex];

				rect.moveAnchorPointFromGravity(gravity);

				label.setText(gravity.toString());

				if (++gindex >= gravities.length)
					gindex = 0;
			};
		};

		Alpha alpha = new Alpha(timeline, Mode.LINEAR);

		ScaleBehaviour behave = new ScaleBehaviour(alpha, 0.0, 0.0, /*
																	 * scale
																	 * start
																	 */
		1.0, 1.0); /* scale end */

		behave.apply(rect);

		timeline.setLoop(true);
		timeline.start();
	}

}
