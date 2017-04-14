//
//  ImageOuter.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef ImageOuter_hpp
#define ImageOuter_hpp


#include "IImage.hpp"

class ImageOuter : public IImage
{
 public:
  static ImageOuter* newL(Evas_Object* parent);
  virtual ~ImageOuter();
  virtual void pre();
  virtual void post();
  
 private:
  ImageOuter(Evas_Object* parent);
  void construct();
};



#endif /* ImageOuter_hpp */
