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
, hashotspots_(false)
, mouse_pressed(false)
//, current_object(0)
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

  if (curr.y < _get_draw_area_top()) {
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
//XXX: todo - DONT DELETE
  _update_line_item();
//  bo_pattern_lock_algorithm_scan_hotspots(alogrithm_, curr.x , curr.y, mouse);
}

void PatternLockViewController::_update_line_item()
{TRACE
  int x1 = 0;
  int y1 = 0;
  int x2 = 0;
  int y2 = 0;

  if (!mouse_pressed) {
    DBG("mouse pressed did not happen before so return");
    return;
  }

//  if (!current_object) {
//    _create_line();
//    return;
//  }
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
  
  linemgr_->drawLine(x1, y1, x2, y2);
}

void PatternLockViewController::_create_line()
{TRACE
}

void PatternLockViewController::tableGeometry(int& x, int& y, int& w, int& h)
{TRACE
  BOImageTable& tbl = table();
  tbl.geometry(x, y, w, h);
}

int PatternLockViewController::_get_draw_area_top() 
{TRACE
//  int y = 0;
//  int h = 0;
  int x = 0;
  int y_top = 0;
  int w = 0;
  int h = 0;

//  if (evas_object_visible_get(thiz->color_selector_panel)) {
//    evas_object_geometry_get(thiz->color_selector_panel, NULL, &y, NULL, &h);
//    y_top = y + h;
//  } else {
//  evas_object_geometry_get(thiz->draw_area_, NULL, &y_top, NULL, NULL);
//  }

BOImageTable& tbl = table();

//evas_object_geometry_get(thiz->draw_area_, NULL, &y_top, NULL, NULL);
tbl.geometry(x, y_top, w, h);

  return y_top;
}

void PatternLockViewController::_start_new_line_draw() 
{TRACE
  mouse_pressed = false;
  //current_object = NULL;
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
