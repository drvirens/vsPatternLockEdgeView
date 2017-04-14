//
//  Table.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#include <vector>
#include "OS.h"

using namespace std;

class IImage;

class Table
{
 public:
  virtual ~Table();
  static Table* newL(Evas_Object* parent, int bgColSpan, int bgRowSpan);
  void add(IImage& image, int col, int row, int colSpan, int rowSpan);
  Evas_Object* nativeTable() const;
  
 private:
  Table(Evas_Object* parent, int bgColSpan, int bgRowSpan);
  void construct();
  
 private:
  vector<IImage*> items_;
  Evas_Object* table_;
  Evas_Object* parent_;
  int bgcolspan_;
  int bgrowspan_;
};

#endif /* Table_hpp */
