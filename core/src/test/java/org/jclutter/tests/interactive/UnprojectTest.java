package org.jclutter.tests.interactive;

import org.jclutter.Actor;
import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Point;
import org.jclutter.Rectangle;
import org.jclutter.Rotation;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.Event;
import org.jclutter.events.StageAdapter;

public class UnprojectTest {

	private static final int RECT_L = 200;
	private static final int RECT_T = 150;
	private static final int RECT_W = 320;
	private static final int RECT_H = 240;

	static Rectangle test_rectangle = null;
	static Text label = null;

	public static void main(String[] args) {

		int i, rotate_x = 0, rotate_y = 60, rotate_z = 0;

		for (i = 0; i < args.length; ++i) {
			if (!args[i].startsWith("--rotate-x")) {
				rotate_x = Integer.parseInt(args[i].substring(11));
			} else if (!args[i].startsWith("--rotate-y")) {
				rotate_y = Integer.parseInt(args[i].substring(11));
			} else if (!args[i].startsWith("--rotate-z")) {
				rotate_z = Integer.parseInt(args[i].substring(11));
			} else if (!args[i].startsWith("--help")) {
				System.out.println("[--rotage-x=degrees] "
						+ "[--rotage-y=degrees] " + "[--rotage-z=degrees]");

				return;
			}
		}

		Clutter.init();

		Stage stage = Stage.getDefault();
		stage.setListener(new StageAdapter(){
			
			public boolean onEvent(Stage s, Event event) {
				switch (event.getType()) {
				case Event.TYPE_BUTTON_PRESS: {
					Actor actor;
					float x = ((ButtonEvent)event).getX();
					float y = ((ButtonEvent)event).getY();

					actor = s.getActorAtPos(Stage.PICK_ALL, x, y);
					Point point = actor.transformStagePoint(x, y);

					if (point != null) {
						String txt;

						if (actor == test_rectangle) {
							txt = String.format("Click on rectangle\n"
									+ "Screen coords: [%d, %d]\n"
									+ "Local coords : [%d, %d]", (int) x,
									(int) y, (int) point.x, (int) point.y);
						} else {
							txt = String.format("Click on stage\n"
									+ "Screen coords: [%d, %d]\n"
									+ "Local coords : [%d, %d]", (int) x,
									(int) y, (int) point.x, (int) point.y);
						}

						label.setText(txt);
					} else
						label.setText("Unprojection failed.");
				}
					break;

				default:
					break;
				}
				return false;
			}
		});

		stage.setColor(Color.BLACK);
		stage.setSize(640, 480);

		Rectangle rect = new Rectangle(Color.WHITE);
		rect.setSize(RECT_W, RECT_H);
		rect.setPosition(RECT_L, RECT_T);
		rect.setRotation(new Rotation(Rotation.X_AXIS, rotate_x, 0, 0,
				0));
		rect.setRotation(new Rotation(Rotation.Y_AXIS, rotate_y, 0, 0,
				0));
		rect.setRotation(new Rotation(Rotation.Z_AXIS, rotate_z, 0, 0,
				0));
		stage.add(rect);
		test_rectangle = rect;

		String txt = String.format("Rectangle: L %d, R %d, T %d, B %d\n"
				+ "Rotation : x %d, y %d, z %d", RECT_L, RECT_L + RECT_W,
				RECT_T, RECT_T + RECT_H, rotate_x, rotate_y, rotate_z);

		Text label0 = new Text("Mono 8pt", txt);
		label0.setColor(Color.WHITE);

		label0.setPosition(10, 10);
		stage.add(label0);

		Text label = new Text("Mono 8pt", "Click around!");

		label.setColor(Color.BLUE);

		label.setPosition(10, 50);
		stage.add(label);

		stage.showAll();

		Clutter.mainStart();
	}

}
