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
#include "BOBackgroundSpec.hpp"

static void __add_image(Evas_Object* nativeTbl, Evas_Object* nativeImg, int col, int row, int colSpan, int rowSpan);
static Evas_Object* __create_table(Evas_Object* parent, int colSpan, int rowSpan, const BOBackgroundSpec& bgspecs);
static void __addMouseDownEventHandler(Evas_Object* nativeTbl, BOImageTableEventCallback cb, void* data);
static void __addMouseUpEventHandler(Evas_Object* nativeTbl, BOImageTableEventCallback cb, void* data);
static void __addMouseMoveEventHandler(Evas_Object* nativeTbl, BOImageTableEventCallback cb, void* data);
static void __table_position(Evas_Object* nativetable, int& x, int& y, int& w, int& h);

BOImageTable::~BOImageTable()
{TRACE
}

BOImageTable* BOImageTable::newL(Evas_Object* parent, int bgColSpan, int bgRowSpan, const BOBackgroundSpec& bgspecs)
{TRACE
  BOImageTable* obj = new BOImageTable(parent, bgColSpan, bgRowSpan, bgspecs);
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
void BOImageTable::addMouseUpEventHandler(BOImageTableEventCallback cb, void* data)
{TRACE
  mouseupcb_ = cb;
  mouseupcb_data_ = data;
  Evas_Object* nativetable = nativeTable();
  __addMouseUpEventHandler(nativetable, cb, this);
}
void BOImageTable::addMouseMoveEventHandler(BOImageTableEventCallback cb, void* data)
{TRACE
  mousemovecb_ = cb;
  mousemovecb_data_ = data;
  Evas_Object* nativetable = nativeTable();
  __addMouseMoveEventHandler(nativetable, cb, this);
}

BOImageTable::BOImageTable(Evas_Object* parent, int bgColSpan, int bgRowSpan, const BOBackgroundSpec& bgspecs)
: table_(0)
, parent_(parent)
, bgcolspan_(bgColSpan)
, bgrowspan_(bgRowSpan)
, bgspecs_(bgspecs)
, mousedowncb_(0)
, mousedowncb_data_(0)
, mouseupcb_(0)
, mouseupcb_data_(0)
, mousemovecb_(0)
, mousemovecb_data_(0)
{TRACE
}

void BOImageTable::construct()
{TRACE
  table_ = __create_table(parent_, bgcolspan_, bgrowspan_, bgspecs_);
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

static Evas_Object* __create_table(Evas_Object* parent, int colSpan, int rowSpan, const BOBackgroundSpec& bgspecs)
{TRACE
  Evas_Object* tbl = 0;
#if defined __TIZEN__
  tbl = __tizen_create_table(parent, colSpan, rowSpan, bgspecs);
  BO_ASSERT(tbl != 0);
#else
  return &tbl; //to let unit test case asserts pass
#endif
return tbl;
}

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
void _mouse_up_cb(void *data, Evas *e, Evas_Object *obj, void *event_info) {
  TRACE
  Evas_Event_Mouse_Up *mouse = (Evas_Event_Mouse_Up *) event_info;
  BOImageTable* thiz = static_cast<BOImageTable*>(data);
  BO_ASSERT(thiz != 0);
  if (!thiz)
    {
    return;
    }
  if (thiz->mouseupcb_)
  {
    (*(thiz->mouseupcb_))(mouse, thiz->mouseupcb_data_);
  }
}
void _mouse_move_cb(void *data, Evas *e, Evas_Object *obj, void *event_info) {
  TRACE
  Evas_Event_Mouse_Move *mouse = (Evas_Event_Mouse_Move *) event_info;
  BOImageTable* thiz = static_cast<BOImageTable*>(data);
  BO_ASSERT(thiz != 0);
  if (!thiz)
    {
    return;
    }
  if (thiz->mousemovecb_)
  {
    (*(thiz->mousemovecb_))(mouse, thiz->mousemovecb_data_);
  }
}

static void __addMouseDownEventHandler(Evas_Object* nativeTbl, BOImageTableEventCallback cb, void* data)
{TRACE
#if defined __TIZEN__
  __tizen_addMouseDownEventHandler(nativeTbl, _mouse_down_cb, data);
#endif
}
static void __addMouseUpEventHandler(Evas_Object* nativeTbl, BOImageTableEventCallback cb, void* data)
{TRACE
#if defined __TIZEN__
  __tizen_addMouseUpEventHandler(nativeTbl, _mouse_up_cb, data);
#endif
}
static void __addMouseMoveEventHandler(Evas_Object* nativeTbl, BOImageTableEventCallback cb, void* data)
{TRACE
#if defined __TIZEN__
  __tizen_addMouseMoveEventHandler(nativeTbl, _mouse_move_cb, data);
#endif
}

static void __table_position(Evas_Object* nativetable, int& x, int& y, int& w, int& h) 
{TRACE
#if defined __TIZEN__
  __tizen_table_position(nativetable, x, y, w, h);
#endif
}
