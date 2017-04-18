//
//  PatternLockViewController.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/18/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef PatternLockViewController_hpp
#define PatternLockViewController_hpp

class PatternLockViewController
  {
 public:
  static PatternLockViewController* newL();
  virtual ~PatternLockViewController();
  void show();
  
 private:
  PatternLockViewController();
  void construct();
  };

#endif /* PatternLockViewController_hpp */
