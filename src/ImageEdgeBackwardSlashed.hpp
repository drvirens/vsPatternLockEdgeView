//
//  ImageEdgeBackwardSlashed.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef ImageEdgeBackwardSlashed_hpp
#define ImageEdgeBackwardSlashed_hpp

#include "IImage.hpp"

class ImageEdgeBackwardSlashed : public IImage
{
 public:
  static ImageEdgeBackwardSlashed* newL(Evas_Object* parent);
  virtual ~ImageEdgeBackwardSlashed();
  virtual void pre();
  virtual void post();
  virtual int animated() const;
  
 private:
  ImageEdgeBackwardSlashed(Evas_Object* parent);
  void construct();
};


#endif /* ImageEdgeBackwardSlashed_hpp */
