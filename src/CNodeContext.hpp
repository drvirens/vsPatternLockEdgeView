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
#include "BOHotspot.hpp"

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
  
  void resize();
  void show();
  void ok();
  void error();
  
  Evas_Object* evasObject() const;
  void setRow(int row);
  void setColumn(int column);
  int row() const;
  int column() const;
  void populateHotspotInfo();


 private:
  CNodeContext(Evas_Object* parent);
  void construct();
  void createTable();
  void createImages();
  void addImagesInTable();

  void setPassive();
  void setActive();
  
  void geometry(int& x, int& y, int& w, int& h);

 private:
  Evas_Object* parent_;
  IImage* images_[EImageMaxSize];
  INodeView* state_; //current state
  StatePassive* passive_;
  StateActive* active_;
  NodeColorDecorator* colordecorator_;
  BOImageTable* table_;
  
 private: //house keeping for hotspot info
  BOHotspot hotspot_;
  
 friend 
  class StatePassive;
 friend 
  class StateActive;
};

#endif /* CNodeContext_hpp */
