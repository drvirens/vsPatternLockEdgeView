//
//  IImage.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "IImage.hpp"
#include "trace.hpp"

static Evas_Object* _create_image(Evas_Object* parent);
static void _set_up_image(Evas_Object* image, const char* image_file_name);

IImage::~IImage()
{TRACE
}

void IImage::show()
{TRACE
  DBG("Image ..... ✅ \n");
}

void IImage::hide()
{TRACE
  DBG("Image ..... ❌ \n");
}

IImage::IImage(Evas_Object* parent)
: parent_(parent)
, image_(0)
{TRACE
}
  
void IImage::construct()
{TRACE
  pre();
  image_ = _create_image(parent_);
  _set_up_image(image_, file_name_.c_str());
  post();
}

Evas_Object* IImage::nativeImage() const
{TRACE
  return image_;
}

// ----------------------------------- OS specific 

#if defined __TIZEN__
#include "bo_clean_tizen_image.hpp"
#endif

static Evas_Object* _create_image(Evas_Object* parent)
{TRACE
  Evas_Object* image = 0;
#if defined __TIZEN__
  image = __tizen_create_image(parent);
  BO_ASSERT(image != 0);
#endif
  return image;
}

static void _set_up_image(Evas_Object* image, const char* image_file_name)
{TRACE
#if defined __TIZEN__
  __tizen_set_up_image(image, image_file_name);
#endif
}
  
