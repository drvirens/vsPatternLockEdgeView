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
#include "BOHotspot.hpp"
#include "BOPatternLockView.hpp"
#include "trace.hpp"

PatternLockViewController::PatternLockViewController(const BOPatternbLockConfig& config, Evas_Object* parent)
: parent_(parent)
, container_(0)
, table_(0)
, hashotspots_(false)
, mouse_pressed(false)
, current_object(0)
, config_(config)
, patternlockview_(0)
{TRACE
}

static void didReceiveMouseDownEvent(void* event_info, void* data)
{TRACE
  PatternLockViewController* thiz = static_cast<PatternLockViewController*>(data);
  BO_ASSERT(thiz != 0);
  Evas_Event_Mouse_Down* mouse = (Evas_Event_Mouse_Down*) event_info;
  thiz->handleMouseDown(mouse);
}
static void didReceiveMouseUpEvent(void* event_info, void* data)
{TRACE
  PatternLockViewController* thiz = static_cast<PatternLockViewController*>(data);
  BO_ASSERT(thiz != 0);
  Evas_Event_Mouse_Up* mouse = (Evas_Event_Mouse_Up*) event_info;
  thiz->handleMouseUp(mouse);
}
static void didReceiveMouseMoveEvent(void* event_info, void* data)
{TRACE
  PatternLockViewController* thiz = static_cast<PatternLockViewController*>(data);
  BO_ASSERT(thiz != 0);
  Evas_Event_Mouse_Move *mouse = (Evas_Event_Mouse_Move*) event_info;
  thiz->handleMouseMove(mouse);
}

void PatternLockViewController::handleMouseDown(Evas_Event_Mouse_Down* mouse)
{TRACE
  mouse_pressed = true;
  if (!hashotspots_) 
  {
    createHotspots(); 
    hashotspots_ = true;
  }
  _reset_coords(mouse);
}
void PatternLockViewController::handleMouseUp(Evas_Event_Mouse_Up* mouse)
{TRACE
  _start_new_line_draw();
}
void PatternLockViewController::handleMouseMove(Evas_Event_Mouse_Move* mouse)
{TRACE
}

void PatternLockViewController::_start_new_line_draw() 
{TRACE
  mouse_pressed = 0; //false;
  current_object = NULL;
}
void PatternLockViewController::_reset_coords(Evas_Event_Mouse_Down* mouse) 
{TRACE
  start.x = mouse->canvas.x;
  start.y = mouse->canvas.y;
  prev.x = mouse->canvas.x;
  prev.y = mouse->canvas.y;
  curr.x = mouse->canvas.x;
  curr.y = mouse->canvas.y;
}
void PatternLockViewController::_reset_coords_in_move(Evas_Event_Mouse_Move* mouse) 
{TRACE
  start.x = mouse->cur.canvas.x;
  start.y = mouse->cur.canvas.y;
  prev.x = mouse->cur.canvas.x;
  prev.y = mouse->cur.canvas.y;
  curr.x = mouse->cur.canvas.x;
  curr.y = mouse->cur.canvas.y;
}
void PatternLockViewController::_reset_coords_zeroout() 
{TRACE
  start.x = 0;
  start.y = 0;
  prev.x = 0;
  prev.y = 0;
  curr.x = 0;
  curr.y = 0;
}



