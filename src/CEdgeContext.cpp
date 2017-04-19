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
#include "BOEdgeType.hpp"
#include "ImageEdgeVertical.hpp"
#include "ImageEdgeHorizontal.hpp"
#include "ImageEdgeForwardSlashed.hpp"
#include "ImageEdgeBackwardSlashed.hpp"
#include "EdgeColorDecorator.hpp"
#include "BOImageTable.hpp"
#include "BOImageTablePosition.hpp"
#include "trace.hpp"

static const BOImageTablePosition kBOImageTablePositions[EImageMiddle] =
   {
      //{2, 2, 8, 8}, //edge = 0
      {0, 0, 14, 14}, //vertical edge = 0
      {0, 0, 14, 14}, //bg = 1
   };

CEdgeContext* CEdgeContext::newL(Evas_Object* parent, const BOEdgeType& type)
{TRACE
  CEdgeContext* obj = new CEdgeContext(parent, type);
  if (obj) 
    {
    obj->construct();
    }
  return obj;
}

CEdgeContext::CEdgeContext(Evas_Object* parent, const BOEdgeType& type) 
: parent_(parent)
, image_(0)
, state_(0)
, thin_(0)
, thick_(0)
, colordecorator_(0)
, table_(0)
, edgetype_(type)
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
  if (edgetype_ == BOEdgeType_Horizontal)
  {
    image_ = ImageEdgeHorizontal::newL(tbl);
  } else if (edgetype_ == BOEdgeType_Vertical)
  {
    image_ = ImageEdgeVertical::newL(tbl);
  } else if (edgetype_ == BOEdgeType_ForwardSlashed)
  {
    image_ = ImageEdgeForwardSlashed::newL(tbl);
  } else if (edgetype_ == BOEdgeType_BackwardSlashed)
  {
    image_ = ImageEdgeBackwardSlashed::newL(tbl);
  } else {
    image_ = 0;
  }
  BO_ASSERT(image_ != 0);
}

void CEdgeContext::addImagesInTable()
{TRACE
  BOEdgeType i = edgetype_;
  BO_ASSERT(image_ != 0);
  IImage& img = *(image_);
  table_->add(img, kBOImageTablePositions[i].col, kBOImageTablePositions[i].row, kBOImageTablePositions[i].colSpan, kBOImageTablePositions[i].rowSpan);
  
//  for (int i = EImageCore; i >= 0; i--)//only one image
//  {
//    BO_ASSERT(images_[i] != 0);
//    IImage& img = *(images_[i]);
//    table_->add(img, kBOImageTablePositions[i].col, kBOImageTablePositions[i].row, kBOImageTablePositions[i].colSpan, kBOImageTablePositions[i].rowSpan);
//  } 
}

void CEdgeContext::construct()
{TRACE
  createTable();
  createImages();
  addImagesInTable();
  
  thick_ = EdgeStateThick::newL(*table_, *image_);
  thin_ = EdgeStateThin::newL(*table_, *image_);
  state_ = thin_;
  
  colordecorator_ = new EdgeColorDecorator(*thick_, *table_, *image_);
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
  state_ = thin_;
}

void CEdgeContext::setActive()
{TRACE
  state_ = thick_;
}

