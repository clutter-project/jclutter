#include "jclutter-common.h"
#include <gmodule.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <glib.h>
#include <glib-object.h>

jclass cls_nobject = NULL;
jmethodID method_getnobject = NULL;
jclass cls_clutter_exception = NULL;
jfieldID field_nobject = NULL;

jclass cls_stage = NULL;
jmethodID method_stage_init = NULL;
jmethodID method_stage_create = NULL;

jclass cls_shader = NULL;
jmethodID method_shader_init = NULL;

jclass cls_clutter = NULL;
jmethodID method_task_execute = NULL;
jmethodID method_task_destroy = NULL;

jclass cls_event = NULL;
jmethodID method_event_init = NULL;
jmethodID method_event_create = NULL;
jfieldID field_eventptr = NULL;

jclass cls_actor_box = NULL;

jmethodID method_actor_box_init = NULL;
jfieldID field_actor_box_x1 = NULL;
jfieldID field_actor_box_y1 = NULL;
jfieldID field_actor_box_x2 = NULL;
jfieldID field_actor_box_y2 = NULL;

jclass cls_scale = NULL;
jmethodID method_scale_init = NULL;
jfieldID field_scale_x = NULL;
jfieldID field_scale_y = NULL;

jclass cls_dimension = NULL;
jmethodID method_dimension_init = NULL;
jfieldID field_dimension_width = NULL;
jfieldID field_dimension_height = NULL;

jclass cls_fog = NULL;
jmethodID method_fog_init = NULL;
jfieldID field_fog_z_near = NULL;
jfieldID field_fog_z_far = NULL;

jclass cls_perspective = NULL;
jmethodID method_perspective_init = NULL;
jfieldID field_perspective_fovy = NULL;
jfieldID field_perspective_aspect = NULL;
jfieldID field_perspective_z_near = NULL;
jfieldID field_perspective_z_far = NULL;

jclass cls_geometry = NULL;
jmethodID method_geometry_init = NULL;

jclass cls_rotation = NULL;
jmethodID method_rotation_init = NULL;
jfieldID field_rotation_axis = NULL;
jfieldID field_rotation_angle = NULL;
jfieldID field_rotation_x = NULL;
jfieldID field_rotation_y = NULL;
jfieldID field_rotation_z = NULL;

jclass cls_point = NULL;
jmethodID method_point_init = NULL;
jfieldID field_point_x = NULL;
jfieldID field_point_y = NULL;
jfieldID field_point_z = NULL;

jclass cls_timeline = NULL;
jmethodID method_timeline_create = NULL;

jclass cls_color = NULL;
jmethodID method_color_init = NULL;
jfieldID field_color_red = NULL;
jfieldID field_color_green = NULL;
jfieldID field_color_blue = NULL;
jfieldID field_color_alpha = NULL;

jmethodID method_getcallback = NULL;

jclass cls_knot = NULL;
jmethodID method_knot_init = NULL;
jfieldID field_knot_x = NULL;
jfieldID field_knot_y = NULL;

jclass cls_animation = NULL;
jmethodID method_animation_init = NULL;

jclass cls_device = NULL;
jmethodID method_device_init = NULL;

jclass cls_binding_pool = NULL;
jmethodID method_binding_pool_init = NULL;

jclass cls_cogl_texture = NULL;
jfieldID field_cogl_texture_pointer = NULL;
jmethodID method_cogl_texture_init = NULL;
jclass cls_cogl_matrix = NULL;
jmethodID method_cogl_matrix_init = NULL;
jfieldID field_cogl_matrix_pointer = NULL;
jclass cls_cogl_color = NULL;
jmethodID method_cogl_color_init = NULL;
jfieldID field_cogl_color_pointer = NULL;



JavaVM *cached_jvm;

void LOGI(const char * fmt, ...) {
	va_list arg_ptr;
	printf("JClutter: ");
	va_start(arg_ptr, fmt);
	vprintf(fmt, arg_ptr);
	va_end(arg_ptr);
	printf("\n");
}

void jniClutterException(JNIEnv *env, const char * message) {
	(*env)->ThrowNew(env, cls_clutter_exception, message);
}

static void detachJVM() {
	(*cached_jvm)->DetachCurrentThread(cached_jvm);
}

static JNIEnv * attachJVM() {
	JNIEnv *env;
	(*cached_jvm)->AttachCurrentThread(cached_jvm, (void **) &env, NULL);
	return env;
}

