//
//  trace.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef trace_hpp
#define trace_hpp

#include <assert.h>

#if defined __TIZEN__
#include "logger.h"
#else

#include <iostream>

using namespace std;

#define MODULE_INFO (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define DBG(fmt, arg...) printf(\
		"%s: %s(%d) : " fmt, MODULE_INFO, \
		__func__, __LINE__, ##arg)
    
// trace
#if defined SHOW_TRACE
#define TRACE printf("%s: %s (%d)\n", MODULE_INFO, __func__, __LINE__);
#else
#define TRACE
#endif

#endif


//assert
#define BO_ASSERT assert

#endif /* trace_hpp */
