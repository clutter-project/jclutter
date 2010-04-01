package org.jclutter;

/**
 * General exception.
 * 
 *
 */
public class ClutterException extends RuntimeException {

	/**
	 * 
	 */
	private static final long serialVersionUID = 5843798475659240030L;

	public ClutterException() {
		super();
	}

	public ClutterException(String message, Throwable cause) {
		super(message, cause);
	}

	public ClutterException(String message) {
		super(message);
	}

	public ClutterException(Throwable cause) {
		super(cause);
	}
	
	

}
