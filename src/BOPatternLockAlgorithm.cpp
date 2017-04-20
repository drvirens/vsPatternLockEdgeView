//
//  BOPatternLockAlgorithm.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/20/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "BOPatternLockAlgorithm.hpp"
#include "CNodeContext.hpp"
#include "BOHotspot.hpp"
#include "trace.hpp"


BOPatternLockAlgorithm* BOPatternLockAlgorithm::newL(vector<CNodeContext*>& hotspots)
{TRACE
  BOPatternLockAlgorithm* obj = new BOPatternLockAlgorithm(hotspots);
  if (obj)
  {
    obj->construct();
  }
  return obj;
}

BOPatternLockAlgorithm::~BOPatternLockAlgorithm()
{TRACE
}

void BOPatternLockAlgorithm::construct()
{TRACE
}

BOPatternLockAlgorithm::BOPatternLockAlgorithm(vector<CNodeContext*>& hotspots)
: hotspots_(hotspots)
{TRACE
}
bool BOPatternLockAlgorithm::isScanned(CNodeContext* c)
{TRACE
  bool ret = false;
  set<CNodeContext*>::iterator it = highlighted_.find(c); 
  if (it != highlighted_.end())
  {
    ret = true;
  }
  return ret;
}
void BOPatternLockAlgorithm::scan(int x, int y, Evas_Event_Mouse_Move* mouse)
{TRACE
  for (vector<CNodeContext*>::iterator it = hotspots_.begin();
        it != hotspots_.end();
        ++it) 
  {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (!c) 
      {
      continue;  
      }
    if (isScanned(c))
    {
      continue;
    }
    
    bool pointLiesInHotspot = c->hotspot().lies(x, y);
    if (pointLiesInHotspot)
    {
      c->show();
      highlighted_.insert(c);
    }
  } //end for
}

