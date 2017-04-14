//
//  INodeView.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "INodeView.hpp"
#include "trace.hpp"
#include "ImageCore.hpp"
#include "ImageInner.hpp"
#include "ImageMiddle.hpp"
#include "ImageOuter.hpp"

INodeView::~INodeView()
{TRACE
}

INodeView::INodeView(Table* parent, IImage*& images)
: parent_(parent)
, images_(&images)
{TRACE
}

void INodeView::construct()
{TRACE
}

IImage& INodeView::core()
{TRACE
  IImage* i = images_[EImageCore];
  BO_ASSERT(i);
  return *i;
}
IImage& INodeView::inner()
{TRACE
  IImage* i = images_[EImageInner];
  BO_ASSERT(i);
  return *i;
}
IImage& INodeView::middle()
{TRACE
  IImage* i = images_[EImageMiddle];
  BO_ASSERT(i);
  return *i;
}
IImage& INodeView::outer()
{TRACE
  IImage* i = images_[EImageOuter];
  BO_ASSERT(i);
  return *i;
}

