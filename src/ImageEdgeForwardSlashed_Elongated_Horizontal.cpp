//
//  ImageEdgeForwardSlashed_Elongated_Horizontal.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/22/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageEdgeForwardSlashed_Elongated_Horizontal.hpp"
#include "trace.hpp"

static const string kImageName = "images/forwardslashed_Elongated_Horizontal.png";

ImageEdgeForwardSlashed_Elongated_Horizontal* ImageEdgeForwardSlashed_Elongated_Horizontal::newL(Evas_Object* parent)
{TRACE
  ImageEdgeForwardSlashed_Elongated_Horizontal* obj = new ImageEdgeForwardSlashed_Elongated_Horizontal(parent);
  if (obj)
  {
    obj->construct();
  }
  return obj;
}

ImageEdgeForwardSlashed_Elongated_Horizontal::ImageEdgeForwardSlashed_Elongated_Horizontal(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageEdgeForwardSlashed_Elongated_Horizontal::pre()
{TRACE
  filename_ = kImageName;
  DBG("ImageName: %s\n", filename_.c_str());
}

void ImageEdgeForwardSlashed_Elongated_Horizontal::post()
{TRACE
}

int ImageEdgeForwardSlashed_Elongated_Horizontal::animated() const
{TRACE
  return 1; 
}

void ImageEdgeForwardSlashed_Elongated_Horizontal::construct()
{TRACE
  IImage::construct();
}

ImageEdgeForwardSlashed_Elongated_Horizontal::~ImageEdgeForwardSlashed_Elongated_Horizontal()
{TRACE
}
