package org.jclutter.tests.interactive;

import org.jclutter.Actor;
import org.jclutter.Clone;
import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Gravity;
import org.jclutter.Group;
import org.jclutter.Rotation;
import org.jclutter.Stage;
import org.jclutter.Texture;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.Mode;
import org.jclutter.animation.ScaleBehaviour;
import org.jclutter.animation.Timeline;
import org.jclutter.cogl.COGL;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.EventCallback;
import org.jclutter.events.KeyEvent;
import org.jclutter.events.TextureAdapter;
import org.jclutter.events.TimelineAdapter;
import org.jclutter.glib.GObject;
import org.jclutter.tests.TestGroup;

public class PaintWrapperTest extends TestGroup {

	static final int NHANDS = 6;

	Actor[] hand = new Actor[NHANDS];
	
	boolean[] paint_guards = new boolean[NHANDS];

	@Override
	public void init() {

		Color stage_color = new Color(0x61, 0x64, 0x8c, 0xff);

		Stage.getDefault().setColor(stage_color);

		/* Create a timeline to manage animation */
		Timeline timeline = new Timeline(6000, 0);

		timeline.setLoop(true);

		/* Set up some behaviours to handle scaling */
		Alpha alpha = new Alpha(timeline, Mode.EASE_IN_OUT_SINE); // sine
																			// wave

		ScaleBehaviour scaler_1 = new ScaleBehaviour(alpha, 0.5, 0.5, 1.0, 1.0);
		ScaleBehaviour scaler_2 = new ScaleBehaviour(alpha, 1.0, 1.0, 0.5, 0.5);

		Texture real_hand = Texture.createFromFile("src/test/resources/redhand.png");

		/* create a new group to hold multiple actors in a group */
		final Group group = new Group();

		final float radius = (getWidth() + getHeight()) / NHANDS;

		for (int i = 0; i < NHANDS; i++) {

			if (i == 0)
				hand[i] = real_hand;
			else
				hand[i] = new Clone(real_hand);

			hand[i].setReactive(true);

			hand[i].setSize(200, 213);

			/* Place around a circle */
			float w = hand[i].getWidth();
			float h = hand[i].getHeight();

			float x = (float) (getWidth() / 2 + radius
					* Math.cos(i * Math.PI / (NHANDS / 2)) - w / 2);

			float y = (float) (getHeight() / 2 + radius
					* Math.sin(i * Math.PI / (NHANDS / 2)) - h / 2);

			hand[i].setPosition(x, y);

			hand[i].moveAnchorPointFromGravity(Gravity.CENTER);

			hand[i].setListener(new TextureAdapter() {
				
				public boolean onButtonPressEvent(Texture actor,
						ButtonEvent event) {
					System.out
							.printf(
									"*** button press event (button:%d) at %.2f, %.2f ***\n",
									event, event.getX(), event.getY());

					actor.hide();

					return true;
				}

				
				public void onPaint(Texture actor) {
					int actor_num = 0;
					for (actor_num = 0; hand[actor_num] != actor; actor_num++)
						;

					assert (!paint_guards[actor_num]);

					COGL.setSource(255, 0, 0, 128);
					COGL.rectangle(0, 0, actor.getWidth() / 2, actor
							.getHeight() / 2);

					paint_guards[actor_num] = true;
				}
				
				@EventCallback(signal = "paint", when = GObject.CONNECT_AFTER)
				public void onPaintAfter(Texture actor) {
					int actor_num = 0;
					for (actor_num = 0; hand[actor_num] != actor; actor_num++)
						;

					assert (paint_guards[actor_num]);

					float w = actor.getWidth();
					float h = actor.getHeight();

					COGL.setSource(0, 255, 0, 128);
					COGL.rectangle(w / 2, h / 2, w, h);

					paint_guards[actor_num] = false;
				}
			});

			/* Add to our group group */
			group.add(hand[i]);

			if (i % 2 == 1)
				scaler_1.apply(hand[i]);
			else
				scaler_2.apply(hand[i]);
		}

		add(group);

		timeline.setListener(new TimelineAdapter() {
			public void onNewFrame(Timeline timeline, int elapsedTime) {
				double rotation = timeline.getProgress() * 360.0f;
				/* Rotate everything clockwise about stage center */
				group.setRotation(new Rotation(Rotation.Z_AXIS,
						(int) rotation, (int) getWidth() / 2,
						(int) getHeight() / 2, 0));
				for (int i = 0; i < hand.length; i++) {
					/*
					 * Rotate each hand around there centers - to get this we
					 * need to take into account any scaling.
					 */
					hand[i].setRotation(new Rotation(Rotation.Z_AXIS,
							(int) (-6.0 * rotation), 0, 0, 0));
				}
			}
		});
		/* and start it */
		timeline.start();

	}

	
	public boolean onKeyReleaseEvent(Stage main_stage, KeyEvent event) {
		if (event.getType() == KeyEvent.TYPE_KEY_RELEASE) {
			KeyEvent ke = (KeyEvent) event;
			System.out.printf("*** key press event (key:%c) ***\n", ke
					.getKeySymbol());

			if (ke.getKeySymbol() == 'q') {
				Clutter.mainQuit();
				return true;
			} else if (ke.getKeySymbol() == 'r') {
				for (int i = 0; i < hand.length; i++)
					hand[i].show();
				return true;
			}
		}

		return false;
	}
}
