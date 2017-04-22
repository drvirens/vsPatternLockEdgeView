//
//  ImageEdgeBackwardSlashed_Elongated_Horizontal.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/22/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageEdgeBackwardSlashed_Elongated_Horizontal.hpp"
#include "trace.hpp"

static const string kImageName = "images/backwardslashed_Elongated_Horizontal.png";

ImageEdgeBackwardSlashed_Elongated_Horizontal* ImageEdgeBackwardSlashed_Elongated_Horizontal::newL(Evas_Object* parent)
{TRACE
  ImageEdgeBackwardSlashed_Elongated_Horizontal* obj = new ImageEdgeBackwardSlashed_Elongated_Horizontal(parent);
  if (obj)
  {
    obj->construct();
  }
  return obj;
}

ImageEdgeBackwardSlashed_Elongated_Horizontal::ImageEdgeBackwardSlashed_Elongated_Horizontal(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageEdgeBackwardSlashed_Elongated_Horizontal::pre()
{TRACE
  filename_ = kImageName;
  DBG("ImageName: %s\n", filename_.c_str());
}

void ImageEdgeBackwardSlashed_Elongated_Horizontal::post()
{TRACE
}

int ImageEdgeBackwardSlashed_Elongated_Horizontal::animated() const
{TRACE
  return 1; 
}

void ImageEdgeBackwardSlashed_Elongated_Horizontal::construct()
{TRACE
  IImage::construct();
}

ImageEdgeBackwardSlashed_Elongated_Horizontal::~ImageEdgeBackwardSlashed_Elongated_Horizontal()
{TRACE
}
