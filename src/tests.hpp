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
Evas_Object* testNodeView(Evas_Object* parent);

Evas_Object* testImage(Evas_Object* parent);
Evas_Object* testCoreImage(Evas_Object* parent);
Evas_Object* testInnerImage(Evas_Object* parent);
Evas_Object* testMiddleImage(Evas_Object* parent);
Evas_Object* testOuterImage(Evas_Object* parent);

Evas_Object* testTable(Evas_Object* parent);

#ifdef __cplusplus
}
#endif


#endif /* tests_hpp */
