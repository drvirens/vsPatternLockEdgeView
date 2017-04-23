//
//  BOLockScreenWindow.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/22/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef BOLockScreenWindow_hpp
#define BOLockScreenWindow_hpp

#include "OS.h"

class BOLockScreenWindow
{
 public:
  static BOLockScreenWindow* newL();
  virtual ~BOLockScreenWindow();
  Evas_Object* window();
  
 private:
  BOLockScreenWindow();
  void construct();
  
 private:
  Evas_Object* window_;
  Evas_Object* winbg_;
};

#endif /* BOLockScreenWindow_hpp */
