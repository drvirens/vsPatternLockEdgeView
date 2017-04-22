//
//  ImageEdgeForwardSlashed.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageEdgeForwardSlashed.hpp"
#include "trace.hpp"

static const string kImageName = "images/forwardslashed.png";

ImageEdgeForwardSlashed* ImageEdgeForwardSlashed::newL(Evas_Object* parent)
{TRACE
  ImageEdgeForwardSlashed* obj = new ImageEdgeForwardSlashed(parent);
  if (obj)
  {
    obj->construct();
  }
  return obj;
}

ImageEdgeForwardSlashed::ImageEdgeForwardSlashed(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageEdgeForwardSlashed::pre()
{TRACE
  filename_ = kImageName;
  DBG("ImageName: %s\n", filename_.c_str());
}

void ImageEdgeForwardSlashed::post()
{TRACE
}

int ImageEdgeForwardSlashed::animated() const
{TRACE
  return 1; 
}

void ImageEdgeForwardSlashed::construct()
{TRACE
  IImage::construct();
}

ImageEdgeForwardSlashed::~ImageEdgeForwardSlashed()
{TRACE
}

