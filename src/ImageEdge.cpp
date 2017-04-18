//
//  ImageEdge.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageEdge.hpp"
#include "trace.hpp"

static const string kImageName = "images/horizontal-green.png";

ImageEdge* ImageEdge::newL(Evas_Object* parent)
{TRACE
  ImageEdge* obj = new ImageEdge(parent);
  if (obj)
  {
  obj->construct();
  }
  return obj;
}

ImageEdge::ImageEdge(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageEdge::pre()
{TRACE
  filename_ = kImageName;
  DBG("ImageName: %s\n", filename_.c_str());
}

void ImageEdge::post()
{TRACE
}

int ImageEdge::animated() const
{TRACE
  return 1; 
}

void ImageEdge::construct()
{TRACE
  IImage::construct();
}

ImageEdge::~ImageEdge()
{TRACE
}
