#include "jclutter-cairo.h"

JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_destroy(JNIEnv *env, jobject obj){
cairo_context_destroy();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_save(JNIEnv *env, jobject obj){
cairo_context_save();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_fill(JNIEnv *env, jobject obj){
cairo_context_fill();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_rotate(JNIEnv *env, jobject obj, jdouble param0){
cairo_context_rotate();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_mask(JNIEnv *env, jobject obj, jobject param0){
cairo_context_mask();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_scale(JNIEnv *env, jobject obj, jdouble param0, jdouble param1){
cairo_context_scale();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setSource(JNIEnv *env, jobject obj, jdouble param0, jdouble param1, jdouble param2, jdouble param3){
cairo_context_set_source();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setSource(JNIEnv *env, jobject obj, jobject param0){
cairo_context_set_source();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setSource(JNIEnv *env, jobject obj, jdouble param0, jdouble param1, jdouble param2){
cairo_context_set_source();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_status(JNIEnv *env, jobject obj){
return (jint)cairo_context_status();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_restore(JNIEnv *env, jobject obj){
cairo_context_restore();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_pushGroup(JNIEnv *env, jobject obj){
cairo_context_push_group();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cairo_CairoContext_popGroup(JNIEnv *env, jobject obj){
return (jobject)cairo_context_pop_group();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_popGroupToSource(JNIEnv *env, jobject obj){
cairo_context_pop_group_to_source();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cairo_CairoContext_getSource(JNIEnv *env, jobject obj){
return (jobject)cairo_context_get_source();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setAntialias(JNIEnv *env, jobject obj, jint param0){
cairo_context_set_antialias();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getAntialias(JNIEnv *env, jobject obj){
return (jint)cairo_context_get_antialias();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setDash(JNIEnv *env, jobject obj, jobject param0, jdouble param1){
cairo_context_set_dash();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getDashCount(JNIEnv *env, jobject obj){
return (jint)cairo_context_get_dash_count();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setFillRule(JNIEnv *env, jobject obj, jint param0){
cairo_context_set_fill_rule();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getFillRule(JNIEnv *env, jobject obj){
return (jint)cairo_context_get_fill_rule();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setLineCap(JNIEnv *env, jobject obj, jint param0){
cairo_context_set_line_cap();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getLineCap(JNIEnv *env, jobject obj){
return (jint)cairo_context_get_line_cap();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setLineJoin(JNIEnv *env, jobject obj, jint param0){
cairo_context_set_line_join();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getLineJoin(JNIEnv *env, jobject obj){
return (jint)cairo_context_get_line_join();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setLineWidth(JNIEnv *env, jobject obj, jdouble param0){
cairo_context_set_line_width();
}
JNIEXPORT jdouble JNICALL Java_org_jclutter_cairo_CairoContext_getLineWidth(JNIEnv *env, jobject obj){
return (jdouble)cairo_context_get_line_width();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setMiterLimit(JNIEnv *env, jobject obj, jdouble param0){
cairo_context_set_miter_limit();
}
JNIEXPORT jdouble JNICALL Java_org_jclutter_cairo_CairoContext_getMiterLimit(JNIEnv *env, jobject obj){
return (jdouble)cairo_context_get_miter_limit();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setOperator(JNIEnv *env, jobject obj, jint param0){
cairo_context_set_operator();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getOperator(JNIEnv *env, jobject obj){
return (jint)cairo_context_get_operator();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setTolerance(JNIEnv *env, jobject obj, jdouble param0){
cairo_context_set_tolerance();
}
JNIEXPORT jdouble JNICALL Java_org_jclutter_cairo_CairoContext_getTolerance(JNIEnv *env, jobject obj){
return (jdouble)cairo_context_get_tolerance();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_clip(JNIEnv *env, jobject obj){
cairo_context_clip();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_clipPreserve(JNIEnv *env, jobject obj){
cairo_context_clip_preserve();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_resetClip(JNIEnv *env, jobject obj){
cairo_context_reset_clip();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_fillPreserve(JNIEnv *env, jobject obj){
cairo_context_fill_preserve();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cairo_CairoContext_inFill(JNIEnv *env, jobject obj, jdouble param0, jdouble param1){
return (jboolean)cairo_context_in_fill();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_paint(JNIEnv *env, jobject obj){
cairo_context_paint();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_paintWithAlpha(JNIEnv *env, jobject obj, jdouble param0){
cairo_context_paint_with_alpha();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_stroke(JNIEnv *env, jobject obj){
cairo_context_stroke();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_strokePreserve(JNIEnv *env, jobject obj){
cairo_context_stroke_preserve();
}
JNIEXPORT jboolean JNICALL Java_org_jclutter_cairo_CairoContext_inStroke(JNIEnv *env, jobject obj, jdouble param0, jdouble param1){
return (jboolean)cairo_context_in_stroke();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_copyPage(JNIEnv *env, jobject obj){
cairo_context_copy_page();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_showPage(JNIEnv *env, jobject obj){
cairo_context_show_page();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoContext_getReferenceCount(JNIEnv *env, jobject obj){
return (jint)cairo_context_get_reference_count();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_tranaslate(JNIEnv *env, jobject obj, jdouble param0, jdouble param1){
cairo_context_tranaslate();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_setFontSize(JNIEnv *env, jobject obj, jdouble param0){
cairo_context_set_font_size();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_showText(JNIEnv *env, jobject obj, jstring param0){
cairo_context_show_text();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_newPath(JNIEnv *env, jobject obj){
cairo_context_new_path();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_newSubPath(JNIEnv *env, jobject obj){
cairo_context_new_sub_path();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_closePath(JNIEnv *env, jobject obj){
cairo_context_close_path();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_arc(JNIEnv *env, jobject obj, jdouble param0, jdouble param1, jdouble param2, jdouble param3, jdouble param4){
cairo_context_arc();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_arcNegative(JNIEnv *env, jobject obj, jdouble param0, jdouble param1, jdouble param2, jdouble param3, jdouble param4){
cairo_context_arc_negative();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_curveTo(JNIEnv *env, jobject obj, jdouble param0, jdouble param1, jdouble param2, jdouble param3, jdouble param4, jdouble param5){
cairo_context_curve_to();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_lineTo(JNIEnv *env, jobject obj, jdouble param0, jdouble param1){
cairo_context_line_to();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_moveTo(JNIEnv *env, jobject obj, jdouble param0, jdouble param1){
cairo_context_move_to();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_rectangle(JNIEnv *env, jobject obj, jdouble param0, jdouble param1, jdouble param2, jdouble param3){
cairo_context_rectangle();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_textPath(JNIEnv *env, jobject obj, jstring param0){
cairo_context_text_path();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_relCurveTo(JNIEnv *env, jobject obj, jdouble param0, jdouble param1, jdouble param2, jdouble param3, jdouble param4, jdouble param5){
cairo_context_rel_curve_to();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_relLineTo(JNIEnv *env, jobject obj, jdouble param0, jdouble param1){
cairo_context_rel_line_to();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoContext_relMoveTo(JNIEnv *env, jobject obj, jdouble param0, jdouble param1){
cairo_context_rel_move_to();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_destroy(JNIEnv *env, jobject obj){
cairo_pattern_destroy();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_getType(JNIEnv *env, jobject obj){
return (jint)cairo_pattern_get_type();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_create(JNIEnv *env, jclass cl, jdouble param0, jdouble param1, jdouble param2){
return (jint)cairo_pattern_create();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_status(JNIEnv *env, jobject obj){
return (jint)cairo_pattern_status();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_getReferenceCount(JNIEnv *env, jobject obj){
return (jint)cairo_pattern_get_reference_count();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_createWithAlpha(JNIEnv *env, jclass cl, jdouble param0, jdouble param1, jdouble param2, jdouble param3){
return (jint)cairo_pattern_create_with_alpha();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_createLinear(JNIEnv *env, jclass cl, jdouble param0, jdouble param1, jdouble param2, jdouble param3){
return (jint)cairo_pattern_create_linear();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_createRadial(JNIEnv *env, jclass cl, jdouble param0, jdouble param1, jdouble param2, jdouble param3, jdouble param4, jdouble param5){
return (jint)cairo_pattern_create_radial();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_addColorStop(JNIEnv *env, jobject obj, jdouble param0, jdouble param1, jdouble param2, jdouble param3){
cairo_pattern_add_color_stop();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_addColorStopWithAlpha(JNIEnv *env, jobject obj, jdouble param0, jdouble param1, jdouble param2, jdouble param3, jdouble param4){
cairo_pattern_add_color_stop_with_alpha();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_getColorStopCount(JNIEnv *env, jobject obj){
return (jint)cairo_pattern_get_color_stop_count();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_reference(JNIEnv *env, jobject obj){
cairo_pattern_reference();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_setExtend(JNIEnv *env, jobject obj, jint param0){
cairo_pattern_set_extend();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_getExtend(JNIEnv *env, jobject obj){
return (jint)cairo_pattern_get_extend();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoPattern_setFilter(JNIEnv *env, jobject obj, jint param0){
cairo_pattern_set_filter();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoPattern_getFilter(JNIEnv *env, jobject obj){
return (jint)cairo_pattern_get_filter();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoTexture_clear(JNIEnv *env, jobject obj){
cairo_texture_clear();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoTexture_newInstance(JNIEnv *env, jclass cl, jint param0, jint param1){
return (jint)cairo_texture_new();
}
JNIEXPORT void JNICALL Java_org_jclutter_cairo_CairoTexture_setSurfaceSize(JNIEnv *env, jobject obj, jint param0, jint param1){
cairo_texture_set_surface_size();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoTexture_getSurfaceWidth(JNIEnv *env, jobject obj){
return (jint)cairo_texture_get_surface_width();
}
JNIEXPORT jint JNICALL Java_org_jclutter_cairo_CairoTexture_getSurfaceHeight(JNIEnv *env, jobject obj){
return (jint)cairo_texture_get_surface_height();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cairo_CairoTexture_createContext(JNIEnv *env, jobject obj){
return (jobject)cairo_texture_create_context();
}
JNIEXPORT jobject JNICALL Java_org_jclutter_cairo_CairoTexture_createRegion(JNIEnv *env, jobject obj, jint param0, jint param1, jint param2, jint param3){
return (jobject)cairo_texture_create_region();
}
