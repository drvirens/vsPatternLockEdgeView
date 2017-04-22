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
#include <string>
#include <sstream>
#include "OS.h"
#include "NodeColor.hpp"

using namespace std;

class CNodeContext;
class CEdgeContext;
class BOPatternLockAlgorithmObserver;

class BOPatternLockAlgorithm
{
 public:
  static BOPatternLockAlgorithm* newL(vector<CNodeContext*>& hotspots, BOPatternLockAlgorithmObserver& observer);
  virtual ~BOPatternLockAlgorithm();
  void scan(int x, int y, Evas_Event_Mouse_Move* mouse);
  bool isPasswordCorrect();
  void decorate(EHotspotColor color);
  
 private:
  void construct();
  BOPatternLockAlgorithm(vector<CNodeContext*>& hotspots, BOPatternLockAlgorithmObserver& observer);
  bool isScanned(CNodeContext* c);
  void highLightEdge(CNodeContext* prev, CNodeContext* curr);
  
 private:
  vector<CNodeContext*>& hotspots_;
  set<CNodeContext*> highlightedNodes_;
  set<CEdgeContext*> highlightedEdges_;
  CNodeContext* prev_;
  CNodeContext* curr_;
  stringstream enteredPassword_;
  string expectedPassword_;
  BOPatternLockAlgorithmObserver& observer_;
};

#endif /* BOPatternLockAlgorithm_hpp */
