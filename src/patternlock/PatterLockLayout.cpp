//
//  PatterLockLayout.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/19/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "PatterLockLayout.hpp"

//#define __USE_2x2_MATRIX__ 1
#define __USE_3x3_MATRIX__ 1


#if defined __USE_3x3_MATRIX__


BOImageTablePosition kBackgroundTablePosition[1] =
{
    { 0, 0,     30, 30,   -1},
};


const int kTotalNodeCells = 9; 
const int kTotalEdgeCells = 28;
static const int kInceaseNodeBy = 1;

static const int kNodeWidth = 4 + (kInceaseNodeBy*2);

BOImageTablePosition kNodesTablePositions[kTotalNodeCells] =
     {
     /* coords      span    name    edgeType*/
	 //row 1
        { 3-kInceaseNodeBy, 3-kInceaseNodeBy ,    kNodeWidth, kNodeWidth,    1,   BOEdgeType_NotEdge},
        {13-kInceaseNodeBy, 3-kInceaseNodeBy ,    kNodeWidth, kNodeWidth,    2,   BOEdgeType_NotEdge},
        {23-kInceaseNodeBy, 3-kInceaseNodeBy ,    kNodeWidth, kNodeWidth,    3,   BOEdgeType_NotEdge},
		
	//row 2
        { 3-kInceaseNodeBy, 13-kInceaseNodeBy,    kNodeWidth, kNodeWidth,    4,   BOEdgeType_NotEdge},
        {13-kInceaseNodeBy, 13-kInceaseNodeBy,    kNodeWidth, kNodeWidth,    5,   BOEdgeType_NotEdge},
        {23-kInceaseNodeBy, 13-kInceaseNodeBy,    kNodeWidth, kNodeWidth,    6,   BOEdgeType_NotEdge},
		
	//row 3
        { 3-kInceaseNodeBy, 23-kInceaseNodeBy,    kNodeWidth, kNodeWidth,    7,   BOEdgeType_NotEdge},
        {13-kInceaseNodeBy, 23-kInceaseNodeBy,    kNodeWidth, kNodeWidth,    8,   BOEdgeType_NotEdge},
        {23-kInceaseNodeBy, 23-kInceaseNodeBy,    kNodeWidth, kNodeWidth,    9,   BOEdgeType_NotEdge},
     };



BOImageTablePosition kEdgesTablePositions[kTotalEdgeCells] =
     {
     /* coords      span    name */
        { 5, 4 ,    10, 2,    12,  BOEdgeType_Horizontal},
        { 15, 4,    10, 2,    23,  BOEdgeType_Horizontal},
		
        { 4, 5 ,    2, 10,    14,  BOEdgeType_Vertical},
        { 14, 5 ,   2, 10,    25,  BOEdgeType_Vertical},
        { 24, 5 ,   2, 10,    36,  BOEdgeType_Vertical},
		
        { 5, 14,    10, 2,    45,  BOEdgeType_Horizontal},
        { 15, 14,   10, 2,    56,  BOEdgeType_Horizontal},
            
        { 4, 15 ,    2, 10,    47,  BOEdgeType_Vertical},
        { 14, 15 ,   2, 10,    58,  BOEdgeType_Vertical},
        { 24, 15 ,   2, 10,    69,  BOEdgeType_Vertical},
		
        { 5, 24,     10, 2,    78,  BOEdgeType_Horizontal},
        { 15, 24,    10, 2,    89,  BOEdgeType_Horizontal},
				
        { 5, 5,     10, 10,   15,  BOEdgeType_BackwardSlashed},
        { 5, 5,     10, 10,   24,  BOEdgeType_ForwardSlashed},
		
        { 15, 5,     10, 10,   26,  BOEdgeType_BackwardSlashed},
        { 15, 5,     10, 10,   35,  BOEdgeType_ForwardSlashed},
		
        { 5, 15,     10, 10,   48,  BOEdgeType_BackwardSlashed},
        { 5, 15,     10, 10,   57,  BOEdgeType_ForwardSlashed},

        { 15, 15,     10, 10,   59,  BOEdgeType_BackwardSlashed},
        { 15, 15,     10, 10,   68,  BOEdgeType_ForwardSlashed},
        
        
        // 8 elongated edges
        		
        { 5, 5,     20, 10,   16,  BOEdgeType_BackwardSlashed_Elongated_Horizontal},
        { 5, 5,     20, 10,   34,  BOEdgeType_ForwardSlashed_Elongated_Horizontal},
		
        { 5, 15,     20, 10,   49,  BOEdgeType_BackwardSlashed_Elongated_Horizontal},
        { 5, 15,     20, 10,   67,  BOEdgeType_ForwardSlashed_Elongated_Horizontal},

        { 5, 5,     10, 20,   18,  BOEdgeType_BackwardSlashed_Elongated_Vertical},
        { 5, 5,     10, 20,   27,  BOEdgeType_ForwardSlashed_Elongated_Vertical},
		
        { 15, 5,     10, 20,   29,  BOEdgeType_BackwardSlashed_Elongated_Vertical},
        { 15, 5,     10, 20,   38,  BOEdgeType_ForwardSlashed_Elongated_Vertical},

     };



#if 0
//works but too small
BOImageTablePosition kNodesTablePositions[kTotalNodeCells] =
     {
     /* coords      span    name    edgeType*/
	 //row 1
        { 3, 3 ,    4, 4,    1,   BOEdgeType_NotEdge},
        {13, 3 ,    4, 4,    2,   BOEdgeType_NotEdge},
        {23, 3 ,    4, 4,    3,   BOEdgeType_NotEdge},
		
	//row 2
        { 3, 13,    4, 4,    4,   BOEdgeType_NotEdge},
        {13, 13,    4, 4,    5,   BOEdgeType_NotEdge},
        {23, 13,    4, 4,    6,   BOEdgeType_NotEdge},
		
	//row 3
        { 3, 23,    4, 4,    7,   BOEdgeType_NotEdge},
        {13, 23,    4, 4,    8,   BOEdgeType_NotEdge},
        {23, 23,    4, 4,    9,   BOEdgeType_NotEdge},
     };
#endif


#elif __USE_2x2_MATRIX__

BOImageTablePosition kBackgroundTablePosition[1] =
{
    { 0, 0,     20, 20,   -1},
};



const int kTotalNodeCells = 4; 

const int kTotalEdgeCells = 6;

BOImageTablePosition kNodesTablePositions[kTotalNodeCells] =
     {
     /* coords      span    name    edgeType*/
        { 3, 3 ,    4, 4,    1,   BOEdgeType_NotEdge},
        {13, 3 ,    4, 4,    2,   BOEdgeType_NotEdge},
        { 3, 13,    4, 4,    3,   BOEdgeType_NotEdge},
        {13, 13,    4, 4,    4,   BOEdgeType_NotEdge},
     };

BOImageTablePosition kEdgesTablePositions[kTotalEdgeCells] =
     {
     /* coords      span    name */
        { 5, 4 ,    10, 2,    12,  BOEdgeType_Horizontal},
        { 4, 5 ,    2, 10,    13,  BOEdgeType_Vertical},
        { 14, 5,    2, 10,    24,  BOEdgeType_Vertical},
        { 5, 14,    10, 2,    34,  BOEdgeType_Horizontal},
        
        { 5, 5,     10, 10,   14,  BOEdgeType_BackwardSlashed},
        { 5, 5,     10, 10,   23,  BOEdgeType_ForwardSlashed},

     };
     
     
#else

#error You must use either 3x3 or 2x2 matrix

#endif
