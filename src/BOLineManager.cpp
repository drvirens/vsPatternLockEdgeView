//
//  BOLineManager.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/20/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "BOLineManager.hpp"
#include "trace.hpp"
#include "bo_colors.h"

void BOLineManager::construct()
{TRACE
#if defined __TIZEN__
  evas = evas_object_evas_get(parent_);
#endif
}

BOLineManager::BOLineManager(Evas_Object* parent)
: evas(0)
, line_new_(0)
, win_layer(0)
, current_object(0)
, parent_(parent)
{TRACE
}

BOLineManager* BOLineManager::newL(Evas_Object* parent)
{TRACE
  BOLineManager* obj = new BOLineManager(parent);
  if (obj)
  {
    obj->construct();
  }
  return obj;
}

BOLineManager::~BOLineManager()
{TRACE
}

bool BOLineManager::createLine(int startx, int starty, int startx1, int starty1)
{TRACE
  bool ret = false;
  if (!current_object) {
    _create_line(startx, starty, startx1, starty1);
    return true;
  }
  return ret;
}

void BOLineManager::drawLine(int x1, int y1, int x2, int y2)
{TRACE
#if defined __TIZEN__
  evas_object_line_xy_set(line_new_, x1, y1, x2, y2);
#endif
}

void BOLineManager::startNewLine()
{TRACE
  current_object = NULL;
}
//
//void BOLineManager::_create_line(int startx, int starty, int startx1, int starty1) 
//{TRACE
//  Evas_Object* line_new = NULL;
//#if defined __TIZEN__
//  line_new = evas_object_line_add(evas);
//#endif
//  if (!line_new) {
//    DBG("ERROR: evas_object_line_add() failed.");
//    return;
//  }
//  line_new_ = line_new;
//  //objects = eina_list_append(objects, line_new_);
//  objects.push_back(line_new_);
//  
////just fake it because we dont need object shit
//  current_object = &(current_object); //_create_object(LINE);
//  if (!current_object)
//    return;
//
//#if defined __TIZEN__
//  evas_object_color_set(line_new, BO_COLOR_BLUE_ALPHA);
//  evas_object_pass_events_set(td.ctrl_pt2_line, EINA_TRUE);
//  
//  //evas_object_line_xy_set(line_new, start.x, start.y, start.x, start.y);
//  evas_object_line_xy_set(line_new, startx, starty, startx1, starty1);
//  
//  evas_object_anti_alias_set(line_new, EINA_TRUE);
//  
//  evas_object_repeat_events_set(line_new, EINA_TRUE);
//  evas_object_show(line_new);
//  evas_object_layer_set(line_new, win_layer + 1);
//#endif
//}


//void BOLineManager::_create_line(int startx, int starty, int startx1, int starty1) 
//{TRACE
////just fake it because we dont need object shit
//  current_object = &(current_object); //_create_object(LINE);
//  if (!current_object)
//  {
//    DBG("No current_object so we return <---- ");
//    return;
//  }
//
//
//  Evas_Object* line_new = NULL;
//#if defined __TIZEN__
//  line_new = evas_object_line_add(evas);
//  if (!line_new) {
//    DBG("ERROR: evas_object_line_add() failed.");
//    return;
//  }
//  
//  evas_object_color_set(line_new, BO_COLOR_BLUE_ALPHA);
//  evas_object_pass_events_set(line_new, EINA_TRUE);
//  
//  //evas_object_line_xy_set(line_new, start.x, start.y, start.x, start.y);
//  evas_object_line_xy_set(line_new, startx, starty, startx1, starty1);
//  
//  evas_object_anti_alias_set(line_new, EINA_TRUE);
//  
//  evas_object_repeat_events_set(line_new, EINA_TRUE);
//  evas_object_show(line_new);
//  //evas_object_layer_set(line_new, win_layer + 1);
//#endif
//
//  line_new_ = line_new;
//  objects.push_back(line_new_);
//
//}

static const int kLineThickNess = 1;
static Evas_Object* _create_one_line(Evas* evas, int startx, int starty, int startx1, int starty1)
{TRACE
  Evas_Object* line = NULL;
#if defined __TIZEN__
  line = evas_object_line_add   (evas);
  evas_object_color_set         (line, BO_COLOR_BLUE_ALPHA);
  evas_object_line_xy_set       (line, startx, starty, startx1, starty1);
  evas_object_anti_alias_set    (line, EINA_TRUE);
  evas_object_repeat_events_set (line, EINA_TRUE);
  evas_object_pass_events_set   (line, EINA_TRUE);
  evas_object_show              (line);
#endif
  return line;
}

/*
vertical line: y2 > y1
x1, y1 (2, 2)
  |
  |
x2, y2 (2, 10)
  x-2 x-1 x x+1 x+2
  

horizontal line: x2 > x1
x1, y1  ------  x2, y2
 (2,2)          (10,2)
  
  y-2 y-1 y y+1 y+2
  
*/

void BOLineManager::_create_line(int startx, int starty, int startx1, int starty1) 
{TRACE

  current_object = &(current_object); //_create_object(LINE);
  if (!current_object)
  {
    DBG("No current_object so we return <---- ");
    return;
  }
  
  for (int i = 0; i < kLineThickNess; i++)
  {
    int x1 = startx;
    int y1 = starty;
    int x2 = startx1;
    int y2 = starty1;
    
//    if (y2 > y1)  //vertical line
//      {
//      x1 = startx + i;
//      x2 = startx1 + i;
//      }
//    else if (x2 > x1) //horizontal line
//      {
//      y1 = starty + i;
//      y2 = starty1 + 1;
//      }
//    else
//      {
//      DBG("what would this mean");
//      //BO_ASSERT(1 != 1);
//      }
    
    Evas_Object* line = _create_one_line(evas, x1, y1, x2, y2);
    if (i == 0)
      {
      line_new_ = line; //so that other existing logic works
      objects.push_back(line_new_);
      }
    lines_.push_back(line);
  } //end for  
}



