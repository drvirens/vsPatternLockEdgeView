//
//  IEdgeDecorator.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/14/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef IEdgeDecorator_hpp
#define IEdgeDecorator_hpp

#include "IEdgeView.hpp"

class IEdgeDecorator : public IEdgeView
{
 public:
  virtual ~IEdgeDecorator();
  
  virtual void now(CEdgeContext& context);
  virtual void decorate(EHotspotColor color);
  
 protected:
  IEdgeDecorator(IEdgeView& edgeView, Table& parent, IImage*& images);
  
 private:
  IEdgeView& edgeview_;
};

#endif /* IEdgeDecorator_hpp */
