package org.jclutter.tests.interactive;

import org.jclutter.ActorBox;
import org.jclutter.Color;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.Units;
import org.jclutter.cogl.COGL;
import org.jclutter.tests.TestGroup;

public class TextFieldTest extends TestGroup {

	private static final String FONT = "Mono Bold 14px";

	static Text createLabel(Color color, String text) {
		Text retval = new Text();

		retval.setWidth(200);

		retval.setFontName(FONT);
		retval.setColor(color);
		retval.setMarkup(text);
		retval.setEditable(true);
		retval.setSelectable(false);
		retval.setSingleLineMode(true);
		retval.setEllipsizeMode(Text.ELLIPSIZE_END);

		return retval;
	}

	static Text createEntry(Color color, String text, char password_char,
			int max_length) {
		Text retval = new Text(FONT, text, color) {
			
			public void onActivate() {
				System.out.printf(
						"Text activated: %s (cursor: %d, selection at: %d)\n", 
						getText(), getCursorPosition(), getSelectionBound());
			}

			
			public void onPaint() {
				ActorBox allocation = getAllocationBox();
				float width = allocation.x2 - allocation.x1;
				float height = allocation.y2 - allocation.y1;

				COGL.setSource(255, 255, 255, 255);
				COGL.pathRoundRectangle(0, 0, width, height, 4.0f, 1.0f);
				COGL.pathStroke();
			}
		};
		Color selection = color.copy().darker();

		retval.setWidth(200);
		retval.setReactive(true);

		retval.setEditable(true);
		retval.setSelectable(true);
		retval.setActivatable(true);
		retval.setSingleLineMode(true);
		retval.setPasswordChar(password_char);
		retval.setCursorColor(selection);
		retval.setMaxLength(max_length);

		return retval;
	}

	@Override
	public void init() {
		Color entry_color = new Color(0x33, 0xff, 0x33, 0xff);
		Color label_color = new Color(0xff, 0xff, 0xff, 0xff);
		Color background_color = new Color(0x00, 0x00, 0x00, 0xff);

		float width, height;

		Stage.getDefault().setColor(background_color);

		Units h_padding = Units.fromEmForFont(FONT, 2.0f); /* 2em */
		Units v_padding = Units.fromEmForFont(FONT, 3.0f); /* 3em */

		System.out.printf("padding: h:%.2f px, v:%.2f px\n", h_padding
				.toPixels(), v_padding.toPixels());

		Text text = createLabel(label_color, "<b>Input field:</b>    ");
		text.setPosition(10, 10);
		add(text);

		width = text.getWidth();
		height = text.getHeight();

		text = createEntry(entry_color, "<i>some</i> text", '0', 0);
		text.setPosition(width + 10 + h_padding.toPixels(), 10);
		add(text);

		text = createLabel(label_color, "<i>A very long password field</i>: ");
		text.setPosition(10, height + 10 + v_padding.toPixels());
		add(text);

		text = createEntry(entry_color, "password", '*', 8);
		text.setPosition(width + 10 + h_padding.toPixels(), height + 10
				+ v_padding.toPixels());
		add(text);

	}

}
