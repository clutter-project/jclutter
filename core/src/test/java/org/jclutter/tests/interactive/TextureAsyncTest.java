package org.jclutter.tests.interactive;

import java.util.Timer;
import java.util.TimerTask;

import org.jclutter.Clone;
import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Stage;
import org.jclutter.Texture;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.DepthBehaviour;
import org.jclutter.animation.Mode;
import org.jclutter.animation.Timeline;
import org.jclutter.events.ButtonEvent;
import org.jclutter.tests.TestGroup;

public class TextureAsyncTest extends TestGroup {


	private String path = "src/test/resources/redhand.png";
	
	private static final int LOAD_SYNC = 0;
	private static final int LOAD_DATA_ASYNC = 1;
	private static final int LOAD_ASYNC = 2;

	static void loadFinished(int loadType, boolean success, String error) {
		String load_str = null;

		switch (loadType) {
		case LOAD_SYNC:
			load_str = "synchronous loading";
			break;

		case LOAD_DATA_ASYNC:
			load_str = "asynchronous data loading";
			break;

		case LOAD_ASYNC:
			load_str = "asynchronous loading";
			break;
		}

		if (success) {
			System.out.println(load_str + " successful");
		} else {
			System.out.println(load_str + " failed:" + error);
		}
	}

	boolean task() {

		Texture[] image = new Texture[4];
		final Clone[] clone = new Clone[4];

		/* for (i=0;i<4;i++) */
		image[0] = new Texture() {
			
			public void onLoadFinished(boolean success, String messageIfAny) {
				loadFinished(LOAD_SYNC, success, messageIfAny);
			}

			
			public void onSizeChange(int width, int height) {
				clone[0].setSize(width, height);
			}
		};

		image[1] = new Texture() {
			
			public void onLoadFinished(boolean success, String messageIfAny) {
				loadFinished(LOAD_DATA_ASYNC, success, messageIfAny);
			}

			
			public void onSizeChange(int width, int height) {
				clone[1].setSize(width, height);
			}
		};
		image[1].setLoadDataAsync(true);

		image[2] = new Texture() {
			@Override
			public void onLoadFinished(boolean success, String messageIfAny) {
				loadFinished(LOAD_ASYNC, success, messageIfAny);
			}

			@Override
			public void onSizeChange(int width, int height) {
				clone[2].setSize(width, height);
			}
		};
		image[2].setLoadAsync(true);

		for (int i = 0; i < 3; i++) {
			image[i].setFromFile(path);
		}

		for (int i = 0; i < 3; i++) {
			add(image[i]);
		}

		for (int i = 0; i < 3; i++) {
			image[i].setPosition(50 + i * 100, 0 + i * 50);
			clone[i] = new Clone(image[i]);
			add(clone[i]);
			clone[i].setPosition(50 + i * 100, 150 + i * 50 + 100);
		}

		for (int i = 0; i < 3; i++) {
			Timeline timeline = new Timeline(5000, 0);
			Alpha alpha = new Alpha(timeline, Mode.LINEAR);
			DepthBehaviour depth_behavior = new DepthBehaviour(alpha, -2500, 0);
			depth_behavior.apply(image[i]);
			timeline.start();
		}
		return false;
	}

	@Override
	public void init() {
		Color stage_color = new Color(0x12, 0x34, 0x56, 0xff);

		// TODO g_thread_init (NULL);

		Stage.getDefault().setColor(stage_color);

		new Timer().scheduleAtFixedRate(new TimerTask() {
			@Override
			public void run() {
				task();
			}
		}, 0, 500);
	}
	
	
	public boolean onButtonPressEvent(Stage s, ButtonEvent event) {
		Clutter.mainQuit();
		return true;
	}

}