void cacheMethodIds(JNIEnv *env) {
	(*env)->GetJavaVM(env, &cached_jvm);
	cls_nobject = (*env)->FindClass(env, "org/jclutter/glib/GObject");

	cls_clutter = (*env)->FindClass(env, "org/jclutter/Clutter");
	cls_clutter_exception = (*env)->FindClass(env,
			"org/jclutter/ClutterException");
	cls_scale = (*env)->FindClass(env, "org/jclutter/Scale");

	cls_dimension = (*env)->FindClass(env, "org/jclutter/Dimension");
	cls_point = (*env)->FindClass(env, "org/jclutter/Point");
	cls_geometry = (*env)->FindClass(env, "org/jclutter/Geometry");
	cls_actor_box = (*env)->FindClass(env, "org/jclutter/ActorBox");

	cls_fog = (*env)->FindClass(env, "org/jclutter/Fog");
	cls_color = (*env)->FindClass(env, "org/jclutter/Color");
	cls_perspective = (*env)->FindClass(env, "org/jclutter/Perspective");
	cls_rotation = (*env)->FindClass(env, "org/jclutter/Rotation");
	cls_knot = (*env)->FindClass(env, "org/jclutter/animation/Knot");
	cls_timeline = (*env)->FindClass(env, "org/jclutter/animation/Timeline");
	cls_animation = (*env)->FindClass(env, "org/jclutter/animation/Animation");
	cls_device = (*env)->FindClass(env, "org/jclutter/InputDevice");
	cls_stage = (*env)->FindClass(env, "org/jclutter/Stage");
	cls_binding_pool = (*env)->FindClass(env, "org/jclutter/KeyBindingPool");
	cls_shader = (*env)->FindClass(env, "org/jclutter/Shader");

	method_shader_init = (*env)->GetMethodID(env, cls_shader, "<init>", "(I)V");
	method_binding_pool_init = (*env)->GetMethodID(env, cls_binding_pool,
			"<init>", "(I)V");
	method_device_init = (*env)->GetMethodID(env, cls_device, "<init>", "(I)V");
	method_stage_init = (*env)->GetMethodID(env, cls_stage, "<init>", "(I)V");
	method_stage_create = (*env)->GetStaticMethodID(env, cls_stage, "createStage", "(I)Lorg/jclutter/Stage;");
	cls_event = (*env)->FindClass(env, "org/jclutter/events/Event");
	method_event_init = (*env)->GetMethodID(env, cls_event, "<init>", "(I)V");
	field_eventptr = (*env)->GetFieldID(env, cls_event, "pointer", "I");
	method_event_create = (*env)->GetStaticMethodID(env, cls_event,
			"createEvent", "(II)Lorg/jclutter/events/Event;");

	field_nobject = (*env)->GetFieldID(env, cls_nobject, "pointer", "I");
	method_getnobject = (*env)->GetStaticMethodID(env, cls_nobject,
			"getByPointer", "(I)Lorg/jclutter/glib/GObject;");
	method_point_init = (*env)->GetMethodID(env, cls_point, "<init>", "(FFF)V");
	field_point_x = (*env)->GetFieldID(env, cls_point, "x", "F");
	field_point_y = (*env)->GetFieldID(env, cls_point, "y", "F");
	field_point_z = (*env)->GetFieldID(env, cls_point, "z", "F");
	method_actor_box_init = (*env)->GetMethodID(env, cls_actor_box, "<init>",
			"(FFFF)V");
	field_actor_box_x1 = (*env)->GetFieldID(env, cls_actor_box, "x1", "F");
	field_actor_box_y1 = (*env)->GetFieldID(env, cls_actor_box, "y1", "F");
	field_actor_box_x2 = (*env)->GetFieldID(env, cls_actor_box, "x2", "F");
	field_actor_box_y2 = (*env)->GetFieldID(env, cls_actor_box, "y2", "F");
	method_scale_init
			= (*env)->GetMethodID(env, cls_scale, "<init>", "(DDFF)V");
	field_scale_x = (*env)->GetFieldID(env, cls_scale, "x", "D");
	field_scale_y = (*env)->GetFieldID(env, cls_scale, "y", "D");
	method_dimension_init = (*env)->GetMethodID(env, cls_dimension, "<init>",
			"(FF)V");
	field_dimension_width
			= (*env)->GetFieldID(env, cls_dimension, "width", "F");
	field_dimension_height = (*env)->GetFieldID(env, cls_dimension, "height",
			"F");
	method_fog_init = (*env)->GetMethodID(env, cls_fog, "<init>", "(FF)V");
	field_fog_z_near = (*env)->GetFieldID(env, cls_fog, "zNear", "F");
	field_fog_z_far = (*env)->GetFieldID(env, cls_fog, "zFar", "F");
	method_perspective_init = (*env)->GetMethodID(env, cls_perspective,
			"<init>", "(FFFF)V");
	field_perspective_fovy = (*env)->GetFieldID(env, cls_perspective, "fovy",
			"F");
	field_perspective_aspect = (*env)->GetFieldID(env, cls_perspective,
			"aspect", "F");
	field_perspective_z_near = (*env)->GetFieldID(env, cls_perspective,
			"zNear", "F");
	field_perspective_z_far = (*env)->GetFieldID(env, cls_perspective, "zFar",
			"F");

	method_geometry_init = (*env)->GetMethodID(env, cls_geometry, "<init>",
			"(IIII)V");
	method_rotation_init = (*env)->GetMethodID(env, cls_rotation, "<init>",
			"(IDFFF)V");
	field_rotation_axis = (*env)->GetFieldID(env, cls_rotation, "axis", "I");
	field_rotation_angle = (*env)->GetFieldID(env, cls_rotation, "angle", "D");

	method_timeline_create = (*env)->GetStaticMethodID(env, cls_timeline, "createTimeline", "(I)Lorg/jclutter/animation/Timeline;");
	method_color_init
			= (*env)->GetMethodID(env, cls_color, "<init>", "(IIII)V");
	field_color_red = (*env)->GetFieldID(env, cls_color, "red", "I");
	field_color_green = (*env)->GetFieldID(env, cls_color, "green", "I");
	field_color_blue = (*env)->GetFieldID(env, cls_color, "blue", "I");
	field_color_alpha = (*env)->GetFieldID(env, cls_color, "alpha", "I");

	method_knot_init = (*env)->GetMethodID(env, cls_knot, "<init>", "(II)V");
	field_knot_x = (*env)->GetFieldID(env, cls_knot, "x", "I");
	field_knot_y = (*env)->GetFieldID(env, cls_knot, "y", "I");

	method_animation_init = (*env)->GetMethodID(env, cls_animation, "<init>",
			"(I)V");

	method_getcallback = (*env)->GetStaticMethodID(env, cls_clutter,
			"getCallback", "(I)Ljava/lang/Object;");

	jclass cls_task = (*env)->FindClass(env, "org/jclutter/BlockingTask");
	method_task_execute = (*env)->GetMethodID(env, cls_task, "execute", "()Z");
	method_task_destroy = (*env)->GetMethodID(env, cls_task, "destroy", "()V");

	cls_cogl_texture = (*env)->FindClass(env, "org/jclutter/cogl/CoglTexture");
	field_cogl_texture_pointer = (*env)->GetFieldID(env, cls_cogl_texture, "pointer", "I");
	method_cogl_texture_init = (*env)->GetMethodID(env, cls_cogl_texture,
			"<init>", "(I)V");
	cls_cogl_matrix = (*env)->FindClass(env, "org/jclutter/cogl/Matrix");
	method_cogl_matrix_init = (*env)->GetMethodID(env, cls_cogl_matrix,
			"<init>", "(I)V");
	field_cogl_matrix_pointer = (*env)->GetFieldID(env, cls_cogl_matrix,
			"pointer", "I");
	cls_cogl_color = (*env)->FindClass(env, "org/jclutter/cogl/Color");
	method_cogl_color_init = (*env)->GetMethodID(env, cls_cogl_color, "<init>",
			"(I)V");
	field_cogl_color_pointer = (*env)->GetFieldID(env, cls_cogl_color,
			"pointer", "I");
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved) {
	LOGI("loading lib");
	JNIEnv *env = NULL;
	void *venv = NULL;

	if ((*jvm)->GetEnv(jvm, &venv, JNI_VERSION_1_4) == JNI_OK) {
		LOGI("Load class methods");
		env = venv;
		cacheMethodIds(env);
	}
	return JNI_VERSION_1_4;
}

