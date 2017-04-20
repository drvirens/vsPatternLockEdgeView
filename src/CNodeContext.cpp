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
#include "BOImageTable.hpp"
#include "BOImageTablePosition.hpp"
#include "trace.hpp"

static const BOImageTablePosition kBOImageTablePositions[EImageMaxSize + 1] =
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
, colordecorator_(0)
, table_(0)
, hotspot_()
{TRACE
}

void CNodeContext::createTable()
{TRACE
  BOImageTablePosition bgBOImageTablePosition = kBOImageTablePositions[EImageMaxSize];
  table_ = BOImageTable::newL(parent_, bgBOImageTablePosition.colSpan, bgBOImageTablePosition.rowSpan);
}

void CNodeContext::createImages()
{TRACE
  Evas_Object* tbl = table_->nativeTable();
  images_[EImageCore] = ImageCore::newL(tbl);
  BO_ASSERT(images_[EImageCore] != NULL);

  images_[EImageInner] = ImageInner::newL(tbl);
  BO_ASSERT(images_[EImageInner] != NULL);

  images_[EImageMiddle] = ImageMiddle::newL(tbl);
  BO_ASSERT(images_[EImageMiddle] != NULL);

  images_[EImageOuter] = ImageOuter::newL(tbl);
  BO_ASSERT(images_[EImageOuter] != NULL);
}

void CNodeContext::addImagesInTable()
{TRACE
  //add them in reverse order so that core is always at the top
  for (int i = EImageOuter; i >= 0; i--)
  {
    BO_ASSERT(images_[i] != 0);
    IImage& img = *(images_[i]);
    table_->add(img, kBOImageTablePositions[i].col, kBOImageTablePositions[i].row, kBOImageTablePositions[i].colSpan, kBOImageTablePositions[i].rowSpan);
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

void CNodeContext::resize()
{TRACE
  TODO("resize needs to be implemented");
  //table_->resize();
}

int CNodeContext::row() const
{TRACE
  BO_ASSERT(hotspot_.row_ != -1);
  return hotspot_.row_;
}
int CNodeContext::column() const
{TRACE
  BO_ASSERT(hotspot_.column_ != -1);
  return hotspot_.column_;
}
void CNodeContext::setRow(int row)
{TRACE
  hotspot_.row_ = row;
}
void CNodeContext::setColumn(int column)
{TRACE
  hotspot_.column_ = column;
}

BOHotspot& CNodeContext::hotspot()
{TRACE
  return hotspot_;
}

void CNodeContext::populateHotspotInfo()
{TRACE
  int x = 0;
  int y = 0;
  int w = 0;
  int h = 0;
  geometry(x, y, w, h);
  
  hotspot_.hotspot_rect_.x = x;
  hotspot_.hotspot_rect_.y = y;
  hotspot_.hotspot_rect_.w = w;
  hotspot_.hotspot_rect_.h = h;
  
  hotspot_.computeCenterPoint();
}

void CNodeContext::geometry(int& x, int& y, int& w, int& h)
{TRACE
  table_->geometry(x, y, w, h);
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