void PatternLockViewController::construct()
{TRACE
  _reset_coords_zeroout();
  patternlockview_ = BOPatternLockView::newL(parent_);
  if (!patternlockview_)
  {
    return;
  }
  attachEventHandlersToTable();
  
//  createTable();
//  createNodeContexts();
//  addNodesInTable();
//  createEdgeContexts();
//  addEdgesInTable();
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

void PatternLockViewController::attachEventHandlersToTable()
{TRACE
  BOImageTable& table = patternlockview_->table();
  table.addMouseDownEventHandler(didReceiveMouseDownEvent, this);
  table.addMouseUpEventHandler(didReceiveMouseUpEvent, this);
  table.addMouseMoveEventHandler(didReceiveMouseMoveEvent, this);
  
//  container_ = table_->nativeTable();
}

//void PatternLockViewController::createTable()
//{TRACE
//  BOImageTablePosition bgNodesTablePosition = kNodesTablePositions[kBackgroundCellIndex];
//  table_ = BOImageTable::newL(parent_, bgNodesTablePosition.colSpan, bgNodesTablePosition.rowSpan);
//  
//  table_->addMouseDownEventHandler(didReceiveMouseDownEvent, this);
//  table_->addMouseUpEventHandler(didReceiveMouseUpEvent, this);
//  table_->addMouseMoveEventHandler(didReceiveMouseMoveEvent, this);
//  
//  container_ = table_->nativeTable();
//}
//void PatternLockViewController::createNodeContexts()
//{TRACE
//  nodecontexts_.reserve(kTotalNodeCells);
//  for (int i = 0; i < kTotalNodeCells; i++)
//  {
//    CNodeContext* context = CNodeContext::newL(container_);
//    nodecontexts_.push_back(context);
//  } //end for
//}
//
//void PatternLockViewController::addNodesInTable()
//{TRACE
//  int i = 0;
//  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
//        it != nodecontexts_.end();
//        ++it) 
//  {
//    CNodeContext* c = *it;
//    BO_ASSERT(c != NULL);
//    if (!c)
//    {
//      continue;
//    }
//    Evas_Object* evasObj = c->evasObject();
//    int column = kNodesTablePositions[i].col;
//    int row = kNodesTablePositions[i].row;
//    int columnspan = kNodesTablePositions[i].colSpan;
//    int rowspan = kNodesTablePositions[i].rowSpan;
//    
//    table_->addEvasObject(evasObj, column, row, columnspan, rowspan);
//    
//    c->setColumn(column);
//    c->setRow(row);
//    
//    i++;
//  } //end for
//}
//void PatternLockViewController::createEdgeContexts()
//{TRACE
//  edgecontexts_.reserve(kTotalEdgeCells);
//
//  int i = 0;
//  int howMany = 0;
//  
//      //horizontal
//  howMany += kTotalEdgeCells_Horizontal;
//  for (; i < howMany; i++)
//  {
//    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_Horizontal);
//    edgecontexts_.push_back(context);
//  } //end for
//
//
//    //vertical
//  howMany += kTotalEdgeCells_Vertical;
//  for (; i < howMany; i++)
//  {
//    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_Vertical);
//    edgecontexts_.push_back(context);
//  } //end for
//  
//
//    //forward
//  howMany += kTotalEdgeCells_ForwardSlashed;
//  for (; i < howMany; i++)
//  {
//    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_ForwardSlashed);
//    edgecontexts_.push_back(context);
//  } //end for
//  
//      //backward
//  howMany += kTotalEdgeCells_BackwardSlashed;
//  for (; i < howMany; i++)
//  {
//    CEdgeContext* context = CEdgeContext::newL(container_, BOEdgeType_BackwardSlashed);
//    edgecontexts_.push_back(context);
//  } //end for
//}
//void PatternLockViewController::addEdgesInTable()
//{TRACE
//  int i = 0;
//  for (vector<CEdgeContext*>::iterator it = edgecontexts_.begin();
//        it != edgecontexts_.end();
//        ++it) 
//  {
//    CEdgeContext* c = *it;
//    BO_ASSERT(c != NULL);
//    if (c) 
//      {
//      Evas_Object* evasObj = c->evasObject();
//      table_->addEvasObject(evasObj, kEdgesTablePositions[i].col, kEdgesTablePositions[i].row, kEdgesTablePositions[i].colSpan, kEdgesTablePositions[i].rowSpan);
//      i++;
//      }
//  } //end for
//}
  
Evas_Object* PatternLockViewController::evasObject() const
{TRACE
  return patternlockview_->evasObject();
}

//void PatternLockViewController::showNodes()
//{TRACE
//  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
//        it != nodecontexts_.end();
//        ++it) 
//  {
//    CNodeContext* c = *it;
//    BO_ASSERT(c != NULL);
//    if (c) 
//      {
//      c->show();
//      }
//  } //end for
//}
//void PatternLockViewController::showEdges()
//{TRACE
//  for (vector<CEdgeContext*>::iterator it = edgecontexts_.begin();
//        it != edgecontexts_.end();
//        ++it) 
//  {
//    CEdgeContext* c = *it;
//    BO_ASSERT(c != NULL);
//    if (c) 
//      {
//      c->show();
//      }
//  } //end for
//}
void PatternLockViewController::show()
{TRACE
  patternlockview_->showNodes();
  patternlockview_->showEdges(); //this call is needed to put all edges in thick mode so they get shown later.
}
void PatternLockViewController::error()
{TRACE
//  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
//        it != nodecontexts_.end();
//        ++it) 
//  {
//    CNodeContext* c = *it;
//    BO_ASSERT(c != NULL);
//    if (c) 
//      {
//      c->error();
//      }
//  } //end for
  patternlockview_->error();
}
void PatternLockViewController::ok()
{TRACE
//  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
//        it != nodecontexts_.end();
//        ++it) 
//  {
//    CNodeContext* c = *it;
//    BO_ASSERT(c != NULL);
//    if (c) 
//      {
//      c->ok();
//      }
//  } //end for
  patternlockview_->ok();
}

void PatternLockViewController::createHotspots()
{TRACE
//  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
//        it != nodecontexts_.end();
//        ++it) 
//  {
//    CNodeContext* c = *it;
//    BO_ASSERT(c != NULL);
//    if (c) 
//      {
//      c->populateHotspotInfo();  
//      }
//  } //end for
  patternlockview_->createHotspots();
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




