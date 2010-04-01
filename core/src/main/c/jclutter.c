#include "jclutter.h"
#include "jclutter-common.h"
#include <clutter/clutter.h>
#include <string.h>


// TODO doesnt work with arguments
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_init(JNIEnv *env, jclass jc, jobjectArray jargs)
{
	LOGI("clutter init");
	jsize argc = 0;
	char **argv = NULL;

	if (jargs != NULL) {
		argc = (*env)->GetArrayLength(env, jargs);
		if (argc > 0)
		arrayStringsFromJava(env, argv, jargs);
	}

	int ret = clutter_init(&argc, &argv);

	switch (ret) {
		case CLUTTER_INIT_SUCCESS: break;
		case CLUTTER_INIT_ERROR_UNKNOWN: jniClutterException(env, "Unknown error"); return;
		case CLUTTER_INIT_ERROR_THREADS: jniClutterException(env, "Error in threads"); return;
		case CLUTTER_INIT_ERROR_BACKEND: jniClutterException(env, "Backend error"); return;
		case CLUTTER_INIT_ERROR_INTERNAL: jniClutterException(env, "Internal error"); return;
	}
}

JNIEXPORT void JNICALL Java_org_jclutter_Clutter_mainStart(JNIEnv *env, jclass jc)
{
	clutter_main();
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_mainQuit(JNIEnv *env, jclass jc)
{
	clutter_main_quit();
}
JNIEXPORT jint JNICALL Java_org_jclutter_Clutter_mainLevel(JNIEnv *env,
		jclass jc) {
	return (jint) clutter_main_level();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Clutter_getDebugEnabled(
		JNIEnv *env, jclass jc) {
	return (jboolean) clutter_get_debug_enabled();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Clutter_getShowFps(JNIEnv *env,
		jclass jc) {
	return (jboolean) clutter_get_show_fps();
}
JNIEXPORT jlong JNICALL Java_org_jclutter_Clutter_getTimestamp(JNIEnv *env,
		jclass jc) {
	return (jlong) clutter_get_timestamp();
}
JNIEXPORT jint JNICALL Java_org_jclutter_Clutter_getActorPointerByGID(
		JNIEnv *env, jclass jc, jint gid) {
	return (jint) clutter_get_actor_by_gid(gid);
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_setDefaultFrameRate(JNIEnv *env, jclass jc, jint frames_per_sec)
{
	clutter_set_default_frame_rate(frames_per_sec);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Clutter_getDefaultFrameRate(
		JNIEnv *env, jclass jc) {
	return (jint) clutter_get_default_frame_rate();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Clutter_isMotionEventsEnabled(
		JNIEnv *env, jclass jc) {
	return (jboolean) clutter_get_motion_events_enabled();
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_setMotionEventsEnabled(JNIEnv *env, jclass jc, jboolean enable)
{
	clutter_set_motion_events_enabled(enable);
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_clearGlyphCache(JNIEnv *env, jclass jc) {
	clutter_clear_glyph_cache();
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_threadsInit(JNIEnv *env, jclass jc) {
	clutter_threads_init();
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_threadsEnter(JNIEnv *env, jclass jc) {
	clutter_threads_enter();
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_threadsLeave(JNIEnv *env, jclass jc) {
	clutter_threads_leave();
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_threadsAddIdle(JNIEnv *env, jclass clazz, jint func, jint priority) {
	threadsAddIdle(func, priority);
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_threadsAddTimeout(JNIEnv *env, jclass clazz, jint func, jint priority, jint interval) {
	threadsAddTimeout(func, priority, interval);
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_threadsAddFrameSource(JNIEnv *env, jclass clazz, jint func, jint priority, jint fps) {
	threadsAddFrameSource(func, priority, fps);
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_threadsAddRepaint(JNIEnv *env, jclass clazz, jint func) {
	threadsAddRepaint(func);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Clutter_getKeyboardGrab(JNIEnv *env,
		jclass jc) {
	ClutterActor *actor = clutter_get_keyboard_grab();
	return findJavaGObject(env, G_OBJECT(actor));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Clutter_getPointerGrab(JNIEnv *env,
		jclass jc) {
	ClutterActor *actor = clutter_get_pointer_grab();
	return findJavaGObject(env, G_OBJECT(actor));
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_grabKeyboard(JNIEnv *env, jclass jc, jobject actor)
{
	clutter_grab_keyboard(actorFromJava(env, actor));
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_grabPointer(JNIEnv *env, jclass jc, jobject actor)
{
	clutter_grab_pointer(actorFromJava(env, actor));
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_ungrabKeyboard(JNIEnv *env, jclass jc)
{
	clutter_ungrab_keyboard();
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_ungrabPointer(JNIEnv *env, jclass jc)
{
	clutter_ungrab_pointer();
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_grabPointerForDevice(JNIEnv *env, jclass jc, jobject actor, jint id)
{
	clutter_grab_pointer_for_device(actorFromJava(env, actor), id);
}
JNIEXPORT void JNICALL Java_org_jclutter_Clutter_ungrabPointerForDevice(JNIEnv *env, jclass jc, jint id)
{
	clutter_ungrab_pointer_for_device(id);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Clutter_getMajorVersion(JNIEnv *env,
		jclass jc) {
	return CLUTTER_MAJOR_VERSION;
}
JNIEXPORT jint JNICALL Java_org_jclutter_Clutter_getMinorVersion(JNIEnv *env,
		jclass jc) {
	return CLUTTER_MINOR_VERSION;
}
JNIEXPORT jint JNICALL Java_org_jclutter_Clutter_getMicroVersion(JNIEnv *env,
		jclass jc) {
	return CLUTTER_MICRO_VERSION;
}
JNIEXPORT jstring JNICALL Java_org_jclutter_Clutter_getVersion(JNIEnv *env,
		jclass jc) {
	return ((*env)->NewStringUTF(env, CLUTTER_VERSION_S));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Clutter_checkVersion(JNIEnv *env,
		jclass jc, jint maj, jint min, jint mic) {
	return clutter_check_version(maj, min, mic);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Clutter_hasFeature(JNIEnv *env,
		jclass jc, jint feature) {
	return (jboolean)clutter_feature_available(feature);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Clutter_getFeatures(JNIEnv *env,
		jclass jc) {
	return (jint)clutter_feature_get_all();
}


JNIEXPORT void JNICALL Java_org_jclutter_Actor_show(JNIEnv *env, jobject obj) {
	clutter_actor_show(actorFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_showAll(JNIEnv *env, jobject obj) {
	clutter_actor_show_all(actorFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_hide(JNIEnv *env, jobject obj) {
	clutter_actor_hide(actorFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_hideAll(JNIEnv *env, jobject obj) {
	clutter_actor_hide_all(actorFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_realize(JNIEnv *env, jobject obj) {
	clutter_actor_realize(actorFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_unrealize(JNIEnv *env, jobject obj) {
	clutter_actor_unrealize(actorFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_paint(JNIEnv *env, jobject obj) {
	clutter_actor_paint(actorFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_queueRedraw(JNIEnv *env, jobject obj) {
	clutter_actor_queue_redraw(actorFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_queueRelayout(JNIEnv *env, jobject obj) {
	clutter_actor_queue_relayout(actorFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_destroy(JNIEnv *env, jobject obj) {
	clutter_actor_destroy(actorFromJava(env, obj));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Actor_shouldPickPaint(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_actor_should_pick_paint(actorFromJava(env, obj));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getAllocationBox(JNIEnv *env,
		jobject obj) {
	ClutterActorBox ret_box;
	clutter_actor_get_allocation_box(actorFromJava(env, obj), &ret_box);
	return toJavaActorBox(env, &ret_box);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getAllocationGeometry(
		JNIEnv *env, jobject obj) {
	ClutterGeometry ret_geo;
	clutter_actor_get_allocation_geometry(actorFromJava(env, obj), &ret_geo);
	return toJavaGeometry(env, &ret_geo);
}
/*
 JNIEXPORT jobjectArray JNICALL Java_org_jclutter_Actor_getAllocationVertices(JNIEnv *env, jobject obj, jobject ancestor)
 {

 jint ancestor_ptr = (*env)->GetIntField(env, ancestor, field_nobject);
 gint ret_x;
 gint ret_y;
 clutter_actor_get_allocation_vertices(actorFromJava(env, obj), CLUTTER_ACTOR(ancestor_ptr), &ret_x, &ret_y);
 return toJavaPoint(env, ret_x, ret_y);
 }*/

JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getPreferredSize(JNIEnv *env,
		jobject obj) {
	float ret_width;
	float ret_height;
	float min_width;
	float min_height;
	clutter_actor_get_preferred_size(actorFromJava(env, obj), &min_width,
			&min_height, &ret_width, &ret_height);
	return toJavaDimension(env, ret_width, ret_height);
}

JNIEXPORT jfloat JNICALL Java_org_jclutter_Actor_getPreferredWidth(JNIEnv *env,
		jobject obj, jfloat forHeight) {
	float width;
	float min_width;
	clutter_actor_get_preferred_width(actorFromJava(env, obj), forHeight,
			&min_width, &width);
	return width;
}

JNIEXPORT jfloat JNICALL Java_org_jclutter_Actor_getPreferredHeight(
		JNIEnv *env, jobject obj, jfloat forWidth) {
	float height;
	float min_height;
	clutter_actor_get_preferred_height(actorFromJava(env, obj), forWidth,
			&min_height, &height);
	return height;
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setFixedPositionSet(JNIEnv *env, jobject obj, jboolean isSet)
{
	clutter_actor_set_fixed_position_set(actorFromJava(env, obj), isSet);
}

JNIEXPORT jboolean JNICALL Java_org_jclutter_Actor_getFixedPositionSet(
		JNIEnv *env, jobject obj) {
	return (jboolean) clutter_actor_get_fixed_position_set(actorFromJava(env,
			obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setGeometry(JNIEnv *env, jobject obj, jint x, jint y, jint width, jint height)
{
	ClutterGeometry geo;
	geo.x = x;
	geo.y = y;
	geo.width = width;
	geo.height = height;
	clutter_actor_set_geometry(actorFromJava(env, obj), &geo);
}

JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getGeometry(JNIEnv *env,
		jobject obj) {
	ClutterGeometry ret_geo;
	clutter_actor_get_geometry(actorFromJava(env, obj), &ret_geo);
	return toJavaGeometry(env, &ret_geo);
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setSize(JNIEnv *env, jobject obj, jfloat width, jfloat height)
{
	clutter_actor_set_size(actorFromJava(env, obj), width, height);
}

JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getSize(JNIEnv *env,
		jobject obj) {
	float ret_width;
	float ret_height;
	clutter_actor_get_size(actorFromJava(env, obj), &ret_width, &ret_height);
	return toJavaDimension(env, ret_width, ret_height);
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setPosition(JNIEnv *env, jobject obj, jfloat x, jfloat y)
{
	clutter_actor_set_position(actorFromJava(env, obj), x, y);
}

JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getPosition(JNIEnv *env,
		jobject obj) {
	float ret_x;
	float ret_y;
	clutter_actor_get_position(actorFromJava(env, obj), &ret_x, &ret_y);
	return toJavaPoint(env, ret_x, ret_y, 0);
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setWidth(JNIEnv *env, jobject obj, jfloat width)
{
	clutter_actor_set_width(actorFromJava(env, obj), width);
}

JNIEXPORT jfloat JNICALL Java_org_jclutter_Actor_getWidth(JNIEnv *env,
		jobject obj) {
	return (jfloat) clutter_actor_get_width(actorFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setHeight(JNIEnv *env, jobject obj, jfloat height)
{
	clutter_actor_set_height(actorFromJava(env, obj), height);
}

JNIEXPORT jfloat JNICALL Java_org_jclutter_Actor_getHeight(JNIEnv *env,
		jobject obj) {
	return (jfloat) clutter_actor_get_height(actorFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setX(JNIEnv *env, jobject obj, jfloat x)
{
	clutter_actor_set_x(actorFromJava(env, obj), x);
}

JNIEXPORT jfloat JNICALL Java_org_jclutter_Actor_getX(JNIEnv *env, jobject obj) {
	return (jfloat) clutter_actor_get_x(actorFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setY(JNIEnv *env, jobject obj, jfloat y)
{
	clutter_actor_set_y(actorFromJava(env, obj), y);
}

JNIEXPORT jfloat JNICALL Java_org_jclutter_Actor_getY(JNIEnv *env, jobject obj) {
	return (jfloat) clutter_actor_get_y(actorFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_moveBy(JNIEnv *env, jobject obj, jint dx, jint dy)
{
	clutter_actor_move_by(actorFromJava(env, obj), dx, dy);
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setRotation(JNIEnv *env, jobject obj, jobject rotation)
{
	ClutterRotateAxis rotate_axis;
	gdouble rotation_angle;
	gfloat rotation_x;
	gfloat rotation_y;
	gfloat rotation_z;
	rotationFromJava(env, rotation, &rotate_axis, &rotation_angle, &rotation_x, &rotation_y, &rotation_z );
	clutter_actor_set_rotation(actorFromJava(env, obj),rotate_axis,rotation_angle,rotation_x,rotation_y,rotation_z);
}

JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getRotation(JNIEnv *env,
		jobject obj, jint axis) {
	gfloat ret_x;
	gfloat ret_y;
	gfloat ret_z;
	gdouble angle = clutter_actor_get_rotation(actorFromJava(env, obj), axis,
			&ret_x, &ret_y, &ret_z);
	return toJavaRotation(env, axis, angle, ret_x, ret_y, ret_z);
}

JNIEXPORT jboolean JNICALL Java_org_jclutter_Actor_isRotated(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_actor_is_rotated(actorFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setOpacity(JNIEnv *env, jobject obj, jint opacity)
{
	clutter_actor_set_opacity(actorFromJava(env, obj), opacity);
}

JNIEXPORT jint JNICALL Java_org_jclutter_Actor_getOpacity(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_actor_get_opacity(actorFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setName(JNIEnv *env, jobject obj, jstring string)
{
	const char *nstring = (*env)->GetStringUTFChars(env, string, 0);
	clutter_actor_set_name(actorFromJava(env, obj), nstring);
}

JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getName(JNIEnv *env,
		jobject obj) {
	const gchar *name = clutter_actor_get_name(actorFromJava(env, obj));
	return (*env)->NewStringUTF(env, name);
}

JNIEXPORT jint JNICALL Java_org_jclutter_Actor_getGid(JNIEnv *env, jobject obj) {
	return (jint) clutter_actor_get_gid(actorFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setClip(JNIEnv *env, jobject obj, jfloat x, jfloat y, jfloat width, jfloat height)
{
	clutter_actor_set_clip(actorFromJava(env, obj), x, y, width, height);
}
/*
 JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getClip(JNIEnv *env, jobject obj)
 {
 clutter_actor_get_clip(actorFromJava(env, obj), &x, &y, &width, &height);
 ClutterGeometry ret_geo;
 ret_geo.x = x;
 ret_geo.y = y;
 ret_geo.width = width;
 ret_geo.height = height;
 return toJavaGeometry(env, &ret_geo);
 }*/

JNIEXPORT void JNICALL Java_org_jclutter_Actor_removeClip(JNIEnv *env, jobject obj)
{
	clutter_actor_remove_clip(actorFromJava(env, obj));
}

JNIEXPORT jboolean JNICALL Java_org_jclutter_Actor_hasClip(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_actor_has_clip(actorFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_raise(JNIEnv *env, jobject obj, jobject below)
{
	clutter_actor_raise(actorFromJava(env, obj), actorFromJava(env, below));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_lower(JNIEnv *env, jobject obj, jobject above)
{
	clutter_actor_lower(actorFromJava(env, obj), actorFromJava(env, above));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_raiseTop(JNIEnv *env, jobject obj)
{
	clutter_actor_raise_top(actorFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_lowerBottom(JNIEnv *env, jobject obj)
{
	clutter_actor_lower_bottom(actorFromJava(env, obj));
}

JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getStage(JNIEnv *env,
		jobject obj) {
	ClutterActor *stage = clutter_actor_get_stage(actorFromJava(env, obj));
	return findJavaGObject(env, G_OBJECT(stage));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getParent(JNIEnv *env, jobject obj){
	ClutterActor *parent = clutter_actor_get_parent(actorFromJava(env, obj));
	return findJavaGObject(env, G_OBJECT(parent));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setDepth(JNIEnv *env, jobject obj, jfloat depth)
{
	clutter_actor_set_depth(actorFromJava(env, obj), depth);
}

JNIEXPORT jfloat JNICALL Java_org_jclutter_Actor_getDepth(JNIEnv *env,
		jobject obj) {
	return (jfloat) clutter_actor_get_depth(actorFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setScale(JNIEnv *env, jobject obj, jdouble scale_x, jdouble scale_y, jobject center)
{
	if (center == NULL)
	clutter_actor_set_scale (actorFromJava(env, obj), scale_x, scale_y);
	else clutter_actor_set_scale_full (actorFromJava(env, obj), scale_x, scale_y, getPointX(env, center), getPointY(env, center));
}

JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getScale(JNIEnv *env,
		jobject obj) {
	gdouble ret_x;
	gdouble ret_y;
	float centerx;
	float centery;
	clutter_actor_get_scale(actorFromJava(env, obj), &ret_x, &ret_y);
	clutter_actor_get_scale_center(actorFromJava(env, obj), &centery, &centery);
	return toJavaScale(env, ret_x, ret_y, centerx, centery);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Actor_isScaled(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_actor_is_scaled(actorFromJava(env, obj));
}
/*
 JNIEXPORT void JNICALL Java_org_jclutter_Actor_applyTransformToPoint(JNIEnv *env, jobject obj, jobject jpoint, jobject jvertex)
 {

 ClutterVertex point;
 ClutterVertex vertex;
 point.x = (*env)->GetIntField(env, jpoint, field_position_x);
 point.y = (*env)->GetIntField(env, jpoint, field_position_y);
 point.z = (*env)->GetIntField(env, jpoint, field_position_z);
 vertex.x = (*env)->GetIntField(env, jvertex, field_position_x);
 vertex.y = (*env)->GetIntField(env, jvertex, field_position_y);
 vertex.z = (*env)->GetIntField(env, jvertex, field_position_z);
 clutter_actor_apply_transform_to_point(actorFromJava(env, obj), &point, &vertex);
 }*/
/*
 JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_transformStagePoint(JNIEnv *env, jobject obj, jint x, jint y)
 {

 gint ret_x;
 gint ret_y;
 clutter_actor_transform_stage_point(actorFromJava(env, obj), x, y, &ret_x, &ret_y);
 return toJavaPoint(env, ret_x, ret_y, 0);
 }*/
/*
 JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_applyRelativeTransformToPoint(JNIEnv *env, jobject obj, jobject ancestor, jobject point)
 {

 jint ancestor_ptr = (*env)->GetIntField(env, ancestor, field_nobject);
 gint point_x;
 gint point_y;
 readJavaPosition(env, point, point_x, point_y);
 gint ret_x;
 gint ret_y;
 clutter_actor_apply_relative_transform_to_point(actorFromJava(env, obj), CLUTTER_ACTOR(ancestor_ptr), point_x, point_y, &ret_x, &ret_y);
 return toJavaPoint(env, ret_x, ret_y);
 }*/
/*
 JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getTransformedPosition(JNIEnv *env, jobject obj)
 {

 gint ret_x;
 gint ret_y;
 clutter_actor_get_transformed_position(actorFromJava(env, obj), &ret_x, &ret_y);
 return toJavaPoint(env, ret_x, ret_y, 0);
 }*/
/*
 JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getTransformedSize(JNIEnv *env, jobject obj)
 {

 int ret_width;
 int ret_height;
 clutter_actor_get_transformed_size(actorFromJava(env, obj), &ret_width, &ret_height);
 return createJavaDimension(env, ret_width, ret_height);
 }*/

JNIEXPORT jbyte JNICALL Java_org_jclutter_Actor_getPaintOpacity(JNIEnv *env,
		jobject obj) {
	return (jbyte) clutter_actor_get_paint_opacity(actorFromJava(env, obj));
}
/*
 JNIEXPORT jobjectArray JNICALL Java_org_jclutter_Actor_getAbsAllocationVertices(JNIEnv *env, jobject obj)
 {

 gint ret_x;
 gint ret_y;
 clutter_actor_get_abs_allocation_vertices(actorFromJava(env, obj), &ret_x, &ret_y);
 return toJavaPoint(env, ret_x, ret_y);
 }*/
/*
 JNIEXPORT jobjectArray JNICALL Java_org_jclutter_Actor_boxGetFromVertices(JNIEnv *env, jclass jc, jobjectArray vtx)
 {
 gint vtx_x;
 gint vtx_y;
 readJavaPosition(env, vtx, vtx_x, vtx_y);
 ClutterActorBox ret_box;
 clutter_box_get_from_vertices(vtx_x, vtx_y, &ret_box);
 return createJavaBox(env, &ret_box);
 }*/

JNIEXPORT void JNICALL Java_org_jclutter_Actor_setAnchorPoint(JNIEnv *env, jobject obj, jfloat anchor_x, jfloat anchor_y)
{
	clutter_actor_set_anchor_point(actorFromJava(env, obj), anchor_x, anchor_y);
}

JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getAnchorPoint(JNIEnv *env, jobject obj) {
 gfloat ret_x;
 gfloat ret_y;
 clutter_actor_get_anchor_point(actorFromJava(env, obj), &ret_x, &ret_y);
 return toJavaPoint(env, ret_x, ret_y, 0);
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_setAnchorPointFromGravity(JNIEnv *env, jobject obj, jint gravity) {
	clutter_actor_set_anchor_point_from_gravity(actorFromJava(env, obj), gravity);
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_moveAnchorPoint(JNIEnv *env, jobject obj, jfloat anchor_x, jfloat anchor_y) {
	clutter_actor_move_anchor_point(actorFromJava(env, obj), anchor_x, anchor_y);
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_moveAnchorPointFromGravity(JNIEnv *env, jobject obj, jint gravity) {
	clutter_actor_move_anchor_point_from_gravity(actorFromJava(env, obj), gravity);
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_setReactive(JNIEnv *env, jobject obj, jboolean reactive) {
	clutter_actor_set_reactive(actorFromJava(env, obj), reactive);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Actor_isReactive(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_actor_get_reactive(actorFromJava(env, obj));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Actor_setShader(JNIEnv *env,
		jobject obj, jobject shader) {
	return (jboolean) clutter_actor_set_shader(actorFromJava(env, obj),
			shaderFromJava(env, shader));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getShader(JNIEnv *env,
		jobject obj) {
	ClutterShader *shader = clutter_actor_get_shader(actorFromJava(env, obj));
	if (shader == NULL)
		return NULL;
	return toJavaShader(env, shader);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Actor_getKeyBindingPool(
		JNIEnv *env, jobject obj) {
	ClutterActor *actor = actorFromJava(env, obj);
	ClutterBindingPool *pool = clutter_binding_pool_find(G_OBJECT_TYPE_NAME(actor));
	if (pool == NULL)
		return NULL;
	LOGI("pool is not null");
	jobject jpool = findJavaGObject(env, G_OBJECT(pool));
	if (jpool != NULL)
		return jpool;
	else {
		LOGI("create java binding pool");
		return createJavaKeyBindingPool(env, pool);
	}
}
JNIEXPORT void JNICALL Java_org_jclutter_Actor_grabKeyFocus(JNIEnv *env, jobject obj){
	clutter_actor_grab_key_focus(actorFromJava(env, obj));
}

/*
 JNIEXPORT void JNICALL Java_org_jclutter_Actor_setShaderParam(JNIEnv *env, jobject obj, jstring param, jfloat value)
 {
 const char *nstring = (*env)->GetStringUTFChars(env, param, 0);
 // TODO: convert a value to gvalue clutter_actor_set_shader_param(actorFromJava(env, obj), nstring, value);
 }*/
JNIEXPORT jboolean JNICALL Java_org_jclutter_Actor_isMapped(JNIEnv *env,
		jobject obj) {
	return CLUTTER_ACTOR_IS_MAPPED(actorFromJava(env, obj));
}

JNIEXPORT jobject JNICALL Java_org_jclutter_Color_getColor(JNIEnv *env, jclass cl, jstring cstring){
	const char *colorname = (*env)->GetStringUTFChars(env, cstring, 0);
	ClutterColor c;
	gboolean b = clutter_color_from_string(&c, colorname);
	(*env)->ReleaseStringUTFChars(env, cstring, colorname);
	if (b) return toJavaColor(env, &c);
	else return NULL;
}

JNIEXPORT void JNICALL Java_org_jclutter_MediaSupport_setUri(JNIEnv *env, jclass cl, jobject media, jstring uri) {
	const char *nstring = (*env)->GetStringUTFChars(env, uri, 0);
	clutter_media_set_uri(CLUTTER_MEDIA(getGPointer(env, media)), nstring);
}
JNIEXPORT jstring JNICALL Java_org_jclutter_MediaSupport_getUri(JNIEnv *env, jclass cl,
		jobject media) {
	return (*env)->NewStringUTF(env, clutter_media_get_uri(CLUTTER_MEDIA(
			getGPointer(env, media))));
}
JNIEXPORT void JNICALL Java_org_jclutter_MediaSupport_setPlaying(JNIEnv *env, jclass cl, jobject media, jboolean p) {
	clutter_media_set_playing(CLUTTER_MEDIA(getGPointer(env, media)), p);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_MediaSupport_isPlaying(JNIEnv *env, jclass cl,
		jobject media) {
	return clutter_media_get_playing(CLUTTER_MEDIA(getGPointer(env, media)));
}
JNIEXPORT void JNICALL Java_org_jclutter_MediaSupport_setProgress(JNIEnv *env, jclass cl, jobject media, jdouble progress) {
	clutter_media_set_progress(CLUTTER_MEDIA(getGPointer(env, media)), progress);
}
JNIEXPORT jdouble JNICALL Java_org_jclutter_MediaSupport_getProgress(JNIEnv *env, jclass cl,
		jobject media) {
	return clutter_media_get_progress(CLUTTER_MEDIA(getGPointer(env, media)));
}
JNIEXPORT void JNICALL Java_org_jclutter_MediaSupport_setAudioVolume(JNIEnv *env, jclass cl, jobject media, jdouble volume) {
	clutter_media_set_audio_volume(CLUTTER_MEDIA(getGPointer(env, media)), volume);
}
JNIEXPORT jdouble JNICALL Java_org_jclutter_MediaSupport_getAudioVolume(JNIEnv *env, jclass cl,
		jobject media) {
	return clutter_media_get_audio_volume(
			CLUTTER_MEDIA(getGPointer(env, media)));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_MediaSupport_isCanSeek(JNIEnv *env, jclass cl,
		jobject media) {
	return clutter_media_get_can_seek(CLUTTER_MEDIA(getGPointer(env, media)));
}
JNIEXPORT jdouble JNICALL Java_org_jclutter_MediaSupport_getBufferFill(JNIEnv *env, jclass cl,
		jobject media) {
	return clutter_media_get_buffer_fill(CLUTTER_MEDIA(getGPointer(env, media)));
}
JNIEXPORT jdouble JNICALL Java_org_jclutter_MediaSupport_getDuration(JNIEnv *env, jclass cl,
		jobject media) {
	return clutter_media_get_duration(CLUTTER_MEDIA(getGPointer(env, media)));
}
JNIEXPORT void JNICALL Java_org_jclutter_MediaSupport_setFileName(JNIEnv *env, jclass cl, jobject media, jstring string) {
	const char *nstring = (*env)->GetStringUTFChars(env, string, 0);
	clutter_media_set_filename(CLUTTER_MEDIA(getGPointer(env, media)), nstring);
}
JNIEXPORT void JNICALL Java_org_jclutter_MediaSupport_setSubtitleUri(JNIEnv *env, jclass cl, jobject media, jstring uri) {
	const char *nstring = (*env)->GetStringUTFChars(env, uri, 0);
	clutter_media_set_subtitle_uri(CLUTTER_MEDIA(getGPointer(env, media)), nstring);
}
JNIEXPORT jstring JNICALL Java_org_jclutter_MediaSupport_getSubtitleUri(JNIEnv *env, jclass cl,
		jobject media) {
	return (*env)->NewStringUTF(env, clutter_media_get_subtitle_uri(CLUTTER_MEDIA(
			getGPointer(env, media))));
}
JNIEXPORT void JNICALL Java_org_jclutter_MediaSupport_setSubtitleFontname(JNIEnv *env, jclass cl, jobject media, jstring font) {
	const char *nstring = (*env)->GetStringUTFChars(env, font, 0);
	clutter_media_set_subtitle_font_name(CLUTTER_MEDIA(getGPointer(env, media)), nstring);
}
JNIEXPORT jstring JNICALL Java_org_jclutter_MediaSupport_getSubtitleFontname(JNIEnv *env, jclass cl,
		jobject media) {
	return (*env)->NewStringUTF(env, clutter_media_get_subtitle_font_name(CLUTTER_MEDIA(
			getGPointer(env, media))));
}

JNIEXPORT jint JNICALL Java_org_jclutter_Stage_newInstance(JNIEnv *env, jclass cl){
	ClutterActor *newstage = clutter_stage_new();
	if (newstage == NULL) return 0; // TODO error handling
	return (jint)newstage;
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Stage_getDefault(JNIEnv *env,
		jclass jc) {
	ClutterActor *stage = clutter_stage_get_default();
	if (stage == NULL)
		return NULL;
	jobject obj = findJavaGObject(env, G_OBJECT(stage));
	if (obj == NULL) {
		LOGI("create java stage in get default");
		return createJavaStage(env, CLUTTER_STAGE(stage));
	} else
		return obj;
}
JNIEXPORT jint JNICALL Java_org_jclutter_Stage_getDefaultId(JNIEnv *env,
		jclass jc) {
	ClutterActor *stage = clutter_stage_get_default();
	return (jint) stage;
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_setDefault(JNIEnv *env, jclass jc, jobject obj) {
	if (obj == NULL) return;
	ClutterStageManager *mgr = clutter_stage_manager_get_default();
	clutter_stage_manager_set_default_stage(mgr, stageFromJava(env, obj));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Stage_listStages(JNIEnv *env,
		jclass jc) {
	ClutterStageManager *mgr = clutter_stage_manager_get_default();
	GSList *gli = clutter_stage_manager_list_stages(mgr);
	// TODO convert into java,util.List<Stage>
	if (gli == NULL)
		return NULL;
	return NULL;
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Stage_isDefault(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_stage_is_default(stageFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_setColor(JNIEnv *env, jobject obj, jobject jcolor) {
	ClutterColor color;
	colorFromJava(env, jcolor, &color);
	clutter_stage_set_color(stageFromJava(env,obj), &color);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Stage_getColor(JNIEnv *env,
		jobject obj) {
	ClutterColor c;
	clutter_stage_get_color(stageFromJava(env, obj), &c);
	return toJavaColor(env, &c);
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_setFullscreen(JNIEnv *env, jobject obj, jboolean b) {
	clutter_stage_set_fullscreen(stageFromJava(env,obj), b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Stage_isFullscreen(JNIEnv *env,
		jobject obj) {
	return clutter_stage_get_fullscreen(stageFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_showCursor(JNIEnv *env, jobject obj) {
	clutter_stage_show_cursor(stageFromJava(env,obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_hideCursor(JNIEnv *env, jobject obj) {
	clutter_stage_hide_cursor(stageFromJava(env,obj));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Stage_getActorAtPos(JNIEnv *env,
		jobject obj, jint pick_mode, jint x, jint y) {
	ClutterActor *a = clutter_stage_get_actor_at_pos(stageFromJava(env, obj),
			pick_mode, x, y);
	return findJavaGObject(env, G_OBJECT(a));
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_ensureCurrent(JNIEnv *env, jobject obj) {
	clutter_stage_ensure_current(stageFromJava(env,obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_queueRedraw(JNIEnv *env, jobject obj) {
	clutter_stage_queue_redraw(stageFromJava(env,obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_setKeyFocus(JNIEnv *env, jobject obj, jobject actor) {
	clutter_stage_set_key_focus(stageFromJava(env,obj), actorFromJava(env, actor));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Stage_getKeyFocus(JNIEnv *env,
		jobject obj) {
	ClutterActor *a = clutter_stage_get_key_focus(stageFromJava(env, obj));
	return findJavaGObject(env, G_OBJECT(a));
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_setPerspective(JNIEnv *env, jobject obj, jfloat fovy, jfloat aspect, jfloat zNear, jfloat zFar) {
	ClutterPerspective *per;
	per->fovy = fovy;
	per->aspect = aspect;
	per->z_near = zNear;
	per->z_far = zFar;
	clutter_stage_set_perspective(stageFromJava(env,obj), per);
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_setTitle(JNIEnv *env, jobject obj, jstring title) {
	const char *nstring = (*env)->GetStringUTFChars(env, title, 0);
	clutter_stage_set_title(stageFromJava(env,obj), nstring);
	(*env)->ReleaseStringUTFChars(env, title, nstring);
}
JNIEXPORT jstring JNICALL Java_org_jclutter_Stage_getTitle(JNIEnv *env,
		jobject obj) {
	const char *str = clutter_stage_get_title(stageFromJava(env, obj));
	return ((*env)->NewStringUTF(env, str));
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_setUserResizable(JNIEnv *env, jobject obj, jboolean resizable) {
	clutter_stage_set_user_resizable(stageFromJava(env,obj), resizable);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Stage_getUserResizable(
		JNIEnv *env, jobject obj) {
	return (jboolean) clutter_stage_get_user_resizable(stageFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_setUseFog(JNIEnv *env, jobject obj, jboolean fog) {
	clutter_stage_set_use_fog(stageFromJava(env,obj), fog);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Stage_getUseFog(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_stage_get_use_fog(stageFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Stage_setFog(JNIEnv *env, jobject obj, jfloat z_near, jfloat z_far) {
	ClutterFog fog = {z_near, z_far};
	clutter_stage_set_fog(stageFromJava(env,obj), &fog);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Stage_getFog(JNIEnv *env,
		jobject obj) {
	ClutterFog fog;
	clutter_stage_get_fog(stageFromJava(env, obj), &fog);
	return toJavaFog(env, fog.z_near, fog.z_far);
}

JNIEXPORT jint JNICALL Java_org_jclutter_Clone_newInstance(JNIEnv *env,
		jclass cl, jobject source) {
	return (jint) clutter_clone_new(actorFromJava(env, source));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Clone_getSource(JNIEnv *env,
		jobject clone) {
	ClutterActor *a = clutter_clone_get_source(CLUTTER_CLONE(getGPointer(env,
			clone)));
	return findJavaGObject(env, G_OBJECT(a));
}
JNIEXPORT void JNICALL Java_org_jclutter_Clone_setSource(JNIEnv *env, jobject clone, jobject source) {
	clutter_clone_set_source(CLUTTER_CLONE(getGPointer(env, clone)), actorFromJava(env, source));
}

JNIEXPORT jint JNICALL Java_org_jclutter_Texture_newInstance(JNIEnv *env,
		jclass jc) {
	return (jint) clutter_texture_new();
}
JNIEXPORT jint JNICALL Java_org_jclutter_Texture_newFromFile(
		JNIEnv *env, jclass jc, jstring filename) {
	const char *nstring = (*env)->GetStringUTFChars(env, filename, 0);
	ClutterActor *actor = clutter_texture_new_from_file(nstring, NULL);
	if (actor == NULL) jniClutterException(env, "Couldnt load file");
	else return (jint)actor;
	return 0;
}
JNIEXPORT jint JNICALL Java_org_jclutter_Texture_newFromActor(
		JNIEnv *env, jclass jc, jobject actor) {
	return (jint) clutter_texture_new_from_actor(actorFromJava(env, actor));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Texture_setFromFile(JNIEnv *env,
		jobject obj, jstring filename) {
	const char *nstring = (*env)->GetStringUTFChars(env, filename, 0);
	// TODO handle error
	return (jboolean) clutter_texture_set_from_file(textureFromJava(env, obj),
			nstring, NULL);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Texture_setFromRgbData(
		JNIEnv *env, jobject obj, jstring data, jboolean hasAlpha, jint width,
		jint height, jint rowstride, jint bpp, jint textureflags) {
	const guchar *nstring = (guchar *) (*env)->GetStringChars(env, data, 0);
	return (jboolean) clutter_texture_set_from_rgb_data(textureFromJava(env,
			obj), nstring, hasAlpha, width, height, rowstride, bpp,
			textureflags, NULL);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Texture_setFromYuvData(
		JNIEnv *env, jobject obj, jstring data, jint width, jint height,
		jint textureflags) {
	const guchar *nstring = (guchar *) (*env)->GetStringChars(env, data, 0);
	return (jboolean) clutter_texture_set_from_yuv_data(textureFromJava(env,
			obj), nstring, width, height, textureflags, NULL);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Texture_setAreaFromRgbData(
		JNIEnv *env, jobject obj, jstring data, jboolean hasAlpha, jint x,
		jint y, jint width, jint height, jint rowstride, jint bpp, jint flags) {
	const guchar *nstring = (guchar *) (*env)->GetStringChars(env, data, 0);
	return (jboolean) clutter_texture_set_area_from_rgb_data(textureFromJava(
			env, obj), nstring, hasAlpha, x, y, width, height, rowstride, bpp,
			flags, NULL);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Texture_getBaseSize(JNIEnv *env,
		jobject obj) {
	int ret_width;
	int ret_height;
	clutter_texture_get_base_size(textureFromJava(env, obj), &ret_width,
			&ret_height);
	return toJavaDimension(env, ret_width, ret_height);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Texture_getFilterQuality(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_texture_get_filter_quality(textureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Texture_setFilterQuality(JNIEnv *env, jobject obj, jint texturequality) {
	clutter_texture_set_filter_quality(textureFromJava(env,obj), (ClutterTextureQuality)texturequality);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Texture_getMaxTileWaste(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_texture_get_max_tile_waste(textureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Texture_setKeepAspectRatio(JNIEnv *env, jobject obj, jboolean b) {
	clutter_texture_set_keep_aspect_ratio(textureFromJava(env,obj), b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Texture_isKeepAspectRatio(
		JNIEnv *env, jobject obj) {
	return clutter_texture_get_keep_aspect_ratio(textureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Texture_setLoadAsync(JNIEnv *env, jobject obj, jboolean b) {
	clutter_texture_set_load_async(textureFromJava(env,obj), b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Texture_isLoadAsync(JNIEnv *env,
		jobject obj) {
	return clutter_texture_get_load_async(textureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Texture_setLoadDataAsync(JNIEnv *env, jobject obj, jboolean b) {
	clutter_texture_set_load_async(textureFromJava(env,obj), b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Texture_isLoadDataAsync(
		JNIEnv *env, jobject obj) {
	return clutter_texture_get_load_data_async(textureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Texture_setSyncSize(JNIEnv *env, jobject obj, jboolean b) {
	clutter_texture_set_sync_size(textureFromJava(env,obj), b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Texture_isSyncSize(JNIEnv *env,
		jobject obj) {
	return clutter_texture_get_sync_size(textureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Texture_setRepeat(JNIEnv *env, jobject obj, jboolean x, jboolean y) {
	clutter_texture_set_repeat(textureFromJava(env,obj), x, y);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Texture_isRepeatX(JNIEnv *env,
		jobject obj) {
	gboolean value;
	clutter_texture_get_repeat(textureFromJava(env, obj), &value, NULL);
	return value;
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Texture_isRepeatY(JNIEnv *env,
		jobject obj) {
	gboolean value;
	clutter_texture_get_repeat(textureFromJava(env, obj), NULL, &value);
	return value;
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Texture_getCoglMaterial(
		JNIEnv *env, jobject obj) {
	CoglHandle h = clutter_texture_get_cogl_material(textureFromJava(env, obj));
	return createJavaCoglTexture(env, &h);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Texture_getCoglTexture(JNIEnv *env,
		jobject obj) {
	CoglHandle h = clutter_texture_get_cogl_texture(textureFromJava(env, obj));
	return createJavaCoglTexture(env, &h);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Texture_getCoglPixelFormat(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_texture_get_pixel_format(textureFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Texture_setCoglMaterial(JNIEnv *env, jobject obj, jobject h) {
	clutter_texture_set_cogl_material(textureFromJava(env,obj), coglTextureFromJava(env, h));
}
JNIEXPORT void JNICALL Java_org_jclutter_Texture_setCoglTexture(JNIEnv *env, jobject obj, jobject h) {
	clutter_texture_set_cogl_texture(textureFromJava(env,obj), coglTextureFromJava(env, h));
}

JNIEXPORT jint JNICALL Java_org_jclutter_Rectangle_rectangleNew(JNIEnv *env,
		jclass jc) {
	return (jint) clutter_rectangle_new();
}
JNIEXPORT jint JNICALL Java_org_jclutter_Rectangle_rectangleNewWithColor(
		JNIEnv *env, jclass jc, jobject jcolor) {
	ClutterColor color;
	colorFromJava(env, jcolor, &color);
	return (jint) clutter_rectangle_new_with_color(&color);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Rectangle_getColor(JNIEnv *env,
		jobject obj) {
	ClutterColor c;
	clutter_rectangle_get_color(rectangleFromJava(env, obj), &c);
	return toJavaColor(env, &c);
}
JNIEXPORT void JNICALL Java_org_jclutter_Rectangle_setColor(JNIEnv *env, jobject obj, jobject jcolor) {
	ClutterColor color;
	colorFromJava(env, jcolor, &color);
	clutter_rectangle_set_color(rectangleFromJava(env,obj), &color);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Rectangle_getBorderColor(
		JNIEnv *env, jobject obj) {
	ClutterColor c;
	clutter_rectangle_get_border_color(rectangleFromJava(env, obj), &c);
	return toJavaColor(env, &c);
}
JNIEXPORT void JNICALL Java_org_jclutter_Rectangle_setBorderColor(JNIEnv *env, jobject obj, jobject jcolor) {
	ClutterColor color;
	colorFromJava(env, jcolor, &color);
	clutter_rectangle_set_border_color(rectangleFromJava(env,obj), &color);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Rectangle_getBorderWidth(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_rectangle_get_border_width(
			rectangleFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Rectangle_setBorderWidth(JNIEnv *env, jobject obj, jint width) {
	clutter_rectangle_set_border_width(rectangleFromJava(env,obj), width);
}

JNIEXPORT jint JNICALL Java_org_jclutter_Text_newInstance(JNIEnv *env,
		jclass jc) {
	return (jint) clutter_text_new();
}
JNIEXPORT jint JNICALL Java_org_jclutter_Text_newWithText(JNIEnv *env,
		jclass jc, jstring font, jstring text) {
	const char *nfont = (*env)->GetStringUTFChars(env, font, 0);
	const char *ntext = (*env)->GetStringUTFChars(env, text, 0);
	return (jint) clutter_text_new_with_text(nfont, ntext);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Text_newFull(JNIEnv *env, jclass jc,
		jstring font, jstring text, jobject jcolor) {
	const char *nfont = (*env)->GetStringUTFChars(env, font, 0);
	const char *ntext = (*env)->GetStringUTFChars(env, text, 0);
	ClutterColor color;
	colorFromJava(env, jcolor, &color);
	return (jint) clutter_text_new_full(nfont, ntext, &color);
}
JNIEXPORT jstring JNICALL Java_org_jclutter_Text_getText(JNIEnv *env,
		jobject obj) {
	const gchar* str = clutter_text_get_text(textFromJava(env, obj));
	return (*env)->NewStringUTF(env, str);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setText(JNIEnv *env, jobject obj, jstring text) {
	const char *ntext = (*env)->GetStringUTFChars(env, text, 0);
	clutter_text_set_text(textFromJava(env, obj), ntext );
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Text_getColor(JNIEnv *env,
		jobject obj) {
	ClutterColor c;
	clutter_text_get_color(textFromJava(env, obj), &c);
	return toJavaColor(env, &c);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setColor(JNIEnv *env, jobject obj, jobject jcolor) {
	ClutterColor color;
	colorFromJava(env, jcolor, &color);
	clutter_text_set_color(textFromJava(env, obj), &color);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Text_isLineWrap(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_text_get_line_wrap(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setLineWrap(JNIEnv *env, jobject obj, jboolean wrap) {
	clutter_text_set_line_wrap(textFromJava(env, obj), wrap);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Text_isUseMarkup(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_text_get_use_markup(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setUseMarkup(JNIEnv *env, jobject obj, jboolean setting) {
	clutter_text_set_use_markup(textFromJava(env, obj), setting);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Text_isJustify(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_text_get_justify(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setJustify(JNIEnv *env, jobject obj, jboolean justify) {
	clutter_text_set_justify(textFromJava(env, obj), justify);
}
JNIEXPORT jstring JNICALL Java_org_jclutter_Text_getChars(JNIEnv *env,
		jobject obj, jint start, jint end) {
	const gchar *str = clutter_text_get_chars(textFromJava(env, obj), start,
			end);
	return (*env)->NewStringUTF(env, str);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Text_activate(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_text_activate(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setMarkup(JNIEnv *env, jobject obj, jstring m) {
	const char *markup = (*env)->GetStringUTFChars(env, m, 0);
	clutter_text_set_markup(textFromJava(env, obj), markup);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setActivatable(JNIEnv *env, jobject obj, jboolean a) {
	clutter_text_set_activatable(textFromJava(env, obj), a);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Text_isActivatable(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_text_get_activatable(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setEllipsizeMode(JNIEnv *env, jobject obj, jint mode) {
	clutter_text_set_ellipsize(textFromJava(env, obj), (PangoEllipsizeMode)mode);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Text_getEllipsizeMode(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_text_get_ellipsize(textFromJava(env, obj));
}
JNIEXPORT jstring JNICALL Java_org_jclutter_Text_getFontName(JNIEnv *env,
		jobject obj) {
	const char *str = clutter_text_get_font_name(textFromJava(env, obj));
	return (*env)->NewStringUTF(env, str);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setFontName(JNIEnv *env, jobject obj, jstring font) {
	const char *nfont = (*env)->GetStringUTFChars(env, font, 0);
	clutter_text_set_font_name(textFromJava(env, obj), nfont);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setPasswordChar(JNIEnv *env, jobject obj, jchar c) {
	clutter_text_set_password_char(textFromJava(env, obj), c);
}
JNIEXPORT jchar JNICALL Java_org_jclutter_Text_getPasswordChar(JNIEnv *env,
		jobject obj) {
	return (jchar) clutter_text_get_password_char(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setLineAlignment(JNIEnv *env, jobject obj, jint align) {
	clutter_text_set_line_alignment(textFromJava(env, obj), align);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Text_getLineAlignment(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_text_get_line_alignment(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setLineWrapMode(JNIEnv *env, jobject obj, jint wrap) {
	clutter_text_set_line_wrap_mode(textFromJava(env, obj), wrap);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Text_getLineWrapMode(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_text_get_line_wrap_mode(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setMaxLength(JNIEnv *env, jobject obj, jint max) {
	clutter_text_set_max_length(textFromJava(env, obj), max);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Text_getCursorPosition(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_text_get_cursor_position(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setCursorPosition(JNIEnv *env, jobject obj, jint pos) {
	clutter_text_set_cursor_position(textFromJava(env, obj), pos);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_insertUnichar(JNIEnv *env, jobject obj, jchar c) {
	clutter_text_insert_unichar(textFromJava(env, obj), c);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_deleteChars(JNIEnv *env, jobject obj, jint size) {
	clutter_text_delete_chars(textFromJava(env, obj), size);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_insertText(JNIEnv *env, jobject obj, jstring text, jint pos) {
	const char *t = (*env)->GetStringUTFChars(env, text, 0);
	clutter_text_insert_text(textFromJava(env, obj), t, pos);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_deleteText(JNIEnv *env, jobject obj, jint i, jint j) {
	clutter_text_delete_text(textFromJava(env, obj), i , j);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_deleteSelection(JNIEnv *env, jobject obj) {
	clutter_text_delete_selection(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setCursorVisible(JNIEnv *env, jobject obj, jboolean v) {
	clutter_text_set_cursor_visible(textFromJava(env, obj), v);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Text_isCursorVisible(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_text_get_cursor_visible(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setCursorColor(JNIEnv *env, jobject obj, jobject jcolor) {
	ClutterColor color;
	colorFromJava(env, jcolor, &color);
	clutter_text_set_cursor_color(textFromJava(env, obj), &color);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Text_getCursorColor(JNIEnv *env,
		jobject obj) {
	ClutterColor c;
	clutter_text_get_cursor_color(textFromJava(env, obj), &c);
	return toJavaColor(env, &c);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setCursorSize(JNIEnv *env, jobject obj, jint size) {
	clutter_text_set_cursor_size(textFromJava(env, obj), size);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Text_getCursorSize(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_text_get_cursor_size(textFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_Text_getMaxLength(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_text_get_max_length(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setSelectionBound(JNIEnv *env, jobject obj, jint bound) {
	clutter_text_set_selection_bound(textFromJava(env, obj), bound);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Text_getSelectionBound(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_text_get_selection_bound(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setSelectionColor(JNIEnv *env, jobject obj, jobject jcolor) {
	ClutterColor color;
	colorFromJava(env, jcolor, &color);
	clutter_text_set_selection_color(textFromJava(env, obj), &color);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Text_getSelectionColor(JNIEnv *env,
		jobject obj) {
	ClutterColor c;
	clutter_text_get_selection_color(textFromJava(env, obj), &c);
	return toJavaColor(env, &c);
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setSelectable(JNIEnv *env, jobject obj, jboolean b) {
	clutter_text_set_selectable(textFromJava(env, obj), b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Text_isSelectable(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_text_get_selectable(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setEditable(JNIEnv *env, jobject obj, jboolean b) {
	clutter_text_set_editable(textFromJava(env, obj), b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Text_isEditable(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_text_get_editable(textFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Text_setSingleLineMode(JNIEnv *env, jobject obj, jboolean b) {
	clutter_text_set_single_line_mode(textFromJava(env, obj), b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Text_isSingleLineMode(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_text_get_single_line_mode(textFromJava(env, obj));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Text_positionToCoords(JNIEnv *env,
		jobject obj, jint pos) {
	gfloat x, y, h;
	clutter_text_position_to_coords(textFromJava(env, obj), pos, &x, &y, &h);
	return toJavaPoint(env, x, y, h);
}

JNIEXPORT jint JNICALL Java_org_jclutter_Group_groupNew(JNIEnv *env, jclass jc) {
	return (jint) clutter_group_new();
}
JNIEXPORT void JNICALL Java_org_jclutter_Group_removeAll(JNIEnv *env, jobject group) {
	clutter_group_remove_all(groupFromJava(env, group));
}
JNIEXPORT jint JNICALL Java_org_jclutter_Group_getChildrenCount(JNIEnv *env,
		jobject group) {
	return clutter_group_get_n_children(groupFromJava(env, group));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Group_getChild(JNIEnv *env,
		jobject group, jint index) {
	ClutterActor *actor = clutter_group_get_nth_child(
			groupFromJava(env, group), index);
	if (actor == NULL)
		return NULL;
	return findJavaGObject(env, G_OBJECT(actor));
}

JNIEXPORT void JNICALL Java_org_jclutter_Container_addActors(JNIEnv *env, jobject obj, jobjectArray jactors) {
	jint count = (*env)->GetArrayLength(env, jactors);
	if (count == 0) return;
	if (count == 1) {
		jobject actor = (*env)->GetObjectArrayElement(env, jactors, 0);
		clutter_container_add_actor(containerFromJava(env, obj), actorFromJava(env, actor));
		return;
	}
	const ClutterActor *actors[count];
	int i;
	for (i = 0; i < count; i++) {
		jobject actor_obj = (*env)->GetObjectArrayElement(env, jactors, i);
		clutter_container_add_actor(containerFromJava(env, obj), actorFromJava(env, actor_obj));
	}
	//actors[i+1] = NULL;
	//clutter_container_add(containerFromJava(env, obj), actors);
}
JNIEXPORT void JNICALL Java_org_jclutter_Container_lowerChild(JNIEnv *env, jobject obj, jobject actor, jobject sibling) {
	clutter_container_lower_child(containerFromJava(env, obj), actorFromJava(env, actor), actorFromJava(env, sibling));
}
JNIEXPORT void JNICALL Java_org_jclutter_Container_raiseChild(JNIEnv *env, jobject obj, jobject actor, jobject sibling) {
	clutter_container_raise_child(containerFromJava(env, obj), actorFromJava(env, actor), actorFromJava(env, sibling));
}
JNIEXPORT void JNICALL Java_org_jclutter_Container_removeActors(JNIEnv *env, jobject obj, jobjectArray jactors) {
	jint count = (*env)->GetArrayLength(env, jactors);
	if (count == 0) return;
	if (count == 1) {
		jobject actor = (*env)->GetObjectArrayElement(env, jactors, 0);
		clutter_container_remove_actor(containerFromJava(env, obj), actorFromJava(env, actor));
		return;
	}
	//const ClutterActor *actors[count];
	int i;
	for (i = 0; i < count; i++) {
		jobject actor_obj = (*env)->GetObjectArrayElement(env, jactors, i);
		clutter_container_remove_actor(containerFromJava(env, obj), actorFromJava(env, actor_obj));
	}
	//actors[i] = NULL;
	//clutter_container_remove(containerFromJava(env, obj), actors);
}
JNIEXPORT void JNICALL Java_org_jclutter_Container_sortDepthOrder(JNIEnv *env, jobject obj) {
	clutter_container_sort_depth_order(containerFromJava(env, obj));
}
/*
 JNIEXPORT jobject JNICALL Java_org_jclutter_Container_childGet(JNIEnv *env, jobject obj, jobject actor, jstring propertyName)
 {
 const char *nprop = (*env)->GetStringUTFChars(env, propertyName, 0);
 clutter_container_child_get(containerFromJava(env, obj), actorFromJava(env, actor), nprop);
 }*///TODO SET AND GET

JNIEXPORT void JNICALL Java_org_jclutter_Container_childSet(JNIEnv *env, jobject obj, jobject actor, jstring propname, jobject value)
{
	const char *nprop = (*env)->GetStringUTFChars(env, propname, 0);
	clutter_container_child_set(containerFromJava(env, obj), actorFromJava(env, actor), nprop, value, NULL);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Container_findChildByName(
		JNIEnv *env, jobject obj, jstring childName) {
	const char *nname = (*env)->GetStringUTFChars(env, childName, 0);
	ClutterActor *actor = clutter_container_find_child_by_name(
			containerFromJava(env, obj), nname);
	return findJavaGObject(env, G_OBJECT(actor));
}

JNIEXPORT jint JNICALL Java_org_jclutter_animation_Timeline_timelineNew(
		JNIEnv *env, jclass jc, jint durationInSec) {
	return (jint) clutter_timeline_new(durationInSec);
}
// TODO: REMOVE JNIEXPORT jint JNICALL Java_org_jclutter_animation_Timeline_timelineNewForDuration(JNIEnv *env, jclass jc, jint durationInSec)
//{
//	return (jint)clutter_timeline_new_for_duration(durationInSec);
//}
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Timeline_clone(
		JNIEnv *env, jobject obj) {
	ClutterTimeline *t = clutter_timeline_clone(timelineFromJava(env, obj));
	return createJavaTimeline(env, t);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Timeline_getDuration(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_timeline_get_duration(timelineFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_setDuration(JNIEnv *env, jobject obj, jint duration)
{
	clutter_timeline_set_duration(timelineFromJava(env, obj), duration);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_animation_Timeline_isLoop(
		JNIEnv *env, jobject obj) {
	return (jboolean) clutter_timeline_get_loop(timelineFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_setLoop(JNIEnv *env, jobject obj, jboolean loop)
{
	clutter_timeline_set_loop(timelineFromJava(env, obj), loop);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Timeline_getDelay(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_timeline_get_delay(timelineFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_setDelay(JNIEnv *env, jobject obj, jint msecs)
{
	clutter_timeline_set_delay(timelineFromJava(env, obj), msecs);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Timeline_getDirection(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_timeline_get_direction(timelineFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_setDirection(JNIEnv *env, jobject obj, jint timelinedirection)
{
	clutter_timeline_set_direction(timelineFromJava(env, obj), (ClutterTimelineDirection)timelinedirection);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_start(JNIEnv *env, jobject obj)
{
	clutter_timeline_start(timelineFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_pause(JNIEnv *env, jobject obj)
{
	clutter_timeline_pause(timelineFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_stop(JNIEnv *env, jobject obj)
{
	clutter_timeline_stop(timelineFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_rewind(JNIEnv *env, jobject obj)
{
	clutter_timeline_rewind(timelineFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_skip(JNIEnv *env, jobject obj, jint secs)
{
	clutter_timeline_skip(timelineFromJava(env, obj), secs);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_advance(JNIEnv *env, jobject obj, jint secs)
{
	clutter_timeline_advance(timelineFromJava(env, obj), secs);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Timeline_getDelta(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_timeline_get_delta(timelineFromJava(env, obj));
}
JNIEXPORT jdouble JNICALL Java_org_jclutter_animation_Timeline_getProgress(
		JNIEnv *env, jobject obj) {
	return (jdouble) clutter_timeline_get_progress(timelineFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Timeline_getElapsedTime(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_timeline_get_elapsed_time(timelineFromJava(env, obj));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_animation_Timeline_isPlaying(
		JNIEnv *env, jobject obj) {
	return (jboolean) clutter_timeline_is_playing(timelineFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_addMarkerAtTime(JNIEnv *env, jobject obj, jstring name, jint msecs)
{
	const char *nname = (*env)->GetStringUTFChars(env, name, 0);
	clutter_timeline_add_marker_at_time(timelineFromJava(env, obj), nname, msecs);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_animation_Timeline_hasMarker(
		JNIEnv *env, jobject obj, jstring name) {
	const char *nname = (*env)->GetStringUTFChars(env, name, 0);
	return (jboolean) clutter_timeline_has_marker(timelineFromJava(env, obj),
			nname);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_removeMarker(JNIEnv *env, jobject obj, jstring name)
{
	const char *nname = (*env)->GetStringUTFChars(env, name, 0);
	clutter_timeline_remove_marker(timelineFromJava(env, obj), nname);
}
/*
 JNIEXPORT jobjectArray JNICALL Java_org_jclutter_animation_Timeline_listMarkers(JNIEnv *env, jobject obj)
 {
 clutter_timeline_list_markers(timelineFromJava(env, obj));
 }*/
JNIEXPORT void JNICALL Java_org_jclutter_animation_Timeline_advanceToMarker(JNIEnv *env, jobject obj, jstring name)
{
	const char *nname = (*env)->GetStringUTFChars(env, name, 0);
	clutter_timeline_advance_to_marker(timelineFromJava(env, obj), nname);
}

JNIEXPORT jint JNICALL Java_org_jclutter_animation_Score_scoreNew(JNIEnv *env,
		jclass jc) {
	return (jint) clutter_score_new();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_animation_Score_isLoop(
		JNIEnv *env, jobject obj) {
	return (jboolean) clutter_score_get_loop(scoreFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Score_setLoop(JNIEnv *env, jobject obj, jboolean loop)
{
	clutter_score_set_loop(scoreFromJava(env, obj), loop);
}
JNIEXPORT jlong JNICALL Java_org_jclutter_animation_Score_append(JNIEnv *env,
		jobject obj, jobject parent, jobject timeline) {
	// parent can be null
	if (parent != NULL) {
		return (jlong) clutter_score_append(scoreFromJava(env, obj),
				timelineFromJava(env, parent), timelineFromJava(env, timeline));
	} else {
		return (jlong) clutter_score_append(scoreFromJava(env, obj), NULL,
				timelineFromJava(env, timeline));
	}
}
JNIEXPORT jlong JNICALL Java_org_jclutter_animation_Score_appendAtMarker(
		JNIEnv *env, jobject obj, jobject parent, jstring markerName,
		jobject timeline) {
	const char *nname = (*env)->GetStringUTFChars(env, markerName, 0);
	return (jlong) clutter_score_append_at_marker(scoreFromJava(env, obj),
			timelineFromJava(env, parent), nname, timelineFromJava(env,
					timeline));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Score_remove(JNIEnv *env, jobject obj, jlong id)
{
	clutter_score_remove(scoreFromJava(env, obj), id);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Score_removeAll(JNIEnv *env, jobject obj)
{
	clutter_score_remove_all(scoreFromJava(env, obj));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Score_getTimeline(
		JNIEnv *env, jobject obj, jlong id) {
	ClutterTimeline *t =
			clutter_score_get_timeline(scoreFromJava(env, obj), id);
	return createJavaTimeline(env, t);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Score_listTimelines(
		JNIEnv *env, jobject obj) {
	/// TODO list
	return NULL;
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Score_start(JNIEnv *env, jobject obj)
{
	clutter_score_start(scoreFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Score_pause(JNIEnv *env, jobject obj)
{
	clutter_score_pause(scoreFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Score_stop(JNIEnv *env, jobject obj)
{
	clutter_score_stop(scoreFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Score_rewind(JNIEnv *env, jobject obj)
{
	clutter_score_rewind(scoreFromJava(env, obj));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_animation_Score_isPlaying(
		JNIEnv *env, jobject obj) {
	return (jboolean) clutter_score_is_playing(scoreFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_ScaleBehaviour_behaviourScaleNew(
		JNIEnv *env, jclass jc, jobject alpha, jdouble x_scale_start,
		jdouble y_scale_start, jdouble x_scale_end, jdouble y_scale_end) {
	return (jint) clutter_behaviour_scale_new(alphaFromJava(env, alpha),
			x_scale_start, y_scale_start, x_scale_end, y_scale_end);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_ScaleBehaviour_setBounds(JNIEnv *env, jobject obj, jdouble x_scale_start, jdouble y_scale_start, jdouble x_scale_end, jdouble y_scale_end)
{
	clutter_behaviour_scale_set_bounds(behaviourScaleFromJava(env, obj), x_scale_start, y_scale_start, x_scale_end, y_scale_end);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_RotateBehaviour_behaviourRotateNew(
		JNIEnv *env, jclass jc, jobject alpha, jint rotateaxis,
		jint rotatedirection, jdouble start, jdouble end) {
	return (jint) clutter_behaviour_rotate_new(alphaFromJava(env, alpha),
			(ClutterRotateAxis) rotateaxis,
			(ClutterRotateDirection) rotatedirection, start, end);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_RotateBehaviour_setAxis(JNIEnv *env, jobject obj, jint rotateaxis)
{
	clutter_behaviour_rotate_set_axis(behaviourRotateFromJava(env, obj), (ClutterRotateAxis)rotateaxis);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_RotateBehaviour_getAxis(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_behaviour_rotate_get_axis(behaviourRotateFromJava(
			env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_RotateBehaviour_setDirection(JNIEnv *env, jobject obj, jint rotatedirection)
{
	clutter_behaviour_rotate_set_direction(behaviourRotateFromJava(env, obj), (ClutterRotateDirection)rotatedirection);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_RotateBehaviour_getDirection(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_behaviour_rotate_get_direction(
			behaviourRotateFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_RotateBehaviour_setBounds(JNIEnv *env, jobject obj, jdouble start, jdouble end)
{
	clutter_behaviour_rotate_set_bounds(behaviourRotateFromJava(env, obj), start, end);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_RotateBehaviour_setCenter(JNIEnv *env, jobject obj, jint x, jint y, jint z)
{
	clutter_behaviour_rotate_set_center(behaviourRotateFromJava(env, obj), x, y, z);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_RotateBehaviour_getCenter(
		JNIEnv *env, jobject obj) {
	gint ret_x;
	gint ret_y;
	gint ret_z;
	clutter_behaviour_rotate_get_center(behaviourRotateFromJava(env, obj),
			&ret_x, &ret_y, &ret_z);
	return toJavaPoint(env, ret_x, ret_y, ret_z);
}

JNIEXPORT jint JNICALL Java_org_jclutter_animation_PathBehaviour_behaviourPathNew(
		JNIEnv *env, jclass jc, jobject jalpha, jobject jpath) {
	return (jint) clutter_behaviour_path_new(alphaFromJava(env, jalpha),
			pathFromJava(env, jpath));
}

JNIEXPORT jint JNICALL Java_org_jclutter_animation_PathBehaviour_behaviourPathNewWithKnots(
		JNIEnv *env, jclass jc, jobject alpha, jobjectArray jknots) {
	//int count = (*env)->GetArrayLength(env, jknots);
	//return (jint)clutter_behaviour_path_new_with_knots(alphaFromJava(env, alpha), knotsFromJava(env, jknots), count);
	return 0;
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_OpacityBehaviour_behaviourOpacityNew(
		JNIEnv *env, jclass jc, jobject alpha, jbyte start, jbyte end) {
	return (jint) clutter_behaviour_opacity_new(alphaFromJava(env, alpha),
			start, end);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_OpacityBehaviour_setBounds(JNIEnv *env, jobject obj, jbyte start, jbyte end)
{
	clutter_behaviour_opacity_set_bounds(behaviourOpacityFromJava(env, obj), start, end);
}
/*
 JNIEXPORT jobject JNICALL Java_org_jclutter_animation_OpacityBehaviour_getBounds(JNIEnv *env, jobject obj)
 {

 clutter_behaviour_opacity_get_bounds(CLUTTER_BEHAVIOUR_OPACITY(obj_ptr));
 }*/

JNIEXPORT jint JNICALL Java_org_jclutter_animation_EllipseBehaviour_behaviourEllipseNew(
		JNIEnv *env, jclass jc, jobject alpha, jint x, jint y, jint width,
		jint height, jint rotatedirection, jdouble start, jdouble end) {
	return (jint) clutter_behaviour_ellipse_new(alphaFromJava(env, alpha), x,
			y, width, height, (ClutterRotateDirection) rotatedirection, start,
			end);
}

JNIEXPORT void JNICALL Java_org_jclutter_animation_EllipseBehaviour_setCenter(JNIEnv *env, jobject obj, jint x, jint y)
{
	clutter_behaviour_ellipse_set_center(behaviourEllipseFromJava(env, obj), x, y);
}
/*
 JNIEXPORT jobject JNICALL Java_org_jclutter_animation_EllipseBehaviour_getCenter(JNIEnv *env, jobject obj)
 {
 gint ret_x;
 gint ret_y;
 clutter_behaviour_ellipse_get_center(behaviourEllipseFromJava(env, obj), &ret_x, &ret_y);
 return toJavaPoint(env, ret_x, ret_y, 0);
 }*/

JNIEXPORT void JNICALL Java_org_jclutter_animation_EllipseBehaviour_setAngleStart(JNIEnv *env, jobject obj, jdouble angleStart)
{
	clutter_behaviour_ellipse_set_angle_start(behaviourEllipseFromJava(env, obj), angleStart);
}

JNIEXPORT jdouble JNICALL Java_org_jclutter_animation_EllipseBehaviour_getAngleStart(
		JNIEnv *env, jobject obj) {
	return (jdouble) clutter_behaviour_ellipse_get_angle_start(
			behaviourEllipseFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_animation_EllipseBehaviour_setAngleEnd(JNIEnv *env, jobject obj, jdouble angleEnd)
{
	clutter_behaviour_ellipse_set_angle_end(behaviourEllipseFromJava(env, obj), angleEnd);
}

JNIEXPORT jdouble JNICALL Java_org_jclutter_animation_EllipseBehaviour_getAngleEnd(
		JNIEnv *env, jobject obj) {
	return (jdouble) clutter_behaviour_ellipse_get_angle_end(
			behaviourEllipseFromJava(env, obj));
}

JNIEXPORT void JNICALL Java_org_jclutter_animation_EllipseBehaviour_setWidth(JNIEnv *env, jobject obj, jfloat width)
{
	clutter_behaviour_ellipse_set_width(behaviourEllipseFromJava(env, obj), width);
}

JNIEXPORT jfloat JNICALL Java_org_jclutter_animation_EllipseBehaviour_getWidth(
		JNIEnv *env, jobject obj) {
	return (jfloat) clutter_behaviour_ellipse_get_width(
			behaviourEllipseFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_EllipseBehaviour_setHeight(JNIEnv *env, jobject obj, jfloat height)
{
	clutter_behaviour_ellipse_set_height(behaviourEllipseFromJava(env, obj), height);
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_animation_EllipseBehaviour_getHeight(
		JNIEnv *env, jobject obj) {
	return (jfloat) clutter_behaviour_ellipse_get_height(
			behaviourEllipseFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_EllipseBehaviour_setDirection(JNIEnv *env, jobject obj, jint direction)
{
	clutter_behaviour_ellipse_set_direction(behaviourEllipseFromJava(env, obj), direction);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_EllipseBehaviour_getDirection(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_behaviour_ellipse_get_direction(
			behaviourEllipseFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_EllipseBehaviour_setTilt(JNIEnv *env, jobject obj, jdouble x, jdouble y, jdouble z){
	clutter_behaviour_ellipse_set_tilt(behaviourEllipseFromJava(env, obj), x, y, z);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_EllipseBehaviour_setAngleTilt(JNIEnv *env, jobject obj, jint axis, jdouble angle){
	clutter_behaviour_ellipse_set_angle_tilt(behaviourEllipseFromJava(env, obj), axis, angle);
}

JNIEXPORT jint JNICALL Java_org_jclutter_animation_DepthBehaviour_depthNew(
		JNIEnv *env, jclass jc, jobject alpha, jint start, jint end) {
	return (jint) clutter_behaviour_depth_new(alphaFromJava(env, alpha), start,
			end);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_DepthBehaviour_setBounds(JNIEnv *env, jobject obj, jint start, jint end){
	clutter_behaviour_depth_set_bounds(behaviourDepthFromJava(env, obj), start, end);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Behaviour_apply(JNIEnv *env, jobject obj, jobject actor){
	clutter_behaviour_apply(behaviourFromJava(env, obj), actorFromJava(env, actor));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Behaviour_remove(JNIEnv *env, jobject obj, jobject actor){
	clutter_behaviour_remove(behaviourFromJava(env, obj), actorFromJava(env, actor));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Behaviour_removeAll(JNIEnv *env, jobject obj){
	clutter_behaviour_remove_all(behaviourFromJava(env, obj));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_animation_Behaviour_isApplied(
		JNIEnv *env, jobject obj, jobject actor) {
	return (jboolean) clutter_behaviour_is_applied(behaviourFromJava(env, obj),
			actorFromJava(env, actor));
}

JNIEXPORT jint JNICALL Java_org_jclutter_animation_Behaviour_getActorCount(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_behaviour_get_n_actors(behaviourFromJava(env, obj));
}

/** TODO: same as below
 JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Behaviour_getActors(JNIEnv *env, jobject obj)
 {

 clutter_behaviour_get_actors(behaviourFromJava(env, obj));
 }*/
/** TODO : find type and convert to actor
 JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Behaviour_getActorAt(JNIEnv *env, jobject obj, jint index)
 {

 clutter_behaviour_get_nth_actor(behaviourFromJava(env, obj), index);
 }*/
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Behaviour_getAlpha(JNIEnv *env, jobject obj) {
	ClutterAlpha *alpha = clutter_behaviour_get_alpha(behaviourFromJava(env, obj));
	return findJavaGObject(env, G_OBJECT(alpha));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Behaviour_setAlpha(JNIEnv *env, jobject obj, jobject alpha)
{
	clutter_behaviour_set_alpha(behaviourFromJava(env, obj), alphaFromJava(env, alpha));
}

JNIEXPORT jint JNICALL Java_org_jclutter_animation_Alpha_alphaNew(JNIEnv *env,
		jclass jc) {
	return (jint) clutter_alpha_new();
}

JNIEXPORT jint JNICALL Java_org_jclutter_animation_Alpha_alphaNewFull(
		JNIEnv *env, jclass jc, jobject timeline, jint mode) {
	return (jint) clutter_alpha_new_full(timelineFromJava(env, timeline), mode);
}

JNIEXPORT jint JNICALL Java_org_jclutter_animation_Alpha_getAlpha(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_alpha_get_alpha(alphaFromJava(env, obj));
}

/*JNIEXPORT void JNICALL Java_org_jclutter_animation_Alpha_setFunc(JNIEnv *env, jobject obj, jint alphafunc)
 {
 clutter_alpha_set_func(alphaFromJava(env, obj), alphafunc, NULL, NULL);
 }*/

JNIEXPORT void JNICALL Java_org_jclutter_animation_Alpha_setTimeline(JNIEnv *env, jobject obj, jobject timeline)
{
	clutter_alpha_set_timeline(alphaFromJava(env, obj), timelineFromJava(env, timeline));
}

JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Alpha_getTimeline(
		JNIEnv *env, jobject obj) {
	ClutterTimeline *t = clutter_alpha_get_timeline(alphaFromJava(env, obj));
	return createJavaTimeline(env, t);
}

JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_setActor(JNIEnv *env, jobject anim, jobject actor) {
	clutter_animation_set_object(animationFromJava(env, anim), G_OBJECT(actorFromJava(env, actor)));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Animation_getActor(
		JNIEnv *env, jobject anim) {
	ClutterActor *a = (ClutterActor *) clutter_animation_get_object(
			animationFromJava(env, anim));
	return toJavaActor(env, a);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Animation_newInstance(
		JNIEnv *env, jclass clazz) {
	return (jint) clutter_animation_new();
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_setNativeMode(JNIEnv *env, jobject anim, jint mode) {
	clutter_animation_set_mode(animationFromJava(env, anim), mode);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Animation_getNativeMode(
		JNIEnv *env, jobject anim) {
	return clutter_animation_get_mode(animationFromJava(env, anim));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_setDuration(JNIEnv *env, jobject anim, jint msecs) {
	clutter_animation_set_duration(animationFromJava(env, anim), msecs);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Animation_getDuration(
		JNIEnv *env, jobject anim) {
	return clutter_animation_get_duration(animationFromJava(env, anim));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_setLoop(JNIEnv *env, jobject anim, jboolean loop) {
	clutter_animation_set_loop(animationFromJava(env, anim), loop);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_animation_Animation_isLoop(
		JNIEnv *env, jobject anim) {
	return clutter_animation_get_loop(animationFromJava(env, anim));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_setTimeline(JNIEnv *env, jobject anim, jobject timeline) {
	clutter_animation_set_timeline(animationFromJava(env, anim), timelineFromJava(env, timeline));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Animation_getTimeline(
		JNIEnv *env, jobject anim) {
	ClutterTimeline *t = clutter_animation_get_timeline(animationFromJava(env, anim));
	return createJavaTimeline(env, t);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_setAlpha(JNIEnv *env, jobject anim, jobject jalpha) {
	clutter_animation_set_alpha(animationFromJava(env, anim), alphaFromJava(env, jalpha));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Animation_getAlpha(
		JNIEnv *env, jobject anim) {
	ClutterAlpha *alpha = clutter_animation_get_alpha(animationFromJava(env,
			anim));
	return toJavaAlpha(env, alpha);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_completed(JNIEnv *env, jobject anim) {
	clutter_animation_completed(animationFromJava(env, anim));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_bindDouble(JNIEnv *env, jobject anim, jstring prop, jdoubleArray val) {
	const char *nprop = (*env)->GetStringUTFChars(env, prop, 0);
	jint count = (*env)->GetArrayLength(env, val);
	jdouble *arr = (*env)->GetDoubleArrayElements(env, val, 0);
	if (count == 1) {
		GValue v = {0};
		g_value_init(&v, G_TYPE_DOUBLE);
		g_value_set_double(&v, arr[0]);
		clutter_animation_bind(animationFromJava(env, anim), nprop, &v);
	}
	(*env)->ReleaseDoubleArrayElements(env, val, arr, 0);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_bindBoolean(JNIEnv *env, jobject anim, jstring prop, jbooleanArray val) {
	const char *nprop = (*env)->GetStringUTFChars(env, prop, 0);
	jint count = (*env)->GetArrayLength(env, val);
	jboolean *arr = (*env)->GetBooleanArrayElements(env, val, 0);
	if (count == 1) {
		GValue v = {0};
		g_value_init(&v, G_TYPE_BOOLEAN);
		g_value_set_boolean(&v, arr[0]);
		clutter_animation_bind(animationFromJava(env, anim), nprop, &v);
	}
	(*env)->ReleaseBooleanArrayElements(env, val, arr, 0);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_bindInteger(JNIEnv *env, jobject anim, jstring prop, jintArray val) {
	const char *nprop = (*env)->GetStringUTFChars(env, prop, 0);
	jint count = (*env)->GetArrayLength(env, val);
	jint *arr = (*env)->GetIntArrayElements(env, val, 0);
	if (count == 1) {
		GValue v = {0};
		g_value_init(&v, G_TYPE_INT);
		g_value_set_int(&v, arr[0]);
		clutter_animation_bind(animationFromJava(env, anim), nprop, &v);
	}
	(*env)->ReleaseIntArrayElements(env, val, arr, 0);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_bindFloat(JNIEnv *env, jobject anim, jstring prop, jfloatArray val) {
	const char *nprop = (*env)->GetStringUTFChars(env, prop, 0);
	jint count = (*env)->GetArrayLength(env, val);
	jfloat *arr = (*env)->GetFloatArrayElements(env, val, 0);
	LOGI("bind float :%i", count);
	if (count == 1) {
		GValue v = {0};
		g_value_init (&v, G_TYPE_FLOAT);
		g_value_set_float(&v, arr[0]);
		clutter_animation_bind(animationFromJava(env, anim), nprop, &v);
	}
	(*env)->ReleaseFloatArrayElements(env, val, arr, 0);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_animation_Animation_hasProperty(
		JNIEnv *env, jobject anim, jstring prop) {
	const char *nprop = (*env)->GetStringUTFChars(env, prop, 0);
	jboolean b = clutter_animation_has_property(animationFromJava(env, anim),
			nprop);
	return b;
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animation_unbindProperty(JNIEnv *env, jobject anim, jstring prop) {
	const char *nprop = (*env)->GetStringUTFChars(env, prop, 0);
	clutter_animation_unbind_property(animationFromJava(env, anim), nprop);
}

JNIEXPORT jint JNICALL Java_org_jclutter_animation_Path_getLength(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_path_get_length(pathFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_clear(JNIEnv *env, jobject obj) {
	clutter_path_clear(pathFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Path_pathNew(JNIEnv *env,
		jclass cl) {
	return (jint) clutter_path_new();
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Path_pathNewWithDescription(
		JNIEnv *env, jclass cl, jstring string) {
	const char *desc = (*env)->GetStringUTFChars(env, string, 0);
	return (jint) clutter_path_new_with_description(desc);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_addMoveTo(JNIEnv *env, jobject obj, jint x, jint y) {
	clutter_path_add_move_to(pathFromJava(env, obj), x, y);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_addRelMoveTo(JNIEnv *env, jobject obj, jint x, jint y) {
	clutter_path_add_rel_move_to(pathFromJava(env, obj), x, y);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_addLineTo(JNIEnv *env, jobject obj, jint x, jint y) {
	clutter_path_add_line_to(pathFromJava(env, obj), x, y);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_addRelLineTo(JNIEnv *env, jobject obj, jint x, jint y) {
	clutter_path_add_rel_line_to(pathFromJava(env, obj), x, y);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_addCurveTo(JNIEnv *env, jobject obj, jint x1, jint y1, jint x2, jint y2, jint x3, jint y3) {
	clutter_path_add_curve_to(pathFromJava(env, obj), x1, y1, x2, y2, x3, y3);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_addRelCurveTo(JNIEnv *env, jobject obj, jint x1, jint y1, jint x2, jint y2, jint x3, jint y3) {
	clutter_path_add_rel_curve_to(pathFromJava(env, obj), x1, y1, x2, y2, x3, y3);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_addClose(JNIEnv *env, jobject obj) {
	clutter_path_add_close(pathFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_addString(JNIEnv *env, jobject obj, jstring string) {
	const char *str = (*env)->GetStringUTFChars(env, string, 0);
	clutter_path_add_string(pathFromJava(env, obj), str);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_addNode(JNIEnv *env, jobject obj, jobject node) {
	clutter_path_add_node(pathFromJava(env, obj), pathNodeFromJava(env, node));
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Path_getNodeCount(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_path_get_n_nodes(pathFromJava(env, obj));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Path_getNodeAt(
		JNIEnv *env, jobject obj, jint index) {
	ClutterPathNode *node;
	clutter_path_get_node(pathFromJava(env, obj), index, node);
	return toJavaPathNode(env, node);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Path_getNodes(
		JNIEnv *env, jobject obj) {
	//clutter_path_get_nodes(pathFromJava(env, obj)); TODO
	return NULL;
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_insertNodeAt(JNIEnv *env, jobject obj, jint index, jobject node) {
	clutter_path_insert_node(pathFromJava(env, obj), index, pathNodeFromJava(env, node));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_removeNodeAt(JNIEnv *env, jobject obj, jint index) {
	clutter_path_remove_node(pathFromJava(env, obj), index);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_replaceNodeAt(JNIEnv *env, jobject obj, jint index, jobject node) {
	clutter_path_replace_node(pathFromJava(env, obj), index, pathNodeFromJava(env, node));
}
JNIEXPORT jstring JNICALL Java_org_jclutter_animation_Path_getDescription(
		JNIEnv *env, jobject obj) {
	return (*env)->NewStringUTF(env, clutter_path_get_description(pathFromJava(
			env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Path_setDescription(JNIEnv *env, jobject obj, jstring string) {
	const char *desc = (*env)->GetStringUTFChars(env, string, 0);
	clutter_path_set_description(pathFromJava(env, obj), desc);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Path_getPosition(
		JNIEnv *env, jobject obj, jdouble progress) {
	// TODO clutter_path_get_position(pathFromJava(env, obj), progress);
	return NULL;
}

JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Animator_run(JNIEnv *env, jobject obj){
ClutterTimeline *t = clutter_animator_run(CLUTTER_ANIMATOR(getGPointer(env, obj)));
jobject jtimeline = findJavaGObject(env, G_OBJECT(t));
if (jtimeline != NULL) return jtimeline;
return createJavaTimeline(env, t);
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Animator_newInstance(JNIEnv *env, jclass cl){
return (jint)clutter_animator_new();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_animation_Animator_getTimeline(JNIEnv *env, jobject obj){
ClutterTimeline *t = clutter_animator_get_timeline(CLUTTER_ANIMATOR(getGPointer(env, obj)));
jobject jtimeline = findJavaGObject(env, G_OBJECT(t));
if (jtimeline != NULL) return jtimeline;
return createJavaTimeline(env, t);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animator_setTimeline(JNIEnv *env, jobject obj, jobject jtimeline){
clutter_animator_set_timeline(CLUTTER_ANIMATOR(getGPointer(env, obj)), timelineFromJava(env, jtimeline));
}
JNIEXPORT jint JNICALL Java_org_jclutter_animation_Animator_getDuration(JNIEnv *env, jobject obj){
return (jint)clutter_animator_get_duration(CLUTTER_ANIMATOR(getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animator_setDuration(JNIEnv *env, jobject obj, jint duration){
clutter_animator_set_duration(CLUTTER_ANIMATOR(getGPointer(env, obj)), duration);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animator_setEaseIn(JNIEnv *env, jobject obj, jobject actor, jstring prop, jboolean b){
	const char *nstr = (*env)->GetStringUTFChars(env, prop, 0);
	clutter_animator_set_ease_in(CLUTTER_ANIMATOR(getGPointer(env, obj)), getGPointer(env, obj), nstr, b);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_animation_Animator_isEaseIn(JNIEnv *env, jobject obj, jobject actor, jstring prop){
	const char *nstr = (*env)->GetStringUTFChars(env, prop, 0);
	return (jboolean)clutter_animator_is_ease_in(CLUTTER_ANIMATOR(getGPointer(env, obj)), getGPointer(env, obj), nstr);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animator_setKeyInt(JNIEnv *env, jobject obj, jobject actor, jstring prop, jint mode, jdouble progress, jint val){
	const char *nstr = (*env)->GetStringUTFChars(env, prop, 0);
	GValue gval = {0};
	g_value_init(&gval, G_TYPE_INT);
	g_value_set_int(&gval, val);
	clutter_animator_set_key(CLUTTER_ANIMATOR(getGPointer(env, obj)), getGPointer(env, obj), nstr, mode, progress, &gval);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animator_setKeyFloat(JNIEnv *env, jobject obj, jobject actor, jstring prop, jint mode, jdouble progress, jfloat val){
	const char *nstr = (*env)->GetStringUTFChars(env, prop, 0);
	GValue gval = {0};
	g_value_init(&gval, G_TYPE_FLOAT);
	g_value_set_float(&gval, val);
	clutter_animator_set_key(CLUTTER_ANIMATOR(getGPointer(env, obj)), getGPointer(env, obj), nstr, mode, progress, &gval);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animator_setKeyDouble(JNIEnv *env, jobject obj, jobject actor, jstring prop, jint mode, jdouble progress, jdouble val){
	const char *nstr = (*env)->GetStringUTFChars(env, prop, 0);
	GValue gval = {0};
	g_value_double(&gval, G_TYPE_DOUBLE);
	g_value_set_double(&gval, val);
	clutter_animator_set_key(CLUTTER_ANIMATOR(getGPointer(env, obj)), getGPointer(env, obj), nstr, mode, progress, &gval);
}
JNIEXPORT void JNICALL Java_org_jclutter_animation_Animator_setKeyBoolean(JNIEnv *env, jobject obj, jobject actor, jstring prop, jint mode, jdouble progress, jboolean val){
	const char *nstr = (*env)->GetStringUTFChars(env, prop, 0);
	GValue gval = {0};
	g_value_init(&gval, G_TYPE_BOOLEAN);
	g_value_set_boolean(&gval, val);
	clutter_animator_set_key(CLUTTER_ANIMATOR(getGPointer(env, obj)), getGPointer(env, obj), nstr, mode, progress, &gval);
}


JNIEXPORT jobject JNICALL Java_org_jclutter_util_Units_fromMillimeters(
		JNIEnv *env, jclass cl, jfloat mm) {
	ClutterUnits *units;
	clutter_units_from_mm(units, mm);
	return toJavaUnits(env, units);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_util_Units_fromPoints(JNIEnv *env,
		jclass cl, jfloat pts) {
	ClutterUnits *units;
	clutter_units_from_pt(units, pts);
	return toJavaUnits(env, units);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_util_Units_fromEm(JNIEnv *env,
		jclass cl, jfloat em) {
	ClutterUnits *units;
	clutter_units_from_em(units, em);
	return toJavaUnits(env, units);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_util_Units_fromEmForFont(
		JNIEnv *env, jclass cl, jstring font, jfloat em) {
	const char *nfont = (*env)->GetStringUTFChars(env, font, 0);
	ClutterUnits *units;
	clutter_units_from_em_for_font(units, nfont, em);
	return toJavaUnits(env, units);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_util_Units_fromPixels(JNIEnv *env,
		jclass cl, jint pix) {
	ClutterUnits *units;
	clutter_units_from_pixels(units, pix);
	return toJavaUnits(env, units);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_util_Units_fromString(JNIEnv *env,
		jclass cl, jstring str) {
	const char *nstr = (*env)->GetStringUTFChars(env, str, 0);
	ClutterUnits *units;
	if (clutter_units_from_string(units, nstr))
		return toJavaUnits(env, units);
	else
		return NULL;
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_util_Units_toPixels(JNIEnv *env,
		jobject units) {
	return clutter_units_to_pixels(unitsFromJava(env, units));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_util_Units_copy(JNIEnv *env,
		jobject units) {
	return toJavaUnits(env, clutter_units_copy(unitsFromJava(env, units)));
}
JNIEXPORT void JNICALL Java_org_jclutter_util_Units_free(JNIEnv *env, jobject units) {
	clutter_units_free(unitsFromJava(env, units));
}
JNIEXPORT jint JNICALL Java_org_jclutter_util_Units_getUnitType(JNIEnv *env,
		jobject units) {
	return clutter_units_get_unit_type(unitsFromJava(env, units));
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_util_Units_getUnitValue(JNIEnv *env,
		jobject units) {
	return clutter_units_get_unit_value(unitsFromJava(env, units));
}
JNIEXPORT jstring JNICALL Java_org_jclutter_util_Units_toString(JNIEnv *env,
		jobject units) {
	return (*env)->NewStringUTF(env, clutter_units_to_string(unitsFromJava(env,
			units)));
}

JNIEXPORT jint JNICALL Java_org_jclutter_Shader_shaderNew(JNIEnv *env,
		jclass jc) {
	return (int) clutter_shader_new();
}
JNIEXPORT void JNICALL Java_org_jclutter_Shader_setVertexSource(JNIEnv *env, jobject obj, jstring data) {
	const char *ndata = (*env)->GetStringUTFChars(env, data, 0);
	clutter_shader_set_vertex_source(shaderFromJava(env, obj), ndata, 0);
}
JNIEXPORT jstring JNICALL Java_org_jclutter_Shader_getVertexSource(JNIEnv *env,
		jobject obj) {
	const gchar *s = clutter_shader_get_vertex_source(shaderFromJava(env, obj));
	return (*env)->NewStringUTF(env, s);
}
JNIEXPORT void JNICALL Java_org_jclutter_Shader_setFragmentSource(JNIEnv *env, jobject obj, jstring data) {
	const char *ndata = (*env)->GetStringUTFChars(env, data, 0);
	clutter_shader_set_fragment_source(shaderFromJava(env, obj), ndata, 0);
}
JNIEXPORT jstring JNICALL Java_org_jclutter_Shader_getFragmentSource(
		JNIEnv *env, jobject obj) {
	const gchar *s = clutter_shader_get_fragment_source(
			shaderFromJava(env, obj));
	return (*env)->NewStringUTF(env, s);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Shader_compile(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_shader_compile(shaderFromJava(env, obj), NULL);
}
JNIEXPORT void JNICALL Java_org_jclutter_Shader_release(JNIEnv *env, jobject obj) {
	clutter_shader_release(shaderFromJava(env, obj));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Shader_isCompiled(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_shader_is_compiled(shaderFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Shader_setEnabled(JNIEnv *env, jobject obj, jboolean enabled) {
	clutter_shader_set_is_enabled(shaderFromJava(env, obj), enabled);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_Shader_isEnabled(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_shader_get_is_enabled(shaderFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Shader_setUniformInt(JNIEnv *env, jobject obj, jstring name, jint value) {
	// TODO const char *nname = (*env)->GetStringUTFChars(env, name, 0);
	//clutter_shader_set_uniform(shaderFromJava(env, obj), nname, value);
}
JNIEXPORT void JNICALL Java_org_jclutter_Shader_setUniformFloat(JNIEnv *env, jobject obj, jstring name, jfloat value) {
	//const char *nname = (*env)->GetStringUTFChars(env, name, 0);
	//clutter_shader_set_uniform(shaderFromJava(env, obj), nname, value);
}
JNIEXPORT void JNICALL Java_org_jclutter_Shader_setUniformFloatArray(JNIEnv *env, jobject obj, jstring name, jfloatArray value) {
	//const char *nname = (*env)->GetStringUTFChars(env, name, 0);
	//clutter_shader_set_uniform(shaderFromJava(env, obj), nname, value);
}

JNIEXPORT jint JNICALL Java_org_jclutter_events_Event_getType(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_event_type(eventFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_events_Event_getTime(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_event_get_time(eventFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_events_Event_getFlag(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_event_get_flags(eventFromJava(env, obj));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_events_Event_getStage(JNIEnv *env,
		jobject obj) {
	ClutterStage *stage = clutter_event_get_stage(eventFromJava(env, obj));
	return findJavaGObject(env, G_OBJECT(stage));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_events_Event_getSource(JNIEnv *env,
		jobject obj) {
	ClutterActor *actor = clutter_event_get_source(eventFromJava(env, obj));
	return findJavaGObject(env, G_OBJECT(actor));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_events_Event_getCoords(JNIEnv *env,
		jobject obj) {
	gfloat x;
	gfloat y;
	clutter_event_get_coords(eventFromJava(env, obj), &x, &y);
	return toJavaPoint(env, x, y, 0);
}
JNIEXPORT void JNICALL Java_org_jclutter_events_Event_free(JNIEnv *env, jobject obj)
{
	clutter_event_free(eventFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_events_Event_getModifierState(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_event_get_state(eventFromJava(env, obj));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_events_Event_eventsPending(
		JNIEnv *env, jclass jc) {
	return (jboolean) clutter_events_pending();
}
JNIEXPORT jint JNICALL Java_org_jclutter_events_Event_getDeviceId(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_event_get_device_id(eventFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_events_Event_getClickCount(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_event_get_click_count(eventFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_events_Event_getButton(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_event_get_button(eventFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_events_Event_getKeySymbol(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_event_get_key_symbol(eventFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_events_Event_getKeyCode(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_event_get_key_code(eventFromJava(env, obj));
}
JNIEXPORT jchar JNICALL Java_org_jclutter_events_Event_getKeyUnicode(
		JNIEnv *env, jobject obj) {
	return (jchar) clutter_event_get_key_unicode(eventFromJava(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_events_Event_getDirection(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_event_get_scroll_direction(eventFromJava(env, obj));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_events_Event_getRelated(
		JNIEnv *env, jobject obj) {
	ClutterActor *actor = clutter_event_get_related(eventFromJava(env, obj));
	return toJavaActor(env, actor);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_events_Event_getInputDevice(
		JNIEnv *env, jobject obj) {
	ClutterInputDevice *device = clutter_event_get_device(eventFromJava(env,
			obj));
	return toJavaInputDevice(env, device);
}

JNIEXPORT jint JNICALL Java_org_jclutter_InputDevice_getDeviceId(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_input_device_get_device_id(
			(ClutterInputDevice *) getGPointer(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_InputDevice_getDeviceTypeInt(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_input_device_get_device_type(
			(ClutterInputDevice *) getGPointer(env, obj));
}
JNIEXPORT jint JNICALL Java_org_jclutter_InputDeviceManager_getDefaultId(JNIEnv *env, jclass cl){
return (jint)clutter_input_device_manager_get_default_id();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_InputDeviceManager_listDevices(JNIEnv *env, jobject obj){
GSList *list = clutter_input_device_manager_list_devices();
// TODO
return NULL;
}
JNIEXPORT jobject JNICALL Java_org_jclutter_InputDeviceManager_getInputDevice(JNIEnv *env, jobject obj, jint param0){
ClutterInputDevice *device = clutter_input_device_manager_get_input_device();
return toJavaInputDevice(env, device);
}


JNIEXPORT jint JNICALL Java_org_jclutter_KeyBindingPool_newInstance(JNIEnv *env, jclass cl, jstring name) {
	const char *a = (*env)->GetStringUTFChars(env, name, 0);
	return (jint)clutter_binding_pool_new(a);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_KeyBindingPool_find(JNIEnv *env, jclass cl, jstring name) {
	const char *a = (*env)->GetStringUTFChars(env, name, 0);
	ClutterBindingPool *pool = clutter_binding_pool_find(a);
	if (pool == NULL) return NULL;
	return findJavaGObject(env, G_OBJECT(pool));
}
JNIEXPORT void JNICALL Java_org_jclutter_KeyBindingPool_installAction(JNIEnv *env, jobject obj, jstring action_name, jint key_val, jint modifiers, jint cbid, jclass c, jstring method) {
	const char *a = (*env)->GetStringUTFChars(env, action_name, 0);
	const char *m = (*env)->GetStringUTFChars(env, method, 0);
	jmethodID mid = (*env)->GetMethodID(env, c, m, "()V");
	installBindingPoolAction(CLUTTER_BINDING_POOL(getGPointer(env, obj)), a, key_val, modifiers, cbid, c, mid);
}
JNIEXPORT jstring JNICALL Java_org_jclutter_KeyBindingPool_findAction(
		JNIEnv *env, jobject obj, jint key_val, jint modifiers) {
	const gchar *a = clutter_binding_pool_find_action(CLUTTER_BINDING_POOL(
			getGPointer(env, obj)), key_val, modifiers);
	return (*env)->NewStringUTF(env, a);
}
JNIEXPORT void JNICALL Java_org_jclutter_KeyBindingPool_removeAction(JNIEnv *env, jobject obj, jint key_val, jint modifiers) {
	clutter_binding_pool_remove_action(CLUTTER_BINDING_POOL(getGPointer(env, obj)), key_val, modifiers);
}
JNIEXPORT void JNICALL Java_org_jclutter_KeyBindingPool_blockAction(JNIEnv *env, jobject obj, jstring action_name) {
	const char *a = (*env)->GetStringUTFChars(env, action_name, 0);
	clutter_binding_pool_block_action(CLUTTER_BINDING_POOL(getGPointer(env, obj)), a);
}
JNIEXPORT void JNICALL Java_org_jclutter_KeyBindingPool_unblockAction(JNIEnv *env, jobject obj, jstring action_name) {
	const char *a = (*env)->GetStringUTFChars(env, action_name, 0);
	clutter_binding_pool_unblock_action(CLUTTER_BINDING_POOL(getGPointer(env, obj)), a);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_KeyBindingPool_activate(
		JNIEnv *env, jobject obj, jobject actor, jint key_val, jint modifiers) {
	return clutter_binding_pool_activate(CLUTTER_BINDING_POOL(getGPointer(env, obj)),
			key_val, modifiers, G_OBJECT(getGPointer(env, actor)));
}

JNIEXPORT jint JNICALL Java_org_jclutter_Backend_getDefaultBackend(JNIEnv *env,
		jclass jc) {
	return (jint) clutter_get_default_backend();
}
JNIEXPORT jdouble JNICALL Java_org_jclutter_Backend_getResolution(JNIEnv *env,
		jobject obj) {
	return (jdouble) clutter_backend_get_resolution(backendFromJava(env, obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Backend_setResolution(JNIEnv *env, jobject obj, jdouble dpi) {
	clutter_backend_set_resolution(backendFromJava(env, obj), dpi);
}
JNIEXPORT void JNICALL Java_org_jclutter_Backend_setDoubleClickTime(JNIEnv *env, jobject obj, jint msec) {
	clutter_backend_set_double_click_time(backendFromJava(env, obj), msec);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Backend_getDoubleClickTime(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_backend_get_double_click_time(backendFromJava(env,
			obj));
}
JNIEXPORT void JNICALL Java_org_jclutter_Backend_setDoubleClickDistance(JNIEnv *env, jobject obj, jint distance) {
	clutter_backend_set_double_click_distance(backendFromJava(env, obj), distance);
}
JNIEXPORT jint JNICALL Java_org_jclutter_Backend_getDoubleClickDistance(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_backend_get_double_click_distance(backendFromJava(
			env, obj));
}
JNIEXPORT jstring JNICALL Java_org_jclutter_Backend_getFontName(JNIEnv *env,
		jobject obj) {
	const char *str = clutter_backend_get_font_name(backendFromJava(env, obj));
	return (*env)->NewStringUTF(env, str);
}
JNIEXPORT void JNICALL Java_org_jclutter_Backend_setFontName(JNIEnv *env, jobject obj, jstring font) {
	const char *nfont = (*env)->GetStringUTFChars(env, font, 0);
	clutter_backend_set_font_name(backendFromJava(env, obj), nfont);
}

JNIEXPORT jint JNICALL Java_org_jclutter_Box_newInstance(JNIEnv *env, jclass cl, jobject layout){
	return (jint)clutter_box_new(CLUTTER_LAYOUT_MANAGER(getGPointer(env, layout)));
}
JNIEXPORT void JNICALL Java_org_jclutter_Box_setLayoutManager(JNIEnv *env, jobject obj, jobject layout){
	return clutter_box_set_layout_manager(CLUTTER_BOX(getGPointer(env, obj)), CLUTTER_LAYOUT_MANAGER(getGPointer(env, layout)));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Box_getLayoutManager(JNIEnv *env, jobject obj){
	ClutterLayoutManager *layout = clutter_box_get_layout_manager(CLUTTER_BOX(getGPointer(env, obj)));
	return findJavaGObject(env, G_OBJECT(layout));
}
JNIEXPORT void JNICALL Java_org_jclutter_Box_setColor(JNIEnv *env, jobject obj, jobject jcolor){
	ClutterColor color;
	colorFromJava(env, jcolor, &color);
	clutter_box_set_color(CLUTTER_BOX(getGPointer(env, obj)), &color);
}
JNIEXPORT jobject JNICALL Java_org_jclutter_Box_getColor(JNIEnv *env, jobject obj){
	ClutterColor c;
	clutter_box_get_color(CLUTTER_BOX(getGPointer(env, obj)), &c);
	return toJavaColor(env, &c);
}
/*JNIEXPORT void JNICALL Java_org_jclutter_Box_pack(JNIEnv *env, jobject obj, jobjectArray actors){
clutter_box_pack(CLUTTER_BOX(getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_Box_packAfter(JNIEnv *env, jobject obj, jobject sibling, jobjectArray actors){
clutter_box_pack_after(CLUTTER_BOX(getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_Box_packBefore(JNIEnv *env, jobject obj, jobject sibling, jobjectArray actors){
clutter_box_pack_before(CLUTTER_BOX(getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_Box_packAt(JNIEnv *env, jobject obj, int index, jobjectArray actors){
clutter_box_pack_at(CLUTTER_BOX(getGPointer(env, obj)));
}*/

JNIEXPORT void JNICALL Java_org_jclutter_LayoutManager_allocate(JNIEnv *env, jobject obj, jobject container, jobject box, jint flags) {
	clutter_layout_manager_allocate(CLUTTER_LAYOUT_MANAGER(getGPointer(env, obj)), containerFromJava(env, container), actorBoxFromJava(env, box), flags);
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_LayoutManager_getPreferredWidth(
		JNIEnv *env, jobject obj, jobject container, jfloat forheight) {
	gfloat f;
	clutter_layout_manager_get_preferred_width(CLUTTER_LAYOUT_MANAGER(
			getGPointer(env, obj)), CLUTTER_CONTAINER(getGPointer(env, obj)),
			forheight, NULL, &f);
	return f;
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_LayoutManager_getMinimumWidth(
		JNIEnv *env, jobject obj, jobject container, jfloat forheight) {
	gfloat f;
	clutter_layout_manager_get_preferred_width(CLUTTER_LAYOUT_MANAGER(
			getGPointer(env, obj)), CLUTTER_CONTAINER(getGPointer(env, obj)),
			forheight, &f, NULL);
	return f;
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_LayoutManager_getPreferredHeight(
		JNIEnv *env, jobject obj, jobject container, jfloat forwidth) {
	gfloat f;
	clutter_layout_manager_get_preferred_height(CLUTTER_LAYOUT_MANAGER(
			getGPointer(env, obj)), CLUTTER_CONTAINER(getGPointer(env, obj)),
			forwidth, NULL, &f);
	return f;
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_LayoutManager_getMinimumHeight(
		JNIEnv *env, jobject obj, jobject container, jfloat forwidth) {
	gfloat f;
	clutter_layout_manager_get_preferred_height(CLUTTER_LAYOUT_MANAGER(
			getGPointer(env, obj)), CLUTTER_CONTAINER(getGPointer(env, obj)),
			forwidth, &f, NULL);
	return f;
}
JNIEXPORT void JNICALL Java_org_jclutter_LayoutManager_layoutChanged(JNIEnv *env, jobject obj) {
	clutter_layout_manager_layout_changed(CLUTTER_LAYOUT_MANAGER(getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_LayoutManager_setContainer(JNIEnv *env, jobject obj, jobject container) {
	clutter_layout_manager_set_container(CLUTTER_LAYOUT_MANAGER(getGPointer(env, obj)), CLUTTER_CONTAINER(getGPointer(env, obj)));
}
JNIEXPORT jobject JNICALL Java_org_jclutter_LayoutManager_beginAnimation(
		JNIEnv *env, jobject obj, jint duration, jint animation) {
	return (jobject) clutter_layout_manager_begin_animation(
			CLUTTER_LAYOUT_MANAGER(getGPointer(env, obj)), duration, animation);
}
JNIEXPORT void JNICALL Java_org_jclutter_LayoutManager_endAnimation(JNIEnv *env, jobject obj) {
	clutter_layout_manager_end_animation(CLUTTER_LAYOUT_MANAGER(getGPointer(env, obj)));
}
JNIEXPORT jdouble JNICALL Java_org_jclutter_LayoutManager_getAnimationProgress(
		JNIEnv *env, jobject obj) {
	return (jdouble) clutter_layout_manager_get_animation_progress(
			CLUTTER_LAYOUT_MANAGER(getGPointer(env, obj)));
}
JNIEXPORT jint JNICALL Java_org_jclutter_FixedLayout_newInstance(JNIEnv *env,
		jclass cl) {
	return (jint) clutter_fixed_layout_new();
}
JNIEXPORT jint JNICALL Java_org_jclutter_FlowLayout_newInstance(JNIEnv *env,
		jclass cl, jint orientation) {
	return (jint) clutter_flow_layout_new(orientation);
}
JNIEXPORT void JNICALL Java_org_jclutter_FlowLayout_setHomogeneous(JNIEnv *env, jobject obj, jboolean h) {
	clutter_flow_layout_set_homogeneous(CLUTTER_FLOW_LAYOUT(getGPointer(env, obj)), h);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_FlowLayout_isHomogeneous(
		JNIEnv *env, jobject obj) {
	return (jboolean) clutter_flow_layout_get_homogeneous(CLUTTER_FLOW_LAYOUT(
			getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_FlowLayout_setOrientation(JNIEnv *env, jobject obj, jint orientation) {
	clutter_flow_layout_set_orientation(CLUTTER_FLOW_LAYOUT(getGPointer(env, obj)), orientation);
}
JNIEXPORT jint JNICALL Java_org_jclutter_FlowLayout_getOrientation(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_flow_layout_get_orientation(CLUTTER_FLOW_LAYOUT(
			getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_FlowLayout_setColumnSpacing(JNIEnv *env, jobject obj, jfloat spacing) {
	clutter_flow_layout_set_column_spacing(CLUTTER_FLOW_LAYOUT(getGPointer(env, obj)), spacing);
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_FlowLayout_getColumnSpacing(
		JNIEnv *env, jobject obj) {
	return (jfloat) clutter_flow_layout_get_column_spacing(CLUTTER_FLOW_LAYOUT(
			getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_FlowLayout_setRowSpacing(JNIEnv *env, jobject obj, jfloat spacing) {
	clutter_flow_layout_set_row_spacing(CLUTTER_FLOW_LAYOUT(getGPointer(env, obj)), spacing);
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_FlowLayout_getRowSpacing(
		JNIEnv *env, jobject obj) {
	return (jfloat) clutter_flow_layout_get_row_spacing(CLUTTER_FLOW_LAYOUT(
			getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_FlowLayout_setColumnWidth(JNIEnv *env, jobject obj, jfloat min, jfloat max) {
	clutter_flow_layout_set_column_width(CLUTTER_FLOW_LAYOUT(getGPointer(env, obj)), min, max);
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_FlowLayout_getColumnMaxWidth(
		JNIEnv *env, jobject obj) {
	gfloat f;
	clutter_flow_layout_get_column_width(CLUTTER_FLOW_LAYOUT(getGPointer(env,
			obj)), NULL, &f);
	return f;
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_FlowLayout_getColumnMinWidth(
		JNIEnv *env, jobject obj) {
	gfloat f;
	clutter_flow_layout_get_column_width(CLUTTER_FLOW_LAYOUT(getGPointer(env,
			obj)), &f, NULL);
	return f;
}
JNIEXPORT void JNICALL Java_org_jclutter_FlowLayout_setRowHeight(JNIEnv *env, jobject obj, jfloat min, jfloat max) {
	clutter_flow_layout_set_row_height(CLUTTER_FLOW_LAYOUT(getGPointer(env, obj)), min, max);
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_FlowLayout_getRowMaxHeight(
		JNIEnv *env, jobject obj) {
	gfloat f;
	clutter_flow_layout_get_row_height(CLUTTER_FLOW_LAYOUT(
			getGPointer(env, obj)), NULL, &f);
	return f;
}
JNIEXPORT jfloat JNICALL Java_org_jclutter_FlowLayout_getRowMinHeight(
		JNIEnv *env, jobject obj) {
	gfloat f;
	clutter_flow_layout_get_row_height(CLUTTER_FLOW_LAYOUT(
			getGPointer(env, obj)), &f, NULL);
	return f;
}
JNIEXPORT jint JNICALL Java_org_jclutter_BoxLayout_newInstance(JNIEnv *env,
		jclass cl) {
	return (jint) clutter_box_layout_new();
}
JNIEXPORT void JNICALL Java_org_jclutter_BoxLayout_setPackStart(JNIEnv *env, jobject obj, jboolean pack) {
	clutter_box_layout_set_pack_start(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)), pack);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_BoxLayout_isPackStart(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_box_layout_get_pack_start(CLUTTER_BOX_LAYOUT(
			getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_BoxLayout_setSpacing(JNIEnv *env, jobject obj, jint spacing) {
	clutter_box_layout_set_spacing(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)), spacing);
}
JNIEXPORT jint JNICALL Java_org_jclutter_BoxLayout_getSpacing(JNIEnv *env,
		jobject obj) {
	return (jint) clutter_box_layout_get_spacing(CLUTTER_BOX_LAYOUT(
			getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_BoxLayout_setVertical(JNIEnv *env, jobject obj, jboolean vertical) {
	clutter_box_layout_set_vertical(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)), vertical);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_BoxLayout_isVertical(JNIEnv *env,
		jobject obj) {
	return (jboolean) clutter_box_layout_get_vertical(CLUTTER_BOX_LAYOUT(
			getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_BoxLayout_pack(JNIEnv *env, jobject obj, jobject actor, jboolean expand, jboolean xf, jboolean yf, jint xa, jint ya) {
	clutter_box_layout_pack(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)), actorFromJava(env, actor), expand, xf, yf, xa, ya);
}
JNIEXPORT void JNICALL Java_org_jclutter_BoxLayout_setAlignment(JNIEnv *env, jobject obj, jobject actor, jint xalign, jint yalign) {
	clutter_box_layout_set_alignment(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)), actorFromJava(env, actor), xalign, yalign);
}
JNIEXPORT jint JNICALL Java_org_jclutter_BoxLayout_getAlignmentX(JNIEnv *env,
		jobject obj, jobject actor) {
	ClutterBoxAlignment i;
	clutter_box_layout_get_alignment(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)),
			actorFromJava(env, actor), &i, NULL);
	return i;
}
JNIEXPORT jint JNICALL Java_org_jclutter_BoxLayout_getAlignmentY(JNIEnv *env,
		jobject obj, jobject actor) {
	ClutterBoxAlignment i;
	clutter_box_layout_get_alignment(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)),
			actorFromJava(env, actor), NULL, &i);
	return i;
}
JNIEXPORT void JNICALL Java_org_jclutter_BoxLayout_setExpand(JNIEnv *env, jobject obj, jobject actor, jboolean expand) {
	clutter_box_layout_set_expand(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)), actorFromJava(env, actor), expand);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_BoxLayout_isExpand(JNIEnv *env,
		jobject obj, jobject actor) {
	return (jboolean) clutter_box_layout_get_expand(CLUTTER_BOX_LAYOUT(
			getGPointer(env, obj)), actorFromJava(env, actor));
}
JNIEXPORT void JNICALL Java_org_jclutter_BoxLayout_setFill(JNIEnv *env, jobject obj, jobject actor, jboolean xfill, jboolean yfill) {
	clutter_box_layout_set_fill(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)), actorFromJava(env, actor), xfill, yfill);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_BoxLayout_isFillX(JNIEnv *env,
		jobject obj, jobject actor) {
	gboolean b;
	clutter_box_layout_get_fill(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)),
			actorFromJava(env, actor), &b, NULL);
	return b;
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_BoxLayout_isFillY(JNIEnv *env,
		jobject obj, jobject actor) {
	gboolean b;
	clutter_box_layout_get_fill(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)),
			actorFromJava(env, actor), NULL, &b);
	return b;
}
JNIEXPORT void JNICALL Java_org_jclutter_BoxLayout_setUseAnimations(JNIEnv *env, jobject obj, jboolean use) {
	clutter_box_layout_set_use_animations(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)), use);
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_BoxLayout_isUseAnimations(
		JNIEnv *env, jobject obj) {
	return (jboolean) clutter_box_layout_get_use_animations(CLUTTER_BOX_LAYOUT(
			getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_BoxLayout_setEasingDuration(JNIEnv *env, jobject obj, jint duration) {
	clutter_box_layout_set_easing_duration(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)), duration);
}
JNIEXPORT jint JNICALL Java_org_jclutter_BoxLayout_getEasingDuration(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_box_layout_get_easing_duration(CLUTTER_BOX_LAYOUT(
			getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_BoxLayout_setEasingMode(JNIEnv *env, jobject obj, jint mode) {
	clutter_box_layout_set_easing_mode(CLUTTER_BOX_LAYOUT(getGPointer(env, obj)), mode);
}
JNIEXPORT jint JNICALL Java_org_jclutter_BoxLayout_getEasingModeNative(
		JNIEnv *env, jobject obj) {
	return (jint) clutter_box_layout_get_easing_mode(CLUTTER_BOX_LAYOUT(
			getGPointer(env, obj)));
}
JNIEXPORT void JNICALL Java_org_jclutter_BinLayout_add(JNIEnv *env, jobject obj, jobject actor, jint xalign, jint yalign) {
	clutter_bin_layout_add(CLUTTER_BIN_LAYOUT(getGPointer(env, obj)), actorFromJava(env, actor), xalign, yalign);
}
JNIEXPORT jint JNICALL Java_org_jclutter_BinLayout_newInstance(JNIEnv *env,
		jclass cl, jint x, jint y) {
	return (jint) clutter_bin_layout_new(x, y);
}
JNIEXPORT void JNICALL Java_org_jclutter_BinLayout_setAlignment(JNIEnv *env, jobject obj, jobject actor, jint xalign, jint yalign) {
	clutter_bin_layout_set_alignment(CLUTTER_BIN_LAYOUT(getGPointer(env, obj)), actorFromJava(env, actor), xalign, yalign);
}
JNIEXPORT jint JNICALL Java_org_jclutter_BinLayout_getAlignmentX(JNIEnv *env,
		jobject obj, jobject actor) {
	ClutterBinAlignment i;
	clutter_bin_layout_get_alignment(CLUTTER_BIN_LAYOUT(getGPointer(env, obj)),
			actorFromJava(env, actor), &i, NULL);
	return i;
}
JNIEXPORT jint JNICALL Java_org_jclutter_BinLayout_getAlignmentY(JNIEnv *env,
		jobject obj, jobject actor) {
	ClutterBinAlignment i;
	clutter_bin_layout_get_alignment(CLUTTER_BIN_LAYOUT(getGPointer(env, obj)),
			actorFromJava(env, actor), NULL, &i);
	return i;
}