jobject createJavaCoglTexture(JNIEnv *env, CoglHandle *h) {
	return (*env)->NewObject(env, cls_cogl_texture, method_cogl_texture_init, (jint) h);
}

CoglHandle coglTextureFromJava(JNIEnv *env, jobject obj){
	jint p = (*env)->GetIntField(env, obj, field_cogl_texture_pointer);
	CoglHandle h = (CoglHandle)p;
	return h;
}

CoglColor * coglColorFromJava(JNIEnv *env, jobject obj){
	return (CoglColor *)((*env)->GetIntField(env, obj, field_cogl_color_pointer));
}

CoglMatrix * coglMatrixFromJava(JNIEnv *env, jobject obj){
	return (CoglMatrix *)((*env)->GetIntField(env, obj, field_cogl_matrix_pointer));
}

jobject toJavaCoglColor(JNIEnv *env, CoglColor *color){
	return (*env)->NewObject(env, cls_cogl_color, method_cogl_color_init, (jint) color);
}

jobject toJavaCoglMatrix(JNIEnv *env, CoglMatrix *matrix){
	return (*env)->NewObject(env, cls_cogl_matrix, method_cogl_matrix_init, (jint) matrix);
}

static gboolean executeTask(gpointer data) {
	int target = (int) data;
	JNIEnv *env = attachJVM();
	jobject inst = (*env)->CallStaticObjectMethod(env, cls_clutter,
			method_getcallback, target);
	jboolean b = (*env)->CallBooleanMethod(env, inst, method_task_execute);
	detachJVM();
	return b;
}

static void destroyTask(gpointer data) {
	int target = (int) data;
	JNIEnv *env = attachJVM();
	jobject inst = (*env)->CallStaticObjectMethod(env, cls_clutter,
			method_getcallback, target);
	(*env)->CallVoidMethod(env, inst, method_task_destroy);
	detachJVM();
}

jobject findJavaGObject(JNIEnv *env, GObject *g) {
	if (g == NULL) return NULL;
	else return (*env)->CallStaticObjectMethod(env, cls_nobject, method_getnobject,
			(jint) g);
}

