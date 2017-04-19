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

class BOImageTable;
class BOPatternbLockConfig;

class PatternLockViewController : public IPatternLockViewController
  {
 public:
  static PatternLockViewController* newL(const BOPatternbLockConfig& config, Evas_Object* parent);
  virtual ~PatternLockViewController();
  void show();
  
  Evas_Object* evasObject() const;
  
  virtual void viewWillAppear(int animated);
  virtual void viewDidAppear(int animated);
  virtual void viewDidLoad();
  virtual void viewWillDisappear(int animated);
  virtual void viewDidDisappear(int animated);
  
 private:
  PatternLockViewController(const BOPatternbLockConfig& config, Evas_Object* parent);
  void construct();
  void createTable();
  void createImages();
  void addImagesInTable();
  
 private:
  Evas_Object* parent_;
  Evas_Object* container_;
  BOImageTable* table_;
  const BOPatternbLockConfig& config_;
  };

#endif /* PatternLockViewController_hpp */
