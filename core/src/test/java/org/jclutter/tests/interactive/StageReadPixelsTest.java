package org.jclutter.tests.interactive;

import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Rectangle;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.Texture;
import org.jclutter.events.MotionEvent;
import org.jclutter.events.StageAdapter;

public class StageReadPixelsTest {

	private static final int DOT_SIZE = 2;
	private static final int TEX_SIZE = 64;

//	static gboolean
//	on_motion_idle (gpointer user_data)
//	{
//	  CallbackData *data = (CallbackData *) user_data;
//	  guchar *pixels, *p;
//	  gfloat stage_width, stage_height;
//	  gint x, y;
//
//	  data->idle_source = 0;
//
//	  clutter_actor_get_size (data->stage, &stage_width, &stage_height);
//
//	  x = CLAMP (data->event.x - TEX_SIZE / 2, 0, stage_width - TEX_SIZE);
//	  y = CLAMP (data->event.y - TEX_SIZE / 2, 0, stage_height - TEX_SIZE);
//
//	  clutter_actor_set_position (data->box,
//	                              x + TEX_SIZE / 2 - 1,
//				      y + TEX_SIZE / 2 - 1);
//	  clutter_actor_show (data->box);
//	  /* Redraw so that the layouting will be done and the box will be
//	     drawn in the right position */
//	  clutter_redraw (CLUTTER_STAGE (data->stage));
//
//	  pixels = clutter_stage_read_pixels (CLUTTER_STAGE (data->stage),
//					      x, y,
//	                                      TEX_SIZE, TEX_SIZE);
//
//	  /* Make a red dot in the center */
//	  p = pixels + (TEX_SIZE / 2 - DOT_SIZE / 2) * TEX_SIZE * 4
//	    + (TEX_SIZE / 2 - DOT_SIZE / 2) * 4;
//	  for (y = 0; y < DOT_SIZE; y++)
//	    {
//	      for (x = 0; x < DOT_SIZE; x++)
//		{
//		  *(p++) = 255;
//		  memset (p, 0, 3);
//		  p += 3;
//		}
//	      p += TEX_SIZE * 4 - DOT_SIZE * 4;
//	    }
//
//	  /* Set all of the alpa values to full */
//	  for (p = pixels + TEX_SIZE * TEX_SIZE * 4; p > pixels; p -= 4)
//	    *(p - 1) = 255;
//
//	  clutter_texture_set_from_rgb_data (CLUTTER_TEXTURE (data->tex),
//					     pixels, TRUE,
//					     TEX_SIZE, TEX_SIZE,
//					     TEX_SIZE * 4, 4, 0, NULL);
//	  g_free (pixels);
//
//	  return FALSE;
//	}
//
//	static gboolean
//	on_motion (ClutterActor *stage, ClutterMotionEvent *event, CallbackData *data)
//	{
//	  /* Handle the motion event in an idle handler so that multiple
//	     events will be combined into one */
//	  if (data->idle_source == 0)
//	    data->idle_source = clutter_threads_add_idle (on_motion_idle, data);
//
//	  data->event = *event;
//
//	  return FALSE;
//	}

	public static void main(String[] args) {
	  Clutter.init();

	  
	  Stage stage = Stage.getDefault();
		stage.setListener(new StageAdapter(){
		  
		public boolean onMotionEvent(Stage s, MotionEvent event) {
			// TODO 
			return super.onMotionEvent(s, event);
		}
	  });
	  int idle_source = 0;
	  Texture tex = new Texture ();
	  tex.setSize (TEX_SIZE * 2, TEX_SIZE * 2);
	  Rectangle box = new Rectangle(Color.BLUE);
	  box.setSize (DOT_SIZE + 2, DOT_SIZE + 2);
	  box.hide ();
	  
	  tex.setPosition (
				      stage.getWidth()
				      - tex.getWidth(),
				      stage.getHeight()
				      - tex.getHeight());

	  Text label = new Text("Sans 10", "A very long label,\nvery looooong,\n really very very very loooooooooooooong");
	  stage.add (label, tex, box);

	  stage.show ();

	  Clutter.mainStart();
	}
	
}
