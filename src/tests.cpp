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
#include "ImageInner.hpp"
#include "ImageMiddle.hpp"
#include "ImageOuter.hpp"
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


Evas_Object* testTable(Evas_Object* parent)
{
  int bgRowSpan = 14;
  int bgColSpan = 14;
  Table* table = Table::newL(parent, bgColSpan, bgRowSpan);
  Evas_Object* tbl = table->nativeTable();
  IImage* img = ImageCore::newL(tbl);

  table->add(*img, 10, 10, 5, 5);

  return tbl;
}

Evas_Object* testImage(Evas_Object* parent)
{
  IImage* img = ImageCore::newL(parent);
  Evas_Object* nativeimage = img->nativeImage();
  return nativeimage;
}
Evas_Object* testCoreImage(Evas_Object* parent)
{
  IImage* img = ImageCore::newL(parent);
  Evas_Object* nativeimage = img->nativeImage();
  return nativeimage;
}
Evas_Object* testInnerImage(Evas_Object* parent)
{
  IImage* img = ImageInner::newL(parent);
  Evas_Object* nativeimage = img->nativeImage();
  return nativeimage;
}
Evas_Object* testMiddleImage(Evas_Object* parent)
{
  IImage* img = ImageMiddle::newL(parent);
  Evas_Object* nativeimage = img->nativeImage();
  return nativeimage;
}
Evas_Object* testOuterImage(Evas_Object* parent)
{
  IImage* img = ImageOuter::newL(parent);
  Evas_Object* nativeimage = img->nativeImage();
  return nativeimage;
}

//
//static void testContextShows()
//{
//  Evas_Object* parent = NULL;
//  CNodeContext* context = CNodeContext::newL(parent);
//  context->show();
//
//  //after sometime simulate mouse-down
//  DBG("\n--------------------------- MOUSE DOWN\n");
//  context->show();
//  DBG("\n--------------------------- Try again\n");
//  context->show();
//}

Evas_Object* testNodeView(Evas_Object* parent)
{
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
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
