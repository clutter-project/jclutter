package org.jclutter.tests.interactive;

import org.jclutter.Actor;
import org.jclutter.ActorBox;
import org.jclutter.Color;
import org.jclutter.Point;
import org.jclutter.Rectangle;
import org.jclutter.Rotation;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.Event;
import org.jclutter.events.MotionEvent;
import org.jclutter.tests.TestGroup;

public class ProjectTest extends TestGroup {
	
	Rectangle rect;
	Rectangle [] p = new Rectangle[5]; 

	void
	init_handles ()
	{

	  Point [] v = rect.getAbsAllocationVertices ();
	  Point v1 = new Point();
	  
	  for (int i = 0; i < 4; ++i)
	    {
	      p[i] = new Rectangle (Color.BLUE);
	      p[i].setSize (5, 5);
	      p[i].setPosition ( 0, 0);
	      add (p[i]);

	      p[i].setPosition (
					  v[i].x - p[i].getWidth () / 2,
					  v[i].y - p[i].getHeight () / 2);

	      p[i].raiseTop ();

	      p[i].show ();
	    }

	  v1.x = rect.getWidth () / 2;
	  v1.y = rect.getHeight () / 2;
	  v1.z = 0;
	  
	  Point v2 =rect.applyTransformToPoint(v1);
	  
	  p[4] = new Rectangle (Color.BLUE);
	  p[4].setSize (5, 5);
	  p[4].setPosition (0, 0);
	  add (p[4]);
	  p[4].setPosition (
				      v2.x - p[4].getWidth () / 2,
				      v2.y - p[4].getHeight () / 2);

	  p[4].raiseTop ();
	  
	  p[4].show ();
	}

	void place_handles ()
	{

	  Point [] v = rect.getAbsAllocationVertices();
	  Point v1 = new Point();
	  
	  for (int i = 0; i < 4; ++i)
	    {
		  p[i].setPosition (
				  v[i].x - p[i].getWidth () / 2,
				  v[i].y - p[i].getHeight () / 2);
	    }

	  v1.x = rect.getWidth () / 2;
	  v1.y = rect.getHeight () / 2;
	  v1.z = 0;
	  
	  Point v2 = rect.applyTransformToPoint(v1);
	  p[4].setPosition (
			  v2.x - p[4].getWidth () / 2,
			  v2.y - p[4].getHeight () / 2);
	}

//	#define M(m,row,col)  (m)[col*4+row]

	int find_handle_index (Actor a)
	{
	    for (int i = 0; i < p.length; ++i)
		if (p[i].equals(a))
		    return i;

	    return -1;
	}

	@Override
	public boolean onEvent(Event event) {
	  Actor dragging = null;
	  
	  switch (event.getType())
	    {
	    case Event.TYPE_BUTTON_PRESS:
	      {

		Actor actor = Stage.getDefault().getActorAtPos(Stage.PICK_ALL,
				((ButtonEvent)event).getX(), ((ButtonEvent)event).getY());
		
	        if (!actor.equals(Stage.getDefault()))
		  {
		    if (!actor.equals(rect))
		      dragging = actor;
		  }
	      }
	      break;

	    case Event.TYPE_MOTION:
	      {
		if (dragging != null)
		  { 
		    int i = find_handle_index (dragging);

		    if (i < 0)
		      break;
		  
		    
		    ActorBox box1 = dragging.getAllocationBox();
		    ActorBox box2 = rect.getAllocationBox();

		    int xp = (int) ((((MotionEvent)event).getX() - 3) - box1.x1);
		    int yp = (int) ((((MotionEvent)event).getY() - 3) - box1.y1);
		    
		    if (i == 4)
		      {
			System.out.printf ("moving box by %f, %f\n", xp, yp);
			rect.moveBy (xp, yp);
		      }
		    else
		      {
		    	System.out.printf  ("adjusting box by %f, %f, handle %d\n", xp, yp, i);

			switch (i)
			  {
			  case 0:
			    box2.x1 += xp;
			    box2.y1 += yp;
			    break;
			  case 1:
			    box2.x2 += xp;
			    box2.y1 += yp;
			    break;
			  case 2:
			    box2.x1 += xp;
			    box2.y2 += yp;
			    break;
			  case 3:
			    box2.x2 += xp;
			    box2.y2 += yp;
			    break;
			  }

	                /* FIXME this is just plain wrong, to allocate directly
	                 * like this
	                 */
//			clutter_actor_allocate (box2, true);
		      }
		    
	 	    place_handles ();
		  }
	      }
	      break;
	      
	    case Event.TYPE_BUTTON_RELEASE:
	      {
		dragging = null;
	      }
	      break;
	      
	    default:
	      break;
	    }
	  
	  return false;
	}

	@Override
	public void init() {
	  Stage.getDefault().setColor(Color.BLACK);

	  rect = new Rectangle (Color.WHITE);
	  rect.setSize (320, 240);
	  rect.setPosition (180, 120);
	  rect.setRotation (new Rotation(Rotation.Y_AXIS, 60, 0, 0, 0));
	  add (rect);

	  Text label = new Text ("Mono 8pt", "Drag the blue rectangles");
	  label.setColor (Color.WHITE);
	  
	  label.setPosition(10, 10);
	  add (label);
	  
	  init_handles ();
	 
	}
	
}
