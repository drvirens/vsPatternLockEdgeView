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

Evas_Object* __tizen_create_table(Evas_Object* parent, int colSpan, int rowSpan);

#endif //#if defined __TIZEN__

#ifdef __cplusplus
}
#endif

#endif /* bo_clean_tizen_table_hpp */
