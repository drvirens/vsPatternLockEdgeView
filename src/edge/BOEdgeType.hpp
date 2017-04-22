//
//  BOEdgeType.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/19/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef BOEdgeType_hpp
#define BOEdgeType_hpp

enum BOEdgeType
{
  BOEdgeType_NotEdge,
  BOEdgeType_Horizontal,
  BOEdgeType_Vertical,
  BOEdgeType_ForwardSlashed, /* / */
  BOEdgeType_BackwardSlashed, /* \ */
  BOEdgeType_BackwardSlashed_Elongated_Horizontal,
  BOEdgeType_ForwardSlashed_Elongated_Horizontal,
  BOEdgeType_BackwardSlashed_Elongated_Vertical,
  BOEdgeType_ForwardSlashed_Elongated_Vertical
};

#endif /* BOEdgeType_hpp */
