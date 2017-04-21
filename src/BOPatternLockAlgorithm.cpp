//
//  BOPatternLockAlgorithm.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/20/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "BOPatternLockAlgorithm.hpp"
#include "CNodeContext.hpp"
#include "CEdgeContext.hpp"
#include "BOHotspot.hpp"
#include "BOPatternLockAlgorithmObserver.hpp"
#include "trace.hpp"

BOPatternLockAlgorithm* BOPatternLockAlgorithm::newL(vector<CNodeContext*>& hotspots, BOPatternLockAlgorithmObserver& observer)
{TRACE
  BOPatternLockAlgorithm* obj = new BOPatternLockAlgorithm(hotspots, observer);
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

BOPatternLockAlgorithm::BOPatternLockAlgorithm(vector<CNodeContext*>& hotspots, BOPatternLockAlgorithmObserver& observer)
: hotspots_(hotspots)
, observer_(observer)
, prev_(0)
, curr_(0)
{TRACE
}
bool BOPatternLockAlgorithm::isScanned(CNodeContext* c)
{TRACE
  bool ret = false;
  set<CNodeContext*>::iterator it = highlightedNodes_.find(c); 
  if (it != highlightedNodes_.end())
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
    if (!pointLiesInHotspot)
    {
      continue;
    }
    
    prev_ = curr_;
    curr_ = c;
    //check which edge needs to be higlighted
    highLightEdge(prev_, curr_);



    c->show();
    highlightedNodes_.insert(c);
    observer_.didEnterInsideHotspot(mouse, *c);
    
//    prev_ = curr_;
//    curr_ = c;
//
//    //check which edge needs to be higlighted
//    highLightEdge(prev_, curr_);
    break;

  } //end for
}

void BOPatternLockAlgorithm::highLightEdge(CNodeContext* prev, CNodeContext* curr)
{TRACE
  if ( !(prev && curr) )
  {
    DBG("to highlight edge we need two nodes");
    return;
  }
  int p = prev->index();
  int c = curr->index();
  DBG("Highlight edge between nodes [%d] and [%d]", p, c);
  CEdgeContext* edge = observer_.getEdgeBetweenNodes(p, c);
  //BO_ASSERT(edge != 0);
  if (edge)
  {
    edge->show();
  }
  else
  {
    DBG("we dont have image for this edge");
  }
}
