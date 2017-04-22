//
//  BOPatternLockView.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/19/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "BOPatternLockView.hpp"
#include "BOImageTable.hpp"
#include "BOPatternbLockConfig.hpp"
#include "CNodeContext.hpp"
#include "CEdgeContext.hpp"
#include "PatterLockLayout.hpp"
#include "trace.hpp"
#include "bo_colors.h"

static string kBgImageName = "";

BOPatternLockView* BOPatternLockView::newL(Evas_Object* parent)
{TRACE
  BOPatternLockView* obj = new BOPatternLockView(parent);
  if (obj)
  {
    obj->construct();
  }
  return obj;
}
BOPatternLockView::~BOPatternLockView()
{TRACE
}
BOPatternLockView::BOPatternLockView(Evas_Object* parent)
: parent_(parent)
, container_(0)
, table_(0)
, tblBackgroudSpecs_(BO_COLOR_MAGENTA_TRANSPARENT, kBgImageName)
{TRACE
}
void BOPatternLockView::construct()
{TRACE
  createTable();
  createNodeContexts();
  createEdgeContexts();
}

void BOPatternLockView::showNodes()
{TRACE
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) 
  {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      c->show();
      }
  } //end for
}
void BOPatternLockView::showEdges()
{TRACE
  for (vector<CEdgeContext*>::iterator it = edgecontexts_.begin();
        it != edgecontexts_.end();
        ++it) 
  {
    CEdgeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      c->show();
      }
  } //end for
}
void BOPatternLockView::error()
{TRACE
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) 
  {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      c->error();
      }
  } //end for
}
void BOPatternLockView::ok()
{TRACE
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) 
  {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      c->ok();
      }
  } //end for
}

vector<CNodeContext*>& BOPatternLockView::createHotspots()
{TRACE
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) 
  {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      c->populateHotspotInfo();  
      }
  } //end for
  return nodecontexts_;
}

void BOPatternLockView::createTable()
{TRACE
  BOImageTablePosition bgNodesTablePosition = kBackgroundTablePosition[0];
  table_ = BOImageTable::newL(parent_, bgNodesTablePosition.colSpan, bgNodesTablePosition.rowSpan, tblBackgroudSpecs_);
  if (!table_)
  {
    return;
  }
  container_ = table_->nativeTable();
}
void BOPatternLockView::createNodeContexts()
{TRACE
  int loopfor = kTotalNodeCells;
  nodecontexts_.reserve(loopfor);
  for (int i = 0; i < loopfor; i++)
  {
    CNodeContext* n = CNodeContext::newL(container_);
    Evas_Object* evasObj = n->evasObject();
    int column = kNodesTablePositions[i].col;
    int row = kNodesTablePositions[i].row;
    int columnspan = kNodesTablePositions[i].colSpan;
    int rowspan = kNodesTablePositions[i].rowSpan;
    int name = kNodesTablePositions[i].name;
    
    table_->addEvasObject(evasObj, column, row, columnspan, rowspan);
    n->setColumn(column);
    n->setRow(row);
    n->setIndex(name);

    nodecontexts_.push_back(n);
  } //end for

}

void BOPatternLockView::createEdgeContexts()
{TRACE
  edgecontexts_.reserve(kTotalEdgeCells);
  for (int i = 0; i < kTotalEdgeCells; i++)
  {
    BOImageTablePosition specs = kEdgesTablePositions[i];  
    int col = specs.col;
    int row = specs.row;
    int colSpan = specs.colSpan;
    int rowSpan = specs.rowSpan;
    int name = specs.name; 
    BOEdgeType edgetype = specs.edgetype; 
    
    CEdgeContext* e = CEdgeContext::newL(container_, edgetype);
    e->setName(name);
    Evas_Object* evasObj = e->evasObject();
    table_->addEvasObject(evasObj, col, row, colSpan, rowSpan);
    
    edgecontexts_.push_back(e);
  } //end for
}

CEdgeContext* BOPatternLockView::getEdgeBetweenNodes(int prevNodeIndex, int currNodeIndex)
{TRACE
  CEdgeContext* retEdge = 0; //edgecontexts_[i];
  //create the name of the edge we are looking for. we create two numbers.
  // <prev><curr> and <curr><prev>
  //If one is not found, look for other
  
  int name1 = 0;
  int name2 = 0;
  
  name1 = (prevNodeIndex * 10) + currNodeIndex;
  name2 = (currNodeIndex * 10) + prevNodeIndex;
  
  DBG("=======>>> Looking for edge named either %d or %d", name1, name2);
    
  //then we look for that specific edge 
  for (vector<CEdgeContext*>::iterator it = edgecontexts_.begin();
        it != edgecontexts_.end();
        ++it) 
  {
    CEdgeContext* e = *it;
    BO_ASSERT(e != NULL);
    if (!e) 
      {
      continue;
      }
    int name = e->name();
    if (name == name1 || name == name2)
    {
      retEdge = e;
      break;
    }
  } //end for
  
  return retEdge;
}
  
Evas_Object* BOPatternLockView::evasObject() const
{TRACE
  return container_;
}
BOImageTable& BOPatternLockView::table() const
{TRACE
  return *table_;
}

