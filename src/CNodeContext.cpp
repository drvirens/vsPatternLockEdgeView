//
//  CNodeContext.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "CNodeContext.hpp"
#include "StatePassive.hpp"
#include "StateActive.hpp"
#include "ImageCore.hpp"
#include "ImageInner.hpp"
#include "ImageMiddle.hpp"
#include "ImageOuter.hpp"
#include "NodeColorDecorator.hpp"
#include "Table.hpp"
#include "trace.hpp"

static struct ImagePosition
  {
    int col;
    int row;
    int colSpan;
    int rowSpan;
  } 
  kImagePositions[EImageMaxSize + 1] =
     {
        {6, 6, 2, 2}, //core
        {5, 5, 4, 4}, //inner
        {2, 2, 10, 10}, //middle
        {1, 1, 12, 12}, //outer
        {0, 0, 14, 14}, //bg
     };
                     


CNodeContext* CNodeContext::newL(Evas_Object* parent)
{TRACE
  CNodeContext* obj = new CNodeContext(parent);
  if (obj) 
    {
    obj->construct();
    }
  return obj;
}

CNodeContext::CNodeContext(Evas_Object* parent) 
: parent_(parent)
, state_(0)
, passive_(0)
, active_(0)
, table_(0)
{TRACE
}

void CNodeContext::createTable()
{TRACE
  ImagePosition bgImagePosition = kImagePositions[EImageMaxSize];
  table_ = Table::newL(parent_, bgImagePosition.colSpan, bgImagePosition.rowSpan);
}

void CNodeContext::createImages()
{TRACE
  Evas_Object* tbl = table_->nativeTable();
  images_[EImageCore] = ImageCore::newL(tbl);
  images_[EImageInner] = ImageInner::newL(tbl);
  images_[EImageMiddle] = ImageMiddle::newL(tbl);
  images_[EImageOuter] = ImageOuter::newL(tbl);
}

void CNodeContext::addImagesInTable()
{TRACE
  //add them in reverse order so that core is always at the top
  for (int i = EImageOuter; i >= 0; i--)
  {
    BO_ASSERT(images_[i] != 0);
    IImage& img = *(images_[i]);
    table_->add(img, kImagePositions[i].col, kImagePositions[i].row, kImagePositions[i].colSpan, kImagePositions[i].rowSpan);
  } 
}

void CNodeContext::construct()
{TRACE
  createTable();
  createImages();
  addImagesInTable();
  
  active_ = StateActive::newL(*table_, *images_);
  passive_ = StatePassive::newL(*table_, *images_);
  state_ = passive_;
  
  colordecorator_ = new NodeColorDecorator(*active_, *table_, *images_);
}

CNodeContext::~CNodeContext()
{TRACE
}

void CNodeContext::show()
{TRACE
  state_->now(*this);
}

void CNodeContext::ok()
{TRACE
  colordecorator_->decorate(eGreen);
}
void CNodeContext::error()
{TRACE
  colordecorator_->decorate(eRed);
}
  
Evas_Object* CNodeContext::evasObject() const
{TRACE
  Evas_Object* tbl = table_->nativeTable();
  return tbl;
}
void CNodeContext::setPassive()
{TRACE
  state_ = passive_;
}

void CNodeContext::setActive()
{TRACE
  state_ = active_;
}

