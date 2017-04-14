//
//  IImage.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef IImage_hpp
#define IImage_hpp

#include <string>
#include "OS.h"
#include "NodeColor.hpp"

using namespace std;

enum EImageType
{
  EImageCore,
  EImageInner,
  EImageMiddle,
  EImageOuter,
  EImageMaxSize
};

class IImage
{
 public:
  void show();
  void hide();
  void decorate(EHotspotColor color);
  virtual void pre() = 0;
  virtual void post() = 0;
  virtual int animated() const = 0;
  virtual ~IImage();
  
  Evas_Object* nativeImage() const;
  
 protected:
  IImage(Evas_Object* parent);
  void construct();
  
 protected:
  Evas_Object* parent_;
  Evas_Object* image_;
  string filename_;
};

#endif /* IImage_hpp */
