package org.jclutter.tests.interactive;

import org.jclutter.Actor;
import org.jclutter.Color;
import org.jclutter.Dimension;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.animation.Animation;
import org.jclutter.animation.Mode;
import org.jclutter.events.ButtonEvent;
import org.jclutter.tests.TestGroup;

public class EasingTest extends TestGroup {

	
	static EasingMode easing_modes[] = {
		 new EasingMode( "linear", Mode.LINEAR),
		  new EasingMode( "easeInQuad", Mode.EASE_IN_QUAD),
		  new EasingMode( "easeOutQuad", Mode.EASE_OUT_QUAD),
		  new EasingMode( "easeInOutQuad", Mode.EASE_IN_OUT_QUAD),
		  new EasingMode( "easeInCubic", Mode.EASE_IN_CUBIC),
		  new EasingMode( "easeOutCubic", Mode.EASE_OUT_CUBIC),
		  new EasingMode( "easeInOutCubic", Mode.EASE_IN_OUT_CUBIC),
		  new EasingMode( "easeInQuart", Mode.EASE_IN_QUART),
		  new EasingMode( "easeOutQuart", Mode.EASE_OUT_QUART),
		  new EasingMode( "easeInOutQuart", Mode.EASE_IN_OUT_QUART),
		  new EasingMode( "easeInQuint", Mode.EASE_IN_QUINT),
		  new EasingMode( "easeOutQuint", Mode.EASE_OUT_QUINT),
		  new EasingMode( "easeInOutQuint", Mode.EASE_IN_OUT_QUINT),
		  new EasingMode( "easeInSine", Mode.EASE_IN_SINE),
		  new EasingMode( "easeOutSine", Mode.EASE_OUT_SINE),
		  new EasingMode( "easeInOutSine", Mode.EASE_IN_OUT_SINE),
		  new EasingMode( "easeInExpo", Mode.EASE_IN_EXPO),
		  new EasingMode( "easeOutExpo", Mode.EASE_OUT_EXPO),
		  new EasingMode( "easeInOutExpo", Mode.EASE_IN_OUT_EXPO),
		  new EasingMode( "easeInCirc", Mode.EASE_IN_CIRC),
		  new EasingMode( "easeOutCirc", Mode.EASE_OUT_CIRC),
		  new EasingMode( "easeInOutCirc", Mode.EASE_IN_OUT_CIRC),
		  new EasingMode( "easeInElastic", Mode.EASE_IN_ELASTIC),
		  new EasingMode( "easeOutElastic", Mode.EASE_OUT_ELASTIC),
		  new EasingMode( "easeInOutElastic", Mode.EASE_IN_OUT_ELASTIC),
		  new EasingMode( "easeInBack", Mode.EASE_IN_BACK),
		  new EasingMode( "easeOutBack", Mode.EASE_OUT_BACK),
		  new EasingMode( "easeInOutBack", Mode.EASE_IN_OUT_BACK),
		  new EasingMode( "easeInBounce", Mode.EASE_IN_BOUNCE),
		  new EasingMode( "easeOutBounce", Mode.EASE_OUT_BOUNCE),
		  new EasingMode( "easeInOutBounce", Mode.EASE_IN_OUT_BOUNCE)
		};

		final int n_easing_modes = easing_modes.length;
		int current_mode = 0;

		int duration = 1;
		boolean recenter = false;

		Text easing_mode_label;

		void on_animation_completed (Animation animation,
		                        Actor     rectangle)
		{
		  float base_x, base_y;
		  Mode cur_mode;

		  base_x = getWidth () / 2;
		  base_y = getHeight () / 2;

		  cur_mode = easing_modes[current_mode].mode;

		  rectangle.animate(cur_mode, 150, "x", base_x, "y", base_y);

		}

