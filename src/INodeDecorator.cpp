//
//  INodeDecorator.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/14/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "INodeDecorator.hpp"
#include "trace.hpp"


INodeDecorator::~INodeDecorator()
{TRACE
}
void INodeDecorator::now(CNodeContext& context)
{TRACE
}
void INodeDecorator::decorate(EHotspotColor color)
{TRACE
  nodeview_.decorate(color);
}
INodeDecorator::INodeDecorator(INodeView& nodeView,BOImageTable& parent, IImage*& images)
: INodeView(&parent, images)
, nodeview_(nodeView)
{TRACE
}

