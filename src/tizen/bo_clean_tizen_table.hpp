//
//  bo_clean_tizen_table.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef bo_clean_tizen_table_hpp
#define bo_clean_tizen_table_hpp

#ifdef __cplusplus
extern "C" {
#endif

#if defined __TIZEN__

#include <evas.h>
#include "CommonDef.hpp"

Evas_Object* __tizen_create_table(Evas_Object* parent, int colSpan, int rowSpan);
void __tizen_add_image(Evas_Object* nativeTbl, Evas_Object* nativeImg, int col, int row, int colSpan, int rowSpan);
void __tizen_addMouseDownEventHandler(Evas_Object* nativeTbl, Evas_Object_Event_Cb cb, void* data);
void __tizen_addMouseUpEventHandler(Evas_Object* nativeTbl, Evas_Object_Event_Cb cb, void* data);
void __tizen_addMouseMoveEventHandler(Evas_Object* nativeTbl, Evas_Object_Event_Cb cb, void* data);
void __tizen_table_position(Evas_Object* nativetable, int& x, int& y, int& w, int& h);

#endif //#if defined __TIZEN__

#ifdef __cplusplus
}
#endif

#endif /* bo_clean_tizen_table_hpp */
