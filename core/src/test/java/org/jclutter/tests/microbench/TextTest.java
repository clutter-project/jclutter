package org.jclutter.tests.microbench;

import org.jclutter.Clutter;
import org.jclutter.Group;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.events.KeyEvent;
import org.jclutter.events.StageAdapter;
import org.jclutter.glib.Glib;

public class TextTest {

	private static final int STAGE_WIDTH = 640;
	private static final int STAGE_HEIGHT = 480;

	private static final int COLS = 18;
	private static final int ROWS = 20;

	private static long lastTime = System.currentTimeMillis();

	private static int fps = 0;

	public static void main(String[] args) {
		Glib.setEnv("CLUTTER_VBLANK", "none", false);
		Glib.setEnv("CLUTTER_DEFAULT_FPS", "1000", false);

		Clutter.init();

		Stage stage = Stage.getDefault();
		stage.setListener(new StageAdapter(){
			
			public boolean onKeyPressEvent(Stage s, KeyEvent event) {
				Clutter.mainQuit();
				return true;
			}
		});

		stage.setSize(STAGE_WIDTH, STAGE_HEIGHT);
		stage.setColor(0x000000);

		Group group = new Group() {
			
			public void onPaint() {
				long now = System.currentTimeMillis();
				if ((now - lastTime) > 1000) {
					lastTime = now;
					System.out.println("fps :" + fps);
					fps = 0;
				}
				fps++;
			}
		};
		group.setSize(STAGE_WIDTH, STAGE_HEIGHT);

		stage.add(group);

		// TODO g_idle_add (queue_redraw, stage);

		for (int row = 0; row < ROWS; row++) {
			for (int col = 0; col < COLS; col++) {

				int font_size = row + 10;
				double scale = 0.17 + (1.5 * col / COLS);
				String font_name = "Sans " + font_size + "px";
				String text = "OH";

				if (row == 0 | col == 0) {
					font_size = 10;
					scale = 1.0;
					text = ""; // TODO: not exactly that
				}

				Text label = new Text(font_name, text);
				label.setColor(0xffffff);
				label.setPosition((STAGE_WIDTH / COLS) * col,
						(STAGE_HEIGHT / ROWS) * row);
				label.setScale(scale, scale);
				label.setLineWrap(false);
				group.add(label);
			}
		}

		stage.showAll();

		Clutter.mainStart();
	}

	static boolean queueRedraw(long stagePointer) {
		Stage.getDefault().queueRedraw();
		return true;
	}

}
