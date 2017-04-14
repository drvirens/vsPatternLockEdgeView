//
//  Table.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "Table.hpp"
#include "IImage.hpp"
#include "trace.hpp"
#include "bo_clean_tizen_table.hpp"

static void __add_image(Evas_Object* nativeTable, Evas_Object* nativeImg, int col, int row, int colSpan, int rowSpan);
static Evas_Object* __create_table(Evas_Object* parent, int colSpan, int rowSpan);


Table::~Table()
{TRACE
}

Table* Table::newL(Evas_Object* parent, int bgColSpan, int bgRowSpan)
{TRACE
  Table* obj = new Table(parent, bgColSpan, bgRowSpan);
  if (obj)
    {
    obj->construct();
    }
  return obj;
}

void Table::add(IImage& image, int col, int row, int colSpan, int rowSpan)
{TRACE
  Evas_Object* nativeImg = image.nativeImage();
  Evas_Object* nativeTable = table_;
  __add_image(nativeTable, nativeImg, col, row, colSpan, rowSpan);
  
  items_.push_back(&image);
}

Table::Table(Evas_Object* parent, int bgColSpan, int bgRowSpan)
: table_(0)
, parent_(parent)
, bgcolspan_(bgColSpan)
, bgrowspan_(bgRowSpan)
{TRACE
}

void Table::construct()
{TRACE
  table_ = __create_table(parent_, bgcolspan_, bgrowspan_);
}

Evas_Object* Table::nativeTable() const
{TRACE
  return table_;
}

// ----------------------- Tizen
#if defined __TIZEN__

#endif

static void __add_image(Evas_Object* nativeTable, Evas_Object* nativeImg, int col, int row, int colSpan, int rowSpan)
{TRACE
#if defined __TIZEN__
#endif
}

static Evas_Object* __create_table(Evas_Object* parent, int colSpan, int rowSpan)
{TRACE
  Evas_Object* tbl = 0;
#if defined __TIZEN__
  tbl = __tizen_create_table(parent, colSpan, rowSpan);
#endif
return tbl;
}

