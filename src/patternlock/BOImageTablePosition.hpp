//
//  BOImageTablePosition.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/18/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef BOImageTablePosition_hpp
#define BOImageTablePosition_hpp

#include "BOEdgeType.hpp"

struct BOImageTablePosition
{
  int col;
  int row;
  int colSpan;
  int rowSpan;
  int name; //for node, it's node number from 1-9, for edges, it's the names of two nodes it connects
  BOEdgeType edgetype; //applies only for edge
};

#endif /* BOImageTablePosition_hpp */
