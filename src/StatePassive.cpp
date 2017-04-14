//
//  StatePassive.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "StatePassive.hpp"
#include "CNodeContext.hpp"
#include "StateActive.hpp"
#include "IImage.hpp"
#include "trace.hpp"

void StatePassive::now(CNodeContext& context)
{TRACE
  core().show();
  inner().hide();
  middle().hide();
  outer().hide();
  
  context.setActive();
}

void StatePassive::decorate(EHotspotColor color)
{TRACE
}

StatePassive::StatePassive(Table& parent, IImage*& images)
: INodeView(parent, images)
{TRACE
}

StatePassive* StatePassive::newL(Table& parent, IImage*& images)
{TRACE
  StatePassive* obj = new StatePassive(parent, images);
  if (obj) 
    {
    obj->construct();
    }
  return obj;
}
void StatePassive::construct()
{TRACE
  INodeView::construct();
}

StatePassive::~StatePassive()
{TRACE
}
