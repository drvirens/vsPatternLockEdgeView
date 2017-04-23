//
//  BOLockScreenWindow.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/22/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "BOLockScreenWindow.hpp"
#include "bo_clean_tizen_window_always_top.hpp"
#include "trace.hpp"

static Evas_Object* __lock_window_create(void);

BOLockScreenWindow* BOLockScreenWindow::newL()
{TRACE
  BOLockScreenWindow* obj = new BOLockScreenWindow();
  if (obj)
  {
    obj->construct();
  }
  return obj;
}

BOLockScreenWindow::~BOLockScreenWindow()
{TRACE
}

BOLockScreenWindow::BOLockScreenWindow()
: window_(0)
, winbg_(0)
{TRACE
}

void BOLockScreenWindow::construct()
{TRACE
  window_ = __lock_window_create();
}

Evas_Object* BOLockScreenWindow::window()
{TRACE
  BO_ASSERT(window_ != 0);
  return window_;
}

static Evas_Object* __lock_window_create(void)
{TRACE
  return __tizen_lock_window_create();
}

