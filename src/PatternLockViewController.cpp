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
#include "BOLineManager.hpp"
#include "BOPatternLockAlgorithm.hpp"
#include "trace.hpp"

void PatternLockViewController::construct()
{TRACE
  linemgr_ = BOLineManager::newL(parent_);
  _reset_coords_zeroout();
  patternlockview_ = BOPatternLockView::newL(parent_);
  if (!patternlockview_)
  {
    return;
  }
  attachEventHandlersToTable();
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
  delete patternlockview_; patternlockview_ = 0;
  delete linemgr_; patternlockview_ = 0;
  parent_ = NULL;
}
PatternLockViewController::PatternLockViewController(const BOPatternbLockConfig& config, Evas_Object* parent)
: parent_(parent)
, patternlockview_(0)
, linemgr_(0)
, algorithm_(0)
, hashotspots_(false)
, mouse_pressed(false)
, mode_(EPatternLockMode_ScreenLock)
, config_(config)
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
  
  if (EPatternLockMode_ScreenLock == mode_)
  {
    bool passwordcorrect = algorithm_->isPasswordCorrect();
    EHotspotColor color;
    if (passwordcorrect)
    {
      DBG("password is correct");
      color = eGreen;
    }
    else 
    {
      //XXX: timer here
      DBG("password is not correct: start a timer and reset all shit at end of timer");
      color = eRed;
    }
    algorithm_->decorate(color);
  }
}

void PatternLockViewController::handleMouseMove(Evas_Event_Mouse_Move* mouse)
{TRACE
  int x = 0;
  int y = 0;
  int w = 0;
  int h = 0;
  tableGeometry(x, y, w, h);
  
  prev.x = curr.x;
  prev.y = curr.y;

  if (curr.y < _get_draw_area_top()) 
  {
    DBG("======>> FOUL this area is not visible stupid ass motherfucker");
    return;
  }

  if (mouse->cur.canvas.x < x)
    curr.x = x;
  else if (mouse->cur.canvas.x > x + w)
    curr.x = x + w;
  else
    curr.x = mouse->cur.canvas.x;

  if (mouse->cur.canvas.y < y)
    curr.y = y;
  else if (mouse->cur.canvas.y > y + h)
    curr.y = y + h;
  else
    curr.y = mouse->cur.canvas.y;

{
  int lineX2 = 0;
  int lineY2 = 0;
  
  _update_line_item(lineX2, lineY2);
  
  int scanPointX = lineX2;
  int scanPointY = lineY2;
  
  if (scanPointX == 0)
  {
    scanPointX = curr.x;
  }
  if (scanPointY == 0)
  {
    scanPointY = curr.y;
  }

  //algorithm_->scan(scanPointX , scanPointY, mouse);
  
  
  algorithm_->scan(curr.x , curr.y, mouse);
}

}

void PatternLockViewController::_update_line_item(int& lineX2, int& lineY2)
{TRACE
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;

  if (!mouse_pressed) {
    DBG("mouse pressed did not happen before so return");
    return;
  }
  bool created = linemgr_->createLine(start.x, start.y, start.x, start.y);
  if (created) 
  {
    return;
  }

  if (start.y <= curr.y) {
    x1 = start.x;
    x2 = curr.x;
    y1 = start.y;
    y2 = curr.y;
  } else {
    x2 = start.x;
    x1 = curr.x;
    y2 = start.y;
    y1 = curr.y;
  }
  
  lineX2 = x2;
  lineY2 = y2;
  linemgr_->drawLine(x1, y1, x2, y2);
}

void PatternLockViewController::tableGeometry(int& x, int& y, int& w, int& h)
{TRACE
  BOImageTable& tbl = table();
  tbl.geometry(x, y, w, h);
}

int PatternLockViewController::_get_draw_area_top() 
{TRACE
  int x = 0;
  int y_top = 0;
  int w = 0;
  int h = 0;
  BOImageTable& tbl = table();
  tbl.geometry(x, y_top, w, h);
  return y_top;
}

void PatternLockViewController::_start_new_line_draw() 
{TRACE
  mouse_pressed = false;
  linemgr_->startNewLine();
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
void PatternLockViewController::_reset_coords_in_move(Evas_Event_Mouse_Move* mouse, CNodeContext& nodeContext) 
{TRACE
  //reset everything to center of hotspot or what?
  int centerX = nodeContext.hotspot().center_x;
  int centerY = nodeContext.hotspot().center_y;
  
//  start.x = centerX;
//  start.y = centerY;
  
  prev.x = centerX;
  prev.y = centerY;
//
//  curr.x = centerX;
//  curr.y = centerY;
  
    start.x = mouse->cur.canvas.x;
    start.y = mouse->cur.canvas.y;
  //
//    prev.x = mouse->cur.canvas.x;
//    prev.y = mouse->cur.canvas.y;

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

BOImageTable& PatternLockViewController::table() const
{TRACE
  return patternlockview_->table();
}
void PatternLockViewController::attachEventHandlersToTable()
{TRACE
  table().addMouseDownEventHandler(didReceiveMouseDownEvent, this);
  table().addMouseUpEventHandler(didReceiveMouseUpEvent, this);
  table().addMouseMoveEventHandler(didReceiveMouseMoveEvent, this);
}
Evas_Object* PatternLockViewController::evasObject() const
{TRACE
  return patternlockview_->evasObject();
}
void PatternLockViewController::show()
{TRACE
  patternlockview_->showNodes();
  patternlockview_->showEdges(); //this call is needed to put all edges in thick mode so they get shown later.
}
void PatternLockViewController::error()
{TRACE
  patternlockview_->error();
}
void PatternLockViewController::ok()
{TRACE
  patternlockview_->ok();
}
void PatternLockViewController::createHotspots()
{TRACE
  vector<CNodeContext*>& hotspts = patternlockview_->createHotspots();
  algorithm_ = BOPatternLockAlgorithm::newL(hotspts, *this);
}
void PatternLockViewController::didEnterInsideHotspot(Evas_Event_Mouse_Move* mouse, CNodeContext& nodeContext)
{TRACE
  _start_new_line_draw();
  mouse_pressed = true;
  _reset_coords_in_move(mouse, nodeContext);
}
CEdgeContext* PatternLockViewController::getEdgeBetweenNodes(int prevNodeIndex, int currNodeIndex)
{TRACE
  CEdgeContext* edge = patternlockview_->getEdgeBetweenNodes(prevNodeIndex, currNodeIndex);
  return edge;
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
