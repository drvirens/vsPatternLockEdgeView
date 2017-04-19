//
//  PatternLockViewController.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/18/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "PatternLockViewController.hpp"
#include "BOImageTable.hpp"
#include "BOPatternbLockConfig.hpp"
#include "CNodeContext.hpp"
#include "CEdgeContext.hpp"
#include "PatterLockLayout.hpp"
#include "trace.hpp"

PatternLockViewController::PatternLockViewController(const BOPatternbLockConfig& config, Evas_Object* parent)
: parent_(parent)
, container_(0)
, table_(0)
, config_(config)
{TRACE
}

static void didReceiveMouseDownEvent(void* eventInfo, void* data)
{TRACE
  PatternLockViewController* thiz = static_cast<PatternLockViewController*>(data);
  BO_ASSERT(thiz != 0);
//  EventInfo evinfo;
//  thiz->handleMouseDown(evinfo);
}
void PatternLockViewController::createTable()
{TRACE
  BOImageTablePosition bgNodesTablePosition = kNodesTablePositions[kBackgroundCellIndex];
  table_ = BOImageTable::newL(parent_, bgNodesTablePosition.colSpan, bgNodesTablePosition.rowSpan);
  
  /*
  evas_object_event_callback_add(thiz->draw_area_, EVAS_CALLBACK_MOUSE_DOWN, _mouse_down_cb, thiz);
  evas_object_event_callback_add(thiz->draw_area_, EVAS_CALLBACK_MOUSE_UP, _mouse_up_cb, thiz);
  evas_object_event_callback_add(thiz->draw_area_, EVAS_CALLBACK_MOUSE_MOVE, _mouse_move_cb, thiz);
  */
  
  table_->addMouseDownEventHandler(didReceiveMouseDownEvent, this);
//  table_->addMouseUpEventHandler();
//  table_->addMouseMoveEventHandler();
  
  container_ = table_->nativeTable();
}
void PatternLockViewController::construct()
{TRACE
  createTable();
  createNodeContexts();
  addNodesInTable();
  createEdgeContexts();
  addEdgesInTable();
}
PatternLockViewController* PatternLockViewController::newL(const BOPatternbLockConfig& config, Evas_Object* parent)
{TRACE
  PatternLockViewController* obj = new PatternLockViewController(config, parent);
  if (obj)
    {
    obj->construct();
    }
  return obj;
}
PatternLockViewController::~PatternLockViewController()
{TRACE
  parent_ = NULL;
}

void PatternLockViewController::createNodeContexts()
{TRACE
  nodecontexts_.reserve(kTotalNodeCells);
  for (int i = 0; i < kTotalNodeCells; i++)
  {
    CNodeContext* context = CNodeContext::newL(container_);
    nodecontexts_.push_back(context);
  } //end for
}

void PatternLockViewController::addNodesInTable()
{TRACE
  int i = 0;
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      Evas_Object* evasObj = c->evasObject();
      table_->addEvasObject(evasObj, kNodesTablePositions[i].col, kNodesTablePositions[i].row, kNodesTablePositions[i].colSpan, kNodesTablePositions[i].rowSpan);
      i++;
      }
  } //end for
}

void PatternLockViewController::createEdgeContexts()
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
void PatternLockViewController::addEdgesInTable()
{TRACE
  int i = 0;
  for (vector<CEdgeContext*>::iterator it = edgecontexts_.begin();
        it != edgecontexts_.end();
        ++it) {
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
  
Evas_Object* PatternLockViewController::evasObject() const
{TRACE
  return container_;
}

void PatternLockViewController::resize()
{TRACE
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      c->resize();
      }
  } //end for
}

void PatternLockViewController::showNodes()
{TRACE
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      c->show();
      }
  } //end for
}
void PatternLockViewController::showEdges()
{TRACE
  for (vector<CEdgeContext*>::iterator it = edgecontexts_.begin();
        it != edgecontexts_.end();
        ++it) {
    CEdgeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      c->show();
      }
  } //end for
}
void PatternLockViewController::show()
{TRACE
  showNodes();
  //test
  showEdges(); //XXX
}
void PatternLockViewController::error()
{TRACE
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      c->error();
      }
  } //end for
}
void PatternLockViewController::ok()
{TRACE
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      c->ok();
      }
  } //end for
}

void PatternLockViewController::viewWillAppear(int animated)
{TRACE
}

void PatternLockViewController::viewDidAppear(int animated)
{TRACE
}

void PatternLockViewController::viewDidLoad()
{TRACE
}

void PatternLockViewController::viewWillDisappear(int animated)
{TRACE
}

void PatternLockViewController::viewDidDisappear(int animated)
{TRACE
}




