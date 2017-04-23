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

#define SHOW_LAST_DRAWN_LINE_ONLY true

void BOLineManager::construct()
{TRACE
#if defined __TIZEN__
  evas = evas_object_evas_get(parent_);
#endif
}

BOLineManager::BOLineManager(Evas_Object* parent)
: evas(0)
, line_new_(0)
, current_object(0)
, parent_(parent)
, showLastLineOnly_(SHOW_LAST_DRAWN_LINE_ONLY)
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
  if (showLastLineOnly_)
  {
  //do not reset current_object so that all previous lines will not be shown
  }
  else 
  {
    current_object = NULL;
  }
}


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

static const int kLineThickNess = 1;
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
        
    Evas_Object* line = _create_one_line(evas, x1, y1, x2, y2);
    if (i == 0)
      {
      line_new_ = line; //so that other existing logic works
      objects.push_back(line_new_);
      }
    lines_.push_back(line);
  } //end for  
}



