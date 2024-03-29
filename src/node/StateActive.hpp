//
//  StateActive.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef StateActive_hpp
#define StateActive_hpp

#include "INodeView.hpp"

class StateActive: public INodeView
{
 public:
  static StateActive* newL(BOImageTable& parent, IImage*& images);
  virtual ~StateActive();
  
  virtual void now(CNodeContext& context);
  virtual void decorate(EHotspotColor color);
  
 private:
  StateActive(BOImageTable& parent, IImage*& images);
  void construct();
};

#endif /* StateActive_hpp */
