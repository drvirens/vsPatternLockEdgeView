//
//  bo_clean_tizen_image.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#if defined __TIZEN__

#include "bo_clean_tizen_image.hpp"
#include <evas.h>
#include <Elementary.h>
#include "bo_colors.h"
#include "bo_file_utils.h"
#include "logger.h"


Evas_Object* __tizen_create_image(Evas_Object* parent) 
{TRACE
  Evas_Object* image = 0;
  image = elm_image_add(parent);
  return image;
}

void __tizen_set_up_image(Evas_Object* image, const char* image_file_name)
{TRACE
  char path[100] = { 0 };
  snprintf(path, sizeof(path), "%s%s", app_get_resource_path(), image_file_name);
  elm_image_file_set(image, path, NULL);
  evas_object_hide(image); //keep it hidden by default
}

static void __tizen_image_transit_zoom(Evas_Object* image)
{TRACE
   Elm_Transit* trans = NULL;

   trans = elm_transit_add();
   elm_transit_object_add(trans, image);

   elm_transit_effect_zoom_add(trans, 1.0, 1.25);

   elm_transit_duration_set(trans, 0.25);
   elm_transit_auto_reverse_set(trans, EINA_TRUE);
   elm_transit_objects_final_state_keep_set(trans, EINA_TRUE);
   elm_transit_go(trans);
}

void __tizen_image_display_enable(Evas_Object* image, int enable, int animated)
{TRACE
  if (enable)
  {
    evas_object_show(image);
    if (animated)
      {
      __tizen_image_transit_zoom(image);
      }
  }
  else 
  {
    evas_object_hide(image);
  }
}
  
#endif //#if defined __TIZEN__
