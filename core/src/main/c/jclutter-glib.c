#include "jclutter-common.h"
#include "jclutter-glib.h"
#include <glib.h>
#include <gmodule.h>
#include <glib-object.h>

JNIEXPORT jint JNICALL Java_org_jclutter_glib_GObject_getGType(JNIEnv *env,
		jobject obj, jstring prop) {
	if (obj == NULL)
		return -1;
	const char *nstring = (*env)->GetStringUTFChars(env, prop, 0);
	GParamSpec *p = g_object_class_find_property(G_OBJECT_GET_CLASS(
			getGPointer(env, obj)), nstring);
	if (p == NULL)
		return -1;
	return (p->value_type >> G_TYPE_FUNDAMENTAL_SHIFT);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_unref(JNIEnv *env, jobject obj) {
	if (obj == NULL) return;
	g_object_unref(getGPointer(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_connect(JNIEnv *env, jobject source, jstring event, jclass tclass, jstring meth, jstring signature, jboolean isStatic, jint cid, jint flags) {
	signalConnect(env, source, event, tclass, meth, signature, isStatic, cid, flags);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_disconnect(JNIEnv *env, jobject obj, jlong handler) {
	if (obj == NULL) return;
	g_signal_handler_disconnect(getGPointer(env, obj), handler);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GObject_isConnected(
		JNIEnv *env, jobject obj, jlong handler) {
	return (jboolean) g_signal_handler_is_connected(getGPointer(env, obj),
			handler);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_block(JNIEnv *env, jobject obj, jlong handler) {
	if (obj == NULL) return;
	g_signal_handler_block(getGPointer(env, obj), handler);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_unblock(JNIEnv *env, jobject obj, jlong handler) {
	if (obj == NULL) return;
	g_signal_handler_unblock(getGPointer(env, obj), handler);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GObject_hasProperty(JNIEnv *env,jobject obj,jstring name){
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GParamSpec *spec = g_object_class_find_property( G_OBJECT_GET_CLASS(getGPointer(env,obj)), prop);
	if (spec == NULL) return FALSE;
	else return TRUE;
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setBooleanProperty(JNIEnv *env, jobject obj,jstring name, jboolean value) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue gval = {0};
	g_value_init(&gval, G_TYPE_BOOLEAN);
	g_value_set_boolean(&gval, value);
	g_object_set_property(getGPointer(env,obj), prop, &gval);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setStringProperty(JNIEnv *env, jobject obj,jstring name, jstring value) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	const char *val = (*env)->GetStringUTFChars(env, value, 0);
	GValue gval = {0};
	g_value_init(&gval, G_TYPE_STRING);
	g_value_set_string(&gval, val);
	g_object_set_property(getGPointer(env,obj), prop, &gval);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setFloatProperty(JNIEnv *env, jobject obj,jstring name, jfloat value) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue gval = {0};
	g_value_init(&gval, G_TYPE_FLOAT);
	g_value_set_float(&gval, value);
	g_object_set_property(getGPointer(env,obj), prop, &gval);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setDoubleProperty(JNIEnv *env, jobject obj,jstring name, jdouble value) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue gval = {0};
	g_value_init(&gval, G_TYPE_DOUBLE);
	g_value_set_double(&gval, value);
	g_object_set_property(getGPointer(env,obj), prop, &gval);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setIntProperty(JNIEnv *env, jobject obj,jstring name, jint value) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue gval = {0};
	g_value_init(&gval, G_TYPE_INT);
	g_value_set_int(&gval, value);
	g_object_set_property(getGPointer(env,obj), prop, &gval);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setLongProperty(JNIEnv *env, jobject obj,jstring name, jlong value) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue gval = {0};
	g_value_init(&gval, G_TYPE_LONG);
	g_value_set_long(&gval, value);
	g_object_set_property(getGPointer(env,obj), prop, &gval);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setCharProperty(JNIEnv *env, jobject obj,jstring name, jchar value) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue gval = {0};
	g_value_init(&gval, G_TYPE_CHAR);
	g_value_set_char(&gval, value);
	g_object_set_property(getGPointer(env,obj), prop, &gval);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GObject_getBooleanProperty(
		JNIEnv *env, jobject obj, jstring name) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue value = { 0 };
	g_object_get_property(getGPointer(env, obj), prop, &value);
	return g_value_get_boolean(&value);
}
JNIEXPORT jstring JNICALL Java_org_jclutter_glib_GObject_getStringProperty(
		JNIEnv *env, jobject obj, jstring name) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue value = { 0 };
	g_object_get_property(getGPointer(env, obj), prop, &value);
	return (*env)->NewStringUTF(env, g_value_get_string(&value));
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_glib_GObject_getFloatProperty(
		JNIEnv *env, jobject obj, jstring name) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue value = { 0 };
	g_object_get_property(getGPointer(env, obj), prop, &value);
	return g_value_get_float(&value);
}
JNIEXPORT jdouble JNICALL Java_org_jclutter_glib_GObject_getDoubleProperty(
		JNIEnv *env, jobject obj, jstring name) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue value = { 0 };
	g_object_get_property(getGPointer(env, obj), prop, &value);
	return g_value_get_double(&value);
}
JNIEXPORT jint JNICALL Java_org_jclutter_glib_GObject_getIntProperty(
		JNIEnv *env, jobject obj, jstring name) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue value = { 0 };
	g_object_get_property(getGPointer(env, obj), prop, &value);
	return g_value_get_int(&value);
}
JNIEXPORT jlong JNICALL Java_org_jclutter_glib_GObject_getLongProperty(
		JNIEnv *env, jobject obj, jstring name) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue value = { 0 };
	g_object_get_property(getGPointer(env, obj), prop, &value);
	return g_value_get_long(&value);
}
JNIEXPORT jchar JNICALL Java_org_jclutter_glib_GObject_getCharProperty(
		JNIEnv *env, jobject obj, jstring name) {
	const char *prop = (*env)->GetStringUTFChars(env, name, 0);
	GValue value = { 0 };
	g_object_get_property(getGPointer(env, obj), prop, &value);
	return g_value_get_char(&value);
}

JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_Glib_mainContextPending(
		JNIEnv *env, jclass cl) {
	return g_main_context_pending(NULL);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_Glib_mainContextIteration(
		JNIEnv *env, jclass cl, jboolean b) {
	return g_main_context_iteration(NULL, b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_Glib_setEnv(JNIEnv *env,
		jclass cl, jstring name, jstring value, jboolean overwrite) {
	const char *n = (*env)->GetStringUTFChars(env, name, 0);
	const char *v = (*env)->GetStringUTFChars(env, value, 0);
	return g_setenv(n, v, overwrite);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_Glib_unsetEnv(JNIEnv *env, jclass cl, jstring name) {
	const char *n = (*env)->GetStringUTFChars(env, name, 0);
	g_unsetenv(n);
}
JNIEXPORT jstring JNICALL Java_org_jclutter_glib_Glib_getEnv(JNIEnv *env,
		jclass cl, jstring name) {
	const char *n = (*env)->GetStringUTFChars(env, name, 0);
	const char *v = g_getenv(n);
	if (v == NULL)
		return NULL;
	else
		return (*env)->NewStringUTF(env, v);
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_Glib_threadInit(JNIEnv *env, jclass cl){
	g_thread_init(NULL);
}

JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GList_add(JNIEnv *env, jobject obj, jobject data){
g_list_append();
return TRUE;
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GList_addAt(JNIEnv *env, jobject obj, jint index, jobject param1){
g_list_add();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_glib_GList_get(JNIEnv *env, jobject obj, jint param0){
return (jobject)g_list_get();
}
JNIEXPORT jint JNICALL Java_org_jclutter_glib_GList_indexOf(JNIEnv *env, jobject obj, jobject param0){
return (jint)g_list_index_of();
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GList_clear(JNIEnv *env, jobject obj){
g_list_clear();
}
JNIEXPORT jint JNICALL Java_org_jclutter_glib_GList_size(JNIEnv *env, jobject obj){
return (jint)g_list_size();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_glib_GList_remove(JNIEnv *env, jobject obj, jint param0){
return (jobject)g_list_remove();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_glib_GList_set(JNIEnv *env, jobject obj, jint param0, jobject param1){
return (jobject)g_list_set();
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GListIterator_add(JNIEnv *env, jobject obj, jobject param0){
g_list_iterator_add();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GListIterator_hasNext(JNIEnv *env, jobject obj){
return (jboolean)g_list_iterator_has_next();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_glib_GListIterator_next(JNIEnv *env, jobject obj){
return (jobject)g_list_iterator_next();
}
JNIEXPORT void JNICALL Java_org_jclutter_glib_GListIterator_set(JNIEnv *env, jobject obj, jobject param0){
g_list_iterator_set();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GListIterator_hasPrevious(JNIEnv *env, jobject obj){
return (jboolean)g_list_iterator_has_previous();
}
JNIEXPORT jint JNICALL Java_org_jclutter_glib_GListIterator_nextIndex(JNIEnv *env, jobject obj){
return (jint)g_list_iterator_next_index();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_glib_GListIterator_previous(JNIEnv *env, jobject obj){
return (jobject)g_list_iterator_previous();
}
JNIEXPORT jint JNICALL Java_org_jclutter_glib_GListIterator_previousIndex(JNIEnv *env, jobject obj){
return (jint)g_list_iterator_previous_index();
}

