//
//  NodeColorDecorator.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/14/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "NodeColorDecorator.hpp"
#include "trace.hpp"


NodeColorDecorator::~NodeColorDecorator()
{TRACE
}
void NodeColorDecorator::now(CNodeContext& context)
{TRACE
}
void NodeColorDecorator::decorate(EHotspotColor color)
{TRACE
  INodeDecorator::decorate(color);
  DBG("set all image color to be RED here\n");
}
NodeColorDecorator::NodeColorDecorator(INodeView& nodeView, Table& parent, IImage*& images)
: INodeDecorator(nodeView, parent, images)
{TRACE
}
void NodeColorDecorator::construct()
{TRACE
}