void arrayStringsFromJava(JNIEnv *env, char **argv, jobjectArray jargs) {
	jsize argc = 0;
	if (jargs != NULL)
		argc = (*env)->GetArrayLength(env, jargs);
	int i;
	for (i = 0; i < argc; i++) {
		jobject stObj = (*env)->GetObjectArrayElement(env, jargs, i);
		const char *str = (*env)->GetStringUTFChars(env, stObj, 0);
		strcpy(argv[i], str);
		LOGI("argv[%i] = %s", i, argv[i]);
		(*env)->ReleaseStringUTFChars(env, stObj, str);
	}
}

ClutterActor * actorFromJava(JNIEnv *env, jobject actor) {
	if (actor == NULL)
		return NULL;
	return CLUTTER_ACTOR((*env)->GetIntField(env, actor, field_nobject));
}

gpointer getGPointer(JNIEnv *env, jobject obj) {
	return (gpointer)(*env)->GetIntField(env, obj, field_nobject);
}

ClutterShader * shaderFromJava(JNIEnv *env, jobject shader) {
	if (shader == NULL)
		return NULL;
	return CLUTTER_SHADER((*env)->GetIntField(env, shader, field_nobject));
}

jobject toJavaShader(JNIEnv *env, ClutterShader *shader) {
	if (shader == NULL)
		return NULL;
	jobject object = findJavaGObject(env, G_OBJECT(shader));
	if (object != NULL)
		return object;
	else
		return (*env)->NewObject(env, cls_shader, method_shader_init,
				(int) shader);
}

ClutterStage * stageFromJava(JNIEnv *env, jobject stage) {
	if (stage == NULL)
		return NULL;
	return CLUTTER_STAGE((*env)->GetIntField(env, stage, field_nobject));
}

ClutterTexture * textureFromJava(JNIEnv *env, jobject texture) {
	if (texture == NULL)
		return NULL;
	return CLUTTER_TEXTURE((*env)->GetIntField(env, texture, field_nobject));
}

ClutterRectangle * rectangleFromJava(JNIEnv *env, jobject rect) {
	if (rect == NULL)
		return NULL;
	return CLUTTER_RECTANGLE((*env)->GetIntField(env, rect, field_nobject));
}

ClutterEvent * eventFromJava(JNIEnv *env, jobject event) {
	if (event == NULL)
		return NULL;
	return (ClutterEvent *) ((*env)->GetIntField(env, event, field_eventptr));
}

ClutterAlpha * alphaFromJava(JNIEnv *env, jobject alpha) {
	if (alpha == NULL)
		return NULL;
	return CLUTTER_ALPHA((*env)->GetIntField(env, alpha, field_nobject));
}

ClutterTimeline * timelineFromJava(JNIEnv *env, jobject timeline) {
	if (timeline == NULL)
		return NULL;
	return CLUTTER_TIMELINE((*env)->GetIntField(env, timeline, field_nobject));
}

ClutterAnimation * animationFromJava(JNIEnv *env, jobject animation) {
	if (animation == NULL)
		return NULL;
	return CLUTTER_ANIMATION((*env)->GetIntField(env, animation, field_nobject));
}

jobject createJavaTimeline(JNIEnv *env, ClutterTimeline *timeline) {
	if (timeline == NULL)
		return NULL;
	jobject object = findJavaGObject(env, G_OBJECT(timeline));
	if (object == NULL) {
		object = (*env)->CallStaticObjectMethod(env, cls_timeline, method_timeline_create, (int) timeline);
		//(*env)->SetIntField(env, object, field_nobject, (int) timeline);
	}
	return object;
}

ClutterContainer * containerFromJava(JNIEnv *env, jobject container) {
	if (container == NULL)
		return NULL;
	return CLUTTER_CONTAINER((*env)->GetIntField(env, container, field_nobject));
}

ClutterGroup * groupFromJava(JNIEnv *env, jobject group) {
	if (group == NULL)
		return NULL;
	return CLUTTER_GROUP((*env)->GetIntField(env, group, field_nobject));
}

ClutterText * textFromJava(JNIEnv *env, jobject text) {
	if (text == NULL)
		return NULL;
	return CLUTTER_TEXT((*env)->GetIntField(env, text, field_nobject));
}

ClutterBackend * backendFromJava(JNIEnv *env, jobject backend) {
	if (backend == NULL)
		return NULL;
	return CLUTTER_BACKEND((*env)->GetIntField(env, backend, field_nobject));
}

ClutterScript * scriptFromJava(JNIEnv *env, jobject script) {
	if (script == NULL)
		return NULL;
	return CLUTTER_SCRIPT((*env)->GetIntField(env, script, field_nobject));
}

ClutterScore * scoreFromJava(JNIEnv *env, jobject score) {
	if (score == NULL)
		return NULL;
	return CLUTTER_SCORE((*env)->GetIntField(env, score, field_nobject));
}

ClutterBehaviourScale * behaviourScaleFromJava(JNIEnv *env, jobject scale) {
	if (scale == NULL)
		return NULL;
	return CLUTTER_BEHAVIOUR_SCALE((*env)->GetIntField(env, scale,
			field_nobject));
}

