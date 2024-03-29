//
//  IImage.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "IImage.hpp"
#include "trace.hpp"

static Evas_Object* __create_image(Evas_Object* parent);
static void __set_up_image(Evas_Object* image, const char* image_file_name);
static void __image_display_enable(Evas_Object* image, int enable, int animated);
static void __decorate_image(Evas_Object* image, EHotspotColor color, int animated);

IImage::~IImage()
{TRACE
}

void IImage::show()
{TRACE
  DBG("Image ..... ✅ \n");
  Evas_Object* nativeimage = nativeImage();
  static const int show = 1;
  int animate = animated();
  __image_display_enable(nativeimage, show, animate);
}

void IImage::hide()
{TRACE
  DBG("Image ..... ❌ \n");
  Evas_Object* nativeimage = nativeImage();
  static const int show = 0;
  int animated = 1;
  __image_display_enable(nativeimage, show, animated);
}

void IImage::decorate(EHotspotColor color)
{TRACE
  switch (color) {
    case eRed:
      {
      DBG("Decorate [%s].... 🔴\n", filename_.c_str());
      } break;
    case eGreen:
      {
      DBG("Decorate [%s] .... 💚\n", filename_.c_str());
      } break;
    case eGray:
      {
      DBG("Decorate [%s] .... ⚫\n", filename_.c_str());
      } break;
  } //end switch

  Evas_Object* nativeimage = nativeImage();
  int animate = animated();
  __decorate_image(nativeimage, color, animate);
}

IImage::IImage(Evas_Object* parent)
: parent_(parent)
, image_(0)
{TRACE
}
  
void IImage::construct()
{TRACE
  pre();
  image_ = __create_image(parent_);
  __set_up_image(image_, filename_.c_str());
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

static Evas_Object* __create_image(Evas_Object* parent)
{TRACE
  Evas_Object* image = 0;
#if defined __TIZEN__
  image = __tizen_create_image(parent);
  BO_ASSERT(image != 0);
#endif
  return image;
}

static void __set_up_image(Evas_Object* image, const char* image_file_name)
{TRACE
#if defined __TIZEN__
  __tizen_set_up_image(image, image_file_name);
#endif
}

static void __image_display_enable(Evas_Object* image, int enable, int animated)
{TRACE
#if defined __TIZEN__
  __tizen_image_display_enable(image, enable, animated);
#endif
}

static void __decorate_image(Evas_Object* image, EHotspotColor color, int animated) 
{TRACE
#if defined __TIZEN__
  __tizen_decorate_image(image, color, animated);
#endif

}

  
