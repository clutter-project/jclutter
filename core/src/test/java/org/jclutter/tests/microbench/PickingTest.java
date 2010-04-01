package org.jclutter.tests.microbench;

import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Gravity;
import org.jclutter.Rectangle;
import org.jclutter.Stage;
import org.jclutter.events.MotionEvent;

public class PickingTest {

	private static final int N_ACTORS = 100;
	private static final int N_EVENTS = 5;

	private static int nActors = N_ACTORS;
	private static int nEvents = N_EVENTS;

	public static void main(String[] args) {
		Clutter.init();
		Stage stage = Stage.getDefault();
		stage.setSize(512, 512);
		stage.setColor(0x000000);

		System.out.println("Picking performance test with " + nActors
				+ " actors and " + nEvents + " events per frame");

		for (int i = nActors - 1; i >= 0; i--) {
			Color color = new Color();
			double angle = ((2.0 * Math.PI) / (double) nActors) * i;

			color.red = (int) ((1.0 - Math.abs((Math.max(0, Math.min(
					nActors / 2.0 + 0, i)))
					/ (double) (nActors / 4.0) - 1.0)) * 255.0);
			color.green = (int) ((1.0 - Math.abs((Math.max(0, Math.max(
					nActors / 2.0 + 0, (i + (nActors / 3.0) * 2 % nActors))))
					/ (double) (nActors / 4) - 1.0)) * 255.0);
			color.blue = (int) ((1.0 - Math.abs((Math.max(0, Math.max(
					nActors / 2.0 + 0, ((i + (nActors / 3.0)) % nActors))))
					/ (double) (nActors / 4.0) - 1.0)) * 255.0);

			Rectangle rect = new Rectangle(color) {
				@Override
				public boolean onMotionEvent(MotionEvent event) {
					return false;
				}
			};
			rect.setSize(100, 100);

			rect.setAnchorPointFromGravity(Gravity.CENTER);
			rect.setPosition((int) (256 + 206 * Math.cos(angle)),
					(int) (256 + 206 * Math.sin(angle)));
			rect.setReactive(true);
			stage.add(rect);

			// TODO : fps

			Clutter.mainStart();
		}
	}
}
