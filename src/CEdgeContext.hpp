//
//  CEdgeContext.hpp
//  vsEdgeView
//
//  Created by Virendra Shakya on 4/16/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef CEdgeContext_hpp
#define CEdgeContext_hpp

#include "OS.h"
#include "IImage.hpp"

class EdgeStateThin;
class EdgeStateThick;
class EdgeColorDecorator;
class IEdgeView;
class Table;

class IEdgeContext
{
 public:
  static IEdgeContext* newL(Evas_Object* parent);
  ~IEdgeContext();
  
  void show();
  void ok();
  void error();
  
  Evas_Object* evasObject() const;

 private:
  IEdgeContext(Evas_Object* parent);
  void construct();
  void createTable();
  void createImages();
  void addImagesInTable();

  void setPassive();
  void setActive();

 private:
  Evas_Object* parent_;
  IImage* images_[EImageMaxSize];
  IEdgeView* state_; //current state
  EdgeStateThin* passive_;
  EdgeStateThick* active_;
  EdgeColorDecorator* colordecorator_;
  Table* table_;
  
 friend 
  class StatePassive;
 friend 
  class StateActive;
};

#endif /* CEdgeContext_hpp */
