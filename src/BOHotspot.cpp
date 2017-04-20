//
//  BOHotspot.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/19/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "BOHotspot.hpp"
#include "trace.hpp"
//
//BOHotspot* BOHotspot::newL(int x, int y, int w, int h, int col, int row)
//{TRACE
//  BOHotspot* obj = new BOHotspot(x, y, w, h, col, row);
//  if (obj) 
//  {
//    obj->construct();
//  }
//  return obj;
//}
//
//BOHotspot::~BOHotspot()
//{TRACE
//}
//
//BOHotspot::BOHotspot(int x, int y, int w, int h, int col, int row)
//: x_(x)
//, y_(y)
//, w_(w)
//, h_(h)
//, col_(col)
//, row_(row)
//{TRACE
//}

BOHotspot::BOHotspot()
: x_(-1)
, y_(-1)
, w_(-1)
, h_(-1)
, column_(-1)
, row_(-1)
{TRACE
}

//
//void BOHotspot::construct()
//{TRACE
//}
