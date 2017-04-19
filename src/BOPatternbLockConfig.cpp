//
//  BOPatternbLockConfig.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/18/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "BOPatternbLockConfig.hpp"
#include "trace.hpp"

const int BOPatternbLockConfig::kTotalRows = 3;
const int BOPatternbLockConfig::kTotalColumns = 3;
const int BOPatternbLockConfig::kTotalCells = 9; //BOPatternbLockConfig::kTotalRows * BOPatternbLockConfig::kTotalColumns;



BOPatternbLockConfig::BOPatternbLockConfig()
: columns_(BOPatternbLockConfig::kTotalColumns)
, rows_(BOPatternbLockConfig::kTotalRows)
, columnspan_(0)
, rowspan_(0)
{TRACE
}
