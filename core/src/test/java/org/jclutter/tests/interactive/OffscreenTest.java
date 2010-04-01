package org.jclutter.tests.interactive;

import org.jclutter.Clutter;
import org.jclutter.Stage;

public class OffscreenTest {

	/* Very simple test just to see what happens setting up offscreen rendering */

	public static void main(String[] args) {
		Clutter.init();

		Stage stage = Stage.getDefault();

		stage.setOffscreen(true);

		if (!stage.isOffscreen())
			System.out.println("FAIL: Unable to setup offscreen rendering.");
		else
			System.out.println("SUCCESS: Able to setup offscreen rendering.");

		stage.showAll();

		Clutter.mainStart();
	}

}
