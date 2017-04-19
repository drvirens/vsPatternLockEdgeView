//
//  PatternLockViewController.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/18/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "PatternLockViewController.hpp"
#include "BOImageTable.hpp"
#include "BOImageTablePosition.hpp"
#include "BOPatternbLockConfig.hpp"
#include "CNodeContext.hpp"
#include "CEdgeContext.hpp"
#include "trace.hpp"

static const int kTotalCells = 9;
static const BOImageTablePosition kBOImageTablePositions[kTotalCells] =
     {
        {6, 6, 2, 2}, //core
        {5, 5, 4, 4}, //inner
        {2, 2, 10, 10}, //middle
        {1, 1, 12, 12}, //outer
        {0, 0, 14, 14}, //bg
     };


PatternLockViewController::PatternLockViewController(const BOPatternbLockConfig& config, Evas_Object* parent)
: parent_(parent)
, container_(0)
, table_(0)
, config_(config)
{TRACE
}
void PatternLockViewController::createTable()
{TRACE
  BOImageTablePosition bgBOImageTablePosition = kBOImageTablePositions[kTotalCells-1];
  table_ = BOImageTable::newL(parent_, bgBOImageTablePosition.colSpan, bgBOImageTablePosition.rowSpan);
  container_ = table_->nativeTable();
}
void PatternLockViewController::construct()
{TRACE
  createTable();
  createNodeContexts();
  addImagesInTable();
}
PatternLockViewController* PatternLockViewController::newL(const BOPatternbLockConfig& config, Evas_Object* parent)
{TRACE
  PatternLockViewController* obj = new PatternLockViewController(config, parent);
  if (obj)
    {
    obj->construct();
    }
  return obj;
}
PatternLockViewController::~PatternLockViewController()
{TRACE
  parent_ = NULL;
}

void PatternLockViewController::createNodeContexts()
{TRACE
  nodecontexts_.reserve(kTotalCells);
  for (int i = 0; i < kTotalCells; i++)
  {
    CNodeContext* context = CNodeContext::newL(container_);
    nodecontexts_.push_back(context);
  } //end for
}

void PatternLockViewController::addImagesInTable()
{TRACE
  int i = 0;
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      Evas_Object* evasObj = c->evasObject();
      table_->addEvasObject(evasObj, kBOImageTablePositions[i].col, kBOImageTablePositions[i].row, kBOImageTablePositions[i].colSpan, kBOImageTablePositions[i].rowSpan);
      i++;
      }
  } //end for
}

Evas_Object* PatternLockViewController::evasObject() const
{TRACE
  return container_;
}

void PatternLockViewController::show()
{TRACE
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      c->show();
      }
  } //end for
}

void PatternLockViewController::viewWillAppear(int animated)
{TRACE
}

void PatternLockViewController::viewDidAppear(int animated)
{TRACE
}

void PatternLockViewController::viewDidLoad()
{TRACE
}

void PatternLockViewController::viewWillDisappear(int animated)
{TRACE
}

void PatternLockViewController::viewDidDisappear(int animated)
{TRACE
}




