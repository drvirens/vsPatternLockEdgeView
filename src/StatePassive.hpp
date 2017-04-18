//
//  StatePassive.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef StatePassive_hpp
#define StatePassive_hpp

#include "INodeView.hpp"

class StatePassive: public INodeView
{
 public:
  static StatePassive* newL(Table&, IImage*& images);
  virtual ~StatePassive();
  
  virtual void now(CNodeContext& context);
  virtual void decorate(EHotspotColor color);
  
 private:
  StatePassive(Table&, IImage*& images);
  void construct();  
};

#endif /* StatePassive_hpp */
