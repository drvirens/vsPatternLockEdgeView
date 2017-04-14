//
//  NodeRedDecorator.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/14/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef NodeRedDecorator_hpp
#define NodeRedDecorator_hpp

#include "INodeDecorator.hpp"

class NodeRedDecorator: public INodeDecorator
{
 public:
  virtual ~NodeRedDecorator();
  
  virtual void now(CNodeContext& context);
  virtual void decorate(EHotspotColor color);
  
 //protected:
  NodeRedDecorator(INodeView& nodeView, Table& parent, IImage*& images);
  void construct();
};

#endif /* NodeRedDecorator_hpp */
