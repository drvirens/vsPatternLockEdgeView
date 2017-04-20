//
//  BOHotspot.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/19/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef BOHotspot_hpp
#define BOHotspot_hpp

//hotspot = area that has a node underlying it. when user moves his
//finger over this hotspt, the node underneath gets highlighted, if 
//it is not already highlighted
class BOHotspot
{
// public:
//  static BOHotspot* newL(int x, int y, int w, int h, int col, int row);
//  virtual ~BOHotspot();
//  
// private:
//  BOHotspot(int x, int y, int w, int h, int col, int row);
//  void construct();
  
 public:
  int row_;
  int column_;
  int x_;
  int y_;
  int w_;
  int h_;
  
 public:
  BOHotspot();
};

#endif /* BOHotspot_hpp */
