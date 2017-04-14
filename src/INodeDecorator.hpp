//
//  INodeDecorator.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/14/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef INodeDecorator_hpp
#define INodeDecorator_hpp

#include "INodeView.hpp"

class INodeDecorator : public INodeView
{
 public:
  virtual ~INodeDecorator();
  
  virtual void now(CNodeContext& context);
  virtual void decorate(EHotspotColor color);
  
 protected:
  INodeDecorator(INodeView& nodeView, Table& parent, IImage*& images);
  
 private:
  INodeView& nodeview_;
};

#endif /* INodeDecorator_hpp */
