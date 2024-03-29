//
//  tests.hpp
//  vsNodeView
//
//  Created by Virendra Shakya on 4/13/17.
//  Copyright © 2017 Virendra Shakya. All rights reserved.
//

#ifndef tests_hpp
#define tests_hpp

#ifdef __cplusplus
extern "C" {
#endif

void runAllTests(Evas_Object* parent);
void runAllTizenTests(Evas_Object* window);

Evas_Object* testPassiveNodeView(Evas_Object* parent);
Evas_Object* testActiveNodeView(Evas_Object* parent);
Evas_Object* testTizenActiveNodeView(Evas_Object* parent);

Evas_Object* testImage(Evas_Object* parent);
Evas_Object* testCoreImage(Evas_Object* parent);
Evas_Object* testInnerImage(Evas_Object* parent);
Evas_Object* testMiddleImage(Evas_Object* parent);
Evas_Object* testOuterImage(Evas_Object* parent);

Evas_Object* testTable(Evas_Object* parent);

void testNodeRedDecorator();
Evas_Object* testRedNodeViaContext(Evas_Object* parent);

void testEdgeViewThin();
Evas_Object* testThinEdgeView_Vertical(Evas_Object* parent);
Evas_Object* testThickEdgeView_Vertical(Evas_Object* parent);
Evas_Object* testThickEdgeView_Horizontal(Evas_Object* parent);
Evas_Object* testThickEdgeView_ForwardSlashed(Evas_Object* parent);
Evas_Object* testThickEdgeView_BackwardSlashed(Evas_Object* parent);

Evas_Object* testPatterLockVC(Evas_Object* parent);
Evas_Object* testPatterLockVCShowAll_PassiveState(Evas_Object* parent);
Evas_Object* testPatterLockVCShowAll_ActiveState(Evas_Object* parent);
Evas_Object* testPatterLockVCShowAll_ActiveState_WithTimer(Evas_Object* parent);
Evas_Object* testPatterLockVCShowAll_ActiveState_WithTimer_DecorateError(Evas_Object* parent);
Evas_Object* testPatterLockVCShowAll_ActiveState_WithTimer_DecorateOkay(Evas_Object* parent);

#ifdef __cplusplus
}
#endif


#endif /* tests_hpp */
