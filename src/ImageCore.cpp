//
//  ImageCore.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageCore.hpp"
#include "trace.hpp"

static const string kImageName = "images/image_core.png";

ImageCore* ImageCore::newL(Evas_Object* parent)
{TRACE
  ImageCore* obj = new ImageCore(parent);
  if (obj)
  {
    obj->construct();
  }
  return obj;
}

ImageCore::ImageCore(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageCore::pre()
{TRACE
  file_name_ = kImageName;
  DBG("ImageName: %s\n", file_name_.c_str());
}

void ImageCore::post()
{TRACE
}

int ImageCore::animated() const
{TRACE
  return 0; //never animate this guy
}

void ImageCore::construct()
{TRACE
  IImage::construct();
}

ImageCore::~ImageCore()
{TRACE
}
