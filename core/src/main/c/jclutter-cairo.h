#include <jni.h>

JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_destroy(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_save(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_fill(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_rotate(JNIEnv *, jobject, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_mask(JNIEnv *, jobject, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_scale(JNIEnv *, jobject, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setSource(JNIEnv *, jobject, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setSource(JNIEnv *, jobject, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setSource(JNIEnv *, jobject, jdouble, jdouble, jdouble);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_status(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_restore(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_pushGroup(JNIEnv *, jobject);
JNIEXPORT jobject JNICALL Java_org_jclutter_cairo_CairoContext_popGroup(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_popGroupToSource(JNIEnv *, jobject);
JNIEXPORT jobject JNICALL Java_org_jclutter_cairo_CairoContext_getSource(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setAntialias(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getAntialias(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setDash(JNIEnv *, jobject, jobject, jdouble);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getDashCount(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setFillRule(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getFillRule(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setLineCap(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getLineCap(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setLineJoin(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getLineJoin(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setLineWidth(JNIEnv *, jobject, jdouble);
JNIEXPORT jdouble JNICALL Java_org_jclutter_cairo_CairoContext_getLineWidth(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setMiterLimit(JNIEnv *, jobject, jdouble);
JNIEXPORT jdouble JNICALL Java_org_jclutter_cairo_CairoContext_getMiterLimit(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setOperator(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getOperator(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setTolerance(JNIEnv *, jobject, jdouble);
JNIEXPORT jdouble JNICALL Java_org_jclutter_cairo_CairoContext_getTolerance(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_clip(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_clipPreserve(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_resetClip(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_fillPreserve(JNIEnv *, jobject);
JNIEXPORT jboolean JNICALL Java_org_jclutter_cairo_CairoContext_inFill(JNIEnv *, jobject, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_paint(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_paintWithAlpha(JNIEnv *, jobject, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_stroke(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_strokePreserve(JNIEnv *, jobject);
JNIEXPORT jboolean JNICALL Java_org_jclutter_cairo_CairoContext_inStroke(JNIEnv *, jobject, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_copyPage(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_showPage(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getReferenceCount(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_tranaslate(JNIEnv *, jobject, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setFontSize(JNIEnv *, jobject, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_showText(JNIEnv *, jobject, jstring);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_newPath(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_newSubPath(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_closePath(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_arc(JNIEnv *, jobject, jdouble, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_arcNegative(JNIEnv *, jobject, jdouble, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_curveTo(JNIEnv *, jobject, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_lineTo(JNIEnv *, jobject, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_moveTo(JNIEnv *, jobject, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_rectangle(JNIEnv *, jobject, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_textPath(JNIEnv *, jobject, jstring);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_relCurveTo(JNIEnv *, jobject, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_relLineTo(JNIEnv *, jobject, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_relMoveTo(JNIEnv *, jobject, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_destroy(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_getType(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_create(JNIEnv *, jclass, jdouble, jdouble, jdouble);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_status(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_getReferenceCount(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_createWithAlpha(JNIEnv *, jclass, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_createLinear(JNIEnv *, jclass, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_createRadial(JNIEnv *, jclass, jdouble, jdouble, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_addColorStop(JNIEnv *, jobject, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_addColorStopWithAlpha(JNIEnv *, jobject, jdouble, jdouble, jdouble, jdouble, jdouble);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_getColorStopCount(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_reference(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_setExtend(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_getExtend(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_setFilter(JNIEnv *, jobject, jint);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_getFilter(JNIEnv *, jobject);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoTexture_clear(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoTexture_newInstance(JNIEnv *, jclass, jint, jint);
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoTexture_setSurfaceSize(JNIEnv *, jobject, jint, jint);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoTexture_getSurfaceWidth(JNIEnv *, jobject);
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoTexture_getSurfaceHeight(JNIEnv *, jobject);
JNIEXPORT jobject JNICALL Java_org_jclutter_cairo_CairoTexture_createContext(JNIEnv *, jobject);
JNIEXPORT jobject JNICALL Java_org_jclutter_cairo_CairoTexture_createRegion(JNIEnv *, jobject, jint, jint, jint, jint);