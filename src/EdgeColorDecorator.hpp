//
//  EdgeColorDecorator.hpp
//  vsEdgeView
//
//  Created by Virendra Shakya on 4/14/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef EdgeRedDecorator_hpp
#define EdgeRedDecorator_hpp

#include "IEdgeDecorator.hpp"

class EdgeColorDecorator: public IEdgeDecorator
{
 public:
  virtual ~EdgeColorDecorator();
  
  virtual void now(CEdgeContext& context);
  virtual void decorate(EHotspotColor color);
  
 //protected:
  EdgeColorDecorator(IEdgeView& edgeView, Table& parent, IImage*& images);
  void construct();
};

#endif /* EdgeRedDecorator_hpp */
