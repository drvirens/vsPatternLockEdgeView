//
//  tests.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include <iostream>
#include "OS.h"
#include "tests.hpp"
#include "CNodeContext.hpp"
#include "ImageCore.hpp"
#include "Table.hpp"
#include "trace.hpp"



static void testContextWithTable(Evas_Object* parent)
{
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
  //after sometime simulate mouse-down
  DBG("\n--------------------------- MOUSE DOWN\n");
  context->show();
}


static void testTable() 
{
  Evas_Object* parent = NULL;
  int bgRowSpan = 4;
  int bgColSpan = 4;
  Table* table = Table::newL(parent, bgColSpan, bgRowSpan);
  Evas_Object* tbl = table->nativeTable();
  IImage* img = ImageCore::newL(tbl);
  table->add(*img, 6, 6, 2, 2);
}

static void testNodeView() 
{
}

static void testContextShows() 
{
  Evas_Object* parent = NULL;
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
  
  //after sometime simulate mouse-down
  DBG("\n--------------------------- MOUSE DOWN\n");
  context->show();
  DBG("\n--------------------------- Try again\n");
  context->show();
}

Evas_Object* testNodeView(Evas_Object* parent)
{
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
  //after sometime simulate mouse-down
  DBG("\n--------------------------- MOUSE DOWN\n");
  context->show();
  
  Evas_Object* handle = context->evasObject();
  return handle;
}
void runAllTests(Evas_Object* parent)
{
  //testContextShows();
  //testTable();
  testContextWithTable(parent);
}
