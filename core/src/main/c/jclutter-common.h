#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include <clutter/clutter.h>

#ifdef __cplusplus
 extern "C" {
#endif

typedef struct
{
	int target;
	jmethodID method;
	jclass clazz;
	jboolean isStatic;
} JClutterCallback;

void LOGI(const char *, ...);

void jniClutterException(JNIEnv *, const char *);

gpointer getGPointer(JNIEnv *, jobject);

void arrayStringsFromJava(JNIEnv *, char**, jobjectArray);

ClutterActor * actorFromJava(JNIEnv *, jobject);

ClutterShader * shaderFromJava(JNIEnv *, jobject);

jobject toJavaShader(JNIEnv *, ClutterShader *);

ClutterStage * stageFromJava(JNIEnv *, jobject);

ClutterTexture * textureFromJava(JNIEnv *, jobject);

ClutterRectangle * rectangleFromJava(JNIEnv *, jobject);

ClutterEvent * eventFromJava(JNIEnv *, jobject);

ClutterModel * modelFromJava(JNIEnv *, jobject);

ClutterModelIter * modelIterFromJava(JNIEnv *, jobject);

ClutterAlpha * alphaFromJava(JNIEnv *, jobject);

jobject toJavaAlpha(JNIEnv *, ClutterAlpha *);

ClutterTimeline * timelineFromJava(JNIEnv *, jobject);

jobject createJavaTimeline(JNIEnv *, ClutterTimeline *);

ClutterAnimation * animationFromJava(JNIEnv *, jobject);

ClutterContainer * containerFromJava(JNIEnv *, jobject);

ClutterGroup * groupFromJava(JNIEnv *, jobject);

ClutterText * textFromJava(JNIEnv *, jobject);

ClutterBackend * backendFromJava(JNIEnv *, jobject);

ClutterScript * scriptFromJava(JNIEnv *, jobject);

ClutterScore * scoreFromJava(JNIEnv *, jobject);

ClutterBehaviourScale * behaviourScaleFromJava(JNIEnv *, jobject);

ClutterBehaviourRotate * behaviourRotateFromJava(JNIEnv *, jobject);

ClutterBehaviourPath * behaviourPathFromJava(JNIEnv *, jobject);

ClutterBehaviourOpacity * behaviourOpacityFromJava(JNIEnv *, jobject);

ClutterBehaviourDepth * behaviourDepthFromJava(JNIEnv *, jobject);

ClutterBehaviourEllipse * behaviourEllipseFromJava(JNIEnv *, jobject);

ClutterBehaviour * behaviourFromJava(JNIEnv *, jobject);

ClutterPath * pathFromJava(JNIEnv *, jobject);

//TODO
ClutterPathNode * pathNodeFromJava(JNIEnv *, jobject);
jobject toJavaPathNode(JNIEnv *, ClutterPathNode *);

jobject toJavaGeometry(JNIEnv *, ClutterGeometry *);

jobject toJavaScale(JNIEnv *, double, double, float, float);

jobject toJavaRotation(JNIEnv *, int, double, float, float, float);

void rotationFromJava(JNIEnv *, jobject, ClutterRotateAxis *, double *, float *, float *, float *);

jobject toJavaDimension(JNIEnv *, float, float);

jobject toJavaActorBox(JNIEnv *, ClutterActorBox *);

ClutterActorBox * actorBoxFromJava(JNIEnv *, jobject);

jobject toJavaFog(JNIEnv *, float, float);

jobject toJavaPoint(JNIEnv *, float, float, float);

ClutterTextureQuality toTextureQuality(int);

ClutterTimelineDirection toTimelineDirection(int);

ClutterRotateDirection toRotateDirection(int);

ClutterRotateAxis toRotateAxis(int);

ClutterKnot knotFromJava(JNIEnv *, jobject);

ClutterKnot ** knotsFromJava(JNIEnv *, jobjectArray);

void colorFromJava(JNIEnv *, jobject, ClutterColor *);

jobject findJavaGObject(JNIEnv *, GObject *);

jobject toJavaColor(JNIEnv *, ClutterColor *);

jobject toJavaAnimation(JNIEnv *, ClutterAnimation *);

jobject toJavaActor(JNIEnv *, ClutterActor *);

jobject toJavaUnits(JNIEnv *, ClutterUnits *);

jobject createJavaStage(JNIEnv *, ClutterStage *);

ClutterUnits * unitsFromJava(JNIEnv *, jobject);

jobject toJavaInputDevice(JNIEnv *, ClutterInputDevice *);

jobject createJavaKeyBindingPool(JNIEnv *, ClutterBindingPool *);

float getPointX(JNIEnv *, jobject);

float getPointY(JNIEnv *, jobject);

float getPointZ(JNIEnv *, jobject);

void signalConnect(JNIEnv *, jobject, jstring, jclass, jstring, jstring, jboolean, jint, jint);

void installBindingPoolAction(ClutterBindingPool *, const char*, int, int, int, jclass, jmethodID);

int threadsAddTimeout(jint, jint, jint);

int threadsAddFrameSource(jint, jint, jint);

int threadsAddIdle(jint, jint);

int threadsAddRepaint(jint);

jobject createJavaCoglTexture(JNIEnv *, CoglHandle *);

CoglHandle coglTextureFromJava(JNIEnv *, jobject);

CoglColor * coglColorFromJava(JNIEnv *, jobject);

CoglMatrix * coglMatrixFromJava(JNIEnv *, jobject);

jobject toJavaCoglColor(JNIEnv *, CoglColor *);

jobject toJavaCoglMatrix(JNIEnv *, CoglMatrix *);

#ifdef __cplusplus
 }
#endif

