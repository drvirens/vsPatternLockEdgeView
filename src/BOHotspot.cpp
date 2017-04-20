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
#include "trace.hpp"

BOHotspot::BOHotspot()
: column_(-1)
, row_(-1)
{TRACE
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

