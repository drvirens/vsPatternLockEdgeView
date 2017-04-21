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
#include "bo_colors.h"

static string kBgImageName = "";

static const BOImageTablePosition kBOImageTablePositions[EImageMiddle] =
   {
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
, tblBackgroudSpecs_(BO_COLOR_RED_ALPHA, kBgImageName)
, edgetype_(type)
, name_(-1)
{TRACE
}

void CEdgeContext::createTable()
{TRACE
  //BOImageTablePosition bgBOImageTablePosition = kBOImageTablePositions[EImageInner];
  BOImageTablePosition bgBOImageTablePosition = kBOImageTablePositions[0];
  table_ = BOImageTable::newL(parent_, bgBOImageTablePosition.colSpan, bgBOImageTablePosition.rowSpan, tblBackgroudSpecs_);
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
  //BOEdgeType i = edgetype_;
  int i = 0; //all the edges are always drawn in same way
  BO_ASSERT(image_ != 0);
  IImage& img = *(image_);
  int len = sizeof(kBOImageTablePositions)/sizeof(kBOImageTablePositions[0]);
  BO_ASSERT(i >= 0 && i < len);
  if (!(i >= 0 && i < len))
  {
    return;
  }
  table_->add(img, kBOImageTablePositions[i].col, kBOImageTablePositions[i].row, kBOImageTablePositions[i].colSpan, kBOImageTablePositions[i].rowSpan);
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
  delete colordecorator_;
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

void CEdgeContext::setName(int name)
{TRACE
  name_ = name;
}
int CEdgeContext::name() const
{TRACE
  return name_;
}
  
Evas_Object* CEdgeContext::evasObject() const
{TRACE
  Evas_Object* tbl = table_->nativeTable();
  return tbl;
}
void CEdgeContext::setThin()
{TRACE
  state_ = thin_;
}

void CEdgeContext::setThick()
{TRACE
  state_ = thick_;
}

