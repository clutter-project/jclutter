#include "jclutter-gst.h"
#include <clutter/clutter.h>
#include <clutter-gst/clutter-gst.h>

JNIEXPORT void JNICALL Java_org_jclutter_ext_gst_Video_init(JNIEnv *env, jclass cl, jobjectArray jargs) {
	clutter_gst_init(NULL, NULL);
}
JNIEXPORT jint JNICALL Java_org_jclutter_ext_gst_Video_newInstance(JNIEnv *env,
		jclass) {
	return (jint)clutter_gst_video_texture_new();
}
JNIEXPORT jint JNICALL Java_org_jclutter_ext_gst_Video_getMajorVersion(JNIEnv *env,
		jclass jc) {
	return CLUTTER_GST_MAJOR_VERSION;
}
JNIEXPORT jint JNICALL Java_org_jclutter_ext_gst_Video_getMinorVersion(JNIEnv *env,
		jclass jc) {
	return CLUTTER_GST_MINOR_VERSION;
}
JNIEXPORT jint JNICALL Java_org_jclutter_ext_gst_Video_getMicroVersion(JNIEnv *env,
		jclass jc) {
	return CLUTTER_GST_MICRO_VERSION;
}
JNIEXPORT jstring JNICALL Java_org_jclutter_ext_gst_Video_getVersion(JNIEnv *env,
		jclass jc) {
	return ((*env)->NewStringUTF(env, CLUTTER_GST_VERSION_S));
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_ext_gst_Video_checkVersion(
		JNIEnv *env, jclass jc, jint maj, jint min, jint mic) {
	return clutter_gst_check_version(maj, min, mic);
}
