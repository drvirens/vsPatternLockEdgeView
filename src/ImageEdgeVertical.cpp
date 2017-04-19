//
//  ImageEdgeVertical.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageEdgeVertical.hpp"
#include "trace.hpp"

static const string kImageName = "images/vertical.png";

ImageEdgeVertical* ImageEdgeVertical::newL(Evas_Object* parent)
{TRACE
  ImageEdgeVertical* obj = new ImageEdgeVertical(parent);
  if (obj)
  {
  obj->construct();
  }
  return obj;
}

ImageEdgeVertical::ImageEdgeVertical(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageEdgeVertical::pre()
{TRACE
  filename_ = kImageName;
  DBG("ImageName: %s\n", filename_.c_str());
}

void ImageEdgeVertical::post()
{TRACE
}

int ImageEdgeVertical::animated() const
{TRACE
  return 1; 
}

void ImageEdgeVertical::construct()
{TRACE
  IImage::construct();
}

ImageEdgeVertical::~ImageEdgeVertical()
{TRACE
}
