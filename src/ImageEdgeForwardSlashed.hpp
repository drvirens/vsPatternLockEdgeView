//
//  ImageEdgeForwardSlashed.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef ImageEdgeForwardSlashed_hpp
#define ImageEdgeForwardSlashed_hpp

#include "IImage.hpp"

class ImageEdgeForwardSlashed : public IImage
{
 public:
  static ImageEdgeForwardSlashed* newL(Evas_Object* parent);
  virtual ~ImageEdgeForwardSlashed();
  virtual void pre();
  virtual void post();
  virtual int animated() const;
  
 private:
  ImageEdgeForwardSlashed(Evas_Object* parent);
  void construct();
};


#endif /* ImageEdgeForwardSlashed_hpp */
