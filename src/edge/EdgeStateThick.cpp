//
//  EdgeStateThick.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/17/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "EdgeStateThick.hpp"
#include "CEdgeContext.hpp"
#include "EdgeStateThin.hpp"
#include "IImage.hpp"
#include "trace.hpp"

EdgeStateThick* EdgeStateThick::newL(BOImageTable& table, IImage& image)
{TRACE
  EdgeStateThick* obj = new EdgeStateThick(table, image);
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
  edge().show();
}

void EdgeStateThick::decorate(EHotspotColor color)
{TRACE
}

EdgeStateThick::EdgeStateThick(BOImageTable& table, IImage& image)
: IEdgeView(&table, image)
{TRACE
}

void EdgeStateThick::construct()
{TRACE
}
