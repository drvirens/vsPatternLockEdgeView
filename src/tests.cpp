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
#include "NodeRedDecorator.hpp"
#include "StateActive.hpp"



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

Evas_Object* testActiveNodeView(Evas_Object* parent)
{
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
  DBG("\n--------------------------- MOUSE DOWN\n");
  context->show();
  Evas_Object* handle = context->evasObject();
  return handle;
}
Evas_Object* testPassiveNodeView(Evas_Object* parent)
{
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
  Evas_Object* handle = context->evasObject();
  return handle;
}

#if defined __TIZEN__
static Eina_Bool __wait_3_seconds(void* data)
{
  CNodeContext* context = static_cast<CNodeContext*>(data);
  if (context)
  {
    context->show();
  }
  return ECORE_CALLBACK_CANCEL;
}
Evas_Object* testTizenActiveNodeView(Evas_Object* parent)
{
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
  DBG("\n--------------------------- MOUSE DOWN\n");

  Ecore_Timer* timer = ecore_timer_add(3, &__wait_3_seconds, context);

  Evas_Object* handle = context->evasObject();
  return handle;
}
#endif

void testNodeRedDecorator()
{
  Table* tbl = Table::newL(0, 0, 0);
  IImage* images[1] = {0};
  StateActive* active = StateActive::newL(*tbl, *images);
  NodeRedDecorator* red = new NodeRedDecorator(*active, *tbl, *images);
  red->decorate(eRed);
}

void runAllTests(Evas_Object* parent)
{
  //testContextShows();
  //testTable();
  testContextWithTable(parent);
}
