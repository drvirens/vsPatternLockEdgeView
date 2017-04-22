//
//  ImageEdgeVertical.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef ImageEdgeVertical_hpp
#define ImageEdgeVertical_hpp

#include "IImage.hpp"

class ImageEdgeVertical : public IImage
{
 public:
  static ImageEdgeVertical* newL(Evas_Object* parent);
  virtual ~ImageEdgeVertical();
  virtual void pre();
  virtual void post();
  virtual int animated() const;
  
 private:
  ImageEdgeVertical(Evas_Object* parent);
  void construct();
};


#endif /* ImageEdgeVertical_hpp */
