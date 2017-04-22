//
//  IPatternLockViewController.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/18/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef IPatternLockViewController_hpp
#define IPatternLockViewController_hpp

class IPatternLockViewController
  {
 public:
  virtual void viewWillAppear(int animated) = 0;
  virtual void viewDidAppear(int animated) = 0;
  virtual void viewDidLoad() = 0;
  virtual void viewWillDisappear(int animated) = 0;
  virtual void viewDidDisappear(int animated) = 0;
  };

#endif /* IPatternLockViewController_hpp */
