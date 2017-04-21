//
//  BOBackgroundSpec.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/21/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef BOColor_hpp
#define BOColor_hpp

#include <string>
using namespace std;

class BOBackgroundSpec
{
 public:
  BOBackgroundSpec(int r, int g, int b, int a, string& bgimgname) 
   : r_(r)
   , g_(g)
   , b_(b)
   , a_(a)
   , bgimgname_(bgimgname)
  {}
  
 public:
  int r_;
  int g_;
  int b_;
  int a_;
  
  string bgimgname_;
};

#endif /* BOColor_hpp */
