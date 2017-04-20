//
//  BOImageTable.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#include <vector>
#include "OS.h"
#include "CommonDef.hpp"

using namespace std;

class IImage;

#if defined __TIZEN__
void _mouse_down_cb(void *data, Evas *e, Evas_Object *obj, void *event_info);
#endif


class BOImageTable
{
#if defined __TIZEN__
friend void _mouse_down_cb(void *data, Evas *e, Evas_Object *obj, void *event_info);
#endif
 public:
  virtual ~BOImageTable();
  static BOImageTable* newL(Evas_Object* parent, int bgColSpan, int bgRowSpan);
  void add(IImage& image, int col, int row, int colSpan, int rowSpan);
  void addEvasObject(Evas_Object* nativeEvasObject, int col, int row, int colSpan, int rowSpan);
  void addMouseDownEventHandler(BOImageTableEventCallback cb, void* data);
  Evas_Object* nativeTable() const;
  
  void geometry(int& x, int& y, int& w, int& h);
  
 private:
  BOImageTable(Evas_Object* parent, int bgColSpan, int bgRowSpan);
  void construct();
  
 private:
  vector<IImage*> items_;
  Evas_Object* table_;
  Evas_Object* parent_;
  int bgcolspan_;
  int bgrowspan_;
  
  BOImageTableEventCallback mousedowncb_;
  void* mousedowncb_data_;
};

#endif /* Table_hpp */
