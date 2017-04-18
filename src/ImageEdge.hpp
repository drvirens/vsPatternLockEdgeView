//
//  ImageEdge.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef ImageEdge_hpp
#define ImageEdge_hpp

#include "IImage.hpp"

class ImageEdge : public IImage
{
 public:
  static ImageEdge* newL(Evas_Object* parent);
  virtual ~ImageEdge();
  virtual void pre();
  virtual void post();
  virtual int animated() const;
  
 private:
  ImageEdge(Evas_Object* parent);
  void construct();
};


#endif /* ImageEdge_hpp */
