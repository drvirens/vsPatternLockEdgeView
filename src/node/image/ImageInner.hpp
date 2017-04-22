//
//  ImageInner.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef ImageInner_hpp
#define ImageInner_hpp

#include "IImage.hpp"

class ImageInner : public IImage
{
 public:
  static ImageInner* newL(Evas_Object* parent);
  virtual ~ImageInner();
  virtual void pre();
  virtual void post();
  virtual int animated() const;
  
 private:
  ImageInner(Evas_Object* parent);
  void construct();
};


#endif /* ImageInner_hpp */
