/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2005 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org/> for more information.
 *
 *  Systems in Motion, Postboks 1283, Pirsenteret, 7462 Trondheim, NORWAY.
 *  <URL:http://www.sim.no/>.
 *
\**************************************************************************/

// src/Inventor/Qt/viewers/SoQtViewer.h.  Generated from SoGuiViewer.h.in by configure.

#ifndef SOQT_VIEWER_H
#define SOQT_VIEWER_H

/**************************************************************************\
 * 
 *  A WORD OF ADVICE
 *
 *  It is fruitless to modify the contents of the SoQtViewer.h file
 *  because it is autogenerated by configure from the SoAnyViewer.h.in 
 *  file which you will find in the src/Inventor/Qt/common/ directory.
 *  Do your modifications to that file instead.
 *  
\**************************************************************************/

// Include this first, as a workaround for building on top of SGI and
// TGS Inventor on some Linux distributions. (The bug is in SGI/TGS
// Inventor.)
#include <math.h>

#include <Inventor/SbTime.h>
#include <Inventor/SoType.h>
#include <Inventor/SbLinear.h>

#include <Inventor/Qt/SoQtRenderArea.h>

#ifndef SOQT_INTERNAL
#include <Inventor/events/SoKeyboardEvent.h>
#endif // SOQT_INTERNAL

class SoCallbackList;
class SoBaseColor;
class SoCamera;
class SoComplexity;
class SoDirectionalLight;
class SoDrawStyle;
class SoGetBoundingBoxAction;
class SoGroup;
class SoLightModel;
class SoMaterialBinding;
class SoNode;
class SoPolygonOffset;
class SoSensor;
class SoSeparator;
class SoSwitch;
class SoTimerSensor;

class SoQtViewer;

typedef void SoQtViewerCB(void * data, SoQtViewer * viewer);
typedef void SoQtViewerFPSCB(float fps, void * data, SoQtViewer * viewer);

typedef SbVec2f SoQtAutoClippingCB(void * data, const SbVec2f & nearfar);

// *************************************************************************

class SOQT_DLL_API SoQtViewer : public SoQtRenderArea {
  SOQT_OBJECT_ABSTRACT_HEADER(SoQtViewer, SoQtRenderArea);

public:
  enum Type {
    BROWSER,
    EDITOR
  };

  enum DrawStyle {
    VIEW_AS_IS,
    VIEW_HIDDEN_LINE,
    VIEW_NO_TEXTURE,
    VIEW_LOW_COMPLEXITY,
    VIEW_LINE,
    VIEW_POINT,
    VIEW_BBOX,
    VIEW_LOW_RES_LINE,
    VIEW_LOW_RES_POINT,
    VIEW_SAME_AS_STILL,
    VIEW_WIREFRAME_OVERLAY
  };

  enum DrawType {
    STILL = 0,
    INTERACTIVE
  };

  enum BufferType {
    BUFFER_SINGLE,
    BUFFER_DOUBLE,
    BUFFER_INTERACTIVE
  };

  enum AutoClippingStrategy {
    VARIABLE_NEAR_PLANE,
    CONSTANT_NEAR_PLANE
  };

  virtual void setCamera(SoCamera * camera);
  SoCamera * getCamera(void) const;

  virtual void setCameraType(SoType type);
  SoType getCameraType(void) const;

  virtual void toggleCameraType(void);

  virtual void viewAll(void);

  virtual void saveHomePosition(void);
  virtual void resetToHomePosition(void);

  virtual void setHeadlight(SbBool enable);
  SbBool isHeadlight(void) const;
  SoDirectionalLight * getHeadlight(void) const;

  virtual void setDrawStyle(SoQtViewer::DrawType type, SoQtViewer::DrawStyle style);
  SoQtViewer::DrawStyle getDrawStyle(const SoQtViewer::DrawType type) const;

  virtual void setBufferingType(SoQtViewer::BufferType type);
  SoQtViewer::BufferType getBufferingType(void) const;

  virtual void setViewing(SbBool enable);
  SbBool isViewing(void) const;

  virtual void setCursorEnabled(SbBool enable);
  SbBool isCursorEnabled(void) const;

  void setAutoClipping(SbBool enable);
  SbBool isAutoClipping(void) const;

  void setAutoClippingStrategy(const AutoClippingStrategy strategy,
                               const float value = 0.6f,
                               SoQtAutoClippingCB * cb = NULL,
                               void * cbuserdata = NULL);

  virtual void setStereoViewing(SbBool enable);
  SbBool isStereoViewing(void) const;

  virtual void setStereoOffset(const float dist);
  float getStereoOffset(void) const;

  enum StereoType {
    STEREO_NONE, STEREO_ANAGLYPH, STEREO_QUADBUFFER,
    STEREO_INTERLEAVED_ROWS, STEREO_INTERLEAVED_COLUMNS
  };

  SbBool setStereoType(SoQtViewer::StereoType s);
  SoQtViewer::StereoType getStereoType(void) const;

  void setAnaglyphStereoColorMasks(const SbBool left[3], const SbBool right[3]);
  void getAnaglyphStereoColorMasks(SbBool left[3], SbBool right[3]);

  void setDetailSeek(const SbBool enable);
  SbBool isDetailSeek(void) const;

  void setSeekTime(const float seconds);
  float getSeekTime(void) const;

  void addStartCallback(SoQtViewerCB * func, void * data = NULL);
  void addFinishCallback(SoQtViewerCB * func, void * data = NULL);
  void removeStartCallback(SoQtViewerCB * func, void * data = NULL);
  void removeFinishCallback(SoQtViewerCB * func, void * data = NULL);

  void setWireframeOverlayColor(const SbColor & color);
  const SbColor & getWireframeOverlayColor(void) const;

  virtual void setDoubleBuffer(const SbBool enable);

  virtual void setSceneGraph(SoNode * root);
  virtual SoNode * getSceneGraph(void);

protected:
  SoQtViewer(QWidget * parent,
                const char * name,
                SbBool embed,
                Type type,
                SbBool build);
  ~SoQtViewer();

  virtual void sizeChanged(const SbVec2s & size);
  virtual void setSeekMode(SbBool enable);
  SbBool isSeekMode(void) const;
  SbBool seekToPoint(const SbVec2s screenpos);
  void seekToPoint(const SbVec3f & scenepos);
  virtual void computeSeekFinalOrientation(void);

  virtual void actualRedraw(void);
  virtual SbBool processSoEvent(const SoEvent * const event);

  void interactiveCountInc(void);
  void interactiveCountDec(void);
  int getInteractiveCount(void) const;

  void setSeekDistance(const float distance);
  float getSeekDistance(void) const;
  void setSeekValueAsPercentage(const SbBool on);
  SbBool isSeekValuePercentage(void) const;

  virtual void changeCameraValues(SoCamera * camera);

  void addSuperimposition(SoNode * scene);
  void removeSuperimposition(SoNode * scene);
  void setSuperimpositionEnabled(SoNode * scene, const SbBool enable);
  SbBool getSuperimpositionEnabled(SoNode * scene) const;

private:
  class SoQtViewerP * pimpl;
  friend class SoQtViewerP;
};

// *************************************************************************

#endif // ! SOQT_VIEWER_H
