//
//  ImageCore.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef ImageCore_hpp
#define ImageCore_hpp

#include "IImage.hpp"

class ImageCore : public IImage
{
 public:
  static ImageCore* newL(Evas_Object* parent);
  virtual ~ImageCore();
  virtual void pre();
  virtual void post();
  virtual int animated() const;
  
 private:
  ImageCore(Evas_Object* parent);
  void construct();
};

#endif /* ImageCore_hpp */
