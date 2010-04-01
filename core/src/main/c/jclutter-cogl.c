#include "jclutter-cogl.h"
#include "jclutter-common.h"
#include <cogl/cogl.h>

JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_clear(JNIEnv *env, jclass cl, jobject color, jlong buffers) {
	cogl_clear(coglColorFromJava(env, color), buffers);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_flush(JNIEnv *env, jclass cl) {
	cogl_flush();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_rotate(JNIEnv *env, jclass cl, jfloat angle, jfloat x, jfloat y, jfloat z) {
	cogl_rotate(angle, x, y, z);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_scale(JNIEnv *env, jclass cl, jfloat x, jfloat y, jfloat z) {
	cogl_scale(x, y, z);
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_COGL_getFeatures(JNIEnv *env,
		jclass cl) {
	return (jint) cogl_get_features();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cogl_COGL_featuresAvailable(
		JNIEnv *env, jclass cl, jint f) {
	return (jboolean) cogl_features_available(f);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pushMatrix(JNIEnv *env, jclass cl) {
	cogl_push_matrix();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_popMatrix(JNIEnv *env, jclass cl) {
	cogl_pop_matrix();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_translate(JNIEnv *env, jclass cl, jfloat x, jfloat y, jfloat z) {
	cogl_translate(x, y, z);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_frustum(JNIEnv *env, jclass cl, jfloat l, jfloat r, jfloat b, jfloat t, jfloat n, jfloat f) {
	cogl_frustum(l, r, b, t, n, f);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_perspective(JNIEnv *env, jclass cl, jfloat fovy, jfloat aspect, jfloat n, jfloat f) {
	cogl_perspective(fovy, aspect, n, f);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_ortho(JNIEnv *env, jclass cl, jfloat l, jfloat r, jfloat b, jfloat t, jfloat n, jfloat f) {
	cogl_ortho(l, r, b, t, n, f);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cogl_COGL_getViewPort(JNIEnv *env,
		jclass cl) {
	float v[4];
	cogl_get_viewport(v);
	return NULL;//TODO
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_setDepthTestEnabled(JNIEnv *env, jclass cl, jboolean b) {
	cogl_set_depth_test_enabled(b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cogl_COGL_isDepthTestEnabled(
		JNIEnv *env, jclass cl) {
	return (jboolean) cogl_get_depth_test_enabled();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_setBackfaceCullingEnabled(JNIEnv *env, jclass cl, jboolean b) {
	cogl_set_backface_culling_enabled(b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cogl_COGL_isBackfaceCullingEnabled(
		JNIEnv *env, jclass cl) {
	return (jboolean) cogl_get_backface_culling_enabled();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_disableFog(JNIEnv *env, jclass cl) {
	cogl_disable_fog();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_setSource(JNIEnv *env, jclass cl, jint r, jint g, jint b, jint a) {
	cogl_set_source_color4ub(r,g,b,a);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_setSourceTexture(JNIEnv *env, jclass cl, jobject obj) {
	cogl_set_source_texture(coglTextureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_beginGL(JNIEnv *env, jclass cl) {
	cogl_begin_gl();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_endGL(JNIEnv *env, jclass cl) {
	cogl_end_gl();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_rectangle(JNIEnv *env, jclass cl, jfloat x1, jfloat y1, jfloat x2, jfloat y2) {
	cogl_rectangle(x1, y1, x2, y2);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_rectangles(JNIEnv *env, jclass cl, jfloatArray rects) {
	jsize size = (*env)->GetArrayLength(env, rects);
	guint nrects = size / 4;
	const float *verts = (*env)->GetFloatArrayElements(env, rects, 0);
	cogl_rectangles(verts, nrects);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_rectangleWithTextureCoords(JNIEnv *env, jclass cl, jfloat i, jfloat j, jfloat k, jfloat l, jfloat m, jfloat n, jfloat o, jfloat p) {
	cogl_rectangle_with_texture_coords(i, j, k, l, m, n, o, p);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_rectanglesWithTextureCoords(JNIEnv *env, jclass cl, jfloatArray param0) {
	// TODO
	//cogl_rectangles_with_texture_coords();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_rectangleWithMultitextureCoords(JNIEnv *env, jclass cl, jfloat i, jfloat j, jfloat k, jfloat l, jfloatArray tex) {
	// TODO
	//cogl_rectangle_with_multitexture_coords();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_polygon(JNIEnv *env, jclass cl, jobjectArray vertices, jboolean usecolor) {
	// TODO
	cogl_polygon(NULL, 0, usecolor);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathNew(JNIEnv *env, jclass cl) {
	cogl_path_new();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathMoveTo(JNIEnv *env, jclass cl, jfloat x, jfloat y) {
	cogl_path_move_to(x, y);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathClose(JNIEnv *env, jclass cl) {
	cogl_path_close();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathLineTo(JNIEnv *env, jclass cl, jfloat x, jfloat y) {
	cogl_path_line_to(x, y);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathCurveTo(JNIEnv *env, jclass cl, jfloat x1, jfloat y1, jfloat x2, jfloat y2, jfloat x3, jfloat y3) {
	cogl_path_curve_to(x1,y1,x2,y2,x3,y3);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathArc(JNIEnv *env, jclass cl, jfloat i, jfloat j, jfloat k, jfloat l, jfloat m, jfloat n) {
	cogl_path_arc(i, j, k, l, m, n);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathRelMoveTo(JNIEnv *env, jclass cl, jfloat i, jfloat j) {
	cogl_path_rel_move_to(i, j);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathRelLineTo(JNIEnv *env, jclass cl, jfloat i, jfloat j) {
	cogl_path_rel_line_to(i, j);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathRelCurveTo(JNIEnv *env, jclass cl, jfloat i, jfloat j, jfloat k, jfloat l, jfloat m, jfloat n) {
	cogl_path_rel_curve_to(i, j, k, l, m, n);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathLine(JNIEnv *env, jclass cl, jfloat i, jfloat j, jfloat k, jfloat l) {
	cogl_path_line(i, j, k, l);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_path_polyline(JNIEnv *env, jclass cl, jfloatArray coords) {
	jsize size = (*env)->GetArrayLength(env, coords);
	guint n = size / 2;
	float *c = (*env)->GetFloatArrayElements(env, coords, 0);
	cogl_path_polyline(c, n);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_path_polygon(JNIEnv *env, jclass cl, jfloatArray coords) {
	jsize size = (*env)->GetArrayLength(env, coords);
	guint n = size / 2;
	float *c = (*env)->GetFloatArrayElements(env, coords, 0);
	cogl_path_polygon(c, n);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathRectangle(JNIEnv *env, jclass cl, jfloat i, jfloat j, jfloat k, jfloat l) {
	cogl_path_rectangle(i, j, k, l);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathRoundRectangle(JNIEnv *env, jclass cl, jfloat i, jfloat j, jfloat k, jfloat l, jfloat m, jfloat n) {
	cogl_path_round_rectangle(i, j, k, l, m, n);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathEllipse(JNIEnv *env, jclass cl, jfloat i, jfloat j, jfloat k, jfloat l) {
	cogl_path_ellipse(i, j, k, l);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathFill(JNIEnv *env, jclass cl) {
	cogl_path_fill();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathFillPreserve(JNIEnv *env, jclass cl) {
	cogl_path_fill_preserve();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathStroke(JNIEnv *env, jclass cl) {
	cogl_path_stroke();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_pathStrokePreserve(JNIEnv *env, jclass cl) {
	cogl_path_stroke_preserve();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_clipPushRectangle(JNIEnv *env, jclass cl, jfloat i, jfloat j, jfloat k, jfloat l) {
	cogl_clip_push_rectangle(i, j, k, l);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_clipPushWindowRectangle(JNIEnv *env, jclass cl, jint i, jint j, jint k, jint l) {
	cogl_clip_push_window_rectangle(i, j, k, l);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_clipPushFromPath(JNIEnv *env, jclass cl) {
	cogl_clip_push_from_path();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_clipPushFromPathPreserve(JNIEnv *env, jclass cl) {
	cogl_clip_push_from_path_preserve();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_clipPop(JNIEnv *env, jclass cl) {
	cogl_clip_pop();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_setFramebuffer(JNIEnv *env, jclass cl, jobject obj) {
	cogl_set_framebuffer(coglTextureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_COGL_popFramebuffer(JNIEnv *env, jclass cl) {
	cogl_pop_framebuffer();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_Color_newInstance(JNIEnv *env,
		jclass cl) {
	return (jint) cogl_color_new();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_Color_getRed(JNIEnv *env,
		jobject obj) {
	return (jint) cogl_color_get_red(coglColorFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_Color_getGreen(JNIEnv *env,
		jobject obj) {
	return (jint) cogl_color_get_green(coglColorFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_Color_getBlue(JNIEnv *env,
		jobject obj) {
	return (jint) cogl_color_get_blue(coglColorFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_Color_getAlpha(JNIEnv *env,
		jobject obj) {
	return (jint) cogl_color_get_alpha(coglColorFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_Color_copyNative(JNIEnv *env,
		jobject obj) {
	return (jint) cogl_color_copy(coglColorFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Color_free(JNIEnv *env, jobject obj) {
	cogl_color_free(coglColorFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Color_setFrom(JNIEnv *env, jobject obj, jint i, jint j, jint k, jint l) {
	cogl_color_set_from_4ub(coglColorFromJava(env, obj), i, j, k, l);
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_Material_newInstance(JNIEnv *env,
		jclass cl) {
	return (jint) cogl_material_new();
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_CoglTexture_ref(JNIEnv *env, jobject obj){
	cogl_handle_ref(coglTextureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_CoglTexture_unref(JNIEnv *env, jobject obj){
	cogl_handle_unref(coglTextureFromJava(env, obj));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cogl_CoglTexture_isMaterial(
		JNIEnv *env, jobject obj) {
	return (jboolean) cogl_is_material(coglTextureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setColor(JNIEnv *env, jobject obj, jobject color) {
	cogl_material_set_color(coglTextureFromJava(env, obj), coglColorFromJava(env, color));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cogl_Material_getColor(JNIEnv *env,
		jobject obj) {
	CoglColor *color;
	cogl_material_get_color(coglTextureFromJava(env, obj), color);
	return toJavaCoglColor(env, color);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setAmbient(JNIEnv *env, jobject obj, jobject color) {
	cogl_material_set_ambient(coglTextureFromJava(env, obj), coglColorFromJava(env, color));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cogl_Material_getAmbient(
		JNIEnv *env, jobject obj) {
	CoglColor *color;
	cogl_material_get_ambient(coglTextureFromJava(env, obj), color);
	return toJavaCoglColor(env, color);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setDiffuse(JNIEnv *env, jobject obj, jobject color) {
	cogl_material_set_diffuse(coglTextureFromJava(env, obj), coglColorFromJava(env, color));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cogl_Material_getDiffuse(
		JNIEnv *env, jobject obj) {
	CoglColor *color;
	cogl_material_get_diffuse(coglTextureFromJava(env, obj), color);
	return toJavaCoglColor(env, color);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setAmbientAndDiffuse(JNIEnv *env, jobject obj, jobject color) {
	cogl_material_set_ambient_and_diffuse(coglTextureFromJava(env, obj), coglColorFromJava(env, color));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setEmission(JNIEnv *env, jobject obj, jobject color) {
	cogl_material_set_emission(coglTextureFromJava(env, obj), coglColorFromJava(env, color));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cogl_Material_getEmission(
		JNIEnv *env, jobject obj) {
	CoglColor *color;
	cogl_material_get_emission(coglTextureFromJava(env, obj), color);
	return toJavaCoglColor(env, color);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setSpecular(JNIEnv *env, jobject obj, jobject color) {
	cogl_material_set_specular(coglTextureFromJava(env, obj), coglColorFromJava(env, color));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cogl_Material_getSpecular(
		JNIEnv *env, jobject obj) {
	CoglColor *color;
	cogl_material_get_specular(coglTextureFromJava(env, obj), color);
	return toJavaCoglColor(env, color);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setShininess(JNIEnv *env, jobject obj, jfloat s) {
	cogl_material_set_shininess(coglTextureFromJava(env, obj), s);
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_cogl_Material_getShininess(
		JNIEnv *env, jobject obj) {
	return (jfloat) cogl_material_get_shininess(coglTextureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setAlphaTestFunction(JNIEnv *env, jobject obj, jint func, jfloat alpharef) {
	cogl_material_set_alpha_test_function(coglTextureFromJava(env, obj), func, alpharef);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cogl_Material_setBlend(
		JNIEnv *env, jobject obj, jstring string) {
	const char *str = (*env)->GetStringUTFChars(env, string, 0);
	return (jboolean) cogl_material_set_blend(coglTextureFromJava(env, obj),
			str, NULL);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setBlendConstant(JNIEnv *env, jobject obj, jobject color) {
	cogl_material_set_blend_constant(coglTextureFromJava(env, obj), coglColorFromJava(env, color));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setLayer(JNIEnv *env, jobject obj, jint index, jobject texture) {
	cogl_material_set_layer(coglTextureFromJava(env, obj), index, coglTextureFromJava(env, texture));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_removeLayer(JNIEnv *env, jobject obj, jint l) {
	cogl_material_remove_layer(coglTextureFromJava(env, obj), l);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cogl_Material_setLayerCombine(
		JNIEnv *env, jobject obj, jint l, jstring string) {
	const char *str = (*env)->GetStringUTFChars(env, string, 0);
	return (jboolean) cogl_material_set_layer_combine(coglTextureFromJava(env,
			obj), l, str, NULL);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setLayerCombineConstant(JNIEnv *env, jobject obj, jint index, jobject color) {
	cogl_material_set_layer_combine_constant(coglTextureFromJava(env, obj), index, coglColorFromJava(env, color));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setLayerMatrix(JNIEnv *env, jobject obj, jint index, jobject matrix) {
	cogl_material_set_layer_matrix(coglTextureFromJava(env, obj), index, coglMatrixFromJava(env, matrix));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cogl_Material_getLayers(
		JNIEnv *env, jobject obj) {
	// TODO
	return (jobject) cogl_material_get_layers(coglTextureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Material_setLayerFilters(JNIEnv *env, jobject obj, jint index, jint minfilter, jint magfilter) {
	cogl_material_set_layer_filters(coglTextureFromJava(env, obj), index, minfilter, magfilter);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cogl_Matrix_getArray(JNIEnv *env,
		jobject obj) {
	return (jobject) cogl_matrix_get_array(coglMatrixFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Matrix_rotate(JNIEnv *env, jobject obj, jfloat i, jfloat j, jfloat k, jfloat l) {
	cogl_matrix_rotate(coglMatrixFromJava(env, obj), i,j,k,l);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Matrix_scale(JNIEnv *env, jobject obj, jfloat i, jfloat j, jfloat k) {
	cogl_matrix_scale(coglMatrixFromJava(env, obj), i,j,k);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Matrix_translate(JNIEnv *env, jobject obj, jfloat i, jfloat j, jfloat k) {
	cogl_matrix_translate(coglMatrixFromJava(env, obj), i,j,k);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Matrix_frustum(JNIEnv *env, jobject obj, jfloat i, jfloat j, jfloat k, jfloat l, jfloat m, jfloat n) {
	cogl_matrix_frustum(coglMatrixFromJava(env, obj), i,j,k,l,m,n);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Matrix_perspective(JNIEnv *env, jobject obj, jfloat i, jfloat j, jfloat k, jfloat l) {
	cogl_matrix_perspective(coglMatrixFromJava(env, obj), i,j,k,l);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Matrix_ortho(JNIEnv *env, jobject obj, jfloat i, jfloat j, jfloat k, jfloat l, jfloat m, jfloat n) {
	cogl_matrix_ortho(coglMatrixFromJava(env, obj), i,j,k,l,m,n);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Matrix_initIdentity(JNIEnv *env, jobject obj) {
	cogl_matrix_init_identity(coglMatrixFromJava(env, obj));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cogl_Matrix_multiply(JNIEnv *env,
		jobject obj, jobject obj2) {
	CoglMatrix *m;
	cogl_matrix_multiply(m, coglMatrixFromJava(env, obj), coglMatrixFromJava(
			env, obj));
	return toJavaCoglMatrix(env, m);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_Matrix_initFromArray(JNIEnv *env, jobject obj, jfloatArray arr) {
	const float *array = (*env)->GetFloatArrayElements(env, arr, 0);
	cogl_matrix_init_from_array(coglMatrixFromJava(env, obj), array);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cogl_Matrix_getInverse(JNIEnv *env,
		jobject obj) {
	CoglMatrix *inv;
	gboolean b = cogl_matrix_get_inverse(coglMatrixFromJava(env, obj), inv);
	if (b == 0)
		return NULL;
	else
		return toJavaCoglMatrix(env, inv);
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_OffscreenBuffer_newInstance(
		JNIEnv *env, jclass cl, jobject obj) {
	return (jint) cogl_offscreen_new_to_texture(coglTextureFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_Shader_newInstance(JNIEnv *env,
		jclass cl, jint type) {
	return (jint) cogl_create_shader(type);
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_CoglTexture_newWithSize(
		JNIEnv *env, jclass cl, jint i, jint j, jint k, jint l) {
	return (jint) cogl_texture_new_with_size(i, j, k, l);
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_CoglTexture_newFromFile(
		JNIEnv *env, jclass cl, jstring string, jint i, jint j) {
	const char *str = (*env)->GetStringUTFChars(env, string, 0);
	CoglHandle ch = cogl_texture_new_from_file(str, i, j, NULL);
	if (ch == COGL_INVALID_HANDLE){
		jniClutterException(env, "COGL invalid handle");
		return -1;
	}
	(*env)-> ReleaseStringUTFChars(env, string, str);
	jint jp = (jint)ch;
	return jp;
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_CoglTexture_newFromData(
		JNIEnv *env, jclass cl, jint i, jint j, jint k, jint l, jint m, jint n,
		jstring string) {
	const guchar *str = (const guchar *) (*env)->GetStringChars(env, string, 0);
	return (jint) cogl_texture_new_from_data(i, j, k, l, m, n, str);
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_CoglTexture_getWidth(JNIEnv *env,
		jobject obj) {
	return (jint) cogl_texture_get_width(coglTextureFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_CoglTexture_getHeight(
		JNIEnv *env, jobject obj) {
	return (jint) cogl_texture_get_height(coglTextureFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_CoglTexture_getFormat(
		JNIEnv *env, jobject obj) {
	return (jint) cogl_texture_get_format(coglTextureFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_CoglTexture_getRowstride(
		JNIEnv *env, jobject obj) {
	return (jint) cogl_texture_get_rowstride(coglTextureFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_CoglTexture_getMaxWaste(
		JNIEnv *env, jobject obj) {
	return (jint) cogl_texture_get_max_waste(coglTextureFromJava(env, obj));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cogl_CoglTexture_isSliced(
		JNIEnv *env, jobject obj) {
	return (jboolean) cogl_texture_is_sliced(coglTextureFromJava(env, obj));
}
JNIEXPORT jstring JNICALL Java_org_jclutter_cogl_CoglTexture_getData(
		JNIEnv *env, jobject obj, jint i, jint j) {
	guchar *str;
	int size = cogl_texture_get_data(coglTextureFromJava(env, obj), i, j, str);
	if (size == 0)
		return NULL;
	else
		return (*env)->NewString(env, (const jchar *) str, size);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cogl_CoglTexture_setRegion(
		JNIEnv *env, jobject obj, jint i, jint j, jint k, jint l, jint m,
		jint n, jint o, jint p, jint q, jint r, jstring string) {
	const guchar *str = (const guchar *) (*env)->GetStringUTFChars(env, string,
			0);
	return (jboolean) cogl_texture_set_region(coglTextureFromJava(env, obj), i,
			j, k, l, m, n, o, p, q, r, str);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cogl_CoglTexture_isOffscreen(
		JNIEnv *env, jobject obj) {
	return (jboolean) cogl_is_offscreen(coglTextureFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_VertexBuffer_newInstance(
		JNIEnv *env, jclass cl, jint i) {
	return (jint) cogl_vertex_buffer_new(i);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_VertexBuffer_delete(JNIEnv *env, jobject obj, jstring string) {
	const char *str = (*env)->GetStringUTFChars(env, string, 0);
	cogl_vertex_buffer_delete(coglTextureFromJava(env, obj), str);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_VertexBuffer_disable(JNIEnv *env, jobject obj, jstring string) {
	const char *str = (*env)->GetStringUTFChars(env, string, 0);
	cogl_vertex_buffer_disable(coglTextureFromJava(env, obj), str);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_VertexBuffer_enable(JNIEnv *env, jobject obj, jstring string) {
	const char *str = (*env)->GetStringUTFChars(env, string, 0);
	cogl_vertex_buffer_enable(coglTextureFromJava(env, obj), str);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cogl_CoglTexture_isVertexBuffer(
		JNIEnv *env, jobject obj) {
	return (jboolean) cogl_is_vertex_buffer(coglTextureFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_cogl_VertexBuffer_getVerticesCount(
		JNIEnv *env, jobject obj) {
	return (jint) cogl_vertex_buffer_get_n_vertices(coglTextureFromJava(env,
			obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_VertexBuffer_submit(JNIEnv *env, jobject obj) {
	cogl_vertex_buffer_submit(coglTextureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_VertexBuffer_draw(JNIEnv *env, jobject obj, jint mode, jint first, jint count) {
	cogl_vertex_buffer_draw(coglTextureFromJava(env, obj), mode, first, count);
}
JNIEXPORT void JNICALL Java_org_jclutter_cogl_VertexBuffer_drawElements(JNIEnv *env, jobject obj, jint mode, jobject handle, jint min, jint max, jint off, jint count) {
	cogl_vertex_buffer_draw_elements(coglTextureFromJava(env, obj), mode, coglTextureFromJava(env, handle), min, max, off, count);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cogl_VertexBuffer_indicesGetForQuads(
		JNIEnv *env, jclass cl, jint indices) {
	CoglHandle h = cogl_vertex_buffer_indices_get_for_quads(indices);
	return createJavaCoglTexture(env, &h);
}
