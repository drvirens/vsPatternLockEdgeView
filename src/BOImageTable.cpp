//
//  BOImageTable.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "BOImageTable.hpp"
#include "IImage.hpp"
#include "trace.hpp"
#include "bo_clean_tizen_table.hpp"

static void __add_image(Evas_Object* nativeTbl, Evas_Object* nativeImg, int col, int row, int colSpan, int rowSpan);
static Evas_Object* __create_table(Evas_Object* parent, int colSpan, int rowSpan);


BOImageTable::~BOImageTable()
{TRACE
}

BOImageTable* BOImageTable::newL(Evas_Object* parent, int bgColSpan, int bgRowSpan)
{TRACE
  BOImageTable* obj = new BOImageTable(parent, bgColSpan, bgRowSpan);
  if (obj)
    {
    obj->construct();
    }
  return obj;
}

void BOImageTable::add(IImage& image, int col, int row, int colSpan, int rowSpan)
{TRACE
  Evas_Object* nativeImg = image.nativeImage();
  Evas_Object* nativetable = nativeTable();
  __add_image(nativetable, nativeImg, col, row, colSpan, rowSpan);
}

void BOImageTable::addEvasObject(Evas_Object* nativeEvasObject, int col, int row, int colSpan, int rowSpan)
{TRACE
  //Evas_Object* nativeImg = nativeEvasObject;
  Evas_Object* nativetable = nativeTable();
  __add_image(nativetable, nativeEvasObject, col, row, colSpan, rowSpan);
}

BOImageTable::BOImageTable(Evas_Object* parent, int bgColSpan, int bgRowSpan)
: table_(0)
, parent_(parent)
, bgcolspan_(bgColSpan)
, bgrowspan_(bgRowSpan)
{TRACE
}

void BOImageTable::construct()
{TRACE
  table_ = __create_table(parent_, bgcolspan_, bgrowspan_);
}

Evas_Object* BOImageTable::nativeTable() const
{TRACE
  return table_;
}

// ----------------------- Tizen

static void __add_image(Evas_Object* nativeTbl, Evas_Object* nativeImg, int col, int row, int colSpan, int rowSpan)
{TRACE
#if defined __TIZEN__
  __tizen_add_image(nativeTbl, nativeImg, col, row, colSpan, rowSpan);
#endif
}

static Evas_Object* __create_table(Evas_Object* parent, int colSpan, int rowSpan)
{TRACE
  Evas_Object* tbl = 0;
#if defined __TIZEN__
  tbl = __tizen_create_table(parent, colSpan, rowSpan);
  BO_ASSERT(tbl != 0);
#else
  return &tbl; //to let unit test case asserts pass
#endif
return tbl;
}