ClutterBehaviourRotate * behaviourRotateFromJava(JNIEnv *env, jobject b) {
	if (b == NULL)
		return NULL;
	return CLUTTER_BEHAVIOUR_ROTATE((*env)->GetIntField(env, b, field_nobject));
}

ClutterBehaviourPath * behaviourPathFromJava(JNIEnv *env, jobject b) {
	if (b == NULL)
		return NULL;
	return CLUTTER_BEHAVIOUR_PATH((*env)->GetIntField(env, b, field_nobject));
}

ClutterBehaviourOpacity * behaviourOpacityFromJava(JNIEnv *env, jobject b) {
	if (b == NULL)
		return NULL;
	return CLUTTER_BEHAVIOUR_OPACITY((*env)->GetIntField(env, b, field_nobject));
}

ClutterBehaviourDepth * behaviourDepthFromJava(JNIEnv *env, jobject b) {
	if (b == NULL)
		return NULL;
	return CLUTTER_BEHAVIOUR_DEPTH((*env)->GetIntField(env, b, field_nobject));
}

ClutterBehaviourEllipse * behaviourEllipseFromJava(JNIEnv *env, jobject b) {
	if (b == NULL)
		return NULL;
	return CLUTTER_BEHAVIOUR_ELLIPSE((*env)->GetIntField(env, b, field_nobject));
}

ClutterBehaviour * behaviourFromJava(JNIEnv *env, jobject b) {
	if (b == NULL)
		return NULL;
	return CLUTTER_BEHAVIOUR((*env)->GetIntField(env, b, field_nobject));
}

ClutterPath * pathFromJava(JNIEnv *env, jobject path) {
	if (path == NULL)
		return NULL;
	return CLUTTER_PATH((*env)->GetIntField(env, path, field_nobject));
}

jobject toJavaGeometry(JNIEnv *env, ClutterGeometry *geo) {
	return (*env)->NewObject(env, cls_geometry, method_geometry_init, geo->x,
			geo->y, geo->width, geo->height);
}

jobject toJavaScale(JNIEnv *env, double x, double y, float cx, float cy) {
	return (*env)->NewObject(env, cls_scale, method_scale_init, x, y, cx, cy);
}

jobject toJavaRotation(JNIEnv *env, int axis, double angle, float x, float y,
		float z) {
	return (*env)->NewObject(env, cls_rotation, method_rotation_init, axis,
			angle, x, y, z);
}

void rotationFromJava(JNIEnv *env, jobject jrot, ClutterRotateAxis *ra,
		double *angle, float *x, float *y, float *z) {
	// TODO
}

jobject toJavaDimension(JNIEnv *env, float width, float height) {
	return (*env)->NewObject(env, cls_dimension, method_dimension_init, width,
			height);
}

jobject toJavaActorBox(JNIEnv *env, ClutterActorBox *box) {
	return (*env)->NewObject(env, cls_actor_box, method_actor_box_init,
			box->x1, box->y1, box->x2, box->y2);
}

jobject createJavaStage(JNIEnv *env, ClutterStage *stage) {
	return (*env)->CallStaticObjectMethod(env, cls_stage, method_stage_create, (jint) stage);
}

ClutterActorBox * actorBoxFromJava(JNIEnv *env, jobject jbox) {
	return clutter_actor_box_new((*env)->GetFloatField(env, jbox,
			field_actor_box_x1), (*env)->GetFloatField(env, jbox,
			field_actor_box_y1), (*env)->GetFloatField(env, jbox,
			field_actor_box_x2), (*env)->GetFloatField(env, jbox,
			field_actor_box_y2));
}

jobject toJavaFog(JNIEnv *env, float z_near, float z_far) {
	return (*env)->NewObject(env, cls_fog, method_fog_init, z_near, z_far);
}

jobject toJavaPoint(JNIEnv *env, float x, float y, float z) {
	return (*env)->NewObject(env, cls_point, method_point_init, x, y, z);
}

jobject toJavaAnimation(JNIEnv *env, ClutterAnimation *anim) {
	if (anim == NULL)
		return NULL;
	return (*env)->NewObject(env, cls_animation, method_animation_init,
			(int) anim);
}

float getPointX(JNIEnv *env, jobject point) {
	return (*env)->GetFloatField(env, point, field_point_x);
}

float getPointY(JNIEnv *env, jobject point) {
	return (*env)->GetFloatField(env, point, field_point_y);
}

float getPointZ(JNIEnv *env, jobject point) {
	return (*env)->GetFloatField(env, point, field_point_z);
}

ClutterKnot knotFromJava(JNIEnv *env, jobject jknot) {
	const ClutterKnot knot = { (*env)->GetIntField(env, jknot, field_knot_x),
			(*env)->GetIntField(env, jknot, field_knot_y) };
	return knot;
}

