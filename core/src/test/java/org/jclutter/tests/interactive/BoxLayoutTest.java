package org.jclutter.tests.interactive;

import java.util.Random;

import org.jclutter.Box;
import org.jclutter.BoxLayout;
import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Container;
import org.jclutter.Rectangle;
import org.jclutter.Stage;
import org.jclutter.cogl.COGL;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.CrossingEvent;
import org.jclutter.events.EventCallback;
import org.jclutter.events.KeyEvent;
import org.jclutter.glib.GObject;
import org.jclutter.pango.Layout;
import org.jclutter.tests.TestGroup;

public class BoxLayoutTest extends TestGroup {

	static String INSTRUCTIONS = "Press v\t\342\236\236\tSwitch horizontal/vertical\n"
			+ "Press p\t\342\236\236\tSwitch pack start/end\n"
			+ "Press s\t\342\236\236\tIncrement spacing (up to 12px)\n"
			+ "Press a\t\342\236\236\tSwitch animations on/off\n"
			+ "Press q\t\342\236\236\tQuit";

	Random random = new Random();

	BoxLayout layout = new BoxLayout();

	Box box = new Box(layout);
	
	Rectangle hover = null;
	
	boolean expand = true;
	
	int index;

	@Override
	public void init() {
		Stage.getDefault().setUserResizable(true);
		add(box);
		for (int i = 0; i < 5; i++) {
			addActor();
		}
	}
	
	private void addActor(){
		Color c = new Color();
		c.setHls((float)(random.nextInt(100)/100), .5f, 0.5f);

		Rectangle r = new Rectangle(c) {
			@EventCallback(when = GObject.CONNECT_AFTER)
			public void onPaint() {
				Layout pl = createPangoLayout(""+index++);
				COGL.renderLayout(pl, (int)(getWidth()-(pl.getWidth()/1024))/2, 
						(int)(getHeight()-(pl.getHeight()/1024))/2, Color.BLACK.toCoglColor(), 0);
			}

			@EventCallback
			public boolean onEnterEvent(CrossingEvent event) {
				setBorderColor(Color.BLACK);
				setBorderWidth(2);
				hover = this;
				return true;
			}

			@EventCallback
			public boolean onLeaveEvent(CrossingEvent event) {
				setBorderWidth(0);
				hover = null;
				return true;
			}

			@EventCallback
			public boolean onButtonReleaseEvent(ButtonEvent event) {
				if (event.getButton() == 1) {
					layout.setFill(this, !layout.isFillX(this), !layout
							.isFillY(this));
				} else {
					int xalign = layout.getAlignmentX(this);
					int yalign = layout.getAlignmentY(this);
					
					if (xalign < 2)
						xalign += 1;
					else
						xalign = 0;

					if (yalign < 2)
						yalign += 1;
					else
						yalign = 0;
					
					layout.setAlignment(this, xalign, yalign);
				}
				return true;
			}
		};
		r.setSize(32, 64);
		box.add(r, new BoxLayout.Constraint(expand, false, false,
				BoxLayout.CENTER, BoxLayout.CENTER));
		r.setReactive(true);
		expand = !expand;
	}
	
	
	public boolean onKeyReleaseEvent(Container actor, KeyEvent event) {
		  switch (event.getKeyUnicode())
		    {
		    case 'a':
		      layout.setUseAnimations(!layout.isUseAnimations());
		      break;

		    case 'v':
		    	layout.setVertical(!layout.isVertical());
		      break;

		    case 'p':
		    	layout.setPackStart(!layout.isPackStart());
		      break;

		    case 's':
		      int spacing = layout.getSpacing();

		      if (spacing > 12)
		        spacing = 0;
		      else
		        spacing++;

		      layout.setSpacing(spacing);
		      break;

		    case '+':
		      addActor();
		      break;

		    case 'q':
		      Clutter.mainQuit();
		      break;

		    default:
		      return false;
		    }
		
		return true;
	}

}
