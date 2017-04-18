//
//  EdgeStateThin.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/17/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef EdgeStateThin_hpp
#define EdgeStateThin_hpp

#include "IEdgeView.hpp"

class EdgeStateThin : public IEdgeView
{
 public:
  static EdgeStateThin* newL(Table& parent, IImage*& images);
  virtual ~EdgeStateThin();
  
  virtual void now(CEdgeContext& context);
  virtual void decorate(EHotspotColor color);
  
 private:
  EdgeStateThin(Table& parent, IImage*& images);
  void construct();
};


#endif /* EdgeStateThin_hpp */
