//
//  ImageEdgeHorizontal.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageEdgeHorizontal.hpp"
#include "trace.hpp"

static const string kImageName = "images/horizontal.png";

ImageEdgeHorizontal* ImageEdgeHorizontal::newL(Evas_Object* parent)
{TRACE
  ImageEdgeHorizontal* obj = new ImageEdgeHorizontal(parent);
  if (obj)
  {
    obj->construct();
  }
  return obj;
}

ImageEdgeHorizontal::ImageEdgeHorizontal(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageEdgeHorizontal::pre()
{TRACE
  filename_ = kImageName;
  DBG("ImageName: %s\n", filename_.c_str());
}

void ImageEdgeHorizontal::post()
{TRACE
}

int ImageEdgeHorizontal::animated() const
{TRACE
  return 1; 
}

void ImageEdgeHorizontal::construct()
{TRACE
  IImage::construct();
}

ImageEdgeHorizontal::~ImageEdgeHorizontal()
{TRACE
}
