package org.jclutter.glib;


/**
 * This object is returned by GObject.connect().
 * It is used to block/unblock/disconnect a signal from its callback passed with connect().
 * 
 *
 */
public class SignalHandler {
	
	private long id;
	
	private GObject source;
	
	private String signal;
	
	private int when;
	
	private boolean blocked;
	
	protected SignalHandler(long id, GObject source, String signal, int when) {
		super();
		this.id = id;
		this.source = source;
		this.signal = signal;
		this.when = when;
	}

	public void disconnect(){
		source.disconnect(id);
	}
	
	public void setBlocked(boolean b) {
		if (b == blocked) return;
		if (b) block(); else unblock();
		this.blocked = b;
	}
	
	public boolean isBlocked() {
		return blocked;
	}
	
	private void block(){
		source.block(id);
	}
	
	private void unblock(){
		source.unblock(id);
	}
	
	public boolean isConnected(){
		return source.isConnected(id);
	}
	
	public String getSignal() {
		return signal;
	}
	
	public int getWhen() {
		return when;
	}
	
	public GObject getSource() {
		return source;
	}	

}
