//
//  EdgeStateThin.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/17/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "EdgeStateThin.hpp"
#include "trace.hpp"

EdgeStateThin* EdgeStateThin::newL(Table& parent, IImage*& images)
{TRACE
  EdgeStateThin* obj = new EdgeStateThin(parent, images);
  if (obj) 
    {
    obj->construct();
    }
  return obj;
}

EdgeStateThin::~EdgeStateThin()
{TRACE
}

void EdgeStateThin::now(CEdgeContext& context)
{TRACE
}

void EdgeStateThin::decorate(EHotspotColor color)
{TRACE
}

EdgeStateThin::EdgeStateThin(Table& parent, IImage*& images)
: IEdgeView(&parent, images)
{TRACE
}

void EdgeStateThin::construct()
{TRACE
}
