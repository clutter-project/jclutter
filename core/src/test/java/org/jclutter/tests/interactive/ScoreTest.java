package org.jclutter.tests.interactive;

import java.util.HashMap;
import java.util.Map;

import org.jclutter.Clutter;
import org.jclutter.animation.Score;
import org.jclutter.animation.Timeline;

public class ScoreTest {

	static int level = 1;

	public static void main(String[] args) {
		Clutter.init();

		final Map<Timeline, String> names = new HashMap<Timeline, String>();

		Timeline timeline_1 = new Timeline(1000, 0);
		Timeline timeline_2 = new Timeline(1000, 0);
		timeline_2.addMarkerAtTime("foo", 500);
		Timeline timeline_3 = new Timeline(1000, 0);
		Timeline timeline_4 = new Timeline(1000, 0);
		Timeline timeline_5 = new Timeline(1000, 0);

		names.put(timeline_1, "Timeline 1");
		names.put(timeline_2, "Timeline 2");
		names.put(timeline_3, "Timeline 3");
		names.put(timeline_4, "Timeline 4");
		names.put(timeline_5, "Timeline 5");

		Score score = new Score() {
			
			public void onStarted() {
				System.out.println("Score started");
			}

			
			public void onTimelineStarted(Timeline t) {
				for (int i = 0; i < level; i++)
					System.out.print(" ");

				System.out.println("Started timeline: " + names.get(t));
				level++;
			}

			
			public void onTimelineCompleted(Timeline t) {
				level--;

				for (int i = 0; i < level; i++)
					System.out.print(" ");

				System.out.println("Completed timeline: " + names.get(t));
			}

			
			public void onCompleted() {
				System.out.println("Score completed");
				Clutter.mainQuit();
			}

		};

		score.append(null, timeline_1);
		score.append(timeline_1, timeline_2);
		score.append(timeline_1, timeline_3);
		score.append(timeline_3, timeline_4);

		score.appendAtMarker(timeline_2, "foo", timeline_5);

		// TODO timelines = clutter_score_list_timelines (score);
		// g_assert (5 == g_slist_length (timelines));

		score.start();

		Clutter.mainStart();
	}

}
