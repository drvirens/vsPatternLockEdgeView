//
//  BOHotspot.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/19/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef BOHotspot_hpp
#define BOHotspot_hpp

#include "OS.h"

//hotspot = area that has a node underlying it. when user moves his
//finger over this hotspt, the node underneath gets highlighted, if 
//it is not already highlighted
class BOHotspot
{  
 public:
  int row_;
  int column_;

  //computed internally - treat them as private
  Eina_Rectangle hotspot_rect_;
  int center_x;
  int center_y;
  
  float xmin_;
  float ymin_;
  float xmax_;
  float ymax_;
  
 public:
  BOHotspot();
  void computeCenterPoint();
  bool lies(int x, int y); //does this point lies in this hotspot or what?
  bool intersects(int lineX1, int lineY1, int lineX2, int lineY2);
};

#endif /* BOHotspot_hpp */
