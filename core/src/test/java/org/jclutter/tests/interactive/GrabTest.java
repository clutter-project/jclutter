package org.jclutter.tests.interactive;

import org.jclutter.Actor;
import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Rectangle;
import org.jclutter.Stage;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.Event;
import org.jclutter.events.StageAdapter;
import org.jclutter.tests.TestGroup;

public class GrabTest extends TestGroup {

	@Override
	public void init() {
		System.out.println("Red box:    aquire grab on press, releases it on next button release");
		System.out.println("Blue box:   aquire grab on press, destroys the blue box actor on release");
		System.out.println("Yellow box: aquire grab on press, releases grab on next press on yellow box");
		System.out.println("Green box:  toggle per actor motion events.");
		System.out.println("Cyan  box:  toggle grab (from cyan box) for keyboard events.");
		System.out.println();

		Stage.getDefault().setListener(new StageAdapter() {
			
			public boolean onEvent(Stage s, Event event) {
				return EventsTest.debugEvent(s, event, "stage");
			}

			
			public void onFullscreen(Stage s) {
				System.out.printf("[stage signal] %s\n", "fullscreen");
			}

			
			public void onUnfullscreen(Stage s) {
				System.out.printf("[stage signal] %s\n", "unfullscreen");
			}

			
			public void onActivate(Stage s) {
				System.out.printf("[stage signal] %s\n", "activate");
			}

			
			public void onDeactivate(Stage s) {
				System.out.printf("[stage signal] %s\n", "deactivate");
			}
		});

		Rectangle actor = new Rectangle(Color.RED) {
			
			public boolean onEvent(Event event) {
				return EventsTest.debugEvent(this, event, "red box");
			}

			
			public boolean onButtonPressEvent(ButtonEvent event) {
				Clutter.grabPointer(this);
				return false;
			}

			
			public boolean onButtonReleaseEvent(ButtonEvent event) {
				Clutter.ungrabPointer();
				return false;
			}
		};
		actor.setSize(100, 100);
		actor.setPosition(100, 100);
		actor.setReactive(true);
		add(actor);

		actor = new Rectangle(Color.YELLOW) {
			
			public boolean onEvent(Event event) {
				return EventsTest.debugEvent(this, event, "yellow box");
			}

			
			public boolean onButtonPressEvent(ButtonEvent event) {
				if (Clutter.getPointerGrab() != null)
					Clutter.ungrabPointer();
				else
					Clutter.grabPointer(this);
				return false;
			}
		};
		actor.setSize(100, 100);
		actor.setPosition(100, 300);
		actor.setReactive(true);
		add(actor);

		actor = new Rectangle(Color.BLUE) {
			
			public boolean onEvent(Event event) {
				return EventsTest.debugEvent(this, event, "blue box");
			}

			
			public boolean onButtonPressEvent(ButtonEvent event) {
				// TODO Auto-generated method stub
				return super.onButtonPressEvent(event);
			}

			
			public boolean onButtonReleaseEvent(ButtonEvent event) {
				destroy();
				return false;
			}
		};
		actor.setSize(100, 100);
		actor.setPosition(300, 100);
		actor.setReactive(true);
		add(actor);

		actor = new Rectangle(Color.GREEN) {
			
			public boolean onEvent(Event event) {
				return EventsTest.debugEvent(this, event, "green box");
			}

			
			public boolean onButtonPressEvent(ButtonEvent event) {
				Clutter
						.setMotionEventsEnabled(!Clutter
								.isMotionEventsEnabled());

				System.out.printf("per actor motion events are now %s\n",
						Clutter.isMotionEventsEnabled() ? "enabled"
								: "disabled");

				return false;
			}
		};
		actor.setSize(100, 100);
		actor.setPosition(300, 300);
		actor.setReactive(true);
		add(actor);

		actor = new Rectangle(Color.CYAN) {
			
			@Override
			public boolean onEvent(Event event) {
				return EventsTest.debugEvent(this, event, "cyan box");
			}

			
			public boolean onButtonPressEvent(ButtonEvent event) {
				if (Clutter.getPointerGrab() != null)
					Clutter.ungrabPointer();
				else
					Clutter.grabPointer(this);
				return false;
			}
		};
		actor.setSize(100, 100);
		actor.setPosition(500, 100);
		actor.setReactive(true);
		add(actor);
	}

	static boolean toggleGrabPointer(Actor actor, ButtonEvent event) {
		/* we only deal with the event if the source is ourself */
		if (event.getSource().equals(actor)) {
			if (Clutter.getPointerGrab() != null)
				Clutter.ungrabPointer();
			else
				Clutter.grabPointer(actor);
		}
		return false;
	}

}
