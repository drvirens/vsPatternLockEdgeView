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


static const int kBackgroundCell = 1; 
static const int kTotalNodeCells = 9; 
static const int kTotalTableCells = kTotalNodeCells + kBackgroundCell;

static const int kBackgroundCellIndex = kTotalTableCells - 1;

static const BOImageTablePosition kNodesTablePositions[kTotalTableCells] =
     {
        //row 1
        {3, 3, 1, 1}, 
        {6, 3, 1, 1},
        {9, 3, 1, 1},
        //row 2
        {3, 6, 1, 1},
        {6, 6, 1, 1},
        {9, 6, 1, 1},
        //row 3
        {3, 9, 1, 1},
        {6, 9, 1, 1},
        {9, 9, 1, 1},
        //bg
        {0, 0, 13, 13} //always kBackgroundCellIndex
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
  BOImageTablePosition bgNodesTablePosition = kNodesTablePositions[kBackgroundCellIndex];
  table_ = BOImageTable::newL(parent_, bgNodesTablePosition.colSpan, bgNodesTablePosition.rowSpan);
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
  nodecontexts_.reserve(kTotalNodeCells);
  for (int i = 0; i < kTotalNodeCells; i++)
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
      table_->addEvasObject(evasObj, kNodesTablePositions[i].col, kNodesTablePositions[i].row, kNodesTablePositions[i].colSpan, kNodesTablePositions[i].rowSpan);
      i++;
      }
  } //end for
}

Evas_Object* PatternLockViewController::evasObject() const
{TRACE
  return container_;
}


void PatternLockViewController::resize()
{TRACE
  for (vector<CNodeContext*>::iterator it = nodecontexts_.begin();
        it != nodecontexts_.end();
        ++it) {
    CNodeContext* c = *it;
    BO_ASSERT(c != NULL);
    if (c) 
      {
      //Evas_Object* evasobj = c->evasObject();
      c->resize();
      }
  } //end for
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




