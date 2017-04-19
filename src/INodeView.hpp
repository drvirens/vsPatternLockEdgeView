//
//  INodeView.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef IHotspot_hpp
#define IHotspot_hpp

#include "NodeColor.hpp"

class CNodeContext;
class IImage;
class BOImageTable;

class INodeView 
{
 public:
  virtual void now(CNodeContext& context) = 0;
  virtual void decorate(EHotspotColor color) = 0;
  virtual ~INodeView();
  
 protected:
  INodeView(BOImageTable* parent, IImage*& images);
  IImage& core();
  IImage& inner();
  IImage& middle();
  IImage& outer();
  
  void construct();
  
 protected:
  BOImageTable* parent_;
  IImage** images_; //using
};

#endif /* IHotspot_hpp */
