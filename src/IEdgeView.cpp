//
//  IEdgeView.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/16/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "IEdgeView.hpp"
#include "trace.hpp"
#include "ImageCore.hpp"
#include "ImageInner.hpp"
#include "ImageMiddle.hpp"
#include "ImageOuter.hpp"

IEdgeView::~IEdgeView()
{TRACE
}

IEdgeView::IEdgeView(BOImageTable* parent, IImage*& images)
: parent_(parent)
, images_(&images)
{TRACE
}

void IEdgeView::construct()
{TRACE
}

IImage& IEdgeView::edge()
{TRACE
  IImage* i = images_[EImageCore];
  BO_ASSERT(i);
  return *i;
}
