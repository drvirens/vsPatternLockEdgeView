//
//  IEdgeView.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/16/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef IEdgeView_hpp
#define IEdgeView_hpp

#include "NodeColor.hpp"

class CEdgeContext;
class IImage;
class BOImageTable;

class IEdgeView 
{
 public:
  virtual void now(CEdgeContext& context) = 0;
  virtual void decorate(EHotspotColor color) = 0;
  virtual ~IEdgeView();
  
 protected:
  IEdgeView(BOImageTable* parent, IImage& image);
  IImage& edge();
  
  void construct();
  
 protected:
  BOImageTable* parent_;
  IImage* image_; //using
};


#endif /* IEdgeView_hpp */
