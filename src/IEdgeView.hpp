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
class Table;

class IEdgeView 
{
 public:
  virtual void now(CEdgeContext& context) = 0;
  virtual void decorate(EHotspotColor color) = 0;
  virtual ~IEdgeView();
  
 protected:
  IEdgeView(Table* parent, IImage*& images);
  IImage& core();
//  IImage& inner();
//  IImage& middle();
//  IImage& outer();
  
  void construct();
  
 protected:
  Table* parent_;
  IImage** images_; //using
};


#endif /* IEdgeView_hpp */
