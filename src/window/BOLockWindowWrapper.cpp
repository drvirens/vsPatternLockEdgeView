//
//  BOLockWindowWrapper.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/23/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "BOLockWindowWrapper.h"
#include "BOLockScreenWindow.hpp"
#include "trace.hpp"


static BOLockScreenWindow* gBOLockScreenWindow = 0;

extern Evas_Object* wrapper_CreateLockWindow(void)
{TRACE
  Evas_Object* w = 0;
  if (!gBOLockScreenWindow)
  {
    gBOLockScreenWindow = BOLockScreenWindow::newL();
  }
  w = gBOLockScreenWindow->window();
  
  return w;
}
