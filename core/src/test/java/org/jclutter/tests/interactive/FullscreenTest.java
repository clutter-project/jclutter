package org.jclutter.tests.interactive;

import java.util.Timer;
import java.util.TimerTask;

import org.jclutter.Clutter;
import org.jclutter.Stage;
import org.jclutter.events.StageAdapter;
import org.jclutter.tests.TestGroup;

public class FullscreenTest extends TestGroup {

	@Override
	public void init() {
		Stage stage = Stage.getDefault();
		stage.setListener(new StageAdapter(){
			
			public void onFullscreen(Stage s) {
				System.out.printf(
						"fullscreen set, size: %.2fx%.2f, mapped: %s",
						s.getWidth(), s.getHeight(), s.isMapped() ? "true" : "false");
			}

			
			public void onUnfullscreen(Stage s) {
				System.out.printf(
						"fullscreen unset, size: %.2fx%.2f, mapped: %s",
						s.getWidth(), s.getHeight(), s.isMapped() ? "true" : "false");
			}
		});

		stage.setFullscreen(true);
		stage.show();

		System.out.printf("stage size: %.2fx%.2f, mapped: %s",
				stage.getWidth(), stage.getHeight(), stage.isMapped() ? "true"
						: "false");

		new Timer().scheduleAtFixedRate(new TimerTask() {
			static final int START = 0;
			static final int HIDE = 1;
			static final int SHOW = 2;
			static final int DONE = 3;

			int state = START;

			@Override
			public void run() {
				Stage stage = Stage.getDefault();
				boolean is_fullscreen = stage.isFullscreen();

				switch (state) {
				case START:
					System.out.printf("start: is_fullscreen := %s",
							is_fullscreen ? "true" : "false");
					stage.hide();
					state = HIDE;
					break;

				case HIDE:
					System.out.printf("hide:  is_fullscreen := %s",
							is_fullscreen ? "true" : "false");
					stage.show();
					state = SHOW;
					break;

				case SHOW:
					System.out.printf("show:  is_fullscreen := %s",
							is_fullscreen ? "true" : "false");
					stage.setFullscreen(false);
					state = DONE;
					break;

				case DONE:
					System.out.printf("done:  is_fullscreen := %s",
							is_fullscreen ? "true" : "false");
					Clutter.mainQuit();
					break;
				}
			}
		}, 500, 1000);

	}
}
