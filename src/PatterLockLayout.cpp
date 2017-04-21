//
//  PatterLockLayout.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/19/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "PatterLockLayout.hpp"

#define __USE_2x2_MATRIX__ 1

#if defined __USE_3x3_MATRIX__

static const int kBackgroundCell = 1; 
const int kTotalNodeCells = 9; 

const int kTotalEdgeCells = 20;
const int kTotalEdgeCells_Vertical = 6;
const int kTotalEdgeCells_Horizontal = 6;
const int kTotalEdgeCells_ForwardSlashed = 4;
const int kTotalEdgeCells_BackwardSlashed = 4;

const int kTotalTableCells = kTotalNodeCells + kBackgroundCell;
const int kBackgroundCellIndex = kTotalTableCells - 1;


BOImageTablePosition kNodesTablePositions[kTotalTableCells] =
     {
        //row 1
        {2, 2, 1, 1, 1}, 
        {5, 2, 1, 1, 2},
        {8, 2, 1, 1, 3},
        //row 2
        {2, 5, 1, 1, 4},
        {5, 5, 1, 1, 5},
        {8, 5, 1, 1, 6},
        //row 3
        {2, 8, 1, 1, 7},
        {5, 8, 1, 1, 8},
        {8, 8, 1, 1, 9},
        //bg
        {0, 0, 13, 13, 10} //always kBackgroundCellIndex
     };

BOImageTablePosition kEdgesTablePositions[kTotalEdgeCells] =
     {
        //
        //vertical edges: 6
        // 
        /*
             1 2 3
             4 5 6
             6 7 8
        */
        //
        //   1 - 2 - 3
        //   
        //   4 - 5 - 6
        //
        //   7 - 8 - 9
        // 
        {3, 3, 4, 1, 12},
        {6, 3, 4, 1, 23},
        {3, 6, 4, 1, 45},
        {6, 6, 4, 1, 56},
        {3, 9, 4, 1, 78},
        {6, 9, 4, 1, 89},
        //
        //horizontal edges: 6
        //
        /*
             1 2 3
             4 5 6
             6 7 8
        */
        //
        //   1  2  3
        //   |  |  |
        //   4  5  6
        //   |  |  |
        //   7  8  9
        // 
        {3, 3, 1, 4, 14},
        {6, 3, 1, 4, 25},
        {9, 3, 1, 4, 36},
        {3, 6, 1, 4, 47},
        {6, 6, 1, 4, 58},
        {9, 6, 1, 4, 69},
        //
        //diagonal edges - top-left to bottom-right aka forward slashed : 4
        //
        /*
             1 2 3
             4 5 6
             6 7 8
        */
        //
        //   1  2  3
        //     \  \
        //   4  5  6
        //     \  \ 
        //   7  8  9
        //
        {3, 3, 4, 4, 15},
        {6, 3, 4, 4, 26},
        {3, 6, 4, 4, 48},
        {6, 6, 4, 4, 59},
        //
        //diagonal edges - top-right to bottom-left aka backslashed : 4
        //
        /*
             1 2 3
             4 5 6
             6 7 8
        */
        //
        //   1  2  3
        //     /  /
        //   4  5  6
        //     /  / 
        //   7  8  9
        //
        {3, 3, 4, 4, 24},
        {6, 3, 4, 4, 35},
        {3, 6, 4, 4, 57},
        {6, 6, 4, 4, 68},

     };

#elif __USE_2x2_MATRIX__

BOImageTablePosition kBackgroundTablePosition[1] =
{
    { 0, 0,     20, 20,   -1},
};



const int kTotalNodeCells = 4; 

const int kTotalEdgeCells = 6;
const int kTotalEdgeCells_Vertical = 2;
const int kTotalEdgeCells_Horizontal = 2;
const int kTotalEdgeCells_ForwardSlashed = 1;
const int kTotalEdgeCells_BackwardSlashed = 1;

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
