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
, tblBackgroudSpecs_(BO_COLOR_MAGENTA_ALPHA, kBgImageName)
{TRACE
}
void BOPatternLockView::construct()
{TRACE
  createTable();
  createNodeContexts();
  addNodesInTable();
  createEdgeContexts();
  addEdgesInTable();
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
loopfor = 0;
  nodecontexts_.reserve(loopfor);
  for (int i = 0; i < loopfor; i++)
  {
    CNodeContext* context = CNodeContext::newL(container_);
    nodecontexts_.push_back(context);
  } //end for

}

void BOPatternLockView::addNodesInTable()
{TRACE
  int i = 0;
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) 
  {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (!c)
    {
      continue;
    }
    Evas_Object* evasObj = c->evasObject();
    int column = kNodesTablePositions[i].col;
    int row = kNodesTablePositions[i].row;
    int columnspan = kNodesTablePositions[i].colSpan;
    int rowspan = kNodesTablePositions[i].rowSpan;
    int name = kNodesTablePositions[i].name;
    
    table_->addEvasObject(evasObj, column, row, columnspan, rowspan);
    
    c->setColumn(column);
    c->setRow(row);
    c->setIndex(name);
    
    i++;
  } //end for
}

void BOPatternLockView::createEdgeContexts()
{TRACE
  edgecontexts_.reserve(kTotalEdgeCells);

  int i = 0;
  int howMany = 0;
#if 0
      //horizontal
  howMany += kTotalEdgeCells_Horizontal;
  for (; i < howMany; i++)
  {
    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_Horizontal);
    int name = kEdgesTablePositions[i].name;
    context->setName(name);
    edgecontexts_.push_back(context);
  } //end for


    //vertical
  howMany += kTotalEdgeCells_Vertical;
  for (; i < howMany; i++)
  {
    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_Vertical);
    int name = kEdgesTablePositions[i].name;
        context->setName(name);
    edgecontexts_.push_back(context);
  } //end for
  

    //forward
  howMany += kTotalEdgeCells_ForwardSlashed;
  for (; i < howMany; i++)
  {
    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_ForwardSlashed);
    int name = kEdgesTablePositions[i].name;
        context->setName(name);
    edgecontexts_.push_back(context);
  } //end for
  
      //backward
  howMany += kTotalEdgeCells_BackwardSlashed;
  for (; i < howMany; i++)
  {
    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_BackwardSlashed);
    int name = kEdgesTablePositions[i].name;
        context->setName(name);
    edgecontexts_.push_back(context);
  } //end for
#endif
}
void BOPatternLockView::addEdgesInTable()
{TRACE
  int i = 0;
  for (vector<CEdgeContext*>::iterator it = edgecontexts_.begin();
        it != edgecontexts_.end();
        ++it) 
  {
    CEdgeContext* e = *it;
    BO_ASSERT(e != NULL);
    if (e) 
      {
      Evas_Object* evasObj = e->evasObject();
      table_->addEvasObject(evasObj, kEdgesTablePositions[i].col, kEdgesTablePositions[i].row, kEdgesTablePositions[i].colSpan, kEdgesTablePositions[i].rowSpan);
      i++;
      
//      int name = kEdgesTablePositions[i].name;
//      e->setName(name);
      }
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
    if (name == name1 /*|| name == name2*/)
    {
      //bingo
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

