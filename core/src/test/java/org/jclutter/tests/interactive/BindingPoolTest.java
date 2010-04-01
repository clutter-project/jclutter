package org.jclutter.tests.interactive;

import org.jclutter.Clutter;
import org.jclutter.Color;
import org.jclutter.Container;
import org.jclutter.KeyAction;
import org.jclutter.Keys;
import org.jclutter.Rectangle;
import org.jclutter.events.ButtonEvent;
import org.jclutter.events.KeyEvent;
import org.jclutter.tests.TestGroup;

public class BindingPoolTest extends TestGroup {

	private int selectedIndex;
	
	private Rectangle [] rectangles = {
			new Rectangle(Color.RED),
			new Rectangle(Color.GREEN),
			new Rectangle(Color.BLUE)
	};
	
	@Override
	public void init() {
		rectangles[0].setSize(50, 50);
		rectangles[1].setSize(50, 50);
		rectangles[1].setPosition(75, 0);
		rectangles[2].setSize(50, 50);
		rectangles[2].setPosition(150, 0);
		add(rectangles);
	}
	
	
	private void updateUI(){
		for (int i = 0; i < rectangles.length; i++) {
			Color c = (selectedIndex == i)?Color.BLACK:Color.WHITE;
			int w = (selectedIndex == i)?5:1;
			rectangles[i].setBorderColor(c);
			rectangles[i].setBorderWidth(w);
		}
	}
	
	@Override
	public boolean onKeyPressEvent(KeyEvent event) {
		return true;
	}
	
	@Override
	public boolean onButtonPressEvent(ButtonEvent event) {
		Clutter.mainQuit();
		return true;
	}
	
	@KeyAction(key=Keys.Left)
	public void moveLeft(){
		selectedIndex+=2;
		selectedIndex=selectedIndex%3;
		updateUI();
	}
	
	@KeyAction(key=Keys.Right)
	public void moveRight(){
		selectedIndex++;
		selectedIndex=selectedIndex%3;
		updateUI();
	}

}
