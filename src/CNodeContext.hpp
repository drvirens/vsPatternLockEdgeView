//
//  CNodeContext.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef CNodeContext_hpp
#define CNodeContext_hpp

#include "OS.h"
#include "IImage.hpp"

class StatePassive;
class StateActive;
class NodeColorDecorator;
class INodeView;
class BOImageTable;

class CNodeContext
{
 public:
  static CNodeContext* newL(Evas_Object* parent);
  ~CNodeContext();
  
  void show();
  void ok();
  void error();
  
  Evas_Object* evasObject() const;

 private:
  CNodeContext(Evas_Object* parent);
  void construct();
  void createTable();
  void createImages();
  void addImagesInTable();

  void setPassive();
  void setActive();

 private:
  Evas_Object* parent_;
  IImage* images_[EImageMaxSize];
  INodeView* state_; //current state
  StatePassive* passive_;
  StateActive* active_;
  NodeColorDecorator* colordecorator_;
  BOImageTable* table_;
  
 friend 
  class StatePassive;
 friend 
  class StateActive;
};

#endif /* CNodeContext_hpp */
