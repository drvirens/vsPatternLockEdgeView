/*
 * bo_file_utils.c
 *
 *  Created on: Feb 4, 2017
 *      Author: virendra.shakya
 */

#if defined __TIZEN__

#include <app_common.h>
#include <tizen.h>
#include "bo_file_utils.h"

void get_app_resource(const char *file_name_in, char *file_path_out) {
	char *res_path = app_get_resource_path();
	if(res_path) {
		snprintf(file_path_out, PATH_MAX, "%s%s", res_path, file_name_in);
		free(res_path);
	}
}

Evas_Object* bo_utils_create_spacer_view(Evas_Object *table, int height)   {
	  Evas_Object *bt;
	  char tmp[16];
	   snprintf(tmp, sizeof(tmp), "Space");
	   bt = elm_button_add(table);
	   elm_object_text_set(bt, tmp);

	    //static const int kAppIconWidth = 10;
	    //const int h = (thiz->win_height_) * 0.02;
	    evas_object_size_hint_min_set(bt, ELM_SCALE_SIZE(height), ELM_SCALE_SIZE(height));


	   elm_box_pack_end(table, bt);

	   return bt;
	  }

#endif //#if defined __TIZEN__
