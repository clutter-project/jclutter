package org.jclutter.events;

import org.jclutter.Texture;

public class TextureAdapter extends ActorAdapter<Texture> {

	public void onLoadFinished(Texture texture, boolean success,
			String messageIfAny) {
		texture.onLoadFinished(success, messageIfAny);
	}

	public void onPixbufChange(Texture texture) {
		texture.onPixbufChange();
	}

	public void onSizeChange(Texture texture, int width, int height) {
		texture.onSizeChange(width, height);
	} 
}
