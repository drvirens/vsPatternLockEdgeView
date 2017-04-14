//
//  ImageInner.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageInner.hpp"
#include "trace.hpp"

static const string kImageName = "images/image_inner.png";

ImageInner* ImageInner::newL(Evas_Object* parent)
{TRACE
  ImageInner* obj = new ImageInner(parent);
  if (obj)
  {
  obj->construct();
  }
  return obj;
}

ImageInner::ImageInner(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageInner::pre()
{TRACE
  filename_ = kImageName;
  DBG("ImageName: %s\n", filename_.c_str());
}

void ImageInner::post()
{TRACE
}

int ImageInner::animated() const
{TRACE
  return 1; 
}

void ImageInner::construct()
{TRACE
  IImage::construct();
}

ImageInner::~ImageInner()
{TRACE
}
