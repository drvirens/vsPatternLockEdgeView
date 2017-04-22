//
//  ImageEdgeForwardSlashed_Elongated_Vertical.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/22/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef ImageEdgeForwardSlashed_Elongated_Vertical_hpp
#define ImageEdgeForwardSlashed_Elongated_Vertical_hpp

#include "IImage.hpp"

class ImageEdgeForwardSlashed_Elongated_Vertical : public IImage
{
 public:
  static ImageEdgeForwardSlashed_Elongated_Vertical* newL(Evas_Object* parent);
  virtual ~ImageEdgeForwardSlashed_Elongated_Vertical();
  virtual void pre();
  virtual void post();
  virtual int animated() const;
  
 private:
  ImageEdgeForwardSlashed_Elongated_Vertical(Evas_Object* parent);
  void construct();
};

#endif /* ImageEdgeForwardSlashed_Elongated_Vertical_hpp */
