#include "jclutter-cairo.h"


JNIEXPORT jstring JNICALL Java_org_jclutter_pango_PangoContext_getLanguage(
		JNIEnv *env, jobject obj) {
	return (jstring) pango_pango_context_get_language();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_PangoContext_setLanguage(JNIEnv *env, jobject obj, jstring param0) {
	pango_pango_context_set_language();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_PangoContext_setBaseDirection(JNIEnv *env, jobject obj, jint param0) {
	pango_pango_context_set_base_direction();
}
JNIEXPORT jint JNICALL Java_org_jclutter_pango_PangoContext_getBaseDirection(
		JNIEnv *env, jobject obj) {
	return (jint) pango_pango_context_get_base_direction();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_pango_PangoContext_getMatrix(
		JNIEnv *env, jobject obj) {
	return (jobject) pango_pango_context_get_matrix();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_PangoContext_setMatrix(JNIEnv *env, jobject obj, jobject param0) {
	pango_pango_context_set_matrix();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_pango_Layout_getSize(JNIEnv *env,
		jobject obj) {
	return (jobject) pango_layout_get_size();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setText(JNIEnv *env, jobject obj, jstring param0) {
	pango_layout_set_text();
}
JNIEXPORT jstring JNICALL Java_org_jclutter_pango_Layout_getText(JNIEnv *env,
		jobject obj) {
	return (jstring) pango_layout_get_text();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setMarkup(JNIEnv *env, jobject obj, jstring param0) {
	pango_layout_set_markup();
}
JNIEXPORT jstring JNICALL Java_org_jclutter_pango_Layout_getMarkup(JNIEnv *env,
		jobject obj) {
	return (jstring) pango_layout_get_markup();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_pango_Layout_isAutoDir(
		JNIEnv *env, jobject obj) {
	return (jboolean) pango_layout_is_auto_dir();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setAutoDir(JNIEnv *env, jobject obj, jboolean param0) {
	pango_layout_set_auto_dir();
}
JNIEXPORT jint JNICALL Java_org_jclutter_pango_Layout_getWidth(JNIEnv *env,
		jobject obj) {
	return (jint) pango_layout_get_width();
}
JNIEXPORT jint JNICALL Java_org_jclutter_pango_Layout_getHeight(JNIEnv *env,
		jobject obj) {
	return (jint) pango_layout_get_height();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setWidth(JNIEnv *env, jobject obj, jint param0) {
	pango_layout_set_width();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setHeight(JNIEnv *env, jobject obj, jint param0) {
	pango_layout_set_height();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setEllipsizeMode(JNIEnv *env, jobject obj) {
	pango_layout_set_ellipsize_mode();
}
JNIEXPORT jint JNICALL Java_org_jclutter_pango_Layout_getEllipsizeMode(
		JNIEnv *env, jobject obj) {
	return (jint) pango_layout_get_ellipsize_mode();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setWrapMode(JNIEnv *env, jobject obj, jint param0) {
	pango_layout_set_wrap_mode();
}
JNIEXPORT jint JNICALL Java_org_jclutter_pango_Layout_getWrapMode(JNIEnv *env,
		jobject obj) {
	return (jint) pango_layout_get_wrap_mode();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setIndent(JNIEnv *env, jobject obj, jint param0) {
	pango_layout_set_indent();
}
JNIEXPORT jint JNICALL Java_org_jclutter_pango_Layout_getIndent(JNIEnv *env,
		jobject obj) {
	return (jint) pango_layout_get_indent();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setSpacing(JNIEnv *env, jobject obj, jint param0) {
	pango_layout_set_spacing();
}
JNIEXPORT jint JNICALL Java_org_jclutter_pango_Layout_getSpacing(JNIEnv *env,
		jobject obj) {
	return (jint) pango_layout_get_spacing();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setJustify(JNIEnv *env, jobject obj, jboolean b) {
	pango_layout_set_justify();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_pango_Layout_isJustify(
		JNIEnv *env, jobject obj) {
	return (jboolean) pango_layout_get_justify();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setAutodir(JNIEnv *env, jobject obj, jboolean b) {
	pango_layout_set_autodir();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_pango_Layout_isAutodir(
		JNIEnv *env, jobject obj) {
	return (jboolean) pango_layout_is_autodir();
}
JNIEXPORT void JNICALL Java_org_jclutter_pango_Layout_setAlignment(JNIEnv *env, jobject obj, jint param0) {
	pango_layout_set_alignment();
}
JNIEXPORT jint JNICALL Java_org_jclutter_pango_Layout_getAlignment(JNIEnv *env,
		jobject obj) {
	return (jint) pango_layout_get_alignment();
}
