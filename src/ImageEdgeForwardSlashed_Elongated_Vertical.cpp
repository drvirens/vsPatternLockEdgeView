//
//  ImageEdgeForwardSlashed_Elongated_Vertical.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/22/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageEdgeForwardSlashed_Elongated_Vertical.hpp"
#include "trace.hpp"

static const string kImageName = "images/forwardslashed_Elongated_Vertical.png";

ImageEdgeForwardSlashed_Elongated_Vertical* ImageEdgeForwardSlashed_Elongated_Vertical::newL(Evas_Object* parent)
{TRACE
  ImageEdgeForwardSlashed_Elongated_Vertical* obj = new ImageEdgeForwardSlashed_Elongated_Vertical(parent);
  if (obj)
  {
    obj->construct();
  }
  return obj;
}

ImageEdgeForwardSlashed_Elongated_Vertical::ImageEdgeForwardSlashed_Elongated_Vertical(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageEdgeForwardSlashed_Elongated_Vertical::pre()
{TRACE
  filename_ = kImageName;
  DBG("ImageName: %s\n", filename_.c_str());
}

void ImageEdgeForwardSlashed_Elongated_Vertical::post()
{TRACE
}

int ImageEdgeForwardSlashed_Elongated_Vertical::animated() const
{TRACE
  return 1; 
}

void ImageEdgeForwardSlashed_Elongated_Vertical::construct()
{TRACE
  IImage::construct();
}

ImageEdgeForwardSlashed_Elongated_Vertical::~ImageEdgeForwardSlashed_Elongated_Vertical()
{TRACE
}

