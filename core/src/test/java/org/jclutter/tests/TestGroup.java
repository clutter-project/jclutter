package org.jclutter.tests;

import org.jclutter.Clutter;
import org.jclutter.Group;
import org.jclutter.Stage;
import org.jclutter.glib.Glib;

public abstract class TestGroup extends Group {
	
	public TestGroup() {
	}
	
	private String param;
	
	public void setParam(String param) {
		this.param = param;
	}
	
	public String getParam() {
		return param;
	}
	
	// To call after it s added to container
	public abstract void init();
	
	public synchronized void log(Object txt){
		System.out.println(getClass().getSimpleName()+":"+txt);
	}
	
	public static void main(String[] args) {
		try {
			String p = (args.length>1)?args[1]:null;
			showInDefaultStage(args[0], p);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public static void showInDefaultStage(String scene, String param) throws Exception {
		Glib.copyEnvFromSystem();
		Clutter.init();
		TestGroup a = (TestGroup) Class.forName(scene).newInstance();
		Stage stage = Stage.getDefault();
		stage.setTitle("Scene::" + scene);
		stage.add(a);
		a.setParam(param);
		a.init();
		
		stage.showAll();
		stage.setReactive(true);
		Clutter.mainStart();
	}

}
