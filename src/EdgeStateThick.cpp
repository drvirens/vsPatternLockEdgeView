//
//  EdgeStateThick.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/17/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "EdgeStateThick.hpp"
#include "trace.hpp"

EdgeStateThick* EdgeStateThick::newL(Table& table, IImage*& images)
{TRACE
  EdgeStateThick* obj = new EdgeStateThick(table, images);
  if (obj) 
    {
    obj->construct();
    }
  return obj;
}

EdgeStateThick::~EdgeStateThick()
{TRACE
}

void EdgeStateThick::now(CEdgeContext& context)
{TRACE
}

void EdgeStateThick::decorate(EHotspotColor color)
{TRACE
}

EdgeStateThick::EdgeStateThick(Table& table, IImage*& images)
: IEdgeView(&table, images)
{TRACE
}

void EdgeStateThick::construct()
{TRACE
}
