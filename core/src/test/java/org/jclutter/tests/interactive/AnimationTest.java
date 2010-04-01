package org.jclutter.tests.interactive;

import org.jclutter.Actor;
import org.jclutter.Color;
import org.jclutter.Dimension;
import org.jclutter.Point;
import org.jclutter.Rectangle;
import org.jclutter.animation.Animation;
import org.jclutter.animation.Mode;
import org.jclutter.events.AnimationAdapter;
import org.jclutter.events.ButtonEvent;
import org.jclutter.tests.TestGroup;

public class AnimationTest extends TestGroup {

	boolean is_expanded = false;

	boolean onButtonPress(final Actor actor) {
		float new_x, new_y;
		float new_width, new_height;
		double new_angle;
		Point vertex = new Point();
		Color new_color = new Color(0);

		Point pos = actor.getPosition();
		Dimension dim = actor.getSize();

		/*
		 * determine the final state of the animation depending on the state of
		 * the actor
		 */
		if (!is_expanded) {
			new_x = pos.x - 100;
			new_y = pos.y - 100;
			new_width = dim.width + 200;
			new_height = dim.height + 200;
			new_angle = 360.0;

			new_color.red = 0xdd;
			new_color.green = 0x44;
			new_color.blue = 0xdd;
			new_color.alpha = 0xff;
		} else {
			new_x = pos.x + 100;
			new_y = pos.y + 100;
			new_width = dim.width - 200;
			new_height = dim.height - 200;
			new_angle = 0.0;

			new_color.red = 0x44;
			new_color.green = 0xdd;
			new_color.blue = 0x44;
			new_color.alpha = 0x88;
		}

		vertex.x = new_width / 2;
		vertex.y = new_height / 2;
		vertex.z = 0;

		// TODO bind point, boolean
		Animation animation = actor.animate(Mode.EASE_IN_EXPO, 2000, 
				"x",new_x,
				"y",new_y, 
				"width", new_width, 
				"height",new_height,
				"color", new_color.getRgb(),
				"rotation-angle-z", new_angle/*, 
				"fixed::rotation-center-z", vertex,
				"fixed::reactive", false*/
				);
		
		animation.setListener(new AnimationAdapter(){
			
			public void onCompleted(Animation animation) {
				is_expanded = !is_expanded;
				
				System.out.println("Animation complete");
				
				actor.setReactive(true);
			}
		});

		return true;
	}

	@Override
	public void init() {
		Color rect_color = new Color(0x44, 0xdd, 0x44, 0xff);

		getParent().setColor(new Color(0x66, 0x66, 0xdd, 0xff));

		Rectangle rect = new Rectangle(rect_color) {
			public boolean onButtonPressEvent(ButtonEvent event) {
				return onButtonPress(this);
			}
		};
		add(rect);
		rect.setSize(50, 50);
		rect.setAnchorPoint(25, 25);
		rect.setPosition((int) getWidth() / 2,
				(int) getHeight() / 2);
		rect.setColor(rect_color);
		rect.setOpacity((byte) 0x88);
		rect.setReactive(true);
		rect.show();
	}

}
