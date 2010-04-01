package org.jclutter.tests.interactive;

import java.util.Random;

import org.jclutter.Task;
import org.jclutter.Clutter;
import org.jclutter.Group;
import org.jclutter.Text;
import org.jclutter.Threads;
import org.jclutter.tests.TestGroup;

public class RandomTextTest extends TestGroup {

	static final int MAX_TEXT_LEN = 10;
	static final int MIN_FONT_SIZE = 10;
	static final int MAX_FONT_SIZE = 30;

	static final Random r = new Random();

	static String[] font_names = { "Sans", "Sans Italic", "Serif",
			"Serif Bold", "Times", "Monospace" };

	static String string = "qwertyuiopåasdfghjklöäzxcvbnmQWERTYUIOPÅASDFGHJKLÖÄZXCVBNM1234567890";
	
	char nextChar(){
		return string.charAt(r.nextInt(string.length()));
	}

	boolean on_idle() {
		int line_height = 0, xpos = 0, ypos = 0;
		char[] text = new char[MAX_TEXT_LEN + 1];
		/* Remove all of the children */
		((Group)getParent()).removeAll();

		/* Fill the stage with new random labels */
		while (ypos < getHeight()) {
			int text_len = r.nextInt(MAX_TEXT_LEN + 1);

			for (int i = 0; i < text_len; i++)
				text[i] = nextChar();

			String font_name = font_names[r.nextInt(font_names.length)]
					+ " "
					+ (r.nextInt(MAX_FONT_SIZE - MIN_FONT_SIZE) + MIN_FONT_SIZE);

			String s = new String(text);
			log("adding label: "+s);
			Text label = new Text(font_name, s);

			if (label.getHeight() > line_height)
				line_height = (int) label.getHeight();

			if (xpos + label.getWidth() > getWidth()) {
				xpos = 0;
				ypos += line_height;
				line_height = 0;
			}

			label.setPosition(xpos, ypos);

			add(label);

			xpos += label.getWidth();
		}

		return true;
	}
	
	@Override
	public void init() {
		Threads.addIdleTask(new Task() {
			public boolean execute() {
				return on_idle();
			}

			public void destroy() {
			}
		}, 0);
	}

}
