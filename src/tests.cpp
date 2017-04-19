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
#include "BOImageTable.hpp"
#include "trace.hpp"
#include "NodeColorDecorator.hpp"
#include "StateActive.hpp"
#include "NodeColor.hpp"
#include "EdgeStateThin.hpp"
#include "EdgeStateThick.hpp"
#include "EdgeColorDecorator.hpp"
#include "CEdgeContext.hpp"
#include "PatternLockViewController.hpp"
#include "BOPatternbLockConfig.hpp"

static const int kTimerDuration = 1;

static void __sleep(unsigned int seconds, Eina_Bool (*sleep_call_back)(void*), void* data );
static void testContextWithTable(Evas_Object* parent)
{
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
  DBG("\n--------------------------- MOUSE DOWN\n");
  context->show();
}
Evas_Object* testTable(Evas_Object* parent)
{
  int bgRowSpan = 14;
  int bgColSpan = 14;
  BOImageTable* table = BOImageTable::newL(parent, bgColSpan, bgRowSpan);
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
Evas_Object* testTizenActiveNodeView(Evas_Object* parent)
{
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
  DBG("\n--------------------------- MOUSE DOWN\n");
  void* data = static_cast<void*>(context);
  __sleep(kTimerDuration, &__wait_3_seconds, data);
  Evas_Object* handle = context->evasObject();
  return handle;
}
void testNodeRedDecorator()
{
  BOImageTable* tbl = BOImageTable::newL(0, 0, 0);
  IImage* images[1] = {0};
  StateActive* active = StateActive::newL(*tbl, *images);
  NodeColorDecorator* red = new NodeColorDecorator(*active, *tbl, *images);
  red->decorate(eRed);
}
static void __sleep(unsigned int seconds, Eina_Bool (*sleep_call_back)(void*), void* data )
{
#if defined __TIZEN__
  ecore_timer_add(seconds, sleep_call_back, (const void *)data);
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
    __sleep(kTimerDuration, &__pause_another_3_seconds, (void*)context);
  }
  return 0;
}
Evas_Object* testRedNodeViaContext(Evas_Object* parent)
{
  CNodeContext* context = CNodeContext::newL(parent);
  context->show();
  DBG("\n--------------------------- MOUSE DOWN\n");

  __sleep(kTimerDuration, &__pause_3_seconds, (void*)context);

  Evas_Object* handle = context->evasObject();
  return handle;
}
void testEdgeViewThin()
{
  BOImageTable* tbl = BOImageTable::newL(0, 0, 0);
  IImage* images[1] = {};
  EdgeStateThin* thin = EdgeStateThin::newL(*tbl, *images);
  BO_ASSERT(thin != NULL);
}
Evas_Object* testThinEdgeView(Evas_Object* parent)
{
  CEdgeContext* context = CEdgeContext::newL(parent);
  context->show();
  Evas_Object* handle = context->evasObject();
  return handle;
}
Evas_Object* testThickEdgeView(Evas_Object* parent)
{
  CEdgeContext* context = CEdgeContext::newL(parent);
  context->show();
  Evas_Object* handle = context->evasObject();
  
  context->show();
  handle = context->evasObject();
  return handle;
}
Evas_Object* testPatterLockVC(Evas_Object* parent)
{
  const BOPatternbLockConfig config;
  
  PatternLockViewController* pl = PatternLockViewController::newL(config, parent);
  Evas_Object* view = pl->evasObject();
  return view;
}
Evas_Object* testPatterLockVCShowAll_PassiveState(Evas_Object* parent)
{
  const BOPatternbLockConfig config;
  PatternLockViewController* pl = PatternLockViewController::newL(config, parent);
  pl->show();
  Evas_Object* view = pl->evasObject();
  return view;
}
Evas_Object* testPatterLockVCShowAll_ActiveState(Evas_Object* parent)
{
  const BOPatternbLockConfig config;
  PatternLockViewController* pl = PatternLockViewController::newL(config, parent);
  pl->show();
  pl->show();
  Evas_Object* view = pl->evasObject();
  return view;
}
static Eina_Bool __go_active(void* data)
{
  PatternLockViewController* pl = (PatternLockViewController*)data;
  pl->show();
  return false;
}
Evas_Object* testPatterLockVCShowAll_ActiveState_WithTimer(Evas_Object* parent)
{
  const BOPatternbLockConfig config;
  PatternLockViewController* pl = PatternLockViewController::newL(config, parent);
  pl->show();
  __sleep(3, &__go_active, (void*)pl);
  Evas_Object* view = pl->evasObject();
  return view;
}
static void __halt(Evas_Object* window, Evas_Object* target)
{
  int sleepSecs = 1000;
  usleep(sleepSecs);
#if defined __TIZEN__
  //  elm_win_resize_object_add(window, target);

    evas_object_move(target, 50, 200);
    evas_object_resize(target, 200, 200);

    evas_object_show(target);
    evas_object_show(window);
#endif
}
void runAllTizenTests(Evas_Object* window)
{
  Evas_Object* target = NULL;

  {
    target = testImage(window);
    __halt(window, target);
  }
  {
    target = testOuterImage(window);
    __halt(window, target);
  }
  {
    target = testMiddleImage(window);
    __halt(window, target);
  }
  {
    target = testInnerImage(window);
    __halt(window, target);
  }
  {
    target = testCoreImage(window);
    __halt(window, target);
  }
  {
    target = testTable(window);
    __halt(window, target);
  }
  {
    target = testActiveNodeView(window);
    __halt(window, target);
  }
  {
    target = testPassiveNodeView(window);
    __halt(window, target);
  }
  {
    target = testTizenActiveNodeView(window);
    __halt(window, target);
  }
  {
    target = testRedNodeViaContext(window);
    __halt(window, target);
  }
  {
    target = testThinEdgeView(window);
    BO_ASSERT(target != 0);
    __halt(window, target);
  }
  {
    target = testThickEdgeView(window);
    BO_ASSERT(target != 0);
    __halt(window, target);
  }
  {
    target = testPatterLockVCShowAll_PassiveState(window);
  }
#if defined __TIZEN__
    elm_win_resize_object_add(window, target);

    evas_object_move(target, 50, 200);
    evas_object_resize(target, 200, 200);

    evas_object_show(target);
    evas_object_show(window);
#endif
}
void runAllTests(Evas_Object* parent)
{
  testContextWithTable(parent);
  testTable(parent);
  testContextWithTable(parent);
}
