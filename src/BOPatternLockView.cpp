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
  BOImageTablePosition bgNodesTablePosition = kNodesTablePositions[kBackgroundCellIndex];
  table_ = BOImageTable::newL(parent_, bgNodesTablePosition.colSpan, bgNodesTablePosition.rowSpan);

  container_ = table_->nativeTable();
}
void BOPatternLockView::createNodeContexts()
{TRACE
  nodecontexts_.reserve(kTotalNodeCells);
  for (int i = 0; i < kTotalNodeCells; i++)
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
    
    table_->addEvasObject(evasObj, column, row, columnspan, rowspan);
    
    c->setColumn(column);
    c->setRow(row);
    
    i++;
  } //end for
}

void BOPatternLockView::createEdgeContexts()
{TRACE
  edgecontexts_.reserve(kTotalEdgeCells);

  int i = 0;
  int howMany = 0;
  
      //horizontal
  howMany += kTotalEdgeCells_Horizontal;
  for (; i < howMany; i++)
  {
    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_Horizontal);
    edgecontexts_.push_back(context);
  } //end for


    //vertical
  howMany += kTotalEdgeCells_Vertical;
  for (; i < howMany; i++)
  {
    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_Vertical);
    edgecontexts_.push_back(context);
  } //end for
  

    //forward
  howMany += kTotalEdgeCells_ForwardSlashed;
  for (; i < howMany; i++)
  {
    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_ForwardSlashed);
    edgecontexts_.push_back(context);
  } //end for
  
      //backward
  howMany += kTotalEdgeCells_BackwardSlashed;
  for (; i < howMany; i++)
  {
    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_BackwardSlashed);
    edgecontexts_.push_back(context);
  } //end for
}
void BOPatternLockView::addEdgesInTable()
{TRACE
  int i = 0;
  for (vector<CEdgeContext*>::iterator it = edgecontexts_.begin();
        it != edgecontexts_.end();
        ++it) 
  {
    CEdgeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      Evas_Object* evasObj = c->evasObject();
      table_->addEvasObject(evasObj, kEdgesTablePositions[i].col, kEdgesTablePositions[i].row, kEdgesTablePositions[i].colSpan, kEdgesTablePositions[i].rowSpan);
      i++;
      }
  } //end for
}
  
Evas_Object* BOPatternLockView::evasObject() const
{TRACE
  return container_;
}
BOImageTable& BOPatternLockView::table() const
{TRACE
  return *table_;
}

