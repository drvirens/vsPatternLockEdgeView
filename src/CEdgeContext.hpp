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
#include "BOEdgeType.hpp"

class EdgeStateThin;
class EdgeStateThick;
class EdgeColorDecorator;
class IEdgeView;
class BOImageTable;

class CEdgeContext
{
 public:
  static CEdgeContext* newL(Evas_Object* parent, const BOEdgeType& type);
  ~CEdgeContext();
  
  void show();
  void ok();
  void error();
  
  Evas_Object* evasObject() const;
  
  void setName(int name);
  int name() const;

 private:
  CEdgeContext(Evas_Object* parent, const BOEdgeType& type);
  void construct();
  void createTable();
  void createImages();
  void addImagesInTable();

  void setThin();
  void setThick();

 private:
  Evas_Object* parent_;
  //IImage* images_[EImageMaxSize];
  IImage* image_;
  IEdgeView* state_; //current state
  EdgeStateThin* thin_;
  EdgeStateThick* thick_;
  EdgeColorDecorator* colordecorator_;
  BOImageTable* table_;
  const BOEdgeType edgetype_;
  int name_; //2 digits number each digit specifies a node that connects with
  
 friend 
  class EdgeStateThin;
 friend 
  class EdgeStateThick;
};

#endif /* CEdgeContext_hpp */
