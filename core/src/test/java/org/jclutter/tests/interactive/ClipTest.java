package org.jclutter.tests.interactive;

import static org.jclutter.cogl.COGL.clipPush;
import static org.jclutter.cogl.COGL.clipPushFromPath;
import static org.jclutter.cogl.COGL.pathClose;
import static org.jclutter.cogl.COGL.pathEllipse;
import static org.jclutter.cogl.COGL.pathFillPreserve;
import static org.jclutter.cogl.COGL.pathLineTo;
import static org.jclutter.cogl.COGL.pathMoveTo;
import static org.jclutter.cogl.COGL.pathRectangle;
import static org.jclutter.cogl.COGL.pathStroke;
import static org.jclutter.cogl.COGL.popMatrix;
import static org.jclutter.cogl.COGL.pushMatrix;
import static org.jclutter.cogl.COGL.rectangle;
import static org.jclutter.cogl.COGL.rectangleWithTextureCoords;
import static org.jclutter.cogl.COGL.rotate;
import static org.jclutter.cogl.COGL.setSource;
import static org.jclutter.cogl.COGL.setSourceTexture;
import static org.jclutter.cogl.COGL.translate;

import java.util.ArrayList;
import java.util.List;

import org.jclutter.Geometry;
import org.jclutter.Rectangle;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.cogl.COGL;
import org.jclutter.cogl.CoglTexture;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.EventCallback;
import org.jclutter.events.MotionEvent;
import org.jclutter.tests.TestGroup;

public class ClipTest extends TestGroup {

	enum ClipType
	  {
	    CLIP_NONE,
	    CLIP_RECTANGLE,
	    CLIP_ELLIPSE,
	    CLIP_SHAPES
	  }

	class Clip
	{
	  ClipType type = ClipType.CLIP_NONE;
	  int x1, y1, x2, y2;
	}
	
	private Clip current_clip = new Clip();

	static String
	instructions =
	  "Press and drag any of the three mouse buttons to add a clip with different "+
	  "shapes. Press 'r' to reset or 'u' to undo the last clip.";
	
	static List<Clip> clips = new ArrayList<Clip>(); 
	
	private CoglTexture hand;
	
	@Override
	public void init() {
		log("Loading cogl texture");
		hand = new CoglTexture ("src/test/resources/redhand.png",
				COGL.TEXTURE_NONE,
				COGL.PIXEL_FORMAT_ANY);
		log("Hand created");
		
		Rectangle stubActor = new Rectangle(){
			@EventCallback
			@Override
			public void onPaint() {
				log("Paint rectangle");
				Geometry stageGeo = Stage.getDefault().getAllocationGeometry();
				int hand_width = hand.getWidth();
				int hand_height = hand.getHeight();
				log("hand size :"+hand_width+","+hand_height);
				for (Clip clip : clips) {
					if (clip.type == ClipType.CLIP_RECTANGLE){
						clipPush(clip.x1, clip.y1, clip.x2 - clip.x1, clip.y2 - clip.y1);
					} else {
						makeClipPath(clip);
						clipPushFromPath();
					}
				}
				
				setSource(0x80, 0x80, 0xff, 0xff);
				rectangle(0, 0, stageGeo.width, stageGeo.height);
				
				drawShapes(10, 10);
				
				for (int i = -2; i <= 2; i++) {
					pushMatrix();
					translate(stageGeo.width / 2 + stageGeo.width / 6 * i,
							stageGeo.height / 2, 0);
					rotate(i * 40, 0, 1, 0);
					setSourceTexture(hand);
					rectangleWithTextureCoords((-hand_width / 2),
                            (-hand_height / 2),
                            (hand_width / 2),
                            (hand_height / 2),
                            0, 0, 1, 1);
					popMatrix();
				}
				
				drawShapes((int)getWidth()-310, (int)getHeight() -110);
				
				for(int i = 0; i <= clips.size(); i++){
					//clipPop();
				}
				
				for(Clip c : clips){
					makeClipPath(c);
					setSource(0, 0, 0xff, 0xff);
					pathStroke();
				}
				
				if (current_clip.type != ClipType.CLIP_NONE){
					makeClipPath(current_clip);
					setSource(0xff, 0, 0, 0xff);
					pathStroke();
				}
			}
		};
		add(stubActor);
		
		log("Rectangle added");
		
		Text label = new Text("Sans 12px", instructions);
		label.setLineWrap(true);
		label.setWidth(getWidth() - 310);
		label.setY(getHeight()-label.getHeight());
		add(label);
	}
	

