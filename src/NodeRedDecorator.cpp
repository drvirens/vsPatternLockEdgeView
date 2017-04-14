//
//  NodeRedDecorator.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/14/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "NodeRedDecorator.hpp"
#include "trace.hpp"


NodeRedDecorator::~NodeRedDecorator()
{TRACE
}
void NodeRedDecorator::now(CNodeContext& context)
{TRACE
}
void NodeRedDecorator::decorate(EHotspotColor color)
{TRACE
  INodeDecorator::decorate(color);
  DBG("set all image color to be RED here\n");
}
NodeRedDecorator::NodeRedDecorator(INodeView& nodeView, Table& parent, IImage*& images)
: INodeDecorator(nodeView, parent, images)
{TRACE
}
void NodeRedDecorator::construct()
{TRACE
}
