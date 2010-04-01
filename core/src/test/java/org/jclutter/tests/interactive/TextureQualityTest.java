package org.jclutter.tests.interactive;

import java.util.Timer;
import java.util.TimerTask;

import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Fog;
import org.jclutter.Stage;
import org.jclutter.Texture;
import org.jclutter.animation.Alpha;
import org.jclutter.animation.DepthBehaviour;
import org.jclutter.animation.Mode;
import org.jclutter.animation.Timeline;
import org.jclutter.events.ButtonEvent;
import org.jclutter.tests.TestGroup;

public class TextureQualityTest extends TestGroup {
	
	
	private String path = "src/test/resources/redhand.png";

	static boolean changeFilter (Texture actor)
	{
	  int old_quality = actor.getFilterQuality ();

	  switch (old_quality)
	    {
	      case Texture.QUALITY_LOW:
	        actor.setFilterQuality (
	           Texture.QUALITY_MEDIUM);
	        System.out.println("Setting texture rendering quality to medium");
	        break;
	      case Texture.QUALITY_MEDIUM:
	        actor.setFilterQuality (
	           Texture.QUALITY_HIGH);
	        System.out.println ("Setting texture rendering quality to high");
	        break;
	      case Texture.QUALITY_HIGH:
	        actor.setFilterQuality (
	           Texture.QUALITY_LOW);
	        System.out.println ("Setting texture rendering quality to low");
	        break;
	    }
	  return true;
	}

	@Override
	public void init() {
	  Color      stage_color = new Color( 0x12, 0x34, 0x56, 0xff );
	  Fog        stage_fog = new Fog( 10.0f, -50.0f );

	  Stage.getDefault().setColor (stage_color);
	  Stage.getDefault().setUseFog (true);
	  Stage.getDefault().setFog (stage_fog);

	  final Texture image  = new Texture (path);

	  /* center the image */
	  image.setPosition ( 
	    (getWidth () - image.getWidth ())/2,
	    (getHeight () - image.getHeight ())/2);
	  add(image);

	  Timeline timeline = new Timeline (5000, 0){
		  
		public void onCompleted() {
			  swapDirection();
			  start ();
		}
	  };

	  Alpha alpha = new Alpha (timeline, Mode.LINEAR);
	  DepthBehaviour depthBehavior = new DepthBehaviour (alpha, -2500, 400);
	  depthBehavior.apply (image);

	  timeline.start ();

	  new Timer().scheduleAtFixedRate(new TimerTask(){
		  @Override
		public void run() {
			changeFilter(image);
		}
	  }, 0, 10000);

	}
	

	public boolean onButtonPressEvent(Stage s, ButtonEvent event) {
		Clutter.mainQuit();
		return true;
	}
	
}
