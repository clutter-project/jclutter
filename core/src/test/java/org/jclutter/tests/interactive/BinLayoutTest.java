package org.jclutter.tests.interactive;

import java.util.Random;

import org.jclutter.Actor;
import org.jclutter.BinLayout;
import org.jclutter.Box;
import org.jclutter.Color;
import org.jclutter.Gravity;
import org.jclutter.Rectangle;
import org.jclutter.Stage;
import org.jclutter.Texture;
import org.jclutter.BinLayout.Alignment;
import org.jclutter.animation.Mode;
import org.jclutter.cairo.CairoContext;
import org.jclutter.cairo.CairoPattern;
import org.jclutter.cairo.CairoTexture;
import org.jclutter.events.CrossingEvent;
import org.jclutter.tests.TestGroup;

public class BinLayoutTest extends TestGroup {

	static final int BG_ROUND_RADIUS = 12;
	
	Random r = new Random();
	Rectangle emblem = new Rectangle(new Color(r.nextInt(255), r.nextInt(255), r.nextInt(255), 224));

	@Override
	public void init() {
		Color stage_color = new Color( 0xe0, 0xf2, 0xfc, 0xff );
		Color bg_color = new Color( 0xcc, 0xcc, 0xcc, 0x99 );
		Stage.getDefault().setColor(stage_color);
		
		BinLayout bin = new BinLayout(BinLayout.CENTER, BinLayout.CENTER);
		Box box = new Box(bin){
			@Override
			public boolean onEnterEvent(CrossingEvent event) {
				emblem.animate(Mode.LINEAR, 150, "opacity", 255);
				return true;
			}
			
			@Override
			public boolean onLeaveEvent(CrossingEvent event) {
				emblem.animate(Mode.LINEAR, 150, "opacity", 0);
				return true;
			}
		};
		
		add(box);
		
		box.setAnchorPointFromGravity(Gravity.CENTER);
		box.setPosition(320, 240);
		box.setReactive(true);
		box.setName("box");
		
		Actor bg = makeBackground(bg_color, 200, 200);
		box.add(bg, new Alignment(BinLayout.FILL, BinLayout.FILL));
		bg.lowerBottom();
		bg.setName("background");
		
		Texture tex = new Texture("src/test/resources/redhand.png");
		tex.setKeepAspectRatio(true);
		bin.add(tex, BinLayout.CENTER, BinLayout.CENTER);
		tex.raise(bg);
		tex.setWidth(175);
		tex.setName("texture");
		
		box.add(emblem);
		emblem.setSize(50, 50);
		emblem.setOpacity(0);
		emblem.setName("emblem");
		emblem.raiseTop();	
	}

	static Actor makeBackground(Color color, float width, float height) {
		CairoTexture t = new CairoTexture(width, height);
		CairoContext ctx = t.createContext();
		int x = 0, y = 0;

		ctx.moveTo(BG_ROUND_RADIUS, y);
		ctx.lineTo(width - BG_ROUND_RADIUS, y);
		ctx.moveTo(BG_ROUND_RADIUS, y);
		ctx.lineTo(width - BG_ROUND_RADIUS, y);
		ctx.curveTo(width, y, width, y, width, BG_ROUND_RADIUS);
		ctx.lineTo(width, height - BG_ROUND_RADIUS);
		ctx.curveTo(width, height, width, height, width - BG_ROUND_RADIUS,
				height);
		ctx.lineTo(BG_ROUND_RADIUS, height);
		ctx.curveTo(x, height, x, height, x, height - BG_ROUND_RADIUS);
		ctx.lineTo(x, BG_ROUND_RADIUS);
		ctx.curveTo(x, y, x, y, BG_ROUND_RADIUS, y);

		ctx.closePath();

		ctx.setSource(color);
		ctx.stroke();

		x += 4;
		y += 4;
		width -= 4;
		height -= 4;

		ctx.moveTo(BG_ROUND_RADIUS, y);
		ctx.lineTo(width - BG_ROUND_RADIUS, y);
		ctx.curveTo(width, y, width, y, width, BG_ROUND_RADIUS);
		ctx.lineTo(width, height - BG_ROUND_RADIUS);
		ctx.curveTo(width, height, width, height, width - BG_ROUND_RADIUS,
				height);
		ctx.lineTo(BG_ROUND_RADIUS, height);
		ctx.curveTo(x, height, x, height, x, height - BG_ROUND_RADIUS);
		ctx.lineTo(x, BG_ROUND_RADIUS);
		ctx.curveTo(x, y, x, y, BG_ROUND_RADIUS, y);

		ctx.closePath();

		CairoPattern pat = new CairoPattern(0, 0, 0, height);
		pat.addColorStopWithAlpha(1, .85, .85, .85, 1);
		pat.addColorStopWithAlpha(.95, 1, 1, 1, 1);
		pat.addColorStopWithAlpha(.05, 1, 1, 1, 1);
		pat.addColorStopWithAlpha(0, .85, .85, .85, 1);

		ctx.setSource(pat);
		ctx.fill();

		pat.destroy();
		ctx.destroy();

		return t;
	}

}
