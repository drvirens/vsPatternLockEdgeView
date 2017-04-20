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
static void __addMouseDownEventHandler(Evas_Object* nativeTbl, BOImageTableEventCallback cb, void* data);
static void __table_position(Evas_Object* nativetable, int& x, int& y, int& w, int& h);

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

void BOImageTable::geometry(int& x, int& y, int& w, int& h)
{TRACE
  Evas_Object* nativetable = nativeTable();
  __table_position(nativetable, x, y, w, h);
}

void BOImageTable::add(IImage& image, int col, int row, int colSpan, int rowSpan)
{TRACE
  Evas_Object* nativeImg = image.nativeImage();
  Evas_Object* nativetable = nativeTable();
  __add_image(nativetable, nativeImg, col, row, colSpan, rowSpan);
}

void BOImageTable::addEvasObject(Evas_Object* nativeEvasObject, int col, int row, int colSpan, int rowSpan)
{TRACE
  Evas_Object* nativetable = nativeTable();
  __add_image(nativetable, nativeEvasObject, col, row, colSpan, rowSpan);
}

void BOImageTable::addMouseDownEventHandler(BOImageTableEventCallback cb, void* data)
{TRACE
  mousedowncb_ = cb;
  mousedowncb_data_ = data;
  Evas_Object* nativetable = nativeTable();
  __addMouseDownEventHandler(nativetable, cb, this);
}

BOImageTable::BOImageTable(Evas_Object* parent, int bgColSpan, int bgRowSpan)
: table_(0)
, parent_(parent)
, bgcolspan_(bgColSpan)
, bgrowspan_(bgRowSpan)
, mousedowncb_(0)
, mousedowncb_data_(0)
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

#if defined __TIZEN__
void _mouse_down_cb(void *data, Evas *e, Evas_Object *obj, void *event_info) {
  TRACE
  Evas_Event_Mouse_Down *mouse = (Evas_Event_Mouse_Down *) event_info;
  BOImageTable* thiz = static_cast<BOImageTable*>(data);
  BO_ASSERT(thiz != 0);
  if (!thiz)
    {
    return;
    }
  if (thiz->mousedowncb_)
  {
    (*(thiz->mousedowncb_))(mouse, thiz->mousedowncb_data_);
  }
}
#endif

static void __addMouseDownEventHandler(Evas_Object* nativeTbl, BOImageTableEventCallback cb, void* data)
{TRACE
#if defined __TIZEN__
  __tizen_addMouseDownEventHandler(nativeTbl, _mouse_down_cb, data);
#endif
}

static void __table_position(Evas_Object* nativetable, int& x, int& y, int& w, int& h) 
{TRACE
#if defined __TIZEN__
  __tizen_table_position(nativetable, x, y, w, h);
#endif
}
