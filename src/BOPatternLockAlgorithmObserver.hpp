//
//  BOPatternLockAlgorithmObserver.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/20/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef BOPatternLockAlgorithmObserver_hpp
#define BOPatternLockAlgorithmObserver_hpp

#include "OS.h"

class CNodeContext;

class BOPatternLockAlgorithmObserver
{
 public:
  virtual ~BOPatternLockAlgorithmObserver() {}
  virtual void didEnterInsideHotspot(Evas_Event_Mouse_Move* mouse, CNodeContext& nodeContext) = 0;
};



#endif /* BOPatternLockAlgorithmObserver_hpp */
