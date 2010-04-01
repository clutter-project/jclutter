package org.jclutter.tests.microbench;

import org.jclutter.Clutter;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.events.StageAdapter;
import org.jclutter.glib.Glib;

public class TextPerfTest {

	private static final int STAGE_WIDTH = 800;
	private static final int STAGE_HEIGHT = 600;
	
	public static void main(String[] args) {
		Glib.setEnv("CLUTTER_VBLANK", "none", false);
		Glib.setEnv("CLUTTER_DEFAULT_FPS", "1000", false);
		Clutter.init();
		int fontSize = Integer.parseInt(args[0]);
		int nChars = Integer.parseInt(args[1]);
		
		System.out.println("Monospace "+fontSize+"px, string length = "+nChars);
		
		Stage stage = Stage.getDefault();
		stage.setListener(new StageAdapter(){
			
			public void onPaint(Stage s) {
				
			}
		});
		stage.setSize(STAGE_WIDTH, STAGE_HEIGHT);
		stage.setColor(0x000000);
		
		Text label = new Text();
		int w = (int)label.getWidth();
		int h = (int)label.getHeight();
		int cols = STAGE_WIDTH / w;
		int rows = STAGE_HEIGHT / h;
		label.destroy();
		label = null;
		
		if (cols == 0 || rows == 0){
			System.err.println("Too many characters to fit in stage");
			System.exit(1);
		}
		
		for (int row = 0; row < rows; row++) {
			for (int col = 0; col < cols; col++) {
				Text l = new Text();
				l.setPosition(w * col, h * row);
				stage.add(l);
			}
		}
		
		stage.showAll();
		
		// TODO queue redraw
		
		Clutter.mainStart();
	}
	
}
