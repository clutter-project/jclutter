package org.jclutter.tests.interactive;

import org.jclutter.Actor;
import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Group;
import org.jclutter.Rectangle;
import org.jclutter.Stage;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.Event;
import org.jclutter.events.KeyEvent;
import org.jclutter.events.StageAdapter;
import org.jclutter.tests.TestGroup;

public class EventsTest extends TestGroup {

	boolean fullScreen = false;
	boolean motionEventsEnabled = true;

	boolean blue_button_cb() {
		Stage stage = Stage.getDefault();

		if (fullScreen)
			fullScreen = false;
		else
			fullScreen = true;

		stage.setFullscreen(fullScreen);

		System.out.println("*** Fullscreen  "
				+ (fullScreen ? "enabled ***" : "disabled ***"));

		return false;
	}

	boolean red_button_cb() {
		if (motionEventsEnabled)
			motionEventsEnabled = false;
		else
			motionEventsEnabled = true;

		Clutter.setMotionEventsEnabled(motionEventsEnabled);

		System.out.println("*** Per actor motion events "
				+ (motionEventsEnabled ? "enabled ***" : "disabled ***"));

		return false;
	}

	static void key_focus_in_cb(Actor actor, Actor focus_box) {

		if (actor.equals(Stage.getDefault()))
			focus_box.hide();
		else {
			focus_box.setPosition(actor.getX() - 5, actor.getY() - 5);

			focus_box.setSize(actor.getWidth() + 10, actor.getHeight() + 10);
			focus_box.show();
		}
	}

	static void fill_keybuf(String keybuf, KeyEvent event) {

		int modifier_state = event.getModifierState();

		if (modifier_state == Event.STATE_SHIFT_MASK)
			keybuf += "<Shift>";
		if (modifier_state == Event.STATE_LOCK_MASK)
			keybuf += "<Lock>";
		if (modifier_state == Event.STATE_CONTROL_MASK)
			keybuf += "<Control>";
		if (modifier_state == Event.STATE_MOD1_MASK)
			keybuf += "<Mod1>";
		if (modifier_state == Event.STATE_MOD2_MASK)
			keybuf += "<Mod2>";
		if (modifier_state == Event.STATE_MOD3_MASK)
			keybuf += "<Mod3>";
		if (modifier_state == Event.STATE_MOD4_MASK)
			keybuf += "<Mod4>";
		if (modifier_state == Event.STATE_MOD5_MASK)
			keybuf += "<Mod5>";
		// keybuf += utf8;
	}

	public static boolean debugEvent(Actor actor, Event event, String source) {
		Stage stage = Stage.getDefault();

		String keybuf = ""; // TODO

		switch (event.getType()) {
		case Event.TYPE_KEY_PRESS:
			// fill_keybuf (keybuf, ke.get);
			System.out.printf("[%s] KEY PRESS %s", source, keybuf);
			break;
		case Event.TYPE_KEY_RELEASE:
			// fill_keybuf (keybuf, &event->key);
			System.out.printf("[%s] KEY RELEASE %s", source, keybuf);
			break;
		case Event.TYPE_MOTION:
			System.out.printf("[%s] MOTION", source);
			break;
		case Event.TYPE_ENTER:
			System.out.printf("[%s] ENTER", source);
			break;
		case Event.TYPE_LEAVE:
			System.out.printf("[%s] LEAVE", source);
			break;
		case Event.TYPE_BUTTON_PRESS:
			System.out.printf("[%s] BUTTON PRESS (click count:%d)", source, ((ButtonEvent) event)
					.getClickCount());
			break;
		case Event.TYPE_BUTTON_RELEASE:
			System.out.printf("[%s] BUTTON RELEASE (click count:%d)", source,
					((ButtonEvent) event).getClickCount());
			if (event.getSource().equals(stage))
				stage.setKeyFocus(null);
			else if (event.getSource() == actor
					&& actor.getParent().equals(stage))
				stage.setKeyFocus(actor);
			break;
		case Event.TYPE_SCROLL:
			System.out.printf("[%s] BUTTON SCROLL (click count:%d)", source);
			break;
		case Event.TYPE_STAGE_STATE:
			System.out.printf("[%s] STAGE STATE", source);
			break;
		case Event.TYPE_DESTROY_NOTIFY:
			System.out.printf("[%s] DESTROY NOTIFY", source);
			break;
		case Event.TYPE_CLIENT_MESSAGE:
			System.out.printf("[%s] CLIENT MESSAGE", source);
			break;
		case Event.TYPE_DELETE:
			System.out.printf("[%s] DELETE", source);
			break;
		case Event.TYPE_NOTHING:
			return false;
		}

		if (event.getSource().equals(actor))
			System.out.printf(" *source*");

		System.out.println();

		return false;
	}

