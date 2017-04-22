//
//  ImageEdgeHorizontal.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef ImageEdgeHorizontal_hpp
#define ImageEdgeHorizontal_hpp

#include "IImage.hpp"

class ImageEdgeHorizontal : public IImage
{
 public:
  static ImageEdgeHorizontal* newL(Evas_Object* parent);
  virtual ~ImageEdgeHorizontal();
  virtual void pre();
  virtual void post();
  virtual int animated() const;
  
 private:
  ImageEdgeHorizontal(Evas_Object* parent);
  void construct();
};


#endif /* ImageEdgeHorizontal_hpp */
