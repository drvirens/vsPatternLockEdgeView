//
//  StateActive.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "StateActive.hpp"
#include "CNodeContext.hpp"
#include "StateActive.hpp"
#include "IImage.hpp"
#include "trace.hpp"


void StateActive::now(CNodeContext& context)
{TRACE
  core().hide();
  inner().show();
  middle().show();
  outer().show();
  
  context.setPassive();
}

void StateActive::decorate(EHotspotColor color)
{TRACE
}

StateActive::StateActive(Table& parent, IImage*& images)
: INodeView(&parent, images)
{TRACE
}


StateActive* StateActive::newL(Table& parent, IImage*& images)
{TRACE
  StateActive* obj = new StateActive(parent, images);
  if (obj) 
    {
    obj->construct();
    }
  return obj;
}

StateActive::~StateActive()
{TRACE
}

void StateActive::construct()
{TRACE
  INodeView::construct();
}

