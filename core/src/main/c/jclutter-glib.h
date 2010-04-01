#include <jni.h>

JNIEXPORT jint JNICALL Java_org_jclutter_glib_GObject_getGType(JNIEnv *, jobject, jstring);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_unref(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_connect(JNIEnv *, jobject, jstring, jclass, jstring, jstring, jboolean, jint, jint);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_disconnect(JNIEnv *, jobject, jlong);
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GObject_isConnected(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_block(JNIEnv *, jobject, jlong);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_unblock(JNIEnv *, jobject, jlong);
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GObject_hasProperty(JNIEnv *,jobject,jstring);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setBooleanProperty(JNIEnv *,jobject,jstring,jboolean);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setStringProperty(JNIEnv *,jobject,jstring,jstring);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setFloatProperty(JNIEnv *,jobject,jstring,jfloat);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setDoubleProperty(JNIEnv *,jobject,jstring,jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setIntProperty(JNIEnv *,jobject,jstring,jint);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setLongProperty(JNIEnv *,jobject,jstring,jlong);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GObject_setCharProperty(JNIEnv *,jobject,jstring,jchar);
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GObject_getBooleanProperty(JNIEnv *,jobject,jstring);
JNIEXPORT jstring JNICALL Java_org_jclutter_glib_GObject_getStringProperty(JNIEnv *,jobject,jstring);
JNIEXPORT jfloat JNICALL Java_org_jclutter_glib_GObject_getFloatProperty(JNIEnv *,jobject,jstring);
JNIEXPORT jdouble JNICALL Java_org_jclutter_glib_GObject_getDoubleProperty(JNIEnv *,jobject,jstring);
JNIEXPORT jint JNICALL Java_org_jclutter_glib_GObject_getIntProperty(JNIEnv *,jobject,jstring);
JNIEXPORT jlong JNICALL Java_org_jclutter_glib_GObject_getLongProperty(JNIEnv *,jobject,jstring);
JNIEXPORT jchar JNICALL Java_org_jclutter_glib_GObject_getCharProperty(JNIEnv *,jobject,jstring);

JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_Glib_mainContextPending(JNIEnv *, jclass);
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_Glib_mainContextIteration(JNIEnv *, jclass, jboolean);
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_Glib_setEnv(JNIEnv *, jclass, jstring, jstring, jboolean);
JNIEXPORT void JNICALL Java_org_jclutter_glib_Glib_unsetEnv(JNIEnv *, jclass, jstring);
JNIEXPORT jstring JNICALL Java_org_jclutter_glib_Glib_getEnv(JNIEnv *, jclass, jstring);
JNIEXPORT void JNICALL Java_org_jclutter_glib_Glib_threadInit(JNIEnv *, jclass);

JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GList_add(JNIEnv *, jobject, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GList_addAt(JNIEnv *, jobject, jint, jobject);
JNIEXPORT jobject JNICALL Java_org_jclutter_glib_GList_get(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_org_jclutter_glib_GList_indexOf(JNIEnv *, jobject, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GList_clear(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_org_jclutter_glib_GList_size(JNIEnv *, jobject);
JNIEXPORT jobject JNICALL Java_org_jclutter_glib_GList_remove(JNIEnv *, jobject, jint);
JNIEXPORT jobject JNICALL Java_org_jclutter_glib_GList_set(JNIEnv *, jobject, jint, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GListIterator_add(JNIEnv *, jobject, jobject);
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GListIterator_hasNext(JNIEnv *, jobject);
JNIEXPORT jobject JNICALL Java_org_jclutter_glib_GListIterator_next(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_glib_GListIterator_set(JNIEnv *, jobject, jobject);
JNIEXPORT jboolean JNICALL Java_org_jclutter_glib_GListIterator_hasPrevious(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_org_jclutter_glib_GListIterator_nextIndex(JNIEnv *, jobject);
JNIEXPORT jobject JNICALL Java_org_jclutter_glib_GListIterator_previous(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_org_jclutter_glib_GListIterator_previousIndex(JNIEnv *, jobject);