		boolean on_button_press (Actor       actor,
		                 ButtonEvent event,
		                 Actor       rectangle)
		{
		  if (event.getButton() == 3)
		    {
		      String text;
		      Dimension labelDim;

		      current_mode = (current_mode + 1 < n_easing_modes) ? current_mode + 1
		                                                         : 0;

		      text = String.format("Easing mode: %s (%d of %d)\n"
		                              +"Right click to change the easing mode",
		                              easing_modes[current_mode].name,
		                              current_mode + 1,
		                              n_easing_modes);

		      easing_mode_label.setText(text);

		      labelDim = easing_mode_label.getSize();

		      easing_mode_label.setPosition ( (int)(getWidth()  - labelDim.width  - 10),
		    		  (int)(getHeight() - labelDim.height - 10));
		    }
		  else if (event.getButton() == 1)
		    {
		      Animation animation;
		      Mode cur_mode;

		      cur_mode = easing_modes[current_mode].mode;

//		      animation = rectangle.animate(cur_mode, duration * 1000, 
//		    		  new String []{"x", "y"}, new Integer[]{event.getX(), event.getY()}
//		                              );

//		      if (recenter)
//		        g_signal_connect_after (animation, "completed",
//		                                G_CALLBACK (on_animation_completed),
//		                                rectangle);
		    }

		  return true;
		}

		static Actor make_bouncer (Color base_color,
		              float              width,
		              float              height)
		{
		  Actor retval = null;
		  // TODO:cairo ???
//		  cairo_t *cr;
//		  cairo_pattern_t *pattern;
//		  float radius = Math.max (width, height);
//
//		  retval = clutter_cairo_texture_new (width, height);
//
//		  cr = clutter_cairo_texture_create (CLUTTER_CAIRO_TEXTURE (retval));
//
//		  cairo_set_operator (cr, CAIRO_OPERATOR_CLEAR);
//		  cairo_paint (cr);
//		  cairo_set_operator (cr, CAIRO_OPERATOR_ADD);
//
//		  cairo_arc (cr, radius / 2, radius / 2, radius / 2, 0.0, 2.0 * G_PI);
//
//		  pattern = cairo_pattern_create_radial (radius / 2, radius / 2, 0,
//		                                         radius, radius, radius);
//		  cairo_pattern_add_color_stop_rgba (pattern,
//		                                     0,
//		                                     base_color->red / 255.0,
//		                                     base_color->green / 255.0,
//		                                     base_color->blue / 255.0,
//		                                     base_color->alpha / 255.0);
//		  cairo_pattern_add_color_stop_rgba (pattern,
//		                                     0.9,
//		                                     base_color->red / 255.0,
//		                                     base_color->green / 255.0,
//		                                     base_color->blue / 255.0,
//		                                     0.1);
//
//		  cairo_set_source (cr, pattern);
//		  cairo_fill_preserve (cr);
//
//		  cairo_pattern_destroy (pattern);
//		  cairo_destroy (cr);

		  
		  retval.setName ("bouncer");
		  retval.setSize ((int)width, (int)height);
		  retval.setAnchorPoint (width / 2, height / 2);
		  retval.setReactive (true);

		  return retval;
		}

		Object [] test_easing_entries[] = {
		  {
		    "re-center", 'r',
		    0,
//		    G_OPTION_ARG_NONE,
		    recenter,
		    "Re-center the actor when the animation ends",
		    null
		  },
		  {
		    "duration", 'd',
		    0,
//		    G_OPTION_ARG_INT,
		    duration,
		    "Duration of the animation",
		    "SECONDS"
		  },

		  { null }
		};

		
		@Override
		public void init() {
		  Color stage_color = new Color( 0x88, 0x88, 0xdd, 0xff );
		  Color rect_color = new Color( 0xee, 0x33, 0, 0xff );

		  Stage.getDefault().setColor(stage_color);

		  Actor rect = make_bouncer (rect_color, 50, 50);
		  add(rect);
		  rect.setPosition(getWidth()/2,getHeight()/2);

		  String text = String.format ("Easing mode: %s (%d of %d)\n" +
		                          "Right click to change the easing mode",
		                          easing_modes[current_mode].name,
		                          current_mode + 1,
		                          n_easing_modes);

		  Text label = new Text ();
		  
		  add(label);
		  label.setFontName("Sans 18px");
		  label.setText(text);
		  Dimension labelDim = label.getSize();
		  label.setPosition(getWidth() - labelDim.width -10, getHeight() - labelDim.height -10);
		  easing_mode_label = label;

		}

		static final class EasingMode {
			String name;
			Mode mode;
			protected EasingMode(String string, Mode mode){
				this.name = string;
				this.mode = mode;
			}
		}
		
}
