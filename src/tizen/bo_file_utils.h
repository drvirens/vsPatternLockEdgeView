/*
 * bo_file_utils.h
 *
 *  Created on: Feb 4, 2017
 *      Author: virendra.shakya
 */


#ifndef BO_FILE_UTILS_H_
#define BO_FILE_UTILS_H_

#if defined __TIZEN__

#include <Elementary.h>

#ifdef __cplusplus
extern "C" {
#endif

void get_app_resource(const char *file_name_in, char *file_path_out);
Evas_Object* bo_utils_create_spacer_view(Evas_Object *table, int height);

#ifdef __cplusplus
}
#endif

#endif //#if defined __TIZEN__

#endif /* BO_FILE_UTILS_H_ */
