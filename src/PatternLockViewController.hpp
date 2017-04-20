//
//  PatternLockViewController.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/18/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef PatternLockViewController_hpp
#define PatternLockViewController_hpp

#include <vector>
#include "IPatternLockViewController.hpp"
#include "OS.h"

using namespace std;

class BOImageTable;
class BOPatternbLockConfig;
class CNodeContext;
class CEdgeContext;
class BOHotspot;

static void didReceiveMouseDownEvent(void* eventInfo, void* data);

class PatternLockViewController : public IPatternLockViewController
  {
 public:
  static PatternLockViewController* newL(const BOPatternbLockConfig& config, Evas_Object* parent);
  virtual ~PatternLockViewController();
  void show();
  void error();
  void ok();
  
  Evas_Object* evasObject() const;
  
  virtual void viewWillAppear(int animated);
  virtual void viewDidAppear(int animated);
  virtual void viewDidLoad();
  virtual void viewWillDisappear(int animated);
  virtual void viewDidDisappear(int animated);
  
 private:
  PatternLockViewController(const BOPatternbLockConfig& config, Evas_Object* parent);
  void construct();
  void createTable();
  void createNodeContexts();
  void addNodesInTable();
  
  void createEdgeContexts();
  void addEdgesInTable();
  
  void showNodes();
  void showEdges();

  void resize();
  void createHotspots();
  
 private:
  Evas_Object* parent_;
  Evas_Object* container_;
  BOImageTable* table_;
  vector<CNodeContext*> nodecontexts_;
  vector<CEdgeContext*> edgecontexts_;
  vector<BOHotspot*> hotspots_;
  const BOPatternbLockConfig& config_;
  
 friend
  void didReceiveMouseDownEvent(void* eventInfo, void* data);
  };

#endif /* PatternLockViewController_hpp */
