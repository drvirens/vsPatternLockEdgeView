//
//  PatternLockViewController.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/18/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef PatternLockViewController_hpp
#define PatternLockViewController_hpp

#include "IPatternLockViewController.hpp"
#include "OS.h"

class PatternLockViewController : public IPatternLockViewController
  {
 public:
  static PatternLockViewController* newL(Evas_Object* parent, int columns, int rows);
  virtual ~PatternLockViewController();
  void show();
  
  Evas_Object* evasObject() const;
  
  virtual void viewWillAppear(int animated);
  virtual void viewDidAppear(int animated);
  virtual void viewDidLoad();
  virtual void viewWillDisappear(int animated);
  virtual void viewDidDisappear(int animated);
  
 private:
  PatternLockViewController(Evas_Object* parent, int columns, int rows);
  void construct();
  
 private:
  Evas_Object* parent_;
  Evas_Object* container_;
  int columns_;
  int rows_;
  };

#endif /* PatternLockViewController_hpp */