ClutterKnot ** knotsFromJava(JNIEnv *env, jobjectArray jknots) {
	/*int n = (*env)->GetArrayLength(env, jknots);
	 const ClutterKnot knots [n];
	 int i;
	 for (i = 0; i < n; i++) {
	 jobject jpos = (*env)->GetObjectArrayElement(env, jknots, i);
	 knots[i].x = (*env)->GetIntField(env, jpos, field_point_x);
	 knots[i].y = (*env)->GetIntField(env, jpos, field_point_y);
	 }
	 return &knots; **/
	return NULL;
}

void colorFromJava(JNIEnv *env, jobject jcolor, ClutterColor * color) {
	color->red = (*env)->GetIntField(env, jcolor, field_color_red);
	color->green = (*env)->GetIntField(env, jcolor, field_color_green);
	color->blue = (*env)->GetIntField(env, jcolor, field_color_blue);
	color->alpha = (*env)->GetIntField(env, jcolor, field_color_alpha);
}

jobject toJavaColor(JNIEnv *env, ClutterColor * color) {
	return (*env)->NewObject(env, cls_color, method_color_init, color->red,
			color->green, color->blue, color->alpha);
}

jobject toJavaInputDevice(JNIEnv *env, ClutterInputDevice *device) {
	jobject object = findJavaGObject(env, G_OBJECT(device));
	if (object != NULL)
		return object;
	return (*env)->NewObject(env, cls_device, method_device_init, (int) device);
}

jobject createJavaKeyBindingPool(JNIEnv *env, ClutterBindingPool *pool) {
	return (*env)->NewObject(env, cls_binding_pool, method_binding_pool_init,
			(int) pool);
}

	//struct timespec start, end;
	//clock_gettime(CLOCK_MONOTONIC, &start);
	// test
	//clock_gettime(CLOCK_MONOTONIC, &end);
	//LOGI ("Time1: %ld", timespecDiff(&end, &start));
int64_t timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p) {
	return ((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec)
			- ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec);
}

static void genericVoidCallback(JNIEnv *env, jobject source,
		JClutterCallback *d, ...) {
	va_list arg_ptr;
	va_start(arg_ptr, d);
	if (d->isStatic) {
		(*env)->CallStaticVoidMethod(env, d->clazz, d->method, source, arg_ptr);
	} else {
		jobject inst;
		if (d->target > 0) {
			inst = (*env)->CallStaticObjectMethod(env, cls_clutter,
					method_getcallback, d->target);
			(*env)->CallVoidMethod(env, inst, d->method, source, arg_ptr);
		} else {
			inst = source;
			(*env)->CallVoidMethod(env, inst, d->method, arg_ptr);
		}
	}
	va_end(arg_ptr);
}

static void cbActor(ClutterActor *actor, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(actor)), d);
	detachJVM();
}

static void cbActorAllocation(ClutterActor *actor, ClutterActorBox *box,
		ClutterAllocationFlags flags, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(actor)), d,
			toJavaActorBox(env, box));
	detachJVM();
}

static void cbActor2(ClutterActor *actor, ClutterActor *actor2,
		JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(actor)), d,
			findJavaGObject(env, G_OBJECT(actor2)));
	detachJVM();
}

static gboolean cbActorEvent(ClutterActor *actor, ClutterEvent *event,
		JClutterCallback *d) {
	jboolean b = FALSE;
	JNIEnv *env = attachJVM();
	jobject evt =  (*env)->CallStaticObjectMethod(env, cls_event, method_event_create, event->type, (int)event);
	//b = genericBooleanCallback(env, findJavaGObject(env, G_OBJECT(actor)), d, evt);
	jobject source = findJavaGObject(env, G_OBJECT(actor));
	if (d->isStatic) {
			b = (*env)->CallStaticBooleanMethod(env, d->clazz, d->method, source, evt);
	} else {
		jobject inst;
		if (d->target > 0) {
			//LOGI("callback is not source");
			inst = (*env)->CallStaticObjectMethod(env, cls_clutter,
					method_getcallback, d->target);
			if ((*env)->ExceptionOccurred(env)) {
				(*env)->ExceptionDescribe(env);
				return FALSE;
			}
			//LOGI("target found");
			b = (*env)->CallBooleanMethod(env, inst, d->method, source, evt);
		} else {
			//LOGI("callback is source");
			inst = source;
			b = (*env)->CallBooleanMethod(env, inst, d->method, evt);
		}
	}
	detachJVM();
	return b;
}

static void cbActorColor(ClutterActor *actor, ClutterColor *color,
		JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(actor)), d,
			toJavaColor(env, color));
	detachJVM();
}

static void cbBehaviour(ClutterBehaviour *behaviour, ClutterActor *actor,
		JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(behaviour)), d,
			findJavaGObject(env, G_OBJECT(actor)));
	detachJVM();
}

static void cbStage(ClutterStage *stage, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(stage)), d);
	detachJVM();
}

static void cbTextureLoadFinished(ClutterTexture *texture, gpointer error,
		JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	// TODO check error
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(texture)), d);
	detachJVM();
}

static void cbTexturePixbufChange(ClutterTexture *texture, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(texture)), d);
	detachJVM();
}

static void cbTextureSizeChange(ClutterTexture *texture, gint width,
		gint height, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(texture)), d, width,
			height);
	detachJVM();
}

