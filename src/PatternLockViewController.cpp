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
#include "trace.hpp"

// 9 == BOPatternbLockConfig::kTotalCells
static const BOImageTablePosition kBOImageTablePositions[9] =
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
  BOImageTablePosition bgBOImageTablePosition = kBOImageTablePositions[8];
  table_ = BOImageTable::newL(parent_, bgBOImageTablePosition.colSpan, bgBOImageTablePosition.rowSpan);
}
void PatternLockViewController::construct()
{TRACE
  createTable();
  createImages();
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

void PatternLockViewController::createImages()
{TRACE
  Evas_Object* tbl = table_->nativeTable();
//  images_[EImageCore] = ImageCore::newL(tbl);
//  images_[EImageInner] = ImageInner::newL(tbl);
//  images_[EImageMiddle] = ImageMiddle::newL(tbl);
//  images_[EImageOuter] = ImageOuter::newL(tbl);
}

void PatternLockViewController::addImagesInTable()
{TRACE
//  //add them in reverse order so that core is always at the top
//  for (int i = EImageOuter; i >= 0; i--)
//  {
//    BO_ASSERT(images_[i] != 0);
//    IImage& img = *(images_[i]);
//    table_->add(img, kBOImageTablePositions[i].col, kBOImageTablePositions[i].row, kBOImageTablePositions[i].colSpan, kBOImageTablePositions[i].rowSpan);
//  } 
}

Evas_Object* PatternLockViewController::evasObject() const
{TRACE
  return container_;
}

void PatternLockViewController::show()
{TRACE
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




