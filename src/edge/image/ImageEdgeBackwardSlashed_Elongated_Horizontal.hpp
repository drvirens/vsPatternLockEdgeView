//
//  ImageEdgeBackwardSlashed_Elongated_Horizontal.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/22/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef ImageEdgeBackwardSlashed_Elongated_Horizontal_hpp
#define ImageEdgeBackwardSlashed_Elongated_Horizontal_hpp


#include "IImage.hpp"

class ImageEdgeBackwardSlashed_Elongated_Horizontal : public IImage
{
 public:
  static ImageEdgeBackwardSlashed_Elongated_Horizontal* newL(Evas_Object* parent);
  virtual ~ImageEdgeBackwardSlashed_Elongated_Horizontal();
  virtual void pre();
  virtual void post();
  virtual int animated() const;
  
 private:
  ImageEdgeBackwardSlashed_Elongated_Horizontal(Evas_Object* parent);
  void construct();
};


#endif /* ImageEdgeBackwardSlashed_Elongated_Horizontal_hpp */