static void cbTimeline(ClutterTimeline *timeline, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(timeline)), d);
	detachJVM();
}

// TODO : marker name + param
static void cbTimelineMarkerReached(ClutterTimeline *timeline,
		gchar *marker_name, gint msecs, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(timeline)), d,
			marker_name, msecs);
	detachJVM();
}

static void cbTimelineNewFrame(ClutterTimeline *timeline, gint msecs,
		JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(timeline)), d, msecs);
	detachJVM();
}

static void cbText(ClutterText *text, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(text)), d);
	detachJVM();
}

static void cbTextGeometry(ClutterText *text, ClutterGeometry *geometry,
		JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(text)), d,
			toJavaGeometry(env, geometry));
	detachJVM();
}

static void cbMedia(ClutterMedia *media, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(media)), d);
	detachJVM();
}

static void cbMedia2(ClutterMedia *media, gpointer error, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(media)), d);
	detachJVM();
}

static void cbScore(ClutterScore *score, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(score)), d);
	detachJVM();
}

static void cbScoreTimeline(ClutterScore *score, ClutterTimeline *timeline,
		JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(score)), d,
			createJavaTimeline(env, timeline));
	detachJVM();
}

static void cbAnimation(ClutterAnimation *animation, JClutterCallback *d) {
	JNIEnv *env = attachJVM();
	genericVoidCallback(env, findJavaGObject(env, G_OBJECT(animation)), d);
	detachJVM();
}

static gboolean compareString(const char *str1, const char *str2) {
	if (strcmp(str1, str2) == 0)
		return TRUE;
	return FALSE;
}

static GCallback getCallback(GObject *go, const char *name) {
	GObjectClass *clazz = G_OBJECT_GET_CLASS(go);

	const char *clsname = G_OBJECT_CLASS_NAME(clazz);
	//LOGI("class is %s for signal %", b);

	if (G_TYPE_CHECK_INSTANCE_TYPE(go, CLUTTER_TYPE_TEXT)) {
		if (compareString("activate", name))
			return G_CALLBACK(cbText);
		if (compareString("cursor-event", name))
			return G_CALLBACK(cbTextGeometry);
		if (compareString("text-changed", name))
			return G_CALLBACK(cbText);
	}

	if (G_TYPE_CHECK_INSTANCE_TYPE(go, CLUTTER_TYPE_STAGE)) {
		if (compareString("activate", name))
			return G_CALLBACK(cbStage);
		if (compareString("deactivate", name))
			return G_CALLBACK(cbStage);
		if (compareString("fullscreen", name))
			return G_CALLBACK(cbStage);
		if (compareString("unfullscreen", name))
			return G_CALLBACK(cbStage);
	}

	if (G_TYPE_CHECK_INSTANCE_TYPE(go, CLUTTER_TYPE_TEXTURE)) {
		if (compareString("load-finished", name))
			return G_CALLBACK(cbTextureLoadFinished);
		if (compareString("pixbuf-change", name))
			return G_CALLBACK(cbTexturePixbufChange);
		if (compareString("size-change", name))
			return G_CALLBACK(cbTextureSizeChange);
	}

	if (G_TYPE_CHECK_INSTANCE_TYPE(go, CLUTTER_TYPE_ACTOR)) {
		if (compareString("allocation-changed", name))
			return G_CALLBACK(cbActorAllocation);
		//if (compareString("event", strstr(name,"event"))) return G_CALLBACK(cbActorEvent);
		if (compareString("scroll-event", name))
			return G_CALLBACK(cbActorEvent);
		if (compareString("motion-event", name))
			return G_CALLBACK(cbActorEvent);
		if (compareString("leave-event", name))
			return G_CALLBACK(cbActorEvent);
		if (compareString("key-release-event", name))
			return G_CALLBACK(cbActorEvent);
		if (compareString("key-press-event", name))
			return G_CALLBACK(cbActorEvent);
		if (compareString("enter-event", name))
			return G_CALLBACK(cbActorEvent);
		if (compareString("captured-event", name))
			return G_CALLBACK(cbActorEvent);
		if (compareString("button-release-event", name))
			return G_CALLBACK(cbActorEvent);
		if (compareString("button-press-event", name))
			return G_CALLBACK(cbActorEvent);
		if (compareString("event", name))
			return G_CALLBACK(cbActorEvent);
		if (compareString("parent-set", name))
			return G_CALLBACK(cbActor2);
		if (compareString("pick", name))
			return G_CALLBACK(cbActorColor);
		if (compareString("queue-redraw", name))
			return G_CALLBACK(cbActor2);
		return G_CALLBACK(cbActor);
	}

	if (G_TYPE_CHECK_INSTANCE_TYPE(go, CLUTTER_TYPE_BEHAVIOUR)) {
		return G_CALLBACK(cbBehaviour);
	}

	if (G_TYPE_CHECK_INSTANCE_TYPE(go, CLUTTER_TYPE_TIMELINE)) {
		if (compareString("marker-reached", name))
			return G_CALLBACK(cbTimelineMarkerReached);
		if (compareString("completed", name))
			return G_CALLBACK(cbTimeline);
		if (compareString("new-frame", name))
			return G_CALLBACK(cbTimelineNewFrame);
		if (compareString("paused", name))
			return G_CALLBACK(cbTimeline);
		if (compareString("started", name))
			return G_CALLBACK(cbTimeline);
	}

	if (G_TYPE_CHECK_INSTANCE_TYPE(go, CLUTTER_TYPE_ANIMATION)) {
		return G_CALLBACK(cbAnimation);
	}

	//if (G_TYPE_CHECK_INSTANCE_TYPE (go, CLUTTER_TYPE_MODEL)){
	//	if (compareString("row-added", name)) return G_CALLBACK(cbModelIter);
	//	if (compareString("row-changed", name)) return G_CALLBACK(cbModelIter);
	//	if (compareString("row-removed", name)) return G_CALLBACK(cbModelIter);
	//	return G_CALLBACK(cbModel);
	//}

	if (G_TYPE_CHECK_INSTANCE_TYPE(go, CLUTTER_TYPE_SCORE)) {
		if (compareString("timeline-completed", name))
			return G_CALLBACK(cbScoreTimeline);
		if (compareString("timeline-started", name))
			return G_CALLBACK(cbScoreTimeline);
		if (compareString("completed", name))
			return G_CALLBACK(cbScore);
		if (compareString("paused", name))
			return G_CALLBACK(cbScore);
		if (compareString("started", name))
			return G_CALLBACK(cbScore);
	}

	if (G_TYPE_CHECK_INSTANCE_TYPE(go, CLUTTER_TYPE_MEDIA)) {
		if (compareString("eos", name))
			return G_CALLBACK(cbMedia);
		if (compareString("error", name))
			return G_CALLBACK(cbMedia2);
	}

	LOGI("Signal not found for object of type %s. Name was %s", clsname, name);
	return NULL;

}

