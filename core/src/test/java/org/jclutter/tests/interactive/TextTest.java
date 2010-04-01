package org.jclutter.tests.interactive;

import org.jclutter.Color;
import org.jclutter.Geometry;
import org.jclutter.Stage;
import org.jclutter.Text;
import org.jclutter.tests.TestGroup;

public class TextTest extends TestGroup {

	static final String FONT = "Mono Bold 22px";
	private String runes = "áš á›‡áš»á›«á›’á›¦áš¦á›«áš áš±áš©áš áš¢áš±á›«áš á›�áš±ášªá›«áš·á›–áš»áš¹á›¦á›šáš³áš¢á›—\n"
		+"á›‹áš³á›–ášªá›šá›«áš¦á›–ášªáš»á›«á›—ášªáš¾áš¾ášªá›«áš·á›–áš»áš¹á›¦á›šáš³á›«á›—á›�áš³á›šáš¢áš¾á›«áš»á›¦á›�á›«á›žáš«á›šášªáš¾\n"
		+"áš·á›�áš á›«áš»á›–á›«áš¹á›�á›šá›–á›«áš áš©áš±á›«á›žáš±á›�áš»á›�áš¾á›–á›«á›žáš©á›—á›–á›‹á›«áš»á›šá›‡á›�ášªáš¾á›¬\n";


	@Override
	public void init() {
		Color text_color = new Color(0x33, 0xff, 0x33, 0xff);
		Color cursor_color = new Color(0xff, 0x33, 0x33, 0xff);
		Stage.getDefault().setColor(Color.BLACK);

		Text text = new Text(FONT, ".", text_color) {
			@Override
			public void onCursorEvent(Geometry geom) {
				log("on cursor event");
				if (getY() + geom.y < 50) {
					setY(getY() + 100);
				} else if (getY() + geom.y > 720) {
					setY(getY() - 100);
				}
			}
		};

		add(text);
		text.setPosition(40, 30);
		text.setWidth(getWidth());
		text.setLineWrap(true);
		text.setEditable(true);
		text.setSelectable(true);
		text.setCursorColor(cursor_color);

		text.setText(runes);
	}

}
