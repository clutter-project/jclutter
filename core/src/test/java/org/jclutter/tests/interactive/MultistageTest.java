package org.jclutter.tests.interactive;

import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Rotation;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.Texture;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.Mode;
import org.jclutter.animation.RotateBehaviour;
import org.jclutter.animation.Timeline;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.StageAdapter;

public class MultistageTest {

	static int n_stages = 1;

	static boolean onButtonPress() {
		Color color = new Color(0xdd, 0x33, 0xdd, 0xff);
		Color white = new Color(0x99, 0x99, 0x99, 0xff);

		Stage new_stage = Stage.createStage();
		// if (!new_stage)
		// return FALSE;

		/* FIXME: below should really be automatic */
		/* clutter_stage_ensure_cogl_context (CLUTTER_STAGE(new_stage)); */

		new_stage.setColor(color);
		new_stage.setSize(320, 240);

		Texture tex = new Texture("src/test/resources/redhand.png") {
			
			public boolean onButtonPressEvent(ButtonEvent event) {
				hide();
				return true;
			}
		};

		if (tex == null)
			System.err.println("pixbuf load failed");

		tex.setReactive(true);

		new_stage.add(tex);

		String stage_label = "<b>Stage: " + n_stages + "</b>";
		Text label = new Text("Mono 12", stage_label);

		label.setColor(white);
		label.setUseMarkup(true);
		float width = (new_stage.getWidth() - label.getWidth()) / 2;
		float height = (new_stage.getHeight() - label.getHeight()) / 2;
		label.setPosition(width, height);
		new_stage.add(label);
		label.show();

		String win_title = "Stage:" + new_stage;
		new_stage.setTitle(win_title);

		Timeline timeline = new Timeline(2000, 0);
		timeline.setLoop(true);

		Alpha alpha = new Alpha(timeline, Mode.LINEAR);
		RotateBehaviour r_behave = new RotateBehaviour(alpha,
				Rotation.Y_AXIS, RotateBehaviour.CLOCKWISE, 0.0, 360.0);

		r_behave.setCenter((int) label.getWidth() / 2, 0, 0);

		r_behave.apply(label);
		timeline.start();

		new_stage.showAll();

		return true;
	}

	public static void main(String[] args) {
		Clutter.init();

		Stage stage_default = Stage.getDefault();
		
		Stage.getDefault().setListener(new StageAdapter(){
			
			public boolean onButtonPressEvent(Stage s, ButtonEvent event) {
				return onButtonPress();
			}
		});

		Text label = new Text("Mono 16", "Default stage");
		float width = (stage_default.getWidth() - label.getWidth()) / 2;
		float height = (stage_default.getHeight() - label.getHeight()) / 2;
		label.setPosition(width, height);
		stage_default.add(label);
		label.show();

		String win_title = "Stage:" + stage_default;
		stage_default.setTitle(win_title);

		stage_default.show();

		Clutter.mainStart();
	}

}
