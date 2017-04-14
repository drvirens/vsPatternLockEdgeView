//
//  ImageMiddle.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageMiddle.hpp"
#include "trace.hpp"

static const string kImageName = "images/image_middle.png";

ImageMiddle* ImageMiddle::newL(Evas_Object* parent)
{TRACE
  ImageMiddle* obj = new ImageMiddle(parent);
  if (obj)
  {
  obj->construct();
  }
  return obj;
}

ImageMiddle::ImageMiddle(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageMiddle::pre()
{TRACE
  file_name_ = kImageName;
  DBG("ImageName: %s\n", file_name_.c_str());
}

void ImageMiddle::post()
{TRACE
}

int ImageMiddle::animated() const
{TRACE
  return 1; 
}

void ImageMiddle::construct()
{TRACE
  IImage::construct();
}

ImageMiddle::~ImageMiddle()
{TRACE
}
