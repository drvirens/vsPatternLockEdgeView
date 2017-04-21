//
//  bo_clean_tizen_table.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#if defined __TIZEN__

#include "bo_clean_tizen_table.hpp"

#include <evas.h>
#include <Elementary.h>
#include "bo_colors.h"
#include "bo_file_utils.h"
#include "logger.h"
#include "BOBackgroundSpec.hpp"

static const int kTablePaddingHorizontal = 0;
static const int kTablePaddingVertical = 0;

static Evas_Object *view_create_background(Evas_Object *parent,
    const char* bg_image,
    int use_colors_only,
    int use_color_and_image,
    int r, int g, int b, int a) 
{TRACE
  if ( ( (!bg_image) && (!use_colors_only) && (!use_color_and_image)) ) 
  {
    return NULL;
  }
  Evas_Object *bg = elm_bg_add(parent);
  if (!bg) {
    return NULL;
  }
  if (use_color_and_image) 
  {
    char path[PATH_MAX] = { 0 };
    get_app_resource(bg_image, path);
    elm_bg_option_set(bg, ELM_BG_OPTION_SCALE);
    elm_bg_file_set(bg, path, NULL);
    elm_bg_color_set(bg, r, g, b);
  } 
  else if (!bg_image || use_colors_only) 
  {
    Evas* evas_canvas = evas_object_evas_get(parent);
    bg = evas_object_rectangle_add(evas_canvas);
    evas_object_color_set(bg, r, g, b, a); // opaque white background
  }
  evas_object_show(bg);
  return bg;
}

Evas_Object* __tizen_create_table(Evas_Object* parent, int colSpan, int rowSpan, const BOBackgroundSpec& bgspecs)
{TRACE
  Evas_Object* table = elm_table_add(parent);
  elm_table_padding_set(table, kTablePaddingHorizontal, kTablePaddingVertical);
  elm_table_homogeneous_set(table, EINA_TRUE);
  
  int red = bgspecs.r_;
  int green = bgspecs.g_;
  int blue = bgspecs.b_;
  int alpha = bgspecs.a_;

  //table background
  static const char* bg_image = NULL;
  static const int use_colors_only = 1;
  static const int use_color_and_image = 0;

  Evas_Object* bg = view_create_background(table, bg_image, use_colors_only, use_color_and_image, red, green, blue, alpha);

  if (bg) 
  {
    evas_object_size_hint_align_set(bg, EVAS_HINT_FILL, EVAS_HINT_FILL);
    evas_object_size_hint_weight_set(bg, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
    elm_table_pack(table, bg, 0, 0, colSpan, rowSpan);
    evas_object_show(bg);
  }
  evas_object_show(table);
  return table;
}

void __tizen_add_image(Evas_Object* nativeTbl, Evas_Object* nativeImg, int col, int row, int colSpan, int rowSpan)
{TRACE
  elm_table_pack(nativeTbl, nativeImg, col, row, colSpan, rowSpan);
  evas_object_size_hint_align_set(nativeImg, EVAS_HINT_FILL, EVAS_HINT_FILL);
  evas_object_size_hint_weight_set(nativeImg, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
}

void __tizen_addMouseDownEventHandler(Evas_Object* nativeTbl, Evas_Object_Event_Cb cb, void* data)
{TRACE
  evas_object_event_callback_add(nativeTbl, EVAS_CALLBACK_MOUSE_DOWN, cb, data);
}
void __tizen_addMouseUpEventHandler(Evas_Object* nativeTbl, Evas_Object_Event_Cb cb, void* data)
{TRACE
  evas_object_event_callback_add(nativeTbl, EVAS_CALLBACK_MOUSE_UP, cb, data);
}
void __tizen_addMouseMoveEventHandler(Evas_Object* nativeTbl, Evas_Object_Event_Cb cb, void* data)
{TRACE
  evas_object_event_callback_add(nativeTbl, EVAS_CALLBACK_MOUSE_MOVE, cb, data);
}

void __tizen_table_position(Evas_Object* nativetable, int& x, int& y, int& w, int& h)
{TRACE
  evas_object_geometry_get(nativetable, &x, &y, &w, &h);
}
#endif
