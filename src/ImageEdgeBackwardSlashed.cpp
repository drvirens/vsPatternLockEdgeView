//
//  ImageEdgeBackwardSlashed.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageEdgeBackwardSlashed.hpp"
#include "trace.hpp"

static const string kImageName = "images/backwardslashed.png";

ImageEdgeBackwardSlashed* ImageEdgeBackwardSlashed::newL(Evas_Object* parent)
{TRACE
  ImageEdgeBackwardSlashed* obj = new ImageEdgeBackwardSlashed(parent);
  if (obj)
  {
    obj->construct();
  }
  return obj;
}

ImageEdgeBackwardSlashed::ImageEdgeBackwardSlashed(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageEdgeBackwardSlashed::pre()
{TRACE
  filename_ = kImageName;
  DBG("ImageName: %s\n", filename_.c_str());
}

void ImageEdgeBackwardSlashed::post()
{TRACE
}

int ImageEdgeBackwardSlashed::animated() const
{TRACE
  return 1; 
}

void ImageEdgeBackwardSlashed::construct()
{TRACE
  IImage::construct();
}

ImageEdgeBackwardSlashed::~ImageEdgeBackwardSlashed()
{TRACE
}
