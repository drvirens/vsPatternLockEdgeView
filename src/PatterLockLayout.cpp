//
//  PatterLockLayout.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/19/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "PatterLockLayout.hpp"


static const int kBackgroundCell = 1; 
const int kTotalNodeCells = 9; 
const int kTotalEdgeCells = 20;

const int kTotalTableCells = kTotalNodeCells + kBackgroundCell;
const int kBackgroundCellIndex = kTotalTableCells - 1;

BOImageTablePosition kNodesTablePositions[kTotalTableCells] =
     {
        //row 1
        {2, 2, 3, 3}, 
        {5, 2, 3, 3},
        {8, 2, 3, 3},
        //row 2
        {2, 5, 3, 3},
        {5, 5, 3, 3},
        {8, 5, 3, 3},
        //row 3
        {2, 8, 3, 3},
        {5, 8, 3, 3},
        {8, 8, 3, 3},
        //bg
        {0, 0, 13, 13} //always kBackgroundCellIndex
     };


BOImageTablePosition kEdgesTablePositions[kTotalEdgeCells] =
     {
        //row 1
        {3, 2, 4, 3}, 
//        {5, 2, 3, 3},
//        {8, 2, 3, 3},
//        //row 2
//        {2, 5, 3, 3},
//        {5, 5, 3, 3},
//        {8, 5, 3, 3},
//        //row 3
//        {2, 8, 3, 3},
//        {5, 8, 3, 3},
//        {8, 8, 3, 3},
     };

