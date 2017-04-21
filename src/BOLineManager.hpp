//
//  BOLineManager.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/20/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef BOLineManager_hpp
#define BOLineManager_hpp

#include <vector>
#include "OS.h"

using namespace std;

class BOLineManager
{
 public:
  static BOLineManager* newL(Evas_Object* parent);
  virtual ~BOLineManager();
  bool createLine(int startx, int starty, int startx1, int starty1);
  void drawLine(int x1, int y1, int x2, int y2);
  void startNewLine();
  
 private:
  void construct();
  BOLineManager(Evas_Object* parent);
  void _create_line(int startx, int starty, int startx1, int starty1);
  
 private:
  Evas* evas;
  Evas_Object* line_new_; //viren - represent one line
  //Eina_List* objects; //lines array
  vector<Evas_Object*> objects;
  vector<Evas_Object*> lines_;
  int win_layer;
  void* current_object;
  Evas_Object* parent_;
};

#endif /* BOLineManager_hpp */
