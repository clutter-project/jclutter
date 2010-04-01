package org.jclutter.cogl;

import java.util.List;

public class Material extends CoglTexture {

	public enum AlphaFunc {
		NEVER, LESS, EQUAL, LEQUAL, GREATER, NOTEQUAL, GEQUAL, ALWAYS
	}

	public enum Filter {
		NEAREST, LINEAR, NEAREST_MIPMAP_NEAREST, LINEAR_MIPMAP_NEAREST, NEAREST_MIPMAP_LINEAR, LINEAR_MIPMAP_LINEAR;
		int value;
		// TODO remove
		private Filter() {
		}
		private Filter(int v) {
			value = v;
		}
		int value(){
			return value;
		}
	}

	public Material() {
		super(newInstance());
	}
	
	protected Material(int i){
		super(i);
	}

	private static final native int newInstance();

	public native void setColor(Color color);

	//public native void setColor(int red, int green, int blue, int alpha);

	// public native void setColor(float red, float green, float blue,
	// float alpha);
	
	public native Color getColor();

	public native void setAmbient(Color ambient);

	public native Color getAmbient();

	public native void setDiffuse(Color diffuse);

	public native Color getDiffuse();

	public native void setAmbientAndDiffuse(Color color);

	public native void setEmission(Color emission);

	public native Color getEmission();

	public native void setSpecular(Color specular);

	public native Color getSpecular();

	public native void setShininess(float shininess);

	public native float getShininess();

	public void setAlphaTestFunction(AlphaFunc alphaFunc, float alpha_reference){
		setAlphaTestFunction(alphaFunc.ordinal(), alpha_reference);
	}
	
	private native void setAlphaTestFunction(int alphaFunc, float alpha_reference);

	public native boolean setBlend(String blendString);

	public native void setBlendConstant(Color constantColor);

	public native void setLayer(int layer_index, CoglTexture texture);

	public native void removeLayer(int layer_index);

	public native boolean setLayerCombine(int layer_index, String blendString);

	public native void setLayerCombineConstant(int layer_index, Color constant);

	public native void setLayerMatrix(int layer_index, Matrix matrix);

	public native List getLayers();

	public void setLayerFilters(int layer_index, Filter minFilter, Filter magFilter){
		setLayerFilters(layer_index, minFilter.ordinal(), magFilter.ordinal());
	}
	
	private native void setLayerFilters(int layer_index, int minFilter, int magFilter);
	
	// public static native Filter getMinFilter(Texture layer);
	// public static native Filter getMagFilter (Texture layer);
	// TODO ?
	// CoglMaterialLayerType layer_getType (CoglHandle layer);
	// CoglHandle layer_getTexture (CoglHandle layer);

}
