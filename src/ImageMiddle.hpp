//
//  ImageMiddle.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef ImageMiddle_hpp
#define ImageMiddle_hpp


#include "IImage.hpp"

class ImageMiddle : public IImage
{
 public:
  static ImageMiddle* newL(Evas_Object* parent);
  virtual ~ImageMiddle();
  virtual void pre();
  virtual void post();
  
 private:
  ImageMiddle(Evas_Object* parent);
  void construct();
};


#endif /* ImageMiddle_hpp */
