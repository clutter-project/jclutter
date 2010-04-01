#include <jni.h>

JNIEXPORT void JNICALL Java_org_jclutter_ext_gst_Video_init(JNIEnv *, jclass, jobjectArray);
JNIEXPORT jint JNICALL Java_org_jclutter_ext_gst_Video_newInstance(JNIEnv *, jclass);
JNIEXPORT jint JNICALL Java_org_jclutter_ext_gst_Video_getMajorVersion(JNIEnv *, jclass);
JNIEXPORT jint JNICALL Java_org_jclutter_ext_gst_Video_getMinorVersion(JNIEnv *, jclass);
JNIEXPORT jint JNICALL Java_org_jclutter_ext_gst_Video_getMicroVersion(JNIEnv *, jclass);
JNIEXPORT jstring JNICALL Java_org_jclutter_ext_gst_Video_getVersion(JNIEnv *, jclass);
JNIEXPORT jboolean JNICALL Java_org_jclutter_ext_gst_Video_checkVersion(JNIEnv *, jclass, jint, jint, jint);
