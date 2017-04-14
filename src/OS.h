//
//  OS.h
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef OS_h
#define OS_h

#if defined __APPLE__
typedef void Evas_Object;
#endif

#if defined __TIZEN__
#include <evas.h>
#endif

#endif /* OS_h */
