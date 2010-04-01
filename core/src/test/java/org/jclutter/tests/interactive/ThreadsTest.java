package org.jclutter.tests.interactive;

import java.util.Random;

import org.jclutter.Task;
import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Rectangle;
import org.jclutter.Rotation;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.Threads;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.Knot;
import org.jclutter.animation.Mode;
import org.jclutter.animation.PathBehaviour;
import org.jclutter.animation.RotateBehaviour;
import org.jclutter.animation.Timeline;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.KeyEvent;
import org.jclutter.events.StageAdapter;

public class ThreadsTest {

	private static final int RAND_MAX = 32767;
	private static final Random r = new Random();

	static Timeline timeline = null;
	static Text count_label = null;
	static Text help_label = null;
	static Rectangle progress_rect = null;

	static boolean test_thread_done_idle() {

		System.out.println("Thread completed");

		count_label.setText("Completed");
		timeline.stop();

		return false;
	}

	// static GStaticPrivate test_thread_data = G_STATIC_PRIVATE_INIT;

	static boolean update_label_idle(int count) {

		String text = "Count to " + count;

		count_label.setText(text);
		count_label.setWidth(-1);

		int width = 0;

		if (count == 0)
			width = 0;
		else if (count == 100)
			width = 350;
		else
			width = (int) (count / 100.0 * 350.0);

		progress_rect.setWidth(width);

		return false;
	}

	static void do_something_very_slow() {

		for (int i = 0; i < 100; i++) {
			int msecs;

			msecs = 1 + (int) (100.0 * r.nextInt(RAND_MAX) / ((RAND_MAX + 1.0) / 3));

			/* sleep for a while */
			try {
				Thread.sleep(msecs * 1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}

			if ((i % 10) == 0) {
				final int count = i;

				Threads.addIdleTask(new Task() {
					public boolean execute() {
						return update_label_idle(count);
					}
					public void destroy() {}
				}, 0);
			}
		}
	}

	static void test_thread_func() {

		do_something_very_slow();

		Threads.addIdleTask(new Task() {
			public boolean execute() {
				return test_thread_done_idle();
			}
			public void destroy(){}
		}, 0);

	}

	public static void main(String[] args) {
		Color stage_color = new Color(0xcc, 0xcc, 0xcc, 0xff);
		Color rect_color = new Color(0xee, 0x55, 0x55, 0x99);
		Color progress_color = new Color(0x55, 0xee, 0x55, 0xbb);
		Knot knots[] = { new Knot(75, 150), new Knot(400, 150) };

		// g_thread_init (NULL);
		Threads.init();
		Clutter.init();

		help_label = new Text("Mono 12", "Press 's' to start");
		help_label.setPosition(50, 50);
		timeline = new Timeline(3000, 0);
		timeline.setLoop(true);

		Stage stage = Stage.getDefault();
		stage.setListener(new StageAdapter(){
			
			public boolean onButtonPressEvent(Stage s, ButtonEvent event) {
				Clutter.mainQuit();
				return true;
			}

			
			public boolean onKeyPressEvent(Stage s, KeyEvent event) {
				switch (event.getKeySymbol()) {
				case 's':
					help_label.setText("Press 'q' to quit");

					timeline.start();

					return true;

				case 'q':
					Clutter.mainQuit();
					return true;

				default:
					break;
				}

				return false;
			}
		});
		stage.setColor(stage_color);
		stage.setSize(600, 300);

		count_label = new Text("Mono 12", "Counter");
		count_label.setPosition(350, 50);

		Rectangle rect = new Rectangle(rect_color);
		rect.setPosition(75, 150);
		rect.setSize(50, 50);
		rect.setAnchorPoint(25, 25);

		progress_rect = new Rectangle(progress_color);
		progress_rect.setPosition(50, 225);
		progress_rect.setSize(350, 50);

		stage.add(count_label, help_label, rect, progress_rect);

		Alpha alpha = new Alpha(timeline, Mode.LINEAR);
		RotateBehaviour r_behaviour = new RotateBehaviour(alpha,
				Rotation.Z_AXIS, RotateBehaviour.CLOCKWISE, 0.0f, 360.0f);
		r_behaviour.apply(rect);

		alpha = new Alpha(timeline, Mode.LINEAR);
		PathBehaviour p_behaviour = new PathBehaviour(alpha, knots);
		p_behaviour.apply(rect);

		stage.show();

		Threads.enter();
		Clutter.mainStart();
		Threads.leave();
	}

}