	@Override
	public void init() {
		Color rcol = new Color(0xff, 0, 0, 0xff);
		Color bcol = new Color(0, 0, 0xff, 0xff);
		Color gcol = new Color(0, 0xff, 0, 0xff);
		Color ycol = new Color(0xff, 0xff, 0, 0xff);
		Color ncol = new Color(0, 0, 0, 0xff);

		Stage.getDefault().setListener(new StageAdapter() {
			
			public void onFullscreen(Stage s) {
				System.out.println("[stage signal] fullscreen");
			}

			
			public void onUnfullscreen(Stage s) {
				System.out.println("[stage signal] unfullscreen");
			}

			
			public void onActivate(Stage s) {
				System.out.println("[stage signal] activate");
			}

			
			public void onDeactivate(Stage s) {
				System.out.println("[stage signal] deactivate");
			}

			
			public boolean onEvent(Stage s, Event event) {
				// TODO Auto-generated method stub
				return super.onEvent(s, event);
			}

			
			public boolean onCapturedEvent(Stage s, Event event) {
				System.out.printf("* captured event for type '%s' *\n", this
						.getClass().getSimpleName());
				return false;
			}
		});

		final Rectangle focus_box = new Rectangle(ncol);
		add(focus_box);

		Rectangle actor = new Rectangle(rcol) {
			
			public boolean onEvent(Event event) {
				return debugEvent(this, event, "red box");
			}

			
			public void onKeyFocusIn() {
				key_focus_in_cb(this, focus_box);
			}

			
			public boolean onButtonPressEvent(ButtonEvent event) {
				// TODO Auto-generated method stub
				return red_button_cb();
			}

		};
		actor.setSize(100, 100);
		actor.setPosition(100, 100);

		actor.setReactive(true);

		add(actor);

		Stage.getDefault().setKeyFocus(actor);

		actor = new Rectangle(gcol) {
			
			public boolean onCapturedEvent(Event event) {
				System.out.printf("* captured event for type '%s' *\n", this
						.getClass().getSimpleName());
				return false;
			}

			
			public boolean onEvent(Event event) {
				return debugEvent(this, event, "green box");
			}

			
			public void onKeyFocusIn() {
				key_focus_in_cb(this, focus_box);
			}
		};
		actor.setSize(100, 100);
		actor.setPosition(250, 100);

		actor.setReactive(true);

		add(actor);

		actor = new Rectangle(bcol) {
			
			public boolean onEvent(Event event) {
				return debugEvent(this, event, "blue box");
			}

			
			public boolean onButtonPressEvent(ButtonEvent event) {
				// TODO Auto-generated method stub
				return blue_button_cb();
			}

			
			public void onKeyFocusIn() {
				key_focus_in_cb(this, focus_box);
			}
		};
		actor.setSize(100, 100);
		actor.setPosition(400, 100);

		actor.setReactive(true);

		add(actor);

		/* non reactive */
		actor = new Rectangle(ncol) {
			
			public void onKeyFocusIn() {
				key_focus_in_cb(this, focus_box);
			}

			
			public boolean onEvent(Event event) {
				return debugEvent(this, event, "blue box");
			}
		};
		actor.setSize(400, 50);
		actor.setPosition(100, 250);

		add(actor);

		/* non reactive group, with reactive child */
		actor = new Rectangle(ycol) {
			
			public boolean onEvent(Event event) {
				return debugEvent(this, event, "yellow box");
			}
		};
		actor.setSize(100, 100);
		actor.setReactive(true);

		/* note group not reactive */
		Group group = new Group();
		group.add(actor);
		add(group);
		group.setPosition(100, 350);
		group.showAll();

	}

}