void signalConnect(JNIEnv *env, jobject source, jstring eventName,
		jclass clazz, jstring cbmethod, jstring signature, jboolean isStatic,
		jint cid, jint when) {
	const char *signal = (*env)->GetStringUTFChars(env, eventName, 0);
	const char *mtname = (*env)->GetStringUTFChars(env, cbmethod, 0);
	const char *methsig = (*env)->GetStringUTFChars(env, signature, 0);
	LOGI(
			"signal connect signal=%s to method=%s, is static=%i, signature=%s, callback=%i, ",
			signal, mtname, isStatic, methsig, cid);
	GObject *go = G_OBJECT((*env)->GetIntField(env, source, field_nobject));
	GCallback callback = getCallback(go, signal);

	if (callback != NULL) {
		jmethodID jim;

		if (isStatic) {
			jim = (*env)->GetStaticMethodID(env, clazz, mtname, methsig);
		} else {
			jim = (*env)->GetMethodID(env, clazz, mtname, methsig);
		}

		JClutterCallback *disp;
		disp = g_new(JClutterCallback, 1);
		disp->method = jim;
		disp->target = cid;
		disp->clazz = clazz;
		disp->isStatic = isStatic;

		g_signal_connect_data(go, signal, callback, disp, NULL, when);
	} else {
		LOGI("Callback not found for signal %s", signal);
	}
	(*env)->ReleaseStringUTFChars(env, eventName, signal);
	(*env)->ReleaseStringUTFChars(env, cbmethod, mtname);
	(*env)->ReleaseStringUTFChars(env, signature, methsig);
}

static void cbBindingPool(GObject *instance, const gchar *action_name,
		guint key_val, ClutterModifierType modifiers, JClutterCallback *disp) {
	JNIEnv *env = attachJVM();
	LOGI("key action name:%s", action_name);
	genericVoidCallback(env, NULL, disp);
	detachJVM();
}

void installBindingPoolAction(ClutterBindingPool *pool, const char *a,
		int key_val, int modifiers, int cbid, jclass clazz, const jmethodID mid) {
	JClutterCallback *disp;
	disp = g_new(JClutterCallback, 1);
	disp->method = mid;
	disp->target = cbid;
	disp->clazz = clazz;
	disp->isStatic = FALSE;
	LOGI("key action name installed:%s for key: %i", a, key_val);
	clutter_binding_pool_install_action(pool, a, key_val, modifiers,
			G_CALLBACK(cbBindingPool), disp, NULL);
}

int threadsAddTimeout(jint target, jint priority, jint interval) {
	return clutter_threads_add_timeout_full(priority, interval, executeTask,
			(gpointer) target, destroyTask);
}

int threadsAddFrameSource(jint target, jint priority, jint fps) {
	return clutter_threads_add_frame_source_full(priority, fps, executeTask,
			(gpointer) target, destroyTask);
}

int threadsAddIdle(jint target, jint priority) {
	return clutter_threads_add_idle_full(priority, executeTask,
			(gpointer) target, destroyTask);
}

int threadsAddRepaint(jint target) {
	return clutter_threads_add_repaint_func(executeTask, (gpointer) target,
			destroyTask);
}