	static void
	path_shapes (int x, int y, int width, int height)
	{
	  pathMoveTo (x, y);
	  pathLineTo (x, (y + height * 4 / 5));
	  pathLineTo ((x + width * 4 / 15), (y + height * 4 / 5));
	  pathClose ();

	  pathRectangle (x + width / 3,
	                       y,
	                       x + width * 9 / 15,
	                       y + height * 4 / 5);

	  pathEllipse ((x + width * 4 / 5),
	                     (y + height * 2 / 5),
	                     (width * 2 / 15),
	                     (height * 2 / 5));
	}

	static void drawShapes (int x, int y) {
//		log("draw shapes");
	  path_shapes (x, y, 300, 100);
	  setSource (0x00, 0x00, 0xff, 0xff);
	  pathFillPreserve ();
	  setSource (0xff, 0x00, 0x00, 0xff);
	  pathStroke ();
	}

	static void makeClipPath (Clip clip) {
//		log("make clip path");
	  switch (clip.type)
	    {
	    case CLIP_NONE:
	      break;

	    case CLIP_RECTANGLE:
	      pathRectangle (clip.x1,
	                           clip.y1,
	                           clip.x2,
	                           clip.y2);
	      break;

	    case CLIP_ELLIPSE:
	      pathEllipse ((clip.x1 + clip.x2) / 2,
	                         (clip.y1 + clip.y2) / 2,
	                         (clip.x2 - clip.x1) / 2,
	                         (clip.y2 - clip.y1) / 2);
	      break;

	    case CLIP_SHAPES:
	      {
	        int x, y, width, height;

	        if (clip.x1 < clip.x2)
	          {
	            x = clip.x1;
	            width = clip.x2 - x;
	          }
	        else
	          {
	            x = clip.x2;
	            width = clip.x1 - x;
	          }
	        if (clip.y1 < clip.y2)
	          {
	            y = clip.y1;
	            height = clip.y2 - y;
	          }
	        else
	          {
	            y = clip.y2;
	            height = clip.y1 - y;
	          }

	        path_shapes (x, y, width, height);
	      }
	      break;
	    }
	}
	
	
	@Override
	public boolean onButtonPressEvent(ButtonEvent event) {
	log("button press");  
	current_clip.x1 = current_clip.x2 = (int)event.getX();
	  current_clip.y1 = current_clip.y2 = (int)event.getY();
	  log("button press, x1="+current_clip.x1+", y1="+current_clip.y1);
	  current_clip.type
	    = event.getButton() == 1 ? ClipType.CLIP_RECTANGLE
	    : (event.getButton() == 2 ? ClipType.CLIP_SHAPES
	    : ClipType.CLIP_ELLIPSE);

	  
	  log("button press stage queue redraw");
	  Stage.getDefault().queueRedraw();
	  log("button press return false");
	  return false;
	}

	@Override
	public boolean onButtonReleaseEvent(ButtonEvent event) {
	  if (current_clip.type != ClipType.CLIP_NONE)
	    {
		  clips.add(current_clip);
		  current_clip = new Clip();
	    }

	  Stage.getDefault().queueRedraw();

	  return false;
	}

	
	@Override
	public boolean onMotionEvent(MotionEvent event) {
		log("on motion event");
	  if (current_clip.type != ClipType.CLIP_NONE)
	    {
	      current_clip.x2 = (int)event.getX();
	      current_clip.y2 = (int)event.getY();
	      log("stage -> queue redraw");
	      Stage.getDefault().queueRedraw();
	    }

	  return false;
	}
	
}
