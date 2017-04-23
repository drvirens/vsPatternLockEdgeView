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
, prev_(0)
, curr_(0)
, enteredPassword_("")
, expectedPassword_("1234")
, observer_(observer)
{TRACE
}

bool BOPatternLockAlgorithm::isPasswordCorrect()
{TRACE
  string p = enteredPassword_.str();
  bool ret = (p == expectedPassword_);
  return ret;
}

void BOPatternLockAlgorithm::decorate(EHotspotColor color)
{TRACE
  decorateHighlightedNodes(color);
  decorateHighlightedEdges(color);
}

void BOPatternLockAlgorithm::decorateHighlightedNodes(EHotspotColor color)
{TRACE
  for (set<CNodeContext*>::iterator it = highlightedNodes_.begin();
      it != highlightedNodes_.end();
      ++it)
  {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (!c) 
      {
      break;  
      }
    if (color == eRed)
    {
      c->error();
    }
    else if (color == eGreen)
    {
      c->ok();
    }
  } //end for
}
void BOPatternLockAlgorithm::decorateHighlightedEdges(EHotspotColor color)
{TRACE
  for (set<CEdgeContext*>::iterator it = highlightedEdges_.begin();
      it != highlightedEdges_.end();
      ++it)
  {
    CEdgeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (!c) 
    {
      break;  
    }
    if (color == eRed)
    {
      c->error();
    }
    else if (color == eGreen)
    {
      c->ok();
    }
  } //end for
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

bool BOPatternLockAlgorithm::isEdgeHighighted(CEdgeContext* e)
{TRACE
  bool ret = false;
  set<CEdgeContext*>::iterator it = highlightedEdges_.find(e); 
  if (it != highlightedEdges_.end())
  {
    ret = true;
  }
  return ret;
}

void BOPatternLockAlgorithm::processNode(CNodeContext* c, Evas_Event_Mouse_Move* mouse)
{TRACE
  c->show();
  highlightedNodes_.insert(c);
  int index = c->index();
  enteredPassword_ << index;
  string p = enteredPassword_.str();
  DBG("enteredPassword_ is [%s], index is [%d]\n", p.c_str(), index);
  
  observer_.didEnterInsideHotspot(mouse, *c);
}

//if line intersects middle node, and middle not is not highlighted already, then highlight middle node
//and also the edges
bool BOPatternLockAlgorithm::checkLineRectIntersection(int lineX1, int lineY1, int lineX2, int lineY2, Evas_Event_Mouse_Move* mouse)
{TRACE
  bool intersects = true;
  //XXX: use line clip algorithm here
  
  if (intersects)
  {
  }
  
  return intersects;
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
      return;  
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

    if (prev_ != curr_)
    {
      higlight(c, mouse);
    }

//    return;
  } //end for
}

void BOPatternLockAlgorithm::higlight(CNodeContext* c, Evas_Event_Mouse_Move* mouse)
{TRACE
  bool highlightedNodesEmpty = highlightedNodes_.empty();
  if (highlightedNodesEmpty)
  {
    processNode(c, mouse);
    return;
  }
  
  bool edgeExists = highLightEdge(prev_, curr_);
  if (edgeExists) //some edge was highlighted
  {
    processNode(c, mouse);
    return;
  } 
}


static bool isValidNodeNumber(int nodeNumber)
{TRACE
  bool ret = ((nodeNumber >= 1) && (nodeNumber <= 9)); 
  return ret;
}

//return true if highlighted
bool BOPatternLockAlgorithm::highLightEdge(CNodeContext* prev, CNodeContext* curr)
{TRACE
  if ( !(prev && curr) )
  {
    DBG("to highlight edge we need two nodes");
    return false;
  }
  int p = prev->index();
  int c = curr->index();
  if (!isValidNodeNumber(p)) 
  {
    DBG("[%d] is NOT a valid node number so return", p);
    return false;
  }
  if (!isValidNodeNumber(c)) 
  {
    DBG("[%d] is NOT a valid node number so return", c);
    return false;
  }
  if ( p == c ) 
  {
    DBG("there is no edge to highlight with only node ");
    return false;
  }
  
  DBG("Highlight edge between nodes [%d] and [%d]", p, c);
  CEdgeContext* edge = observer_.getEdgeBetweenNodes(p, c);
  //BO_ASSERT(edge != 0);
  if (edge)
  {
    if (!isEdgeHighighted(edge)) 
    {
      edge->show();
      highlightedEdges_.insert(edge);
      return true;
    }
  }
  else
  {
    DBG("we dont have image for this edge");
  }
  return false;
}


