//
//  EdgeColorDecorator.cpp
//  vsEdgeView
//
//  Created by Virendra Shakya on 4/14/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "EdgeColorDecorator.hpp"
#include "IImage.hpp"
#include "trace.hpp"


EdgeColorDecorator::~EdgeColorDecorator()
{TRACE
}
void EdgeColorDecorator::now(CEdgeContext& context)
{TRACE
}
void EdgeColorDecorator::decorate(EHotspotColor color)
{TRACE
  IEdgeDecorator::decorate(color);
  DBG("set all image color to be RED here\n");
  IImage& edgeimg = edge();
  edgeimg.decorate(color);
}
EdgeColorDecorator::EdgeColorDecorator(IEdgeView& nodeView, BOImageTable& parent, IImage& image)
: IEdgeDecorator(nodeView, parent, image)
{TRACE
}
void EdgeColorDecorator::construct()
{TRACE
}
