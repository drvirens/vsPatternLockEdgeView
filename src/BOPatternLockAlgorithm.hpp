//
//  BOPatternLockAlgorithm.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/20/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef BOPatternLockAlgorithm_hpp
#define BOPatternLockAlgorithm_hpp

#include <vector>
#include <set>
#include "OS.h"

using namespace std;

class CNodeContext;

class BOPatternLockAlgorithm
{
 public:
  static BOPatternLockAlgorithm* newL(vector<CNodeContext*>& hotspots);
  virtual ~BOPatternLockAlgorithm();
  void scan(int x, int y, Evas_Event_Mouse_Move* mouse);
  
 private:
  void construct();
  BOPatternLockAlgorithm(vector<CNodeContext*>& hotspots);
  bool isScanned(CNodeContext* c);
  
 private:
  vector<CNodeContext*>& hotspots_;
  set<CNodeContext*> highlighted_;
};

#endif /* BOPatternLockAlgorithm_hpp */
