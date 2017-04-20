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
class BOHotspot;
class BOPatternLockView;
class BOLineManager;

static void didReceiveMouseDownEvent(void* eventInfo, void* data);
static void didReceiveMouseUpEvent(void* eventInfo, void* data);
static void didReceiveMouseMoveEvent(void* event_info, void* data);

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
  
  void attachEventHandlersToTable();
  void createHotspots();
  
  void handleMouseDown(Evas_Event_Mouse_Down* mouse);
  void handleMouseUp(Evas_Event_Mouse_Up* mouse);
  void handleMouseMove(Evas_Event_Mouse_Move* mouse);
  void _start_new_line_draw();
  void _reset_coords(Evas_Event_Mouse_Down* mouse);
  void _reset_coords_in_move(Evas_Event_Mouse_Move* mouse);
  void _reset_coords_zeroout();
  int _get_draw_area_top();
  BOImageTable& table() const;
  void tableGeometry(int& x, int& y, int& w, int& h);
  void _update_line_item();
  void _create_line();
  
 private:
  Evas_Object* parent_;
  BOPatternLockView* patternlockview_;
  BOLineManager* linemgr_;
  
  bool hashotspots_;
  bool mouse_pressed;
  Evas_Coord_Point start;
  Evas_Coord_Point prev;
  Evas_Coord_Point curr;
  //void* current_object; //dummy - like wtf is it for?
  
  const BOPatternbLockConfig& config_;
  
 friend
  void didReceiveMouseDownEvent(void* eventInfo, void* data);
 friend
  void didReceiveMouseUpEvent(void* eventInfo, void* data);
 friend
  void didReceiveMouseMoveEvent(void* event_info, void* data);
};

#endif /* PatternLockViewController_hpp */
