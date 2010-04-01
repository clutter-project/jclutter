package org.jclutter.tests.interactive;

import java.util.Random;

import org.jclutter.ActorBox;
import org.jclutter.Box;
import org.jclutter.Color;
import org.jclutter.FlowLayout;
import org.jclutter.Rectangle;
import org.jclutter.Stage;
import org.jclutter.events.StageAdapter;
import org.jclutter.tests.TestGroup;

public class FlowLayoutTest extends TestGroup {

	boolean homogeneous = false;
	boolean vertical = false;
	boolean random_size = false;

	int n_rects = 20;
	int x_spacing = 0;
	int y_spacing = 0;

	Box box = null;

	Random random = new Random();

	@Override
	public void init() {
		Stage s = Stage.getDefault();
		s.setColor(new Color(0xe0, 0xf2, 0xfc, 0xff));
		s.setUserResizable(true);
		s.setListener(new StageAdapter() {
			
			public boolean onAllocationChanged(Stage stage, ActorBox alloc,
					int flags) {
				if (vertical) {
					box.setHeight(alloc.getHeight());
				} else {
					box.setWidth(alloc.getWidth());
				}
				return true;
			}
		});

		FlowLayout layout = new FlowLayout(vertical ? FlowLayout.VERTICAL
				: FlowLayout.HORIZONTAL);
		layout.setHomogeneous(homogeneous);
		layout.setColumnSpacing(x_spacing);
		layout.setRowSpacing(y_spacing);
		box = new Box(layout);
		box.setColor(Color.WHITE);
		add(box);

		if (vertical)
			box.setHeight(getHeight());
		else
			box.setWidth(getWidth());

		box.setName("box");

		Color c = new Color();
		for (int i = 0; i < n_rects; i++) {
			c.setHls((float) (360.0 / n_rects * i), .5f, .8f);
			Rectangle r = new Rectangle(c);
			box.add(r);

			if (random_size) {
				r.setSize(random.nextInt(50) + 50, random.nextInt(50) + 50);
			} else
				r.setSize(50, 50);

			r.setName("rect" + i);
		}
	}

	@Override
	public boolean onAllocationChanged(ActorBox alloc,
			int flags) {
		if (vertical) {
			box.setHeight(alloc.getHeight());
		} else {
			box.setWidth(alloc.getWidth());
		}
		return true;
	}

}
