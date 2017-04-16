//
//  tests.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include <iostream>
#include <unistd.h>


#if !defined __TIZEN__
typedef int Eina_Bool;
#endif

#if defined __TIZEN__

#ifdef __cplusplus
extern "C" {
#endif

#include <ecore.h>

#ifdef __cplusplus
}
#endif

#endif

#include "OS.h"
#include "tests.hpp"
#include "CNodeContext.hpp"
#include "ImageCore.hpp"
#include "ImageInner.hpp"
#include "ImageMiddle.hpp"
#include "ImageOuter.hpp"
#include "Table.hpp"
#include "trace.hpp"
#include "NodeColorDecorator.hpp"
#include "StateActive.hpp"
#include "NodeColor.hpp"

static void __sleep(unsigned int seconds, int (*sleep_call_back)(void*), void* data );

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


static Eina_Bool __wait_3_seconds(void* data)
{
  CNodeContext* context = static_cast<CNodeContext*>(data);
  if (context)
  {
    context->show();
  }
  return 0;
}
#if defined __TIZEN__
Evas_Object* testTizenActiveNodeView(Evas_Object* parent)
{
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
  DBG("\n--------------------------- MOUSE DOWN\n");
  double in = 3;
  Ecore_Task_Cb func = &__wait_3_seconds;
  const void *data = context;

  ecore_timer_add( in,  func, data);
//  ecore_timer_add(3., &__wait_3_seconds, (const void *)context);

  Evas_Object* handle = context->evasObject();
  return handle;
}
#endif

void testNodeRedDecorator()
{
  Table* tbl = Table::newL(0, 0, 0);
  IImage* images[1] = {0};
  StateActive* active = StateActive::newL(*tbl, *images);
  NodeColorDecorator* red = new NodeColorDecorator(*active, *tbl, *images);
  red->decorate(eRed);
}

static void __sleep(unsigned int seconds, Eina_Bool (*sleep_call_back)(void*), void* data )
{
#if defined __TIZEN__
  ecore_timer_add(3, sleep_call_back, (const void *)data);
#else
  sleep(seconds);
  (*sleep_call_back)(data);
#endif
}

static Eina_Bool __pause_another_3_seconds(void* data)
{
  CNodeContext* context = static_cast<CNodeContext*>(data);
  if (context)
  {
    context->error();
  }
  return 0;
}


static Eina_Bool __pause_3_seconds(void* data)
{
  CNodeContext* context = static_cast<CNodeContext*>(data);
  if (context)
  {
    context->show();
    __sleep(3, &__pause_another_3_seconds, (void*)context);
  }
  return 0;
}
Evas_Object* testRedNodeViaContext(Evas_Object* parent)
{
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
  DBG("\n--------------------------- MOUSE DOWN\n");

  __sleep(3, &__pause_3_seconds, (void*)context);

  Evas_Object* handle = context->evasObject();
  return handle;
}

void runAllTests(Evas_Object* parent)
{
  //testContextShows();
  //testTable();
  testContextWithTable(parent);
}
