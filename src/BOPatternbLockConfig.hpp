//
//  BOPatternbLockConfig.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/18/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef BOPatternbLockConfig_hpp
#define BOPatternbLockConfig_hpp

class BOPatternbLockConfig
{
 public:
  int columns() const { return columns_; }
  int rows() const { return rows_; }
  int columnspan() const { return columnspan_; }
  int rowspan() const { return rowspan_; }
  
 public:
  static const int kTotalRows;
  static const int kTotalColumns;
  static const int kTotalCells;
  
 private:
  int columns_;
  int rows_;
  int columnspan_;
  int rowspan_;
};

#endif /* BOPatternbLockConfig_hpp */
