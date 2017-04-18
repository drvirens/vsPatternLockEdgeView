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

class CEdgeContext
{
 public:
  static CEdgeContext* newL(Evas_Object* parent);
  ~CEdgeContext();
  
  void show();
  void ok();
  void error();
  
  Evas_Object* evasObject() const;

 private:
  CEdgeContext(Evas_Object* parent);
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
  class EdgeStateThin;
 friend 
  class EdgeStateThick;
};

#endif /* CEdgeContext_hpp */
