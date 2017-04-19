//
//  IEdgeDecorator.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/14/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "IEdgeDecorator.hpp"
#include "trace.hpp"


IEdgeDecorator::~IEdgeDecorator()
{TRACE
}
void IEdgeDecorator::now(CEdgeContext& context)
{TRACE
}
void IEdgeDecorator::decorate(EHotspotColor color)
{TRACE
  edgeview_.decorate(color);
}
IEdgeDecorator::IEdgeDecorator(IEdgeView& edgeView,BOImageTable& parent, IImage& image)
: IEdgeView(&parent, image)
, edgeview_(edgeView)
{TRACE
}

