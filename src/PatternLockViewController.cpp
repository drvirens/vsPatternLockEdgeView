//
//  PatternLockViewController.cpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/18/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#include "PatternLockViewController.hpp"
#include "trace.hpp"


PatternLockViewController::PatternLockViewController(Evas_Object* parent, int columns, int rows)
: parent_(parent)
, container_(0)
, columns_(columns)
, rows_(rows)
{TRACE
}
void PatternLockViewController::construct()
{TRACE
}
PatternLockViewController* PatternLockViewController::newL(Evas_Object* parent, int columns, int rows)
{TRACE
  PatternLockViewController* obj = new PatternLockViewController(parent, columns, rows);
  if (obj)
    {
    obj->construct();
    }
  return obj;
}
PatternLockViewController::~PatternLockViewController()
{TRACE
  parent_ = NULL;
  columns_ = 0;
  rows_ = 0;
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




