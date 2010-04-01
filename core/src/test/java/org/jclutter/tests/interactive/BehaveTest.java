package org.jclutter.tests.interactive;

import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Rectangle;
import org.jclutter.Rotation;
import org.jclutter.Stage;
import org.jclutter.Texture;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.Behaviour;
import org.jclutter.animation.EllipseBehaviour;
import org.jclutter.animation.Mode;
import org.jclutter.animation.OpacityBehaviour;
import org.jclutter.animation.Path;
import org.jclutter.animation.PathBehaviour;
import org.jclutter.animation.RotateBehaviour;
import org.jclutter.animation.Timeline;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.KeyEvent;
import org.jclutter.events.ScrollEvent;
import org.jclutter.tests.TestGroup;

public class BehaveTest extends TestGroup {
	
	@Override
	public boolean onButtonPressEvent(ButtonEvent event) {
		String click_type;

		switch (event.getClickCount()) {
		case 2:
			click_type = "double";
			break;
		case 3:
			click_type = "triple";
			break;
		default:
			click_type = "single";
			break;
		}

		System.out.print(String.format("%s button press event\n", click_type));

		return false;
	}
	
	@Override
	public boolean onScrollEvent(ScrollEvent event) {
		String s = String.format("scroll direction: %s\n",
				event.getDirection() == ScrollEvent.SCROLL_UP ? "up" : "down");
		System.out.print(s);
		return false;
	}
	
	
	@Override
	public boolean onKeyPressEvent(KeyEvent event) {
		log("key pressed");
		Clutter.mainQuit();
		return true;
	}

	enum PathType {
		PATH_POLY, PATH_ELLIPSE, PATH_BSPLINE
	};

	@Override
	public void init() {
		log("Behave test. Usage : ant test-interactive-behave -Dpath=poly|ellipse|bspline");
		log("Current parameter:"+getParam()+":");
		Color stage_color = new Color(0xcc, 0xcc, 0xcc, 0xff);
		Color rect_bg_color = new Color(0x33, 0x22, 0x22, 0xff);
		Color rect_border_color = new Color(0, 0, 0, 0);
		PathType path_type = PathType.PATH_POLY;

		String knots_poly = ("M 0, 0   L 0, 300 L 300, 300 "
				+ "L 300, 0 L 0, 0");

		/* A spiral created with inkscake */
		String knots_bspline = "M 34.285713,35.219326 "
				+ "C 44.026891,43.384723 28.084874,52.378758 20.714286,51.409804 "
				+ "C 0.7404474,48.783999 -4.6171866,23.967448 1.904757,8.0764719 "
				+ "C 13.570984,-20.348756 49.798303,-26.746504 74.999994,-13.352108 "
				+ "C 111.98449,6.3047056 119.56591,55.259271 99.047626,89.505034 "
				+ "C 71.699974,135.14925 9.6251774,143.91924 -33.571422,116.17172 "
				+ "C -87.929934,81.254291 -97.88804,5.8941057 -62.857155,-46.209236 "
				+ "C -20.430061,-109.31336 68.300385,-120.45954 129.2857,-78.114021 "
				+ "C 201.15479,-28.21129 213.48932,73.938876 163.80954,143.79074 "
				+ "C 106.45226,224.43749 -9.1490153,237.96076 -87.85713,180.93363 "
				+ "C -177.29029,116.13577 -192.00272,-12.937817 -127.61907,-100.49494 "
				+ "C -55.390344,-198.72081 87.170553,-214.62275 183.57141,-142.87593 "
				+ "C 290.59464,-63.223369 307.68641,92.835839 228.57145,198.07645";

		if ("poly".equals(getParam())){
			path_type = PathType.PATH_POLY;
		} else if ("bspline".equals(getParam())){
			path_type = PathType.PATH_BSPLINE;
		} else if ("ellipse".equals(getParam())){
			path_type = PathType.PATH_ELLIPSE;
		}
		
		System.out.println(":"+path_type);
		
		Stage.getDefault().hideCursor();
		Stage.getDefault().setColor(stage_color);

		/* Make a hand */
		Texture hand = Texture.createFromFile("src/test/resources/redhand.png");
		
		Rectangle rect = new Rectangle();
		rect.setSize(hand.getWidth(), hand.getHeight());
		rect.setColor(rect_bg_color);
		rect.setBorderWidth(10);
		rect_border_color = Color.BLACK;
		// TODO following like causes jvm to crash
//		rect_border_color = Color.getColor("DarkSlateGray");
//		if (rect_border_color == null) {
//			log("warn: no color found for DarkSlateGray");
//		}
		rect.setBorderColor(rect_border_color);

		add(rect, hand);
		
		/* Make a timeline */
		Timeline timeline = new Timeline(4000, 0){
			
			public void onCompleted() {
				int direction;

				direction = getDirection();

				if (direction == Timeline.DIRECTION_FORWARD)
					direction = Timeline.DIRECTION_BACKWARD;
				else
					direction = Timeline.DIRECTION_FORWARD;

				setDirection(direction);
			}
		};
		timeline.setLoop(true);
		
		/* Set an alpha func to power behaviour - ramp is constant rise */
		Alpha alpha = new Alpha(timeline, Mode.LINEAR);
		
		/* Create a behaviour for that alpha */
		
		OpacityBehaviour o_behave = new OpacityBehaviour(alpha, (byte) 0X33, (byte) 0xff);
		
		/* Apply it to our actor */
		o_behave.apply(this);
		
		Behaviour p_behave = null;
		/* Make a path behaviour and apply that too */
		switch (path_type) {
		case PATH_POLY: {
			Path path = new Path();
			path.setDescription(knots_poly);
			p_behave = new PathBehaviour(alpha, path);
		}
			break;
		case PATH_ELLIPSE:
			p_behave = new EllipseBehaviour(alpha, 200, 200, 400, 300,
					RotateBehaviour.CLOCKWISE, 0.0, 360.0);
			((EllipseBehaviour) p_behave).setAngleTilt(Rotation.X_AXIS,
					45.0f);
			((EllipseBehaviour) p_behave).setAngleTilt(Rotation.Z_AXIS,
					45.0f);
			break;

		case PATH_BSPLINE: {
			Path path = new Path();
			path.setDescription(knots_bspline);
			p_behave = new PathBehaviour(alpha, path);
		}
			break;
		}

		p_behave.apply(this);
		
		/* start the timeline and thus the animations */
		timeline.start();
		
		log("Behave test init done");
	}

}
