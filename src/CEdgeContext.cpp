//
//  CEdgeContext.cpp
//  vsEdgeView
//
//  Created by Virendra Shakya on 4/16/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "CEdgeContext.hpp"
#include "EdgeStateThin.hpp"
#include "EdgeStateThick.hpp"
#include "ImageEdge.hpp"
#include "EdgeColorDecorator.hpp"
#include "BOImageTable.hpp"
#include "BOImageTablePosition.hpp"
#include "trace.hpp"

static const BOImageTablePosition kBOImageTablePositions[EImageMiddle] =
   {
      {2, 2, 8, 8}, //edge = 0
      {0, 0, 14, 14}, //bg = 1
   };

CEdgeContext* CEdgeContext::newL(Evas_Object* parent)
{TRACE
  CEdgeContext* obj = new CEdgeContext(parent);
  if (obj) 
    {
    obj->construct();
    }
  return obj;
}

CEdgeContext::CEdgeContext(Evas_Object* parent) 
: parent_(parent)
, state_(0)
, passive_(0)
, active_(0)
, colordecorator_(0)
, table_(0)
{TRACE
}

void CEdgeContext::createTable()
{TRACE
  BOImageTablePosition bgBOImageTablePosition = kBOImageTablePositions[EImageInner];
  table_ = BOImageTable::newL(parent_, bgBOImageTablePosition.colSpan, bgBOImageTablePosition.rowSpan);
}

void CEdgeContext::createImages()
{TRACE
  Evas_Object* tbl = table_->nativeTable();
  images_[EImageCore] = ImageEdge::newL(tbl);
 }

void CEdgeContext::addImagesInTable()
{TRACE
  for (int i = EImageCore; i >= 0; i--)//only one image
  {
    BO_ASSERT(images_[i] != 0);
    IImage& img = *(images_[i]);
    table_->add(img, kBOImageTablePositions[i].col, kBOImageTablePositions[i].row, kBOImageTablePositions[i].colSpan, kBOImageTablePositions[i].rowSpan);
  } 
}

void CEdgeContext::construct()
{TRACE
  createTable();
  createImages();
  addImagesInTable();
  
  active_ = EdgeStateThick::newL(*table_, *images_);
  passive_ = EdgeStateThin::newL(*table_, *images_);
  state_ = passive_;
  
  colordecorator_ = new EdgeColorDecorator(*active_, *table_, *images_);
}

CEdgeContext::~CEdgeContext()
{TRACE
}

void CEdgeContext::show()
{TRACE
  state_->now(*this);
}

void CEdgeContext::ok()
{TRACE
  colordecorator_->decorate(eGreen);
}
void CEdgeContext::error()
{TRACE
  colordecorator_->decorate(eRed);
}
  
Evas_Object* CEdgeContext::evasObject() const
{TRACE
  Evas_Object* tbl = table_->nativeTable();
  return tbl;
}
void CEdgeContext::setPassive()
{TRACE
  state_ = passive_;
}

void CEdgeContext::setActive()
{TRACE
  state_ = active_;
}

