//
//  EdgeStateThick.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/17/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef EdgeThickState_hpp
#define EdgeThickState_hpp

#include "IEdgeView.hpp"

class EdgeStateThick : public IEdgeView
{
 public:
  static EdgeStateThick* newL(Table& table, IImage*& images);
  virtual ~EdgeStateThick();
  
  virtual void now(CEdgeContext& context);
  virtual void decorate(EHotspotColor color);
  
 private:
  EdgeStateThick(Table& table, IImage*& images);
  void construct();  
};


#endif /* EdgeThickState_hpp */
