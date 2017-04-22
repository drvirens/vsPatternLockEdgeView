//
//  ImageOuter.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageOuter.hpp"
#include "trace.hpp"

static const string kImageName = "images/image_outer.png";

ImageOuter* ImageOuter::newL(Evas_Object* parent)
{TRACE
  ImageOuter* obj = new ImageOuter(parent);
  if (obj)
  {
  obj->construct();
  }
  return obj;
}

ImageOuter::ImageOuter(Evas_Object* parent)
: IImage(parent)
{TRACE
}


void ImageOuter::pre()
{TRACE
  filename_ = kImageName;
  DBG("ImageName: %s\n", filename_.c_str());
}

void ImageOuter::post()
{TRACE
}

int ImageOuter::animated() const
{TRACE
  return 1; 
}

void ImageOuter::construct()
{TRACE
  IImage::construct();
}

ImageOuter::~ImageOuter()
{TRACE
}
