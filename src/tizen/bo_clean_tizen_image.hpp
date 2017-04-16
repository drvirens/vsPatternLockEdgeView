//
//  bo_clean_tizen_image.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef bo_clean_tizen_image_hpp
#define bo_clean_tizen_image_hpp

#ifdef __cplusplus
extern "C" {
#endif

#if defined __TIZEN__

#include <evas.h>
#include "NodeColor.hpp"

extern Evas_Object* __tizen_create_image(Evas_Object* parent);
extern void __tizen_set_up_image(Evas_Object* image, const char* image_file_name);
extern void __tizen_image_display_enable(Evas_Object* image, int enable, int animated);
extern void __tizen_decorate_image(Evas_Object* image, EHotspotColor color, int animated);

#endif //#if defined __TIZEN__

#ifdef __cplusplus
}
#endif

#endif /* bo_clean_tizen_image_hpp */
