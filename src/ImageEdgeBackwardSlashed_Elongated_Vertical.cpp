//
//  ImageEdgeBackwardSlashed_Elongated_Vertical.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/22/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "ImageEdgeBackwardSlashed_Elongated_Vertical.hpp"
#include "trace.hpp"

static const string kImageName = "images/backwardslashed_Elongated_Vertical.png";

ImageEdgeBackwardSlashed_Elongated_Vertical* ImageEdgeBackwardSlashed_Elongated_Vertical::newL(Evas_Object* parent)
{TRACE
  ImageEdgeBackwardSlashed_Elongated_Vertical* obj = new ImageEdgeBackwardSlashed_Elongated_Vertical(parent);
  if (obj)
  {
    obj->construct();
  }
  return obj;
}

ImageEdgeBackwardSlashed_Elongated_Vertical::ImageEdgeBackwardSlashed_Elongated_Vertical(Evas_Object* parent)
: IImage(parent)
{TRACE
}

void ImageEdgeBackwardSlashed_Elongated_Vertical::pre()
{TRACE
  filename_ = kImageName;
  DBG("ImageName: %s\n", filename_.c_str());
}

void ImageEdgeBackwardSlashed_Elongated_Vertical::post()
{TRACE
}

int ImageEdgeBackwardSlashed_Elongated_Vertical::animated() const
{TRACE
  return 1; 
}

void ImageEdgeBackwardSlashed_Elongated_Vertical::construct()
{TRACE
  IImage::construct();
}

ImageEdgeBackwardSlashed_Elongated_Vertical::~ImageEdgeBackwardSlashed_Elongated_Vertical()
{TRACE
}
