//
//  BOHotspot.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/19/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#if defined __TIZEN__
#include <eina_rectangle.h>
#endif

#include "BOHotspot.hpp"
#include "BOLineClipAlgorithm.hpp"
#include "trace.hpp"

BOHotspot::BOHotspot()
: row_(-1)
, column_(-1)
, center_x(-1)
, center_y(-1)
, xmin_(0)
, ymin_(0)
, xmax_(0)
, ymax_(0)
{TRACE
}

void BOHotspot::computeCenterPoint()
{TRACE
  center_x = hotspot_rect_.x + (hotspot_rect_.w/2);
  center_y = hotspot_rect_.y + (hotspot_rect_.h/2);
  
  //also compute rect min max 
  xmin_ = hotspot_rect_.x;
  ymin_ = hotspot_rect_.y;
  xmax_ = (hotspot_rect_.x) + (hotspot_rect_.w);
  ymax_ = (hotspot_rect_.y) + (hotspot_rect_.h);
}

bool BOHotspot::lies(int x, int y)
{TRACE
  bool ret = false;
#if defined __TIZEN__
  Eina_Bool r = eina_rectangle_coords_inside( &(hotspot_rect_), x, y );
  if (r) 
  {
    ret = true;
  } 
#endif
  return ret;
}

bool BOHotspot::intersects(int lineX1, int lineY1, int lineX2, int lineY2)
{TRACE
  bool ret = false;
  //diagram: https://gist.github.com/ChickenProp/3194723
  float x1 = lineX1;
  float y1 = lineY1;
  float x2 = lineX2;
  float y2 = lineY2;
  ret = liang_barsky_clipper( xmin_, ymin_, xmax_, ymax_, x1, y1, x2, y2);
  return ret;
}


