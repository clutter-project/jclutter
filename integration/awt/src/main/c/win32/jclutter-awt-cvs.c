#include "jclutter-awt-cvs.h"
#include "jawt_md.h"
#include "jawt.h"
#include <clutter/clutter.h>

JNIEXPORT void JNICALL Java_org_jclutter_awt_JClutterCanvas_paint(JNIEnv *env, jobject canvas, jobject graphics){
	 JAWT awt;
	 JAWT_DrawingSurface* ds;
	 JAWT_DrawingSurfaceInfo* dsi;
	 JAWT_Win32DrawingSurfaceInfo* dsi_win;
	 jboolean result;
	 jint lock;

	 // Get the AWT
	 awt.version = JAWT_VERSION_1_3;
	 result = JAWT_GetAWT(env, &awt);
	 assert(result != JNI_FALSE);

	 // Get the drawing surface
	 ds = awt.GetDrawingSurface(env, canvas);
	 assert(ds != NULL);

	 // Lock the drawing surface
	 lock = ds->Lock(ds);
	 assert((lock & JAWT_LOCK_ERROR) == 0);

	 // Get the drawing surface info
	 dsi = ds->GetDrawingSurfaceInfo(ds);

	 // Get the platform-specific drawing info
	 dsi_win = (JAWT_Win32DrawingSurfaceInfo*)dsi->platformInfo;

	 // TODO : What to do next ?
	 HWND hWnd = dsi_win->hwnd;

	 clutter_win32_set_stage_foreign( clutter_stage_get_default(), hWnd);

	 // Free the drawing surface info
	 ds->FreeDrawingSurfaceInfo(dsi);

	 // Unlock the drawing surface
	 ds->Unlock(ds);

	 // Free the drawing surface
	 awt.FreeDrawingSurface(ds);


}
