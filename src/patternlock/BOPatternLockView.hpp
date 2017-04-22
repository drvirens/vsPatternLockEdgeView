//
//  BOPatternLockView.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/19/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef BOPatternLockView_hpp
#define BOPatternLockView_hpp

#include <vector>
#include "OS.h"
#include "BOBackgroundSpec.hpp"

using namespace std;

class CNodeContext;
class CEdgeContext;
class BOImageTable;

class BOPatternLockView
{
 public:
  static BOPatternLockView* newL(Evas_Object* parent);
  virtual ~BOPatternLockView();
  Evas_Object* evasObject() const;
  BOImageTable& table() const;
  void showNodes();
  void showEdges();
  void error();
  void ok();
  vector<CNodeContext*>& createHotspots();
  CEdgeContext* getEdgeBetweenNodes(int prevNodeIndex, int currNodeIndex);

 private:
  BOPatternLockView(Evas_Object* parent);
  void construct();
  
  void createTable();
  void createNodeContexts();
  void addNodesInTable();
  void createEdgeContexts();
  
 private:
  Evas_Object* parent_;
  Evas_Object* container_;
  BOImageTable* table_;
  vector<CNodeContext*> nodecontexts_;
  vector<CEdgeContext*> edgecontexts_;
  BOBackgroundSpec tblBackgroudSpecs_;
};

#endif /* BOPatternLockView_hpp */
