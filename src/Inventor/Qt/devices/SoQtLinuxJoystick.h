/**************************************************************************\
 *
 *  This file is part of the Coin GUI toolkit libraries.
 *  Copyright (C) 1998-2002 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation.  See the
 *  file LICENSE.LGPL at the root directory of this source distribution
 *  for more details.
 *
 *  If you want to use this library with software that is incompatible
 *  licensewise with the LGPL, and / or you would like to take
 *  advantage of the additional benefits with regard to our support
 *  services, please contact Systems in Motion about acquiring a Coin
 *  Professional Edition License.  See <URL:http://www.coin3d.org> for
 *  more information.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  <URL:http://www.sim.no>, <mailto:support@sim.no>
 *
\**************************************************************************/

#ifndef SOQT_LINUXJOYSTICK_H
#define SOQT_LINUXJOYSTICK_H

#include <Inventor/SbBasic.h>
#include <Inventor/events/SoButtonEvent.h>

#include <Inventor/Qt/devices/SoQtDevice.h>

class QSocketNotifier;
class SbPList;
class SoMotion3Event;
class SoSpaceballButtonEvent;

// *************************************************************************

#define SO_QT_ALL_LINUX_JOYSTICK_EVENTS SoQtLinuxJoystick::ALL_EVENTS

class SOQT_DLL_API SoQtLinuxJoystick : public SoQtDevice {
  SOQT_OBJECT_HEADER(SoQtLinuxJoystick, SoQtDevice);

public:
  enum Events {
    ALL_EVENTS = 0
  };

  SoQtLinuxJoystick(int events = ALL_EVENTS);
  virtual ~SoQtLinuxJoystick(void);

  virtual void enable(QWidget * widget, SoQtEventHandler * handler,
      void * closure);
  virtual void disable(QWidget * widget, SoQtEventHandler * handler,
      void * closure);

  virtual const SoEvent * translateEvent(QEvent * event);

  void setRotationScaleFactor(const float factor);
  float getRotationScaleFactor(void) const;
  void setTranslationScaleFactor(const float factor);
  float getTranslationScaleFactor(void) const;

  static SbBool exists(void);

  void setFocusToWindow(SbBool enable);
  SbBool isFocusToWindow(void) const;

  int getNumButtons(void) const;
  SbBool getButtonValue(const int button) const;

  int getNumAxes(void) const;
  float getAxisValue(const int axis) const;

private:
  class SoQtLinuxJoystickP * pimpl;
  friend class SoQtLinuxJoystickP;
};

// *************************************************************************

#endif // ! SOQT_LINUXJOYSTICK_H
